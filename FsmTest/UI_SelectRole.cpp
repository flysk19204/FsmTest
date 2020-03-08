#include "UI_SelectRole.h"
#include <iostream>

void UI_SelectRole::Enter()
{
	std::cout << " 进入选择角色界面" << std::endl;
}

void UI_SelectRole::Process()
{
	std::cout << " 选择角色逻辑处理中…… " << std::endl;
}

void UI_SelectRole::Leave()
{
	std::cout << " 离开角色选择界面 " << std::endl;
}

