#ifndef JSONREADER_H
#define JSONREADER_H

#include <QObject>
#include <QStackedWidget>

#include "../UI/uiwidget.h"
#include "widgetfactory.h"
#include "Label/labelfactory.h"
#include "../DATA/userinformation.h"
#include "../DATA/machineinformation.h"
#include "widgetmanager.h"
#include "characterhub.h"
#include "battlemanager.h"
#include "carddeckhub.h"

class JsonReader : public QObject
{
    Q_OBJECT
public:
    static JsonReader* GetInstance();
    void SetFileName(const QString &fileName);
    void ReadJsonToUI(QStackedWidget* parentWidget);
    void ReadJsonToUser();
    void ReadJsonToCharacter();
    void ReadJsonToCard();
    void ReadJsonToCardDeck();

    static void readCompleteWidget(const QJsonObject &obj,QWidget* parentWidget);
    static void readObjectWidget(const QJsonObject &obj,QWidget* parentWidget);

    static void readToMainWidget(const QJsonObject &obj,UIWidget* parentWidget);
    static void readToHeadWidget(const QJsonObject &obj,UIWidget* parentWidget);
    static void readToClickLabel(const QJsonObject &obj,UIWidget* parentWidget);
    static void readToListWidget(const QJsonObject &obj,UIWidget* parentWidget);
    static void readToTalkWidget(const QJsonObject &obj,UIWidget* parentWidget);

    static void readSetting(const QJsonObject &obj,UIWidget* widget);
    static void readLabelGroup(const QJsonArray &array,UIWidget* parentWidget);
    static void readEditBoxGroup(const QJsonArray &array,UIWidget* parentWidget);
    static void readCharacterBoxGroup(const QJsonObject &obj,UIWidget* parentWidget);
    static void readCardBoxGroup(const QJsonObject &obj,UIWidget* parentWidget);
public slots:
    static void  AttributeUserNameChanged(QString str);
private:
    static JsonReader* m_instance;
    explicit JsonReader(QObject *parent = nullptr);
    QString m_fileName;



signals:

};

#endif // JSONREADER_H
