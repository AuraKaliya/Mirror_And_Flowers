#ifndef CARDDECKHUB_H
#define CARDDECKHUB_H

#include "../DATA/carddeck.h"
#include <QString>
#include <QMap>
#include <QVector>


class CardDeckHub
{
public:
    static CardDeckHub* GetInstance();
    void InitCardDeckHub(QVector<CardDeck*>cardDeckList);
    void AddCardDeck(CardDeck*);
    CardDeck* GetCardDeckByID(int ID);
    CardDeck* GetCardDeckByName(QString name);
    QVector<CardDeck*>GetCardDeckListByID(QVector<int>IDList);
    QVector<CardDeck*>GetCardDeckListByName(QVector<QString>NameList);
    QVector<CardDeck*>GetCardDeckListByCharacter(QString CharacterName);
    QVector<CardDeck*>GetCardDeckList();

    void ChangeNowCardDeck(CardDeck* cardDeck);
    CardDeck* GetNowCardDeck();

private:
    static CardDeckHub* m_instance;
    CardDeckHub();
    QMap<int, CardDeck*> m_idToCardDeckDictionary;
    QMap<QString,CardDeck* > m_nameToCardDeckDictionary;
    QMap<QString,QVector<CardDeck*>> m_characterToCardDeckListDictionary;
    CardDeck* m_nowCardDeck;

};

#endif // CARDDECKHUB_H
