Route43_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route43_MapScript_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route43_MapScript_OnTransition::
	call_if_set FLAG_HIDE_ROUTE42_SUICUNE, Route42_MapScript_HideTrigger
	callnative SetTimeBasedEncounters
	end

Route43_EventScript_Ben::
	trainerbattle_single TRAINER_BEN Route43_Text_PokemaniacBenSeen, Route43_Text_PokemaniacBenBeaten
	msgbox Route43_Text_PokemaniacBenAfter, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_Brent::
	trainerbattle_single TRAINER_BRENT Route43_Text_PokemaniacBrentSeen, Route43_Text_PokemaniacBrentBeaten
	msgbox Route43_Text_PokemaniacBrentAfter, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_Ron::
	trainerbattle_single TRAINER_RON Route43_Text_PokemaniacRonSeen, Route43_Text_PokemaniacRonBeaten
	msgbox Route43_Text_PokemaniacRonAfter, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_Marvin::
	trainerbattle_single TRAINER_MARVIN Route43_Text_FisherMarvinSeen, Route43_Text_FisherMarvinBeaten
	msgbox Route43_Text_FisherMarvinAfter, MSGBOX_AUTOCLOSE
	end
	
Route43_EventScript_Spencer::
	trainerbattle_single TRAINER_SPENCER Route43_Text_CamperSpencerSeen, Route43_Text_CamperSpencerBeaten
	msgbox Route43_Text_CamperSpencerAfter, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_Tiffany::
	trainerbattle_single TRAINER_TIFFANY Route43_Text_PicnickerTiffanySeen, Route43_Text_PicnickerTiffanyBeaten
	msgbox Route43_Text_PicnickerTiffanyWantsPicnic, MSGBOX_AUTOCLOSE
	end

Route43_EventScript_Sign1::
	msgbox Route43_Sign2, MSGBOX_SIGN
	end

Route43_EventScript_Sign2::
	msgbox Route43_TrainerTips, MSGBOX_SIGN
	end

Route43_EventScript_Item_Max_Ether::
	finditem ITEM_MAX_ETHER
	end

Route43_Text_PokemaniacBenSeen:
    .string "J'adore les POKéMON !\p"
    .string "C'est pour ça que j'ai commencé, et c'est pourquoi je\n"
    .string "continuerai à collectionner des POKéMON !$"

Route43_Text_PokemaniacBenBeaten:
    .string "Comment as-tu pu me faire ça ?$"

Route43_Text_PokemaniacBenAfter:
    .string "Qu'est-ce que j'aime en dehors des\n"
    .string "POKéMON ?\p"
    .string "MARY à la radio. Je parie qu'elle\n"
    .string "est mignonne !$"

Route43_Text_PokemaniacBrentSeen:
    .string "Hé ! Tu as des POKéMON\n"
    .string "rares ?$"

Route43_Text_PokemaniacBrentBeaten:
    .string "Oh, mes pauvres POKéMON ! Chéris !$"

Route43_Text_PokemaniacBrentAfter:
    .string "Je serais heureux de posséder\n"
    .string "un seul POKéMON rare.$"

Route43_Text_PokemaniacRonSeen:
    .string "Tu crois ça ?\p"
    .string "Un type {RIVAL} s'est moqué de mon\n"
    .string "POKéMON !\p"
    .string "Mince ! Mon POKéMON est génial !$"

Route43_Text_PokemaniacRonBeaten:
    .string "Mon NIDOKING s'en est bien sorti !$"

Route43_Text_PokemaniacRonAfter:
    .string "C'est OK que les gens\n"
    .string "aiment différents types de POKéMON.\p"
    .string "Les POKéMON, ce n'est pas\n"
    .string "seulement avoir le plus puissant.$"

Route43_Text_FisherMarvinSeen:
    .string "Je suis dans une mauvaise passe.\p"
    .string "C'est peut-être l'équipement que j'utilise.\p"
    .string "Combattons pour changer d'air !$"

Route43_Text_FisherMarvinBeaten:
    .string "J'ai perdu, mais je me sens mieux quand même.$"

Route43_Text_FisherMarvinAfter:
    .string "La SAFARI BALL de KURT est la meilleure\n"
    .string "pour attraper les POKéMON ferrés.\p"
    .string "Elle est bien plus efficace qu'une\n"
    .string "HYPER BALL.$"

Route43_Text_CamperSpencerSeen:
    .string "Je peux faire tellement de choses\n"
    .string "avec mes POKéMON, c'est génial !$"

Route43_Text_CamperSpencerBeaten:
    .string "Perdre, ce n'est pas drôle du tout…$"

Route43_Text_CamperSpencerAfter:
    .string "Que se passe-t-il au LAC COLÈRE ?\p"
    .string "Nous prévoyions d'y camper.$"

Route43_Text_PicnickerTiffanySeen:
    .string "Tu vas aussi au LAC COLÈRE ?\p"
    .string "Jouons un peu !$"

Route43_Text_PicnickerTiffanyBeaten:
    .string "J'ai trop joué !$"

Route43_Text_PicnickerTiffanyWantsPicnic:
    .string "Je fais un pique-nique avec des POKéMON.\p"
    .string "Tu ne veux pas nous rejoindre ?$"

Route43_Sign1:
    .string "ROUTE 43\p"
    .string "LAC COLÈRE - ACAJOU$"

Route43_Sign2:
    .string "ROUTE 43\p"
    .string "LAC COLÈRE - ACAJOU$"

Route43_TrainerTips:
    .string "CONSEILS DRESSEUR Tous les POKéMON ont\p"
    .string "des avantages et inconvénients selon leurs\n"
    .string "types. Si leurs types diffèrent,\p"
    .string "un POKéMON de niveau supérieur\n"
    .string "peut perdre. Apprends quels types\p"
    .string "sont forts et faibles contre\n"
    .string "le type de tes POKéMON.$"
