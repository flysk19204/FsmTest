#include "CIdleState.h"
#include <iostream>
#include "MonsterBase.h"

void CIdleState::Enter()
{
	std::cout << " ½øÈë¿ÕÏÐ×´Ì¬ " << std::endl;
}

void CIdleState::Process()
{
	std::cout << " ¿ÕÏÐ×´Ì¬Âß¼­´¦ÀíÖÐ¡­¡­ " << std::endl;
}

void CIdleState::Leave()
{
	std::cout << " ¿ÕÏÐ×´Ì¬Àë¿ªÁË " << std::endl;
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
	std::cout << m_Owner->m_Name << " ½øÈë¿ÕÏÐ×´Ì¬ " << std::endl;
}

void CMonsterIdleState::Process()
{
	if (!m_Owner) {
		return;
	}
	std::cout << m_Owner->m_Name << " ¿ÕÏÐÖÐ¡­¡­ " << std::endl;
}

void CMonsterIdleState::Leave()
{
	if (!m_Owner) {
		return;
	}
	std::cout << m_Owner->m_Name << " ¿ÕÏÐ×´Ì¬Àë¿ªÁË " << std::endl;
}
