#pragma once
#include <string>
#include "Data.h"
class Fsm_State_Machine;
class CMonsterAttackState;
class CMonsterIdleState;
class CMonsterPatrolState;
class CMonsterPersueState;

class MonsterBase
{
	Fsm_State_Machine* Fsm_State;

	friend class CMonsterIdleState;
	friend class CMonsterPatrolState;
	friend class CMonsterPersueState;
	friend class CMonsterAttackState;

private:
	std::string m_Name;

	CMonsterIdleState*		m_IdleState;
	CMonsterPatrolState*	m_PatrolState;
	CMonsterPersueState*	m_PersueStatee;
	CMonsterAttackState*	m_AttackState;

	void InitState();

public:
	MonsterBase(const std::string& name);

	virtual ~MonsterBase();

	void ChangTo(ECondition condition);

	void ChangTo(ECondition condition, Target_Str& targetObject );
};

