LavenderTown_SoulHouse_MapScripts::
	.byte 0

LavenderTownSoulHouse_EventScript_MrFuji::
	msgbox MrFuji_Text_Main, MSGBOX_NPC
	end
LavenderTownSoulHouse_EventScript_Lass::
	msgbox SoulHouse_Text_Lass, MSGBOX_NPC
	end
LavenderTownSoulHouse_EventScript_Teacher::
	msgbox SoulHouse_Text_Teacher, MSGBOX_NPC
	end
LavenderTownSoulHouse_EventScript_Granny::
	msgbox SoulHouse_Text_Granny, MSGBOX_NPC
	end

MrFuji_Text_Main:
	.string "M. FUJI :\p"
	.string "Bienvenue.\n"
	.string "Hmm… Tu sembles\l"
	.string "élever tes\p"
	.string "POKéMON\n"
	.string "de manière\l"
	.string "aimante\p"
	.string "et attentionnée.\n"
	.string "Les POKéMON\p"
	.string "sont nos amis.\n"
	.string "Prends-en soin.$"

SoulHouse_Text_Teacher:
	.string "Il y a d'autres tombes de POKéMON\n"
	.string "ici, je crois.\p"
	.string "Il y a beaucoup de salles auxquelles\n"
	.string "seul M. FUJI peut entrer.$"

SoulHouse_Text_Lass:
	.string "Je suis venu avec ma maman visiter\n"
	.string "les tombes de POKéMON…$"

SoulHouse_Text_Granny:
	.string "Les POKéMON qui vivaient avec moi…\p"
	.string "Je les aimais comme mes\n"
	.string "petits-enfants…$"
