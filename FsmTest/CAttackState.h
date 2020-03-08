#pragma once
#include "CStateBase.h"
#include "Data.h"

class CAttackState :
	public CStateBase
{
protected:
	void Enter() override;

	void Process()override;

	void Leave() override;

};

class MonsterBase;
class CMonsterAttackState :
	public CAttackState
{
	MonsterBase* m_Owner;

public:

	CMonsterAttackState(MonsterBase* Owner);

protected:
	void Enter() override;

	void Process()override;

	void Leave() override;

	void Process(Target_Str& tarobjece)override;
};

