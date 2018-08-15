#pragma once
#include <string>

namespace Data {
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

		int GetMaxValue(); //TODO: Implement

		int GetCount(); //TODO: Implement

		string GetName(Nature n); //TODO: Implement
	}
}