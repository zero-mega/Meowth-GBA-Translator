Route2_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route2_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route2_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route2_EventScript_Rob::
	trainerbattle_single TRAINER_ROB, Route2_Text_BugCatcherRob_Seen, Route2_Text_BugCatcherRob_Beaten
	msgbox Route2_Text_BugCatcherRob_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route2_EventScript_Ed::
	trainerbattle_single TRAINER_ED, Route2_Text_BugCatcherEd_Seen, Route2_Text_BugCatcherEd_Beaten
	msgbox Route2_Text_BugCatcherEd_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route2_EventScript_Doug::
	trainerbattle_single TRAINER_DOUG, Route2_Text_BugCatcherDoug_Seen, Route2_Text_BugCatcherDoug_Beaten
	msgbox Route2_Text_BugCatcherDoug_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route2_EventScript_Sign::
	msgbox Route2_Text_Sign, MSGBOX_SIGN
	end

Route2_EventScript_CaveSign::
	msgbox Route2_Text_DiglettsCaveSign, MSGBOX_SIGN
	end

Route2_EventScript_Carbos::
    finditem ITEM_CARBOS
    end

Route2_EventScript_Nugget::
    finditem ITEM_NUGGET
    end

Route2_Text_BugCatcherRob_Seen:
	.string "Mes POKéMON INSECTE sont coriaces.\n"
	.string "Prépare-toi à perdre !$"

Route2_Text_BugCatcherRob_Beaten:
	.string "J'ai été écrasé…$"

Route2_Text_BugCatcherRob_AfterBattle:
	.string "Je vais chercher des POKéMON\n"
	.string "insectes plus forts.$"

Route2_Text_BugCatcherEd_Seen:
	.string "Si tu marches dans les hautes herbes en short,\n"
	.string "tu te fais des éraflures ?$"

Route2_Text_BugCatcherEd_Beaten:
	.string "Aïe, aïe, aïe !$"

Route2_Text_BugCatcherEd_AfterBattle:
	.string "Ça va vraiment piquer quand tu\n"
	.string "prendras un bain.$"

Route2_Text_BugCatcherDoug_Seen:
	.string "Pourquoi les filles n'aiment pas les POKéMON Insecte ?$"

Route2_Text_BugCatcherDoug_Beaten:
	.string "Pas bon !$"

Route2_Text_BugCatcherDoug_AfterBattle:
	.string "Les POKéMON Insecte sont mous comme des peluches\n"
	.string "quand tu leur serres le ventre.\p"
	.string "J'adore cette sensation !$"

Route2_Text_Sign:
	.string "ROUTE 2\p"
	.string "JADIELLE - ARGENTA$"

Route2_Text_DiglettsCaveSign:
	.string "GROTTE TAUPIQUEUR$"

