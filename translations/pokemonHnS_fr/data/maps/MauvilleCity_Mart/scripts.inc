MauvilleCity_Mart_MapScripts::
	.byte 0

MauvilleCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Mart_EventScript_Clerk2::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart MauvilleCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
MauvilleCity_Mart_Pokemart:
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_X_ACCURACY
	.2byte ITEM_NONE
	release
	end

MauvilleCity_Mart_EventScript_ExpertM::
	msgbox MauvilleCity_Mart_Text_ItemsToTemporarilyElevateStats, MSGBOX_NPC
	end

MauvilleCity_Mart_EventScript_Man::
	msgbox MauvilleCity_Mart_Text_DecisionsDetermineBattle, MSGBOX_NPC
	end

MauvilleCity_Mart_Text_ItemsToTemporarilyElevateStats:
	.string "Il y a des objets qui augmentent\n"
	.string "temporairement les stats des POKéMON.\p"
	.string "Ceux que je connais qu'on utilise en combat\n"
	.string "sont ATTAQUE + et DÉFENSE +…\p"
	.string "Je crois qu'il y en a d'autres\n"
	.string "comme eux.$"

MauvilleCity_Mart_Text_DecisionsDetermineBattle:
	.string "Utiliser une certaine attaque, ou\n"
	.string "un objet à la place…\p"
	.string "Les décisions du DRESSEUR déterminent\n"
	.string "l'issue des combats, je pense.$"

