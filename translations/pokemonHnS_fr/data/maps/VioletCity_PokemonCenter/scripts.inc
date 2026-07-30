.set LOCALID_NURSE, 1

VioletCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VioletCity_Pokecenter_OnTransition
	.byte 0

VioletCity_Pokecenter_OnTransition::
	setrespawn HEAL_LOCATION_VIOLET_CITY
	end

VioletCity_PokemonCenter_EventScript_Aide::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TOGEPI_EGG, VioletCity_PokemonCenter_EventScript_Aide_Received
	getpartysize
	goto_if_eq VAR_RESULT, PARTY_SIZE, VioletCity_PokemonCenter_EventScript_AideNoRoom
	msgbox VioletCity_PokeCenter_Text_ElmsAideFavor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VioletCity_PokemonCenter_EventScript_Aide_Refuse
	goto_if_eq VAR_RESULT, YES, VioletCity_PokemonCenter_EventScript_Aide_Accepted
	release
	end


VioletCity_PokemonCenter_EventScript_AideNoRoom::
	msgbox VioletCity_PokeCenter_Text_ElmsAideNoRoom, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_PokemonCenter_EventScript_Aide_Refuse::
	msgbox VioletCity_PokeCenter_Text_ElmsAideRefuse, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, VioletCity_PokemonCenter_EventScript_Aide_Refuse
	goto_if_eq VAR_RESULT, YES, VioletCity_PokemonCenter_EventScript_Aide_Accepted
	release
	end

VioletCity_PokemonCenter_EventScript_Aide_Accepted::
	getpartysize
	goto_if_eq VAR_RESULT, PARTY_SIZE, VioletCity_PokeCenter_Text_ElmsAideFullParty
	playfanfare MUS_OBTAIN_ITEM
	message LavaridgeTown_Text_ReceivedTheEgg
	waitfanfare
	msgbox VioletCity_PokeCenter_Text_ElmsAideGiveEgg, MSGBOX_DEFAULT
	closemessage
	giveegg SPECIES_TOGEPI
	setflag FLAG_RECEIVED_TOGEPI_EGG
	msgbox VioletCity_PokeCenter_Text_ElmsAideGiveItem, MSGBOX_DEFAULT
	giveitem ITEM_EXP_SHARE_SMALL
	setflag FLAG_HIDE_VIOLET_CITY_AIDE
	setvar VAR_VIOLET_CITY_KIMONO_GIRL, 1
	clearflag FLAG_HIDE_VIOLET_CITY_KIMONO_GIRL
	clearflag FLAG_HIDE_NEWBARKTOWN_LAB_AIDE
	release
	end

VioletCity_PokemonCenter_EventScript_Aide_Received::
	msgbox VioletCity_PokeCenter_Text_ElmsAideGiveEgg, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_PokemonCenter_EventScript_Gentleman::
	lock
	faceplayer
	msgbox VioletCity_PokeCenter_Text_Gentleman, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_PokemonCenter_EVentScript_Kid::
	lock
	faceplayer
	msgbox VioletCity_PokeCenter_Text_GameboyKid, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_PokemonCenter_EventScript_Man::
	lock
	faceplayer
	msgbox VioletCity_PokeCenter_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_PokemonCenter_Text_BookshelfWoman::
	lock
	faceplayer
	msgbox VioletCity_PokeCenter_Text_BooksAreGreat, MSGBOX_DEFAULT
	closemessage
	release
	end


VioletCity_PokeCenter_Text_ElmsAideFavor:
	.string "{PLAYER}, ça fait longtemps !\p"
	.string "Le PROF.ORME m'a demandé de te trouver.\p"
	.string "Il a encore un service à te demander.\p"
	.string "Tu veux bien prendre l'ŒUF POKéMON ?$"

VioletCity_PokeCenter_Text_ElmsAideNoRoom:
	.string "{PLAYER}, ça fait longtemps.\p"
	.string "Le PROF.ORME m'a demandé de te trouver.\p"
	.string "Il a une autre faveur à te demander.\p"
	.string "Accepterais-tu l'ŒUF POKéMON ?\p"
	.string "Oh, attends... Il faut d'abord faire de la place\n"
	.string "dans ton équipe.$"

VioletCity_PokeCenter_Text_ElmsAideGiveEgg:
	.string "Nous avons découvert qu'un POKéMON n'éclot\n"
	.string "pas tant qu'il n'a pas grandi dans l'ŒUF.\p"
	.string "Il doit aussi être avec d'autres\n"
	.string "POKéMON actifs pour éclore.\p"
	.string "{PLAYER}, tu es la seule personne\n"
	.string "sur qui on peut compter.$"

VioletCity_PokeCenter_Text_ElmsAideGiveItem:
	.string "Oh, et ça pourrait aider quand ça éclora.$"

VioletCity_PokeCenter_Text_ElmsAideFullParty:
	.string "Oh, non. Tu ne peux plus porter\n"
	.string "de POKéMON avec toi.\p"
	.string "J'attendrai pendant que tu fais\n"
	.string "de la place pour l'ŒUF.$"

VioletCity_PokeCenter_Text_ElmsAideRefuse:
	.string "M-mais… le PROF.ORME t'a demandé…$"

VioletCity_PokeCenter_Text_BooksAreGreat:
	.string "Pendant que mes POKéMON se remettent,\n"
	.string "j'adore lire un bon livre.$"

VioletCity_PokeCenter_Text_MobileAdapter:
	.string "Je viens de me battre contre un ami\n"
	.string "à OLIVILLE via une connexion.\p"
	.string "Si tu branches un ADAPTATEUR MOBILE,\n"
	.string "tu peux te connecter avec un ami\l"
	.string "au loin.$"

VioletCity_PokeCenter_Text_GameboyKid:
	.string "Un type nommé BILL a créé\n"
	.string "le système de stockage PC POKéMON.$"

VioletCity_PokeCenter_Text_Gentleman:
	.string "C'était il y a environ trois ans.\p"
	.string "La TEAM ROCKET faisait des misères\n"
	.string "avec les POKéMON.\p"
	.string "Mais la justice a triomphé — un jeune\n"
	.string "gamin les a démantelés.$"

VioletCity_PokeCenter_Text_Youngster:
	.string "Les POKéMON sont malins. Ils n'obéiront pas\n"
	.string "à un DRESSEUR qu'ils ne respectent pas.\p"
	.string "Sans les bons BADGES D'ARÈNE,\n"
	.string "ils feront ce qu'ils veulent.$"
