#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMouseEvent"
#include "mainwindow.h"
#include <iostream>
#include <QColorDialog>
#include "math.h"
#include<cstdlib>

using namespace std;
static QImage img(500,500,QImage::Format_RGB888);
QRgb rgb(qRgb(0, 255, 0));

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ver=0;
    start=true;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    a[ver]=a[0];
    b[ver]=b[0];

    for(i=0;i<ver;i++)
    {
        dy=b[i+1]-b[i];
        dx=a[i+1]-a[i];
        if(dy==0.0f) slope[i]=1.0;
        if(dx==0.0f) slope[i]=0.0;
        if((dy!=0.0f)&&(dx!=0.0f))
        {
         slope[i]=dx/dy;

        }
    }
    for(int y=0;y<500;y++)
    {
        k=0;
        for(i=0;i<ver;i++)
        {
            if(((b[i]<=y)&&(b[i+1]>y))||((b[i]>y)&&(b[i+1]<=y)))
            {
                xi[k]=int(a[i]+(slope[i]*(y-b[i])));
                k++;
           }
        }
        for(j=0;j<k-1;j++)
            /*Arrange x-intersections in order*/
        for(i=0;i<k-j-1;i++)
       {
        if(xi[i]>xi[i+1])
            {
                temp=xi[i];
                xi[i]=xi[i+1];
                xi[i+1]=temp;
            }
        }

        for(i=0;i<k;i+=2)
        {
            DDA(xi[i],y,xi[i+1]+1,y);

        }
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}


void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    if(start)
    {
      int p=ev->pos().x();
      int q=ev->pos().y();
      a[ver]=p;
      b[ver]=q;
        if(ev->button()==Qt::RightButton)
        {
            DDA(a[0],b[0],a[ver-1],b[ver-1]);
            start =false;
        }
        else
        {
            if (ver>0)
            {
                DDA(a[ver],b[ver],a[ver-1],b[ver-1]);
            }
        }
        ver++;
    }
    ui->label->setPixmap(QPixmap::fromImage(img));
}
void MainWindow::DDA(float x1, float y1, float x2, float y2)
 {
        
        float dx,dy,length,xinc,yinc,x,y;
        dx=x2-x1;
        dy=y2-y1;
        if (abs(dx)>=abs(dy))
            length=abs(dx);
        else {
            length=abs(dy);
        }
        xinc=dx/length;
        yinc=dy/length;
        int i=0;
        x=x1;
        y=y1;
        while(i<length)
        {
            img.setPixel(x,y,rgb);
            x=x+xinc;
            y=y+yinc;
            i++;
        }
    }

void MainWindow::on_pushButton_2_clicked()
{
    {
        QRgb color(QColorDialog::getColor().rgb());
        rgb = color;
    }
}

