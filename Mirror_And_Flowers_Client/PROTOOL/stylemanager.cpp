#include "stylemanager.h"
StyleManager* StyleManager::m_instance=nullptr;
StyleManager::StyleManager()
{

}

StyleManager *StyleManager::GetInstance()
{
    if(m_instance==nullptr)
    {
        m_instance=new StyleManager();
    }
    return m_instance;
}

void StyleManager::SetCloseLabelImage(QString imageUrl)
{
    for(auto it: m_closeLabelList)
    {
        it->setStyleSheet("border-image:url("+imageUrl+");");
    }
}

void StyleManager::AddCloseLabel(ClickLabel *label)
{
    m_closeLabelList.append(label);
}
