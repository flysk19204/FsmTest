#pragma once
#include <string>

#define	IDLE	"Idle"
#define	Patrol	"Patrol"
#define	Persue	"Persue"
#define	Attack	"Attack"
#define SAFE_DELETE(p) if(p) { delete p ; p = NULL;}
typedef std::string Condition_Str;
typedef const std::string Target_Str;

enum ConditionType
{
	ET_IDLE,
	ET_PATROL,
	ET_PERSUE,
	ET_ATTACK,
	
	ET_GOTO_LOGIN,
	ET_GOTO_CREATROLE,
	ET_GOTO_SELECTROLE,
};
typedef ConditionType ECondition;