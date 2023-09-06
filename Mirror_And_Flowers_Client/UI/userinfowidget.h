#ifndef USERINFOWIDGET_H
#define USERINFOWIDGET_H

#include <QWidget>

#include "uiwidget.h"
#include "../PROTOOL/widgetregister.h"

class UserInfoWidget : public UIWidget
{
    Q_OBJECT
public:
    static UserInfoWidget* GetInstance();
    void InitWidget(const QJsonObject& obj)override;
    void SetBackgroundPixUrl(QString pixUrl)override;
    void paintEvent(QPaintEvent*e)override;
private:
    static UserInfoWidget* m_instance;
    explicit UserInfoWidget(QWidget *parent = nullptr);
    QString m_backgroundPixUrl;
signals:

};

REGISTER_WIDGET_SINGLE(UserInfoWidget);
#endif // USERINFOWIDGET_H
