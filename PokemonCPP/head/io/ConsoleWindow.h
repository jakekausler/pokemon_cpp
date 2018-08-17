#pragma once
#include <vector>
#include <string>
#include "ConsoleObject.h"

namespace ConsoleOutput {
	using std::vector;
	using std::string;
		
	class ConsoleObject;

	class ConsoleWindow {
	private:
		const int width;
		const int height;

		vector<ConsoleObject> objects;

	public:
		ConsoleWindow(int w, int h);

		void clear();

		void addObject(ConsoleObject obj);

		friend std::ostream& operator<< (std::ostream &out, const ConsoleWindow &win);
	};
}