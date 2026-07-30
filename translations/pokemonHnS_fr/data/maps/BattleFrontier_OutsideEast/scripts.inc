.set LOCALID_SUDOWOODO, 14

BattleFrontier_OutsideEast_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_OutsideEast_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideEast_OnTransition
	.byte 0

BattleFrontier_OutsideEast_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo
	end

BattleFrontier_OutsideEast_EventScript_TryRemoveSudowoodo::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

BattleFrontier_OutsideEast_OnTransition:
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	call_if_unset FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_ShowSudowoodo
	end

BattleFrontier_OutsideEast_EventScript_ShowSudowoodo::
	clearflag FLAG_HIDE_BATTLE_FRONTIER_SUDOWOODO
	return

BattleFrontier_OutsideEast_EventScript_BattleTowerSign::
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattlePalaceSign::
	msgbox BattleFrontier_OutsideEast_Text_BattlePalaceSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattleArenaSign::
	msgbox BattleFrontier_OutsideEast_Text_BattleArenaSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_BattlePyramidSign::
	msgbox BattleFrontier_OutsideEast_Text_BattlePyramidSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_NinjaBoy::
	msgbox BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man1::
	msgbox BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Hiker::
	msgbox BattleFrontier_OutsideEast_Text_PyramidTooHarsh, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_HexManiac::
	msgbox BattleFrontier_OutsideEast_Text_ThriveInDarkness, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_BlackBelt1::
	msgbox BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Cook::
	lock
	msgbox BattleFrontier_OutsideEast_Text_BelieveInYouBuddy, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Engineer5::
	msgbox BattleFrontier_OutsideWest_Text_Reparations5, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Engineer6::
	msgbox BattleFrontier_OutsideWest_Text_Reparations6, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Engineer7::
	msgbox BattleFrontier_OutsideWest_Text_Reparations7, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Engineer8::
	msgbox BattleFrontier_OutsideWest_Text_Reparations8, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_Text_Reparations5:
	.string "On a presque fini les réparations.\p"
	.string "MACKOGNEUR a été d'une grande aide\n"
	.string "pour soulever les rochers les plus lourds.$"

BattleFrontier_OutsideWest_Text_Reparations6:
    .string "Attention où tu mets les pieds\n"
    .string "! Le sol est encore instable\p"
    .string "ici. Heureusement que l'équipe de MACHOPEUR\n"
    .string "nous aide à déblayer les débris.$"

BattleFrontier_OutsideWest_Text_Reparations7:
    .string "Ces ponts de bois sont le seul moyen\n"
    .string "de traverser pendant les réparations.$"

BattleFrontier_OutsideWest_Text_Reparations8:
    .string "La grotte est encore instable, alors on a construit\n"
    .string "des ponts en bois temporaires.\p"
    .string "Ils sont solides… je crois.$"

BattleFrontier_OutsideEast_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant, MSGBOX_DEFAULT
	waitmoncry
	release
	end

BattleFrontier_OutsideEast_EventScript_RichBoy::
	msgbox BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_ExpertF::
	msgbox BattleFrontier_OutsideEast_Text_OnceBeatGymLeader, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_TriathleteF::
	msgbox BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Twin::
	msgbox BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man2::
	lock
	msgbox BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_TriathleteM::
	msgbox BattleFrontier_OutsideEast_Text_DidScottBringYouHere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Sudowoodo::
	lock
	faceplayer
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake
	waitmovement 0
	release
	end

BattleFrontier_OutsideEast_EventScript_WaterSudowoodo::
	lock
	faceplayer
	special DoWateringBerryTreeAnim
	waitstate
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_SUDOWOODO, BattleFrontier_OutsideEast_Movement_SudowoodoShake
	waitmovement 0
	msgbox gText_Sudowoodo_Attacked, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_SUDOWOODO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_SUDOWOODO
	setwildbattle SPECIES_SUDOWOODO, 40
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo
	setflag FLAG_DEFEATED_SUDOWOODO
	release
	end

BattleFrontier_OutsideEast_EventScript_DefeatedSudowoodo::
	setflag FLAG_DEFEATED_SUDOWOODO
	goto Common_EventScript_RemoveStaticPokemon
	end

BattleFrontier_OutsideEast_Movement_SudowoodoShake:
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	step_end

BattleFrontier_OutsideEast_EventScript_Maniac1::
	msgbox BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Girl::
	msgbox BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_PsychicM::
	msgbox BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Man3::
	msgbox BattleFrontier_OutsideEast_Text_GotWipedOut, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Woman1::
	msgbox BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Woman2::
	msgbox BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_BlackBelt2::
	msgbox BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_Maniac2::
	lock
	msgbox BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Woman3::
	lock
	msgbox BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_RankingHallSign::
	msgbox BattleFrontier_OutsideEast_Text_RankingHallSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_ExchangeCornerSign::
	msgbox BattleFrontier_OutsideEast_Text_ExchangeCornerSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideEast_EventScript_Gentleman::
	msgbox BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_EventScript_OldWoman::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SUDOWOODO, BattleFrontier_OutsideEast_EventScript_OldWomanSudowoodoGone
	msgbox BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_OldWomanSudowoodoGone::
	msgbox BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideEast_EventScript_Camper::
	msgbox BattleFrontier_OutsideEast_Text_StickyMonWithLongTail, MSGBOX_NPC
	end

BattleFrontier_OutsideEast_Text_BattleTowerSign:
	.string "C'est la TOUR DE COMBAT !\n"
	.string "Garde ta série de victoires en tant que\l"
	.string "DRESSEUR le plus coriace !$"

BattleFrontier_OutsideEast_Text_BattlePalaceSign:
	.string "C'est le PALAIS DE COMBAT !\n"
	.string "Garde les yeux sur les combats POKéMON !$"

BattleFrontier_OutsideEast_Text_BattleArenaSign:
	.string "C'est l'ARÈNE DE COMBAT !\n"
	.string "Que les équipes les plus coriaces se rassemblent !$"

BattleFrontier_OutsideEast_Text_BattlePyramidSign:
	.string "C'est la PYRAMIDE DE COMBAT !\n"
	.string "Avance dans la Quête de Combat !$"

BattleFrontier_OutsideEast_Text_RankingHallSign:
	.string "HALL DU CLASSEMENT DE LA ZONE DE COMBAT\n"
	.string "Vise de nouveaux records !$"

BattleFrontier_OutsideEast_Text_ExchangeCornerSign:
	.string "SERVICE D'ÉCHANGE DE POINTS DE COMBAT\n"
	.string "Échange tes Points de Combat et\l"
	.string "échange avec d'autres DRESSEURS !$"

BattleFrontier_OutsideEast_Text_BattleTowerFeelsSpecial:
	.string "Ouah !\n"
	.string "C'est énorme !\p"
	.string "La TOUR DE COMBAT a une ambiance spéciale.\n"
	.string "Elle est différente des autres.$"

BattleFrontier_OutsideEast_Text_ConquerLeagueAndFrontier:
	.string "Ma grande ambition est de conquérir\n"
	.string "la ZONE DE COMBAT et la LIGUE\l"
	.string "POKéMON.\p"
	.string "Et si mon rêve se réalise…\p"
	.string "Je… Je vais demander à MIMI d'à côté\n"
	.string "si elle veut être mon amie !$"

BattleFrontier_OutsideEast_Text_PyramidTooHarsh:
	.string "La PYRAMIDE DE COMBAT est trop dure !\n"
	.string "Je n'arrive pas à atteindre le sommet !\p"
	.string "Comme je n'ai plus d'options,\n"
	.string "je vais peut-être grimper par l'extérieur…$"

BattleFrontier_OutsideEast_Text_ThriveInDarkness:
	.string "Je m'épanouis dans l'obscurité…\n"
	.string "Oui… Qu'est-ce qui me convient ?\l"
	.string "Rien d'autre que la PYRAMIDE DE COMBAT…\p"
	.string "Que dirais-tu d'errer dans l'obscurité\n"
	.string "dans le désespoir le plus total ?$"

BattleFrontier_OutsideEast_Text_PutTogetherUltimateTeam:
	.string "Je n'ai pas dormi pendant une semaine,\n"
	.string "mais j'ai monté l'équipe ultime !\p"
	.string "Je ne me vois pas perdre, sans blague.\n"
	.string "On va déferler sur l'ARÈNE DE COMBAT !$"

BattleFrontier_OutsideEast_Text_DidScottBringYouHere:
	.string "SCOTT t'a amené ici aussi\p"
	.string "? Non ? Mais tu\p"
	.string "le connais sûrement ! Qu'est-ce\p"
	.string "que c'est avec ce type\p"
	.string "? On dirait qu'il sait\n"
	.string "vraiment repérer les DRESSEURS talentueux,\p"
	.string "mais… Je ne l'ai jamais\n"
	.string "vu combattre en personne.$"

BattleFrontier_OutsideEast_Text_BelieveInYouBuddy:
	.string "ZIGG ! Je crois en toi,\n"
	.string "petit ! Je ferai toutes les\p"
	.string "friandises que tu veux à mon\n"
	.string "petit ZIGG si tu gagnes !$"

BattleFrontier_OutsideEast_Text_ZigzagoonLooksVacant:
	.string "ZIGZATON a l'air absent…$"

BattleFrontier_OutsideEast_Text_PeopleCallMeBusybody:
	.string "Les gens m'appellent un fouteur\n"
	.string "de trouble, mais je ne\p"
	.string "peux pas m'en empêcher. Ton\n"
	.string "chapeau est de travers !\l"
	.string "Oh non, des déchets par\p"
	.string "terre ! Fais attention\n"
	.string "à ton apparence !$"

BattleFrontier_OutsideEast_Text_OnceBeatGymLeader:
	.string "Je ne fais peut-être pas très\n"
	.string "fortune, mais j'ai battu un CHAMPION D'ARÈNE.\p"
	.string "Qui sait, je devrais peut-être\n"
	.string "retenter ma chance pour la gloire.$"

BattleFrontier_OutsideEast_Text_FastOnBikeAndBattles:
	.string "Je suis rapide sur mon VÉLO, et c'est pareil\n"
	.string "pour mes combats aussi.\p"
	.string "Je gagne des matchs\n"
	.string "en un clin d'œil !$"

BattleFrontier_OutsideEast_Text_BetterThanDaddyAtPokemon:
	.string "Je suis meilleur que mon papa\n"
	.string "aux POKéMON.$"

BattleFrontier_OutsideEast_Text_GoRackUpSomeWinsForDaddy:
	.string "Allez, mon chéri ! Gagne\n"
	.string "des victoires pour papa !\p"
	.string "Tu es comme ta mère,\n"
	.string "tu vas dominer !$"

BattleFrontier_OutsideEast_Text_HeardPrettyGirlAtBattleArena:
	.string "Ce n'était pas facile d'arriver ici,\n"
	.string "mais j'avais entendu parler d'une jolie\l"
	.string "fille à l'ARÈNE DE COMBAT.\p"
	.string "Au lieu d'elle, tu sais\n"
	.string "ce que j'ai trouvé ?\p"
	.string "Une foule entière d'artistes martiaux\n"
	.string "transpirants, malodorants et primitifs !$"

BattleFrontier_OutsideEast_Text_SometimesImportantOldManInThere:
	.string "Je vois parfois un vieil homme très\n"
	.string "important entrer là-dedans.\p"
	.string "Il a des POKéMON vraiment formidables.\n"
	.string "Il a l'air très sympa, pourtant.$"

BattleFrontier_OutsideEast_Text_LegendOfBattlePyramid:
	.string "Tu le connais ?\n"
	.string "La légende de la\p"
	.string "PYRAMIDE DE\n"
	.string "COMBAT ?\l"
	.string "Quand vient un\p"
	.string "DRESSEUR confiant\n"
	.string "atteignant\l"
	.string "le sommet…\p"
	.string "La gloire\n"
	.string "l'attend !$"

BattleFrontier_OutsideEast_Text_GotWipedOut:
	.string "Mince ! Oh mince !\n"
	.string "Je n'avais jamais perdu avant !\p"
	.string "Mais j'ai été balayé sans aucune\n"
	.string "chance de sauver !\p"
	.string "Et puis on me dit que je n'ai aucun\n"
	.string "talent ?! Mince !$"

BattleFrontier_OutsideEast_Text_ToughTrainerInBattleTower:
	.string "Ce type a croisé un DRESSEUR terriblement\n"
	.string "fort pendant son défi à la\l"
	.string "TOUR DE COMBAT.\p"
	.string "Regarde-le maintenant…\p"
	.string "Il faut être prudent si tu décides\n"
	.string "d'aller à la TOUR DE COMBAT.$"

BattleFrontier_OutsideEast_Text_EnoughBattlePointsForDoll:
	.string "Oui !\n"
	.string "J'ai enfin assez de Points de Combat !\p"
	.string "Je vais m'échanger contre une autre\n"
	.string "POKé POUPÉE géante !$"

BattleFrontier_OutsideEast_Text_LikeToHaveNameRecordedHere:
	.string "Oh, oui, d'accord !\n"
	.string "Alors voici le PANTHÉON DES CHAMPIONS !\p"
	.string "J'aimerais entrer dans l'histoire comme\n"
	.string "un super champion et voir mon nom\l"
	.string "enregistré ici pour la postérité.$"

BattleFrontier_OutsideEast_Text_CanDoAnythingWithYou:
	.string "Avec toi à mes côtés, je peux tout faire.$"

BattleFrontier_OutsideEast_Text_PowerOfOurLoveWillOvercome:
	.string "Ooh, chéri,\p"
	.string "tu es\p"
	.string "si merveilleux !\n"
	.string "Ooh, je n'en peux\p"
	.string "plus d'attendre !\n"
	.string "Allons dans\l"
	.string "une SALLE\p"
	.string "DE COMBAT MULTI !\n"
	.string "Ce sera amusant !$"

BattleFrontier_OutsideEast_Text_FrontierNotExclusivelyForToughTrainers:
	.string "Le PARC DES COMBATS\n"
	.string "n'est pas réservé aux\p"
	.string "DRESSEURS coriaces. Beaucoup de\n"
	.string "gens aux talents spéciaux\p"
	.string "y participent aussi.\p"
	.string "C'est un lieu\n"
	.string "pour tous !$"

BattleFrontier_OutsideEast_Text_OddTreeHereSeemsToWiggle:
	.string "Excusez-moi, jeune homme. Avez-vous une bonne\n"
	.string "vue ? Il y a un\p"
	.string "arbre bizarre plus loin, et à\n"
	.string "mes yeux fatigués, il semble bouger.$"

BattleFrontier_OutsideEast_Text_OnceAnOddTreePastHere:
	.string "Excusez-moi, jeune homme.\n"
	.string "Avez-vous bonne mémoire ?\p"
	.string "J'ai l'impression qu'il y avait autrefois\n"
	.string "un arbre bizarre par ici.$"

BattleFrontier_OutsideEast_Text_StickyMonWithLongTail:
	.string "Je…\n"
	.string "Je l'ai vu !\p"
	.string "Il y avait un POKéMON gluant\n"
	.string "avec une longue queue plus loin !\p"
	.string "Il se cachait sous un rocher et\n"
	.string "me fixait sans cesse !$"
