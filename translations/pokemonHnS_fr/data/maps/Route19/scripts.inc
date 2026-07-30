Route19_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route19_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route19_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route19_EventScript_Harold::
	trainerbattle_single TRAINER_HAROLD Route19_Text_SwimmermHaroldSeen, Route19_Text_SwimmermHaroldBeaten
	msgbox Route19_Text_SwimmermHaroldAfterBattle, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_Tucker::
	trainerbattle_single TRAINER_TUCKER Route19_Text_SwimmermTuckerSeen, Route19_Text_SwimmermTuckerBeaten
	msgbox Route19_Text_SwimmermTuckerAfterBattle, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_Dawn::
	trainerbattle_single TRAINER_DAWN Route19_Text_SwimmerfDawnSeen, Route19_Text_SwimmerfDawnBeaten
	msgbox Route19_Text_SwimmerfDawnAfterBattle, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_Jerome::
	trainerbattle_single TRAINER_JEROME Route19_Text_SwimmermJeromeSeen, Route19_Text_SwimmermJeromeBeaten
	msgbox Route19_Text_SwimmermJeromeAfterBattle, MSGBOX_AUTOCLOSE
	end

Route19_EventScript_Fatman::
	goto_if_unset FLAG_DEFEATED_CINNABAR_ISLAND_GYM, Route19_EventScript_FatmanBefore
	msgbox Route19_Text_Fisher1_RocksCleared, MSGBOX_NPC
	end

Route19_EventScript_FatmanBefore::
	msgbox Route19_Text_Fisher2, MSGBOX_NPC
	end

Route19_EventScript_Sign::
	msgbox Route19_Text_Sign, MSGBOX_SIGN
	end

Route19_EventScript_SwimSign::
	msgbox Route19_Text_CarefulSwimmingSign, MSGBOX_SIGN
	end

CherryGroveCity_EventScript_Kingler::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KINGLER, CRY_MODE_NORMAL
	msgbox Route19_Text_Kingler, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route19_EventScript_Fisher::
	goto_if_unset FLAG_DEFEATED_CINNABAR_ISLAND_GYM, Route19_EventScript_FisherBefore
	msgbox Route19_Text_Fisher2_RocksCleared, MSGBOX_NPC
	end

Route19_EventScript_FisherBefore::
	msgbox Route19_Text_FisherBefore, MSGBOX_NPC
	end

Route19_Text_SwimmermHaroldSeen:
	.string "As-tu déjà nagé dans la mer\n"
	.string "la nuit ?$"

Route19_Text_SwimmermHaroldBeaten:
	.string "Blub…$"

Route19_Text_SwimmermHaroldAfterBattle:
	.string "La nuit, la mer devient noire. On a l'impression\n"
	.string "qu'elle va t'avaler.$"

Route19_Text_SwimmermTuckerSeen:
	.string "Huff, huff… Plus que… un peu…\p"
	.string "encore… jusqu'à… SAFRANIA…$"

Route19_Text_SwimmermTuckerBeaten:
	.string "Je me noie !$"

Route19_Text_SwimmermTuckerAfterBattle:
	.string "J'ai… demandé à ma copine de nager\n"
	.string "jusqu'à SAFRANIA… Huff…$"

Route19_Text_SwimmerfDawnSeen:
	.string "Les faibles me dégoûtent !$"

Route19_Text_SwimmerfDawnBeaten:
	.string "Je pourrais te battre à la nage…$"

Route19_Text_SwimmerfDawnAfterBattle:
	.string "C'est une courte nage entre PARMANIE\n"
	.string "et les ÎLES ÉCUME...\p"
	.string "Pfff, quel grand homme fait mon copain !\n"
	.string "Quel mauviette !$"

Route19_Text_SwimmermJeromeSeen:
	.string "La natation ? Je suis nul.\p"
	.string "Je barbote juste dans ces\n"
	.string "eaux peu profondes.$"

Route19_Text_SwimmermJeromeBeaten:
	.string "Je pensais pouvoir gagner.$"

Route19_Text_SwimmermJeromeAfterBattle:
	.string "Je suis peut-être mauvais nageur, mais\n"
	.string "j'adore la mer.$"

Route19_Text_Fisher1:
	.string "Désolé. Cette route est fermée\n"
	.string "pour des travaux. Si tu\p"
	.string "veux aller à CRAMOIS'ÎLE, tu\n"
	.string "ferais mieux d'aller au\n"
	.string "sud depuis BOURG PALETTE.$"

Route19_Text_Kingler:
	.string "KRABBOSS : KEEEEEEEEEEEE$"

Route19_Text_Fisher1_RocksCleared:
	.string "Je suis tout en sueur. L'heure de nager !$"

Route19_Text_Fisher2:
	.string "Zut, KRABOSS bloque\n"
	.string "la plage.$"

Route19_Text_FisherBefore:
	.string "Pas de pêche tant que ces KRABOSS\n"
	.string "n'ont pas déguerpi.$"

Route19_Text_Fisher2_RocksCleared:
	.string "Ces KRABBOS sont enfin partis !\p"
	.string "Je peux de nouveau aller pêcher.$"

Route19_Text_Sign:
	.string "ROUTE 19\p"
	.string "PARMANIE - ÎLES CRAMOIS'ÎLE$"

Route19_Text_CarefulSwimmingSign:
	.string "Fais attention si tu nages vers\n"
	.string "les ÎLES ÉCUME.\p"
	.string "POLICE DE PARMANIE$"

