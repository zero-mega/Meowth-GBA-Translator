.set LOCALID_NURSE, 1
.set LOCALID_Bill, 4

FallarborTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FallarborTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_FALLARBOR_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

FallarborTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

FallarborTown_PokemonCenter_1F_EventScript_Girl::
	msgbox FallarborTown_PokemonCenter_1F_Text_FossilManiacEdgeOfTown, MSGBOX_NPC
	end

FallarborTown_PokemonCenter_1F_EventScript_ExpertM::
	msgbox FallarborTown_PokemonCenter_1F_Text_PlantHardyTrees, MSGBOX_NPC
	end

FallarborTown_PokemonCenter_1F_EventScript_Bill::
	lock
	faceplayer
	msgbox FallarborTown_PokemonCenter_1F_Text_BillGreeting, MSGBOX_DEFAULT
	closemessage
	switch VAR_FACING
	case DIR_NORTH, FallarborTown_PokemonCenter_1F_EventScript_BillExitNorth
	case DIR_WEST, FallarborTown_PokemonCenter_1F_EventScript_BillExitWest
	end

FallarborTown_PokemonCenter_1F_EventScript_BillExitNorth::
	applymovement LOCALID_Bill, FallarborTown_PokemonCenter_1F_Movement_BillExitNorth
	waitmovement 0
	goto FallarborTown_PokemonCenter_1F_EventScript_BillExited
	end

FallarborTown_PokemonCenter_1F_EventScript_BillExitWest::
	applymovement LOCALID_Bill, FallarborTown_PokemonCenter_1F_Movement_BillExitWest
	waitmovement 0
	goto FallarborTown_PokemonCenter_1F_EventScript_BillExited
	end

FallarborTown_PokemonCenter_1F_EventScript_BillExited::
	playse SE_SLIDING_DOOR
	removeobject LOCALID_Bill
	clearflag FLAG_GARBAGEFLAG
	release
	end

FallarborTown_PokemonCenter_1F_Movement_BillExitNorth:
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

FallarborTown_PokemonCenter_1F_Movement_BillExitWest:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	delay_8
	step_end

FallarborTown_PokemonCenter_1F_Text_BillGreeting:
	.string "Oh, bonjour.\n"
	.string "Vous êtes ?\p"
	.string "D'accord, vous vous appelez {PLAYER}{KUN}.\n"
	.string "Je vois que vous êtes DRESSEUR.\p"
	.string "Donc vous utilisez le Système de Stockage\n"
	.string "POKéMON que j'ai développé.\p"
	.string "Comment j'en suis arrivé à cette conclusion, c'est\n"
	.string "un simple processus de déduction.\p"
	.string "Vous m'avez parlé parce que vous vouliez\n"
	.string "accéder à quelque chose sur ce PC.\p"
	.string "Oh, je suis désolé. Je suis Bill.\p"
	.string "Honnêtement, je suis content de vous rencontrer--\n"
	.string "c'est super que vous utilisiez le Système de Stockage.\p"
	.string "Si vous pouviez, visitez-moi chez moi.\n"
	.string "Ma maison est sur la ROUTE 114.$"

FallarborTown_PokemonCenter_1F_Text_FossilManiacEdgeOfTown:
	.string "Je me demande à quoi ressemblaient\n"
	.string "les POKéMON il y a très longtemps ?\p"
	.string "Peut-être que le MANIAQUE DES FOSSILES\n"
	.string "au bord de la ville le sait.$"

FallarborTown_PokemonCenter_1F_Text_PlantHardyTrees:
	.string "Dans les champs d'AUTÉQUIA, nous plantons\n"
	.string "des jeunes arbres robustes qui survivent\l"
	.string "même dans les cendres volcaniques.$"

