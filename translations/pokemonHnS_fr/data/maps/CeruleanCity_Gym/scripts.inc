.set LOCALID_CERULEAN_GYM_ROCKET, 5

CeruleanCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeruleanCity_Gym_OnFrame
	.byte 0

CeruleanCity_Gym_OnFrame::
	map_script_2 VAR_KANTO_ROCKET_STORY_STATE, 2,  CeruleanCity_Gym_EventScript_RocketGrunt
	map_script_2 VAR_TEMP_0, 0,  CeruleanCity_Gym_EventScript_TryMachinePart
	.2byte 0

CeruleanCity_Gym_EventScript_RocketGrunt::
	lock
	applymovement LOCALID_CERULEAN_GYM_ROCKET, CeruleanCity_Gym_Movement_GruntBumpPlayer
	delay 20
	playse SE_BANG
	waitmovement 0
	
	msgbox CeruleanGym_Text_GruntIntro, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_CERULEAN_GYM_ROCKET, Common_Movement_ExclamationMark
	delay 60
	applymovement LOCALID_CERULEAN_GYM_ROCKET, CeruleanCity_Gym_Movement_GruntWalkBack
	waitmovement 0
	msgbox CeruleanGym_Text_GruntBigMistake, MSGBOX_DEFAULT
	applymovement LOCALID_CERULEAN_GYM_ROCKET, CeruleanCity_Gym_Movement_GruntWalkToPlayerAgain
	waitmovement 0
	msgbox CeruleanGym_Text_GruntBye, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, CeruleanCity_Gym_Movement_PlayerSlide
	delay 10
	applymovement LOCALID_CERULEAN_GYM_ROCKET, CeruleanCity_Gym_Movement_GruntLeave
	waitmovement 0
	fadescreenswapbuffers FADE_TO_BLACK
	playse SE_EXIT
	setflag FLAG_HIDE_CERULEAN_GYM_ROCKET
	removeobject LOCALID_CERULEAN_GYM_ROCKET
	fadescreenswapbuffers FADE_FROM_BLACK
	clearflag FLAG_HIDE_CERULEAN_CAPE_ROCKET
	setvar VAR_KANTO_ROCKET_STORY_STATE, 3
	release
	end

CeruleanCity_Gym_EventScript_TryMachinePart::
	goto_if_eq VAR_KANTO_ROCKET_STORY_STATE, 5, CeruleanCity_Gym_EventScript_MachinePart
	setvar VAR_TEMP_0, 1
	end

CeruleanCity_Gym_EventScript_MachinePart::
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, CeruleanCity_Movement_CameraPanUp
	waitmovement 0
	delay 30
	setvar VAR_0x8004, 5  @ x
	setvar VAR_0x8005, 13  @ y
	playse SE_PIN
	call Route110_TrickHouseEntrance_EventScript_DoHidingSpotSparkle
	delay 55
	applymovement OBJ_EVENT_ID_CAMERA, CeruleanCity_Movement_CameraPanDown
	waitmovement 0
	special RemoveCameraObject
	setvar VAR_TEMP_0, 1
	end

CeruleanCity_Gym_EventScript_MachinePartItem::
	goto_if_lt VAR_KANTO_ROCKET_STORY_STATE, 5, CeruleanCity_Gym_EventScript_DoNothing
	goto_if_ge VAR_KANTO_ROCKET_STORY_STATE, 6, CeruleanCity_Gym_EventScript_DoNothing
	finditem ITEM_MACHINE_PART
	setvar VAR_KANTO_ROCKET_STORY_STATE, 6
	setflag FLAG_HIDDEN_ITEM_MACHINE_PART
	end

CeruleanCity_Gym_EventScript_DoNothing::
	end

CeruleanCity_Movement_CameraPanUp:
	walk_up
	walk_up
	walk_up
	step_end

CeruleanCity_Movement_CameraPanDown:
	walk_down
	walk_down
	walk_down
	step_end

CeruleanCity_Gym_Movement_GruntBumpPlayer:
	walk_fast_down
	walk_fast_down
	walk_in_place_fast_down
	lock_facing_direction
	jump_up
	unlock_facing_direction
	delay_16
	walk_down
	step_end

CeruleanCity_Gym_Movement_GruntWalkBack:
	lock_facing_direction
	walk_slow_up
	walk_slow_up
	unlock_facing_direction
	step_end

CeruleanCity_Gym_Movement_GruntWalkToPlayerAgain:
	walk_down
	walk_down
	step_end

CeruleanCity_Gym_Movement_PlayerSlide:
	lock_facing_direction
	walk_fast_right
	unlock_facing_direction
	step_end

CeruleanCity_Gym_Movement_GruntLeave:
	walk_fast_down
	walk_in_place_fast_down
	step_end

CeruleanCity_Gym_EventScript_Statue::
	lockall
	goto_if_set FLAG_BADGE10_GET, CeruleanCity_Gym_EventScript_GymStatuePostVictory
	msgbox CeruleanCity_Gym_Text_GymStatue
	releaseall
	end

CeruleanCity_Gym_EventScript_StatueDuringRocket::
	msgbox CeruleanGym_Text_Note, MSGBOX_SIGN
	end 

CeruleanCity_Gym_EventScript_GymStatuePostVictory::
	msgbox CeruleanCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

CeruleanGym_EventScript_Diana::
	trainerbattle_single TRAINER_DIANA CeruleanGym_Text_SwimmerfDianaSeen, CeruleanGym_Text_SwimmerfDianaBeaten
	msgbox CeruleanGym_Text_SwimmerfDianaAfter, MSGBOX_AUTOCLOSE
	end

CeruleanGym_EventScript_Briana::
	trainerbattle_single TRAINER_BRIANA CeruleanGym_Text_SwimmerfBrianaSeen, CeruleanGym_Text_SwimmerfBrianaBeaten
	msgbox CeruleanGym_Text_SwimmerfBrianaAfter, MSGBOX_AUTOCLOSE
	end

CeruleanGym_EventScript_Parker::
	trainerbattle_single TRAINER_PARKER CeruleanGym_Text_SwimmermParkerSeen, CeruleanGym_Text_SwimmermParkerBeaten
	msgbox CeruleanGym_Text_SwimmermParkerAfter, MSGBOX_AUTOCLOSE
	end

CeruleanCity_Gym_EventScript_GymGuy::
	goto_if_set FLAG_DEFEATED_CERULEAN_GYM, CeruleanCity_Gym_EventScript_GymGuyAfter
	msgbox CeruleanGym_Text_GuideIntro, MSGBOX_NPC
	end

CeruleanCity_Gym_EventScript_GymGuyAfter::
	msgbox CeruleanGym_Text_GuideWin, MSGBOX_NPC
	end

CeruleanCity_Gym_Text_GymStatue::
    .string "AZURIA ARENE POKéMON\n"
    .string "CHAMPIONNE : ONDINE\p"
    .string "DRESSEURS VAINQUEURS :\n"
    .string "BLUE, RED$"

CeruleanCity_Gym_Text_GymStatuePlayerWon::
    .string "ARÈNE POKéMON D'AZURIA\n"
    .string "CHAMPIONNE D'ARÈNE : ONDINE\p"
    .string "DRESSEURS VAINQUEURS :\n"
    .string "BLEU, ROUGE, {PLAYER}$"

CeruleanGym_Text_Note:
	.string "Désolé, je serai absent un moment.\n"
	.string "ONDINE, CHAMPIONNE D'ARÈNE\p"
	.string "Comme ONDINE est absente, nous serons\n"
	.string "absents aussi.\l"
	.string "DRESSEURS D'ARÈNE$"


CeruleanCity_Gym_EventScript_Misty::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_CERULEAN_GYM, CeruleanCity_Gym_EventScript_Misty_Defeated
	msgbox CeruleanGym_Text_MistyIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MISTY, CeruleanGym_Text_MistyWinLoss
	message CeruleanGym_Text_ReceivedBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	setflag FLAG_BADGE10_GET
	setflag FLAG_DEFEATED_CERULEAN_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 10
	call Common_EventScript_SetGymTrainers
	msgbox CeruleanGym_Text_MistyTm, MSGBOX_DEFAULT
	giveitem ITEM_TM_WATER_PULSE
	clearflag FLAG_HIDE_CAPE_MISTY
	call_if_eq VAR_SUICUNE_ENCOUNTERS, 5, CeruleanCity_Gym_SetSuicuneScene
	closemessage
	release
	end

CeruleanCity_Gym_SetSuicuneScene::
	setvar VAR_SUICUNE_ENCOUNTERS, 6
	clearflag FLAG_HIDE_ROUTE25_SUICUNE
	return

CeruleanCity_Gym_EventScript_Misty_Defeated::
	msgbox CeruleanGym_Text_MistyFightDone, MSGBOX_DEFAULT
	closemessage
	release
	end

CeruleanGym_Text_GruntIntro:
	.string "Oups ! Désolé ! Tu n'es pas\n"
	.string "blessé, hein ? Je suis très\p"
	.string "occupé. Pas le temps de parler\n"
	.string "avec toi. Pas bon pour moi\l"
	.string "si on me voit avec quelqu'un.$"

CeruleanGym_Text_GruntBigMistake:
	.string "Oh non ! Tu m'as déjà vue !\n"
	.string "J'ai fait une grosse erreur !$"

CeruleanGym_Text_GruntBye:
	.string "Hé, toi ! Oublie que tu m'as vu,\n"
	.string "d'accord ?\p"
	.string "Tu ne vois, n'entends et ne sais rien,\p"
	.string "OK ? Salut, gamin ! Rien !\p"
	.string "À plus, à plus !$"

CeruleanGym_Text_Note1:
	.string "Désolé, je serai absent un moment.\n"
	.string "ONDINE, CHAMPIONNE D'ARÈNE\p"
	.string "Comme ONDINE est absente, nous serons\n"
	.string "absents aussi. DRESSEURS D'ARÈNE$"

CeruleanGym_Text_MistyIntro:
	.string "ONDINE : Je t'attendais,\n"
	.string "petit peste !\p"
	.string "Tu as peut-être beaucoup de BADGES\n"
	.string "D'ARENE de JOHTO, mais tu ferais mieux\l"
	.string "de ne pas me sous-estimer.\p"
	.string "Mes POKéMON de type EAU\n"
	.string "sont costauds !$"

CeruleanGym_Text_MistyWinLoss:
	.string "ONDINE : Tu es vraiment fort…\p"
	.string "Je reconnais que tu es doué…\p"
	.string "Tiens. C'est le BADGE CASCADE.$"

CeruleanGym_Text_ReceivedBadge:
	.string "{PLAYER} a reçu le BADGE CASCADE.$"

CeruleanGym_Text_MistyFightDone:
	.string "ONDINE : Y a-t-il beaucoup de DRESSEURS\n"
	.string "forts à JOHTO ? Comme toi, je\l"
	.string "veux dire.\p"
	.string "Je voyagerai un jour pour\n"
	.string "affronter des DRESSEURS\l"
	.string "habiles.$"

CeruleanGym_Text_MistyRematch:
	.string "ONDINE : Wow, tu es le CHAMPION\n"
	.string "de KANTO maintenant !\p"
	.string "C'est incroyable ! Tu es allé\n"
	.string "loin, {PLAYER}.\p"
	.string "Mais je ne recule pas.\p"
	.string "Tu veux avoir une revanche avec moi ?$"

CeruleanGym_Text_MistyRematchDefeat:
	.string "ONDINE : Tu es vraiment fort…$"

CeruleanGym_Text_SwimmerfDianaSeen:
	.string "Désolée d'avoir été absente.\n"
	.string "Allons-y !$"

CeruleanGym_Text_SwimmerfDianaBeaten:
	.string "J'abandonne ! Tu as gagné !$"

CeruleanGym_Text_SwimmerfDianaAfter:
	.string "Je vais nager tranquillement.$"

CeruleanGym_Text_SwimmerfBrianaSeen:
	.string "Ne te laisse pas troubler\n"
	.string "par ma nage élégante.$"

CeruleanGym_Text_SwimmerfBrianaBeaten:
	.string "Ooh, tu t'es débarrassé de moi sans problème…$"

CeruleanGym_Text_SwimmerfBrianaAfter:
	.string "Ne te vante pas trop de m'avoir\n"
	.string "battu.\p"
	.string "ONDINE te détruira si tu\n"
	.string "reposes sur tes lauriers.$"

CeruleanGym_Text_SwimmermParkerSeen:
	.string "Gloub…\p"
	.string "Je suis le premier ! Viens me chercher !$"

CeruleanGym_Text_SwimmermParkerBeaten:
	.string "C'est pas possible…$"

CeruleanGym_Text_SwimmermParkerAfter:
	.string "ONDINE s'est beaucoup améliorée\n"
	.string "ces dernières années.\p"
	.string "Ne baisse pas ta garde, sinon\n"
	.string "tu seras écrasé !$"

CeruleanGym_Text_GuideIntro:
	.string "Yo ! Futur CHAMPION !\p"
	.string "Comme ONDINE était absente, je suis sorti\p"
	.string "me divertir aussi. Hé-hé-hé.$"

CeruleanGym_Text_GuideWin:
	.string "Hoo, tu m'as montré à quel point tu es\n"
	.string "fort.\p"
	.string "Comme toujours, c'était un sacré\n"
	.string "combat !$"

CeruleanGym_Text_MistyTm:
	.string "Tiens, prends ça aussi.$"
