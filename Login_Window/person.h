#ifndef PERSON_H
#define PERSON_H

#include <QString>

class Person
{
private:
    QString firstName;
    QString lastName;
    QString loginName;
    QString password;
    QString email;
    QString avatarImage;

public:
    // Constructor
    Person();
    Person(QString loginname, QString password);

    // Gettter-/Setter-Methods
    const QString &getFirstName() const;
    void setFirstName(const QString &newFirst_name);
    const QString &getLastName() const;
    void setLastName(const QString &newLast_name);
    const QString &getLoginName() const;
    void setLoginName(const QString &newLogin_name);
    const QString &getPassword() const;
    void setPassword(const QString &newPassword);
    const QString &getEmail() const;
    void setEmail(const QString &newEmail);
    const QString &getAvatarImage() const;
    void setAvatarImage(const QString &newAvatarImage);
};

#endif // PERSON_H
