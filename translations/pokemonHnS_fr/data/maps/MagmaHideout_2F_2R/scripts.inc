MagmaHideout_2F_2R_MapScripts::
	.byte 0

MagmaHideout_2F_2R_EventScript_Grunt15::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_15, MagmaHideout_2F_2R_Text_Grunt15Intro, MagmaHideout_2F_2R_Text_Grunt15Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt15PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt6::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_6, MagmaHideout_2F_2R_Text_Grunt6Intro, MagmaHideout_2F_2R_Text_Grunt6Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt6PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt7::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_7, MagmaHideout_2F_2R_Text_Grunt7Intro, MagmaHideout_2F_2R_Text_Grunt7Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt7PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_EventScript_Grunt8::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_8, MagmaHideout_2F_2R_Text_Grunt8Intro, MagmaHideout_2F_2R_Text_Grunt8Defeat
	msgbox MagmaHideout_2F_2R_Text_Grunt8PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_2F_2R_Text_Grunt15Intro:
	.string "Je n'ai rien contre toi.\n"
	.string "Je ne fais que suivre les ordres !$"

MagmaHideout_2F_2R_Text_Grunt15Defeat:
	.string "J'ai peut-être perdu, mais…$"

MagmaHideout_2F_2R_Text_Grunt15PostBattle:
	.string "On a déterré quelque chose d'incroyable !\n"
	.string "Et on a obtenu l'ORBE BLEU\p"
	.string "! Il ne reste plus qu'à\n"
	.string "notre leader de… Fufufu… Fwahahaha !$"

MagmaHideout_2F_2R_Text_Grunt6Intro:
	.string "Je ne supporte pas la chaleur. Peut-être\n"
	.string "que j'aurais dû rejoindre la TEAM AQUA…$"

MagmaHideout_2F_2R_Text_Grunt6Defeat:
	.string "Ouais, je ne suis peut-être vraiment pas fait\n"
	.string "pour la TEAM MAGMA…$"

MagmaHideout_2F_2R_Text_Grunt6PostBattle:
	.string "Tu ne te sens pas seul pour la mer\n"
	.string "en étant dans un endroit comme ça ?$"

MagmaHideout_2F_2R_Text_Grunt7Intro:
	.string "On entend parfois des tremblements\p"
	.string "ici. Ce serait le volcan\n"
	.string "qui gronde ? Ou\p"
	.string "GROU… Oups ! Non,\n"
	.string "non, laisse tomber !$"

MagmaHideout_2F_2R_Text_Grunt7Defeat:
	.string "Tu es un combattant fougueux.\n"
	.string "Comme un volcan !$"

MagmaHideout_2F_2R_Text_Grunt7PostBattle:
	.string "Tu as gagné par chance cette fois,\n"
	.string "mais peu importe.\p"
	.string "L'objectif de la TEAM MAGMA est sur le\n"
	.string "point d'être atteint !$"

MagmaHideout_2F_2R_Text_Grunt8Intro:
	.string "Un de nos gars paniquait parce qu'il avait\n"
	.string "perdu son EMBLÈME MAGMA...\p"
	.string "Attends une minute !\n"
	.string "C'est toi qui l'as trouvé ?$"

MagmaHideout_2F_2R_Text_Grunt8Defeat:
	.string "J'ai du mal à y croire…$"

MagmaHideout_2F_2R_Text_Grunt8PostBattle:
	.string "J'ai le sentiment que notre plan\n"
	.string "va finir en échec…$"

