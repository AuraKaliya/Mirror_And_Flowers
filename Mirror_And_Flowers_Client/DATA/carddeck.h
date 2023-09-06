#ifndef CARDDECK_H
#define CARDDECK_H

#include <QString>
#include <QVector>
#include "card.h"
#include <QDebug>

class CardDeck
{
public:
    CardDeck();

    enum Limit{CARDNUMBER=15};
    int GetID() const;
    void SetID(int newID);

    QString GetCharacter() const;
    void SetCharacter(const QString &newCharacter);

    QString GetDeckName() const;
    void SetDeckName(const QString &newDeckName);

    QString GetCoverUrl() const;
    void SetCoverUrl(const QString &newCoverUrl);

    QString GetIntroduction() const;
    void SetIntroduction(const QString &newIntroduction);

    bool AddCard(int ID);
    bool DeleteCard(int ID);
    QVector<QString> GetContains() const;


private:
    int m_ID;
    QString m_character;
    QString m_deckName;
    QString m_coverUrl;
    QString m_introduction;
    QVector<QString> m_contains;
};

#endif // CARDDECK_H
