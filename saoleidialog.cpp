#include "saoleidialog.h"
#include "ui_saoleidialog.h"

#include <QDebug>


saoleiDialog::saoleiDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::saoleiDialog)
{
    ui->setupUi(this);
    edit_row=new QLineEdit(this);
        edit_col=new QLineEdit(this);
        edit_mine=new QLineEdit(this);

        label_row=new QLabel("行数:",this);
        label_col=new QLabel("列数:",this);
        label_mine=new QLabel("雷数:",this);

        edit_col->move(150,30);
        edit_row->move(150,70);
        edit_mine->move(150,110);

        label_col->move(100,30);
        label_row->move(100,70);
        label_mine->move(100,110);

        up=new QPushButton("确定",this);
        up->move(150,150);
        connect(up,SIGNAL(clicked()),this,SLOT(up_all()));

}

saoleiDialog::~saoleiDialog()
{
    delete ui;
}

void saoleiDialog::setRows(int rows)
{
    this->rows=rows;
}

void saoleiDialog::setCols(int cols)
{
    this->cols=cols;
}

void saoleiDialog::setMine(int mine)
{
    this->mine=mine;
}

int saoleiDialog::getRows()
{
    return rows;
}

int saoleiDialog::getCols()
{
    return cols;
}

int saoleiDialog::getMine()
{
    return mine;
}

void saoleiDialog::up_all()
{
    qDebug()<<"up_all";
    rows=edit_row->text().toInt();
    cols=edit_col->text().toInt();
    mine=edit_mine->text().toInt();

    emit(dia_test());

    this->close();
}
