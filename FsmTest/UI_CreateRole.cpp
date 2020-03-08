#include "UI_CreateRole.h"
#include <iostream>

void UI_CreateRole::Enter()
{
	std::cout << " 进入角色创建界面" << std::endl;
}

void UI_CreateRole::Process()
{
	std::cout << " 角色创建逻辑处理中…… " << std::endl;
}

void UI_CreateRole::Leave()
{
	std::cout << " 离开角色创建界面 " << std::endl;
}

