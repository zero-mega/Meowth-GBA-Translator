Route44_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route44_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route44_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route44_EventScript_Wilton::
	trainerbattle_single TRAINER_WILTON Route44_Text_FisherWilton1Seen, Route44_Text_FisherWilton1Beaten
	msgbox Route44_Text_FisherWiltonHugePoliwag, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Edgar::
	trainerbattle_single TRAINER_EDGAR Route44_Text_FisherEdgarSeen, Route44_Text_FisherEdgarBeaten
	msgbox Route44_Text_FisherEdgarAfter, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Vance::
	trainerbattle_single TRAINER_VANCE Route44_Text_BirdKeeperVance1Seen, Route44_Text_BirdKeeperVance1Beaten
	msgbox Route44_Text_BirdKeeperVanceBirds, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Phil::
	trainerbattle_single TRAINER_PHIL Route44_Text_PsychicPhilSeen, Route44_Text_PsychicPhilBeaten
	msgbox Route44_Text_PsychicPhilAfter, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Zach::
	trainerbattle_single TRAINER_ZACH Route44_Text_PokemaniacZachSeen, Route44_Text_PokemaniacZachBeaten
	msgbox Route44_Text_PokemaniacZachAfter, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Allen::
	trainerbattle_single TRAINER_ALLEN Route44_Text_CooltrainermAllenSeen, Route44_Text_CooltrainermAllenBeaten
	msgbox Route44_Text_CooltrainermAllenAfter, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Cybil::
	trainerbattle_single TRAINER_CYBIL Route44_Text_CooltrainerfCybilSeen, Route44_Text_CooltrainerfCybilBeaten
	msgbox Route44_Text_CooltrainerfCybilAfter, MSGBOX_AUTOCLOSE
	end

Route44_EventScript_Sign1::
	msgbox Route44_Text_Sign1, MSGBOX_SIGN
	end

Route44_EventScript_Sign2::
	msgbox Route44_Text_Sign2, MSGBOX_SIGN
	end

Route44_EventScript_Item_MaxRepel::
	finditem ITEM_MAX_REPEL
	end

Route44_EventScript_Item_UltraBall::
	finditem ITEM_ULTRA_BALL
	end

Route44_EventScript_Item_Elixir::
	finditem ITEM_ELIXIR
	end

Route44_Text_FisherWilton1Seen:
    .string "Aïe !\p"
    .string "Tu m'as fait perdre un PTITARD !\n"
    .string "Qu'est-ce que tu vas faire ?$"

Route44_Text_FisherWilton1Beaten:
    .string "Oublie tout simplement.$"

Route44_Text_FisherWiltonHugePoliwag:
    .string "Ce TÊTARTE qui s'est échappé…\n"
    .string "il était énorme.\p"
    .string "Je jure qu'il devait faire\n"
    .string "5 mètres de long !$"

Route44_Text_FisherEdgarSeen:
    .string "Je pêche jusqu'à ne plus pouvoir.\p"
    .string "Je me bats aussi jusqu'à l'épuisement.\p"
    .string "C'est ma relation avec mes\n"
    .string "POKéMON.$"

Route44_Text_FisherEdgarBeaten:
    .string "Hmmmm… Ce n'est pas normal.$"

Route44_Text_FisherEdgarAfter:
    .string "C'est 100 victoires pour 101 défaites.\p"
    .string "Je ne me battrai plus pendant un moment.$"

Route44_Text_BirdKeeperVance1Seen:
    .string "Tu connais les légendaires\n"
    .string "POKéMON oiseaux ?$"

Route44_Text_BirdKeeperVance1Beaten:
    .string "Ouf ! Tu assures.$"

Route44_Text_BirdKeeperVanceBirds:
    .string "ARTIKODIN, ÉLECTHOR et SULFURA sont\n"
    .string "les trois POKéMON oiseaux légendaires.\p"
    .string "J'ai entendu dire qu'il y\n"
    .string "en avait d'autres, pourtant.$"

Route44_Text_PsychicPhilSeen:
    .string "Je vais gagner, c'est sûr !$"

Route44_Text_PsychicPhilBeaten:
    .string "Arrgh… Quelle défaite choquante…$"

Route44_Text_PsychicPhilAfter:
    .string "Il est important d'avoir la conviction\n"
    .string "de son côté.$"

Route44_Text_PokemaniacZachSeen:
    .string "Je ferais n'importe quoi pour mettre\n"
    .string "la main sur des POKéMON rares !$"

Route44_Text_PokemaniacZachBeaten:
    .string "Oooh, tes POKéMON sont si\n"
    .string "charmants.$"

Route44_Text_PokemaniacZachAfter:
    .string "Si un POKéMON a des couleurs différentes\n"
    .string "de l'habituel, il est plus précieux.\p"
    .string "Quoi ? Ce n'est pas vrai ?$"

Route44_Text_CooltrainermAllenSeen:
    .string "Je vois que tu es un bon DRESSEUR\n"
    .string "rien qu'en te regardant.\p"
    .string "Je suis doué avec les POKéMON, et je\n"
    .string "vois que toi aussi.$"

Route44_Text_CooltrainermAllenBeaten:
    .string "Tch ! C'est une défaite totale pour moi.$"

Route44_Text_CooltrainermAllenAfter:
    .string "Wow. Tu as beaucoup de BADGES.\p"
    .string "Pas étonnant que tu sois si fort.\p"
    .string "Je me demande si MORTIMER de l'ARÈNE\n"
    .string "de ROSALIA s'entraîne encore ?\p"
    .string "Il m'a vraiment écrasé.$"

Route44_Text_CooltrainerfCybilSeen:
    .string "Tu as l'air fort.\p"
    .string "Les bons DRESSEURS cherchent instinctivement\n"
    .string "des adversaires coriaces.$"

Route44_Text_CooltrainerfCybilBeaten:
    .string "Non ! Ça ne va pas du tout.$"

Route44_Text_CooltrainerfCybilAfter:
    .string "On s'améliore tous en vivant\n"
    .string "beaucoup de combats.\p"
    .string "J'ai beaucoup combattu pour devenir\n"
    .string "ce que je suis aujourd'hui : une élite.$"

Route44_Text_Sign1:
    .string "ROUTE 44\n"
    .string "GROTTE GLACE DEVANT$"

Route44_Text_Sign2:
    .string "ROUTE 44\p"
    .string "ACAJOU - EBENELLE$"

