SeafloorCavern_Room4_MapScripts::
	.byte 0

SeafloorCavern_Room4_EventScript_Grunt3::
	trainerbattle_single TRAINER_TYLER, SeafloorCavern_Room4_Text_Grunt3Intro, SeafloorCavern_Room4_Text_Grunt3Defeat
	msgbox SeafloorCavern_Room4_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room4_EventScript_Grunt4::
	trainerbattle_single TRAINER_VALERIE, SeafloorCavern_Room4_Text_Grunt4Intro, SeafloorCavern_Room4_Text_Grunt4Defeat
	msgbox SeafloorCavern_Room4_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room4_Text_Grunt3Intro:
	.string "Qui es-tu ?\n"
	.string "Par où es-tu entré ?$"

SeafloorCavern_Room4_Text_Grunt3Defeat:
	.string "Perdu…$"

SeafloorCavern_Room4_Text_Grunt3PostBattle:
	.string "Je ne trouve pas la sortie !\p"
	.string "Je n'ai pas peur. Ne te méprends pas !$"

SeafloorCavern_Room4_Text_Grunt4Intro:
	.string "Qui es-tu ?\n"
	.string "Où crois-tu aller ?$"

SeafloorCavern_Room4_Text_Grunt4Defeat:
	.string "Je n'ai pas réussi à gagner !$"

SeafloorCavern_Room4_Text_Grunt4PostBattle:
	.string "Mon partenaire a oublié la carte dans ce\n"
	.string "sous-marin !\p"
	.string "Pas terrible comme partenaire, hein ?$"

