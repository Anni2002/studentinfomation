#include "studentinfomation.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StudentInfomation w;
    w.show();
    return a.exec();
}
