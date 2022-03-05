#pragma once

#include <math.h>

class XY
{
public:
    XY();
    XY(double dX, double dY);

public:
    double X;
    double Y;


private:


public:
    XY operator +(const XY & XY1);
    XY operator -(XY XY2);
    XY operator *(double value);
    XY operator /(double value);
    XY operator -();
    double operator *(const XY & XY1);
    XY Normolise();
    double DistanceTo(XY pt);
    void Split(XY vect, XY& vParallel, XY& vVertical);

};
