#ifndef CLICKLABEL_H
#define CLICKLABEL_H

#include <QObject>
#include <QLabel>
#include <QMouseEvent>

#include "uiwidget.h"

class Card;
class ClickLabel : public QLabel
{
    Q_OBJECT
public:
    explicit ClickLabel(QWidget *parent = nullptr);

    void mousePressEvent(QMouseEvent* e)override;
    void mouseReleaseEvent(QMouseEvent* e)override;

    virtual void LinkToWidget(UIWidget* linkWidget);
    virtual void SetImage(QString imageUrl);
    virtual void resetImage();
    virtual void SetCard(Card*){};
signals:
    void me(ClickLabel*);
    void clicked();
    void startLink(UIWidget*);
    void cardClicked(Card*);
protected:
    UIWidget* m_linkWidget;
    QString  m_imageUrl;
};

#endif // CLICKLABEL_H
