#include "carddeckhub.h"

CardDeckHub* CardDeckHub::m_instance = nullptr;

CardDeckHub* CardDeckHub::GetInstance()
{
    if (m_instance == nullptr)
        m_instance = new CardDeckHub();
    return m_instance;
}

void CardDeckHub::InitCardDeckHub(QVector<CardDeck*> cardDeckList)
{
    for (auto it : cardDeckList)
    {
        m_idToCardDeckDictionary[it->GetID()] = it;
        m_nameToCardDeckDictionary[it->GetDeckName()] = it;

        QString characterName = it->GetCharacter();
        if (m_characterToCardDeckListDictionary.contains(characterName))
        {
            m_characterToCardDeckListDictionary[characterName].append(it);
        }
        else
        {
            QVector<CardDeck*> deckList;
            deckList.append(it);
            m_characterToCardDeckListDictionary[characterName] = deckList;
        }
    }
}

void CardDeckHub::AddCardDeck(CardDeck* cardDeck)
{
    m_idToCardDeckDictionary[cardDeck->GetID()] = cardDeck;
    m_nameToCardDeckDictionary[cardDeck->GetDeckName()] = cardDeck;

    QString characterName = cardDeck->GetCharacter();
    if (m_characterToCardDeckListDictionary.contains(characterName))
    {
        m_characterToCardDeckListDictionary[characterName].append(cardDeck);
    }
    else
    {
        QVector<CardDeck*> deckList;
        deckList.append(cardDeck);
        m_characterToCardDeckListDictionary[characterName] = deckList;
    }
}

CardDeck* CardDeckHub::GetCardDeckByID(int ID)
{
    return m_idToCardDeckDictionary[ID];
}

CardDeck* CardDeckHub::GetCardDeckByName(QString name)
{
    return m_nameToCardDeckDictionary[name];
}

QVector<CardDeck*> CardDeckHub::GetCardDeckListByID(QVector<int> IDList)
{
    QVector<CardDeck*> tmpList;
    for (auto it : IDList)
    {
        tmpList.append(m_idToCardDeckDictionary[it]);
    }
    return tmpList;
}

QVector<CardDeck*> CardDeckHub::GetCardDeckListByName(QVector<QString> NameList)
{
    QVector<CardDeck*> tmpList;
    for (auto it : NameList)
    {
        tmpList.append(m_nameToCardDeckDictionary[it]);
    }
    return tmpList;
}

QVector<CardDeck*> CardDeckHub::GetCardDeckListByCharacter(QString CharacterName)
{
    return m_characterToCardDeckListDictionary[CharacterName];
}

QVector<CardDeck*> CardDeckHub::GetCardDeckList()
{
    QVector<CardDeck*> tmpList;
    for (auto it : m_idToCardDeckDictionary)
        tmpList.append(it);
    return tmpList;
}

void CardDeckHub::ChangeNowCardDeck(CardDeck *cardDeck)
{
    m_nowCardDeck=cardDeck;
}

CardDeck *CardDeckHub::GetNowCardDeck()
{
    return m_nowCardDeck;
}

CardDeckHub::CardDeckHub()
{
    m_nowCardDeck=nullptr;
}
