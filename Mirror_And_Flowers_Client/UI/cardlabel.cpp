#include "cardlabel.h"

CardLabel::CardLabel(QWidget *parent)
    : ClickLabel{parent}
{

}

void CardLabel::mouseReleaseEvent(QMouseEvent *e)
{
    if(e->button()==Qt::LeftButton)
    {
        emit ClickLabel::cardClicked(m_card);
    }
}

void CardLabel::SetCard(Card * card)
{
    m_card=card;
    //SetImage(m_card->GetImageUrl());
}
