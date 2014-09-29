#include "tvsc.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    qDebug() << "test";
    QApplication a(argc, argv);
    tvsc w;
    w.show();

    return a.exec();
}
