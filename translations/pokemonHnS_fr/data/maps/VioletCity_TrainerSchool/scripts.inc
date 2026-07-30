VioletCity_TrainerSchool_MapScripts::
	.byte 0

VioletCity_TrainerSchool_EventScript_Earl::
	lock
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_EarlIntro, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_EventScript_Teacher::
	lock
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_Teacher, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_EventScript_Boy1::
	lock
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_GameboyKid1, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_EventScript_Boy2::
	lock
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_GameboyKid2, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_EventScript_Kid::
	lock
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_Youngster1, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_EventScript_Girl::
	lock
	faceplayer
	msgbox VioletCity_TrainerSchool_Text_Youngster2, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_EventScript_Twin::
	msgbox VioletCity_TrainerSchool_Text_Twin, MSGBOX_NPC
	end

VioletCity_TrainerSchool_EventScript_BlackBoard::
	lock
	msgbox VioletCity_TrainerSchool_Text_Blackboard, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_TrainerSchool_Text_Twin:
	.string "Je ne suis pas un gamin GBA, mais j'adore\n"
	.string "jouer aux jeux POKéMON !\p"
	.string "Dans les anciens jeux, il fallait combattre\n"
	.string "beaucoup de POKéMON sauvages pour avoir assez\l"
	.string "d'EXP.\p"
	.string "Mais dans les jeux plus récents, le MULTI EXP\n"
	.string "faisait monter de niveau tes POKéMON trop vite.\p"
	.string "Dans ce jeu, le MULTI EXP est\n"
	.string "équilibré pour mettre tes POKéMON au bon\l"
	.string "niveau. Ou légèrement plus\l"
	.string "haut, selon tes combats.\p"
	.string "Si tu veux une expérience traditionnelle GEN 1-4,\n"
	.string "désactive le MULTI EXP.\l"
	.string "Si tu veux une expérience moderne,\l"
	.string "active le MULTI EXP.\p"
	.string "Tu choisis comment tu veux jouer !$"

VioletCity_TrainerSchool_Text_EarlIntro:
	.string "BOSS, je suis !\p"
	.string "Merveilleux sont les POKéMON, oui !\p"
	.string "Mieux te former je vais pour être un\n"
	.string "meilleur dresseur !$"

VioletCity_TrainerSchool_Text_Teacher:
	.string "Certains POKéMON\n"
	.string "commencent\l"
	.string "faibles et\p"
	.string "requièrent\n"
	.string "beaucoup\l"
	.string "plus d'EXP\l"
	.string "pour devenir\p"
	.string "forts que d'autres.\n"
	.string "Choisis ton équipe\l"
	.string "avec soin !$"

VioletCity_TrainerSchool_Text_TeachHowToWin:
	.string "Bien ! Je vais t'apprendre !\p"
	.string "Au combat, le POKéMON en haut\n"
	.string "de la liste sort en premier !\p"
	.string "Change l'ordre dans la liste,\n"
	.string "le combat sera peut-être plus facile !\p"
	.string "Tu veux en entendre plus ?$"

VioletCity_TrainerSchool_Text_TeachMore:
	.string "Alors, tu veux savoir comment bien\n"
	.string "élever des POKéMON ?$"

VioletCity_TrainerSchool_Text_TeachRaiseWell:
	.string "D'accord ! Je vais t'apprendre !\p"
	.string "Si un POKéMON sort au\n"
	.string "combat même brièvement, il gagne\p"
	.string "des points d'EXP. Mets les\n"
	.string "POKéMON faibles en haut de\p"
	.string "la liste ! Change-les vite\n"
	.string "en combat ! Comme ça,\p"
	.string "les faibles deviennent forts !$"

VioletCity_TrainerSchool_Text_NoMoreToTeach:
	.string "Oh ! Tu es un élève intelligent !\n"
	.string "Je n'ai plus rien à t'enseigner !\p"
	.string "Si tu veux en savoir plus, parle aux\n"
	.string "autres élèves !$"

VioletCity_TrainerSchool_Text_Youngster1:
	.string "Les POKéMON qu'on\n"
	.string "pensait n'évoluer\p"
	.string "que par\n"
	.string "échange peuvent\p"
	.string "évoluer en\n"
	.string "montant de niveau.\p"
	.string "MACHOPEUR et KADABRA\n"
	.string "en font partie.\p"
	.string "C'est une découverte\n"
	.string "récente !$"

VioletCity_TrainerSchool_Text_GameboyKid1:
	.string "Les POKéMON notables disponibles dans une\n"
	.string "zone peuvent être vus dans le\p"
	.string "monde ! Mais vérifie les routes\n"
	.string "le JOUR et la NUIT !$"

VioletCity_TrainerSchool_Text_GameboyKid2:
	.string "Les BAIES de la région de JOHTO\n"
	.string "sont bonnes pour soigner et fabriquer des\p"
	.string "BALLS. Les BAIES de KANTO servent\n"
	.string "à réduire les stats d'un POKéMON.\p"
	.string "Le DOJO de KANTO aide les\n"
	.string "POKéMON à perfectionner leurs stats individuelles.$"

VioletCity_TrainerSchool_Text_Youngster2:
	.string "Attention, tes adversaires utilisent désormais des\n"
	.string "équipes avec une meilleure couverture\l"
	.string "de types, alors attends-toi à\l"
	.string "un parcours bien plus difficile.$"

VioletCity_TrainerSchool_Text_Blackboard:
	.string "Le tableau noir décrit les\n"
	.string "capacités CS des POKéMON.\p"
	.string "Les CS, une fois débloquées, n'ont pas\n"
	.string "besoin d'être enseignées pour être utilisées.$"

VioletCity_TrainerSchool_Text_Notebook:
	.string "C'est le carnet de ce gamin...\p"
	.string "Attrape des POKéMON avec des POKé BALLS.\p"
	.string "Jusqu'à six peuvent être dans ton équipe.\p"
	.string "Continuer la lecture ?$"

VioletCity_TrainerSchool_Text_Notebook1:
	.string "Avant de lancer une POKé\n"
	.string "BALL, affaiblis d'abord la cible.\p"
	.string "Un POKéMON empoisonné ou brûlé\n"
	.string "est plus facile à attraper.\p"
	.string "Continuer à lire ?$"

VioletCity_TrainerSchool_Text_Notebook2:
	.string "Certaines capacités peuvent provoquer la confusion.\p"
	.string "La confusion peut faire qu'un POKéMON\n"
	.string "s'attaque lui-même.\p"
	.string "Quitter le combat dissipe toute\n"
	.string "confusion.\p"
	.string "Continuer à lire ?$"

VioletCity_TrainerSchool_Text_Notebook3:
	.string "Les gens qui\n"
	.string "attrapent et utilisent\n"
	.string "des POKéMON au\p"
	.string "combat sont des\n"
	.string "DRESSEURS POKéMON. On\n"
	.string "attend d'eux qu'ils\p"
	.string "visitent les ARÈNES\p"
	.string "et affrontent les\p"
	.string "CHAMPIONS d'ARÈNE.$"

VioletCity_TrainerSchool_Text_StickerMachine:
	.string "Cette super machine imprime des données\n"
	.string "sous forme d'autocollants !$"
