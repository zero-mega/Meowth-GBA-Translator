.set LOCALID_OLIVINEPORT_SAILOR, 1
.set LOCALID_OLIVINEPORT_BOAT, 6
.set LOCALID_OLIVINEPORT_OAK, 7

OlivineCity_PortInside_MapScripts::
	.byte 0


OlivineCity_PortInside_EventScript_Oak::
	lock
	playbgm MUS_HG_OAK, TRUE
	playse SE_PIN
	applymovement2 LOCALID_OLIVINEPORT_OAK, Common_Movement_ExclamationMark
	delay 60
	turnobject LOCALID_OLIVINEPORT_OAK, DIR_NORTH
	msgbox OlivineCity_PortInside_Text_Nationaldex1, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_OLIVINEPORT_OAK, OlivineCity_PortInside_Movement_OakFixDex
	waitmovement 0
	delay 30
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	playfanfare MUS_OBTAIN_ITEM
	message OlivineCity_PortInside_Text_Nationaldex2
	waitfanfare
	delay 50
	msgbox OlivineCity_PortInside_Text_Nationaldex3, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement2 LOCALID_OLIVINEPORT_OAK, Common_Movement_ExclamationMark
	delay 60
	msgbox OlivineCity_PortInside_Text_Nationaldex4, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, OlivineCity_PortInside_Movement_PlayerMoveOver
	waitmovement 0
	applymovement LOCALID_OLIVINEPORT_OAK, OlivineCity_PortInside_Movement_OakLeave
	waitmovement 0
	setflag FLAG_HIDE_OLIVINE_PORT_OAK
	playse SE_EXIT
	removeobject LOCALID_OLIVINEPORT_OAK
	fadedefaultbgm
	waitse
	release
	end

OlivineCity_PortInside_Movement_OakFixDex:
	walk_in_place_up
	walk_in_place_up
	step_end

OlivineCity_PortInside_Movement_PlayerMoveOver:
	walk_up
	walk_left
	face_right
	step_end

OlivineCity_PortInside_Movement_OakLeave:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OlivineCity_PortInside_Text_Nationaldex1:
	.string "PROF.CHEN : Bonjour ! Tu\n"
	.string "commences à avoir l'attitude\l"
	.string "d'un CHAMPION, {PLAYER} !\p"
	.string "Il est temps que\n"
	.string "ton POKéDEX corresponde à\p"
	.string "qui tu es. Laisse-moi\n"
	.string "voir ton POKéDEX une\p"
	.string "seconde. Je vais l'améliorer\n"
	.string "avec le MODE NATIONAL.$"
OlivineCity_PortInside_Text_Nationaldex2:
	.string "Le POKéDEX de {PLAYER} a été mis à jour\n"
	.string "avec le MODE NATIONAL !$"
OlivineCity_PortInside_Text_Nationaldex3:
	.string "PROF.CHEN : Ce ne sera pas facile de\n"
	.string "compléter le POKéDEX NATIONAL...\p"
	.string "Cependant, je suis sûr que tu feras\n"
	.string "un honnête effort pour nous !$"
OlivineCity_PortInside_Text_Nationaldex4:
	.string "Oh, le temps passe vite !\p"
	.string "J'ai une émission radio à enregistrer à la\n"
	.string "TOUR RADIO de DOUBLONVILLE.\p"
	.string "Tu dois te diriger vers KANTO.\p"
	.string "Si tu passes près de BOURG PALETTE, passe\n"
	.string "à mon LABORATOIRE DE RECHERCHE POKéMON !$"

OlivinePort_EventScript_CooltrainerF::
	msgbox OlivinePort_Text_CooltrainerF, MSGBOX_NPC
	end

OlivinePort_EventScript_Fisher1::
	msgbox OlivinePort_Text_FishingGuru1, MSGBOX_NPC
	end

OlivinePort_EventScript_Fisher2::
	msgbox OlivinePort_Text_FishingGuru2, MSGBOX_NPC
	end

OlivinePort_EventScript_Youngster::
	msgbox OlivinePort_Text_Youngster, MSGBOX_NPC
	end

OlivinePort_EventScript_Sailor::
	lock
	faceplayer
	goto_if_ge VAR_SSAQUA_STATE, 7, OlivinePort_EventScript_Sailor_AfterKanto
	msgbox OlivinePort_Text_AskBoard, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, OlivinePort_EventScript_Sailor_Refused
	checkitem ITEM_SS_TICKET
	goto_if_eq VAR_RESULT, TRUE, OlivinePort_EventScript_Sailor_MaidenVoyage
	msgbox OlivinePort_Text_NoTicket, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivinePort_EventScript_Sailor_AfterKanto::
	message OlivinePort_Text_WhereSail
	multichoice 20, 0, MULTI_OLIVINE_HARBOR, FALSE
	switch VAR_RESULT
	case 0, OlivinePort_EventScript_ChoseVermilion
	case 1, OlivinePort_EventScript_ChoseSouthernIsland
	case 2, OlivinePort_EventScript_ChoseBirthIsland
	case 3, OlivinePort_EventScript_ChoseFarawayIsland
	case 4, OlivinePort_EventScript_ChoseBattleFrontier
	case 5, OlivinePort_EventScript_Sailor_Refused
	case MULTI_B_PRESSED, OlivinePort_EventScript_Sailor_Refused
	release
	end

OlivinePort_EventScript_ChoseVermilion::
	closemessage
	delay 20
	checkitem ITEM_SS_TICKET
	bufferitemname STR_VAR_1, ITEM_SS_TICKET
	goto_if_eq VAR_RESULT, FALSE, OlivinePort_EventScript_Sailor_NoCredentials
	call OlivinePort_EventScript_EnterShip
	warpsilent MAP_VERMILION_CITY_PORT_INSIDE, 8, 9
	release
	end

OlivinePort_EventScript_ChoseSouthernIsland::
	closemessage
	delay 20
	checkitem ITEM_EON_TICKET
	bufferitemname STR_VAR_1, ITEM_EON_TICKET
	goto_if_eq VAR_RESULT, FALSE, OlivinePort_EventScript_Sailor_NoCredentials
	call OlivinePort_EventScript_EnterShip
	warpsilent MAP_SOUTHERN_ISLAND_EXTERIOR, 13, 22
	release
	end

OlivinePort_EventScript_ChoseBirthIsland::
	closemessage
	delay 20
	checkitem ITEM_AURORA_TICKET
	bufferitemname STR_VAR_1, ITEM_AURORA_TICKET
	goto_if_eq VAR_RESULT, FALSE, OlivinePort_EventScript_Sailor_NoCredentials
	call OlivinePort_EventScript_EnterShip
	warpsilent MAP_BIRTH_ISLAND_EXTERIOR, 13, 23
	release
	end

OlivinePort_EventScript_ChoseFarawayIsland::
	closemessage
	delay 20
	checkitem ITEM_OLD_SEA_MAP
	bufferitemname STR_VAR_1, ITEM_OLD_SEA_MAP
	goto_if_eq VAR_RESULT, FALSE, OlivinePort_EventScript_Sailor_NoCredentials
	call OlivinePort_EventScript_EnterShip
	warpsilent MAP_FARAWAY_ISLAND_ENTRANCE, 13, 38
	release
	end	

OlivinePort_EventScript_ChoseBattleFrontier::
	closemessage
	delay 20
	call OlivinePort_EventScript_EnterShip
	warpsilent MAP_BATTLE_FRONTIER_OUTSIDE_WEST, 20, 67
	release
	end	

OlivinePort_EventScript_Sailor_MaidenVoyage::
	msgbox OlivinePort_Text_FlashTicket, MSGBOX_DEFAULT
	call OlivinePort_EventScript_EnterShip
	setvar VAR_SSAQUA_STATE, 1
	clearflag FLAG_HIDE_SSAQUA_1F_GRANDPA
	setflag FLAG_HIDE_SSAQUA_ROOM_SSE_GRANDDAUGHTER

	clearflag FLAG_HIDE_SSAQUA_SAILOR
	clearflag FLAG_HIDE_SSAQUA_CAPTAINS_ROOM_GRANDDAUGHTER

	warpsilent MAP_SSAQUA_1F, 29, 3
	release
	end

OlivinePort_EventScript_EnterShip::
	msgbox OlivinePort_Text_SailorGetOnBoard, MSGBOX_DEFAULT
	closemessage
	delay 20
	applymovement LOCALID_OLIVINEPORT_SAILOR, OlivinePort_Movement_SailorEnterBoat
	waitmovement 0
	playse SE_EXIT
	applymovement OBJ_EVENT_ID_PLAYER, OlivinePort_Movement_PlayerEnterBoat
	waitmovement 0
	special SpawnCameraObject
	playse SE_EXIT
	removeobject OBJ_EVENT_ID_PLAYER
	delay 60
	applymovement LOCALID_OLIVINEPORT_SAILOR, OlivinePort_Movement_BoatLeave
	applymovement LOCALID_OLIVINEPORT_BOAT, OlivinePort_Movement_BoatLeave
	waitmovement LOCALID_OLIVINEPORT_BOAT
	setrespawn HEAL_LOCATION_OLIVINE_CITY
	return

OlivinePort_EventScript_Sailor_Refused::
	msgbox OlivinePort_Text_ComeAgain, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivinePort_EventScript_Sailor_NoCredentials::
	msgbox OlivinePort_Text_NoPass, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivinePort_Movement_SailorEnterBoat:
	walk_down
	walk_down
	step_end

OlivinePort_Movement_PlayerEnterBoat:
	walk_down
	walk_down
	walk_in_place_down
	step_end

OlivinePort_Movement_BoatLeave:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

OlivinePort_Text_NoPass:
    .string "{PLAYER} a essayé de montrer\n"
    .string "le {STR_VAR_1}… …Mais pas de\p"
    .string "{STR_VAR_1} ! Désolé !\p"
    .string "Tu ne peux monter\n"
    .string "à bord que si\l"
    .string "tu as un {STR_VAR_1}.$"

OlivinePort_Text_SailorGetOnBoard:
    .string "Nous partons bientôt.\n"
    .string "Monte à bord, s'il te plaît.$"

OlivinePort_Text_CantBoard:
    .string "Désolé. Tu ne peux pas embarquer maintenant.$"

OlivinePort_Text_WhereSail:
    .string "Où veux-tu naviguer ?$"

OlivinePort_Text_AskBoard:
    .string "Bienvenue sur le PÈQUE-FLÈCHE S.S.AQUA.\p"
    .string "Tu embarques aujourd'hui ?$"

OlivinePort_Text_AskTicket:
    .string "Puis-je voir ton PASSE BATEAU ?$"

OlivinePort_Text_ComeAgain:
    .string "Nous espérons te revoir bientôt !$"

OlivinePort_Text_FlashTicket:
    .string "{PLAYER} a montré le PASSE du S.S.\p"
    .string "C'est bon. Merci !$"

OlivinePort_Text_NoTicket:
    .string "{PLAYER} a essayé de montrer\n"
    .string "le PASSE BATEAU… …Mais pas\p"
    .string "de PASSE ! Désolé !\p"
    .string "Tu ne peux monter à\n"
    .string "bord que si tu\l"
    .string "as un PASSE BATEAU.$"

OlivinePort_Text_FishingGuru1:
    .string "On attrape facilement des KOKIYAS ici.\p"
    .string "Ils sont assez rares ailleurs.$"

OlivinePort_Text_FishingGuru2:
    .string "Combien de CANNES as-tu ?\p"
    .string "Les différentes CANNES permettent\n"
    .string "d'attraper différents POKéMON.$"

OlivinePort_Text_Youngster:
    .string "Le S.S. AQUA utilise des jets pour\n"
    .string "surfer sur les vagues !$"

OlivinePort_Text_CooltrainerF:
    .string "Il y a plein de POKéMON à KANTO.\p"
    .string "J'aimerais pouvoir y aller…$"

OlivinePort_Text_SailorBeforeHOF:
    .string "On ne veut pas que tu tombes à la mer,\n"
    .string "alors tu n'as pas le droit d'entrer.$"
