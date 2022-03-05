#include "XY.h"


XY::XY()
{
    X = 0;
    Y = 0;
}
XY::XY(double dX,double dY)
{
    X = dX;
    Y = dY;
}

//XY XY::operator +(XY XY1, XY XY2)
XY XY::operator +(const XY& XY2)
{
    return XY(XY2.X + this->X, XY2.Y + this->Y);
}

XY XY::operator -(XY XY2)
{
    return XY(this->X - XY2.X, this->Y - XY2.Y);
}

XY XY::operator *(double value)
{
    return XY(this->X * value, this->Y * value);
}

XY XY::operator /(double value)
{
    return XY(this->X / value, this->Y / value);
}

XY XY::operator -()
{
    return XY(-(this->X), -(this->Y));
}

double XY::operator*(const XY & XY2)
{
    return this->X * XY2.X + this->Y * XY2.Y;
}

XY XY::Normolise()
{
    double dLen = this->DistanceTo(XY(0, 0));
    return XY(this->X / dLen, this->Y / dLen);
}

double XY::DistanceTo(XY pt)
{
    return sqrt(pow(pt.X - this->X, 2) + pow(pt.Y - this->Y, 2));
}

//按照vect方向拆分向量
void XY::Split(XY vect, XY & vParallel, XY & vVertical)
{
    vect = vect.Normolise();
    vParallel = vect * (*this * vect);
    vVertical = *this - vParallel;
}
