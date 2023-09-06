# 《Mirror And Flowers》结构简析

## 客户端

* Data层

    Data层作为该项目的最底层，囊括项目所需的所有基础数据信息（类、属性、数据结构、设置和获取属性的方法、一些特殊的属性更改行为）。

    Data层仅包括作为开发工具的Qt的类库和Data层的其他必要的类（如因为CardDeck类因为逻辑需要，包含了Card类）。

    此外，该层的技术点（技巧）有：①基于Map的点对点数据对照	②基于split的指令格式设计和解析方式

    * card.h 

        * 功能：包含一个Card类，描述一个卡牌。包括ID、名字、卡牌类型、ATK、DEF、DHP、介绍、图片的地址。

        * 备注：ID为5位。

        * 结构：

            ```json
            {
                "ID":10101,
                "Name":"露易斯的水晶链",
                "Category":"Equipment",
                "ATK":200,
                "DEF":0,
                "DHP":400,
                "Introduction":"露易斯在寻找纯白之石时随身携带的水晶项链，见证了一切故事的开始。",
                "ImageUrl":""
            }
            ```

        ```c++
        [
            {
                "ID":10101,
                "Name":"露易斯的水晶链",
                "Category":"Equipment",
                "ATK":200,
                "DEF":0,
                "DHP":400,
                "Introduction":"露易斯在寻找纯白之石时随身携带的水晶项链，见证了一切故事的开始。",
                "ImageUrl":"./RESOURCE/Image_90012.png"
            },
            {
                "ID":10102,
                "Name":"烈火的朱凤",
                "Category":"Prop",
                "ATK":0,
                "DEF":0,
                "DHP":0,
                "Introduction":"Luwies的绰号，也是她最擅长的火焰技艺。能够在夜空中绘制出惊艳的火焰图案，令人赞叹不已。",
                "ImageUrl":"./RESOURCE/Image_90013.png"
            },
            {
                "ID":10103,
                "Name":"纯白之石",
                "Category":"Prop",
                "ATK":200,
                "DEF":200,
                "DHP":600,
                "Introduction":"Luwies寻找的神秘宝石，据说能净化一切污秽，治愈一切伤痛，揭示一切真相。",
                "ImageUrl":"./RESOURCE/Image_90014.png"
            },
            {
                "ID":10104,
                "Name":"祖丽安忒",
                "Category":"Equipment",
                "ATK":300,
                "DEF":0,
                "DHP":300,
                "Introduction":"Luwies从父亲那里继承的水晶镯子，上面刻着莎丹国的国徽和火焰图腾，拥有抵抗火焰和增加元素控制力的功效。",
                "ImageUrl":"./RESOURCE/Image_90015.png"
            },
            {
                "ID":10105,
                "Name":"热情绽放之花",
                "Category":"Prop",
                "ATK":100,
                "DEF":100,
                "DHP":100,
                "Introduction":"Luwies在旅途中收到的一束鲜花，花瓣呈现出火焰般的红橙色，散发出温暖的香气。",
                "ImageUrl":"./RESOURCE/Image_90016.png"
            },
            {
                "ID":10106,
                "Name":"冰霜之心",
                "Category":"Deprop",
                "ATK":-100,
                "DEF":-100,
                "DHP":-100,
                "Introduction":"Luwies在旅途中遇到的一个敌人留下的一颗水晶，里面封印着冰冷的力量。",
                "ImageUrl":"./RESOURCE/Image_90017.png"
            },
            {
                "ID":10107,
                "Name":"火焰之舞",
                "Category":"Prop",
                "ATK":200,
                "DEF":0,
                "DHP":200,
                "Introduction":"Luwies在旅途中学习到的一种火焰技艺，能够让火焰随着音乐和节奏舞动，形成美妙的视觉效果。",
                "ImageUrl":"./RESOURCE/Image_90018.png"
            }
        ]
        ```

    * Style.h

        ```json
        {
            "StyleName":"",
            "BaseStyle":{
                "TitleLabel":{
                    
                },
                "ShowLabel":{},
                "TipLabel":{},
                "Widget":{},
                
            },
            "Contains":
            {
                "headWidget":{
                    "BackgroundImageUrl":"./RESOURCE/Image_90024.png",
                    "OtherImageUrl":"",
                    "LabelImageUrl":"./RESOURCE/Image_90025.png"
                },
            }
        
        }
        ```
        
    * character.h

        * 功能：包含一个Character类，描述一个人物。包括ID、名字、人物立绘图的地址。

        * 备注：ID为3位。

        * 结构：

            ```json
            {
                "ID":101,
                "Name":"Luwies",
                "Title":"烈火的朱凤",
                "Introduction":"（测试）如火一般热情的少女。",
                "ATK":800,
                "DEF":800,
                "HP":2400,
                "TachieUrl":"./RESOURCE/Image_90008.png"
            }
            
            ```

        ```c++
        [
          {
            "ID": 101,
            "Name": "Luwies",
            "Title": "烈火的朱凤",
            "Introduction": "（测试）如火一般热情的少女。",
            "ATK": 800,
            "DEF": 800,
            "HP": 2400,
            "TachieUrl": "./RESOURCE/Image_90008.png"
          },
          {
            "ID": 102,
            "Name": "Aiden",
            "Title": "风暴的剑骑士",
            "Introduction": "（测试）感受风暴之力的勇敢剑士。",
            "ATK": 1000,
            "DEF": 1200,
            "HP": 2800,
            "TachieUrl": "./RESOURCE/Image_90009.png"
          },
          {
            "ID": 103,
            "Name": "Evelyn",
            "Title": "冰雪的魔法师",
            "Introduction": "（测试）掌握冰雪魔法的神秘魔法师。",
            "ATK": 1200,
            "DEF": 1000,
            "HP": 2700,
            "TachieUrl": "./RESOURCE/Image_90010.png"
          },
          {
            "ID": 104,
            "Name": "Lucius",
            "Title": "暗夜的刺客",
            "Introduction": "（测试）潜行于夜晚的致命刺客。",
            "ATK": 1500,
            "DEF": 800,
            "HP": 2500,
            "TachieUrl": "./RESOURCE/Image_90011.png"
          }
        ]
        ```

        

    * CardDeck.h

        * 功能：包含一个CardDeck类，描述卡组信息。包括ID、名字、卡组封面图地址、描述、卡组类型、卡牌序列。

        * 备注：ID为6位。

            ​			对战卡组需要系统卡组和自建卡组组合（每套15张，共计30张），系统卡组代表选取的人物，自建卡组代表战斗者的意志和改变角色命运的可能。
        
        * 结构：
        
            ```c++
            {
                "ID":101001,
                "Character":"Me",
                "Name":"测试的套卡1",
                "CoverUrl":"",
                "Introduction":"测试用的卡组",
                "Category":true,
                "CardIndex":[10101,10102,10103,10104,10105,10106,10107,10101,10102,10103,10104,10105,10106,10107]
            }
            ```
        
    * instructionContext.h

        * 功能：包含一个InstructionContext类，描述指令文本的内容。包括指令文本、指令名、指令发出者、指令接收者、指令类型、指令对象、指令值。

        * 示例：

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

    * machineInformation.h

        * 功能：包括一个MachineInformation类，描述本机的机器信息。包括机器名、机器Mac地址、目标服务器IP、目标服务器端口号。

    * player.h

        * 功能：包括一个Player类，描述玩家信息。包括HP最大值、当前HP、ATK、DEF、临时ATK、临时DEF、临时HP、装备ATK、装备DEF、装备HP、对手（指针）。

* PROTool层

    PROTool层作为项目的“工具层”，提供项目运行时所需的大部分逻辑和方法，在本项目中包括指令类集、一些工厂类、数据读取类、管理的类（管理卡牌、角色、卡组、战斗等）、连接类。

    PROTool仅向下包含Data层的相关类，并提供数据处理的方法和数据处理后的结果的获取接口。

    此外，该层的技术点有：①适应Qt的预编译反射机制的实现	②递归式数据读取和数据结构设计	③工厂模式和单例模式

    * Instruction集
        * 包括一个InstructionBase抽象基类和数个Instruction具体子类。
    * CardHub.h
        * 包括一个CardHub类，描述现有卡牌集。包括idToCard的字典、nameToCard的字典。
    * CharacterHub.h
        * 包括一个CharacterHub类，描述现有角色集。包括idToCharacter的字典、nameToCharacter的字典。
    * JsonReader.h
        * 包括一个JsonReader类，用于读取外部数据源，对程序进行初始化（数据、UI等），通过工厂类和反射机制进行外部数据的UI创建和数据导入、修正等功能。
    * LinkManager.h
        * 用于进行TCP连接的类，包括连接、断开、检查状态、数据传输、指令接收和传递等功能。
    * BattleManager.h
        * 用于进行战斗管理的类，包括获取战斗双方信息、执行战斗流程、战斗结果处理和传递等功能。
    * WidgetManager.h
        * 用于整体管理运行窗体的类，包括对UI中各数据显示的实时更新、状态循环检查等功能。
    * Factory和Register
        * 用于反射机制的实现和相关UI的创建。

* WORKTool层

    WORKTool层提供编码时的校验和检查功能，目前试验了一下实现的可能性和应用性。整体思路为通过调用该层的check类中的校验方法进行主动检测和向check类中添加监测类进行实时监测或条件触发。

    * checkPrinter.h
    * checkTool.h

* UI层

    UI层作为项目的最终表达，属于最顶层的结构，其尽可能只引入PROTool层的相关类进行设计，在此项目中，还额外引用了Data层的常数类（ConstNumber）进行设计规范。

    在本项目中，所有窗体的设计都拥有共同的基类：UIWidget，并通过反射机制和针对性的JSON数据结构设计实现了递归化读取、高度代码复用、高度可扩展性和可编辑式修正的目的。

    此外，该层的技术点整理如下：①实现自定义窗体的标题栏	②实现基于拖拽和滚轮的类似Scroll Area窗体	③实现基于信号的多层窗体数据连通	④实现窗体平滑展开与收回	⑤实现手牌的堆叠和展开

    

    

* UI结构：

    

    ```json
    {
      "UIFixedWidget": [
        {
          "ClassName": "MainWidget",
          "Category": "CW",
          "Setting": {
            "Rect": [0, 0, 1600, 900],
            "Style": "",
            "Title": "Mirror And Flowers",
            "BackgroundPixUrl":"./RESOURCE/Image_90028.png"
          },
          "Contains": [
            {
              "ClassName": "HeadWidget",
              "Category": "OW",
              "Setting": {
                "Rect": [0, 0, 450, 150],
                "Style":"color:rgb(0,0,0);font-family:楷体;font-size:25px;",
                "BackgroundPixUrl":"./RESOURCE/Image_90024.png",
                "LabelPixUrl":"./RESOURCE/Image_90025.png",
                "Mask":"./RESOURCE/Image_90027.png",
                "Init": true
              }
            },
            {
              "ClassName": "ClickLabel",
              "Category": "OW",
              "Setting": {
                "Rect": [500, 0, 400, 150],
                "Instruction": "",
                "Title": "匹配",
                "BackgroundPixUrl": ""
              }
            },
            {
              "ClassName": "OptionListWidget",
              "Category": "OW",
              "Setting": {
                "Rect": [1000, 20, 500, 100],
                "Init": true,
                "LabelGroup": [
                  {
                    "LabelClass": "OpenLabel",
                    "LabelLink": "UserInfoWidget",
                    "ImageUrl": "./RESOURCE/Image_90029.png"
                  },
                  {
                    "LabelClass": "OpenLabel",
                    "LabelLink": "CharacterWidget",
                    "ImageUrl": "./RESOURCE/Image_90030.png"
                  },
                  {
                    "LabelClass": "OpenLabel",
                    "LabelLink": "CardWidget",
                    "ImageUrl": "./RESOURCE/Image_90031.png"
                  }
                ]
              }
            }
          ]
        }
      ],
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
    }
    ```

* USER结构

    ```json
    {
        "UserName":"花海海",
        "HeadImageUrl":"./RESOURCE/Image_90006"        
    }
    ```

    