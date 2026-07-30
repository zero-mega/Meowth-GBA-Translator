PacifidlogTown_House5_MapScripts::
	.byte 0

PacifidlogTown_House5_EventScript_MirageIslandWatcher::
	lock
	faceplayer
	specialvar VAR_RESULT, IsMirageIslandPresent
	goto_if_eq VAR_RESULT, TRUE, PacifidlogTown_House5_EventScript_MirageIslandPresent
	msgbox PacifidlogTown_House5_Text_CantSeeMirageIslandToday, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House5_EventScript_MirageIslandPresent::
	msgbox PacifidlogTown_House5_Text_CanSeeMirageIslandToday, MSGBOX_DEFAULT
	release
	end

PacifidlogTown_House5_EventScript_Gentleman::
	msgbox PacifidlogTown_House5_Text_MirageIslandAppearDependingOnWeather, MSGBOX_NPC
	end

PacifidlogTown_House5_Text_CantSeeMirageIslandToday:
	.string "Je ne vois pas l'ÎLE MIRAGE aujourd'hui…$"

PacifidlogTown_House5_Text_CanSeeMirageIslandToday:
	.string "Oh ! Oh là là !\n"
	.string "Je vois l'ÎLE MIRAGE aujourd'hui !$"

PacifidlogTown_House5_Text_MirageIslandAppearDependingOnWeather:
	.string "ÎLE MIRAGE…\p"
	.string "Elle doit devenir\n"
	.string "visible et\l"
	.string "invisible\p"
	.string "selon les\n"
	.string "conditions\p"
	.string "météo qui la font\p"
	.string "apparaître et\n"
	.string "disparaître.\l"
	.string "C'est\p"
	.string "mystérieux !$"
