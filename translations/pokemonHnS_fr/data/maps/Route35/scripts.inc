Route35_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route35_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route35_OnTransition: 
	callnative SetTimeBasedEncounters
	end	

Route35_EventScript_CamperIvan::
	trainerbattle_single TRAINER_IVAN Route35_Text_CamperIvanSeen, Route35_Text_CamperIvanBeaten
	msgbox Route35_Text_CamperIvanAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_CamperElliot::
	trainerbattle_single TRAINER_ELLIOT Route35_Text_CamperElliotSeen, Route35_Text_CamperElliotBeaten
	msgbox Route35_Text_CamperElliotAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_PicnickerBrooke::
	trainerbattle_single TRAINER_BROOKE Route35_Text_PicnickerBrookeSeen, Route35_Text_PicnickerBrookeBeaten
	msgbox Route35_Text_PicnickerBrookeAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_PicnickerKim::
	trainerbattle_single TRAINER_KIM Route35_Text_PicnickerKimSeen, Route35_Text_PicnickerKimBeaten
	msgbox Route35_Text_PicnickerKimAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_BirdKeeperBryan::
	trainerbattle_single TRAINER_BRYAN Route35_Text_BirdKeeperBryanSeen, Route35_Text_BirdKeeperBryanBeaten
	msgbox Route35_Text_BirdKeeperBryanAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_JugglerIrwin::
	trainerbattle_single TRAINER_IRWIN Route35_Text_JugglerIrwinSeen, Route35_Text_JugglerIrwinBeaten
	msgbox Route35_Text_JugglerIrwinAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_BugCatcherArnie::
	trainerbattle_single TRAINER_ARNIE Route35_Text_BugCatcherArnieSeen, Route35_Text_BugCatcherArnieBeaten
	msgbox Route35_Text_BugCatcherArnieAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_FirebreatherWalt::
	trainerbattle_single TRAINER_WALT Route35_Text_FirebreatherWaltSeen, Route35_Text_FirebreatherWaltBeaten
	msgbox Route35_Text_FirebreatherWaltAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_PolicemanDirk::
	trainerbattle_single TRAINER_DIRK Route35_Text_OfficerDirkSeen, Route35_Text_OfficerDirkBeaten
	msgbox Route35_Text_OfficerDirkAfter, MSGBOX_AUTOCLOSE
	end

Route35_EventScript_Sign1::
	lock
	msgbox Route35_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route35_EventScript_Sign2::
	lock
	msgbox Route35_Text_Sign2, MSGBOX_SIGN
	closemessage
	release
	end

Route35_EventScript_Item_RockTomb::
	finditem ITEM_TM_ROCK_TOMB
	end

Route35_EventScript_Item_Nugget::
	finditem ITEM_BIG_NUGGET
	end

Route35_EventScript_Item_ParalyzeHeal::
	finditem ITEM_PARALYZE_HEAL
	end

Route35_Text_CamperIvanSeen:
	.string "Je récupère les données POKéMON sur\n"
	.string "ma radio. Je crois que je suis fort.$"

Route35_Text_CamperIvanBeaten:
	.string "J'abandonne !$"

Route35_Text_CamperIvanAfter:
	.string "La musique à la radio change\n"
	.string "l'humeur des POKéMON sauvages.$"

Route35_Text_CamperElliotSeen:
	.string "Je vais montrer à ma copine\n"
	.string "que je suis un dur !$"

Route35_Text_CamperElliotBeaten:
	.string "J'aurais aimé que tu perdes pour moi…$"

Route35_Text_CamperElliotAfter:
	.string "J'ai été humilié devant ma\n"
	.string "copine…$"

Route35_Text_PicnickerBrookeSeen:
	.string "Mon copain est faible, je ne peux pas\n"
	.string "compter sur lui.$"

Route35_Text_PicnickerBrookeBeaten:
	.string "Oh, mon Dieu ! Tu es si fort !$"

Route35_Text_PicnickerBrookeAfter:
	.string "Je peux compter sur mes POKéMON\n"
	.string "plus que sur mon copain.$"

Route35_Text_PicnickerKimSeen:
	.string "Tu vas à l'ARÈNE ? Moi aussi !$"

Route35_Text_PicnickerKimBeaten:
	.string "Oh. Je n'ai pas pu gagner…$"

Route35_Text_PicnickerKimAfter:
	.string "Les BADGES d'ARÈNE sont jolis.\n"
	.string "Je les collectionne.$"

Route35_Text_BirdKeeperBryanSeen:
	.string "Quels types de BALLS utilises-tu ?$"

Route35_Text_BirdKeeperBryanBeaten:
	.string "Aïe ! Pas assez rapide !$"

Route35_Text_BirdKeeperBryanAfter:
	.string "Certains POKéMON s'enfuient tout de suite.\p"
	.string "Essaie de les attraper avec la\n"
	.string "SPEED BALL de KURT.\p"
	.string "Chaque fois que je trouve une BAIE WILLIA,\n"
	.string "je l'apporte à KURT.\p"
	.string "Il en fait une BALL personnalisée.$"

Route35_Text_JugglerIrwinSeen:
	.string "Admire mon adresse avec les BALLS !$"

Route35_Text_JugglerIrwinBeaten:
	.string "Ouah ! Quelle secousse !$"

Route35_Text_JugglerIrwinAfter:
	.string "J'allais t'éblouir avec mes POKéMON\n"
	.string "chouchous.\p"
	.string "Mais ta prouesse m'a électrisé !$"

Route35_Text_BugCatcherArnieSeen:
	.string "J'irai n'importe où si des POKéMON\n"
	.string "insectes y apparaissent.$"

Route35_Text_BugCatcherArnieBeaten:
	.string "Hein ? Je n'aurais pas dû perdre…$"

Route35_Text_BugCatcherArnieAfter:
	.string "Mon MIMITOSS m'a fait gagner le Concours\n"
	.string "de Capture d'Insectes au PARC NATIONAL.$"

Route35_Text_BugCatcherArnieYanma:
	.string "Waouh… Regarde tous ces YANMA !\p"
	.string "Je suis tellement ébahi que je ne peux plus bouger.$"

Route35_Text_FirebreatherWaltSeen:
	.string "Je m'entraîne à cracher du feu.$"

Route35_Text_FirebreatherWaltBeaten:
	.string "Aïe ! Je me suis brûlé le bout du nez !$"

Route35_Text_FirebreatherWaltAfter:
	.string "La Marche POKéMON à la radio\n"
	.string "attire les POKéMON sauvages.$"

Route35_Text_OfficerDirkSeen:
	.string "Le danger rôde la nuit !$"

Route35_Text_OfficerDirkBeaten:
	.string "Oups !$"

Route35_Text_OfficerDirkAfter:
	.string "Tu sais, la nuit a son charme\n"
	.string "à sa manière.\p"
	.string "Mais n'en fais pas trop, OK ?$"

Route35_Text_OfficerDirkTough:
	.string "Tes POKéMON ont l'air costauds.\p"
	.string "Tu peux aller partout en sécurité.$"

Route35_Text_Sign:
	.string "ROUTE 35$"

Route35_Text_Sign2:
	.string "PORTE DU PARC NATUREL$"
