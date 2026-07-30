Route110_TrickHousePuzzle6_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHousePuzzle6_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route110_TrickHousePuzzle6_OnWarp
	.byte 0

Route110_TrickHousePuzzle6_OnTransition:
	special RotatingGate_InitPuzzle
	end

Route110_TrickHousePuzzle6_OnWarp:
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, Route110_TrickHousePuzzle6_EventScript_InitPuzzle
	.2byte 0

@ NOTE: This rotating gate puzzle makes use of VAR_TEMP_0 - VAR_TEMP_5
Route110_TrickHousePuzzle6_EventScript_InitPuzzle::
	special RotatingGate_InitPuzzleAndGraphics
	end

Route110_TrickHousePuzzle6_EventScript_Scroll::
	lockall
	goto_if_eq VAR_TRICK_HOUSE_PUZZLE_6_STATE, 0, Route110_TrickHousePuzzle6_EventScript_FoundScroll
	goto Route110_TrickHousePuzzle_EventScript_ReadScrollAgain
	end

Route110_TrickHousePuzzle6_EventScript_FoundScroll::
	setvar VAR_TRICK_HOUSE_PUZZLE_6_STATE, 1
	goto Route110_TrickHousePuzzle_EventScript_FoundScroll
	end

Route110_TrickHousePuzzle6_EventScript_Sophia::
	trainerbattle_single TRAINER_SOPHIA, Route110_TrickHousePuzzle6_Text_SophiaIntro, Route110_TrickHousePuzzle6_Text_SophiaDefeat
	msgbox Route110_TrickHousePuzzle6_Text_SophiaPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_EventScript_Benny::
	trainerbattle_single TRAINER_BENNY, Route110_TrickHousePuzzle6_Text_BennyIntro, Route110_TrickHousePuzzle6_Text_BennyDefeat
	msgbox Route110_TrickHousePuzzle6_Text_BennyPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_EventScript_Sebastian::
	trainerbattle_single TRAINER_SEBASTIAN, Route110_TrickHousePuzzle6_Text_SebastianIntro, Route110_TrickHousePuzzle6_Text_SebastianDefeat
	msgbox Route110_TrickHousePuzzle6_Text_SebastianPostBattle, MSGBOX_AUTOCLOSE
	end

Route110_TrickHousePuzzle6_Text_WroteSecretCodeLockOpened:
	.string "{PLAYER} a écrit le code secret sur\n"
	.string "la porte. « Le MAÎTRE DES\p"
	.string "PIÈGES est ma vie. » …\n"
	.string "… … … … … …\p"
	.string "… Le verrou s'est ouvert !$"

Route110_TrickHousePuzzle6_Text_SophiaIntro:
	.string "Quand j'ai entendu parler d'une maison\n"
	.string "étrange, j'ai dû aller voir.$"

Route110_TrickHousePuzzle6_Text_SophiaDefeat:
	.string "J'ai découvert un DRESSEUR coriace !$"

Route110_TrickHousePuzzle6_Text_SophiaPostBattle:
	.string "Je passe vraiment un bon moment\n"
	.string "à explorer cet endroit.\p"
	.string "C'est un défi que je trouve\n"
	.string "valable de répéter !$"

Route110_TrickHousePuzzle6_Text_BennyIntro:
	.string "Je pourrais peut-être faire voler mes\n"
	.string "POKéMON Oiseau par-dessus le mur…$"

Route110_TrickHousePuzzle6_Text_BennyDefeat:
	.string "Gwaaah ! J'ai tout raté !$"

Route110_TrickHousePuzzle6_Text_BennyPostBattle:
	.string "Eh eh eh… J'ai perdu parce que\n"
	.string "j'essayais de tricher.$"

Route110_TrickHousePuzzle6_Text_SebastianIntro:
	.string "J'ai le tournis à cause de ces portes\n"
	.string "qui tournent…$"

Route110_TrickHousePuzzle6_Text_SebastianDefeat:
	.string "Tout tourne dans tous les sens.\n"
	.string "Je n'en peux plus…$"

Route110_TrickHousePuzzle6_Text_SebastianPostBattle:
	.string "Tu ne sembles pas du tout affecté.\n"
	.string "Ou tu as un bon poker face ?$"

