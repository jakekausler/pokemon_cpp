#pragma once
#include <string>

namespace Colors {
	using std::string;

	enum Color {
		Red,
		Blue,
		Yellow,
		Green,
		Black,
		Brown,
		Purple,
		Gray,
		White,
		Pink,
	};

	int GetMaxValue() {
		return 9;
	}

	int GetCount() {
		return 10;
	}

	string GetName(Color c) {
		switch (c) {
		case Red:
			return "Red";
		case Blue:
			return "Blue";
		case Yellow:
			return "Yellow";
		case Green:
			return "Green";
		case Black:
			return "Black";
		case Brown:
			return "Brown";
		case Purple:
			return "Purple";
		case Gray:
			return "Gray";
		case White:
			return "White";
		case Pink:
			return "Pink";
		default:
			return "???";
		}
	}
}