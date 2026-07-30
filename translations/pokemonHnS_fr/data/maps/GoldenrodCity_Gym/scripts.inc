.set LOCALID_GOLDENROD_CITY_GYM_BRIDGET, 6

GoldenrodCity_Gym_MapScripts::
	.byte 0
@Carrie, Bridget, Victoria, Samantha, gym guy


GoldenrodCity_Gym_EventScript_Carrie::
	trainerbattle_single TRAINER_CARRIE GoldenrodCity_Gym_Text_LassCarrieSeen, GoldenrodCity_Gym_Text_LassCarrieBeaten
	msgbox GoldenrodCity_Gym_Text_LassCarrieAfter, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_Gym_EventScript_Bridget::
	trainerbattle_single TRAINER_BRIDGET GoldenrodCity_Gym_Text_LassBridgetSeen, GoldenrodCity_Gym_Text_LassBridgetBeaten
	msgbox GoldenrodCity_Gym_Text_LassBridgetAfter, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_Gym_EventScript_Victoria::
	trainerbattle_single TRAINER_VICTORIA GoldenrodCity_Gym_Text_BeautyVictoriaSeen, GoldenrodCity_Gym_Text_BeautyVictoriaBeaten
	msgbox GoldenrodCity_Gym_Text_BeautyVictoriaAfter, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_Gym_EventScript_Samantha::
	trainerbattle_single TRAINER_SAMANTHA GoldenrodCity_Gym_Text_BeautySamanthaSeen, GoldenrodCity_Gym_Text_BeautySamanthaBeaten
	msgbox GoldenrodCity_Gym_Text_BeautySamanthaAfter, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_Gym_EventScript_Gym_Guy::
	lock
	faceplayer
	goto_if_set FLAG_BADGE03_GET, GoldenrodCity_Gym_EventScript_Gym_Guy_After
	msgbox GoldenrodCity_Gym_Text_GymGuide, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_Gym_Guy_After::
	msgbox GoldenrodCity_Gym_Text_GymGuideWin, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_Whitney::
	lock
	faceplayer
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 3, GoldenrodCity_Gym_EventScript_WhitneyCrying
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 4, GoldenrodCity_Gym_EventScript_WhitneyBadge
	goto_if_set FLAG_DEFEATED_GOLDENROD_CITY_GYM, GoldenrodCity_Gym_EventScript_WhitneyDefeated
	msgbox GoldenrodCity_Gym_Text_WhitneyBefore, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WHITNEY_1, GoldenrodCity_Gym_Text_WhitneyShouldntBeSoSerious
	msgbox GoldenrodCity_Gym_Text_WhitneyYouMeanie, MSGBOX_DEFAULT
	setvar VAR_GOLDENROD_CITY_STATE, 3
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_WhitneyCrying::
	lock
	faceplayer
	msgbox GoldenrodCity_Gym_Text_WhitneyYouMeanie, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_WhitneyBadge::
	lock
	faceplayer
	msgbox GoldenrodCity_Gym_Text_WhitneyWhatDoYouWant, MSGBOX_DEFAULT
	closemessage
	message GoldenrodCity_Gym_Text_PlayerReceivedPlainBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox GoldenrodCity_Gym_Text_WhitneyPlainBadge, MSGBOX_DEFAULT
	setflag FLAG_BADGE03_GET
	setflag FLAG_DEFEATED_GOLDENROD_CITY_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 3
	call Common_EventScript_SetGymTrainers
	giveitem ITEM_TM_ATTRACT
	msgbox GoldenrodCity_Gym_Text_WhitneyAttract, MSGBOX_DEFAULT
	setvar VAR_GOLDENROD_CITY_STATE, 5
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_WhitneyDefeated::
	lock
	faceplayer
	msgbox GoldenrodCity_Gym_Text_WhitneyGoodCry, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_Trigger::	
	turnobject LOCALID_GOLDENROD_CITY_GYM_BRIDGET DIR_WEST
	msgbox GoldenrodCity_Gym_Text_BridgetWhitneyCries, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp1
	waitmovement 0
	setvar VAR_GOLDENROD_CITY_STATE, 4
	closemessage
	release
	end


GoldenrodCity_Gym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_GOLDENROD_CITY_GYM, GoldenrodCity_Gym_EventScript_Statue2
	msgbox GoldenrodCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_EventScript_Statue2::
	msgbox GoldenrodCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Gym_Text_GymStatue:
	.string "ARÈNE POKéMON DE DOUBLONVILLE$"

GoldenrodCity_Gym_Text_GymStatueCertified:
	.string "DOUBLONVILLE ARENE POKéMON\p"
	.string "DRESSEURS CERTIFIÉS DE BLONDA :\n"
	.string "{PLAYER}$"

GoldenrodCity_Gym_Text_WhitneyBefore:
    .string "Salut ! Je suis BLAIRE !\p"
    .string "Tout le monde était dans les POKéMON,\n"
    .string "alors je me suis mise aussi !\p"
    .string "Les POKéMON sont trop mignons !\p"
    .string "Tu veux te battre ? Je te préviens,\n"
    .string "je suis forte !$"

GoldenrodCity_Gym_Text_WhitneyShouldntBeSoSerious:
    .string "Sob…\p"
    .string "…Waaaaaaah ! Tu es méchant !\p"
    .string "Tu ne devrais pas être si sérieux ! Toi…\n"
    .string "toi, petit !$"

GoldenrodCity_Gym_Text_WhitneyYouMeanie:
    .string "Ouuaaaah !\p"
    .string "Ouuaaaah !\p"
    .string "…Snif, hic… …Méchant !$"

GoldenrodCity_Gym_Text_WhitneyWhatDoYouWant:
    .string "…Sniff…\p"
    .string "Quoi ? Qu'est-ce que tu veux ? Un BADGE ?\p"
    .string "Oh, oui. J'avais oublié. Voici\n"
    .string "le BADGE BASIQUE.$"

GoldenrodCity_Gym_Text_PlayerReceivedPlainBadge:
    .string "{PLAYER} a reçu le BADGE PLAINE.$"

GoldenrodCity_Gym_Text_WhitneyPlainBadge:
    .string "Le BADGE PLAINE permet à tes POKéMON d'utiliser\n"
    .string "FORCE hors combat.\p"
    .string "Il augmente aussi la DÉFENSE\n"
    .string "de tes POKéMON.\p"
    .string "Oh, tu peux avoir ça aussi !$"

GoldenrodCity_Gym_Text_WhitneyAttract:
    .string "C'est ATTRACTION ! Ça exploite au maximum\n"
    .string "le charme d'un POKéMON.\p"
    .string "N'est-ce pas parfait pour une mignonne\n"
    .string "comme moi ?$"

GoldenrodCity_Gym_Text_WhitneyGoodCry:
    .string "Ah, c'était une bonne crise de larmes !$"

GoldenrodCity_Gym_Text_WhitneyRematch:
    .string "Salut ! C'est toi !\p"
    .string "Wow, CHAMPION de JOHTO maintenant ?\p"
    .string "Tu es vraiment incroyable !\p"
    .string "Je veux voir à quel point tu es fort.\p"
    .string "Envie d'une revanche avec moi ?$"

GoldenrodCity_Gym_Text_WhitneyRematchDefeat:
    .string "Ouuaaaah !\p"
    .string "Ouuaaaah !\p"
    .string "…Snif, hic… …Méchant !$"

GoldenrodCity_Gym_Text_LassCarrieSeen:
    .string "Ne te laisse pas tromper par la mine mignonne\n"
    .string "de mes POKéMON.\p"
    .string "Ils peuvent te battre !$"

GoldenrodCity_Gym_Text_LassCarrieBeaten:
    .string "Zut… Je pensais que tu étais faible…$"

GoldenrodCity_Gym_Text_LassCarrieAfter:
    .string "Mes POKéMON me trouvent-ils mignon ?$"

GoldenrodCity_Gym_Text_LassBridgetSeen:
    .string "J'aime les POKéMON mignons plus que\n"
    .string "les POKéMON forts.\p"
    .string "Mais j'ai des POKéMON forts et mignons !$"

GoldenrodCity_Gym_Text_LassBridgetBeaten:
    .string "Oh, non, non, non !$"

GoldenrodCity_Gym_Text_LassBridgetAfter:
    .string "J'essaie de battre CAROLINE, mais...\n"
    .string "C'est déprimant.\p"
    .string "Ça va ! Si je perds, j'essaierai\n"
    .string "encore plus fort la prochaine fois !$"

GoldenrodCity_Gym_Text_BridgetWhitneyCries:
    .string "Oh, non. Tu as fait pleurer BLONDIN.\p"
    .string "C'est bon. Elle s'arrêtera bientôt. Elle\n"
    .string "pleure toujours quand elle perd.$"

GoldenrodCity_Gym_Text_BeautyVictoriaSeen:
    .string "Oh, tu es un petit DRESSEUR mignon !\p"
    .string "Je t'aime bien, mais je ne vais pas faire de cadeau !$"

GoldenrodCity_Gym_Text_BeautyVictoriaBeaten:
    .string "Voyons… Oups, c'est fini ?$"

GoldenrodCity_Gym_Text_BeautyVictoriaAfter:
    .string "Waouh, tu dois être fort pour me battre !\n"
    .string "Continue comme ça !$"

GoldenrodCity_Gym_Text_BeautySamanthaSeen:
    .string "Donne tout ce que tu as, ou je\n"
    .string "te terrasse !$"

GoldenrodCity_Gym_Text_BeautySamanthaBeaten:
    .string "Non ! Oh, MIAOUSS, je suis désolée !$"

GoldenrodCity_Gym_Text_BeautySamanthaAfter:
    .string "J'ai appris des capacités à MIAOUSS pour\n"
    .string "affronter tous les types…$"

GoldenrodCity_Gym_Text_GymGuide:
    .string "Yo ! Futur\p"
    .string "CHAMPION !\n"
    .string "Cette ARÈNE abrite\p"
    .string "FELICITE, la\p"
    .string "maîtresse des POKéMON\n"
    .string "de type NORMAL.\l"
    .string "Fais attention\p"
    .string "à ses combos !\n"
    .string "Bonne chance !$"

GoldenrodCity_Gym_Text_GymGuideWin:
    .string "Tu as gagné ? Génial ! J'étais occupé\n"
    .string "à admirer les dames ici.$"

