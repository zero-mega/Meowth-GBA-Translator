NewBarkTown_House1_MapScripts::
	.byte 0

NewBarkTown_House1_EventScript_Mother::
	lock
	faceplayer
	msgbox NewBarkTown_House1_Text_Neighbor, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_House1_EventScript_Daughter::
	lock
	faceplayer
	msgbox NewBarkTown_House1_Text_NeighborsDaughter, MSGBOX_DEFAULT
	closemessage
	release
	end

NewBarkTown_House1_Text_NeighborsDaughter:
	.string "PIKACHU est un POKéMON évolué.\p"
	.string "J'étais stupéfait par les découvertes\n"
	.string "du PROF.ORME.\p"
	.string "Il est si célèbre pour ses recherches\n"
	.string "sur l'évolution des POKéMON.\p"
	.string "…soupir…\p"
	.string "J'aimerais être chercheur\n"
	.string "comme lui…$"


NewBarkTown_House1_Text_Neighbor:
	.string "Ma fille veut absolument devenir\n"
	.string "l'assistante du PROF.ORME.\p"
	.string "Elle adore vraiment les POKéMON !\p"
	.string "Mais moi aussi, d'ailleurs !$"

