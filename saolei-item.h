#ifndef SAOLEIITEM_H
#define SAOLEIITEM_H

#include<QPoint>


class Item
{
public:
    Item();
    Item(QPoint pos);
    //物体所在位置
    QPoint m_pos;

    //是否是雷
    bool isMine;
    //是否标记为雷
    bool isMarked;
    //是否已经打开，且非雷
    bool isopen;

    //数字
    int number;


};

#endif // SAOLEIITEM_H
