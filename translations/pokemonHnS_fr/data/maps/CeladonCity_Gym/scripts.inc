CeladonCity_Gym_MapScripts::
	.byte 0


CeladonCity_Gym_EventScript_Erika::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_CELADON_GYM, CeladonCity_Gym_EventScript_Erika_Defeated
	msgbox CeladonCity_Gym_Text_ErikaBeforeBattle, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ERIKA, CeladonCity_Gym_Text_ErikaBeaten
	message CeladonCity_Gym_Text_PlayerReceivedRainbowBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox CeladonCity_Gym_Text_ErikaExplainTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_GIGA_DRAIN
	setflag FLAG_BADGE12_GET
	setflag FLAG_DEFEATED_CELADON_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 12
	call Common_EventScript_SetGymTrainers
	clearflag FLAG_HIDE_FOUNTAIN_ERIKA
	closemessage
	release
	end

CeladonCity_Gym_EventScript_Erika_Defeated::
	msgbox CeladonCity_Gym_Text_ErikaAfterBattle, MSGBOX_DEFAULT
	closemessage
	release
	end

CeladonCity_Gym_Text_ErikaBeforeBattle:
	.string "ERIKA : Bonjour…\n"
	.string "Quel temps agréable,\p"
	.string "n'est-ce pas ?\p"
	.string "C'est si plaisant…\n"
	.string "…J'ai peur de\p"
	.string "m'endormir…\n"
	.string "Je m'appelle ERIKA,\p"
	.string "la CHAMPIONNE\n"
	.string "d'ARÈNE\p"
	.string "d'AZURIA.$"

CeladonCity_Gym_Text_ErikaBeaten:
	.string "ERIKA : Oh ! Je reconnais ma défaite…\p"
	.string "Tu es remarquablement fort…\p"
	.string "Je vais te donner le BADGE PRISME…$"

CeladonCity_Gym_Text_PlayerReceivedRainbowBadge:
	.string "{PLAYER} a reçu le BADGE PRISME.$"

CeladonCity_Gym_Text_ErikaExplainTM:
	.string "ERIKA : C'était un match\n"
	.string "délicieux. Je me suis sentie\p"
	.string "inspirée. S'il te plaît, je\n"
	.string "souhaite que tu aies cette\p"
	.string "CT. C'est GIGA-SANGSUE. C'est une\p"
	.string "merveilleuse capacité qui draine la\n"
	.string "moitié des dégâts infligés pour\l"
	.string "soigner ton POKéMON. Utilise-la\p"
	.string "si ça te plaît…$"

CeladonCity_Gym_Text_ErikaAfterBattle:
	.string "ERIKA : Perdre laisse un\n"
	.string "goût amer… Mais savoir qu'il\p"
	.string "y a des DRESSEURS\n"
	.string "forts m'incite à m'améliorer…$"

CeladonCity_Gym_Text_ErikaRematch:
	.string "ERIKA : Oh, bonjour. Quelle surprise,\p"
	.string "CHAMPION DE KANTO ! C'est\p"
	.string "si agréable de te revoir.\p"
	.string "Ton voyage a dû être\n"
	.string "si excitant. Même les champions\p"
	.string "aiment un défi. Tu veux\p"
	.string "une revanche avec moi ?$"

CeladonCity_Gym_Text_ErikaRematchDefeat:
	.string "ERIKA : Perdre laisse encore\n"
	.string "un goût amer… Mais savoir\p"
	.string "qu'il y a des DRESSEURS\n"
	.string "forts m'incite à m'améliorer…$"

CeladonCity_Gym_EventScript_Michelle::
	trainerbattle_single TRAINER_MICHELLE CeladonCity_Gym_Text_LassMichelleSeen, CeladonCity_Gym_Text_LassMichelleBeaten
	msgbox CeladonCity_Gym_Text_LassMichelleAfter, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_LassMichelleSeen:
	.string "Tu penses qu'une ARÈNE réservée\n"
	.string "aux filles est rare ?$"

CeladonCity_Gym_Text_LassMichelleBeaten:
	.string "Beurk !$"

CeladonCity_Gym_Text_LassMichelleAfter:
	.string "Je me suis juste laissé distraire, c'est tout !$"


CeladonCity_Gym_EventScript_Tanya::
	trainerbattle_single TRAINER_TANYA CeladonCity_Gym_Text_PicnickerTanyaSeen, CeladonCity_Gym_Text_PicnickerTanyaBeaten
	msgbox CeladonCity_Gym_Text_PicnickerTanyaAfter, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_PicnickerTanyaSeen:
	.string "Oh, un combat ? C'est un peu effrayant,\n"
	.string "mais OK !$"

CeladonCity_Gym_Text_PicnickerTanyaBeaten:
	.string "Oh, c'est tout ?$"

CeladonCity_Gym_Text_PicnickerTanyaAfter:
	.string "Oh, regarde tous tes BADGES. Pas étonnant\n"
	.string "que je n'aie pas pu gagner !$"

CeladonCity_Gym_EventScript_Julia::
	trainerbattle_single TRAINER_JULIA CeladonCity_Gym_Text_BeautyJuliaSeen, CeladonCity_Gym_Text_BeautyJuliaBeaten
	msgbox CeladonCity_Gym_Text_BeautyJuliaAfter, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_BeautyJuliaSeen:
	.string "Tu regardais ces fleurs\n"
	.string "ou moi ?$"

CeladonCity_Gym_Text_BeautyJuliaBeaten:
	.string "Quelle plaie !$"

CeladonCity_Gym_Text_BeautyJuliaAfter:
	.string "Comment faire pour devenir\n"
	.string "élégante comme ERIKA ?$"

CeladonCity_Gym_EventScript_Jo::
	trainerbattle_double TRAINER_JO_AND_ZOE, CeladonCity_Gym_Text_TwinsJoAndZoe1Seen, CeladonCity_Gym_Text_TwinsJoAndZoe1Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox CeladonCity_Gym_Text_TwinsJoAndZoe1After, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_EventScript_Zoe::
	trainerbattle_double TRAINER_JO_AND_ZOE, CeladonCity_Gym_Text_TwinsJoAndZoe2Seen, CeladonCity_Gym_Text_TwinsJoAndZoe2Beaten, Route104_Text_GinaNotEnoughMons
	msgbox CeladonCity_Gym_Text_TwinsJoAndZoe2After, MSGBOX_AUTOCLOSE
	end

CeladonCity_Gym_Text_TwinsJoAndZoe1Seen:
	.string "On va te montrer les attaques POKéMON\n"
	.string "qu'ÉRICA nous a apprises !$"

CeladonCity_Gym_Text_TwinsJoAndZoe1Beaten:
	.string "Oh… On a perdu…$"

CeladonCity_Gym_Text_TwinsJoAndZoe1After:
	.string "ERIKA va te le faire payer pour nous !$"

CeladonCity_Gym_Text_TwinsJoAndZoe2Seen:
	.string "Nous allons protéger ERIKA !$"

CeladonCity_Gym_Text_TwinsJoAndZoe2Beaten:
	.string "On n'a pas pu gagner…$"

CeladonCity_Gym_Text_TwinsJoAndZoe2After:
	.string "ERIKA est bien, bien plus forte !$"

CeladonCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE12_GET, CeladonCity_Gym_EventScript_GymStatuePostVictory
	msgbox CeladonCity_Gym_Text_GymStatue
	releaseall
	end

CeladonCity_Gym_EventScript_GymStatuePostVictory::
	msgbox CeladonCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

CeladonCity_Gym_Text_GymStatue::
    .string "SAFRANIA ARENE POKéMON\n"
    .string "CHAMPIONNE : ERIKA\p"
    .string "DRESSEURS VAINQUEURS :\n"
    .string "BLUE, RED$"

CeladonCity_Gym_Text_GymStatuePlayerWon::
    .string "ARÈNE POKéMON DE CELADOPOLE\n"
    .string "CHAMPIONNE D'ARÈNE : ERIKA\p"
    .string "DRESSEURS VAINQUEURS :\n"
    .string "BLEU, ROUGE, {PLAYER}$"
