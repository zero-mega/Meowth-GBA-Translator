CliffEdgeCave_MapScripts::
	.byte 0

CliffEdgeCave_EventScript_BaldMan::
	lock
	faceplayer
	msgbox CliffEdgeCave_Text_Baldman, MSGBOX_DEFAULT
	closemessage
	release
	end

CliffEdgeCave_Text_Baldman:
	.string "Si tu vois une bifurcation\n"
	.string "dans une grotte, il est probable qu'un\l"
	.string "chemin soit le bon et que l'autre mène\l"
	.string "à une impasse.\p"
	.string "mais les gens ne peuvent s'empêcher d'essayer les deux.$"
