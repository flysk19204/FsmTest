#include "CPatrolState.h"
#include <iostream>
#include "MonsterBase.h"

void CPatrolState::Enter()
{
	std::cout << " ����Ѳ��״̬ " << std::endl;
}

void CPatrolState::Process()
{
	std::cout << " Ѳ��״̬�߼������С��� " << std::endl;
}

void CPatrolState::Leave()
{
	std::cout << " Ѳ��״̬�뿪�� " << std::endl;
}


CMonsterPatrolState::CMonsterPatrolState(MonsterBase* Owner) :CPatrolState()
{
	m_Owner = Owner;
}

void CMonsterPatrolState::Enter()
{
	if (!m_Owner) {
		return;
	}
	std::cout << m_Owner->m_Name << " ����Ѳ��״̬ " << std::endl;
}

void CMonsterPatrolState::Process()
{
	if (!m_Owner) {
		return;
	}
	std::cout << m_Owner->m_Name << " Ѳ���С��� " << std::endl;
}

void CMonsterPatrolState::Leave()
{
	if (!m_Owner) {
		return;
	}
	std::cout << m_Owner->m_Name << " Ѳ��״̬�뿪�� " << std::endl;
}