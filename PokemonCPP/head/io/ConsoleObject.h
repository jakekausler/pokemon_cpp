#pragma once
#include <string>
#include <vector>
#include "ConsoleWindow.h"

namespace ConsoleOutput {
	using std::string;
	using std::vector;

	class ConsoleObject {
	private:
		int width;
		int height;

		int xPos;
		int yPos;

		string text;
		bool border;

		vector<ConsoleObject> objects;

	public:
		ConsoleObject(int w, int h, int x, int y, string t, bool b) : width(w), height(h), xPos(x), yPos(y), text(t), border(b) {}

		int getWidth();
		int getHeight();
		int getX();
		int getY();
		string getText();
		bool hasBorder();

		// Get the text of width/height
		vector<vector<char>> getTextObject();

		void addObject(ConsoleObject obj);

		friend class ConsoleWindow;
	};
}