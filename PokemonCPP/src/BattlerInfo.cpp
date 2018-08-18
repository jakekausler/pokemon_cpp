#include "BattlerInfo.h"
#include <string>

namespace ConsoleOutput {
	BattlerInfo::BattlerInfo(int w, int h, int x, int y, string t, bool b, string name, int currHP, int maxHP, int currXP, int nextXP, int gender) : ConsoleObject(w, h, x, y, t, b) {
		addObject(ConsoleObject(getWidth()-2, 1, 1, 1, name, false));
		addObject(ConsoleObject(getWidth()-2, 1, 1, 2, "HP: " + std::to_string(currHP) + "/" + std::to_string(maxHP), false));
		addObject(ConsoleObject(getWidth()-2, 1, 1, 3, "XP: " + std::to_string(currXP) + "/" + std::to_string(nextXP), false));
		string g;
		switch (gender) {
		case 0:
			g = "-";
			break;
		case 1:
			g = "M";
			break;
		case 2:
			g = "F";
			break;
		default:
			g = "-";
			break;
		}
		addObject(ConsoleObject(getWidth()-2, 1, 0, 4, "Gender: " + g, false));
	}
}
