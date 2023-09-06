#ifndef TOOLWIDGET_H
#define TOOLWIDGET_H

#include <QWidget>

#include "uiwidget.h"
#include "clicklabel.h"
#include "../PROTOOL/widgetregister.h"
#include "../DATA/constnumber.h"
#include "../PROTOOL/stylemanager.h"

class ToolWidget : public UIWidget
{
    Q_OBJECT
public:
    explicit ToolWidget(QWidget *parent = nullptr);
    void mouseReleaseEvent(QMouseEvent* e)override;
    void mousePressEvent(QMouseEvent* e)override;
    void mouseMoveEvent(QMouseEvent* e)override;
    void InitWidget()override;
    void SetBackgroundPixUrl(QString pixUrl)override;
    void paintEvent(QPaintEvent*e)override;
signals:
private:
    bool m_isPressed;
    QPointF m_starPoint;
    QPointF m_distancePoint;
    QString m_backgroundPixUrl;
};

REGISTER_WIDGET(ToolWidget);
#endif // TOOLWIDGET_H
