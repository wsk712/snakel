#ifndef SAOLEIDIALOG_H
#define SAOLEIDIALOG_H

#include <QWidget>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>


namespace Ui {
class saoleiDialog;
}

class saoleiDialog : public QWidget
{
    Q_OBJECT

public:
    explicit saoleiDialog(QWidget *parent = nullptr);
    ~saoleiDialog();

private:
    Ui::saoleiDialog *ui;
    QPushButton *up;
    int rows;
    int cols;
    int mine;
public:
    void setRows(int rows);
    void setCols(int cols);
    void setMine(int mine);

    int getRows();
    int getCols();
    int getMine();

    QLineEdit *edit_row;
    QLineEdit *edit_col;
    QLineEdit *edit_mine;

    QLabel *label_row;
    QLabel *label_col;
    QLabel *label_mine;


signals:
        void dia_test();

public slots:
        void up_all();




};

#endif // SAOLEIDIALOG_H
