#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void goToXY(int x, int y);
    void display(int x1, int y1, int x2, int y2);
    void HilbertA(int level);
    void HilbertB(int level);
    void HilbertC(int level);
    void HilbertD(int level);
    void lineRel(int deltaX, int deltaY);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    int dist0,x,y,dist;
};
#endif // MAINWINDOW_H
