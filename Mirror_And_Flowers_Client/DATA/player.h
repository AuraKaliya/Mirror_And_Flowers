#ifndef PLAYER_H
#define PLAYER_H


class Player
{
public:
    Player();

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
