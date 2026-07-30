Route13_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route13_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route13_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route13_EventScript_Alex::
	trainerbattle_single TRAINER_ALEX Route13_Text_PokefanmAlexSeen, Route13_Text_PokefanmAlexBeaten
	msgbox Route13_Text_PokefanmAlexAfterBattle, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_Joshua::
	trainerbattle_single TRAINER_JOSHUA Route13_Text_PokefanmJoshuaSeen, Route13_Text_PokefanmJoshuaBeaten
	msgbox Route13_Text_PokefanmJoshuaAfterBattle, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_Perry::
	trainerbattle_single TRAINER_PERRY Route13_Text_BirdKeeperPerrySeen, Route13_Text_BirdKeeperPerryBeaten
	msgbox Route13_Text_BirdKeeperPerryAfterBattle, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_Bret::
	trainerbattle_single TRAINER_BRET Route13_Text_BirdKeeperBretSeen, Route13_Text_BirdKeeperBretBeaten
	msgbox Route13_Text_BirdKeeperBretAfterBattle, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_Kenny::
	trainerbattle_single TRAINER_KENNY Route13_Text_HikerKennySeen, Route13_Text_HikerKennyBeaten
	msgbox Route13_Text_HikerKennyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route13_EventScript_TrainerTips::
	msgbox Route13_Text_TrainerTips, MSGBOX_SIGN
	end

Route13_EventScript_RouteSign::
	msgbox Route13_Text_Sign, MSGBOX_SIGN
	end

Route13_EventScript_DirectionsSign::
	msgbox Route13_Text_DirectionsSign, MSGBOX_SIGN
	end

Route13_Text_PokefanmAlexSeen:
	.string "Prosterne-toi devant mes POKéMON royaux !$"

Route13_Text_PokefanmAlexBeaten:
	.string "Comment… Comment oses-tu te moquer de la royauté !$"

Route13_Text_PokefanmAlexAfterBattle:
	.string "Tout le monde ne rêve-t-il pas\n"
	.string "d'être roi un jour ?$"

Route13_Text_PokefanmJoshuaSeen:
	.string "Nihihi ! Veux-tu combattre\n"
	.string "ma bande de PIKACHU ?$"

Route13_Text_PokefanmJoshuaBeaten:
	.string "PI-PIKACHU !$"

Route13_Text_PokefanmJoshuaAfterBattle:
	.string "Tu as l'air d'avoir beaucoup de\n"
	.string "POKéMON, mais PIKACHU\l"
	.string "est toujours le meilleur.$"

Route13_Text_BirdKeeperPerrySeen:
	.string "L'agilité est l'atout principal des\n"
	.string "POKéMON oiseaux.$"

Route13_Text_BirdKeeperPerryBeaten:
	.string "Tu m'as battu avec ta vitesse…$"

Route13_Text_BirdKeeperPerryAfterBattle:
	.string "Tes POKéMON sont remarquablement\n"
	.string "bien entraînés.$"

Route13_Text_BirdKeeperBretSeen:
	.string "Regarde mes POKéMON. Regarde juste\n"
	.string "leur coloration et leur\l"
	.string "plumage.$"

Route13_Text_BirdKeeperBretBeaten:
	.string "Zut ! Pas assez bon !$"

Route13_Text_BirdKeeperBretAfterBattle:
	.string "Si tu les brosses, les POKéMON\n"
	.string "deviennent heureux.$"

Route13_Text_HikerKennySeen:
	.string "Je devrais aller à la GROTTE pour\n"
	.string "capturer un ONIX.$"

Route13_Text_HikerKennyBeaten:
	.string "J'ai perdu…$"

Route13_Text_HikerKennyAfterBattle:
	.string "Les formations géologiques ne semblent pas\n"
	.string "changer.\p"
	.string "Mais elles changent en réalité, petit\n"
	.string "à petit.$"

Route13_Text_TrainerTips:
	.string "CONSEILS DRESSEUR\p"
	.string "Regarde ! Juste là, sur le côté\n"
	.string "gauche du poteau.$"

Route13_Text_Sign:
	.string "ROUTE 13\p"
	.string "NORD VERS PONT DU SILENCE$"

Route13_Text_DirectionsSign:
	.string "NORD VERS LAVANDON\p"
	.string "OUEST VERS CRAMOIS'ÎLE$"

