.set LOCALID_OLIVINE_SILVER, 4

OlivineCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OlivineCity_MapScript_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	map_script MAP_SCRIPT_ON_FRAME_TABLE, OlivineCity_OnFrame
	.byte 0

OlivineCity_MapScript_OnTransition::
	callnative SetTimeBasedEncounters
	goto_if_ge VAR_OLIVINE_CITY_STATE, 5, OlivineCity_MapScript_ClearWeather
	end

OlivineCity_MapScript_ClearWeather::
	setweather WEATHER_NONE
	end

OlivineCity_OnFrame::
	map_script_2 VAR_SAFARI_ZONE_GATE_STATE, 1, OlivineCity_EventScript_BaobaCall
	.2byte 0

OlivineCity_EventScript_BaobaCall::
	lock
	pokenavcall OlivineCity_Text_Baoba
	waitmessage
	delay 30
	setvar VAR_SAFARI_ZONE_GATE_STATE, 2
	release
	end

OlivineCity_Text_Baoba:
	.string "{PLAYER} !\p"
	.string "C'est le GARDIEN BAOBA.\p"
	.string "Désolé de t'avoir\n"
	.string "fait attendre.\l"
	.string "Nous avons\p"
	.string "enfin ouvert la\p"
	.string "ZONE SAFARI !\n"
	.string "Tu sais ce que c'est ?\p"
	.string "Un endroit où tu\n"
	.string "peux attraper\l"
	.string "des POKéMON rares !\p"
	.string "Viens me voir quand\n"
	.string "tu auras le temps !$"

OlivineCity_EventScript_CityTrigger:: @FLAGHEAP
	setflag FLAG_HIDE_OLIVINE_CITY_GYM_JASMINE
	setflag FLAG_HIDE_OLIVINE_SILVER
	setflag FLAG_VISITED_OLIVINE_CITY
	clearflag FLAG_SAFARI_ZONE_WEST_EXPANSION
	clearflag FLAG_SAFARI_ZONE_EAST_EXPANSION
	clearflag FLAG_HIDE_BATTLEFRONTIER_ENGINEER
	clearflag FLAG_HIDE_LIGHTHOUSE_JASMINE
	clearflag FLAG_HIDE_WHIRL_ISLANDS_TENTACRUEL
	setvar VAR_GETFLY, 0
	
	setvar VAR_OLIVINE_CITY_STATE, 1

	@cianwood flags
	setvar VAR_SUICUNE_ENCOUNTERS, 1
	clearflag FLAG_HIDE_CIANWOOD_SUICUNE
	setflag FLAG_HIDE_CIANWOOD_EUSINE
	setvar VAR_CIANWOOD_CITY_STATE, 1
	end

OlivineCity_EventScript_SilverTrigger::
	lock
	clearflag FLAG_HIDE_OLIVINE_SILVER
	opendoor 11, 27
	addobject LOCALID_OLIVINE_SILVER
	playbgm MUS_HG_ENCOUNTER_RIVAL, TRUE
	delay 20 
	closedoor 11, 27
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_1, 28, OlivineCity_EventScript_SilverWalkToPlayer1
	call_if_eq VAR_TEMP_1, 29, OlivineCity_EventScript_SilverWalkToPlayer2
	call_if_eq VAR_TEMP_1, 30, OlivineCity_EventScript_SilverWalkToPlayer3
	msgbox OlivineCity_Text_SilverEncounter, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_TEMP_1, 28, OlivineCity_EventScript_SilverLeaveAdjust1
	call_if_eq VAR_TEMP_1, 29, OlivineCity_EventScript_SilverLeaveAdjust2
	call_if_eq VAR_TEMP_1, 30, OlivineCity_EventScript_SilverLeaveAdjust2
	applymovement LOCALID_OLIVINE_SILVER, OlivineCity_Movement_SilverLeave
	waitmovement 0
	setvar VAR_OLIVINE_CITY_STATE, 2
	setflag FLAG_HIDE_OLIVINE_SILVER
	removeobject LOCALID_OLIVINE_SILVER
	fadedefaultbgm
	release
	end

OlivineCity_EventScript_SilverWalkToPlayer1::
	applymovement LOCALID_OLIVINE_SILVER OlivineCity_Movement_SilverWalkToPlayer1
	waitmovement 0
	return

OlivineCity_EventScript_SilverWalkToPlayer2::
	applymovement LOCALID_OLIVINE_SILVER OlivineCity_Movement_SilverWalkToPlayer2
	waitmovement 0
	return

OlivineCity_EventScript_SilverWalkToPlayer3::
	applymovement LOCALID_OLIVINE_SILVER OlivineCity_Movement_SilverWalkToPlayer3
	waitmovement 0
	return

OlivineCity_EventScript_SilverLeaveAdjust1::
	applymovement LOCALID_OLIVINE_SILVER Common_Movement_WalkDown1
	waitmovement 0
	return

OlivineCity_EventScript_SilverLeaveAdjust2::
	applymovement LOCALID_OLIVINE_SILVER Common_Movement_WalkUp1
	waitmovement 0
	return

OlivineCity_Movement_SilverWalkToPlayer1:
	walk_down
	walk_right
	walk_right
	walk_right
	step_end
OlivineCity_Movement_SilverWalkToPlayer2:
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end
OlivineCity_Movement_SilverWalkToPlayer3:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end


OlivineCity_Movement_SilverLeave:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OlivineCity_Text_SilverEncounter:
	.string "Encore toi ?\n"
	.string "Pas besoin d'être sur tes gardes.\p"
	.string "Je ne m'occupe pas des mauviettes\n"
	.string "comme toi.\p"
	.string "En parlant de faibles, le\n"
	.string "CHAMPION d'ARÈNE de la ville n'est pas là,\l"
	.string "et prendrait soin d'un POKéMON malade\l"
	.string "au PHARE.\l"
	.string "Humph ! Bouh-hou !\p"
	.string "Laisse simplement les\n"
	.string "POKéMON malades partir !\p"
	.string "Un POKéMON qui ne peut pas combattre\n"
	.string "est sans valeur !\p"
	.string "Pourquoi ne pas t'entraîner au\n"
	.string "PHARE ?\p"
	.string "Qui sait ? Ça pourrait faire de toi\n"
	.string "un meilleur DRESSEUR !$"

OlivineCity_EventScript_Sailor1::
	lock
	faceplayer
	msgbox OlivineCity_Text_Sailor1, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_Sailor2::
	lock
	faceplayer
	msgbox OlivineCity_Text_Sailor2, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_Youngster::
	lock
	faceplayer
	msgbox OlivineCity_Text_YoungsterPokegear, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_Machoke::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MACHOKE, CRY_MODE_NORMAL
	msgbox OlivineCity_Text_Machoke, MSGBOX_DEFAULT
	waitmoncry
	release
	end

OlivineCity_EventScript_Sign::
	lock
	msgbox OlivineCity_Text_Sign, MSGBOX_SIGN
	end

OlivineCity_EventScript_PortSign::
	lock
	msgbox OlivineCity_Text_PortSign, MSGBOX_SIGN
	end

OlivineCity_EventScript_CafeSign::
	msgbox OlivineCity_Text_CafeSign, MSGBOX_SIGN
	end

OlivineCity_EventScript_GymSign::
	lock
	msgbox OlivineCity_Text_GymSign, MSGBOX_SIGN
	end

OlivineCity_EventScript_LighthouseSign::
	lock
	msgbox OlivineCity_Text_LighthouseSign, MSGBOX_SIGN
	end

OlivineCity_EventScript_Item_Shockwave::
	finditem ITEM_TM_SHOCK_WAVE
	end

OlivineCity_EventScript_EonTicketWoman::
	lock
	faceplayer
	checkitem ITEM_AURORA_TICKET
	goto_if_eq VAR_RESULT, TRUE, OlivineCity_EventScript_EonTicketWomanAfter
	goto_if_set FLAG_IS_KANTO_CHAMPION, OlivineCity_EventScript_EonTicketWomanChamp
	msgbox OlivineCity_Text_EonTicketWoman1, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_EonTicketWomanChamp::
	msgbox OlivineCity_Text_EonTicketWoman2, MSGBOX_DEFAULT
	giveitem ITEM_AURORA_TICKET
	closemessage
	release
	end

OlivineCity_EventScript_EonTicketWomanAfter::
	msgbox OlivineCity_Text_EonTicketWoman3, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_CafeSign:
	.string "CAFÉ D'OLIVILLE\n"
	.string "OÙ LES MARINS COSTAUDS SAVOURENT\l"
	.string "DES REPAS ROBUSTES DE FORCE$"

OlivineCity_Text_EonTicketWoman1:
	.string "Je m'appelle MARY !\p"
	.string "Je plaisante, mais j'adore l'émission\n"
	.string "radio de MARY !$"

OlivineCity_Text_EonTicketWoman2:
	.string "Tu dois être {PLAYER} !!! Oh\p"
	.string "mon Dieu ! Le champion !\p"
	.string "J'ai entendu parler de toi\n"
	.string "à la radio de MARY\p"
	.string "! Tiens, prends ça !$"

OlivineCity_Text_EonTicketWoman3:
	.string "Je n'arrive pas à croire que j'ai rencontré\n"
	.string "le champion !!!$"

OlivineCity_Text_Sailor1:
	.string "Les routes sombres sont dangereuses\n"
	.string "la nuit.\p"
	.string "Mais dans l'obscurité totale de\n"
	.string "la nuit, la mer est encore plus\l"
	.string "dangereuse !\p"
	.string "Sans le phare du\n"
	.string "PHARE pour le guider,\l"
	.string "aucun navire ne peut naviguer.$"

OlivineCity_Text_YoungsterPokegear:
	.string "Ce truc que tu as-\n"
	.string "c'est un POKéKÉA, non ?\l"
	.string "Waouh, c'est cool.$"

OlivineCity_Text_YoungsterPokedex:
	.string "Waouh, tu as un POKéDEX !\p"
	.string "C'est trop génial.$"

OlivineCity_Text_Sailor2:
	.string "La ligue a classé JASMINE\n"
	.string "comme la sixième CHAMPIONNE\l"
	.string "d'ARÈNE la plus forte !\p"
	.string "Hah ! C'est n'importe quoi.\p"
	.string "PRYCE ne pourrait\n"
	.string "jamais blesser\l"
	.string "les POKéMON ACIER de JASMINE !\p"
	.string "De la bureaucratie, si tu veux\p"
	.string "mon avis.\n"
	.string "Elle est vraiment redoutable !$"

OlivineCity_Text_Sign:
	.string "OLIVILLE\p"
	.string "Le port le plus proche des terres étrangères$"

OlivineCity_Text_PortSign:
	.string "PORT D'OLIVILLE\n"
	.string "QUAI DU NAVIRE RAPIDE$"

OlivineCity_Text_GymSign:
	.string "ARÈNE POKéMON D'OLIVILLE\n"
	.string "CHAMPIONNE D'ARÈNE : JASMINE\p"
	.string "La fille à la défense d'acier$"

OlivineCity_Text_LighthouseSign:
	.string "PHARE d'OLIVILLE\n"
	.string "Aussi connu comme le PHARE\l"
	.string "LUMIÈRE$"

OlivineCity_Text_BattleTowerSign:
	.string "MONTAGNE DES DRESSEURS et\n"
	.string "TENTES DE COMBAT DEVANT.\p"
	.string "Ouverture maintenant !$"

OlivineCity_Text_Machoke:
	.string "MACHOPEUR : CHO !$"
