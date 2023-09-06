#include "optionlistwidget.h"

OptionListWidget::OptionListWidget(QWidget *parent)
    : UIWidget{parent}
{

//    QPalette pal(this->palette());
//    pal.setColor(QPalette::Window, Qt::yellow);
//    setAutoFillBackground(true);
//    setPalette(pal);
}

void OptionListWidget::AddLabel(ClickLabel *pLabel)
{
    pLabel->setParent(this);
    pLabel->setGeometry((ConstNumber::MARGINSMALL*(m_optionLabelList.size())+ConstNumber::R130*(m_optionLabelList.size())),
                         0,
                         ConstNumber::R130,
                         ConstNumber::R130);
    m_optionLabelList.append(pLabel);
    pLabel->setVisible(true);
    this->adjustSize();
}
