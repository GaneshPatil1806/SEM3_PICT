#ifndef ASS1_H
#define ASS1_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class ass1; }
QT_END_NAMESPACE

class ass1 : public QMainWindow
{
    Q_OBJECT

public:
    ass1(QWidget *parent = nullptr);
    ~ass1();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void circle(double ,double ,double);

    void DDA(double,double,double,double);

    void rectangle(int,int,int,int);

    void rhombus(int,int,int,int);

private:
    Ui::ass1 *ui;
};
#endif // ASS1_H
