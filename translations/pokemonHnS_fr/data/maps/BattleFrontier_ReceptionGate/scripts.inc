.set LOCALID_GREETER, 1
.set LOCALID_GUIDE, 2
.set LOCALID_SCOTT, 4

BattleFrontier_ReceptionGate_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_ReceptionGate_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_ReceptionGate_OnTransition
	.byte 0

BattleFrontier_ReceptionGate_OnTransition:
	setflag FLAG_VISITED_BATTLE_FRONTIER
	end

BattleFrontier_ReceptionGate_OnFrame:
	map_script_2 VAR_HAS_ENTERED_BATTLE_FRONTIER, 0, BattleFrontier_ReceptionGate_EventScript_FirstTimeEntering
	.2byte 0

BattleFrontier_ReceptionGate_EventScript_FirstTimeEntering::
	lockall
	setvar VAR_HAS_ENTERED_BATTLE_FRONTIER, 1
	playse SE_PIN
	applymovement LOCALID_GREETER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_GREETER, Common_Movement_Delay48
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_FirstTimeHereThisWay, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_ReceptionGate_Movement_PlayerApproachCounter
	waitmovement 0
	goto BattleFrontier_ReceptionGate_EventScript_ScottScene
	end

BattleFrontier_ReceptionGate_EventScript_ScottScene::
	msgbox BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_IssueFrontierPass, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message BattleFrontier_ReceptionGate_Text_ObtainedFrontierPass
	waitfanfare
	waitmessage
	msgbox BattleFrontier_ReceptionGate_Text_PlacedTrainerCardInFrontierPass, MSGBOX_DEFAULT
	setflag FLAG_SYS_FRONTIER_PASS
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_IfItIsntPlayerYouCame, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GREETER, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_GUIDE, Common_Movement_WalkInPlaceFasterUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_GREETER, Common_Movement_ExclamationMark
	applymovement LOCALID_GUIDE, Common_Movement_ExclamationMark
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_OhMrScottGoodDay, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GREETER, BattleFrontier_ReceptionGate_Movement_GreeterFaceScott
	applymovement LOCALID_GUIDE, BattleFrontier_ReceptionGate_Movement_FacilityGuideFaceScott
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_ReceptionGate_Movement_PlayerFaceScott
	applymovement LOCALID_SCOTT, BattleFrontier_ReceptionGate_Movement_ScottEnter
	waitmovement 0
	msgbox BattleFrontier_ReceptionGate_Text_ScottGreatToSeeYouHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SCOTT, BattleFrontier_ReceptionGate_Movement_ScottExit
	waitmovement 0
	removeobject LOCALID_SCOTT
	releaseall
	end

BattleFrontier_ReceptionGate_Movement_PlayerApproachCounter:
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

BattleFrontier_ReceptionGate_Movement_PlayerFaceScott:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

@ Unused
BattleFrontier_ReceptionGate_Movement_WalkDown:
	walk_down
	walk_down
	step_end

BattleFrontier_ReceptionGate_Movement_ScottEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	step_end

BattleFrontier_ReceptionGate_Movement_ScottExit:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

BattleFrontier_ReceptionGate_Movement_GreeterFaceScott:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

BattleFrontier_ReceptionGate_Movement_FacilityGuideFaceScott:
	delay_16
	delay_16
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

BattleFrontier_ReceptionGate_EventScript_Greeter::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier, MSGBOX_DEFAULT
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_FacilityGuide::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToFacilities, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhich2
	waitmessage
	setvar VAR_0x8004, SCROLL_MULTI_BF_RECEPTIONIST
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_BattleTower
	case 1, BattleFrontier_ReceptionGate_EventScript_BattleDome
	case 2, BattleFrontier_ReceptionGate_EventScript_BattlePalace
	case 3, BattleFrontier_ReceptionGate_EventScript_BattleArena
	case 4, BattleFrontier_ReceptionGate_EventScript_BattleFactory
	case 5, BattleFrontier_ReceptionGate_EventScript_BattlePike
	case 6, BattleFrontier_ReceptionGate_EventScript_BattlePyramid
	case 7, BattleFrontier_ReceptionGate_EventScript_RankingHall
	case 8, BattleFrontier_ReceptionGate_EventScript_ExchangeCorner
	case 9, BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide
	end

BattleFrontier_ReceptionGate_EventScript_BattleTower::
	msgbox BattleFrontier_ReceptionGate_Text_BattleTowerInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattleDome::
	msgbox BattleFrontier_ReceptionGate_Text_BattleDomeInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePalace::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePalaceInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattleArena::
	msgbox BattleFrontier_ReceptionGate_Text_BattleArenaInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattleFactory::
	msgbox BattleFrontier_ReceptionGate_Text_BattleFactoryInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePike::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePikeInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePyramid::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePyramidInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_RankingHall::
	msgbox BattleFrontier_ReceptionGate_Text_RankingHallInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExchangeCorner::
	msgbox BattleFrontier_ReceptionGate_Text_ExchangeCornerInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFacilityToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExitFacilityGuide::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_RulesGuide::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToRules, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhat
	waitmessage
	multichoice 15, 0, MULTI_FRONTIER_RULES, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_LevelMode
	case 1, BattleFrontier_ReceptionGate_EventScript_Level50
	case 2, BattleFrontier_ReceptionGate_EventScript_OpenLevel
	case 3, BattleFrontier_ReceptionGate_EventScript_MonEntry
	case 4, BattleFrontier_ReceptionGate_EventScript_HoldItems
	case 5, BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide
	end

BattleFrontier_ReceptionGate_EventScript_LevelMode::
	msgbox BattleFrontier_ReceptionGate_Text_LevelModeInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_Level50::
	msgbox BattleFrontier_ReceptionGate_Text_Level50Info, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_OpenLevel::
	msgbox BattleFrontier_ReceptionGate_Text_OpenLevelInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_MonEntry::
	msgbox BattleFrontier_ReceptionGate_Text_MonEntryInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_HoldItems::
	msgbox BattleFrontier_ReceptionGate_Text_HoldItemsInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseRuleToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExitRulesGuide::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_EventScript_FrontierPassGuide::
	lock
	faceplayer
	msgbox BattleFrontier_ReceptionGate_Text_YourGuideToFrontierPass, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout::
	message BattleFrontier_ReceptionGate_Text_LearnAboutWhich1
	waitmessage
	multichoice 16, 4, MULTI_FRONTIER_PASS_INFO, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_ReceptionGate_EventScript_Symbols
	case 1, BattleFrontier_ReceptionGate_EventScript_RecordBattle
	case 2, BattleFrontier_ReceptionGate_EventScript_BattlePoints
	case 3, BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide
	case MULTI_B_PRESSED, BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide
	end

BattleFrontier_ReceptionGate_EventScript_Symbols::
	msgbox BattleFrontier_ReceptionGate_Text_SymbolsInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_RecordBattle::
	msgbox BattleFrontier_ReceptionGate_Text_RecordedBattleInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_BattlePoints::
	msgbox BattleFrontier_ReceptionGate_Text_BattlePointsInfo, MSGBOX_DEFAULT
	goto BattleFrontier_ReceptionGate_EventScript_ChooseFrontierPassInfoToLearnAbout
	end

BattleFrontier_ReceptionGate_EventScript_ExitFrontierPassGuide::
	msgbox BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier, MSGBOX_DEFAULT
	release
	end

BattleFrontier_ReceptionGate_Text_FirstTimeHereThisWay:
	.string "C'est ta première fois ici ?\n"
	.string "Passe par ici, s'il te plaît !$"

BattleFrontier_ReceptionGate_Text_WelcomeToBattleFrontier:
	.string "À l'avant-garde des combats de POKéMON !\n"
	.string "Bienvenue dans la ZONE DE COMBAT !$"

BattleFrontier_ReceptionGate_Text_IssueFrontierPass:
	.string "Pour un premier visiteur, nous délivrons\n"
	.string "le PASSE PARADIS.\p"
	.string "Il sert dans toutes les installations\n"
	.string "de la ZONE DE COMBAT.\p"
	.string "Le voici !$"

BattleFrontier_ReceptionGate_Text_ObtainedFrontierPass:
	.string "{PLAYER} obtient\n"
	.string "le PASSE PARADIS.$"

BattleFrontier_ReceptionGate_Text_PlacedTrainerCardInFrontierPass:
	.string "{PLAYER} a placé la CARTE de DRESSEUR\n"
	.string "dans le PASSE du PARC.$"

BattleFrontier_ReceptionGate_Text_EnjoyBattleFrontier:
	.string "Nous espérons que tu apprécieras tout ce que\n"
	.string "la ZONE DE COMBAT a à offrir !$"

BattleFrontier_ReceptionGate_Text_IfItIsntPlayerYouCame:
	.string "???: Eh bien, qui avons-nous ici ?\n"
	.string "Un nouveau Dresseur, hein ?$"

BattleFrontier_ReceptionGate_Text_OhMrScottGoodDay:
	.string "GUIDE : Oh ! M. SCOTT, monsieur !\n"
	.string "Bonne journée, monsieur !$"

BattleFrontier_ReceptionGate_Text_ScottGreatToSeeYouHere:
	.string "Je m'appelle SCOTT. Je suis toujours à la\n"
	.string "recherche de dresseurs talentueux.\p"
	.string "Et tu as vraiment l'air d'en être un !\n"
	.string "Puis-je demander ton nom ?\p"
	.string "Oh, alors tu es {PLAYER}{KUN} !\p"
	.string "Tu es venu de JOHTO ?\n"
	.string "C'est un sacré voyage !\p"
	.string "C'est super de te voir ici,\n"
	.string "vraiment !\p"
	.string "J'espère que tu prendras ton temps et\n"
	.string "exploreras partout.\p"
	.string "Naturellement, j'espère aussi que tu expérimenteras\n"
	.string "l'essence pure du combat.\p"
	.string "J'ai aussi mes quartiers ici, alors n'hésite pas\n"
	.string "à me rendre visite si tu as le temps.$"

BattleFrontier_ReceptionGate_Text_YourGuideToFacilities:
	.string "Je suis ton guide pour les différentes\n"
	.string "installations du PARC DES COMBATS.$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhich2:
	.string "Sur quoi aimerais-tu en apprendre davantage ?$"

BattleFrontier_ReceptionGate_Text_BattleTowerInfo:
	.string "C'est la tour gigantesque considérée\n"
	.string "comme le symbole de la ZONE DE COMBAT.\p"
	.string "Il y a quatre types de SALLES DE COMBAT\n"
	.string "dans la tour pour les combats SOLO, DUO, MULTI\l"
	.string "et MULTI LINK.$"

BattleFrontier_ReceptionGate_Text_BattleDomeInfo:
	.string "Le DÔME DE COMBAT\n"
	.string "est le grand bâtiment\p"
	.string "en forme d'oeuf. Des\n"
	.string "Tournois de Combat y\p"
	.string "sont organisés. Les DRESSEURS\n"
	.string "y affrontent des POKéMON\l"
	.string "de location en série.$"

BattleFrontier_ReceptionGate_Text_BattlePalaceInfo:
	.string "Le PALAIS DE COMBAT est le bâtiment rouge\n"
	.string "à droite de la ZONE DE COMBAT.\p"
	.string "Il y a deux sortes de SALLES DE COMBAT\n"
	.string "pour les COMBATS SOLO et DOUBLES.$"

BattleFrontier_ReceptionGate_Text_BattleArenaInfo:
	.string "L'ARENE DE COMBAT est le bâtiment\n"
	.string "ressemblant à un dojo au centre-droit\l"
	.string "de la ZONE DE COMBAT.\p"
	.string "Un événement appelé le Tournoi KO Direct\n"
	.string "a lieu à l'ARENE DE COMBAT.$"

BattleFrontier_ReceptionGate_Text_BattleFactoryInfo:
	.string "L'USINE DE COMBAT est le\n"
	.string "grand bâtiment le plus\p"
	.string "proche de nous. Un\n"
	.string "événement appelé Tournoi de\p"
	.string "Combat y est organisé.\n"
	.string "Les DRESSEURS y affrontent\l"
	.string "des POKéMON de location.$"

BattleFrontier_ReceptionGate_Text_BattlePikeInfo:
	.string "La RAMPE DE COMBAT est le bâtiment en forme\n"
	.string "de POKéMON au centre-gauche de\l"
	.string "la ZONE DE COMBAT.\p"
	.string "Un événement appelé le Choix de Combat\n"
	.string "y est organisé.$"

BattleFrontier_ReceptionGate_Text_BattlePyramidInfo:
	.string "La PYRAMIDE DE COMBAT est l'énorme\n"
	.string "pyramide.\p"
	.string "Un événement appelé Quête de Combat\n"
	.string "y est organisé.$"

BattleFrontier_ReceptionGate_Text_RankingHallInfo:
	.string "Le HALL DES CLASSEMENTS se trouve près\n"
	.string "de la TOUR DE COMBAT.\p"
	.string "Là, tu pourras voir les records les plus\n"
	.string "fantastiques laissés par les DRESSEURS qui\l"
	.string "ont relevé les nombreux défis de\l"
	.string "la ZONE DE COMBAT.$"

BattleFrontier_ReceptionGate_Text_ExchangeCornerInfo:
	.string "Le SERVICE D'ÉCHANGE est près\n"
	.string "de la TOUR DE COMBAT.\p"
	.string "Les Points de Combat que tu as gagnés\n"
	.string "dans la ZONE DE COMBAT peuvent y être\l"
	.string "échangés contre de fabuleux prix.$"

BattleFrontier_ReceptionGate_Text_YourGuideToRules:
	.string "Je suis ton guide pour les règles\n"
	.string "de base communes à tous les défis\l"
	.string "proposés par les installations de\l"
	.string "la ZONE DE COMBAT.$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhat:
	.string "Sur quoi aimerais-tu en apprendre davantage ?$"

BattleFrontier_ReceptionGate_Text_LevelModeInfo:
	.string "Tous les défis des installations de la\n"
	.string "ZONE DE COMBAT se déclinent\l"
	.string "en deux modes : NORMAL et DIFFICILE.$"

BattleFrontier_ReceptionGate_Text_Level50Info:
	.string "Le parcours NORMAL est ouvert !\n"
	.string "Tous les POKéMON seront au N50.\p"
	.string "Ce parcours sert de niveau d'entrée\n"
	.string "pour les combats au PARC DES\p"
	.string "COMBATS. Pour commencer, nous espérons\n"
	.string "que tu relèveras ce défi.$"

BattleFrontier_ReceptionGate_Text_OpenLevelInfo:
	.string "Le parcours DIFFICILE est\n"
	.string "ouvert ! Tous les\p"
	.string "POKéMON seront au N50.\n"
	.string "Ce parcours offre un\p"
	.string "grand défi aux\n"
	.string "DRESSEURS expérimentés !$"

BattleFrontier_ReceptionGate_Text_MonEntryInfo:
	.string "Pratiquement n'importe quel\n"
	.string "type de POKéMON peut relever\p"
	.string "les défis dans toutes\n"
	.string "les installations.\p"
	.string "Les OEUFS et certains\n"
	.string "types de POKéMON,\p"
	.string "cependant, ne sont pas admis.\n"
	.string "Renseigne-toi avant\l"
	.string "de participer !$"

BattleFrontier_ReceptionGate_Text_HoldItemsInfo:
	.string "En entrant dans un défi au\n"
	.string "PARC DES COMBATS, les POKéMON ne\l"
	.string "peuvent pas tenir le même\p"
	.string "type d'objet. Assure-toi que tous\n"
	.string "les POKéMON participant à un\l"
	.string "défi tiennent des objets différents.$"

BattleFrontier_ReceptionGate_Text_YourGuideToFrontierPass:
	.string "Je suis ton guide pour le PASSE PARADIS.$"

BattleFrontier_ReceptionGate_Text_LearnAboutWhich1:
	.string "Sur quoi aimerais-tu en apprendre davantage ?$"

BattleFrontier_ReceptionGate_Text_SymbolsInfo:
	.string "Il y a sept installations au\n"
	.string "PARC DES COMBATS.\p"
	.string "Les DRESSEURS qui gagnent la reconnaissance\n"
	.string "pour leurs capacités peuvent être récompensés par\l"
	.string "des symboles de chaque installation.\p"
	.string "Pour gagner un symbole, les DRESSEURS peuvent devoir\n"
	.string "battre d'autres DRESSEURS d'affilée,\l"
	.string "et peuvent devoir gagner des événements à répétition.\p"
	.string "Ce n'est certainement pas facile de gagner des symboles.\n"
	.string "Je te souhaite bonne chance !$"

BattleFrontier_ReceptionGate_Text_RecordedBattleInfo:
	.string "Il est possible\n"
	.string "d'enregistrer\p"
	.string "un combat\n"
	.string "sur ton PASSE PARC.\p"
	.string "Tu peux enregistrer un\n"
	.string "combat que tu\l"
	.string "as eu avec\l"
	.string "un ami ou des amis.\p"
	.string "C'est un bon souvenir !\n"
	.string "Essaie-le !$"

BattleFrontier_ReceptionGate_Text_BattlePointsInfo:
	.string "Les Points de Combat sont des récompenses données\n"
	.string "aux DRESSEURS qui se sont distingués\l"
	.string "à la ZONE DE COMBAT.\p"
	.string "Tu peux échanger tes Points de Combat\n"
	.string "contre des prix au SERVICE\l"
	.string "d'ÉCHANGE.$"

