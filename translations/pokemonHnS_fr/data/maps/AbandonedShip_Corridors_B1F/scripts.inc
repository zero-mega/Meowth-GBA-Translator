AbandonedShip_Corridors_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, AbandonedShip_Corridors_B1F_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, SetTimeEncounters
	map_script MAP_SCRIPT_ON_LOAD, AbandonedShip_Corridors_B1F_OnLoad
	.byte 0

AbandonedShip_Corridors_B1F_OnResume:
	setdivewarp MAP_ABANDONED_SHIP_UNDERWATER1, 5, 4
	callnative SetTimeBasedEncounters
	end

AbandonedShip_Corridors_B1F_OnLoad:
	call_if_unset FLAG_USED_STORAGE_KEY, AbandonedShip_Corridors_B1F_EventScript_LockStorageRoom
	call_if_set FLAG_USED_STORAGE_KEY, AbandonedShip_Corridors_B1F_EventScript_UnlockStorageRoom
	end

AbandonedShip_Corridors_B1F_EventScript_LockStorageRoom::
	setmetatile 11, 4, METATILE_InsideShip_IntactDoor_Bottom_Locked, TRUE
	return

AbandonedShip_Corridors_B1F_EventScript_UnlockStorageRoom::
	setmetatile 11, 4, METATILE_InsideShip_IntactDoor_Bottom_Unlocked, TRUE
	return

AbandonedShip_Corridors_B1F_EventScript_TuberM::
	msgbox AbandonedShip_Corridors_B1F_Text_YayItsAShip, MSGBOX_NPC
	end

AbandonedShip_Corridors_B1F_EventScript_StorageRoomDoor::
	lockall
	goto_if_set FLAG_USED_STORAGE_KEY, AbandonedShip_Corridors_B1F_EventScript_DoorIsUnlocked
	checkitem ITEM_STORAGE_KEY
	goto_if_eq VAR_RESULT, FALSE, AbandonedShip_Corridors_B1F_EventScript_DoorIsLocked
	msgbox AbandonedShip_Corridors_B1F_Text_InsertedStorageKey, MSGBOX_DEFAULT
	playse SE_PIN
	removeitem ITEM_STORAGE_KEY
	setflag FLAG_USED_STORAGE_KEY
	call AbandonedShip_Corridors_B1F_EventScript_UnlockStorageRoom
	special DrawWholeMapView
	releaseall
	end

AbandonedShip_Corridors_B1F_EventScript_DoorIsLocked::
	msgbox AbandonedShip_Corridors_B1F_Text_DoorIsLocked, MSGBOX_DEFAULT
	releaseall
	end

AbandonedShip_Corridors_B1F_EventScript_DoorIsUnlocked::
	msgbox AbandonedShip_Text_TheDoorIsOpen, MSGBOX_DEFAULT
	releaseall
	end

AbandonedShip_Corridors_B1F_EventScript_Duncan::
	trainerbattle_single TRAINER_DUNCAN, AbandonedShip_Corridors_B1F_Text_DuncanIntro, AbandonedShip_Corridors_B1F_Text_DuncanDefeat
	msgbox AbandonedShip_Corridors_B1F_Text_DuncanPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Corridors_B1F_Text_DuncanIntro:
	.string "Quand on prend la mer, nous les MARINS\n"
	.string "emmenons toujours nos POKéMON.\l"
	.string "Et si on faisait un combat rapide ?$"

AbandonedShip_Corridors_B1F_Text_DuncanDefeat:
	.string "Oups, je suis coulé !$"

AbandonedShip_Corridors_B1F_Text_DuncanPostBattle:
	.string "La coque du navire a\n"
	.string "coulé dans les profondeurs. Si\p"
	.string "un POKéMON savait plonger sous\n"
	.string "l'eau, on pourrait avancer…$"

AbandonedShip_Corridors_B1F_Text_YayItsAShip:
	.string "Youpi !\n"
	.string "C'est un bateau !$"

AbandonedShip_Corridors_B1F_Text_DoorIsLocked:
	.string "La porte est verrouillée.\p"
	.string "“STOCKAGE” est peint sur la porte.$"

AbandonedShip_Corridors_B1F_Text_InsertedStorageKey:
	.string "{PLAYER} a inséré et tourné la\n"
	.string "CLÉ DE STOCKAGE.\p"
	.string "La CLÉ insérée est restée bloquée,\n"
	.string "mais la porte s'est ouverte.$"

AbandonedShip_Text_TheDoorIsOpen:
	.string "La porte est ouverte.$"

