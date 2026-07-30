RustboroCity_CuttersHouse_MapScripts::
	.byte 0

RustboroCity_CuttersHouse_EventScript_Cutter::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_CUT, RustboroCity_CuttersHouse_EventScript_ExplainCut
	msgbox RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse, MSGBOX_DEFAULT
	giveitem ITEM_HM_CUT
	setflag FLAG_RECEIVED_HM_CUT
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_ExplainCut::
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_Lass::
	msgbox RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees, MSGBOX_NPC
	end

RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse:
	.string "Cette expression\n"
	.string "déterminée…\l"
	.string "Cette façon\p"
	.string "souple de bouger…\p"
	.string "Et tes POKéMON\n"
	.string "bien entraînés…\p"
	.string "Tu es évidemment un\n"
	.string "DRESSEUR\p"
	.string "talentueux !\n"
	.string "Bonne chance !$"

RustboroCity_CuttersHouse_Text_ExplainCut:
	.string "Cette MACHINE CACHE,\n"
	.string "ou CS en bref,\p"
	.string "est COUPE.\n"
	.string "Une capacité CS\p"
	.string "peut être utilisée\n"
	.string "par un POKéMON en\l"
	.string "dehors des combats\p"
	.string "si tu as le bon BADGE.\n"
	.string "Très utile pour explorer !$"

RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees:
	.string "Quand on a agrandi la ville de\n"
	.string "MÉROUVILLE, mon père a aidé.\p"
	.string "Il a fait utiliser COUPE à ses\n"
	.string "POKéMON pour défricher les arbres.$"

