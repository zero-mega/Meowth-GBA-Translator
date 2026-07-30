Route40_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route40_MapScript_OnTransition
	.byte 0

Route40_MapScript_OnTransition::
	callnative SetTimeBasedEncounters
	goto_if_ge VAR_OLIVINE_CITY_STATE, 5, Route40_MapScript_ClearWeather
	end

Route40_MapScript_ClearWeather::
	setweather WEATHER_NONE
	end

Route40_EventScript_Simon::
	trainerbattle_single TRAINER_SIMON, Route40_Text_SwimmermSimonSeen, Route40_Text_SwimmermSimonBeaten
	msgbox Route40_Text_SwimmermSimonAfter, MSGBOX_AUTOCLOSE
	end

Route40_Text_SwimmermSimonSeen:
	.string "Il faut s'échauffer avant\n"
	.string "d'entrer dans l'eau.\p"
	.string "C'est la base.$"

Route40_Text_SwimmermSimonBeaten:
	.string "OK ! J'abandonne !$"

Route40_Text_SwimmermSimonAfter:
	.string "OLIVILLE est assez loin\n"
	.string "d'ici.$"

Route40_EventScript_Randall::
	trainerbattle_single TRAINER_RANDALL, Route40_Text_SwimmermRandallSeen, Route40_Text_SwimmermRandallBeaten
	msgbox Route40_Text_SwimmermRandallAfter, MSGBOX_AUTOCLOSE
	end

Route40_Text_SwimmermRandallSeen:
	.string "Hé, tu es jeune et en forme !\p"
	.string "Ne monte pas ton POKéMON !\n"
	.string "Nage !$"

Route40_Text_SwimmermRandallBeaten:
	.string "Oups. J'ai perdu…$"

Route40_Text_SwimmermRandallAfter:
	.string "La natation exerce tout\n"
	.string "le corps. C'est sain.$"

Route40_EventScript_Elaine::
	trainerbattle_single TRAINER_ELAINE, Route40_Text_SwimmerfElaineSeen, Route40_Text_SwimmerfElaineBeaten
	msgbox Route40_Text_SwimmerfElaineAfter, MSGBOX_AUTOCLOSE
	end

Route40_Text_SwimmerfElaineSeen:
	.string "Tu vas à OLIVILLE ?\p"
	.string "Que dirais-tu d'un rapide combat\n"
	.string "avant ?$"

Route40_Text_SwimmerfElaineBeaten:
	.string "J'ai perdu ce combat !$"

Route40_Text_SwimmerfElaineAfter:
	.string "Je nage mieux que toi.\n"
	.string "Ouais !$"

Route40_EventScript_Paula::
	trainerbattle_single TRAINER_PAULA, Route40_Text_SwimmerfPaulaSeen, Route40_Text_SwimmerfPaulaBeaten
	msgbox Route40_Text_SwimmerfPaulaAfter, MSGBOX_AUTOCLOSE
	end

Route40_Text_SwimmerfPaulaSeen:
	.string "Pas de bouée pour moi.\p"
	.string "Je me accroche à un\n"
	.string "POKéMON marin !$"

Route40_Text_SwimmerfPaulaBeaten:
	.string "Ooh, j'ai la tête qui tourne !$"

Route40_Text_SwimmerfPaulaAfter:
	.string "Pendant que je flotte comme ça,\n"
	.string "les vagues me portent.$"

Route40_EventScript_Woman1::
	lock
	faceplayer
	msgbox Route40_Text_Lass1, MSGBOX_DEFAULT
	closemessage
	release
	end

Route40_Text_Lass1:
	.string "Bien qu'on ne puisse pas le voir d'ici,\n"
	.string "OLIVILLE est de l'autre côté de la mer.$"

Route40_EventScript_Woman2::
	lock
	faceplayer
	msgbox Route40_Text_Lass2, MSGBOX_DEFAULT
	closemessage
	release
	end

Route40_Text_Lass2:
	.string "Je suis venu à OLIVILLE en bateau pour voir\n"
	.string "les sites et profiter de l'\l"
	.string "ambiance.\p"
	.string "En tant que port, ça fait tellement\n"
	.string "différent d'une grande ville.$"

Route40_EventScript_Youngster::
	lock
	faceplayer
	msgbox Route40_Text_StandingYoungster, MSGBOX_DEFAULT
	closemessage
	release
	end

Route40_Text_StandingYoungster:
	.string "Tu es allé au MONT\n"
	.string "DRESSEUR ?\p"
	.string "Je pense que plein de dresseurs costauds\n"
	.string "s'y sont déjà rassemblés.\p"
	.string "Mais avec tous tes BADGES,\n"
	.string "tu ne devrais pas mal t'en sortir.$"

Route40_Text_Monica:
	.string "MONICA : Enchantée. Je suis MONICA de\n"
	.string "la FAMILLE DES JOURS. Je parie\p"
	.string "que tu ne devineras pas mon\n"
	.string "jour préféré de la semaine !$"

Route40_Text_MonicaGivesGift:
	.string "C'est ça !\p"
	.string "En signe de notre amitié,\n"
	.string "j'ai un cadeau pour toi !$"

Route40_Text_MonicaGaveGift:
	.string "MONICA : C'est un objet qui\n"
	.string "augmente la puissance des attaques\p"
	.string "de type VOL. Tu devrais\n"
	.string "l'équiper sur un POKéMON oiseau.$"

Route40_Text_MonicaMonday:
	.string "MONICA : Mes frères et\n"
	.string "sœurs sont partout.\p"
	.string "Essaie de tous\n"
	.string "les trouver !$"

Route40_Text_MonicaNotMonday:
	.string "MONICA : Je ne pense pas qu'aujourd'hui\n"
	.string "soit lundi. Quel dommage…$"

Route40_Text_MonicaNope:
	.string "Pas celui-là.$"

Rotue40_EventScript_Monica::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SHARP_BEAK, Rotue40_EventScript_MonicaCompleted
	msgbox Route40_Text_Monica, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, Rotue40_EventScript_MonicaNope
	case 1, Rotue40_EventScript_MonicaYes
	case 2, Rotue40_EventScript_MonicaNope
	case 3, Rotue40_EventScript_MonicaNope
	case 4, Rotue40_EventScript_MonicaNope
	case 5, Rotue40_EventScript_MonicaNope
	case 6, Rotue40_EventScript_MonicaNope
	case 7 Rotue40_EventScript_MonicaCancel
	case MULTI_B_PRESSED, Rotue40_EventScript_MonicaCancel
	closemessage
	release
	end
Rotue40_EventScript_MonicaYes::
	msgbox Route40_Text_MonicaGivesGift, MSGBOX_DEFAULT
	giveitem ITEM_SHARP_BEAK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_SHARP_BEAK
	msgbox Route40_Text_MonicaGaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end
Rotue40_EventScript_MonicaNope::
	msgbox Route40_Text_MonicaNope, MSGBOX_DEFAULT
	closemessage
	release
	end
Rotue40_EventScript_MonicaCancel::
	closemessage
	release
	end
Rotue40_EventScript_MonicaCompleted::
	msgbox Route40_Text_MonicaMonday, MSGBOX_DEFAULT
	closemessage
	release
	end
