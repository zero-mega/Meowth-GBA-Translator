MysteryGiftScript_OldSeaMap::
	setvaddress MysteryGiftScript_OldSeaMap
	lock
	faceplayer
	vgoto_if_set FLAG_RECEIVED_OLD_SEA_MAP, OldSeaMap_Obtained
	vgoto_if_set FLAG_CAUGHT_MEW, OldSeaMap_Obtained
	checkitem ITEM_OLD_SEA_MAP
	vgoto_if_eq VAR_RESULT, TRUE, OldSeaMap_Obtained
	vmessage sText_MysteryGiftOldSeaMapForYou
	waitmessage
	waitbuttonpress
	checkitemspace ITEM_OLD_SEA_MAP
	vgoto_if_eq VAR_RESULT, FALSE, OldSeaMap_NoBagSpace
	giveitem ITEM_OLD_SEA_MAP
	setflag FLAG_ENABLE_SHIP_FARAWAY_ISLAND
	setflag FLAG_RECEIVED_OLD_SEA_MAP
	vmessage sText_MysteryGiftOldSeaMapUseAtPort
	waitmessage
	waitbuttonpress
	release
	end

OldSeaMap_NoBagSpace:
	vmessage sText_MysteryGiftOldSeaMapBagFull
	waitmessage
	waitbuttonpress
	release
	end

OldSeaMap_Obtained:
	vmessage sText_MysteryGiftOldSeaMapThankYou
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftOldSeaMapForYou:
	.string "Merci d'avoir utilisé le système\n"
	.string "CADEAU MYSTÈRE.\p"
	.string "Laisse-moi confirmer - tu es {PLAYER} ?\p"
	.string "Nous avons reçu cette VIEILLE CARTE MARINE\n"
	.string "adressée à toi.$"

sText_MysteryGiftOldSeaMapUseAtPort:
	.string "Il semble être destiné au port\n"
	.string "de NÉNUCRIQUE.\p"
	.string "Pourquoi ne pas essayer pour voir\n"
	.string "de quoi il s'agit ?$"

sText_MysteryGiftOldSeaMapThankYou:
	.string "Merci d'utiliser le Système\n"
	.string "CADEAU MYSTÈRE.$"

sText_MysteryGiftOldSeaMapBagFull:
	.string "Oh, pardon, {PLAYER}.\n"
	.string "Ta POCHE OBJETS RARES est pleine.\p"
	.string "Range quelque chose sur ton PC,\n"
	.string "puis reviens chercher ça.$"
