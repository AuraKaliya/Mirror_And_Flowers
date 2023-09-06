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

int Character::GetATK() const
{
    return m_ATK;
}

void Character::SetATK(int newATK)
{
    m_ATK = newATK;
}

int Character::GetDEF() const
{
    return m_DEF;
}

void Character::SetDEF(int newDEF)
{
    m_DEF = newDEF;
}

int Character::GetHP() const
{
    return m_HP;
}

void Character::SetHP(int newHP)
{
    m_HP = newHP;
}

QString Character::GetTitle() const
{
    return m_title;
}

void Character::SetTitle(const QString &newTitle)
{
    m_title = newTitle;
}

QString Character::GetIntroduction() const
{
    return m_introduction;
}

void Character::SetIntroduction(const QString &newIntroduction)
{
    m_introduction = newIntroduction;
}
