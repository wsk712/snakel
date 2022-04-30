#ifndef SAOLEI_H
#define SAOLEI_H

#include <QWidget>
#include<QPaintEvent>
#include<QDebug>
#include<QAction>
#include<QMenu>
#include<saolei-item.h>
#include<snakel.h>
#include<saoleidialog.h>
#include<QMenuBar>

//宏定义各种参数数值
#define RECT_WIDTH  30//正方形宽
#define RECT_HEIGHT  30//正方形高

#define START_X  100//起始位置x
#define START_Y  100//起始位置y

namespace Ui {
class saolei;
}

class saolei : public QWidget
{
    Q_OBJECT

public:
    explicit saolei(QWidget *parent = nullptr);
    ~saolei();
    //初始化游戏
    void initItems();
    //结束游戏后释放空间
    void releaseItems();
    //开启新游戏
    void newGame();
    //游戏结束 点到雷
    void overGame();
    //是否找到所有的雷
    bool findAll();
    //绘制图形
    void paintEvent(QPaintEvent *);
    //鼠标操作
    void mousePressEvent(QMouseEvent *e);
    //绘制整个布局
    void drawBoard();
    //绘制物体
    void drawItems();
    //绘制单个物体
    void drawItem(QPainter &painter,Item *pItem);
    //点击空白元素时，递归查找相邻的空白元素，以及空白元素附近的数字元素（数字是雷数）
    void openEmptyItem(QPoint pt);
    //判断坐标是否在游戏内
    bool pointInGameArea(QPoint pt);

    QMenu *menu1;
    QMenu *menu2;



    QAction *easy;
    QAction *normal;
    QAction *hard;
    QAction *self;
public slots:
    void slot_newGame();
    void slot_level_easy();
    void slot_level_normal();
    void slot_level_hard();
    void slot_level_self();
    void slot_level_self_get();


private:
    Ui::saolei *ui;

    QPixmap flagImage;//红旗
    QPixmap bombImage;//雷

    int rows;
    int cols;
    int mine;
    QVector<QPoint> Mines;//雷点
    QVector<QVector<Item*>> items;//所有元素
    bool m_bGameFail;//是否是游戏失败，失败了需要显示雷

    saoleiDialog *dialogSelf;//定义自定义对话框
};

#endif // SAOLEI_H
