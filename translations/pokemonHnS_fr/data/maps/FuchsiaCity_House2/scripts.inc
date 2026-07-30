FuchsiaCity_House2_MapScripts::
	.byte 0

FuchsiaCity_House2_EventScript_Granddaughter::	
	goto_if_set FLAG_TEMP_1, FuchsiaCity_House2_EventScript_Granddaughter2
	msgbox FuchsiaCity_House2_Text_WardensGranddaughter1, MSGBOX_NPC
	setflag FLAG_TEMP_1
	end

FuchsiaCity_House2_EventScript_Granddaughter2::
	msgbox FuchsiaCity_House2_Text_WardensGranddaughter2, MSGBOX_NPC
	end

FuchsiaCity_House2_EventScript_Photo::
	msgbox FuchsiaCity_House2_Text_WardenPhoto, MSGBOX_NPC
	end

FuchsiaCity_House2_Text_WardensGranddaughter1:
	.string "Mon grand-père est le GARDIEN\n"
	.string "du PARC SAFARI.\p"
	.string "Du moins il l'était…\p"
	.string "Il a décidé de partir en vacances\n"
	.string "et est parti à l'étranger tout seul.\p"
	.string "Il a quitté le PARC SAFARI\n"
	.string "comme ça.$"

FuchsiaCity_House2_Text_WardensGranddaughter2:
	.string "Beaucoup de gens étaient déçus que le\n"
	.string "PARC SAFARI ait fermé, mais Grand-père\l"
	.string "est si têtu…$"

FuchsiaCity_House2_Text_WardenPhoto:
	.string "C'est une photo d'un vieil homme souriant\n"
	.string "entouré de POKéMON.$"

FuchsiaCity_House2_Text_SafariZonePhoto:
	.string "C'est une photo d'une immense plaine herbeuse\n"
	.string "avec des POKéMON rares qui s'y ébattent.$"
