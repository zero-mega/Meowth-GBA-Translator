Gate_SaffronCity_Route6_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SaffronCity_OnFrame
	.byte 0

Gate_SaffronCity_Route6_EventScript_Guard::
	goto_if_eq VAR_TEMP_0, 1, Gate_SaffronCity_Route6_EventScript_Guard2
	msgbox Route6_Text_SaffronGuardWelcome, MSGBOX_NPC
	setvar VAR_TEMP_0, 1
	end
Gate_SaffronCity_Route6_EventScript_Guard2::
	msgbox Route6_Text_SaffronGuardMagnetTrain, MSGBOX_NPC
	end

Route6_Text_SaffronGuardWelcome:
	.string "Bienvenue à SAFRANIA, foyer du\n"
	.string "TRAIN MAGNÉT ! …C'est ce\p"
	.string "que je dirais normalement, mais\n"
	.string "le TRAIN MAGNÉT ne roule\l"
	.string "pas maintenant. Il n'a\p"
	.string "plus d'électricité car il\n"
	.string "y a un problème\l"
	.string "avec la CENTRALE ÉLECTRIQUE.$"

Route6_Text_SaffronGuardMagnetTrain:
	.string "Le TRAIN MAGNÉTIQUE est la chose\n"
	.string "la plus célèbre de SAFRANIA.$"
