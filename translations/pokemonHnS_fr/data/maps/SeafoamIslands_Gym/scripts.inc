SeafoamIslands_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SeafoamIslands_Gym_OnTransition
	.byte 0

SeafoamIslands_Gym_OnTransition: 
	setflag FLAG_TEMP_1
	end

SeafoamIslands_Gym_EventScript_Blaine::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_CINNABAR_ISLAND_GYM, SeafoamIslands_Gym_EventScript_Blaine_Defeated
	msgbox SeafoamIslands_Gym_Text_BlaineIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_BLAINE, SeafoamIslands_Gym_Text_BlaineWinLoss
	message SeafoamIslands_Gym_Text_ReceivedVolcanoBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox SeafoamIslands_Gym_Text_TM, MSGBOX_DEFAULT
	giveitem ITEM_TM_OVERHEAT
	setflag FLAG_BADGE15_GET
	setflag FLAG_DEFEATED_CINNABAR_ISLAND_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 15
	clearflag FLAG_HIDE_SEAFOAM_GYMGUY
	call Common_EventScript_SetGymTrainers
	closemessage
	release
	end

SeafoamIslands_Gym_EventScript_Blaine_Defeated::
	msgbox SeafoamIslands_Gym_Text_BlaineAfterBattle, MSGBOX_DEFAULT
	closemessage
	release
	end

SeafomIslands2_EventScript_GymGuide::
	goto_if_set FLAG_TEMP_2, SeafomIslands2_EventScript_GymGuide2
	msgbox SeafoamIslands_Gym_Text_GymGuideWin, MSGBOX_NPC
	setflag FLAG_TEMP_2
	end
SeafomIslands2_EventScript_GymGuide2::
	msgbox SeafoamIslands_Gym_Text_GymGuideWin2, MSGBOX_NPC
	end

SeafoamIslands_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE15_GET, SeafoamIslands_Gym_EventScript_GymStatuePostVictory
	msgbox SeafoamIslands_Gym_Text_GymStatue
	releaseall
	end

SeafoamIslands_Gym_EventScript_GymStatuePostVictory::
	msgbox SeafoamIslands_Gym_Text_GymStatuePlayerWon
	releaseall
	end

SeafoamIslands_Gym_Text_GymStatue::
    .string "CINNABAR ARENE POKéMON\n"
    .string "CHAMPION : AUGUSTE\p"
    .string "DRESSEURS VAINQUEURS :\n"
    .string "BLUE, RED$"

SeafoamIslands_Gym_Text_GymStatuePlayerWon::
    .string "ARÈNE POKéMON DE CRAMOIS'ÎLE\n"
    .string "CHAMPION : AUGUSTE\p"
    .string "DRESSEURS VAINQUEURS :\n"
    .string "BLEU, ROUGE, {PLAYER}$"

SeafoamIslands_Gym_Text_TM:
	.string "Prends ça aussi. Cette CT contient\n"
	.string "la formidable Surchauffe. J'espère que ton\p"
	.string "prochain adversaire aura un Anti-Brûle\n"
	.string "en plus ! Waaah !$"
SeafoamIslands_Gym_Text_BlaineIntro:
	.string "AUGUSTE : Waaah !\p"
	.string "Mon ARÈNE à\p"
	.string "CRAMOIS'ÎLE a brûlé.\n"
	.string "Mes POKéMON\p"
	.string "cracheurs\p"
	.string "de feu et moi sommes\n"
	.string "sans-abri à\p"
	.string "cause de ça.\n"
	.string "Mais je ne\p"
	.string "renonce pas !$"

SeafoamIslands_Gym_Text_BlaineWinLoss:
	.string "AUGUSTE : Génial. Je suis à bout…\p"
	.string "Tu as gagné le BADGE VOLCAN !$"

SeafoamIslands_Gym_Text_ReceivedVolcanoBadge:
	.string "{PLAYER} a reçu le BADGE VOLCAN.$"

SeafoamIslands_Gym_Text_BlaineAfterBattle:
	.string "AUGUSTE : J'ai perdu cette fois, mais\n"
	.string "je gagnerai la prochaine.\p"
	.string "Quand je reconstruirai mon ARÈNE de CRAMOIS'ÎLE,\n"
	.string "on devra avoir une revanche.$"

SeafoamIslands_Gym_Text_BlaineFightDone:
	.string "AUGUSTE : Mes POKéMON de feu seront\n"
	.string "encore plus forts.\p"
	.string "Tu verras !$"

SeafoamIslands_Gym_Text_BlaineRematch:
	.string "AUGUSTE : Whoa !\p"
	.string "Je vois que tu es devenu le CHAMPION\n"
	.string "DE KANTO !\p"
	.string "C'est brûlant !\p"
	.string "Tes talents sont de premier ordre.\p"
	.string "Je suis toujours partant pour un combat.\p"
	.string "Tu veux une revanche avec moi ?$"

SeafoamIslands_Gym_Text_BlaineRematchDefeat:
	.string "AUGUSTE : Tes compétences sont vraiment ardentes !\p"
	.string "Tu as brûlé toutes mes\n"
	.string "défenses.$"

SeafoamIslands_Gym_Text_GymGuideWin:
	.string "Hé !\p"
	.string "… Hein ? C'est déjà fini ?\p"
	.string "Désolé, désolé !\p"
	.string "L'ARÈNE de CRAMOIS'ÎLE avait disparu, alors je\n"
	.string "ne savais pas où te trouver.\p"
	.string "Mais tu es déjà très fort même\n"
	.string "sans mes conseils. Je savais que tu gagnerais !$"

SeafoamIslands_Gym_Text_GymGuideWin2:
	.string "Une ARÈNE POKéMON peut être n'importe où\n"
	.string "tant que le CHAMPION D'ARÈNE est là.\p"
	.string "Pas besoin d'un bâtiment.$"
