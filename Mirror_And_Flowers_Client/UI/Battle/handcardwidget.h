#ifndef HANDCARDWIDGET_H
#define HANDCARDWIDGET_H

#include <QWidget>
#include <QRect>
#include <QVector>

#include "../cardlabel.h"
#include <QPushButton>

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsProxyWidget>
#include <QPalette>
class handCardWidget : public QWidget
{
    Q_OBJECT
public:
    explicit handCardWidget(QWidget *parent = nullptr);
    void SetSmallState();
    void SetLargeState();
    void ResetHandCard();
    void SortHandCard();
    void UpdateHandCard(QVector<Card*> handCard);
    void mouseReleaseEvent(QMouseEvent*e)override;
    void UpdateNowCard(Card* card);
private:
    bool m_choiced;
    Card* m_nowCard;
    QRect m_smallState;
    QRect m_largeState;
    QSize m_smallCardSize;
    QSize m_largeCardSize;
    QVector<CardLabel*> m_handCard;

    QVector<QGraphicsScene*> m_sceneGroup;
    QVector<QGraphicsView*> m_viewGroup;
    QVector<QGraphicsProxyWidget*> m_proxyGroup;

    QGraphicsScene* m_scene;
    QGraphicsView* m_view;

    QLabel* infoLabel;
    QPushButton* m_yesButton;
    QPushButton* m_noButton;


signals:
    void cardUsed(Card*);
};

#endif // HANDCARDWIDGET_H
