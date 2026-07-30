.set LOCALID_ATTENDANT, 1

VerdanturfTown_BattleTentCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VerdanturfTown_BattleTentCorridor_OnFrame
	.byte 0

VerdanturfTown_BattleTentCorridor_OnFrame:
	map_script_2 VAR_TEMP_0, 0, VerdanturfTown_BattleTentCorridor_EventScript_EnterCorridor
	.2byte 0

VerdanturfTown_BattleTentCorridor_EventScript_EnterCorridor::
	lockall
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_ATTENDANT, VerdanturfTown_BattleTentCorridor_Movement_WalkToDoor
	applymovement OBJ_EVENT_ID_PLAYER, VerdanturfTown_BattleTentCorridor_Movement_WalkToDoor
	waitmovement 0
	@opendoor 2, 1
	@waitdooranim
	applymovement LOCALID_ATTENDANT, VerdanturfTown_BattleTentCorridor_Movement_AttendantEnterDoor
	applymovement OBJ_EVENT_ID_PLAYER, VerdanturfTown_BattleTentCorridor_Movement_PlayerEnterDoor
	waitmovement 0
	@closedoor 2, 1
	@waitdooranim
	setvar VAR_0x8006, 0
	warp MAP_VERDANTURF_TOWN_BATTLE_TENT_BATTLE_ROOM, 6, 5
	waitstate
	releaseall
	end

VerdanturfTown_BattleTentCorridor_Movement_WalkToDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

VerdanturfTown_BattleTentCorridor_Movement_PlayerEnterDoor:
	walk_up
VerdanturfTown_BattleTentCorridor_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end


@ Leftover text from when this was a Contest Hall in R/S
@ Unused
VerdanturfTown_ContestHall_Text_WhichContestYouEntering:
	.string "Quel CONCOURS tu vas rejoindre ?\n"
	.string "Tu veux un conseil ? Dans\p"
	.string "n'importe quel CONCOURS, par exemple un\n"
	.string "CONCOURS SÉDUCTION, je ne pense pas\l"
	.string "qu'ils jugent seulement la séduction au\p"
	.string "premier tour. Il faut trouver des\n"
	.string "moyens d'élever mieux les POKéMON.$"

@ Unused
VerdanturfTown_ContestHall_Text_RaisedMonToBeCute:
	.string "J'ai élevé mon POKéMON pour qu'il soit mignon.\p"
	.string "J'ai découvert qu'on peut mettre des POKéMON dans\n"
	.string "un CONCOURS de mignonnerie !\p"
	.string "Je suis si content d'avoir élevé mon POKéMON avec\n"
	.string "tant d'amour…$"

@ Unused
VerdanturfTown_ContestHall_Text_MyMonRules:
	.string "Mes POKéMON sont les meilleurs !\p"
	.string "Ils sont cool, forts, beaux, mignons\n"
	.string "et intelligents. Ils sont parfaits !\p"
	.string "Je pourrais aussi bien viser la victoire\n"
	.string "dans chaque CONCOURS.$"

@ Unused
VerdanturfTown_ContestHall_Text_NormalRankStage:
	.string "CONCOURS POKéMON\n"
	.string "SCÈNE RANG NORMAL !$"

