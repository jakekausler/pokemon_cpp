#pragma once
#include "ConsoleObject.h"

namespace IO {
	namespace Output {

		class FightCommandMenu :
			public ConsoleObject
		{
		public:
			FightCommandMenu(int w, int h, int x, int y, string t, bool b);
		};

	}
}

