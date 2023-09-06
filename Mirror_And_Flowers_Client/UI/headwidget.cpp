#include "headwidget.h"

#include <QRect>
#include <QPalette>
#include "../DATA/constnumber.h"

HeadWidget* HeadWidget::m_instance=nullptr;

HeadWidget::HeadWidget(QWidget *parent)
    : UIWidget{parent}
{
    setWindowFlags(Qt::FramelessWindowHint);
//    QPalette pal(this->palette());
//    pal.setColor(QPalette::Window, Qt::yellow);
//    setAutoFillBackground(true);
//    setPalette(pal);

}

HeadWidget *HeadWidget::GetInstance()
{
    if(m_instance==nullptr)
    {
        m_instance=new HeadWidget();
    }
    return m_instance;
}

void HeadWidget::InitWidget()
{

    QRect rect=this->geometry();

    m_headLabel=new QLabel(this);
    QRect hLRect=QRect(ConstNumber::MARGINSMALL,
                       ConstNumber::MARGINSMALL,
                       rect.height()-2*ConstNumber::MARGINSMALL,
                       rect.height()-2*ConstNumber::MARGINSMALL);
    m_headLabel->setGeometry(hLRect);

    m_userNameLabel=new QLabel(this);
    QRect uNL=QRect(hLRect.x()+hLRect.width()+ConstNumber::MARGINSMALL,
                    hLRect.y(),
                    ConstNumber::WIDTHSMALL,
                    ConstNumber::HEIGHTSMALL);
    m_userNameLabel->setGeometry(uNL);
    m_userNameLabel->setAlignment(Qt::AlignCenter);

    m_userIPLabel=new QLabel(this);
    QRect uIL=QRect(hLRect.x()+hLRect.width()+ConstNumber::MARGINSMALL,
                    hLRect.y()+ConstNumber::HEIGHTSMALL+ConstNumber::MARGINSMALL,
                    ConstNumber::WIDTHSMALL,
                    ConstNumber::HEIGHTSMALL);
    m_userIPLabel->setGeometry(uIL);
    m_userIPLabel->setAlignment(Qt::AlignCenter);
}

bool HeadWidget::IsSingle()
{
    return false;
}

void HeadWidget::SetBackgroundPixUrl(QString pixUrl)
{
    m_backgroundPixUrl=pixUrl;
    //qDebug()<<"this-=-========================\n"<<this->styleSheet();
}

void HeadWidget::SetLabelPixUrl(QString pixUrl)
{
    m_userNameLabel->setStyleSheet(m_userNameLabel->styleSheet()+QString("border-image:url("+pixUrl+");"));
    m_userIPLabel->setStyleSheet(m_userIPLabel->styleSheet()+QString("border-image:url("+pixUrl+");"));
}

void HeadWidget::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    if(!m_backgroundPixUrl.isEmpty())
    {
        painter.setPen(QPen(Qt::white));
        painter.setBrush(QBrush(QPixmap(m_backgroundPixUrl)));
        //painter.drawPixmap(QRect(0,0,this->width(),this->height()),QPixmap(m_backgroundPixUrl));
        painter.drawRoundedRect(QRect(0,0,this->width()-1,this->height()-1), 15, 15);

    }

}

void HeadWidget::SetMask(QString maskUrl)
{
    m_headLabel->setMask(QPixmap(maskUrl).scaled(m_headLabel->size()).mask());
}

void HeadWidget::UpdateUserInfo(QString headImageUrl, QString userName, QString userIP)
{
    if(headImageUrl.isEmpty())
    {

    }
    else
    {
        m_headLabel->setPixmap(QPixmap(headImageUrl).scaled(QSize(m_headLabel->size())));
    }
    if(userName.isEmpty())
    {

    }
    else
    {
        m_userNameLabel->setText(userName);
    }
    if(userIP.isEmpty())
    {

    }
    else
    {
        m_userIPLabel->setText(userIP);
    }
}


