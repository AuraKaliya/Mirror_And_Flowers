// JsonReader.cpp
#include "jsonreader.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>

JsonReader* JsonReader::m_instance = nullptr;

JsonReader* JsonReader::GetInstance()
{
    if (m_instance == nullptr)
    {
        m_instance = new JsonReader();
    }
    return m_instance;
}

void JsonReader::SetFileName(const QString &fileName)
{
    m_fileName = fileName;
}

void JsonReader::ReadJsonToUI(QStackedWidget *parentWidget)
{
    QFile file(m_fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Cannot open file" << m_fileName;
        return;
    }
    QByteArray data = file.readAll();
    QJsonParseError parseError;

    QJsonDocument doc = QJsonDocument::fromJson(data,&parseError);
    if(parseError.error != QJsonParseError::NoError||doc.isNull()||!doc.isObject())
    {
        qDebug()<<"faild to ex";
        return;
    }
    QJsonObject uiRoot=doc.object();
    QJsonArray rootFixedWidget = uiRoot.value("UIFixedWidget").toArray();

    for (const QJsonValue& element : rootFixedWidget) {

        QJsonObject obj = element.toObject();
        UIWidget* widget = WidgetFactory::GetInstance()->CreateWidget(obj.value("ClassName").toString());
        parentWidget->addWidget(widget);
        readCompleteWidget(obj,parentWidget);
    }

    QJsonArray rootActiveWidget =uiRoot.value("UIActiveWidget").toArray();
    for(const QJsonValue& element : rootActiveWidget)
    {
        QJsonObject obj = element.toObject();
        UIWidget* widget = WidgetFactory::GetInstance()->CreateWidget(obj.value("ClassName").toString());
        readCompleteWidget(obj,nullptr);
        widget->setVisible(false);
    }

    file.close();
}

void JsonReader::ReadJsonToUser()
{
    QFile file(m_fileName);
    QString imageUrl;
    QString userName;

    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Cannot open file" << m_fileName;

        userName=MachineInformation::GetInstance()->GetMachineName();
        imageUrl="./RESOURCE/Image_90006.png";
        UserInformation::GetInstance()->SetUserName(userName);
        UserInformation::GetInstance()->SetHeadImageUrl(imageUrl);
        return;
    }
    QByteArray data = file.readAll();
    QJsonParseError parseError;

    QJsonDocument doc = QJsonDocument::fromJson(data,&parseError);
    if(parseError.error != QJsonParseError::NoError||doc.isNull()||!doc.isObject())
    {
        qDebug()<<"faild to ex";
        return;
    }
    QJsonObject root=doc.object();
    imageUrl=root.value("HeadImageUrl").toString();
    userName=root.value("UserName").toString();
    UserInformation::GetInstance()->SetUserName(userName);
    UserInformation::GetInstance()->SetHeadImageUrl(imageUrl);
}

void JsonReader::ReadJsonToCharacter()
{
    QFile file(m_fileName);

    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Cannot open file" << m_fileName;
        return;
    }
    QByteArray data = file.readAll();
    QJsonParseError parseError;

    QJsonDocument doc = QJsonDocument::fromJson(data,&parseError);
    if(parseError.error != QJsonParseError::NoError||doc.isNull()||!doc.isArray())
    {
        qDebug()<<"faild to ex";
        return;
    }
    QJsonArray root=doc.array();
    for (const QJsonValue& element:root)
    {
        QJsonObject characterObj=element.toObject();
        Character* character=new Character();
        character->SetID(characterObj.value("ID").toInt());
        character->SetName(characterObj.value("Name").toString());
        character->SetTitle(characterObj.value("Title").toString());
        character->SetTachieUrl(characterObj.value("TachieUrl").toString());
        character->SetIntroduction(characterObj.value("Introduction").toString());
        character->SetATK(characterObj.value("ATK").toInt());
        character->SetDEF(characterObj.value("DEF").toInt());
        character->SetHP(characterObj.value("HP").toInt());

        CharacterHub::GetInstance()->AddCharacter(character);
    }

    //初始化默认角色
    CharacterHub::GetInstance()->ChangeNowCharacter(CharacterHub::GetInstance()->GetCharacterList()[0]);

    //检查
    for( auto it:CharacterHub::GetInstance()->GetCharacterList())
    {
        qDebug()<<"角色："<<it->GetName();
    }
    //检查

    qDebug()<<"默认角色:"<<CharacterHub::GetInstance()->GetNowCharacter()->GetName();
}

void JsonReader::ReadJsonToCard()
{
    QFile file(m_fileName);

    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Cannot open file" << m_fileName;
        return;
    }
    QByteArray data = file.readAll();
    QJsonParseError parseError;

    QJsonDocument doc = QJsonDocument::fromJson(data,&parseError);
    if(parseError.error != QJsonParseError::NoError||doc.isNull()||!doc.isArray())
    {
        qDebug()<<"faild to ex";
        return;
    }
    QJsonArray root=doc.array();
    for (const QJsonValue& element:root)
    {
        QJsonObject cardObj=element.toObject();
        Card *card=new Card();
        card->SetID(cardObj.value("ID").toInt());
        card->SetName(cardObj.value("Name").toString());
        card->SetCategory(cardObj.value("Category").toString());
        card->SetATK(cardObj.value("ATK").toInt());
        card->SetDEF(cardObj.value("DEF").toInt());
        card->SetDHP(cardObj.value("DHP").toInt());
        card->SetIntroduction(cardObj.value("Introduction").toString());
        card->SetImageUrl(cardObj.value("ImageUrl").toString());

        CardHub::GetInstance()->AddCard(card);
    }

    for( auto it:CardHub::GetInstance()->GetCardList())
    {
        qDebug()<<"卡牌："<<it->GetName();
    }

}

void JsonReader::ReadJsonToCardDeck()
{
    QFile file(m_fileName);

    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Cannot open file" << m_fileName;
        return;
    }
    QByteArray data = file.readAll();
    QJsonParseError parseError;

    QJsonDocument doc = QJsonDocument::fromJson(data,&parseError);
    if(parseError.error != QJsonParseError::NoError||doc.isNull()||!doc.isArray())
    {
        qDebug()<<"faild to ex";
        return;
    }
    QJsonArray root=doc.array();
    for (const QJsonValue& element:root)
    {
        QJsonObject cardDeckObj=element.toObject();
        CardDeck *cardDeck=new CardDeck();
        cardDeck->SetID(cardDeckObj.value("ID").toInt());
        cardDeck->SetCharacter(cardDeckObj.value("Character").toString());
        cardDeck->SetDeckName(cardDeckObj.value("Name").toString());
        cardDeck->SetCoverUrl(cardDeckObj.value("CoverUrl").toString());
        cardDeck->SetIntroduction(cardDeckObj.value("Introduction").toString());

        if (cardDeckObj.contains("CardIndex")) {
            QJsonArray index=cardDeckObj.value("CardIndex").toArray();
            for(const QJsonValue & element:index)
            {
                cardDeck->AddCard(element.toInt());
            }
        }else
        {
            qDebug()<<"卡组空";
        }


        CardDeckHub::GetInstance()->AddCardDeck(cardDeck);
    }


    CardDeckHub::GetInstance()->ChangeNowCardDeck(CardDeckHub::GetInstance()->GetCardDeckList()[0]);


    for( auto it:CardDeckHub::GetInstance()->GetCardDeckList())
    {
        qDebug()<<"卡组："<<it->GetDeckName();
        qDebug()<<it->GetContains();

    }
     qDebug()<<"默认卡组："<<CardDeckHub::GetInstance()->GetNowCardDeck()->GetDeckName();
}

void JsonReader::readCompleteWidget(const QJsonObject &obj, QWidget *parentWidget)
{
    QString className = obj["ClassName"].toString();
    UIWidget* widget = WidgetFactory::GetInstance()->CreateWidget(className);
    widget->setParent(parentWidget);

    QJsonObject setting = obj["Setting"].toObject();
    readSetting(setting,widget);
    widget->InitWidget();

    if (obj.contains("Contains")) {
        QJsonArray contains = obj["Contains"].toArray();
        for (const QJsonValue& element : contains) {
            QJsonObject subobj = element.toObject();
            QString category = subobj["Category"].toString();
            if (category == "CW") {
                readCompleteWidget(subobj, widget);
            } else if (category == "OW") {
                readObjectWidget(subobj, widget);
            }
        }
    }

    //------//
    qDebug()<<className<<"parent:"<<widget->parent();
    qDebug()<<className<<"children:"<<widget->children();
    qDebug()<<className<<"rect"<<widget->geometry();

    //------//
}

void JsonReader::readObjectWidget(const QJsonObject &obj, QWidget *parentWidget)
{
    QString className = obj["ClassName"].toString();

    UIWidget* widget = WidgetFactory::GetInstance()->CreateWidget(className);
    if(widget==nullptr)
    {
        return;
    }
    //------//
    qDebug()<<"Create:"<<className;
    //------//

    widget->setParent(parentWidget);

    QJsonObject setting = obj["Setting"].toObject();
    readSetting(setting,widget);

    if (obj.contains("Contains")) {
        QJsonArray contains = obj["Contains"].toArray();
        for (const QJsonValue& element : contains) {
            QJsonObject subobj = element.toObject();
            QString category = subobj["Category"].toString();
            if (category == "CW") {
                readCompleteWidget(subobj, widget);
            } else if (category == "OW") {
                readObjectWidget(subobj, widget);
            }
        }
    }

    if(className=="HeadWidget")
    {
        WidgetManager::GetInstance()->AddHeadWidget(widget);
    }

//------//
    qDebug()<<className<<"children:"<<widget->children();
    qDebug()<<className<<"rect"<<widget->geometry();
//------//
}

void JsonReader::readToMainWidget(const QJsonObject &obj, UIWidget *parentWidget)
{

}

void JsonReader::readToHeadWidget(const QJsonObject &obj, UIWidget *parentWidget)
{

}

void JsonReader::readToClickLabel(const QJsonObject &obj, UIWidget *parentWidget)
{

}

void JsonReader::readToListWidget(const QJsonObject &obj, UIWidget *parentWidget)
{

}

void JsonReader::readToTalkWidget(const QJsonObject &obj, UIWidget *parentWidget)
{

}

void JsonReader::readSetting(const QJsonObject &obj, UIWidget *widget)
{
    if (obj.contains("Rect")) {
        //qDebug()<<"####This####Rect####"<<widget<<"####This####Rect";
        QJsonArray rect = obj["Rect"].toArray();
        widget->SetRect(QRect(rect[0].toInt(), rect[1].toInt(), rect[2].toInt(), rect[3].toInt()));
        //qDebug()<<widget->geometry();
    }

    if (obj.contains("Title")) {

        QString title = obj["Title"].toString();
        widget->SetTitle(title);
    }


    //ObjectsGroup
    if (obj.contains("LabelGroup")) {

        QJsonArray labelGroup=obj["LabelGroup"].toArray();
        readLabelGroup(labelGroup,widget);
    }

    if (obj.contains("EditBoxGroup")) {

        QJsonArray editBoxGroup=obj["EditBoxGroup"].toArray();
        //qDebug()<<"zheli这里！！！！！！！！！！！！！";
        readEditBoxGroup(editBoxGroup,widget);
    }

    if (obj.contains("Restriction")) {

        int restriction=obj["Restriction"].toInt();
        widget->SetRestriction(restriction);
    }

    if (obj.contains("CharacterBoxGroup")) {

        QJsonObject characterBoxGroup=obj["CharacterBoxGroup"].toObject();
        readCharacterBoxGroup(characterBoxGroup,widget);
    }

    if (obj.contains("CardBoxGroup")) {
        qDebug()<<"--------CardBoxGroup----------start";

        QJsonObject cardBoxGroup=obj["CardBoxGroup"].toObject();
        readCardBoxGroup(cardBoxGroup,widget);
        qDebug()<<"--------CardBoxGroup----------end";
    }

    if (obj.contains("Init")) {
        qDebug()<<widget<<" Init Start";
        bool init = obj["Init"].toBool();
        if(init)
        {
            widget->InitWidget();
        }
        qDebug()<<widget<<"  Init End";
    }

    //Style
    if (obj.contains("Style")) {

        QString style = obj["Style"].toString();
        widget->SetStyle(style);
    }
    if (obj.contains("BackgroundPixUrl")) {
        qDebug()<<"--------BackgroundPixUrl----------start";
        QString backgroundPixUrl=obj["BackgroundPixUrl"].toString();
        widget->SetBackgroundPixUrl(backgroundPixUrl);
        qDebug()<<"--------BackgroundPixUrl----------end";
    }

    if (obj.contains("LabelPixUrl")) {
        qDebug()<<"--------BackgroundPixUrl----------start";
        QString labelPixUrl=obj["LabelPixUrl"].toString();
        widget->SetLabelPixUrl(labelPixUrl);
        qDebug()<<"--------BackgroundPixUrl----------end";
    }

    if (obj.contains("Mask")) {
        qDebug()<<"--------Mask----------start";
        QString mask=obj["Mask"].toString();
        widget->SetMask(mask);
        qDebug()<<"--------Mask----------end";
    }

    //Connect  ---
    connect(widget,&UIWidget::CharacterChoiced,BattleManager::GetInstance(),&BattleManager::CharacterChanged);
    //Connect  ---
}

void JsonReader::readLabelGroup(const QJsonArray &array, UIWidget *parentWidget)
{
    for (int i=0;i<array.size();++i)
    {
        QJsonObject obj=array[i].toObject();
        ClickLabel* label;
        if(obj.contains("LabelClass"))
        {
            label=LabelFactory::GetInstance()->CreateLabel(obj["LabelClass"].toString());
            if(obj.contains("LabelLink"))
            {
                label->LinkToWidget(WidgetFactory::GetInstance()->CreateWidget(obj["LabelLink"].toString()));
            }
            else
            {

            }

            if(obj.contains("ImageUrl"))
            {
                qDebug()<<"SetImage star";

                label->SetImage(obj["ImageUrl"].toString());

                qDebug()<<"SetImage end";
            }
            else
            {

            }
        }
        else
        {
          //--检查语句--//
            label=nullptr;
        }

        if(label!=nullptr)
        {
           qDebug()<<"addLabel star";

            parentWidget->AddLabel(label);

           qDebug()<<"addLabel end";
        }
    }
}

void JsonReader::readEditBoxGroup(const QJsonArray &array, UIWidget *parentWidget)
{
    for (int i=0;i<array.size();++i)
    {
        //qDebug()<<"PARENET 检查"<<parentWidget;
        QJsonObject obj=array[i].toObject();
        UIWidget* widget=WidgetFactory::GetInstance()->CreateWidget("AttributeEditWidget",parentWidget);
        //qDebug()<<"PARENET 检查"<<widget->parent();
        widget->SetTitle(obj.value("Tip").toString());
        parentWidget->AddWidget(widget);
        //qDebug()<<"PARENET 检查"<<widget->parent();
        //qDebug()<<"wIDGET 检查"<<widget->geometry();
        widget->InitWidget();
        if(obj.value("LinkAttribute")=="UserName")
        {
           connect(widget,&UIWidget::AttributeChanged,JsonReader::GetInstance(),&JsonReader::AttributeUserNameChanged);
        }

    }
}

void JsonReader::readCharacterBoxGroup(const QJsonObject &obj, UIWidget *parentWidget)
{
    QVector<Character*> tmpList=CharacterHub::GetInstance()->GetCharacterList();
    QSize size(obj.value("NormalSize").toArray()[0].toInt(),obj.value("NormalSize").toArray()[1].toInt());
    for(auto it:tmpList)
    {

        UIWidget* tmpWidget=WidgetFactory::GetInstance()->CreateWidget("CharacterShowWidget");

        tmpWidget->SetSize(size);
        tmpWidget->SetLinkCharacter(it);
        parentWidget->AddWidget(tmpWidget);

    }


}

void JsonReader::readCardBoxGroup(const QJsonObject &obj, UIWidget *parentWidget)
{
    qDebug()<<"-=-=-=-=-=-=-=-=-==============================";
    qDebug()<<"-=-=-=-=-=-=-=-=-==============================";
    qDebug()<<parentWidget;

    QVector<Card*> tmpList=CardHub::GetInstance()->GetCardList();
    qDebug()<<tmpList.size();
    QSize size(obj.value("NormalSize").toArray()[0].toInt(),obj.value("NormalSize").toArray()[1].toInt());

    for(auto it:tmpList)
    {

        ClickLabel* tmpLabel=LabelFactory::GetInstance()->CreateLabel("CardLabel");
        tmpLabel->resize(size);
        tmpLabel->SetCard(it);
        tmpLabel->SetImage(it->GetImageUrl());
        parentWidget->AddLabel(tmpLabel);

    }
    qDebug()<<"-=-=-=-=-=-=-=-=-==============================";
    qDebug()<<"-=-=-=-=-=-=-=-=-==============================";
}


void JsonReader::AttributeUserNameChanged(QString str)
{
    UserInformation::GetInstance()->SetUserName(str);
    WidgetManager::GetInstance()->UpdateHeadWidget();
}

JsonReader::JsonReader(QObject *parent)
{

}
