.set LOCALID_NURSE, 1
.set LOCALID_FOLLOWER, 0xFE

OldaleTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

OldaleTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_OLDALE_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

OldaleTown_PokemonCenter_1F_EventScript_Nurse::
	applymovement LOCALID_FOLLOWER, Common_Movement_Enter_Pokeball
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Boy::
	msgbox OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat, MSGBOX_NPC
	end

OldaleTown_PokemonCenter_1F_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_SYS_POKEDEX_GET, OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable
	msgbox OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_EventScript_WirelessClubAvailable::
	msgbox OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub, MSGBOX_DEFAULT
	release
	end

OldaleTown_PokemonCenter_1F_Text_TrainersCanUsePC:
	.string "Ce PC dans le\n"
	.string "coin est pour tous\p"
	.string "les DRESSEURS POKéMON. Naturellement,\n"
	.string "tu peux l'utiliser aussi.$"

OldaleTown_PokemonCenter_1F_Text_PokemonCentersAreGreat:
	.string "Les CENTRES POKéMON, c'est génial !\p"
	.string "Tu peux utiliser leurs services\n"
	.string "autant que tu veux, c'est gratuit.\l"
	.string "Tu n'as jamais à t'en faire !$"

OldaleTown_PokemonCenter_1F_Text_WirelessClubNotAvailable:
	.string "Le CLUB POKéMON SANS FIL\n"
	.string "au deuxième étage a été\p"
	.string "construit récemment. Mais on dit\n"
	.string "qu'ils font encore des ajustements.$"

OldaleTown_PokemonCenter_1F_Text_TradedInWirelessClub:
	.string "Le CLUB POKéLINK au\n"
	.string "deuxième étage a été construit récemment.\p"
	.string "J'ai tout de suite échangé des POKéMON.$"

