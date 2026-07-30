PewterCity_Gym_MapScripts::
	.byte 0



PewterCity_Gym_EventScript_Jerry::
	trainerbattle_single TRAINER_JERRY, PewterCity_Gym_Text_CamperJerry_Seen, PewterCity_Gym_Text_CamperJerry_Beaten
	msgbox PewterCity_Gym_Text_CamperJerry_AfterBattle, MSGBOX_AUTOCLOSE
	end

PewterCity_Gym_EventScript_Brock::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_PEWTER_GYM, PewterCity_Gym_EventScript_Brock_Defeated
	msgbox PewterCity_Gym_Text_Brock_Intro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_BROCK, PewterCity_Gym_Text_Brock_WinLoss
	message PewterCity_Gym_Text_ReceivedBoulderBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox PewterCity_Gym_Text_Brock_FightDone, MSGBOX_DEFAULT
	giveitem ITEM_TM_EARTHQUAKE
	setflag FLAG_BADGE09_GET
	setflag FLAG_DEFEATED_PEWTER_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 9
	call Common_EventScript_SetGymTrainers
	clearflag FLAG_HIDE_DIGLETT_BROCK
	closemessage
	release
	end

PewterCity_Gym_EventScript_Brock_Defeated::
	msgbox PewterCity_Gym_Text_Brock_FightDone, MSGBOX_DEFAULT
	closemessage
	release
	end


PewterCity_Gym_Text_Brock_Intro:
	.string "PIERRE : Waouh, on n'a pas souvent\n"
	.string "de challenger de JOHTO.\p"
	.string "Je suis PIERRE, le CHAMPION\p"
	.string "d'ARÈNE de JADIELLE.\p"
	.string "Je suis un expert des POKéMON\n"
	.string "de type ROCHE.\l"
	.string "Mes POKéMON sont imperméables\p"
	.string "à la plupart des attaques physiques. Tu auras du mal à leur infliger des dégâts. Allez, viens !$"

PewterCity_Gym_Text_Brock_WinLoss:
	.string "PIERRE : Les attaques puissantes de tes POKéMON\n"
	.string "ont surmonté ma défense rocheuse…\p"
	.string "Tu es plus fort que je ne pensais…\p"
	.string "Vas-y - prends ce BADGE.$"

PewterCity_Gym_Text_ReceivedBoulderBadge:
	.string "{PLAYER} a reçu le BADGE ROCHE.$"

PewterCity_Gym_Text_Brock_BoulderBadge:
	.string "PIERRE : {PLAYER}, merci. J'ai apprécié\n"
	.string "notre combat, même si je suis un peu\l"
	.string "déçu.\p"
	.string "Ce BADGE ROCHE rendra tes\n"
	.string "POKéMON encore plus puissants.$"

PewterCity_Gym_Text_Brock_FightDone:
	.string "PIERRE : Le monde est immense. Il y a\n"
	.string "encore beaucoup de DRESSEURS forts comme toi.\p"
	.string "Attends et vois. Je vais devenir\n"
	.string "beaucoup plus fort aussi.$"

PewterCity_Gym_Text_CamperJerry_Seen:
	.string "Les Dresseurs de cette ARÈNE utilisent des POKéMON\n"
	.string "de type ROCHE.\p"
	.string "Le type ROCHE a une DEFENSE élevée.\p"
	.string "Les combats pourraient durer longtemps.\n"
	.string "Tu es prêt pour ça ?$"

PewterCity_Gym_Text_CamperJerry_Beaten:
	.string "Je dois gagner ces combats…$"

PewterCity_Gym_Text_CamperJerry_AfterBattle:
	.string "Hé, toi ! DRESSEUR de JOHTO ! PIERRE est\n"
	.string "costaud. Il te punira si tu ne le prends\l"
	.string "pas au sérieux.$"

PewterCity_Gym_Text_Guide:
	.string "Yo ! Futur CHAMPION ! Tu assures\n"
	.string "vraiment.\p"
	.string "Tu affrontes les CHAMPIONS D'ARENE\n"
	.string "de KANTO ?\p"
	.string "Ce sont des gens forts et dévoués,\n"
	.string "comme les CHAMPIONS D'ARENE de JOHTO.$"

PewterCity_Gym_Text_Guide_Win:
	.string "Yo ! Futur CHAMPION ! Cette ARÈNE ne t'a pas\n"
	.string "causé trop de problèmes.\p"
	.string "Ta façon de prendre les choses en main était\n"
	.string "vraiment inspirante. Je le dis sérieusement.$"

PewterCity_Gym_EventScript_GymGuy::
	goto_if_set FLAG_DEFEATED_PEWTER_GYM, PewterCity_Gym_EventScript_GymGuyAfter
	msgbox PewterCity_Gym_Text_Guide, MSGBOX_NPC
	end

PewterCity_Gym_EventScript_GymGuyAfter::
	msgbox PewterCity_Gym_Text_Guide_Win, MSGBOX_NPC
	end


PewterCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE09_GET, PewterCity_Gym_EventScript_GymStatuePostVictory
	msgbox PewterCity_Gym_Text_GymStatue
	releaseall
	end

PewterCity_Gym_EventScript_GymStatuePostVictory::
	msgbox PewterCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

PewterCity_Gym_Text_GymStatue::
    .string "ARENE POKéMON D'ARGENTA\n"
    .string "CHAMPION : PIERRE\p"
    .string "DRESSEURS VAINQUEURS :\n"
    .string "BLUE, RED$"

PewterCity_Gym_Text_GymStatuePlayerWon::
    .string "ARÈNE POKéMON DE JADIELLE\n"
    .string "CHAMPION D'ARÈNE : PIERRE\p"
    .string "DRESSEURS VAINQUEURS :\n"
    .string "BLEU, ROUGE, {PLAYER}$"


