#include "openlabel.h"

OpenLabel::OpenLabel(QWidget *parent)
    : ClickLabel{parent}
{

}

void OpenLabel::mouseReleaseEvent(QMouseEvent *e)
{
    if(e->button()==Qt::LeftButton)
    {
        if(m_linkWidget!=nullptr )
        {
            if(!m_linkWidget->isVisible())
            {
                m_linkWidget->show();
            }
        }
    }
}

//void OpenLabel::SetImage(QString imageUrl)
//{
//    qDebug()<<"OpenLabel--"<<imageUrl;
//    setStyleSheet("border-image:"+imageUrl+";");
//    QPixmap pixmap(imageUrl);
//    if(pixmap.isNull())
//    {
//        qDebug()<<"Null!";
//    }
//    else
//    {
//        qDebug()<<"THis!";
//        setPixmap(pixmap);
//    }

//}
