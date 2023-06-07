#ifndef CARD_H
#define CARD_H

#include <QObject>
#include <QString>
class Card
{
public:
    Card();
    virtual void initCard(int ID,QString name,QString category,int ATK,int DEF,int DHP,QString introduction,QString imageUrl);

    virtual int GetID();
    virtual QString GetName();
    virtual QString GetCategory();
    virtual int GetATK();
    virtual int GetDEF();
    virtual int GetDHP();
    virtual QString GetIntroduction();
    virtual QString GetImageUrl();

    virtual void SetID(int newID);
    virtual void SetName(const QString &newName);
    virtual void SetCategory(const QString &newCategory);
    virtual void SetATK(int newATK);
    virtual void SetDEF(int newDEF);
    virtual void SetDHP(int newDHP);
    virtual void SetIntroduction(const QString &newIntroduction);
    virtual void SetImageUrl(const QString &newImageUrl);

private:
    int m_ID;
    QString m_name;
    QString m_category;
    int m_ATK;
    int m_DEF;
    int m_DHP;
    QString m_introduction;
    QString m_imageUrl;
};

#endif // CARD_H
