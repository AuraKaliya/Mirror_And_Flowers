#ifndef CHARACTERHUB_H
#define CHARACTERHUB_H

#include "../DATA/character.h"
#include <QString>
#include <QMap>
#include <QVector>

class CharacterHub
{
public:
    static CharacterHub* GetInstance();

    void InitCharacterHub(QVector<Character*> characterList);
    void AddCharacter(Character* character);
    void AddCharacter(int id,QString name,QString title,QString tachieUrl,QString introduction,int ATK,int DEF,int HP);
    Character* GetCharacterByID(int ID);
    Character* GetCharacterByName(QString Name);
    QVector<Character*> GetCharacterListByID(QVector<int> IDList);
    QVector<Character*> GetCharacterListByName(QVector<QString> NameList);
    QVector<Character*> GetCharacterList();
    void ChangeNowCharacter(Character* character);
    Character* GetNowCharacter();

private:
    static CharacterHub* m_instance;
    CharacterHub();

    QMap<int, Character*> m_idToCharacterDictionary;
    QMap<QString, Character*> m_nameToCharacterDictionary;
    Character * m_nowCharacter;
};

#endif // CHARACTERHUB_H
