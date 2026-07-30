.set LOCALID_MUSEUM_ROOTFOSSIL, 5
.set LOCALID_MUSEUM_CLAWFOSSIL, 6

PewterCity_Museum_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RuinsOfAlph_Lab_OnTransition
	.byte 0

PewterCity_Museum_1F_EventScript_RootFossil::
	finditem ITEM_ROOT_FOSSIL
	setflag FLAG_HIDE_PEWTER_ROOT_FOSSIL
	removeobject LOCALID_MUSEUM_ROOTFOSSIL
	end

PewterCity_Museum_1F_EventScript_ClawFossil::
	finditem ITEM_CLAW_FOSSIL
	setflag FLAG_HIDE_PEWTER_CLAW_FOSSIL
	removeobject LOCALID_MUSEUM_CLAWFOSSIL
	end

PewterCity_Museum_1F_EventScript_Receptionist::
	msgbox PewterCity_Museum_1F_Text_Recptionist, MSGBOX_NPC
	end

PewterCity_Museum_1F_EventScript_FossilWoman::
	goto_if_set FLAG_HIDE_PEWTER_CLAW_FOSSIL, PewterCity_Museum_1F_EventScript_FossilWoman2
	goto_if_set FLAG_HIDE_PEWTER_ROOT_FOSSIL, PewterCity_Museum_1F_EventScript_FossilWoman2
	goto_if_ge VAR_TEMP_2, 1, PewterCity_Museum_1F_EventScript_FossilWoman2
	msgbox PewterCity_Museum_1F_Text_FossilWoman, MSGBOX_NPC
	setvar VAR_TEMP_2, 1
	end

PewterCity_Museum_1F_EventScript_FossilWoman2::
	msgbox PewterCity_Museum_1F_Text_FossilWomanAfter, MSGBOX_NPC
	end

PewterCity_Museum_1F_EventScript_Oldman::
	msgbox PewterCity_Museum_1F_Text_Oldman, MSGBOX_NPC
	end

PewterCity_Museum_1F_EventScript_Bones::
	msgbox PewterCity_Museum_1F_Text_Bones, MSGBOX_SIGN
	end

PewterCity_Museum_1F_Text_Recptionist:
	.string "Bienvenue !\p"
	.string "Pour info, tous les grands\n"
	.string "spécimens ont été emmenés aux\l"
	.string "autres musées pour exposition.\p"
	.string "Donc pour l'instant, l'entrée est gratuite\n"
	.string "!\p"
	.string "Entrez donc.$"

PewterCity_Museum_1F_Text_FossilWoman:
	.string "Tu dois être un\p"
	.string "DRESSEUR fort. On n'a\n"
	.string "pas grand usage des\p"
	.string "fossiles sur le comptoir\n"
	.string "là-bas. Prends-en un\p"
	.string "si tu veux.$"

PewterCity_Museum_1F_Text_FossilWomanAfter:
	.string "On partage souvent nos recherches avec\n"
	.string "les chercheurs des RUINES D'ALPHA.\p"
	.string "On leur envoie même des fossiles\n"
	.string "via le PC !$"

PewterCity_Museum_1F_Text_Oldman:
	.string "Je devrais être reconnaissant pour ma longue\n"
	.string "vie.\p"
	.string "Je n'aurais jamais pensé voir\n"
	.string "les os d'un dragon !$"

PewterCity_Museum_1F_Text_Bones:
	.string "Os d'un ancien POKéMON\n"
	.string "dragon.$"
