PacifidlogTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PacifidlogTown_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, PacifidlogTown_OnResume
	.byte 0

PacifidlogTown_OnTransition:
	setflag FLAG_VISITED_CIANWOOD_CITY
	end

PacifidlogTown_OnResume:
	setstepcallback STEP_CB_PACIFIDLOG_BRIDGE
	end

PacifidlogTown_EventScript_NinjaBoy::
	msgbox PacifidlogTown_Text_NeatHousesOnWater, MSGBOX_NPC
	end

PacifidlogTown_EventScript_Girl::
	msgbox PacifidlogTown_Text_FastRunningCurrent, MSGBOX_NPC
	end

PacifidlogTown_EventScript_Fisherman::
	msgbox PacifidlogTown_Text_SkyPillarTooScary, MSGBOX_NPC
	end

PacifidlogTown_EventScript_TownSign::
	msgbox PacifidlogTown_Text_TownSign, MSGBOX_SIGN
	end

PacifidlogTown_Text_FastRunningCurrent:
	.string "La mer entre PACIFIVILLE et\n"
	.string "POIVRESSELLE a un courant rapide.\p"
	.string "Si tu décides d'utiliser SURF, tu pourrais\n"
	.string "être emporté ailleurs.$"

PacifidlogTown_Text_NeatHousesOnWater:
	.string "Tu vois, c'est pas mal ?\n"
	.string "Ces maisons sont sur l'eau !\p"
	.string "Je suis né ici !$"

PacifidlogTown_Text_SkyPillarTooScary:
	.string "Le PILIER CELESTE ? …Oh, tu dois\p"
	.string "parler de cette tour très, très haute\n"
	.string "un peu plus loin. Si tu\p"
	.string "me demandes, je ne la grimpais\n"
	.string "pas. C'est trop effrayant d'être si\p"
	.string "haut. La vie au niveau de\n"
	.string "la mer à PACIFIDLOG me convient.$"

PacifidlogTown_Text_TownSign:
	.string "PACIFIDLOG\p"
	.string "« Là où le soleil du matin\n"
	.string "sourit aux eaux. »$"

