FortreeCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_Gym_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, FortreeCity_Gym_OnWarp
	.byte 0

FortreeCity_Gym_OnTransition:
	special RotatingGate_InitPuzzle
	setflag FLAG_TEMP_HIDE_FOLLOWER @ Hide follower bc of rotating gates
	end

FortreeCity_Gym_OnWarp:
	map_script_2 VAR_TEMP_0, VAR_TEMP_0, FortreeCity_Gym_EventScript_InitRotatingGates
	.2byte 0

@ NOTE: This rotating gate puzzle makes use of VAR_TEMP_0 - VAR_TEMP_3
FortreeCity_Gym_EventScript_InitRotatingGates::
	special RotatingGate_InitPuzzleAndGraphics
	end

FortreeCity_Gym_EventScript_Winona::
	trainerbattle_single TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaIntro, FortreeCity_Gym_Text_WinonaDefeat, FortreeCity_Gym_EventScript_WinonaDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_Gym_EventScript_WinonaRematch
	goto_if_unset FLAG_RECEIVED_TM_AERIAL_ACE, FortreeCity_Gym_EventScript_GiveAerialAce2
	msgbox FortreeCity_Gym_Text_WinonaPostBattle, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_WinonaDefeated::
	message FortreeCity_Gym_Text_ReceivedFeatherBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_OLIVINE_CITY_GYM
	setflag FLAG_BADGE06_GET
	setvar VAR_0x8008, 6
	call Common_EventScript_SetGymTrainers
	call FortreeCity_Gym_EventScript_GiveAerialAce
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox FortreeCity_Gym_Text_RegisteredWinona, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WINONA_MATCH_CALL
	setvar VAR_SCOTT_FORTREE_CALL_STEP_COUNTER, 0
	setflag FLAG_SCOTT_CALL_FORTREE_GYM
	release
	end

FortreeCity_Gym_EventScript_GiveAerialAce2::
	giveitem ITEM_TM_AERIAL_ACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_AERIAL_ACE
	release
	end

FortreeCity_Gym_EventScript_GiveAerialAce::
	giveitem ITEM_TM_AERIAL_ACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox FortreeCity_Gym_Text_ExplainAerialAce, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_AERIAL_ACE
	return

FortreeCity_Gym_EventScript_WinonaRematch::
	trainerbattle_rematch_double TRAINER_WINONA_1, FortreeCity_Gym_Text_WinonaPreRematch, FortreeCity_Gym_Text_WinonaRematchDefeat, FortreeCity_Gym_Text_WinonaRematchNeedTwoMons
	msgbox FortreeCity_Gym_Text_WinonaPostRematch, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Jared::
	trainerbattle_single TRAINER_JARED, FortreeCity_Gym_Text_JaredIntro, FortreeCity_Gym_Text_JaredDefeat
	msgbox FortreeCity_Gym_Text_JaredPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Edwardo::
	trainerbattle_single TRAINER_LOIS, FortreeCity_Gym_Text_EdwardoIntro, FortreeCity_Gym_Text_EdwardoDefeat
	msgbox FortreeCity_Gym_Text_EdwardoPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Flint::
	trainerbattle_single TRAINER_RAY, FortreeCity_Gym_Text_FlintIntro, FortreeCity_Gym_Text_FlintDefeat
	msgbox FortreeCity_Gym_Text_FlintPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Ashley::
	trainerbattle_single TRAINER_CHARLES, FortreeCity_Gym_Text_AshleyIntro, FortreeCity_Gym_Text_AshleyDefeat
	msgbox FortreeCity_Gym_Text_AshleyPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Humberto::
	trainerbattle_single TRAINER_CHUCK_2, FortreeCity_Gym_Text_HumbertoIntro, FortreeCity_Gym_Text_HumbertoDefeat
	msgbox FortreeCity_Gym_Text_HumbertoPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Darius::
	trainerbattle_single TRAINER_JIN, FortreeCity_Gym_Text_DariusIntro, FortreeCity_Gym_Text_DariusDefeat
	msgbox FortreeCity_Gym_Text_DariusPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, FortreeCity_Gym_EventScript_GymGuidePostVictory
	msgbox FortreeCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_GymGuidePostVictory::
	msgbox FortreeCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
	goto FortreeCity_Gym_EventScript_GymStatue
	end

FortreeCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
	goto FortreeCity_Gym_EventScript_GymStatue
	end

FortreeCity_Gym_EventScript_GymStatueCertified::
	msgbox FortreeCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_EventScript_GymStatue::
	msgbox FortreeCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_Text_GymGuideAdvice:
	.string "Yo, comment ça\n"
	.string "va, futur CHAMPION\p"
	.string "{PLAYER} ?\n"
	.string "AUDREY, la CHAMPIONNE\p"
	.string "d'ARÈNE de VERGONHA,\n"
	.string "est une maîtresse des\p"
	.string "POKéMON de type VOL.\n"
	.string "Utilise des capacités\p"
	.string "ÉLECTRIK ou GLACE !$"

FortreeCity_Gym_Text_GymGuidePostVictory:
	.string "Tu l'as fait !\n"
	.string "Tu as décollé !$"

FortreeCity_Gym_Text_JaredIntro:
	.string "Admirez le style de combat élégant\n"
	.string "des POKéMON OISEAU !$"

FortreeCity_Gym_Text_JaredDefeat:
	.string "Tu es…\n"
	.string "fort…$"

FortreeCity_Gym_Text_JaredPostBattle:
	.string "Un DRESSEUR doit être\n"
	.string "malin pour suivre les\p"
	.string "événements imprévus. As-tu l'intelligence\n"
	.string "d'atteindre notre CHAMPION ?$"

FortreeCity_Gym_Text_EdwardoIntro:
	.string "Les amoureux des POKéMON OISEAU aspirent à\n"
	.string "rejoindre cette ARÈNE. En tant que membre\p"
	.string "de l'ARÈNE de CIMETRONELLE, je n'ai\n"
	.string "pas le droit de perdre !$"

FortreeCity_Gym_Text_EdwardoDefeat:
	.string "C'était trop lourd à porter\n"
	.string "pour moi…$"

FortreeCity_Gym_Text_EdwardoPostBattle:
	.string "Le monde est immense, et il\n"
	.string "y a d'innombrables DRESSEURS coriaces.\p"
	.string "Je vais continuer à m'entraîner\n"
	.string "pour devenir encore plus fort.$"

FortreeCity_Gym_Text_FlintIntro:
	.string "Pas besoin que ALIZÉE, notre CHAMPION D'ARÈNE,\n"
	.string "s'occupe de toi !\p"
	.string "Je suis largement assez fort pour toi !$"

FortreeCity_Gym_Text_FlintDefeat:
	.string "WINONA, je…\n"
	.string "J'ai perdu !$"

FortreeCity_Gym_Text_FlintPostBattle:
	.string "WINONA est mignonne et elle est forte.\n"
	.string "C'est la CHAMPIONNE ultime !\p"
	.string "Rougit…$"

FortreeCity_Gym_Text_AshleyIntro:
	.string "WINONA m'a entraîné personnellement !\n"
	.string "Tu ne me battras pas facilement !$"

FortreeCity_Gym_Text_AshleyDefeat:
	.string "J'ai été battu…$"

FortreeCity_Gym_Text_AshleyPostBattle:
	.string "Grâce à ALIZA, les habitants de\n"
	.string "FORTREE peuvent vivre sans crainte.$"

FortreeCity_Gym_Text_HumbertoIntro:
	.string "Quand ALIZÉE se bat, son visage\n"
	.string "brille d'une belle détermination…\p"
	.string "Je ne te laisserai pas assister\n"
	.string "à ce spectacle magnifique !$"

FortreeCity_Gym_Text_HumbertoDefeat:
	.string "Urk !\n"
	.string "Je n'ai pas pu t'arrêter.$"

FortreeCity_Gym_Text_HumbertoPostBattle:
	.string "Tu ferais mieux de faire attention !\n"
	.string "Ne reste pas à regarder ALIZÉE\l"
	.string "ou tu vas t'écraser lamentablement !$"

FortreeCity_Gym_Text_DariusIntro:
	.string "Tu ferais mieux de savoir qu'il y a toutes\n"
	.string "sortes de POKéMON de type VOL.\p"
	.string "Tu le sais, n'est-ce pas ?$"

FortreeCity_Gym_Text_DariusDefeat:
	.string "Tu sembles connaître ton affaire !$"

FortreeCity_Gym_Text_DariusPostBattle:
	.string "OK, tu m'as battu.\n"
	.string "Mais fais attention ! Notre CHAMPIONNE\l"
	.string "ALIZÉE et ses POKéMON ne plaisantent pas.$"

FortreeCity_Gym_Text_WinonaIntro:
	.string "Je suis ALIZA. Je suis la\n"
	.string "CHAMPIONNE de l'ARÈNE POKéMON\p"
	.string "de LESÉVANIA.\n"
	.string "Je ne fais plus qu'un avec les\p"
	.string "POKéMON OISEAU et j'ai plané\n"
	.string "dans les cieux…\p"
	.string "Quel que soit le combat éprouvant,\n"
	.string "nous avons triomphé avec grâce… Admire la chorégraphie élégante des POKéMON OISEAU et moi !$"

FortreeCity_Gym_Text_WinonaDefeat:
	.string "Jamais je n'ai vu un DRESSEUR commander\n"
	.string "ses POKéMON avec autant de grâce\l"
	.string "que moi…\p"
	.string "En reconnaissance de ta prouesse,\n"
	.string "je te remets ce BADGE D'ARÈNE.$"

FortreeCity_Gym_Text_ReceivedFeatherBadge:
	.string "{PLAYER} a reçu le BADGE PLUME\n"
	.string "de WINONA.$"

FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis:
	.string "Avec le BADGE PLUME, tous\n"
	.string "les POKéMON jusqu'au\l"
	.string "niv. 70, même\p"
	.string "ceux reçus par\n"
	.string "échange, obéiront\p"
	.string "à tous tes ordres.\p"
	.string "Tu peux aussi\n"
	.string "utiliser VOL\p"
	.string "en dehors des combats.\n"
	.string "Félicitations !$"

FortreeCity_Gym_Text_ExplainAerialAce:
	.string "La CT40 contient AÉROPIQUE.\p"
	.string "Sa vitesse…\n"
	.string "Aucun POKéMON ne devrait pouvoir l'éviter.\p"
	.string "… … … … … …$"

FortreeCity_Gym_Text_RegisteredWinona:
	.string "CHAMPIONNE D'ARÈNE ALIZA\n"
	.string "enregistrée dans le POKéNAV.$"

FortreeCity_Gym_Text_WinonaPostBattle:
	.string "Bien que j'aie perdu contre toi, je resterai\n"
	.string "dévoué aux POKéMON Oiseau.$"

FortreeCity_Gym_Text_GymStatue:
	.string "MYOKARA ARENE POKéMON$"

FortreeCity_Gym_Text_GymStatueCertified:
	.string "MYOKARA ARENE POKéMON\p"
	.string "DRESSEURS CERTIFIÉS DE ALIZEE :\n"
	.string "{PLAYER}$"

FortreeCity_Gym_Text_WinonaPreRematch:
	.string "ALIZA : Nous, humains, ne pouvons\n"
	.string "jamais échapper à la gravité au\p"
	.string "sol.\n"
	.string "Mais en visant l'excellence,\p"
	.string "nous avons le pouvoir de planer !\n"
	.string "Tu as atteint le sommet en tant\p"
	.string "que CHAMPION en titre.\n"
	.string "S'il te plaît, laisse-moi voir ta puissance en plein vol !$"

FortreeCity_Gym_Text_WinonaRematchDefeat:
	.string "Je n'ai encore pas réussi à atteindre ton niveau…$"

FortreeCity_Gym_Text_WinonaPostRematch:
	.string "ALIZÉE : Même si j'ai perdu,\n"
	.string "les ailes de mon cœur restent intactes.\p"
	.string "Je peux m'élever et planer encore\n"
	.string "et encore.\p"
	.string "J'en suis convaincue !$"

FortreeCity_Gym_Text_WinonaRematchNeedTwoMons:
	.string "AUDREY : Nous, humains, ne\n"
	.string "pouvons jamais échapper\p"
	.string "à la gravité au sol.\n"
	.string "Mais en visant\p"
	.string "l'excellence,\n"
	.string "nous avons le\p"
	.string "pouvoir de voler !\n"
	.string "Je suis AUDREY, la\p"
	.string "CHAMPIONNE d'ARÈNE\n"
	.string "d'ATALANOPOLIS !\p"
	.string "Montre-moi que tu\n"
	.string "peux voler haut !$"
