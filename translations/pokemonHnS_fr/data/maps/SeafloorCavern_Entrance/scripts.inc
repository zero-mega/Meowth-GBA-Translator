.set LOCALID_GRUNT, 1

SeafloorCavern_Entrance_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, SeafloorCavern_Entrance_OnResume
	.byte 0

SeafloorCavern_Entrance_OnResume:
	setdivewarp MAP_UNDERWATER_SEAFLOOR_CAVERN, 6, 5
	setescapewarp MAP_UNDERWATER_SEAFLOOR_CAVERN, 6, 5
	end

SeafloorCavern_Entrance_EventScript_Grunt::
	lockall
	goto_if_eq VAR_HAS_TALKED_TO_SEAFLOOR_CAVERN_ENTRANCE_GRUNT, 1, SeafloorCavern_Entrance_EventScript_GruntSpeechShort
	waitse
	playse SE_PIN
	applymovement LOCALID_GRUNT, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_GRUNT, Common_Movement_Delay48
	waitmovement 0
	delay 20
	call_if_eq VAR_FACING, DIR_WEST, SeafloorCavern_Entrance_EventScript_GruntFacePlayerWest
	call_if_eq VAR_FACING, DIR_EAST, SeafloorCavern_Entrance_EventScript_GruntFacePlayerEast
	call_if_eq VAR_FACING, DIR_NORTH, SeafloorCavern_Entrance_EventScript_GruntFacePlayerNorth
	delay 30
	setvar VAR_HAS_TALKED_TO_SEAFLOOR_CAVERN_ENTRANCE_GRUNT, 1
	copyobjectxytoperm LOCALID_GRUNT
	msgbox SeafloorCavern_Entrance_Text_HearMagmaNearMossdeep, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	releaseall
	end

SeafloorCavern_Entrance_EventScript_GruntSpeechShort::
	call_if_eq VAR_FACING, DIR_WEST, SeafloorCavern_Entrance_EventScript_GruntFacePlayerWest
	call_if_eq VAR_FACING, DIR_EAST, SeafloorCavern_Entrance_EventScript_GruntFacePlayerEast
	call_if_eq VAR_FACING, DIR_NORTH, SeafloorCavern_Entrance_EventScript_GruntFacePlayerNorth
	msgbox SeafloorCavern_Entrance_Text_HearMagmaNearMossdeepShort, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	releaseall
	end

SeafloorCavern_Entrance_EventScript_GruntFacePlayerEast::
	applymovement LOCALID_GRUNT, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

SeafloorCavern_Entrance_EventScript_GruntFacePlayerWest::
	applymovement LOCALID_GRUNT, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

SeafloorCavern_Entrance_EventScript_GruntFacePlayerNorth::
	applymovement LOCALID_GRUNT, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

SeafloorCavern_Entrance_Text_HearMagmaNearMossdeep:
	.string "Hé !\n"
	.string "Je me souviens de ton visage !\p"
	.string "Si tu es ici, ça veut dire que tu vas\n"
	.string "encore nous embêter !\p"
	.string "Un punk comme toi, tu crois vraiment\n"
	.string "que tu peux affronter la TEAM AQUA ?\p"
	.string "Je dirais que tu es en avance d'environ\n"
	.string "un billion d'années !\p"
	.string "Tu es parfait pour des gens comme\n"
	.string "la TEAM MAGMA !\p"
	.string "En parlant de TEAM MAGMA, j'ai entendu\n"
	.string "qu'ils ont été repérés près d'ATLANPÔLE.\p"
	.string "Cette bande de voyous, ils ont vraiment\n"
	.string "l'air mal à l'aise près de la mer !$"

SeafloorCavern_Entrance_Text_HearMagmaNearMossdeepShort:
	.string "Un punk comme toi,\n"
	.string "tu crois vraiment\p"
	.string "que tu peux affronter\n"
	.string "la TEAM AQUA ?\p"
	.string "Je dirais que tu es\n"
	.string "en avance d'environ\p"
	.string "un billion d'années !\n"
	.string "Mais tu es fort,\p"
	.string "je l'admets.\n"
	.string "Continue comme ça !$"

