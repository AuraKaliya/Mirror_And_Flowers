#ifndef LABELFACTORY_H
#define LABELFACTORY_H

#include <QString>
#include <QMap>
#include "../../UI/clicklabel.h"

class LabelFactory
{
public:
    static LabelFactory* GetInstance();
    void RegisterLabel(const QString &labelName,ClickLabel*labelClass);
    void RegisterLabel(const QString &labelName,std::function<ClickLabel*(QWidget*)> labelClass);
    //ClickLabel * CreateLabel(const QString &labelName);
    ClickLabel * CreateLabel(const QString &labelName,QWidget* parent=nullptr);

private:
    static LabelFactory* m_instance;
    LabelFactory();

    QMap<QString,ClickLabel*>m_nameToLabelDictionary;


    QMap<QString,std::function<ClickLabel*(QWidget*)> > m_LabelCreator;

};

template <typename T>
std::function<ClickLabel*(QWidget*)> createLabelCreator()
{
    return [](QWidget* parent) ->ClickLabel*
    {
        return new T(parent);
    };
}


#endif // LABELFACTORY_H
