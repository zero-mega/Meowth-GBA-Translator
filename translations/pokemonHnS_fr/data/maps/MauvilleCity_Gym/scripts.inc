MauvilleCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, MauvilleCity_Gym_OnLoad
	.byte 0

MauvilleCity_Gym_OnLoad:
	goto_if_set FLAG_DEFEATED_GOLDENROD_CITY_GYM, MauvilleCity_Gym_EventScript_DeactivatePuzzle
	switch VAR_GARBAGEVAR
	case 0, MauvilleCity_Gym_EventScript_UpdateBarriers
	case 1, MauvilleCity_Gym_EventScript_Switch1Pressed
	case 2, MauvilleCity_Gym_EventScript_Switch2Pressed
	case 3, MauvilleCity_Gym_EventScript_Switch3Pressed
	case 4, MauvilleCity_Gym_EventScript_Switch4Pressed
	end

MauvilleCity_Gym_EventScript_UpdateBarriers::
	goto_if_set FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_SetAltBarriers
	end

MauvilleCity_Gym_EventScript_SetAltBarriers::
	setmetatile 3, 11, METATILE_MauvilleGym_RedBeamV1_On, TRUE
	setmetatile 3, 12, METATILE_MauvilleGym_RedBeamV2_On, TRUE
	setmetatile 3, 13, METATILE_MauvilleGym_PoleTop_On, TRUE
	setmetatile 4, 10, METATILE_MauvilleGym_RedBeamH1_On, FALSE
	setmetatile 5, 10, METATILE_MauvilleGym_RedBeamH2_On, FALSE
	setmetatile 4, 11, METATILE_MauvilleGym_RedBeamH3_On, TRUE
	setmetatile 5, 11, METATILE_MauvilleGym_RedBeamH4_On, TRUE
	setmetatile 7, 10, METATILE_MauvilleGym_RedBeamH1_On, FALSE
	setmetatile 8, 10, METATILE_MauvilleGym_RedBeamH2_On, FALSE
	setmetatile 7, 11, METATILE_MauvilleGym_RedBeamH3_On, TRUE
	setmetatile 8, 11, METATILE_MauvilleGym_RedBeamH4_On, TRUE
	setmetatile 4, 13, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
	setmetatile 5, 13, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
	setmetatile 4, 14, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
	setmetatile 5, 14, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
	setmetatile 1, 10, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
	setmetatile 2, 10, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
	setmetatile 1, 11, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
	setmetatile 2, 11, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
	setmetatile 6, 8, METATILE_MauvilleGym_PoleBottom_On, TRUE
	setmetatile 6, 9, METATILE_MauvilleGym_FloorTile, FALSE
	setmetatile 6, 10, METATILE_MauvilleGym_PoleTop_Off, FALSE
	setmetatile 4, 6, METATILE_MauvilleGym_GreenBeamH1_Off, FALSE
	setmetatile 5, 6, METATILE_MauvilleGym_GreenBeamH2_Off, FALSE
	setmetatile 4, 7, METATILE_MauvilleGym_GreenBeamH3_Off, FALSE
	setmetatile 5, 7, METATILE_MauvilleGym_GreenBeamH4_Off, FALSE
	end

MauvilleCity_Gym_EventScript_Switch1Pressed::
	setvar VAR_0x8004, 0
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch2Pressed::
	setvar VAR_0x8004, 1
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch3Pressed::
	setvar VAR_0x8004, 2
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_Switch4Pressed::
	setvar VAR_0x8004, 3
	special MauvilleGymPressSwitch
	goto MauvilleCity_Gym_EventScript_UpdateBarriers
	end

MauvilleCity_Gym_EventScript_DeactivatePuzzle::
	special MauvilleGymDeactivatePuzzle
	end

MauvilleCity_Gym_EventScript_Wattson::
	trainerbattle_single TRAINER_WATTSON_1, MauvilleCity_Gym_Text_WattsonIntro, MauvilleCity_Gym_Text_WattsonDefeat, MauvilleCity_Gym_EventScript_WattsonDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_Gym_EventScript_WattsonRematch
	goto_if_unset FLAG_RECEIVED_TM_SHOCK_WAVE, MauvilleCity_Gym_EventScript_GiveShockWave2
	goto_if_eq VAR_NEW_MAUVILLE_STATE, 2, MauvilleCity_Gym_EventScript_CompletedNewMauville
	msgbox MauvilleCity_Gym_Text_WattsonPostBattle, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_WattsonDefeated::
	message MauvilleCity_Gym_Text_ReceivedDynamoBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MauvilleCity_Gym_Text_ExplainDynamoBadgeTakeThis, MSGBOX_DEFAULT
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 3
	clearflag FLAG_GARBAGEFLAG
	setflag FLAG_DEFEATED_GOLDENROD_CITY_GYM
	setflag FLAG_BADGE03_GET
	addvar VAR_GARBAGEVAR, 1
	call_if_eq VAR_GARBAGEVAR, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 3
	call Common_EventScript_SetGymTrainers
	special MauvilleGymDeactivatePuzzle
	special DrawWholeMapView
	playse SE_UNLOCK
	call MauvilleCity_Gym_EventScript_GiveShockWave
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MauvilleCity_Gym_Text_RegisteredWattson, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WATTSON_MATCH_CALL
	release
	end

MauvilleCity_Gym_EventScript_GiveShockWave2::
	giveitem ITEM_TM_SHOCK_WAVE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox MauvilleCity_Gym_Text_ExplainShockWave, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_SHOCK_WAVE
	release
	end

MauvilleCity_Gym_EventScript_GiveShockWave::
	giveitem ITEM_TM_SHOCK_WAVE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox MauvilleCity_Gym_Text_ExplainShockWave, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_SHOCK_WAVE
	return

MauvilleCity_Gym_EventScript_CompletedNewMauville::
	msgbox MauvilleCity_Gym_Text_WattsonGoForthAndEndeavor, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_WattsonRematch::
	trainerbattle_rematch_double TRAINER_WATTSON_1, MauvilleCity_Gym_Text_WattsonPreRematch, MauvilleCity_Gym_Text_WattsonRematchDefeat, MauvilleCity_Gym_Text_WattsonRematchNeedTwoMons
	msgbox MauvilleCity_Gym_Text_WattsonPostRematch, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Switch1::
	lockall
	goto_if_set FLAG_DEFEATED_GOLDENROD_CITY_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_GARBAGEVAR, 1, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_GARBAGEVAR, 1
	setvar VAR_0x8004, 0
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch2::
	lockall
	goto_if_set FLAG_DEFEATED_GOLDENROD_CITY_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_GARBAGEVAR, 2, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_GARBAGEVAR, 2
	setvar VAR_0x8004, 1
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch3::
	lockall
	goto_if_set FLAG_DEFEATED_GOLDENROD_CITY_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_GARBAGEVAR, 3, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_GARBAGEVAR, 3
	setvar VAR_0x8004, 2
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_Switch4::
	lockall
	goto_if_set FLAG_DEFEATED_GOLDENROD_CITY_GYM, MauvilleCity_Gym_EventScript_SwitchDoNothing
	goto_if_eq VAR_GARBAGEVAR, 4, MauvilleCity_Gym_EventScript_SwitchDoNothing
	setvar VAR_GARBAGEVAR, 4
	setvar VAR_0x8004, 3
	goto MauvilleCity_Gym_EventScript_PressFloorSwitch
	end

MauvilleCity_Gym_EventScript_PressFloorSwitch::
	special MauvilleGymSetDefaultBarriers
	special MauvilleGymPressSwitch
	special DrawWholeMapView
	playse SE_UNLOCK
	goto_if_set FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_ClearBarriersAltState
	goto_if_unset FLAG_MAUVILLE_GYM_BARRIERS_STATE, MauvilleCity_Gym_EventScript_SetBarriersAltState
	releaseall
	end

MauvilleCity_Gym_EventScript_SwitchDoNothing::
	releaseall
	end

MauvilleCity_Gym_EventScript_SetBarriersAltState::
	setflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	releaseall
	end

MauvilleCity_Gym_EventScript_ClearBarriersAltState::
	clearflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	releaseall
	end

MauvilleCity_Gym_EventScript_Kirk::
	trainerbattle_single TRAINER_KIRK, MauvilleCity_Gym_Text_KirkIntro, MauvilleCity_Gym_Text_KirkDefeat
	msgbox MauvilleCity_Gym_Text_KirkPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Shawn::
	trainerbattle_single TRAINER_SHAWN, MauvilleCity_Gym_Text_ShawnIntro, MauvilleCity_Gym_Text_ShawnDefeat
	msgbox MauvilleCity_Gym_Text_ShawnPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Ben::
	trainerbattle_single TRAINER_BEN, MauvilleCity_Gym_Text_BenIntro, MauvilleCity_Gym_Text_BenDefeat
	msgbox MauvilleCity_Gym_Text_BenPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Vivian::
	trainerbattle_single TRAINER_VIVIAN, MauvilleCity_Gym_Text_VivianIntro, MauvilleCity_Gym_Text_VivianDefeat
	msgbox MauvilleCity_Gym_Text_VivianPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_Angelo::
	trainerbattle_single TRAINER_CARLENE, MauvilleCity_Gym_Text_AngeloIntro, MauvilleCity_Gym_Text_AngeloDefeat
	msgbox MauvilleCity_Gym_Text_AngeloPostBattle, MSGBOX_AUTOCLOSE
	end

MauvilleCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_GOLDENROD_CITY_GYM, MauvilleCity_Gym_EventScript_GymGuidePostVictory
	msgbox MauvilleCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_GymGuidePostVictory::
	msgbox MauvilleCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

MauvilleCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE03_GET, MauvilleCity_Gym_EventScript_GymStatueCertified
	goto MauvilleCity_Gym_EventScript_GymStatue
	end

MauvilleCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE03_GET, MauvilleCity_Gym_EventScript_GymStatueCertified
	goto MauvilleCity_Gym_EventScript_GymStatue
	end

MauvilleCity_Gym_EventScript_GymStatueCertified::
	msgbox MauvilleCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

MauvilleCity_Gym_EventScript_GymStatue::
	msgbox MauvilleCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

MauvilleCity_Gym_Text_GymGuideAdvice:
	.string "Hé, comment ça va, futur CHAMPION\n"
	.string "{PLAYER} ?\p"
	.string "VOLTEK, le CHAMPION\n"
	.string "d'ARÈNE de LAVILLIA,\p"
	.string "utilise des POKéMON\n"
	.string "de type ÉLECTRIK.\p"
	.string "Utilise des capacités\n"
	.string "de type SOL !\p"
	.string "Bonne chance !$"

MauvilleCity_Gym_Text_GymGuidePostVictory:
	.string "Whoa, tu es électrisant !\n"
	.string "Tu as alimenté la porte !$"

MauvilleCity_Gym_Text_KirkIntro:
	.string "Mon âme électrique va briser\n"
	.string "tes rêves en mille, whoa-yeahah !$"

MauvilleCity_Gym_Text_KirkDefeat:
	.string "C'était du tonnerre électrique,\n"
	.string "surchargé et amplifié, mec !$"

MauvilleCity_Gym_Text_KirkPostBattle:
	.string "POKéMON et roche, c'est une question de coeur,\n"
	.string "ouais !$"

MauvilleCity_Gym_Text_ShawnIntro:
	.string "Je me suis entraîné sous WATTSON !\n"
	.string "Je ne perdrai pas facilement !$"

MauvilleCity_Gym_Text_ShawnDefeat:
	.string "Débranché et éteint…$"

MauvilleCity_Gym_Text_ShawnPostBattle:
	.string "WATTSON, notre CHAMPION D'ARÈNE, est là\n"
	.string "depuis très, très longtemps.\p"
	.string "Il combattait déjà avant que ton\n"
	.string "papa naisse, ce vieux dur à cuire.$"

MauvilleCity_Gym_Text_BenIntro:
	.string "Cette ARÈNE a des énigmes !\n"
	.string "C'est pas amusant ?$"

MauvilleCity_Gym_Text_BenDefeat:
	.string "Perdre, ce n'est pas drôle…$"

MauvilleCity_Gym_Text_BenPostBattle:
	.string "WATTSON dit qu'il aime installer\n"
	.string "de petits pièges avec des interrupteurs.$"

MauvilleCity_Gym_Text_VivianIntro:
	.string "Avec mon charme et les capacités de mes POKéMON,\n"
	.string "tu vas être choqué !$"

MauvilleCity_Gym_Text_VivianDefeat:
	.string "Je suis choqué par ta puissance !$"

MauvilleCity_Gym_Text_VivianPostBattle:
	.string "J'ai entendu dire que LAVELLANIA a été fondée\n"
	.string "par WATTSON.\p"
	.string "Il était DRESSEUR bien avant que nous\n"
	.string "le devenions.\l"
	.string "Il doit connaître toutes sortes de choses !$"

MauvilleCity_Gym_Text_AngeloIntro:
	.string "J'adore les choses brillantes !$"

MauvilleCity_Gym_Text_AngeloDefeat:
	.string "Oh…\n"
	.string "Mes yeux sont épuisés…$"

MauvilleCity_Gym_Text_AngeloPostBattle:
	.string "L'ARÈNE de MAUVILLE, WATTSON a un front\n"
	.string "brillant. Ça me rend heureux !$"

MauvilleCity_Gym_Text_WattsonIntro:
	.string "J'ai abandonné mes\n"
	.string "plans de convertir\p"
	.string "la ville, c'est fait.\n"
	.string "Et donc, j'ai consacré\p"
	.string "mon temps à fabriquer\p"
	.string "des pièges de porte\n"
	.string "dans mon ARÈNE.\p"
	.string "Oh ? Non, ne t'inquiète pas,\n"
	.string "ce ne sont que\p"
	.string "des illusions !\n"
	.string "Bats-moi et tu verras !$"

MauvilleCity_Gym_Text_WattsonDefeat:
	.string "Wahahahah !\n"
	.string "Bien, j'ai perdu !\p"
	.string "Tu m'as vraiment donné des frissons !\n"
	.string "Prends ce BADGE !$"

MauvilleCity_Gym_Text_ReceivedDynamoBadge:
	.string "{PLAYER} a reçu le BADGE DYNAMO\n"
	.string "de WATTSON.$"

MauvilleCity_Gym_Text_ExplainDynamoBadgeTakeThis:
	.string "Avec le BADGE DYNAMO, les POKéMON peuvent\n"
	.string "utiliser FORCE en dehors des combats.\p"
	.string "Et ça rendra aussi tes POKéMON\n"
	.string "un peu plus rapides.\p"
	.string "Hmm…\n"
	.string "Tu devrais prendre ceci aussi !$"

MauvilleCity_Gym_Text_ExplainShockWave:
	.string "Cette CT34 contient ONDE DE CHOC. C'est\p"
	.string "une attaque fiable qui ne rate jamais\n"
	.string "! Tu peux compter dessus !\p"
	.string "… … … … … …$"

MauvilleCity_Gym_Text_RegisteredWattson:
	.string "CHAMPION D'ARÈNE VOLTEREK\n"
	.string "enregistré dans le POKéNAV.$"

MauvilleCity_Gym_Text_WattsonPostBattle:
	.string "Je gonfle d'optimisme en voyant un jeune\n"
	.string "DRESSEUR prometteur comme toi !$"

MauvilleCity_Gym_Text_WattsonGoForthAndEndeavor:
	.string "Wahahahah !\n"
	.string "Va de l'avant et persévère, jeune homme !$"

MauvilleCity_Gym_Text_GymStatue:
	.string "MAUVILLE ARENE POKéMON$"

MauvilleCity_Gym_Text_GymStatueCertified:
	.string "MAUVILLE ARENE POKéMON\p"
	.string "DRESSEURS CERTIFIÉS DE WATTSON :\n"
	.string "{PLAYER}$"

MauvilleCity_Gym_Text_WattsonPreRematch:
	.string "VOLTÈRE : Ah ha ! Te voilà enfin !\n"
	.string "Je sais ce que tu veux.\l"
	.string "Tu veux te battre contre mes POKéMON !\p"
	.string "Wahahahaha !\p"
	.string "Je vais te faire des étincelles !\n"
	.string "Ne dis pas que je ne t'ai pas prévenu !$"

MauvilleCity_Gym_Text_WattsonRematchDefeat:
	.string "Ouf…\n"
	.string "Nos piles sont à plat…$"

MauvilleCity_Gym_Text_WattsonPostRematch:
	.string "WATTSON : Il va falloir recharger nos\n"
	.string "batteries à nouveau.\p"
	.string "Quand on sera pleinement rechargés, on acceptera\n"
	.string "volontiers ton défi.\p"
	.string "Alors, reviens un de ces jours,\n"
	.string "d'accord ?$"

MauvilleCity_Gym_Text_WattsonRematchNeedTwoMons:
	.string "VOLTÈRE : Ah-ha ! Te\n"
	.string "voilà enfin ! Je sais\l"
	.string "ce que tu veux. Tu\p"
	.string "veux combattre mes POKéMON !\p"
	.string "Wahahahaha ! Oups ! Attends\n"
	.string "! Tu n'as qu'un seul\p"
	.string "POKéMON ! Reviens avec deux\n"
	.string "POKéMON ou plus, d'accord ?$"

