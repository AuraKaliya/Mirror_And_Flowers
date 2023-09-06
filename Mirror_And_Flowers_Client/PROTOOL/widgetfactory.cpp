#include "widgetfactory.h"

WidgetFactory* WidgetFactory::m_instance=nullptr;

WidgetFactory *WidgetFactory::GetInstance()
{
    if(m_instance==nullptr)
    {
        m_instance=new WidgetFactory();
    }
    return m_instance;
}

void WidgetFactory::RegisterWidget(const QString &widgetName, UIWidget *widgetClass)
{
    m_nameToWidgetDictionary[widgetName]=widgetClass;
}

void WidgetFactory::RegisterWidget(const QString &widgetName, std::function<UIWidget *(QWidget *)> widgetClass)
{
    m_WidgetCreator.insert(widgetName,widgetClass);
}

UIWidget *WidgetFactory::CreateWidget(const QString &widgetName, QWidget *parent)
{
    auto it=m_WidgetCreator.find(widgetName);
    if(it!=m_WidgetCreator.end())
    {
        return it.value()(parent);
    }
    else
    {
        return nullptr;
    }
}

//UIWidget *WidgetFactory::CreateWidget(const QString &widgetName)
//{
//    auto it=m_nameToWidgetDictionary.find(widgetName);
//    if(it!=m_nameToWidgetDictionary.end())
//    {
//        return it.value();
//    }
//    else
//    {
//        return nullptr;
//    }
//}

WidgetFactory::WidgetFactory()
{

}
