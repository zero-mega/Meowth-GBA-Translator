MysteryGiftScript_BattleCard::
	setvaddress MysteryGiftScript_BattleCard
	vgoto_if_set FLAG_MYSTERY_GIFT_DONE, MysteryGiftScript_BattleCardInfo
	setorcopyvar VAR_RESULT, GET_CARD_BATTLES_WON
	specialvar VAR_0x8008, GetMysteryGiftCardStat
	vgoto_if_ne VAR_0x8008, REQUIRED_CARD_BATTLES, MysteryGiftScript_BattleCardInfo
	lock
	faceplayer
	vmessage sText_MysteryGiftBattleCountCard_WonPrize
	waitmessage
	waitbuttonpress
	giveitem ITEM_POTION
	release
	setflag FLAG_MYSTERY_GIFT_DONE
	end

MysteryGiftScript_BattleCardInfo:
	lock
	faceplayer
	vmessage sText_MysteryGiftBattleCountCard
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftBattleCountCard:
	.string "Merci d'utiliser\n"
	.string "le Système\p"
	.string "CADEAU MYSTÈRE.\n"
	.string "Ta CARTE COMPTEUR\l"
	.string "DE COMBAT garde\p"
	.string "une trace de tes\n"
	.string "records de\p"
	.string "combat.\n"
	.string "Continue à\p"
	.string "te battre !$"

sText_MysteryGiftBattleCountCard_WonPrize:
	.string "Merci d'utiliser le système\n"
	.string "CADEAU MYSTÈRE.\p"
	.string "Félicitations !\p"
	.string "Tu as gagné un\n"
	.string "cadeau spécial !\p"
	.string "Profites-en bien !\n"
	.string "Merci !$"
