#ifndef PLAYER_H
#define PLAYER_H

#include <QDebug>

class Player
{
public:
    Player();

    void newTurn();
    // Getters
    int GetHPMax() const;
    int GetHPNow() const;
    int GetATK() const;
    int GetDEF() const;
    int GetTmpATK() const;
    int GetTmpDEF() const;
    int GetTmpHP() const;
    int GetEquipATK() const;
    int GetEquipDEF() const;
    int GetEquipHP() const;
    Player* GetOpponent() const;

    // Setters
    void SetHPMax(int hpMax);
    void SetHPNow(int hpNow);
    void SetATK(int atk);
    void SetDEF(int def);
    void SetTmpATK(int tmpATK);
    void SetTmpDEF(int tmpDEF);
    void SetTmpHP(int tmpHP);
    void SetEquipATK(int equipATK);
    void SetEquipDEF(int equipDEF);
    void SetEquipHP(int equipHP);
    void SetOpponent(Player* opponent);

    void show();
private:

    int m_HPMax;
    int m_HPNow;
    int m_ATK;
    int m_DEF;
    int m_tmpATK;
    int m_tmpDEF;
    int m_tmpHP;
    int m_equipATK;
    int m_equipDEF;
    int m_equipHP;
    Player *m_opponent;
};

#endif // PLAYER_H
