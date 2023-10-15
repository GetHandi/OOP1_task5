
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



void MainWindow::on_sendButton_clicked()
{
    QString dialog = (ui->chatWindow->toPlainText() + "\n\n" + ui->messageWindow->toPlainText());

    ui->chatWindow->setText(dialog);
}

