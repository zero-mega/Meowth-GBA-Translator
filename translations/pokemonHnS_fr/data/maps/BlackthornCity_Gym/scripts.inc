BlackthornCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, BlackthornGym_OnLoad
	.byte 0

BlackthornGym_OnLoad::
	call_if_eq VAR_BLACKTHORN_GYM_STATE, 1, BlackthornGym_MapScript_Var1
	call_if_eq VAR_BLACKTHORN_GYM_STATE, 2, BlackthornGym_MapScript_Var2
	call_if_eq VAR_BLACKTHORN_GYM_STATE, 3, BlackthornGym_MapScript_Var3
	call_if_eq VAR_BLACKTHORN_GYM_STATE, 4, BlackthornGym_MapScript_Var4
	end

BlackthornGym_MapScript_Var1::
	call BlackthornGym_MapScript_BuildBridge1
	end

BlackthornGym_MapScript_Var2::
	call BlackthornGym_MapScript_BuildBridge1
	call BlackthornGym_MapScript_BuildBridge2
	end

BlackthornGym_MapScript_Var3::
	call BlackthornGym_MapScript_BuildBridge1
	call BlackthornGym_MapScript_BuildBridge2
	call BlackthornGym_MapScript_BuildBridge3
	end

BlackthornGym_MapScript_Var4::
	call BlackthornGym_MapScript_BuildBridge1
	call BlackthornGym_MapScript_BuildBridge2
	call BlackthornGym_MapScript_BuildBridge3
	call BlackthornGym_MapScript_BuildBridge4
	end

BlackthornGym_TriggerBridge1::
	call BlackthornGym_MapScript_BuildBridge1
	playse SE_BANG
	special DrawWholeMapView
	setvar VAR_BLACKTHORN_GYM_STATE, 1
	end

BlackthornGym_MapScript_BuildBridge1::
	setmetatile 19, 47, 0x35A, FALSE
	setmetatile 19, 48, 0x35A, FALSE
	setmetatile 19, 49, 0x35A, FALSE
	setmetatile 19, 50, 0x35A, FALSE
	setmetatile 19, 51, 0x35A, FALSE
	setmetatile 19, 52, 0x35A, FALSE
	setmetatile 19, 53, 0x35A, FALSE
	setmetatile 19, 54, 0x35A, FALSE
	setmetatile 20, 47, 0x35A, FALSE
	setmetatile 20, 48, 0x35A, FALSE
	setmetatile 20, 49, 0x35A, FALSE
	setmetatile 20, 50, 0x35A, FALSE
	setmetatile 20, 51, 0x35A, FALSE
	setmetatile 20, 52, 0x35A, FALSE
	setmetatile 20, 53, 0x35A, FALSE
	setmetatile 20, 54, 0x35A, FALSE
	setmetatile 21, 47, 0x35A, FALSE
	setmetatile 21, 48, 0x35A, FALSE
	setmetatile 21, 49, 0x35A, FALSE
	setmetatile 21, 50, 0x35A, FALSE
	setmetatile 21, 51, 0x35A, FALSE
	setmetatile 21, 52, 0x35A, FALSE
	setmetatile 21, 53, 0x35A, FALSE
	setmetatile 21, 54, 0x35A, FALSE
	return

BlackthornGym_TriggerBridge2::
	call BlackthornGym_MapScript_BuildBridge2
	playse SE_BANG
	special DrawWholeMapView
	setvar VAR_BLACKTHORN_GYM_STATE, 2
	end

BlackthornGym_MapScript_BuildBridge2::
	setmetatile 17, 35, 0x35A, FALSE
	setmetatile 17, 36, 0x35A, FALSE
	setmetatile 17, 37, 0x35A, FALSE
	setmetatile 17, 38, 0x35A, FALSE
	setmetatile 17, 39, 0x35A, FALSE
	setmetatile 17, 40, 0x35A, FALSE
	setmetatile 18, 35, 0x35A, FALSE
	setmetatile 18, 36, 0x35A, FALSE
	setmetatile 18, 37, 0x35A, FALSE
	setmetatile 18, 38, 0x35A, FALSE
	setmetatile 18, 39, 0x35A, FALSE
	setmetatile 18, 40, 0x35A, FALSE
	setmetatile 19, 35, 0x35A, FALSE
	setmetatile 19, 36, 0x35A, FALSE
	setmetatile 19, 37, 0x35A, FALSE
	setmetatile 19, 38, 0x35A, FALSE
	setmetatile 19, 39, 0x35A, FALSE
	setmetatile 19, 40, 0x35A, FALSE
	setmetatile 20, 32, 0x359, FALSE
	setmetatile 21, 32, 0x359, FALSE
	setmetatile 22, 32, 0x359, FALSE
	setmetatile 20, 35, 0x361, TRUE
	setmetatile 21, 35, 0x361, TRUE
	setmetatile 22, 35, 0x361, TRUE
	setmetatile 20, 33, 0x35A, FALSE
	setmetatile 20, 34, 0x35A, FALSE
	setmetatile 21, 33, 0x35A, FALSE
	setmetatile 21, 34, 0x35A, FALSE
	setmetatile 22, 33, 0x35A, FALSE
	setmetatile 22, 34, 0x35A, FALSE
	return

BlackthornGym_TriggerBridge3::
	call BlackthornGym_MapScript_BuildBridge3
	playse SE_BANG
	special DrawWholeMapView
	setvar VAR_BLACKTHORN_GYM_STATE, 3
	end

BlackthornGym_MapScript_BuildBridge3::
	setmetatile 17, 26, 0x359, FALSE
	setmetatile 18, 26, 0x359, FALSE
	setmetatile 19, 26, 0x359, FALSE
	setmetatile 20, 26, 0x359, FALSE
	setmetatile 21, 26, 0x359, FALSE
	setmetatile 22, 26, 0x359, FALSE
	setmetatile 23, 26, 0x359, FALSE

	setmetatile 17, 29, 0x361, TRUE
	setmetatile 18, 29, 0x361, TRUE
	setmetatile 19, 29, 0x361, TRUE
	setmetatile 20, 29, 0x361, TRUE
	setmetatile 21, 29, 0x361, TRUE
	setmetatile 22, 29, 0x361, TRUE
	setmetatile 23, 29, 0x361, TRUE

	setmetatile 17, 27, 0x35A, FALSE
	setmetatile 17, 28, 0x35A, FALSE
	setmetatile 18, 27, 0x35A, FALSE
	setmetatile 18, 28, 0x35A, FALSE
	setmetatile 19, 27, 0x35A, FALSE
	setmetatile 19, 28, 0x35A, FALSE
	setmetatile 20, 27, 0x35A, FALSE
	setmetatile 20, 28, 0x35A, FALSE
	setmetatile 21, 27, 0x35A, FALSE
	setmetatile 21, 28, 0x35A, FALSE
	setmetatile 22, 27, 0x35A, FALSE
	setmetatile 22, 28, 0x35A, FALSE
	setmetatile 23, 27, 0x35A, FALSE
	setmetatile 23, 28, 0x35A, FALSE
	return	

BlackthornGym_TriggerBridge4::
	call BlackthornGym_MapScript_BuildBridge4
	playse SE_BANG
	special DrawWholeMapView
	setvar VAR_BLACKTHORN_GYM_STATE, 4
	end

BlackthornGym_MapScript_BuildBridge4::
	setmetatile 19, 11, 0x35A, FALSE
	setmetatile 19, 12, 0x35A, FALSE
	setmetatile 19, 13, 0x35A, FALSE
	setmetatile 19, 14, 0x35A, FALSE
	setmetatile 19, 15, 0x35A, FALSE
	setmetatile 20, 11, 0x35A, FALSE
	setmetatile 20, 12, 0x35A, FALSE
	setmetatile 20, 13, 0x35A, FALSE
	setmetatile 20, 14, 0x35A, FALSE
	setmetatile 20, 15, 0x35A, FALSE
	setmetatile 21, 11, 0x35A, FALSE
	setmetatile 21, 12, 0x35A, FALSE
	setmetatile 21, 13, 0x35A, FALSE
	setmetatile 21, 14, 0x35A, FALSE
	setmetatile 21, 15, 0x35A, FALSE
	return


BlackthornGym_EventScript_Cody::
	trainerbattle_single TRAINER_CODY BlackthornGym_Text_CooltrainermCodySeenText, BlackthornGym_Text_CooltrainermCodyBeatenText
	msgbox BlackthornGym_Text_CooltrainermCodyAfterBattleText, MSGBOX_AUTOCLOSE
	end

BlackthornGym_EventScript_Fran::
	trainerbattle_single TRAINER_FRAN BlackthornGym_Text_CooltrainerfFranSeenText, BlackthornGym_Text_CooltrainerfFranBeatenText
	msgbox BlackthornGym_Text_CooltrainerfFranAfterBattleText, MSGBOX_AUTOCLOSE
	end

BlackthornGym_EventScript_Paul::
	trainerbattle_single TRAINER_PAUL BlackthornGym_Text_CooltrainermPaulSeenText, BlackthornGym_Text_CooltrainermPaulBeatenText
	msgbox BlackthornGym_Text_CooltrainermPaulAfterBattleText, MSGBOX_AUTOCLOSE
	end

BlackthornGym_EventScript_Mike::
	trainerbattle_single TRAINER_MIKE BlackthornGym_Text_CooltrainermMikeSeenText, BlackthornGym_Text_CooltrainermMikeBeatenText
	msgbox BlackthornGym_Text_CooltrainermMikeAfterBattleText, MSGBOX_AUTOCLOSE
	end

BlackthornGym_EventScript_Lola::
	trainerbattle_single TRAINER_LOLA BlackthornGym_Text_CooltrainerfLolaSeenText, BlackthornGym_Text_CooltrainerfLolaBeatenText
	msgbox BlackthornGym_Text_CooltrainerfLolaAfterBattleText, MSGBOX_AUTOCLOSE
	end


BlackthornGym_EventScript_Clair::
	lock
	faceplayer
	goto_if_set FLAG_IS_CHAMPION, BlackthornGym_EventScript_ClairAfterLeague
	goto_if_ge VAR_BLACKTHORN_CITY_STATE, 4, BlackthornGym_EventScript_Clair_Defeated
	goto_if_eq VAR_BLACKTHORN_CITY_STATE, 2, BlackthornGym_EventScript_ClairDuringChallenge
	msgbox BlackthornGym_Text_ClairIntroText, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_CLAIR_1, BlackthornGym_Text_ClairWinText
	msgbox BlackthornGym_Text_ClairText_GoToDragonsDen, MSGBOX_DEFAULT
	setvar VAR_0x8008, 8
	call Common_EventScript_SetGymTrainers
	setvar VAR_BLACKTHORN_CITY_STATE, 2
	closemessage
	release
	end

BlackthornGym_EventScript_ClairDuringChallenge::
	msgbox BlackthornGym_Text_ClairText_TooMuchToExpect, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackthornGym_EventScript_Clair_Defeated::
	msgbox BlackthornGym_Text_ClairText_League, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackthornGym_EventScript_ClairAfterLeague::
	msgbox BlackthornGym_Text_ClairAfterLeague, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackthornGym_Text_ClairIntroText:
    .string "Je suis IRIS. La meilleure maîtresse\p"
    .string "des dragons du monde. Je peux\p"
    .string "me mesurer même au CONSEIL DES\n"
    .string "4 de la LIGUE POKéMON. Tu\p"
    .string "veux quand même m'affronter ? …D'accord.\p"
    .string "Allons-y ! En tant que\p"
    .string "CHAMPION d'ARÈNE, j'utiliserai toute ma\n"
    .string "puissance contre tout adversaire !$"

BlackthornGym_Text_ClairWinText:
    .string "J'ai perdu ?\p"
    .string "Je n'y crois pas. Il doit y avoir\n"
    .string "une erreur…$"

BlackthornGym_Text_ClairText_GoToDragonsDen:
    .string "I won't admit this.\p"
    .string "I may have lost, but you're still\n"
    .string "not ready for the POKéMON LEAGUE.\p"
    .string "I know. You should take the dragon-\n"
    .string "user challenge.\p"
    .string "Behind this GYM is a place called\n"
    .string "DRAGON'S DEN.\p"
    .string "There is a small shrine at its\n"
    .string "center. Go there.\p"
    .string "If you can prove that you've lost\n"
    .string "your lazy ideals, I will recognize\l"
    .string "you as a trainer worthy of a GYM\l"
    .string "BADGE!$"

BlackthornGym_Text_ClairText_TooMuchToExpect:
    .string "Qu'est-ce qui ne va pas ?\p"
    .string "C'est trop demander de toi ?$"

BlackthornGym_Text_ClairText_YouKeptMeWaiting:
    .string "Tu m'as fait attendre !\p"
    .string "Tiens ! Prends ça !$"

BlackthornGym_Text_ClairText_DescribeTM:
    .string "Ça contient GRIFFE DRAGON.\p"
    .string "Tu peux deviner à quoi ça sert.$"

BlackthornGym_Text_ClairText_League:
    .string "Qu'est-ce qui\p"
    .string "se passe ?\n"
    .string "Tu ne vas pas à la\p"
    .string "LIGUE POKéMON ?\p"
    .string "Tu ne sais\p"
    .string "pas où c'est ?\n"
    .string "D'ici, va à\p"
    .string "BOURG PALETTE\n"
    .string "et suis la\p"
    .string "ROUTE 26.\n"
    .string "La LIGUE POKéMON\p"
    .string "t'attend !$"

BlackthornGym_Text_ClairAfterLeague:
    .string "Tu l'as fait, hein ?\p"
    .string "Tu es maintenant le CHAMPION DE JOHTO.$"

BlackthornGym_Text_ClairRematchText:
    .string "Tu l'as fait, hein ? Tu\p"
    .string "es maintenant le CHAMPION DE JOHTO.\p"
    .string "Tu as prouvé ta force, mais\n"
    .string "peux-tu me battre à nouveau ?\p"
    .string "En tant que Maître Dragon,\n"
    .string "je ne me retiendrai pas.\p"
    .string "Pas cette fois. Tu veux\p"
    .string "une revanche avec moi ?$"

BlackthornGym_Text_ClairRematchDefeatText:
    .string "J'ai perdu ?\p"
    .string "Encore ?\p"
    .string "Je n'y crois pas. Il doit y avoir\n"
    .string "une erreur…$"

BlackthornGym_Text_CooltrainermCodySeenText:
    .string "Je viens d'obtenir l'accès aux\n"
    .string "POKéMON de type DRAGON !$"

BlackthornGym_Text_CooltrainermCodyBeatenText:
    .string "Zut ! Si seulement j'avais un DRACOLOSSE !$"

BlackthornGym_Text_CooltrainermCodyAfterBattleText:
    .string "Les membres de notre clan d'utilisateurs de dragons\n"
    .string "ne peuvent utiliser des POKéMON Dragon qu'après\l"
    .string "l'autorisation de notre MAÎTRE.$"

BlackthornGym_Text_CooltrainerfFranSeenText:
    .string "Je ne peux pas laisser passer un DRESSEUR\n"
    .string "sans nom !\p"
    .string "IRIS serait furieuse si je le faisais !$"

BlackthornGym_Text_CooltrainerfFranBeatenText:
    .string "Snif… J'ai perdu…$"

BlackthornGym_Text_CooltrainerfFranAfterBattleText:
    .string "Oh-oh… IRIS va être furieuse…$"

BlackthornGym_Text_CooltrainermPaulSeenText:
    .string "Ton premier combat contre des dragons ?\p"
    .string "Je vais te montrer à quel point ils sont coriaces !$"

BlackthornGym_Text_CooltrainermPaulBeatenText:
    .string "Mon POKéMON dragon a perdu ?$"

BlackthornGym_Text_CooltrainermPaulAfterBattleText:
    .string "LANCE t'a dit qu'il aimerait te\n"
    .string "revoir ?\p"
    .string "Pas question !$"

BlackthornGym_Text_CooltrainermMikeSeenText:
    .string "Mes chances de perdre ? Pas même\n"
    .string "un pour cent !$"

BlackthornGym_Text_CooltrainermMikeBeatenText:
    .string "C'est bizarre.$"

BlackthornGym_Text_CooltrainermMikeAfterBattleText:
    .string "Je connais mes faiblesses maintenant.\p"
    .string "Merci de me les avoir montrées !$"

BlackthornGym_Text_CooltrainerfLolaSeenText:
    .string "Les dragons sont des POKéMON sacrés.\p"
    .string "Ils débordent d'énergie vitale. Si\p"
    .string "tu n'es pas sérieux, tu\n"
    .string "ne pourras pas les battre.$"

BlackthornGym_Text_CooltrainerfLolaBeatenText:
    .string "Bien joué !$"

BlackthornGym_Text_CooltrainerfLolaAfterBattleText:
    .string "Les dragons sont faibles contre les\n"
    .string "capacités de type DRAGON.$"

BlackthornGym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_BLACKTHORN_GYM, EcruteakCity_Gym_EventScript_GymGuy2
	msgbox BlackthornGym_Text_GuideText, MSGBOX_DEFAULT
	closemessage
	release
	end
	
BlackthornGym_EventScript_GymGuy2::
	msgbox BlackthornGym_Text_GuideWinText, MSGBOX_DEFAULT
	release
	end	

BlackthornGym_Text_GuideText:
    .string "Yo ! Futur CHAMPION !\p"
    .string "Ça a été un long voyage, mais on\n"
    .string "est presque au bout ! Compte sur moi !\p"
    .string "Bien que CLAIR admire le Maître\n"
    .string "Dragon LANCE, elle a réussi à\l"
    .string "créer sa propre identité avec une\l"
    .string "équipe de dragons de\l"
    .string "la mer.\p"
    .string "Les dragons sont censés être\n"
    .string "faibles contre les capacités de type GLACE,\l"
    .string "mais tu auras besoin de capacités de type\l"
    .string "DRAGON ou FÉE si tu veux gagner.\l"
    .string "Tu vas y arriver !$"

BlackthornGym_Text_GuideWinText:
    .string "Tu as été formidable en battant IRIS !\p"
    .string "Il ne reste plus que le défi de la\n"
    .string "LIGUE POKéMON.\p"
    .string "Tu es en route pour devenir\n"
    .string "le CHAMPION POKéMON !$"


BlackthornGym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_BLACKTHORN_GYM, BlackthornGym_EventScript_Statue2
	msgbox BlackthornGym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackthornGym_EventScript_Statue2::
	msgbox BlackthornGym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackthornGym_Text_GymStatue:
	.string "ARÈNE POKéMON D'EBENELLE$"

BlackthornGym_Text_GymStatueCertified:
	.string "EBÈNELLE ARENE POKéMON\p"
	.string "DRESSEURS CERTIFIÉS D'IRIS :\n"
	.string "{PLAYER}$"
