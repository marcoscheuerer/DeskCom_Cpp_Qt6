#include "person.h"

Person::Person()
{

}

Person::Person(QString loginname, QString password)
{
    loginName = loginname;
    this->password = password;
}

const QString &Person::getFirstName() const
{
    return firstName;
}

void Person::setFirstName(const QString &newFirst_name)
{
    firstName = newFirst_name;
}

const QString &Person::getLastName() const
{
    return lastName;
}

void Person::setLastName(const QString &newLast_name)
{
    lastName = newLast_name;
}

const QString &Person::getLoginName() const
{
    return loginName;
}

void Person::setLoginName(const QString &newLogin_name)
{
    loginName = newLogin_name;
}

const QString &Person::getPassword() const
{
    return password;
}

void Person::setPassword(const QString &newPassword)
{
    password = newPassword;
}

const QString &Person::getEmail() const
{
    return email;
}

void Person::setEmail(const QString &newEmail)
{
    email = newEmail;
}

const QString &Person::getAvatarImage() const
{
    return avatarImage;
}

void Person::setAvatarImage(const QString &newAvatarImage)
{
    avatarImage = newAvatarImage;
}
