#include "CPatrolState.h"
#include <iostream>
#include "MonsterBase.h"

void CPatrolState::Enter()
{
	std::cout << " ½øÈëÑ²Âß×´Ì¬ " << std::endl;
}

void CPatrolState::Process()
{
	std::cout << " Ñ²Âß×´Ì¬Âß¼­´¦ÀíÖÐ¡­¡­ " << std::endl;
}

void CPatrolState::Leave()
{
	std::cout << " Ñ²Âß×´Ì¬Àë¿ªÁË " << std::endl;
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
	std::cout << m_Owner->m_Name << " ½øÈëÑ²Âß×´Ì¬ " << std::endl;
}

void CMonsterPatrolState::Process()
{
	if (!m_Owner) {
		return;
	}
	std::cout << m_Owner->m_Name << " Ñ²ÂßÖÐ¡­¡­ " << std::endl;
}

void CMonsterPatrolState::Leave()
{
	if (!m_Owner) {
		return;
	}
	std::cout << m_Owner->m_Name << " Ñ²Âß×´Ì¬Àë¿ªÁË " << std::endl;
}