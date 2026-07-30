.set LOCALID_NURSE, 1

SootopolisCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

SootopolisCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_SOOTOPOLIS_CITY
	end

SootopolisCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_Gentleman::
	lock
	faceplayer
	goto_if_ge VAR_SKY_PILLAR_STATE, 2, SootopolisCity_PokemonCenter_1F_EventScript_GentlemanNoLegendaries
	goto_if_unset FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, SootopolisCity_PokemonCenter_1F_EventScript_GentlemanNoLegendaries
	msgbox SootopolisCity_PokemonCenter_1F_Text_EveryoneTakenRefuge, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_GentlemanNoLegendaries::
	msgbox SootopolisCity_PokemonCenter_1F_Text_WallaceToughestInHoenn, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_Woman::
	lock
	faceplayer
	goto_if_ge VAR_SKY_PILLAR_STATE, 2, SootopolisCity_PokemonCenter_1F_EventScript_WomanNoLegendaries
	goto_if_unset FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN, SootopolisCity_PokemonCenter_1F_EventScript_WomanNoLegendaries
	msgbox SootopolisCity_PokemonCenter_1F_Text_ArentPokemonOurFriends, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_EventScript_WomanNoLegendaries::
	msgbox SootopolisCity_PokemonCenter_1F_Text_AlwaysBeFriendsWithPokemon, MSGBOX_DEFAULT
	release
	end

SootopolisCity_PokemonCenter_1F_Text_WallaceToughestInHoenn:
	.string "On dit que ALIZA est le DRESSEUR\n"
	.string "le plus coriace de toute la région\p"
	.string "de HOENN.\n"
	.string "L'ARÈNE de cette ville est dirigée\p"
	.string "par le DRESSEUR qui a formé ALIZA.\n"
	.string "Mais le CONSEIL DES 4… On dit\p"
	.string "qu'ils sont encore plus forts que le mentor d'ALIZA. À quel point peuvent-ils être forts ?$"

SootopolisCity_PokemonCenter_1F_Text_EveryoneTakenRefuge:
	.string "Tout le monde en ville s'est\n"
	.string "réfugié et ne sort pas de\p"
	.string "chez lui. Moi aussi, je\n"
	.string "préférerais ne pas m'aventurer dehors.$"

SootopolisCity_PokemonCenter_1F_Text_AlwaysBeFriendsWithPokemon:
	.string "Quoi qu'il arrive, où que ce\n"
	.string "soit, je serai toujours ami avec\l"
	.string "les POKéMON. Parce que c'est amusant\p"
	.string "d'être avec des POKéMON !$"

SootopolisCity_PokemonCenter_1F_Text_ArentPokemonOurFriends:
	.string "Les POKéMON ne sont-ils pas nos amis ?\p"
	.string "Pourquoi deviennent-ils fous comme ça ?$"

