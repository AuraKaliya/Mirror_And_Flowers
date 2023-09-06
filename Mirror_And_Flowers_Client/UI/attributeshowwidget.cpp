#include "attributeshowwidget.h"

AttributeShowWidget::AttributeShowWidget(QWidget *parent)
    : UIWidget{parent}
{
    m_attributeNameLabel=new QLabel(this);
    m_attributeValueLabel=new QLabel(this);
    m_attributeShowLabel=new QLabel(this);
    m_attributeNameLabel->setAlignment(Qt::AlignCenter);
    m_attributeValueLabel->setAlignment(Qt::AlignCenter);
    m_attributeShowLabel->setAlignment(Qt::AlignCenter);
}

void AttributeShowWidget::SetTitle(QString title)
{
    m_linkAttribute=title;
    m_attributeValueMax=ConstNumber::GetAttributeMax(m_linkAttribute);
}


void AttributeShowWidget::InitWidget()
{
    m_attributeNameLabel->setText(m_linkAttribute);
    m_attributeValueLabel->setText(QString::number(m_attributeValue));

    int starNumber=abs(10*((m_attributeValue*1.0)/(m_attributeValueMax*1.0)));
    QString tmpStr="";
    for(int i=0;i<starNumber;++i)
    {
        tmpStr+="●";
    }

    for(int i=starNumber;i<10;++i)
    {
        tmpStr+="○";
    }
    m_attributeShowLabel->setText(tmpStr);

    QRect rect=geometry();
    m_attributeNameLabel->setGeometry(ConstNumber::MARGINSMALL,
                                      ConstNumber::MARGINSMALL,
                                      (rect.width()-ConstNumber::MARGINSMALL*2)*0.2,
                                      rect.height()-2*ConstNumber::MARGINSMALL
                                      );
    m_attributeShowLabel->setGeometry(ConstNumber::MARGINSMALL+m_attributeNameLabel->width(),
                                      ConstNumber::MARGINSMALL,
                                      (rect.width()-ConstNumber::MARGINSMALL*2)*0.6,
                                      rect.height()-2*ConstNumber::MARGINSMALL
                                      );
    m_attributeValueLabel->setGeometry(ConstNumber::MARGINSMALL+m_attributeNameLabel->width()+m_attributeShowLabel->width(),
                                      ConstNumber::MARGINSMALL,
                                      (rect.width()-ConstNumber::MARGINSMALL*2)*0.2,
                                      rect.height()-2*ConstNumber::MARGINSMALL
                                      );

    qDebug()<<"检查----"<<this->isVisible();
    qDebug()<<"检查----"<<m_attributeValueLabel->text();

}

void AttributeShowWidget::SetValue(int value)
{
    m_attributeValue=value;
}

void AttributeShowWidget::UpdateWidgetInfo()
{
    InitWidget();
}
