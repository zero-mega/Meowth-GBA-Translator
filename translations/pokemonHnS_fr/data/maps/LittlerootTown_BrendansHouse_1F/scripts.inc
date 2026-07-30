.set LOCALID_MOM, 1
.set LOCALID_RIVAL_MOM, 4
.set LOCALID_RIVAL, 7

LittlerootTown_BrendansHouse_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, LittlerootTown_BrendansHouse_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_BrendansHouse_1F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_BrendansHouse_1F_OnFrame
	.byte 0

LittlerootTown_BrendansHouse_1F_OnLoad:
	call_if_lt VAR_GARBAGEVAR, 6, LittlerootTown_BrendansHouse_1F_EventScript_SetMovingBoxes
	call_if_set FLAG_RECEIVED_RUNNING_SHOES, LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual
	end

LittlerootTown_BrendansHouse_1F_EventScript_SetMovingBoxes::
	setmetatile 5, 4, METATILE_BrendansMaysHouse_MovingBox_Open, TRUE
	setmetatile 5, 2, METATILE_BrendansMaysHouse_MovingBox_Closed, TRUE
	return

LittlerootTown_BrendansHouse_1F_EventScript_CheckShowShoesManual::
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual
	return

LittlerootTown_BrendansHouse_1F_EventScript_ShowRunningShoesManual::
	setmetatile 3, 7, METATILE_BrendansMaysHouse_BookOnTable, TRUE
	return

LittlerootTown_BrendansHouse_1F_OnTransition:
	call_if_eq VAR_GARBAGEVAR, 3, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToDoor
	call_if_eq VAR_GARBAGEVAR, 5, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToStairs
	call_if_eq VAR_GARBAGEVAR, 6, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToTV
	end

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToStairs::
	setobjectxyperm LOCALID_MOM, 8, 4
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToTV::
	setobjectxyperm LOCALID_MOM, 4, 5
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToDoor::
	setobjectxyperm LOCALID_MOM, 9, 8
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_UP
	return

@ Many of the below scripts have no gender check because they assume youre in the correct house
@ The below SS Ticket script uses Mays house state by accident(?), but theyre both set identically after the intro
LittlerootTown_BrendansHouse_1F_OnFrame:
	map_script_2 VAR_GARBAGEVAR, 3, LittlerootTown_BrendansHouse_1F_EventScript_EnterHouseMovingIn
	map_script_2 VAR_GARBAGEVAR, 5, LittlerootTown_BrendansHouse_1F_EventScript_GoUpstairsToSetClock
	map_script_2 VAR_GARBAGEVAR, 6, LittlerootTown_BrendansHouse_1F_EventScript_PetalburgGymReport
	map_script_2 VAR_GARBAGEVAR, 1, LittlerootTown_BrendansHouse_1F_EventScript_YoureNewNeighbor
	map_script_2 VAR_GARBAGEVAR, 3, PlayersHouse_1F_EventScript_GetSSTicketAndSeeLatiTV
	.2byte 0

LittlerootTown_BrendansHouse_1F_EventScript_GoUpstairsToSetClock::
	lockall
	msgbox PlayersHouse_1F_Text_GoSetTheClock, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs
	applymovement LOCALID_MOM, LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs
	waitmovement 0
	warp MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F, 7, 1
	waitstate
	releaseall
	end

LittlerootTown_BrendansHouse_1F_Movement_PushTowardStairs:
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_EnterHouseMovingIn::
	lockall
	setvar VAR_0x8004, LOCALID_MOM
	setvar VAR_0x8005, MALE
	goto PlayersHouse_1F_EventScript_EnterHouseMovingIn
	end

LittlerootTown_BrendansHouse_1F_EventScript_PetalburgGymReport::
	lockall
	setvar VAR_0x8004, MALE
	setvar VAR_0x8005, LOCALID_MOM
	goto PlayersHouse_1F_EventScript_PetalburgGymReportMale
	end

LittlerootTown_BrendansHouse_1F_EventScript_YoureNewNeighbor::
	lockall
	playse SE_PIN
	applymovement LOCALID_RIVAL_MOM, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL_MOM, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_RIVAL_MOM, LittlerootTown_BrendansHouse_1F_Movement_RivalMomApproach
	waitmovement 0
	special GetRivalSonDaughterString
	msgbox RivalsHouse_1F_Text_OhYoureTheNewNeighbor, MSGBOX_DEFAULT
	setflag FLAG_MET_RIVAL_MOM
	setvar VAR_GARBAGEVAR, 2
	releaseall
	end

LittlerootTown_BrendansHouse_1F_Movement_RivalMomApproach:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_GoSeeRoom::
	lockall
	setvar VAR_0x8004, LOCALID_MOM
	setvar VAR_0x8005, MALE
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	goto PlayersHouse_1F_EventScript_MomGoSeeRoom
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival0::
	lockall
	setvar VAR_0x8008, 0
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival1::
	lockall
	setvar VAR_0x8008, 1
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival2::
	lockall
	setvar VAR_0x8008, 2
	goto LittlerootTown_BrendansHouse_1F_EventScript_MeetRival
	end

LittlerootTown_BrendansHouse_1F_EventScript_MeetRival::
	playse SE_EXIT
	delay 10
	addobject LOCALID_RIVAL
	delay 30
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	call_if_ne VAR_0x8008, 1, LittlerootTown_BrendansHouse_1F_EventScript_PlayerFaceBrendan
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	call_if_eq VAR_0x8008, 0, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer0
	call_if_eq VAR_0x8008, 1, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer1
	call_if_eq VAR_0x8008, 2, LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer2
	msgbox RivalsHouse_1F_Text_BrendanWhoAreYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 0, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs0
	call_if_eq VAR_0x8008, 1, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs1
	call_if_eq VAR_0x8008, 2, LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs2
	playse SE_EXIT
	removeobject LOCALID_RIVAL
	setflag FLAG_GARBAGEFLAG
	setflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	delay 30
	setvar VAR_GARBAGEVAR, 3
	setvar VAR_GARBAGEVAR, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LittlerootTown_BrendansHouse_1F_EventScript_PlayerFaceBrendan::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer0::
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer0
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer1::
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer1
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanApproachPlayer2::
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer2
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer0:
	walk_in_place_faster_left
	walk_left
	walk_in_place_faster_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer1:
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanApproachPlayer2:
	walk_in_place_faster_right
	walk_right
	walk_in_place_faster_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs0::
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit0
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs0
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs1::
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit1
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs1
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_BrendanGoUpstairs2::
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit2
	applymovement LOCALID_RIVAL, LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs2
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit0:
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit1:
	delay_16
	delay_8
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_PlayerWatchBrendanExit2:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs0:
	walk_in_place_faster_right
	walk_right
	walk_in_place_faster_up
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs1:
	walk_in_place_faster_right
	walk_right
	walk_in_place_faster_up
	walk_up
	walk_up
	walk_in_place_faster_left
	walk_left
	walk_in_place_faster_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_BrendanGoUpstairs2:
	walk_in_place_faster_left
	walk_left
	walk_in_place_faster_up
	walk_up
	walk_up
	step_end

PlayersHouse_1F_Text_IsntItNiceInHere:
	.string "MAMAN : Tu vois, {PLAYER} ?\n"
	.string "C'est agréable ici aussi, non ?$"

PlayersHouse_1F_Text_MoversPokemonGoSetClock:
	.string "Les POKéMON des déménageurs font tout\n"
	.string "le travail de nous installer et\l"
	.string "de nettoyer après. C'est si pratique\p"
	.string "! {PLAYER}, ta chambre est à\n"
	.string "l'étage. Va la voir, mon chéri\p"
	.string "! PAPA t'a acheté une nouvelle\n"
	.string "horloge pour marquer notre emménagement ici.\l"
	.string "N'oublie pas de la régler !$"

PlayersHouse_1F_Text_ArentYouInterestedInRoom:
	.string "MAMAN : Alors, {PLAYER} ?\p"
	.string "Tu n'as pas envie de voir\n"
	.string "ta propre chambre ?$"

PlayersHouse_1F_Text_GoSetTheClock:
	.string "MAMAN : {PLAYER}.\p"
	.string "Va régler l'horloge dans ta chambre, chéri.$"

PlayersHouse_1F_Text_OhComeQuickly:
	.string "MAMAN : Oh ! {PLAYER}, {PLAYER} !\n"
	.string "Vite ! Viens vite !$"

PlayersHouse_1F_Text_MaybeDadWillBeOn:
	.string "MAMAN : Regarde ! C'est l'ARÈNE de MYOKARA !\n"
	.string "Peut-être que PAPA sera à l'antenne !$"

PlayersHouse_1F_Text_ItsOverWeMissedHim:
	.string "MAMAN : Oh… C'est fini.\p"
	.string "Je crois que PAPA était à l'antenne, mais on l'a raté.\n"
	.string "Dommage.$"

PlayersHouse_1F_Text_GoIntroduceYourselfNextDoor:
	.string "Oh, oui.\n"
	.string "Un des amis de PAPA vit en ville.\p"
	.string "Le PROF. SEKO, c'est son nom.\p"
	.string "Il habite juste à côté, tu devrais\n"
	.string "aller te présenter.$"

PlayersHouse_1F_Text_SeeYouHoney:
	.string "MAMAN : À plus tard, mon chéri !$"

PlayersHouse_1F_Text_DidYouMeetProfBirch:
	.string "MAMAN : T'es-tu présenté au\n"
	.string "PROF. BIRCH ?$"

PlayersHouse_1F_Text_YouShouldRestABit:
	.string "MAMAN : Comment vas-tu, {PLAYER} ?\n"
	.string "Tu as l'air un peu fatigué.\p"
	.string "Je pense que tu devrais te reposer un peu.$"

PlayersHouse_1F_Text_YouShouldRestABit_PokecenterChallenge:
	.string "MAMAN : Désolé chéri, tu joues\n"
	.string "avec le DÉFI POKéCENTER !$"

PlayersHouse_1F_Text_TakeCareHoney:
	.string "MAMAN : Prends soin de toi, mon chéri !$"

PlayersHouse_1F_Text_GotDadsBadgeHeresSomethingFromMom:
	.string "MAMAN : Oh ? PAPA t'a donné ce BADGE ?\p"
	.string "Alors voici quelque chose de ta MAMAN !$"

PlayersHouse_1F_Text_DontPushYourselfTooHard:
	.string "Ne te surmène pas, mon chéri.\n"
	.string "Tu peux toujours rentrer à la maison.\p"
	.string "Fonce, chéri !$"

PlayersHouse_1F_Text_IsThatAPokenav:
	.string "MAMAN : Qu'est-ce que c'est, chéri ? Un POKéNAV ?\n"
	.string "Quelqu'un de DEVON te l'a donné ?\p"
	.string "Eh bien, chéri, et si tu enregistrais\n"
	.string "ta maman ?\p"
	.string "… … …$"

PlayersHouse_1F_Text_RegisteredMom:
	.string "MAMAN a été enregistrée\n"
	.string "dans le POKéNAV.$"

PlayersHouse_1F_Text_Vigoroth1:
	.string "Fugiiiiih !$"

PlayersHouse_1F_Text_Vigoroth2:
	.string "Huggoh, uggo uggo…$"

PlayersHouse_1F_Text_ReportFromPetalburgGym:
	.string "JOURNALISTE : …Nous vous apportons ce reportage\n"
	.string "devant l'ARÈNE de PETALBURG.$"

PlayersHouse_1F_Text_TheresAMovieOnTV:
	.string "Il y a un film à la télé.\p"
	.string "Deux hommes dansent sur un grand\n"
	.string "clavier de piano.\p"
	.string "Il vaut mieux y aller !$"

PlayersHouse_1F_Text_RunningShoesManual:
	.string "C'est le manuel d'instructions des\n"
	.string "CHAUSSURES DE COURSE.\p"
	.string "“Appuie sur le bouton B pour courir en\n"
	.string "portant tes CHAUSSURES DE COURSE.\p"
	.string "“Lace tes CHAUSSURES DE COURSE et\n"
	.string "pars courir !”$"

PlayersHouse_1F_Text_TicketFromBrineyCameForYou:
	.string "DAD: Hm?\p"
	.string "Hey, it's {PLAYER}!\p"
	.string "It's been a while since I saw you,\n"
	.string "but you look…stronger, somehow.\p"
	.string "That's the impression I get.\n"
	.string "But your old man hasn't given up yet!\p"
	.string "Oh, yes, I have something for you.\n"
	.string "This came to you from someone named\l"
	.string "MR. BRINEY.$"

PlayersHouse_1F_Text_PortsInSlateportLilycove:
	.string "PAPA : Hm, un TICKET pour un ferry ?\p"
	.string "Si je me souviens bien, il y a des ports de ferry à\n"
	.string "POIVRESSE et LILYGRACE.$"

PlayersHouse_1F_Text_BetterGetBackToGym:
	.string "Je ferais mieux de retourner à l'ARÈNE de POIVRESSAMBURG.\p"
	.string "MAMAN, merci de t'occuper de la maison\n"
	.string "pendant mon absence.$"

PlayersHouse_1F_Text_DadShouldStayLonger:
	.string "MAMAN : Ce PAPA à toi…\p"
	.string "Il rentre pour la première fois depuis longtemps,\n"
	.string "mais il ne parle que de POKéMON.\p"
	.string "Il devrait se détendre et rester un peu plus longtemps.$"

PlayersHouse_1F_Text_IsThatABreakingStory:
	.string "MAMAN : C'est une info de dernière minute ?$"

PlayersHouse_1F_Text_LatiEmergencyNewsFlash:
	.string "Nous vous apportons ce flash\n"
	.string "d'information d'urgence ! Dans divers\p"
	.string "endroits de HOENN, il y\n"
	.string "a eu des signalements\l"
	.string "d'un POKéMON BZZT… de\p"
	.string "couleur en vol. L'identité\n"
	.string "de ce POKéMON est\p"
	.string "actuellement inconnue. Nous reprenons\n"
	.string "maintenant le programme habituel.$"

PlayersHouse_1F_Text_WhatColorDidTheySay:
	.string "MAMAN : {PLAYER}, tu as entendu ?\p"
	.string "De quelle couleur l'animateur a dit\n"
	.string "que ce POKéMON était ?$"

PlayersHouse_1F_Text_StillUnknownPokemon:
	.string "MAMAN : Eh bien, c'est quelque chose !\n"
	.string "Il y a encore des POKéMON inconnus.$"

