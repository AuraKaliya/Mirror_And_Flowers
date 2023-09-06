#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>

#include "uiwidget.h"
#include "../PROTOOL/widgetregister.h"
class MainWidget : public UIWidget
{
    Q_OBJECT
public:
    static MainWidget* GetInstance();
    void InitWidget(const QJsonObject& obj)override;
    void SetBackgroundPixUrl(QString pixUrl)override;
    void paintEvent(QPaintEvent* e)override;
    bool IsSingle()override;
private:

    static MainWidget* m_instance;
    QString m_backgroundPixUrl;
    explicit MainWidget(QWidget *parent = nullptr);


signals:

};

REGISTER_WIDGET_SINGLE(MainWidget);
#endif // MAINWIDGET_H
