#include "CAttackState.h"
#include <iostream>
#include "MonsterBase.h"

void CAttackState::Enter()
{
	std::cout << " ½øÈë¹¥»÷×´Ì¬ " << std::endl;
}

void CAttackState::Process()
{
	std::cout << " ¹¥»÷ÖÐ¡­¡­ " << std::endl;
}

void CAttackState::Leave()
{
	std::cout << " ¹¥»÷×´Ì¬Àë¿ªÁË " << std::endl;
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
	std::cout << m_Owner->m_Name << " ½øÈë¹¥»÷×´Ì¬ " << std::endl;
}

void CMonsterAttackState::Process()
{
	if (!m_Owner) {
		return;
	}
	std::cout << m_Owner->m_Name << " ¹¥»÷ÖÐ¡­¡­ " << std::endl;
}

void CMonsterAttackState::Leave()
{
	if (!m_Owner) {
		return;
	}
	std::cout << m_Owner->m_Name << " ¹¥»÷×´Ì¬Àë¿ªÁË " << std::endl;
}

void CMonsterAttackState::Process(Target_Str& tarobjece)
{
	if (!m_Owner) {
		return;
	}
	std::cout << m_Owner->m_Name << " ¹¥»÷ÖÐ¡­¡­ "<<"Ä¿±êÎª"<< tarobjece << std::endl;
}
