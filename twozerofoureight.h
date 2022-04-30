#ifndef TWOZEROFOUREIGHT_H
#define TWOZEROFOUREIGHT_H

#include <QWidget>
#include<QPushButton>
#include<qpainter.h>
#include<QVector>
#include<qstring.h>
#include<QTime>
#include<QColor>
#include<QMessageBox>


namespace Ui {
class twozerofoureight;
}

class twozerofoureight : public QWidget
{
    Q_OBJECT

public:
    explicit twozerofoureight(QWidget *parent = nullptr);
    ~twozerofoureight();
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *event);
    QPushButton *button;
    QPushButton* size_btn_3;//3*3按钮
    QPushButton* size_btn_4;//4*4按钮
    QPushButton *re;//返回按钮
    int lattice_3[3][3];
    int lattice_4[4][4];
    int score=0;
    bool state;//游戏状态 true正常运行 false停止
    int size;

    //wasd函数
    void PressUp();
    void PressDown();
    void PressLeft();
    void PressRight();

    //随机生成函数 判断结束函数
    void myRand();
    struct Position
    {
        int i;
        int j;
    };

public slots://槽函数
    void slotStart();
    void ensureSize3();//3*3
    void ensureSize4();//4*4
private slots:

    void on_pushButton_clicked();

private:
    Ui::twozerofoureight *ui;
};

#endif // TWOZEROFOUREIGHT_H
