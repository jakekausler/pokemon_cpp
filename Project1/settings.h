#pragma once
#include "Items.h"
#include "Trainer.h"
#include "Pokemon.h"
#include <string>
#include <array>
#include <map>
#include <vector>

namespace Settings{
	using namespace Data;
	using std::string;
	using std::array;
	using std::vector;
	using std::map;

	// The default screen width (at a zoom of 1.0; size is half this at zoom 0.5).
	const int DEFAULT_SCREEN_WIDTH = 512;
	// The default screen height (at a zoom of 1.0).
	const int DEFAULT_SCREEN_HEIGHT = 384;
	// The default screen zoom. (1.0 means each tile is 32x32 pixels, 0.5 means
	// each tile is 16x16 pixels, 2.0 means each tile is 64x64 pixels.)
	const double DEFAULT_SCREEN_ZOOM = 1.0;
	// Whether full-screen display lets the border graphic go outside the edges of
	// the screen(true), or forces the border graphic to always be fully shown
	// (false).
	const bool FULL_SCREEN_BORDER_CROP = false;
	// The width of each of the left and right sides of the screen border. This is
	// added on to the screen width above, only if the border is turned on.
	const int BORDER_WIDTH = 80;
	// The height of each of the top and bottom sides of the screen border. This is
	// added on to the screen height above, only if the border is turned on.
	const int BORDER_HEIGHT = 80;
	// Map view mode (0=original, 1=custom, 2=perspective).
	const int MAP_VIEW_MODE = 1;

	// Max Level a Pokemon can reach
	const int MAXIMUM_LEVEL = 100;
	// Level of newly hatched Pokemon
	const int EGG_INITIAL_LEVEL = 1;
	// Chance of a newly generated Pokemon being shiny (out of 65536)
	const int SHINY_CHANCE = 8;
	// Chance of a newly generated Pokemon having Pokerus (out of 65536)
	const int POKERUS_CHANCE = 3;

	// Whether poisoned Pokémon will lose HP while walking around in the field.
	const bool POISON_IN_FIELD = true;
	// Whether poisoned Pokémon will faint while walking around in the field
	// (true), or survive the poisoning with 1HP (false).
	const bool POISON_FAINT_IN_FIELD = false;
	// Whether fishing automatically hooks the Pokémon (if false, there is a
	// reaction test first).
	const bool FISHING_AUTO_HOOK = false;
	// Whether the player can surface from anywhere while diving (true), or only in
	// spots where they could dive down from above(false).
	const bool DIVING_SURFACE_ANYWHERE = false;
	// Whether planted berries grow according to Gen 4 mechanics(true) or Gen 3
	// mechanics(false).
	const bool NEW_BERRY_PLANTS = true;
	//Whether TMs can be used infinitely as in Gen 5 (true), or are one - use - only
	// as in older Gens(false).
	const bool INFINITE_TMS	= true;

	// Whether outdoor maps should be shaded according to the time of day.
	const bool ENABLE_SHADING = true;

	// Whether a move's physical/special category depends on the move itself as in
	// newer Gens(true), or on its type as in older Gens(false).
	const bool USE_MOVE_CATEGORY = true;
	// Whether the battle mechanics mimic Gen 6 (true) or Gen 5 (false).
	const bool USE_MOVE_CATEGORY = true;
	// Whether the Exp gained from beating a Pokémon should be scaled depending on
	// gainer's level as in Gen 5 (true), or not as in other Gens (false).
	const bool USE_MOVE_CATEGORY = true;
	// Whether the Exp gained from beating a Pokémon should be divided equally
	// between each participant(false), or whether each participant should gain
	// that much Exp.This also applies to Exp gained via the Exp Share(held
	// item version) being distributed to all Exp Share holders.This is true in
	// Gen 6 and false otherwise.
	const bool USE_MOVE_CATEGORY = true;
	// Whether the critical capture mechanic applies (true) or not (false). Note
	// that it is based on a total of 600 + species(i.e.that many species need
	// to be caught to provide the greatest critical capture chance of 2.5x),
	// and there may be fewer species in your game.
	const bool USE_MOVE_CATEGORY = true;
	// Whether Pokémon gain Exp for capturing a Pokémon (true) or not (false).
	// An array of items which act as Mega Rings for the player (NPCs don't need a
	// Mega Ring item, just a Mega Stone).
	const array<Items::Item, 4> MEGA_RINGS = {
		Items::MEGARING,
		Items::MEGABRACELET,
		Items::MEGACUFF,
		Items::MEGACHARM
	};

	// The minimum number of badges required to boost each stat of a player's
	// Pokémon by 1.1x, while using moves in battle only.
	const int BADGES_BOOST_ATTACK = 1;
	const int BADGES_BOOST_DEFENSE = 5;
	const int BADGES_BOOST_SPEED = 3;
	const int BADGES_BOOST_SPATK = 7;
	const int BADGES_BOOST_SPDEF = 7;
	// Whether the badge restriction on using certain hidden moves is either owning
	// at least a certain number of badges(true), or owning a particular badge
	// (false).
	const bool HIDDEN_MOVES_COUNT_BADGES = true;
	// Depending on HIDDENMOVESCOUNTBADGES, either the number of badges required to
	// use each hidden move, or the specific badge number required to use each
	// move.Remember that badge 0 is the first badge, badge 1 is the second
	// badge, etc.
	// e.g.To require the second badge, put false and 1.
	// To require at least 2 badges, put true and 2.
	const int BADGE_FOR_CUT = 1;
	const int BADGE_FOR_FLASH = 2;
	const int BADGE_FOR_ROCKSMASH = 3;
	const int BADGE_FOR_SURF = 4;
	const int BADGE_FOR_FLY = 5;
	const int BADGE_FOR_STRENGTH = 6;
	const int BADGE_FOR_DIVE = 7;
	const int BADGE_FOR_WATERFALL = 8;

	// The names of each pocket of the Bag. Leave the first entry blank.
	const array<string, 9> POCKET_NAMES = {
		"Items",
		"Medicine",
		"Poke Balls",
		"TMs & HMs",
		"Berries",
		"Mail",
		"Battle Items",
		"Key Items"
	};
	// The maximum number of slots per pocket (-1 means infinite number). Ignore
	// the first number.
	const array<int, 9> MAX_POCKET_SIZE = {
		0,
		-1,
		-1,
		-1,
		-1,
		-1,
		-1,
		-1,
		-1
	};
	// The maximum number of items each slot in the Bag can hold.
	const int BAG_MAX_PER_SLOT = 999;
	// Whether each pocket in turn auto-sorts itself by item ID number. Ignore the
	// first entry.
	const array<bool, 9> POCKET_AUTO_SORT = {
		false,
		false,
		false,
		false,
		true,
		true,
		false,
		false,
		false
	};

	// The name of the person who created the PokÃ©mon storage system.
	const string STORAGE_CREATOR = "Bill";
	// The number of boxes in PokÃ©mon storage.
	const int STORAGE_BOXES = 24;

	// Whether the PokÃ©dex list shown is the one for the player's current region
	// (true), or whether a menu pops up for the player to manually choose which
	// Dex list to view when appropriate(false).
	const bool DEX_DEPENDS_ON_LOCATION = false;
	// The names of each Dex list in the game, in order and with National Dex at
	// the end.This is also the order that $PokemonGlobal.pokedexUnlocked is
	// in, which records which Dexes have been unlocked(first is unlocked by
	// default).
	// You can define which region a particular Dex list is linked to.This
	// means the area map shown while viewing that Dex list will ALWAYS be that
	// of the defined region, rather than whichever region the player is
	// currently in.To define this, put the Dex name and the region number in
	// an array, like the Kanto and Johto Dexes are.The National Dex isn't in
	// an array with a region number, therefore its area map is whichever region
	// the player is currently in.
	const array<string, 3> DEX_NAMES = {
		"Kanto Pokedex",
		"Johto Pokedex",
		"National Pokedex"
	};
	// Whether all forms of a given species will be immediately available to view
	// in the PokÃ©dex so long as that species has been seen at all(true), or
	// whether each form needs to be seen specifically before that form appears
	// in the PokÃ©dex(false).
	const bool ALWAYS_SHOW_ALL_FORMS = false;
	// An array of numbers, where each number is that of a Dex list (National Dex
	// is - 1).All Dex lists included here have the species numbers in them
	// reduced by 1, thus making the first listed species have a species number
	// of 0 (e.g.Victini in Unova's Dex).
	const array<int, 0> DEX_INDEX_OFFSETS = {};

	// The amount of money the player starts the game with.
	const int INITIAL_MONEY = 3000;
	// The maximum amount of money the player can have.
	const int MAX_MONEY = 999999;
	// The maximum number of Game Corner coins the player can have.
	const int MAX_COINS = 99999;
	// The maximum length, in characters, that the player's name can be.
	const int PLAYER_NAME_LIMIT = 10;

	// A set of arrays each containing a trainer type followed by a Global Variable
	// number.If the variable isn't set to 0, then all trainers with the
	// associated trainer type will be named as whatever is in that variable.
	const array<array<Trainers::Trainer, 2>, 0> RIVAL_NAMES = {};

	// A list of maps used by roaming PokÃ©mon. Each map has an array of other maps
	// it can lead to.
	const map<int, vector<int>> ROAMING_AREAS = {};
	// A set of arrays each containing the details of a roaming PokÃ©mon. The
	// information within is as follows :
	// - Species.
	// - Level.
	// - Global Switch; the PokÃ©mon roams while this is ON.
	// - Encounter type (0=any, 1=grass/walking in cave, 2=surfing, 3=fishing,
	// 4 = surfing / fishing).See bottom of PField_RoamingPokemon for lists.
	// - Name of BGM to play for that encounter (optional).
	// - Roaming areas specifically for this PokÃ©mon (optional).
	const map<Pokemon::Species, int> ROAMING_LEVELS = {};
	const map<Pokemon::Species, int> ROAMING_SWITCHES = {};
	const map<Pokemon::Species, int> ROAMING_TYPES = {};
	const map<Pokemon::Species, string> ROAMING_BGMS = {};
	const map<Pokemon::Species, map<int, vector<int>>> ROAMING_AREAS = {};

	// A set of arrays each containing details of a wild encounter that can only
	// occur via using the PokÃ© Radar.The information within is as follows :
	// - Map ID on which this encounter can occur.
	// - Probability that this encounter will occur (as a percentage).
	// - Species.
	// - Minimum possible level.
	// - Maximum possible level (optional).
	const array<array<int, 5>, 0> POKERADAR_EXCLUSIVES = {};

	// A set of arrays each containing details of a graphic to be shown on the
	// region map if appropriate.The values for each array are as follows :
	// - Region number.
	// - Global Switch; the graphic is shown if this is ON (non-wall maps only).
	// - X coordinate of the graphic on the map, in squares.
	// - Y coordinate of the graphic on the map, in squares.
	// - Name of the graphic, found in the Graphics/Pictures folder.
	// - The graphic will always (true) or never (false) be shown on a wall map.
	struct RegionMapExtra {
		int region;
		int globalSwitch;
		int x;
		int y;
		string graphic;
		bool alwaysOnWall;
	};
	const array<RegionMapExtra, 0> REGION_MAP_EXTRAS = {};

	// The number of steps allowed before a Safari Zone game is over (0=infinite).
	const int SAFARI_STEPS = 600;
	// The number of seconds a Bug Catching Contest lasts for (0=infinite).
	const BUG_CONTEST_TIME = 1200;

	// The Global Switch that is set to ON when the player whites out.
	const int STARTING_OVER_SWITCH = 1;
	// The Global Switch that is set to ON when the player has seen PokÃ©rus in the
	// PokÃ© Center, and doesn't need to be told about it again.
	const int SEEN_POKERUS_SWITCH = 2;
	// The Global Switch which, while ON, makes all wild PokÃ©mon created be
	// shiny.
	const int SHINY_WILD_POKEMON_SWITCH = 31;
	// The Global Switch which, while ON, makes all PokÃ©mon created considered to
	// be met via a fateful encounter.
	const int FATEFUL_ENCOUNTER_SWITCH = 32;
	// The Global Switch which determines whether the player will lose money if
	// they lose a battle(they can still gain money from trainers for winning).
	const int NO_MONEY_LOSS = 33;
	// The Global Switch which, while ON, prevents all PokÃ©mon in battle from Mega
	// Evolving even if they otherwise could.
	const int NO_MEGA_EVOLUTION = 34;

	// The ID of the common event that runs when the player starts fishing (runs
	// instead of showing the casting animation).
	const int FISHING_BEGIN_COMMON_EVENT = -1;
	// The ID of the common event that runs when the player stops fishing(runs
	// instead of showing the reeling in animation).
	const int FISHING_END_COMMON_EVENT = -1;

	// The ID of the animation played when the player steps on grass (shows grass
	// rustling).
	const int GRASS_ANIMATION_ID = 1;
	// The ID of the animation played when the player lands on the ground after
	// hopping over a ledge(shows a dust impact).
	const int DUST_ANIMATION_ID = 2;
	// The ID of the animation played when a trainer notices the player (an
	// exclamation bubble).
	const int EXCLAMATION_ANIMATION_ID = 3;
	// The ID of the animation played when a patch of grass rustles due to using
	// the PokÃ© Radar.
	const int RUSTLE_NORMAL_ANIMATION_ID = 1;
	// The ID of the animation played when a patch of grass rustles vigorously due
	// to using the PokÃ© Radar. (Rarer species)
	const int RUSTLE_VIGOROUS_ANIMATION_ID = 5;
	// The ID of the animation played when a patch of grass rustles and shines due
	// to using the PokÃ© Radar. (Shiny encounter)
	const int RUSTLE_SHINY_ANIMATION_ID = 6;
	// The ID of the animation played when a berry tree grows a stage while the
	// player is on the map(for new plant growth mechanics only).
	const int PLANT_SPARKLE_ANIMATION_ID = 7;


	// An array of available languages in the game, and their corresponding
	// message file in the Data folder.Edit only if you have 2 or more
	// languages to choose from.
	const array<array<string, 2>, 1> LANGUAGES = {"English", "english.dat"};
}