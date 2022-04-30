#ifndef HUARONGDAO_H
#define HUARONGDAO_H

#include <QWidget>
#include <QTimer>
#include<snakel.h>

namespace Ui {
class huarongdao;
}

class huarongdao : public QWidget
{
    Q_OBJECT

public:
    explicit huarongdao(QWidget *parent = nullptr);
    ~huarongdao();
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
    Ui::huarongdao *ui;
};

#endif // HUARONGDAO_H
