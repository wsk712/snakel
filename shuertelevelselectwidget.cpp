#include "shuertelevelselectwidget.h"
#include "ui_shuertelevelselectwidget.h"

shuertelevelselectwidget::shuertelevelselectwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::shuertelevelselectwidget),
    m_nIndexSelect(-1)
{
    ui->setupUi(this);
    QButtonGroup *btnGroup = new QButtonGroup(this);
        btnGroup->addButton(ui->btnLevel3, 0);
        btnGroup->addButton(ui->btnLevel4, 1);
        btnGroup->addButton(ui->btnLevel5, 2);
        btnGroup->addButton(ui->btnLevel6, 3);
        btnGroup->addButton(ui->btnRanking, 4);

        connect(btnGroup, SIGNAL(buttonClicked(int)), this, SLOT(SltButtonClicked(int)));
}

shuertelevelselectwidget::~shuertelevelselectwidget()
{
    delete ui;
}

void shuertelevelselectwidget::SltButtonClicked(int index)
{
    m_nIndexSelect = index;
    this->close();
}
