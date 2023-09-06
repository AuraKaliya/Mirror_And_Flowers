#ifndef VIEWPORTWIDGET_H
#define VIEWPORTWIDGET_H

#include <QWidget>
#include <QVector>
#include <QMouseEvent>
#include "uiwidget.h"
#include "../PROTOOL/widgetregister.h"
#include "../DATA/constnumber.h"


class ViewPortWidget : public UIWidget
{
    Q_OBJECT
public:
    explicit ViewPortWidget(QWidget *parent = nullptr);
    void mouseReleaseEvent(QMouseEvent* e)override;
    void mousePressEvent(QMouseEvent* e)override;
    void mouseMoveEvent(QMouseEvent* e)override;
    void InitWidget()override;
    void AddWidget(UIWidget*pWidget)override;
    void SetRestriction(int restriction)override;
    void RedoLayout();
    void RedoMove()override;
signals:
private:

    Character* m_nowCharacter;


    bool m_mousePressed;
    int  m_heightGap;
    int  m_widthDistance;
    int  m_heightRestriction;
    QVector<UIWidget*> m_characterShowWidgetList;
};
REGISTER_WIDGET(ViewPortWidget);
#endif // VIEWPORTWIDGET_H
