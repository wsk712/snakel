#ifndef HUARONGDAOGAMEPANELWIDGET_H
#define HUARONGDAOGAMEPANELWIDGET_H

#include<huarongdao.h>
#include <QWidget>

class huarongdaogamepanelwidget : public QWidget
{
    Q_OBJECT
public:
    explicit huarongdaogamepanelwidget(QWidget *parent = 0);
    ~huarongdaogamepanelwidget();

    void SetRows(int row);

    void Start();
    void Stop();

signals:
    void signalWin();

public slots:

private:
    int *m_npDigitalMap;
    int m_nRows;

    bool m_bStart;
private:
    void MoveBlock(int row, int col);
    void CheckWin();
    void InitMapDigital();

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *e);
};

#endif // HUARONGDAOGAMEPANELWIDGET_H
