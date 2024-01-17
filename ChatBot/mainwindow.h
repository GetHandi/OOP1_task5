
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


#include "message.h"
#include "user.h"
#include "ui_mainwindow.h"
#include "loginwindow.h"
#include "processing_request.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // Обработка данных нажатия кнопки "отправить";
    void on_sendButton_clicked();

    void on_messageWindow_textChanged();

private:
    Ui::MainWindow *ui;
    Message message;
    Processing_request answer;

};

#endif // MAINWINDOW_H
