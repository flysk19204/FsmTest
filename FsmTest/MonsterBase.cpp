#include "MonsterBase.h"
#include "CStateBase.h"
#include "CIdleState.h"
#include "CPatrolState.h"
#include "CPersueState.h"
#include "CAttackState.h"



MonsterBase::MonsterBase(const std::string& name)
{
	m_Name = name;
	
	Fsm_State = new Fsm_State_Machine();
	m_IdleState = new CMonsterIdleState(this);
	m_PatrolState = new CMonsterPatrolState(this);
	m_PersueStatee = new CMonsterPersueState(this);
	m_AttackState = new CMonsterAttackState(this);

	InitState();
}

MonsterBase::~MonsterBase()
{
	SAFE_DELETE(Fsm_State);
	SAFE_DELETE(m_IdleState);
	SAFE_DELETE(m_PatrolState);
	SAFE_DELETE(m_PersueStatee);
	SAFE_DELETE(m_AttackState);
}

void MonsterBase::ChangTo(ECondition condition)
{
	Fsm_State->ChangeTo(condition);
}

void MonsterBase::ChangTo(ECondition condition, Target_Str& targetObject)
{
	Fsm_State->ChangeTo(condition, targetObject);
}

void MonsterBase::InitState()
{
	Fsm_State->RegisterState(m_IdleState, ET_PATROL, m_PatrolState);
	Fsm_State->RegisterState(m_IdleState, ET_PERSUE, m_PersueStatee);
	Fsm_State->RegisterState(m_IdleState, ET_ATTACK, m_AttackState);

	Fsm_State->RegisterState(m_PatrolState, ET_IDLE, m_IdleState);
	Fsm_State->RegisterState(m_PatrolState, ET_PATROL, m_PatrolState);
	Fsm_State->RegisterState(m_PatrolState, ET_ATTACK, m_AttackState);

	Fsm_State->RegisterState(m_PersueStatee, ET_IDLE, m_IdleState);
	Fsm_State->RegisterState(m_PersueStatee, ET_PATROL, m_PatrolState);
	Fsm_State->RegisterState(m_PersueStatee, ET_ATTACK, m_AttackState);

	Fsm_State->RegisterState(m_AttackState, ET_IDLE, m_IdleState);
	Fsm_State->RegisterState(m_AttackState, ET_PATROL, m_PatrolState);
	Fsm_State->RegisterState(m_AttackState, ET_PERSUE,m_PersueStatee);

	Fsm_State->InitState(m_IdleState);
	
}