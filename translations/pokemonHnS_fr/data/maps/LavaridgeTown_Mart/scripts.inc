LavaridgeTown_Mart_MapScripts::
	.byte 0

LavaridgeTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Mart_EventScript_Clerk2::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LavaridgeTown_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LavaridgeTown_Mart_Pokemart:
	.2byte ITEM_X_SPEED
	.2byte ITEM_NONE
	release
	end

LavaridgeTown_Mart_EventScript_ExpertM::
	msgbox LavaridgeTown_Mart_Text_XSpeedFirstStrike, MSGBOX_NPC
	end

LavaridgeTown_Mart_EventScript_OldWoman::
	msgbox LavaridgeTown_Mart_Text_LocalSpecialtyOnMtChimney, MSGBOX_NPC
	end

LavaridgeTown_Mart_Text_XSpeedFirstStrike:
	.string "Utilise ATTAQUE VITESSE pour augmenter la\n"
	.string "VITESSE d'un POKéMON en combat.\p"
	.string "Ça l'aidera à frapper en\n"
	.string "premier, un avantage certain !$"

LavaridgeTown_Mart_Text_LocalSpecialtyOnMtChimney:
	.string "Au sommet du MONT CHIMNEY, il y a\n"
	.string "une spécialité locale qu'on ne peut acheter que\p"
	.string "là. Donne-la à un POKéMON, il sera ravi.$"

