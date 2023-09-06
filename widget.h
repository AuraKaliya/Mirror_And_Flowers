#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QStackedWidget>
#include <QDebug>

#include <QPushButton>

//------------------------------------------测试------------------------------------------//
#include "DATA/machineinformation.h"

#include "PROTOOL/jsonreader.h"
#include "PROTOOL/widgetmanager.h"

//-------------================其他测试=========-=//
#include "UI/Battle/battlewidget.h"
#include "PROTOOL/characterhub.h"
//-------------================其他测试=========-=//
//------------------------------------------测试------------------------------------------//
#pragma execution_character_set("utf-8")
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QStackedWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
