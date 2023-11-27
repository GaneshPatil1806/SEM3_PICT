#ifndef ASSR_H
#define ASSR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class assr; }
QT_END_NAMESPACE

class assr : public QMainWindow
{
    Q_OBJECT

public:
    assr(QWidget *parent = nullptr);
    ~assr();

private slots:
    void on_pushButton_clicked();
    int pointcode(float x, float y);
    void DDA(float x1, float y1, float x2, float y2);
    void DDA2(float x1, float y1, float x2, float y2);
    void cohenclip(float x1, float y1, float x2, float y2);

    void on_pushButton_2_clicked();

private:
    Ui::assr *ui;
};
#endif // ASSR_H
