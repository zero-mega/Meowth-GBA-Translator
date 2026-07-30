.set LOCALID_VERMILION_EUSINE, 24
.set LOCALID_VERMILION_SUICUNE, 23
.set LOCALID_VERMILION_SNORLAX, 1

VermilionCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_MapScript_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

VermilionCity_MapScript_OnTransition::
	setflag FLAG_VISITED_VERMILION_CITY
	goto_if_eq VAR_SUICUNE_ENCOUNTERS, 3, VermilionCity_EventScript_SetSuicuneScene
	setflag FLAG_HIDE_VERMILION_EUSINE_SUICUNE
	callnative SetTimeBasedEncounters
	end

VermilionCity_EventScript_SetSuicuneScene::
	clearflag FLAG_HIDE_VERMILION_EUSINE_SUICUNE
	callnative SetTimeBasedEncounters
	end

VermilionCity_EventScript_OldSeaMap::
	finditem ITEM_OLD_SEA_MAP
	end

VermilionCity_TriggerSuicuneNorth_Left::
	lock
	playse SE_PIN
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	delay 60
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	goto VermilionCity_TriggerSuicuneNorth_Merge
VermilionCity_TriggerSuicuneNorth_Mid::
	lock
	playse SE_PIN
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	delay 60
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	goto VermilionCity_TriggerSuicuneNorth_Merge
VermilionCity_TriggerSuicuneNorth_Right::
	lock
	playse SE_PIN
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	delay 60
	goto VermilionCity_TriggerSuicuneNorth_Merge
VermilionCity_TriggerSuicuneNorth_Merge::
	applymovement OBJ_EVENT_ID_PLAYER, VermilionCity_Movement_NorthSuicune_PlayerWalkDown
	waitmovement 0
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	applymovement2 LOCALID_VERMILION_SUICUNE, VermilionCity_Movement_Suicune1
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_PLAYER, VermilionCity_Movement_NorthSuicune_PlayerWalkDown
	delay 60
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	applymovement2 LOCALID_VERMILION_EUSINE, VermilionCity_Movement_EusineWalkToRail
	waitmovement LOCALID_VERMILION_EUSINE
	waitmovement OBJ_EVENT_ID_PLAYER
	goto VermilionCity_EventScript_SuicuneEpisode

VermilionCity_Movement_NorthSuicune_PlayerWalkDown:
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

VermilionCity_TriggerSuicuneTop::
	lock
	playse SE_PIN
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	delay 60
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	applymovement2 LOCALID_VERMILION_SUICUNE, VermilionCity_Movement_Suicune1
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_PLAYER, VermilionCity_Movement_PlayerWalkToRailTop
	delay 60
	applymovement2 LOCALID_VERMILION_EUSINE, VermilionCity_Movement_EusineWalkToRail
	waitmovement LOCALID_VERMILION_EUSINE
	waitmovement OBJ_EVENT_ID_PLAYER
	goto VermilionCity_EventScript_SuicuneEpisode
VermilionCity_TriggerSuicuneMid::
	lock
	playse SE_PIN
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	delay 60
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	applymovement2 LOCALID_VERMILION_SUICUNE, VermilionCity_Movement_Suicune1
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_PLAYER, VermilionCity_Movement_PlayerWalkToRailMid
	delay 60
	applymovement2 LOCALID_VERMILION_EUSINE, VermilionCity_Movement_EusineWalkToRail
	waitmovement LOCALID_VERMILION_EUSINE
	waitmovement OBJ_EVENT_ID_PLAYER
	goto VermilionCity_EventScript_SuicuneEpisode
VermilionCity_TriggerSuicuneBot::
	lock
	playse SE_PIN
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	delay 60
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	applymovement2 LOCALID_VERMILION_SUICUNE, VermilionCity_Movement_Suicune1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_PLAYER, VermilionCity_Movement_PlayerWalkToRailBot
	waitmovement 0
	applymovement2 LOCALID_VERMILION_EUSINE, VermilionCity_Movement_EusineWalkToRail
	waitmovement LOCALID_VERMILION_EUSINE
	waitmovement OBJ_EVENT_ID_PLAYER
	goto VermilionCity_EventScript_SuicuneEpisode

VermilionCity_EventScript_SuicuneEpisode::
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	applymovement2 LOCALID_VERMILION_SUICUNE, VermilionCity_Movement_SuicuneLeave
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	playse SE_LEDGE
	delay 30
	waitmovement 0
	msgbox VermilionCity_Text_Eusine, MSGBOX_DEFAULT
	turnobject LOCALID_VERMILION_EUSINE, DIR_SOUTH
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	msgbox VermilionCity_Text_Eusine2, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_VERMILION_EUSINE, VermilionCity_Movement_EusineLeave
	waitmovement 0
	removeobject LOCALID_VERMILION_EUSINE
	removeobject LOCALID_VERMILION_SUICUNE
	setflag FLAG_HIDE_VERMILION_EUSINE_SUICUNE

	setvar VAR_SUICUNE_ENCOUNTERS, 4
	clearflag FLAG_HIDE_ROUTE14_SUICUNE
	release
	end

VermilionCity_EventScript_Teacher::
	msgbox VermilionCity_Text_Teacher, MSGBOX_NPC
	end

VermilionCity_EventScript_Oldman::
	msgbox VermilionCity_Text_MachopOwner, MSGBOX_NPC
	end

VermilionCity_EventScript_Machop::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MACHOP, CRY_MODE_NORMAL
	msgbox VermilionCity_Text_Machop1, MSGBOX_DEFAULT
	waitmoncry
	msgbox VermilionCity_Text_Machop2, MSGBOX_DEFAULT
	release
	end

VermilionCity_EventScript_Nerd::
	msgbox VermilionCity_Text_SuperNerd, MSGBOX_NPC
	end

VermilionCity_EventScript_Snorlax::
	lock
	goto_if_set FLAG_KANTO_RADIO_GOT, VermilionCity_EventScript_SnorlaxWakeUp
	msgbox VermilionCity_Text_SnorlaxSleeping, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_EventScript_SnorlaxWakeUp::
    playbgm MUS_HG_RADIO_POKE_FLUTE, TRUE
    msgbox VermilionCity_Text_RadioNearSnorlax, MSGBOX_DEFAULT
    playmoncry SPECIES_SNORLAX, CRY_MODE_ENCOUNTER
    delay 40
    waitmoncry
    setwildbattle SPECIES_SNORLAX, 50
    dowildbattle
    specialvar VAR_RESULT, GetBattleOutcome
    goto_if_eq VAR_RESULT, B_OUTCOME_RAN, VermilionCity_EventScript_SnorlaxRan
    fadescreenswapbuffers FADE_TO_BLACK
    removeobject LOCALID_VERMILION_SNORLAX
    removeobject 8
    removeobject 9
    removeobject 10
    removeobject 11
    setflag FLAG_HIDE_VERMILION_SNORLAX
    fadescreenswapbuffers FADE_FROM_BLACK
    setflag FLAG_INDIGOJUNCTION_HIDE_KANTO_GUARD
    fadedefaultbgm
    release
    end

VermilionCity_EventScript_SnorlaxRan::
    fadedefaultbgm
    release
    end

VermilionCity_EventScript_BadgeGuy::
	lock
	faceplayer
	goto_if_set FLAG_GOT_VERMILION_HP_UP, VermilionCity_EventScript_BadgeGuyAfter
	goto_if_ge VAR_NUM_BADGES, 16, VermilionCity_EventScript_BadgeGuyAll
	goto_if_ge VAR_NUM_BADGES, 12, VermilionCity_EventScript_BadgeGuyMost
	goto_if_ge VAR_NUM_BADGES, 9, VermilionCity_EventScript_BadgeGuySome
	msgbox VermilionCity_Text_BadgeGuy_Trainer, MSGBOX_DEFAULT
	closemessage
	release
	end
VermilionCity_EventScript_BadgeGuySome::
	msgbox VermilionCity_Text_BadgeGuy_SomeBadges, MSGBOX_DEFAULT
	closemessage
	release
	end
VermilionCity_EventScript_BadgeGuyMost::
	msgbox VermilionCity_Text_BadgeGuy_MostBadges, MSGBOX_DEFAULT
	closemessage
	release
	end
VermilionCity_EventScript_BadgeGuyAll::
	msgbox VermilionCity_Text_BadgeGuy_AllBadges, MSGBOX_DEFAULT
	giveitem ITEM_HP_UP
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_VERMILION_HP_UP
	closemessage
	release
	end
VermilionCity_EventScript_BadgeGuyAfter::
	msgbox VermilionCity_Text_BadgeGuy_BattleEdge, MSGBOX_DEFAULT
	closemessage
	release
	end


VermilionCity_Movement_Suicune1:
	jump_in_place_left
	jump_in_place_left
	jump_in_place_left
	step_end

VermilionCity_Movement_PlayerWalkToRailTop: @goal tile = 51, 28
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	step_end
VermilionCity_Movement_PlayerWalkToRailMid:
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_right
	step_end
VermilionCity_Movement_PlayerWalkToRailBot:
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	step_end

VermilionCity_Movement_EusineWalkToRail:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	step_end

VermilionCity_Movement_SuicuneLeave:
	jump_in_place_left
	jump_2_right
	jump_2_right
	jump_2_right
	step_end

VermilionCity_Movement_EusineLeave:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

VermilionCity_Text_Eusine:
	.string "EUSINE : C'était\n"
	.string "si proche !\l"
	.string "Je pensais pouvoir\p"
	.string "le coincer en\n"
	.string "l'attendant ici. Mais\p"
	.string "il s'est enfui\n"
	.string "encore… La prochaine\p"
	.string "fois, SUICUNE sera\p"
	.string "à moi !$"

VermilionCity_Text_Eusine2:
	.string "Désolé {PLAYER}, je dois y aller !$"

VermilionCity_Text_Teacher:
	.string "Le PORT D'ORANGE est la porte maritime\n"
	.string "de KANTO.\p"
	.string "Des paquebots de luxe du monde entier\n"
	.string "accostent ici.$"

VermilionCity_Text_MachopOwner:
	.string "Mon POKéMON prépare le terrain\n"
	.string "pour la construction.\p"
	.string "Mais je n'ai pas d'argent pour lancer\n"
	.string "le projet…$"

VermilionCity_Text_Machop1:
	.string "MACHOC : Guooh gogogoh !$"

VermilionCity_Text_Machop2:
	.string "Un MACHOC grogne en\n"
	.string "écrasant le sol à coups de pied.$"

VermilionCity_Text_SuperNerd:
	.string "Il y a huit ARÈNES à KANTO.\p"
	.string "Ce grand bâtiment est l'ARÈNE POKéMON\n"
	.string "de CARMIN SUR MER.$"

VermilionCity_Text_SnorlaxSleeping:
	.string "RONFLEX ronfle paisiblement…$"

VermilionCity_Text_RadioNearSnorlax:
	.string "On a placé la RADIO près du\n"
	.string "RONFLEX endormi…\p"
	.string "…\p"
	.string "RONFLEX s'est réveillé !$"

VermilionCity_Text_BadgeGuy_Trainer:
	.string "Des DRESSEURS talentueux se rassemblent à KANTO.\p"
	.string "Les CHAMPIONS D'ARÈNE sont particulièrement forts.\p"
	.string "Ils ne seront pas faciles à battre.$"

VermilionCity_Text_BadgeGuy_SomeBadges:
	.string "Tu as commencé à collectionner les\n"
	.string "BADGES D'ARÈNE DE KANTO ?\p"
	.string "Tu ne trouves pas que les Dresseurs\n"
	.string "d'ici sont coriaces ?$"

VermilionCity_Text_BadgeGuy_MostBadges:
	.string "Tu vas bientôt avoir fini de conquérir\n"
	.string "les ARÈNES de KANTO, j'imagine.\p"
	.string "Dis-moi quand tu auras les huit\n"
	.string "BADGES.$"

VermilionCity_Text_BadgeGuy_AllBadges:
	.string "Félicitations !\p"
	.string "Tu as tous les BADGES D'ARÈNE DE KANTO.\p"
	.string "J'ai une récompense pour tes efforts.$"

VermilionCity_Text_BadgeGuy_BattleEdge:
	.string "Avoir une variété de types de\n"
	.string "POKéMON devrait te donner un avantage\p"
	.string "en combat. Je suis sûr que\n"
	.string "les BADGES de KANTO t'aideront.$"

VermilionCity_EventScript_CitySign::
	msgbox VermilionCity_Text_Sign, MSGBOX_SIGN
	end
VermilionCity_EventScript_GymSign::
	msgbox VermilionCity_Text_GymSign, MSGBOX_SIGN
	end
VermilionCity_EventScript_FanClubSign::
	msgbox VermilionCity_Text_FanClubSign, MSGBOX_SIGN
	end
VermilionCity_EventScript_DiglettsCaveSign::
	msgbox VermilionCity_Text_DiglettsCaveSign, MSGBOX_SIGN
	end

VermilionCity_Text_Sign:
	.string "VERMILIA\p"
	.string "Le port aux couchers de soleil exquis$"

VermilionCity_Text_GymSign:
	.string "CARMIN SUR MER\n"
	.string "ARENE POKéMON\p"
	.string "CHAMPION : LT.SURGE\p"
	.string "L'Américain Foudroyant$"

VermilionCity_Text_FanClubSign:
	.string "FAN CLUB POKéMON\p"
	.string "Tous les fans de POKéMON sont les bienvenus !$"

VermilionCity_Text_DiglettsCaveSign:
	.string "GROTTE TAUPIQUEUR$"

VermilionCity_Text_PortSign:
	.string "PORT DE CARMIN SUR MER\n"
	.string "ENTRÉE$"
