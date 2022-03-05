#include "BouncingBall.h"

const int nNumBall = 5;
static QTimer *time;
Ball arrBall[nNumBall];
//Ball ball;
XY vect;
XY acc;

BouncingBall::BouncingBall(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    BallInit();
    connect(ui.btnUpdate, SIGNAL(clicked()), this, SLOT(btnUpdateClicked()));

    time = new QTimer(this);
    connect(time, SIGNAL(timeout()), this, SLOT(UpdateCircle()));
    time->start(10);

}

void BouncingBall::btnUpdateClicked()
{
    BallInit();
    //UpdateCircle();
}

void BouncingBall::BallInit()
{
    double dRadius = 50;

    for (int i = 0; i < nNumBall; i++)
    {
        XY pt = XY((1.0 * width() * i / nNumBall) + dRadius, dRadius * (i + 1));
        XY vect = XY(rand() % 20 - 20, 0);

        Ball ball = Ball(dRadius - 5 * i, pt);
        ball.Speed = vect;
        ball.Acceleration = XY(0, 0.2);
        arrBall[i] = ball;
    }
}

void BouncingBall::UpdateCircle()
{
    for (int i = 0; i < nNumBall; i++)
    {
        //Ball ball = arrBall[i];
        if (abs(arrBall[i].Center.Y - height()) < 0.1
            && arrBall[i].Speed.Y < 0.1)
        {
            return;
        }

        if (arrBall[i].Center.Y + arrBall[i].Radius > height())
        {
            arrBall[i].Speed.Y = arrBall[i].Speed.Y * -0.8;
            arrBall[i].Speed.X = arrBall[i].Speed.X * 0.8;
            arrBall[i].Center.Y = height() - arrBall[i].Radius;
        }

        if (arrBall[i].Center.X + arrBall[i].Radius > width())
        {
            arrBall[i].Speed.X = arrBall[i].Speed.X * -1;
            arrBall[i].Center.X = width() - arrBall[i].Radius;
        }

        if (arrBall[i].Center.X - arrBall[i].Radius < 0)
        {
            arrBall[i].Speed.X = arrBall[i].Speed.X * -1;
            arrBall[i].Center.X = arrBall[i].Radius;
        }

        for (int j = i + 1; j < nNumBall; j++)
        {
            arrBall[i].CollideWith(arrBall[j]);
        }

        arrBall[i].Update();
    }

    update();
}

void BouncingBall::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    for (int i = 0; i < nNumBall; i++)
    {
        Ball ball = arrBall[i];
        painter.drawEllipse(ball.Center.X - ball.Radius, ball.Center.Y - ball.Radius, ball.Radius * 2, ball.Radius * 2);
    }

    //painter.drawLine(QPointF(0, 0), QPointF(width(), height()));
    //painter.drawLine(QPointF(width() / 2, 0), QPointF(width() / 2, height()));
}