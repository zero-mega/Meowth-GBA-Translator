.set LOCALID_CHALLENGE_BIKER, 21
.set LOCALID_RIVAL, 28
.set LOCALID_RIVAL_ON_BIKE, 29
.set LOCALID_BIRCH, 36

Route110_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route110_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route110_OnFrame
	.byte 0

Route110_OnResume:
	callnative SetTimeBasedEncounters
	special UpdateCyclingRoadState
	end

Route110_OnTransition:
	callnative SetTimeBasedEncounters
	call Common_EventScript_SetupRivalGfxId
	call Common_EventScript_SetupRivalOnBikeGfxId
	call_if_eq VAR_CYCLING_CHALLENGE_STATE, 1, Route110_EventScript_SaveCyclingMusic
	end

Route110_EventScript_SaveCyclingMusic::
	savebgm MUS_CYCLING
	return

Route110_OnFrame:
	map_script_2 VAR_CYCLING_CHALLENGE_STATE, 1, Route110_EventScript_BeginCylcingRoadChallenge
	.2byte 0

Route110_EventScript_BeginCylcingRoadChallenge::
	special Special_BeginCyclingRoadChallenge
	setvar VAR_CYCLING_CHALLENGE_STATE, 2
	return

Route110_EventScript_AquaGrunt1::
	lock
	faceplayer
	msgbox Route110_Text_WeCantTalkAboutAquaActivities, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route110_EventScript_AquaGrunt2::
	lock
	faceplayer
	msgbox Route110_Text_KickUpARuckus, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route110_EventScript_AquaGrunt3::
	lock
	faceplayer
	msgbox Route110_Text_MyFirstJobInAqua, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route110_EventScript_AquaGrunt4::
	lock
	faceplayer
	msgbox Route110_Text_AquaActionsBringSmiles, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route110_EventScript_Boy1::
	msgbox Route110_Text_RideBikeAtFullSpeed, MSGBOX_NPC
	end

Route110_EventScript_CyclingGirl1::
	msgbox Route110_Text_HairStreamsBehindMe, MSGBOX_NPC
	end

Route110_EventScript_CyclingGuy1::
	msgbox Route110_Text_YouGotBikeFromRydel, MSGBOX_NPC
	end

Route110_EventScript_OldMan::
	msgbox Route110_Text_TwoRoads, MSGBOX_NPC
	end

Route110_EventScript_OldWoman::
	msgbox Route110_Text_WalkOnTheLowRoad, MSGBOX_NPC
	end

Route110_EventScript_CyclingGuy2::
	msgbox Route110_Text_BikeTechniques, MSGBOX_NPC
	end

Route110_EventScript_Boy2::
	msgbox Route110_Text_WhichShouldIChoose, MSGBOX_NPC
	end

Route110_EventScript_SlateportCitySign::
	msgbox Route110_Text_SlateportCitySign, MSGBOX_SIGN
	end

Route110_EventScript_CyclingRoadSign::
	msgbox Route110_Text_CyclingRoadSign, MSGBOX_SIGN
	end

Route110_EventScript_VandalizedSign::
	msgbox Route110_Text_AquaWasHere, MSGBOX_SIGN
	end

Route110_EventScript_Route103Sign::
	msgbox Route110_Text_Route103Sign, MSGBOX_SIGN
	end

Route110_EventScript_SeasideParkingSign::
	msgbox Route110_Text_SeasideParkingSign, MSGBOX_SIGN
	end

Route110_EventScript_MauvilleCitySign::
	msgbox Route110_Text_MauvilleCitySign, MSGBOX_SIGN
	end

Route110_EventScript_TrainerTipsPrlzSleep::
	msgbox Route110_Text_TrainerTipsPrlzSleep, MSGBOX_SIGN
	end

Route110_EventScript_TrainerTipsRegisterItems::
	msgbox Route110_Text_TrainerTipsRegisterItems, MSGBOX_SIGN
	end

Route110_EventScript_TrickHouseSign::
	msgbox Route110_Text_TrickHouseSign, MSGBOX_SIGN
	end

Route110_EventScript_CyclingRoadResultsSign::
	lockall
	specialvar VAR_RESULT, GetRecordedCyclingRoadResults
	goto_if_eq VAR_RESULT, FALSE, Route110_EventScript_NoRecordSet
	msgbox Route110_Text_BestRecord, MSGBOX_DEFAULT
	releaseall
	end

Route110_EventScript_NoRecordSet::
	msgbox Route110_Text_ThereIsNoRecord, MSGBOX_DEFAULT
	releaseall
	end

Route110_EventScript_ChallengeGuy::
	lock
	faceplayer
	specialvar VAR_RESULT, GetPlayerAvatarBike
	goto_if_eq VAR_RESULT, 1, Route110_EventScript_PlayerRidingAcroBike
	goto_if_eq VAR_CYCLING_CHALLENGE_STATE, 0, Route110_EventScript_PlayerNotRidingBike
	msgbox Route110_Text_AlwaysAimHigher, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_PlayerNotRidingBike::
	msgbox Route110_Text_RatedForNumberOfCollisions, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_PlayerRidingAcroBike::
	msgbox Route110_Text_AcroBikesDoNotQualify, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_Edward::
	trainerbattle_single TRAINER_EDWARD, Route110_Text_EdwardIntro, Route110_Text_EdwardDefeated
	msgbox Route110_Text_EdwardPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Jaclyn::
	trainerbattle_single TRAINER_JACLYN, Route110_Text_JaclynIntro, Route110_Text_JaclynDefeated
	msgbox Route110_Text_JaclynPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Edwin::
	trainerbattle_single TRAINER_LOLA, Route110_Text_EdwinIntro, Route110_Text_EdwinDefeated, Route110_EventScript_EdwinRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route110_EventScript_EdwinRematch
	msgbox Route110_Text_EdwinPostBattle, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_EdwinRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route110_Text_EdwinRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_LOLA
	release
	end

Route110_EventScript_EdwinRematch::
	trainerbattle_rematch TRAINER_LOLA, Route110_Text_EdwinRematchIntro, Route110_Text_EdwinRematchDefeated
	msgbox Route110_Text_EdwinRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Dale::
	trainerbattle_single TRAINER_DALE, Route110_Text_DaleIntro, Route110_Text_DaleDefeated
	msgbox Route110_Text_DalePostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Jacob::
	trainerbattle_single TRAINER_RIVAL_CYNDAQUIL_2, Route110_Text_JacobIntro, Route110_Text_JacobDefeated
	msgbox Route110_Text_JacobPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Anthony::
	trainerbattle_single TRAINER_ANTHONY, Route110_Text_AnthonyIntro, Route110_Text_AnthonyDefeated
	msgbox Route110_Text_AnthonyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Benjamin::
	trainerbattle_single TRAINER_BENJAMIN_1, Route110_Text_BenjaminIntro, Route110_Text_BenjaminDefeated, Route110_EventScript_BenjaminRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route110_EventScript_BenjaminRematch
	msgbox Route110_Text_BenjaminPostBattle, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_BenjaminRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route110_Text_BenjaminRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_BENJAMIN_1
	release
	end

Route110_EventScript_BenjaminRematch::
	trainerbattle_rematch TRAINER_BENJAMIN_1, Route110_Text_BenjaminRematchIntro, Route110_Text_BenjaminRematchDefeated
	msgbox Route110_Text_BenjaminRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Jasmine::
	trainerbattle_single TRAINER_JASMINE, Route110_Text_JasmineIntro, Route110_Text_JasmineDefeated
	msgbox Route110_Text_JasminePostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Abigail::
	trainerbattle_single TRAINER_ABE, Route110_Text_AbigailIntro, Route110_Text_AbigailDefeated, Route110_EventScript_AbigailRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route110_EventScript_AbigailRematch
	msgbox Route110_Text_AbigailPostBattle, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_AbigailRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route110_Text_AbigailRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ABE
	release
	end

Route110_EventScript_AbigailRematch::
	trainerbattle_rematch TRAINER_ABE, Route110_Text_AbigailRematchIntro, Route110_Text_AbigailRematchDefeated
	msgbox Route110_Text_AbigailRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Isabel::
	trainerbattle_single TRAINER_LTSURGE, Route110_Text_IsabelIntro, Route110_Text_IsabelDefeated, Route110_EventScript_IsabelRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route110_EventScript_IsabelRematch
	msgbox Route110_Text_IsabelPostBattle, MSGBOX_DEFAULT
	release
	end

Route110_EventScript_IsabelRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route110_Text_IsabelRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_LTSURGE
	release
	end

Route110_EventScript_IsabelRematch::
	trainerbattle_rematch TRAINER_LTSURGE, Route110_Text_IsabelRematchIntro, Route110_Text_IsabelRematchDefeated
	msgbox Route110_Text_IsabelRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Timmy::
	trainerbattle_single TRAINER_TIMMY, Route110_Text_TimmyIntro, Route110_Text_TimmyDefeated
	msgbox Route110_Text_TimmyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Unused::
	end

Route110_EventScript_Kaleb::
	trainerbattle_single TRAINER_KALEB, Route110_Text_KalebIntro, Route110_Text_KalebDefeated
	msgbox Route110_Text_KalebPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Joseph::
	trainerbattle_single TRAINER_JOSEPH, Route110_Text_JosephIntro, Route110_Text_JosephDefeated
	msgbox Route110_Text_JosephPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_Alyssa::
	trainerbattle_single TRAINER_BRAD, Route110_Text_AlyssaIntro, Route110_Text_AlyssaDefeated
	msgbox Route110_Text_AlyssaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_EventScript_CyclingChallengeEnd::
	lockall
	applymovement LOCALID_CHALLENGE_BIKER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	call Route110_EventScript_CyclingChallengeResults
	releaseall
	end

Route110_EventScript_CyclingChallengeResults::
	special FinishCyclingRoadChallenge
	msgbox Route110_Text_CyclingChallengeResultSummary, MSGBOX_DEFAULT
	switch VAR_RESULT
	case 10, Route110_EventScript_ChallengeReactionBest
	case 9, Route110_EventScript_ChallengeReactionGood
	case 8, Route110_EventScript_ChallengeReactionGood
	case 7, Route110_EventScript_ChallengeReactionGood
	case 6, Route110_EventScript_ChallengeReactionOk
	case 5, Route110_EventScript_ChallengeReactionOk
	case 4, Route110_EventScript_ChallengeReactionOk
	case 3, Route110_EventScript_ChallengeReactionBad
	case 2, Route110_EventScript_ChallengeReactionBad
	case 1, Route110_EventScript_ChallengeReactionBad
	case 0, Route110_EventScript_ChallengeReactionWorst
	end

Route110_EventScript_ChallengeReactionBest::
	msgbox Route110_Text_ChallengeReactionBest, MSGBOX_DEFAULT
	goto Route110_EventScript_EndChallenge
	end

Route110_EventScript_ChallengeReactionGood::
	msgbox Route110_Text_ChallengeReactionGood, MSGBOX_DEFAULT
	goto Route110_EventScript_EndChallenge
	end

Route110_EventScript_ChallengeReactionOk::
	msgbox Route110_Text_ChallengeReactionOk, MSGBOX_DEFAULT
	goto Route110_EventScript_EndChallenge
	end

Route110_EventScript_ChallengeReactionBad::
	msgbox Route110_Text_ChallengeReactionBad, MSGBOX_DEFAULT
	goto Route110_EventScript_EndChallenge
	end

Route110_EventScript_ChallengeReactionWorst::
	msgbox Route110_Text_ChallengeReactionWorst, MSGBOX_DEFAULT
	goto Route110_EventScript_EndChallenge
	end

Route110_EventScript_EndChallenge::
	setvar VAR_CYCLING_CHALLENGE_STATE, 3
	savebgm MUS_DUMMY
	fadedefaultbgm
	return

Route110_EventScript_RivalTrigger1::
	setvar VAR_0x8008, 1
	setflag FLAG_INCREASE_DIFFICULTY
	goto Route110_EventScript_RivalScene
	end

Route110_EventScript_RivalTrigger2::
	setvar VAR_0x8008, 2
	setflag FLAG_INCREASE_DIFFICULTY
	goto Route110_EventScript_RivalScene
	end

Route110_EventScript_RivalTrigger3::
	setvar VAR_0x8008, 3
	setflag FLAG_INCREASE_DIFFICULTY
	goto Route110_EventScript_RivalScene
	end

Route110_EventScript_RivalScene::
	lockall
	checkplayergender
	call_if_eq VAR_RESULT, MALE, Route110_EventScript_PlayMayMusic
	call_if_eq VAR_RESULT, FEMALE, Route110_EventScript_PlayBrendanMusic
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	delay 30
	call_if_eq VAR_0x8008, 1, Route110_EventScript_RivalApproachPlayer1
	call_if_eq VAR_0x8008, 2, Route110_EventScript_RivalApproachPlayer2
	call_if_eq VAR_0x8008, 3, Route110_EventScript_RivalApproachPlayer3
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, Route110_EventScript_MayBattle
	goto_if_eq VAR_RESULT, FEMALE, Route110_EventScript_BrendanBattle
	releaseall
	end

Route110_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	return

Route110_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	return

Route110_EventScript_MayBattle::
	msgbox Route110_Text_MayLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route110_EventScript_MayBattleTreecko
	case 1, Route110_EventScript_MayBattleTorchic
	case 2, Route110_EventScript_MayBattleMudkip
	end

Route110_EventScript_MayBattleTreecko::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_110_TREECKO, Route110_Text_MayDefeated
	goto Route110_EventScript_MayDefeated
	end

Route110_EventScript_MayBattleTorchic::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_110_TORCHIC, Route110_Text_MayDefeated
	goto Route110_EventScript_MayDefeated
	end

Route110_EventScript_MayBattleMudkip::
	trainerbattle_no_intro TRAINER_MAY_ROUTE_110_MUDKIP, Route110_Text_MayDefeated
	goto Route110_EventScript_MayDefeated
	end

Route110_EventScript_MayDefeated::
	msgbox Route110_Text_MayTakeThis, MSGBOX_DEFAULT
	call Route110_EventScript_GiveItemfinder
	msgbox Route110_Text_MayExplainItemfinder, MSGBOX_DEFAULT
	goto Route110_EventScript_RivalExit
	end

Route110_EventScript_BrendanBattle::
	msgbox Route110_Text_BrendanLetsBattle, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, Route110_EventScript_BrendanBattleTreecko
	case 1, Route110_EventScript_BrendanBattleTorchic
	case 2, Route110_EventScript_BrendanBattleMudkip
	end

Route110_EventScript_BrendanBattleTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_TREECKO, Route110_Text_BrendanDefeated
	goto Route110_EventScript_BrendanDefeated
	end

Route110_EventScript_BrendanBattleTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_ROUTE_110_TORCHIC, Route110_Text_BrendanDefeated
	goto Route110_EventScript_BrendanDefeated
	end

Route110_EventScript_BrendanBattleMudkip::
	trainerbattle_no_intro TRAINER_DUFF_AND_EDA, Route110_Text_BrendanDefeated
	goto Route110_EventScript_BrendanDefeated
	end

Route110_EventScript_BrendanDefeated::
	msgbox Route110_Text_BrendanTakeThis, MSGBOX_DEFAULT
	call Route110_EventScript_GiveItemfinder
	msgbox Route110_Text_BrendanExplainItemfinder, MSGBOX_DEFAULT
	goto Route110_EventScript_RivalExit
	end

Route110_EventScript_GiveItemfinder::
	giveitem ITEM_ITEMFINDER
	return

Route110_EventScript_RivalExit::
	closemessage
	call_if_eq VAR_0x8008, 1, Route110_EventScript_MoveRival1
	call_if_eq VAR_0x8008, 2, Route110_EventScript_MoveRival2
	call_if_eq VAR_0x8008, 3, Route110_EventScript_MoveRival3
	setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_FACE_RIGHT
	setobjectmovementtype LOCALID_RIVAL_ON_BIKE, MOVEMENT_TYPE_FACE_RIGHT
	removeobject LOCALID_RIVAL
	addobject LOCALID_RIVAL_ON_BIKE
	delay 45
	call_if_eq VAR_0x8008, 1, Route110_EventScript_RivalExit1
	call_if_eq VAR_0x8008, 2, Route110_EventScript_RivalExit2
	call_if_eq VAR_0x8008, 3, Route110_EventScript_RivalExit3
	removeobject LOCALID_RIVAL_ON_BIKE
	setvar VAR_GARBAGEVAR, 1
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

Route110_EventScript_RivalApproachPlayer1::
	applymovement LOCALID_RIVAL, Route110_Movement_RivalApproachPlayer1
	waitmovement 0
	return

Route110_EventScript_RivalApproachPlayer2::
	applymovement LOCALID_RIVAL, Route110_Movement_RivalApproachPlayer2
	waitmovement 0
	return

Route110_EventScript_RivalApproachPlayer3::
	applymovement LOCALID_RIVAL, Route110_Movement_RivalApproachPlayer3
	waitmovement 0
	return

Route110_EventScript_RivalExit1::
	applymovement LOCALID_RIVAL_ON_BIKE, Route110_Movement_RivalExit1
	waitmovement 0
	return

Route110_EventScript_RivalExit2::
	applymovement LOCALID_RIVAL_ON_BIKE, Route110_Movement_RivalExit2
	waitmovement 0
	return

Route110_EventScript_RivalExit3::
	applymovement LOCALID_RIVAL_ON_BIKE, Route110_Movement_RivalExit3
	waitmovement 0
	return

Route110_EventScript_MoveRival1::
	setobjectxyperm LOCALID_RIVAL_ON_BIKE, 33, 55
	return

Route110_EventScript_MoveRival2::
	setobjectxyperm LOCALID_RIVAL_ON_BIKE, 34, 55
	return

Route110_EventScript_MoveRival3::
	setobjectxyperm LOCALID_RIVAL_ON_BIKE, 35, 55
	return

Route110_Movement_RivalApproachPlayer1:
	walk_down
	walk_left
	walk_in_place_faster_down
	step_end

Route110_Movement_RivalApproachPlayer2:
	walk_down
	step_end

Route110_Movement_RivalApproachPlayer3:
	walk_down
	walk_right
	walk_in_place_faster_down
	step_end

Route110_Movement_RivalExit1:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route110_Movement_RivalExit2:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_down
	step_end

Route110_Movement_RivalExit3:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

Route110_EventScript_BirchScene1::
	lockall
	setvar VAR_0x8008, 1
	goto Route110_EventScript_BirchScene

Route110_EventScript_BirchScene2::
	lockall
	setvar VAR_0x8008, 2
	goto Route110_EventScript_BirchScene

Route110_EventScript_BirchScene3::
	lockall
	setvar VAR_0x8008, 3
	goto Route110_EventScript_BirchScene

Route110_EventScript_BirchScene4::
	lockall
	setvar VAR_0x8008, 4
	goto Route110_EventScript_BirchScene

Route110_EventScript_BirchScene::
	addobject LOCALID_BIRCH
	applymovement LOCALID_BIRCH, Route110_Movement_BirchEntrance
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_BIRCH, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_BIRCH, Common_Movement_Delay48
	waitmovement 0
	call_if_eq VAR_0x8008, 1, Route110_EventScript_BirchApproachPlayer1
	call_if_eq VAR_0x8008, 2, Route110_EventScript_BirchApproachPlayer2
	call_if_eq VAR_0x8008, 3, Route110_EventScript_BirchApproachPlayer3
	call_if_eq VAR_0x8008, 4, Route110_EventScript_BirchApproachPlayer4
	msgbox Route110_Text_ImagineSeeingYouHere, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 10
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 20
	applymovement LOCALID_BIRCH, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	msgbox Route110_Text_HeardYouInstallMatchCall, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox Route110_Text_RegisteredBirchInPokenav, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_PROF_BIRCH_MATCH_CALL
	msgbox Route110_Text_KeepAnEyeOutForRival, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 1, Route110_EventScript_BirchExit1
	call_if_eq VAR_0x8008, 2, Route110_EventScript_BirchExit2
	call_if_eq VAR_0x8008, 3, Route110_EventScript_BirchExit3
	call_if_eq VAR_0x8008, 4, Route110_EventScript_BirchExit4
	removeobject LOCALID_BIRCH
	setvar VAR_REGISTER_BIRCH_STATE, 2
	releaseall
	end

Route110_EventScript_BirchApproachPlayer1::
	applymovement LOCALID_BIRCH, Route110_Movement_BirchApproachPlayer1
	waitmovement 0
	return

Route110_EventScript_BirchApproachPlayer2::
	applymovement LOCALID_BIRCH, Route110_Movement_BirchApproachPlayer2
	waitmovement 0
	return

Route110_EventScript_BirchApproachPlayer3::
	applymovement LOCALID_BIRCH, Route110_Movement_BirchApproachPlayer3
	waitmovement 0
	return

Route110_EventScript_BirchApproachPlayer4::
	applymovement LOCALID_BIRCH, Route110_Movement_BirchApproachPlayer4
	waitmovement 0
	return

Route110_EventScript_BirchExit1::
	applymovement LOCALID_BIRCH, Route110_Movement_BirchExit1
	waitmovement 0
	return

Route110_EventScript_BirchExit2::
	applymovement LOCALID_BIRCH, Route110_Movement_BirchExit2
	waitmovement 0
	return

Route110_EventScript_BirchExit3::
	applymovement LOCALID_BIRCH, Route110_Movement_BirchExit3
	waitmovement 0
	return

Route110_EventScript_BirchExit4::
	applymovement LOCALID_BIRCH, Route110_Movement_BirchExit4
	waitmovement 0
	return

Route110_Movement_BirchEntrance:
	walk_down
	walk_down
	walk_down
	step_end

Route110_Movement_BirchApproachPlayer1:
	walk_down
	walk_left
	walk_left
	walk_down
	step_end

Route110_Movement_BirchApproachPlayer2:
	walk_down
	walk_left
	walk_down
	step_end

Route110_Movement_BirchApproachPlayer3:
	walk_down
	walk_down
	step_end

Route110_Movement_BirchApproachPlayer4:
	walk_down
	walk_right
	walk_down
	step_end

Route110_Movement_BirchExit1:
	walk_up
	walk_up
	walk_right
	walk_up
	walk_up
	walk_up
	step_end

Route110_Movement_BirchExit2:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route110_Movement_BirchExit3:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route110_Movement_BirchExit4:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

Route110_Text_WeCantTalkAboutAquaActivities:
	.string "Les activités de la TEAM AQUA…\n"
	.string "On ne peut pas en parler encore.$"

Route110_Text_KickUpARuckus:
	.string "Je veux aller à POIVRESSEL\n"
	.string "et faire du grabuge !$"

Route110_Text_MyFirstJobInAqua:
	.string "C'est mon premier boulot après avoir rejoint\n"
	.string "la TEAM AQUA. C'est un peu effrayant.$"

Route110_Text_AquaActionsBringSmiles:
	.string "Les actions de la TEAM AQUA devraient\n"
	.string "apporter le sourire aux gens !$"

Route110_Text_MayLetsBattle:
	.string "FLORA : Salut, {PLAYER}{KUN}, ça fait longtemps !\p"
	.string "En cherchant d'autres POKéMON,\n"
	.string "les miens sont devenus plus forts.\p"
	.string "Alors…\n"
	.string "Que dirais-tu d'un petit combat ?$"

Route110_Text_MayDefeated:
	.string "Aïe !\n"
	.string "Tu es meilleur que je ne le pensais !$"

Route110_Text_MayTakeThis:
	.string "FLORA : {PLAYER}{KUN}, tu t'es bien\n"
	.string "entraîné aussi, n'est-ce pas ? Je\p"
	.string "crois que tu mérites une récompense\n"
	.string "! C'est de ma part !$"

Route110_Text_MayExplainItemfinder:
	.string "FLORA : C'est un CHERCH'OBJET.\p"
	.string "Essaie-le. S'il y a un objet invisible,\n"
	.string "il émet un son.\p"
	.string "D'accord, {PLAYER}{KUN}, on se\p"
	.string "revoit !\n"
	.string "Je sais que c'est un peu bizarre\l"
	.string "venant de moi, mais je pense que tu devrais t'entraîner beaucoup plus pour la prochaine fois.$"

Route110_Text_BrendanLetsBattle:
	.string "BRENDAN : Hé, {PLAYER}.\n"
	.string "Alors c'est ici que tu étais.\l"
	.string "Comment ça va ?\p"
	.string "Tu as bien élevé tes POKéMON ?\n"
	.string "Je vais vérifier pour toi.$"

Route110_Text_BrendanDefeated:
	.string "Hmm…\n"
	.string "Tu es plutôt fort.$"

Route110_Text_BrendanTakeThis:
	.string "BRENDAN : {PLAYER}, tu t'es entraîné\n"
	.string "sans que je m'en aperçoive…\p"
	.string "Bien joué !\n"
	.string "Tiens, prends ça.$"

Route110_Text_BrendanExplainItemfinder:
	.string "BRICE : C'est un CHASSEUR.\p"
	.string "Utilise-le pour chercher des objets\n"
	.string "qui ne sont pas visibles.\p"
	.string "S'il détecte quelque chose, il émet\n"
	.string "un son.\p"
	.string "Bref, je pars chercher de nouveaux\n"
	.string "POKéMON.$"

Route110_Text_RideBikeAtFullSpeed:
	.string "Ce serait génial de rouler à pleine vitesse\n"
	.string "sur la PISTE CYCLABLE en BICYCLETTE !$"

Route110_Text_HairStreamsBehindMe:
	.string "Comment trouves-tu la façon dont mes cheveux\n"
	.string "noirs flottent derrière moi ?\p"
	.string "Je les ai laissés pousser juste pour ça.$"

Route110_Text_YouGotBikeFromRydel:
	.string "Oh, hé, tu as ce VÉLO de RYDEL !\p"
	.string "Oh, c'est flagrant.\n"
	.string "C'est écrit sur ton vélo…\p"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\n"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\p"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\n"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\p"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\n"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\p"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\n"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL,\p"
	.string "RYDEL, RYDEL, RYDEL, RYDEL, RYDEL…\n"
	.string "Ce nom est partout.\p"
	.string "Tu devrais rouler partout--c'est une bonne\n"
	.string "publicité !$"

Route110_Text_TwoRoads:
	.string "Les deux routes, l'une en haut, l'autre en bas...\p"
	.string "Une route pour les humains, une pour les POKéMON.\n"
	.string "C'est peut-être juste et équitable.$"

Route110_Text_WalkOnTheLowRoad:
	.string "Je n'ai pas de BICYCLETTE, alors je vais\n"
	.string "me promener tranquillement sur le chemin du bas.$"

Route110_Text_BikeTechniques:
	.string "Apprendre des techniques rendra la conduite\n"
	.string "en VÉLO encore plus amusante.\p"
	.string "Il y a des endroits que tu ne peux\n"
	.string "atteindre qu'en utilisant une technique VÉLO.$"

Route110_Text_WhichShouldIChoose:
	.string "Que dois-je choisir ? Foncer vers\p"
	.string "LAVANDIA sur la PISTE CYCLABLE,\n"
	.string "ou prendre le chemin bas\l"
	.string "et chercher des POKéMON ?$"

Route110_Text_CyclingChallengeResultSummary:
	.string "Nombre de collisions :\n"
	.string "… … {STR_VAR_1} !\p"
	.string "Temps total :\n"
	.string "… … {STR_VAR_2} !$"

Route110_Text_ChallengeReactionBest:
	.string "Bravo ! Splendide performance ! Ton amour\p"
	.string "du cyclisme vient du fond de\n"
	.string "ton cœur. Tu m'as secoué jusqu'au\l"
	.string "plus profond de mon âme !$"

Route110_Text_ChallengeReactionGood:
	.string "Ta technique est remarquable.\p"
	.string "Je te suggère d'accélérer un peu tout en\n"
	.string "évitant les collisions.$"

Route110_Text_ChallengeReactionOk:
	.string "Je te considérerais comme un travail\n"
	.string "en cours.\p"
	.string "Quand même, j'espère que tu n'oublieras pas\n"
	.string "le pur plaisir du vélo.$"

Route110_Text_ChallengeReactionBad:
	.string "Mon Dieu... Tes talents en vélo frôlent\n"
	.string "le terrifiant.\p"
	.string "Certainement, tu as besoin de beaucoup\n"
	.string "plus de pratique.$"

Route110_Text_ChallengeReactionWorst:
	.string "…Je suis consterné…\p"
	.string "Tu n'es peut-être pas fait pour cette\n"
	.string "malheureuse affaire de cyclisme.\p"
	.string "Tu devrais sérieusement envisager de\n"
	.string "rendre ce VÉLO à RYDEL.$"

Route110_Text_RatedForNumberOfCollisions:
	.string "C'est la PISTE CYCLABLE.\p"
	.string "Si tu parcourais la ROUTE 110 de LAVANDIA\n"
	.string "à POIVRESSEL sur un VÉLO COURSE, tu serais\l"
	.string "évalué sur le nombre de collisions\l"
	.string "et ton temps total.$"

Route110_Text_AlwaysAimHigher:
	.string "Quel que soit le résultat, je compte sur\n"
	.string "d'autres défis de ta part.\l"
	.string "Vise toujours plus haut !$"

Route110_Text_AcroBikesDoNotQualify:
	.string "Sur cette PISTE CYCLABLE, ceux qui roulent\n"
	.string "en MOTOBYCLISSE sont notés selon leur nombre\l"
	.string "de collisions et leur temps total. Les\p"
	.string "MOTOS-CRO sont exclues du classement. Elles tournent\n"
	.string "facilement, ce ne serait pas juste.$"

Route110_Text_SlateportCitySign:
	.string "ROUTE 110\n"
	.string "{DOWN_ARROW} POIVRESSE$"

Route110_Text_CyclingRoadSign:
	.string "PISTE CYCLABLE CÔTIÈRE$"

Route110_Text_AquaWasHere:
	.string "« La TEAM AQUA était ici ! »\p"
	.string "Quelqu'un a peint ça sur ce panneau,\n"
	.string "mais quelqu'un d'autre l'a recouvert.\p"
	.string "« La TEAM MAGMA règne ! »\n"
	.string "c'est ce qui est écrit maintenant.$"

Route110_Text_Route103Sign:
	.string "ROUTE 110\n"
	.string "{LEFT_ARROW} ROUTE 103$"

Route110_Text_SeasideParkingSign:
	.string "PARKING CÔTIER$"

Route110_Text_MauvilleCitySign:
	.string "ROUTE 110\n"
	.string "{UP_ARROW} MAUVILLE$"

Route110_Text_TrainerTipsPrlzSleep:
	.string "CONSEILS DRESSEUR\p"
	.string "L'ennemi peut être rendu inoffensif en\n"
	.string "le paralysant ou en l'endormant.\p"
	.string "C'est une technique importante pour\n"
	.string "les combats de POKéMON.$"

Route110_Text_TrainerTipsRegisterItems:
	.string "CONSEILS DRESSEUR\p"
	.string "Les objets du SAC peuvent être réorganisés\n"
	.string "en appuyant sur SELECT.$"

Route110_Text_TrickHouseSign:
	.string "« Trois pas {RIGHT_ARROW} et deux pas {UP_ARROW}\n"
	.string "pour atteindre la merveilleuse MAISON DES PIÈGES. »$"

Route110_Text_BestRecord:
	.string "LE MEILLEUR RECORD À CE JOUR…\p"
	.string "Nb de collisions : {STR_VAR_1}\p"
	.string "Temps écoulé : {STR_VAR_2}$"

Route110_Text_ThereIsNoRecord:
	.string "LE MEILLEUR RECORD À CE JOUR…\p"
	.string "Personne ne semble avoir relevé le\n"
	.string "défi. Il n'y a pas de record…$"

Route110_Text_ImagineSeeingYouHere:
	.string "PROF. SEKO : Oh, {PLAYER}{KUN} !\n"
	.string "Imagine te voir ici !\p"
	.string "Et où serait mon ARGENT ?$"

Route110_Text_HeardYouInstallMatchCall:
	.string "Oh, je vois !\n"
	.string "Vous deux\l"
	.string "courez\p"
	.string "séparément.\n"
	.string "Bien,\p"
	.string "c'est bien.\n"
	.string "Oh, oui,\p"
	.string "j'ai entendu\n"
	.string "que ton POKéNAV\p"
	.string "a été amélioré !$"

Route110_Text_RegisteredBirchInPokenav:
	.string "PROF. SEKO enregistré\n"
	.string "dans le POKéNAV.$"

Route110_Text_KeepAnEyeOutForRival:
	.string "PROF. SEKO : {PLAYER}{KUN}…\p"
	.string "Garde un œil sur mon ARGENT, s'il te plaît.\n"
	.string "… … … … … …\p"
	.string "Bon, je ferais mieux d'y aller.\n"
	.string "À bientôt, {PLAYER}{KUN} !$"

