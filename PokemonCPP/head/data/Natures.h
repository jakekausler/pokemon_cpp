#pragma once
#include <string>

namespace Natures {
	using std::string;

	enum Nature {
		HARDY,
		LONELY,
		BRAVE,
		ADAMANT,
		NAUGHTY,
		BOLD,
		DOCILE,
		RELAXED,
		IMPISH,
		LAX,
		TIMID,
		HASTY,
		SERIOUS,
		JOLLY,
		NAIVE,
		MODEST,
		MILD,
		QUIET,
		BASHFUL,
		RASH,
		CALM,
		GENTLE,
		SASSY,
		CAREFUL,
		QUIRKY,
	};

	int GetMaxValue() {
		return 24;
	}

	int GetCount() {
		return 25;
	}

	string GetName(Nature n) {
		switch (n) {
		case HARDY:
			return "Hardy";
		case LONELY:
			return "Lonely";
		case BRAVE:
			return "Brave";
		case ADAMANT:
			return "Adamant";
		case NAUGHTY:
			return "Naughty";
		case BOLD:
			return "Bold";
		case DOCILE:
			return "Docile";
		case RELAXED:
			return "Relaxed";
		case IMPISH:
			return "Impish";
		case LAX:
			return "Lax";
		case TIMID:
			return "Timid";
		case HASTY:
			return "Hasty";
		case SERIOUS:
			return "Serious";
		case JOLLY:
			return "Jolly";
		case NAIVE:
			return "Naive";
		case MODEST:
			return "Modest";
		case MILD:
			return "Mild";
		case QUIET:
			return "Quiet";
		case BASHFUL:
			return "Bashful";
		case RASH:
			return "Rash";
		case CALM:
			return "Calm";
		case GENTLE:
			return "Gentle";
		case SASSY:
			return "Sassy";
		case CAREFUL:
			return "Careful";
		case QUIRKY:
			return "Quirky";
		default:
			return "???";
		}
	}
}