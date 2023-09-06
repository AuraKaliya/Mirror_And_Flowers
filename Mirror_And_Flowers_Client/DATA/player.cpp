#include "Player.h"

// Constructor
Player::Player()
{
    m_tmpATK = 0;
    m_tmpDEF = 0;
    m_tmpHP = 0;
    m_equipATK = 0;
    m_equipDEF = 0;
    m_equipHP = 0;
    m_opponent = nullptr;
}

void Player::newTurn()
{
    m_tmpATK = 0;
    m_tmpDEF = 0;
    m_tmpHP = 0;
}

// Getters
int Player::GetHPMax() const
{
    return m_HPMax; // Return the total HP max
}

int Player::GetHPNow() const
{
    return m_HPNow; // Return the current HP
}

int Player::GetATK() const
{
    return m_ATK; // Return the total ATK
}

int Player::GetDEF() const
{
    return m_DEF; // Return the total DEF
}

int Player::GetTmpATK() const
{
    return m_tmpATK; // Return the temporary ATK
}

int Player::GetTmpDEF() const
{
    return m_tmpDEF; // Return the temporary DEF
}

int Player::GetTmpHP() const
{
    return m_tmpHP; // Return the temporary HP max
}

int Player::GetEquipATK() const
{
    return m_equipATK; // Return the equipment ATK
}

int Player::GetEquipDEF() const
{
    return m_equipDEF; // Return the equipment DEF
}

int Player::GetEquipHP() const
{
    return m_equipHP; // Return the equipment HP max
}

Player* Player::GetOpponent() const
{
    return m_opponent; // Return the pointer to the opponent player
}

// Setters
void Player::SetHPMax(int hpMax)
{
    if (hpMax >= 0) // Check if the input is valid
    {
        m_HPMax = hpMax; // Set the HP max to the input value
    }
}

void Player::SetHPNow(int hpNow)
{
    if (hpNow >= 0 && hpNow <= GetHPMax()) // Check if the input is valid and within the range of HP max
    {
        m_HPNow = hpNow; // Set the current HP to the input value
    }else if(hpNow>GetHPMax())
    {
        m_HPNow=m_HPMax;
    }else
    {
        m_HPNow=0;
    }
}

void Player::SetATK(int atk)
{
    if (atk >= 0) // Check if the input is valid
    {
        m_ATK = atk; // Set the ATK to the input value
    }
}

void Player::SetDEF(int def)
{
    if (def >= 0) // Check if the input is valid
    {
        m_DEF = def; // Set the DEF to the input value
    }
}

void Player::SetTmpATK(int tmpATK)
{
    if (tmpATK >= 0) // Check if the input is valid
    {
        m_tmpATK = tmpATK; // Set the temporary ATK to the input value
    }
}

void Player::SetTmpDEF(int tmpDEF)
{
    if (tmpDEF >= 0) // Check if the input is valid
    {
        m_tmpDEF = tmpDEF; // Set the temporary DEF to the input value
    }
}

void Player::SetTmpHP(int tmpHP)
{
    if (tmpHP >= 0) // Check if the input is valid
    {
        m_tmpHP = tmpHP; // Set the temporary HP max to the input value
    }
}

void Player::SetEquipATK(int equipATK)
{
    if (equipATK >= 0) // Check if the input is valid
    {
        m_equipATK = equipATK; // Set the equipment ATK to the input value
    }
}

void Player::SetEquipDEF(int equipDEF)
{
    if (equipDEF >= 0) // Check if the input is valid
    {
        m_equipDEF = equipDEF; // Set the equipment DEF to the input value
    }
}

void Player::SetEquipHP(int equipHP)
{
    if (equipHP >= 0) // Check if the input is valid
    {
        m_equipHP = equipHP; // Set the equipment HP max to the input value
    }
}

void Player::SetOpponent(Player* opponent)
{
    if (opponent != nullptr) // Check if the input is not null
    {
        m_opponent = opponent; // Set the pointer to the opponent player to the input value
    }
}

void Player::show()
{
    // 使用qDebug()将玩家当前的属性展示出来
    qDebug() << "Player's current attributes:";
    qDebug() << "HPMax:" << GetHPMax();
    qDebug() << "HPNow:" << GetHPNow();
    qDebug() << "ATK:" << GetATK();
    qDebug() << "DEF:" << GetDEF();
    qDebug() << "TmpATK:" << GetTmpATK();
    qDebug() << "TmpDEF:" << GetTmpDEF();
    qDebug() << "TmpHP:" << GetTmpHP();
    qDebug() << "EquipATK:" << GetEquipATK();
    qDebug() << "EquipDEF:" << GetEquipDEF();
    qDebug() << "EquipHP:" << GetEquipHP();
}
