OlivineCity_House2_MapScripts::
	.byte 0

OlivineCity_EventScript_Punisher::
	lock
	faceplayer
	msgbox OlivineCity_Text_PunishmentBro, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_PunisherBoy::
	lock
	faceplayer
	msgbox OlivineCity_Text_PunishmentBoy, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_PunishmentBro:
	.string "Sur le chemin d'OLIVILLE, il\n"
	.string "y a quatre îles désertes.\p"
	.string "Les mauvais enfants y sont\n"
	.string "emmenés en punition !$"

OlivineCity_Text_PunishmentBoy:
	.string "Chaque fois que j'ai des ennuis,\n"
	.string "mon grand frère me fait peur.$"
