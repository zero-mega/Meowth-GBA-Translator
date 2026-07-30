SootopolisCity_House4_MapScripts::
	.byte 0

SootopolisCity_House4_EventScript_Man::
	msgbox SootopolisCity_House4_Text_AncientTreasuresWaitingInSea, MSGBOX_NPC
	end

SootopolisCity_House4_EventScript_Woman::
	msgbox SootopolisCity_House4_Text_StrollUnderwaterWithPokemon, MSGBOX_NPC
	end

SootopolisCity_House4_EventScript_Azumarill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, CRY_MODE_NORMAL
	msgbox SootopolisCity_House4_Text_Azumarill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SootopolisCity_House4_Text_AncientTreasuresWaitingInSea:
	.string "Écoute bien, et je vais te dire\n"
	.string "quelque chose de bien.\p"
	.string "Il y aurait une ancienne\n"
	.string "ruine dans la mer par ici.\p"
	.string "Des trésors attendraient peut-être\n"
	.string "d'être découverts là-dessous.$"

SootopolisCity_House4_Text_StrollUnderwaterWithPokemon:
	.string "Des trésors anciens…\p"
	.string "Ce serait bien s'ils existaient, mais\n"
	.string "même s'ils n'existaient pas, ce serait si\l"
	.string "beau de faire une promenade sous-marine\l"
	.string "avec mes POKéMON.$"

SootopolisCity_House4_Text_Azumarill:
	.string "AZUMARILL : Marurii.$"

