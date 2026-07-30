VioletCity_Gym_MapScripts::
	.byte 0

VioletCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_VIOLET_GYM, VioletCity_Gym_EventScript_GymGuy2
	msgbox VioletGym_Text_GymGuide_Intro, MSGBOX_DEFAULT
	closemessage
	release
	end
	
VioletCity_Gym_EventScript_GymGuy2::
	msgbox VioletGym_Text_GymGuide_Win, MSGBOX_DEFAULT
	release
	end	

VioletCity_Gym_EventScript_Rod::
	trainerbattle_single TRAINER_ROD VioletGym_Text_BirdKeeperRod_Seen, VioletGym_Text_BirdKeeperRod_Beaten
	msgbox VioletGym_Text_BirdKeeperRod_After, MSGBOX_AUTOCLOSE
	end

VioletCity_Gym_EventScript_Abe::
	trainerbattle_single TRAINER_ABE VioletGym_Text_BirdKeeperAbe_Seen, VioletGym_Text_BirdKeeperAbe_Beaten
	msgbox VioletGym_Text_BirdKeeperAbe_After, MSGBOX_AUTOCLOSE
	end

VioletCity_Gym_EventScript_Falkner::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_VIOLET_GYM, VioletCity_Gym_EventScript_Falkner_Defeated
	msgbox VioletGym_Text_Falkner_Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_FALKNER_1, VioletGym_Text_Falkner_WinLoss
	message VioletGym_Text_ReceivedZephyrBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox VioletGym_Text_Falkner_BadgeExplain, MSGBOX_DEFAULT
	setflag FLAG_BADGE01_GET
	setflag FLAG_DEFEATED_VIOLET_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 1
	call Common_EventScript_SetGymTrainers
	giveitem ITEM_TM_DOUBLE_TEAM
	msgbox VioletGym_Text_Falkner_TMExplain, MSGBOX_DEFAULT
	setvar VAR_VIOLET_CITY_STATE, 3
	setrespawn HEAL_LOCATION_VIOLET_CITY
	closemessage
	release
	end

VioletCity_Gym_EventScript_Falkner_Defeated::
	msgbox VioletGym_Text_Falkner_AfterFight, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletGym_Text_Falkner_Intro:
	.string "Je suis FALKNER, le CHAMPION\n"
	.string "d'ARÈNE POKéMON de MAUVILLE !\p"
	.string "On dit qu'on peut couper les ailes\n"
	.string "des POKéMON de type VOL avec une\p"
	.string "décharge électrique…\n"
	.string "Je n'autoriserai pas de telles\l"
	.string "insultes envers les POKéMON\p"
	.string "oiseau !\n"
	.string "Je vais te montrer la vraie puissance des magnifiques POKéMON oiseau !$"

VioletGym_Text_Falkner_WinLoss:
	.string "…Zut ! Le POKéMON oiseau\n"
	.string "précieux de mon père…\p"
	.string "D'accord. Prends ça. C'est\p"
	.string "le BADGE ZEPHYR officiel\n"
	.string "de la LIGUE POKéMON.$"

VioletGym_Text_ReceivedZephyrBadge:
	.string "{PLAYER} a reçu le BADGE ZÉPHYR.$"

VioletGym_Text_Falkner_BadgeExplain:
	.string "Le BADGE ZÉPHYR augmente la puissance\n"
	.string "d'ATTAQUE des POKéMON.\p"
	.string "Il permet aussi aux POKéMON d'utiliser\n"
	.string "FLASH, s'ils peuvent l'apprendre,\l"
	.string "à tout moment.\p"
	.string "Tiens, prends ça aussi.$"

VioletGym_Text_Falkner_TMExplain:
	.string "En utilisant une CT, un POKéMON\n"
	.string "apprend instantanément une nouvelle attaque.\p"
	.string "La CT32 contient REFLET.\p"
	.string "Elle augmente l'esquive d'un POKéMON.\p"
	.string "En d'autres termes, ton POKéMON\n"
	.string "sera plus difficile à toucher.$"

VioletGym_Text_Falkner_AfterFight:
	.string "Il y a des ARENES POKéMON dans les\n"
	.string "villes plus loin.\p"
	.string "Tu devrais tester tes compétences\n"
	.string "dans ces ARENES.\p"
	.string "Je vais m'entraîner plus dur pour\n"
	.string "devenir le plus grand maître des oiseaux !$"

VioletGym_Text_Falkner_Rematch:
	.string "Félicitations pour avoir battu\n"
	.string "les 4 DUOS SUPRÊMES !\p"
	.string "J'ai entraîné mes POKéMON\n"
	.string "de type VOL encore plus dur.\p"
	.string "Tu penses pouvoir affronter à nouveau\n"
	.string "la puissance des cieux ?$"

VioletGym_Text_Falkner_RematchLoss:
	.string "Waouh… Tu m'as encore battu.\p"
	.string "Je vais m'entraîner plus dur pour\n"
	.string "devenir le plus grand maître des oiseaux !$"

VioletGym_Text_BirdKeeperRod_Seen:
	.string "Le mot d'ordre, c'est le cran !\p"
	.string "Ceux qui sont ici s'entraînent jour et nuit\n"
	.string "pour devenir maîtres des POKéMON OISEAU.\p"
	.string "Allez !$"

VioletGym_Text_BirdKeeperRod_Beaten:
	.string "Aaah !$"

VioletGym_Text_BirdKeeperRod_After:
	.string "Les compétences de FALKNER sont réelles !\p"
	.string "Ne te laisse pas aller juste parce\n"
	.string "que tu m'as battu !$"

VioletGym_Text_BirdKeeperAbe_Seen:
	.string "Voyons si tu es assez bon\n"
	.string "pour affronter ALIZE !$"

VioletGym_Text_BirdKeeperAbe_Beaten:
	.string "Ce n'est pas possible !$"

VioletGym_Text_BirdKeeperAbe_After:
	.string "C'est pathétique, perdre contre\n"
	.string "un DRESSEUR débutant…$"

VioletGym_Text_GymGuide_Intro:
	.string "Hé ! Quoi de neuf ? Je ne suis pas dresseur,\n"
	.string "mais je peux donner des conseils !\p"
	.string "Crois-moi ! Si tu crois, un\n"
	.string "rêve de championnat peut devenir réalité.\p"
	.string "Tu crois ? Alors écoute.\p"
	.string "L'as de FALKNER est un hibou costaud\n"
	.string "qui adore manger des BAIES.\p"
	.string "Bien qu'il ne soit pas le plus fort,\n"
	.string "il peut encaisser beaucoup de coups.\p"
	.string "Tu peux le blesser avec des capacités de type\n"
	.string "ÉLECTRIK et ROCHE, mais attention à\l"
	.string "JET-BOUE !\p"
	.string "Si tu veux plus d'aide, va visiter\n"
	.string "l'ACADÉMIE POKéMON.\p"
	.string "Les élèves là-bas connaissent vraiment\n"
	.string "leur sujet !$"

VioletGym_Text_GymGuide_Win:
	.string "Beau combat ! Continue comme ça\n"
	.string "et tu seras CHAMPION en un rien\l"
	.string "detemps !$"

VioletCity_Gym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_VIOLET_GYM, VioletCity_Gym_EventScript_Statue2
	msgbox VioletCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_Gym_EventScript_Statue2::
	msgbox VioletCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

VioletCity_Gym_Text_GymStatue:
	.string "MAUVILLE ARENE POKéMON$"

VioletCity_Gym_Text_GymStatueCertified:
	.string "MAUVILLE ARENE POKéMON\p"
	.string "DRESSEURS CERTIFIÉS DE FALKNER :\n"
	.string "{PLAYER}$"
