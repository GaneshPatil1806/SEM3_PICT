#include "assr.h"
#include "ui_assr.h"

QImage img(500,500,QImage::Format_RGB888);
QImage img2(500,500,QImage::Format_RGB888);

assr::assr(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::assr)
{
    ui->setupUi(this);
}

assr::~assr()
{
    delete ui;
}

void assr::on_pushButton_clicked()
{

    float x1,y1,x2,y2;
    x1=ui->textEdit->toPlainText().toDouble();
    x2=ui->textEdit_3->toPlainText().toDouble();
    y1=ui->textEdit_2->toPlainText().toDouble();
    y2=ui->textEdit_4->toPlainText().toDouble();
    DDA(100,100,400,100);
    DDA(400,100,400,400);
    DDA(100,400,400,400);
    DDA(100,100,100,400);
    DDA(x1,y1,x2,y2);

    ui->label->setPixmap(QPixmap::fromImage(img));

}


void assr::on_pushButton_2_clicked()
{
   float x1,y1,x2,y2;
   x1=ui->textEdit->toPlainText().toDouble();
   x2=ui->textEdit_3->toPlainText().toDouble();
   y1=ui->textEdit_2->toPlainText().toDouble();
   y2=ui->textEdit_4->toPlainText().toDouble();
   DDA2(100,100,400,100);
   DDA2(400,100,400,400);
   DDA2(100,400,400,400);
   DDA2(100,100,100,400);
   cohenclip(x1,y1,x2,y2);
   ui->label_2->setPixmap(QPixmap::fromImage(img2));
}

void assr::DDA(float x1, float y1, float x2, float y2)
{
  float dx,dy,length,xinc,yinc,x,y;
  dx=x2-x1;
  dy=y2-y1;

  if(abs(dx)>abs(dy)){
      length=dx;
  }
  else{
      length=dy;
  }
  xinc=dx/length;
  yinc=dy/length;

  x=x1;
  y=y1;
  int i=1;
  while(i<=length){
      img.setPixel(x,y,qRgb(255,255,360));
      x+=xinc;
      y+=yinc;
      i++;
  }
}

void assr::DDA2(float x1, float y1, float x2, float y2)
{
    float dx,dy,length,xinc,yinc,x,y;
    dx=x2-x1;
    dy=y2-y1;

    if(abs(dx)>abs(dy)){
        length=dx;
    }
    else{
        length=dy;
    }
    xinc=dx/length;
    yinc=dy/length;

    x=x1;
    y=y1;
    int i=1;
    while(i<=length){
        img2.setPixel(x,y,qRgb(255,255,360));
        x+=xinc;
        y+=yinc;
        i++;
    }
}

const int inside=0;
const int top=8;
const int bottom=4;
const int right=2;
const int left=1;

const int xmin=100;
const int xmax=400;
const int ymin=100;
const int ymax=400;

int assr::pointcode(float x, float y)
{
  int code=inside;
  if(x<xmin)
  {
      code= code | left;
  }
  else if(x>xmax){
      code= code | right;
  }
  if(y<ymin){
      code= code | bottom;
  }
  else if(y>ymax){
      code = code | top;
  }
  return code;
}

void assr::cohenclip(float x1, float y1, float x2, float y2)
{
   int code1=pointcode(x1,y1);
   int code2=pointcode(x2,y2);
   float m=(y2-y1)/(x2-x1);

   while(true)
   {
       if((code1==0) && (code2==0)){
           break;
       }
       else if(code1 & code2){
           break;
       }
       else
       {
           int endcode;
           float x,y;

           if(code1!=0){
               endcode=code1;
           }
           else{
               endcode=code2;
           }

           if(endcode & top){
               x=x1+(ymax-y1)/m;
               y=ymax;
           }
           else if(endcode & bottom){
               x=x1+(ymin-y1)/m;
               y=ymin;
           }
           else if(endcode & left){
               x=xmin;
               y=y1+m*(xmin-x1);
           }
           else if(endcode & right){
               x=xmax;
               y=y1+(xmax-x1)*m;
          }
           if(endcode==code1){
               x1=x;
               y1=y;
               code1=pointcode(x1,y1);
           }
           else{
               x2=x;
               y2=y;
               code2=pointcode(x2,y2);
           }

        }
   }


           DDA2(x1,y1,x2,y2);
}




