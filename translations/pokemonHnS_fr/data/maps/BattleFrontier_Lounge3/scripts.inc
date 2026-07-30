BattleFrontier_Lounge3_MapScripts::
	.byte 0

	.set BET_AMOUNT_5,  5
	.set BET_AMOUNT_10, 10
	.set BET_AMOUNT_15, 15

BattleFrontier_Lounge3_EventScript_Gambler::
	lock
	faceplayer
	goto_if_set FLAG_MET_BATTLE_FRONTIER_GAMBLER, BattleFrontier_Lounge3_EventScript_AlreadyMetGambler
	call BattleFrontier_Lounge3_EventScript_CountSilverSymbols
	goto_if_le VAR_0x8004, 2, BattleFrontier_Lounge3_EventScript_NotEnoughSilverSymbols
	setflag FLAG_MET_BATTLE_FRONTIER_GAMBLER
	msgbox BattleFrontier_Lounge3_Text_YouLookToughExplainGambling, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_AskToEnterChallenge
	end

BattleFrontier_Lounge3_EventScript_AskToEnterChallenge::
	special ShowFrontierGamblerLookingMessage
	waitmessage
	waitbuttonpress
	msgbox BattleFrontier_Lounge3_Text_HowAboutEnteringEventForMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge3_EventScript_DeclineChallenge
	msgbox BattleFrontier_Lounge3_Text_SpotMeSomeBattlePoints, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge3_EventScript_DeclineChallenge
	message BattleFrontier_Lounge3_Text_HowMuchCanYouSpot
	waitmessage
	special ShowBattlePointsWindow
	goto BattleFrontier_Lounge3_EventScript_ChooseBetAmount
	end

BattleFrontier_Lounge3_EventScript_ChooseBetAmount::
	multichoice 20, 4, MULTI_FRONTIER_GAMBLER_BET, FALSE
	copyvar VAR_FRONTIER_GAMBLER_AMOUNT_BET, VAR_RESULT
	switch VAR_RESULT
	case FRONTIER_GAMBLER_BET_5, BattleFrontier_Lounge3_EventScript_Bet5
	case FRONTIER_GAMBLER_BET_10, BattleFrontier_Lounge3_EventScript_Bet10
	case FRONTIER_GAMBLER_BET_15, BattleFrontier_Lounge3_EventScript_Bet15
	case FRONTIER_GAMBLER_BET_CANCEL, BattleFrontier_Lounge3_EventScript_CancelBet
	case MULTI_B_PRESSED, BattleFrontier_Lounge3_EventScript_CancelBet
	end

BattleFrontier_Lounge3_EventScript_Bet5::
	setvar VAR_0x8008, BET_AMOUNT_5
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
	end

BattleFrontier_Lounge3_EventScript_Bet10::
	setvar VAR_0x8008, BET_AMOUNT_10
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
	end

BattleFrontier_Lounge3_EventScript_Bet15::
	setvar VAR_0x8008, BET_AMOUNT_15
	goto BattleFrontier_Lounge3_EventScript_TryPlaceBet
	end

BattleFrontier_Lounge3_EventScript_TryPlaceBet::
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_Lounge3_EventScript_PlaceBet
	msgbox BattleFrontier_Lounge3_Text_YouDontHaveEnoughPoints, MSGBOX_DEFAULT
	message BattleFrontier_Lounge3_Text_HowMuchCanYouSpot
	waitmessage
	goto BattleFrontier_Lounge3_EventScript_ChooseBetAmount
	end

BattleFrontier_Lounge3_EventScript_PlaceBet::
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET
	special UpdateBattlePointsWindow
	playse SE_SHOP
	msgbox BattleFrontier_Lounge3_Text_ThanksOffYouGo, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FinishBet
	end

BattleFrontier_Lounge3_EventScript_FinishBet::
	special ShowFrontierGamblerGoMessage
	waitmessage
	waitbuttonpress
	special CloseBattlePointsWindow
	release
	end

BattleFrontier_Lounge3_EventScript_CountSilverSymbols::
	setvar VAR_0x8004, 0
	call_if_set FLAG_SYS_TOWER_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_DOME_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_PALACE_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_ARENA_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_FACTORY_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_PIKE_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	call_if_set FLAG_SYS_PYRAMID_SILVER, BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount
	return

BattleFrontier_Lounge3_EventScript_AddSilverSymbolCount::
	addvar VAR_0x8004, 1
	return

BattleFrontier_Lounge3_EventScript_NotEnoughSilverSymbols::
	msgbox BattleFrontier_Lounge3_Text_CantYouSeeWereBusyHere, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_AlreadyMetGambler::
	msgbox BattleFrontier_Lounge3_Text_Oh, MSGBOX_DEFAULT
	goto_if_ge VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET, BattleFrontier_Lounge3_EventScript_CheckBetResults
	goto BattleFrontier_Lounge3_EventScript_AskToEnterChallenge
	end

BattleFrontier_Lounge3_EventScript_CheckBetResults::
	goto_if_eq VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_PLACED_BET, BattleFrontier_Lounge3_EventScript_ChallengeNotAttempted
	goto_if_eq VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WON, BattleFrontier_Lounge3_EventScript_WonChallenge
	goto BattleFrontier_Lounge3_EventScript_LostChallenge
	end

BattleFrontier_Lounge3_EventScript_WonChallenge::
	msgbox BattleFrontier_Lounge3_Text_HelloChampHeresYourPoints, MSGBOX_DEFAULT
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_5, BattleFrontier_Lounge3_EventScript_RewardBet5
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_10, BattleFrontier_Lounge3_EventScript_RewardBet10
	call_if_eq VAR_FRONTIER_GAMBLER_AMOUNT_BET, FRONTIER_GAMBLER_BET_15, BattleFrontier_Lounge3_EventScript_RewardBet15
	msgbox BattleFrontier_Lounge3_Text_ObtainedBattlePoints, MSGBOX_GETPOINTS
	special GiveFrontierBattlePoints
	msgbox BattleFrontier_Lounge3_Text_ThinkOfMeForAnotherChallenge, MSGBOX_DEFAULT
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WAITING
	release
	end

BattleFrontier_Lounge3_EventScript_LostChallenge::
	msgbox BattleFrontier_Lounge3_Text_NiceTryCantReturnPoints, MSGBOX_DEFAULT
	setvar VAR_FRONTIER_GAMBLER_STATE, FRONTIER_GAMBLER_WAITING
	release
	end

BattleFrontier_Lounge3_EventScript_RewardBet5::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_5 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_5 * 2)
	return

BattleFrontier_Lounge3_EventScript_RewardBet10::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_10 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_10 * 2)
	return

BattleFrontier_Lounge3_EventScript_RewardBet15::
	buffernumberstring STR_VAR_1, (BET_AMOUNT_15 * 2)
	setvar VAR_0x8004, (BET_AMOUNT_15 * 2)
	return

BattleFrontier_Lounge3_EventScript_ChallengeNotAttempted::
	special ShowFrontierGamblerGoMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge3_EventScript_DeclineChallenge::
	msgbox BattleFrontier_Lounge3_Text_NotInterested, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge3_EventScript_CancelBet::
	special CloseBattlePointsWindow
	goto BattleFrontier_Lounge3_EventScript_DeclineChallenge
	end

BattleFrontier_Lounge3_EventScript_Man::
	msgbox BattleFrontier_Lounge3_Text_ShouldBeTakingChallenges, MSGBOX_NPC
	end

BattleFrontier_Lounge3_EventScript_Woman::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_BackedWrongTrainer, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_PokefanF::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_KnowWinnerWhenISeeOne, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_FatMan::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge3_Text_TrainerGoodButRattled, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge3_EventScript_FaceOriginalDirection
	end

BattleFrontier_Lounge3_EventScript_FaceOriginalDirection::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

BattleFrontier_Lounge3_Text_CantYouSeeWereBusyHere::
	.string "...Qu'est-ce que tu veux ?\p"
	.string "Tu ne vois pas qu'on est occupés ?\n"
	.string "Ton affaire peut attendre, non ?$"

BattleFrontier_Lounge3_Text_YouLookToughExplainGambling::
	.string "…Hein ?\n"
	.string "Tu as l'air d'être un DRESSEUR coriace.\p"
	.string "Héhéh…\n"
	.string "Écoute, j'ai une proposition.\p"
	.string "On a un petit groupe ici,\n"
	.string "et on joue un petit jeu avec ce qui se passe\l"
	.string "au PARC DES COMBATS.\p"
	.string "Les règles sont vraiment simples.\p"
	.string "D'abord, on choisit une des installations\n"
	.string "du PARC DES COMBATS.\p"
	.string "Ensuite, on parie chacun sur un DRESSEUR\n"
	.string "différent qui relève le défi de cette installation,\l"
	.string "et on mise avec nos Points de Combat.\p"
	.string "Celui qui a parié sur le DRESSEUR avec\n"
	.string "la meilleure performance remporte tous les Points\l"
	.string "de Combat de la cagnotte.\p"
	.string "Ça a l'air simple, non ?\n"
	.string "Alors, bref…$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerSingle::
	.string "Ce que je cherche, c'est un DRESSEUR qui va\n"
	.string "relever le défi des SALLES DE COMBAT\l"
	.string "SOLO de la TOUR DE COMBAT.\p"
	.string "Mais jusqu'ici, je n'ai pas vu de DRESSEUR\n"
	.string "qui ait cette qualité de vainqueur.$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerDouble::
	.string "Ce que je cherche, c'est un DRESSEUR qui va\n"
	.string "relever le défi des SALLES DE COMBAT\l"
	.string "DUO de la TOUR DE COMBAT.\p"
	.string "Mais jusqu'ici, je n'ai pas vu de DRESSEUR\n"
	.string "qui ait cette qualité de vainqueur.$"

BattleFrontier_Lounge3_Text_ChallengeBattleTowerMulti::
	.string "Ce que je cherche, c'est un DRESSEUR qui va\n"
	.string "relever le défi des SALLES DE COMBAT\l"
	.string "MULTI de la TOUR DE COMBAT.\p"
	.string "Mais jusqu'ici, je n'ai pas vu de DRESSEUR\n"
	.string "qui ait cette qualité de vainqueur.$"

BattleFrontier_Lounge3_Text_ChallengeBattleDomeSingle::
	.string "Ce que je cherche, c'est un DRESSEUR qui va\n"
	.string "participer au Tournoi Combat Solo\l"
	.string "du DÔME DE COMBAT.\p"
	.string "Mais jusqu'ici, je n'ai pas vu de DRESSEUR\n"
	.string "qui ait cette qualité de vainqueur.$"

BattleFrontier_Lounge3_Text_ChallengeBattleDomeDouble::
	.string "Ce que je cherche, c'est un DRESSEUR qui va\n"
	.string "participer au Tournoi Combat Duo\l"
	.string "du DÔME DE COMBAT.\p"
	.string "Mais jusqu'ici, je n'ai pas vu de DRESSEUR\n"
	.string "qui ait cette qualité de vainqueur.$"

BattleFrontier_Lounge3_Text_ChallengeBattleFactorySingle::
	.string "Ce que je cherche, c'est un DRESSEUR qui va\n"
	.string "participer au Tournoi Échange Solo\l"
	.string "du PARC DE COMBAT.\p"
	.string "Mais jusqu'ici, je n'ai pas vu de DRESSEUR\n"
	.string "qui ait cette qualité de vainqueur.$"

BattleFrontier_Lounge3_Text_ChallengeBattleFactoryDouble::
	.string "Ce que je cherche, c'est un DRESSEUR qui va\n"
	.string "participer au Tournoi Échange Double\l"
	.string "du PARC DE COMBAT.\p"
	.string "Mais jusqu'ici, je n'ai pas vu de DRESSEUR\n"
	.string "qui ait cette qualité de vainqueur.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePalaceSingle::
	.string "Ce que je cherche, c'est un DRESSEUR qui va\n"
	.string "relever le défi des SALLES DE COMBAT\l"
	.string "SOLO du PALAIS DE COMBAT.\p"
	.string "Mais jusqu'ici, je n'ai pas vu de DRESSEUR\n"
	.string "qui ait cette qualité de vainqueur.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePalaceDouble::
	.string "Ce que je cherche, c'est un DRESSEUR qui va\n"
	.string "relever le défi des SALLES DE COMBAT\l"
	.string "DUO du PALAIS DE COMBAT.\p"
	.string "Mais jusqu'ici, je n'ai pas vu de DRESSEUR\n"
	.string "qui ait cette qualité de vainqueur.$"

BattleFrontier_Lounge3_Text_ChallengeBattleArena::
	.string "Ce que je cherche, c'est un DRESSEUR qui va\n"
	.string "participer au Tournoi de l'\l"
	.string "ARÈNE DE COMBAT.\p"
	.string "Mais jusqu'ici, je n'ai pas vu de DRESSEUR\n"
	.string "qui ait cette qualité de vainqueur.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePike::
	.string "Ce que je cherche, c'est un DRESSEUR qui va\n"
	.string "relever le défi du SERPENT\l"
	.string "DE COMBAT.\p"
	.string "Mais jusqu'ici, je n'ai pas vu de DRESSEUR\n"
	.string "qui ait cette qualité de vainqueur.$"

BattleFrontier_Lounge3_Text_ChallengeBattlePyramid::
	.string "Ce que je cherche, c'est un DRESSEUR qui va\n"
	.string "participer à la PYRAMIDE\l"
	.string "DE COMBAT.\p"
	.string "Mais jusqu'ici, je n'ai pas vu de DRESSEUR\n"
	.string "qui ait cette qualité de vainqueur.$"

BattleFrontier_Lounge3_Text_HowAboutEnteringEventForMe::
	.string "Je veillerai à ce que tu en profites aussi.\n"
	.string "Alors, qu'en dis-tu ?\l"
	.string "Tu veux bien participer à cet événement pour moi ?$"

BattleFrontier_Lounge3_Text_SpotMeSomeBattlePoints::
	.string "D'accord, c'est parfait.\n"
	.string "Alors, euh… Tu pourrais me prêter\l"
	.string "quelques Points de Combat ?\p"
	.string "Fais-moi confiance, je te montrerai\n"
	.string "ma gratitude après.$"

BattleFrontier_Lounge3_Text_HowMuchCanYouSpot::
	.string "Super, super !\n"
	.string "Alors, combien peux-tu me prêter ?$"

BattleFrontier_Lounge3_Text_YouDontHaveEnoughPoints::
	.string "Oh, non, non, non ! Tu n'as pas\n"
	.string "assez de Points de Combat ! J'aimerais que\p"
	.string "tu arrêtes de plaisanter et de faire perdre\n"
	.string "du temps à tout le monde !$"

BattleFrontier_Lounge3_Text_ThanksOffYouGo::
	.string "Héhé ! Merci beaucoup !\n"
	.string "Allez, au travail !$"

BattleFrontier_Lounge3_Text_GetToBattleTowerSingle::
	.string "File à la TOUR DE COMBAT,\n"
	.string "aux SALLES DE COMBAT SOLO !\p"
	.string "C'est une situation où il faut gagner !\n"
	.string "Ne gâche pas ta chance !\l"
	.string "Nos deux avenirs dépendent de toi !$"

BattleFrontier_Lounge3_Text_GetToBattleTowerDouble::
	.string "File à la TOUR DE COMBAT,\n"
	.string "aux SALLES DE COMBAT EN DOUBLE !\p"
	.string "C'est une situation où il faut gagner !\n"
	.string "Ne gâche pas ta chance !\l"
	.string "Nos deux avenirs dépendent de toi !$"

BattleFrontier_Lounge3_Text_GetToBattleTowerMulti::
	.string "File à la TOUR DE COMBAT,\n"
	.string "aux SALLES DE COMBAT MULTI !\p"
	.string "C'est une situation où il faut gagner !\n"
	.string "Ne gâche pas ta chance !\l"
	.string "Nos deux avenirs dépendent de toi !$"

BattleFrontier_Lounge3_Text_GetToBattleDomeSingle::
	.string "Va vite au Tournoi de COMBATS\n"
	.string "SIMPLES du DÔME DE COMBAT !\p"
	.string "C'est une situation où il faut gagner !\n"
	.string "Ne gâche pas ta chance !\l"
	.string "Nos deux avenirs dépendent de toi !$"

BattleFrontier_Lounge3_Text_GetToBattleDomeDouble::
	.string "Va vite au Tournoi de COMBATS\n"
	.string "DOUBLES du DÔME DE COMBAT !\p"
	.string "C'est une situation où il faut gagner !\n"
	.string "Ne gâche pas ta chance !\l"
	.string "Nos deux avenirs dépendent de toi !$"

BattleFrontier_Lounge3_Text_GetToBattleFactorySingle::
	.string "Va vite au Tournoi Échange Simple\n"
	.string "de l'USINE DE COMBAT !\p"
	.string "C'est une situation où il faut gagner !\n"
	.string "Ne gâche pas ta chance !\l"
	.string "Nos deux avenirs dépendent de toi !$"

BattleFrontier_Lounge3_Text_GetToBattleFactoryDouble::
	.string "Va vite au Tournoi Échange Double\n"
	.string "de l'USINE DE COMBAT !\p"
	.string "C'est une situation où il faut gagner !\n"
	.string "Ne gâche pas ta chance !\l"
	.string "Nos deux avenirs dépendent de toi !$"

BattleFrontier_Lounge3_Text_GetToBattlePalaceSingle::
	.string "Va vite aux SALLES DE COMBAT\n"
	.string "SOLO du PALAIS DE COMBAT !\p"
	.string "C'est une situation où il faut gagner !\n"
	.string "Ne gâche pas ta chance !\l"
	.string "Nos deux avenirs dépendent de toi !$"

BattleFrontier_Lounge3_Text_GetToBattlePalaceDouble::
	.string "Va vite aux SALLES DE COMBAT\n"
	.string "EN DOUBLE du PALAIS DE COMBAT !\p"
	.string "C'est une situation où il faut gagner !\n"
	.string "Ne gâche pas ta chance !\l"
	.string "Nos deux avenirs dépendent de toi !$"

BattleFrontier_Lounge3_Text_GetToBattleArena::
	.string "File à l'ARÈNE DE COMBAT,\n"
	.string "au Tournoi K.O. Direct !\p"
	.string "C'est une situation où il faut gagner !\n"
	.string "Ne gâche pas ta chance !\l"
	.string "Nos deux avenirs dépendent de toi !$"

BattleFrontier_Lounge3_Text_GetToBattlePike::
	.string "File au RAYON VERT,\n"
	.string "au Choix de Combat !\p"
	.string "C'est une situation où il faut gagner !\n"
	.string "Ne gâche pas ta chance !\l"
	.string "Nos deux avenirs dépendent de toi !$"

BattleFrontier_Lounge3_Text_GetToBattlePyramid::
	.string "File à la PYRAMIDE DE COMBAT,\n"
	.string "à la Quête de Combat !\p"
	.string "C'est une situation où il faut gagner !\n"
	.string "Ne gâche pas ta chance !\l"
	.string "Nos deux avenirs dépendent de toi !$"

BattleFrontier_Lounge3_Text_NiceTryCantReturnPoints::
	.string "Oh, c'est toi…\n"
	.string "Bien essayé…\p"
	.string "Je déteste te le dire, mais je ne peux pas\n"
	.string "te rendre tes Points de Combat…\p"
	.string "Je suppose qu'il faudra s'en servir\n"
	.string "pour nous motiver à faire mieux la prochaine fois !$"

BattleFrontier_Lounge3_Text_HelloChampHeresYourPoints::
	.string "Oh, oui !\n"
	.string "Bonjour, champion !\p"
	.string "Je savais que tu le ferais !\n"
	.string "Je savais que tu y arriverais !\l"
	.string "On est tous les deux\p"
	.string "formidables !\n"
	.string "Bravo !$"

BattleFrontier_Lounge3_Text_ObtainedBattlePoints::
	.string "{PLAYER} a obtenu\n"
	.string "{STR_VAR_1} Points de Combat.$"

BattleFrontier_Lounge3_Text_ThinkOfMeForAnotherChallenge::
	.string "Si tu es partant pour un autre défi,\n"
	.string "pense à moi, s'il te plaît !$"

BattleFrontier_Lounge3_Text_NotInterested::
	.string "Pas intéressé ?! Tu ne devrais pas\n"
	.string "avoir si peur de tenter ta chance !$"

BattleFrontier_Lounge3_Text_Oh::
	.string "Oh…$"

BattleFrontier_Lounge3_Text_BackedWrongTrainer::
	.string "J'ai encore soutenu le mauvais DRESSEUR !\p"
	.string "Peut-être que je devrais combattre normalement\n"
	.string "comme tout le monde…$"

BattleFrontier_Lounge3_Text_TrainerGoodButRattled::
	.string "Ce DRESSEUR…\p"
	.string "Il est bon, mais il panique trop facilement\n"
	.string "pour survivre au DÔME DE COMBAT…$"

BattleFrontier_Lounge3_Text_KnowWinnerWhenISeeOne::
	.string "Hihi !\n"
	.string "Je reconnais un gagnant quand j'en vois un !$"

BattleFrontier_Lounge3_Text_ShouldBeTakingChallenges::
	.string "Ces DRESSEURS…\n"
	.string "Que font-ils ?\l"
	.string "Ils devraient relever des défis.$"
