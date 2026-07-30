.set LOCALID_ATTENDANT, 1

BattleFrontier_BattleArenaLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleArenaLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleArenaLobby_OnWarp
	.byte 0

BattleFrontier_BattleArenaLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleArenaLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattleArenaLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleArenaLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattleArenaLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattleArenaLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_PAUSED, BattleFrontier_BattleArenaLobby_EventScript_ResumeChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattleArenaLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattleArenaLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattleArenaLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattleArenaLobby_EventScript_QuitWithoutSaving::
	lockall
	msgbox BattleFrontier_BattleArenaLobby_Text_DidntSaveBeforeShuttingDown, MSGBOX_DEFAULT
	closemessage
	arena_set ARENA_DATA_WIN_STREAK, 0
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleArenaLobby_EventScript_DefeatedTycoon
	msgbox BattleFrontier_BattleArenaLobby_Text_CongratsOnSevenWins, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_GiveBattlePoints

BattleFrontier_BattleArenaLobby_EventScript_DefeatedTycoon::
	msgbox BattleFrontier_BattleArenaLobby_Text_CongratsOnDefeatingTycoon, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_GiveBattlePoints::
	msgbox BattleFrontier_BattleArenaLobby_Text_PleaseAcceptBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	message BattleFrontier_BattleArenaLobby_Text_RecordAchievement
	waitmessage
	call BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge2, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_LostChallenge::
	lockall
	message BattleFrontier_BattleArenaLobby_Text_ThankYouWaitWhileSave
	waitmessage
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, FALSE
	call BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge2, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_SaveAfterChallenge::
	frontier_checkairshow
	special LoadPlayerParty
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	arena_save 0
	playse SE_SAVE
	waitse
	call BattleFrontier_EventScript_GetCantRecordBattle
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge
	message BattleFrontier_BattleArenaLobby_Text_RecordLastMatch
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge
	case 0, BattleFrontier_BattleArenaLobby_EventScript_RecordMatch
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge

BattleFrontier_BattleArenaLobby_EventScript_RecordMatch::
	call BattleFrontier_EventScript_SaveBattle
BattleFrontier_BattleArenaLobby_EventScript_EndSaveAfterChallenge::
	return

BattleFrontier_BattleArenaLobby_EventScript_ResumeChallenge::
	lockall
	message BattleFrontier_BattleArenaLobby_Text_LookingForwardToArrivalSaveGame
	waitmessage
	arena_save CHALLENGE_STATUS_SAVING
	playse SE_SAVE
	waitse
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto BattleFrontier_BattleArenaLobby_EventScript_EnterChallenge

BattleFrontier_BattleArenaLobby_EventScript_Attendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_ARENA
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	special SavePlayerParty
	msgbox BattleFrontier_BattleArenaLobby_Text_WelcomeToBattleArena, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_AskTakeChallenge::
	message BattleFrontier_BattleArenaLobby_Text_WishToTakeChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleArenaLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattleArenaLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattleArenaLobby_Text_WhichLevelMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattleArenaLobby_Text_SelectThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	callnative RemoveFollowingPokemon
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge
	msgbox BattleFrontier_BattleArenaLobby_Text_OkayToSave, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattleArenaLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	arena_init
	arena_set ARENA_DATA_WIN_STREAK_ACTIVE, TRUE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleArenaLobby_EventScript_CancelChallengeSaveFailed
BattleFrontier_BattleArenaLobby_EventScript_EnterChallenge::
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattleArenaLobby_Text_GuideYouToArena, MSGBOX_DEFAULT
	closemessage
	frontier_get FRONTIER_DATA_LVL_MODE
	call_if_eq VAR_RESULT, FRONTIER_LVL_50, BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLv50
	call_if_eq VAR_RESULT, FRONTIER_LVL_OPEN, BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLvOpen
	warp MAP_BATTLE_FRONTIER_BATTLE_ARENA_CORRIDOR, 9, 13
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattleArenaLobby_EventScript_ExplainChallenge::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainChallenge, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_AskTakeChallenge

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge

BattleFrontier_BattleArenaLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
BattleFrontier_BattleArenaLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge, MSGBOX_DEFAULT
BattleFrontier_BattleArenaLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLv50::
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToLeftDoor
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToLeftDoor
	waitmovement 0
	opendoor 2, 2
	waitdooranim
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 2, 2
	waitdooranim
	return

BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToLeftDoor:
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToLeftDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleArenaLobby_EventScript_WalkToDoorLvOpen::
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToRightDoor
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToRightDoor
	waitmovement 0
	opendoor 11, 2
	waitdooranim
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleArenaLobby_Movement_AttendantEnterDoor
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleArenaLobby_Movement_PlayerEnterDoor
	waitmovement 0
	closedoor 11, 2
	waitdooranim
	return

BattleFrontier_BattleArenaLobby_Movement_AttendantWalkToRightDoor:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

BattleFrontier_BattleArenaLobby_Movement_PlayerWalkToRightDoor:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

BattleFrontier_BattleArenaLobby_EventScript_ShowResults::
	lockall
	frontier_results FRONTIER_FACILITY_ARENA
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattleArenaLobby_EventScript_Youngster::
	msgbox BattleFrontier_BattleArenaLobby_Text_BadIdeaToNotAttack, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Man::
	msgbox BattleFrontier_BattleArenaLobby_Text_LandingHitsWorked, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Camper::
	msgbox BattleFrontier_BattleArenaLobby_Text_MatchWasDeclaredDraw, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_Woman::
	msgbox BattleFrontier_BattleArenaLobby_Text_OrderOfMonsImportant, MSGBOX_NPC
	end

BattleFrontier_BattleArenaLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattleArenaLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattleArenaLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 17, 2, MULTI_BATTLE_ARENA_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattleArenaLobby_EventScript_BattleRules
	case 1, BattleFrontier_BattleArenaLobby_EventScript_MindRules
	case 2, BattleFrontier_BattleArenaLobby_EventScript_SkillRules
	case 3, BattleFrontier_BattleArenaLobby_EventScript_BodyRules
	case 4, BattleFrontier_BattleArenaLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattleArenaLobby_EventScript_ExitRules
	end

BattleFrontier_BattleArenaLobby_EventScript_BattleRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainBattleRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_MindRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainMindRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_SkillRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainSkillRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_BodyRules::
	msgbox BattleFrontier_BattleArenaLobby_Text_ExplainBodyRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattleArenaLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattleArenaLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattleArenaLobby_Text_WelcomeToBattleArena:
	.string "Là où l'esprit combatif des DRESSEURS\n"
	.string "est mis à l'épreuve !\p"
	.string "Je t'accueille à l'ARÈNE DE COMBAT !\p"
	.string "Je suis ton guide pour le Tournoi K.O. Direct !$"

BattleFrontier_BattleArenaLobby_Text_WishToTakeChallenge:
	.string "Maintenant, veux-tu relever\n"
	.string "le défi de l'ARÈNE DE COMBAT ?$"

BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge:
	.string "Nous attendons ton défi\n"
	.string "une autre fois !$"

BattleFrontier_BattleArenaLobby_Text_ExplainChallenge:
	.string "Dans l'ARÈNE DE COMBAT, nous organisons\n"
	.string "le Tournoi KO Fixe.\p"
	.string "Tous les participants entrent avec une équipe de\n"
	.string "trois POKéMON.\p"
	.string "Les trois POKéMON doivent être alignés dans\n"
	.string "l'ordre où ils apparaîtront.\p"
	.string "Pendant le combat, les POKéMON apparaîtront\n"
	.string "un par un dans l'ordre prédéfini.\p"
	.string "Une fois qu'un POKéMON entre en combat, il doit\n"
	.string "rester sur le terrain jusqu'à la fin du match.\p"
	.string "Si un match reste indécis après\n"
	.string "trois tours, il passe au jugement.\p"
	.string "Si tu souhaites interrompre ton défi,\n"
	.string "sauvegarde la partie.\p"
	.string "Si tu ne sauvegardes pas, tu ne pourras pas\n"
	.string "continuer ton défi.\p"
	.string "Si tu réussis à battre\n"
	.string "sept DRESSEURS d'affilée,\l"
	.string "nous te remettrons des Points de Combat.$"

BattleFrontier_BattleArenaLobby_Text_OkayToSave:
	.string "Avant de t'emmener à l'ARÈNE DE COMBAT,\n"
	.string "tu dois sauvegarder. C'est bon ?$"

BattleFrontier_BattleArenaLobby_Text_WhichLevelMode:
	.string "L'ARENE DE COMBAT propose deux niveaux\n"
	.string "de défi, NORMAL et DIFFICILE.\l"
	.string "Lequel choisis-tu ?$"

BattleFrontier_BattleArenaLobby_Text_SelectThreeMons:
	.string "Très bien, choisis tes\n"
	.string "trois POKéMON, s'il te plaît.$"

BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLvOpen:
	.string "My dear challenger!\p"
	.string "You do not have the three POKéMON\n"
	.string "required for entry.\p"
	.string "To qualify, you must bring three\n"
	.string "different kinds of POKéMON.\p"
	.string "They also must not hold the same\n"
	.string "kinds of items.\p"
	.string "EGGS{STR_VAR_1} ineligible.\p"
	.string "When you have made your preparations,\n"
	.string "please do return.$"

BattleFrontier_BattleArenaLobby_Text_NotEnoughValidMonsLv50:
	.string "My dear challenger!\p"
	.string "You do not have the three POKéMON\n"
	.string "required for entry.\p"
	.string "To qualify, you must bring three\n"
	.string "different kinds of POKéMON.\p"
	.string "They also must not hold the same\n"
	.string "kinds of items.\p"
	.string "EGGS{STR_VAR_1} ineligible.\p"
	.string "When you have made your preparations,\n"
	.string "please do return.$"

BattleFrontier_BattleArenaLobby_Text_GuideYouToArena:
	.string "Je vais maintenant te conduire\n"
	.string "à l'ARÈNE DE COMBAT.$"

BattleFrontier_BattleArenaLobby_Text_DidntSaveBeforeShuttingDown:
	.string "Mon cher challenger ! Tu\p"
	.string "n'as pas sauvegardé avant\n"
	.string "de quitter, n'est-ce pas\p"
	.string "? C'est malheureux, mais\n"
	.string "cela a entraîné ta\l"
	.string "disqualification de ton défi.\p"
	.string "Tu peux, bien sûr,\n"
	.string "recommencer un nouveau défi.$"

BattleFrontier_BattleArenaLobby_Text_CongratsOnSevenWins:
	.string "Nous te félicitons pour ta\n"
	.string "splendide série de victoires sur sept DRESSEURS !$"

BattleFrontier_BattleArenaLobby_Text_RecordAchievement:
	.string "Ton exploit sera enregistré.\n"
	.string "Patientez pendant que je sauvegarde la partie.$"

@ Unused
BattleFrontier_BattleArenaLobby_Text_PresentYouWithPrize:
	.string "Pour commémorer ta série de 7 victoires,\n"
	.string "nous t'offrons ce prix.$"

@ Unused
BattleFrontier_BattleArenaLobby_Text_ReceivedPrize:
	.string "{PLAYER} a reçu le prix\n"
	.string "{STR_VAR_1}.$"

@ Unused
BattleFrontier_BattleArenaLobby_Text_BagFullReturnForPrize:
	.string "Oh ?\n"
	.string "Ton SAC semble être plein.\p"
	.string "Je t'invite à faire de la place et\n"
	.string "à revenir chercher ton lot.$"

BattleFrontier_BattleArenaLobby_Text_ThankYouWaitWhileSave:
	.string "Merci beaucoup d'avoir participé !\p"
	.string "Patientez pendant que je sauvegarde la partie.$"

BattleFrontier_BattleArenaLobby_Text_AwaitAnotherChallenge2:
	.string "Nous attendons ton défi\n"
	.string "une autre fois !$"

BattleFrontier_BattleArenaLobby_Text_LookingForwardToArrivalSaveGame:
	.string "Nous attendions votre arrivée\n"
	.string "avec impatience.\p"
	.string "Avant de vous conduire à l'ARÈNE\n"
	.string "de COMBAT, je dois sauvegarder.\l"
	.string "Veuillez patienter.$"

BattleFrontier_BattleArenaLobby_Text_RecordLastMatch:
	.string "Dois-je enregistrer ton dernier match\n"
	.string "D'ARÈNE DE COMBAT sur ton PASSE PARADIS ?$"

BattleFrontier_BattleArenaLobby_Text_BadIdeaToNotAttack:
	.string "J'ai perdu sur décision de l'ARBITRE… Je ne\p"
	.string "pense pas que ce soit une bonne idée\n"
	.string "de n'utiliser que des attaques défensives sans attaquer…$"

BattleFrontier_BattleArenaLobby_Text_LandingHitsWorked:
	.string "J'ai gagné au jugement !\p"
	.string "Toucher régulièrement les POKéMON\n"
	.string "adverses a fonctionné !$"

BattleFrontier_BattleArenaLobby_Text_MatchWasDeclaredDraw:
	.string "Notre match a été déclaré nul.\p"
	.string "Quand le temps s'est écoulé, mes\n"
	.string "POKéMON et ceux de l'adversaire avaient environ\l"
	.string "la même quantité de PV restants.$"

BattleFrontier_BattleArenaLobby_Text_OrderOfMonsImportant:
	.string "Dans l'ARÈNE DE\n"
	.string "COMBAT, l'ordre des\p"
	.string "POKéMON est totalement important.\n"
	.string "Par exemple, si\l"
	.string "ton premier POKéMON\l"
	.string "est faible contre\l"
	.string "le type adverse,\p"
	.string "tu seras en difficulté.\n"
	.string "Planifie ton équipe avec soin !$"

BattleFrontier_BattleArenaLobby_Text_RulesAreListed:
	.string "Les règles du Tournoi KO sont affichées.$"

BattleFrontier_BattleArenaLobby_Text_ReadWhichHeading:
	.string "Quel titre veux-tu lire ?$"

BattleFrontier_BattleArenaLobby_Text_ExplainBattleRules:
	.string "Le Tournoi KO Fixe a\n"
	.string "des règles spéciales,\p"
	.string "contrairement aux combats standards.\n"
	.string "D'abord, un combat ne dure que\p"
	.string "trois tours.\n"
	.string "Si le résultat reste indécis,\p"
	.string "il passe au jugement.\n"
	.string "De plus, les POKéMON apparaissent\p"
	.string "dans un ordre prédéfini.\n"
	.string "Bonne chance !$"

BattleFrontier_BattleArenaLobby_Text_ExplainMindRules:
	.string "Le premier critère de jugement est “Esprit”.\n"
	.string "Ce critère évalue l'agressivité\l"
	.string "des combattants.\p"
	.string "Le jugement se base sur la fréquence\n"
	.string "à laquelle les DRESSEURS ont ordonné\l"
	.string "d'utilisation d'attaques offensives.$"

BattleFrontier_BattleArenaLobby_Text_ExplainSkillRules:
	.string "Le deuxième critère de jugement est “Habileté”.\n"
	.string "Ce critère évalue l'efficacité avec laquelle\l"
	.string "les capacités POKéMON ont été utilisées.\p"
	.string "Si une capacité a réussi,\n"
	.string "la note d'Habileté augmente.\p"
	.string "Si une capacité a échoué, la note d'Habileté\n"
	.string "est abaissée.\p"
	.string "Si c'était une capacité offensive, la note\n"
	.string "d'Habileté augmente si la capacité était “super\l"
	.string "efficace” et diminue si elle était “pas très\l"
	.string "efficace”.\p"
	.string "La note d'Habileté n'augmentera pas pour\n"
	.string "des capacités comme PROTECTION et DÉTECTION.\p"
	.string "Si l'adversaire a utilisé PROTECTION ou\n"
	.string "DÉTECTION, et que ton POKéMON a échoué à\l"
	.string "toucher avec une capacité, sa note d'Habileté\l"
	.string "ne diminuera pas.$"

BattleFrontier_BattleArenaLobby_Text_ExplainBodyRules:
	.string "Le troisième critère de jugement est “Corps\n"
	.string "”. Ce critère est basé sur les\l"
	.string "PV restants à la fin d'un combat.\p"
	.string "La note tient compte des PV qu'un\n"
	.string "POKéMON avait au début du combat, et\l"
	.string "de ce qui restait à la fin.$"

BattleFrontier_BattleArenaLobby_Text_CongratsOnDefeatingTycoon:
	.string "Une victoire arrachée au MAÎTRE\n"
	.string "de l'ARÈNE, et sept DRESSEURS éliminés !\p"
	.string "Félicitations pour ce magnifique\n"
	.string "défi !$"

BattleFrontier_BattleArenaLobby_Text_PleaseAcceptBattlePoints:
	.string "Mon cher challenger, en reconnaissance\n"
	.string "de ton esprit infatigable,\l"
	.string "accepte ces Points de Combat.$"
