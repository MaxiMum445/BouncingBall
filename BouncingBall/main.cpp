#include "BouncingBall.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BouncingBall w;
    w.show();
    return a.exec();
}
