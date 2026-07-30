PalletTown_RedsHouse_1F_MapScripts::
	.byte 0

PalletTown_RedsHouse_1F_EventScript_Mom::
	lock
	faceplayer
	goto_if_ge VAR_TEMP_0, 1, PalletTown_RedsHouse_1F_EventScript_MomAfter
	msgbox RedsHouse_Text_Mom1, MSGBOX_DEFAULT
	closemessage
	setvar VAR_TEMP_0, 1
	release
	end

PalletTown_RedsHouse_1F_EventScript_MomAfter::
	msgbox RedsHouse_Text_Mom2, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_RedsHouse_1F_EventScript_TV::
	msgbox RedsHouse_Text_TV, MSGBOX_SIGN
	end

RedsHouse_Text_Mom1:
	.string "Salut ! ROUGE est\p"
	.string "parti depuis longtemps.\p"
	.string "Il n'a pas\n"
	.string "appelé non plus,\l"
	.string "alors je ne\p"
	.string "sais pas où\n"
	.string "il est. J'espère\l"
	.string "qu'il va bien…$"

RedsHouse_Text_Mom2:
	.string "Je m'inquiète que RED se blesse ou\n"
	.string "tombe malade, mais c'est un garçon.\p"
	.string "Je suis fier qu'il fasse ce\n"
	.string "qu'il veut.$"

RedsHouse_Text_TV:
	.string "Ils ont des programmes qui ne passent\n"
	.string "pas à JOHTO…$"
