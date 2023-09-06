#ifndef JUMPLABEL_H
#define JUMPLABEL_H

#include "clicklabel.h"

class JumpLabel:public ClickLabel
{
    Q_OBJECT
public:
    explicit JumpLabel(QWidget *parent = nullptr);

};

#endif // JUMPLABEL_H
