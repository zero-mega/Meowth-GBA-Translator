Route30_House_MapScripts::
	.byte 0

Route30_House_EventScript_BaldMan::
	lock
	faceplayer
	goto_if_set FLAG_GOT_BERRY_ROUTE_30_HOUSE, Route30_House_EventScript_BaldMan2
	msgbox Route30_BerryHouse_Text_MonEatBerries, MSGBOX_DEFAULT
	giveitem ITEM_CHERI_BERRY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	closemessage
	setflag FLAG_GOT_BERRY_ROUTE_30_HOUSE
Route30_House_EventScript_BaldMan2::
	msgbox Route30_BerryHouse_Text_CheckTrees MSGBOX_DEFAULT
	closemessage
	release
	end

Route30_BerryHouse_Text_MonEatBerries:
	.string "Quand tu suis ce\n"
	.string "chemin vers le nord,\p"
	.string "tu verras la maison\n"
	.string "de M. POKéMON.\p"
	.string "Mais avant d'y aller, laisse-moi\n"
	.string "te parler des BAIES.\p"
	.string "Les BAIES poussent\n"
	.string "sur des arbres\p"
	.string "dans un sol meuble.\n"
	.string "Plante des BAIES et\p"
	.string "aide la nature !$"

Route30_BerryHouse_Text_CheckTrees:
	.string "Vérifie les arbres pour les BAIES.\n"
	.string "Elles repoussent après quelques heures.$"
