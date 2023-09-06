#include "widgetregister.h"

WidgetRegister::WidgetRegister()
{

}

WidgetRegister::WidgetRegister(const QString &widgetName, UIWidget *widgetClass)
{
    WidgetFactory* factory=WidgetFactory::GetInstance();
    factory->RegisterWidget(widgetName,widgetClass);
}

WidgetRegister::WidgetRegister(const QString &widgetName, std::function<UIWidget *(QWidget *)> widgetClass)
{
    WidgetFactory* factory=WidgetFactory::GetInstance();
    factory->RegisterWidget(widgetName,widgetClass);
}
