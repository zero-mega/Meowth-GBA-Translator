GoldenrodCity_House1_MapScripts::
	.byte 0

GoldenrodCity_NameRatersHouse_EventScript_ToggleShinies::
	lock
	msgbox GoldenrodCity_NameRatersHouse_Text_AskToggleShinies, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_NameRatersHouse_EventScript_ToggleShiniesRefused
	special ToggleShinyColors
	msgbox GoldenrodCity_NameRatersHouse_Text_ToggleShinies, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_NameRatersHouse_EventScript_ToggleShiniesRefused::
	release
	end

GoldenrodCity_NameRatersHouse_Text_AskToggleShinies:
	.string "Veux-tu activer ou désactiver le paramètre\n"
	.string "Couleurs Chromatiques uniques ?$"

GoldenrodCity_NameRatersHouse_Text_ToggleShinies:
	.string "Couleurs chromatiques activées !\p"
	.string "Consulte ton réglage au\n"
	.string "VISUALISEUR DE DÉFIS sur n'importe quel PC.$"

GoldenrodCity_NameRatersHouse_EventScript_RenameRival::
	msgbox GoldenrodCity_NameRatersHouse_Text_RenameRival, MSGBOX_DEFAULT
	closemessage
	special NameRival
	waitstate
	end

GoldenrodCity_NameRatersHouse_Text_RenameRival:
	.string "C'est aux infos…\p"
	.string "La POLICE recherche ce\n"
	.string "GARÇON AUX CHEVEUX ROUGES !\p"
	.string "Tu connais son nom ?$"

GoldenrodCity_NameRatersHouse_EventScript_NameRater::
	lock
	faceplayer
	msgbox GoldenrodCity_NameRatersHouse_Text_PleasedToRateMonNickname, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, GoldenrodCity_NameRatersHouse_EventScript_ChooseMonToRate
	goto_if_eq VAR_RESULT, NO, GoldenrodCity_NameRatersHouse_EventScript_DeclineNameRate
	end

GoldenrodCity_NameRatersHouse_EventScript_ChooseMonToRate::
	msgbox GoldenrodCity_NameRatersHouse_Text_CritiqueWhichMonNickname, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	lock
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, GoldenrodCity_NameRatersHouse_EventScript_RateMonNickname
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, GoldenrodCity_NameRatersHouse_EventScript_DeclineNameRate
	end

GoldenrodCity_NameRatersHouse_EventScript_DeclineNameRate::
	msgbox GoldenrodCity_NameRatersHouse_Text_DoVisitAgain, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_NameRatersHouse_EventScript_RateMonNickname::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, GoldenrodCity_NameRatersHouse_EventScript_CantRateEgg
	special BufferMonNickname
	@special IsMonOTIDNotPlayers
	@goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	@specialvar VAR_RESULT, MonOTNameNotPlayer
	special BufferMonNickname
	@goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_NameRatersHouse_EventScript_PlayerNotMonsOT
	msgbox GoldenrodCity_NameRatersHouse_Text_FineNameSuggestBetterOne, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, GoldenrodCity_NameRatersHouse_EventScript_ChangeNickname
	goto_if_eq VAR_RESULT, NO, GoldenrodCity_NameRatersHouse_EventScript_DeclineNameRate
	end

GoldenrodCity_NameRatersHouse_EventScript_CantRateEgg::
	msgbox GoldenrodCity_NameRatersHouse_Text_ThatIsMerelyAnEgg, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_NameRatersHouse_EventScript_PlayerNotMonsOT::
	msgbox GoldenrodCity_NameRatersHouse_Text_MagnificentName, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_NameRatersHouse_EventScript_ChangeNickname::
	msgbox GoldenrodCity_NameRatersHouse_Text_WhatShallNewNameBe, MSGBOX_DEFAULT
	call Common_EventScript_NameReceivedPartyMon
	specialvar VAR_RESULT, TryPutNameRaterShowOnTheAir
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_NameRatersHouse_EventScript_NewNameDifferent
	msgbox GoldenrodCity_NameRatersHouse_Text_NameNoDifferentYetSuperior, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_NameRatersHouse_EventScript_NewNameDifferent::
	msgbox GoldenrodCity_NameRatersHouse_Text_MonShallBeKnownAsName, MSGBOX_DEFAULT
	release
	end

GoldenrodCity_NameRatersHouse_Text_PleasedToRateMonNickname:
	.string "Salut, salut ! Je suis le JUGE DES\n"
	.string "SURNOMS ! Je suis le diseur de\p"
	.string "bonne aventure des noms ! Je serai\n"
	.string "ravi d'évaluer le surnom de ton POKéMON.$"

GoldenrodCity_NameRatersHouse_Text_CritiqueWhichMonNickname:
	.string "Le surnom de quel POKéMON\n"
	.string "dois-je critiquer ?$"

GoldenrodCity_NameRatersHouse_Text_FineNameSuggestBetterOne:
	.string "Hmmm… {STR_VAR_1}, c'est ça ? C'est\n"
	.string "un bien joli nom que tu as donné.\p"
	.string "Mais ! Que dirais-tu si je te\n"
	.string "suggérais un nom un peu meilleur ?$"

GoldenrodCity_NameRatersHouse_Text_WhatShallNewNameBe:
	.string "Ah, bien. Alors, quel sera\n"
	.string "le nouveau surnom ?$"

GoldenrodCity_NameRatersHouse_Text_MonShallBeKnownAsName:
	.string "C'est fait ! Désormais, ce\n"
	.string "POKéMON s'appellera {STR_VAR_1} ! C'est\p"
	.string "un meilleur nom qu'avant !\n"
	.string "Quelle chance pour toi !$"

GoldenrodCity_NameRatersHouse_Text_DoVisitAgain:
	.string "Je vois.\n"
	.string "Reviens nous voir.$"

GoldenrodCity_NameRatersHouse_Text_NameNoDifferentYetSuperior:
	.string "C'est fait ! Désormais, ce POKéMON\n"
	.string "s'appellera {STR_VAR_1} !\p"
	.string "Il n'a pas l'air différent qu'avant,\n"
	.string "et pourtant, c'est bien supérieur !\p"
	.string "Quelle chance pour toi !$"

GoldenrodCity_NameRatersHouse_Text_MagnificentName:
	.string "Hmmm… {STR_VAR_1}, c'est ça !\p"
	.string "C'est un surnom magnifique !\n"
	.string "Il est impeccablement irréprochable !\p"
	.string "Tu ferais bien de chérir ton\n"
	.string "{STR_VAR_1} maintenant et à l'avenir.$"

GoldenrodCity_NameRatersHouse_Text_ThatIsMerelyAnEgg:
	.string "Doucement.\n"
	.string "Ce n'est qu'un ŒUF !$"


