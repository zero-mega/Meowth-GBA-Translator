EcruteakCity_Mart_MapScripts::
	.byte 0

EcruteakCity_Mart_EventScript_Nerd::
	lock
	faceplayer
	msgbox EcruteakMart_Text_SuperNerd, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Mart_EventScript_Granny::
	lock
	faceplayer
	msgbox EcruteakMart_Text_Granny, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakMart_Text_SuperNerd:
	.string "Mon ÉVOLI a évolué en MENTALI.\p"
	.string "Mais l'ÉVOLI de mon ami est devenu\n"
	.string "un NOCTALI.\p"
	.string "Je me demande pourquoi ? On élevait tous les deux\n"
	.string "nos ÉVOLI de la même façon…$"

EcruteakMart_Text_Granny:
	.string "Si tu utilises RÉANIMATOR, un POKéMON\n"
	.string "évanoui se réveillera aussitôt.$"
