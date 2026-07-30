Route114_FossilManiacsHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_FossilManiacsHouse_OnTransition
	.byte 0

Route114_FossilManiacsHouse_OnTransition:
	setflag FLAG_LANDMARK_FOSSIL_MANIACS_HOUSE
	end

Route114_FossilManiacsHouse_EventScript_FossilManiacsBrother::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_DIG, Route114_FossilManiacsHouse_EventScript_ReceivedDig
	msgbox Route114_FossilManiacsHouse_Text_HaveThisToDigLikeMyBrother, MSGBOX_DEFAULT
	giveitem ITEM_TM_DIG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_DIG
	release
	end

Route114_FossilManiacsHouse_EventScript_ReceivedDig::
	msgbox Route114_FossilManiacsHouse_Text_DigReturnsYouToEntrance, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsHouse_EventScript_RockDisplay::
	msgbox Route114_FossilManiacsHouse_Text_RocksFillDisplayCase, MSGBOX_SIGN
	end

Route114_FossilManiacsHouse_EventScript_Bookshelf::
	msgbox Route114_FossilManiacsHouse_Text_CrammedWithBooks, MSGBOX_SIGN
	end

Route114_FossilManiacsHouse_Text_HaveThisToDigLikeMyBrother:
	.string "Mon grand frère est\n"
	.string "le MANIAQUE DES FOSSILES…\p"
	.string "C'est un type sympa\n"
	.string "qui adore les FOSSILES…\p"
	.string "Il adore creuser dans\n"
	.string "le DÉSERT DÉSERT…$"

Route114_FossilManiacsHouse_Text_DigReturnsYouToEntrance:
	.string "Si tu fais creuser un POKéMON dans une\n"
	.string "grotte, tu es renvoyé à l'entrée…$"

Route114_FossilManiacsHouse_Text_RocksFillDisplayCase:
	.string "Des rochers aux formes étranges\n"
	.string "remplissent la vitrine…$"

Route114_FossilManiacsHouse_Text_CrammedWithBooks:
	.string "LA COMPOSITION DES STRATES...\n"
	.string "COMMENT LA PLUIE FAÇONNE LE SOL...\l"
	.string "PIERRES, TERRE ET ROCHE...\p"
	.string "C'est rempli de livres.$"

