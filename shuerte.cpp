#include "shuerte.h"
#include "ui_shuerte.h"

#include<snakel.h>
#include <QTime>
#include <QMessageBox>
#include<shuertegamepanelwidget.h>
#include<shuertelevelselectwidget.h>
#include"ui_shuertelevelselectwidget.h"

shuerte::shuerte(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::shuerte)
{
    ui->setupUi(this);
    m_timer = new QTimer(this);
        m_timer->setInterval(1000);

        // 关联信号槽
        connect(m_timer, SIGNAL(timeout()), this, SLOT(SltTimeCount()));
        connect(ui->widgetGamePanel, SIGNAL(signalWin()), this, SLOT(SltWinTheGame()));
}

shuerte::~shuerte()
{
    delete ui;
}

void shuerte::on_btnStart_clicked()
{
    if (m_timer->isActive()) {
        m_timer->stop();
        ui->widgetGamePanel->Stop();
    }
    else {
        m_nTimeCnts = 0;
        m_timer->start();
        ui->widgetGamePanel->Start();
    }
}

void shuerte::SltTimeCount()
{
    m_nTimeCnts++;

    // 计算当前时分秒
    quint8 nHour = (m_nTimeCnts / 3600);
    quint8 nMin = (m_nTimeCnts % 3600) / 60;
    quint8 nSec = (m_nTimeCnts % 3600) % 60;
    ui->labelTimes->setText(QString("%1:%2:%3").arg(nHour, 2, 10, QChar('0')).
                         arg(nMin, 2, 10, QChar('0')).
                         arg(nSec, 2, 10, QChar('0')));
}

void shuerte::SltWinTheGame()
{
    if (m_timer->isActive()) m_timer->stop();

    quint8 nHour = (m_nTimeCnts / 3600);
    quint8 nMin = (m_nTimeCnts % 3600) / 60;
    quint8 nSec = (m_nTimeCnts % 3600) % 60;

    QString strTimes = QString("%1:%2:%3").arg(nHour, 2, 10, QChar('0')).
            arg(nMin, 2, 10, QChar('0')).
            arg(nSec, 2, 10, QChar('0'));

    QMessageBox::information(this, tr("恭喜你"), tr("恭喜你，你完成了游戏，用时[%1].").arg(strTimes));
}

void shuerte::on_btnLevelSelect_clicked()
{
    shuertelevelselectwidget *levelDialog = new shuertelevelselectwidget(this);
    levelDialog->show();
    int nlevel = levelDialog->GetLevel();
    if (-1 != nlevel && nlevel < 4) {
        if (m_timer->isActive()) m_timer->stop();
        ui->widgetGamePanel->SetRows(3 + nlevel);
    }

    delete levelDialog;
    levelDialog = NULL;
}
