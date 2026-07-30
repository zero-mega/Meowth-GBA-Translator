MagmaHideout_3F_2R_MapScripts::
	.byte 0

MagmaHideout_3F_2R_EventScript_Grunt10::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_10, MagmaHideout_3F_2R_Text_Grunt10Intro, MagmaHideout_3F_2R_Text_Grunt10Defeat
	msgbox MagmaHideout_3F_2R_Text_Grunt10PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_3F_2R_Text_Grunt10Intro:
	.string "Je comprends tout ce que dit\n"
	.string "notre chef. Mais tu sais quoi\p"
	.string "? Faire des trucs comme déterrer\n"
	.string "un POKéMON super-ancien et voler\l"
	.string "la MÉTÉORITE de quelqu'un… Je\p"
	.string "crois qu'on va un peu\n"
	.string "trop loin. Qu'en penses-tu ?$"

MagmaHideout_3F_2R_Text_Grunt10Defeat:
	.string "Ouais, je crois qu'on fait quelque chose\n"
	.string "de travers d'une façon ou d'une autre.$"

MagmaHideout_3F_2R_Text_Grunt10PostBattle:
	.string "Tu sais, perdre contre toi m'a débarrassé l'esprit.\p"
	.string "La prochaine fois que je verrai notre\n"
	.string "leader, je lui demanderai ce qu'on fait.$"

