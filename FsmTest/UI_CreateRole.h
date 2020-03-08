#pragma once
#include "Data.h"
#include "CStateBase.h"


class UI_CreateRole:
	public CStateBase
{
protected:
	void Enter() override;

	void Process()override;

	void Leave() override;
};

