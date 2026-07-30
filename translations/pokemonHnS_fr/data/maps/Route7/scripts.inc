Route7_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route7_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route7_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route7_EventScript_Sign::
	msgbox Route7_Text_UndergroundPathSign, MSGBOX_SIGN
	end

Route7_EventScript_Door::
	msgbox Route7_Text_LockedDoor, MSGBOX_SIGN
	end

Route7_Text_UndergroundPathSign:
	.string "Qu'est-ce que ce tract\p"
	.string "? … Des dresseurs\n"
	.string "grossiers organisent des combats\l"
	.string "dans le PASSAGE SOUTERRAIN.\p"
	.string "À cause des plaintes\n"
	.string "des riverains, le PASSAGE\l"
	.string "SOUTERRAIN a été fermé\p"
	.string "indéfiniment. POLICE DE CELADOPOLE$"

Route7_Text_LockedDoor:
	.string "C'est verrouillé…$"

