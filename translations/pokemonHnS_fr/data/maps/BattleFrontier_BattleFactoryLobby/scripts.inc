.set LOCALID_ATTENDANT_SINGLES, 1
.set LOCALID_ATTENDANT_DOUBLES, 6

BattleFrontier_BattleFactoryLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleFactoryLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleFactoryLobby_OnWarp
	.byte 0

BattleFrontier_BattleFactoryLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleFactoryLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattleFactoryLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleFactoryLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattleFactoryLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattleFactoryLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattleFactoryLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattleFactoryLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattleFactoryLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattleFactoryLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattleFactoryLobby_EventScript_QuitWithoutSaving::
	lockall
	msgbox BattleFrontier_BattleFactoryLobby_Text_DidntSaveBeforeQuitting, MSGBOX_DEFAULT
	closemessage
	factory_setswapped
	factory_set FACTORY_DATA_WIN_STREAK_SWAPS, 0
	factory_set FACTORY_DATA_WIN_STREAK, 0
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleFactoryLobby_EventScript_DefeatedFactoryHead
	msgbox BattleFrontier_BattleFactoryLobby_Text_CongratsSevenWins, MSGBOX_DEFAULT
	waitmessage
	goto BattleFrontier_BattleFactoryLobby_EventScript_GiveBattlePoints

BattleFrontier_BattleFactoryLobby_EventScript_DefeatedFactoryHead::
	msgbox BattleFrontier_BattleFactoryLobby_Text_CongratsForDefeatingHead, MSGBOX_DEFAULT
	waitmessage
BattleFrontier_BattleFactoryLobby_EventScript_GiveBattlePoints::
	msgbox BattleFrontier_BattleFactoryLobby_Text_AwardBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattleFactoryLobby_Text_ExchangeMonsAndSave
	waitmessage
	frontier_checkairshow
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
	factory_save 0
	playse SE_SAVE
	waitse
	goto BattleFrontier_BattleFactoryLobby_EventScript_AskRecordBattle
	end

BattleFrontier_BattleFactoryLobby_EventScript_LostChallenge::
	lockall
	message BattleFrontier_BattleFactoryLobby_Text_ReturnMonsSaveResults
	waitmessage
	frontier_checkairshow
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, FALSE
	factory_save 0
	playse SE_SAVE
	waitse

BattleFrontier_BattleFactoryLobby_EventScript_AskRecordBattle::
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle
	message BattleFrontier_BattleFactoryLobby_Text_RecordLastMatch
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_RecordBattle
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle

BattleFrontier_BattleFactoryLobby_EventScript_RecordBattle::
	call BattleFrontier_EventScript_SaveBattle
BattleFrontier_BattleFactoryLobby_EventScript_EndRecordBattle::
	msgbox BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_ResumeChallenge::
	lockall
	message BattleFrontier_BattleFactoryLobby_Text_WaitingForYouToResume
	waitmessage
	factory_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	setvar VAR_0x8006, 2
	goto BattleFrontier_BattleFactoryLobby_EventScript_EnterChallenge

BattleFrontier_BattleFactoryLobby_EventScript_SinglesAttendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	goto BattleFrontier_BattleFactoryLobby_EventScript_Attendant
	end

BattleFrontier_BattleFactoryLobby_EventScript_DoublesAttendant::
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_FACTORY
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES
	goto BattleFrontier_BattleFactoryLobby_EventScript_Attendant
	end

BattleFrontier_BattleFactoryLobby_EventScript_Attendant::
	special SavePlayerParty
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForSingleBattle
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForDoubleBattle
BattleFrontier_BattleFactoryLobby_EventScript_AskTakeChallenge::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_TakeSinglesChallenge
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_TakeDoublesChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge

BattleFrontier_BattleFactoryLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattleFactoryLobby_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattleFactoryLobby_Text_OkayToSaveBeforeChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattleFactoryLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattleFactoryLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	factory_init
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	factory_set FACTORY_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleFactoryLobby_EventScript_CancelChallengeSaveFailed
	setvar VAR_0x8006, 0
BattleFrontier_BattleFactoryLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	msgbox BattleFrontier_BattleFactoryLobby_Text_StepThisWay, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_TalkedToSinglesAttendant
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_TalkedToDoublesAttendant
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleFactoryLobby_Movement_AttendantEnterDoor
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleFactoryLobby_Movement_PlayerEnterDoor
	waitmovement 0
	warp MAP_BATTLE_FRONTIER_BATTLE_FACTORY_PRE_BATTLE_ROOM, 8, 13
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattleFactoryLobby_EventScript_TalkedToSinglesAttendant::
	setvar VAR_LAST_TALKED, LOCALID_ATTENDANT_SINGLES
	return

BattleFrontier_BattleFactoryLobby_EventScript_TalkedToDoublesAttendant::
	setvar VAR_LAST_TALKED, LOCALID_ATTENDANT_DOUBLES
	return

BattleFrontier_BattleFactoryLobby_EventScript_ExplainChallenge::
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES, BattleFrontier_BattleFactoryLobby_EventScript_ExplainSinglesChallenge
	call_if_eq VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_DOUBLES, BattleFrontier_BattleFactoryLobby_EventScript_ExplainDoublesChallenge
	goto BattleFrontier_BattleFactoryLobby_EventScript_AskTakeChallenge

BattleFrontier_BattleFactoryLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge

BattleFrontier_BattleFactoryLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
BattleFrontier_BattleFactoryLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleFactoryLobby_Movement_AttendantEnterDoor:
	walk_up
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleFactoryLobby_Movement_PlayerEnterDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForSingleBattle::
	msgbox BattleFrontier_BattleFactoryLobby_Text_WelcomeForSingleBattle, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_WelcomeForDoubleBattle::
	msgbox BattleFrontier_BattleFactoryLobby_Text_WelcomeForDoubleBattle, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_TakeSinglesChallenge::
	message BattleFrontier_BattleFactoryLobby_Text_TakeSinglesChallenge
	return

BattleFrontier_BattleFactoryLobby_EventScript_TakeDoublesChallenge::
	message BattleFrontier_BattleFactoryLobby_Text_TakeDoublesChallenge
	return

BattleFrontier_BattleFactoryLobby_EventScript_ExplainSinglesChallenge::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSinglesChallenge, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_ExplainDoublesChallenge::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainDoublesChallenge, MSGBOX_DEFAULT
	return

BattleFrontier_BattleFactoryLobby_EventScript_ShowSinglesResults::
	lockall
	frontier_results FRONTIER_FACILITY_FACTORY, FRONTIER_MODE_SINGLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_ShowDoublesResults::
	lockall
	frontier_results FRONTIER_FACILITY_FACTORY, FRONTIER_MODE_DOUBLES
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleFactoryLobby_EventScript_Woman::
	msgbox BattleFrontier_BattleFactoryLobby_Text_NeedKnowledgeOfMonsMoves, MSGBOX_NPC
	end

BattleFrontier_BattleFactoryLobby_EventScript_Camper::
	msgbox BattleFrontier_BattleFactoryLobby_Text_SwappedForWeakMon, MSGBOX_NPC
	end

BattleFrontier_BattleFactoryLobby_EventScript_Picnicker::
	lock
	msgbox BattleFrontier_BattleFactoryLobby_Text_NeedToCheckOpponentsMons, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleFactoryLobby_EventScript_FatMan::
	msgbox BattleFrontier_BattleFactoryLobby_Text_CantFigureOutStaffHints, MSGBOX_NPC
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattleFactoryLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattleFactoryLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 17, 0, MULTI_BATTLE_FACTORY_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleFactoryLobby_EventScript_RulesBasics
	case 1, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapPartner
	case 2, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNumber
	case 3, BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNotes
	case 4, BattleFrontier_BattleFactoryLobby_EventScript_RulesOpenLv
	case 5, BattleFrontier_BattleFactoryLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattleFactoryLobby_EventScript_ExitRules
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesBasics::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainBasicRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapPartner::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapPartnerRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNumber::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNumberRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesSwapNotes::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNotesRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_RulesOpenLv::
	msgbox BattleFrontier_BattleFactoryLobby_Text_ExplainOpenLvRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleFactoryLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleFactoryLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattleFactoryLobby_Text_WelcomeForSingleBattle:
	.string "L'intelligence des DRESSEURS\n"
	.string "est mise à l'épreuve !\p"
	.string "Bienvenue à l'USINE DE COMBAT !\p"
	.string "Je suis ton guide pour le Tournoi\n"
	.string "Échange en Solo.$"

BattleFrontier_BattleFactoryLobby_Text_TakeSinglesChallenge:
	.string "Veux-tu relever le défi\n"
	.string "Échange de Combat en Solo ?$"

BattleFrontier_BattleFactoryLobby_Text_ExplainSinglesChallenge:
	.string "Le Tournoi Échange Simple de Combat\n"
	.string "est une compétition de COMBAT SIMPLE\l"
	.string "utilisant uniquement des POKéMON de location.\p"
	.string "D'abord, on te prêtera trois\n"
	.string "POKéMON spécialement pour cet événement.\p"
	.string "Avec les POKéMON de location fournis,\n"
	.string "tu dois mener un COMBAT SIMPLE.\p"
	.string "Si tu gagnes, tu es autorisé à échanger\n"
	.string "un de tes POKéMON de location.\p"
	.string "Répète ce cycle de combat et\n"
	.string "d'échange--si tu gagnes sept fois\l"
	.string "d'affilée, tu gagneras des Points de Combat.\p"
	.string "Si tu veux interrompre ton\n"
	.string "défi, sauvegarde la partie.\p"
	.string "Si tu ne sauvegardes pas, tu seras\n"
	.string "disqualifié de ton défi.$"

BattleFrontier_BattleFactoryLobby_Text_LookForwardToNextVisit:
	.string "Nous attendons ta prochaine visite avec impatience.$"

BattleFrontier_BattleFactoryLobby_Text_WhichLevelMode:
	.string "Quel niveau veux-tu affronter ?\n"
	.string "NORMAL ou DIFFICILE ?$"

BattleFrontier_BattleFactoryLobby_Text_OkayToSaveBeforeChallenge:
	.string "Avant de commencer ton défi,\n"
	.string "je dois sauvegarder la partie. C'est bon ?$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_WillHoldMonsForSafekeeping:
	.string "OK, je garderai tes POKéMON en\n"
	.string "sécurité pendant que tu concours.$"

BattleFrontier_BattleFactoryLobby_Text_StepThisWay:
	.string "Par ici, s'il vous plaît.$"

BattleFrontier_BattleFactoryLobby_Text_ReturnMonsSaveResults:
	.string "Merci d'avoir participé !\p"
	.string "Je te rendrai tes POKéMON en échange\n"
	.string "de nos POKéMON de location.\p"
	.string "Je dois aussi sauvegarder les résultats de l'événement.\n"
	.string "Patientez.$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_ReturnMons:
	.string "Je te rendrai tes POKéMON en échange\n"
	.string "de nos POKéMON de location.$"

BattleFrontier_BattleFactoryLobby_Text_CongratsSevenWins:
	.string "Félicitations ! Tu as gagné sept matchs\n"
	.string "ÉCHANGE DE COMBAT d'affilée !$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_AwardBattlePointsForStreak:
	.string "En reconnaissance de ta série de 7 victoires,\n"
	.string "nous t'attribuons ces Point(s) de Combat.$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_MaxBattlePoints:
	.string "Oh, oh, oh !\p"
	.string "Tes Points de Combat sont au maximum.\p"
	.string "Reviens après en avoir\n"
	.string "utilisé quelques-uns.$"

BattleFrontier_BattleFactoryLobby_Text_WaitingForYouToResume:
	.string "On t'attendait !\p"
	.string "Avant de reprendre ton défi,\n"
	.string "je dois sauvegarder.$"

BattleFrontier_BattleFactoryLobby_Text_DidntSaveBeforeQuitting:
	.string "Je suis désolé de te dire ça, mais tu n'as\n"
	.string "pas sauvegardé avant d'arrêter de jouer la dernière fois.\p"
	.string "En conséquence, tu as été disqualifié\n"
	.string "de ton défi.$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_WellReturnMons:
	.string "Nous te rendrons tes POKéMON personnels.$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_ReceivedPrizeItem:
	.string "{PLAYER} a reçu le prix\n"
	.string "{STR_VAR_1}.$"

BattleFrontier_BattleFactoryLobby_Text_WelcomeForDoubleBattle:
	.string "L'intelligence des DRESSEURS\n"
	.string "est mise à l'épreuve !\p"
	.string "Bienvenue à l'USINE DE COMBAT !\p"
	.string "Je suis ton guide pour le Tournoi\n"
	.string "Échange en Double.$"

BattleFrontier_BattleFactoryLobby_Text_TakeDoublesChallenge:
	.string "Veux-tu relever le défi\n"
	.string "Échange de Combat en Duo ?$"

BattleFrontier_BattleFactoryLobby_Text_ExplainDoublesChallenge:
	.string "Le Tournoi Échange Double de Combat\n"
	.string "est une compétition de COMBAT DOUBLE\l"
	.string "utilisant uniquement des POKéMON de location.\p"
	.string "D'abord, on te prêtera trois\n"
	.string "POKéMON spécialement pour cet événement.\p"
	.string "Avec les POKéMON de location fournis,\n"
	.string "tu dois mener un COMBAT DOUBLE.\p"
	.string "Si tu gagnes, tu es autorisé à échanger\n"
	.string "un de tes POKéMON de location.\p"
	.string "Répète ce cycle de combat et\n"
	.string "d'échange--si tu gagnes sept fois\l"
	.string "d'affilée, tu gagneras des Points de Combat.\p"
	.string "Si tu veux interrompre ton\n"
	.string "défi, sauvegarde la partie.\p"
	.string "Si tu ne sauvegardes pas avant d'interrompre,\n"
	.string "tu seras disqualifié.$"

BattleFrontier_BattleFactoryLobby_Text_CongratsForDefeatingHead:
	.string "Félicitations pour avoir battu le\n"
	.string "CHEF DE L'USINE et remporté\l"
	.string "sept matchs d'affilée !$"

BattleFrontier_BattleFactoryLobby_Text_AwardBattlePoints:
	.string "En reconnaissance de votre richesse\n"
	.string "de connaissances et de votre intelligence,\l"
	.string "nous vous attribuons ces Points de Combat.$"

BattleFrontier_BattleFactoryLobby_Text_ExchangeMonsAndSave:
	.string "Laissez-moi échanger vos POKéMON\n"
	.string "contre nos POKéMON de location.\p"
	.string "Je dois sauvegarder les données de combat,\n"
	.string "alors patientez.$"

BattleFrontier_BattleFactoryLobby_Text_RecordLastMatch:
	.string "Veux-tu enregistrer ton dernier match\n"
	.string "de l'USINE DE COMBAT sur ton\l"
	.string "PASSE FRONTIÈRE ?$"

BattleFrontier_BattleFactoryLobby_Text_NeedKnowledgeOfMonsMoves:
	.string "Salut !\n"
	.string "Toi, là !\p"
	.string "Tu penses que les\n"
	.string "événements ici\l"
	.string "sont faciles\p"
	.string "puisque tu\n"
	.string "n'as pas besoin d'avoir\p"
	.string "un rang élevé ?\n"
	.string "Détrompe-toi !\l"
	.string "C'est difficile !$"

BattleFrontier_BattleFactoryLobby_Text_SwappedForWeakMon:
	.string "J'ai échangé pour un POKéMON faible...\n"
	.string "Je pensais que c'était un bon choix...\p"
	.string "Ils nous ont écrasés...$"

BattleFrontier_BattleFactoryLobby_Text_NeedToCheckOpponentsMons:
	.string "Rien ne va pour moi\n"
	.string "en ce moment.\p"
	.string "Il faut vérifier les POKéMON\n"
	.string "de l'adversaire pendant le combat pour voir s'ils\l"
	.string "sont bons.$"

BattleFrontier_BattleFactoryLobby_Text_CantFigureOutStaffHints:
	.string "Tu sais, le personnel ici te donne\n"
	.string "quelques indices sur ton prochain adversaire ?\p"
	.string "Eh bien, je suis un homme adulte, mais j'ai\n"
	.string "du mal à comprendre leurs indices.$"

@ Unused
BattleFrontier_BattleFactoryLobby_Text_RentalMonsAreVaried:
	.string "Genre, je suis vraiment costaud, mais\n"
	.string "je m'ennuie vite, alors j'ai\l"
	.string "continué à échanger et combattre.\p"
	.string "Bref, en participant aux événements\n"
	.string "Échange Combat, j'ai remarqué qu'ils\l"
	.string "variaient les POKéMON de location.$"

BattleFrontier_BattleFactoryLobby_Text_RulesAreListed:
	.string "Les règles de l'Échange de Combat sont affichées.$"

BattleFrontier_BattleFactoryLobby_Text_ReadWhichHeading:
	.string "Quel titre veux-tu lire ?$"

BattleFrontier_BattleFactoryLobby_Text_ExplainBasicRules:
	.string "Dans un événement Échange de Combat, tu ne peux\n"
	.string "utiliser que trois POKéMON.\p"
	.string "Que tu loues ou échanges, ton équipe ne peut\n"
	.string "pas avoir deux POKéMON identiques ou\l"
	.string "plus.$"

BattleFrontier_BattleFactoryLobby_Text_ExplainSwapPartnerRules:
	.string "Tu ne peux échanger des POKéMON qu'avec\n"
	.string "le DRESSEUR que tu viens de battre.\p"
	.string "Tu ne peux échanger que les POKéMON\n"
	.string "utilisés par le DRESSEUR vaincu.$"

BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNumberRules:
	.string "Après chaque combat gagné, tu peux\n"
	.string "échanger contre un des POKéMON\l"
	.string "vaincus de ton adversaire.\p"
	.string "Tu ne pourras pas échanger de POKéMON\n"
	.string "avec le septième DRESSEUR de l'épreuve.$"

BattleFrontier_BattleFactoryLobby_Text_ExplainSwapNotesRules:
	.string "Il y a deux points\n"
	.string "clés à connaître\p"
	.string "lors d'un échange de POKéMON.\n"
	.string "D'abord, lors d'un échange,\l"
	.string "tu ne peux pas vérifier\p"
	.string "les stats du POKéMON de l'autre.\n"
	.string "Deuxièmement, certains\l"
	.string "POKéMON n'évoluent\p"
	.string "qu'en étant échangés.\n"
	.string "N'oublie pas ça !$"

BattleFrontier_BattleFactoryLobby_Text_ExplainOpenLvRules:
	.string "Au niveau DIFFICILE, les POKéMON de location\n"
	.string "et les POKéMON des DRESSEURS adverses\l"
	.string "sont tous de Niveau 50.$"
