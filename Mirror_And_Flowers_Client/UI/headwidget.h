#ifndef HEADWIDGET_H
#define HEADWIDGET_H

#include <QWidget>
#include <QLabel>

#include "uiwidget.h"
#include "../PROTOOL/widgetregister.h"


//这个应该是可以有多个实例的

class HeadWidget : public UIWidget
{
    Q_OBJECT
public:
    explicit HeadWidget(QWidget *parent = nullptr);
    static HeadWidget*GetInstance();
    void InitWidget()override;
    bool IsSingle()override;
    void SetBackgroundPixUrl(QString pixUrl)override;
    void paintEvent(QPaintEvent*e)override;
    void SetLabelPixUrl(QString pixUrl)override;

    void SetMask(QString mask)override;
public slots:
    void UpdateUserInfo(QString headImageUrl,QString userName,QString userIP)override;

signals:
private:
    static HeadWidget * m_instance;
    QString m_backgroundPixUrl;
    QPixmap m_backgroundImage;
    QLabel *m_headLabel;
    QLabel *m_userNameLabel;
    QLabel *m_userIPLabel;
};

REGISTER_WIDGET(HeadWidget);
#endif // HEADWIDGET_H
