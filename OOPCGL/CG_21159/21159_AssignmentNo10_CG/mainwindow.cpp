#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <iostream>
using namespace std;
QImage img(600,600,QImage::Format_RGB888);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dist0 = 512;x=0;y = 0;
    dist = dist0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::goToXY(int x, int y)
{
    this->x = x;
    this->y = y;
}

void MainWindow::HilbertA(int level)
{
    if (level > 0)
    {
        HilbertB(level - 1);
        lineRel(0,dist);
        HilbertA(level-1);
        lineRel(dist,0);
        HilbertA(level-1);
        lineRel(0,-dist);
        HilbertC(level - 1);

    }
}

void MainWindow::HilbertB(int level)
{
    if (level > 0){
        HilbertA(level - 1);
        lineRel(dist, 0);
        HilbertB(level - 1);
        lineRel(0, dist);
        HilbertB(level - 1);
        lineRel(-dist, 0);
        HilbertD(level - 1);
    }
}

void MainWindow::HilbertC(int level)
{
    if (level > 0){
        HilbertD(level - 1);
        lineRel(-dist, 0);
        HilbertC(level-1);
        lineRel(0, -dist);
        HilbertC(level-1);
        lineRel(dist,0);
        HilbertA(level-1);
    }
}

void MainWindow::HilbertD(int level)
{
    if (level > 0){
        HilbertC(level-1);
        lineRel(0,-dist);
        HilbertD(level-1);
        lineRel(-dist,0);
        HilbertD(level-1);
        lineRel(0, dist);
        HilbertB(level-1);
    }
}

void MainWindow::display(int x1, int y1, int x2, int y2)
{
    //DDA Line Drawing Algorithm
    float step, dx, dy, i, x, y;
    dx = x2-x1;
    dy = y2-y1;
    if(abs(dx)>=abs(dy))
      {
        step = abs(dx);
      }
    else
      {
        step = abs(dy);
      }
    x = x1;
    y = y1;
    i = 0;
    dx = (dx/step);
    dy = (dy/step);
    while (i<=step)
      {
        img.setPixel((x),(y),qRgb(0,255,255));
        x = x + dx;
        y = y + dy;
        i++;
      }
//    ui->label->setPixmap(QPixmap::fromImage(img));
}
void MainWindow::lineRel(int deltaX, int deltaY)
{
    display(x, y, x+deltaX, y+deltaY);
    cout << x << " " << y <<  " " << x+deltaX << " " << y + deltaY << endl;
    x += deltaX;
    y += deltaY;
}


void MainWindow::on_pushButton_clicked()
{
    int level;
    level = ui->textEdit->toPlainText().toInt();
    for (int i = level; i > 0; i--)
        dist /= 2;
    goToXY(dist/2,dist/2);
    HilbertA(level);
    ui->label->setPixmap(QPixmap::fromImage(img));

}

