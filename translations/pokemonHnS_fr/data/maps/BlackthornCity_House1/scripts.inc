BlackthornCity_House1_MapScripts::
	.byte 0

BlackthornCity_House1EventScript_Granny::
	msgbox BlackthornCity_House1_Text_Granny, MSGBOX_NPC
	end

BlackthornCity_House1EventScript_Dratini::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DRATINI, CRY_MODE_NORMAL
	msgbox BlackthornCity_House1_Text_Dratini, MSGBOX_DEFAULT
	waitmoncry
	release
	end

BlackthornCity_House1_Text_Granny:
	.string "Un clan de Dresseurs qui commandent librement\n"
	.string "les dragons vit ici même à\l"
	.string "BLACKTHORN.\p"
	.string "Du coup, il y a beaucoup de légendes\n"
	.string "sur les dragons dans cette ville.$"

BlackthornCity_House1_Text_Dratini:
	.string "MINIDRACO : Draa !$"
