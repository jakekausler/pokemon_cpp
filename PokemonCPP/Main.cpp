#include <iostream>;
#include <Windows.h>;
#include "ConsoleWindow.h"
#include "ConsoleObject.h"
#include "FightCommandMenu.h"
#include "BattlerInfo.h"

using namespace std;

int main(int argc, char *argv[]) {
	IO::Output::ConsoleWindow cw(120, 29);
	cw.addObject(IO::Output::FightCommandMenu(120, 10, 0, 18, "", true));
	cw.addObject(IO::Output::BattlerInfo(60, 6, 0, 0, "", true, "Bulbasaur", 10, 20, 40, 50, 1));
	cw.addObject(IO::Output::BattlerInfo(60, 6, 60, 12, "", true, "Charmander", 15, 23, 35, 55, 2));
	cw.clear();
	cout << cw;
	system("PAUSE");
	return 0;
}