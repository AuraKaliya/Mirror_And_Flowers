#ifndef CARDINFOWIDGET_H
#define CARDINFOWIDGET_H

#include <QWidget>

#include "uiwidget.h"
#include "../PROTOOL/widgetregister.h"

#include "../PROTOOL/cardhub.h"
#include "clicklabel.h"
#include "../DATA/constnumber.h"
#include "attributeshowwidget.h"
class CardInfoWidget : public UIWidget
{
    Q_OBJECT
public:
    explicit CardInfoWidget(QWidget *parent = nullptr);
    void InitWidget()override;
    void SetCard(Card* card)override;
    void UpdateWidgetInfo()override;
    void AddWidget(AttributeShowWidget*pWidget)override;
    void wheelEvent(QWheelEvent* e)override;
    void RedoMove()override;
signals:
    void AddToDeck(Card*);
private:
    Card* m_nowCard;

    QWidget* m_viewWidget;
    QLabel* m_cardImageLabel;

    QLabel* m_cardATKLabel;
    QLabel* m_cardDEFLabel;
    QLabel* m_cardDHPLabel;

    QVector<AttributeShowWidget*> m_attributeWidgetList;

    QLabel* m_cardNameLabel;
    QLabel* m_cardCategtoryLabel;

    ClickLabel* m_addToDeckLabel;

};
REGISTER_WIDGET(CardInfoWidget);
#endif // CARDINFOWIDGET_H
