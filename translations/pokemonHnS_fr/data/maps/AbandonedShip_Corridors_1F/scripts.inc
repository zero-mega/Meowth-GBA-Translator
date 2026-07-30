AbandonedShip_Corridors_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SetTimeEncounters
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

AbandonedShip_Corridors_1F_EventScript_Youngster::
	msgbox AbandonedShip_Corridors_1F_Text_IsntItFunHere, MSGBOX_NPC
	end

AbandonedShip_Corridors_1F_EventScript_Charlie::
	trainerbattle_single TRAINER_CHARLIE, AbandonedShip_Corridors_1F_Text_CharlieIntro, AbandonedShip_Corridors_1F_Text_CharlieDefeat
	msgbox AbandonedShip_Corridors_1F_Text_CharliePostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Corridors_1F_Text_CharlieIntro:
	.string "Qu'est-ce qui est drôle d'avoir ma bouée\n"
	.string "sur le bateau ?$"

AbandonedShip_Corridors_1F_Text_CharlieDefeat:
	.string "Ouah, tu m'as submergé !$"

AbandonedShip_Corridors_1F_Text_CharliePostBattle:
	.string "Ce n'est pas facile de lancer des POKé BALLS\n"
	.string "en tenant une bouée !$"

AbandonedShip_Corridors_1F_Text_IsntItFunHere:
	.string "C'est pas super ici ?\n"
	.string "Rien qu'être ici me rend tout excité !$"
