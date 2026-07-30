.set LOCALID_ELM, 2
.set LOCALID_AIDE1, 1
.set LOCALID_AIDE2, 3
.set LOCALID_COP, 7
.set PLAYER_STARTER_SPECIES,  VAR_TEMP_2

NewBarkTown_Lab_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NewBarkTown_Lab_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, NewBarkTown_Lab_OnFrame
	.byte 0

NewBarkTown_Lab_OnTransition::
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 6, NewBarkTown_Lab_EventScript_ElmAtComputer
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 2, NewBarkTown_Lab_EventScript_ElmAtComputer
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 3, NewBarkTown_Lab_EventScript_ElmAtComputer
	end
	
NewBarkTown_Lab_OnFrame::
	map_script_2 VAR_NEWBARKTOWN_LABSTATE, 4, NewBarkTown_Lab_EventScript_PoliceEpisode
	.2byte 0

NewBarkTown_Lab_EventScript_ElmAtComputer::
	setobjectxyperm LOCALID_ELM, 3, 2
	setobjectmovementtype LOCALID_ELM, MOVEMENT_TYPE_FACE_UP
	end

NewBarkTown_Lab_EventScript_TriggerStartLabLeft::	
	lock
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_WalkRight
	waitmovement 0
	goto NewBarkTown_Lab_EventScript_TriggerStartLab
	end

NewBarkTown_Lab_EventScript_TriggerStartLabRight::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_WalkLeft
	waitmovement 0
	goto NewBarkTown_Lab_EventScript_TriggerStartLab
	end

NewBarkTown_Lab_EventScript_TriggerStartLab::
	lock
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_LabMovement_WalkToElm
	waitmovement 0
	goto NewBarkTown_Lab_EventScript_ElmIntro
	end

NewBarkTown_EventScript_Aide1::
	lock
	faceplayer
	msgbox NewBarkTown_Lab_Text_AideAlwaysBusy, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_EventScript_Aide2::
	lock
	faceplayer
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 5, NewBarkTown_EventScript_Aide2Testimony
	msgbox NewBarkTown_Lab_Text_AideSave, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_EventScript_Aide2Testimony::
	msgbox NewBarkTown_Lab_Text_AideTheftTestimony, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_Elm::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_NEWBARKTOWN_LAB_AIDE, NewBarkTown_Lab_EventScript_ElmAideIsWaiting
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 7, NewBarkTown_Lab_EventScript_ElmMasterBall
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 8, NewBarkTown_Lab_EventScript_ElmKimono
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 9, NewBarkTown_Lab_EventScript_ElmLeague
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 10, NewBarkTown_Lab_EventScript_ElmSSTicket

	goto_if_set FLAG_SHOWN_ELM_TOGEPI, NewBarkTown_Lab_EventScript_Elm_CallMe
	call_if_unset FLAG_SHOWN_ELM_TOGEPI, NewBarkTown_Lab_EventScript_Elm_Check_Togepi
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 1, NewBarkTown_Lab_EventScript_Elm_Check_WhereIsEgg
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 5, NewBarkTown_Lab_EventScript_ElmState5

	goto_if_ge VAR_NEWBARKTOWN_LABSTATE, 6, NewBarkTown_Lab_EventScript_ElmState5
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 2, CopNewBarkTown_Lab_EventScript_ElmState2
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 3, CopNewBarkTown_Lab_EventScript_ElmState2
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_MrPokemon
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 1, NewBarkTown_Lab_EventScript_ElmChoosePokemon
	end

NewBarkTown_Lab_EventScript_ElmAideIsWaiting::
	msgbox NewBarkTown_Lab_Text_ElmAideIsWaiting, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_Text_ElmAideIsWaiting:
	.string "{PLAYER} !\p"
	.string "Que fais-tu ici ?\p"
	.string "Mon assistant t'attend toujours\n"
	.string "à MAUVILLE !$"

NewBarkTown_Lab_EventScript_ElmIntro::
	msgbox NewBarkTown_Lab_Text_ElmIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ElmAccepted
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_ElmRefused
	end

NewBarkTown_Lab_EventScript_ElmRefused::
	msgbox NewBarkTown_Lab_Text_ElmRefused, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ElmAccepted
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_ElmRefused
	end

NewBarkTown_Lab_EventScript_ElmAccepted::
	msgbox NewBarkTown_Lab_Text_ElmAccepted, MSGBOX_DEFAULT
	msgbox NewBarkTown_Lab_Text_ElmResearchAmbitions, MSGBOX_DEFAULT
	delay 30
	playse SE_PC_LOGIN
	waitse
	playse SE_PIN
	applymovement LOCALID_ELM, Common_Movement_QuestionMark
	delay 60
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_CheckEmail
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_Look_Left
	waitmovement 0
	waitmovement 0
	msgbox NewBarkTown_Lab_Text_ElmGotAnEmail, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_ReturnFromEmail
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_Look_Up
	waitmovement 0
	delay 30
	msgbox NewBarkTown_Lab_Text_ElmMissionFromMrPokemon, MSGBOX_DEFAULT
	goto NewBarkTown_Lab_EventScript_ElmChoosePokemon
	end

NewBarkTown_Lab_EventScript_ElmChoosePokemon::
	msgbox NewBarkTown_Lab_Text_ElmChooseAPokemon, MSGBOX_DEFAULT
	closemessage
	setvar VAR_NEWBARKTOWN_LABSTATE, 1
	release
	end

NewBarkTown_Lab_EventScript_TriggerReturnPlayer::
	lock
	msgbox NewBarkTown_Lab_Text_ElmWhereGoing, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_ReturnPlayer
	waitmovement 0
	release
	end

NewBarkTown_Lab_EventScript_ShouldntTouch::
	msgbox NewBarkTown_Lab_Text_ShouldntTouch, MSGBOX_DEFAULT
	closemessage
	end


NewBarkTown_Lab_EventScript_ChikoritaBall::
	lock
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_ShouldntTouch
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 1, NewBarkTown_Lab_EventScript_ChikoritaBall_Choice
	msgbox NewBarkTown_Lab_Text_ShouldntTouch, MSGBOX_DEFAULT
	release
	closemessage
	end

NewBarkTown_Lab_EventScript_ChikoritaBall_Choice::
	callnative DisableStaticRandomizer
	setvar VAR_STARTER_MON, 0
	setvar PLAYER_STARTER_SPECIES, SPECIES_CHIKORITA
	showmonpic PLAYER_STARTER_SPECIES, 10, 3
	playmoncry PLAYER_STARTER_SPECIES, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_1, PLAYER_STARTER_SPECIES
	buffermoncategory STR_VAR_2, PLAYER_STARTER_SPECIES
	msgbox NewBarkTown_Lab_Text_ChooseChikorita, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ChoseStarter
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_DeclinedStarter
	end

NewBarkTown_Lab_EventScript_CyndaquilBall::
	lock
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_ShouldntTouch
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 1, NewBarkTown_Lab_EventScript_CyndaquilBall_Choice
	msgbox NewBarkTown_Lab_Text_ShouldntTouch, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_CyndaquilBall_Choice::
	callnative DisableStaticRandomizer
	setvar VAR_STARTER_MON, 1
	setvar PLAYER_STARTER_SPECIES, SPECIES_CYNDAQUIL
	showmonpic PLAYER_STARTER_SPECIES, 10, 3
	playmoncry PLAYER_STARTER_SPECIES, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_1, PLAYER_STARTER_SPECIES
	buffermoncategory STR_VAR_2, PLAYER_STARTER_SPECIES
	msgbox NewBarkTown_Lab_Text_ChooseCyndaquil, MSGBOX_YESNO	
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ChoseStarter
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_DeclinedStarter
	end

NewBarkTown_Lab_EventScript_TotodileBall::
	lock
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_ShouldntTouch
	goto_if_eq VAR_NEWBARKTOWN_LABSTATE, 1, NewBarkTown_Lab_EventScript_TotodileBall_Choice
	msgbox NewBarkTown_Lab_Text_ShouldntTouch, MSGBOX_DEFAULT
	release
	closemessage
	end

NewBarkTown_Lab_EventScript_TotodileBall_Choice::
	callnative DisableStaticRandomizer
	setvar VAR_STARTER_MON, 2
	setvar PLAYER_STARTER_SPECIES, SPECIES_TOTODILE
	showmonpic PLAYER_STARTER_SPECIES, 10, 3
	playmoncry PLAYER_STARTER_SPECIES, CRY_MODE_NORMAL
	bufferspeciesname STR_VAR_1, PLAYER_STARTER_SPECIES
	buffermoncategory STR_VAR_2, PLAYER_STARTER_SPECIES
	msgbox NewBarkTown_Lab_Text_ChooseTotodile, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_ChoseStarter
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_DeclinedStarter
	end

NewBarkTown_Lab_EventScript_DeclinedStarter::
	hidemonpic
	msgbox NewBarkTown_Lab_Text_DidntChooseStarter, MSGBOX_DEFAULT
	closemessage
	callnative EnableStaticRandomizer
	release
	end

NewBarkTown_Lab_EventScript_ChoseStarter::
	callnative EnableStaticRandomizer
	hidemonpic
	removeobject VAR_LAST_TALKED
	msgbox NewBarkTown_Lab_Text_ChoseStarter, MSGBOX_DEFAULT
	givemon PLAYER_STARTER_SPECIES, 5
	setflag FLAG_SYS_POKEMON_GET
	playfanfare MUS_OBTAIN_ITEM
	bufferspeciesname STR_VAR_1, PLAYER_STARTER_SPECIES
	message NewBarkTown_Lab_Text_ReceivedStarter
	waitfanfare
	specialvar VAR_RESULT, IsNuzlockeNicknamingActive
	goto_if_eq VAR_RESULT, TRUE, NewBarkTown_Lab_EventScript_ChoseStarter_NicknameStarter_Nuzlocke
	msgbox NewBarkTown_Lab_Text_Nickname, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_NicknameStarter
	callnative UpdateFollowingPokemon
	release
	end

NewBarkTown_Lab_EventScript_NicknameStarter::
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	end

NewBarkTown_Lab_EventScript_ChoseStarter_NicknameStarter_Nuzlocke::
	message NewBarkTown_Lab_Text_Nickname
	waitmessage
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	release
	end

NewBarkTown_Lab_EventScript_MrPokemon::
	setvar VAR_NEWBARKTOWN_LABSTATE, 2
	setvar VAR_NEWBARK_TOWN_STATE, 3
	msgbox NewBarkTown_Lab_Text_ElmDirections1, MSGBOX_DEFAULT
	setflag FLAG_ENABLE_PROF_BIRCH_MATCH_CALL
	msgbox NewBarkTown_Lab_Text_ElmDirections2, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_FACING, DIR_EAST, NewBarkTown_Lab_EventScript_MrPokemonMovementSafe
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_CheckEmailSlow
	waitmovement 0
	clearflag FLAG_RECEIVED_FIRST_BALLS
	clearflag FLAG_RECEIVED_FIRST_POTION
	setvar VAR_NEWBARK_TOWN_STATE, 3
	release
	end

NewBarkTown_Lab_EventScript_MrPokemonMovementSafe::
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_GotoComputerSafe
	waitmovement 0
	clearflag FLAG_RECEIVED_FIRST_BALLS
	clearflag FLAG_RECEIVED_FIRST_POTION
	setvar VAR_NEWBARK_TOWN_STATE, 3
	release
	end

CopNewBarkTown_Lab_EventScript_ElmState2::
	msgbox NewBarkTown_Lab_Text_ElmDirections1, MSGBOX_DEFAULT
	msgbox NewBarkTown_Lab_Text_ElmDirections2, MSGBOX_DEFAULT
	applymovement LOCALID_ELM, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_HealingMachine1::
	lock
	goto_if_set FLAG_SYS_POKEMON_GET, NewBarkTown_Lab_EventScript_HealingMachine2
	msgbox LittlerootTown_ProfessorBirchsLab_Text_SeriousLookingMachine, MSGBOX_SIGN
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_HealingMachine2::
	call Common_EventScript_OutOfCenterPartyHeal
	release
	end



NewBarkTown_Lab_EventScript_TriggerAideGivePotion::
	lock
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1WalkToPlayer
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox NewBarkTown_Lab_Text_AideGivePotion, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_POTION
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FIRST_POTION
	setvar VAR_NEWBARKTOWN_LABSTATE, 3
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1LeavePlayer
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	release
	end

NewBarkTown_Lab_EventScript_HideCyndaquil::
	setflag FLAG_HIDE_CYNDAQUILBALL
	return
NewBarkTown_Lab_EventScript_HideTotodile::
	setflag FLAG_HIDE_TOTODILEBALL
	return
NewBarkTown_Lab_EventScript_HideChikorita::
	setflag FLAG_HIDE_CHIKORITABALL
	return

NewBarkTown_Lab_EventScript_PoliceEpisode::
	lock
	setmetatile 7, 1, METATILE_R26_21_Broken_Window, TRUE
	call_if_eq VAR_STARTER_MON, 0 NewBarkTown_Lab_EventScript_HideCyndaquil
	call_if_eq VAR_STARTER_MON, 1 NewBarkTown_Lab_EventScript_HideTotodile
	call_if_eq VAR_STARTER_MON, 2 NewBarkTown_Lab_EventScript_HideChikorita
	applymovement OBJ_EVENT_ID_PLAYER, NeBarkTownLab_Movement_PlayerWalkToCop
	waitmovement 0
	setflag FLAG_HIDE_LAB_POLICEMAN
	turnobject LOCALID_COP DIR_WEST
	msgbox NewBarkTown_Lab_Text_Officer1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_PoliceYes
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_PoliceNo
	end

NewBarkTown_Lab_EventScript_PoliceNo::
	msgbox NewBarkTown_Lab_Text_OfficerNo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, NewBarkTown_Lab_EventScript_PoliceYes
	goto_if_eq VAR_RESULT, NO, NewBarkTown_Lab_EventScript_PoliceNo
	end

NewBarkTown_Lab_EventScript_PoliceYes::
	closemessage
	special NameRival
	waitstate
	msgbox NewBarkTown_Lab_Text_Officer2_1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, NewBarkTown_Lab_EventScript_PoliceYes
	msgbox NewBarkTown_Lab_Text_Officer2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_COP, NewBarkTown_Lab_Movement_CopLeaves
	waitmovement 0
	removeobject LOCALID_COP

	@ setobjectxyperm LOCALID_COP, 25, 4
	applymovement OBJ_EVENT_ID_PLAYER, NewBarkTown_Lab_Movement_PlayerStepsToElm
	waitmovement 0
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft1, MSGBOX_DEFAULT
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_ElmStepBack
	waitmovement 0
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft3, MSGBOX_DEFAULT
	delay 20
	closemessage
	applymovement LOCALID_ELM, NewBarkTown_Lab_Movement_ElmStepForward
	waitmovement 0
	msgbox NewBarkTown_Lab_Text_ElmAfterTheft4, MSGBOX_DEFAULT
	closemessage
	setvar VAR_NEWBARKTOWN_LABSTATE, 5
	setvar VAR_NEWBARK_TOWN_STATE, 4
	setflag FLAG_HIDE_MOMS_FRIEND
	clearflag FLAG_HIDE_MOMS_FRIEND2
	setflag FLAG_ADVENTURE_STARTED
	setflag FLAG_EXP_SHARE
	removeitem ITEM_MYSTERY_EGG
	end

NewBarkTown_Lab_EventScript_ElmState5::
	lock
	faceplayer
	msgbox NewBarkTown_Lab_Text_ElmStudyingEgg, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ELM Common_Movement_FaceOriginalDirection
	release
	end
	
NewBarkTown_Lab_EventScript_ElmMasterBall::
	lock
	faceplayer
	msgbox NewBarkTown_Lab_Text_ElmGiveMasterBall1, MSGBOX_DEFAULT
	giveitem ITEM_MASTER_BALL
	msgbox NewBarkTown_Lab_Text_ElmGiveMasterBall2, MSGBOX_DEFAULT
	closemessage
	delay 20
	playse SE_PIN
	applymovement LOCALID_ELM, Common_Movement_ExclamationMark
	delay 60
	msgbox NewBarkTown_Lab_Text_KimonoGirls, MSGBOX_DEFAULT
	closemessage
	setvar VAR_NEWBARKTOWN_LABSTATE, 8
	setvar VAR_ECRUTEAK_CITY_THEATER, 4
	setflag FLAG_HIDE_ECRUTEAK_SILVER
	setflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_NPCS
	clearflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_KIMONOS
	release
	end

NewBarkTown_Lab_EventScript_ElmKimono::
	lock
	faceplayer
	msgbox NewBarkTown_Lab_Text_KimonoWaiting, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_ElmLeague::
	lock
	faceplayer
	msgbox NewBarkTown_Lab_Text_League, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_ElmSSTicket::
	msgbox NewBarkTown_Lab_Text_ElmGiveTicket1, MSGBOX_DEFAULT
	giveitem ITEM_SS_TICKET
	msgbox NewBarkTown_Lab_Text_ElmGiveTicket2, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_SSAQUA_1F_GRANDPA
	setvar VAR_NEWBARKTOWN_LABSTATE, 11
	clearflag FLAG_HIDE_OLIVINE_PORT_OAK
	release
	end

NewBarkTown_Lab_EventScript_TriggerAideGiveBalls::
	lock
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1WalkToPlayer
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox NewBarkTown_Lab_Text_AideGiveBalls, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_POKE_BALL, 5
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_FIRST_BALLS
	setvar VAR_NEWBARKTOWN_LABSTATE, 6
	applymovement LOCALID_AIDE1, NewBarkTown_Lab_Movement_Aide1LeavePlayer
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	release
	end

NewBarkTown_Lab_EventScript_Elm_Check_WhereIsEgg::
	msgbox NewBarkTown_Lab_Text_ElmWaitingEggHatch, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_EventScript_Elm_Check_Togepi::
	specialvar VAR_RESULT, CheckTogepi
	goto_if_eq VAR_RESULT, TRUE, NewBarkTown_Lab_EventScript_Elm_Togepi_Seen
	return

NewBarkTown_Lab_EventScript_Elm_Togepi_Seen::
	msgbox NewBarkTown_Lab_Text_ShowTogepi1, MSGBOX_DEFAULT
	waitmessage
	msgbox NewBarkTown_Lab_Text_ShowTogepi2, MSGBOX_DEFAULT
	waitmessage
	msgbox NewBarkTown_Lab_Text_ShowTogepi3, MSGBOX_DEFAULT
	waitmessage
	msgbox NewBarkTown_Lab_Text_ElmGiveEverstone1, MSGBOX_DEFAULT
	waitmessage
	giveitem ITEM_EVERSTONE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox NewBarkTown_Lab_Text_ElmGiveEverstone2, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_SHOWN_ELM_TOGEPI
	release
	end

NewBarkTown_Lab_EventScript_Elm_CallMe::
	msgbox NewBarkTown_Lab_Text_Elm_CallMe, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_Lab_Movement_WalkRight:
	walk_right
	step_end

NewBarkTown_Lab_Movement_WalkLeft:
	walk_left
	step_end

NewBarkTown_LabMovement_WalkToElm:
	walk_up
	walk_up
	walk_up
	step_end

NewBarkTown_Lab_Movement_ReturnPlayer:
	walk_up
	step_end

NewBarkTown_Lab_Movement_CheckEmail:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	step_end

NewBarkTown_Lab_Movement_CheckEmailSlow:
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

NewBarkTown_Lab_Movement_GotoComputerSafe:
	walk_up
	walk_left
	walk_left
	walk_left
	face_up
	step_end

NewBarkTown_Lab_Movement_ReturnFromEmail:
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	face_down
	step_end

NewBarkTown_Lab_Movement_Look_Left:
	face_left
	step_end

NewBarkTown_Lab_Movement_Look_Up:
	face_up
	step_end


NewBarkTown_Lab_Movement_Aide1WalkToPlayer:
	walk_down
	walk_down
	walk_right
	walk_right
	step_end

NewBarkTown_Lab_Movement_Aide1LeavePlayer:
	walk_left
	walk_left
	walk_up
	walk_up
	face_down
	step_end

NeBarkTownLab_Movement_PlayerWalkToCop:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	walk_fast_up
	face_right
	step_end

NewBarkTown_Lab_Movement_CopLeaves:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

NewBarkTown_Lab_Movement_PlayerStepsToElm:
	walk_right
	face_up
	step_end

NewBarkTown_Lab_Movement_ElmStepBack:
	lock_facing_direction
	walk_fast_up
	unlock_facing_direction
	step_end

NewBarkTown_Lab_Movement_ElmStepForward:
	walk_fast_down
	step_end

NewBarkTown_Lab_Text_ShouldntTouch:
	.string "Mieux vaut ne pas toucher !$"

NewBarkTown_Lab_Text_ElmIntro:
	.string "ELM: {PLAYER}! There you are!\p"
	.string "I needed to ask you a favor.\p"
	.string "I'm conducting new POKéMON\n"
	.string "research right now. I was\l"
	.string "wondering if you could help\l"
	.string "me with it, {PLAYER}.\p"
	.string "You see…\p"
	.string "I'm writing a paper that I\n"
	.string "want to present at a conference.\p"
	.string "But there are some things I\n"
	.string "don't quite understand yet.\p"
	.string "So!\p"
	.string "I'd like you to raise a\n"
	.string "POKéMON that I recently caught.$"

NewBarkTown_Lab_Text_ElmAccepted:
	.string "Merci, {PLAYER} !\n"
	.string "Tu es d'une grande aide !$"

NewBarkTown_Lab_Text_ElmRefused:
	.string "Mais… S'il te plaît, j'ai besoin\n"
	.string "de ton aide !$"

NewBarkTown_Lab_Text_ElmResearchAmbitions:
	.string "Quand j'annoncerai mes découvertes,\n"
	.string "nous approfondirons sûrement les\p"
	.string "nombreux mystères des\n"
	.string "POKéMON. Tu peux\p"
	.string "compter dessus !$"

NewBarkTown_Lab_Text_ElmGotAnEmail:
	.string "Oh, hé ! J'ai reçu un e-mail !\p"
	.string "… … … … … … … …\n"
	.string "Hm… Ouais…\p"
	.string "OK…$"

NewBarkTown_Lab_Text_ElmMissionFromMrPokemon:
	.string "Hey, listen.\p"
	.string "I have an acquaintance called\n"
	.string "MR. POKéMON.\p"
	.string "He keeps finding weird things and\n"
	.string "raving about his discoveries.\p"
	.string "Anyway, I just got an e-mail\n"
	.string "from him saying that this\l"
	.string "time it's real.\p"
	.string "It is intriguing, but we're\n"
	.string "busy with our POKéMON research...\p"
	.string "Wait!\n"
	.string "I know!\p"
	.string "{PLAYER}, can you go in our\n"
	.string "place?$"

NewBarkTown_Lab_Text_ElmChooseAPokemon:
	.string "Je veux que tu élèves l'un des\n"
	.string "POKéMON contenus dans ces BALLS.\p"
	.string "Tu seras le premier partenaire de ce\n"
	.string "POKéMON, {PLAYER} !\p"
	.string "Allez, choisis-en un !$"

NewBarkTown_Lab_Text_ElmWhereGoing:
	.string "ORME : Attends ! Où\n"
	.string "vas-tu ?$"

NewBarkTown_Lab_Text_ChooseCyndaquil:
	.string "ORME : Tu prends {STR_VAR_1},\n"
	.string "le POKéMON {STR_VAR_2} ?$"

NewBarkTown_Lab_Text_ChooseTotodile:
	.string "ORME : Tu veux {STR_VAR_1},\n"
	.string "le POKéMON {STR_VAR_2} ?$"

NewBarkTown_Lab_Text_ChooseChikorita:
	.string "ORME : Alors, tu aimes {STR_VAR_1},\n"
	.string "le POKéMON {STR_VAR_2} ?$"

NewBarkTown_Lab_Text_DidntChooseStarter:
	.string "ORME : Réfléchis bien.\p"
	.string "Ton partenaire est important.$"

NewBarkTown_Lab_Text_ChoseStarter:
	.string "ORME : Je pense que c'est un super\n"
	.string "POKéMON aussi !$"

NewBarkTown_Lab_Text_ReceivedStarter:
	.string "{PLAYER} a reçu {STR_VAR_1} !$"

NewBarkTown_Lab_Text_Nickname:
	.string "Veux-tu donner un surnom\n"
	.string "à ton {STR_VAR_1} ?$"

NewBarkTown_Lab_Text_ElmDirections1:
	.string "M. POKéMON habite un peu\n"
	.string "au-delà de CÉLESTIA, la ville\l"
	.string "suivante. C'est presque un chemin\p"
	.string "direct, tu ne peux pas\n"
	.string "te tromper. Mais au\p"
	.string "cas où, tu as\n"
	.string "mon numéro. Appelle-moi si\l"
	.string "quelque chose arrive !$"


NewBarkTown_Lab_Text_ElmLetYourMonBattle:
	.string "Si un POKéMON sauvage apparaît,\n"
	.string "laisse ton POKéMON le combattre !$"

NewBarkTown_Lab_Text_ElmDirections2:
	.string "Si un POKéMON sauvage apparaît, laisse\n"
	.string "ton POKéMON se battre !\p"
	.string "Si ton POKéMON est blessé, tu\n"
	.string "devrais le soigner avec la machine\l"
	.string "à ma droite, ou au CENTRE POKéMON.\p"
	.string "Je compte sur toi !$"

NewBarkTown_Lab_Text_GotElmsNumber:
	.string "{PLAYER} a obtenu le numéro\n"
	.string "d'ORME.$"

NewBarkTown_Lab_Text_ElmDescribesMrPokemon:
	.string "M. POKéMON va partout et\n"
	.string "trouve des raretés.\p"
	.string "Dommage qu'elles soient rares\n"
	.string "et pas très utiles...$"

NewBarkTown_Lab_Text_ElmPokeBall:
	.string "Il contient un POKéMON attrapé\n"
	.string "par le PROF.ORME.$"

@THEFT================================================================================

NewBarkTown_Lab_Text_ElmAfterTheft1:
	.string "ORME : {PLAYER}, c'est terrible…\p"
	.string "Oh, oui, quelle était la grande\n"
	.string "découverte de M. POKéMON ?$"

NewBarkTown_Lab_Text_ElmAfterTheft2:
	.string "{PLAYER} a donné l'OEUF MYSTÈRE\n"
	.string "au PROF.ORME.$"

NewBarkTown_Lab_Text_ElmAfterTheft3:
	.string "ORME : Ça ?$"

NewBarkTown_Lab_Text_ElmAfterTheft4:
	.string "Mais… C'est un OEUF POKéMON ?\p"
	.string "Si c'en est un, c'est une grande\n"
	.string "découverte !\p"
	.string "ORME : Quoi ?!\p"
	.string "Le PROF. CHEN t'a donné un POKéDEX ?\p"
	.string "{PLAYER}, c'est vrai ?\n"
	.string "C-c'est incroyable !\p"
	.string "Il est superbe pour voir le\n"
	.string "potentiel des gens en tant que dresseurs.\p"
	.string "Waouh, {PLAYER}. Tu as peut-être ce qu'il\n"
	.string "faut pour devenir CHAMPION.\p"
	.string "Tu sembles bien t'entendre\n"
	.string "avec les POKéMON aussi.\p"
	.string "Tu devrais relever le défi\n"
	.string "des ARÈNES POKéMON.\p"
	.string "L'ARÈNE la plus proche serait\n"
	.string "celle de MAUVILLE.\p"
	.string "…{PLAYER}. La route vers le\n"
	.string "championnat sera longue.\p"
	.string "Avant de partir, assure-toi\n"
	.string "de parler à ta maman.$"

NewBarkTown_Lab_Text_ElmStudyingEgg:
	.string "ORME : N'abandonne pas !\n"
	.string "J'appellerai si j'apprends quoi que ce soit\l"
	.string "sur cet OEUF !$"

NewBarkTown_Lab_Text_ElmAideHasEgg:
	.string "ORME : {PLAYER} ? Tu n'as pas rencontré\n"
	.string "mon assistant ?\p"
	.string "Il devait te retrouver avec\n"
	.string "l'OEUF au CENTRE POKéMON de\p"
	.string "MAUVILLE.\p"
	.string "Tu as dû le manquer.\n"
	.string "Essaie de le rattraper là-bas.$"

NewBarkTown_Lab_Text_ElmWaitingEggHatch:
	.string "ORME : Hé, cet OEUF a-t-il\n"
	.string "changé ?$"

NewBarkTown_Lab_Text_ElmThoughtEggHatched:
	.string "{PLAYER} ? Je pensais que l'OEUF\n"
	.string "avait éclos.\p"
	.string "Où est le POKéMON ?$"

NewBarkTown_Lab_Text_ShowTogepi1:
	.string "ORME : {PLAYER}, tu as l'air en forme !$"

NewBarkTown_Lab_Text_ShowTogepi2:
	.string "Quoi ? Ce POKéMON !?!$"

NewBarkTown_Lab_Text_ShowTogepi3:
	.string "L'OEUF a éclos ! Donc les POKéMON\n"
	.string "naissent des OEUFS…\p"
	.string "Non, peut-être que tous les POKéMON\n"
	.string "ne le font pas.\p"
	.string "Wow, il reste encore beaucoup de\n"
	.string "recherches à faire.$"

NewBarkTown_Lab_Text_ElmGiveEverstone1:
	.string "Merci, {PLAYER} ! Tu nous aides\n"
	.string "à percer les mystères des POKéMON !\p"
	.string "Je veux te donner ça en\n"
	.string "signe de notre reconnaissance.$"

NewBarkTown_Lab_Text_ElmGiveEverstone2:
	.string "C'est une PIERRE STASE.\p"
	.string "Certaines espèces de POKéMON évoluent\n"
	.string "quand elles atteignent certains niveaux.\p"
	.string "Un POKéMON tenant la PIERRE STASE\n"
	.string "n'évoluera pas.\p"
	.string "Donne-la à un POKéMON que tu ne\n"
	.string "veux pas faire évoluer.$"

NewBarkTown_Lab_Text_ElmCallYou:
	.string "ORME : {PLAYER}, je t'appellerai si\n"
	.string "quelque chose se passe.$"

NewBarkTown_Lab_Text_AideAfterTheft:
	.string "…soupir… Ce POKéMON volé. Je me\p"
	.string "demande comment il va. On dit\p"
	.string "qu'un POKéMON élevé par une mauvaise\n"
	.string "personne devient mauvais lui aussi.$"

NewBarkTown_Lab_Text_ElmGiveMasterBall1:
	.string "ORME : Salut, {PLAYER} !\p"
	.string "Grâce à toi, mes recherches\n"
	.string "avancent à grands pas !\p"
	.string "Prends ceci en signe de\n"
	.string "ma reconnaissance.$"

NewBarkTown_Lab_Text_ElmGiveMasterBall2:
	.string "La MASTER BALL est la meilleure\p"
	.string "! C'est la BALL ultime !\n"
	.string "Elle attrapera n'importe quel POKéMON sans\p"
	.string "échec. Elle n'est donnée qu'aux chercheurs\n"
	.string "POKéMON reconnus. Je pense que tu\p"
	.string "peux en faire beaucoup meilleur\n"
	.string "usage que moi, {PLAYER} !$"

NewBarkTown_Lab_Text_KimonoGirls:
	.string "By the way...\n"
	.string "A group of beautiful KIMONO\l"
	.string "GIRLS were looking for you.\p"
	.string "They told me they are\n"
	.string "waiting for you at the\l" 
	.string "ECRUTEAK DANCE THEATER.\p"
	.string "I know you've gone through many\n"
	.string "things since that EGG got you\l"
	.string "involved in all this...\p"
	.string "I hope you'll carry through it.$"

NewBarkTown_Lab_Text_KimonoWaiting:
	.string "PROF.ORME : Les FILLES KIMONO\n"
	.string "t'attendent au\l"
	.string "THÉÂTRE DE DANSE D'ECORIA.$"

NewBarkTown_Lab_Text_League:
	.string "PROF.ORME : Hahaha…\n"
	.string "Bien joué !\p"
	.string "Cet OEUF rare t'a causé beaucoup\n"
	.string "de soucis, hein ?\p"
	.string "Les FILLES KIMONO ont dit quelque chose\n"
	.string "sur moi ?\p"
	.string "Je n'ai rien à voir avec ça.\p"
	.string "Tu as pris ta décision et tu l'as\n"
	.string "mise à exécution.\p"
	.string "Après tant de choses accomplies, tu devrais\n"
	.string "pouvoir affronter la LIGUE maintenant !\p"
	.string "Tu devrais te diriger vers le\n"
	.string "PLATEAU INDIGO !\p"
	.string "Tu sais comment y aller ?\n"
	.string "Suis la ROUTE 27 jusqu'à la ROUTE 26.\p"
	.string "Une fois là, va tout droit vers le nord !$"


NewBarkTown_Lab_Text_ElmGiveTicket1:
	.string "ORME : {PLAYER} ! Te voilà !\p"
	.string "J'ai appelé parce que j'ai\n"
	.string "quelque chose pour toi.\p"
	.string "Tu vois ? C'est un PASSE BATEAU.\p"
	.string "Maintenant tu peux attraper des POKéMON\n"
	.string "à KANTO.$"

NewBarkTown_Lab_Text_ElmGiveTicket2:
	.string "Le bateau part d'\n"
	.string "OLIVILLE.\p"
	.string "Mais tu le savais déjà,\n"
	.string "{PLAYER}.\p"
	.string "Après tout, tu as voyagé partout\n"
	.string "avec tes POKéMON.\p"
	.string "Passe le bonjour au PROF.CHêNE à\n"
	.string "KANTO !$"

NewBarkTown_Lab_Text_LabMonEgg:
	.string "C'est l'OEUF POKéMON étudié\n"
	.string "par le PROF.ORME.$"

NewBarkTown_Lab_Text_AideGivePotion:
	.string "{PLAYER}, je veux que tu aies\n"
	.string "ça pour ta course.$"

NewBarkTown_Lab_Text_AideAlwaysBusy:
	.string "Nous ne sommes que trois, alors\n"
	.string "nous sommes toujours débordés.$"

NewBarkTown_Lab_Text_AideSave:
	.string "N'oublie pas de sauvegarder ta partie\n"
	.string "régulièrement !\p"
	.string "Appuie sur START, puis\n"
	.string "SAUVEGARDE !$"

NewBarkTown_Lab_Text_AideTheftTestimony:
	.string "Il y a eu un grand bruit dehors…\n"
	.string "Quand on est allés voir, quelqu'un\p"
	.string "a volé un POKéMON.\n"
	.string "C'est incroyable que quelqu'un\p"
	.string "puisse faire ça !\n"
	.string "…soupir… Ce POKéMON volé.\p"
	.string "Je me demande comment il va.\p"
	.string "On dit qu'un POKéMON élevé par\p"
	.string "une mauvaise personne devient\n"
	.string "mauvais lui aussi.$"

NewBarkTown_Lab_Text_AideGiveBalls:
	.string "{PLAYER} !\p"
	.string "Utilise-les pour ton\n"
	.string "quête du POKéDEX !$"

NewBarkTown_Lab_Text_AideExplainBalls:
	.string "Pour compléter ton POKéDEX, tu dois\n"
	.string "attraper des POKéMON.\p"
	.string "Lance des POKé BALLS sur les POKéMON\n"
	.string "sauvages pour les attraper.$"

NewBarkTown_Lab_Text_Officer1:
	.string "J'ai entendu qu'un POKéMON\n"
	.string "a été volé ici…\p"
	.string "Je venais d'obtenir des\n"
	.string "informations du PROF.ORME. Apparemment,\p"
	.string "c'était un jeune homme\n"
	.string "aux cheveux longs et\p"
	.string "rouges… Quoi ? Tu\p"
	.string "as combattu un\n"
	.string "dresseur comme ça\p"
	.string "? As-tu eu\n"
	.string "son nom ?$"

NewBarkTown_Lab_Text_Officer2_1:
	.string "OK ! Alors {RIVAL}, c'était son nom ?$"

NewBarkTown_Lab_Text_Officer2:
	.string "Merci d'avoir aidé mon\n"
	.string "enquête !$"

NewBarkTown_Lab_Text_OfficerNo:
	.string "Tu as bien noté son nom ?!$"

NewBarkTown_Lab_Text_Elm_CallMe:
	.string "Ah, {PLAYER} ! Comment va ton\p"
	.string "POKéDEX ? Je suis occupé maintenant,\n"
	.string "mais appelle-moi de temps en temps\l"
	.string "et je vérifierai tes progrès !$"
