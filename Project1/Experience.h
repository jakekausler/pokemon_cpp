//TODO: Finish
#pragma once
#include "settings.h""

namespace Data {
	namespace Experience {
		enum Growth {
			MEDIUM,
			ERRATIC,
			FLUCTUATING,
			PARABOLIC,
			FAST,
			SLOW,
		};

		const int MAX_LEVEL = Settings::MAXIMUM_LEVEL;
	}
}