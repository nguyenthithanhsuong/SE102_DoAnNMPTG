#pragma once

#include "ID.h"
#include "GameObject.h"
#include "Deleted.h"

class QNode
{
public:
	int level;
	float leftx, topy, rightx, boty;
	list<LPGAMEOBJECT> objects;
	QNode* left, * right;
	QNode();
	QNode(int level, float a1, float b1, float a2, float b2);
	void Clear(QNode* node);
	bool IsContain(CGameObject* object);
	bool IsOnBoundary(CGameObject* object);
	void Split();
	void Insert(CGameObject* object);
	void Get(CGameObject* object, QNode* node, QNode* Tree);
	int HighestLevel(QNode* node);
};

