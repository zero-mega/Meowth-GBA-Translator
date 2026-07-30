SafariZone_Southwest_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	map_script MAP_SCRIPT_ON_TRANSITION, SetTimeEncounters
	.byte 0

SafariZone_Southwest_EventScript_Woman::
	msgbox SafariZone_Southwest_Text_Woman, MSGBOX_NPC
	end

SafariZone_Southwest_EventScript_RestHouseSign::
	msgbox SafariZone_Southwest_Text_RestHouseSign, MSGBOX_SIGN
	end

SafariZone_Southwest_EventScript_Happiny::
	msgbox SafariZone_Southwest_EventScript_Happiny_Text, MSGBOX_NPC
	end

SafariZone_Southwest_EventScript_Happiny_Text:
	.string "LEVEINARD évolue par BONHEUR en\n"
	.string "LEUPHORIE. Et PTIRAVI ?\l"
	.string "Comment évolue-t-il ?\p"
	.string "Eh bien, il faut qu'il tienne\n"
	.string "un OEUF CHANCE en montant de niveau !$"
