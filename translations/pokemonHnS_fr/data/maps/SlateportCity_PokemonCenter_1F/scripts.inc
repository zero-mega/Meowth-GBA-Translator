.set LOCALID_NURSE, 1

SlateportCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

SlateportCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_SLATEPORT_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

SlateportCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

SlateportCity_PokemonCenter_1F_EventScript_Sailor::
	msgbox SlateportCity_PokemonCenter_1F_Text_RaiseDifferentTypesOfPokemon, MSGBOX_NPC
	end

SlateportCity_PokemonCenter_1F_EventScript_Woman::
	msgbox SlateportCity_PokemonCenter_1F_Text_TradedMonWithFriend, MSGBOX_NPC
	end

SlateportCity_PokemonCenter_1F_Text_RaiseDifferentTypesOfPokemon:
	.string "Tu veux un conseil pour les\p"
	.string "combats ? Je dirais d'élever différents\n"
	.string "types de POKéMON de façon équilibrée.\p"
	.string "Ce n'est pas bon de ne\n"
	.string "rendre fort qu'un seul POKéMON. S'il\p"
	.string "a un désavantage de type,\n"
	.string "il n'aura peut-être aucune chance.$"

SlateportCity_PokemonCenter_1F_Text_TradedMonWithFriend:
	.string "J'échange des POKéMON avec mes amis.\p"
	.string "Si un POKéMON échangé tient un objet,\n"
	.string "ça me rend deux fois plus heureux !$"

