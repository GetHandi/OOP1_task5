
#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


bool isEmpty = true;

void MainWindow::on_sendButton_clicked()
{
    message User;
    QString dialog;

    if (isEmpty)
    {
        dialog = ui->messageWindow->toPlainText();
        isEmpty = false;
    }
    else
    {
        /// создаем экземпляр класса QString, в который добавляем текст из окна чата + текст из окна сообщения;
        dialog = (ui->chatWindow->toPlainText() + "\n\n" + ui->messageWindow->toPlainText());
    }
    User.setT();
    User.setN("UserName");
    User.setM(ui->messageWindow->toPlainText());
    User.Print();
    User.Write(User);
    ///вывод в окно чата содержимое экземпляра класса QString;
    ui->chatWindow->setText(dialog);
}

