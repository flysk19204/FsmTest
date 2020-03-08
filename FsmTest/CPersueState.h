#pragma once
#include "CStateBase.h"
class CPersueState :
	public CStateBase
{
protected:
	void Enter() override;

	void Process()override;

	void Leave() override;

};

class MonsterBase;
class CMonsterPersueState :
	public CPersueState
{
	MonsterBase* m_Owner;

public:

	CMonsterPersueState(MonsterBase* Owner);

protected:
	void Enter() override;

	void Process()override;

	void Leave() override;

	void Process(Target_Str& tarobjece)override;
};