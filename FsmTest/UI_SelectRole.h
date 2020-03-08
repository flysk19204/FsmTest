#pragma once
#include "CStateBase.h"
class UI_SelectRole:
	public CStateBase
{
protected:
	void Enter() override;

	void Process()override;

	void Leave() override;
};

