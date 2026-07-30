DewfordTown_House2_MapScripts::
	.byte 0

DewfordTown_House2_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SILK_SCARF, DewfordTown_House2_EventScript_ExplainSilkScarf
	msgbox DewfordTown_House2_Text_WantYouToHaveSilkScarf, MSGBOX_DEFAULT
	giveitem ITEM_SILK_SCARF
	goto_if_eq VAR_RESULT, FALSE, DewfordTown_House2_EventScript_NoRoomForScarf
	setflag FLAG_RECEIVED_SILK_SCARF
	release
	end

DewfordTown_House2_EventScript_NoRoomForScarf::
	msgbox DewfordTown_House2_Text_NoRoom, MSGBOX_DEFAULT
	release
	end

DewfordTown_House2_EventScript_ExplainSilkScarf::
	msgbox DewfordTown_House2_Text_ExplainSilkScarf, MSGBOX_DEFAULT
	release
	end

DewfordTown_House2_EventScript_Boy::
	msgbox DewfordTown_House2_Text_BrawlySoCool, MSGBOX_NPC
	end

DewfordTown_House2_Text_WantYouToHaveSilkScarf:
	.string "Régale tes yeux avec ça ! C'est\p"
	.string "un MOUCHOIR SOIE. C'est à la pointe\n"
	.string "de la mode, ouais ! Oh, je\p"
	.string "vois tes yeux briller ! Tu\n"
	.string "apprécies mon style éblouissant ! Oh,\p"
	.string "tu es un délice ! Tiens.\n"
	.string "Je veux que tu l'aies !$"

DewfordTown_House2_Text_NoRoom:
	.string "Oh, tu n'as plus de place ?\p"
	.string "Écoute bien, ce FOULARD est un\n"
	.string "must ! Je vendrais tous mes objets\l"
	.string "pour en avoir un !$"

DewfordTown_House2_Text_ExplainSilkScarf:
	.string "Le FOULARD SOIE augmente la puissance\n"
	.string "des attaques de type NORMAL. C'est\p"
	.string "un FOULARD merveilleux qui va à\n"
	.string "presque tous les POKéMON !$"

DewfordTown_House2_Text_BrawlySoCool:
	.string "Waouh, tu as traversé la mer\n"
	.string "pour visiter MYOKARA ?\p"
	.string "Tu es peut-être venu ici parce que tu as\n"
	.string "entendu parler de BRAWLY ?\p"
	.string "Il est tellement cool…\n"
	.string "Tout le monde l'idolâtre.$"

