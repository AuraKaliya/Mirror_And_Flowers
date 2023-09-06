#include "card.h"

Card::Card()
{

}

void Card::initCard(int ID, QString name, QString category, int ATK, int DEF, int DHP, QString introduction, QString imageUrl)
{
    SetID(ID);
    SetName(name);
    SetCategory(category);
    SetATK(ATK);
    SetDEF(DEF);
    SetDHP(DHP);
    SetIntroduction(introduction);
    SetImageUrl(imageUrl);
}

int Card::GetID()
{
    return m_ID;
}

QString Card::GetName()
{
    return m_name;
}

QString Card::GetCategory()
{
    return m_category;
}

int Card::GetATK()
{
    return m_ATK;
}

int Card::GetDEF()
{
    return m_DEF;
}

int Card::GetDHP()
{
    return m_DHP;
}

QString Card::GetIntroduction()
{
    return m_introduction;
}

QString Card::GetImageUrl()
{
    return m_imageUrl;
}

void Card::SetID(int newID)
{
    m_ID = newID;
}

void Card::SetName(const QString &newName)
{
    m_name = newName;
}

void Card::SetCategory(const QString &newCategory)
{
    m_category = newCategory;
}

void Card::SetATK(int newATK)
{
    m_ATK = newATK;
}

void Card::SetDEF(int newDEF)
{
    m_DEF = newDEF;
}

void Card::SetDHP(int newDHP)
{
    m_DHP = newDHP;
}

void Card::SetIntroduction(const QString &newIntroduction)
{
    m_introduction = newIntroduction;
}

void Card::SetImageUrl(const QString &newImageUrl)
{
    m_imageUrl = newImageUrl;
}
