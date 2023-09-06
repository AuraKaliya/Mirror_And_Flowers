#ifndef USERINFORMATION_H
#define USERINFORMATION_H

#include <QString>

class UserInformation
{
public:
    static UserInformation* GetInstance();

    QString GetHeadImageUrl() const;
    void SetHeadImageUrl(const QString &newHeadImageUrl);

    QString GetUserName() const;
    void SetUserName(const QString &newUserName);

    QString GetUserIP() const;
    void SetUserIP(const QString &newUserIP);

private:

    UserInformation();
    static UserInformation* m_instance;
    QString m_headImageUrl;
    QString m_userName;
    QString m_userIP;
};

#endif // USERINFORMATION_H
