#include "CAttackState.h"
#include <iostream>
#include "MonsterBase.h"

void CAttackState::Enter()
{
	std::cout << " ���빥��״̬ " << std::endl;
}

void CAttackState::Process()
{
	std::cout << " �����С��� " << std::endl;
}

void CAttackState::Leave()
{
	std::cout << " ����״̬�뿪�� " << std::endl;
}


CMonsterAttackState::CMonsterAttackState(MonsterBase* Owner):CAttackState()
{
	m_Owner = Owner;
}

void CMonsterAttackState::Enter()
{
	if (!m_Owner) {
		return;
	}
	std::cout << m_Owner->m_Name << " ���빥��״̬ " << std::endl;
}

void CMonsterAttackState::Process()
{
	if (!m_Owner) {
		return;
	}
	std::cout << m_Owner->m_Name << " �����С��� " << std::endl;
}

void CMonsterAttackState::Leave()
{
	if (!m_Owner) {
		return;
	}
	std::cout << m_Owner->m_Name << " ����״̬�뿪�� " << std::endl;
}

void CMonsterAttackState::Process(Target_Str& tarobjece)
{
	if (!m_Owner) {
		return;
	}
	std::cout << m_Owner->m_Name << " �����С��� "<<"Ŀ��Ϊ"<< tarobjece << std::endl;
}
