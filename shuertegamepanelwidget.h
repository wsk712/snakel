#ifndef SHUERTEGAMEPANELWIDGET_H
#define SHUERTEGAMEPANELWIDGET_H

#include<shuerte.h>
#include<QWidget>

class shuertegamepanelwidget:public QWidget
{
    Q_OBJECT
public:
    explicit shuertegamepanelwidget(QWidget *parent=0);
    ~shuertegamepanelwidget();
    void SetRows(int row);
    
    void Start();
    void Stop();
    int correct[16]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    int collect[16]={0};
signals:
    void signalWin();
    public slots:

    private:
        int *m_npDigitalMap;
        int m_nRows;

        int count=0;

        bool m_bStart;
    private:
        void correctBlock(int row, int col);
        void CheckWin();
        void InitMapDigital();

    protected:
        void paintEvent(QPaintEvent *);
        void mousePressEvent(QMouseEvent *e);
    
};

#endif // SHUERTEGAMEPANELWIDGET_H
