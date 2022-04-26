#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H

#include <QDialog>
#include <QPixmap>
#include <QFileDialog>
#include "logindialog.h"
#include "person.h"

namespace Ui {
class RegisterDialog;
}

class RegisterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterDialog(QWidget *parent = nullptr);
    ~RegisterDialog();

    const QString &password() const;
    const QString &firstName() const;
    const QString &lastName() const;
    const QString &loginName() const;
    const QString &email() const;
    const QString &avatarImage() const;

private slots:
    void on_registerButton_clicked();
    void on_cancelButton_clicked();
    void on_avatarButton_clicked();

private:
    QString m_firstName;
    QString m_lastName;
    QString m_loginName;
    QString m_password;
    QString m_email;
    QString m_avatarImage;

    Ui::RegisterDialog *ui;
};

#endif // REGISTERDIALOG_H
