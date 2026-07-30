.set LOCALID_CINNABAR_BLUE, 1
.set LOCALID_CINNABAR_BLAINE, 12

CinnabarIsland_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CinnabarIsland_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0
	
CinnabarIsland_OnTransition:
	setflag FLAG_VISITED_CINNABAR_ISLAND
	callnative SetTimeBasedEncounters
	end

CinnabarIsland_EventScript_Blaine::
    lock
    faceplayer
    msgbox CinnabarIsland_Text_Blaine, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_CINNABAR_BLAINE
    removeobject LOCALID_CINNABAR_BLAINE
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_BLAINE
    release
    end

CinnabarIsland_Text_Blaine:
    .string "AUGUSTE : Je n'abandonnerai jamais\n"
    .string "jusqu'au jour où j'aurai\l"
    .string "reconstruit l'ARÈNE de CRAMOIS'ÎLE\p"
    .string "! Je serai au\n"
    .string "DOJO DE COMBAT jusque-là.$"



CinnabarIsland_EventScript_Blue::
	lock
	faceplayer
	goto_if_eq VAR_NUM_BADGES, 15, CinnabarIsland_EventScript_BlueActive
	msgbox CinnabarIsland_Text_BlueBefore, MSGBOX_NPC
	release
	end

CinnabarIsland_EventScript_BlueActive::
	msgbox CinnabarIsland_Text_Blue, MSGBOX_NPC
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_CINNABAR_BLUE
	removeobject LOCALID_CINNABAR_BLUE
	clearflag FLAG_HIDE_VIRIDIAN_BLUE
	fadescreenswapbuffers FADE_FROM_BLACK
	release
	end


CinnabarIsland_Text_BlueBefore:
	.string "Qui es-tu ?\p"
	.string "Eh bien, on voit bien que tu es\n"
	.string "un dresseur…\p"
	.string "Je m'appelle BLUE.\p"
	.string "J'ai été CHAMPION, mais\n"
	.string "pendant peu de temps…\p"
	.string "Ce fichu RED m'a eu…\p"
	.string "Bref, qu'est-ce que tu veux ? Tu veux\n"
	.string "me défier ou quoi ?\p"
	.string "…Je déteste le dire, mais je ne suis pas\n"
	.string "d'humeur à combattre maintenant.\p"
	.string "Regarde bien autour de toi…\p"
	.string "Un volcan entre en éruption, et comme\n"
	.string "ça, une ville entière disparaît.\p"
	.string "On peut continuer à gagner et perdre en\n"
	.string "POKéMON. Mais si la nature fronce les sourcils,\l"
	.string "on peut tout perdre en une seconde.\p"
	.string "…\p"
	.string "C'est comme ça…\p"
	.string "Mais bon, je suis toujours un dresseur.\p"
	.string "Si je vois un adversaire fort,\n"
	.string "j'ai envie de me battre.\p"
	.string "Si tu veux me défier, il te faudra\n"
	.string "d'abord 15 BADGES.\p"
	.string "Je t'affronterai alors.$"

CinnabarIsland_Text_Blue:
	.string "Qui es-tu ?\p"
	.string "Eh bien, on voit bien que tu es\n"
	.string "un dresseur…\p"
	.string "Je m'appelle BLUE.\p"
	.string "J'ai été CHAMPION, mais\n"
	.string "pendant peu de temps…\p"
	.string "Ce fichu RED m'a eu…\p"
	.string "Bref, qu'est-ce que tu veux ? Tu veux\n"
	.string "me défier ou quoi ?\p"
	.string "…Je déteste le dire, mais je ne suis pas\n"
	.string "d'humeur à combattre maintenant.\p"
	.string "Regarde bien autour de toi…\p"
	.string "Un volcan entre en éruption, et comme\n"
	.string "ça, une ville entière disparaît.\p"
	.string "On peut continuer à gagner et perdre en\n"
	.string "POKéMON. Mais si la nature fronce les sourcils,\l"
	.string "on peut tout perdre en une seconde.\p"
	.string "…\p"
	.string "C'est comme ça…\p"
	.string "Mais bon, je suis toujours un dresseur.\p"
	.string "Si je vois un adversaire fort,\n"
	.string "j'ai envie de me battre.\p"
	.string "Si tu veux me défier, viens à\n"
	.string "l'ARÈNE de JADIELLE.\p"
	.string "Je t'affronterai alors.$"

CinnabarIsland_EventScript_Sign::
	msgbox CinnabarIsland_Text_Sign, MSGBOX_SIGN
	end

CinnabarIsland_EventScript_GymSign::
	msgbox CinnabarIsland_Text_GymSign, MSGBOX_SIGN
	end

CinnabarIsland_Text_GymSign:
	.string "Il y a un avis ici…\p"
	.string "L'ARÈNE de CRAMOIS'ÎLE a déménagé aux\n"
	.string "ÎLES ECUME.\p"
	.string "AUGUSTE$"

CinnabarIsland_Text_Sign:
	.string "CRAMOIS'ÎLE\p"
	.string "La ville ardente du désir brûlant$"

