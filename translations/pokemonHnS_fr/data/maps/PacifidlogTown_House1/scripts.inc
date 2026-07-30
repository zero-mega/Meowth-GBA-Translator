PacifidlogTown_House1_MapScripts::
	.byte 0

PacifidlogTown_House1_EventScript_Man::
	msgbox PacifidlogTown_House1_Text_RegiStory, MSGBOX_NPC
	end

PacifidlogTown_House1_EventScript_Woman::
	msgbox PacifidlogTown_House1_Text_SixDotsOpenThreeDoors, MSGBOX_NPC
	end

PacifidlogTown_House1_Text_RegiStory:
	.string "Dans la région de HOENN, il y a\n"
	.string "cinq POKéMON qui représentent\l"
	.string "la puissance du roc, de la glace,\l"
	.string "de l'acier, de l'électricité et de\p"
	.string "l'énergie dragon.\n"
	.string "Chacun se cacherait au fond de\p"
	.string "grottes.\n"
	.string "C'est l'histoire qu'on m'a racontée quand j'étais petit.$"

PacifidlogTown_House1_Text_SixDotsOpenThreeDoors:
	.string "« Six points ouvrent cinq portes. »\p"
	.string "Grand-père disait ça, mais je ne\n"
	.string "sais pas ce qu'il voulait dire.$"

