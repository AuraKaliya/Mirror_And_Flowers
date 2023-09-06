#ifndef CARDHUB_H
#define CARDHUB_H

#include "../DATA/card.h"
#include <QString>
#include <QMap>
#include <QVector>

class CardHub
{
public:
    static CardHub* GetInstance();

    void InitCardHub(QVector<Card*>cardList);
    void AddCard(Card* card);
    Card* GetCardByID(int ID);
    Card* GetCardByName(QString Name);
    QVector<Card*>GetCardListByID(QVector<int>IDList);
    QVector<Card*>GetCardListByName(QVector<QString>NameList);
    QVector<Card*>GetCardList();



private:
    static CardHub* m_instance;
    CardHub();

    QMap<int,Card*>m_idToCardDictionary;
    QMap<QString,Card*>m_nameToCardDictionary;
};

#endif // CARDHUB_H
