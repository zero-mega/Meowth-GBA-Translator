DewfordTown_House1_MapScripts::
	.byte 0

DewfordTown_House1_EventScript_Man::
	msgbox DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland, MSGBOX_NPC
	end

DewfordTown_House1_EventScript_Woman::
	msgbox DewfordTown_House1_Text_LifeGoesSlowlyOnIsland, MSGBOX_NPC
	end

DewfordTown_House1_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox DewfordTown_House1_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

DewfordTown_House1_Text_LotToBeSaidForLivingOnIsland:
	.string "On peut dire beaucoup de choses sur la vie\n"
	.string "sur une petite île comme celle-ci, en harmonie\l"
	.string "avec les POKéMON et la famille.$"

DewfordTown_House1_Text_LifeGoesSlowlyOnIsland:
	.string "J'ai quitté le grand port de POIVRESSEL\n"
	.string "quand je me suis mariée ici.\p"
	.string "La vie passe lentement sur cette petite\n"
	.string "île. Mais être entourée de la\l"
	.string "belle mer--c'est aussi le bonheur.$"

DewfordTown_House1_Text_Zigzagoon:
	.string "ZIGZAGOON : Guguuh !$"

