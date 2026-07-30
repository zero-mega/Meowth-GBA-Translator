.set LOCALID_NURSE, 1

ViridianCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianCity_PokemonCenter_OnTransition
	.byte 0

ViridianCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_VIRIDIAN_CITY
	end

ViridianCity_PokemonCenter_EventScript_CooltrainerM::
	goto_if_set FLAG_HIDE_CINNABAR_BLUE, VirianCity_EventScript_GymGrampsBlue
	msgbox ViridianCity_PokemonCenter_Text_1FCooltrainerM, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_EventScript_CooltrainerMBlue::
	msgbox ViridianCity_PokemonCenter_Text_1FCooltrainerM_BlueReturned, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_EventScript_CooltrainerF::
	msgbox ViridianCity_PokemonCenter_Text_1FCooltrainerF, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_EventScript_BugCatcher::
	msgbox ViridianCity_PokemonCenter_Text_1FBugCatcher, MSGBOX_NPC
	end

ViridianCity_PokemonCenter_Text_1FCooltrainerM:
	.string "Où est passé le CHAMPION D'ARÈNE de VERTANIA ?\n"
	.string "Je voulais le défier.$"

ViridianCity_PokemonCenter_Text_1FCooltrainerM_BlueReturned:
	.string "Il n'y a pas de DRESSEURS\n"
	.string "dans l'ARÈNE de JADIELLE. Le CHAMPION\p"
	.string "dit que sa politique est de\n"
	.string "gagner sans avoir de subordonnés.$"

ViridianCity_PokemonCenter_Text_1FCooltrainerF:
	.string "J'ai entendu dire que l'ARÈNE de CRAMOIS'ÎLE a\n"
	.string "disparu.\p"
	.string "Je me demande ce qu'est devenu AUGUSTE, le\n"
	.string "CHAMPION D'ARÈNE.$"

ViridianCity_PokemonCenter_Text_1FBugCatcher:
	.string "Mon rêve est de devenir CHAMPION d'ARÈNE.$"
