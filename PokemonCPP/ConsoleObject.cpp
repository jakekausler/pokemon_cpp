#include "ConsoleObject.h"

namespace IO {
	namespace Output {
		int ConsoleObject::getX() {
			return xPos;
		}
		int ConsoleObject::getY() {
			return yPos;
		}
		int ConsoleObject::getWidth() {
			return width;
		}
		int ConsoleObject::getHeight() {
			return height;
		}
		string ConsoleObject::getText() {
			return text;
		}
		bool ConsoleObject::hasBorder() {
			return border;
		}

		vector<vector<char>> ConsoleObject::getTextObject() {
			vector<vector<char>> retVal;
			retVal.push_back(vector<char>(width, hasBorder() ? '=' : ' '));
			for (int i = 1; i < height - 1; i++) {
				retVal.push_back(vector<char>(width, ' '));
				if (hasBorder()) {
					retVal[i][0] = '=';
					retVal[i][width - 1] = '=';
				}
			}
			retVal.push_back(vector<char>(width, hasBorder() ? '=' : ' '));
			int text_row = getHeight() / 2;
			int text_col = (getWidth() / 2) - (getText().length() / 2);
			for (char &c : getText()) {
				if (text_col < 0 || text_col >= getWidth()) {
					text_col++;
					continue;
				}
				retVal[text_row][text_col++] = c;
			}
			for (ConsoleObject obj : objects) {
				vector<vector<char>> text = obj.getTextObject();
				for (int i = 0; i < obj.getHeight(); i++) {
					for (int j = 0; j < obj.getWidth(); j++) {
						retVal[i + obj.getY()][j + obj.getX()] = text[i][j];
					}
				}
			}
			return retVal;
		}

		void ConsoleObject::addObject(ConsoleObject obj) {
			objects.push_back(obj);
		}
	}
}