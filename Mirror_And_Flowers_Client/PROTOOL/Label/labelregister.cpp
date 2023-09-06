#include "labelregister.h"

LabelRegister::LabelRegister()
{

}

LabelRegister::LabelRegister(const QString &labelName, ClickLabel *labelClass)
{
    LabelFactory* factory =LabelFactory::GetInstance();
    factory->RegisterLabel(labelName,labelClass);
}

LabelRegister::LabelRegister(const QString &labelName, std::function<ClickLabel *(QWidget *)> labelClass)
{
    LabelFactory* factory =LabelFactory::GetInstance();
    factory->RegisterLabel(labelName,labelClass);
}
