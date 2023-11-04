#ifndef SIGNINWINDOW_H
#define SIGNINWINDOW_H

#include <QDialog>

#include "message.h"
#include "user.h"
#include "loginwindow.h"

namespace Ui {
class signinwindow;
}

class signinwindow : public QDialog
{
    Q_OBJECT

public:
    explicit signinwindow(QWidget *parent = nullptr);
    ~signinwindow();

private slots:
    ///по нажатию кнопки Sign In, закрываем окно signinwindow и открываем окно loginwindow;
    void on_buttonSignIn_clicked();

private:
    Ui::signinwindow *ui;
};

#endif // SIGNINWINDOW_H
