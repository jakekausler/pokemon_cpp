#pragma once
#include <string>

namespace Statuses {
	using std::string;

	enum Status {
		HEALTHY,
		SLEEP,
		POISON,
		BURN,
		PARALSIS,
		FROZEN,
	};

	string GetName(Status s) {
		switch (s) {
		case HEALTHY:
			return "healthy";
		case SLEEP:
			return "asleep";
		case POISON:
			return "poisoned";
		case BURN:
			return "burned";
		case PARALSIS:
			return "paralyzed";
		case FROZEN:
			return "frozen";
		default:
			return "???";
		}
	}
}