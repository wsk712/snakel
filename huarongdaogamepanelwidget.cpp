
#include<huarongdaogamepanelwidget.h>

#include <QTime>
#include <QPainter>
#include <QDebug>
#include <QMouseEvent>
#include<snakel.h>

#define BLOCK_SPACE     2

huarongdaogamepanelwidget::huarongdaogamepanelwidget(QWidget *parent) : QWidget(parent),
    m_nRows(4)
{
    SetRows(m_nRows);
    m_bStart = false;
}

huarongdaogamepanelwidget::~huarongdaogamepanelwidget()
{

}

void huarongdaogamepanelwidget::SetRows(int row)
{
    if (row < 2 || row > 10) return;

    if (NULL != m_npDigitalMap) {
        delete [] m_npDigitalMap;
    }

    m_nRows = row;
    m_npDigitalMap = new int[m_nRows * m_nRows];
    memset(m_npDigitalMap, 0x00, sizeof(int) * m_nRows * m_nRows);
    for (int i = 0; i < m_nRows; i++) {
        for (int j = 0; j < m_nRows; j++) {
            m_npDigitalMap[j * m_nRows + i] =  (i * m_nRows + j + 1);
        }
    }

    m_npDigitalMap[m_nRows * m_nRows - 1] = 0x00;

    m_bStart = false;
    this->update();
}

void huarongdaogamepanelwidget::Start()
{
    m_bStart = true;
    InitMapDigital();
}

void huarongdaogamepanelwidget::Stop()
{
    m_bStart = false;
}

void huarongdaogamepanelwidget::MoveBlock(int row, int col)
{
    int value = m_npDigitalMap[col * m_nRows + row];
    // 判断上边
    if (0 == m_npDigitalMap[col * m_nRows + row - 1] && row > 0) {
        m_npDigitalMap[col * m_nRows + row] = 0;
        m_npDigitalMap[col * m_nRows + row - 1] = value;
    }
    // 判断下边
    else if (0 == m_npDigitalMap[col * m_nRows + row + 1] && row < (m_nRows - 1)) {
        m_npDigitalMap[col * m_nRows + row] = 0;
        m_npDigitalMap[col * m_nRows + row + 1] = value;
    }
    // 判断左边
    else if (0 == m_npDigitalMap[(col - 1) * m_nRows + row] && col > 0) {
        m_npDigitalMap[col * m_nRows + row] = 0;
        m_npDigitalMap[(col - 1) * m_nRows + row] = value;
    }
    // 判断右边
    else if (0 == m_npDigitalMap[(col + 1) * m_nRows + row] && col < (m_nRows - 1)) {
        m_npDigitalMap[col * m_nRows + row] = 0;
        m_npDigitalMap[(col + 1) * m_nRows + row] = value;
    }

    // 检测游戏状态
    CheckWin();

    this->update();
}

void huarongdaogamepanelwidget::CheckWin()
{
    bool bOk = true;
    for (int i = 0; i < m_nRows; i++) {
        for (int j = 0; j < m_nRows; j++) {
            int value = m_npDigitalMap[j * m_nRows + i];
            if (i == (m_nRows - 1) && (j == (m_nRows - 1)) && 0 == value) {
                qDebug() << "yes you win";
                emit signalWin();
                m_bStart = false;
                break;
            }

            if (value != (i * m_nRows + j + 1)) {
                bOk = false;
                break;
            }
        }

        if (!bOk) break;
    }
}

void huarongdaogamepanelwidget::InitMapDigital()
{
    memset(m_npDigitalMap, 0x00, sizeof(int) * m_nRows * m_nRows);

    /*生成1-4的随机数*/
    QTime time = QTime::currentTime();
    srand(time.msec() + time.second() * 1000);
    int nCnt = 0;
    while (1) {
        int result = (rand() % (m_nRows * m_nRows - 1)) + 1;
        bool bOk = false;
        for (int i = 0; i < m_nRows; i++) {
            for (int j = 0; j < m_nRows; j++) {
                int value = m_npDigitalMap[j * m_nRows + i];
                if (result == value) {
                    bOk = true;
                    break;
                }
            }
        }

        if (!bOk) {
            m_npDigitalMap[nCnt] = result;
            nCnt++;
        }

        if (nCnt >= (m_nRows * m_nRows - 1)) break;
    }

    this->update();
}

void huarongdaogamepanelwidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing, true);
    painter.setPen(QColor("#999999"));
    painter.setBrush(QColor("#40180c"));
    painter.drawRect(1, 1, this->width() - 2, this->height() - 2);

    int nBlockW = (this->width() - 2 - 10 - (m_nRows - 1) * BLOCK_SPACE) / m_nRows;
    qreal offset = (this->width() - (m_nRows - 1) * BLOCK_SPACE - m_nRows * nBlockW) / 2;
    QFont font("Algerian");
    font.setPixelSize(nBlockW * 0.6);
    painter.setFont(font);

    QRect rect(0, 0, nBlockW, nBlockW);
    for (int i = 0; i < m_nRows; i++) {
        for (int j = 0; j < m_nRows; j++) {
            int value = m_npDigitalMap[j * m_nRows + i];
            if (value != 0) {
                rect.setX(j * nBlockW + (j * BLOCK_SPACE) + offset);
                rect.setY(i * nBlockW + (i * BLOCK_SPACE) + offset);
                rect.setWidth(nBlockW);
                rect.setHeight(nBlockW);
                painter.setPen(Qt::NoPen);
                painter.setBrush(QColor("#e5b88e"));
                painter.drawRect(rect);

                painter.setPen("#8b5531");
                painter.drawText(rect, Qt::AlignCenter, QString::number(value));
            }
        }
    }
}

void huarongdaogamepanelwidget::mousePressEvent(QMouseEvent *e)
{
    if (!m_bStart) return;
    if (Qt::RightButton == e->button()) {
        return;
    }

    int nBlockW = (this->width() - 2 - 10 - (m_nRows - 1) * BLOCK_SPACE) / m_nRows;
    QRect rect(0, 0, nBlockW, nBlockW);
    for (int i = 0; i < m_nRows; i++) {
        for (int j = 0; j < m_nRows; j++) {
            int value = m_npDigitalMap[j * m_nRows + i];
            if (value != 0) {
                rect.setX(j * nBlockW + (j * BLOCK_SPACE) + 5);
                rect.setY(i * nBlockW + (i * BLOCK_SPACE) + 5);
                rect.setWidth(nBlockW);
                rect.setHeight(nBlockW);

                if (rect.contains(e->pos())) {
                    MoveBlock(i, j);
                }
            }
        }
    }
}
