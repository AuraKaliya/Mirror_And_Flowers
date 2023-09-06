#include "widgetmanager.h"

WidgetManager* WidgetManager::m_instance=nullptr;
WidgetManager *WidgetManager::GetInstance()
{
    if(m_instance==nullptr)
    {
        m_instance=new WidgetManager();
    }
    return m_instance;
}

void WidgetManager::AddHeadWidget(UIWidget *headWidget)
{
    m_headWidget.append(headWidget);
}

void WidgetManager::UpdateWidget()
{
    UpdateHeadWidget();
}

void WidgetManager::UpdateWdiegt(UpdateOption opration)
{
    if(opration&HEADWIDGET)
    {
        UpdateHeadWidget();
    }

}

void WidgetManager::UpdateHeadWidget()
{
    for(auto it: m_headWidget)
    {
        it->UpdateUserInfo(
                           UserInformation::GetInstance()->GetHeadImageUrl(),
                           UserInformation::GetInstance()->GetUserName(),
                           UserInformation::GetInstance()->GetUserIP()
                           );
    }
}

WidgetManager::WidgetManager()
{

}
