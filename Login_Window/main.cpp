#include "./mainwindow.h"
#include "./logindialog.h"

#include <QApplication>
#include <QLabel>
#include <QFile>

QString readTextFile(QString path)
{
    QFile file(path);

    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream in(&file);
        return in.readAll();
    }

    return "";
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QString css = readTextFile(":/styles/styles/style.css");

    if (css.length() > 0)
        a.setStyleSheet(css);


    LoginDialog *loginWindow = new LoginDialog();
    int loginResult = loginWindow->exec();

    if (loginResult == LoginDialog::Accepted)
    {
        w.show();
    }
    else
    {
        return -1;
    }

    return a.exec();
}
