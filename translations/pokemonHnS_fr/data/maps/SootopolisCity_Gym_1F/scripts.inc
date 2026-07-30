SootopolisCity_Gym_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SootopolisCity_Gym_1F_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, SootopolisCity_Gym_1F_OnResume
	map_script MAP_SCRIPT_ON_LOAD, SootopolisCity_Gym_1F_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, SootopolisCity_Gym_1F_OnTransition
	.byte 0

SootopolisCity_Gym_1F_OnTransition:
	setvar VAR_ICE_STEP_COUNT, 1
	end

SootopolisCity_Gym_1F_OnResume:
	setstepcallback STEP_CB_SOOTOPOLIS_ICE
	end

SootopolisCity_Gym_1F_OnLoad:
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special SetSootopolisGymCrackedIceMetatiles
	end

SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles::
	goto_if_lt VAR_ICE_STEP_COUNT, 8, SootopolisCity_Gym_1F_EventScript_StopCheckingStairs  @ All stairs ice
	goto_if_lt VAR_ICE_STEP_COUNT, 28, SootopolisCity_Gym_1F_EventScript_OpenFirstStairs
	goto_if_lt VAR_ICE_STEP_COUNT, 67, SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs
	setmetatile 8, 4, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 5, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_OpenFirstAndSecondStairs::
	setmetatile 8, 10, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 11, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_OpenFirstStairs::
	setmetatile 8, 15, METATILE_SootopolisGym_Stairs, FALSE
	setmetatile 8, 16, METATILE_SootopolisGym_Stairs, FALSE
SootopolisCity_Gym_1F_EventScript_StopCheckingStairs::
	return

SootopolisCity_Gym_1F_OnFrame:
	map_script_2 VAR_ICE_STEP_COUNT, 8, SootopolisCity_Gym_1F_EventScript_UnlockFirstStairs
	map_script_2 VAR_ICE_STEP_COUNT, 28, SootopolisCity_Gym_1F_EventScript_UnlockSecondStairs
	map_script_2 VAR_ICE_STEP_COUNT, 67, SootopolisCity_Gym_1F_EventScript_UnlockThirdStairs
	map_script_2 VAR_ICE_STEP_COUNT, 0, SootopolisCity_Gym_1F_EventScript_FallThroughIce
	.2byte 0

SootopolisCity_Gym_1F_EventScript_UnlockFirstStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_UnlockSecondStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_UnlockThirdStairs::
	addvar VAR_ICE_STEP_COUNT, 1
	delay 40
	playse SE_ICE_STAIRS
	call SootopolisCity_Gym_1F_EventScript_CheckSetStairMetatiles
	special DrawWholeMapView
	end

SootopolisCity_Gym_1F_EventScript_FallThroughIce::
	lockall
	delay 20
	applymovement OBJ_EVENT_ID_PLAYER, SootopolisCity_Gym_1F_Movement_FallThroughIce
	waitmovement 0
	playse SE_FALL
	delay 60
	warphole MAP_SOOTOPOLIS_CITY_GYM_B1F
	waitstate
	end

SootopolisCity_Gym_1F_Movement_FallThroughIce:
	set_invisible
	step_end

SootopolisCity_Gym_1F_EventScript_Juan::
	trainerbattle_single TRAINER_JUAN_1, SootopolisCity_Gym_1F_Text_JuanIntro, SootopolisCity_Gym_1F_Text_JuanDefeat, SootopolisCity_Gym_1F_EventScript_JuanDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, SootopolisCity_Gym_1F_EventScript_JuanRematch
	goto_if_unset FLAG_RECEIVED_TM_WATER_PULSE, SootopolisCity_Gym_1F_EventScript_GiveWaterPulse2
	goto_if_unset FLAG_BADGE06_GET, SootopolisCity_Gym_1F_EventScript_GoGetFortreeBadge
	msgbox SootopolisCity_Gym_1F_Text_JuanPostBattle, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_JuanDefeated::
	message SootopolisCity_Gym_1F_Text_ReceivedRainBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_BLACKTHORN_GYM
	setflag FLAG_BADGE08_GET
	setflag FLAG_GARBAGEFLAG
	setflag FLAG_GARBAGEFLAG
	setflag FLAG_GARBAGEFLAG
	setvar VAR_GARBAGEVAR, 6
	clearflag FLAG_GARBAGEFLAG
	setvar VAR_0x8008, 8
	call Common_EventScript_SetGymTrainers
	call SootopolisCity_Gym_1F_EventScript_GiveWaterPulse
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox SootopolisCity_Gym_1F_Text_RegisteredJuan, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_JUAN_MATCH_CALL
	release
	end

SootopolisCity_Gym_1F_EventScript_GiveWaterPulse::
	giveitem ITEM_TM_WATER_PULSE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox SootopolisCity_Gym_1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_WATER_PULSE
	return

SootopolisCity_Gym_1F_EventScript_GiveWaterPulse2::
	giveitem ITEM_TM_WATER_PULSE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox SootopolisCity_Gym_1F_Text_ExplainWaterPulse, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_WATER_PULSE
	release
	end

SootopolisCity_Gym_1F_EventScript_GoGetFortreeBadge::
	msgbox SootopolisCity_Gym_1F_Text_GoGetFortreeBadge, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_JuanRematch::
	trainerbattle_rematch_double TRAINER_JUAN_1, SootopolisCity_Gym_1F_Text_JuanPreRematch, SootopolisCity_Gym_1F_Text_JuanRematchDefeat, SootopolisCity_Gym_1F_Text_JuanRematchNeedTwoMons
	msgbox SootopolisCity_Gym_1F_Text_JuanPostRematch, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_1F_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_BLACKTHORN_GYM, SootopolisCity_Gym_1F_EventScript_GymGuidePostVictory
	msgbox SootopolisCity_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_GymGuidePostVictory::
	msgbox SootopolisCity_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

SootopolisCity_Gym_1F_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_GymStatueCertified
	goto SootopolisCity_Gym_1F_EventScript_GymStatue
	end

SootopolisCity_Gym_1F_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE08_GET, SootopolisCity_Gym_1F_EventScript_GymStatueCertified
	goto SootopolisCity_Gym_1F_EventScript_GymStatue
	end

SootopolisCity_Gym_1F_EventScript_GymStatueCertified::
	msgbox SootopolisCity_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_Gym_1F_EventScript_GymStatue::
	msgbox SootopolisCity_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_Gym_1F_Text_GymGuideAdvice:
	.string "Yo ! Comment ça\n"
	.string "va, futur CHAMPION\p"
	.string "{PLAYER} ?\n"
	.string "JUAN, le CHAMPION d'ARÈNE\p"
	.string "d'ATALANOPOLIS,\n"
	.string "est un maître\p"
	.string "des POKéMON de type EAU.\n"
	.string "Utilise des capacités de\p"
	.string "type PLANTE ou ÉLECTRIK !\n"
	.string "Bonne chance !$"

SootopolisCity_Gym_1F_Text_GymGuidePostVictory:
	.string "Waouh ! Tu as même battu JUAN, qui\n"
	.string "était censé être le meilleur de tout HOENN\p"
	.string "! OK ! Regarde ta CARTE DRESSEUR. Si\p"
	.string "tu as tous les BADGES, tu es prêt\n"
	.string "pour le défi de la LIGUE POKéMON !$"

SootopolisCity_Gym_1F_Text_JuanIntro:
	.string "Laisse-moi te demander.\n"
	.string "Tu savais ?\l"
	.string "Ah, je ne devrais pas être si mystérieux.\p"
	.string "C'est moi qui ai tout appris à WALLACE\n"
	.string "sur les POKéMON.\p"
	.string "Autrefois, j'avais abandonné ma position de\n"
	.string "CHAMPION d'ARÈNE.\p"
	.string "À ma place, j'avais confié WALLACE\n"
	.string "à l'ARÈNE.\p"
	.string "Cependant, une raison impérieuse m'a poussé\n"
	.string "à faire un retour.\p"
	.string "Ah, mais assez bavardé.\n"
	.string "Commençons notre match, veux-tu ?\p"
	.string "S'il te plaît, tu seras témoin de\n"
	.string "notre art.\p"
	.string "Une grande illusion d'eau sculptée\n"
	.string "par les POKéMON et moi-même !$"

@ NOTE: This defeat text actually causes a buffer overflow. It's about 50 bytes too long for
@ the gDisplayedStringBattle buffer that it's put into, and it stomps all over the gBattleTextBuffs
@ after, as well as the otherwise unused array after that. One wonders if that's the reason for
@ the existence of that unused array of ints.
SootopolisCity_Gym_1F_Text_JuanDefeat:
	.string "CAPT. POIVRE : Oh, {PLAYER}{KUN}…\n"
	.string "D'accord… La TEAM AQUA est partie avant que\p"
	.string "tu puisses les arrêter…\n"
	.string "Oh, non, ne te blâme pas.\p"
	.string "Tu n'es pas responsable de ça.\n"
	.string "Attraper un sous-marin…\p"
	.string "C'est impossible pour la plupart des gens.\n"
	.string "Il te faudrait un POKéMON qui sait\p"
	.string "PLONGER…\n"
	.string "Peut-être si tu allais à\p"
	.string "ATLANPÔLE…\p"
	.string "Beaucoup de plongeurs y vivent, alors\n"
	.string "quelqu'un pourrait t'apprendre…$"

SootopolisCity_Gym_1F_Text_ReceivedRainBadge:
	.string "{PLAYER} a reçu le BADGE PLUIE\n"
	.string "de JUAN.$"

SootopolisCity_Gym_1F_Text_ExplainRainBadgeTakeThis:
	.string "Avec le BADGE PLUIE,\n"
	.string "tous tes POKéMON\l"
	.string "obéiront à tous\p"
	.string "tes ordres.\n"
	.string "Tu peux aussi\l"
	.string "utiliser CASCADE\p"
	.string "en dehors des combats.\n"
	.string "Félicitations !$"

SootopolisCity_Gym_1F_Text_ExplainWaterPulse:
	.string "La CAPACITÉ TECHNIQUE que je t'ai donnée\n"
	.string "contient VIBRAQUA.\p"
	.string "En combat, elle peut parfois troubler\n"
	.string "la cible avec des ultrasons.\p"
	.string "… … … … … …$"

SootopolisCity_Gym_1F_Text_RegisteredJuan:
	.string "CHAMPION D'ARÈNE JUAN\n"
	.string "enregistré dans le POKéNAV.$"

SootopolisCity_Gym_1F_Text_JuanPostBattle:
	.string "Les DRESSEURS qui ont réuni tous\n"
	.string "les BADGES d'ARÈNE de HOENN\l"
	.string "doivent se diriger vers la\p"
	.string "destination ultime.\p"
	.string "La LIGUE POKéMON.\n"
	.string "Voyage vers l'extrême est de\p"
	.string "HOENN, sur l'île ÎLE DES HUIT.\n"
	.string "Là, tu trouveras la LIGUE POKéMON.$"

SootopolisCity_Gym_1F_Text_GoGetFortreeBadge:
	.string "Il ne reste qu'un BADGE à\n"
	.string "obtenir à HOENN.\p"
	.string "Si tu veux défier la LIGUE POKéMON,\n"
	.string "tu dois obtenir le dernier BADGE\l"
	.string "de l'ARENE de CIMETRONELLE.$"

SootopolisCity_Gym_1F_Text_GymStatue:
	.string "ARÈNE POKéMON D'ATALANTIS$"

SootopolisCity_Gym_1F_Text_GymStatueCertified:
	.string "ATALANOPOLIS ARENE POKéMON\p"
	.string "DRESSEURS CERTIFIÉS DE JUAN :\n"
	.string "{PLAYER}$"

SootopolisCity_Gym_1F_Text_JuanPreRematch:
	.string "ADRIAN : Ah, cette ARÈNE était revenue\n"
	.string "à son état de sérénité habituel… Mais\p"
	.string "notre jeune typhon est revenu pour nous\n"
	.string "mettre à l'épreuve ! Eh bien,\p"
	.string "mon ami, certainement ! Je serai\p"
	.string "ravi de danser avec toi aussi\n"
	.string "souvent que tu le souhaites !$"

SootopolisCity_Gym_1F_Text_JuanRematchDefeat:
	.string "Ahahaha, tu as gagné !\n"
	.string "Tu m'as encore battu !$"

SootopolisCity_Gym_1F_Text_JuanPostRematch:
	.string "ADRIAN : Si je te\n"
	.string "demandais de devenir mon apprenti,\p"
	.string "tu refuserais, j'en suis sûr.\n"
	.string "J'aimerais t'offrir mon manteau. Mais\p"
	.string "encore une fois, tu refuseras.\n"
	.string "Je l'imagine bien. Et ça,\p"
	.string "mon ami, est un signe\n"
	.string "certain de noblesse !$"

SootopolisCity_Gym_1F_Text_JuanRematchNeedTwoMons:
	.string "JUAN : Ah, cette ARÈNE\n"
	.string "était revenue à son\p"
	.string "état habituel\n"
	.string "de sérénité…\p"
	.string "Mais notre jeune\n"
	.string "typhon est revenu\p"
	.string "pour nous mettre\n"
	.string "à l'épreuve !\p"
	.string "{PLAYER}{KUN},\n"
	.string "montre-moi ta danse !$"

