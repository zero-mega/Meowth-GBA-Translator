PewterCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PewterCity_EventScript_CityEnter
	.byte 0

PewterCity_EventScript_CityEnter::
	setflag FLAG_VISITED_PEWTER_CITY
	end

PewterCity_EventScript_CooltrainerF::
	msgbox PewterCity_Text_CooltrainerF, MSGBOX_NPC
	end

PewterCity_EventScript_BugCatcher::
	msgbox PewterCity_Text_BugCatcher, MSGBOX_NPC
	end

PewterCity_EventScript_Gramps::
	lock
	faceplayer
	goto_if_eq VAR_LUGIA_OR_HOOH, 1, PewterCity_EventScript_GrampsRainbowWing
	goto_if_eq VAR_LUGIA_OR_HOOH, 2, PewterCity_EventScript_GrampsSilverWing
	end

PewterCity_EventScript_GrampsRainbowWing::
	checkitem ITEM_RAINBOW_WING
	goto_if_eq VAR_RESULT, TRUE, PewterCity_EventScript_GrampsDone
	msgbox PewterCity_Text_Gramps, MSGBOX_DEFAULT
	setvar VAR_COMPLETED_HO_OH, 4
	giveitem ITEM_RAINBOW_WING
	setflag FLAG_HIDE_TINTOWER_GUARD
	closemessage
	release
	end

PewterCity_EventScript_GrampsSilverWing::
	checkitem ITEM_SILVER_WING
	goto_if_eq VAR_RESULT, TRUE, PewterCity_EventScript_GrampsDone
	msgbox PewterCity_Text_Gramps, MSGBOX_DEFAULT
	setvar VAR_COMPLETED_LUGIA, 4
	giveitem ITEM_SILVER_WING
	setflag FLAG_HIDE_WHIRL_ISLANDS_TENTACRUEL
	closemessage
	release
	end

PewterCity_EventScript_GrampsDone::
	msgbox PewterCity_Text_Gramps_GotSilverWing, MSGBOX_DEFAULT
	closemessage
	release
	end

PewterCity_EventScript_Bugcatcher::
	msgbox PewterCity_Text_BugCatcher, MSGBOX_NPC
	end

PewterCity_EventScript_Cooltrainer::
	msgbox PewterCity_Text_CooltrainerF, MSGBOX_NPC
	end

PewterCity_Text_CooltrainerF:
	.string "Tu es allé à l'ARÈNE d'ARGENTA ?\p"
	.string "Le CHAMPION utilise des POKéMON de type ROCHE.$"

PewterCity_Text_BugCatcher:
	.string "La nuit, des MÉLOFÉE sortent jouer\n"
	.string "au MONT LUNE.\p"
	.string "Mais pas toutes les nuits.$"

PewterCity_Text_Gramps:
	.string "Ah, tu es venu jusqu'ici depuis\n"
	.string "JOHTO ? Ça me rappelle des\p"
	.string "souvenirs. Quand j'étais jeune, je suis\n"
	.string "allé à JOHTO pour m'entraîner. Tu\p"
	.string "me rappelles tellement ce que j'étais\n"
	.string "quand j'étais jeune. Tiens. Je veux\p"
	.string "que tu aies cet objet\n"
	.string "que j'ai trouvé à JOHTO.$"

PewterCity_Text_Gramps_GotSilverWing:
	.string "Aller vers de nouveaux endroits inconnus\n"
	.string "et rencontrer de nouvelles personnes…\p"
	.string "Voilà les joies du voyage.$"

PewterCity_EventScript_CitySign::
	msgbox PewterCity_Text_Sign, MSGBOX_NPC
	end

PewterCity_EventScript_GymSign::
	msgbox PewterCity_Text_GymSign, MSGBOX_NPC
	end

PewterCity_EventScript_MuseumSign::
	msgbox PewterCity_Text_MuseumSign, MSGBOX_NPC
	end

PewterCity_EventScript_MtMoonSign::
	msgbox PewterCity_Text_MtMoonGiftShopSign, MSGBOX_NPC
	end

PewterCity_EventScript_WelcomeSign::
	msgbox PewterCity_Text_WelcomeSign, MSGBOX_NPC
	end

PewterCity_Text_Sign:
	.string "ARGENTA\n"
	.string "La ville de pierre grise$"

PewterCity_Text_GymSign:
	.string "ARÈNE POKéMON DE JADIELLE\n"
	.string "CHAMPION D'ARÈNE : PIERRE\p"
	.string "Le DRESSEUR POKéMON solide comme le roc$"

PewterCity_Text_MuseumSign:
	.string "Il y a un avis ici…\p"
	.string "Le MUSÉE DES SCIENCES DE JADIELLE est fermé\n"
	.string "pour rénovation…$"

PewterCity_Text_MtMoonGiftShopSign:
	.string "Il y a un avis ici…\p"
	.string "BOUTIQUE CADEAUX MT. LUNA OUVERTE !$"

PewterCity_Text_WelcomeSign:
	.string "BIENVENUE À JADIELLE !$"

