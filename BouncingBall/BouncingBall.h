#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_BouncingBall.h"
#include <QWidget>  
#include <QPainter> 
#include <QTimer>
#include "ball.h"

class BouncingBall : public QMainWindow
{
    Q_OBJECT

public:
    BouncingBall(QWidget *parent = Q_NULLPTR);

private:
    Ui::BouncingBallClass ui;

public slots:
    void btnUpdateClicked();

public slots:
    void UpdateCircle();

protected:
    void paintEvent(QPaintEvent *event);
    void BallInit();
};
