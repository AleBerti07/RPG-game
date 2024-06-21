#include "uzamig.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    uzamig w;
    w.show();
    return a.exec();
}
