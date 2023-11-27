#include "assr.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    assr w;
    w.show();
    return a.exec();
}
