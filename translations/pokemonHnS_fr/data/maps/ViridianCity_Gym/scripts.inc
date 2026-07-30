ViridianCity_Gym_MapScripts::
	.byte 0

ViridianCity_Gym_EventScript_Blue::
	lock
	faceplayer
	goto_if_unset FLAG_HIDE_DOJO_BLUE, ViridianCity_Gym_EventScript_BlueAtDojo
	goto_if_set FLAG_DEFEATED_VIRIDIAN_GYM, ViridianCity_Gym_EventScript_BlueGotoDojo
	goto_if_set FLAG_DEFEATED_VIRIDIAN_GYM, ViridianCity_Gym_EventScript_Blue_Defeated
	msgbox ViridianCity_Gym_Text_LeaderBlue_Before, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_BLUE, ViridianCity_Gym_Text_LeaderBlue_Win
	message ViridianCity_Gym_Text_ReceivedEarthBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox ViridianCity_Gym_Text_LeaderBlue_After, MSGBOX_DEFAULT
	giveitem ITEM_TM_BULK_UP
	setflag FLAG_BADGE16_GET
	setflag FLAG_DEFEATED_VIRIDIAN_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 16
	call Common_EventScript_SetGymTrainers
	closemessage
	setflag FLAG_HIDE_LEAGUE_BLACKBELT
	setflag FLAG_HIDE_CERULEANCAVE_GUARD
	setflag FLAG_HIDE_SEAFOAM_BLAINE
	clearflag FLAG_HIDE_CINNABAR_BLAINE
	release
	end

ViridianCity_Gym_EventScript_Blue_Defeated::
	msgbox ViridianCity_Gym_Text_LeaderBlue_Epilogue, MSGBOX_DEFAULT
	closemessage
	release
	end

ViridianCity_Gym_EventScript_BlueGotoDojo::
	msgbox ViridianCity_Gym_Text_BlueGotoDojo, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_DOJO_BLUE
	release
	end

ViridianCity_Gym_Text_BlueGotoDojo:
	.string "BLUE : Déjà de retour ?\p"
	.string "Si tu veux une autre chance contre moi,\n"
	.string "viens au DOJO !$"

ViridianCity_Gym_EventScript_BlueAtDojo::
	msgbox ViridianCity_Gym_Text_LeaderBlue_Epilogue, MSGBOX_DEFAULT
	closemessage
	release
	end

ViridianCity_Gym_Text_LeaderBlue_Before:
	.string "BLUE : Yo ! Tu es\p"
	.string "enfin arrivé, hein ?\p"
	.string "Je n'étais pas d'humeur\p"
	.string "à CRAMOIS'ÎLE,\p"
	.string "mais maintenant je suis\n"
	.string "prêt à te combattre.\p"
	.string "…\n"
	.string "Tu me dis que tu\p"
	.string "as déjà battu\p"
	.string "la LIGUE POKéMON ?\n"
	.string "Humph ! On verra bien !\p"
	.string "Montre-moi ce que tu as !$"

ViridianCity_Gym_Text_LeaderBlue_Win:
	.string "BLUE : Quoi ?\p"
	.string "Comment ai-je pu perdre contre toi ?\p"
	.string "...\p"
	.string "Bon, d'accord... Tiens, prends ça...\n"
	.string "le BADGE TERRE.$"

ViridianCity_Gym_Text_ReceivedEarthBadge:
	.string "{PLAYER} a reçu le BADGE TERRE.$"

ViridianCity_Gym_Text_LeaderBlue_After:
	.string "BLUE : …\p"
	.string "D'accord, j'avais tort. Tu es\n"
	.string "le vrai truc. Tu es un bon DRESSEUR.\p"
	.string "Mais je te battrai un jour.\p"
	.string "N'oublie pas ça !$"

ViridianCity_Gym_Text_LeaderBlue_Epilogue:
	.string "BLUE : Écoute-moi.\p"
	.string "Tu ferais mieux de ne pas perdre avant\n"
	.string "que je t'aie battu. Compris ?$"


ViridianCity_Gym_EventScript_GymGuy::
	goto_if_set FLAG_DEFEATED_VIRIDIAN_GYM, ViridianCity_Gym_EventScript_GymGuyAfter
	msgbox ViridianCity_Gym_Text_Guide, MSGBOX_NPC
	end

ViridianCity_Gym_EventScript_GymGuyAfter::
	msgbox ViridianCity_Gym_Text_Guide_Win, MSGBOX_NPC
	end

ViridianCity_Gym_Text_Guide:
	.string "Hé, futur CHAMPION !\p"
	.string "Comment ça va ? On dirait que tu\n"
	.string "enchaînes les victoires.\p"
	.string "Le CHAMPION D'ARÈNE est un type qui a affronté\n"
	.string "le CHAMPION il y a trois ans.\p"
	.string "Ce n'est pas un mince adversaire.\p"
	.string "Donne tout ce que tu as !$"

ViridianCity_Gym_Text_Guide_Win:
	.string "Mince, tu es vraiment costaud...\p"
	.string "C'était un combat tellement inspirant.\n"
	.string "Ça m'a mis les larmes aux yeux.$"


ViridianCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE16_GET, ViridianCity_Gym_EventScript_GymStatuePostVictory
	msgbox ViridianCity_Gym_Text_GymStatue
	releaseall
	end

ViridianCity_Gym_EventScript_GymStatuePostVictory::
	msgbox ViridianCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

ViridianCity_Gym_Text_GymStatue::
    .string "JADERELLE ARENE POKéMON\n"
    .string "CHAMPION : BLUE\p"
    .string "DRESSEURS VAINQUEURS :\n"
    .string "BLUE, RED$"

ViridianCity_Gym_Text_GymStatuePlayerWon::
    .string "ARÈNE POKéMON DE VERTANIA\n"
    .string "CHAMPION D'ARÈNE : BLEU\p"
    .string "DRESSEURS VAINQUEURS :\n"
    .string "BLEU, ROUGE, {PLAYER}$"

