.set LOCALID_WALLY_ENTRANCE, 4

VictoryRoad_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VictoryRoad_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

VictoryRoad_1F_OnTransition:
	callnative SetTimeBasedEncounters
	call_if_eq VAR_VICTORY_ROAD_1F_STATE, 1, VictoryRoad_1F_EventScript_SetEntranceWallyPos1
	call_if_eq VAR_VICTORY_ROAD_1F_STATE, 2, VictoryRoad_1F_EventScript_SetEntranceWallyPos2
	end

VictoryRoad_1F_EventScript_SetEntranceWallyPos1::
	setobjectxyperm LOCALID_WALLY_ENTRANCE, 2, 24
	setobjectmovementtype LOCALID_WALLY_ENTRANCE, MOVEMENT_TYPE_FACE_DOWN
	return

VictoryRoad_1F_EventScript_SetEntranceWallyPos2::
	setobjectxyperm LOCALID_WALLY_ENTRANCE, 3, 24
	setobjectmovementtype LOCALID_WALLY_ENTRANCE, MOVEMENT_TYPE_FACE_DOWN
	return

VictoryRoad_1F_EventScript_WallyBattleTrigger1::
	lockall
	setvar VAR_0x8008, 1
	addobject LOCALID_WALLY_ENTRANCE
	applymovement LOCALID_WALLY_ENTRANCE, VictoryRoad_1F_Movement_WallyApproachPlayer1
	waitmovement 0
	goto VictoryRoad_1F_EventScript_WallyEntranceBattle
	end

VictoryRoad_1F_EventScript_WallyBattleTrigger2::
	lockall
	setvar VAR_0x8008, 2
	addobject LOCALID_WALLY_ENTRANCE
	applymovement LOCALID_WALLY_ENTRANCE, VictoryRoad_1F_Movement_WallyApproachPlayer2
	waitmovement 0
	goto VictoryRoad_1F_EventScript_WallyEntranceBattle
	end

VictoryRoad_1F_EventScript_WallyEntranceBattle::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox VictoryRoad_1F_Text_WallyNotGoingToLoseAnymore, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLY_VR_1, VictoryRoad_1F_Text_WallyEntranceDefeat
	msgbox VictoryRoad_1F_Text_WallyPostEntranceBattle, MSGBOX_DEFAULT
	clearflag FLAG_GARBAGEFLAG
	copyobjectxytoperm LOCALID_WALLY_ENTRANCE
	setflag FLAG_DEFEATED_WALLY_VICTORY_ROAD
	copyvar VAR_VICTORY_ROAD_1F_STATE, VAR_0x8008
	releaseall
	end

VictoryRoad_1F_Movement_WallyApproachPlayer1:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

VictoryRoad_1F_Movement_WallyApproachPlayer2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

@ This Wally appears near the entrance once his battle is triggered and remains there until the Hall of Fame is entered
VictoryRoad_1F_EventScript_EntranceWally::
	msgbox VictoryRoad_1F_Text_WallyPostEntranceBattle, MSGBOX_NPC
	end

@ This Wally appears and remains at the exit after the Hall of Fame is entered
VictoryRoad_1F_EventScript_ExitWally::
	trainerbattle_single TRAINER_WALLY_VR_2, VictoryRoad_1F_Text_WallyIntro, VictoryRoad_1F_Text_WallyDefeat
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, VictoryRoad_1F_EventScript_RematchWally
	msgbox VictoryRoad_1F_Text_WallyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_RematchWally::
	trainerbattle_rematch TRAINER_WALLY_VR_2, VictoryRoad_1F_Text_WallyIntro, VictoryRoad_1F_Text_WallyDefeat
	msgbox VictoryRoad_1F_Text_WallyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Edgar::
	trainerbattle_single TRAINER_EDGAR, VictoryRoad_1F_Text_EdgarIntro, VictoryRoad_1F_Text_EdgarDefeat
	msgbox VictoryRoad_1F_Text_EdgarPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Albert::
	trainerbattle_single TRAINER_ALBERT, VictoryRoad_1F_Text_AlbertIntro, VictoryRoad_1F_Text_AlbertDefeat
	msgbox VictoryRoad_1F_Text_AlbertPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Hope::
	trainerbattle_single TRAINER_HOPE, VictoryRoad_1F_Text_HopeIntro, VictoryRoad_1F_Text_HopeDefeat
	msgbox VictoryRoad_1F_Text_HopePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Quincy::
	trainerbattle_single TRAINER_QUINCY, VictoryRoad_1F_Text_QuincyIntro, VictoryRoad_1F_Text_QuincyDefeat
	msgbox VictoryRoad_1F_Text_QuincyPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_EventScript_Katelynn::
	trainerbattle_single TRAINER_KATELYNN, VictoryRoad_1F_Text_KatelynnIntro, VictoryRoad_1F_Text_KatelynnDefeat
	msgbox VictoryRoad_1F_Text_KatelynnPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_1F_Text_WallyNotGoingToLoseAnymore:
	.string "WALLY : Salut\p"
	.string "! {PLAYER} !\p"
	.string "Je parie que tu es\n"
	.string "surpris de me voir ici !\p"
	.string "J'ai réussi à arriver\n"
	.string "jusqu'ici, et c'est\p"
	.string "grâce à toi, {PLAYER} !\p"
	.string "Merci pour tout !\n"
	.string "Je vais continuer\p"
	.string "à m'entraîner !$"

VictoryRoad_1F_Text_WallyEntranceDefeat:
	.string "Waouh !\n"
	.string "{PLAYER}, tu es fort, après tout !$"

VictoryRoad_1F_Text_WallyPostEntranceBattle:
	.string "TIMMY : Je n'ai pas pu te battre aujourd'hui,\n"
	.string "{PLAYER}, mais un de ces jours, je te\l"
	.string "rattraperai !$"

VictoryRoad_1F_Text_WallyIntro:
	.string "PETER : Salut ! {PLAYER} ! Je\p"
	.string "suis devenu plus fort depuis la dernière\n"
	.string "fois ! Je voulais te le\p"
	.string "montrer, {PLAYER} ! OK… J'arrive !$"

VictoryRoad_1F_Text_WallyDefeat:
	.string "Waouh !\n"
	.string "{PLAYER}, tu es fort, après tout !$"

VictoryRoad_1F_Text_WallyPostBattle:
	.string "TIMMY : Je n'ai pas pu te battre cette\n"
	.string "fois non plus… Mais un jour, {PLAYER},\l"
	.string "je te rattraperai…\p"
	.string "Et je défierai la LIGUE POKéMON !$"

VictoryRoad_1F_Text_EdgarIntro:
	.string "J'y suis arrivé quelques fois,\n"
	.string "mais le dernier tronçon est si long…$"

VictoryRoad_1F_Text_EdgarDefeat:
	.string "Mon rêve s'arrête encore ici…$"

VictoryRoad_1F_Text_EdgarPostBattle:
	.string "Tu es arrivé jusqu'ici. Garde l'élan\n"
	.string "et deviens le\l"
	.string "CHAMPION ! Si quelqu'un peut le faire, c'est toi !$"

VictoryRoad_1F_Text_AlbertIntro:
	.string "Je ne suis pas venu jusqu'ici pour perdre.\n"
	.string "Cette possibilité n'existe pas !$"

VictoryRoad_1F_Text_AlbertDefeat:
	.string "Impossible…\n"
	.string "J'ai perdu ?$"

VictoryRoad_1F_Text_AlbertPostBattle:
	.string "J'ai perdu ici…\p"
	.string "Ça veut dire que je n'ai pas les qualités\n"
	.string "pour devenir le CHAMPION…$"

VictoryRoad_1F_Text_HopeIntro:
	.string "Cette route infinie et rude\n"
	.string "porte bien son nom de VICTOIRE.$"

VictoryRoad_1F_Text_HopeDefeat:
	.string "Ton style de combat est fantastique…$"

VictoryRoad_1F_Text_HopePostBattle:
	.string "Tu sembles avoir le potentiel pour\n"
	.string "devenir le CHAMPION.$"

VictoryRoad_1F_Text_QuincyIntro:
	.string "C'est quoi la ROUTE VICTOIRE ?\n"
	.string "Je te le dirai si tu gagnes !$"

VictoryRoad_1F_Text_QuincyDefeat:
	.string "OK !\n"
	.string "Bien joué !$"

VictoryRoad_1F_Text_QuincyPostBattle:
	.string "Traverser cet endroit en sécurité - c'est\n"
	.string "le test final pour tout DRESSEUR visant\n"
	.string "à devenir le CHAMPION POKéMON.\p"
	.string "C'est pourquoi on l'appelle la ROUTE\l"
	.string "VICTOIRE.$"

VictoryRoad_1F_Text_KatelynnIntro:
	.string "Je n'ai rien à dire à quiconque\n"
	.string "est venu si loin. Allez, viens !$"

VictoryRoad_1F_Text_KatelynnDefeat:
	.string "C'est une honte…$"

VictoryRoad_1F_Text_KatelynnPostBattle:
	.string "Humph, vas-y, avance.\n"
	.string "Comme si ça m'intéressait.$"
