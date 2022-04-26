#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include "person.h"

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

private slots:
    void on_okButton_clicked();

    void on_cancelButton_clicked();

    void on_registerButton_clicked();

private:
    Person *user;
    QString name;
    QString password;
    Ui::LoginDialog *ui;
};

#endif // LOGINDIALOG_H
