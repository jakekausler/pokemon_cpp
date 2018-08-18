#include "Terrains.h"

bool Targets::IsSurfable(Terrain tag)
{
	return IsWater(tag);
}

bool Targets::IsWater(Terrain tag)
{
	return tag == Water ||
		tag == StillWater ||
		tag == DeepWater ||
		tag == WaterfallCrest ||
		tag == Waterfall;
}

bool Targets::IsPassableWater(Terrain tag)
{
	return tag == Water ||
		tag == StillWater ||
		tag == DeepWater ||
		tag == WaterfallCrest;
}

bool Targets::IsJustWater(Terrain tag)
{
	return tag == Water ||
		tag == StillWater ||
		tag == DeepWater;
}

bool Targets::IsDeepWater(Terrain tag)
{
	return tag == DeepWater;
}

bool Targets::IsWaterfall(Terrain tag)
{
	return tag == WaterfallCrest ||
		tag == Waterfall;
}

bool Targets::IsGrass(Terrain tag)
{
	return tag == Grass ||
		tag == TallGrass ||
		tag == UnderwaterGrass ||
		tag == SootGrass;
}

bool Targets::IsJustGrass(Terrain tag)
{
	return tag == Grass ||
		tag == UnderwaterGrass;
}

bool Targets::IsLedge(Terrain tag)
{
	return tag == Ledge;
}

bool Targets::IsIce(Terrain tag)
{
	return tag == Ice;
}

bool Targets::IsBridge(Terrain tag)
{
	return tag == Bridge;
}

bool Targets::HasReflection(Terrain tag)
{
	return tag == StillWater ||
		tag == Puddle;
}

bool Targets::OnlyWalk(Terrain tag)
{
	return tag == TallGrass ||
		tag == Ice;
}

bool Targets::IsDoubleWildBattle(Terrain tag)
{
	return tag == TallGrass;
}
