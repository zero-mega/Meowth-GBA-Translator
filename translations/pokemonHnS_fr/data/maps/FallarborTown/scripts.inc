FallarborTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_OnTransition
	.byte 0

FallarborTown_OnTransition:
	setflag FLAG_VISITED_ECRUTEAK_CITY
	setvar VAR_CONTEST_HALL_STATE, 0
	clearflag FLAG_CONTEST_SKETCH_CREATED
	end

FallarborTown_EventScript_ExpertM::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FallarborTown_EventScript_ExpertMNormal
	msgbox FallarborTown_Text_ShadyCharactersCozmosHome, MSGBOX_DEFAULT
	release
	end

FallarborTown_EventScript_ExpertMNormal::
	msgbox FallarborTown_Text_RegionKnownForMeteors, MSGBOX_DEFAULT
	release
	end

FallarborTown_EventScript_Girl::
	msgbox FallarborTown_Text_MyPreciousAzurill, MSGBOX_NPC
	end

FallarborTown_EventScript_Gentleman::
	msgbox FallarborTown_Text_HaveYouChallengedFlannery, MSGBOX_NPC
	end

FallarborTown_EventScript_Azurill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, CRY_MODE_NORMAL
	msgbox FallarborTown_Text_Azurill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FallarborTown_EventScript_BattleTentSign::
	msgbox FallarborTown_Text_BattleTentSign, MSGBOX_SIGN
	end

FallarborTown_EventScript_TownSign::
	msgbox FallarborTown_Text_TownSign, MSGBOX_SIGN
	end

FallarborTown_EventScript_MoveTutorSign::
	msgbox FallarborTown_Text_MoveTutorSign, MSGBOX_SIGN
	end

FallarborTown_Text_ShadyCharactersCozmosHome:
	.string "Il se passe quelque chose, et ça\n"
	.string "ne me plaît pas ! J'ai\p"
	.string "vu des personnages louches entrer et\n"
	.string "sortir de chez le PROF. COSMO…$"

FallarborTown_Text_RegionKnownForMeteors:
	.string "Cette région est connue pour les météorites\n"
	.string "depuis les temps anciens.\p"
	.string "On dit que la CHUTE MÉTÉORE a été creusée\n"
	.string "par une météorite tombée il y a longtemps.$"

FallarborTown_Text_MyPreciousAzurill:
	.string "Regarde ! Regarde !\n"
	.string "Voici mon précieux AZURILL !\p"
	.string "Il est lisse, doux et tout pelucheux !$"

FallarborTown_Text_Azurill:
	.string "AZURILL : Rooreelooo.$"

FallarborTown_Text_HaveYouChallengedFlannery:
	.string "As-tu déjà défie AUGUSTE,\n"
	.string "la CHAMPIONNE\p"
	.string "d'ARÈNE de LAVARIA ?\n"
	.string "Le grand-père de la\l"
	.string "fille était célèbre\p"
	.string "pour ses techniques\n"
	.string "de type FEU.\l"
	.string "Elle est digne de son héritage !$"

FallarborTown_Text_BattleTentSign:
	.string "TENTE DE COMBAT VERGOIGNON\n"
	.string "« Que les meilleures équipes se rassemblent ! »$"

FallarborTown_Text_TownSign:
	.string "ATALAIA\n"
	.string "« Une communauté agricole aux petits jardins. »$"

FallarborTown_Text_MoveTutorSign:
	.string "MAISON DU MAÎTRE DES CAPACITÉS\n"
	.string "« De nouvelles attaques enseignées aux POKéMON. »$"

