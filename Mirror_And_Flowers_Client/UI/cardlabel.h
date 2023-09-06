#ifndef CARDLABEL_H
#define CARDLABEL_H

#include <QLabel>
#include <QObject>

#include "clicklabel.h"
#include "../PROTOOL/Label/labelregister.h"

#include "../PROTOOL/cardhub.h"

class CardLabel : public ClickLabel
{
    Q_OBJECT
public:
    explicit CardLabel(QWidget *parent = nullptr);
    void mouseReleaseEvent(QMouseEvent* e)override;
    void SetCard(Card*card)override;

private:
     Card* m_card;

};
REGISTER_LABEL(CardLabel);
#endif // CARDLABEL_H
