#pragma once
#include <cmath>
#include "ID.h"
#include "debug.h"
class CCamera
{
private:
public:
	float cam_x=0;
	float cam_y=0;
	float cam_width = SCREEN_WIDTH;
	float cam_height = SCREEN_HEIGHT;
	CCamera() { cam_x = 0; cam_y = 0; }
	void SetCamPos(float x, float y) { cam_x = x; cam_y = y; }
	void GetCamPos(float& x, float& y) { x = cam_x; y = cam_y; }
	void Update(float cx, float cy);
	void DrawCoordinate(float& x, float& y) 
	{
		x -= cam_x, y -= cam_y; 
	}
};