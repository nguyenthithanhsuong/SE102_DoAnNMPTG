#include "Collision.h"
#include "GameObject.h"
#include "BinaryTree.h"
#include "debug.h"
#include "GameObject.h"
#include "Bill.h"

extern CBill* bill;

#define BLOCK_PUSH_FACTOR 0.2f

int CCollisionEvent::WasCollided() {
	return
		(t >= 0.0f && t <= 1.0f) && (obj->IsDirectionColliable(nx, ny) == 1);
}


CCollision* CCollision::__instance = NULL;

CCollision* CCollision::GetInstance()
{
	if (__instance == NULL) __instance = new CCollision();
	return __instance;
}

void CCollision::SweptAABB(
	float ml, float mt, float mr, float mb,
	float dx, float dy,
	float sl, float st, float sr, float sb,
	float& t, float& nx, float& ny)
{

	float dx_entry, dx_exit, tx_entry, tx_exit;
	float dy_entry, dy_exit, ty_entry, ty_exit;

	float t_entry;
	float t_exit;

	t = -1.0f;			// no collision
	nx = ny = 0;

	//
	// Broad-phase test 
	//

	float bl = dx > 0 ? ml : ml + dx;
	float bt = dy > 0 ? mt + dy : mt;
	float br = dx > 0 ? mr + dx : mr;
	float bb = dy > 0 ? mb : mb + dy;
	if (br < sl || bl > sr || bb > st || bt < sb) return;

	if (dx == 0 && dy == 0) return;		// moving object is not moving > obvious no collision

	if (dx > 0)
	{
		dx_entry = sl - mr;
		dx_exit = sr - ml;
	}
	else if (dx < 0)
	{
		dx_entry = sr - ml;
		dx_exit = sl - mr;
	}


	if (dy < 0)
	{
		dy_entry = st - mb; //collision from the bottom
		dy_exit = sb - mt;  //collision from the bottom
	}
	else if (dy > 0)
	{
		dy_entry = sb - mt; //collision from the top
		dy_exit = st - mb; //collision from the top
	}

	if (dx == 0)
	{
		tx_entry = -9999999.0f;
		tx_exit = 99999999.0f;
	}
	else
	{
		tx_entry = dx_entry / dx;
		tx_exit = dx_exit / dx;
	}

	if (dy == 0)
	{
		ty_entry = -99999999999.0f;
		ty_exit = 99999999999.0f;
	}
	else
	{
		ty_entry = dy_entry / dy;
		ty_exit = dy_exit / dy;
	}
	if ((tx_entry < 0.0f && ty_entry < 0.0f) || tx_entry > 1.0f || ty_entry > 1.0f) return;

	t_entry = max(tx_entry, ty_entry);
	t_exit = min(tx_exit, ty_exit);

	if (t_entry > t_exit) return;

	t = t_entry;

	if (tx_entry > ty_entry)
	{
		ny = 0.0f;
		dx > 0 ? nx = -1.0f : nx = 1.0f;
	}
	else
	{
		nx = 0.0f;
		dy > 0 ? ny = 1.0f : ny = -1.0f;
	}
}


LPCOLLISIONEVENT CCollision::SweptAABB(LPGAMEOBJECT objSrc, DWORD dt, LPGAMEOBJECT objDest)
{
	float sl, st, sr, sb;		// static object bbox
	float ml, mt, mr, mb;		// moving object bbox
	float t = 0, nx = 0, ny = 0;

	float mvx, mvy;
	objSrc->GetSpeed(mvx, mvy);

	//khong can xai dt
	DWORD dt_basis = dt;
	float mdx = mvx * dt_basis;
	float mdy = mvy * dt_basis;

	float svx, svy;
	objDest->GetSpeed(svx, svy);
	float sdx = svx * dt_basis;
	float sdy = svy * dt_basis;

	//
	// NOTE: new m speed = original m speed - collide object speed
	// 
	float dx = mdx - sdx;
	float dy = mdy - sdy;


	objSrc->GetBoundingBox(ml, mt, mr, mb);
	objDest->GetBoundingBox(sl, st, sr, sb);

	SweptAABB(
		ml, mt, mr, mb,
		dx, dy,
		sl, st, sr, sb,
		t, nx, ny
	);

	CCollisionEvent* e = new CCollisionEvent(t, nx, ny, dx, dy, objDest, objSrc);
	return e;
}

void CCollision::Scan(LPGAMEOBJECT objSrc, DWORD dt, QNode* node, vector<LPCOLLISIONEVENT>& coEvents)
{
	if (node == NULL)
	{
		return;
	}
	if (node->left != NULL)
	{
		Scan(objSrc, dt, node->left, coEvents);
	}
	if (node->right != NULL)
	{
		Scan(objSrc, dt, node->right, coEvents);
	}
	if (node->left == NULL && node->right == NULL)
	{
		for (auto obj : node->objects)
		{
			if (obj->GetID() != objSrc->GetID())
			{
				LPCOLLISIONEVENT e = SweptAABB(objSrc, dt, obj);
				if (e->WasCollided() == 1)
					coEvents.push_back(e);
				else
					delete e;
			}
		}
	}
	std::sort(coEvents.begin(), coEvents.end(), CCollisionEvent::compare);
}

void CCollision::Filter(LPGAMEOBJECT objSrc,
	vector<LPCOLLISIONEVENT>& coEvents,
	LPCOLLISIONEVENT& colX,
	LPCOLLISIONEVENT& colY,
	int filterBlock = 1,		// 1 = only filter block collisions, 0 = filter all collisions 
	int filterX = 1,			// 1 = process events on X-axis, 0 = skip events on X 
	int filterY = 1)			// 1 = process events on Y-axis, 0 = skip events on Y
{
	float min_tx, min_ty;

	min_tx = 1.0f;
	min_ty = 1.0f;
	int min_ix = -1;
	int min_iy = -1;

	for (UINT i = 0; i < coEvents.size(); i++)
	{
		LPCOLLISIONEVENT c = coEvents[i];
		if (c->isDeleted) continue;
		if (c->obj->IsDeleted()) continue;

		// ignore collision event with object having IsBlocking = 0 (like coin, mushroom, etc)
		if (filterBlock == 1 && !c->obj->IsBlocking())
		{
			continue;
		}

		if (c->t < min_tx && c->nx != 0 && filterX == 1) {
			min_tx = c->t; min_ix = i;
		}

		if (c->t < min_ty && c->ny != 0 && filterY == 1) {
			min_ty = c->t; min_iy = i;
		}
	}

	if (min_ix >= 0) colX = coEvents[min_ix];
	if (min_iy >= 0) colY = coEvents[min_iy];
}

void CCollision::Process(LPGAMEOBJECT objSrc, DWORD dt, QNode* Tree)
{
	vector<LPCOLLISIONEVENT> coEvents;
	LPCOLLISIONEVENT colX = NULL;
	LPCOLLISIONEVENT colY = NULL;

	coEvents.clear();

	if (objSrc->IsCollidable())
	{
		Scan(objSrc, dt, Tree, coEvents);
	}

	// No collision detected
	if (coEvents.size() == 0)
	{
		objSrc->OnNoCollision(dt);
	}
	else
	{
		Filter(objSrc, coEvents, colX, colY);

		float x, y, vx, vy, dx, dy;
		objSrc->GetPosition(x, y);
		objSrc->GetSpeed(vx, vy);
		dx = vx * dt;
		dy = vy * dt;

		if (colX != NULL && colY != NULL)
		{
			if (colY->t < colX->t)	// was collision on Y first ?
			{
				y += colY->t * dy - colY->ny * BLOCK_PUSH_FACTOR;
				objSrc->SetPosition(x, y);
				objSrc->OnCollisionWith(colY);

				LPCOLLISIONEVENT colX_other = NULL;

				colX->isDeleted = true;

				coEvents.push_back(SweptAABB(objSrc, dt, colX->obj));

				Filter(objSrc, coEvents, colX_other, colY, /*filterBlock = */ 1, 1, /*filterY=*/0);

				if (colX_other != NULL)
				{
					x += colX_other->t * dx + colX_other->nx * BLOCK_PUSH_FACTOR;
					objSrc->OnCollisionWith(colX_other);
				}
				else
				{
					x += dx;
				}
			}
			else
			{
				x += colX->t * dx + colX->nx * BLOCK_PUSH_FACTOR;
				objSrc->SetPosition(x, y);

				objSrc->OnCollisionWith(colX);

				LPCOLLISIONEVENT colY_other = NULL;

				colY->isDeleted = true;

				coEvents.push_back(SweptAABB(objSrc, dt, colY->obj));

				Filter(objSrc, coEvents, colX, colY_other, /*filterBlock = */ 1, /*filterX=*/0, /*filterY=*/1);

				if (colY_other != NULL)
				{
					y += colY_other->t * dy - colY_other->ny * BLOCK_PUSH_FACTOR;
					objSrc->OnCollisionWith(colY_other);
				}
				else
				{
					y += dy;
				}
			}
		}
		else
			if (colX != NULL)
			{
				x += colX->t * dx + colX->nx * BLOCK_PUSH_FACTOR;
				y += dy;
				objSrc->OnCollisionWith(colX);
			}
			else
				if (colY != NULL)
				{
					x += dx;
					y += colY->t * dy - colY->ny * BLOCK_PUSH_FACTOR;
					objSrc->OnCollisionWith(colY);
				}
				else // both colX & colY are NULL 
				{
					x += dx;
					y += dy;
				}
		objSrc->SetPosition(x, y);
	}

	//
	// Scan all non-blocking collisions for further collision logic
	//
	for (UINT i = 0; i < coEvents.size(); i++)
	{
		LPCOLLISIONEVENT e = coEvents[i];
		if (e->isDeleted) continue;
		if (e->obj->IsBlocking()) continue;  // blocking collisions were handled already, skip them

		objSrc->OnCollisionWith(e);
	}


	for (UINT i = 0; i < coEvents.size(); i++) delete coEvents[i];
}

