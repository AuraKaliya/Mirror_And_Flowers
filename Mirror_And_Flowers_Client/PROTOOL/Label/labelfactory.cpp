#include "labelfactory.h"

LabelFactory* LabelFactory::m_instance=nullptr;
LabelFactory *LabelFactory::GetInstance()
{
    if(m_instance==nullptr)
    {
        m_instance=new LabelFactory();
    }
    return m_instance;
}

void LabelFactory::RegisterLabel(const QString &labelName, ClickLabel *labelClass)
{
    m_nameToLabelDictionary[labelName]=labelClass;
}

void LabelFactory::RegisterLabel(const QString &labelName, std::function<ClickLabel *(QWidget *)> labelClass)
{
    m_LabelCreator.insert(labelName,labelClass);
}

//ClickLabel *LabelFactory::CreateLabel(const QString &labelName)
//{
//    auto it =m_nameToLabelDictionary.find(labelName);
//    if(it!=m_nameToLabelDictionary.end())
//    {
//        return it.value();
//    }
//    else
//    {
//        return nullptr;
//    }
//}

ClickLabel *LabelFactory::CreateLabel(const QString &labelName, QWidget *parent)
{
    auto it =m_LabelCreator.find(labelName);
    if(it!=m_LabelCreator.end())
    {
        return it.value()(parent);
    }
    else
    {
        return nullptr;
    }
}

LabelFactory::LabelFactory()
{

}
