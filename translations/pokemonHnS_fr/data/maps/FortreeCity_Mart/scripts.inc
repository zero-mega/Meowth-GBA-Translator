FortreeCity_Mart_MapScripts::
	.byte 0

FortreeCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

FortreeCity_Mart_EventScript_Clerk2::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart FortreeCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
FortreeCity_Mart_Pokemart:
	.2byte ITEM_WOOD_MAIL
	.2byte ITEM_NONE
	release
	end

FortreeCity_Mart_EventScript_Woman::
	msgbox FortreeCity_Mart_Text_SuperRepelBetter, MSGBOX_NPC
	end

FortreeCity_Mart_EventScript_Girl::
	msgbox FortreeCity_Mart_Text_StockUpOnItems, MSGBOX_NPC
	end

FortreeCity_Mart_EventScript_Boy::
	msgbox FortreeCity_Mart_Text_RareCandyMakesMonGrow, MSGBOX_NPC
	end

FortreeCity_Mart_Text_SuperRepelBetter:
	.string "Le SUPER REPOUSSE dure longtemps\n"
	.string "et fait bien le travail.\p"
	.string "C'est bien mieux qu'un REPOUSSE\n"
	.string "ordinaire.$"

FortreeCity_Mart_Text_StockUpOnItems:
	.string "J'achète toujours plus d'objets\n"
	.string "que ce dont j'ai besoin.\p"
	.string "On ne sait jamais ce qui peut\n"
	.string "arriver. Mieux vaut prévenir !$"

FortreeCity_Mart_Text_RareCandyMakesMonGrow:
	.string "Une SUPER BONBON fait grandir un POKéMON\n"
	.string "immédiatement d'un niveau.$"

