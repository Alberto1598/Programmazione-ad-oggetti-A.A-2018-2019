#include "mainwindow.h"
#include <QApplication>
#include <controller.h>
#include <model.h>
#include <mywidgets.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    controller w;
    w.show();
    return a.exec();
}
