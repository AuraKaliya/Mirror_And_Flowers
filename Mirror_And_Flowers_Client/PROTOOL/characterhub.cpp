#include "characterhub.h"

CharacterHub* CharacterHub::m_instance = nullptr;

CharacterHub* CharacterHub::GetInstance()
{
    if (m_instance == nullptr)
        m_instance = new CharacterHub();
    return m_instance;
}

void CharacterHub::InitCharacterHub(QVector<Character*> characterList)
{
    for (auto it : characterList)
    {
        m_idToCharacterDictionary[it->GetID()] = it;
        m_nameToCharacterDictionary[it->GetName()] = it;
    }
}

Character* CharacterHub::GetCharacterByID(int ID)
{
    return m_idToCharacterDictionary[ID];
}

Character* CharacterHub::GetCharacterByName(QString Name)
{
    return m_nameToCharacterDictionary[Name];
}

QVector<Character*> CharacterHub::GetCharacterListByID(QVector<int> IDList)
{
    QVector<Character*> tmpList;
    for (auto it : IDList)
    {
        tmpList.append(m_idToCharacterDictionary[it]);
    }
    return tmpList;
}

QVector<Character*> CharacterHub::GetCharacterListByName(QVector<QString> NameList)
{
    QVector<Character*> tmpList;
    for (auto it : NameList)
    {
        tmpList.append(m_nameToCharacterDictionary[it]);
    }
    return tmpList;
}

QVector<Character*> CharacterHub::GetCharacterList()
{
    QVector<Character*> tmpList;
    for (auto it : m_idToCharacterDictionary)
        tmpList.append(it);
    return tmpList;
}

CharacterHub::CharacterHub()
{

}
