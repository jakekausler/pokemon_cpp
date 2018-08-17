#pragma once

namespace Targets {

	enum Terrain {
		Ledge,
		Grass,
		Sand,
		Rock,
		DeepWater,
		StillWater,
		Water,
		Waterfall,
		WaterfallCrest,
		TallGrass,
		UnderwaterGrass,
		Ice,
		Neutral,
		SootGrass,
		Bridge,
		Puddle,
	};

	bool IsSurfable(Terrain tag);
	bool IsWater(Terrain tag);
	bool IsPassableWater(Terrain tag);
	bool IsJustWater(Terrain tag);
	bool IsDeepWater(Terrain tag);
	bool IsWaterfall(Terrain tag);
	bool IsGrass(Terrain tag);
	bool IsJustGrass(Terrain tag);
	bool IsLedge(Terrain tag);
	bool IsIce(Terrain tag);
	bool IsBridge(Terrain tag);
	bool HasReflection(Terrain tag);
	bool OnlyWalk(Terrain tag);
	bool IsDoubleWildBattle(Terrain tag);
}