#pragma once
#include "CStateBase.h"
class CPatrolState :
	public CStateBase
{
protected:
	void Enter() override;

	void Process()override;

	void Leave() override;

};


class MonsterBase;
class CMonsterPatrolState :
	public CPatrolState
{
	MonsterBase* m_Owner;

public:

	CMonsterPatrolState(MonsterBase* Owner);

protected:
	void Enter() override;

	void Process()override;

	void Leave() override;
};