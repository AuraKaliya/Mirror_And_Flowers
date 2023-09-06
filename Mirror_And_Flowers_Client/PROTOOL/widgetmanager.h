#ifndef WIDGETMANAGER_H
#define WIDGETMANAGER_H

#include <QWidget>
#include <QVector>

#include "../UI/uiwidget.h"
#include "../DATA/userinformation.h"

class WidgetManager
{
public:
    enum UpdateOption{
        HEADWIDGET=0b0001
    };
    static WidgetManager* GetInstance();

    void AddHeadWidget(UIWidget*headWidget);
    void UpdateWidget();
    void UpdateWdiegt(UpdateOption opration);
    void UpdateHeadWidget();
private:
    static WidgetManager* m_instance;
    WidgetManager();
    QVector<UIWidget*> m_headWidget;

};

#endif // WIDGETMANAGER_H
