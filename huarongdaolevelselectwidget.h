#ifndef HUARONGDAOLEVELSELECTWIDGET_H
#define HUARONGDAOLEVELSELECTWIDGET_H

#include <QWidget>
#include <QDialog>
#include <QButtonGroup>


namespace Ui {
class huarongdaolevelselectwidget;
}

class huarongdaolevelselectwidget : public QWidget
{
    Q_OBJECT

public:
    explicit huarongdaolevelselectwidget(QWidget *parent = nullptr);
    ~huarongdaolevelselectwidget();

    int GetLevel() {return m_nIndexSelect;}
    private slots:
        void SltButtonClicked(int index);

private:
    Ui::huarongdaolevelselectwidget *ui;
    int     m_nIndexSelect;
};

#endif // HUARONGDAOLEVELSELECTWIDGET_H
