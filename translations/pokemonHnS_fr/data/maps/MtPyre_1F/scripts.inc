MtPyre_1F_MapScripts::
	.byte 0

MtPyre_1F_DusknoirMisdreavusEvo::
	msgbox MtPyre_1F_DusknoirMisdreavusEvo_Text, MSGBOX_NPC
	end

MtPyre_1F_DusknoirMisdreavusEvo_Text:
	.string "Les SKELENOX sauvages portent parfois\n"
	.string "une RUNE SORT. Je me demande pourquoi ? À quoi ça leur sert ?\l"
	.string "Peut-être pour évoluer ?\p"
	.string "Ce que je sais, c'est que FEUFORÊVE\n"
	.string "évolue s'il la tient pendant la nuit.$"

MtPyre_1F_EventScript_CleanseTagWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CLEANSE_TAG, MtPyre_1F_EventScript_ReceivedCleanseTag
	msgbox MtPyre_1F_Text_TakeThisForYourOwnGood, MSGBOX_DEFAULT
	giveitem ITEM_CLEANSE_TAG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_CLEANSE_TAG
	release
	end

MtPyre_1F_EventScript_ReceivedCleanseTag::
	msgbox MtPyre_1F_Text_ExplainCleanseTag, MSGBOX_DEFAULT
	release
	end

MtPyre_1F_EventScript_PokefanF::
	msgbox MtPyre_1F_Text_ComeToPayRespects, MSGBOX_NPC
	end

MtPyre_1F_EventScript_Man::
	msgbox MtPyre_1F_Text_RestingPlaceOfZigzagoon, MSGBOX_NPC
	end

MtPyre_1F_Text_TakeThisForYourOwnGood:
	.string "Toutes sortes d'êtres errent sur les pentes\n"
	.string "du MONT PYRÉ…\p"
	.string "On ne sait jamais ce qui peut arriver.\n"
	.string "Prends ça. C'est pour ton bien.$"

MtPyre_1F_Text_ExplainCleanseTag:
	.string "Fais tenir cette\n"
	.string "RUNE PURIF. à un POKéMON.\p"
	.string "Ça aidera à repousser les POKéMON sauvages.$"

MtPyre_1F_Text_ComeToPayRespects:
	.string "Tu es venu rendre hommage\n"
	.string "aux esprits des POKéMON disparus ?\p"
	.string "Tu dois vraiment aimer tes POKéMON.$"

MtPyre_1F_Text_RestingPlaceOfZigzagoon:
	.string "C'est le dernier repos de mon\n"
	.string "ZIGZAGOON. Je le chérissais…$"

