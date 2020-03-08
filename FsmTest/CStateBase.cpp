#include "CStateBase.h"
#include <iostream>

CStateBase::CStateBase()
{
}

const MapCondition& CStateBase::GetConMap() const
{
	return m_ConMap;
}

bool CStateBase::AddContition(ECondition con, CStateBase* targetState)
{
	if (!targetState) {
		return false;
	}

	MapCondition::iterator conIter = m_ConMap.find(con);
	if (conIter != m_ConMap.end()) {
		std::cout << "已经添加过转换该条件了" << std::endl;
		return false;
	}

	m_ConMap[con] = targetState;
	
	return true;
}

void CStateBase::RemoveCondition(ECondition con)
{
	MapCondition::iterator conIter = m_ConMap.find(con);
	if (conIter != m_ConMap.end()) {
		m_ConMap.erase(con);
	}
}


Fsm_State_Machine_Single* Fsm_State_Machine_Single::m_Instance = nullptr;
Fsm_State_Machine_Single::Fsm_State_Machine_Single()
{
	m_CurrentState = NULL;
}

bool Fsm_State_Machine_Single::RegisterState(CStateBase* srcState, ECondition con, CStateBase* targetState)
{
	if (srcState == NULL || targetState == NULL) {
		return false;
	}

	srcState->AddContition(con, targetState);
	
	auto Stateiter = m_StateMap.find(srcState);
	if (Stateiter == m_StateMap.end()) {

		m_StateMap[srcState] = srcState->GetConMap();

	}
	return true;
}

void Fsm_State_Machine_Single::InitState(CStateBase* targetState)
{
	if (  m_CurrentState != targetState) {

		m_CurrentState = targetState;

		m_CurrentState->Enter();

		m_CurrentState->Process();
	}
}

bool Fsm_State_Machine_Single::ChangeTo(ECondition con)
{
	if (!m_CurrentState) {
		
		return false;
	}

	const MapCondition& ConMap = m_CurrentState->GetConMap();
	auto conIter = ConMap.find(con);
	if (conIter != ConMap.end()) {

		CStateBase* targetState = conIter->second;
		if (!targetState) {
			return false;
		}

		m_CurrentState->Leave();

		targetState->Enter();

		targetState->Process();

		m_CurrentState = targetState;
	}
	return true;
}



Fsm_State_Machine::Fsm_State_Machine()
{
}

bool Fsm_State_Machine::RegisterState(CStateBase* srcState, ECondition con, CStateBase* targetState)
{
	if (srcState == NULL || targetState == NULL) {
		return false;
	}

	srcState->AddContition(con, targetState);

	auto Stateiter = m_StateMap.find(srcState);
	if (Stateiter == m_StateMap.end()) {

		m_StateMap[srcState] = srcState->GetConMap();

	}
	return true;
}

bool Fsm_State_Machine::ChangeTo(ECondition con)
{
	if (!m_CurrentState) {

		return false;
	}

	const MapCondition& ConMap = m_CurrentState->GetConMap();
	auto conIter = ConMap.find(con);
	if (conIter != ConMap.end()) {

		CStateBase* targetState = conIter->second;
		if (!targetState) {
			return false;
		}

		m_CurrentState->Leave();

		targetState->Enter();

		targetState->Process();

		m_CurrentState = targetState;
	}
	return true;
}

bool Fsm_State_Machine::ChangeTo(ECondition con, Target_Str& targetObject)
{
	if (!m_CurrentState) {

		return false;
	}

	const MapCondition& ConMap = m_CurrentState->GetConMap();
	auto conIter = ConMap.find(con);
	if (conIter != ConMap.end()) {

		CStateBase* targetState = conIter->second;
		if (!targetState) {
			return false;
		}

		m_CurrentState->Leave();

		targetState->Enter();

		targetState->Process(targetObject);

		m_CurrentState = targetState;
	}
	return true;
}

void Fsm_State_Machine::InitState(CStateBase* targetState)
{
	if (m_CurrentState != targetState) {

		m_CurrentState = targetState;

		m_CurrentState->Enter();

		m_CurrentState->Process();
	}
}
