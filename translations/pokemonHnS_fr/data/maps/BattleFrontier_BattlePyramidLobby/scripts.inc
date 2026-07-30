.set LOCALID_ATTENDANT, 1
.set LOCALID_HINT_GIVER, 2

BattleFrontier_BattlePyramidLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleDomeLobby_OnWarp
	.byte 0

@ Unused. Pyramid uses Dome's OnWarp (presumably by mistake). Their effects are identical
BattleFrontier_BattlePyramidLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePyramidLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattlePyramidLobby_EventScript_TurnPlayerNorth:
	setvar VAR_TEMP_1, 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePyramidLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattlePyramidLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePyramidLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePyramidLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattlePyramidLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattlePyramidLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattlePyramidLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattlePyramidLobby_EventScript_QuitWithoutSaving::
	lockall
	message BattleFrontier_BattlePyramidLobby_Text_DidntSaveBeforeQuittingTakeBag
	waitmessage
	playse SE_EXP_MAX
	waitse
	closemessage
	pyramid_set PYRAMID_DATA_WIN_STREAK, 0
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_DefeatedKing
	msgbox BattleFrontier_BattlePyramidLobby_Text_YouveConqueredPyramid, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_GiveBattlePoints

BattleFrontier_BattlePyramidLobby_EventScript_DefeatedKing::
	msgbox BattleFrontier_BattlePyramidLobby_Text_YouveDefeatedPyramidKing, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_GiveBattlePoints::
	special DoBattlePyramidMonsHaveHeldItem
	call_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_StoreHeldItemsInPyramidBag
	clearflag FLAG_STORING_ITEMS_IN_PYRAMID_BAG
	frontier_checkairshow
	special LoadPlayerParty
	pyramid_clearhelditems
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	message BattleFrontier_BattlePyramidLobby_Text_UsedBattleBagWillBeKept
	waitmessage
	playse SE_EXP_MAX
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_GiveYouTheseBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait
	waitmessage
	pyramid_setprize
	pyramid_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_LostChallenge::
	frontier_checkairshow
	special LoadPlayerParty
	pyramid_clearhelditems
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	lockall
	message BattleFrontier_BattlePyramidLobby_Text_DisappointingHereIsBag
	waitmessage
	playse SE_EXP_MAX
	waitse
	message BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait
	waitmessage
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, FALSE
	pyramid_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_ResumeChallenge::
	goto BattleFrontier_BattlePyramidLobby_EventScript_EnterChallenge

BattleFrontier_BattlePyramidLobby_EventScript_Attendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PYRAMID
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	special SavePlayerParty
	msgbox BattleFrontier_BattlePyramidLobby_Text_WelcomeToBattlePyramid, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_AskTakeChallenge::
	message BattleFrontier_BattlePyramidLobby_Text_EmbarkOnChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattlePyramidLobby_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattlePyramidLobby_Text_SelectThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	callnative RemoveFollowingPokemon
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge
	msgbox BattleFrontier_BattlePyramidLobby_Text_OkayToSaveBeforeChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattlePyramidLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	pyramid_init
	pyramid_set PYRAMID_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	pyramid_seedfloor
	pyramid_settrainers
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_CancelChallengeSaveFailed
BattleFrontier_BattlePyramidLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattlePyramidLobby_Text_ShowYouIntoPyramid, MSGBOX_DEFAULT
	closemessage
	call BattleFrontier_BattlePyramidLobby_EventScript_WalkToPanelAndReceiveBag
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_RESULT, 0
	special HealPlayerParty
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR, 1, 1
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattlePyramidLobby_EventScript_ExplainChallenge::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainBattlePyramid, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_AskTakeChallenge

BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge

BattleFrontier_BattlePyramidLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
BattleFrontier_BattlePyramidLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattlePyramidLobby_Text_AwaitFutureChallenge, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattlePyramidLobby_EventScript_HintGiver::
	lockall
	applymovement LOCALID_HINT_GIVER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidLobby_Text_TellYouWhatMisfortunesAwait, MSGBOX_DEFAULT
	call BattleFrontier_BattlePyramidLobby_EventScript_GiveHint
	msgbox BattleFrontier_BattlePyramidLobby_Text_BelieveMyFortunesOrNot, MSGBOX_DEFAULT
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_GiveHint::
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLvOpen
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePyramidLobby_EventScript_NoHint
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_NoHint
	return

@ Shouldnt occur
BattleFrontier_BattlePyramidLobby_EventScript_NoHint::
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLv50::
	msgbox BattleFrontier_BattlePyramidLobby_Text_Aah, MSGBOX_DEFAULT
	pyramid_get PYRAMID_DATA_WIN_STREAK_ACTIVE_50
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLv50Streak
	setvar VAR_RESULT, 0
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLv50Streak::
	pyramid_get PYRAMID_DATA_WIN_STREAK_50
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintLvOpen::
	msgbox BattleFrontier_BattlePyramidLobby_Text_Aah, MSGBOX_DEFAULT
	pyramid_get PYRAMID_DATA_WIN_STREAK_ACTIVE_OPEN
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLvOpenStreak
	setvar VAR_RESULT, 0
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_GiveHintGetLvOpenStreak::
	pyramid_get PYRAMID_DATA_WIN_STREAK_OPEN
	goto BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment
	return

BattleFrontier_BattlePyramidLobby_EventScript_DoHintComment::
	copyvar VAR_0x8004, VAR_RESULT
	special GetBattlePyramidHint
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_HintParalysis
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_HintPoison
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_HintBurn
	case 3, BattleFrontier_BattlePyramidLobby_EventScript_HintPPWaste
	case 4, BattleFrontier_BattlePyramidLobby_EventScript_HintLevitate
	case 5, BattleFrontier_BattlePyramidLobby_EventScript_HintTrapAbility
	case 6, BattleFrontier_BattlePyramidLobby_EventScript_HintIce
	case 7, BattleFrontier_BattlePyramidLobby_EventScript_HintExplosion
	case 8, BattleFrontier_BattlePyramidLobby_EventScript_HintPsychic
	case 9, BattleFrontier_BattlePyramidLobby_EventScript_HintRock
	case 10, BattleFrontier_BattlePyramidLobby_EventScript_HintFighting
	case 11, BattleFrontier_BattlePyramidLobby_EventScript_HintWeather
	case 12, BattleFrontier_BattlePyramidLobby_EventScript_HintBug
	case 13, BattleFrontier_BattlePyramidLobby_EventScript_HintDark
	case 14, BattleFrontier_BattlePyramidLobby_EventScript_HintWater
	case 15, BattleFrontier_BattlePyramidLobby_EventScript_HintGhost
	case 16, BattleFrontier_BattlePyramidLobby_EventScript_HintSteel
	case 17, BattleFrontier_BattlePyramidLobby_EventScript_HintFlyingDragon
	case 18, BattleFrontier_BattlePyramidLobby_EventScript_HintStoneEvolve
	case 19, BattleFrontier_BattlePyramidLobby_EventScript_HintNormal
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintParalysis::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintParalysis, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintPoison::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPoison, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintBurn::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintBurn, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintPPWaste::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPPWaste, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintLevitate::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintLevitate, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintTrapAbility::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintTrapAbility, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintIce::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintIce, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintExplosion::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintExplosion, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintPsychic::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintPsychic, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintRock::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintRock, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintFighting::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintFighting, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintWeather::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintWeather, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintBug::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintBug, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintDark::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintDark, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintWater::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintWater, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintGhost::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintGhost, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintSteel::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintSteel, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintFlyingDragon::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintFlyingDragon, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintStoneEvolve::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintStoneEvolve, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_HintNormal::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HintNormal, MSGBOX_DEFAULT
	return

BattleFrontier_BattlePyramidLobby_EventScript_ShowResults::
	lockall
	frontier_results FRONTIER_FACILITY_PYRAMID
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePyramidLobby_EventScript_WalkToPanelAndReceiveBag::
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePyramidLobby_Movement_AttendantWalkToPanel
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePyramidLobby_Movement_PlayerWalkToPanel
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidLobby_Text_WeWillHoldBagForSafekeeping, MSGBOX_DEFAULT
	pyramid_get PYRAMID_DATA_WIN_STREAK
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_ReceiveNewBattleBag
	msgbox BattleFrontier_BattlePyramidLobby_Text_PleaseTakePreviousBattleBag, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReceiveBattleBag

BattleFrontier_BattlePyramidLobby_EventScript_ReceiveNewBattleBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_PleaseTakeThisBattleBag, MSGBOX_DEFAULT
BattleFrontier_BattlePyramidLobby_EventScript_ReceiveBattleBag::
	message BattleFrontier_BattlePyramidLobby_Text_ExchangedBagForBattleBag
	waitmessage
	playse SE_EXP_MAX
	waitse
	msgbox BattleFrontier_BattlePyramidLobby_Text_StepOnFloorPanel, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePyramidLobby_Movement_AttendantMoveAside
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePyramidLobby_Movement_PlayerStepOnPanel
	waitmovement 0
	return

BattleFrontier_BattlePyramidLobby_Movement_AttendantWalkToPanel:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	face_down
	step_end

BattleFrontier_BattlePyramidLobby_Movement_PlayerWalkToPanel:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePyramidLobby_Movement_AttendantMoveAside:
	walk_right
	face_left
	step_end

BattleFrontier_BattlePyramidLobby_Movement_PlayerStepOnPanel:
	walk_up
	walk_up
	step_end

BattleFrontier_BattlePyramidLobby_EventScript_StoreHeldItemsInPyramidBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_MonHoldingItemCannotTake, MSGBOX_DEFAULT
	setflag FLAG_STORING_ITEMS_IN_PYRAMID_BAG
	special TryStoreHeldItemsInPyramidBag
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidLobby_EventScript_HeldItemsStoredInPyramidBag
	message BattleFrontier_BattlePyramidLobby_Text_BagCannotHoldPickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_HeldItemsStoredInPyramidBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_HeldItemsMovedToBag, MSGBOX_DEFAULT
	return

@ When exiting Battle Pyramid with a full pyramid bag and held items the player must select to keep/toss party held items and make room for any kept items by tossing from the pyramid bag
BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep::
	multichoice 17, 6, MULTI_FRONTIER_ITEM_CHOOSE, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromBag
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromParty
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems
	end

BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromBag::
	special ChooseItemsToTossFromPyramidBag
	waitstate
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_PickItemsFromParty::
	special BattlePyramidChooseMonHeldItems
	waitstate
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_ExitPickItems::
	special DoBattlePyramidMonsHaveHeldItem
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePyramidLobby_EventScript_PartyStillHasHeldItems
	return

BattleFrontier_BattlePyramidLobby_EventScript_PartyStillHasHeldItems::
	msgbox BattleFrontier_BattlePyramidLobby_Text_LeastOneMonHoldingItem, MSGBOX_DEFAULT
	message BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep
	waitmessage
	goto BattleFrontier_BattlePyramidLobby_EventScript_PickItemsToKeep
	end

BattleFrontier_BattlePyramidLobby_EventScript_Woman::
	msgbox BattleFrontier_BattlePyramidLobby_Text_TrainersNoticeRunning, MSGBOX_NPC
	end

BattleFrontier_BattlePyramidLobby_EventScript_FatMan::
	msgbox BattleFrontier_BattlePyramidLobby_Text_LostLotOfItems, MSGBOX_NPC
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattlePyramidLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattlePyramidLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 15, 2, MULTI_BATTLE_PYRAMID_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePyramidLobby_EventScript_RulesPokemon
	case 1, BattleFrontier_BattlePyramidLobby_EventScript_RulesTrainers
	case 2, BattleFrontier_BattlePyramidLobby_EventScript_RulesMaze
	case 3, BattleFrontier_BattlePyramidLobby_EventScript_RulesBag
	case 4, BattleFrontier_BattlePyramidLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattlePyramidLobby_EventScript_ExitRules
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesPokemon::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainMonRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesTrainers::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainTrainerRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesMaze::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainMazeRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_RulesBag::
	msgbox BattleFrontier_BattlePyramidLobby_Text_ExplainBagRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePyramidLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattlePyramidLobby_Text_WelcomeToBattlePyramid:
	.string "Là où le courage des DRESSEURS\n"
	.string "est mis à l'épreuve ! Bienvenue\p"
	.string "à la PYRAMIDE DE COMBAT\p"
	.string "! Je suis votre guide\n"
	.string "pour la Quête de Combat.$"

BattleFrontier_BattlePyramidLobby_Text_EmbarkOnChallenge:
	.string "As-tu le courage de te lancer dans\n"
	.string "le défi Quête de Combat ?$"

BattleFrontier_BattlePyramidLobby_Text_AwaitFutureChallenge:
	.string "Nous attendons ton défi à l'avenir !$"

BattleFrontier_BattlePyramidLobby_Text_ExplainBattlePyramid:
	.string "La Quête de Combat est un événement\n"
	.string "de combat dans lequel tu dois explorer\l"
	.string "la PYRAMIDE et essayer d'atteindre le sommet.\p"
	.string "Dans la PYRAMIDE se trouvent sept étages\n"
	.string "de labyrinthes, tous remplis non seulement\l"
	.string "de DRESSEURS habiles mais aussi de POKéMON sauvages.\p"
	.string "Tu dois entrer avec trois POKéMON,\n"
	.string "aucun ne tenant d'objet.\p"
	.string "Pendant ton ascension, on te fournira\n"
	.string "un SAC DE COMBAT pour les objets.\p"
	.string "Si tu échoues dans ton défi, tout objet\n"
	.string "placé dans le SAC DE COMBAT disparaît.\p"
	.string "Si tu veux interrompre ton\n"
	.string "défi, tu dois sélectionner “REPOS”\l"
	.string "et sauvegarder la partie.\p"
	.string "Si tu ne sauvegardes pas avant d'interrompre,\n"
	.string "tu seras disqualifié.$"

BattleFrontier_BattlePyramidLobby_Text_WhichLevelMode:
	.string "La PYRAMIDE propose deux parcours,\n"
	.string "NORMAL et DIFFICILE.\l"
	.string "Lequel choisis-tu ?$"

BattleFrontier_BattlePyramidLobby_Text_SelectThreeMons:
	.string "Très bien. Maintenant, sélectionne les trois\n"
	.string "POKéMON qui t'accompagneront.$"

BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLvOpen:
	.string "Un léger problème, aventurier !\p"
	.string "Il semble que tu n'aies pas les\n"
	.string "trois POKéMON qualifiés pour le\p"
	.string "défi.\n"
	.string "N'oublie pas non plus de retirer\p"
	.string "tous les objets de tes POKéMON.\p"
	.string "Les OEUFS{STR_VAR_1} ne sont pas admis.\n"
	.string "Quand tu seras prêt, viens me parler.$"

BattleFrontier_BattlePyramidLobby_Text_NotEnoughValidMonsLv50:
	.string "A slight problem, adventurer!\p"
	.string "You seem to not have the three\n"
	.string "POKéMON qualified for the challenge.\p"
	.string "The three POKéMON must be different.\p"
	.string "Please also remember to take all\n"
	.string "items from your POKéMON.\p"
	.string "EGGS{STR_VAR_1} ineligible.\p"
	.string "When you are ready, please have\n"
	.string "a word with me.$"

BattleFrontier_BattlePyramidLobby_Text_OkayToSaveBeforeChallenge:
	.string "Avant d'entrer dans la PYRAMIDE DE COMBAT,\n"
	.string "la partie doit être sauvegardée. C'est bon ?$"

BattleFrontier_BattlePyramidLobby_Text_ShowYouIntoPyramid:
	.string "Très bien. Je vais maintenant vous faire entrer\n"
	.string "dans la PYRAMIDE DE COMBAT.$"

BattleFrontier_BattlePyramidLobby_Text_WeWillHoldBagForSafekeeping:
	.string "Nous garderons ton SAC en sécurité,\n"
	.string "{PLAYER}, pendant que tu explores.$"

BattleFrontier_BattlePyramidLobby_Text_PleaseTakePreviousBattleBag:
	.string "En échange, prends ce SAC DE COMBAT,\n"
	.string "celui que tu as utilisé précédemment.$"

BattleFrontier_BattlePyramidLobby_Text_PleaseTakeThisBattleBag:
	.string "En échange, prends ce\n"
	.string "SAC DE COMBAT.$"

BattleFrontier_BattlePyramidLobby_Text_ExchangedBagForBattleBag:
	.string "{PLAYER} a échangé le SAC contre\n"
	.string "le SAC DE COMBAT.$"

BattleFrontier_BattlePyramidLobby_Text_StepOnFloorPanel:
	.string "Quand tu marches sur ce panneau de sol,\n"
	.string "tu seras transporté à un étage\l"
	.string "supérieur de la PYRAMIDE.\p"
	.string "J'espère pour toi que ta\n"
	.string "quête se passe bien !$"

BattleFrontier_BattlePyramidLobby_Text_DidntSaveBeforeQuittingTakeBag:
	.string "Un gros problème, explorateur !\p"
	.string "Tu n'as pas sauvegardé avant de\n"
	.string "terminer ton défi la dernière fois.\p"
	.string "Par conséquent, ton défi a été\n"
	.string "disqualifié, je suis désolé de le\p"
	.string "dire.\n"
	.string "Voici le SAC que nous gardions\p"
	.string "pour toi. {PLAYER} a récupéré le SAC.$"

BattleFrontier_BattlePyramidLobby_Text_YouveConqueredPyramid:
	.string "Ravi de te revoir !\p"
	.string "Tu as conquis la PYRAMIDE !\n"
	.string "C'est splendide !$"

BattleFrontier_BattlePyramidLobby_Text_MonHoldingItemCannotTake:
	.string "Ah, un petit problème.\p"
	.string "Au moins un POKéMON tient\n"
	.string "un objet.\p"
	.string "Je suis désolé, les objets obtenus dans\n"
	.string "la PYRAMIDE ne peuvent pas être emportés.$"

BattleFrontier_BattlePyramidLobby_Text_HeldItemsMovedToBag:
	.string "Tous les objets tenus par tes POKéMON seront\n"
	.string "déplacés dans ton SAC DE COMBAT, {PLAYER}.$"

BattleFrontier_BattlePyramidLobby_Text_BagCannotHoldPickItemsToKeep:
	.string "Le SAC DE COMBAT ne peut pas contenir\n"
	.string "tous tes objets, je suis désolé.\p"
	.string "Choisis les objets que tu garderas dans\n"
	.string "le SAC DE COMBAT, ainsi que tes POKéMON.$"

BattleFrontier_BattlePyramidLobby_Text_LeastOneMonHoldingItem:
	.string "Au moins un POKéMON tient\n"
	.string "encore un objet.$"

BattleFrontier_BattlePyramidLobby_Text_PickItemsToKeep:
	.string "Choisis les objets que tu garderas dans le\n"
	.string "SAC DE COMBAT, ainsi qu'avec tes POKéMON.$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_ReturnedEverythingMonsHeld:
	.string "{PLAYER} a rendu tout ce que\n"
	.string "les POKéMON tenaient.$"

BattleFrontier_BattlePyramidLobby_Text_UsedBattleBagWillBeKept:
	.string "Le SAC DE COMBAT que tu as utilisé sera gardé\n"
	.string "en réserve pour ton prochain défi.\p"
	.string "{PLAYER} a rendu le SAC DE COMBAT\n"
	.string "pour récupérer son SAC.$"

BattleFrontier_BattlePyramidLobby_Text_RecordResultsWait:
	.string "Je dois enregistrer tes résultats.\n"
	.string "Patientez.$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_ForConqueringPyramidTakeThis:
	.string "En souvenir de ta conquête de la\n"
	.string "PYRAMIDE DE COMBAT, accepte ceci.$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_ReceivedPrizeItem:
	.string "{PLAYER} a reçu le prix\n"
	.string "{STR_VAR_1}.$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_BagIsFull:
	.string "…Ah…\n"
	.string "Ton SAC semble être plein.\p"
	.string "Reviens après avoir rangé\n"
	.string "le contenu de ton SAC.$"

BattleFrontier_BattlePyramidLobby_Text_DisappointingHereIsBag:
	.string "Quelle déception pour toi...\p"
	.string "Voici le SAC que nous gardions\n"
	.string "pour toi.\p"
	.string "{PLAYER} a récupéré le SAC.$"

BattleFrontier_BattlePyramidLobby_Text_LookForwardToNextChallenge:
	.string "Nous attendons avec impatience\n"
	.string "ton prochain défi !$"

@ Unused
BattleFrontier_BattlePyramidLobby_Text_HereIsPrize:
	.string "Nous attendions ta venue avec\n"
	.string "impatience !\p"
	.string "Voici ta récompense pour avoir conquis\n"
	.string "la PYRAMIDE.$"

BattleFrontier_BattlePyramidLobby_Text_TellYouWhatMisfortunesAwait:
	.string "Bienvenue…\p"
	.string "Je serai ravi de te dire quels malheurs\n"
	.string "t'attendent dans la PYRAMIDE…$"

BattleFrontier_BattlePyramidLobby_Text_Aah:
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "… … … … … …\n"
	.string "Aah !$"

BattleFrontier_BattlePyramidLobby_Text_HintParalysis:
	.string "Je vois une pluie d'étincelles…\p"
	.string "…Et dedans, je vois tes POKéMON\n"
	.string "lutter contre la paralysie…$"

BattleFrontier_BattlePyramidLobby_Text_HintPoison:
	.string "Je vois du poison…\p"
	.string "…Et je vois tes POKéMON souffrir\n"
	.string "des effets du poison…$"

BattleFrontier_BattlePyramidLobby_Text_HintBurn:
	.string "Je vois de vives flammes rouges…\p"
	.string "…Et je vois tes POKéMON souffrir\n"
	.string "de brûlures…$"

BattleFrontier_BattlePyramidLobby_Text_HintPPWaste:
	.string "Je sens la pression écrasante de\n"
	.string "la colère non assouvie…\p"
	.string "C'est une malédiction…\p"
	.string "…Et, je sens aussi\n"
	.string "une grande tristesse…\l"
	.string "C'est troublant…$"

BattleFrontier_BattlePyramidLobby_Text_HintLevitate:
	.string "Je vois des POKéMON planer majestueusement...\p"
	.string "...Et je vois tes POKéMON frustrés\n"
	.string "par des attaques SOL inefficaces...$"

BattleFrontier_BattlePyramidLobby_Text_HintTrapAbility:
	.string "Je sens une énergie formidable monter\n"
	.string "du sol en dessous… …Et je\p"
	.string "vois ton POKéMON incapable d'échapper\n"
	.string "à l'emprise de ce pouvoir…$"

BattleFrontier_BattlePyramidLobby_Text_HintIce:
	.string "Je vois des POKéMON de type GLACE…\p"
	.string "…Et je vois tes POKéMON lutter\n"
	.string "contre les effets du gel…$"

BattleFrontier_BattlePyramidLobby_Text_HintExplosion:
	.string "Je vois une rafale de capacités qui mettent\n"
	.string "l'utilisateur en danger…\p"
	.string "…Et je vois tes POKéMON succomber\n"
	.string "à ces capacités…$"

BattleFrontier_BattlePyramidLobby_Text_HintPsychic:
	.string "Je vois des POKéMON de type PSY…\p"
	.string "…Et je vois tes POKéMON en proie\n"
	.string "aux attaques de type PSY…$"

BattleFrontier_BattlePyramidLobby_Text_HintRock:
	.string "Je vois des POKéMON de type ROCHE…\p"
	.string "…Et je vois tes POKéMON souffrir\n"
	.string "des attaques de type ROCHE…$"

BattleFrontier_BattlePyramidLobby_Text_HintFighting:
	.string "Je vois des POKéMON de type COMBAT…\p"
	.string "…Et je vois tes POKéMON malmenés\n"
	.string "par les attaques de type COMBAT…$"

BattleFrontier_BattlePyramidLobby_Text_HintWeather:
	.string "DANSE PLUIE… ZÉNITH…\n"
	.string "TEMPÊTE DE SABLE… GRÊLE…\p"
	.string "Je vois des POKéMON qui deviennent plus forts\n"
	.string "avec la météo…\p"
	.string "…Et je vois tes POKéMON déconcertés\n"
	.string "par différents types d'attaques…$"

BattleFrontier_BattlePyramidLobby_Text_HintBug:
	.string "Je vois des POKéMON de type INSECTE…\p"
	.string "…Et je vois tes POKéMON souffrir\n"
	.string "à cause de différents types d'attaques…$"

BattleFrontier_BattlePyramidLobby_Text_HintDark:
	.string "Je vois des POKéMON de type TÉNÈBRES…\p"
	.string "…Et je vois tes POKéMON souffrir\n"
	.string "des attaques de type TÉNÈBRES…$"

BattleFrontier_BattlePyramidLobby_Text_HintWater:
	.string "Je vois des POKéMON de type EAU…\p"
	.string "…Et je vois tes POKéMON souffrir\n"
	.string "des attaques de type EAU…$"

BattleFrontier_BattlePyramidLobby_Text_HintGhost:
	.string "Je vois des POKéMON de type SPECTRE…\p"
	.string "…Et je vois tes POKéMON souffrir\n"
	.string "des attaques de type SPECTRE…$"

BattleFrontier_BattlePyramidLobby_Text_HintSteel:
	.string "Je vois des POKéMON de type ACIER…\p"
	.string "…Et je vois tes POKéMON souffrir\n"
	.string "à cause de capacités incroyablement puissantes…$"

BattleFrontier_BattlePyramidLobby_Text_HintFlyingDragon:
	.string "Je vois des POKéMON volants…\p"
	.string "…Et je vois tes POKéMON souffrir\n"
	.string "à cause de capacités incroyablement puissantes…$"

BattleFrontier_BattlePyramidLobby_Text_HintStoneEvolve:
	.string "Je vois ceux qui ont évolué grâce\n"
	.string "au pouvoir des pierres…\p"
	.string "Je sens aussi le feu, l'eau\n"
	.string "et l'électricité…\p"
	.string "…Et je vois tes POKéMON souffrir\n"
	.string "de ces trois pouvoirs…$"

BattleFrontier_BattlePyramidLobby_Text_HintNormal:
	.string "Je vois des POKéMON de type NORMAL…\p"
	.string "…Et je vois tes POKéMON souffrir\n"
	.string "à cause de capacités incroyablement puissantes…$"

BattleFrontier_BattlePyramidLobby_Text_BelieveMyFortunesOrNot:
	.string "Que tu croies ou non à mes prédictions,\n"
	.string "c'est ton choix…\p"
	.string "L'avenir peut changer à tout moment…\n"
	.string "Je te souhaite un bon voyage…$"

BattleFrontier_BattlePyramidLobby_Text_TrainersNoticeRunning:
	.string "Tu savais ? Si tu cours\p"
	.string "vite, les DRESSEURS peuvent le remarquer\n"
	.string "et te défier au combat.\p"
	.string "Alors, pour éviter les DRESSEURS,\n"
	.string "évite de croiser leur regard,\l"
	.string "mais passe discrètement et silencieusement.$"

BattleFrontier_BattlePyramidLobby_Text_LostLotOfItems:
	.string "Awaaaaaaarrrrgh !\p"
	.string "J'avais plein d'objets, mais je les ai tous\n"
	.string "perdus en perdant !\p"
	.string "Awaaaaaaarrrrgh !$"

BattleFrontier_BattlePyramidLobby_Text_YouveDefeatedPyramidKing:
	.string "Bon retour ! Tu as accompli\n"
	.string "l'impensable ! Tu as vaincu le\p"
	.string "ROI DE LA PYRAMIDE et conquis\n"
	.string "la PYRAMIDE DE COMBAT !$"

BattleFrontier_BattlePyramidLobby_Text_GiveYouTheseBattlePoints:
	.string "Jeune explorateur !\n"
	.string "En reconnaissance de ton courage,\l"
	.string "nous te donnons ces Points de Combat !$"

BattleFrontier_BattlePyramidLobby_Text_RulesAreListed:
	.string "Les règles de la Quête de Combat sont affichées.$"

BattleFrontier_BattlePyramidLobby_Text_ReadWhichHeading:
	.string "Quel titre veux-tu lire ?$"

BattleFrontier_BattlePyramidLobby_Text_ExplainMonRules:
	.string "Quand la PYRAMIDE est conquise,\n"
	.string "les POKéMON sauvages qui y apparaissent\l"
	.string "sont remplacés par d'autres espèces.\p"
	.string "Explore, observe et apprends quels\n"
	.string "types de POKéMON sauvages tu pourrais rencontrer.$"

BattleFrontier_BattlePyramidLobby_Text_ExplainTrainerRules:
	.string "Des DRESSEURS te guettent\n"
	.string "à l'intérieur de la PYRAMIDE.\p"
	.string "À chaque étage, il y a jusqu'à\n"
	.string "huit DRESSEURS.\p"
	.string "Quand tu bats un DRESSEUR, tu obtiens\n"
	.string "un indice utile pour ton aventure.$"

BattleFrontier_BattlePyramidLobby_Text_ExplainMazeRules:
	.string "Les labyrinthes de la PYRAMIDE se\n"
	.string "réorganisent à chaque entrée. Les labyrinthes\p"
	.string "sont mal éclairés. Tu dois\n"
	.string "avancer avec prudence. La lumière\p"
	.string "s'intensifie quand tu bats un\n"
	.string "POKéMON sauvage ou un DRESSEUR.$"

BattleFrontier_BattlePyramidLobby_Text_ExplainBagRules:
	.string "Le SAC DE COMBAT sert de SAC\n"
	.string "pendant que tu es\p"
	.string "dans la PYRAMIDE.\n"
	.string "Il y a deux SACS DE\l"
	.string "COMBAT séparés--\p"
	.string "un pour les objets tenus et\n"
	.string "un pour les\p"
	.string "objets de combat.\n"
	.string "Utilise-les stratégiquement !$"

