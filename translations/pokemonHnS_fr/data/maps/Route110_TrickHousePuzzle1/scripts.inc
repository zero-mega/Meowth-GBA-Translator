Route110_TrickHousePuzzle1_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Route110_TrickHousePuzzle1_OnLoad
	.byte 0

Route110_TrickHousePuzzle1_OnLoad:
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_1_STATE, 2, Route110_TrickHousePuzzle1_EventScript_OpenDoor
	end

Route110_TrickHousePuzzle1_EventScript_OpenDoor::
	setmetatile 13, 1, METATILE_TrickHousePuzzle_Stairs_Down, FALSE
	end

Route110_TrickHousePuzzle1_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_1_STATE, 0, Route110_TrickHousePuzzle1_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle1_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_1_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle1_EventScript_Sally::
	trainerbattle_single TRAINER_SALLY, Route110_TrickHousePuzzle1_Text_SallyIntro, Route110_TrickHousePuzzle1_Text_SallyDefeat
	msgbox Route110_TrickHousePuzzle1_Text_SallyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_EventScript_Eddie::
	trainerbattle_single TRAINER_EDDIE, Route110_TrickHousePuzzle1_Text_EddieIntro, Route110_TrickHousePuzzle1_Text_EddieDefeat
	msgbox Route110_TrickHousePuzzle1_Text_EddiePostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_EventScript_Robin::
	trainerbattle_single TRAINER_ROBIN, Route110_TrickHousePuzzle1_Text_RobinIntro, Route110_TrickHousePuzzle1_Text_RobinDefeat
	msgbox Route110_TrickHousePuzzle1_Text_RobinPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle1_Text_WroteSecretCodeLockOpened::
	.string "{PLAYER} a écrit le code secret\n"
	.string "sur la porte. “Le MAÎTRE\p"
	.string "DES PIÈGES est fabuleux.” …\n"
	.string "… … … … … …\p"
	.string "… Le verrou s'est ouvert !$"

Route110_TrickHousePuzzle1_Text_SallyIntro:
	.string "Je vais tailler mon chemin vers la victoire\n"
	.string "avec COUPE qu'on vient d'apprendre !$"

Route110_TrickHousePuzzle1_Text_SallyDefeat:
	.string "Pourquoi es-tu si sérieux ?$"

Route110_TrickHousePuzzle1_Text_SallyPostBattle:
	.string "Je ne me lasse jamais de\n"
	.string "frapper et de trancher !$"

Route110_TrickHousePuzzle1_Text_EddieIntro:
	.string "Je suis entré dans cette maison bizarre\n"
	.string "par accident…$"

Route110_TrickHousePuzzle1_Text_EddieDefeat:
	.string "Et maintenant j'ai perdu…$"

Route110_TrickHousePuzzle1_Text_EddiePostBattle:
	.string "Je me suis perdu, j'ai perdu un combat, et je suis\n"
	.string "encore plus perdu… Je ne peux pas sortir…$"

Route110_TrickHousePuzzle1_Text_RobinIntro:
	.string "Mais qui est le MAÎTRE DES PIÈGES ?$"

Route110_TrickHousePuzzle1_Text_RobinDefeat:
	.string "J'ai perdu en étant perdu dans mes pensées !$"

Route110_TrickHousePuzzle1_Text_RobinPostBattle:
	.string "Tu es fort !\n"
	.string "Qui es-tu donc ?$"

