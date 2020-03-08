#pragma once

#include <map>
#include <string>
#include "Data.h"

class CStateBase;

typedef std::map< ECondition, CStateBase*> MapCondition;

class CStateBase
{

protected:

	MapCondition m_ConMap;

public:
	CStateBase();

	const MapCondition& GetConMap() const;

	bool AddContition(ECondition con, CStateBase* targetState);

	void RemoveCondition(ECondition con);

	virtual void Enter() = 0;

	virtual void Process() = 0;

	virtual void Leave() = 0;

	virtual void Process(Target_Str& tarobjece)  {};
};



class Fsm_State_Machine_Single
{
	Fsm_State_Machine_Single();

	std::map< CStateBase*, MapCondition > m_StateMap;

	CStateBase* m_CurrentState;

public:
	static Fsm_State_Machine_Single* m_Instance;

	static Fsm_State_Machine_Single* GetInstance() {
		if (m_Instance == nullptr) {
			m_Instance = new Fsm_State_Machine_Single;
		}
		return m_Instance;
	}

	bool RegisterState(CStateBase* srcState, ECondition con, CStateBase* targetState);

	bool ChangeTo(ECondition con);

	void InitState(CStateBase* srcState);

};

#define MyFsm Fsm_State_Machine_Single::GetInstance()



class Fsm_State_Machine
{
	std::map< CStateBase*, MapCondition > m_StateMap;

	CStateBase* m_CurrentState;

public:
	Fsm_State_Machine();

	bool RegisterState(CStateBase* srcState, ECondition con, CStateBase* targetState);

	bool ChangeTo(ECondition con);

	bool ChangeTo(ECondition con, Target_Str& targetObject);

	void InitState(CStateBase* srcState);

};