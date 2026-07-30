.set LOCALID_ATTENDANT, 1

BattleFrontier_BattlePikeLobby_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePikeLobby_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePikeLobby_OnWarp
	.byte 0

BattleFrontier_BattlePikeLobby_OnFrame:
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, 0, BattleFrontier_BattlePikeLobby_EventScript_GetChallengeStatus
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePikeLobby_EventScript_QuitWithoutSaving
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_WON, BattleFrontier_BattlePikeLobby_EventScript_WonChallenge
	map_script_2 VAR_TEMP_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST, BattleFrontier_BattlePikeLobby_EventScript_LostChallenge
	.2byte 0

BattleFrontier_BattlePikeLobby_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePikeLobby_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattlePikeLobby_EventScript_TurnPlayerNorth::
	setvar VAR_TEMP_1, 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattlePikeLobby_EventScript_GetChallengeStatus::
	frontier_getstatus
	end

BattleFrontier_BattlePikeLobby_EventScript_QuitWithoutSaving::
	special HealPlayerParty
	pike_resethelditems
	lockall
	msgbox BattleFrontier_BattlePikeLobby_Text_FailedToSaveBeforeQuitting, MSGBOX_DEFAULT
	closemessage
	pike_set PIKE_DATA_WIN_STREAK, 0
	pike_set PIKE_DATA_WIN_STREAK_ACTIVE, FALSE
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePikeLobby_EventScript_WonChallenge::
	lockall
	frontier_isbrain
	goto_if_eq VAR_RESULT, TRUE, BattleFrontier_BattlePikeLobby_EventScript_DefeatedQueen
	msgbox BattleFrontier_BattlePikeLobby_Text_PossessLuckInAbundance, MSGBOX_DEFAULT
	waitmessage
	goto BattleFrontier_BattlePikeLobby_EventScript_GiveBattlePoints

BattleFrontier_BattlePikeLobby_EventScript_DefeatedQueen::
	msgbox BattleFrontier_BattlePikeLobby_Text_SnatchedVictoryFromQueen, MSGBOX_DEFAULT
	waitmessage
BattleFrontier_BattlePikeLobby_EventScript_GiveBattlePoints::
	msgbox BattleFrontier_BattlePikeLobby_Text_AwardYouTheseBattlePoints, MSGBOX_DEFAULT
	frontier_givepoints
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_GETPOINTS
	frontier_checkairshow
	pike_get PIKE_DATA_TOTAL_STREAKS
	addvar VAR_RESULT, 1
	pike_set PIKE_DATA_TOTAL_STREAKS, VAR_RESULT
	special LoadPlayerParty
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	pike_resethelditems
	message BattleFrontier_BattlePikeLobby_Text_ShallRecordResults
	waitmessage
	pike_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePikeLobby_EventScript_LostChallenge::
	lockall
	message BattleFrontier_BattlePikeLobby_Text_ChallengeEndedRecordResults
	waitmessage
	frontier_checkairshow
	frontier_set FRONTIER_DATA_BATTLE_NUM, 0
	pike_set PIKE_DATA_WIN_STREAK_ACTIVE, FALSE
	special LoadPlayerParty
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	pike_resethelditems
	pike_save 0
	playse SE_SAVE
	waitse
	msgbox BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	releaseall
	end

BattleFrontier_BattlePikeLobby_EventScript_Attendant::
	lock
	faceplayer
	setvar VAR_FRONTIER_FACILITY, FRONTIER_FACILITY_PIKE
	setvar VAR_FRONTIER_BATTLE_MODE, FRONTIER_MODE_SINGLES
	special SavePlayerParty
	msgbox BattleFrontier_BattlePikeLobby_Text_WelcomeToBattlePike, MSGBOX_DEFAULT
BattleFrontier_BattlePikeLobby_EventScript_AskTakeChallenge::
	message BattleFrontier_BattlePikeLobby_Text_TakeChallenge
	waitmessage
	multichoice 17, 6, MULTI_CHALLENGEINFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePikeLobby_EventScript_TryEnterChallenge
	case 1, BattleFrontier_BattlePikeLobby_EventScript_ExplainChallenge
	case 2, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge

BattleFrontier_BattlePikeLobby_EventScript_TryEnterChallenge::
	message BattleFrontier_BattlePikeLobby_Text_WhichChallengeMode
	waitmessage
	multichoice 17, 6, MULTI_LEVEL_MODE, FALSE
	switch VAR_RESULT
	case FRONTIER_LVL_TENT, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge
	frontier_checkineligible
	goto_if_eq VAR_0x8004, TRUE, BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMons
	frontier_set FRONTIER_DATA_LVL_MODE, VAR_RESULT
	msgbox BattleFrontier_BattlePikeLobby_Text_PleaseChooseThreeMons, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	callnative RemoveFollowingPokemon
	call BattleFrontier_EventScript_GetLvlMode
	copyvar VAR_0x8004, VAR_RESULT
	setvar VAR_0x8005, FRONTIER_PARTY_SIZE
	special ChoosePartyForBattleFrontier
	waitstate
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePikeLobby_EventScript_LoadPartyAndCancelChallenge
	msgbox BattleFrontier_BattlePikeLobby_Text_SaveBeforeChallenge, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_BattlePikeLobby_EventScript_LoadPartyAndCancelChallenge
	case YES, BattleFrontier_BattlePikeLobby_EventScript_SaveBeforeChallenge
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_LoadPartyAndCancelChallenge

BattleFrontier_BattlePikeLobby_EventScript_SaveBeforeChallenge::
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	setvar VAR_TEMP_1, 0
	frontier_set FRONTIER_DATA_SELECTED_MON_ORDER
	pike_init
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_SAVING
	pike_set PIKE_DATA_WIN_STREAK_ACTIVE, TRUE
	pike_savehelditems
	frontier_set FRONTIER_DATA_PAUSED, FALSE
	special LoadPlayerParty
	closemessage
	delay 2
	call Common_EventScript_SaveGame
	setvar VAR_TEMP_CHALLENGE_STATUS, 255
	pike_savehelditems
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePikeLobby_EventScript_CancelChallengeSaveFailed
	special SavePlayerParty
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	msgbox BattleFrontier_BattlePikeLobby_Text_StepThisWay, MSGBOX_DEFAULT
	closemessage
	frontier_settrainers
	call BattleFrontier_BattlePikeLobby_EventScript_WalkToCorridor
	special HealPlayerParty
	call BattleFrontier_BattlePike_EventScript_CloseCurtain
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_PIKE_CORRIDOR, 6, 7
	setvar VAR_TEMP_CHALLENGE_STATUS, 0
	waitstate
	end

BattleFrontier_BattlePikeLobby_EventScript_ExplainChallenge::
	msgbox BattleFrontier_BattlePikeLobby_Text_ExplainBattlePike, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_AskTakeChallenge

BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMons::
	switch VAR_RESULT
	case FRONTIER_LVL_50, BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMonsLv50
	case FRONTIER_LVL_OPEN, BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMonsLvOpen

BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMonsLv50::
	msgbox BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLv50, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePikeLobby_EventScript_NotEnoughValidMonsLvOpen::
	msgbox BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLvOpen, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_EndCancelChallenge

BattleFrontier_BattlePikeLobby_EventScript_CancelChallengeSaveFailed::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	goto BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge

BattleFrontier_BattlePikeLobby_EventScript_LoadPartyAndCancelChallenge::
	special LoadPlayerParty
	callnative UpdateFollowingPokemon
BattleFrontier_BattlePikeLobby_EventScript_CancelChallenge::
	msgbox BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou, MSGBOX_DEFAULT
BattleFrontier_BattlePikeLobby_EventScript_EndCancelChallenge::
	release
	end

BattleFrontier_BattlePikeLobby_EventScript_ShowResults::
	lockall
	frontier_results FRONTIER_FACILITY_PIKE
	waitbuttonpress
	special RemoveRecordsWindow
	releaseall
	end

BattleFrontier_BattlePikeLobby_EventScript_WalkToCorridor::
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePikeLobby_Movement_AttendantWalkToCorridor
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePikeLobby_Movement_PlayerWalkToCorridor
	waitmovement 0
	return

BattleFrontier_BattlePikeLobby_Movement_PlayerWalkToCorridor:
	walk_up
BattleFrontier_BattlePikeLobby_Movement_AttendantWalkToCorridor:
	walk_up
	walk_up
	set_invisible
	step_end

BattleFrontier_BattlePikeLobby_EventScript_Hiker::
	msgbox BattleFrontier_BattlePikeLobby_Text_OneRoomAwayFromGoal, MSGBOX_NPC
	end

BattleFrontier_BattlePikeLobby_EventScript_Twin::
	msgbox BattleFrontier_BattlePikeLobby_Text_NeverHadToBattleTrainer, MSGBOX_NPC
	end

BattleFrontier_BattlePikeLobby_EventScript_Beauty::
	msgbox BattleFrontier_BattlePikeLobby_Text_ThinkAbilitiesUsefulHere, MSGBOX_NPC
	end

BattleFrontier_BattlePikeLobby_EventScript_RulesBoard::
	lockall
	msgbox BattleFrontier_BattlePikeLobby_Text_RulesAreListed, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard::
	message BattleFrontier_BattlePikeLobby_Text_ReadWhichHeading
	waitmessage
	multichoice 16, 4, MULTI_BATTLE_PIKE_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_BattlePikeLobby_EventScript_RulesPokenavBag
	case 1, BattleFrontier_BattlePikeLobby_EventScript_RulesHeldItems
	case 2, BattleFrontier_BattlePikeLobby_EventScript_RulesMonOrder
	case 3, BattleFrontier_BattlePikeLobby_EventScript_ExitRules
	case MULTI_B_PRESSED, BattleFrontier_BattlePikeLobby_EventScript_ExitRules
	end

BattleFrontier_BattlePikeLobby_EventScript_RulesPokenavBag::
	msgbox BattleFrontier_BattlePikeLobby_Text_ExplainPokenavBagRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePikeLobby_EventScript_RulesHeldItems::
	msgbox BattleFrontier_BattlePikeLobby_Text_ExplainHeldItemRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePikeLobby_EventScript_RulesMonOrder::
	msgbox BattleFrontier_BattlePikeLobby_Text_ExplainMonOrderRules, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePikeLobby_EventScript_ReadRulesBoard
	end

BattleFrontier_BattlePikeLobby_EventScript_ExitRules::
	releaseall
	end

BattleFrontier_BattlePike_EventScript_CloseCurtain::
	playse SE_PIKE_CURTAIN_CLOSE
	special CloseBattlePikeCurtain
	waitstate
	waitse
	return

BattleFrontier_BattlePikeLobby_Text_WelcomeToBattlePike:
	.string "Là où la chance des DRESSEURS\n"
	.string "est mise à l'épreuve… Bienvenue au\p"
	.string "BÂTON DE COMBAT… Je suis votre\p"
	.string "guide pour le BÂTON DE COMBAT…$"

BattleFrontier_BattlePikeLobby_Text_TakeChallenge:
	.string "Veux-tu relever le défi\n"
	.string "Choix de Combat ?$"

BattleFrontier_BattlePikeLobby_Text_ExplainBattlePike:
	.string "Ici, nous organisons un événement appelé\n"
	.string "le Choix de Combat.\p"
	.string "Les règles du Choix de Combat sont très\n"
	.string "simples…\p"
	.string "Choisis l'un des trois chemins et atteins\n"
	.string "la salle but à la fin du\l"
	.string "BÂTON DE COMBAT. C'est aussi simple que ça.\p"
	.string "Cependant, ce qui se passe sur le chemin choisi\n"
	.string "dépend entièrement de la chance\l"
	.string "du challenger…\p"
	.string "Si tu atteins le but, tu seras\n"
	.string "récompensé par des Points de Combat.\p"
	.string "Si tu veux interrompre ton\n"
	.string "défi, parle à notre personnel dans les grandes salles\l"
	.string "sur le chemin.\p"
	.string "Si tu ne sauvegardes pas avant d'interrompre,\n"
	.string "tu seras disqualifié.$"

BattleFrontier_BattlePikeLobby_Text_LookForwardToSeeingYou:
	.string "Nous espérons te revoir\n"
	.string "une autre fois…$"

BattleFrontier_BattlePikeLobby_Text_WhichChallengeMode:
	.string "Tu as le choix entre deux parcours,\n"
	.string "NORMAL et DIFFICILE.\l"
	.string "Lequel vas-tu relever ?$"

BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLv50:
	.string "I beg your pardon, but…\p"
	.string "You do not have three eligible\n"
	.string "POKéMON for the Battle Choice event.\p"
	.string "You must have three different POKéMON.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "EGGS{STR_VAR_1} ineligible.\p"
	.string "Please come see me when\n"
	.string "you are ready…$"

BattleFrontier_BattlePikeLobby_Text_NotEnoughValidMonsLvOpen:
	.string "I beg your pardon, but…\p"
	.string "You do not have three eligible\n"
	.string "POKéMON for the Battle Choice event.\p"
	.string "You must have three different\n"
	.string "POKéMON to enter.\p"
	.string "They also must be holding different\n"
	.string "kinds of items.\p"
	.string "EGGS{STR_VAR_1} ineligible.\p"
	.string "Please come see me when\n"
	.string "you are ready…$"

BattleFrontier_BattlePikeLobby_Text_PleaseChooseThreeMons:
	.string "Choisis les trois POKéMON\n"
	.string "que tu veux inscrire au défi…$"

BattleFrontier_BattlePikeLobby_Text_SaveBeforeChallenge:
	.string "Avant de commencer ton défi Choix de Combat,\n"
	.string "je dois sauvegarder la partie.\l"
	.string "C'est acceptable ?$"

BattleFrontier_BattlePikeLobby_Text_StepThisWay:
	.string "Par ici, s'il vous plaît…$"

BattleFrontier_BattlePikeLobby_Text_ChallengeEndedRecordResults:
	.string "Ton défi est terminé…\p"
	.string "Je vais enregistrer tes résultats.\n"
	.string "Un instant, s'il te plaît…$"

BattleFrontier_BattlePikeLobby_Text_PossessLuckInAbundance:
	.string "Tu as terminé le défi…\p"
	.string "Je dois dire… Tu sembles avoir\n"
	.string "une chance incroyable…$"

BattleFrontier_BattlePikeLobby_Text_ShallRecordResults:
	.string "Je vais enregistrer tes résultats.\n"
	.string "Patientez…$"

@ Unused
BattleFrontier_BattlePikeLobby_Text_AwardYouTheseBattlePoints2:
	.string "Pour commémorer ta réussite au défi\n"
	.string "du Parcours de Combat, nous t'attribuons\l"
	.string "ces Points de Combat...$"

@ Unused
BattleFrontier_BattlePikeLobby_Text_ReachedBattlePointLimit:
	.string "Tu sembles avoir atteint la\n"
	.string "limite de Points de Combat…\p"
	.string "Échange des Points de Combat\n"
	.string "contre des prix, puis reviens…$"

BattleFrontier_BattlePikeLobby_Text_FailedToSaveBeforeQuitting:
	.string "Je vous prie de m'excuser, mais…\p"
	.string "Vous n'avez pas sauvegardé avant d'abandonner\n"
	.string "votre défi la dernière fois.\p"
	.string "Veuillez recommencer depuis le début.\n"
	.string "Merci de votre compréhension.$"

BattleFrontier_BattlePikeLobby_Text_SnatchedVictoryFromQueen:
	.string "Félicitations…\p"
	.string "Tu as arraché la victoire à la REINE DU DONJON\n"
	.string "et terminé l'épreuve…$"

BattleFrontier_BattlePikeLobby_Text_AwardYouTheseBattlePoints:
	.string "En reconnaissance de ta chance incroyable,\n"
	.string "nous t'attribuons ces Point(s) de Combat…$"

BattleFrontier_BattlePikeLobby_Text_OneRoomAwayFromGoal:
	.string "Arrrgh ! J'ai raté ma chance !\n"
	.string "J'étais à une salle du but !\p"
	.string "Ici, tu ferais mieux de faire attention\n"
	.string "au poison, au gel, et ainsi de suite.$"

BattleFrontier_BattlePikeLobby_Text_NeverHadToBattleTrainer:
	.string "J'ai terminé le défi 10 fois\n"
	.string "maintenant, mais je n'ai jamais eu à combattre\l"
	.string "un seul DRESSEUR.$"

BattleFrontier_BattlePikeLobby_Text_ThinkAbilitiesUsefulHere:
	.string "Écoute ! Écoute !\p"
	.string "Tu ne trouves pas que les capacités\n"
	.string "spéciales des POKéMON seront utiles\l"
	.string "ici ?$"

@ Unused
BattleFrontier_BattlePikeLobby_Text_TrainersWhicheverPathIChoose:
	.string "Qu'est-ce que cet endroit bizarre ?\n"
	.string "Je n'arrive pas du tout à comprendre !\p"
	.string "J'ai relevé le défi de la PYRAMIDE\n"
	.string "plusieurs fois, mais…\l"
	.string "C'est toujours différent !$"

BattleFrontier_BattlePikeLobby_Text_RulesAreListed:
	.string "Les règles du Choix de Combat sont affichées.$"

BattleFrontier_BattlePikeLobby_Text_ReadWhichHeading:
	.string "Quel titre veux-tu lire ?$"

BattleFrontier_BattlePikeLobby_Text_ExplainPokenavBagRules:
	.string "Le SAC et le POKéNAV ne peuvent pas être utilisés\n"
	.string "pendant un défi Choix de Combat.$"

BattleFrontier_BattlePikeLobby_Text_ExplainHeldItemRules:
	.string "Pendant un défi au Parcours de Combat,\n"
	.string "toute BAIE ou HERBE tenue par un POKéMON\l"
	.string "ne sera efficace qu'une seule fois.$"

BattleFrontier_BattlePikeLobby_Text_ExplainMonOrderRules:
	.string "Pendant un défi Choix de Combat,\n"
	.string "la séquence de POKéMON ne peut pas être\l"
	.string "modifiée.\p"
	.string "La séquence doit être définie avant\n"
	.string "de commencer ton défi.$"

