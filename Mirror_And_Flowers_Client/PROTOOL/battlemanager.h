#ifndef BATTLEMANAGER_H
#define BATTLEMANAGER_H

#include <QObject>
#include <QMap>
#include <QDebug>

#include "../DATA/character.h"
#include "../DATA/player.h"
#include "../DATA/card.h"
#include "../DATA/constnumber.h"
#include "carddeckhub.h"
#include "cardhub.h"
#include <QRandomGenerator>

typedef std::function<void(Card*)> Func;

class BattleManager:public QObject
{
    Q_OBJECT
public:


    static BattleManager* GetInstance();

    static void SolveCardProp(Card*card);
    static void SolveCardDeprop(Card*card);
    static void SolveCardEquipment(Card*card);

    void InitBattle();
    void InitCardDeck(QVector<Card*> cardDeck);
    void DrawCard();
    void SetOpCharacter(Character* character);
    void UseCard(Card* card);
    void UpdatePlayer(Player*,ConstNumber::BattleInstruction,int value);

    void Battle();
    void AttackEnd();

    QVector<Card*> GetCardDeck();
    QVector<Card*> GetCardHand();
    QPair<Character*,Character*> GetCharacter();
public slots:
    void CharacterChanged(Character*character);

signals:
    void NextTurn();
    void battleStar();
    void battleInfo(QString);
    void BattleEnd(Character* winner);
   // void InitBattle(Character*ME,Character*OPPO);
    void UpdatePlayerState(double me,double op);
private:
    bool m_battleFlag;
    static BattleManager* m_instance;
    BattleManager();
    Character* m_myCharacter;
    Character* m_opCharacter;

    static Player* s_player1;
    static Player* s_player2;

    QVector<Card*> m_cardDeck;
    QVector<Card*> m_cardHand;

    QMap<QString,Func> m_CardSolution;
};

#endif // BATTLEMANAGER_H
