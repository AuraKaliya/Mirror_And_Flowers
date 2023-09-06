# 《Mirror And Flowers》技术点整理

* Data层

    * 基于Map的点对点数据对照

        比较简单，是对map的应用。

        示例代码：

        ```c++
        QMap<QString,ConstNumber::Battle> ConstNumber::m_battleAttributeDictionary={
            {"ATK", ConstNumber::ATKMAX},
            {"DEF", ConstNumber::DEFMAX},
            {"HP", ConstNumber::HPMAX},
            {"DHP", ConstNumber::DHPMAX},
            {"DATK", ConstNumber::DATKMAX},
            {"DDEF", ConstNumber::DDEFMAX},
        };
        
        ConstNumber::Battle ConstNumber::GetAttributeMax(QString attribute)
        {
        
            auto it =m_battleAttributeDictionary.find(attribute);
            if(it != m_battleAttributeDictionary.end())
            {
                return it.value();
            }else
            {
                return ConstNumber::ERROR;
            }
        }
        ```

    * 基于split的指令格式设计和解析方式

        避免在进行数据流传递时需要自己编写解析器的情况，采用自带的QString解析器进行数据流传递。

        方法简单，即先对指令进行结构化分层，规范指令树每层使用的分割符号即可。

        示例指令：

        ```c++
        //------------------------------指令格式-------------------------//
        //          发送者|接收者（主机名+机器码前五位）|指令类型|指令名|指令值
        //         AuraKaliye70:1A|Sever|Match|JoinGame
        //         Sever|AuraKaliye70:1A|Match|Succeeded|Monkey20:3B#Luwies
        //         AuraKaliye70:1A|Sever|Battle|UseCard|10002
        //         Sever|AuraKaliye70:1A|Battle|Messages|Opponent#Card@恢复魔瓶
        //         Sever|AuraKaliye70:1A|Battle|Process|Me#NowHP@800,NowATK@300,NowDEF@400
        //         AuraKaliye70:1A|Sever|Battle|End
        //         Sever|AuraKaliye70:1A|Battle|Result|Winner@Me
        //         AuraKaliye70:1A|Sever|Battle|UseCard|10002
        //         Sever|AuraKaliye70:1A|Battle|NowTime|30
        //         Sever|AuraKaliye70:1A|Battle|NowTime|29
        //         Sever|AuraKaliye70:1A|Battle|OppoEnd
        //         Sever|AuraKaliye70:1A|Battle|NewTurn
        //------------------------------指令格式-------------------------//
        ```

        

* Tool层

    * 适应Qt的预编译反射机制的实现

        使用预编译和工厂类实现的反射能够实现程序运行时根据外部数据文本创建同名的类，并通过插件方式进行类的扩展，避免了拓展时对原有程序的改动，但这种实现的关键为在预编译时对注册类的静态化和通过该展开的注册类在工厂中进行进行类的注册。

        在Qt中，有时基于实际需求，需要从QWidget或QLabel等组件中扩展一个基类作为项目的功能接口，但通过“预编译和工厂类实现的反射”在实践时会遇到“QWidget”不能在“QApplication”之前创建的致命错误，目前网络上的建议是不使用static的QWidget，但在“预编译和工厂类实现的反射”方法中又必须对基类的注册类进行静态化，此外，通过宏展开的生成函数在传递参数时只能传入类的同名文本，并不支持带参数的构造函数的创建，但QObject类族中又有一个十分重要的概念：parent。故而，在经过多次尝试后，得到如下解决方案：

        ①使用模板template解决静态问题，通过函数包装器std::fuction解决带参传递问题。

        ②在工厂类中进行模板定义，在注册类中仅宏定义出注册函数的调用即可。

        代码示例：

        ```c++
        //工厂类：
        class WidgetFactory
        {
        public:
            static WidgetFactory* GetInstance();
            void RegisterWidget(const QString &widgetName,UIWidget* widgetClass);
            void RegisterWidget(const QString &widgetName,std::function<UIWidget*(QWidget*)> widgetClass);
            //UIWidget* CreateWidget(const QString &widgetName);
            UIWidget* CreateWidget(const QString &widgetName,QWidget* parent=nullptr);
        private:
            static WidgetFactory* m_instance;
            WidgetFactory();
        
            QMap<QString,UIWidget*>m_nameToWidgetDictionary;
        
            QMap<QString,std::function<UIWidget*(QWidget*)> >m_WidgetCreator;
        };
        
        template <typename T>
        std::function<UIWidget*(QWidget*)> createWidgetCreator()
        {
            return [](QWidget* parent) ->UIWidget*
            {
                return new T(parent);
            };
        }
        
        template <typename T>
        std::function<UIWidget*(QWidget*)> createWidgetCreatorSingle()
        {
            return [](QWidget* parent) ->UIWidget*
            {
                return T::GetInstance();
            };
        }
        /*注：由于实际需要，派生出的UIWidget的子类拥有“可建立多个”（如人物信息栏）和“理论上只有一个”（如角色展示页面、卡牌展示页面、游戏大厅页面），故而设计两款模板*/
        
        
        //注册类
        class WidgetRegister
        {
        public:
            WidgetRegister();
            WidgetRegister(const QString & widgetName,UIWidget* widgetClass);
            WidgetRegister(const QString &widgetName,std::function<UIWidget*(QWidget*)> widgetClass);
        };
        
        
        //#define REGISTER_WIDGET(widgetName)\
        //static UIWidget* CreateWidget##widgetName() \
        //{\
        //    UIWidget* obj;\
        //     obj=new widgetName();\
        //return obj;\
        //}\
        //static WidgetRegister WidgetRegister##widgetName(#widgetName,CreateWidget##widgetName());
        
        //#define REGISTER_WIDGET_SINGLE(widgetName)\
        //static UIWidget* CreateWidget##widgetName() \
        //{\
        //        UIWidget* obj;\
        //    obj=(UIWidget*)widgetName::GetInstance();\
        //    return obj;\
        //}\
        //    static WidgetRegister WidgetRegister##widgetName(#widgetName,CreateWidget##widgetName());
        
        /*这里展示原宏定义作为对比*/
        
        #define REGISTER_WIDGET(widgetName) static WidgetRegister widgetRegister_##widgetName(#widgetName,createWidgetCreator< widgetName > () );
        #define REGISTER_WIDGET_SINGLE(widgetName) static WidgetRegister widgetRegister_##widgetName(#widgetName,createWidgetCreatorSingle< widgetName > () );
        
        
        /*在相应的子类中，只需添加宏即可*/
        
        //子类示例
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
        ```

        

    * 递归式数据读取和数据结构设计	

        * 这部分技巧极大简化了程序的配置文件的规模设计，同时提高了数据设计的有序性和逻辑性。

            相关数据：

            ```c++
            "UIActiveWidget": [
                {
                  "ClassName": "UserInfoWidget",
                  "Category": "CW",
                  "Setting": {
                    "Rect": [600, 150, 450, 600],
                     "Style":"background-color:rgba(180,180,180,220);border-radius:10px;",
                    "BackgroundPixUrl":"./RESOURCE/Image_90032.png",
                    "Title": "用户信息栏"
                  },
                  "Contains": [
                    {
                      "ClassName": "HeadWidget",
                      "Category": "OW",
                      "Setting": {
                      "Rect": [0, 50, 450, 150],
                      "Style":"color:rgb(0,0,0);font-family:楷体;font-size:25px;",
                      "BackgroundPixUrl":"./RESOURCE/Image_90024.png",
                      "Mask":"./RESOURCE/Image_90027.png",
                      "LabelPixUrl":"./RESOURCE/Image_90025.png",
                      "Init": true
                      }
                    },
                    {
                      "ClassName": "ModifyWidget",
                      "Category": "OW",
                      "Setting": {
                        "Rect": [0, 200, 450, 150],
                      "Style":"color:white;font-family:楷体;font-size:25px;",
                        "EditBoxGroup": [
                          {
                            "LinkAttribute": "UserName",
                            "Tip": "UserName"
                          }
                        ]
                      }
                    },
                    {
                      "ClassName": "ToolWidget",
                      "Category": "OW",
                      "Setting": {
                        "Rect": [0, 0, 450, 50],
                      "Style":"background-color:rgb(250,250,250);border-radius:10px;",
                     "BackgroundPixUrl":"./RESOURCE/Image_90035.png",
                        "Init": true
                      }
                    }
                  ]
                },
                {
                  "ClassName": "CharacterWidget",
                  "Category": "CW",
                  "Setting": {
                    "Rect": [600, 400, 1300, 700],
                    "Style": "",
                    "BackgroundPixUrl":"./RESOURCE/Image_90034.png",
                    "Title": "角色信息栏"
                  },
                  "Contains": [
                    {
                      "ClassName": "ToolWidget",
                      "Category": "OW",
                      "Setting": {
                        "Rect": [0, 0, 1300, 50],
                     "Style":"background-color:rgb(250,250,250);border-radius:10px;",
                     "BackgroundPixUrl":"./RESOURCE/Image_90035.png",
                        "Init": true
                      }
                    },
                    {
                      "ClassName": "ViewPortWidget",
                      "Category": "OW",
                      "Setting": {
                        "Rect": [50, 50, 1200, 650],
                        "Restriction": 1200,
                        "Init": true,
                      "Style":"background-color:rgba(0,0,0,0.1);color:rgb(255,255,255);border-radius:5px;font-family:楷体;",
                        "CharacterBoxGroup": {
                          "ChoicedStyle": "",
                          "NormalStyle": "",
                          "NormalSize": [300, 650]
                        }
                      }
                    }
                  ]
                },
                {
                  "ClassName": "CardWidget",
                  "Category": "CW",
                  "Setting": {
                    "Rect": [600, 400, 1200, 750],
                    "BackgroundPixUrl":"./RESOURCE/Image_90033.png",
                    "Style": "color:rgb(255,255,255);border-radius:5px;font-family:楷体;font-size:25px;",
                    "Title": "卡牌信息栏"
                  },
                  "Contains": [
                    {
                      "ClassName": "ToolWidget",
                      "Category": "OW",
                      "Setting": {
                        "Rect": [480, 0, 720, 50],
                     "Style":"background-color:rgb(250,250,250);border-radius:10px;",
                     "BackgroundPixUrl":"./RESOURCE/Image_90035.png",
                        "Init": true
                      }
                    },
                    {
                      "ClassName": "CardInfoWidget",
                      "Category": "OW",
                      "Setting": {
                        "Rect": [0, 0, 480, 700],
                    "Style":"background-color:rgba(220,220,220,0.1);",
                        "Init": true
                      }
                    },
                    {
                      "ClassName": "CardHubWidget",
                      "Category": "OW",
                      "Setting": {
                        "Rect": [480, 50, 720, 700],
                        "Init": true,
                        "CardBoxGroup": {
                          "NormalSize": [170, 338]
                        }
                      }
                    }
                  ]
                },
                  {
                     "ClassName": "CardDeckWidget",
                     "Category": "CW",
                     "Setting": {
                     "Rect": [600, 400, 1200, 750],
                     "Style": "",
                     "Title": "卡组界面"
                  },
                  "Contains": [
                      {
                        "ClassName": "ToolWidget",
                         "Category": "OW",
                         "Setting": {
                         "Rect": [0, 0, 1200, 50],
                        "Style":"color:rgb(180,180,180);",
                         "Init": true
                              }
                    },
                      {
                         "ClassName": "CardDeckShowWidget",
                         "Category": "OW",
                          "Setting":{
                              "Rect":[0,50,1200,700],
                              "Style":"",
                              "Init":true
                          }
                      }
                      ]
                  }
              ]
            ```

            由于是第一次实践这个想法，该设计还有一些不完善的地方，但整体思路挺清晰。

            ①读取ClassName，通过工厂进行同名类的创建，并根据其所在位置为该类设置parent。

            ②读取Category进行ObjectWidget和CompleteWidget的选择，将其分流至不同的读取函数中进行处理。

            ③读取一般属性配置并进行相应处理（如Rect、Style、BackgroundPixUrl等）。

            ④若该类的Contains中还有子类，说明在该窗体中还存在自定义的子控件，则进行下一轮读取。

            

    * 工厂模式和单例模式

        对于需要批量产生的相似类，可通过工厂进行模块定义和生成；对于理论上在整个程序生命周期中只存在一个的类，通常写为单例模式。
        代码示例：

        ```c++
        // .h文件
        #ifndef LABELFACTORY_H
        #define LABELFACTORY_H
        
        #include <QString>
        #include <QMap>
        #include "../../UI/clicklabel.h"
        
        class LabelFactory
        {
        public:
            static LabelFactory* GetInstance();
            void RegisterLabel(const QString &labelName,ClickLabel*labelClass);
            void RegisterLabel(const QString &labelName,std::function<ClickLabel*(QWidget*)> labelClass);
            //ClickLabel * CreateLabel(const QString &labelName);
            ClickLabel * CreateLabel(const QString &labelName,QWidget* parent=nullptr);
        
        private:
            static LabelFactory* m_instance;
            LabelFactory();
        
            QMap<QString,ClickLabel*>m_nameToLabelDictionary;
        
        
            QMap<QString,std::function<ClickLabel*(QWidget*)> > m_LabelCreator;
        
        };
        
        template <typename T>
        std::function<ClickLabel*(QWidget*)> createLabelCreator()
        {
            return [](QWidget* parent) ->ClickLabel*
            {
                return new T(parent);
            };
        }
        
        
        #endif // LABELFACTORY_H
        
        
        
        //.cpp文件
        #include "labelfactory.h"
        
        LabelFactory* LabelFactory::m_instance=nullptr;
        LabelFactory *LabelFactory::GetInstance()
        {
            if(m_instance==nullptr)
            {
                m_instance=new LabelFactory();
            }
            return m_instance;
        }
        
        void LabelFactory::RegisterLabel(const QString &labelName, ClickLabel *labelClass)
        {
            m_nameToLabelDictionary[labelName]=labelClass;
        }
        
        void LabelFactory::RegisterLabel(const QString &labelName, std::function<ClickLabel *(QWidget *)> labelClass)
        {
            m_LabelCreator.insert(labelName,labelClass);
        }
        
        //ClickLabel *LabelFactory::CreateLabel(const QString &labelName)
        //{
        //    auto it =m_nameToLabelDictionary.find(labelName);
        //    if(it!=m_nameToLabelDictionary.end())
        //    {
        //        return it.value();
        //    }
        //    else
        //    {
        //        return nullptr;
        //    }
        //}
        
        ClickLabel *LabelFactory::CreateLabel(const QString &labelName, QWidget *parent)
        {
            auto it =m_LabelCreator.find(labelName);
            if(it!=m_LabelCreator.end())
            {
                return it.value()(parent);
            }
            else
            {
                return nullptr;
            }
        }
        
        LabelFactory::LabelFactory()
        {
        
        }
        
        ```

        

* UI层

  * 实现自定义窗体的标题栏	
  
      标题栏需要装载在窗体中，可让父窗体在无边框状态下具有一个自定义的可拖拽的区域。
  
      实现思路为利用三个mouseEvent完成鼠标状态检测和转换、鼠标追踪和对父窗体的位置的移动。
  
      相关代码：
  
      ```c++
      
      void ToolWidget::mouseReleaseEvent(QMouseEvent *e)
      {
      
          m_isPressed=false;
      }
      
      void ToolWidget::mousePressEvent(QMouseEvent *e)
      {
      
          if(e->button()==Qt::LeftButton)
          {
              m_isPressed=true;
              m_starPoint=e->globalPosition();
              if(this->parent()!=nullptr)
              {
                  m_distancePoint=this->parentWidget()->pos()-m_starPoint;
              }
          }
      }
      
      void ToolWidget::mouseMoveEvent(QMouseEvent *e)
      {
      
          if(m_isPressed)
          {
              m_starPoint=e->globalPosition();
              if(this->parent()!=nullptr)
              {
                  this->parentWidget()->move(m_starPoint.x()+m_distancePoint.x(),m_starPoint.y()+m_distancePoint.y());
              }
          }
      }
      
      //注：在此区域中可自定义添加控件实现关闭、最小化等功能
      ```
  
      
  
  * 实现基于拖拽和滚轮的类似Scroll Area窗体	
  
      这部分是因为在项目构建过程中需要用到固定视口的可滑动窗体，但QScrollArea类与UIWidget的关系属于同父类的不同子分支，所以需要在基于UIWidget的基础上进行仿QScrollArea类的设计。
  
      实现思路为通过鼠标事件进行状态转化、鼠标追踪和内置子窗体的移动，或通过滚轮事件将滚轮角度转化为内置子窗体的移动距离。
  
      示例代码：
  
      ```c++
      //滚轮
      void CardHubWidget::wheelEvent(QWheelEvent *e)
      {
          //竖着
          int delta=e->angleDelta().y();
          m_viewWidget->move(m_viewWidget->x(),m_viewWidget->y()+delta);
          RedoMove();
      }
      void CardHubWidget::RedoMove()
      {
          int nowY=m_viewWidget->y();
          int heightLimit=this->height();
          if(nowY+m_viewWidget->height()<heightLimit)
          {
              m_viewWidget->move(m_viewWidget->x(),heightLimit-m_viewWidget->height());
          }
          else if(nowY>0)
          {
              m_viewWidget->move(m_viewWidget->x(),0);
          }
      }
      
      
      
      //拖拽
      
      void ViewPortWidget::mouseReleaseEvent(QMouseEvent *e)
      {
          m_mousePressed=false;
          RedoMove();
      }
      
      void ViewPortWidget::mousePressEvent(QMouseEvent *e)
      {
      
          if(e->button()==Qt::LeftButton)
          {
              m_mousePressed=true;
              QPointF startPoint=e->globalPosition();
              m_widthDistance=startPoint.x()-this->x();
      
          }
      
      }
      
      void ViewPortWidget::mouseMoveEvent(QMouseEvent *e)
      {
          //拖拽
          if(m_mousePressed)
          {
              QPoint desPoint(e->globalPosition().x()-m_widthDistance,this->y());
              move(desPoint);
          }
          //随鼠标移动
          if(m_heightGap!=0)
          {
              double centreY=this->height()/2+this->pos().y();
              double  yMoveFactor=((centreY-e->globalPosition().y())/(m_heightRestriction/2.0))+1.0;
              if(yMoveFactor>2.0)
              {
                  yMoveFactor=2.0;
              }
              else if(yMoveFactor<0)
              {
                  yMoveFactor=0;
              }
              for(auto it:m_characterShowWidgetList)
              {
                  it->move(it->x(),((this->height()-it->height())/2)*(2-yMoveFactor));
              }
          }
      }
      void ViewPortWidget::RedoMove()
      {
          int nowX=this->x();
          int nowWidth=this->width();
          int leftLimit=this->parentWidget()->width();
          if((nowX+nowWidth)<leftLimit)
          {
              move(leftLimit-nowWidth,this->y());
          }else if(nowX>0)
          {
              move(0,this->y());
          }
      }
      
      
      ```
  
  * 实现基于信号的多层窗体数据连通	
  
      这部分比较简单，我常使用的有两种模式：一个是通过父窗体进行子窗体的构建，在父窗体内进行子窗体的connect，这部分用于父窗体接收子窗体的信号；一个是通过子窗体的parent获取父窗体的指针，用于子窗体订阅父窗体的信号。
  
      （其实有点像双向链表的原理，也有点像观察者模式，也有点像TCP和UDP的原理）
  
  * 实现窗体平滑展开与收回
  
      * 这部分也比较简单，从我学会开始几乎每个项目都想玩一下。
  
          实现原理为监测一个状态来确定触发展开或收回动作，通过QPropertyAnimation的相关组件实现平滑动画。
  
          该项目中的示例代码：
  
          ```c++
          void CharacterShowWidget::InitWidget()
          {
              m_nowState=false;
          
              m_tachieLabel->setGeometry(0,0,m_normalSize.width(),m_normalSize.height());
              m_infoWidget->setGeometry(0,0,m_normalSize.width(),m_normalSize.height());
              m_tachieLabel->raise();
              if(m_linkCharacter!=nullptr)
              {
                  m_tachieLabel->SetImage(m_linkCharacter->GetTachieUrl());
                  m_infoWidget->SetCharacterName(m_linkCharacter->GetName());
                  m_infoWidget->SetCharacterTitle(m_linkCharacter->GetTitle());
                  m_infoWidget->SetCharacterIntroduction(m_linkCharacter->GetIntroduction());
          
                  //ATK
                  AttributeShowWidget* atkWidget=new AttributeShowWidget(m_infoWidget);
                  atkWidget->SetTitle("ATK");
                  atkWidget->SetValue(m_linkCharacter->GetATK());
                  m_infoWidget->AddWidget(atkWidget);
                  //atkWidget->InitWidget();   只能调用下一级的Init，不能越位初始化
                  //DEF
                  AttributeShowWidget* defWidget=new AttributeShowWidget(m_infoWidget);
                  defWidget->SetTitle("DEF");
                  defWidget->SetValue(m_linkCharacter->GetDEF());
                  m_infoWidget->AddWidget(defWidget);
                  //HP
                  AttributeShowWidget* hpWidget=new AttributeShowWidget(m_infoWidget);
                  hpWidget->SetTitle("HP");
                  hpWidget->SetValue(m_linkCharacter->GetHP());
                  m_infoWidget->AddWidget(hpWidget);
          
                  m_infoWidget->InitWidget();
              }
          
              connect(m_tachieLabel,&ClickLabel::clicked,this,[=](){
                  if(m_nowState==false)
                  {
                      //resize(m_expandSize.width(),m_expandSize.height());
          
          
          
                      QPropertyAnimation *animation =new QPropertyAnimation(this,"geometry");
                      animation->setDuration(200);
                      connect(animation,&QPropertyAnimation::finished,[this](){
                          m_nowState=true;
                          emit UIWidget::CharacterChoiced(m_linkCharacter);
                      });
                      connect(animation,&QPropertyAnimation::valueChanged,[this](){
                          m_infoWidget->move(this->width()-m_infoWidget->width(),m_infoWidget->y());
                          //qDebug()<<"foriiii3";
                          emit UIWidget::RectChanged();
                      });
                      animation->setStartValue(this->geometry());
                      QRect desRect(this->geometry().x(),this->geometry().y(),m_expandSize.width(),m_expandSize.height());
                      animation->setEndValue(desRect);
                      animation->start(QAbstractAnimation::DeleteWhenStopped);
          
                  }else
                  {
          
                      QPropertyAnimation *animation =new QPropertyAnimation(this,"geometry");
                      animation->setDuration(200);
                      connect(animation,&QPropertyAnimation::finished,[this](){
                          m_nowState=false;
          
                      });
                      connect(animation,&QPropertyAnimation::valueChanged,[this](){
                          m_infoWidget->move(this->width()-m_infoWidget->width(),m_infoWidget->y());
                          //qDebug()<<"foriiii";
                          emit UIWidget::RectChanged();
                      });
                      animation->setStartValue(this->geometry());
                      QRect desRect(this->geometry().x(),this->geometry().y(),m_normalSize.width(),m_normalSize.height());
                      animation->setEndValue(desRect);
                      animation->start(QAbstractAnimation::DeleteWhenStopped);
                  }
              });
          
              //--//
              CheckPrinter::GetInstance()->AddCheckWidget(this);
              //--//
          }
          ```
  
  * 实现手牌的堆叠和展开
  
      这部分是突发奇想的尝试，在学习了QGraphics相关组件后获得了成功。
  
      手卡的堆叠是一般情况下的对控件的位置的调整，更花里胡哨的在《Luck No Complete》中剧情卡片的轮播图中有尝试；关于手卡的展开是通过QGraphicsProxyWidget将控件以代理窗体的形式放置在Scene中，再将View进行旋转和平移以实现手卡展开的效果。
  
      相关代码：
  
      ```c++
      //.h 文件
      
      #ifndef HANDCARDWIDGET_H
      #define HANDCARDWIDGET_H
      
      #include <QWidget>
      #include <QRect>
      #include <QVector>
      
      #include "../cardlabel.h"
      #include <QPushButton>
      
      #include <QGraphicsScene>
      #include <QGraphicsView>
      #include <QGraphicsProxyWidget>
      #include <QPalette>
      class handCardWidget : public QWidget
      {
          Q_OBJECT
      public:
          explicit handCardWidget(QWidget *parent = nullptr);
          void SetSmallState();
          void SetLargeState();
          void ResetHandCard();
          void SortHandCard();
          void UpdateHandCard(QVector<Card*> handCard);
          void mouseReleaseEvent(QMouseEvent*e)override;
          void UpdateNowCard(Card* card);
      private:
          bool m_choiced;
          Card* m_nowCard;
          QRect m_smallState;
          QRect m_largeState;
          QSize m_smallCardSize;
          QSize m_largeCardSize;
          QVector<CardLabel*> m_handCard;
      
          QVector<QGraphicsScene*> m_sceneGroup;
          QVector<QGraphicsView*> m_viewGroup;
          QVector<QGraphicsProxyWidget*> m_proxyGroup;
      
          QGraphicsScene* m_scene;
          QGraphicsView* m_view;
      
          QLabel* infoLabel;
          QPushButton* m_yesButton;
          QPushButton* m_noButton;
      
      
      signals:
          void cardUsed(Card*);
      };
      
      #endif // HANDCARDWIDGET_H
      
      
      
      // .cpp文件
      #include "handcardwidget.h"
      
      handCardWidget::handCardWidget(QWidget *parent)
          : QWidget{parent}
      {
          QPalette palette(this->palette());
          palette.setColor(QPalette::Window, Qt::white);
          this->setAutoFillBackground(true);
          this->setPalette(palette);
          setWindowFlags(Qt::FramelessWindowHint);
          setStyleSheet("background:white;");
      
          m_choiced=true;
          m_smallState=QRect(450,575,800,325);
          m_largeState=QRect(200,100,1200,700);
          m_smallCardSize=QSize(170,300);
          m_largeCardSize=QSize(170,300);
      
          infoLabel=new QLabel(this);
          infoLabel->setGeometry(450,500,300,100);
      
          m_yesButton=new QPushButton("使用",this);
          m_yesButton->setGeometry(500,625,75,50);
          m_noButton=new QPushButton("取消",this);
          m_noButton->setGeometry(625,625,75,50);
      
          connect(m_yesButton,&QPushButton::clicked,[=](){
              if(m_nowCard!=nullptr){
                  emit cardUsed(m_nowCard);
                  m_nowCard=nullptr;
                  infoLabel->setText("");
              }
          });
      
          connect(m_noButton,&QPushButton::clicked,[=](){
      
                  m_nowCard=nullptr;
                  infoLabel->setText("");
                  SetSmallState();
          });
      
          m_yesButton->setVisible(false);
          m_noButton->setVisible(false);
          SetSmallState();
      }
      
      void handCardWidget::SetSmallState()
      {
          if(m_choiced==false) return;
          m_choiced=false;
          setGeometry(m_smallState);
          m_yesButton->setVisible(false);
          m_noButton->setVisible(false);
          ResetHandCard();
      }
      
      void handCardWidget::SetLargeState()
      {
          if(m_choiced==true) return;
      
          m_choiced=true;
          setGeometry(m_largeState);
          m_yesButton->setVisible(true);
          m_noButton->setVisible(true);
          SortHandCard();
          
          update();
      }
      
      void handCardWidget::ResetHandCard()
      {
          //450,575,800,325   --170,300
      
          for(auto it:m_proxyGroup)
          {
              it->resetTransform();
              it->setWidget(this);
      
          }
          for(auto it:m_proxyGroup) m_proxyGroup.pop_front();
      
          for(auto it :m_sceneGroup) it->deleteLater();
          for(auto it:m_sceneGroup) m_sceneGroup.pop_front();
      
          for(auto it : m_viewGroup) it->deleteLater();
          for(auto it: m_viewGroup)  m_viewGroup.pop_front();
      
          for(int i=0;i<m_handCard.size();i++)
          {
      
              m_handCard[i]->setParent(this);
              m_handCard[i]->resize(m_smallCardSize);
              m_handCard[i]->move(100+50*i,10);
              m_handCard[i]->raise();
              m_handCard[i]->setVisible(true);
              
          }
      
      }
      
      void handCardWidget::SortHandCard()
      {
      
      
          m_scene=new QGraphicsScene(this);
          m_view= new QGraphicsView(m_scene,this);
      
          QPoint O(m_largeState.width()/2,m_largeState.height());
      
          int R=300;
      
          for(auto it:m_handCard)
          {
              it->move(0,0);
              it->resize(m_largeCardSize.width(),m_largeCardSize.height());
              it->setParent(nullptr);
          }
            //考虑做成一个动画
         
          for(int i=0;i<m_handCard.size();i++)
          {
      
            
              QGraphicsProxyWidget* tmpProxy=m_scene->addWidget(m_handCard[i]);
              QPointF tmpPoint(m_largeCardSize.width()/2,m_largeCardSize.height()+R);
      
      
              tmpProxy->setTransformOriginPoint(tmpPoint);
              if(m_handCard.size()>1)
              {
                  tmpProxy->setRotation(-75+((150*i)/(m_handCard.size()>0?m_handCard.size():1)));
                  m_handCard[i]->move(O.x()-m_largeCardSize.width()/2,O.y()-R-m_largeCardSize.height());
      
              }
              else
              {
                 tmpProxy->setRotation(0);
                 m_view->move(O.x()-m_largeCardSize.width()/2,O.y()-R-m_largeCardSize.height());
      
              }
      
      
              tmpProxy->setVisible(true);
              m_proxyGroup.append(tmpProxy);
              
          }
          
          m_view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
          m_view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
          m_view->setWindowOpacity(0);
          m_view->setStyleSheet("background:transparent;border:0px;");
          m_view->setWindowFlags(Qt::FramelessWindowHint);
          m_view->setVisible(true);
      
          m_sceneGroup.append(m_scene);
          m_viewGroup.append(m_view);
      }
      
      void handCardWidget::UpdateHandCard(QVector<Card *> handCard)
      {
          for(auto it:m_handCard)
          {
              it->deleteLater();
              m_handCard.pop_front();
          }
          m_handCard.clear();
      
          for(auto it:handCard)
          {
              CardLabel* tmp = new CardLabel(this);
              tmp->SetCard(it);
              tmp->resize(m_smallCardSize);
              tmp->SetImage(it->GetImageUrl());
              m_handCard.append(tmp);
              connect(tmp,&CardLabel::cardClicked,[=](Card* card){
                  UpdateNowCard(card);
              });
          }
          ResetHandCard();
      }
      
      
      void handCardWidget::mouseReleaseEvent(QMouseEvent *e)
      {
          if(e->button()==Qt::LeftButton)
          {
              if(m_choiced==false)
              {
                  SetLargeState();
              }
          }
      }
      
      void handCardWidget::UpdateNowCard(Card* card)
      {
          m_nowCard=card;
          QString str="[";
          str+=m_nowCard->GetName();
          str+="] ";
          str+=m_nowCard->GetCategory();
          str+=" ATK:";
          str+=QString::number(m_nowCard->GetATK());
          str+=" DEF:";
          str+=QString::number(m_nowCard->GetDEF());
          str+=" DHP:";
          str+=QString::number(m_nowCard->GetDHP());
          infoLabel->setText(str);
      
      }
      
      ```
  
      