#ifndef CHARACTER_H
#define CHARACTER_H

#include <QString>

class Character
{
public:
    Character();
    void InitCharacter(int ID,QString name,QString tachieUrl);
    void SetID(int ID);
    void SetName(QString Name);
    void SetTachieUrl(QString TachieUrl);

    int GetID() const;
    QString GetName() const;
    QString GetTachieUrl() const;

    int GetATK() const;
    void SetATK(int newATK);

    int GetDEF() const;
    void SetDEF(int newDEF);

    int GetHP() const;
    void SetHP(int newHP);

    QString GetTitle() const;
    void SetTitle(const QString &newTitle);

    QString GetIntroduction() const;
    void SetIntroduction(const QString &newIntroduction);

private:
    int m_ID;
    QString m_name;
    QString m_tachieUrl;
    QString m_title;
    QString m_introduction;
    int m_ATK;
    int m_DEF;
    int m_HP;
};

#endif // CHARACTER_H
