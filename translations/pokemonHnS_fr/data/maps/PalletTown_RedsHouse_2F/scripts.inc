PalletTown_RedsHouse_2F_MapScripts::
	.byte 0

PalletTown_RedsHouse_2F_EventScript_NES::
	msgbox RedsHouse_Text_NES, MSGBOX_SIGN
	end

PalletTown_RedsHouse_2F_EventScript_PC::
	msgbox RedsHouse_Text_PC, MSGBOX_SIGN
	end

RedsHouse_Text_NES:
	.string "{PLAYER} a joué à la NES.\p"
	.string "Mieux vaut y aller : pas le temps à perdre !$"

RedsHouse_Text_PC:
	.string "On dirait qu'il n'a pas été utilisé\n"
	.string "depuis longtemps…$"
