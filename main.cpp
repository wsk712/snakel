#include "snakel.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    snakel w;
    w.show();
    w.setFixedSize(320,480);//改变窗口大小
    w.setWindowTitle("综合小游戏");//改变窗口标题
    return a.exec();
}
