Route110_TrickHousePuzzle4_MapScripts::
	.byte 0

Route110_TrickHousePuzzle4_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_4_STATE, 0, Route110_TrickHousePuzzle4_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle4_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_4_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle4_EventScript_Cora::
	trainerbattle_single TRAINER_GRUNT_28, Route110_TrickHousePuzzle4_Text_CoraIntro, Route110_TrickHousePuzzle4_Text_CoraDefeat
	msgbox Route110_TrickHousePuzzle4_Text_CoraPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_EventScript_Yuji::
	trainerbattle_single TRAINER_YUJI, Route110_TrickHousePuzzle4_Text_YujiIntro, Route110_TrickHousePuzzle4_Text_YujiDefeat
	msgbox Route110_TrickHousePuzzle4_Text_YujiPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_EventScript_Paula::
	trainerbattle_single TRAINER_PAULA, Route110_TrickHousePuzzle4_Text_PaulaIntro, Route110_TrickHousePuzzle4_Text_PaulaDefeat
	msgbox Route110_TrickHousePuzzle4_Text_PaulaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle4_Text_WroteSecretCodeLockOpened:
	.string "{PLAYER} a écrit le code secret\n"
	.string "sur la porte. “Le MAÎTRE\p"
	.string "DES PIÈGES est cool.” …\n"
	.string "… … … … … …\p"
	.string "… Le verrou s'est ouvert !$"

Route110_TrickHousePuzzle4_Text_CoraIntro:
	.string "C'est trop compliqué d'y réfléchir.\n"
	.string "Je voulais juste me battre !$"

Route110_TrickHousePuzzle4_Text_CoraDefeat:
	.string "Même si j'ai perdu, j'aime toujours\n"
	.string "me battre avant tout !$"

Route110_TrickHousePuzzle4_Text_CoraPostBattle:
	.string "Tu ne trouves pas ? Tu irais\n"
	.string "partout s'il y avait des DRESSEURS.$"

Route110_TrickHousePuzzle4_Text_YujiIntro:
	.string "Hé ! Des rochers comme ça, je peux\n"
	.string "les écarter d'un doigt !$"

Route110_TrickHousePuzzle4_Text_YujiDefeat:
	.string "Je peux pousser des rochers, mais je ne peux pas\n"
	.string "résoudre l'énigme…$"

Route110_TrickHousePuzzle4_Text_YujiPostBattle:
	.string "Ce n'est pas assez d'être costaud…\n"
	.string "Il faut utiliser sa tête. Sois malin !$"

Route110_TrickHousePuzzle4_Text_PaulaIntro:
	.string "La MAISON PIÈGE devient de plus en plus\n"
	.string "piégeuse, non ?$"

Route110_TrickHousePuzzle4_Text_PaulaDefeat:
	.string "Aaah !$"

Route110_TrickHousePuzzle4_Text_PaulaPostBattle:
	.string "Quelqu'un est-il déjà arrivé au bout ?$"

