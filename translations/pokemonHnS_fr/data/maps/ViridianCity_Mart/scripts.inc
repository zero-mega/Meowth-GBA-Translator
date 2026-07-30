ViridianCity_Mart_MapScripts::
	.byte 0

ViridianCity_Mart_EventScript_Lass::
	msgbox ViridianMart_Text_Lass, MSGBOX_NPC
	end

ViridianCity_Mart_EventScript_Cooltrainer::
	msgbox ViridianMart_Text_CooltrainerM, MSGBOX_NPC
	end

ViridianMart_Text_Lass:
	.string "Le CHAMPION d'ARÈNE ici est super cool.$"

ViridianMart_Text_CooltrainerM:
	.string "Tu es déjà allé à CRAMOIS'ÎLE ?\p"
	.string "C'est une île au sud d'ici.$"

