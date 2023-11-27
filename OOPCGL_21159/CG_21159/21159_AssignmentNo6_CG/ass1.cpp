#include "ass1.h"
#include "ui_ass1.h"
#include<cmath>
QImage img(500,500,QImage::Format_RGB888);

ass1::ass1(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::ass1)
{
    ui->setupUi(this);
}

ass1::~ass1()
{
    delete ui;
}


void ass1::on_pushButton_clicked()
{
    double x1,y1,l,b;
    x1=ui->textEdit->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    l=ui->textEdit_3->toPlainText().toInt();
    b=ui->textEdit_4->toPlainText().toInt();
    rectangle(x1,y1,l,b);
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void ass1::on_pushButton_2_clicked()
{
    double x1,y1,l,b;
    x1=ui->textEdit->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    l=ui->textEdit_3->toPlainText().toInt();
    b=ui->textEdit_4->toPlainText().toInt();
    rhombus(x1,y1,l,b);
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void ass1::on_pushButton_3_clicked()
{
    double x1,y1,l,b,xc,yc,radius;
    x1=ui->textEdit->toPlainText().toInt();
    y1=ui->textEdit_2->toPlainText().toInt();
    l=ui->textEdit_3->toPlainText().toInt();
    b=ui->textEdit_4->toPlainText().toInt();
    xc=x1+l/2;
    yc=y1+b/2;
    radius=sqrt(pow(l/2,2)+pow(b/2,2))/2;
    circle(xc,yc,radius);
    ui->label->setPixmap(QPixmap::fromImage(img));
}

void ass1::circle(double c1,double c2,double r)
{
QRgb value;
value = qRgb(0,255,0);

double radius ;
double xc,yc;
radius = r;
xc = c1;
yc = c2;

double x0 = 0 ;
double y0 = radius ;

double D = 3 - 2*radius;
double x ,y;
x = x0;
y = y0;

while(x<=y)
    {
    img.setPixel(x+xc,y+yc,value);
    img.setPixel(-x+xc,y+yc,value);
    img.setPixel(x+xc,-y+yc,value);
    img.setPixel(-x+xc,-y+yc,value);
    img.setPixel(y+yc,x+xc,value);
    img.setPixel(-y+yc,x+xc,value);
    img.setPixel(y+yc,-x+xc,value);
    img.setPixel(-y+yc,-x+xc,value);

    if(D<0)
    {
        D += 4*x+6;
    }
    else
    {
        D += 4*(x-y)+10;
        y -= 1;
    }
    x+=1;
}
}

void ass1::DDA(double x1, double y1, double x2, double y2)
{
    float dx,dy,length,xinc,yinc,x,y;
    dx=x2-x1;
    dy=y2-y1;
    if(abs(dx)>abs(dy)){
        length=abs(dx);
    }
    else{
       length=abs(dy);
    }

    xinc=dx/length;
    yinc=dy/length;
    int i=0;
    x=x1;
    y=y1;
    while(i<length)
    {
        img.setPixel(int(x),int(y),qRgb(255,255,255));
        x=x+xinc;
        y=y+yinc;
        i++;
    }
}

void ass1::rectangle(int x1, int y1, int l, int b)
{
    DDA(x1,y1,x1,y1+b);
    DDA(x1,y1,x1+l,y1);
    DDA(x1,y1+b,l+x1,y1+b);
    DDA(x1+l,y1,x1+l,y1+b);
}

void ass1::rhombus(int x1, int y1, int l, int b)
{
    DDA(x1,y1+b/2,x1+l/2,y1+b);
    DDA(x1,y1+b/2,x1+l/2,y1);
    DDA(x1+l,y1+b/2,x1+l/2,y1);
    DDA(x1+l,y1+b/2,x1+l/2,y1+b);
}
