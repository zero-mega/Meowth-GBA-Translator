MagmaHideout_2F_1R_MapScripts::
	.byte 0

MagmaHideout_2F_1R_EventScript_Grunt14::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_14, MagmaHideout_2F_1R_Text_Grunt14Intro, MagmaHideout_2F_1R_Text_Grunt14Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt14PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt3::
	trainerbattle_single TRAINER_NARD, MagmaHideout_2F_1R_Text_Grunt3Intro, MagmaHideout_2F_1R_Text_Grunt3Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_4, MagmaHideout_2F_1R_Text_Grunt4Intro, MagmaHideout_2F_1R_Text_Grunt4Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_5, MagmaHideout_2F_1R_Text_Grunt5Intro, MagmaHideout_2F_1R_Text_Grunt5Defeat
	msgbox MagmaHideout_2F_1R_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_1R_Text_Grunt14Intro:
	.string "Quoi, quoi, quoi ?\p"
	.string "Seuls les membres de la TEAM MAGMA sont censés\n"
	.string "être ici !\p"
	.string "Mais tu n'es pas habillé avec l'uniforme\n"
	.string "de la TEAM MAGMA…\p"
	.string "Tu éveilles mes soupçons !\n"
	.string "Combattons !$"

MagmaHideout_2F_1R_Text_Grunt14Defeat:
	.string "Aiyiyi…\n"
	.string "Ma fierté de membre de la TEAM MAGMA…$"

MagmaHideout_2F_1R_Text_Grunt14PostBattle:
	.string "Si tu as des frissons, tu devrais\n"
	.string "rejoindre la TEAM MAGMA.$"

MagmaHideout_2F_1R_Text_Grunt3Intro:
	.string "Halte là !\p"
	.string "Tu ne crois quand même pas que je vais\n"
	.string "fermer ma bouche et te laisser passer ?$"

MagmaHideout_2F_1R_Text_Grunt3Defeat:
	.string "Ooh wow !\n"
	.string "Je m'incline !$"

MagmaHideout_2F_1R_Text_Grunt3PostBattle:
	.string "Peut-être que j'aurais dû te laisser passer\n"
	.string "sans te défier…$"

MagmaHideout_2F_1R_Text_Grunt4Intro:
	.string "Ahah !\n"
	.string "Un intrus !$"

MagmaHideout_2F_1R_Text_Grunt4Defeat:
	.string "Graaah !$"

MagmaHideout_2F_1R_Text_Grunt4PostBattle:
	.string "J'ai déjà perdu.\p"
	.string "Dois-je vraiment continuer à\n"
	.string "tourner en rond ?$"

MagmaHideout_2F_1R_Text_Grunt5Intro:
	.string "Oh, oh !\n"
	.string "Un intrus !$"

MagmaHideout_2F_1R_Text_Grunt5Defeat:
	.string "Marmonne…$"

MagmaHideout_2F_1R_Text_Grunt5PostBattle:
	.string "En fait, je ne suis pas expert en combat…$"

