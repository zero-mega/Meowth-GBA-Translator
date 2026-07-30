LavenderTown_Mart_MapScripts::
	.byte 0

LavenderTown_Mart_EventScript_Pokefan::
	msgbox LavenderMart_Text_PokefanM, MSGBOX_NPC
	end

LavenderTown_Mart_EventScript_Rocker::
	msgbox LavenderMart_Text_Rocker, MSGBOX_NPC
	end

LavenderMart_Text_PokefanM:
	.string "Le REPOUSSE est indispensable si tu\n"
	.string "vas explorer une grotte.\p"
	.string "Même si j'aime explorer,\n"
	.string "je n'ai pas encore visité\l"
	.string "toutes les grottes.$"

LavenderMart_Text_Rocker:
	.string "J'ai entendu parler d'un artisan qui\n"
	.string "fabrique des BALLS sur mesure dans la ville\l"
	.string "d'ÉCORCIA, à JOHTO.\p"
	.string "J'aimerais en avoir.$"
