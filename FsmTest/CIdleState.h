#pragma once
#include "CStateBase.h"
class CIdleState :
	public CStateBase
{

protected:
	void Enter() override;

	void Process()override;

	void Leave() override;

};


class MonsterBase;
class CMonsterIdleState :
	public CIdleState
{
	MonsterBase* m_Owner;

public:

	CMonsterIdleState(MonsterBase* Owner);

protected:
	void Enter() override;

	void Process()override;

	void Leave() override;
};