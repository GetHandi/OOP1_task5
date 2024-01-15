#include <QApplication>

#include "loginwindow.h"
#include "mainwindow.h"
#include "message.h"
#include "user.h"

#include <QDebug>
#include <QMap>
#include <QVector>


int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "RUSSIAN");
    QApplication a(argc, argv);



    ///MainWindow w;
    loginwindow w;
    w.setWindowTitle("Чат-бот LUM");
    w.show();

    QMap <QString, QVector<QString>> hi;
    hi["hi"] = {"Привет", "Прив", "Hello", "Hi", "Здравствуй",
                                                "Здарова", "Здравствуйте", "Добрый день", "Доброго времени суток"};

    for (auto now : hi["hi"])
    {
        qInfo() << now << " ";
    }



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
