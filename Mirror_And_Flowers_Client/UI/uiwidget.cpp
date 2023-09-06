#include "uiwidget.h"

UIWidget::UIWidget(QWidget *parent)
    : QWidget{parent}
{

}

void UIWidget::SetBackgroundPixUrl(QString pixUrl)
{
    m_backgroundPixUrl=pixUrl;
}

void UIWidget::SetStyle(QString styleSheetStr)
{
    setStyleSheet(this->styleSheet()+";"+styleSheetStr);
}

void UIWidget::SetRect(QRect rect)
{
    setGeometry(rect);
}

void UIWidget::SetSize(QSize size)
{
    resize(size);
}

bool UIWidget::IsSingle()
{
    return false;
}

void UIWidget::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    if(!m_backgroundPixUrl.isEmpty())
    {
        painter.setPen(QPen(Qt::white));
        painter.setBrush(QBrush(QPixmap(m_backgroundPixUrl).scaled(QSize(1400,50))));
        //painter.drawPixmap(QRect(0,0,this->width(),this->height()),QPixmap(m_backgroundPixUrl));
        painter.drawRoundedRect(QRect(0,0,this->width()-1,this->height()-1), 15, 15);

    }
}
