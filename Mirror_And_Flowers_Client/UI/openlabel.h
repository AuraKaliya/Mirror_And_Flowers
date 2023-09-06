#pragma once
#ifndef OPENLABEL_H
#define OPENLABEL_H


#include "clicklabel.h"

#include "../PROTOOL/Label/labelregister.h"

class OpenLabel:public ClickLabel
{
    Q_OBJECT
public:
    explicit OpenLabel(QWidget *parent = nullptr);
    void mouseReleaseEvent(QMouseEvent* e)override;

    //void SetImage(QString imageUrl)override;
};

REGISTER_LABEL(OpenLabel);
//static LabelRegister labelRegister_OpenLabel("OpenLabel", createLabelCreator<OpenLabel>());

#endif // OPENLABEL_H
