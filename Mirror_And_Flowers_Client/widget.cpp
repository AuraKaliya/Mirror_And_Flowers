#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


    //------------------------------------------测试------------------------------------------//
    //测试MachineInformation能否正常获取
    MachineInformation* machineInfo=MachineInformation::GetInstance();
    machineInfo->InitMachineInformation();

    QString tmpStr=machineInfo->GetMachineName();
    qDebug()<<tmpStr;

    tmpStr=machineInfo->GetMachineMac();
    qDebug()<<tmpStr;

    //------------------------------------------测试------------------------------------------//


    //------------------------------------------测试------------------------------------------//




}

Widget::~Widget()
{
    delete ui;
}

