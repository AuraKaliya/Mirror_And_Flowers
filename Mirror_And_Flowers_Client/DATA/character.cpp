#include "character.h"

Character::Character()
{

}

void Character::InitCharacter(int ID, QString name, QString tachieUrl)
{
    SetID(ID);
    SetName(name);
    SetTachieUrl(tachieUrl);
}

void Character::SetID(int ID)
{
    m_ID=ID;
}

void Character::SetName(QString Name)
{
    m_name=Name;
}

void Character::SetTachieUrl(QString TachieUrl)
{
    m_tachieUrl=TachieUrl;
}

int Character::GetID() const
{
    return m_ID;
}

QString Character::GetName() const
{
    return m_name;
}

QString Character::GetTachieUrl() const
{
    return m_tachieUrl;
}
