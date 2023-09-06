#ifndef WIDGETFACTORY_H
#define WIDGETFACTORY_H


#include<QString>
#include <QMap>

#include "../UI/uiwidget.h"
#include "widgetmanager.h"

class WidgetFactory
{
public:
    static WidgetFactory* GetInstance();
    void RegisterWidget(const QString &widgetName,UIWidget* widgetClass);
    void RegisterWidget(const QString &widgetName,std::function<UIWidget*(QWidget*)> widgetClass);
    //UIWidget* CreateWidget(const QString &widgetName);
    UIWidget* CreateWidget(const QString &widgetName,QWidget* parent=nullptr);
private:
    static WidgetFactory* m_instance;
    WidgetFactory();

    QMap<QString,UIWidget*>m_nameToWidgetDictionary;

    QMap<QString,std::function<UIWidget*(QWidget*)> >m_WidgetCreator;
};

template <typename T>
std::function<UIWidget*(QWidget*)> createWidgetCreator()
{
    return [](QWidget* parent) ->UIWidget*
    {
        return new T(parent);
    };
}

template <typename T>
std::function<UIWidget*(QWidget*)> createWidgetCreatorSingle()
{
    return [](QWidget* parent) ->UIWidget*
    {
        return T::GetInstance();
    };
}


#endif // WIDGETFACTORY_H
