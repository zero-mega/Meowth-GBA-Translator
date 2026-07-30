MysteryGiftScript_AuroraTicket::
	setvaddress MysteryGiftScript_AuroraTicket
	lock
	faceplayer
	vgoto_if_set FLAG_RECEIVED_AURORA_TICKET, AuroraTicket_Obtained
	vgoto_if_set FLAG_BATTLED_DEOXYS, AuroraTicket_Obtained
	checkitem ITEM_AURORA_TICKET
	vgoto_if_eq VAR_RESULT, TRUE, AuroraTicket_Obtained
	vmessage sText_AuroraTicketForYou
	waitmessage
	waitbuttonpress
	checkitemspace ITEM_AURORA_TICKET
	vgoto_if_eq VAR_RESULT, FALSE, AuroraTicket_NoBagSpace
	giveitem ITEM_AURORA_TICKET
	setflag FLAG_ENABLE_SHIP_BIRTH_ISLAND
	setflag FLAG_RECEIVED_AURORA_TICKET
	vmessage sText_AuroraTicketUseAtPort
	waitmessage
	waitbuttonpress
	release
	end

AuroraTicket_NoBagSpace:
	vmessage sText_AuroraTicketBagFull
	waitmessage
	waitbuttonpress
	release
	end

AuroraTicket_Obtained:
	vmessage sText_AuroraTicketThankYou
	waitmessage
	waitbuttonpress
	release
	end

sText_AuroraTicketForYou:
	.string "Merci d'utiliser le système\n"
	.string "CADEAU MYSTÈRE.\p"
	.string "Tu dois être {PLAYER}.\n"
	.string "Il y a un ticket pour toi.$"

sText_AuroraTicketUseAtPort:
	.string "Il semble être destiné au port\n"
	.string "de NÉNUCRIQUE.\p"
	.string "Pourquoi ne pas essayer pour voir\n"
	.string "de quoi il s'agit ?$"

sText_AuroraTicketThankYou:
	.string "Merci d'utiliser le Système\n"
	.string "CADEAU MYSTÈRE.$"

sText_AuroraTicketBagFull:
	.string "Oh, pardon, {PLAYER}.\n"
	.string "Ta POCHE OBJETS RARES est pleine.\p"
	.string "Range quelque chose sur ton PC,\n"
	.string "puis reviens chercher ça.$"
