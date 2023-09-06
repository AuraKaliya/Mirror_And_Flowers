#include "modifywidget.h"

ModifyWidget::ModifyWidget(QWidget *parent)
    : UIWidget{parent}
{

}

void ModifyWidget::AddWidget(UIWidget *pWidget)
{
    //qDebug()<<"zZHELI这里231231541！！！";
    pWidget->setParent(this);
    pWidget->setGeometry(0,
                        (ConstNumber::MARGINSMALL*(m_modifyOptionList.size()+1)+ConstNumber::HEIGHTSMALL*(m_modifyOptionList.size())),
                        this->width(),
                        ConstNumber::HEIGHTSMALL
                        );
    //qDebug()<<"属性编辑栏的  223333333333333333333333333333333RECT："<<pWidget->geometry();
    m_modifyOptionList.append(pWidget);
    pWidget->setVisible(true);
    this->adjustSize();
}
