#include "twozerofoureight.h"
#include "ui_twozerofoureight.h"
#include<qrect.h>
#include<qtimer.h>
#include<QKeyEvent>
#include<QRandomGenerator>
#include<snakel.h>

twozerofoureight::twozerofoureight(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::twozerofoureight)
{
    ui->setupUi(this);
    //初始化
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(size==3)
            {
                lattice_3[i][j]=0;
            }
            else
            {
                lattice_4[i][j]=0;
            }
        }
    }
    //开始按钮
    button=new QPushButton("开始游戏",this);
    button->setGeometry(60,400,200,50);

    //3*3按钮
    size_btn_3 = new QPushButton("3X3");
    size_btn_3->move(50,80);
    size_btn_3->setParent(this);
    size_btn_3->setFixedSize(80,30);
    connect(size_btn_3,SIGNAL(clicked()),this,SLOT(ensureSize3()));

    //4*4按钮
    size_btn_4 = new QPushButton("4X4");
    size_btn_4->move(180,80);
    size_btn_4->setParent(this);
    size_btn_4->setFixedSize(80,30);
    connect(size_btn_4,SIGNAL(clicked()),this,SLOT(ensureSize4()));

    //返回按钮
    re=new QPushButton("返回",this);
    re->setGeometry(230,450,93,29);

    //随机种子
    srand(uint(QTime(0,0,0).secsTo(QTime::currentTime())));

    //槽函数与信号
    connect(button,SIGNAL(clicked()),this,SLOT(slotStart()));
}

twozerofoureight::~twozerofoureight()
{
    delete ui;
}

void twozerofoureight::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.setBrush(Qt::blue);
    p.setFont(QFont("微软雅黑",20,700,false));

    QString strscore;
    p.drawText(QPoint(20,60),"分数："+QString::number(score));//把数字转化为字符串画出来

    //格子的实现
    for (int i=0;i<size ;i++ ) {
        for(int j=0;j<size;j++){
            p.setPen(Qt::transparent);
            int value;
            if(size==3)
            {
                value=lattice_3[i][j];
            }
            else
            {
                value=lattice_4[i][j];
            }

            if(value==0){
                p.setBrush(Qt::gray);
                p.drawRect(i*60+40,j*60+120,55,55);
            }
            else if(value==2){
                p.setBrush(QColor(255,160,122));
                p.drawRect(i*60+40,j*60+120,55,55);
                p.setPen(Qt::black);
                p.setFont(QFont("微软雅黑",10,700,false));
                //在方格中 绘制Text,并且使文本位置位于中部
                p.drawText(QRectF(i*60+40,j*60+120,55,55),QString::number(2),QTextOption(Qt::AlignCenter));
            }
            else if(value==4){
                p.setBrush(QColor(250,128,114));
                p.drawRect(i*60+40,j*60+120,55,55);
                p.setPen(Qt::black);
                p.setFont(QFont("微软雅黑",10,700,false));
                //在方格中 绘制Text,并且使文本位置位于中部
                p.drawText(QRectF(i*60+40,j*60+120,55,55),QString::number(4),QTextOption(Qt::AlignCenter));
            }
            else if(value==8){
                p.setBrush(QColor(255,165,0));
                p.drawRect(i*60+40,j*60+120,55,55);
                p.setPen(Qt::black);
                p.setFont(QFont("微软雅黑",10,700,false));
                //在方格中 绘制Text,并且使文本位置位于中部
                p.drawText(QRectF(i*60+40,j*60+120,55,55),QString::number(8),QTextOption(Qt::AlignCenter));
            }
            else if(value==16){
                p.setBrush(QColor(255,140,0));
                p.drawRect(i*60+40,j*60+120,55,55);
                p.setPen(Qt::black);
                p.setFont(QFont("微软雅黑",10,700,false));
                //在方格中 绘制Text,并且使文本位置位于中部
                p.drawText(QRectF(i*60+40,j*60+120,55,55),QString::number(16),QTextOption(Qt::AlignCenter));
            }
            else if(value==32){
                p.setBrush(QColor(255,127,80));
                p.drawRect(i*60+40,j*60+120,55,55);
                p.setPen(Qt::black);
                p.setFont(QFont("微软雅黑",10,700,false));
                //在方格中 绘制Text,并且使文本位置位于中部
                p.drawText(QRectF(i*60+40,j*60+120,55,55),QString::number(32),QTextOption(Qt::AlignCenter));
            }
            else if(value==64){
                p.setBrush(QColor(255,99,71));
                p.drawRect(i*60+40,j*60+120,55,55);
                p.setPen(Qt::black);
                p.setFont(QFont("微软雅黑",10,700,false));
                //在方格中 绘制Text,并且使文本位置位于中部
                p.drawText(QRectF(i*60+40,j*60+120,55,55),QString::number(64),QTextOption(Qt::AlignCenter));
            }
            else if(value==128){
                p.setBrush(QColor(255,69,0));
                p.drawRect(i*60+40,j*60+120,55,55);
                p.setPen(Qt::black);
                p.setFont(QFont("微软雅黑",10,700,false));
                //在方格中 绘制Text,并且使文本位置位于中部
                p.drawText(QRectF(i*60+40,j*60+120,55,55),QString::number(128),QTextOption(Qt::AlignCenter));
            }
            else if(value==256){
                p.setBrush(QColor(255,0,0));
                p.drawRect(i*60+40,j*60+120,55,55);
                p.setPen(Qt::black);
                p.setFont(QFont("微软雅黑",10,700,false));
                //在方格中 绘制Text,并且使文本位置位于中部
                p.drawText(QRectF(i*60+40,j*60+120,55,55),QString::number(256),QTextOption(Qt::AlignCenter));
            }
            else if(value==512){
                p.setBrush(QColor(238,59,59));
                p.drawRect(i*60+40,j*60+120,55,55);
                p.setPen(Qt::black);
                p.setFont(QFont("微软雅黑",10,700,false));
                //在方格中 绘制Text,并且使文本位置位于中部
                p.drawText(QRectF(i*60+40,j*60+120,55,55),QString::number(512),QTextOption(Qt::AlignCenter));
            }
            else if(value==1024){
                p.setBrush(QColor(205,51,51));
                p.drawRect(i*60+40,j*60+120,55,55);
                p.setPen(Qt::black);
                p.setFont(QFont("微软雅黑",10,700,false));
                //在方格中 绘制Text,并且使文本位置位于中部
                p.drawText(QRectF(i*60+40,j*60+120,55,55),QString::number(1024),QTextOption(Qt::AlignCenter));
            }
            else if(value==2048){
                p.setBrush(QColor(139,35,35));
                p.drawRect(i*60+40,j*60+120,55,55);
                p.setPen(Qt::black);
                p.setFont(QFont("微软雅黑",10,700,false));
                //在方格中 绘制Text,并且使文本位置位于中部
                p.drawText(QRectF(i*60+40,j*60+120,55,55),QString::number(2048),QTextOption(Qt::AlignCenter));
            }
            else {
                if(size==3)
                {
                    p.setBrush(Qt::blue);
                    p.drawRect(i*60+40,j*60+120,55,55);
                    p.setPen(Qt::black);
                    p.setFont(QFont("微软雅黑",10,700,false));
                    //在方格中 绘制Text,并且使文本位置位于中部
                    p.drawText(QRectF(i*60+40,j*60+120,55,55),QString::number(lattice_3[i][j]),QTextOption(Qt::AlignCenter));
                }
                else
                {
                    p.setBrush(Qt::blue);
                    p.drawRect(i*60+40,j*60+120,55,55);
                    p.setPen(Qt::black);
                    p.setFont(QFont("微软雅黑",10,700,false));
                    //在方格中 绘制Text,并且使文本位置位于中部
                    p.drawText(QRectF(i*60+40,j*60+120,55,55),QString::number(lattice_4[i][j]),QTextOption(Qt::AlignCenter));
                }

            }
        }

    }
}

void twozerofoureight::keyPressEvent(QKeyEvent *event)
{
    if(!state){
        return;
    }
    switch(event->key()){
    case Qt::Key_W:
        PressUp();
        break;
    case Qt::Key_S:
        PressDown();
        break;
    case Qt::Key_A:
        PressLeft();
        break;
    case Qt::Key_D:
        PressRight();
        break;
    default:
        return;//忽略其他按钮
    }
    myRand();//检测有没有空的格子，有的话就生成一个2，没有就游戏结束
    update();//强制页面刷新
}
void twozerofoureight::slotStart()
{
    //游戏开始 或 游戏重新开始的 函数
    QMessageBox::about(this,"游戏规则","WSAD控制方块上下左右移动");
    if(size==0)
    {
        QMessageBox::warning(this,"提示！","请先选择游戏类型！");
        return;
    }
    score=0;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(size==3)
            {
                lattice_3[i][j]=0;
            }
            else
            {
                lattice_4[i][j]=0;
            }
        }
    }

    button->setText("重新游戏");

    int randi=QRandomGenerator::global()->bounded(size);
    int randj=QRandomGenerator::global()->bounded(size);
    if(size==3)
    {
        lattice_3[randi][randj]=2;
    }
    else
    {
        lattice_4[randi][randj]=2;
    }
    state=true;
    update();
}

void twozerofoureight::ensureSize3()
{
    size = 3;
    //button->setText("开始游戏");
}

void twozerofoureight::ensureSize4()
{
    size = 4;
    //button->setText("开始游戏");
}
void twozerofoureight::PressUp()
{
    //移动
    for(int i=0;i<size;i++){
        for(int j=1;j<size;j++){
            // 3*3
            if(size==3)
            {
                if(lattice_3[i][j] == 0)  // 为0跳过
                continue;
                for(int p=0;p<j;p++)
                {
                    //查看前面是否有格子移动
                    if(lattice_3[i][p] == 0)
                    {
                        lattice_3[i][p]=lattice_3[i][j];
                        lattice_3[i][j]=0;
                        break;
                    }
                }
            }
            else
            {
                if(lattice_4[i][j] == 0)  // 为0跳过
                continue;
                for(int p=0;p<j;p++)
                {
                    //查看前面是否有格子移动
                    if(lattice_4[i][p] == 0)
                    {
                        lattice_4[i][p]=lattice_4[i][j];
                        lattice_4[i][j]=0;
                        break;
                    }
                }
            }
        }
    }

    //相加
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(size==3)
            {
                if(lattice_3[i][j]==lattice_3[i][j+1]){
                    lattice_3[i][j]=2*lattice_3[i][j];
                    lattice_3[i][j+1]=0;
                    score+=lattice_3[i][j];
                    for(int p=j+2;p<4;p++)
                    {
                        lattice_3[i][p-1]=lattice_3[i][p];
                    }
                }
            }
            else
            {
                if(lattice_4[i][j]==lattice_4[i][j+1]){
                    lattice_4[i][j]=2*lattice_4[i][j];
                    lattice_4[i][j+1]=0;
                    score+=lattice_4[i][j];
                    for(int p=j+2;p<4;p++)
                    {
                        lattice_4[i][p-1]=lattice_4[i][p];
                    }
                }
            }
        }
    }

}

    void twozerofoureight::PressDown()
    {
        //移动
        for(int i=0;i<size;i++){
            for(int j=2;j>=0;j--){
                if(size==3)
                {
                    if(lattice_3[i][j] == 0)  // 为0跳过
                    continue;
                    for(int p=2;p>j;p--)
                    {
                        //查看前面是否有格子移动
                        if(lattice_3[i][p]==0)
                        {
                            lattice_3[i][p]=lattice_3[i][j];
                            lattice_3[i][j]=0;
                            break;
                        }
                    }
                }
                else
                {
                    if(lattice_4[i][j] == 0)  // 为0跳过
                    continue;
                    for(int p=3;p>j;p--)
                    {
                        //查看前面是否有格子移动
                        if(lattice_4[i][p]==0)
                        {
                            lattice_4[i][p]=lattice_4[i][j];
                            lattice_4[i][j]=0;
                            break;
                        }
                    }

                }

            }
        }

        //相加
        for(int i=0;i<size;i++){
            for(int j=size-1;j>0;j--){
                if(size==4)
                {
                    if(lattice_4[i][j]==lattice_4[i][j-1]){
                        lattice_4[i][j]=2*lattice_4[i][j];
                        lattice_4[i][j-1]=0;
                        score+=lattice_4[i][j];
                        for(int p=j-2;p>=0;p--)
                        {
                            lattice_4[i][p+1]=lattice_4[i][p];
                        }
                    }
                }
                else
                {
                    if(lattice_3[i][j]==lattice_3[i][j-1]){
                        lattice_3[i][j]=2*lattice_3[i][j];
                        lattice_3[i][j-1]=0;
                        score+=lattice_3[i][j];
                        for(int p=j-2;p>=0;p--)
                        {
                            lattice_3[i][p+1]=lattice_3[i][p];
                        }
                    }
                }
            }
        }
    }

    void twozerofoureight::PressLeft()
    {
        //移动
        for(int j=0;j<size;j++){
            for(int i=1;i>=size;i++){
                if(size==4)
                {
                    if(lattice_4[i][j]==0)continue;
                    for(int p=0;p<i;p++)
                    {
                        //查看前面是否有格子移动
                        if(lattice_4[p][j]==0)
                        {
                            lattice_4[p][j]=lattice_4[i][j];
                            lattice_4[i][j]=0;
                            break;
                        }
                    }
                }
                else
                {
                    if(lattice_3[i][j]==0)continue;
                    for(int p=0;p<i;p++)
                    {
                        //查看前面是否有格子移动
                        if(lattice_3[p][j]==0)
                        {
                            lattice_3[p][j]=lattice_3[i][j];
                            lattice_3[i][j]=0;
                            break;
                        }
                    }
                }
            }
        }

        //相加
        for(int j=0;j<size;j++){
            for(int i=0;i<size-1;i++){
                if(size==4)
                {
                    if(lattice_4[i][j]==lattice_4[i+1][j]){
                        lattice_4[i][j]=2*lattice_4[i][j];
                        lattice_4[i+1][j]=0;
                        score+=lattice_4[i][j];
                        for(int p=i+2;p<4;p++)
                        {
                            lattice_4[p-1][j]=lattice_4[p][j];
                        }
                    }
                }
                else
                {
                    if(lattice_3[i][j]==lattice_3[i+1][j]){
                        lattice_3[i][j]=2*lattice_3[i][j];
                        lattice_3[i+1][j]=0;
                        score+=lattice_3[i][j];
                        for(int p=i+2;p<size;p++)
                        {
                            lattice_3[p-1][j]=lattice_3[p][j];
                        }
                    }
                }
            }
        }
    }

    void twozerofoureight::PressRight()
    {
        //移动
        for(int j=0;j<size;j++){
            for(int i=size-2;i>=0;i--){
                if(size==4)
                {
                    if(lattice_4[i][j]==0)continue;
                    for(int p=3;p>j;p--)
                    {
                        //查看前面是否有格子移动
                        if(lattice_4[p][j]==0)
                        {
                            lattice_4[p][j]=lattice_4[i][j];
                            lattice_4[i][j]=0;
                            break;
                        }
                    }
                }
                else
                {
                    if(lattice_3[i][j]==0)continue;
                    for(int p=2;p>j;p--)
                    {
                        //查看前面是否有格子移动
                        if(lattice_3[p][j]==0)
                        {
                            lattice_3[p][j]=lattice_3[i][j];
                            lattice_3[i][j]=0;
                            break;
                        }
                    }
                }
            }
        }

        //相加
        for(int j=0;j<size;j++){
            for(int i=size-1;i>0;i--){
                if(size==4)
                {
                    if(lattice_4[i][j]==lattice_4[i-1][j]){
                        lattice_4[i][j]=2*lattice_4[i][j];
                        lattice_4[i-1][j]=0;
                        score+=lattice_4[i][j];
                        for(int p=i-2;p>=0;p--)
                        {
                            lattice_4[p+1][j]=lattice_4[p][j];
                        }
                    }
                }
                else
                {
                    if(lattice_3[i][j]==lattice_3[i-1][j]){
                        lattice_3[i][j]=2*lattice_3[i][j];
                        lattice_3[i-1][j]=0;
                        score+=lattice_3[i][j];
                        for(int p=i-2;p>=0;p--)
                        {
                            lattice_3[p+1][j]=lattice_3[p][j];
                        }
                    }
                }
            }
        }
    }

    void twozerofoureight::myRand()
    {
        //首先找出空的格子
        int i=0;
        int j=0;
        //找出格子
        struct Position site_3[9];
        struct Position site_4[16];
        int ni=0;//几个空的格子
        for(i=0;i<size;i++)
        {
            for(j=0;j<size;j++)
            {
                if(size==3)
                {
                    if(lattice_3[i][j]==0)
                    {
                        site_3[ni].i=i;
                        site_3[ni].j=j;
                        ni++;
                    }
                }
                else
                {
                    if(lattice_4[i][j]==0)
                    {
                        site_4[ni].i=i;
                        site_4[ni].j=j;
                        ni++;
                    }
                }
            }
        }
        //判断游戏是否结束
        if(ni==0)
        {
            for(i=0;i<size;i++)
            {
                for(j=0;j<size-1;j++)
                {
                    if(size==3)
                    {
                        if(lattice_3[i][j]==lattice_3[i][j+1])
                        {
                            return;
                        }
                    }
                    else
                    {
                        if(lattice_4[i][j]==lattice_4[i][j+1])
                        {
                            return;
                        }
                    }
                }
            }
            for(j=0;j<4;j++)
            {
                for(i=0;i<3;i++)
                {
                    if(size==3)
                    {
                        if(lattice_3[i][j]==lattice_3[i+1][j])
                        {
                            return;
                        }
                    }
                    else
                    {
                        if(lattice_4[i][j]==lattice_4[i+1][j])
                        {
                            return;
                        }
                    }
                }
            }
            QMessageBox::about(this,"游戏失败","分数为："+QString::number(score)+"");
            return ;
        }
        //在随机的格子里生成一个2
        int rand=QRandomGenerator::global()->bounded(ni);
        if(size==3)
        {
            lattice_3[site_3[rand].i][site_3[rand].j]=2;
        }
        else
        {
            lattice_4[site_4[rand].i][site_4[rand].j]=2;
        }
    }






void twozerofoureight::on_pushButton_clicked()
{
    snakel *fater=new snakel();
    this->close();
    fater->show();

}
