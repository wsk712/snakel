#include<saolei-item.h>
#include<snakel.h>

Item::Item()
{
    //初始化物体
    m_pos=QPoint(-1,-1);

    number=0;
    isMine=false;
    isMarked=false;
    isopen=false;
}

Item::Item(QPoint pos)
{
    //初始化物体
    m_pos=pos;

    number=0;
    isMine=false;
    isMarked=false;
    isopen=false;
}
