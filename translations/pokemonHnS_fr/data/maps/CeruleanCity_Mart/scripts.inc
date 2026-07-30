CeruleanCity_Mart_MapScripts::
	.byte 0

CeruleanCity_Mart_EventScript_Juggler::
	msgbox CeruleanMart_Text_CooltrainerM, MSGBOX_NPC
	end

CeruleanCity_Mart_EventScript_CooltrainerF::
	msgbox CeruleanMart_Text_CooltrainerF, MSGBOX_NPC
	end

CeruleanMart_Text_CooltrainerM:
	.string "Tu croiseras plein de DRESSEURS sur\n"
	.string "le chemin du CAP CERULE.\p"
	.string "Ils veulent voir comment ils\n"
	.string "se comportent face aux autres.$"

CeruleanMart_Text_CooltrainerF:
	.string "ONDINE est à peu près la seule en ville\n"
	.string "qui peut battre les Dresseurs du\l"
	.string "CAP d'AZURIA.$"
