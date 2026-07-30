.set LOCALID_ATTENDANT, 1

VerdanturfTown_BattleTentLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VerdanturfTown_BattleTentLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, VerdanturfTown_BattleTentLobby_OnWarp
	.byte 0

VerdanturfTown_BattleTentLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, VerdanturfTown_BattleTentLobby_EventScript_TurnPlayerNorth
	.2byte 0

VerdanturfTown_BattleTentLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

VerdanturfTown_BattleTentLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, VerdanturfTown_BattleTentLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, VerdanturfTown_BattleTentLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, VerdanturfTown_BattleTentLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, VerdanturfTown_BattleTentLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, VerdanturfTown_BattleTentLobby_EventScript_LostChallenge
	.2byte 0

VerdanturfTown_BattleTentLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

VerdanturfTown_BattleTentLobby_EventScript_QuitWithoutSaving::
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_FailedToSaveBeforeEndingChallenge, MSGBOX_DEFAULT
	closemessage
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	releaseall
	end

VerdanturfTown_BattleTentLobby_EventScript_WonChallenge::
	lockall
	msgbox VerdanturfTown_BattleTentLobby_Text_AchievedThreeWinStreak, MSGBOX_DEFAULT
	message VerdanturfTown_BattleTentLobby_Text_FeatWillBeRecorded
	waitmessage
	verdanturftent_setrandomprize
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	verdanturftent_save 0
	playse SE_SAVE
	waitse

VerdanturfTown_BattleTentLobby_EventScript_GivePrize::
	msgbox VerdanturfTown_BattleTentLobby_Text_PresentYouWithPrize, MSGBOX_DEFAULT
	verdanturftent_giveprize
	switch VAR_RESULT
	case FALSE, VerdanturfTown_BattleTentLobby_EventScript_NoRoomForPrize
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	message BattleFrontier_BattleDomeLobby_Text_ReceivedPrize  @ Odd that it used Dome's copy instead of Palace's
	waitmessage
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	msgbox VerdanturfTown_BattleTentLobby_Text_ReturnFortified, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

VerdanturfTown_BattleTentLobby_EventScript_NoRoomForPrize::
	msgbox BattleFrontier_BattlePalaceLobby_Text_NoSpaceForPrize, MSGBOX_DEFAULT
	waitmessage
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

VerdanturfTown_BattleTentLobby_EventScript_PrizeWaiting::
	lockall
	msgbox VerdanturfTown_BattleTentLobby_Text_AchievedThreeWinStreak, MSGBOX_DEFAULT
	goto VerdanturfTown_BattleTentLobby_EventScript_GivePrize
	end

VerdanturfTown_BattleTentLobby_EventScript_LostChallenge::
	lockall
	message VerdanturfTown_BattleTentLobby_Text_ResultsWillBeRecorded
	waitmessage
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_50
	verdanturftent_save 0
	playse SE_SAVE
	waitse
	msgbox VerdanturfTown_BattleTentLobby_Text_ReturnFortified, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

VerdanturfTown_BattleTentLobby_EventScript_ResumeChallenge::
	lockall
	msgbox BattleFrontier_BattlePalaceLobby_Text_WeHaveBeenWaiting, MSGBOX_DEFAULT
	message BattleFrontier_BattlePalaceLobby_Text_MustSaveBeforeChallenge
	waitmessage
	verdanturftent_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto VerdanturfTown_BattleTentLobby_EventScript_EnterChallenge

VerdanturfTown_BattleTentLobby_EventScript_Attendant::
	lock
	faceplayer
	verdanturftent_getprize
	goto_if_ne VAR_RESULT, ITEM_NONE, VerdanturfTown_BattleTentLobby_EventScript_PrizeWaiting
	special SavePlayerParty
	msgbox VerdanturfTown_BattleTentLobby_Text_WelcomeToBattleTent, MSGBOX_DEFAULT
VerdanturfTown_BattleTentLobby_EventScript_AskEnterChallenge::
	message VerdanturfTown_BattleTentLobby_Text_TakeChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, VerdanturfTown_BattleTentLobby_EventScript_TryEnterChallenge
	case 1, VerdanturfTown_BattleTentLobby_EventScript_ExplainChallenge
	case 2, VerdanturfTown_BattleTentLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, VerdanturfTown_BattleTentLobby_EventScript_CancelChallenge

VerdanturfTown_BattleTentLobby_EventScript_TryEnterChallenge::
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PALACE
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	setvar VAR_RESULT, 2
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, VerdanturfTown_BattleTentLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, FRONTIER_LVL_TENT
	msgbox VerdanturfTown_BattleTentLobby_Text_SelectThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	callnative RemoveFollowingPokemon
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	goto_if_eq VAR_RESULT, 0, VerdanturfTown_BattleTentLobby_EventScript_LoadPartyCancelChallenge
	msgbox VerdanturfTown_BattleTentLobby_Text_SaveBeforeChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, VerdanturfTown_BattleTentLobby_EventScript_LoadPartyCancelChallenge
	case YES, VerdanturfTown_BattleTentLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, VerdanturfTown_BattleTentLobby_EventScript_LoadPartyCancelChallenge

VerdanturfTown_BattleTentLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	verdanturftent_init
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, VerdanturfTown_BattleTentLobby_EventScript_CancelChallengeSaveFailed
VerdanturfTown_BattleTentLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox VerdanturfTown_BattleTentLobby_Text_NowFollowMe, MSGBOX_DEFAULT
	closemessage
	call VerdanturfTown_BattleTentLobby_EventScript_WalkToDoor
	warp MAP_VERDANTURF_TOWN_BATTLE_TENT_CORRIDOR, 2, 7
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

VerdanturfTown_BattleTentLobby_EventScript_ExplainChallenge::
	msgbox VerdanturfTown_BattleTentLobby_Text_ExplainVerdanturfTent, MSGBOX_DEFAULT
	goto VerdanturfTown_BattleTentLobby_EventScript_AskEnterChallenge

VerdanturfTown_BattleTentLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, VerdanturfTown_BattleTentLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, VerdanturfTown_BattleTentLobby_EventScript_NotEnoughValidMonsLvOpen

VerdanturfTown_BattleTentLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox VerdanturfTown_BattleTentLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	goto VerdanturfTown_BattleTentLobby_EventScript_EndCancelChallenge

VerdanturfTown_BattleTentLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox VerdanturfTown_BattleTentLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	goto VerdanturfTown_BattleTentLobby_EventScript_EndCancelChallenge

VerdanturfTown_BattleTentLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto VerdanturfTown_BattleTentLobby_EventScript_CancelChallenge

VerdanturfTown_BattleTentLobby_EventScript_LoadPartyCancelChallenge::
	special LoadPlayerParty
VerdanturfTown_BattleTentLobby_EventScript_CancelChallenge::
	msgbox VerdanturfTown_BattleTentLobby_Text_ReturnFortified, MSGBOX_DEFAULT
VerdanturfTown_BattleTentLobby_EventScript_EndCancelChallenge::
	release
	end

VerdanturfTown_BattleTentLobby_EventScript_WalkToDoor::
	applymovement LOCALID_ATTENDANT, VerdanturfTown_BattleTentLobby_Movement_WalkToDoor
	applymovement OBJ_EVENT_ID_PLAYER, VerdanturfTown_BattleTentLobby_Movement_WalkToDoor
	waitmovement 0
	opendoor 6, 1
	waitdooranim
	applymovement LOCALID_ATTENDANT, VerdanturfTown_BattleTentLobby_Movement_AttendantEnterDoor
	applymovement OBJ_EVENT_ID_PLAYER, VerdanturfTown_BattleTentLobby_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 6, 1
	waitdooranim
	return

VerdanturfTown_BattleTentLobby_Movement_WalkToDoor:
	walk_up
	walk_up
	walk_up
	step_end

VerdanturfTown_BattleTentLobby_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end

VerdanturfTown_BattleTentLobby_Movement_PlayerEnterDoor:
	walk_up
	walk_up
	set_invisible
	step_end

VerdanturfTown_BattleTentLobby_EventScript_AttractGiver::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_ATTRACT, VerdanturfTown_BattleTentLobby_EventScript_ReceivedAttract
	msgbox VerdanturfTown_BattleTentLobby_Text_AttractionRunsDeep, MSGBOX_DEFAULT
	giveitem ITEM_TM_ATTRACT
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_ATTRACT
	msgbox VerdanturfTown_BattleTentLobby_Text_AttractionMutual, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_BattleTentLobby_EventScript_ReceivedAttract::
	msgbox VerdanturfTown_BattleTentLobby_Text_AttractionMutual, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_BattleTentLobby_EventScript_Boy1::
	msgbox VerdanturfTown_BattleTentLobby_Text_TaughtWhatKindsOfMoves, MSGBOX_NPC
	end

VerdanturfTown_BattleTentLobby_EventScript_Boy2::
	lock
	msgbox VerdanturfTown_BattleTentLobby_Text_MonsReluctantToUseDislikedMoves, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_BattleTentLobby_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_IN_VERDANTURF, VerdanturfTown_BattleTentLobby_EventScript_ScottAlreadySpokenTo
	msgbox VerdanturfTown_BattleTentLobby_Text_ScottCanMeetToughTrainers, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_IN_VERDANTURF
	release
	end

VerdanturfTown_BattleTentLobby_EventScript_ScottAlreadySpokenTo::
	msgbox VerdanturfTown_BattleTentLobby_Text_ScottVisitRegularly, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_BattleTentLobby_EventScript_LittleBoy::
	lock
	msgbox VerdanturfTown_BattleTentLobby_Text_GentleMonsScaryIfAngry, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_BattleTentLobby_EventScript_RulesBoard::
	lockall
	msgbox VerdanturfTown_BattleTentLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto VerdanturfTown_BattleTentLobby_EventScript_ReadRulesBoard
	end

VerdanturfTown_BattleTentLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattlePalaceLobby_Text_ReadWhichHeading
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BATTLE_TENT_RULES
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, VerdanturfTown_BattleTentLobby_EventScript_RulesLevel
	case 1, VerdanturfTown_BattleTentLobby_EventScript_RulesBasics
	case 2, VerdanturfTown_BattleTentLobby_EventScript_RulesNature
	case 3, VerdanturfTown_BattleTentLobby_EventScript_RulesMoves
	case 4, VerdanturfTown_BattleTentLobby_EventScript_RulesUnderpowered
	case 5, VerdanturfTown_BattleTentLobby_EventScript_RulesWhenInDanger
	case 6, VerdanturfTown_BattleTentLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, VerdanturfTown_BattleTentLobby_EventScript_ExitRules
	end

VerdanturfTown_BattleTentLobby_EventScript_RulesLevel::
	msgbox BattleTentLobby_Text_ExplainLevelRules, MSGBOX_DEFAULT
	goto VerdanturfTown_BattleTentLobby_EventScript_ReadRulesBoard
	end

VerdanturfTown_BattleTentLobby_EventScript_RulesBasics::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesBasics, MSGBOX_DEFAULT
	goto VerdanturfTown_BattleTentLobby_EventScript_ReadRulesBoard
	end

VerdanturfTown_BattleTentLobby_EventScript_RulesNature::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesNature, MSGBOX_DEFAULT
	goto VerdanturfTown_BattleTentLobby_EventScript_ReadRulesBoard
	end

VerdanturfTown_BattleTentLobby_EventScript_RulesMoves::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesMoves, MSGBOX_DEFAULT
	goto VerdanturfTown_BattleTentLobby_EventScript_ReadRulesBoard
	end

VerdanturfTown_BattleTentLobby_EventScript_RulesUnderpowered::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesUnderpowered, MSGBOX_DEFAULT
	goto VerdanturfTown_BattleTentLobby_EventScript_ReadRulesBoard
	end

VerdanturfTown_BattleTentLobby_EventScript_RulesWhenInDanger::
	msgbox BattleFrontier_BattlePalaceLobby_Text_ExplainRulesWhenInDanger, MSGBOX_DEFAULT
	goto VerdanturfTown_BattleTentLobby_EventScript_ReadRulesBoard
	end

VerdanturfTown_BattleTentLobby_EventScript_ExitRules::
	releaseall
	end

VerdanturfTown_BattleTentLobby_Text_MonsReluctantToUseDislikedMoves:
	.string "Si un POKéMON n'aime pas\n"
	.string "une certaine capacité,\p"
	.string "il sera réticent\n"
	.string "à l'utiliser.\p"
	.string "Peu importe à quel\n"
	.string "point elle est forte.\l"
	.string "Choisis les\p"
	.string "capacités selon\n"
	.string "la nature de ton POKéMON.\l"
	.string "C'est important !$"

VerdanturfTown_BattleTentLobby_Text_GentleMonsScaryIfAngry:
	.string "Ma grande soeur est douce d'habitude.\n"
	.string "Mais quand elle se met en colère,\l"
	.string "elle est vraiment, vraiment effrayante !\p"
	.string "Je parie qu'un POKéMON doux devient effrayant\n"
	.string "s'il se met en colère !$"

VerdanturfTown_BattleTentLobby_Text_AttractionRunsDeep:
	.string "Mes sentiments envers mon POKéMON…\n"
	.string "L'attirance est profonde…\p"
	.string "Oh, salut, tu n'as pas vu ça, n'est-ce pas ?\n"
	.string "Bref, peu importe.\p"
	.string "Tu voudrais cette CT pour\n"
	.string "ton POKéMON ?$"

VerdanturfTown_BattleTentLobby_Text_AttractionMutual:
	.string "Mes sentiments envers mes POKéMON… Je\n"
	.string "suis sûre que l'attirance est\p"
	.string "mutuelle ! Ils combattent exactement\n"
	.string "comme je le veux !$"

VerdanturfTown_BattleTentLobby_Text_TaughtWhatKindsOfMoves:
	.string "Quel genre d'attaques as-tu apprises\n"
	.string "à tes POKéMON ?\p"
	.string "Je pense que tu aurais un avantage s'ils savaient\n"
	.string "se soigner ou se\l"
	.string "protéger.$"

VerdanturfTown_BattleTentLobby_Text_ScottCanMeetToughTrainers:
	.string "SCOTT : Salut, {PLAYER}{KUN} !\n"
	.string "Je pensais que je\p"
	.string "pourrais te voir ici.\n"
	.string "Une TENTE DE COMBAT\p"
	.string "est un endroit où\n"
	.string "tu peux tester\p"
	.string "tes compétences.\n"
	.string "Amuse-toi bien !{PLAYER}{KUN}$"

VerdanturfTown_BattleTentLobby_Text_ScottVisitRegularly:
	.string "SCOTT : Je viens ici régulièrement en espérant\n"
	.string "voir des DRESSEURS costauds en action\l"
	.string "dans toutes sortes de situations.$"
