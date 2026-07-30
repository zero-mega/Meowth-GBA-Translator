Route26_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route26_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route26_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route26_EventScript_Jake::
	trainerbattle_single TRAINER_JAKE Route26_Text_CooltrainermJakeSeen, Route26_Text_CooltrainermJakeBeaten
	msgbox Route26_Text_CooltrainermJakeAfter, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_Gaven::
	trainerbattle_single TRAINER_GAVEN Route26_Text_CooltrainermGavenSeen, Route26_Text_CooltrainermGavenBeaten
	msgbox Route26_Text_CooltrainermGavenAfter, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_Joyce::
	trainerbattle_single TRAINER_JOYCE Route26_Text_CooltrainerfJoyceSeen, Route26_Text_CooltrainerfJoyceBeaten
	msgbox Route26_Text_CooltrainerfJoyceAfter, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_Beth::
	trainerbattle_single TRAINER_BETH Route26_Text_CooltrainerfBethSeen, Route26_Text_CooltrainerfBethBeaten
	msgbox Route26_Text_CooltrainerfBethAfter, MSGBOX_AUTOCLOSE
	end

Route26_EventScript_Richard::
	trainerbattle_single TRAINER_RICHARD Route26_Text_PsychicRichardSeen, Route26_Text_PsychicRichardBeaten
	msgbox Route26_Text_PsychicRichardAfter, MSGBOX_AUTOCLOSE
	end

Route26_Text_CooltrainermJakeSeen:
    .string "Je fais mes préparatifs finaux\n"
    .string "pour la LIGUE POKéMON.$"

Route26_Text_CooltrainermJakeBeaten:
    .string "J'ai tout gâché !$"

Route26_Text_CooltrainermJakeAfter:
    .string "Ça va être dur de gagner à\n"
    .string "la LIGUE.\p"
    .string "Il faut que je m'entraîne encore.\p"
    .string "J'ai entendu dire que le CONSEIL DES 4\n"
    .string "de la LIGUE est plus fort que les CHAMPIONS D'ARÈNE.$"

Route26_Text_CooltrainermGavenSeen:
    .string "En vivant des combats difficiles, tu\n"
    .string "gagnes en puissance.$"

Route26_Text_CooltrainermGavenBeaten:
    .string "Gaah ! La vie est encore plus dure !$"

Route26_Text_CooltrainermGavenAfter:
    .string "Pour aller à la LIGUE POKéMON,\n"
    .string "il faut traverser la ROUTE VICTOIRE.\p"
    .string "Mais la ROUTE VICTOIRE est dure.\p"
    .string "Pratiquement personne n'y va !$"

Route26_Text_CooltrainerfJoyceSeen:
    .string "Puisque tu es arrivé jusqu'ici,\n"
    .string "tu dois être fort.\p"
    .string "Je vais donner tout ce que j'ai\n"
    .string "dans ce combat !$"

Route26_Text_CooltrainerfJoyceBeaten:
    .string "Non ! Je n'y crois pas !$"

Route26_Text_CooltrainerfJoyceAfter:
    .string "J'ai battu huit CHAMPIONS D'ARÈNE,\n"
    .string "alors j'étais confiant.\p"
    .string "Il faudra que j'essaie plus fort la prochaine fois.$"

Route26_Text_CooltrainerfBethSeen:
    .string "J'ai perdu contre un Dresseur nommé {RIVAL}.\p"
    .string "Il était vraiment fort, mais…\p"
    .string "C'était comme s'il devait absolument\n"
    .string "gagner à tout prix.\p"
    .string "J'ai eu pitié de ses POKéMON.$"

Route26_Text_CooltrainerfBethBeaten:
    .string "Les POKéMON ne sont pas des outils de guerre.$"

Route26_Text_CooltrainerfBethAfter:
    .string "Les POKéMON sont des partenaires\n"
    .string "précieux pour la vie.$"

Route26_Text_PsychicRichardSeen:
    .string "Waouh, regarde tous ces BADGES !\n"
    .string "Je suis impressionné.\p"
    .string "Mais tu n'es pas satisfait de simplement\n"
    .string "les collectionner, n'est-ce pas ?$"

Route26_Text_PsychicRichardBeaten:
    .string "Bon combat !$"

Route26_Text_PsychicRichardAfter:
    .string "Les gens et les POKéMON grandissent grâce à leurs\n"
    .string "expériences.\p"
    .string "Ne deviens pas paresseux et complaisant.$"

Route26_Text_Sign:
    .string "ROUTE 26\p"
    .string "LIGUE POKéMON\n"
    .string "PORTE D'ACCUEIL$"

