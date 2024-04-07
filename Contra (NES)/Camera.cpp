#include "Camera.h"

void CCamera::Update(float cx, float cy)
{
    cam_x = cx - cam_width / 2;
    cam_y = 0;
    if (cam_x < 0) cam_x = 0;
    if (cam_x > LEVEL_LENGTH - cam_width) cam_x = LEVEL_LENGTH - cam_width;
    SetCamPos(cam_x, cam_y);
}
