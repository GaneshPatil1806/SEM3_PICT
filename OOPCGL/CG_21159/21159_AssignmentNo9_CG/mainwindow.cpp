#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cmath"
QImage img(400, 400, QImage::Format_RGB888);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::dda(float x1, float y1, float x2, float y2)
{
    float dx, dy, length;
    float xinc, yinc;
    float x, y;
    dx = x2-x1;
    dy = y2-y1;
    if(abs(dx)>abs(dy))
    {
        length = abs(dx);
    }
    else
    {
        length = abs(dy);
    }
    xinc = dx/length;
    yinc = dy/length;
    x = x1;
    y = y1;
    for(int i=0; i<length; i++){
        img.setPixel(x,y,qRgb(255, 255, 255));
        x += xinc;
        y += yinc;
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::dda2(float x1, float y1, float x2, float y2)
{
    float dx, dy, length;
    float xinc, yinc;
    float x, y;
    dx = x2-x1;
    dy = y2-y1;
    if(abs(dx)>abs(dy)){
        length = abs(dx);
    }else{
        length = abs(dy);
    }
    xinc = dx/length;
    yinc = dy/length;
    x = x1;
    y = y1;
    for(int i=0; i<length; i++){
        img.setPixel(x,y,qRgb(0, 0, 0));
        x += xinc;
        y += yinc;
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::Window()
{
    dda(200, 0, 200, 400);
    dda(0, 200, 400, 200);
}

void MainWindow::Triangle(float x1, float y1, float x2, float y2, float x3, float y3)
{
    dda(x1+200, y1+200, x2+200, y2+200);
    dda(x2+200, y2+200, x3+200, y3+200);
    dda(x3+200, y3+200, x1+200, y1+200);
}

void MainWindow::Clear()
{
    for (int y=0; y<400; y++){
        dda2(0,y,400,y);
        void Window();
    }
}


void MainWindow::on_pushButton_clicked()
{
//    Clear();
//    Window();

    float tx, ty;
    tx = ui->textEdit->toPlainText().toFloat();
    ty = ui->textEdit_2->toPlainText().toFloat();

//    float x1, y1, x2, y2, x3, y3;
    X1 = X1+tx;
    Y1 = Y1-ty;
    X2 = X2+tx;
    Y2 = Y2-ty;
    X3 = X3+tx;
    Y3 = Y3-ty;

    Triangle(X1, Y1, X2, Y2, X3, Y3);
}

void MainWindow::on_pushButton_4_clicked()
{
    Window();

//    X1 = 50;
//    Y1 = 50;
//    X2 = 100;
//    Y2 = 50;
//    X3 = 100;
//    Y3 = 100;

    X1 = ui->textEdit_6->toPlainText().toFloat();
    Y1 = ui->textEdit_9->toPlainText().toFloat();
    X2 = ui->textEdit_7->toPlainText().toFloat();
    Y2 = ui->textEdit_10->toPlainText().toFloat();
    X3 = ui->textEdit_8->toPlainText().toFloat();
    Y3 = ui->textEdit_11->toPlainText().toFloat();

    Triangle(X1, Y1, X2, Y2, X3, Y3);
}

void MainWindow::on_pushButton_3_clicked()
{
//    Clear();
//    Window();

    float sx, sy;
    sx = ui->textEdit_4->toPlainText().toFloat();
    sy = ui->textEdit_5->toPlainText().toFloat();

//    float x1, y1, x2, y2, x3, y3;
    X1 = X1*sx;
    Y1 = Y1*sy;
    X2 = X2*sx;
    Y2 = Y2*sy;
    X3 = X3*sx;
    Y3 = Y3*sy;
    Triangle(X1, Y1, X2, Y2, X3, Y3);
}

void MainWindow::on_pushButton_2_clicked()
{
//    Clear();
//    Window();

    float angle, requiredAngle;
    angle = ui->textEdit_3->toPlainText().toFloat();
    requiredAngle = (0.0174533*angle);

    float x1, y1, x2, y2, x3, y3;
    x1 = -Y1*sin(requiredAngle)+X1*cos(requiredAngle);
    y1 = X1*sin(requiredAngle)+Y1*cos(requiredAngle);
    x2 = -Y2*sin(requiredAngle)+X2*cos(requiredAngle);
    y2 = X2*sin(requiredAngle)+Y2*cos(requiredAngle);
    x3 = -Y3*sin(requiredAngle)+X3*cos(requiredAngle);
    y3 = X3*sin(requiredAngle)+Y3*cos(requiredAngle);

    X1 = x1;
    X2 = x2;
    X3 = x3;
    Y1 = y1;
    Y2 = y2;
    Y3 = y3;

    Triangle(X1, Y1, X2, Y2, X3, Y3);
}
