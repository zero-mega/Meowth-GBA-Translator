MagmaHideout_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MagmaHideout_1F_OnTransition
	.byte 0

MagmaHideout_1F_OnTransition:
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 0
	goto_if_set FLAG_DEFEATED_ENTEI, MagmaHideout_End
	goto_if_set FLAG_UNLOCK_DOGS, MagmaHideout_Entei_CryFaint
	end

MagmaHideout_Entei_CryFaint::
	playmoncry SPECIES_ENTEI, CRY_MODE_FAINT
	release
	end

MagmaHideout_End::
	end

MagmaHideout_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_1, MagmaHideout_1F_Text_Grunt1Intro, MagmaHideout_1F_Text_Grunt1Defeat
	msgbox MagmaHideout_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_1F_EventScript_Grunt2::
	trainerbattle_single TRAINER_RICHARDO, MagmaHideout_1F_Text_Grunt2Intro, MagmaHideout_1F_Text_Grunt2Defeat
	msgbox MagmaHideout_1F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_1F_Text_Grunt1Intro:
	.string "Quand la TEAM MAGMA fait l'appel, on reçoit\n"
	.string "des missions de garde importantes dans\l"
	.string "l'ordre où on se met en ligne.\p"
	.string "C'est pour ça que je suis coincé dans ce coin.\n"
	.string "Je suis toujours en retard à l'appel !$"

MagmaHideout_1F_Text_Grunt1Defeat:
	.string "Je suis toujours en retard aux séances d'entraînement,\n"
	.string "aussi !\p"
	.string "Je déteste le dire, mais je suis minable…$"

MagmaHideout_1F_Text_Grunt1PostBattle:
	.string "OK, je vais essayer de faire un peu plus\n"
	.string "d'efforts à partir de maintenant…$"

MagmaHideout_1F_Text_Grunt2Intro:
	.string "Notre chef nous a\n"
	.string "dit de creuser au\p"
	.string "MONT CHIMNÉE, alors on\n"
	.string "a creusé et creusé.\p"
	.string "Et en creusant, on\p"
	.string "a trouvé quelque\n"
	.string "chose d'incroyable !$"

MagmaHideout_1F_Text_Grunt2Defeat:
	.string "Arrgh !\n"
	.string "À terre !$"

MagmaHideout_1F_Text_Grunt2PostBattle:
	.string "Je ne te le dirai finalement pas.\n"
	.string "Tu le découvriras quand tu y seras !\p"
	.string "C'est mieux de garder des surprises\n"
	.string "pour la fin, tu ne trouves pas ?$"

