SeafloorCavern_Room3_MapScripts::
	.byte 0

SeafloorCavern_Room3_EventScript_Shelly::
	trainerbattle_single TRAINER_GRANT, SeafloorCavern_Room3_Text_ShellyIntro, SeafloorCavern_Room3_Text_ShellyDefeat
	msgbox SeafloorCavern_Room3_Text_ShellyPostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room3_EventScript_Grunt5::
	trainerbattle_single TRAINER_VANCE, SeafloorCavern_Room3_Text_Grunt5Intro, SeafloorCavern_Room3_Text_Grunt5Defeat
	msgbox SeafloorCavern_Room3_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

SeafloorCavern_Room3_Text_ShellyIntro:
	.string "Ahahahaha !\p"
	.string "Comment\n"
	.string "as-tu réussi\l"
	.string "à arriver\p"
	.string "ici sans\n"
	.string "sous-marin ?\p"
	.string "Quel enfant\n"
	.string "impressionnant !\p"
	.string "Mais… Il est temps\n"
	.string "de combattre !$"

SeafloorCavern_Room3_Text_ShellyDefeat:
	.string "Ahahahaha !\p"
	.string "Aïe !$"

SeafloorCavern_Room3_Text_ShellyPostBattle:
	.string "Ahahahaha !\n"
	.string "Tu es terriblement fort.\p"
	.string "C'est vraiment dommage que tu ne sois pas\n"
	.string "membre de la TEAM AQUA.\p"
	.string "Tu aurais pu profiter du monde fabuleux\n"
	.string "que notre BOSS nous a promis en tant que\l"
	.string "membre de notre équipe…$"

SeafloorCavern_Room3_Text_Grunt5Intro:
	.string "Pour que notre rêve\n"
	.string "devienne réalité, nous avons\p"
	.string "besoin du pouvoir des\n"
	.string "POKéMON. Mais des intrus\l"
	.string "comme toi utilisent\p"
	.string "les POKéMON pour\n"
	.string "nous gêner !$"

SeafloorCavern_Room3_Text_Grunt5Defeat:
	.string "Ouah !$"

SeafloorCavern_Room3_Text_Grunt5PostBattle:
	.string "Tu sais, nous n'osons pas remettre en question\n"
	.string "les motivations de notre chef.\p"
	.string "Mais toi, juste un morveux,\n"
	.string "tu vas affronter notre BOSS.\p"
	.string "Peut-être…\n"
	.string "Tu dois être quelqu'un…$"

