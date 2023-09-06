#ifndef CHARACTERWIDGET_H
#define CHARACTERWIDGET_H

#include <QWidget>

#include "uiwidget.h"
#include "../PROTOOL/widgetregister.h"

class CharacterWidget : public UIWidget
{
    Q_OBJECT
public:
    static CharacterWidget*GetInstance();
    void InitWidget()override;
    void SetBackgroundPixUrl(QString pixUrl)override;
    void paintEvent(QPaintEvent*e)override;
private:
    static CharacterWidget* m_instance;
    explicit CharacterWidget(QWidget *parent = nullptr);
    QString m_backgroundPixUrl;

signals:

};

REGISTER_WIDGET_SINGLE(CharacterWidget);
#endif // CHARACTERWIDGET_H
