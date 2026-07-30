.set LOCALID_NURSE, 1

PewterCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PewterCity_PokemonCenter_OnTransition
	.byte 0

PewterCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_PEWTER_CITY
	end

PewterCity_PokemonCenter_EventScript_Teacher::
	msgbox PewterCity_PokemonCenter1F_Text_Teacher, MSGBOX_NPC
	end

PewterCity_PokemonCenter_EventScript_BugCatcher::
	msgbox PewterCity_PokemonCenter1F_Text_BugCatcher, MSGBOX_NPC
	end

PewterCity_PokemonCenter1F_Text_Teacher:
	.string "…Ouais, et l'ARÈNE de CRAMOIS'ÎLE a disparu.\p"
	.string "J'étais vraiment surpris.\p"
	.string "…Oui ? Je suis au téléphone. Dégage !$"

PewterCity_PokemonCenter1F_Text_Jigglypuff:
	.string "RONDOUDOU : Puu pupuu.$"

PewterCity_PokemonCenter1F_Text_BugCatcher:
	.string "La plupart des POKéMON deviennent somnolents s'ils entendent\n"
	.string "un RONDOUDOU chanter.\p"
	.string "Il existe plusieurs capacités utilisables\n"
	.string "uniquement quand un POKéMON dort.$"
