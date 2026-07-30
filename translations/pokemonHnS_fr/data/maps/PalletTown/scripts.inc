PalletTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_EventScript_CityEnter
	.byte 0

PalletTown_EventScript_CityEnter::
	setflag FLAG_VISITED_PALLET_TOWN
	end

PalletTown_EventScript_Woman::
	msgbox PalletTown_Text_Teacher, MSGBOX_NPC
	end
PalletTown_EventScript_Fatman::
	msgbox PalletTown_Text_Fisher, MSGBOX_NPC
	end
PalletTown_EventScript_TownSign::
	msgbox PalletTown_Text_Sign, MSGBOX_SIGN
	end	
PalletTown_EventScript_RedsHouseSign::
	msgbox PalletTown_Text_RedsHouseSign, MSGBOX_SIGN
	end
PalletTown_EventScript_BluesHouseSign::
	msgbox PalletTown_Text_BluesHouseSign, MSGBOX_SIGN
	end	
PalletTown_EventScript_OaksLabSign::
	msgbox PalletTown_Text_OaksLabSign, MSGBOX_SIGN
	end	

PalletTown_Text_Teacher:
	.string "J'élève des POKéMON aussi.\p"
	.string "Ils servent de gardes\n"
	.string "privés.$"

PalletTown_Text_Fisher:
	.string "La technologie est incroyable !\p"
	.string "Tu peux maintenant échanger des POKéMON\n"
	.string "à travers le temps comme des e-mails.$"

PalletTown_Text_Sign:
	.string "BOURG PALETTE\p"
	.string "Un havre de paix\n"
	.string "et de pureté$"

PalletTown_Text_RedsHouseSign:
	.string "MAISON DE RED$"

PalletTown_Text_OaksLabSign:
	.string "LABO POKéMON\n"
	.string "du PROF. CHêNE$"

PalletTown_Text_BluesHouseSign:
	.string "MAISON DE BLEU$"
