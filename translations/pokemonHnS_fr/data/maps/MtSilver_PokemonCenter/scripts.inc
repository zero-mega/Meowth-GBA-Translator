.set LOCALID_NURSE, 1

MtSilver_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MtSilver_PokemonCenter_OnTransition
	.byte 0

MtSilver_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_MT_SILVER
	end

MtSilver_PokemonCenter_EventScript_Meara::
	msgbox MtSilver_PokemonCenter_Text_Meara, MSGBOX_NPC
	end

MtSilver_PokemonCenter_Text_Meara:
	.string "Je suis chercheur\n"
	.string "du musée\p"
	.string "d'ARGANTA.\n"
	.string "Une quantité\l"
	.string "inhabituelle\p"
	.string "d'artefacts a été\n"
	.string "découverte\l"
	.string "récemment.\l"
	.string "C'est passionnant\p"
	.string "pour la recherche !$"
