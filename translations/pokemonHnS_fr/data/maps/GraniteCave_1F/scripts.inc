GraniteCave_1F_MapScripts::
	.byte 0

GraniteCave_1F_EventScript_Hiker::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_FLASH, GraniteCave_1F_EventScript_ReceivedFlash
	msgbox GraniteCave_1F_Text_GetsDarkAheadHereYouGo, MSGBOX_DEFAULT
	giveitem ITEM_HM_FLASH
	setflag FLAG_RECEIVED_HM_FLASH
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_EventScript_ReceivedFlash::
	msgbox GraniteCave_1F_Text_ExplainFlash, MSGBOX_DEFAULT
	release
	end

GraniteCave_1F_Text_GetsDarkAheadHereYouGo:
	.string "Hé, toi.\n"
	.string "Il fait terriblement\l"
	.string "sombre devant.\p"
	.string "Ça sera dur d'explorer.\n"
	.string "Ce type qui est passé plus tôt…\p"
	.string "PIERRE, je crois,\n"
	.string "est allé dans cette\p"
	.string "grotte.\n"
	.string "Tu devrais le suivre,\p"
	.string "{PLAYER}{KUN}.$"

GraniteCave_1F_Text_ExplainFlash:
	.string "Tu peux utiliser FLASH si tu\n"
	.string "as la CS dans le SAC\l"
	.string "et un POKéMON qui peut l'apprendre.\p"
	.string "Pas besoin de l'enseigner. Mais, pour\n"
	.string "l'utiliser, il te faut le BADGE\p"
	.string "d'ARÈNE de l'ARÈNE POKéMON d'ALGATIA. Ça\n"
	.string "éclaire même l'obscurité totale des grottes.$"
