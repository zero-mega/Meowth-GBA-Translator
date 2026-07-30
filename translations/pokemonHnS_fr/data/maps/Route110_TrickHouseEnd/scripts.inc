.set LOCALID_TRICK_MASTER, 1

Route110_TrickHouseEnd_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, Route110_TrickHouseEnd_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, Route110_TrickHouseEnd_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route110_TrickHouseEnd_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, Route110_TrickHouseEnd_OnWarp
	.byte 0

Route110_TrickHouseEnd_OnResume:
	call_if_eq VAR_TEMP_1, 1, Route110_TrickHouseEnd_EventScript_SetDoorClosedMetatile
	end

Route110_TrickHouseEnd_OnTransition:
	setvar VAR_TEMP_1, 0
	setvar VAR_TEMP_2, 0
	special SetTrickHouseNuggetFlag
	end

Route110_TrickHouseEnd_OnWarp:
	map_script_2 VAR_TEMP_2, 0, Route110_TrickHouseEnd_EventScript_SetTrickMasterPos
	.2byte 0

Route110_TrickHouseEnd_EventScript_SetTrickMasterPos::
	addobject LOCALID_TRICK_MASTER
	showobjectat LOCALID_TRICK_MASTER, MAP_ROUTE110_TRICK_HOUSE_END
	turnobject LOCALID_TRICK_MASTER, DIR_EAST
	end

Route110_TrickHouseEnd_OnFrame:
	map_script_2 VAR_TEMP_1, 0, Route110_TrickHouseEnd_EventScript_CloseDoor
	.2byte 0

Route110_TrickHouseEnd_EventScript_CloseDoor::
	setvar VAR_TEMP_1, 1
	call Route110_TrickHouseEnd_EventScript_SetDoorClosedMetatile
	special DrawWholeMapView
	end

Route110_TrickHouseEnd_EventScript_SetDoorClosedMetatile::
	setmetatile 10, 1, METATILE_GenericBuilding_TrickHouse_Door_Closed, TRUE
	return

Route110_TrickHouseEnd_EventScript_TrickMaster::
	lock
	faceplayer
	msgbox Route110_TrickHouseEnd_Text_YouveMadeItToMe, MSGBOX_DEFAULT
	setvar VAR_TEMP_2, 1
	switch VAR_TRICK_HOUSE_LEVEL
	case 0, Route110_TrickHouseEnd_EventScript_CompletedPuzzle1
	case 1, Route110_TrickHouseEnd_EventScript_CompletedPuzzle2
	case 2, Route110_TrickHouseEnd_EventScript_CompletedPuzzle3
	case 3, Route110_TrickHouseEnd_EventScript_CompletedPuzzle4
	case 4, Route110_TrickHouseEnd_EventScript_CompletedPuzzle5
	case 5, Route110_TrickHouseEnd_EventScript_CompletedPuzzle6
	case 6, Route110_TrickHouseEnd_EventScript_CompletedPuzzle7
	case 7, Route110_TrickHouseEnd_EventScript_CompletedPuzzle8
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle1::
	msgbox Route110_TrickHouseEnd_Text_AllNightToPlantTrees, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_RARE_CANDY
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle2::
	msgbox Route110_TrickHouseEnd_Text_AllNightToMakeMaze, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_TIMER_BALL
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle3::
	msgbox Route110_TrickHouseEnd_Text_AllNightToPreparePanels, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_HARD_STONE
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle4::
	msgbox Route110_TrickHouseEnd_Text_AllNightToShoveBoulders, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_SMOKE_BALL
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle5::
	msgbox Route110_TrickHouseEnd_Text_AllNightToMakeMechadolls, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_TM_TAUNT
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle6::
	msgbox Route110_TrickHouseEnd_Text_AllNightToInstallDoors, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_MAGNET
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle7::
	msgbox Route110_TrickHouseEnd_Text_AllNightSettingUpArrows, MSGBOX_DEFAULT
	msgbox Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	giveitem ITEM_PP_MAX
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_BagFull
	msgbox Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou, MSGBOX_DEFAULT
	closemessage
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	release
	end

Route110_TrickHouseEnd_EventScript_CompletedPuzzle8::
	msgbox Route110_TrickHouseEnd_Text_AllNightPolishingFloors, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_SOUTH, Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwaySouth
	call_if_eq VAR_FACING, DIR_NORTH, Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayNorth
	call_if_eq VAR_FACING, DIR_WEST, Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayWest
	call_if_eq VAR_FACING, DIR_EAST, Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayEast
	delay 30
	msgbox Route110_TrickHouseEnd_Text_FountainOfIdeasRunDry, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TRICK_MASTER, Common_Movement_FacePlayer
	waitmovement 0
	delay 30
	msgbox Route110_TrickHouseEnd_Text_DefeatedMePreferWhichTent, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 0
	call Route110_TrickHouseEnd_EventScript_ChooseTent
	call_if_eq VAR_RESULT, FALSE, Route110_TrickHouseEnd_EventScript_NoRoomForTent
	msgbox Route110_TrickHouseEnd_Text_LeavingOnJourney, MSGBOX_DEFAULT
	call Route110_TrickHouseEnd_EventScript_TrickMasterExit
	special ResetTrickHouseNuggetFlag
	release
	end

Route110_TrickHouseEnd_EventScript_ChooseTent::
	multichoice 0, 0, MULTI_TENT, TRUE
	switch VAR_RESULT
	case 0, Route110_TrickHouseEnd_EventScript_GiveRedTent
	goto Route110_TrickHouseEnd_EventScript_GiveBlueTent

Route110_TrickHouseEnd_EventScript_GiveRedTent::
	givedecoration DECOR_RED_TENT
	return

Route110_TrickHouseEnd_EventScript_GiveBlueTent::
	givedecoration DECOR_BLUE_TENT
	return

Route110_TrickHouseEnd_EventScript_TrickMasterExit::
	applymovement LOCALID_TRICK_MASTER, Route110_TrickHouse_Movement_TrickMasterSpin
	waitmovement 0
	playse SE_M_EXPLOSION
	applymovement LOCALID_TRICK_MASTER, Route110_TrickHouse_Movement_TrickMasterJumpAway
	waitmovement 0
	removeobject LOCALID_TRICK_MASTER
	addvar VAR_TRICK_HOUSE_LEVEL, 1
	return

Route110_TrickHouseEnd_EventScript_BagFull::
	call Common_EventScript_BagIsFull
	msgbox Route110_TrickHouseEnd_Text_NoRoomForThis, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 1
	return

Route110_TrickHouseEnd_EventScript_NoRoomForTent::
	call Common_EventScript_NoRoomForDecor
	msgbox Route110_TrickHouseEnd_Text_NoRoomInPC, MSGBOX_DEFAULT
	setvar VAR_TRICK_HOUSE_PRIZE_PICKUP, 1
	return

Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwaySouth::
	applymovement LOCALID_TRICK_MASTER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayNorth::
	applymovement LOCALID_TRICK_MASTER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayWest::
	applymovement LOCALID_TRICK_MASTER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

Route110_TrickHouseEnd_EventScript_TrickMasterFaceAwayEast::
	applymovement LOCALID_TRICK_MASTER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

Route110_TrickHouseEnd_EventScript_TrickMasterExitTrigger::
	lockall
	turnobject LOCALID_TRICK_MASTER, DIR_WEST
	playse SE_PIN
	applymovement LOCALID_TRICK_MASTER, Common_Movement_ExclamationMark
	waitmovement 0
	delay 20
	applymovement LOCALID_TRICK_MASTER, Route110_TrickHouseEnd_Movement_TrickMasterSurprise
	waitmovement 0
	playse SE_M_EXPLOSION
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox Route110_TrickHouseEnd_Text_YoureIgnoringMe, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Route110_TrickHouseEnd_Movement_KeepPlayerInRoom
	waitmovement 0
	delay 4
	turnobject LOCALID_TRICK_MASTER, DIR_EAST
	releaseall
	end

Route110_TrickHouseEnd_Movement_KeepPlayerInRoom:
	walk_down
	step_end

Route110_TrickHouseEnd_Movement_TrickMasterSurprise:
	jump_in_place_left
	step_end

Route110_TrickHouseEnd_Text_YouveMadeItToMe:
	.string "Aak !\n"
	.string "Tu es arrivé jusqu'à moi ?\l"
	.string "Hmmm… Tu es vif !$"

Route110_TrickHouseEnd_Text_AllNightToPlantTrees:
	.string "Il m'a fallu toute une nuit pour planter tous ces\n"
	.string "arbres…\p"
	.string "Tu es presque mon égal en grandeur,\n"
	.string "d'une, deux, trois, quatre, cinq, six places !$"

Route110_TrickHouseEnd_Text_AllNightToMakeMaze:
	.string "Ça m'a pris toute la nuit pour faire le\p"
	.string "labyrinthe… Tu es presque mon égal en grandeur, à\n"
	.string "un, deux, trois, quatre, cinq places près !$"

Route110_TrickHouseEnd_Text_AllNightToPreparePanels:
	.string "Ça m'a pris toute la nuit pour\n"
	.string "préparer les panneaux muraux… Tu es presque\p"
	.string "mon égal en grandeur, à un,\n"
	.string "deux, trois, quatre places près !$"

Route110_TrickHouseEnd_Text_AllNightToShoveBoulders:
	.string "Ça m'a pris toute la nuit\n"
	.string "pour pousser ces rochers… Tu es\p"
	.string "presque mon égal en grandeur, à\n"
	.string "un, deux, trois places près !$"

Route110_TrickHouseEnd_Text_AllNightToMakeMechadolls:
	.string "Il m'a fallu toute une nuit pour fabriquer des MÉCHADOLLS\n"
	.string "et une autre pour inventer le quiz…\p"
	.string "Tu es presque mon égal en grandeur,\n"
	.string "d'une ou deux places !$"

Route110_TrickHouseEnd_Text_AllNightToInstallDoors:
	.string "Ça m'a pris toute la nuit pour installer\n"
	.string "les portes…\p"
	.string "Tu es presque mon égal en grandeur !$"

Route110_TrickHouseEnd_Text_AllNightSettingUpArrows:
	.string "Ça m'a pris toute la nuit pour placer les flèches…\p"
	.string "Tu es mon égal en grandeur !$"

Route110_TrickHouseEnd_Text_AllNightPolishingFloors:
	.string "Ça m'a pris toute la nuit à cirer les sols…\p"
	.string "Tu me dépasses en grandeur !\n"
	.string "Peut-être…$"

Route110_TrickHouseEnd_Text_FountainOfIdeasRunDry:
	.string "Q-que dois-je faire ?\n"
	.string "Mon inspiration pour les farces est à\l"
	.string "sèche…\p"
	.string "Peut-être est-il temps de parcourir\n"
	.string "le pays pour inventer de nouvelles farces…$"

Route110_TrickHouseEnd_Text_DefeatedMePreferWhichTent:
	.string "Je déteste admettre la défaite, mais tu\n"
	.string "m'as battu !\p"
	.string "Quand même, tu as dû être attiré par\n"
	.string "mon charisme pour\l"
	.string "revenir me voir encore\p"
	.string "et encore. Oui, c'est sûr !\n"
	.string "Mais ça n'a rien à voir avec ma\p"
	.string "défaite !\n"
	.string "En reconnaissance de l'amitié entre toi,\l"
	.string "le déterminé, et le génie que je suis,\l"
	.string "j'exige que tu prennes ce souvenir !\p"
	.string "En fait, il y en a deux--\n"
	.string "une TENTE ROUGE et une TENTE BLEUE.\l"
	.string "Laquelle préfères-tu ?$"

Route110_TrickHouseEnd_Text_NoRoomInPC:
	.string "Quoi ? Plus de place dans ton PC ?\n"
	.string "Qu'est-ce que je suis censé en penser ?\p"
	.string "J'aimerais pouvoir dire ça, mais je suis trop\n"
	.string "gentil, alors reviens plus tard !$"

Route110_TrickHouseEnd_Text_LeavingOnJourney:
	.string "… … … … … …\p"
	.string "Je pars pour un voyage de découverte.\n"
	.string "Une quête à la recherche de nouveaux types\p"
	.string "de POKéMON.\n"
	.string "Adieu.\p"
	.string "Bonne chance à toi aussi.$"

Route110_TrickHouseEnd_Text_YouHaveEarnedThisReward:
	.string "Bien !\n"
	.string "Tu as mérité cette récompense !$"

Route110_TrickHouseEnd_Text_NoRoomForThis:
	.string "Quoi ? Tu n'as pas de place pour ça ?\n"
	.string "Quel genre d'objets transportes-tu ?\p"
	.string "Mais bon, puisque tu es arrivé jusqu'ici,\n"
	.string "ta récompense attendra avec moi.$"

Route110_TrickHouseEnd_Text_MakeNewTricksToStumpYou:
	.string "Efface ce sourire suffisant de ton visage !\n"
	.string "C'est bien trop tôt pour croire avoir\p"
	.string "gagné ! Je vais inventer de nouveaux\n"
	.string "pièges pour te dérouter. Tu ne pourras\p"
	.string "te moquer que quand tu auras fini.\n"
	.string "Reviens pour le prochain épisode palpitant !$"

Route110_TrickHouseEnd_Text_YoureIgnoringMe:
	.string "Bon, bon ! Tu m'ignores maintenant ?\n"
	.string "Ça, je trouve ça déchirant !$"

