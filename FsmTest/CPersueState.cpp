#include "CPersueState.h"
#include <iostream>
#include "MonsterBase.h"

void CPersueState::Enter()
{
	std::cout << " ½øÈë×·»÷×´Ì¬ " << std::endl;
}

void CPersueState::Process()
{
	std::cout << " ×·»÷×´Ì¬Âß¼­´¦ÀíÖÐ¡­¡­ " << std::endl;
}

void CPersueState::Leave()
{
	std::cout << " ×·»÷×´Ì¬Àë¿ªÁË " << std::endl;
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
	std::cout << m_Owner->m_Name << " ½øÈë×·»÷×´Ì¬ " << std::endl;
}

void CMonsterPersueState::Process()
{
	if (!m_Owner) {
		return;
	}
	std::cout << m_Owner->m_Name << " ×·»÷ÖÐ¡­¡­ " << std::endl;
}

void CMonsterPersueState::Leave()
{
	if (!m_Owner) {
		return;
	}
	std::cout << m_Owner->m_Name << " ×·»÷×´Ì¬Àë¿ªÁË " << std::endl;
}

void CMonsterPersueState::Process(Target_Str& tarobjece)
{
	std::cout << m_Owner->m_Name << " ×·»÷ÖÐ¡­¡­ " << "Ä¿±êÎª" << tarobjece << std::endl;
}
