#include "clicklabel.h"

ClickLabel::ClickLabel(QWidget *parent)
    : QLabel{parent}
{

}

void ClickLabel::mousePressEvent(QMouseEvent *e)
{

}

void ClickLabel::mouseReleaseEvent(QMouseEvent *e)
{
    //可以通过不带参的clicked信号与明确/指定的类的槽函数相连，执行不需要传递的数据的函数。
    //可以通过传递目标参数的信号进行需要传递数据的处理。
    //传递参数可变-不同类的同一个处理-connect中的类可变，需要一个上级类。
    if(e->button()==Qt::LeftButton)
    {
        emit clicked();
        emit me(this);
        if(m_linkWidget!=nullptr)
        {
            emit startLink(m_linkWidget);
        }
    }
}

void ClickLabel::LinkToWidget(UIWidget *linkWidget)
{
    m_linkWidget=linkWidget;
}

void ClickLabel::SetImage(QString imageUrl)
{
    qDebug()<<"Base SetImage";
    m_imageUrl=imageUrl;
    QString styleSheetPlus("border-image:url("+imageUrl+");");
    setStyleSheet(styleSheet()+styleSheetPlus);
    qDebug()<<styleSheet();
    qDebug()<<"Base SetImage end";
}

void ClickLabel::resetImage()
{

}
