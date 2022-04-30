#include "saolei.h"
#include "ui_saolei.h"

#include<QAbstractButton>
#include<QMessageBox>
#include<QPaintEvent>
#include<QPainter>
#include<QTime>
#include<QtWidgets>
#include <QMenuBar>
#include<snakel.h>
#include<qrect.h>
#include<QAction>
#include<QMainWindow>
#include<QRandomGenerator>
#include<QMenu>
#include<QAction>


saolei::saolei(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::saolei)
{
    ui->setupUi(this);

    //menu初始化
    QMenuBar *menuBar=new QMenuBar(this);
    menu1=new QMenu("新游戏",this);
    menu2=new QMenu("难度",this);
    menuBar->addMenu(menu1);
    menuBar->addMenu(menu2);






        /*ui->menuBar->addMenu(menu1);
        ui->menuBar->addMenu(menu2);*/




    connect(menu1,SIGNAL(aboutToShow()),this,SLOT(slot_newGame()));

    //Action 初始化
    easy=new QAction("easy",this);
    normal=new QAction("normal",this);
    hard=new QAction("hard",this);
    self=new QAction("自定义",this);

    menu2->addAction(easy);
    menu2->addAction(normal);
    menu2->addAction(hard);
    menu2->addAction(self);

    connect(easy,SIGNAL(triggered()),this,SLOT(slot_level_easy()));
    connect(normal,SIGNAL(triggered()),this,SLOT(slot_level_normal()));
    connect(hard,SIGNAL(triggered()),this,SLOT(slot_level_hard()));
    connect(self,SIGNAL(triggered()),this,SLOT(slot_level_self()));


    dialogSelf=new saoleiDialog(this);
    connect(dialogSelf,SIGNAL(dia_test()),this,SLOT(slot_level_self_get()));



    flagImage = QPixmap(":/image/图片/flag.jpg");	//旗帜
    bombImage = QPixmap(":/image/图片/bomb.jpg");	//雷

        rows = 9;
        cols = 9;
        mine = 10;
        newGame();



}

saolei::~saolei()
{
    delete ui;
}

void saolei::initItems()
{
    //随机初始化 雷
    Mines.clear();
    for(int i = 0; i<mine; i++)
    {
        srand(QTime::currentTime().msec());
        int x = QRandomGenerator::global()->bounded(cols);
        int y = QRandomGenerator::global()->bounded(rows);

        while(Mines.contains(QPoint(x,y)))
        {//当已经包含了这个雷 则重新随机生成一个雷
            x = QRandomGenerator::global()->bounded(cols);
            y = QRandomGenerator::global()->bounded(rows);
        }
        Mines.append(QPoint(x,y));
    }
    //建立2维数组保存所有元素位置，方便索引
    for(int i=0; i<cols; i++) //列
    {
        QVector<Item*> rowItems;//Item对象指针的容器
        for(int j=0; j<rows; j++)
        {
            QPoint pos = QPoint(i,j);
            Item* pItem = new Item(pos);
            if(Mines.contains(pos))   //若该位置是雷
            {
                pItem->isMine = true;
            }
            rowItems.append(pItem);
        }
        items.append(rowItems);
    }
    //计算格子的数字
    for(int i=0; i<cols; i++)
    {
        for(int j=0; j<rows; j++)
        {
            if (items[i][j]->isMine)
            {
                continue;
            }
            int nCountMines = 0;
            //求每个点附近的8个点的是雷的总数
            for (int m=-1;m<=1;m++)
            {
                for (int n=-1; n<=1;n++)
                {
                    if (m==0 && n==0)
                    {
                        continue;
                    }
                    QPoint ptNew = QPoint(i+m,j+n);
                    if (!pointInGameArea(ptNew))
                    {
                        continue;
                    }

                    if (items[i+m][j+n]->isMine)
                    {
                        nCountMines++;
                    }
                }
            }
            items[i][j]->number = nCountMines;
        }
    }
}

void saolei::releaseItems()
{   //清除所有的指针
    //释放空间
    for (int i=0; i<items.size(); i++)
    {
        for (int j=0;j<items[i].size(); j++)
        {
            if (items[i][j] != nullptr)
            {
                delete items[i][j];
                items[i][j] = nullptr;
            }
        }
    }
    items.clear();
}

void saolei::newGame()
{
    m_bGameFail = false;

    //初始化界面大小
    resize(START_X*2 + cols*RECT_WIDTH  ,START_Y*2 + rows*RECT_HEIGHT);

    releaseItems();
    initItems();
}

void saolei::overGame()
{
    m_bGameFail = true;
    for (int i=0; i<items.size(); i++)
    {
        for (int j=0;j<items[i].size(); j++)
        {
            if (items[i][j]->isMine)
            {
                items[i][j]->isMarked = true;
            }
            else
            {
                items[i][j]->isMarked = false;
                items[i][j]->isopen = true;
            }
        }
    }
}

bool saolei::findAll()
{
    bool bFindAll = true;
    //遍历二维数组 QVector<QVector<Item*>> m_items
    for (int i=0; i<items.size(); i++)
    {
        for (int j=0;j<items[i].size(); j++)
        {
            //只要存在一个雷没被标记，或存在一个非雷被没打开，都不算找完
            Item* pItem = items[i][j];
            if (pItem->isMine)
            {
                if (!pItem->isMarked)
                {
                    bFindAll = false;
                }
            }
            else
            {
                if (!pItem->isopen)
                {
                    bFindAll = false;
                }
            }
        }
    }
    return bFindAll;
}

void saolei::paintEvent(QPaintEvent *)
{
    drawBoard();
    drawItems();

    //刷新游戏画面
    update();
}

void saolei::mousePressEvent(QMouseEvent *e)
{
    //得到鼠标处的格子坐标
    QPoint pt;
    pt.setX( (e->pos().x() - START_X ) / RECT_WIDTH);
    pt.setY( (e->pos().y() - START_X ) / RECT_HEIGHT);
    //是否点在游戏区域内
    if (!pointInGameArea(pt))
    {
        return;
    }
    //获取所点击矩形元素
    Item* pItem = items[pt.x()][pt.y()];
    //左键打开元素，右键插旗帜标记
    if(e->button()==Qt::LeftButton)
    {
        //不是已标记的或已打开的空白点，也就是未处理的
        if(!pItem->isMarked && !pItem->isopen)
        {
            //如果是雷，就GAME OVER
            if (pItem->isMine)
            {
                overGame();
                QMessageBox::StandardButton ret;
                ret=QMessageBox::information(nullptr,  "GAME OVER","Try Again?",
                                             QMessageBox::Yes , QMessageBox::No);
                if(ret==QMessageBox::Yes){
                    newGame();
                }
                else{
                    QApplication::quit();
                }
                return;
            }
            else
            {
                //打开
                pItem->isopen = true;
                if (pItem->number == 0)
                {
                    //如果数字是0，也就是不含任何相邻雷的元素，那么递归打开所有的相邻数字是0的元素
                    //也就是点到一个空白处，一下打开一大片的效果
                    openEmptyItem(pt);
                }
                //如果已找到所有雷
                if (findAll())
                {

                    QMessageBox::StandardButton ret;
                    ret=QMessageBox::information(nullptr,  "GAME OVER","SUCCESS! Try Again?",
                                                 QMessageBox::Yes , QMessageBox::No);
                    if(ret==QMessageBox::Yes){
                        newGame();
                    }
                    else{
                        QApplication::quit();
                    }
                    return;
                }
            }
        }
    }
    else if(e->button()==Qt::RightButton)
    {
        //已标记过的，取消标记
        if (pItem->isMarked)
        {
            pItem->isMarked = false;
        }
        else if (!pItem->isopen)
        {
            //没标记也没打开，就是未处理的，就插旗帜标记上
            pItem->isMarked = true;
            if (findAll())
            {
                QMessageBox::StandardButton ret;
                ret=QMessageBox::information(nullptr,  "GAME OVER","SUCCESS! Try Again?",
                                             QMessageBox::Yes , QMessageBox::No);
                if(ret==QMessageBox::Yes){
                    newGame();
                }
                else{
                    QApplication::quit();
                }
                return;
            }
        }
    }
}



void saolei::drawBoard()
{
    QPainter painter(this);
    painter.setBrush(Qt::lightGray);
    painter.drawRect( 0,0,width(),height());
}

void saolei::drawItems()
{
    QPainter painter(this);
    painter.setBrush(Qt::lightGray);
    painter.setPen(QPen(QColor(Qt::black),2));

    for(int i=0; i<cols; i++)
    {
        for(int j=0; j<rows; j++)
        {
            drawItem(painter,items[i][j]);
        }
    }
}

void saolei::drawItem(QPainter &painter, Item *pItem)
{
    if(pItem->isMarked)
    {
        if (m_bGameFail)
        {
            //游戏结束，显示为雷
            QRect rcSrc(0,0,flagImage.width(),flagImage.height());
            QRect rcTarget(START_X + pItem->m_pos.x()*RECT_WIDTH + 2,START_Y + pItem->m_pos.y()*RECT_HEIGHT + 2,RECT_WIDTH-4,RECT_HEIGHT-4);
            painter.drawPixmap(rcTarget,bombImage,rcSrc);
        }
        else
        {
            //游戏没结束，显示为旗子
            QRect rcSrc(0,0,flagImage.width(),flagImage.height());
            QRect rcTarget(START_X + pItem->m_pos.x()*RECT_WIDTH + 2,START_Y + pItem->m_pos.y()*RECT_HEIGHT + 2,RECT_WIDTH-4,RECT_HEIGHT-4);
            painter.drawPixmap(rcTarget,flagImage,rcSrc);
        }
        painter.setBrush(Qt::transparent);
        painter.drawRect( START_X + pItem->m_pos.x()*RECT_WIDTH,START_Y + pItem->m_pos.y()*RECT_HEIGHT,RECT_WIDTH,RECT_HEIGHT);
        return;
    }
    else if (pItem->isopen)
    {
        if(pItem->number == 0)
            //如果为0 则为白色
        {
            painter.setBrush(Qt::white);
        }
        else
        {
            QFont font;
            font.setPointSize(20);
            font.setFamily(("msyh"));
            font.setBold(true);

            //float f = pItem->m_nNumber/8;
            //painter.setBrush(QColor(f*255,f*255,0));
            painter.setBrush(Qt::white);
            painter.drawRect( START_X + pItem->m_pos.x()*RECT_WIDTH,
                              START_Y + pItem->m_pos.y()*RECT_HEIGHT,RECT_WIDTH,RECT_HEIGHT);

            painter.setBrush(Qt::black);
            painter.setFont(font);
            painter.drawText( START_X + pItem->m_pos.x()*RECT_WIDTH  + 8,
                              START_Y + pItem->m_pos.y()*RECT_HEIGHT + 22,QString("%1").arg(pItem->number));
            return;
        }
    }
    else
    {
        painter.setBrush(Qt::yellow);

        //调试使用：显示各个雷
//        if (pItem->isMine)
//        {
//            painter.setBrush(Qt::red);
//            painter.drawRect( START_X + pItem->m_pos.x()*RECT_WIDTH,START_Y + pItem->m_pos.y()*RECT_HEIGHT,10,10);
//            return;
//        }
    }
    painter.drawRect( START_X + pItem->m_pos.x()*RECT_WIDTH,START_Y + pItem->m_pos.y()*RECT_HEIGHT,RECT_WIDTH,RECT_HEIGHT);

}

//运气好时点到一个空白元素，可能打开挨着的一大片
void saolei::openEmptyItem(QPoint pt)
{
    //对于空白元素，有上下左右4个方向挨着的空白元素，就打开并继续查找空白元素
    QVector<QPoint> directions;
    directions.push_back(QPoint(-1,0));
    directions.push_back(QPoint(1,0));
    directions.push_back(QPoint(0,-1));
    directions.push_back(QPoint(0,1));
    for (int i=0; i<directions.size(); i++)
    {
        QPoint ptNew = pt + directions[i];
        if (!pointInGameArea(ptNew))
        {
            continue;
        }
        Item* pItem = items[ptNew.x()][ptNew.y()];
        if (!pItem->isMine && !pItem->isopen && !pItem->isMarked && pItem->number >= 0)
        {
            //若不是雷 未被打开 未被标记 且数为0
            //则将其打开
            pItem->isopen = true;

            //对于找到的空白元素，在它的8个方向上有数字元素就打开
            QVector<QPoint> directions2 = directions;
            directions2.push_back(QPoint(-1,-1));
            directions2.push_back(QPoint(1,1));
            directions2.push_back(QPoint(1,-1));
            directions2.push_back(QPoint(-1,1));
            for (int j=0; j<directions2.size(); j++)
            {
                //对四个方向进行递归查看
                QPoint ptNew2 = ptNew + directions2[j];
                if(!pointInGameArea(ptNew2))
                {
                    continue;
                }
                Item* pItem2 = items[ptNew2.x()][ptNew2.y()];
                if (!pItem2->isMine && !pItem2->isopen && !pItem2->isMarked && pItem2->number > 0)
                {
                    //若不是雷 未被打开 未被标记 且数大于0
                    //则将其打开
                    pItem2->isopen = true;
                }
            }
            //递归查找上下左右4个方向的空白元素
            openEmptyItem(ptNew);
        }
    }
}

bool saolei::pointInGameArea(QPoint pt)
{
    if(pt.x()>=0 && pt.x()< cols && pt.y()>=0 && pt.y()< rows)
    {
        return true;
    }
    return false;
}

void saolei::slot_newGame()
{
    qDebug()<<"slot_newGame()";
    newGame();
}

void saolei::slot_level_easy()
{
    rows = 9;
    cols = 9;
    mine = 10;
    newGame();
}

void saolei::slot_level_normal()
{
    rows = 16;
    cols = 16;
    mine = 40;
    newGame();
}

void saolei::slot_level_hard()
{
    rows = 16;
    cols = 30;
    mine = 99;
    newGame();
}

void saolei::slot_level_self()
{
    dialogSelf->show();
}

void saolei::slot_level_self_get()
{
    rows=dialogSelf->getRows();
    cols=dialogSelf->getCols();
    mine=dialogSelf->getMine();
    qDebug()<<rows;
    qDebug()<<cols;
    qDebug()<<mine;
    newGame();

}
