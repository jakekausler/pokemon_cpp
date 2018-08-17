#pragma once
#include <string>
#include <stdexcept>

namespace Stats {
	using std::string;

	enum Stat {
		HP,
		ATTACK,
		DEFENSE,
		SPEED,
		SPATK,
		SPDEF,
		ACCURACY,
		EVASION,
	};

	string GetName(Stat s) {
		switch (s) {
		case HP:
			return "HP";
		case ATTACK:
			return "Attack";
		case DEFENSE:
			return "Defense";
		case SPEED:
			return "Speed";
		case SPATK:
			return "Special Attack";
		case SPDEF:
			return "Special Defense";
		case ACCURACY:
			return "Accuracy";
		case EVASION:
			return "Evasion";
		default:
			throw std::runtime_error("Not a valid stat!");
		}
	}

	string GetNameBrief(Stat s) {
		switch (s) {
		case HP:
			return "HP";
		case ATTACK:
			return "Atk";
		case DEFENSE:
			return "Def";
		case SPEED:
			return "Spd";
		case SPATK:
			return "SpAtk";
		case SPDEF:
			return "SpDef";
		case ACCURACY:
			return "Acc";
		case EVASION:
			return "Eva";
		default:
			throw std::runtime_error("Not a valid stat!");
		}
	}
}