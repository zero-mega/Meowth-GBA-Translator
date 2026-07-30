.set LOCALID_ATTENDANT, 1

SlateportCity_BattleTentCorridor_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SlateportCity_BattleTentCorridor_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, SlateportCity_BattleTentCorridor_OnWarp
	.byte 0

	@ This is Slateport Tent's version of the Battle Factory Pre-Battle Room

SlateportCity_BattleTentCorridor_OnWarp:
	map_script_2 VAR_TEMP_1, 0, SlateportCity_BattleTentCorridor_EventScript_SetUpObjects
	.2byte 0

SlateportCity_BattleTentCorridor_EventScript_SetUpObjects::
	setvar VAR_TEMP_1, 1
	goto_if_ne VAR_0x8006, 1, SlateportCity_BattleTentCorridor_EventScript_TurnPlayerNorth
	setobjectxy LOCALID_ATTENDANT, 2, 2
	turnobject LOCALID_ATTENDANT, DIR_SOUTH
SlateportCity_BattleTentCorridor_EventScript_TurnPlayerNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

SlateportCity_BattleTentCorridor_OnFrame:
	map_script_2 VAR_TEMP_0, 0, SlateportCity_BattleTentCorridor_EventScript_EnterCorridor
	.2byte 0

SlateportCity_BattleTentCorridor_EventScript_EnterCorridor::
	goto_if_eq VAR_0x8006, 1, SlateportCity_BattleTentCorridor_EventScript_ReturnToRoomFromBattle
	setvar VAR_TEMP_0, 1
	applymovement LOCALID_ATTENDANT, SlateportCity_BattleTentCorridor_Movement_AttendantEnter
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_BattleTentCorridor_Movement_PlayerEnter
	waitmovement 0
	goto_if_eq VAR_0x8006, 2, SlateportCity_BattleTentCorridor_EventScript_ResumeChallenge
	slateporttent_generaterentalmons
	slateporttent_generateopponentmons
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_HoldMonsChooseFromSelection, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	slateporttent_rentmons
	waitstate
SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_RightThisWay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ATTENDANT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	@opendoor 2, 1
	@waitdooranim
	applymovement LOCALID_ATTENDANT, SlateportCity_BattleTentCorridor_Movement_AttendantExit
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_BattleTentCorridor_Movement_PlayerExit
	waitmovement 0
	@closedoor 2, 1
	@waitdooranim
	warp MAP_SLATEPORT_CITY_BATTLE_TENT_BATTLE_ROOM, 4, 4
	waitstate
	end

SlateportCity_BattleTentCorridor_EventScript_ReturnToRoomFromBattle::
	factory_setopponentmons
	factory_resethelditems
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_LetUsRestoreMons, MSGBOX_DEFAULT
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent::
	frontier_get FRONTIER_DATA_BATTLE_NUM
	call_if_eq VAR_RESULT, 1, SlateportCity_BattleTentCorridor_EventScript_ReadyFor2ndOpponent
	call_if_eq VAR_RESULT, 2, SlateportCity_BattleTentCorridor_EventScript_ReadyFor3rdOpponent
	multichoice 20, 6, MULTI_GO_ON_REST_RETIRE, TRUE
	switch VAR_RESULT
	case 0, SlateportCity_BattleTentCorridor_EventScript_AskSwapMon
	case 1, SlateportCity_BattleTentCorridor_EventScript_AskPauseChallenge
	case 2, SlateportCity_BattleTentCorridor_EventScript_AskRetireChallenge

SlateportCity_BattleTentCorridor_EventScript_AskPauseChallenge::
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_SaveAndQuitGame, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent
	case YES, SlateportCity_BattleTentCorridor_EventScript_PauseChallenge
	case MULTI_B_PRESSED, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent

SlateportCity_BattleTentCorridor_EventScript_AskRetireChallenge::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_RetireFromChallenge
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent
	case 0, SlateportCity_BattleTent_EventScript_WarpToLobbyLost
	case MULTI_B_PRESSED, SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent

SlateportCity_BattleTentCorridor_EventScript_AskSwapMon::
	slateporttent_generateopponentmons
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_LikeToSwapMon, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom
	case YES, SlateportCity_BattleTentCorridor_EventScript_SwapMons
	case MULTI_B_PRESSED, SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom

SlateportCity_BattleTentCorridor_EventScript_SwapMons::
	fadescreen FADE_TO_BLACK
	slateporttent_swapmons
	waitstate
	goto_if_eq VAR_RESULT, 1, SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom
	msgbox BattleFrontier_BattleFactoryPreBattleRoom_Text_YourSwapIsComplete, MSGBOX_DEFAULT
	goto SlateportCity_BattleTentCorridor_EventScript_EnterBattleRoom

SlateportCity_BattleTentCorridor_EventScript_ReadyFor2ndOpponent::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor2ndOpponent
	waitmessage
	return

SlateportCity_BattleTentCorridor_EventScript_ReadyFor3rdOpponent::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_ReadyFor3rdOpponent
	waitmessage
	return

SlateportCity_BattleTentCorridor_EventScript_PauseChallenge::
	message BattleFrontier_BattleFactoryPreBattleRoom_Text_SavingDataPleaseWait
	waitmessage
	slateporttent_save CHALLENGE_STATUS_PAUSED
	playse SE_SAVE
	waitse
	fadescreen FADE_TO_BLACK
	frontier_reset
	end

SlateportCity_BattleTentCorridor_EventScript_ResumeChallenge::
	special SavePlayerParty
	factory_setparties 0
	goto SlateportCity_BattleTentCorridor_EventScript_AskReadyForOpponent

SlateportCity_BattleTentCorridor_Movement_PlayerEnter:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SlateportCity_BattleTentCorridor_Movement_PlayerExit:
	walk_up
	walk_up
	set_invisible
	step_end

SlateportCity_BattleTentCorridor_Movement_AttendantEnter:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

SlateportCity_BattleTentCorridor_Movement_AttendantExit:
	walk_up
	set_invisible
	step_end

@ Leftover text from when this was a Contest Hall in R/S
@ Unused
SlateportCity_ContestHall_Text_AdviceForContests:
	.string "Tu veux un\n"
	.string "petit conseil\p"
	.string "pour les CONCOURS ?\n"
	.string "Utiliser une certaine\l"
	.string "capacité après un autre\p"
	.string "certain type de capacité\n"
	.string "peut être efficace.\p"
	.string "Essaie différentes\n"
	.string "combinaisons !$"

@ Unused
SlateportCity_ContestHall_Text_MyPapaIsContestJudge:
	.string "Mon papa est JUGE de CONCOURS.\p"
	.string "Je me demande ce que je serai plus tard,\n"
	.string "JUGE ou CHAMPION D'ARÈNE ?$"

@ Unused
SlateportCity_ContestHall_Text_ImLikeMajorlyCheesed:
	.string "Hé, mec, je suis genre super énervé,\n"
	.string "tu sais. Genre, tu\l"
	.string "sais, je voulais juste\l"
	.string "savoir pourquoi mes POKéMON\p"
	.string "ne gagnaient jamais, tu sais.\n"
	.string "Alors j'ai demandé à un type fort,\p"
	.string "et il m'a dit que c'était\n"
	.string "à cause de la NATURE.\p"
	.string "La NATURE, tu sais !\n"
	.string "C'est fou, non ?$"

@ Unused
SlateportCity_ContestHall_Text_ExplainTorment:
	.string "C'est, genre, la CT41, tu vois\n"
	.string "? Hé, c'est TOURMENTE, tu m'entends\p"
	.string "? Genre, ça empêche l'autre d'utiliser\n"
	.string "la même capacité deux fois de\p"
	.string "suite. Hé, écoute, genre, je\n"
	.string "ne te tourmente pas !$"

@ Unused
SlateportCity_ContestHall_Text_MCStepUpTakePartInContest:
	.string "MC : Oh là là !\n"
	.string "Quel magnifique POKéMON !\p"
	.string "S'il vous plaît ! Venez participer\n"
	.string "à nos splendides CONCOURS !\p"
	.string "Vous allez bien vous en sortir !\n"
	.string "J'en suis sûr ! Mes yeux ne m'ont jamais trompé !$"

@ Unused
SlateportCity_ContestHall_Text_JudgeWouldntDoToMissContest:
	.string "JUGE : Eh bien, bonjour !\n"
	.string "Je vois que tu es un DRESSEUR !\p"
	.string "Alors, tu ne peux pas rater\n"
	.string "un CONCOURS POKéMON !\p"
	.string "Obtiens un PASSE CONCOURS à VERGOUILLETTE\n"
	.string "et participe quand tu veux !$"

@ Unused
SlateportCity_ContestHall_Text_ItsAppealTime:
	.string "C'est l'heure des utilisations !\n"
	.string "Par quoi commencer ?$"

@ Unused
SlateportCity_ContestHall_Text_DidntPayAttentionToAppeal:
	.string "Ils n'ont pas beaucoup prêté attention au\n"
	.string "charme de mon POKéMON… Humph, ce\p"
	.string "JUGE ne reconnaît pas une bonne\n"
	.string "chose quand il en voit une.$"

@ Unused
SlateportCity_ContestHall_Text_RewardWithSageAdvice:
	.string "Oh, salut ! Tu dois être un\n"
	.string "fan sérieux pour t'approcher\p"
	.string "si près de l'action.\n"
	.string "Je vais récompenser ton enthousiasme avec\p"
	.string "ce conseil avisé.\n"
	.string "Le CHAMPION d'ARÈNE\p"
	.string "ici utilise des POKéMON\n"
	.string "de type EAU.\p"
	.string "Utilise des capacités de\n"
	.string "type PLANTE ou ÉLECTRIK !$"

@ Unused
SlateportCity_ContestHall_Text_MoreFreakedOutThanMon:
	.string "Je n'y arrive pas ! Je suis plus paniqué\n"
	.string "que mes POKéMON.\p"
	.string "Je tremble et mon cœur bat la chamade !$"

@ Unused
SlateportCity_ContestHall_Text_BattleAndContestAlike:
	.string "Un combat et un CONCOURS ne sont pas\n"
	.string "pareils, mais ils se ressemblent aussi.\p"
	.string "Il faut travailler dur et croire\n"
	.string "aux POKéMON que tu as élevés.$"

@ Unused
SlateportCity_ContestHall_Text_MonLooksOnTopOfGame:
	.string "Ce POKéMON a l'air au top de sa forme,\n"
	.string "non ?\p"
	.string "Un POKéMON qui se débrouille bien\n"
	.string "au jugement secondaire semble plus\l"
	.string "détendu quand il fait des démonstrations.$"

@ Unused
SlateportCity_ContestHall_Text_MyMonBetterThanThatLot:
	.string "Tu vois cet état pitoyable ?\p"
	.string "Hé, mes POKéMON sont clairement meilleurs\n"
	.string "que ce lot !$"

@ Unused
SlateportCity_ContestHall_Text_GetUrgeToMoveWithMon:
	.string "Tu n'as pas envie de bouger avec\n"
	.string "tes POKéMON quand ils font une appel\l"
	.string "énergique ?$"

@ Unused
SlateportCity_ContestHall_Text_HyperRankStage:
	.string "CONCOURS POKéMON\n"
	.string "SCÈNE RANG HYPER !$"

