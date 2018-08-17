#include "Experience.h"
#include <cmath>
#include <stdexcept>
#include <algorithm>

int Experience::GetExperienceInternal(const int level, const Growth growth)
{
	if (level > 100) {
		switch (growth) {
			int rate;
		case MEDIUM:
			return static_cast<int>(pow(level, 3));
		case ERRATIC:
			return static_cast<int>(pow(level, 3) * ((level * 6 / 10) / (100 * 1.0)));
		case FLUCTUATING:
			rate = 82 - (level - 100) / 2;
			if (rate < 40)
				rate = 40;
			return static_cast<int>(pow(level, 3) * ((level * rate / 100) / 50.0));
		case PARABOLIC:
			return static_cast<int>((6 * pow(level, 3) / 5) - 15 * pow(level, 2) + 100 * level - 140);
		case FAST:
			return static_cast<int>(4 * pow(level, 3) / 5);
		case SLOW:
			return static_cast<int>(5 * pow(level, 3) / 4);
		default:
			return 0;
		}
	}
	else {
		return ExpTable[growth][level];
	}
}

int Experience::GetMaxExperience(const Growth growth)
{
	return GetExperienceInternal(MAX_LEVEL, growth);
}

int Experience::GetStartExperience(int level, const Growth growth)
{
	if (level < 0) {
		throw std::runtime_error("Level cannot be less than 0!");
	}
	if (level > MAX_LEVEL) {
		level = MAX_LEVEL;
	}
	return GetExperienceInternal(level, growth);
}

int Experience::AddExperience(const int currExp, const int expGain, const Growth growth)
{
	return std::min(currExp + expGain, GetMaxExperience(growth));
	
}

int Experience::GetLevelFromExperience(int exp, const Growth growth)
{
	exp = std::min(exp, GetMaxExperience(growth));
	for (int j = 0; j < MAX_LEVEL; j++)
	{
		int currExp = GetExperienceInternal(j, growth);
		if (exp == currExp) {
			return j;
		}
		if (exp < currExp) {
			return j - 1;
		}
	}
	return MAX_LEVEL;
}
