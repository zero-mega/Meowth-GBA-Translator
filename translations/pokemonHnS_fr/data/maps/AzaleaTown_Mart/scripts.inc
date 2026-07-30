AzaleaTown_Mart_MapScripts::
	.byte 0

AzaleaTown_Mart_EventScriptCooltrainerM::
	lock
	faceplayer
	msgbox AzaleaMart_Text_CooltrainerM, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_Mart_EventScriptBugCatcher::
	lock
	faceplayer
	msgbox AzaleaMart_Text_BugCatcher, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaMart_Text_CooltrainerM:
	.string "Tu arrives à acheter une SUPER\n"
	.string "BALL ? Moi je ne peux\p"
	.string "acheter que des POKé BALLS. J'ai\n"
	.string "entendu que plus d'objets deviennent disponibles\l"
	.string "quand tu obtiens des BADGES\p"
	.string "d'ARÈNE ! J'aimerais que KURT\n"
	.string "me fasse des BALLS personnalisées.$"

AzaleaMart_Text_BugCatcher:
	.string "La SUPER BALL est meilleure qu'une\n"
	.string "POKé BALL pour attraper des POKéMON.\p"
	.string "Mais celle de KURT est parfois\n"
	.string "encore mieux.$"

