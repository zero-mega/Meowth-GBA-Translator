EcruteakCity_House2_MapScripts::
	.byte 0

Ecruteak_Text_ItemfinderAdventure:
	.string "Ah. Tu es en aventure avec\n"
	.string "tes POKéMON ?\p"
	.string "Eh bien, qu'est-ce qu'une aventure sans\n"
	.string "chasse au trésor ?\p"
	.string "J'ai raison, ou j'ai raison ?$"

Ecruteak_Text_ItemfinderTrueSpirit:
	.string "Bien ! Tu comprends le vrai\n"
	.string "esprit de l'aventure.\p"
	.string "J'aime ça ! Prends ceci.$"

Ecruteak_Text_ItemfinderExplanation:
	.string "Il y a beaucoup\n"
	.string "d'objets éparpillés\p"
	.string "qui ne sont pas évidents.\n"
	.string "Utilise le CHERCH'OBJET\p"
	.string "pour vérifier s'il y a\n"
	.string "un objet caché à proximité.\p"
	.string "Tu pourrais trouver\n"
	.string "des trésors !$"

Ecruteak_Text_ItemfinderToEachHisOwn:
	.string "Oh… Chacun ses goûts, je suppose…$"

EcruteakCity_House2_EventScript_ItemFinderMan::
	lock
	faceplayer
	msgbox Ecruteak_Text_ItemFinderMan, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_House2_EventScript_Book::
	lock
	msgbox Ecruteak_Text_HistoryBook, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, EcruteakCity_House2_EventScript_Book2
	closemessage
	release
	end

EcruteakCity_House2_EventScript_Book2::
	msgbox Ecruteak_Text_TwoTowers, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, EcruteakCity_House2_EventScript_Book3
	release
	end

EcruteakCity_House2_EventScript_Book3::
	msgbox Ecruteak_Text_ThreeMon, MSGBOX_DEFAULT
	closemessage
	release
	end

Ecruteak_Text_ItemFinderMan::
	.string "ROSALIA est une ville très ancienne.\n"
	.string "De nombreuses générations ont transmis\l"
	.string "leur histoire dans des livres comme ceux-ci.$"

Ecruteak_Text_HistoryBook:
	.string "HISTOIRE DE ROSALIA\p"
	.string "Tu veux la lire ?$"

Ecruteak_Text_TwoTowers:
	.string "Dans ECRUTEAK, là étaient deux\p"
	.string "towers. Each tower était\n"
	.string "le roost de powerful\p"
	.string "flying POKéMON. Mais un\n"
	.string "de le towers burned\p"
	.string "à le ground. Le\n"
	.string "deux POKéMON haven't été\p"
	.string "seen since… Keep reading?$"

Ecruteak_Text_ThreeMon:
	.string "ROSYÈRES abritait\n"
	.string "aussi trois\p"
	.string "POKéMON qui couraient\n"
	.string "dans la ville.\p"
	.string "On dit qu'ils\n"
	.string "ont été bénis\p"
	.string "par les dieux.\n"
	.string "C'est une belle légende.$"
