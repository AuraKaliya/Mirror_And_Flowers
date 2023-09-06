#ifndef CARDDECKSHOWWIDGET_H
#define CARDDECKSHOWWIDGET_H

#include <QWidget>
#include <QLabel>

#include "clicklabel.h"
#include "uiwidget.h"
#include "../PROTOOL/widgetregister.h"
#include "../PROTOOL/carddeckhub.h"
#include "../DATA/constnumber.h"
#include "../PROTOOL/cardhub.h"
class CardDeckShowWidget : public UIWidget
{
    Q_OBJECT
public:
    explicit CardDeckShowWidget(QWidget *parent = nullptr);

    void InitWidget()override;
    void InitCardWidget();
    void AddToCardDeck(int ID);
    void RedoMove()override;
signals:
private:
    QLabel * m_cardsNumberLabel;
    QVector<QWidget*> m_cardWidget;
    CardDeck* m_cardDeckMe;
};

#endif // CARDDECKSHOWWIDGET_H
