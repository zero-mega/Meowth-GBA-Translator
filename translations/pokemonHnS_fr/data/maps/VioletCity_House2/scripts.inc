VioletCity_House2_MapScripts::
	.byte 0

VioletCity_House2_EventScript_Lass::
	lock
	faceplayer
	msgbox VioletCity_NicknameHouse_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_House2_EventScript_Teacher::
	lock
	faceplayer
	msgbox VioletCity_NicknameHouse_Text_Teacher, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_House2_EventScript_Pidgey::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIDGEY, CRY_MODE_NORMAL
	msgbox VioletCity_NicknameHouse_Text_Bird, MSGBOX_DEFAULT
	waitmoncry
	release
	end

VioletCity_NicknameHouse_Text_Teacher:
	.string "Elle utilise les noms de ses\n"
	.string "plats préférés.\p"
	.string "Pour les surnoms qu'elle donne\n"
	.string "à ses POKéMON, je veux dire.$"

VioletCity_NicknameHouse_Text_Lass:
	.string "J'appelle mon ROUCOOL FRAISE !$"

VioletCity_NicknameHouse_Text_Bird:
	.string "STRAWBERRY : Pijji !$"
