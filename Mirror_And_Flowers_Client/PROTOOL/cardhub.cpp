#include "cardhub.h"

CardHub* CardHub::m_instance=nullptr;

CardHub *CardHub::GetInstance()
{
    if(m_instance==nullptr)
        m_instance=new CardHub();
    return m_instance;
}

void CardHub::InitCardHub(QVector<Card *> cardList)
{
    for(auto it:cardList)
    {
        m_idToCardDictionary[it->GetID()]=it;
        m_nameToCardDictionary[it->GetName()]=it;
    }
}

Card *CardHub::GetCardByID(int ID)
{
    return m_idToCardDictionary[ID];
}

Card *CardHub::GetCardByName(QString Name)
{
    return m_nameToCardDictionary[Name];
}

QVector<Card *> CardHub::GetCardListByID(QVector<int> IDList)
{
    QVector<Card*> tmpList;
    for(auto it:IDList)
    {
        tmpList.append(m_idToCardDictionary[it]);
    }
    return tmpList;
}

QVector<Card *> CardHub::GetCardListByName(QVector<QString> NameList)
{
    QVector<Card*> tmpList;
    for(auto it:NameList)
    {
        tmpList.append(m_nameToCardDictionary[it]);
    }
    return tmpList;
}

QVector<Card *> CardHub::GetCardList()
{
    QVector<Card*> tmpList;
    for(auto it:m_idToCardDictionary)
        tmpList.append(it);
    return tmpList;
}

CardHub::CardHub()
{

}
