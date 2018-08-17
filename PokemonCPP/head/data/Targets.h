#pragma once
#include "BattleMove.h"

namespace Targets {

	enum Target {
		SingleNonUser = 0x00,
		NoTarget = 0x01,
		RandomOpposing = 0x02,
		AllOpposing = 0x04,
		AllNonUsers = 0x08,
		User = 0x10,
		BothSides = 0x20,
		UserSide = 0x40,
		OpposingSide = 0x80,
		Partner = 0x100,
		UserOrPartner = 0x200,
		SingleOpposing = 0x400,
		OppositeOpposing = 0x800,
	};

	bool HasMultipleTargets(Battle::BattleMove move);
	bool TargetsOneOpponent(Battle::BattleMove move);
}