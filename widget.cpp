#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QStackedWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    resize(1600,900);
    //------------------------------------------测试------------------------------------------//
    //测试MachineInformation能否正常获取
    MachineInformation* machineInfo=MachineInformation::GetInstance();
    machineInfo->InitMachineInformation();

    QString tmpStr=machineInfo->GetMachineName();
    qDebug()<<tmpStr;
    tmpStr=machineInfo->GetMachineMac();
    qDebug()<<tmpStr;


    //进行数据初始化----//
    //UserInfo
    UserInformation::GetInstance()->SetUserIP(MachineInformation::GetInstance()->GetMachineMac());


    //进行数据初始化----//

    //------------------------------------------测试------------------------------------------//
    //测试相对路径
    QImage image;
    if(false==image.load("./RESOURCE/Image_90001.png"))
    {
        qDebug()<<"False---"<<Qt::endl;
    }

    //------------------------------------------测试------------------------------------------//
    //测试JSON读取

    JsonReader* jsr=JsonReader::GetInstance();

    //读取USER数据-----//
    QString fileName="./RESOURCE/USER.json";
    jsr->SetFileName(fileName);
    jsr->ReadJsonToUser();
    //读取USER数据-----//

    //读取character数据----//
    fileName="./RESOURCE/CHARACTER.json";
    jsr->SetFileName(fileName);
    jsr->ReadJsonToCharacter();
    //读取character数据----//



    //读取card数据----//
    fileName="./RESOURCE/CARD.json";
    jsr->SetFileName(fileName);
    jsr->ReadJsonToCard();
    //读取card数据----//

    //读取CardDeck数据--------//
    fileName="./RESOURCE/CARDDECK.json";
    jsr->SetFileName(fileName);
    jsr->ReadJsonToCardDeck();
    //读取CardDeck数据--------//

    //读取UI设置-----//
    fileName="./RESOURCE/UI.json";
    jsr->SetFileName(fileName);
    jsr->ReadJsonToUI(this);
    qDebug()<<"currentWidget:"<<this->currentWidget();
    //读取UI设置-----//


    //进行更新--//
    WidgetManager::GetInstance()->UpdateWidget();
    //进行更新--//

    //------------------------------------------测试------------------------------------------//

    BattleWidget * btw=new BattleWidget();
    btw->setVisible(false);
    QPushButton * tmpBtn=new QPushButton("战斗测试",this);
    tmpBtn->setGeometry(0,800,100,50);
    connect(tmpBtn,&QPushButton::clicked,[=](){
        BattleManager::GetInstance()->SetOpCharacter(CharacterHub::GetInstance()->GetCharacterList()[0]);
        btw->BattleStar();
        btw->setVisible(true);
    });

    //------------------------------------------测试------------------------------------------//






}

Widget::~Widget()
{
    delete ui;
}

