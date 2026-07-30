Roulette_EventScript_Table1::
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 0
	getpokenewsactive POKENEWS_GAME_CORNER
	goto_if_eq VAR_RESULT, FALSE, Roulette_EventScript_Play
	addvar VAR_0x8004, ROULETTE_SPECIAL_RATE
	goto Roulette_EventScript_Play
	end

Roulette_EventScript_Table2::
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_GameCorner_EventScript_NoCoinCase
	setvar VAR_0x8004, 1
	getpokenewsactive POKENEWS_GAME_CORNER
	goto_if_eq VAR_RESULT, FALSE, Roulette_EventScript_Play
	addvar VAR_0x8004, ROULETTE_SPECIAL_RATE
	goto Roulette_EventScript_Play
	end

Roulette_EventScript_Play::
	special PlayRoulette
	waitstate
	end

Roulette_Text_PlayMinimumWagerIsX::
	.string "La mise minimale à cette table\n"
	.string "est de {STR_VAR_1}. Tu veux jouer ?$"

Roulette_Text_NotEnoughCoins::
	.string "Tu n'as pas assez de JETONS.$"

Roulette_Text_SpecialRateTable::
	.string "Tableau des taux spéciaux en ce moment !$"

Roulette_Text_ControlsInstruction::
	.string "Place ta mise avec le + du\n"
	.string "Pavé Directionnel, puis appuie sur A.$"

Roulette_Text_ItsAHit::
	.string "C'est gagné !$"

Roulette_Text_Jackpot::
	.string "Jackpot !$"

Roulette_Text_NothingDoing::
	.string "Pas question !$"

Roulette_Text_YouveWonXCoins::
	.string "Tu as gagné {STR_VAR_1} JETONS !$"

Roulette_Text_NoCoinsLeft::
	.string "Plus de JETONS…$"

Roulette_Text_KeepPlaying::
	.string "Continuer à jouer ?$"

Roulette_Text_BoardWillBeCleared::
	.string "Le plateau de la ROULETTE sera effacé.$"

@ Unused
Roulette_Text_YouDontHaveACoinCase::
	.string "Tu n'as pas de BOÎTE À JETONS.$"

Roulette_Text_CoinCaseIsFull::
	.string "Ta BOÎTE JETONS est pleine !\n"
	.string "Les jetons peuvent être échangés contre des lots.$"
