#include "attributeeditwidget.h"

AttributeEditWidget::AttributeEditWidget(QWidget *parent)
    : UIWidget{parent}
{
    m_lineEdit=new QLineEdit(this);
    m_btnLabel=new ClickLabel(this);
    m_btnLabel->setAlignment(Qt::AlignCenter);
}


void AttributeEditWidget::SetLinkAttribute(const QString &newLinkAttribute)
{
    m_linkAttribute = newLinkAttribute;
}

void AttributeEditWidget::SetTitle(QString title)
{
    SetLinkAttribute(title);
}

void AttributeEditWidget::InitWidget()
{

    QRect rect=this->geometry();
    //qDebug()<<" 这里！！！！！！！！！-----widgetRect"<<rect;
    m_lineEdit->setGeometry(
                                ConstNumber::MARGINSMALL,
                                ConstNumber::MARGINSMALL,
                                0.6*rect.width(),
                                (rect.height()-2*ConstNumber::MARGINSMALL)
                            );
    if(!m_linkAttribute.isEmpty())
    {
        //qDebug()<<"在这里";
        m_lineEdit->setPlaceholderText(QString("修改")+m_linkAttribute);
    }else
    {

    }
    m_btnLabel->setGeometry(
                                0.7*rect.width()+ConstNumber::MARGINSMALL,
                                ConstNumber::MARGINSMALL,
                                (0.3*rect.width()-2*ConstNumber::MARGINSMALL),
                                (rect.height()-2*ConstNumber::MARGINSMALL)
        );
    m_btnLabel->setText("提交");

    connect(m_btnLabel,&ClickLabel::clicked,this,[=](){
            emit AttributeChanged(m_lineEdit->text());
    });
}


