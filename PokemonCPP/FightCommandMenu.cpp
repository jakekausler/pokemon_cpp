#include "FightCommandMenu.h"
#include "ConsoleObject.h"

namespace IO {
	namespace Output {
		FightCommandMenu::FightCommandMenu(int w, int h, int x, int y, string t, bool b) : ConsoleObject(w, h, x, y, t, b) {
			addObject(ConsoleObject(getWidth() / 2, getHeight() / 2, 0, 0, "Fight", true));
			addObject(ConsoleObject(getWidth() / 2, getHeight() / 2, getWidth()/2, 0, "Bag", true));
			addObject(ConsoleObject(getWidth() / 2, getHeight() / 2, 0, getHeight()/2, "Pokemon", true));
			addObject(ConsoleObject(getWidth() / 2, getHeight() / 2, getWidth()/2, getHeight()/2, "Run", true));
		}
	}
}
