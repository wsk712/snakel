#ifndef SHUERTELEVELSELECTWIDGET_H
#define SHUERTELEVELSELECTWIDGET_H

#include <QWidget>
#include <QDialog>
#include <QButtonGroup>

namespace Ui {
class shuertelevelselectwidget;
}

class shuertelevelselectwidget : public QWidget
{
    Q_OBJECT

public:
    explicit shuertelevelselectwidget(QWidget *parent = nullptr);
    ~shuertelevelselectwidget();
    int GetLevel() {return m_nIndexSelect;}
    private slots:
        void SltButtonClicked(int index);

private:
    Ui::shuertelevelselectwidget *ui;
    int     m_nIndexSelect;
};

#endif // SHUERTELEVELSELECTWIDGET_H
