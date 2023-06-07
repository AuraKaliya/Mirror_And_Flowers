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

private:
    int m_ID;
    QString m_name;
    QString m_tachieUrl;

};

#endif // CHARACTER_H
