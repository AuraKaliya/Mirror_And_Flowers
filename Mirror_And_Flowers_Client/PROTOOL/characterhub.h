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
    Character* GetCharacterByID(int ID);
    Character* GetCharacterByName(QString Name);
    QVector<Character*> GetCharacterListByID(QVector<int> IDList);
    QVector<Character*> GetCharacterListByName(QVector<QString> NameList);
    QVector<Character*> GetCharacterList();

private:
    static CharacterHub* m_instance;
    CharacterHub();

    QMap<int, Character*> m_idToCharacterDictionary;
    QMap<QString, Character*> m_nameToCharacterDictionary;
};

#endif // CHARACTERHUB_H
