#pragma once
#include <string>

namespace Ribbons {
	using std::string;

	enum Ribbon {
		HOENNCOOL = 1,
		HOENNCOOLSUPER,
		HOENNCOOLHYPER,
		HOENNCOOLMASTER,
		HOENNBEAUTY,
		HOENNBEAUTYSUPER,
		HOENNBEAUTYHYPER,
		HOENNBEAUTYMASTER,
		HOENNCUTE,
		HOENNCUTESUPER,
		HOENNCUTEHYPER,
		HOENNCUTEMASTER,
		HOENNSMART,
		HOENNSMARTSUPER,
		HOENNSMARTHYPER,
		HOENNSMARTMASTER,
		HOENNTOUGH,
		HOENNTOUGHSUPER,
		HOENNTOUGHHYPER,
		HOENNTOUGHMASTER,
		SINNOHCOOL,
		SINNOHCOOLSUPER,
		SINNOHCOOLHYPER,
		SINNOHCOOLMASTER,
		SINNOHBEAUTY,
		SINNOHBEAUTYSUPER,
		SINNOHBEAUTYHYPER,
		SINNOHBEAUTYMASTER,
		SINNOHCUTE,
		SINNOHCUTESUPER,
		SINNOHCUTEHYPER,
		SINNOHCUTEMASTER,
		SINNOHSMART,
		SINNOHSMARTSUPER,
		SINNOHSMARTHYPER,
		SINNOHSMARTMASTER,
		SINNOHTOUGH,
		SINNOHTOUGHSUPER,
		SINNOHTOUGHHYPER,
		SINNOHTOUGHMASTER,
		WINNING,
		VICTORY,
		ABILITY,
		GREATABILITY,
		DOUBLEABILITY,
		MULTIABILITY,
		PAIRABILITY,
		WORLDABILITY,
		CHAMPION,
		SINNOHCHAMP,
		RECORD,
		EVENT,
		LEGEND,
		GORGEOUS,
		ROYAL,
		GORGEOUSROYAL,
		ALERT,
		SHOCK,
		DOWNCAST,
		CARELESS,
		RELAX,
		SNOOZE,
		SMILE,
		FOOTPRINT,
		ARTIST,
		EFFORT,
		BIRTHDAY,
		SPECIAL,
		CLASSIC,
		PREMIER,
		SOUVENIR,
		WISHING,
		NATIONAL,
		COUNTRY,
		BATTLECHAMPION,
		REGIONALCHAMPION,
		EARTH,
		WORLD,
		NATIONALCHAMPION,
		WORLDCHAMPION,
	};

	int GetMaxValue() {
		return 24;
	}

	int GetCount() {
		return 25;
	}

	string GetName(Ribbon r) {
		switch (r) {
		case HOENNCOOL:
			return "Cool Ribbon";
		case HOENNCOOLSUPER:
			return "Cool Ribbon Super";
		case HOENNCOOLHYPER:
			return "Cool Ribbon Hyper";
		case HOENNCOOLMASTER:
			return "Cool Ribbon Master";
		case HOENNBEAUTY:
			return "Beauty Ribbon";
		case HOENNBEAUTYSUPER:
			return "Beauty Ribbon Super";
		case HOENNBEAUTYHYPER:
			return "Beauty Ribbon Hyper";
		case HOENNBEAUTYMASTER:
			return "Beauty Ribbon Master";
		case HOENNCUTE:
			return "Cute Ribbon";
		case HOENNCUTESUPER:
			return "Cute Ribbon Super";
		case HOENNCUTEHYPER:
			return "Cute Ribbon Hyper";
		case HOENNCUTEMASTER:
			return "Cute Ribbon Master";
		case HOENNSMART:
			return "Smart Ribbon";
		case HOENNSMARTSUPER:
			return "Smart Ribbon Super";
		case HOENNSMARTHYPER:
			return "Smart Ribbon Hyper";
		case HOENNSMARTMASTER:
			return "Smart Ribbon Master";
		case HOENNTOUGH:
			return "Tough Ribbon";
		case HOENNTOUGHSUPER:
			return "Tough Ribbon Super";
		case HOENNTOUGHHYPER:
			return "Tough Ribbon Hyper";
		case HOENNTOUGHMASTER:
			return "Tough Ribbon Master";
		case SINNOHCOOL:
			return "Cool Ribbon";
		case SINNOHCOOLSUPER:
			return "Cool Ribbon Great";
		case SINNOHCOOLHYPER:
			return "Cool Ribbon Ultra";
		case SINNOHCOOLMASTER:
			return "Cool Ribbon Master";
		case SINNOHBEAUTY:
			return "Beauty Ribbon";
		case SINNOHBEAUTYSUPER:
			return "Beauty Ribbon Great";
		case SINNOHBEAUTYHYPER:
			return "Beauty Ribbon Ultra";
		case SINNOHBEAUTYMASTER:
			return "Beauty Ribbon Master";
		case SINNOHCUTE:
			return "Cute Ribbon";
		case SINNOHCUTESUPER:
			return "Cute Ribbon Great";
		case SINNOHCUTEHYPER:
			return "Cute Ribbon Ultra";
		case SINNOHCUTEMASTER:
			return "Cute Ribbon Master";
		case SINNOHSMART:
			return "Smart Ribbon";
		case SINNOHSMARTSUPER:
			return "Smart Ribbon Great";
		case SINNOHSMARTHYPER:
			return "Smart Ribbon Ultra";
		case SINNOHSMARTMASTER:
			return "Smart Ribbon Master";
		case SINNOHTOUGH:
			return "Tough Ribbon";
		case SINNOHTOUGHSUPER:
			return "Tough Ribbon Great";
		case SINNOHTOUGHHYPER:
			return "Tough Ribbon Ultra";
		case SINNOHTOUGHMASTER:
			return "Tough Ribbon Master";
		case WINNING:
			return "Winning Ribbon";
		case VICTORY:
			return "Victory Ribbon";
		case ABILITY:
			return "Ability Ribbon";
		case GREATABILITY:
			return "Great Ability Ribbon";
		case DOUBLEABILITY:
			return "Double Ability Ribbon";
		case MULTIABILITY:
			return "Multi Ability Ribbon";
		case PAIRABILITY:
			return "Pair Ability Ribbon";
		case WORLDABILITY:
			return "World Ability Ribbon";
		case CHAMPION:
			return "Champion Ribbon";
		case SINNOHCHAMP:
			return "Sinnoh Champ Ribbon";
		case RECORD:
			return "Record Ribbon";
		case EVENT:
			return "Event Ribbon";
		case LEGEND:
			return "Legend Ribbon";
		case GORGEOUS:
			return "Gorgeous Ribbon";
		case ROYAL:
			return "Royal Ribbon";
		case GORGEOUSROYAL:
			return "Gorgeous Royal Ribbon";
		case ALERT:
			return "Alert Ribbon";
		case SHOCK:
			return "Shock Ribbon";
		case DOWNCAST:
			return "Downcast Ribbon";
		case CARELESS:
			return "Careless Ribbon";
		case RELAX:
			return "Relax Ribbon";
		case SNOOZE:
			return "Snooze Ribbon";
		case SMILE:
			return "Smile Ribbon";
		case FOOTPRINT:
			return "Footprint Ribbon";
		case ARTIST:
			return "Artist Ribbon";
		case EFFORT:
			return "Effort Ribbon";
		case BIRTHDAY:
			return "Birthday Ribbon";
		case SPECIAL:
			return "Special Ribbon";
		case CLASSIC:
			return "Classic Ribbon";
		case PREMIER:
			return "Premier Ribbon";
		case SOUVENIR:
			return "Souvenir Ribbon";
		case WISHING:
			return "Wishing Ribbon";
		case NATIONAL:
			return "National Ribbon";
		case COUNTRY:
			return "Country Ribbon";
		case BATTLECHAMPION:
			return "Battle Champion Ribbon";
		case REGIONALCHAMPION:
			return "Regional Champion Ribbon";
		case EARTH:
			return "Earth Ribbon";
		case WORLD:
			return "World Ribbon";
		case NATIONALCHAMPION:
			return "National Champion Ribbon";
		case WORLDCHAMPION:
			return "World Champion Ribbon";
		default:
			return "???";
		}
	}

	string GetName(Ribbon r) {
		switch (r) {
		case HOENNCOOL:
			return "Hoenn Cool Contest Normal Rank winner!";
		case HOENNCOOLSUPER:
			return "Hoenn Cool Contest Super Rank winner!";
		case HOENNCOOLHYPER:
			return "Hoenn Cool Contest Hyper Rank winner!";
		case HOENNCOOLMASTER:
			return "Hoenn Cool Contest Master Rank winner!";
		case HOENNBEAUTY:
			return "Hoenn Beauty Contest Normal Rank winner!";
		case HOENNBEAUTYSUPER:
			return "Hoenn Beauty Contest Super Rank winner!";
		case HOENNBEAUTYHYPER:
			return "Hoenn Beauty Contest Hyper Rank winner!";
		case HOENNBEAUTYMASTER:
			return "Hoenn Beauty Contest Master Rank winner!";
		case HOENNCUTE:
			return "Hoenn Cute Contest Normal Rank winner!";
		case HOENNCUTESUPER:
			return "Hoenn Cute Contest Super Rank winner!";
		case HOENNCUTEHYPER:
			return "Hoenn Cute Contest Hyper Rank winner!";
		case HOENNCUTEMASTER:
			return "Hoenn Cute Contest Master Rank winner!";
		case HOENNSMART:
			return "Hoenn Smart Contest Normal Rank winner!";
		case HOENNSMARTSUPER:
			return "Hoenn Smart Contest Super Rank winner!";
		case HOENNSMARTHYPER:
			return "Hoenn Smart Contest Hyper Rank winner!";
		case HOENNSMARTMASTER:
			return "Hoenn Smart Contest Master Rank winner!";
		case HOENNTOUGH:
			return "Hoenn Tough Contest Normal Rank winner!";
		case HOENNTOUGHSUPER:
			return "Hoenn Tough Contest Super Rank winner!";
		case HOENNTOUGHHYPER:
			return "Hoenn Tough Contest Hyper Rank winner!";
		case HOENNTOUGHMASTER:
			return "Hoenn Tough Contest Master Rank winner!";
		case SINNOHCOOL:
			return "Super Contest Cool Category Normal Rank winner!";
		case SINNOHCOOLSUPER:
			return "Super Contest Cool Category Great Rank winner!";
		case SINNOHCOOLHYPER:
			return "Super Contest Cool Category Ultra Rank winner!";
		case SINNOHCOOLMASTER:
			return "Super Contest Cool Category Master Rank winner!";
		case SINNOHBEAUTY:
			return "Super Contest Beauty Category Normal Rank winner!";
		case SINNOHBEAUTYSUPER:
			return "Super Contest Beauty Category Great Rank winner!";
		case SINNOHBEAUTYHYPER:
			return "Super Contest Beauty Category Ultra Rank winner!";
		case SINNOHBEAUTYMASTER:
			return "Super Contest Beauty Category Master Rank winner!";
		case SINNOHCUTE:
			return "Super Contest Cute Category Normal Rank winner!";
		case SINNOHCUTESUPER:
			return "Super Contest Cute Category Great Rank winner!";
		case SINNOHCUTEHYPER:
			return "Super Contest Cute Category Ultra Rank winner!";
		case SINNOHCUTEMASTER:
			return "Super Contest Cute Category Master Rank winner!";
		case SINNOHSMART:
			return "Super Contest Smart Category Normal Rank winner!";
		case SINNOHSMARTSUPER:
			return "Super Contest Smart Category Great Rank winner!";
		case SINNOHSMARTHYPER:
			return "Super Contest Smart Category Ultra Rank winner!";
		case SINNOHSMARTMASTER:
			return "Super Contest Smart Category Master Rank winner!";
		case SINNOHTOUGH:
			return "Super Contest Tough Category Normal Rank winner!";
		case SINNOHTOUGHSUPER:
			return "Super Contest Tough Category Great Rank winner!";
		case SINNOHTOUGHHYPER:
			return "Super Contest Tough Category Ultra Rank winner!";
		case SINNOHTOUGHMASTER:
			return "Super Contest Tough Category Master Rank winner!";
		case WINNING:
			return "Ribbon awarded for clearing Hoenn's Battle Tower's Lv. 50 challenge.";
		case VICTORY:
			return "Ribbon awarded for clearing Hoenn's Battle Tower's Lv. 100 challenge.";
		case ABILITY:
			return "A Ribbon awarded for defeating the Tower Tycoon at the Battle Tower.";
		case GREATABILITY:
			return "A Ribbon awarded for defeating the Tower Tycoon at the Battle Tower.";
		case DOUBLEABILITY:
			return "A Ribbon awarded for completing the Battle Tower Double challenge.";
		case MULTIABILITY:
			return "A Ribbon awarded for completing the Battle Tower Multi challenge.";
		case PAIRABILITY:
			return "A Ribbon awarded for completing the Battle Tower Link Multi challenge.";
		case WORLDABILITY:
			return "A Ribbon awarded for completing the Wi-Fi Battle Tower challenge.";
		case CHAMPION:
			return "Ribbon for clearing the Pokémon League and entering the Hall of Fame in another region. ";
		case SINNOHCHAMP:
			return "Ribbon awarded for beating the Sinnoh Champion and entering the Hall of Fame.";
		case RECORD:
			return "A Ribbon awarded for setting an incredible record.";
		case EVENT:
			return "Pokémon Event Participation Ribbon.";
		case LEGEND:
			return "A Ribbon awarded for setting a legendary record.";
		case GORGEOUS:
			return "An extraordinarily gorgeous and extravagant Ribbon.";
		case ROYAL:
			return "An incredibly regal Ribbon with an air of nobility.";
		case GORGEOUSROYAL:
			return "A gorgeous and regal Ribbon that is the peak of fabulous.";
		case ALERT:
			return "A Ribbon for recalling an invigorating event that created life energy.";
		case SHOCK:
			return "A Ribbon for recalling a thrilling event that made life more exciting.";
		case DOWNCAST:
			return "A Ribbon for recalling feelings of sadness that added spice to life.";
		case CARELESS:
			return "A Ribbon for recalling a careless error that helped steer life decisions.";
		case RELAX:
			return "A Ribbon for recalling a refreshing event that added sparkle to life.";
		case SNOOZE:
			return "A Ribbon for recalling a deep slumber that made life soothing.";
		case SMILE:
			return "A Ribbon for recalling that smiles enrich the quality of life.";
		case FOOTPRINT:
			return "A Ribbon awarded to a Pokémon deemed to have a top-quality footprint.";
		case ARTIST:
			return "Ribbon awarded for being chosen as a super sketch model in Hoenn.";
		case EFFORT:
			return "Ribbon awarded for being an exceptionally hard worker.";
		case BIRTHDAY:
			return "A Ribbon to celebrate a birthday.";
		case SPECIAL:
			return "A special Ribbon for a special day.";
		case CLASSIC:
			return "A Ribbon that proclaims love for Pokémon.";
		case PREMIER:
			return "Special Holiday Ribbon.";
		case SOUVENIR:
			return "A Ribbon to cherish a special memory.";
		case WISHING:
			return "A Ribbon said to make your wish come true.";
		case NATIONAL:
			return "A Ribbon awarded for overcoming all difficult challenges.";
		case COUNTRY:
			return "Pokémon League Champion Ribbon.";
		case BATTLECHAMPION:
			return "Battle Competition Champion Ribbon.";
		case REGIONALCHAMPION:
			return "Pokémon World Championships Regional Champion Ribbon.";
		case EARTH:
			return "A Ribbon awarded for winning 100 matches in a row.";
		case WORLD:
			return "Pokémon League Champion Ribbon.";
		case NATIONALCHAMPION:
			return "Pokémon World Championships National Champion Ribbon.";
		case WORLDCHAMPION:
			return "Pokémon World Championships World Champion Ribbon.";
		default:
			return "???";
		}
	}
}