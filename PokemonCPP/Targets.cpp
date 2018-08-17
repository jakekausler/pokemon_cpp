#include "Targets.h"

bool Targets::HasMultipleTargets(Battle::BattleMove move)
{
	return move.target & (AllOpposing | AllNonUsers) == move.target;
}

bool Targets::TargetsOneOpponent(Battle::BattleMove move)
{
	return move.target & (SingleNonUser | RandomOpposing | SingleOpposing | OppositeOpposing) == move.target;
}
