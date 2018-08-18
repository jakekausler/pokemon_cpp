#pragma once
#include "ConsoleObject.h"

namespace ConsoleOutput {

	class FightCommandMenu :
		public ConsoleObject
	{
	public:
		FightCommandMenu(int w, int h, int x, int y, string t, bool b);
	};

}

