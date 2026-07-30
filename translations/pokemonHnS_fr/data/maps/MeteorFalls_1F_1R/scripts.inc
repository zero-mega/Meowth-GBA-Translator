.set LOCALID_MAGMA_GRUNT_1, 5
.set LOCALID_MAGMA_GRUNT_2, 6
.set LOCALID_ARCHIE, 7
.set LOCALID_AQUA_GRUNT_1, 8
.set LOCALID_AQUA_GRUNT_2, 9

MeteorFalls_1F_1R_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MeteorFalls_1F_1R_OnLoad
	.byte 0

MeteorFalls_1F_1R_OnLoad:
	call_if_set FLAG_SYS_GAME_CLEAR, MeteorFalls_1F_1R_EventScript_OpenStevensCave
	end

MeteorFalls_1F_1R_EventScript_OpenStevensCave::
	setmetatile 4, 1, METATILE_MeteorFalls_CaveEntrance_Top, TRUE
	setmetatile 3, 2, METATILE_MeteorFalls_CaveEntrance_Left, TRUE
	setmetatile 4, 2, METATILE_MeteorFalls_CaveEntrance_Bottom, FALSE
	setmetatile 5, 2, METATILE_MeteorFalls_CaveEntrance_Right, TRUE
	return

MeteorFalls_1F_1R_EventScript_MagmaStealsMeteoriteScene::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	delay 30
	applymovement LOCALID_MAGMA_GRUNT_1, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_WithThisMeteorite, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAGMA_GRUNT_1, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_MAGMA_GRUNT_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_MAGMA_GRUNT_1, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MAGMA_GRUNT_1, Common_Movement_Delay48
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_DontExpectMercyFromMagma, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAGMA_GRUNT_1, MeteorFalls_1F_1R_Movement_MagmaGruntApproachPlayer
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_HoldItRightThereMagma, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_MAGMA_GRUNT_1, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_MAGMA_GRUNT_2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	addobject LOCALID_ARCHIE
	addobject LOCALID_AQUA_GRUNT_1
	addobject LOCALID_AQUA_GRUNT_2
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_ARCHIE, MeteorFalls_1F_1R_Movement_ArchieArrive
	applymovement LOCALID_AQUA_GRUNT_1, MeteorFalls_1F_1R_Movement_AquaGrunt1Arrive
	applymovement LOCALID_AQUA_GRUNT_2, MeteorFalls_1F_1R_Movement_AquaGrunt2Arrive
	waitmovement 0
	applymovement LOCALID_MAGMA_GRUNT_1, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_MAGMA_GRUNT_2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_BeSeeingYouTeamAqua, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, MeteorFalls_1F_1R_Movement_PushPlayerOutOfWay
	applymovement LOCALID_MAGMA_GRUNT_1, MeteorFalls_1F_1R_Movement_MagmaGrunt1Exit
	applymovement LOCALID_MAGMA_GRUNT_2, MeteorFalls_1F_1R_Movement_MagmaGrunt2Exit
	waitmovement 0
	removeobject LOCALID_MAGMA_GRUNT_1
	removeobject LOCALID_MAGMA_GRUNT_2
	applymovement LOCALID_ARCHIE, MeteorFalls_1F_1R_Movement_ArchieApproachPlayer
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_ArchieSeenYouBefore, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_AQUA_GRUNT_1, MeteorFalls_1F_1R_Movement_AquaGrunt1ApproachArchie
	applymovement LOCALID_AQUA_GRUNT_2, MeteorFalls_1F_1R_Movement_AquaGrunt2ApproachArchie
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_BossWeShouldChaseMagma, MSGBOX_DEFAULT
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_ArchieYesNoTellingWhatMagmaWillDo, MSGBOX_DEFAULT
	applymovement LOCALID_ARCHIE, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox MeteorFalls_1F_1R_Text_ArchieFarewell, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ARCHIE, MeteorFalls_1F_1R_Movement_ArchieExit
	applymovement LOCALID_AQUA_GRUNT_1, MeteorFalls_1F_1R_Movement_AquaGrunt1Exit
	applymovement LOCALID_AQUA_GRUNT_2, MeteorFalls_1F_1R_Movement_AquaGrunt2Exit
	waitmovement 0
	fadedefaultbgm
	removeobject LOCALID_ARCHIE
	removeobject LOCALID_AQUA_GRUNT_1
	removeobject LOCALID_AQUA_GRUNT_2
	setflag FLAG_GARBAGEFLAG
	setflag FLAG_MET_ARCHIE_METEOR_FALLS
	setflag FLAG_GARBAGEFLAG
	setvar VAR_METEOR_FALLS_STATE, 1
	releaseall
	end

MeteorFalls_1F_1R_Movement_MagmaGruntApproachPlayer:
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

MeteorFalls_1F_1R_Movement_MagmaGrunt1Exit:
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

MeteorFalls_1F_1R_Movement_MagmaGrunt2Exit:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

MeteorFalls_1F_1R_Movement_ArchieArrive:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt1Arrive:
	delay_16
	delay_16
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt2Arrive:
	delay_16
	delay_16
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_ArchieExit:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_ArchieApproachPlayer:
	walk_right
	walk_right
	walk_up
	walk_up
	walk_in_place_faster_left
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt1Exit:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt1ApproachArchie:
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt2Exit:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MeteorFalls_1F_1R_Movement_AquaGrunt2ApproachArchie:
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

MeteorFalls_1F_1R_Movement_PushPlayerOutOfWay:
	walk_in_place_faster_down
	delay_4
	walk_in_place_faster_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	face_right
	step_end

MeteorFalls_1F_1R_EventScript_ProfCozmo::
	lock
	faceplayer
	goto_if_set FLAG_MET_PROF_COZMO, MeteorFalls_1F_1R_EventScript_MetCozmo
	setflag FLAG_MET_PROF_COZMO
	msgbox MeteorFalls_1F_1R_Text_MeetProfCozmo, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_1R_EventScript_MetCozmo::
	msgbox MeteorFalls_1F_1R_Text_WhatsTeamMagmaDoingAtMtChimney, MSGBOX_DEFAULT
	release
	end

MeteorFalls_1F_1R_Text_WithThisMeteorite:
	.string "Héhéhé !\p"
	.string "Avec ce MÉTÉORITE, cette chose au\n"
	.string "MONT CHIMNÉE va…$"

MeteorFalls_1F_1R_Text_DontExpectMercyFromMagma:
	.string "Hein ?\p"
	.string "Je ne sais pas qui tu es, mais si tu te mets\n"
	.string "en travers de la TEAM MAGMA, n'attends\l"
	.string "aucune pitié !$"

MeteorFalls_1F_1R_Text_HoldItRightThereMagma:
	.string "Halte là, TEAM MAGMA !\p"
	.string "Vous vous trompez lourdement si vous\n"
	.string "croyez pouvoir faire ce que vous voulez !$"

MeteorFalls_1F_1R_Text_BeSeeingYouTeamAqua:
	.string "Héhéhé ! Même la TEAM\n"
	.string "AQUA nous rejoint ! Mais\p"
	.string "c'est trop galère de s'occuper\n"
	.string "de vous tous… Hé, peu\p"
	.string "importe ! On a la\p"
	.string "MÉTÉORITE, alors direction le MONT\n"
	.string "CHIMNÉE ! Héhéhé ! À\p"
	.string "bientôt, bande de nigauds de\n"
	.string "la TEAM AQUA !$"

MeteorFalls_1F_1R_Text_ArchieSeenYouBefore:
	.string "ARCHIE : Je ne t'avais pas déjà vu ?\n"
	.string "Au MUSÉE de POIVRESSE ?\p"
	.string "Ah, tu t'appelles donc {PLAYER}.\p"
	.string "À l'époque, je pensais que tu étais un des\n"
	.string "hommes de la TEAM MAGMA.\p"
	.string "Humph…\n"
	.string "Tu es un drôle de gamin.\p"
	.string "La TEAM MAGMA est un groupe dangereux\n"
	.string "de fanatiques totaux.\p"
	.string "Ils s'adonnent à la destruction, prétendant\n"
	.string "agrandir la masse terrestre.\p"
	.string "Ce sont nos rivaux,\n"
	.string "nous, la TEAM AQUA qui aime la mer !$"

MeteorFalls_1F_1R_Text_BossWeShouldChaseMagma:
	.string "BOSS, nous devrions poursuivre\n"
	.string "la TEAM MAGMA…$"

MeteorFalls_1F_1R_Text_ArchieYesNoTellingWhatMagmaWillDo:
	.string "ARCHIE : Oui, oui, il le faut !\n"
	.string "Il faut se dépêcher.\p"
	.string "On ne sait pas ce que la TEAM MAGMA\n"
	.string "va faire au MONT CHIMÈRE !$"

MeteorFalls_1F_1R_Text_ArchieFarewell:
	.string "ARCHIE : {PLAYER}, tu devrais aussi garder\n"
	.string "un oeil sur la TEAM MAGMA.\p"
	.string "Adieu !$"

MeteorFalls_1F_1R_Text_MeetProfCozmo:
	.string "I… I'm COZMO…\n"
	.string "I'm a PROFESSOR…\p"
	.string "TEAM MAGMA asked me to guide them\n"
	.string "to METEOR FALLS…\p"
	.string "But they tricked me.\n"
	.string "They even took my METEORITE away…\p"
	.string "And then another similar bunch,\n"
	.string "TEAM AQUA showed up.\p"
	.string "After that…\n"
	.string "I don't understand any of it.\p"
	.string "But that TEAM MAGMA…\p"
	.string "What are they going to do with that\n"
	.string "METEORITE at MT. CHIMNEY?$"

MeteorFalls_1F_1R_Text_WhatsTeamMagmaDoingAtMtChimney:
	.string "PROF. KOSMO : Mais cette TEAM MAGMA...\p"
	.string "Qu'est-ce qu'ils vont faire de cette\n"
	.string "MÉTÉORITE au MONT CHIMÈRE ?$"
