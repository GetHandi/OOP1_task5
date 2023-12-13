#include <QApplication>

#include "loginwindow.h"
#include "signinwindow.h"
#include "mainwindow.h"
#include "message.h"
#include "user.h"



int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "RUSSIAN");
    QApplication a(argc, argv);
    ///MainWindow w;
    loginwindow w;
    w.show();



    return a.exec();

//user User;
////User.setId(1);
////User.setLogin("Alex");
////User.setPassword("pass");
////User.Write();

////User.Read("readLast");
//user User2;
//User2.Read("readLast");
//User2.Print();
////qInfo() << "test" << User2.getLastId();

}
