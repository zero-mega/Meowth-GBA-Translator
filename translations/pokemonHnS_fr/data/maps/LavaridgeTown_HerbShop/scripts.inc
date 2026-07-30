LavaridgeTown_HerbShop_MapScripts::
	.byte 0

LavaridgeTown_HerbShop_EventScript_Clerk::
	lock
	faceplayer
	message LavaridgeTown_HerbShop_Text_WelcomeToHerbShop
	waitmessage
	pokemart LavaridgeTown_HerbShop_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LavaridgeTown_HerbShop_Pokemart:
	.2byte ITEM_ENERGY_POWDER
	.2byte ITEM_ENERGY_ROOT
	.2byte ITEM_HEAL_POWDER
	.2byte ITEM_REVIVAL_HERB
	.2byte ITEM_NONE
	release
	end

LavaridgeTown_HerbShop_EventScript_ExpertM::
	msgbox LavaridgeTown_HerbShop_Text_HerbalMedicineWorksButMonWillDislike, MSGBOX_NPC
	end

LavaridgeTown_HerbShop_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_GARBAGEFLAG, LavaridgeTown_HerbShop_EventScript_ExplainCharcoal
	msgbox LavaridgeTown_HerbShop_Text_YouveComeToLookAtHerbalMedicine, MSGBOX_DEFAULT
	giveitem ITEM_CHARCOAL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GARBAGEFLAG
	release
	end

LavaridgeTown_HerbShop_EventScript_ExplainCharcoal::
	msgbox LavaridgeTown_HerbShop_Text_ExplainCharcoal, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_HerbShop_Text_WelcomeToHerbShop:
	.string "Bienvenue à la HERBORISTERIE,\n"
	.string "foyer de médicaments efficaces et bon marché !$"

LavaridgeTown_HerbShop_Text_YouveComeToLookAtHerbalMedicine:
	.string "Tu es venu voir les remèdes herboristes\n"
	.string "à VERMILAVA ?\p"
	.string "C'est plutôt louable.\p"
	.string "Je t'aime bien ! Prends ça !$"

LavaridgeTown_HerbShop_Text_ExplainCharcoal:
	.string "Le CHARBON que je t'ai donné sert à\n"
	.string "faire des remèdes à base de plantes.\p"
	.string "Il fait aussi des merveilles quand un\n"
	.string "POKéMON le tient.\p"
	.string "Il intensifie la puissance des capacités\n"
	.string "de type Feu.$"

LavaridgeTown_HerbShop_Text_HerbalMedicineWorksButMonWillDislike:
	.string "Les remèdes à base de plantes fonctionnent remarquablement\n"
	.string "bien. Mais ton POKéMON ne t'aimera pas pour\l"
	.string "ça. Ça doit être horriblement amer !$"

