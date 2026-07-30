MahoganyTown_Gym_MapScripts::
	.byte 0


MahoganyTown_Gym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM,  MahoganyTown_Gym_EventScript_Statue2
	msgbox MahoganyTown_Gym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

MahoganyTown_Gym_EventScript_Statue2::
	msgbox MahoganyTown_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

MahoganyTown_Gym_Text_GymStatue:
	.string "MAHOGANYVILLE ARENE POKéMON$"

MahoganyTown_Gym_Text_GymStatueCertified:
	.string "MAHOGANYVILLE ARENE POKéMON\p"
	.string "DRESSEURS CERTIFIÉS DE PRYCE :\n"
	.string "{PLAYER}$"


MahoganyTown_GymEventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM, MahoganyTown_Gym_EventScript_GymGuy2
	msgbox MahoganyTown_Gym_Text_Guide, MSGBOX_DEFAULT
	closemessage
	release
	end
	
MahoganyTown_Gym_EventScript_GymGuy2::
	msgbox MahoganyTown_Gym_Text_GuideWin, MSGBOX_DEFAULT
	release
	end	

MahoganyTown_Gym_EventScript_Ronald::
	trainerbattle_single TRAINER_RONALD MahoganyTown_Gym_Text_BoarderRonaldSeen, MahoganyTown_Gym_Text_BoarderRonaldBeaten
	msgbox MahoganyTown_Gym_Text_BoarderRonaldAfter, MSGBOX_AUTOCLOSE
	end

MahoganyTown_Gym_EventScript_Brad::
	trainerbattle_single TRAINER_BRAD MahoganyTown_Gym_Text_BoarderBradSeen, MahoganyTown_Gym_Text_BoarderBradBeaten
	msgbox MahoganyTown_Gym_Text_BoarderBradAfter, MSGBOX_AUTOCLOSE
	end

MahoganyTown_Gym_EventScript_Douglas::
	trainerbattle_single TRAINER_DOUGLAS MahoganyTown_Gym_Text_BoarderDouglasSeen, MahoganyTown_Gym_Text_BoarderDouglasBeaten
	msgbox MahoganyTown_Gym_Text_BoarderDouglasAfter, MSGBOX_AUTOCLOSE
	end

MahoganyTown_Gym_EventScript_Roxanne::
	trainerbattle_single TRAINER_ROXANNE MahoganyTown_Gym_Text_SkierRoxanneSeen, MahoganyTown_Gym_Text_SkierRoxanneBeaten
	msgbox MahoganyTown_Gym_Text_SkierRoxanneAfter, MSGBOX_AUTOCLOSE
	end

MahoganyTown_Gym_EventScript_Clarissa::
	trainerbattle_single TRAINER_CLARISSA MahoganyTown_Gym_Text_SkierClarissaSeen, MahoganyTown_Gym_Text_SkierClarissaBeaten
	msgbox MahoganyTown_Gym_Text_SkierClarissaAfter, MSGBOX_AUTOCLOSE
	end

MahoganyTown_Gym_EventScript_Pryce::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_MAHOGANY_TOWN_GYM, MahoganyTown_Gym_EventScript_Pryce_Defeated
	msgbox MahoganyTown_Gym_Text_PryceIntro, MSGBOX_DEFAULT
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, MahoganyTown_Gym_EventScript_OlivineCheckCianwood
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, MahoganyTown_Gym_EventScript_CianwoodCheckOlivine
	goto MahoganyTown_Gym_EventScript_Pryce_Battle1

MahoganyTown_Gym_EventScript_PryceVictory::
	message MahoganyTown_Gym_Text_ReceivedBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MahoganyTown_Gym_Text_GlacierBadgeSpeech, MSGBOX_DEFAULT
	setflag FLAG_BADGE07_GET
	setflag FLAG_DEFEATED_MAHOGANY_TOWN_GYM
    addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 7
	call Common_EventScript_SetGymTrainers
	giveitem ITEM_TM_HAIL
	msgbox MahoganyTown_Gym_Text_HailSpeech, MSGBOX_DEFAULT
	setvar VAR_MAHOGANY_TOWN_STATE, 15
    setrespawn HEAL_LOCATION_MAHOGANYTOWN
	closemessage
	release
	end

MahoganyTown_Gym_EventScript_OlivineCheckCianwood::
	goto_if_set FLAG_DEFEATED_CIANWOOD_GYM, MahoganyTown_Gym_EventScript_Pryce_Battle3
	goto MahoganyTown_Gym_EventScript_Pryce_Battle2

MahoganyTown_Gym_EventScript_CianwoodCheckOlivine::
	goto_if_set FLAG_DEFEATED_OLIVINE_CITY_GYM, MahoganyTown_Gym_EventScript_Pryce_Battle3
	goto MahoganyTown_Gym_EventScript_Pryce_Battle2
	
MahoganyTown_Gym_EventScript_Pryce_Battle1::
	trainerbattle_no_intro TRAINER_PRYCE_1, MahoganyTown_Gym_Text_PryceImpressed
	goto MahoganyTown_Gym_EventScript_PryceVictory

MahoganyTown_Gym_EventScript_Pryce_Battle2::
	trainerbattle_no_intro TRAINER_PRYCE_1_2, MahoganyTown_Gym_Text_PryceImpressed
	goto MahoganyTown_Gym_EventScript_PryceVictory

MahoganyTown_Gym_EventScript_Pryce_Battle3::
	trainerbattle_no_intro TRAINER_PRYCE_1_3, MahoganyTown_Gym_Text_PryceImpressed
	goto MahoganyTown_Gym_EventScript_PryceVictory

MahoganyTown_Gym_EventScript_Pryce_Defeated::
	msgbox MahoganyTown_Gym_Text_CherishPokemon, MSGBOX_DEFAULT
	closemessage
	release
	end

MahoganyTown_Gym_Text_PryceIntro:
    .string "POKéMON have many experiences\n"
    .string "in their lives, just like we do.\p"
    .string "I, too, have seen and suffered\n"
    .string "much in my life.\p"
    .string "Since I am your elder, let me\n"
    .string "show you what I mean.\p"
    .string "I have been with POKéMON since\n"
    .string "before you were born.\p"
    .string "I do not lose easily.\p"
    .string "I, PRYCE--the winter trainer--\n"
    .string "shall demonstrate my power!$"

MahoganyTown_Gym_Text_PryceImpressed:
    .string "Ah, je suis impressionné par ta\n"
    .string "prouesse.\p"
    .string "Avec ta volonté forte, je sais que tu\n"
    .string "surmonteras tous les obstacles de la vie.\p"
    .string "Tu mérites ce BADGE !$"

MahoganyTown_Gym_Text_ReceivedBadge:
    .string "{PLAYER} a reçu le BADGE GLACIER.$"

MahoganyTown_Gym_Text_GlacierBadgeSpeech:
    .string "Ce BADGE augmentera l'ATTAQUE\n"
    .string "SPÉCIALE des POKéMON.\p"
    .string "Il permet aussi à tes POKéMON d'utiliser\n"
    .string "TOURBILLON pour traverser\l"
    .string "de vrais tourbillons.\p"
    .string "Et ça… C'est un cadeau de ma part !$"

MahoganyTown_Gym_Text_HailSpeech:
    .string "Cette CT contient GRELON.\p"
    .string "Elle inflige des dégâts\n"
    .string "à chaque tour pendant\p"
    .string "5 tours. Elle démontre\n"
    .string "la dureté de l'hiver.$"

MahoganyTown_Gym_Text_CherishPokemon:
    .string "Quand la glace et la neige fondent,\n"
    .string "le printemps arrive.\p"
    .string "Toi et tes POKéMON serez\n"
    .string "ensemble pendant de nombreuses années.\p"
    .string "Chéris ce temps passé ensemble !$"

MahoganyTown_Gym_Text_PryceRematch:
    .string "Ah, CHAMPION DE JOHTO !\p"
    .string "Tes compétences sont en effet\n"
    .string "remarquables. Je suis impressionné. Mais\p"
    .string "même maintenant, on a encore\p"
    .string "beaucoup à apprendre l'un de\n"
    .string "l'autre. Moi, FRÉDÉRIC--le dresseur d'hiver--\p"
    .string "J'ai encore quelques tours dans\n"
    .string "mon sac. Tu veux une\p"
    .string "revanche avec moi ?$"

MahoganyTown_Gym_Text_PryceRematchDefeat:
    .string "Ah, encore une fois, je suis\n"
    .string "impressionné par tes prouesses. Avec ta\p"
    .string "volonté, je sais que tu surmonteras\n"
    .string "tous les obstacles de la vie.$"

MahoganyTown_Gym_Text_Guide:
    .string "FRÉDÉRIC est un vétéran\n"
    .string "qui entraîne des POKéMON\p"
    .string "depuis environ 50\n"
    .string "ans. Il a\l"
    .string "une solide équipe\p"
    .string "de POKéMON GLACE.\n"
    .string "Une revanche ?$"

MahoganyTown_Gym_Text_GuideWin:
    .string "FREDO est quelque chose, mais toi,\n"
    .string "tu es autre chose !\p"
    .string "C'était un combat chaud qui a\n"
    .string "franchi le fossé des générations !$"

MahoganyTown_Gym_Text_BoarderRonaldSeen:
    .string "Je vais geler tes POKéMON,\n"
    .string "alors tu ne pourras rien faire !$"

MahoganyTown_Gym_Text_BoarderRonaldBeaten:
    .string "Zut. Je n'ai rien pu faire.$"

MahoganyTown_Gym_Text_BoarderRonaldAfter:
    .string "Je crois qu'il y a une capacité qu'un\n"
    .string "POKéMON peut utiliser quand il est\l"
    .string "gelé.$"

MahoganyTown_Gym_Text_BoarderBradSeen:
    .string "Cette ARÈNE a un sol glissant.\p"
    .string "C'est amusant, non ?\p"
    .string "Mais bon - on ne joue pas\n"
    .string "ici !$"

MahoganyTown_Gym_Text_BoarderBradBeaten:
    .string "Tu vois à quel point nous sommes sérieux ?$"

MahoganyTown_Gym_Text_BoarderBradAfter:
    .string "Cette ARÈNE est géniale.\n"
    .string "J'adore faire du snowboard avec mes\l"
    .string "POKéMON !$"

MahoganyTown_Gym_Text_BoarderDouglasSeen:
    .string "Je connais le secret de FREDO.$"

MahoganyTown_Gym_Text_BoarderDouglasBeaten:
    .string "OK. Je vais te dire le secret de FREDDY.$"

MahoganyTown_Gym_Text_BoarderDouglasAfter:
    .string "Le secret de la puissance de FREDO...\p"
    .string "Il médite sous une cascade\n"
    .string "chaque jour pour renforcer son esprit\l"
    .string "et son corps.$"

MahoganyTown_Gym_Text_SkierRoxanneSeen:
    .string "Pour atteindre PRYCE, notre CHAMPION\n"
    .string "d'ARÈNE, il faut réfléchir avant de patiner.$"

MahoganyTown_Gym_Text_SkierRoxanneBeaten:
    .string "Je ne t'aurais pas battu au ski !$"

MahoganyTown_Gym_Text_SkierRoxanneAfter:
    .string "Si tu ne patines pas avec précision,\n"
    .string "tu n'iras pas loin dans cette ARÈNE.$"

MahoganyTown_Gym_Text_SkierClarissaSeen:
    .string "Regarde mon virage parallèle !$"

MahoganyTown_Gym_Text_SkierClarissaBeaten:
    .string "Non ! Tu m'as fait tomber !$"

MahoganyTown_Gym_Text_SkierClarissaAfter:
    .string "Je n'aurais pas dû me vanter\n"
    .string "de mon ski…$"

