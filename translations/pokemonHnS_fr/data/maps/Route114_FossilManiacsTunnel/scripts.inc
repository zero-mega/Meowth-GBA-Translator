.set LOCALID_FOSSIL_MANIAC, 1

Route114_FossilManiacsTunnel_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_FossilManiacsTunnel_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route114_FossilManiacsTunnel_OnLoad
	.byte 0

Route114_FossilManiacsTunnel_OnTransition:
	call_if_set FLAG_SYS_GAME_CLEAR, Route114_FossilManiacsTunnel_EventScript_MoveFossilManiac
	end

Route114_FossilManiacsTunnel_EventScript_MoveFossilManiac::
	setobjectxyperm LOCALID_FOSSIL_MANIAC, 6, 5
	setobjectmovementtype LOCALID_FOSSIL_MANIAC, MOVEMENT_TYPE_FACE_DOWN
	return

Route114_FossilManiacsTunnel_OnLoad:
	call_if_unset FLAG_SYS_GAME_CLEAR, Route114_FossilManiacsTunnel_EventScript_CloseDesertUnderpass
	end

Route114_FossilManiacsTunnel_EventScript_CloseDesertUnderpass::
	setmetatile 6, 1, METATILE_Fallarbor_RedRockWall, TRUE
	setmetatile 6, 2, METATILE_Fallarbor_RedRockWall, TRUE
	return

Route114_FossilManiacsTunnel_EventScript_ManiacMentionCaveIn::
	lockall
	applymovement LOCALID_FOSSIL_MANIAC, Common_Movement_WalkInPlaceFasterUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox Route114_FossilManiacsTunnel_Text_NotSafeThatWay, MSGBOX_DEFAULT
	setvar VAR_FOSSIL_MANIAC_STATE, 2
	releaseall
	end

Route114_FossilManiacsTunnel_EventScript_FossilManiac::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_REVIVED_FOSSIL_MON, Route114_FossilManiacsTunnel_EventScript_PlayerRevivedFossil
	checkitem ITEM_ROOT_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil
	checkitem ITEM_CLAW_FOSSIL
	goto_if_eq VAR_RESULT, TRUE, Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil
	msgbox Route114_FossilManiacsTunnel_Text_LookInDesertForFossils, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_EventScript_PlayerHasFossil::
	msgbox Route114_FossilManiacsTunnel_Text_DevonCorpRevivingFossils, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_EventScript_PlayerRevivedFossil::
	msgbox Route114_FossilManiacsTunnel_Text_FossilsAreWonderful, MSGBOX_DEFAULT
	release
	end

Route114_FossilManiacsTunnel_Text_LookInDesertForFossils:
	.string "Je suis le MANIAQUE\n"
	.string "DES FOSSILES…\p"
	.string "Je suis un gentil type\p"
	.string "qui adore\n"
	.string "les FOSSILES…\p"
	.string "Tu veux un FOSSILE ?\n"
	.string "Mais les FOSSILES\l"
	.string "sont rares…\l"
	.string "Reviens plus tard !$"

Route114_FossilManiacsTunnel_Text_DevonCorpRevivingFossils:
	.string "Tu as trouvé un\n"
	.string "FOSSILE,\p"
	.string "n'est-ce pas ?\n"
	.string "C'est si bien…\p"
	.string "C'est si rêveur…\n"
	.string "Qu'est-ce que tu\l"
	.string "vas en faire ?\p"
	.string "Le musée serait\n"
	.string "intéressé !$"

Route114_FossilManiacsTunnel_Text_FossilsAreWonderful:
	.string "Les FOSSILES sont si… Merveilleux…\n"
	.string "C'est tellement rêveur…$"

Route114_FossilManiacsTunnel_Text_NotSafeThatWay:
	.string "Oh… Ce n'est pas sûr par\n"
	.string "là… Je creusais, tu vois… Quand\p"
	.string "tout le mur s'est effondré… Je\n"
	.string "crois qu'il y a une\p"
	.string "caverne gigantesque en dessous… Mais\n"
	.string "je l'ai laissée tranquille car\p"
	.string "je ne pense pas qu'il\n"
	.string "y ait des POKéMON là-dedans…$"

