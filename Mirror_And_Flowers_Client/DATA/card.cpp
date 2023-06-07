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

}

QString Card::GetName()
{

}

QString Card::GetCategory()
{

}

int Card::GetATK()
{

}

int Card::GetDEF()
{

}

int Card::GetDHP()
{

}

QString Card::GetIntroduction()
{

}

QString Card::GetImageUrl()
{

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
