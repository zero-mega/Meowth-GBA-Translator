MauvilleCity_House1_MapScripts::
	.byte 0

MauvilleCity_House1_EventScript_RockSmashDude::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_ROCK_SMASH, MauvilleCity_House1_EventScript_ReceivedRockSmash
	msgbox MauvilleCity_House1_Text_ImRockSmashDudeTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_HM_ROCK_SMASH
	setflag FLAG_RECEIVED_HM_ROCK_SMASH
	setflag FLAG_GARBAGEFLAG
	msgbox MauvilleCity_House1_Text_ExplainRockSmash, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House1_EventScript_ReceivedRockSmash::
	msgbox MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House1_Text_ImRockSmashDudeTakeThis:
	.string "Woohoo !\p"
	.string "J'entends les gens\n"
	.string "m'appeler le\p"
	.string "MEC COUPE,\n"
	.string "mais je trouve ça\p"
	.string "un peu dégradant.\p"
	.string "Je préfère être appelé\n"
	.string "le SPÉCIALISTE ROCHE.\p"
	.string "Utilise COUPE\n"
	.string "pour explorer !$"

MauvilleCity_House1_Text_ExplainRockSmash:
	.string "Cette CS contient FORCE. Si\p"
	.string "tu rencontres de gros rochers\n"
	.string "qui bloquent ton chemin… Utilise\p"
	.string "cette capacité et écrase-les pour\n"
	.string "ouvrir le passage ! Oui\p"
	.string "! Écrase les rochers, je\n"
	.string "dis ! Woohoo !$"

MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock:
	.string "Oh, oui, si tu écrases un rocher, un POKéMON\n"
	.string "pourrait surgir de sa cachette.\p"
	.string "Youhou !$"

