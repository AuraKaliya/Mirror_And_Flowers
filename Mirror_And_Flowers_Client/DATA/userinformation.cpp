#include "userinformation.h"

UserInformation* UserInformation::m_instance=nullptr;
UserInformation::UserInformation()
{

}

UserInformation *UserInformation::GetInstance()
{
    if(m_instance==nullptr)
    {
        m_instance=new UserInformation();
    }
    return m_instance;
}

QString UserInformation::GetHeadImageUrl() const
{
    return m_headImageUrl;
}

void UserInformation::SetHeadImageUrl(const QString &newHeadImageUrl)
{
    m_headImageUrl = newHeadImageUrl;
}

QString UserInformation::GetUserName() const
{
    return m_userName;
}

void UserInformation::SetUserName(const QString &newUserName)
{
    m_userName = newUserName;
}

QString UserInformation::GetUserIP() const
{
    return m_userIP;
}

void UserInformation::SetUserIP(const QString &newUserIP)
{
    m_userIP = newUserIP;
}

