//TODO: Finish
#pragma once
#include "Battle.h"
#include <string>
#include "Types.h"
#include "Effects.h"
#include "Targets.h"
#include "Moves.h"

namespace Targets {
	enum Target;
}

namespace Battle {
	using std::string;

	class BattleMove {
	public:
		int id;
		Battle battle;
		string name;
		int function;
		int baseDamage;
		Types::Type type;
		int accuracy;
		Effects::MoveEffect addlEffect;
		Targets::Target target;
		int priority;
		int flags;
		Moves::Move thisMove;
		int pp;
		int totalPP;
		bool powerBoost;
	};
}