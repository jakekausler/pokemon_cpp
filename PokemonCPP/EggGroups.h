#pragma once
#include <string>

namespace EggGroups {
	using std::string;

	enum EggGroup {
		Undiscovered,
		Monster,
		Water1,
		Bug,
		Flying,
		Field,
		Fairy,
		Grass,
		Humanlike,
		Water3,
		Mineral,
		Amorphous,
		Water2,
		Ditto,
		Dragon,
	};

	int GetMaxValue() {
		return 14;
	}

	int GetCount() {
		return 15;
	}

	string GetName(EggGroup eg) {
		switch (eg) {
		case Undiscovered:
			return "Undiscovered";
		case Monster:
			return "Monster";
		case Water1:
			return "Water 1";
		case Bug:
			return "Bug";
		case Flying:
			return "Flying";
		case Field:
			return "Field";
		case Fairy:
			return "Fairy";
		case Grass:
			return "Grass";
		case Humanlike:
			return "Humanlike";
		case Water3:
			return "Water 3";
		case Mineral:
			return "Mineral";
		case Amorphous:
			return "Amorphous";
		case Water2:
			return "Water 2";
		case Ditto:
			return "Ditto";
		case Dragon:
			return "Dragon";
		default:
			return "???";
		}
	}
}