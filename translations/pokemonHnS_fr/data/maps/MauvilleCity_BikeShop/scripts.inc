MauvilleCity_BikeShop_MapScripts::
	.byte 0

MauvilleCity_BikeShop_EventScript_Rydel::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_BIKE, MauvilleCity_BikeShop_EventScript_AskSwitchBikes
	goto_if_set FLAG_DECLINED_BIKE, MauvilleCity_BikeShop_EventScript_SkipGreeting
	msgbox MauvilleCity_BikeShop_Text_RydelGreeting, MSGBOX_DEFAULT
	msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_YesFar
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_NotFar
	end

MauvilleCity_BikeShop_EventScript_SkipGreeting::
	msgbox MauvilleCity_BikeShop_Text_DidYouComeFromFarAway, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_YesFar
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_NotFar
	end

MauvilleCity_BikeShop_EventScript_ChooseBike::
	msgbox MauvilleCity_BikeShop_Text_ExplainBikesChooseWhichOne, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_GetAcroBike
	goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_GetMachBike
	@waitmessage
	@multichoice 21, 8, MULTI_BIKE, TRUE
	@switch VAR_RESULT
	@case 0, MauvilleCity_BikeShop_EventScript_GetMachBike
	@case 1, MauvilleCity_BikeShop_EventScript_GetMachBike
	end

MauvilleCity_BikeShop_EventScript_NotFar::
	setflag FLAG_DECLINED_BIKE
	msgbox MauvilleCity_BikeShop_Text_GuessYouDontNeedBike, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_YesFar::
	goto MauvilleCity_BikeShop_EventScript_ChooseBike
	end

MauvilleCity_BikeShop_EventScript_GetMachBike::
	msgbox MauvilleCity_BikeShop_Text_GuessYouDontNeedBike2, MSGBOX_DEFAULT
	@giveitem ITEM_MACH_BIKE
	@goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	release
	end

MauvilleCity_BikeShop_EventScript_GetAcroBike::
	msgbox MauvilleCity_BikeShop_Text_ChoseAcroBike, MSGBOX_DEFAULT
	giveitem ITEM_MACH_BIKE
	setflag FLAG_RECEIVED_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_ComeBackToSwitchBikes, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_AskSwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_WantToSwitchBikes, MSGBOX_NPC
	@goto_if_eq VAR_RESULT, YES, MauvilleCity_BikeShop_EventScript_SwitchBikes
	@goto_if_eq VAR_RESULT, NO, MauvilleCity_BikeShop_EventScript_KeepBike
	end

@ If the player does not have a bike on them Rydel assumes its stored in the PC
MauvilleCity_BikeShop_EventScript_SwitchBikes::
	msgbox MauvilleCity_BikeShop_Text_IllSwitchBikes, MSGBOX_DEFAULT
	checkitem ITEM_ACRO_BIKE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BikeShop_EventScript_SwitchAcroForMach
	checkitem ITEM_MACH_BIKE
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_BikeShop_EventScript_SwitchMachForAcro
	msgbox MauvilleCity_BikeShop_Text_OhYourBikeIsInPC, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_KeepBike::
	msgbox MauvilleCity_BikeShop_Text_HappyYouLikeIt, MSGBOX_DEFAULT
	release
	end

MauvilleCity_BikeShop_EventScript_SwitchAcroForMach::
	incrementgamestat GAME_STAT_TRADED_BIKES
	msgbox MauvilleCity_BikeShop_Text_ExchangedAcroForMach, MSGBOX_DEFAULT
	removeitem ITEM_ACRO_BIKE
	giveitem ITEM_MACH_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_SwitchMachForAcro::
	incrementgamestat GAME_STAT_TRADED_BIKES
	msgbox MauvilleCity_BikeShop_Text_ExchangedMachForAcro, MSGBOX_DEFAULT
	removeitem ITEM_MACH_BIKE
	giveitem ITEM_ACRO_BIKE
	goto MauvilleCity_BikeShop_EventScript_ComeBackToSwitchBikes
	end

MauvilleCity_BikeShop_EventScript_Assistant::
	msgbox MauvilleCity_BikeShop_Text_HandbooksAreInBack, MSGBOX_NPC
	end

MauvilleCity_BikeShop_EventScript_MachBikeHandbook::
	message MauvilleCity_BikeShop_Text_MachHandbookWhichPage
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage::
	multichoice 0, 0, MULTI_MACH_BIKE_INFO, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_HowToRide
	case 1, MauvilleCity_BikeShop_EventScript_HowToTurn
	case 2, MauvilleCity_BikeShop_EventScript_SandySlopes
	case 3, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitMachHandbook
	end

MauvilleCity_BikeShop_EventScript_HowToRide::
	message MauvilleCity_BikeShop_Text_HowToRideMachBike
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_HowToTurn::
	message MauvilleCity_BikeShop_Text_HowToTurnMachBike
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_SandySlopes::
	message MauvilleCity_BikeShop_Text_SandySlopes
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseMachHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ExitMachHandbook::
	release
	end

MauvilleCity_BikeShop_EventScript_AcroBikeHandbook::
	message MauvilleCity_BikeShop_Text_AcroHandbookWhichPage
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage::
	multichoice 0, 0, MULTI_ACRO_BIKE_INFO, FALSE
	switch VAR_RESULT
	case 0, MauvilleCity_BikeShop_EventScript_Wheelies
	case 1, MauvilleCity_BikeShop_EventScript_BunnyHops
	case 2, MauvilleCity_BikeShop_EventScript_Jumps
	case 3, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
	case MULTI_B_PRESSED, MauvilleCity_BikeShop_EventScript_ExitAcroHandbook
	end

MauvilleCity_BikeShop_EventScript_Wheelies::
	message MauvilleCity_BikeShop_Text_Wheelies
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_BunnyHops::
	message MauvilleCity_BikeShop_Text_BunnyHops
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_Jumps::
	message MauvilleCity_BikeShop_Text_Jumps
	waitmessage
	goto MauvilleCity_BikeShop_EventScript_ChooseAcroHandbookPage
	end

MauvilleCity_BikeShop_EventScript_ExitAcroHandbook::
	release
	end

MauvilleCity_BikeShop_Text_RydelGreeting:
	.string "Eh bien, eh bien, qu'avons-nous là ?\n"
	.string "Un client plein d'énergie ! Moi ?\p"
	.string "Tu peux m'appeler RYDEL. Je suis le\n"
	.string "propriétaire de ce magasin de vélos.$"

MauvilleCity_BikeShop_Text_DidYouComeFromFarAway:
	.string "RYDEL : Tes CHAUSSURES DE COURSE…\n"
	.string "Elles sont terriblement sales.\p"
	.string "Tu viens de loin ?$"

MauvilleCity_BikeShop_Text_GuessYouDontNeedBike:
	.string "RYDEL : C'est vrai ?\p"
	.string "Alors, je suppose que tu n'as pas besoin\n"
	.string "d'aucun de mes VÉLOS.$"

MauvilleCity_BikeShop_Text_GuessYouDontNeedBike2:
	.string "RYDEL : C'est ça ?\p"
	.string "OK, c'est comme tu veux.$"

MauvilleCity_BikeShop_Text_ExplainBikesChooseWhichOne:
	.string "RYDEL : Hm, hm… … … … …\p"
	.string "Tu dis que tu es venu jusqu'ici\n"
	.string "depuis BOURG-EN-HERBE ?\p"
	.string "Mon Dieu !\n"
	.string "C'est ridiculement loin !\p"
	.string "Si tu avais un de mes VÉLOS, tu pourrais\n"
	.string "aller partout facilement en sentant\l"
	.string "la caresse douce du vent !\p"
	.string "Je vais te dire quoi !\n"
	.string "Je vais te donner un VÉLO !\p"
	.string "Oh, attends une seconde !\p"
	.string "J'ai oublié de te dire qu'il y a\n"
	.string "deux types de VÉLOS !\p"
	.string "Ce sont le VÉLO COURSE et\n"
	.string "le VÉLO CROISEUR !\p"
	.string "Le VÉLO COURSE est pour les cyclistes qui veulent\n"
	.string "sentir le vent sur leur corps !\p"
	.string "Et un VÉLO CROISEUR est pour ceux qui\n"
	.string "préfèrent les figures techniques !\p"
	.string "Et tu sais ce qu'il y a de mieux ?\p"
	.string "Les VÉLOS CROISEUR et COURSE ne font qu'un\n"
	.string "seul VÉLO ! Tout-en-un !\p"
	.string "Alors, tu veux un VÉLO ?$"

MauvilleCity_BikeShop_Text_ChoseMachBike:
	.string "{PLAYER} a choisi le VÉLO CROSS.$"

MauvilleCity_BikeShop_Text_ChoseAcroBike:
	.string "{PLAYER} a reçu un VÉLO.$"

MauvilleCity_BikeShop_Text_ComeBackToSwitchBikes:
	.string "RYDEL : Profite de ta nouvelle BICYCLETTE !\p"
	.string "RYDEL : N'oublie pas d'appuyer sur le\n"
	.string "bouton R pour changer de mode.$"

MauvilleCity_BikeShop_Text_WantToSwitchBikes:
	.string "RYDEL : Tu apprécies\n"
	.string "ton VÉLO ?\p"
	.string "RYDEL : N'oublie pas d'appuyer sur le\n"
	.string "bouton R pour changer de mode.$"

MauvilleCity_BikeShop_Text_IllSwitchBikes:
	.string "RYDEL : OK, pas de problème !\n"
	.string "Je vais échanger les BICYCLETTES !$"

MauvilleCity_BikeShop_Text_ExchangedMachForAcro:
	.string "{PLAYER} a échangé le VÉLO CROSS\n"
	.string "contre un VÉLO CROIX.$"

MauvilleCity_BikeShop_Text_ExchangedAcroForMach:
	.string "{PLAYER} a échangé la BICYCLETTE CROIZ\n"
	.string "contre une BICYCLETTE RUSH.$"

MauvilleCity_BikeShop_Text_HappyYouLikeIt:
	.string "RYDEL : Bien, bien !\n"
	.string "Je suis content que ça te plaise !$"

MauvilleCity_BikeShop_Text_OhYourBikeIsInPC:
	.string "Oh ? Qu'est-il arrivé au VÉLO que\n"
	.string "je t'ai donné ? Oh, je comprends,\p"
	.string "tu l'as stocké avec ton PC. Eh\p"
	.string "bien, sors-le du stockage PC, et\n"
	.string "je serai heureux de l'échanger !\p"
	.string "Que le vent soit toujours dans\n"
	.string "ton dos pendant ton aventure !$"

MauvilleCity_BikeShop_Text_HandbooksAreInBack:
	.string "J'apprends tout sur les VÉLOS en\n"
	.string "travaillant ici.\p"
	.string "Si tu as besoin de conseils pour rouler\n"
	.string "ton VÉLO, il y a quelques manuels\l"
	.string "à l'arrière.$"

MauvilleCity_BikeShop_Text_MachHandbookWhichPage:
	.string "C'est un manuel sur la BICYCLETTE RUSH.\p"
	.string "Quelle page veux-tu lire ?$"

MauvilleCity_BikeShop_Text_HowToRideMachBike:
	.string "Un VÉLO se déplace dans la\n"
	.string "direction où la croix est pressée.\p"
	.string "Il accélère une fois lancé. Pour\p"
	.string "t'arrêter, relâche la croix. Le VÉLO\n"
	.string "ralentira jusqu'à s'arrêter. Tu veux\p"
	.string "lire une autre page ?$"

MauvilleCity_BikeShop_Text_HowToTurnMachBike:
	.string "Un VÉLO CROSS est rapide,\n"
	.string "mais il ne s'arrête pas\p"
	.string "très vite. C'est un peu\n"
	.string "délicat de tourner. Relâche la\p"
	.string "croix un peu avant le\n"
	.string "coin et ralentis. Tu veux\p"
	.string "lire une autre page ?$"

MauvilleCity_BikeShop_Text_SandySlopes:
	.string "Il y a de petites pentes\n"
	.string "sablonneuses partout dans la région de\p"
	.string "HOENN. Le sable meuble rend l'escalade\n"
	.string "impossible normalement. Mais si tu as\p"
	.string "un VÉLO CROSS, tu peux monter\n"
	.string "une pente sablonneuse. Tu veux\p"
	.string "lire une autre page ?$"

MauvilleCity_BikeShop_Text_AcroHandbookWhichPage:
	.string "C'est un manuel sur la BICYCLETTE CROIZ.\p"
	.string "Quelle page veux-tu lire ?$"

MauvilleCity_BikeShop_Text_Wheelies:
	.string "Appuie sur le bouton B en\n"
	.string "roulant, et la roue avant\p"
	.string "se soulève. Tu peux filer\n"
	.string "comme ça ! Mais attention\p"
	.string "aux virages ! Tu veux\p"
	.string "lire une autre page ?$"

MauvilleCity_BikeShop_Text_BunnyHops:
	.string "En maintenant le bouton B enfoncé,\n"
	.string "ton VÉLO peut sauter sur place.\p"
	.string "Cette technique s'appelle le BUNNY HOP.\p"
	.string "Essaie !\p"
	.string "C'est amusant !$"

MauvilleCity_BikeShop_Text_Jumps:
	.string "Appuie sur le bouton B et la\n"
	.string "croix directionnelle en même temps pour\p"
	.string "sauter. Appuie sur la croix sur\n"
	.string "le côté pour sauter sur le\p"
	.string "côté. Appuie en arrière pour faire\n"
	.string "tourner le VÉLO en sautant. Tu\p"
	.string "veux lire une autre page ?$"

