SeafloorCavern_Room1_MapScripts::
	.byte 0

SeafloorCavern_Room1_EventScript_Grunt1::
	trainerbattle_single TRAINER_TROY, SeafloorCavern_Room1_Text_Grunt1Intro, SeafloorCavern_Room1_Text_Grunt1Defeat
	msgbox SeafloorCavern_Room1_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room1_EventScript_Grunt2::
	trainerbattle_single TRAINER_TULLY, SeafloorCavern_Room1_Text_Grunt2Intro, SeafloorCavern_Room1_Text_Grunt2Defeat
	msgbox SeafloorCavern_Room1_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room1_Text_Grunt1Intro:
	.string "On n'a pas besoin d'un gamin ici !\n"
	.string "Rentre chez toi !$"

SeafloorCavern_Room1_Text_Grunt1Defeat:
	.string "Je veux rentrer chez moi…$"

SeafloorCavern_Room1_Text_Grunt1PostBattle:
	.string "Je veux une promotion pour pouvoir\n"
	.string "commander les SBIRES…$"

SeafloorCavern_Room1_Text_Grunt2Intro:
	.string "Ce sous-marin… C'est minuscule à l'intérieur.\n"
	.string "J'ai mal partout !$"

SeafloorCavern_Room1_Text_Grunt2Defeat:
	.string "Perdre me rend grognon !$"

SeafloorCavern_Room1_Text_Grunt2PostBattle:
	.string "Ce sous-marin qu'on a volé, mec,\n"
	.string "c'est brutal comme balade.\l"
	.string "C'est beaucoup trop étroit là-dedans !$"

