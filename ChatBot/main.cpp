
#include "mainwindow.h"
#include "message.h"

#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    message first;
    message second;
    second.Print();
    first.SetN("Alex");
    first.Print();
    first.Write(first);
    second.Read(second);
    second.Print();


    return a.exec();
}
