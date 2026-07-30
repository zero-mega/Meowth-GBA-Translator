MysteryGiftScript_MysticTicket::
	setvaddress MysteryGiftScript_MysticTicket
	lock
	faceplayer
	vgoto_if_set FLAG_RECEIVED_MYSTIC_TICKET, MysticTicket_Obtained
	vgoto_if_set FLAG_CAUGHT_LUGIA, MysticTicket_Obtained
	vgoto_if_set FLAG_CAUGHT_HO_OH, MysticTicket_Obtained
	checkitem ITEM_MYSTIC_TICKET
	vgoto_if_eq VAR_RESULT, TRUE, MysticTicket_Obtained
	vmessage sText_MysticTicketForYou
	waitmessage
	waitbuttonpress
	checkitemspace ITEM_MYSTIC_TICKET
	vgoto_if_eq VAR_RESULT, FALSE, MysticTicket_NoBagSpace
	giveitem ITEM_MYSTIC_TICKET
	setflag FLAG_ENABLE_SHIP_NAVEL_ROCK
	setflag FLAG_RECEIVED_MYSTIC_TICKET
	vmessage sText_MysticTicketUseAtPort
	waitmessage
	waitbuttonpress
	release
	end

MysticTicket_NoBagSpace:
	vmessage sText_MysticTicketBagFull
	waitmessage
	waitbuttonpress
	release
	end

MysticTicket_Obtained:
	vmessage sText_MysticTicketThankYou
	waitmessage
	waitbuttonpress
	release
	end

sText_MysticTicketForYou:
	.string "Merci d'utiliser le système\n"
	.string "CADEAU MYSTÈRE.\p"
	.string "Tu dois être {PLAYER}.\n"
	.string "Il y a un ticket pour toi.$"

sText_MysticTicketUseAtPort:
	.string "Il semble être destiné au port\n"
	.string "de NÉNUCRIQUE.\p"
	.string "Pourquoi ne pas essayer pour voir\n"
	.string "de quoi il s'agit ?$"

sText_MysticTicketThankYou:
	.string "Merci d'utiliser le Système\n"
	.string "CADEAU MYSTÈRE.$"

sText_MysticTicketBagFull:
	.string "Oh, pardon, {PLAYER}.\n"
	.string "Ta POCHE OBJETS RARES est pleine.\p"
	.string "Range quelque chose sur ton PC,\n"
	.string "puis reviens chercher ça.$"
