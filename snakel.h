#ifndef SNAKEL_H
#define SNAKEL_H

#include <QMainWindow>
#include<QPushButton>
#include<qpainter.h>
#include<QVector>
#include<qstring.h>
#include<QTime>
#include<QColor>
#include<QMessageBox>
#include<twozerofoureight.h>
#include<QKeyEvent>
#include<saolei.h>
#include<huarongdao.h>
#include<shuerte.h>


QT_BEGIN_NAMESPACE
namespace Ui { class snakel; }
QT_END_NAMESPACE

class snakel : public QMainWindow
{
    Q_OBJECT

public:
    explicit snakel(QWidget *parent = nullptr);
    ~snakel();


    QPushButton *button2048;//2048按钮
    QPushButton *buttonsaolei;//扫雷按钮
    QPushButton *buttonshuerte;//舒尔特方格按钮
    QPushButton *buttonhuarongdao;//数字华容道


public slots://槽函数
    void ensure2048();//2048
    void ensuresaolei();//扫雷
    void ensureshuerte();//舒尔特方格
    void ensurehuarongdao();//数字华容道
private slots:

    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::snakel *ui;

};
#endif // SNAKEL_H
