.set LOCALID_NURSE, 1

VermilionCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_PokemonCenter_OnTransition
	.byte 0

VermilionCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_VERMILION_CITY
	end

VermilionPokeCenter_EventScript_FishingGuru::
	goto_if_set FLAG_HIDE_VERMILION_SNORLAX, VermilionPokeCenter_EventScript_FishingGuru2
	msgbox VermilionCity_PokemonCenter1F_Text_FishingGuru, MSGBOX_NPC
	end

VermilionPokeCenter_EventScript_FishingGuru2::
	msgbox VermilionCity_PokemonCenter1F_Text_FishingGuru_FoughtSnorlax, MSGBOX_NPC
	end

VermilionPokeCenter_EventScript_Sailor::
	msgbox VermilionCity_PokemonCenter1F_Text_Sailor, MSGBOX_NPC
	end

VermilionPokeCenter_EventScript_Bugcatcher::
	msgbox VermilionCity_PokemonCenter1F_Text_BugCatcher, MSGBOX_NPC
	end

VermilionCity_PokemonCenter1F_Text_FishingGuru:
	.string "Un POKéMON endormi est allongé\n"
	.string "devant la GROTTE TAUPIQUEUR.\p"
	.string "C'est une occasion fantastique de\n"
	.string "l'attraper, mais comment le réveiller ?$"

VermilionCity_PokemonCenter1F_Text_FishingGuru_FoughtSnorlax:
	.string "Il y avait autrefois un POKéMON endormi\n"
	.string "devant l'entrée de la\l"
	.string "GROTTE TAUPIQUEUR.\p"
	.string "Mais il semble avoir disparu.$"

VermilionCity_PokemonCenter1F_Text_Sailor:
	.string "Le PÈQUE-FLÈCHE est un super endroit pour\n"
	.string "rencontrer et combattre des Dresseurs.$"

VermilionCity_PokemonCenter1F_Text_BugCatcher:
	.string "Oh ? Tu as des BADGES que je n'ai\n"
	.string "jamais vus.\p"
	.string "Oh, je comprends. Tu les as obtenus en\n"
	.string "JOHTO.$"
