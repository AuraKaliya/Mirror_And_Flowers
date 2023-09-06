#ifndef WIDGETREGISTER_H
#define WIDGETREGISTER_H

#include <QString>

#include "widgetfactory.h"
#include "../UI/uiwidget.h"

class WidgetRegister
{
public:
    WidgetRegister();
    WidgetRegister(const QString & widgetName,UIWidget* widgetClass);
    WidgetRegister(const QString &widgetName,std::function<UIWidget*(QWidget*)> widgetClass);
};


//#define REGISTER_WIDGET(widgetName)\
//static UIWidget* CreateWidget##widgetName() \
//{\
//    UIWidget* obj;\
//     obj=new widgetName();\
//return obj;\
//}\
//static WidgetRegister WidgetRegister##widgetName(#widgetName,CreateWidget##widgetName());

//#define REGISTER_WIDGET_SINGLE(widgetName)\
//static UIWidget* CreateWidget##widgetName() \
//{\
//        UIWidget* obj;\
//    obj=(UIWidget*)widgetName::GetInstance();\
//    return obj;\
//}\
//    static WidgetRegister WidgetRegister##widgetName(#widgetName,CreateWidget##widgetName());



#define REGISTER_WIDGET(widgetName) static WidgetRegister widgetRegister_##widgetName(#widgetName,createWidgetCreator< widgetName > () );
#define REGISTER_WIDGET_SINGLE(widgetName) static WidgetRegister widgetRegister_##widgetName(#widgetName,createWidgetCreatorSingle< widgetName > () );

#endif // WIDGETREGISTER_H
