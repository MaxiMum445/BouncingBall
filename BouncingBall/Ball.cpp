#include "ball.h"

Ball::Ball() 
{

}

Ball::Ball(int nRadius) 
{
    Radius = nRadius;
    Center = XY();
    Speed = XY();
    Acceleration = XY();
}

Ball::Ball(int nRadius, XY ptCenter) 
{
    Radius = nRadius;
    Center = ptCenter;
    Speed = XY();
    Acceleration = XY();
}
void Ball::Move(XY vect)
{
    Center = Center + vect;
}
void Ball::Move()
{
    Center = Center + Speed;
}
void Ball::Update()
{
    Speed = Speed + Acceleration;
    Center = Center + Speed;
}

bool Ball::IsCollideTo(Ball ball) 
{
    return ball.Radius + this->Radius > ball.Center.DistanceTo(this->Center);
}

void Ball::CollideWith(Ball& ball)
{
    if (!(this->IsCollideTo(ball)))
    {
        return;
    }

    //碰撞后速度调整

    //方向
    XY vThisToBall = (ball.Center - this->Center).Normolise();
    XY vSpeedThisX;
    XY vSpeedThisY;
    XY vSpeedBallX;
    XY vSpeedBallY;

    this->Speed.Split(vThisToBall, vSpeedThisX, vSpeedThisY);
    ball.Speed.Split(vThisToBall, vSpeedBallX, vSpeedBallY);

    //按照实际质量交换速度
    //double dSpeedThis = vThisToBall * vSpeedThisX;
    //double dSpeedBall = vSpeedBallX * vSpeedThisX;

    //double dSpeedThisNew = ((this->Mass - ball.Mass)*dSpeedThis + 2.0*ball.Mass*dSpeedBall) / (this->Mass + ball.Mass);
    //double dSpeedBallNew = ((ball.Mass - this->Mass)*dSpeedThis + 2.0*this->Mass*dSpeedThis) / (this->Mass + ball.Mass);

    //XY vSpeedThisXNew = vThisToBall * dSpeedThisNew;
    //XY vSpeedBallXNew = vThisToBall * dSpeedBallNew;

    //this->Speed = vSpeedThisXNew + vSpeedThisY;
    //ball.Speed = vSpeedBallXNew + vSpeedBallY;

    //按照质量相等交换速度
    this->Speed = vSpeedBallX + vSpeedThisY;
    ball.Speed = vSpeedThisX + vSpeedBallY;

    //碰撞后位置调整
    double dDis = this->Center.DistanceTo(ball.Center);
    double dError = ball.Radius + this->Radius - dDis;
    if (dError > 0.01)
    {
        this->Center = this->Center - vThisToBall * (dError / 2);
        ball.Center = ball.Center + vThisToBall * (dError / 2);
    }

}
