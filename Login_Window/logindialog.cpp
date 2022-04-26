#include "logindialog.h"
#include "ui_logindialog.h"
#include "registerdialog.h"
#include "person.h"
#include <QPixmap>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    ui->passwordLineEdit->setEchoMode(QLineEdit::Password);

    user = new Person("marco", "1234");
    user->setFirstName("Marco");
    user->setLastName("Scheuerer");

    /*
    // Remove Window frame
    Qt::WindowFlags flags;
    flags = Qt::CustomizeWindowHint;
    this->setWindowFlags(flags);
    */
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_okButton_clicked()
{

    static int count = 1;

    if (ui->userNameLineEdit->text() == user->getLoginName() &&
            ui->passwordLineEdit->text() == user->getPassword())
    {
        accept();
        qDebug() << user->getFirstName();
        qDebug() << user->getLastName();
        qDebug() << user->getLoginName();
        qDebug() << user->getPassword();
        qDebug() << user->getEmail();
    }
    else
    {
        QMessageBox::critical(this, "Access denied",
                "<h1>Access denied</h1><p>Wrong user name or password!</p><p>You've got " + QString::number(3 - count) + " of 3 attempts</p>",
                QMessageBox::Ok);
        ui->userNameLineEdit->setText(user->getLoginName());
        ui->passwordLineEdit->setText("");
        count++;
    }

    if (count > 3)
    {
        reject();
    }
}


void LoginDialog::on_cancelButton_clicked()
{
    reject();
}


void LoginDialog::on_registerButton_clicked()
{
    RegisterDialog *registerWindow = new RegisterDialog(this);
    int success = registerWindow->exec();

    if (success == RegisterDialog::Accepted)
    {
        user->setFirstName(registerWindow->firstName());
        user->setLastName(registerWindow->lastName());
        user->setPassword(registerWindow->password());
        user->setLoginName(registerWindow->loginName());
        user->setEmail(registerWindow->email());
        user->setAvatarImage(registerWindow->avatarImage());
        ui->userNameLineEdit->setText(user->getLoginName());
        ui->avatarLabel->setPixmap(QPixmap(user->getAvatarImage()));
    }
}

