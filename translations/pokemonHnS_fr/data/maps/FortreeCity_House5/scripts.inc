FortreeCity_House5_MapScripts::
	.byte 0

FortreeCity_House5_EventScript_PokefanF::
	msgbox FortreeCity_House5_Text_TreeHousesAreGreat, MSGBOX_NPC
	end

FortreeCity_House5_EventScript_Man::
	msgbox FortreeCity_House5_Text_AdaptedToNature, MSGBOX_NPC
	end

FortreeCity_House5_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox FortreeCity_House5_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FortreeCity_House5_Text_TreeHousesAreGreat:
	.string "Les maisons dans les arbres de CIMETRONELLE sont géniales !\p"
	.string "Je pense que c'est la ville numéro un pour\n"
	.string "vivre avec les POKéMON.$"

FortreeCity_House5_Text_AdaptedToNature:
	.string "Les POKéMON et les humains se sont\n"
	.string "adaptés à la nature pour survivre.\p"
	.string "Inutile de forcer la nature\n"
	.string "à s'adapter à notre mode de vie.$"

FortreeCity_House5_Text_Zigzagoon:
	.string "ZIGZAGOON : Bufuu !$"

