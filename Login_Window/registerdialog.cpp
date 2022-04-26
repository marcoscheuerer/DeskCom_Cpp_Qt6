#include "registerdialog.h"
#include "ui_registerdialog.h"
#include "logindialog.h"

RegisterDialog::RegisterDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RegisterDialog)
{
    ui->setupUi(this);   
}

RegisterDialog::~RegisterDialog()
{
    delete ui;
}

void RegisterDialog::on_registerButton_clicked()
{

    m_firstName = ui->firstNameLineEdit->text();
    m_lastName = ui->lastNameLineEdit->text();
    m_loginName = ui->loginNameLineEdit->text();
    m_password = ui->passwordLineEdit->text();
    m_email = ui->eMailLineEdit->text();

    if (!m_firstName.isEmpty() && !m_lastName.isEmpty() && !m_loginName.isEmpty()
            && !m_password.isEmpty() && !m_email.isEmpty())
    {
        accept();
    }
    else
    {
        reject();
    }
}


void RegisterDialog::on_cancelButton_clicked()
{
    reject();
}

const QString &RegisterDialog::firstName() const
{
    return m_firstName;
}

const QString &RegisterDialog::lastName() const
{
    return m_lastName;
}

const QString &RegisterDialog::loginName() const
{
    return m_loginName;
}

const QString &RegisterDialog::email() const
{
    return m_email;
}

const QString &RegisterDialog::password() const
{
    return m_password;
}


void RegisterDialog::on_avatarButton_clicked()
{
    m_avatarImage = QFileDialog::getOpenFileName(this, tr("Open file"),
                                               "/home",
                                                 tr("Images [*.png, *.bmp, *.ico, *.gif, *.jpg] (*.png *.bmp *.ico *.gif *.jpg)"));
    qDebug() << m_avatarImage;

}

const QString &RegisterDialog::avatarImage() const
{
    return m_avatarImage;
}

