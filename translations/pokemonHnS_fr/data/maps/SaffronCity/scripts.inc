SaffronCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SaffronCity_EventScript_CityEnter
	.byte 0

SaffronCity_OnFrame::
	map_script_2 VAR_SAFFRON_CITY_STATE, 0,  SaffronCity_EventScript_BaobaCall
	.2byte 0

SaffronCity_EventScript_CityEnter::
	setflag FLAG_VISITED_SAFFRON_CITY
	end

SaffronCity_EventScript_BaobaCall::
	pokenavcall SaffronCity_Text_Baoba
	waitmessage
	delay 30
	setflag FLAG_SAFARI_ZONE_EAST_EXPANSION
	setvar VAR_SAFFRON_CITY_STATE, 1
	end

SaffronCity_Text_Baoba:
	.string "GARDIEN BAOBA : {PLAYER} !\p"
	.string "C'est le GARDIEN BAOBA.\p"
	.string "J'appelle pour te dire que le\n"
	.string "PARC SAFARI s'est encore agrandi !\p"
	.string "Enfin, mon PARC SAFARI est\n"
	.string "entièrement réalisé !\p"
	.string "Tu te souviens où c'est, hein ?\p"
	.string "Juste à l'ouest de PARMANIE !\n"
	.string "À bientôt !$"

SaffronCity_EventScript_Lass1A::
	goto_if_set FLAG_RETURNED_MACHINE_PART, SaffronCity_EventScript_Lass1B
	msgbox SaffronCity_Text_Lass1, MSGBOX_NPC
	end

SaffronCity_EventScript_Lass1B::
	msgbox SaffronCity_Text_Lass1_ReturnedPart, MSGBOX_NPC
	end

SaffronCity_EventScript_Lass2::
	msgbox SaffronCity_Text_Lass2, MSGBOX_NPC
	end

SaffronCity_EventScript_PokefanM::
	goto_if_set FLAG_RETURNED_MACHINE_PART, SaffronCity_EventScript_PokefanM2
	msgbox SaffronCity_Text_PokefanM, MSGBOX_NPC
	end

SaffronCity_EventScript_PokefanM2::
	msgbox SaffronCity_Text_PokefanM_ReturnedPart, MSGBOX_NPC
	end

SaffronCity_EventScript_CooltrainerM::
	msgbox SaffronCity_Text_CooltrainerM, MSGBOX_NPC
	end

SaffronCity_EventScript_CooltrainerF::
	msgbox SaffronCity_Text_CooltrainerF, MSGBOX_NPC
	end

SaffronCity_EventScript_Fisher::
	goto_if_set FLAG_RETURNED_MACHINE_PART, SaffronCity_EventScript_Fisher2
	msgbox SaffronCity_Text_Fisher, MSGBOX_NPC
	end

SaffronCity_EventScript_Fisher2::
	msgbox SaffronCity_Text_Fisher_ReturnedPart, MSGBOX_NPC
	end

SaffronCity_EventScript_Youngster1::
	msgbox SaffronCity_Text_Youngster1, MSGBOX_NPC
	end

SaffronCity_EventScript_Youngster2::
	msgbox SaffronCity_Text_Youngster2, MSGBOX_NPC
	end
SaffronCity_EventScript_CitySign::
	msgbox SaffronCity_Text_Sign, MSGBOX_SIGN
	end

SaffronCity_EventScript_GymSign::
	msgbox SaffronCity_Text_GymSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_DojoSign::
	msgbox SaffronCity_Text_FightingDojoSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_SilphCoSign::
	msgbox SaffronCity_Text_SilphCoSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_MrPsychicSign::
	msgbox SaffronCity_Text_MrPsychicHouseSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_MagnetTrainSign::
	msgbox SaffronCity_Text_MagnetTrainStationSign, MSGBOX_SIGN
	end

SaffronCity_EventScript_Elli::
	msgbox SaffronCity_Text_Elli, MSGBOX_NPC
	end

SaffronCity_Text_Elli:
	.string "J'adore GOUPIX ! :D$"

SaffronCity_Text_Lass1:
	.string "Une petite fille experte pour\n"
	.string "imiter les gens vit ici.\p"
	.string "Elle imite même les gens avec qui\n"
	.string "elle discute. C'est déroutant.$"

SaffronCity_Text_Lass1_ReturnedPart:
	.string "La fille COPIEUR avait l'air triste.\p"
	.string "Elle a dit qu'elle avait perdu\n"
	.string "sa POKé POUPÉE - MÉLOFÉE préférée.$"

SaffronCity_Text_PokefanM:
	.string "Tu viens de JOHTO ?\p"
	.string "Tu peux rentrer chez toi si le\n"
	.string "TRAIN MAGNÉTIQUE fonctionne.$"

SaffronCity_Text_PokefanM_ReturnedPart:
	.string "Tu viens de JOHTO ?\p"
	.string "Tu peux rentrer chez toi en prenant\n"
	.string "le TRAIN MAGNÉTIQUE.$"

SaffronCity_Text_CooltrainerM:
	.string "Je suis allé à l'ARÈNE, prêt pour\n"
	.string "des combats contre des Dresseurs…\p"
	.string "Il s'avère que je suis tombé dans l'\n"
	.string "ARÈNE inutilisée d'à côté.\p"
	.string "Bon sang, j'étais bien embarrassé.$"

SaffronCity_Text_CooltrainerF:
	.string "C'est la SYLPHE SARL, célèbre\n"
	.string "pour ses produits POKéMON. Autrefois,\p"
	.string "la TEAM ROCKET voulait\n"
	.string "l'entreprise pour cette raison.$"

SaffronCity_Text_Fisher:
	.string "Miam… Miam…\p"
	.string "J'entends qu'il y a de gros problèmes à\n"
	.string "la CENTRALE.\p"
	.string "Miam… Miam…$"

SaffronCity_Text_Fisher_ReturnedPart:
	.string "Mâche… Mâche…\p"
	.string "J'ai entendu qu'il y avait eu de gros problèmes\n"
	.string "à la CENTRALE.\p"
	.string "Mâche… Mâche… Haaah, je suis rassasié !$"

SaffronCity_Text_Youngster1:
	.string "Entrer dans une ruelle pour la première\n"
	.string "fois, ça me rend un peu anxieux.$"

SaffronCity_Text_Youngster2:
	.string "Il y a un endroit appelé MAISON DES\n"
	.string "DRESSEURS à VIRIDIA où des DRESSEURS\l"
	.string "viennent de partout.$"

SaffronCity_Text_Lass2:
	.string "Notre ville a été mise\n"
	.string "en avant dans une émission\p"
	.string "radio. C'est agréable d'entendre des\n"
	.string "éloges sur sa ville, mais\l"
	.string "c'est un peu embarrassant aussi.$"

SaffronCity_Text_Sign:
	.string "SAFRANIA\p"
	.string "Terre dorée du commerce éclatant$"

SaffronCity_Text_GymSign:
	.string "SAFRANIA\n"
	.string "ARÈNE POKéMON\l"
	.string "CHAMPION D'ARÈNE : MORGANE\p"
	.string "La maîtresse des POKéMON PSY !$"

SaffronCity_Text_FightingDojoSign:
	.string "Tout le monde est le bienvenu !\n"
	.string "DOJO DE COMBAT$"

SaffronCity_Text_SilphCoSign:
	.string "SYLPHE SARL\n"
	.string "SIÈGE SOCIAL$"

SaffronCity_Text_MrPsychicHouseSign:
	.string "MAISON DE M.\n"
	.string "PSYCHOKINÉ$"

SaffronCity_Text_MagnetTrainStationSign:
	.string "SAFRANIA\n"
	.string "GARE DU TRAIN MAGNÉTIQUE$"
