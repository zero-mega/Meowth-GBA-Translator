SaffronCity_House1_MapScripts::
	.byte 0

SaffronCity_House1_EventScript_MrPsychic::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM_PSYCHIC, SaffronCity_House1_EventScript_MrPsychicAfter
	msgbox MrPsychic_Text_1, MSGBOX_NPC
	giveitem ITEM_TM_PSYCHIC
	msgbox MrPsychic_Text_2, MSGBOX_NPC
	setflag FLAG_GOT_TM_PSYCHIC
	release
	end

SaffronCity_House1_EventScript_MrPsychicAfter::
	msgbox MrPsychic_Text_2, MSGBOX_NPC
	end

MrPsychic_Text_1:
	.string "…\p"
	.string "…\p"
	.string "…\p"
	.string "…Je l'ai !\p"
	.string "Tu voulais ça !$"

MrPsychic_Text_2:
	.string "CT29 contient PSYKO.\p"
	.string "Elle peut baisser la\n"
	.string "DÉF. SPÉ. de la cible.$"
