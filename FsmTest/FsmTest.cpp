// FsmTest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "CAttackState.h"
#include "CIdleState.h"
#include "CPersueState.h"
#include "CPatrolState.h"
#include "MonsterBase.h"

#include "UI_LoginGame.h"
#include "UI_CreateRole.h"
#include "UI_SelectRole.h"
int main()
{
    std::cout << "Hello World!\n";
    std::cout << "========================单例状态机=============================\n";
    //怪物的空闲，追击，巡逻，攻击状态的状态切换
    /*CPatrolState PrtrolState;
    CIdleState IdleState;
    CPersueState PersueState;
    CAttackState AttackState;

    MyFsm->RegisterState(&IdleState, ET_IDLE, &PrtrolState);
    MyFsm->RegisterState(&IdleState, ET_PERSUE, &PersueState);
    MyFsm->RegisterState(&IdleState, ET_ATTACK, &AttackState);

    MyFsm->RegisterState(&PrtrolState, ET_IDLE, &IdleState);
    MyFsm->RegisterState(&PrtrolState, ET_PATROL, &PrtrolState);
    MyFsm->RegisterState(&PrtrolState, ET_ATTACK, &AttackState);

    MyFsm->RegisterState(&PersueState, ET_IDLE, &IdleState);
    MyFsm->RegisterState(&PersueState, ET_PATROL, &PrtrolState);
    MyFsm->RegisterState(&PersueState, ET_ATTACK, &AttackState);

    MyFsm->RegisterState(&AttackState, ET_IDLE, &IdleState);
    MyFsm->RegisterState(&AttackState, ET_PATROL, &PrtrolState);
    MyFsm->RegisterState(&AttackState, ET_PERSUE, &PersueState);

    MyFsm->InitState(&IdleState);
    MyFsm->ChangeTo(ET_PATROL);
    MyFsm->ChangeTo(ET_IDLE);
    MyFsm->ChangeTo(ET_PERSUE);
    MyFsm->ChangeTo(ET_ATTACK);
    MyFsm->ChangeTo(ET_IDLE);*/
   
    //登录游戏，创建角色，选择角色的状态切换
    UI_LoginGame m_UI_LoginGame;
    UI_CreateRole m_UI_CreateRole;
    UI_SelectRole m_UI_SelectRole;

    MyFsm->RegisterState(&m_UI_LoginGame, ET_GOTO_CREATROLE, &m_UI_CreateRole);
    MyFsm->RegisterState(&m_UI_LoginGame, ET_GOTO_SELECTROLE, &m_UI_SelectRole);
  
    MyFsm->RegisterState(&m_UI_CreateRole, ET_GOTO_LOGIN, &m_UI_LoginGame);
    MyFsm->RegisterState(&m_UI_CreateRole, ET_GOTO_SELECTROLE, &m_UI_SelectRole);
  
    MyFsm->RegisterState(&m_UI_SelectRole, ET_GOTO_LOGIN, &m_UI_LoginGame);
    MyFsm->RegisterState(&m_UI_SelectRole, ET_GOTO_CREATROLE, &m_UI_CreateRole);
   

    MyFsm->InitState(&m_UI_LoginGame);
    MyFsm->ChangeTo(ET_GOTO_CREATROLE);
    MyFsm->ChangeTo(ET_GOTO_LOGIN);
    MyFsm->ChangeTo(ET_GOTO_SELECTROLE);
    MyFsm->ChangeTo(ET_GOTO_LOGIN);

    std::cout << "========================对象状态机=============================\n";
    size_t maxMonsterNum = 10;
    MonsterBase* MosterA[10];
    char buff[8]; 
    std::string name;
    std::string PlayerName = "飞龙在天";

    for (size_t i = 0; i < maxMonsterNum; i++)
    {
        memset(buff, 0, sizeof(char) * 8);
        _itoa_s(i, buff, 10);
        name = "小喽啰";
        name += buff;
        MosterA[i] = new MonsterBase(name);


        MosterA[i]->ChangTo(ConditionType(std::rand() % ET_ATTACK + ET_PATROL), PlayerName);

        std::cout << "\n";
    }

    //MonsterBase MosterA("小喽啰" + atoi(i));
    //MosterA.ChangTo(ET_PATROL);
    //MosterA.ChangTo(ET_IDLE);
    //MosterA.ChangTo(ET_PERSUE);
    //MosterA.ChangTo(ET_ATTACK);
    //MosterA.ChangTo(ET_IDLE);
    //MonsterBase MosterA("小喽啰");

    for (size_t i = 0; i < maxMonsterNum; i++)
    {
        SAFE_DELETE(MosterA[i]);
    }
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
