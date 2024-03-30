#pragma once

class CCamera
{
private:
public:
	float cam_x=0;
	float cam_y=0;
	CCamera() { cam_x = 0; cam_y = 0; }
	void SetCamPos(float x, float y) { cam_x = x; cam_y = y; }
	void GetCamPos(float& x, float& y) { x = cam_x; y = cam_y; }
};