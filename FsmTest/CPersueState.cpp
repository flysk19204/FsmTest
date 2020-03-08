#include "CPersueState.h"
#include <iostream>
#include "MonsterBase.h"

void CPersueState::Enter()
{
	std::cout << " ����׷��״̬ " << std::endl;
}

void CPersueState::Process()
{
	std::cout << " ׷��״̬�߼������С��� " << std::endl;
}

void CPersueState::Leave()
{
	std::cout << " ׷��״̬�뿪�� " << std::endl;
}


CMonsterPersueState::CMonsterPersueState(MonsterBase* Owner) :CPersueState()
{
	m_Owner = Owner;
}

void CMonsterPersueState::Enter()
{
	if (!m_Owner) {
		return;
	}
	std::cout << m_Owner->m_Name << " ����׷��״̬ " << std::endl;
}

void CMonsterPersueState::Process()
{
	if (!m_Owner) {
		return;
	}
	std::cout << m_Owner->m_Name << " ׷���С��� " << std::endl;
}

void CMonsterPersueState::Leave()
{
	if (!m_Owner) {
		return;
	}
	std::cout << m_Owner->m_Name << " ׷��״̬�뿪�� " << std::endl;
}

void CMonsterPersueState::Process(Target_Str& tarobjece)
{
	std::cout << m_Owner->m_Name << " ׷���С��� " << "Ŀ��Ϊ" << tarobjece << std::endl;
}
