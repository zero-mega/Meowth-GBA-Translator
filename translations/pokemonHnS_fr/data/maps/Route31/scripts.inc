Route31_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route31_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route31_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route31_EventScript_Bugcatcher_Wade::
	trainerbattle_single TRAINER_WADE, Route31_Text_BugCatcherWade1_Seen, Route31_Text_BugCatcherWade1_Beaten
	msgbox Route31_Text_BugCatcherWade1_After, MSGBOX_AUTOCLOSE
	end

Route31_EventScript_Youngster::
	lock
	faceplayer
	msgbox Route31_Text_CooltrainerM, MSGBOX_DEFAULT
	closemessage
	release
	end

Route31_EventScript_SleepyMan::
	lock
	faceplayer
	goto_if_eq VAR_KENYA, 1, Route31_EventScript_SleepyMan_AskForKenya
	msgbox Route31_Text_SleepyMan, MSGBOX_DEFAULT
	closemessage
	release
	end

Route31_EventScript_SleepyMan_AskForKenya::
	msgbox Route31_Text_SleepyManGotMail MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route31_EventScript_SleepyMan_GiveKenya
	msgbox Route31_Text_SleepyManFail, MSGBOX_DEFAULT
	closemessage
	release
	end

Route31_EventScript_SleepyMan_GiveKenya::
	removenamedmon 1
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, Route31_EventScript_SleepyMan_Fail
	msgbox Route31_Text_HandOverMailMon, MSGBOX_DEFAULT
	delay 55
	callnative UpdateFollowingPokemon
	msgbox Route31_Text_ReadingMail, MSGBOX_DEFAULT
	giveitem ITEM_TM_TORMENT
	msgbox Route31_Text_DescribeNightmare, MSGBOX_DEFAULT
	closemessage
	setvar VAR_KENYA, 2
	release
	end

Route31_EventScript_SleepyMan_Fail::
	msgbox Route31_Text_SleepyManFail, MSGBOX_DEFAULT
	release
	end


Route31_EventScript_Boy::
	lock
	faceplayer
	msgbox Route31_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

Route31_EventScript_DarkCaveSign::
	lock
	msgbox Route31_Text_DarkCaveSign, MSGBOX_SIGN
	closemessage
	release
	end

Route31_EventScript_Sign::
	lock
	msgbox Route31_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route31_EventScript_ItemPokeBall::
	finditem ITEM_POKE_BALL
	end

Route31_EventScript_ItemAntidote::
	finditem ITEM_ANTIDOTE
	end

Route31_Text_CooltrainerM:
	.string "GROTTE OBSCURE…\p"
	.string "Si des POKéMON pouvaient l'éclairer,\n"
	.string "je l'explorerais.$"

Route31_Text_BugCatcherWade1_Seen:
	.string "J'ai attrapé plein de POKéMON.\n"
	.string "Laisse-moi me battre avec toi !$"

Route31_Text_BugCatcherWade1_Beaten:
	.string "Snif…$"

Route31_Text_BugCatcherWade1_After:
	.string "Tu peux attraper des POKéMON même\n"
	.string "si tu en as déjà six avec toi.\p"
	.string "Si tu en attrapes un, il ira\n"
	.string "automatiquement dans ta BOÎTE.$"

Route31_Text_SleepyMan:
	.string "… Hnuurg… Hein ?\p"
	.string "J'ai trop marché aujourd'hui en cherchant\n"
	.string "des POKéMON.\p"
	.string "Mes pieds me font mal et j'ai sommeil…\p"
	.string "Si j'étais un POKéMON sauvage, je serais\n"
	.string "facile à attraper…\p"
	.string "…Zzzz…$"

Route31_Text_SleepyManGotMail:
	.string "…Zzzz… Hein ?\p"
	.string "Quoi ? Tu as du COURRIER\n"
	.string "pour moi ?$"

Route31_Text_SleepyManFail:
	.string "…Zzzz…$"

Route31_Text_HandOverMailMon:
	.string "{PLAYER} a remis le\n"
	.string "POKéMON portant la LETTRE.$"

Route31_Text_ReadingMail:
	.string "Voyons voir…\p"
	.string "Merci de m'avoir apporté\n"
	.string "ça.\p"
	.string "Mon ami est un chic type, et\n"
	.string "toi aussi !\p"
	.string "J'aimerais te rendre la pareille\n"
	.string "aussi !\p"
	.string "Je sais ! Je veux que tu aies\n"
	.string "ça !$"

Route31_Text_DescribeNightmare:
	.string "Cette CT contient TOURMENT.\p"
	.string "C'est une attaque vicieuse qui\n"
	.string "rend l'ennemi super nerveux et\l"
	.string "l'empêche d'utiliser la même\p"
	.string "attaque plusieurs fois de suite.$"

Route31_Text_WrongMail:
	.string "Ce COURRIER n'est pas pour moi.$"

Route31_Text_MissingMail:
	.string "Pourquoi ce POKéMON est-il si spécial ?\p"
	.string "Il n'a pas de LETTRE.$"

Route31_Text_DeclinedToHandOverMail:
	.string "Quoi ? Tu ne veux\n"
	.string "rien ?$"

Route31_Text_CantTakeLastMon:
	.string "Si je prends ce POKéMON de\n"
	.string "toi,\p"
	.string "qu'est-ce que tu vas utiliser\n"
	.string "en combat ?$"

Route31_Text_Youngster:
	.string "J'ai trouvé un bon\n"
	.string "POKéMON dans la GROTTE\p"
	.string "OBSCURE. Je vais l'élever\n"
	.string "pour affronter ALDO. C'est\p"
	.string "le CHAMPION de\n"
	.string "l'ARÈNE de MAUVILLE.$"

Route31_Text_Sign:
	.string "ROUTE 31\p"
	.string "MAUVILLE - VILLE GRIOTTE$"

Route31_Text_DarkCaveSign:
	.string "GROTTE SOMBRE$"
