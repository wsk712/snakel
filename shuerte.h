#ifndef SHUERTE_H
#define SHUERTE_H

#include <QWidget>
#include <QTimer>
#include<snakel.h>

namespace Ui {
class shuerte;
}

class shuerte : public QWidget
{
    Q_OBJECT

public:
    explicit shuerte(QWidget *parent = nullptr);
    ~shuerte();
private slots:
    void on_btnStart_clicked();

private:

    QTimer  *m_timer;
    quint32  m_nTimeCnts;

private slots:
    void SltTimeCount();
    void SltWinTheGame();
    void on_btnLevelSelect_clicked();

private:
    Ui::shuerte *ui;
};

#endif // SHUERTE_H
