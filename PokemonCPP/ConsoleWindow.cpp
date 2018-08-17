#include "ConsoleWindow.h"
#include <stdlib.h>
#include <iostream>
#include <string>
#include <array>

namespace ConsoleOutput {
	using std::cout;
	using std::endl;
	using std::string;
	using std::array;

	ConsoleWindow::ConsoleWindow(int w, int h) : width(w), height(h), objects() {
		objects.push_back(ConsoleObject(width, height, 0, 0, "", true));
	}

	std::ostream& operator<< (std::ostream &out, const ConsoleWindow &win) {
		vector<vector<char>> screen;
		screen.resize(win.height);
		for (int i = 0; i < win.height; i++) {
			screen[i].resize(win.width);
		}
		for (ConsoleObject obj : win.objects) {
			vector<vector<char>> text = obj.getTextObject();
			for (int i = 0; i < obj.getHeight(); i++) {
				for (int j = 0; j < obj.getWidth(); j++) {
					screen[i + obj.getY()][j + obj.getX()] = text[i][j];
				}
			}
		}
		for (int i = 0; i < win.height; i++) {
			for (int j = 0; j < win.width; j++) {
				cout << screen[i][j];
			}
			cout << endl;
		}

		return out;
	}

	void ConsoleWindow::addObject(ConsoleObject obj) {
		objects.push_back(obj);
	}

	void ConsoleWindow::clear() {
		system("CLS");
	}

}