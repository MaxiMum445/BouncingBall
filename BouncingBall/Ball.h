#pragma once

#include "XY.h"
#include <cmath>

#define M_PI 3.1415926535897
#define DENSITY 3.1415926535897

class Ball
{

public:
    Ball();
    Ball(int nRadius);
    Ball(int nRadius, XY ptCenter);

public:
    //�뾶
	int Radius;

    //����
    XY Center;

    //�ٶ�
    XY Speed;

    //���ٶ�
    XY Acceleration;

    double Mass = M_PI * Radius * Radius * DENSITY;

public:
    void Move(XY vect);

    void Move();

    void Update();

    bool IsCollideTo(Ball ball);

    void CollideWith(Ball& ball);

private:



};