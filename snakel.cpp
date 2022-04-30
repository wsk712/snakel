#include "snakel.h"
#include "ui_snakel.h"
#include<qrect.h>
#include<qtimer.h>
#include<QKeyEvent>
#include<QRandomGenerator>
#include<qpainter.h>

snakel::snakel(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::snakel)
{
    ui->setupUi(this);

    //开始按钮
    button2048=new QPushButton("2048",this);
    button2048->setGeometry(110,150,93,29);
    button2048->setStyleSheet("QPushButton{font: 25 14pt '微软雅黑 Light';color: rgb(255,255,255);background-color: rgb(255,245,238);"
                                                                      "border: 2px groove gray;border-radius:15px;padding:2px 4px;border-style: outset;}"
                                                                      "QPushButton:hover{background-color: rgb(22,218,208);}"//hover
                                                                      "QPushButton:pressed{background-color: rgb(17,171,164);}"//pressed
                                                                        "border:2px solid rgb(20,196,188);");//边框粗细-颜色-圆角设置


    buttonsaolei=new QPushButton("扫雷",this);
    buttonsaolei->setGeometry(110,200,93,29);

    buttonshuerte=new QPushButton("数字华容道",this);
    buttonshuerte->setGeometry(110,250,93,29);

    buttonhuarongdao=new QPushButton("舒尔特方格",this);
    buttonhuarongdao->setGeometry(110,300,93,29);

    //2048按钮
    connect(button2048,SIGNAL(clicked()),this,SLOT(ensure2048()));

    //扫雷按钮
    connect(buttonsaolei,SIGNAL(clicked()),this,SLOT(ensuresaolei()));

    //舒尔特方格按钮
    connect(buttonshuerte,SIGNAL(clicked()),this,SLOT(ensureshuerte()));

    //数字华容道按钮
    connect(buttonhuarongdao,SIGNAL(clicked()),this,SLOT(ensurehuarongdao()));


}

snakel::~snakel()
{
    delete ui;
}

void snakel::ensure2048()
{
    this->close();//关闭当前界面，也就是父界面
    twozerofoureight *pic=new twozerofoureight();
    pic->show();

}

void snakel::ensuresaolei()
{
    this->close();//关闭当前界面，也就是父界面
    saolei *pic=new saolei();
    pic->show();

}

void snakel::ensurehuarongdao()
{
    this->close();//关闭当前界面，也就是父界面
    shuerte *pic=new shuerte();
    pic->show();
    this->close();//关闭当前界面，也就是父界面

}

void snakel::ensureshuerte()
{

    huarongdao *pic=new huarongdao();
    //huarongdaolevelselectwidget *pi=new huarongdaolevelselectwidget();
    pic->show();
    //pi->show();

}



