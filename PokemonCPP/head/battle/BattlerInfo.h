#pragma once
#include "ConsoleObject.h"

namespace ConsoleOutput {
	class BattlerInfo :
		public ConsoleObject
	{
	public:
		BattlerInfo(int w, int h, int x, int y, string t, bool b, string name, int currHP, int maxHP, int currXP, int nextXP, int gender);
	};
}

