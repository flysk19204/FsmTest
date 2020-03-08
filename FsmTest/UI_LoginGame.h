#pragma once
#include "CStateBase.h"
class UI_LoginGame:
	public CStateBase
{
protected:
	void Enter() override;

	void Process()override;

	void Leave() override;
};

