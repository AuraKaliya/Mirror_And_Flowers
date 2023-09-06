#include "carddeck.h"

CardDeck::CardDeck()
{

}

int CardDeck::GetID() const
{
    return m_ID;
}

void CardDeck::SetID(int newID)
{
    m_ID = newID;
}

QString CardDeck::GetCharacter() const
{
    return m_character;
}

void CardDeck::SetCharacter(const QString &newCharacter)
{
    m_character = newCharacter;
}

QString CardDeck::GetDeckName() const
{
    return m_deckName;
}

void CardDeck::SetDeckName(const QString &newDeckName)
{
    m_deckName = newDeckName;
}

QString CardDeck::GetCoverUrl() const
{
    return m_coverUrl;
}

void CardDeck::SetCoverUrl(const QString &newCoverUrl)
{
    m_coverUrl = newCoverUrl;
}

QString CardDeck::GetIntroduction() const
{
    return m_introduction;
}

void CardDeck::SetIntroduction(const QString &newIntroduction)
{
    m_introduction = newIntroduction;
}

bool CardDeck::AddCard(int ID)
{
    bool flag=true;
    if(m_contains.size()<CARDNUMBER)
    {
        m_contains.append(QString::number(ID));
    }
    else
    {
        flag=false;
    }
    return flag;
}

bool CardDeck::DeleteCard(int ID)
{
    m_contains.removeOne(QString::number(ID));
    qDebug()<<"%%%%%%%%this size:"<<m_contains.size();
    return true;
}

QVector<QString> CardDeck::GetContains() const
{
    return m_contains;
}
