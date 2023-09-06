#ifndef LABELREGISTER_H
#define LABELREGISTER_H
#pragma once

#include <QString>

#include "labelfactory.h"
#include "../../UI/clicklabel.h"

class LabelRegister
{
public:
    LabelRegister();
    LabelRegister(const QString &labelName,ClickLabel* labelClass);
    LabelRegister(const QString &labelName,std::function<ClickLabel*(QWidget*)> labelClass);

};


//#define REGISTER_LABEL(labelName) \
//ClickLabel * CreateLabel##labelName() \
//{ \
//        ClickLabel* obj =new labelName(); \
//        return obj; \
//} \
//LabelRegister labelRegister##labelName(#labelName,CreateLabel##labelName());


//REGISTER_LABEL(OpenLabel);


//#define REGISTER_LABEL(labelName)\
//static LabelRegister labelRegister_##labelName(#labelName, createLabelCreator<labelName>());

#define REGISTER_LABEL(labelName) static LabelRegister labelRegister_##labelName(#labelName,createLabelCreator< labelName > () );


#endif // LABELREGISTER_H
