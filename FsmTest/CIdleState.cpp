#include "CIdleState.h"
#include <iostream>
#include "MonsterBase.h"

void CIdleState::Enter()
{
	std::cout << " �������״̬ " << std::endl;
}

void CIdleState::Process()
{
	std::cout << " ����״̬�߼������С��� " << std::endl;
}

void CIdleState::Leave()
{
	std::cout << " ����״̬�뿪�� " << std::endl;
}


CMonsterIdleState::CMonsterIdleState(MonsterBase* Owner) :CIdleState()
{
	m_Owner = Owner;
}

void CMonsterIdleState::Enter()
{
	if (!m_Owner) {
		return;
	}
	std::cout << m_Owner->m_Name << " �������״̬ " << std::endl;
}

void CMonsterIdleState::Process()
{
	if (!m_Owner) {
		return;
	}
	std::cout << m_Owner->m_Name << " �����С��� " << std::endl;
}

void CMonsterIdleState::Leave()
{
	if (!m_Owner) {
		return;
	}
	std::cout << m_Owner->m_Name << " ����״̬�뿪�� " << std::endl;
}
