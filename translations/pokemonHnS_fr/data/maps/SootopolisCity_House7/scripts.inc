SootopolisCity_House7_MapScripts::
	.byte 0

SootopolisCity_House7_EventScript_OldMan::
	msgbox SootopolisCity_House7_Text_CityFromEruptedVolcano, MSGBOX_NPC
	end

SootopolisCity_House7_EventScript_PokefanF::
	msgbox SootopolisCity_House7_Text_CaveMadeToKeepSomething, MSGBOX_NPC
	end

SootopolisCity_House7_Text_CityFromEruptedVolcano:
	.string "Un volcan sous-marin a fait éruption et\n"
	.string "s'est hissé des profondeurs.\p"
	.string "Son cratère a émergé de la mer et\n"
	.string "s'est rempli d'eau de pluie.\p"
	.string "C'est ainsi qu'est née\n"
	.string "ATALANOPOLIS.$"

SootopolisCity_House7_Text_CaveMadeToKeepSomething:
	.string "La grotte qui relie ATALANOPOLIS\n"
	.string "et le monde extérieur…\p"
	.string "On dirait que la grotte a été faite\n"
	.string "pour empêcher quelque chose de sortir.\p"
	.string "Ou est-ce que j'imagine des choses ?$"

