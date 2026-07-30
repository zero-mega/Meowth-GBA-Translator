.set LOCALID_FAT_MAN, 1
.set LOCALID_MAN_1, 2
.set LOCALID_RICH_BOY, 3
.set LOCALID_GRUNT_1, 5
.set LOCALID_COOK, 6
.set LOCALID_OLD_WOMAN, 7
.set LOCALID_GIRL, 8
.set LOCALID_TY, 9
.set LOCALID_GABBY, 10
.set LOCALID_CAPT_STERN, 11
.set LOCALID_GRUNT_2, 18
.set LOCALID_GRUNT_3, 19
.set LOCALID_GRUNT_4, 26
.set LOCALID_GRUNT_5, 27
.set LOCALID_GRUNT_6, 28
.set LOCALID_GRUNT_7, 29
.set LOCALID_GRUNT_8, 30
.set LOCALID_GRUNT_9, 31
.set LOCALID_GRUNT_11, 33
.set LOCALID_SCOTT, 35

@ Note: LOCALID_SLATEPORT_ENERGY_GURU is a local id for this map used elsewhere. It's defined in event_objects.h

SlateportCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SlateportCity_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_OnFrame
	.byte 0

SlateportCity_OnTransition:
	setvar VAR_SLATEPORT_MUSEUM_1F_STATE, 0
	call SlateportCity_EventScript_EnterSlateport
	call_if_eq VAR_GARBAGEVAR, 1, SlateportCity_EventScript_MovePeopleForSternInterview
	call_if_eq VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1, SlateportCity_EventScript_SetReadyForScottScene
	end

SlateportCity_EventScript_EnterSlateport::
	setflag FLAG_VISITED_MAHOGANY_TOWN
	setvar VAR_CONTEST_HALL_STATE, 0
	setflag FLAG_GARBAGEFLAG
	return

SlateportCity_EventScript_MovePeopleForSternInterview::
	setobjectxyperm LOCALID_CAPT_STERN, 28, 13
	setobjectxyperm LOCALID_OLD_WOMAN, 25, 13
	setobjectxyperm LOCALID_RICH_BOY, 25, 14
	setobjectxyperm LOCALID_COOK, 27, 16
	setobjectxyperm LOCALID_GIRL, 28, 16
	setobjectxyperm LOCALID_FAT_MAN, 29, 16
	setobjectxyperm LOCALID_MAN_1, 31, 14
	setobjectmovementtype LOCALID_CAPT_STERN, MOVEMENT_TYPE_FACE_DOWN
	setobjectmovementtype LOCALID_OLD_WOMAN, MOVEMENT_TYPE_FACE_DOWN_AND_RIGHT
	setobjectmovementtype LOCALID_RICH_BOY, MOVEMENT_TYPE_FACE_UP_AND_RIGHT
	setobjectmovementtype LOCALID_COOK, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_GIRL, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_FAT_MAN, MOVEMENT_TYPE_FACE_UP
	setobjectmovementtype LOCALID_MAN_1, MOVEMENT_TYPE_FACE_LEFT
	return

SlateportCity_EventScript_SetReadyForScottScene::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8004, 30, SlateportCity_EventScript_MoveScottLeft
	setobjectxyperm LOCALID_SCOTT, 23, 27
	setobjectmovementtype LOCALID_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
	return

SlateportCity_EventScript_MoveScottLeft::
	setobjectxyperm LOCALID_SCOTT, 22, 27
	setobjectmovementtype LOCALID_SCOTT, MOVEMENT_TYPE_FACE_RIGHT
	return

SlateportCity_OnFrame:
	map_script_2 VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1, SlateportCity_EventScript_ScottScene
	.2byte 0

SlateportCity_EventScript_ScottScene::
	lockall
	addobject LOCALID_SCOTT
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PlayerFaceScott
	applymovement LOCALID_SCOTT, SlateportCity_Movement_ScottApproachPlayer
	waitmovement 0
	msgbox SlateportCity_Text_YouDroveTeamAquaAway, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SCOTT, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 60
	msgbox SlateportCity_Text_MaybeThisTrainer, MSGBOX_DEFAULT
	applymovement LOCALID_SCOTT, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox SlateportCity_Text_LetsRegisterEachOther, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox SlateportCity_Text_RegisteredScott, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_SCOTT_MATCH_CALL
	msgbox SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SCOTT, SlateportCity_Movement_ScottExit
	waitmovement 0
	removeobject LOCALID_SCOTT
	setobjectxyperm LOCALID_SCOTT, 10, 12
	setobjectmovementtype LOCALID_SCOTT, MOVEMENT_TYPE_FACE_DOWN
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 2
	addvar VAR_SCOTT_STATE, 1
	releaseall
	end

SlateportCity_Movement_PlayerFaceScott:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_ScottApproachPlayer:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_Movement_ScottExit:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_EventScript_EnergyGuru::
	lock
	faceplayer
	message SlateportCity_Text_EnergyGuruSellWhatYouNeed
	waitmessage
	pokemart SlateportCity_Pokemart_EnergyGuru
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_Pokemart_EnergyGuru:
	.2byte ITEM_PROTEIN
	.2byte ITEM_IRON
	.2byte ITEM_CARBOS
	.2byte ITEM_ZINC
	.2byte ITEM_CALCIUM
	.2byte ITEM_HP_UP
	.2byte ITEM_NONE
	release
	end

SlateportCity_EventScript_EffortRibbonWoman::
	lock
	faceplayer
	bufferleadmonspeciesname STR_VAR_1
	msgbox SlateportCity_Text_OhYourPokemon, MSGBOX_DEFAULT
	specialvar VAR_RESULT, LeadMonHasEffortRibbon
	call_if_eq VAR_RESULT, TRUE, SlateportCity_EventScript_MonHasEffortRibbon
	specialvar VAR_RESULT, Special_AreLeadMonEVsMaxedOut
	call_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_MonEVsNotMaxed
	msgbox SlateportCity_Text_PleaseGiveItThisEffortRibbon, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message SlateportCity_Text_ReceivedEffortRibbon
	waitfanfare
	msgbox SlateportCity_Text_PutEffortRibbonOnMon, MSGBOX_DEFAULT
	special GiveLeadMonEffortRibbon
	release
	end

SlateportCity_EventScript_MonEVsNotMaxed::
	msgbox SlateportCity_Text_GoForItLittleHarder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_MonHasEffortRibbon::
	msgbox SlateportCity_Text_EffortRibbonLooksGoodOnIt, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Cook::
	lock
	faceplayer
	call_if_eq VAR_GARBAGEVAR, 1, SlateportCity_EventScript_CookSternInterview
	msgbox SlateportCity_Text_SeaweedFullOfLife, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_CookSternInterview::
	msgbox SlateportCity_Text_CaptainComeBackWithBigFish, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_OldWoman::
	lock
	faceplayer
	call_if_eq VAR_GARBAGEVAR, 1, SlateportCity_EventScript_OldWomanSternInterview
	msgbox SlateportCity_Text_HowTownIsBornAndGrows, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_OldWomanSternInterview::
	msgbox SlateportCity_Text_CaptSternBeingInterviewed, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Girl::
	lock
	faceplayer
	call_if_eq VAR_GARBAGEVAR, 1, SlateportCity_EventScript_GirlSternInterview
	goto_if_set FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_GirlSecretBase
	msgbox SlateportCity_Text_SlateportWonderfulPlace, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_GirlSternInterview::
	msgbox SlateportCity_Text_InterviewerSoCool, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_GirlSecretBase::
	msgbox SlateportCity_Text_BuyBricksSoDecorWontGetDirty, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_RichBoy::
	lock
	faceplayer
	call_if_eq VAR_GARBAGEVAR, 1, SlateportCity_EventScript_RichBoySternInterview
	msgbox SlateportCity_Text_GoingToCompeteInBattleTent, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_RichBoySternInterview::
	msgbox SlateportCity_Text_SternSaysDiscoveredSomething, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_FatMan::
	goto_if_eq VAR_GARBAGEVAR, 1, SlateportCity_EventScript_FatManSternInterview
	msgbox SlateportCity_Text_BushedHikingFromMauville, MSGBOX_NPC
	end

SlateportCity_EventScript_FatManSternInterview::
	msgbox SlateportCity_Text_AmIOnTV, MSGBOX_SIGN
	end

SlateportCity_EventScript_Man1::
	lock
	faceplayer
	call_if_eq VAR_GARBAGEVAR, 1, SlateportCity_EventScript_Man1SternInterview
	msgbox SlateportCity_Text_EveryoneCallsHimCaptStern, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Man1SternInterview::
	msgbox SlateportCity_Text_CaptainsACelebrity, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman1::
	lock
	faceplayer
	goto_if_set FLAG_DOCK_REJECTED_DEVON_GOODS, SlateportCity_EventScript_Woman1AquaGone
	msgbox SlateportCity_Text_WhatsLongLineOverThere, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman1AquaGone::
	msgbox SlateportCity_Text_VisitedMuseumOften, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_BattleTentSign::
	msgbox SlateportCity_Text_BattleTentSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_SternsShipyardSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_SternsShipyardFerryComplete
	goto_if_set FLAG_BADGE07_GET, SlateportCity_EventScript_SternsShipyardNearsCompletion
	msgbox SlateportCity_Text_SternsShipyardWantedSign, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_SternsShipyardNearsCompletion::
	msgbox SlateportCity_Text_SternsShipyardNearsCompletion, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_SternsShipyardFerryComplete::
	msgbox SlateportCity_Text_SternsShipyardFerryComplete, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_PokemonFanClubSign::
	msgbox SlateportCity_Text_PokemonFanClubSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_OceanicMuseumSign::
	msgbox SlateportCity_Text_OceanicMuseumSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_CitySign::
	msgbox SlateportCity_Text_CitySign, MSGBOX_SIGN
	end

SlateportCity_EventScript_MarketSign::
	msgbox SlateportCity_Text_MarketSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_HarborSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_EventScript_HarborSignFerryComplete
	msgbox SlateportCity_Text_HarborFerryUnderConstruction, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_HarborSignFerryComplete::
	msgbox SlateportCity_Text_HarborSign, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_EventScript_NameRatersHouseSign::
	msgbox SlateportCity_Text_NameRatersHouseSign, MSGBOX_SIGN
	end

SlateportCity_EventScript_Maniac::
	lock
	faceplayer
	call_if_eq VAR_GARBAGEVAR, 1, SlateportCity_EventScript_ManiacSternInterview
	msgbox SlateportCity_Text_GetNameRaterToHelpYou, MSGBOX_DEFAULT
	release
	end

@ Unclear if the text here was meant to be different, but its not
SlateportCity_EventScript_ManiacSternInterview::
	msgbox SlateportCity_Text_GetNameRaterToHelpYou, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_Woman2::
	msgbox SlateportCity_Text_CantChangeTradeMonName, MSGBOX_NPC
	end

SlateportCity_EventScript_Sailor1::
	msgbox SlateportCity_Text_SeaIsSoWet, MSGBOX_NPC
	end

SlateportCity_EventScript_Sailor2::
	msgbox SlateportCity_Text_SinkOldBoats, MSGBOX_NPC
	end

SlateportCity_EventScript_PokefanF::
	msgbox SlateportCity_Text_BuyTooMuch, MSGBOX_NPC
	end

SlateportCity_EventScript_Man2::
	msgbox SlateportCity_Text_BattleTentBuiltRecently, MSGBOX_NPC
	end

SlateportCity_EventScript_AquaGrunt1::
	lock
	faceplayer
	msgbox SlateportCity_Text_QuitPushing, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt2::
	lock
	faceplayer
	msgbox SlateportCity_Text_AquaHasPolicy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt3::
	lock
	faceplayer
	msgbox SlateportCity_Text_BossIsBrilliant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt4::
	lock
	faceplayer
	msgbox SlateportCity_Text_WhatsNewSchemeIWonder, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt5::
	lock
	faceplayer
	msgbox SlateportCity_Text_ShouldTakeItAll, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_5, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt6::
	lock
	faceplayer
	msgbox SlateportCity_Text_DontButtIn, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_6, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt7::
	lock
	faceplayer
	msgbox SlateportCity_Text_RemindsMeOfLongLineForGames, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_7, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt8::
	lock
	faceplayer
	msgbox SlateportCity_Text_WhyAreWeLiningUp, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_8, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_AquaGrunt9::
	lock
	faceplayer
	playse SE_PIN
	applymovement LOCALID_GRUNT_9, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_GRUNT_9, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_Text_WhatDoYouWant, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	applymovement LOCALID_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	applymovement LOCALID_GRUNT_9, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_Text_IllReadSignForYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	applymovement LOCALID_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	msgbox SlateportCity_Text_SaysSomethingLikeSeaIsEndless, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_9, Common_Movement_FacePlayer
	waitmovement 0
	applymovement LOCALID_GRUNT_9, SlateportCity_Movement_DelayAquaGrunt
	waitmovement 0
	applymovement LOCALID_GRUNT_9, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_Movement_DelayAquaGrunt:
	delay_16
	delay_16
	step_end

SlateportCity_EventScript_AquaGrunt10::
	msgbox SlateportCity_Text_ShouldveBroughtMyGameBoy, MSGBOX_SIGN
	end

SlateportCity_EventScript_AquaGrunt11::
	lock
	faceplayer
	msgbox SlateportCity_Text_HotSpringsAfterOperation, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_11, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_EventScript_DollClerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration SlateportCity_PokemartDecor_Dolls
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_PokemartDecor_Dolls:
	.2byte DECOR_AZURILL_DOLL
	.2byte DECOR_MARILL_DOLL
	.2byte DECOR_SKITTY_DOLL
	.2byte DECOR_NONE
	release
	end

SlateportCity_EventScript_ComeBackWithSecretPower::
	msgbox gText_ComeBackWithSecretPower, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_DecorClerk::
	lock
	faceplayer
	goto_if_unset FLAG_RECEIVED_SECRET_POWER, SlateportCity_EventScript_ComeBackWithSecretPower
	message gText_HowMayIServeYou
	waitmessage
	pokemartdecoration SlateportCity_PokemartDecor
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_PokemartDecor:
	.2byte DECOR_RED_BRICK
	.2byte DECOR_BLUE_BRICK
	.2byte DECOR_YELLOW_BRICK
	.2byte DECOR_RED_BALLOON
	.2byte DECOR_BLUE_BALLOON
	.2byte DECOR_YELLOW_BALLOON
	.2byte DECOR_C_LOW_NOTE_MAT
	.2byte DECOR_D_NOTE_MAT
	.2byte DECOR_E_NOTE_MAT
	.2byte DECOR_F_NOTE_MAT
	.2byte DECOR_G_NOTE_MAT
	.2byte DECOR_A_NOTE_MAT
	.2byte DECOR_B_NOTE_MAT
	.2byte DECOR_C_HIGH_NOTE_MAT
	.2byte DECOR_NONE
	release
	end

SlateportCity_EventScript_PowerTMClerk::
	goto_if_set FLAG_FINITE_TMS, SlateportCity_EventScript_PowerTMClerkFinite
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SlateportCity_Pokemart_PowerTMs
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_Pokemart_PowerTMs:
	.2byte ITEM_SEA_INCENSE
	.2byte ITEM_LAX_INCENSE
	.2byte ITEM_NONE
	release
	end

SlateportCity_EventScript_PowerTMClerkFinite::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SlateportCity_Pokemart_PowerTMs2
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SlateportCity_Pokemart_PowerTMs2:
	.2byte ITEM_TM_HIDDEN_POWER
	.2byte ITEM_TM_SECRET_POWER
	.2byte ITEM_SEA_INCENSE
	.2byte ITEM_LAX_INCENSE
	.2byte ITEM_NONE
	release
	end

@ Scene with Capt Sterns interview and Team Aqua announcing plans to steal Submarine
SlateportCity_EventScript_CaptStern::
	lockall
	msgbox SlateportCity_Text_SternMoveAheadWithExploration, MSGBOX_DEFAULT
	msgbox SlateportCity_Text_GabbyWonderfulThanksForInterview, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GABBY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 10
	applymovement LOCALID_TY, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 25
	applymovement LOCALID_CAPT_STERN, SlateportCity_Movement_SternWatchGabbyAndTyExit
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PlayerFaceStern
	applymovement LOCALID_GABBY, SlateportCity_Movement_GabbyExit
	applymovement LOCALID_TY, SlateportCity_Movement_TyExit
	waitmovement 0
	removeobject LOCALID_GABBY
	removeobject LOCALID_TY
	msgbox SlateportCity_Text_SternWhewFirstInterview, MSGBOX_DEFAULT
	applymovement LOCALID_CAPT_STERN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_Text_OhPlayerWeMadeDiscovery, MSGBOX_DEFAULT
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	msgbox SlateportCity_Text_AquaWillAssumeControlOfSubmarine, MSGBOX_DEFAULT
	applymovement LOCALID_COOK, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_FAT_MAN, Common_Movement_WalkInPlaceFasterLeft
	applymovement LOCALID_OLD_WOMAN, SlateportCity_Movement_OldWomanConcern
	applymovement LOCALID_RICH_BOY, Common_Movement_QuestionMark
	applymovement LOCALID_MAN_1, SlateportCity_Movement_ManConcern
	waitmovement 0
	applymovement LOCALID_CAPT_STERN, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox SlateportCity_Text_SternWhatWasAllThat, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement LOCALID_CAPT_STERN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_CAPT_STERN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_CAPT_STERN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_Text_FromHarborTryingToTakeSub, MSGBOX_DEFAULT
	msgbox SlateportCity_Text_PleaseComeWithMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CAPT_STERN, SlateportCity_Movement_SternEnterHarbor
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PlayerEnterHarbor
	waitmovement 0
	removeobject LOCALID_CAPT_STERN
	clearflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	setvar VAR_GARBAGEVAR, 2
	warp MAP_SLATEPORT_CITY_HARBOR, 11, 14
	waitstate
	releaseall
	end

SlateportCity_Movement_OldWomanConcern:
	delay_16
	delay_16
	emote_question_mark
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_ManConcern:
	emote_question_mark
	walk_in_place_faster_up
	delay_16
	walk_in_place_faster_down
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

SlateportCity_Movement_GabbyExit:
	delay_16
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Movement_TyExit:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

SlateportCity_Movement_Unused:
	walk_down
	walk_in_place_faster_up
	step_end

SlateportCity_Movement_SternEnterHarbor:
	walk_right
	walk_up
	walk_up
	set_invisible
	step_end

SlateportCity_Movement_SternWatchGabbyAndTyExit:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_down
	walk_left
	step_end

SlateportCity_Movement_PlayerEnterHarbor:
	walk_in_place_faster_right
	delay_16
	delay_16
	walk_right
	walk_up
	step_end

SlateportCity_Movement_PlayerFaceStern:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_down
	step_end

SlateportCity_EventScript_Ty::
	msgbox SlateportCity_Text_BigSmileForCamera, MSGBOX_SIGN
	end

SlateportCity_EventScript_Gabby::
	msgbox SlateportCity_Text_MostInvaluableExperience, MSGBOX_SIGN
	end

SlateportCity_EventScript_Man3::
	msgbox SlateportCity_Text_WonderIfLighthouseStartlesPokemon, MSGBOX_NPC
	end

SlateportCity_EventScript_BerryPowderClerk::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_POWDER_JAR, SlateportCity_EventScript_ReceivedPowderJar
	msgbox SlateportCity_Text_ExplainBerries, MSGBOX_DEFAULT
	giveitem ITEM_POWDER_JAR
	setflag FLAG_RECEIVED_POWDER_JAR
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_ReceivedPowderJar::
	setvar VAR_0x8004, 1
	specialvar VAR_RESULT, HasEnoughBerryPowder
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_ExplainBerryPowder
	msgbox SlateportCity_Text_BroughtMeSomeBerryPowder, MSGBOX_DEFAULT
	special DisplayBerryPowderVendorMenu
	goto SlateportCity_EventScript_ChooseBerryPowderItem
	end

SlateportCity_EventScript_ExplainBerryPowder::
	msgbox SlateportCity_Text_ExplainBerryPowder, MSGBOX_DEFAULT
	release
	end

SlateportCity_EventScript_ChooseBerryPowderItem::
	message SlateportCity_Text_ExchangeWhatWithIt
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BERRY_POWDER_VENDOR
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, SlateportCity_EventScript_EnergyPowder
	case 1, SlateportCity_EventScript_EnergyRoot
	case 2, SlateportCity_EventScript_HealPowder
	case 3, SlateportCity_EventScript_RevivalHerb
	case 4, SlateportCity_EventScript_Protein
	case 5, SlateportCity_EventScript_Iron
	case 6, SlateportCity_EventScript_Carbos
	case 7, SlateportCity_EventScript_Calcium
	case 8, SlateportCity_EventScript_Zinc
	case 9, SlateportCity_EventScript_HPUp
	case 10, SlateportCity_EventScript_PPUp
	case 11, SlateportCity_EventScript_CancelPowderItemSelect
	case MULTI_B_PRESSED, SlateportCity_EventScript_CancelPowderItemSelect
	end

SlateportCity_EventScript_EnergyPowder::
	bufferitemname STR_VAR_1, ITEM_ENERGY_POWDER
	setvar VAR_0x8008, ITEM_ENERGY_POWDER
	setvar VAR_0x8009, 50
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_EnergyRoot::
	bufferitemname STR_VAR_1, ITEM_ENERGY_ROOT
	setvar VAR_0x8008, ITEM_ENERGY_ROOT
	setvar VAR_0x8009, 80
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_HealPowder::
	bufferitemname STR_VAR_1, ITEM_HEAL_POWDER
	setvar VAR_0x8008, ITEM_HEAL_POWDER
	setvar VAR_0x8009, 50
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_RevivalHerb::
	bufferitemname STR_VAR_1, ITEM_REVIVAL_HERB
	setvar VAR_0x8008, ITEM_REVIVAL_HERB
	setvar VAR_0x8009, 300
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Protein::
	bufferitemname STR_VAR_1, ITEM_PROTEIN
	setvar VAR_0x8008, ITEM_PROTEIN
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Iron::
	bufferitemname STR_VAR_1, ITEM_IRON
	setvar VAR_0x8008, ITEM_IRON
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Carbos::
	bufferitemname STR_VAR_1, ITEM_CARBOS
	setvar VAR_0x8008, ITEM_CARBOS
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Calcium::
	bufferitemname STR_VAR_1, ITEM_CALCIUM
	setvar VAR_0x8008, ITEM_CALCIUM
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_Zinc::
	bufferitemname STR_VAR_1, ITEM_ZINC
	setvar VAR_0x8008, ITEM_ZINC
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_HPUp::
	bufferitemname STR_VAR_1, ITEM_HP_UP
	setvar VAR_0x8008, ITEM_HP_UP
	setvar VAR_0x8009, 1000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_PPUp::
	bufferitemname STR_VAR_1, ITEM_PP_UP
	setvar VAR_0x8008, ITEM_PP_UP
	setvar VAR_0x8009, 3000
	goto SlateportCity_EventScript_TryBuyBerryPowderItem
	end

SlateportCity_EventScript_CancelPowderItemSelect::
	msgbox SlateportCity_Text_ComeBackToTradeBerryPowder, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_TryBuyBerryPowderItem::
	msgbox SlateportCity_Text_ExchangeBerryPowderForItem, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SlateportCity_EventScript_ChooseBerryPowderItem
	copyvar VAR_0x8004, VAR_0x8009
	specialvar VAR_RESULT, HasEnoughBerryPowder
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_NotEnoughBerryPowder
	giveitem VAR_0x8008
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_EventScript_NoRoomForBerryPowderItem
	copyvar VAR_0x8004, VAR_0x8009
	special TakeBerryPowder
	special PrintPlayerBerryPowderAmount
	msgbox SlateportCity_Text_FineBerryPowderTradeSomethingElse, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SlateportCity_EventScript_ChooseBerryPowderItem
	msgbox SlateportCity_Text_WhenYouGetMoreBringItToMe, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_NoRoomForBerryPowderItem::
	msgbox gText_TheBagIsFull, MSGBOX_DEFAULT
	special RemoveBerryPowderVendorMenu
	release
	end

SlateportCity_EventScript_NotEnoughBerryPowder::
	msgbox SlateportCity_Text_DontHaveEnoughBerryPowder, MSGBOX_DEFAULT
	goto SlateportCity_EventScript_ChooseBerryPowderItem
	end

SlateportCity_EventScript_ScottBattleTentScene::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	opendoor 10, 12
	waitdooranim
	addobject LOCALID_SCOTT
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PushPlayerDown
	applymovement LOCALID_SCOTT, SlateportCity_Movement_ScottExitBattleTent
	waitmovement 0
	closedoor 10, 12
	waitdooranim
	msgbox SlateportCity_Text_TakingBattleTentChallenge, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_SCOTT, SlateportCity_Movement_ScottExitAfterBattleTent
	waitmovement 0
	removeobject LOCALID_SCOTT
	addvar VAR_SCOTT_STATE, 1
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
	releaseall
	end

SlateportCity_Movement_PushPlayerDown:
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

SlateportCity_Movement_PlayerWatchScottExit:
	delay_16
	walk_in_place_faster_right
	step_end

SlateportCity_Movement_ScottExitBattleTent:
	delay_8
	walk_down
	step_end

SlateportCity_Movement_ScottExitAfterBattleTent:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_EventScript_BerryCrushRankingsSign::
	lockall
	special ShowBerryCrushRankings
	waitstate
	releaseall
	end

SlateportCity_Text_EnergyGuruSellWhatYouNeed:
	.string "Je suis le GOURU DE L'ÉNERGIE ! Je vais tout donner\n"
	.string "et te vendre ce dont tu as besoin !$"

SlateportCity_Text_OhYourPokemon:
	.string "Oh ?\n"
	.string "Ton {STR_VAR_1}…$"

SlateportCity_Text_PleaseGiveItThisEffortRibbon:
	.string "Il s'est donné à fond de façon stupéfiante !\p"
	.string "En récompense, donne-lui ce\n"
	.string "RUBAN EFFORT.$"

SlateportCity_Text_ReceivedEffortRibbon:
	.string "{PLAYER} a reçu le RUBAN EFFORT.$"

SlateportCity_Text_PutEffortRibbonOnMon:
	.string "{PLAYER} a attaché le RUBAN EFFORT\n"
	.string "sur {STR_VAR_1}.$"

SlateportCity_Text_GoForItLittleHarder:
	.string "Il faut y aller un peu plus fort.\p"
	.string "Si tu le fais, je donnerai quelque chose de sympa\n"
	.string "à ton POKéMON.$"

SlateportCity_Text_EffortRibbonLooksGoodOnIt:
	.string "Oh ! Ton {STR_VAR_1}, ce RUBAN D'EFFORT\n"
	.string " lui va bien !$"

SlateportCity_Text_WonderIfLighthouseStartlesPokemon:
	.string "La lumière du phare atteint des\n"
	.string "dizaines de kilomètres. Je me\p"
	.string "demande si ça ne surprend\n"
	.string "pas les POKéMON en mer.$"

SlateportCity_Text_SeaweedFullOfLife:
	.string "Oh, regarde ça !\p"
	.string "Les algues qu'on trouve par ici sont\n"
	.string "fraîches et pleines de vie.\p"
	.string "On dirait même qu'elles peuvent\n"
	.string "se dresser et attaquer !$"

SlateportCity_Text_HowTownIsBornAndGrows:
	.string "Là où l'eau est propre, les fruits\n"
	.string "d'une récolte abondante s'accumulent.\p"
	.string "Et là où les gens se rassemblent, un marché\n"
	.string "naît bientôt.\p"
	.string "C'est ainsi qu'une ville naît et grandit.$"

SlateportCity_Text_SlateportWonderfulPlace:
	.string "Faire du shopping en respirant\n"
	.string "l'odeur de l'océan…\p"
	.string "POIVRESSE, c'est un endroit merveilleux !$"

SlateportCity_Text_BuyBricksSoDecorWontGetDirty:
	.string "Si tu mets des POUPÉES ou des COUSSINS\n"
	.string "par terre, ils se salissent.\p"
	.string "Je vais acheter des BRIQUES pour que mes\n"
	.string "POUPÉES et COUSSINS ne se salissent pas\l"
	.string "quand je les laisse dehors.$"

SlateportCity_Text_GoingToCompeteInBattleTent:
	.string "Wroooar ! Je vais aussi participer\n"
	.string "à la TENTE DE COMBAT !\p"
	.string "Mais avant ça, il faut que j'attrape\n"
	.string "des POKéMON !$"

SlateportCity_Text_BushedHikingFromMauville:
	.string "Ouf… Je suis crevé…\p"
	.string "J'ai marché depuis LAVELLANIA.\n"
	.string "Mais bon sang, cette ville est immense.\p"
	.string "Si j'avais su, j'aurais pris\n"
	.string "mon VÉLO.$"

SlateportCity_Text_EveryoneCallsHimCaptStern:
	.string "STERN, celui qui a construit le\n"
	.string "MUSÉE, est aussi le chef\l"
	.string "d'une équipe d'exploration sous-marine.\p"
	.string "Alors tout le monde l'appelle CAPT. STERN.$"

SlateportCity_Text_WhatsLongLineOverThere:
	.string "Qu'est-ce que c'est là-bas ?\n"
	.string "Cette longue file…$"

SlateportCity_Text_VisitedMuseumOften:
	.string "Quand j'étais enfant, je venais\n"
	.string "souvent au MUSÉE.\p"
	.string "Je rêvais des mystères de la mer\n"
	.string "après avoir vu les expositions.$"

SlateportCity_Text_QuitPushing:
	.string "Hé, toi ! Arrête de pousser !\n"
	.string "C'est la file, tu ne vois pas ?$"

SlateportCity_Text_AquaHasPolicy:
	.string "La TEAM AQUA a pour politique de se\n"
	.string "rassembler et de se disperser sur\l"
	.string "le lieu de l'opération.$"

SlateportCity_Text_BossIsBrilliant:
	.string "Notre BOSS est brillant.\p"
	.string "Qu'est-ce qu'il voudrait faire\n"
	.string "d'un MUSÉE maintenant ?$"

SlateportCity_Text_WhatsNewSchemeIWonder:
	.string "Quel est le nouveau plan, je me demande ?\p"
	.string "Notre BOSS est effrayant quand il est en colère,\n"
	.string "alors je ferais mieux de ne pas tout gâcher...$"

SlateportCity_Text_ShouldTakeItAll:
	.string "S'il y a quelque chose dont on a besoin au\n"
	.string "MUSÉE, on devrait tout prendre !$"

SlateportCity_Text_DontButtIn:
	.string "Hé, toi là !\n"
	.string "Ne te mêle pas de ça !$"

SlateportCity_Text_RemindsMeOfLongLineForGames:
	.string "Une longue file, hein ?\p"
	.string "Ça me rappelle le temps où je faisais la queue pour\n"
	.string "acheter des jeux à succès…$"

SlateportCity_Text_WhyAreWeLiningUp:
	.string "Pourquoi faire la queue et payer ?\n"
	.string "On devrait simplement entrer !$"

SlateportCity_Text_WhatDoYouWant:
	.string "Quoi ?\n"
	.string "Que veux-tu ?$"

SlateportCity_Text_IllReadSignForYou:
	.string "Tu veux lire ce panneau ?\n"
	.string "Je vais le lire pour toi !$"

SlateportCity_Text_SaysSomethingLikeSeaIsEndless:
	.string "Voyons voir…\p"
	.string "Euh… Je crois que ça dit un truc\n"
	.string "comme « la vie en mer est sans fin ».\p"
	.string "Ouais, je suis presque sûr que\n"
	.string "c'est ça.$"

SlateportCity_Text_ShouldveBroughtMyGameBoy:
	.string "Grumble…\p"
	.string "J'aurais dû apporter ma Game Boy\n"
	.string "Advance pour ne pas m'ennuyer dans la file…\p"
	.string "Grumble…$"

SlateportCity_Text_HotSpringsAfterOperation:
	.string "Quand cette opération sera terminée,\n"
	.string "notre chef nous emmènera dans une source\p"
	.string "chaude ! C'est ce qu'il a dit.\n"
	.string "J'ai hâte !$"

SlateportCity_Text_SeaIsSoWet:
	.string "La mer est si vaste…\p"
	.string "La mer aurait-elle été faite\n"
	.string "par les larmes versées par les POKéMON ?$"

SlateportCity_Text_SinkOldBoats:
	.string "Tu sais ce qu'on fait des vieux\n"
	.string "navires trop vieux pour naviguer ?\p"
	.string "On les coule en mer pour qu'ils\n"
	.string "deviennent des habitats pour les POKéMON.$"

SlateportCity_Text_BuyTooMuch:
	.string "Chaque fois que je viens ici, je me laisse emporter\n"
	.string "et j'achète trop.$"

SlateportCity_Text_GetNameRaterToHelpYou:
	.string "Si tu veux changer le surnom de ton POKéMON,\n"
	.string "tu devras demander de l'aide au\l"
	.string "JUGE DES SURNOMS.$"

SlateportCity_Text_CantChangeTradeMonName:
	.string "Pour tout POKéMON reçu en échange,\n"
	.string "tu ne peux pas changer son surnom.\p"
	.string "L'amour du DRESSEUR d'origine pour ce\n"
	.string "POKéMON est dans le surnom.$"

SlateportCity_Text_BattleTentBuiltRecently:
	.string "Récemment, une TENTE DE COMBAT a été construite\n"
	.string "à POIVRESSEL.\p"
	.string "Les ARÈNES sont amusantes, mais la TENTE DE COMBAT\n"
	.string "est géniale à sa manière.\p"
	.string "Tu devrais y trouver des POKéMON costauds\n"
	.string "pour la TENTE DE COMBAT !$"

SlateportCity_Text_CaptSternBeingInterviewed:
	.string "J'espérais que c'était une star célèbre\n"
	.string "pour avoir un autographe.\p"
	.string "Mais qui est interviewé là ?\n"
	.string "Ce n'est pas le CAPT. STERN ?$"

SlateportCity_Text_InterviewerSoCool:
	.string "Cette journaliste est tellement cool\n"
	.string "et jolie.\p"
	.string "Quand je serai grand, je serai\n"
	.string "une journaliste internationale !$"

SlateportCity_Text_SternSaysDiscoveredSomething:
	.string "Le CAPT. LOUGE dit qu'ils ont découvert\n"
	.string "quelque chose au fond de la mer.\p"
	.string "Je me demande ce que c'est ?\n"
	.string "Qu'est-ce que ça pourrait être ?$"

SlateportCity_Text_CaptainComeBackWithBigFish:
	.string "Que se passe-t-il ici ?\p"
	.string "Le bon CAPITAINE est-il revenu avec\n"
	.string "un gros poisson des fonds marins ?$"

SlateportCity_Text_AmIOnTV:
	.string "Hé ! Tu regardes ?\n"
	.string "Je suis à la TV ?$"

SlateportCity_Text_CaptainsACelebrity:
	.string "Une interview à la télé ! Ici !\n"
	.string "Le CAPITAINE est une célébrité !$"

SlateportCity_Text_BigSmileForCamera:
	.string "TY : OK, CAPT. LOQUET, un grand sourire\n"
	.string "pour la caméra !$"

SlateportCity_Text_MostInvaluableExperience:
	.string "CATHY : Je vois, je vois. Tu as eu une\n"
	.string "expérience des plus précieuses…$"

SlateportCity_Text_SternMoveAheadWithExploration:
	.string "CAPT. STERN : Oui, en effet. Nous comptons\n"
	.string "poursuivre notre exploration.$"

SlateportCity_Text_GabbyWonderfulThanksForInterview:
	.string "MARILOU : C'est merveilleux, CAPT. SERGENT !\n"
	.string "Merci d'avoir pris le temps de votre\l"
	.string "agenda chargé pour nous parler.\p"
	.string "Nous espérons vous interviewer à nouveau\n"
	.string "avec des nouvelles découvertes !$"

SlateportCity_Text_SternWhewFirstInterview:
	.string "CAP. POIVRE : Ouf…\p"
	.string "C'était ma première fois filmé pour\n"
	.string "la télé. C'était stressant.$"

SlateportCity_Text_OhPlayerWeMadeDiscovery:
	.string "Oh ! {PLAYER}{KUN} ! Tu as\n"
	.string "l'air en forme ! On a\p"
	.string "fait une énorme découverte lors de\n"
	.string "notre dernière exploration sous- marine. On\p"
	.string "a trouvé une caverne sous-marine sur\n"
	.string "la ROUTE 128. On pense\p"
	.string "que c'est l'habitat d'un POKéMON\n"
	.string "censé être éteint depuis longtemps.$"

SlateportCity_Text_AquaWillAssumeControlOfSubmarine:
	.string "Fufufu… CAPT. KUSTO, je suppose.\n"
	.string "Nous de la TEAM AQUA\p"
	.string "allons prendre le contrôle de\n"
	.string "ton sous-marin ! Tes objections\p"
	.string "sont sans importance ! Nous\n"
	.string "attendons ta pleine coopération !\p"
	.string "Fufufu… Regarde et apprends\n"
	.string "ce que la TEAM\l"
	.string "AQUA a prévu !$"

SlateportCity_Text_SternWhatWasAllThat:
	.string "CAPT. STERN : Qu'est-ce que c'était que ça ?\p"
	.string "On aurait dit quelqu'un avec\n"
	.string "un mégaphone...\p"
	.string "D'où est-ce que ça venait ?$"

SlateportCity_Text_FromHarborTryingToTakeSub:
	.string "C'est du PORT !\p"
	.string "Le sous-marin !\n"
	.string "Ils essaient de le prendre !$"

SlateportCity_Text_PleaseComeWithMe:
	.string "{PLAYER}{KUN} !\n"
	.string "S'il te plaît, viens avec moi !$"

SlateportCity_Text_BattleTentSign:
	.string "TENTE DE COMBAT POIVRESSE\n"
	.string "« Trouve-le ! Le POKéMON ultime ! »$"

SlateportCity_Text_SternsShipyardWantedSign:
	.string "CHANTIER NAVAL DE STERN\p"
	.string "« Recherché : un marin capable de naviguer\n"
	.string "dans tous les courants. »$"

SlateportCity_Text_SternsShipyardNearsCompletion:
	.string "CHANTIER NAVAL DE STERN\p"
	.string "« Le ferry S.S. MARÉE approche de\n"
	.string "la fin de sa construction pour desservir\l"
	.string "les ports de MYOKARA et NÉNUCRIQUE. »$"

SlateportCity_Text_SternsShipyardFerryComplete:
	.string "CHANTIER NAVAL DE STERN\p"
	.string "« L'embarquement sur le ferry S.S. MARÉE\n"
	.string "POIVRESSEL-NÉNUCRIQUE se fait au\l"
	.string "PORT. »$"

SlateportCity_Text_PokemonFanClubSign:
	.string "FAN CLUB POKéMON\n"
	.string "« Appel à tous les fans de POKéMON ! »$"

SlateportCity_Text_OceanicMuseumSign:
	.string "« La mer infinie nourrit\n"
	.string "toute vie. »\p"
	.string "MUSÉE OCÉANOGRAPHIQUE$"

SlateportCity_Text_CitySign:
	.string "POIVRESSE\p"
	.string "« Le port où les gens et les POKéMON\n"
	.string "se croisent. »$"

SlateportCity_Text_MarketSign:
	.string "MARCHÉ DE POIVRESSEL\n"
	.string "« Des objets uniques introuvables ailleurs ! »$"

SlateportCity_Text_HarborFerryUnderConstruction:
	.string "PORT DE POIVRESSEL. Le\p"
	.string "ferry S.S. MARINE est\n"
	.string "en construction au CHANTIER\p"
	.string "NAVAL. La mise en\n"
	.string "service est prévue bientôt.$"

SlateportCity_Text_HarborSign:
	.string "PORT DE POIVRESSE\p"
	.string "« Profitez d'une croisière agréable\n"
	.string "sur le ferry S.S. MARÉE. »$"

SlateportCity_Text_NameRatersHouseSign:
	.string "MAISON DU JUGE DE SURNOMS\n"
	.string "« Surnoms de POKéMON évalués. »$"

SlateportCity_Text_ExplainBerries:
	.string "Si un POKéMON sauvage est blessé, il se soigne\n"
	.string "en mâchant des BAIES.\p"
	.string "Tu le savais ?\p"
	.string "Quelqu'un a vu ça et a eu l'idée\n"
	.string "de faire des médicaments à partir de BAIES.\p"
	.string "Tu le savais ?\p"
	.string "Pour transformer des BAIES en médicament,\n"
	.string "il faut les écraser en poudre.\p"
	.string "Tu le savais ?\p"
	.string "Tu sembles avoir un intérêt\n"
	.string "pour les BAIES !\p"
	.string "J'ai quelque chose de bien pour\n"
	.string "quelqu'un comme toi.$"

SlateportCity_Text_ExplainBerryPowder:
	.string "J'ai récemment fait\n"
	.string "installer des machines\p"
	.string "dans les\n"
	.string "CENTRES POKéMON\p"
	.string "pour écraser des BAIES.\p"
	.string "La machine BROYEUSE\n"
	.string "DE BAIES peut faire\p"
	.string "des {POKEBLOCK}S !\n"
	.string "Essaie-la !$"

SlateportCity_Text_BroughtMeSomeBerryPowder:
	.string "M'as-tu apporté de la\n"
	.string "POUDRE BAIE ?$"

SlateportCity_Text_ExchangeWhatWithIt:
	.string "Avec quoi veux-tu\n"
	.string "l'échanger ?$"

SlateportCity_Text_ExchangeBerryPowderForItem:
	.string "OK, tu veux échanger ta\n"
	.string "POUDRE DE BAIE contre un {STR_VAR_1} ?$"

SlateportCity_Text_DontHaveEnoughBerryPowder:
	.string "Oh, mince. Tu n'as pas assez de\n"
	.string "POUDRE DE BAIE.$"

SlateportCity_Text_FineBerryPowderTradeSomethingElse:
	.string "C'est de la fine POUDRE BAIE.\n"
	.string "Elle fera d'excellentes médicines.\p"
	.string "Veux-tu échanger plus de ta\n"
	.string "POUDRE BAIE contre autre chose ?$"

SlateportCity_Text_WhenYouGetMoreBringItToMe:
	.string "OK ! Quand tu auras plus de POUDRE DE BAIE,\n"
	.string "apporte-la-moi, s'il te plaît !$"

SlateportCity_Text_ComeBackToTradeBerryPowder:
	.string "Reviens si tu veux échanger ta\n"
	.string "POUDRE DE BAIE contre des médicaments.\p"
	.string "Je tiens toujours un bazar\p"
	.string "ici. Tu le savais ?$"

SlateportCity_Text_YouDroveTeamAquaAway:
	.string "SCOTT : Hein ? Je suis\n"
	.string "sûr de t'avoir rencontré quelque part\p"
	.string "avant. Je me suis présenté ?\n"
	.string "Si non, je m'appelle SCOTT. Je\p"
	.string "viens de voir la TEAM AQUA\n"
	.string "s'enfuir d'ici comme piqués. Je\p"
	.string "suppose--tu les as chassés ?$"

SlateportCity_Text_MaybeThisTrainer:
	.string "SCOTT : Hmm…\n"
	.string "Peut-être, juste peut-être, ce DRESSEUR…$"

SlateportCity_Text_LetsRegisterEachOther:
	.string "SCOTT : Très bien ! Je pense que tu vas\n"
	.string "devenir un bon ami.\p"
	.string "Alors, enregistrons-nous mutuellement dans nos\n"
	.string "POKéNAVS.\p"
	.string "… … … … … …$"

SlateportCity_Text_RegisteredScott:
	.string "Cette personne SCOTT a été\n"
	.string "enregistrée dans le POKéNAV.$"

SlateportCity_Text_KeepEyeOnTrainersBeSeeingYou:
	.string "SCOTT : J'aimerais\n"
	.string "t'accompagner, mais je\l"
	.string "dois surveiller le\p"
	.string "PARC DES COMBATS.\n"
	.string "Bonne chance\p"
	.string "là-bas !$"

SlateportCity_Text_TakingBattleTentChallenge:
	.string "SCOTT : Oh, hé !\n"
	.string "Si ce n'est pas\p"
	.string "{PLAYER}{KUN} !\n"
	.string "{PLAYER}{KUN}, laisse-moi\p"
	.string "deviner--tu vas\n"
	.string "relever le défi de\p"
	.string "la LIGUE POKéMON !\n"
	.string "Je t'encourage,\p"
	.string "{PLAYER}{KUN} !$"
