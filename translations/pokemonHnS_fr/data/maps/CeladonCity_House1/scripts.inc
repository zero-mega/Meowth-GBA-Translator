CeladonCity_House1_MapScripts::
	.byte 0

CeladonCity_House1_EventScript_Chef::
	msgbox CeladonCity_House1_Text_ChefEatathon, MSGBOX_NPC
	end

CeladonCity_House1_EventScript_Fisher1::
	lock
	msgbox CeladonCity_House1_Text_Fisher1Snarfle, MSGBOX_DEFAULT
	faceplayer
	msgbox CeladonCity_House1_Text_Fisher1Concentration, MSGBOX_DEFAULT
	turnobject VAR_LAST_TALKED, DIR_WEST
	release
	end

CeladonCity_House1_EventScript_Fisher2::
	lock
	msgbox CeladonCity_House1_Text_Fisher2GulpChew, MSGBOX_DEFAULT
	faceplayer
	msgbox CeladonCity_House1_Text_Fisher2Quantity, MSGBOX_DEFAULT
	turnobject VAR_LAST_TALKED, DIR_EAST
	release
	end

CeladonCity_House1_EventScript_Fisher3::
	lock
	msgbox CeladonCity_House1_Text_Fisher3MunchMunch, MSGBOX_DEFAULT
	faceplayer
	msgbox CeladonCity_House1_Text_Fisher3GoldenrodIsBest, MSGBOX_DEFAULT
	turnobject VAR_LAST_TALKED, DIR_EAST
	release
	end

CeladonCity_House1_EventScript_Teacher::
	lock
	msgbox CeladonCity_House1_Text_TeacherCrunchCrunch, MSGBOX_DEFAULT
	faceplayer
	checkitem ITEM_COIN_CASE
	goto_if_eq VAR_RESULT, FALSE, CeladonCity_House1_EventScript_TeacherCoincase
	msgbox CeladonCity_House1_Text_TeacherKeepEating, MSGBOX_DEFAULT
	turnobject VAR_LAST_TALKED, DIR_WEST
	release
	end

CeladonCity_House1_EventScript_TeacherCoincase::
	msgbox CeladonCity_House1_Text_TeacherNoCoinCase, MSGBOX_DEFAULT
	turnobject VAR_LAST_TALKED, DIR_WEST
	release
	end

CeladonCity_House1_EventScript_Sign::
	msgbox CeladonCity_House1_Text_EatathonContestPoster, MSGBOX_SIGN
	end

CeladonCity_House1_Text_ChefEatathon:
	.string "Salut !\p"
	.string "On organise un concours de gourmandise.\p"
	.string "On ne peut pas te servir maintenant.\n"
	.string "Désolé.$"

CeladonCity_House1_Text_Fisher1Snarfle:
	.string "…Miam, miam…$"

CeladonCity_House1_Text_Fisher1Concentration:
	.string "Ne me parle pas !\p"
	.string "Tu vas briser ma concentration !$"

CeladonCity_House1_Text_Fisher2GulpChew:
	.string "…Gloup… Miam…$"

CeladonCity_House1_Text_Fisher2Quantity:
	.string "Je préfère la quantité à la qualité !\p"
	.string "Je suis heureux quand je suis rassasié !$"

CeladonCity_House1_Text_Fisher3MunchMunch:
	.string "Miam, miam…$"

CeladonCity_House1_Text_Fisher3GoldenrodIsBest:
	.string "La nourriture est bonne ici, mais\n"
	.string "DOUBLONVILLE a la meilleure nourriture\l"
	.string "de partout.$"

CeladonCity_House1_Text_TeacherCrunchCrunch:
	.string "Miam… Miam…$"

CeladonCity_House1_Text_TeacherNoCoinCase:
	.string "Personne ici ne te donnera une BOÎTE A JETONS.\n"
	.string "Tu devrais chercher à JOHTO.$"

CeladonCity_House1_Text_TeacherKeepEating:
	.string "Crunch… Crunch…\p"
	.string "Je peux continuer à manger !\p"
	.string "Encore, CHEF !$"

CeladonCity_House1_Text_EatathonContestPoster:
	.string "Concours de goinfrerie ! Sans limite de temps !\p"
	.string "Un combat sans fin ! Le plus gros mangeur\n"
	.string "gagne tout gratuitement !$"

