.set LOCALID_ATTENDANT, 1

BattleFrontier_BattleTowerMultiPartnerRoom_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattleTowerMultiPartnerRoom_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattleTowerMultiPartnerRoom_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattleTowerMultiPartnerRoom_OnFrame
	.byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_OnResume:
	pyramid_resetparty
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnTransition:
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ChosePartner
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_1
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_2
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_3
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_4
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_5
	clearflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_6
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_1
	setflag FLAG_HIDE_BATTLE_TOWER_MULTI_BATTLE_PARTNER_ALT_2
	tower_loadpartners
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ChosePartner::
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_MR_FUJI
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_MR_FUJI
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_MR_FUJI
	setvar VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_MR_FUJI
	setvar VAR_OBJ_GFX_ID_4, OBJ_EVENT_GFX_MR_FUJI
	setvar VAR_OBJ_GFX_ID_5, OBJ_EVENT_GFX_MR_FUJI
	setvar VAR_OBJ_GFX_ID_6, OBJ_EVENT_GFX_MR_FUJI
	setvar VAR_OBJ_GFX_ID_7, OBJ_EVENT_GFX_MR_FUJI
	setvar VAR_TEMP_1, 1
	setvar VAR_TEMP_3, 1
	setobjectxyperm LOCALID_ATTENDANT, 10, 2
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnWarp:
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TurnPlayerNorth
	.2byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TurnPlayerNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

BattleFrontier_BattleTowerMultiPartnerRoom_OnFrame:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterRoom
	map_script_2 VAR_TEMP_3, 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ExitRoom
	.2byte 0

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_ExitRoom::
	lockall
	setvar VAR_TEMP_3, 0
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterElevator
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterRoom::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterRoom
	waitmovement 0
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantBlockExit
	waitmovement 0
	copyobjectxytoperm LOCALID_ATTENDANT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner, MSGBOX_DEFAULT
	special HealPlayerParty
	setvar VAR_TEMP_1, 1
	releaseall
	end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterRoom:
	walk_down
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantBlockExit:
	walk_left
	walk_in_place_faster_down
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Attendant::
	lock
	faceplayer
	message BattleFrontier_BattleTowerMultiPartnerRoom_Text_QuitLookingForPartner
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_QuitChallenge
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner2, MSGBOX_DEFAULT
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_QuitChallenge::
	frontier_set FRONTIER_DATA_RECORD_DISABLED, TRUE
	goto BattleFrontier_BattleTower_EventScript_WarpToLobbyLost
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_EnterElevator::
	msgbox BattleFrontier_BattleTowerMultiPartnerRoom_Text_ThankYouForChoosingPartner, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ATTENDANT, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	opendoor 10, 1
	waitdooranim
	call BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator
	closedoor 10, 1
	waitdooranim
	warp MAP_BATTLE_FRONTIER_BATTLE_TOWER_ELEVATOR, 1, 6
	waitstate
	releaseall
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevator::
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator
	waitmovement 0
	return

@ Unused
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevatorEast:
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorEast
	waitmovement 0
	return

@ Unused
BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_MoveToElevatorWest:
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEneterElevatorWest
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevator:
	walk_up
	walk_up
	set_invisible
	step_end

@ Functionally unused
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEnterElevatorEast:
	walk_right
	walk_up
	set_invisible
	step_end

@ Functionally unused
BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PlayerEneterElevatorWest:
	walk_left
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_AttendantEnterElevator:
	walk_up
	set_invisible
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner1::
	lock
	faceplayer
	setvar VAR_TEMP_2, 0
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner::
	goto_if_set FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	tower_dopartnermsg PARTNER_MSGID_INTRO
	waitmessage
	waitbuttonpress
	tower_dopartnermsg PARTNER_MSGID_MON1
	waitmessage
	waitbuttonpress
	tower_dopartnermsg PARTNER_MSGID_MON2_ASK
	waitmessage
	multichoicedefault 20, 8, MULTI_YESNO, 1, FALSE
	switch VAR_RESULT
	case 1, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	case MULTI_B_PRESSED, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner
	tower_dopartnermsg PARTNER_MSGID_ACCEPT
	waitmessage
	waitbuttonpress
	closemessage
	call_if_ne VAR_FACING, DIR_SOUTH, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExitSouth
	removeobject VAR_LAST_TALKED
	setflag FLAG_CHOSEN_MULTI_BATTLE_NPC_PARTNER
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_TOWER_MULTI_PARTNER_ROOM, 10, 3
	waitstate
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_RejectPartner::
	tower_dopartnermsg PARTNER_MSGID_REJECT
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExit::
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_PartnerExitSouth::
	applymovement VAR_LAST_TALKED, BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExitSouth
	waitmovement 0
	return

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExit:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_Movement_PartnerExitSouth:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner2::
	lock
	faceplayer
	setvar VAR_TEMP_2, 1
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner3::
	lock
	faceplayer
	setvar VAR_TEMP_2, 2
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner4::
	lock
	faceplayer
	setvar VAR_TEMP_2, 3
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner5::
	lock
	faceplayer
	setvar VAR_TEMP_2, 4
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner6::
	lock
	faceplayer
	setvar VAR_TEMP_2, 5
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner7::
	lock
	faceplayer
	setvar VAR_TEMP_2, 6
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_Partner8::
	lock
	faceplayer
	setvar VAR_TEMP_2, 7
	goto BattleFrontier_BattleTowerMultiPartnerRoom_EventScript_TalkToPotentialPartner
	end

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner:
	.string "Trouve un partenaire parmi les\n"
	.string "DRESSEURS rassemblés ici.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_QuitLookingForPartner:
	.string "{PLAYER}, tu n'as pas trouvé de partenaire\n"
	.string "pour ton équipe en duo.\p"
	.string "Veux-tu arrêter de chercher et\n"
	.string "retourner au comptoir d'accueil ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PleaseFindPartner2:
	.string "Alors, trouve un partenaire parmi\n"
	.string "les DRESSEURS rassemblés ici.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ThankYouForChoosingPartner::
	.string "Merci d'avoir choisi un partenaire.\p"
	.string "Je vais maintenant t'emmener dans\n"
	.string "ta SALLE DE COMBAT MULTI.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Intro::
	.string "Je suis l'apprenti no {STR_VAR_1} de {STR_VAR_2}.\n"
	.string "Tu peux m'appeler {STR_VAR_3} !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon1::
	.string "Sur les conseils de {STR_VAR_1}, j'ai amené\n"
	.string "un {STR_VAR_3} avec {STR_VAR_2} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Mon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}.\p"
	.string "S'il te plaît, laisse-moi te rejoindre en équipe.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Accept::
	.string "Merci !\n"
	.string "Je vais m'inscrire tout de suite.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice1Reject::
	.string "Je voulais vraiment former une équipe en relais\n"
	.string "avec toi, {PLAYER}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Intro::
	.string "Je suis l'apprenti no {STR_VAR_1} de {STR_VAR_2}.\n"
	.string "Je m'appelle {STR_VAR_3}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon1::
	.string "J'ai eu des conseils de {STR_VAR_1} et j'ai choisi\n"
	.string "un {STR_VAR_3} avec {STR_VAR_2} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Mon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}.\p"
	.string "S'il te plaît, formons une équipe en duo !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Accept::
	.string "Merci beaucoup !\n"
	.string "Je finirai l'inscription rapidement !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_UnusedApprentice2Reject::
	.string "{PLAYER}, j'espérais pouvoir\n"
	.string "faire équipe avec toi…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Intro::
	.string "Euh, je m'appelle {STR_VAR_3}, et je suis\n"
	.string "le n  {STR_VAR_1} apprenti de {STR_VAR_2}.\p"
	.string "Snif…\p"
	.string "Je suis désolé !\n"
	.string "Cette tension me fait pleurer…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon1::
	.string "{STR_VAR_3} m'a conseillé, alors j'ai\n"
	.string "un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Mon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}.\p"
	.string "Snif…\n"
	.string "S'il te plaît, fais équipe avec moi !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Accept::
	.string "Oh, vraiment ? Tu veux bien ?\n"
	.string "Génial ! Super ! Awoooh !\p"
	.string "Oh… Pardon…\n"
	.string "Je suis tellement heureux que je pleure…\p"
	.string "Je vais m'inscrire tout de suite.\n"
	.string "Ne pars pas !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice1Reject::
	.string "Oh, m-mais…\n"
	.string "Snif… Waaaaah !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Intro::
	.string "Salut ! Je suis {STR_VAR_3} !\n"
	.string "Je suis l'apprenti no {STR_VAR_1} de {STR_VAR_2} !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon1::
	.string "{STR_VAR_3} a recommandé mon équipe.\n"
	.string "Un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Mon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1},\n"
	.string "c'est ce que j'ai ! Cool, non ?\p"
	.string "Allez !\n"
	.string "Formons une équipe !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Accept::
	.string "Yay ! Super !\n"
	.string "D'accord, je vais m'inscrire, d'accord ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice2Reject::
	.string "Aww, pourquoi ?\n"
	.string "Je voulais faire équipe, {PLAYER} !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Intro::
	.string "Je suis {STR_VAR_3}, l'apprenti no {STR_VAR_2}\n"
	.string "du célèbre {STR_VAR_1} !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon1::
	.string "J'ai demandé conseil à {STR_VAR_3}.\n"
	.string "Un {STR_VAR_1} utilisant {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Mon2Ask::
	.string "et un {STR_VAR_2} avec {STR_VAR_1},\n"
	.string "voilà mon duo.\p"
	.string "S'il te plaît, tu veux bien me rejoindre\n"
	.string "en combat en duo ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Accept::
	.string "Merci !\n"
	.string "Je m'inscris tout de suite !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice3Reject::
	.string "{PLAYER}, j'espérais pouvoir te rejoindre\n"
	.string "en équipe en relais…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Intro::
	.string "Euh… Je suis sincèrement content que tu\n"
	.string "prennes le temps de me parler.\p"
	.string "Je suis {STR_VAR_3}.\n"
	.string "Je suis le n  {STR_VAR_1} apprenti de {STR_VAR_2}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon1::
	.string "{STR_VAR_3} m'a donné des conseils.\n"
	.string "J'en suis très reconnaissant.\p"
	.string "J'ai une équipe avec un {STR_VAR_2}\n"
	.string "avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Mon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}.\n"
	.string "Je sais que je demande beaucoup…\p"
	.string "Je ne pense pas que tu voudras,\n"
	.string "mais puis-je te rejoindre comme partenaire ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Accept::
	.string "Vraiment ? Je n'arrive pas à y croire !\n"
	.string "Je n'arrive pas à croire que tu me laisses\l"
	.string "me joindre à toi !\p"
	.string "Euh… Si c'est vraiment d'accord,\n"
	.string "je vais m'inscrire tout de suite !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice4Reject::
	.string "Oh…\n"
	.string "Je ne pensais pas être assez bon…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Intro::
	.string "Salut, je suis {STR_VAR_3}.\n"
	.string "Je suis le n  {STR_VAR_1} apprenti de {STR_VAR_2} !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon1::
	.string "{STR_VAR_3} m'a dit qu'il serait bon\n"
	.string "de faire cette équipe :\l"
	.string "un {STR_VAR_1} utilisant {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Mon2Ask::
	.string "et un {STR_VAR_2} qui sait utiliser\n"
	.string "{STR_VAR_1}.\p"
	.string "Pas mal, hein ?\n"
	.string "Tu veux faire équipe avec moi ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Accept::
	.string "D'accord, content de te rejoindre !\n"
	.string "J'espère que tu ne vas pas tout gâcher pour moi !\l"
	.string "Je vais faire mon enregistrement maintenant.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice5Reject::
	.string "Hein ? Pourquoi tu as refusé ?\n"
	.string "Tu ne sais pas juger le caractère !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Intro::
	.string "Je suis {STR_VAR_3} et je suis TRIATHLETE.\n"
	.string "Je suis occupé chaque jour entre jogging,\l"
	.string "entraînement et rap.\p"
	.string "Je suis aussi le n  {STR_VAR_1} apprenti\n"
	.string "de {STR_VAR_2}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon1::
	.string "C'est ce que {STR_VAR_3} a recommandé.\n"
	.string "Un {STR_VAR_1} utilisant {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Mon2Ask::
	.string "et un {STR_VAR_1} utilisant\n"
	.string "{STR_VAR_2}.\p"
	.string "J'ai mis beaucoup d'efforts à les élever\n"
	.string "même si je suis occupé.\p"
	.string "Formons une équipe en duo\n"
	.string "et essayons !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Accept::
	.string "Merci, c'est l'esprit !\n"
	.string "Attends un peu pendant que je m'enregistre, OK ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice6Reject::
	.string "J'ai pris du temps sur mon emploi du temps chargé\n"
	.string "pour être ici ! Laisse-moi tranquille !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Intro::
	.string "Salut !\n"
	.string "Comment ça va ?\p"
	.string "Je suis {STR_VAR_3}, l'apprenti n  {STR_VAR_1}\n"
	.string "de {STR_VAR_2}. Enchanté !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon1::
	.string "Écoute, écoute ! Tu dois entendre\n"
	.string "parler du POKéMON que {STR_VAR_3} recommande.\l"
	.string "Un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Mon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}.\n"
	.string "Bien sûr, je les ai élevés superbement !\p"
	.string "Alors, on fait équipe ?\n"
	.string "Je suis sûr que ce sera génial !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Accept::
	.string "Yay, je pense que ça va être amusant !\n"
	.string "Je vais m'inscrire !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice7Reject::
	.string "Oh, tu es méchant !\n"
	.string "On m'a recommandé, tu sais.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Intro::
	.string "Permettez-moi de me présenter.\n"
	.string "Je suis {STR_VAR_3}.\p"
	.string "Je suis l'apprenti n  {STR_VAR_1}\n"
	.string "de {STR_VAR_2}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon1::
	.string "J'ai suivi les avis avisés de\n"
	.string "{STR_VAR_3} et j'ai élevé mon équipe\l"
	.string "d'un seul {STR_VAR_2} avec {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Mon2Ask::
	.string "et un {STR_VAR_2} avec {STR_VAR_1}.\p"
	.string "Accepte de faire équipe avec moi !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Accept::
	.string "Oh… Je suis ravie !\n"
	.string "Je promets de donner le meilleur de moi-même !\p"
	.string "Bien sûr que je vais nous enregistrer !\n"
	.string "Attends un instant !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice8Reject::
	.string "J'espérais pouvoir faire équipe\n"
	.string "avec toi, {PLAYER}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Intro::
	.string "Eek ! Tu m'as parlé !\n"
	.string "Je... Je suis aux anges !\p"
	.string "Je suis {STR_VAR_3} ! Je suis l'apprenti\n"
	.string "n  {STR_VAR_1} de {STR_VAR_2} !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon1::
	.string "Sur les conseils de {STR_VAR_3}, j'ai entraîné\n"
	.string "un {STR_VAR_1} utilisant {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Mon2Ask::
	.string "et un {STR_VAR_1} utilisant {STR_VAR_2}. S'il\n"
	.string "te plaît, peux-tu exaucer mon\p"
	.string "souhait ? Je veux être\n"
	.string "ton partenaire en duo !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Accept::
	.string "Eek ! Je… Je me sens toute chose !\n"
	.string "Merci beaucoup !\l"
	.string "Je vais nous inscrire tout de suite !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice9Reject::
	.string "Waaah ! Tu n'as aucune pitié ?\n"
	.string "Mais ça te rend plus cool…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Intro::
	.string "Yeehaw ! Je suis l'apprenti nº {STR_VAR_1} de\n"
	.string "{STR_VAR_2} !\p"
	.string "{STR_VAR_3} c'est mon nom, bonjour, bonjour !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon1::
	.string "Mon mentor {STR_VAR_3} a recommandé\n"
	.string "un {STR_VAR_1} maître de {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Mon2Ask::
	.string "et un {STR_VAR_1} maître de {STR_VAR_2}.\p"
	.string "Pas mal, hein ?\n"
	.string "Tu veux bien faire équipe avec moi,\n"
	.string "n'est-ce pas ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Accept::
	.string "D'accord, excellent !\n"
	.string "Je m'occupe vite de l'inscription !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice10Reject::
	.string "Gwaaah !\n"
	.string "Tu es calculateur, {PLAYER} !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Intro::
	.string "Hé ! Gros problème ! C'est le\n"
	.string "dernier jour de la TOUR DE COMBAT\p"
	.string "! … … … … … …\n"
	.string "Je plaisante ! On m'appelle {STR_VAR_3} et\p"
	.string "moi aussi ! Je suis l'apprenti no\n"
	.string "1 000 de {STR_VAR_1} ! En fait,\l"
	.string "je suis le no {STR_VAR_2} !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon1::
	.string "{STR_VAR_3} m'a donné des conseils.\n"
	.string "{STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Mon2Ask::
	.string "{STR_VAR_2} avec {STR_VAR_1}.\n"
	.string "J'en ai dix de chaque sorte !\l"
	.string "En fait, un seul de chaque !\p"
	.string "Ça te dit ?\n"
	.string "Tu veux essayer des combats en duo avec moi ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Accept::
	.string "Youpi !\n"
	.string "Je te donne un POKéMON en remerciement !\p"
	.string "Je plaisante ! Mais je vais vraiment\n"
	.string "aller m'inscrire, OK ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice11Reject::
	.string "Oh, c'est si froid ! Je vais devoir détruire la\n"
	.string "TOUR DE COMBAT pour ça !\p"
	.string "Bien sûr que je ne le ferai pas !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Intro::
	.string "Hé, je suis rock'n'roll ! POKéMON, je\n"
	.string "les contrôle ! Je suis {STR_VAR_3}\p"
	.string "le MARIN qui rappe. Ne me\n"
	.string "prends pas pour un pleurnicheur !\p"
	.string "Je suis l'apprenti no {STR_VAR_1} de\n"
	.string "{STR_VAR_2}. Ne me sous-estime pas !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon1::
	.string "Sur les conseils de {STR_VAR_3}, j'ai constitué\n"
	.string "l'équipe dont je suis fier !\l"
	.string "Un {STR_VAR_1} utilisant {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Mon2Ask::
	.string "et un {STR_VAR_1} utilisant {STR_VAR_2}\n"
	.string "! Notre rencontre mérite\p"
	.string "d'être célébrée par une\n"
	.string "victoire en duo !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Accept::
	.string "Hé, hé, j'aime ton style !\n"
	.string "Notre inscription, je vais la déposer !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice12Reject::
	.string "Oh, hé, {PLAYER}, c'est dur !\n"
	.string "Si je puis me permettre !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Intro::
	.string "Youpi-youhou !\n"
	.string "Oh, ne pars pas ! Je m'amusais !\p"
	.string "Salut ! Je suis {STR_VAR_3} !\n"
	.string "Je suis l'apprenti n  {STR_VAR_1} de {STR_VAR_2} !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon1::
	.string "{STR_VAR_3} m'a dit quoi faire.\n"
	.string "Alors un {STR_VAR_1} qui utilise {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Mon2Ask::
	.string "et un {STR_VAR_1} utilisant {STR_VAR_2},\n"
	.string "c'est ce que j'ai choisi.\p"
	.string "Alors, qu'en dis-tu ?\n"
	.string "Allez, fais-moi plaisir !\p"
	.string "S'il te plaît, je t'en supplie !\n"
	.string "Laisse-moi te rejoindre, ne me laisse pas sur un plateau !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Accept::
	.string "Yeah ! La chance est avec moi !\n"
	.string "Ça me rend tellement heureux !\p"
	.string "Avant de rejoindre la mêlée,\n"
	.string "je vais m'inscrire tout de suite !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice13Reject::
	.string "Tu refuses ?\n"
	.string "{PLAYER}, tu me fais froncer les sourcils !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Intro::
	.string "Kof !\p"
	.string "Oh, pardon, j'ai un rhume.\n"
	.string "Mes POKéMON vont bien, par contre.\p"
	.string "Je m'appelle {STR_VAR_3}, apprenti n  {STR_VAR_1}\n"
	.string "de {STR_VAR_2}. Kof !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon1::
	.string "J'ai suivi les conseils de {STR_VAR_3}\n"
	.string "et constitué mon équipe avec\l"
	.string "un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Mon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}.\p"
	.string "Je les ai entraînés chaque jour,\n"
	.string "même par le vent et la pluie.\p"
	.string "C'est pour ça que j'ai ce rhume,\n"
	.string "je crois.\p"
	.string "C'est ce que je suis.\n"
	.string "Tu veux être mon partenaire ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Accept::
	.string "Merci, j'apprécie !\n"
	.string "Tousse, tousse !\l"
	.string "Attends pendant que je m'inscris.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice14Reject::
	.string "Oh, tu refuses ?\n"
	.string "{PLAYER}, je crois qu'on ferait une bonne équipe.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Intro::
	.string "Oh, bonjour !\n"
	.string "C'est stressant.\p"
	.string "Je suis {STR_VAR_3}.\n"
	.string "Je suis l'apprenti n  {STR_VAR_2} de {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon1::
	.string "{STR_VAR_3} a dit que cette équipe serait bien--\n"
	.string "un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Mon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}.\p"
	.string "Je me sens un peu gêné,\n"
	.string "mais tu veux bien que je te rejoigne ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Accept::
	.string "Oh, merci beaucoup !\n"
	.string "Je suis gênée, mais je vais faire de mon mieux !\p"
	.string "Je vais faire l'enregistrement.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice15Reject::
	.string "Oh, ne dis pas non, s'il te plaît !\n"
	.string "Je suis déjà assez mal à l'aise…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Intro::
	.string "Je suis {STR_VAR_3}, et ce n'est pas un mensonge.\n"
	.string "Je suis le n  {STR_VAR_1} apprenti de {STR_VAR_2}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon1::
	.string "{STR_VAR_3} a recommandé mon équipe.\p"
	.string "Comme les conseils semblaient sincères,\n"
	.string "j'ai décidé d'emmener avec moi\l"
	.string "mon {STR_VAR_1} utilisant {STR_VAR_2} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Mon2Ask::
	.string "mon {STR_VAR_1} utilisant {STR_VAR_2}.\p"
	.string "Si possible, j'aimerais que tu m'acceptes\n"
	.string "comme partenaire en équipe.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Accept::
	.string "Tu vas vraiment m'accepter ?\n"
	.string "Ce serait trop terrible sinon.\p"
	.string "Mais puisque tu as accepté, c'est parfait.\n"
	.string "Je vais nous inscrire tous les deux.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_Apprentice16Reject::
	.string "Hm ? Pourquoi refuserais-tu ?\n"
	.string "C'est une blague ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassIntro::
	.string "Je suis {STR_VAR_1}, et je suis FILLETTE !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon1::
	.string "Ce que j'ai, c'est un {STR_VAR_2}\n"
	.string "qui utilise {STR_VAR_1} et un$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassMon2Ask::
	.string "un {STR_VAR_2} qui utilise {STR_VAR_1}.\n"
	.string "C'est ce que j'ai avec moi.\p"
	.string "Tu veux être mon partenaire ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassAccept::
	.string "Merci !\n"
	.string "Je vais m'inscrire !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LassReject::
	.string "Tu ne veux pas être mon partenaire ?\n"
	.string "Tu le regretteras plus tard !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterIntro::
	.string "Bonjour !\p"
	.string "Je suis GAMIN {STR_VAR_1} !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon1::
	.string "Tu veux savoir ce que j'ai ?\n"
	.string "Un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1} !\p"
	.string "Tu seras mon partenaire d'équipe,\n"
	.string "n'est-ce pas ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterAccept::
	.string "Yay !\n"
	.string "Je vais m'inscrire, d'accord ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_YoungsterReject::
	.string "Aïe ! Si tu formais une équipe en duo avec\n"
	.string "mes POKéMON, on serait imbattables !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerIntro::
	.string "Youhou !\n"
	.string "Je suis MONTAGNARD {STR_VAR_1} !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon1::
	.string "Tu sais ce que j'ai sur moi ?\n"
	.string "Mon {STR_VAR_1} qui utilise {STR_VAR_2} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerMon2Ask::
	.string "mon {STR_VAR_1} utilisant {STR_VAR_2} !\p"
	.string "Ça a l'air bien, hein ?\n"
	.string "Tu veux former une équipe ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerAccept::
	.string "Yahoo !\n"
	.string "Je vais m'inscrire, alors.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HikerReject::
	.string "J'aurais aimé combattre\n"
	.string "à tes côtés.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyIntro::
	.string "Bonjour !\n"
	.string "Je suis {STR_VAR_1}, et je suis une TOP MODEL !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon1::
	.string "Tu sais ce que j'ai élevé ?\n"
	.string "Un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1} !\p"
	.string "Qu'en penses-tu ?\n"
	.string "On forme une équipe en duo ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyAccept::
	.string "Formidable !\n"
	.string "Je m'occupe de l'inscription !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BeautyReject::
	.string "Comme c'est décevant !\p"
	.string "Nous deux ensemble-on aurait été\n"
	.string "les meilleurs !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanIntro::
	.string "Yo !\p"
	.string "Tu sais qui je suis ?\n"
	.string "Je suis {STR_VAR_1} le PÊCHEUR !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon1::
	.string "J'ai avec moi une équipe d'un\n"
	.string "{STR_VAR_1} qui utilise {STR_VAR_2} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanMon2Ask::
	.string "un {STR_VAR_1} utilisant {STR_VAR_2}.\p"
	.string "Alors, qu'est-ce que tu dis ?\n"
	.string "Tu veux combattre à mes côtés ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanAccept::
	.string "Bien, bien !\n"
	.string "Laisse faire !\p"
	.string "Je vais aller nous inscrire.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_FishermanReject::
	.string "On s'accordait parfaitement, pourtant…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyIntro::
	.string "Enchantée de te rencontrer.\n"
	.string "Je suis {STR_VAR_1}, une LADY.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon1::
	.string "Je suis accompagné d'une équipe d'un\n"
	.string "{STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}.\p"
	.string "J'espère te plaire.\n"
	.string "Car je souhaite être ton partenaire.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyAccept::
	.string "Je te remercie sincèrement.\n"
	.string "Je m'occupe de l'inscription.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_LadyReject::
	.string "Je suis sûr que tu regretteras de ne pas\n"
	.string "m'avoir comme partenaire.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFIntro::
	.string "Je suis TRIATHLÈTE {STR_VAR_1} !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon1::
	.string "Ce que j'ai…\n"
	.string "Un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1} !\n"
	.string "C'est mon duo !\p"
	.string "S'il te plaît ?\n"
	.string "Tu veux former une équipe en duo avec moi ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFAccept::
	.string "Merci !\n"
	.string "Je vais m'inscrire au comptoir.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteFReject::
	.string "Nous deux ensemble, on aurait été\n"
	.string "forts à coup sûr !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherIntro::
	.string "Hiya !\n"
	.string "Je suis CHASSEUR D'INSECTES {STR_VAR_1} !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon1::
	.string "Regarde ce que j'ai !\n"
	.string "Un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1} !\p"
	.string "Alors, écoute !\n"
	.string "Tu veux former une équipe ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherAccept::
	.string "Compris !\p"
	.string "Je vais m'occuper de l'inscription\n"
	.string "au comptoir.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugCatcherReject::
	.string "Aww, mes POKéMON sont géniaux.\n"
	.string "J'espère que tu ne le regretteras pas !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMIntro::
	.string "Bonjour !\n"
	.string "Je suis ÉCOLIER {STR_VAR_1} !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon1::
	.string "Ce que j'élève, c'est un\n"
	.string "{STR_VAR_2} qui utilise {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMMon2Ask::
	.string "et un {STR_VAR_2} qui utilise\n"
	.string "{STR_VAR_1}.\p"
	.string "Pas mal, tu ne trouves pas ?\n"
	.string "Ça te dit de former une équipe ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMAccept::
	.string "Merci beaucoup !\n"
	.string "Je m'occupe de l'inscription.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidMReject::
	.string "C'est dommage…\p"
	.string "J'espérais pouvoir apprendre\n"
	.string "de toi en tant que partenaire…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyIntro::
	.string "Yo ! Laisse-moi te dire qui je suis !\n"
	.string "Je suis RICHARD {STR_VAR_1} !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon1::
	.string "Devine ce que j'ai !\n"
	.string "Un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1} !\p"
	.string "Je t'offre la chance\n"
	.string "de faire équipe avec moi.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyAccept::
	.string "Bon choix !\p"
	.string "Je vais finir l'inscription\n"
	.string "rapidement !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RichBoyReject::
	.string "Tu me refuserais, moi ?\n"
	.string "Tu regretteras cette décision, c'est sûr !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltIntro::
	.string "Hiyah !\n"
	.string "Je suis KARATÉKA {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon1::
	.string "Comme compagnons, j'ai\n"
	.string "un {STR_VAR_2} qui utilise {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltMon2Ask::
	.string "et un {STR_VAR_2} utilisant\n"
	.string "{STR_VAR_1}.\p"
	.string "S'il te plaît, exauce mon voeu !\n"
	.string "Laisse-moi être ton partenaire !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltAccept::
	.string "Hiyah !\n"
	.string "Je vais m'inscrire tout de suite !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BlackBeltReject::
	.string "Je vois… J'espère une autre occasion\n"
	.string "la prochaine fois qu'on se verra…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFIntro::
	.string "Salut !\n"
	.string "Je suis {STR_VAR_1}, et je suis une NAGEUSE !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon1::
	.string "Je vais te dire ce que j'ai.\n"
	.string "Un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1} !\n"
	.string "Puis-je faire équipe avec toi en duo ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFAccept::
	.string "Merci !\n"
	.string "Je vais nous inscrire !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberFReject::
	.string "Si on était devenus partenaires,\n"
	.string "on aurait pu être si forts !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacIntro::
	.string "Salutations…\n"
	.string "Je suis FOLLEUR {STR_VAR_1}…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon1::
	.string "J'ai avec moi un {STR_VAR_1} qui utilise\n"
	.string "{STR_VAR_2} ainsi qu'un$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacMon2Ask::
	.string "{STR_VAR_1} utilisant {STR_VAR_2}…\p"
	.string "Je t'en supplie…\n"
	.string "Fais équipe avec moi…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacAccept::
	.string "Je te remercie…\n"
	.string "Je vais nous inscrire…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_HexManiacReject::
	.string "Je rêvais tant de te rejoindre…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMIntro::
	.string "Comment allez-vous ? Je suis {STR_VAR_1},\n"
	.string "et je suis un ÉLEVEUR POKéMON !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon1::
	.string "J'élève une bonne paire !\n"
	.string "Un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1} !\p"
	.string "Alors, qu'est-ce que tu dis ?\n"
	.string "Ça te dit de faire équipe avec moi ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMAccept::
	.string "Merci beaucoup !\p"
	.string "Je vais m'occuper de l'inscription,\n"
	.string "alors attends ici !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederMReject::
	.string "J'avais hâte d'être\n"
	.string "ton partenaire…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFIntro::
	.string "Bonjour !\n"
	.string "Je suis TRIATHLÈTE {STR_VAR_1} !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon1::
	.string "Tu veux savoir avec quoi je joue ?\n"
	.string "Un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1} !\p"
	.string "Alors ?\n"
	.string "Tu veux faire équipe avec moi ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFAccept::
	.string "Bien joué !\p"
	.string "Je vais vite m'occuper de\n"
	.string "l'inscription !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteFReject::
	.string "Toi et moi, on aurait été au top.\n"
	.string "C'est dommage…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMIntro::
	.string "Hé, toi ! Je m'appelle {STR_VAR_1} !\n"
	.string "Je suis un TRIATHLÈTE !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon1::
	.string "Je cours avec mon équipe solide--\n"
	.string "un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1} !\p"
	.string "Pas mal, hein ?\n"
	.string "On devrait former une équipe en duo !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMAccept::
	.string "D'accord !\n"
	.string "Je vais m'inscrire en un éclair !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RunningTriathleteMReject::
	.string "Je voulais vraiment me battre comme\n"
	.string "ton partenaire en équipe…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlIntro::
	.string "Je suis COMBATTANTE {STR_VAR_1} !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon1::
	.string "J'ai renforcé un {STR_VAR_1}\n"
	.string "qui utilise {STR_VAR_2} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlMon2Ask::
	.string "un {STR_VAR_1} utilisant {STR_VAR_2} !\p"
	.string "Tu aimes ce duo ?\n"
	.string "Et si toi et moi on faisait équipe ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlAccept::
	.string "Merci !\p"
	.string "Je m'occupe de l'inscription\n"
	.string "tout de suite !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BattleGirlReject::
	.string "Avec toi, je pensais qu'on pourrait former\n"
	.string "l'équipe ultime en relais…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMIntro::
	.string "Je suis TRIATHLÈTE {STR_VAR_1} !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon1::
	.string "Je cours avec un {STR_VAR_2}\n"
	.string "qui sait utiliser {STR_VAR_1}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMMon2Ask::
	.string "et un {STR_VAR_2} avec {STR_VAR_1} !\p"
	.string "On pourrait former une équipe en duo.\n"
	.string "Ce serait génial, non ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMAccept::
	.string "Merci !\p"
	.string "Je vais nous inscrire,\n"
	.string "et c'est tout de suite !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CyclingTriathleteMReject::
	.string "Dommage ! On aurait formé\n"
	.string "la meilleure équipe en duo !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMIntro::
	.string "Moi ?\n"
	.string "Je suis NAGEUR {STR_VAR_1} !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon1::
	.string "Qu'est-ce que j'ai sur moi ?\n"
	.string "Un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1} !\p"
	.string "Hé ?\n"
	.string "Tu feras équipe avec moi, non ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMAccept::
	.string "D'accord !\p"
	.string "Je vais m'inscrire !\n"
	.string "Soyons excellents ensemble !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_TuberMReject::
	.string "Mes POKéMON sont coriaces, c'est sûr…\n"
	.string "Dommage que tu ne veuilles pas faire équipe.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristIntro::
	.string "Yay-hey !\n"
	.string "Appelle-moi GUITARISTE {STR_VAR_1} !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon1::
	.string "Regarde mon entourage !\n"
	.string "Un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1} !\p"
	.string "Youpi ! Plutôt fou, non ?\n"
	.string "On devrait faire un duo en équipe !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristAccept::
	.string "Youpi ! Parfait !\n"
	.string "Je m'occupe de l'inscription maintenant !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GuitaristReject::
	.string "Mes POKéMON sont durs comme la roche !\n"
	.string "Tu vas le regretter, je te le dis !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanIntro::
	.string "Enchanté de vous rencontrer.\n"
	.string "Je suis {STR_VAR_1}, un GENTLEMAN.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon1::
	.string "Je suis accompagné de mon fidèle\n"
	.string "{STR_VAR_1} qui utilise {STR_VAR_2} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanMon2Ask::
	.string "un {STR_VAR_1} utilisant {STR_VAR_2}.\p"
	.string "Puis-je te demander de m'accepter\n"
	.string "en partenariat d'équipe ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanAccept::
	.string "Ah, je te remercie de ta confiance.\n"
	.string "Je termine l'inscription.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_GentlemanReject::
	.string "C'est vraiment dommage…\p"
	.string "J'attends avec impatience\n"
	.string "la prochaine occasion…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMIntro::
	.string "Bonjour, je suis {STR_VAR_1},\n"
	.string "et je suis un POKéFAN.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon1::
	.string "J'ai avec moi un {STR_VAR_2}\n"
	.string "qui connaît la capacité {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}.\p"
	.string "Ça te plaît ?\n"
	.string "Pourquoi ne pas être mon partenaire en duo ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMAccept::
	.string "Merci !\n"
	.string "Je m'occupe de l'inscription !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanMReject::
	.string "Mes POKéMON sont de premier ordre…\n"
	.string "Dommage que tu ne puisses pas l'apprécier.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMIntro::
	.string "Hm !\n"
	.string "Je suis {STR_VAR_1}, et EXPERT je suis !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon1::
	.string "Les POKéMON que j'ai entraînés sont :\n"
	.string "un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1} !\p"
	.string "Qu'en dis-tu ? Une équipe avec moi ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMAccept::
	.string "Hm !\n"
	.string "Je vais nous inscrire tout de suite !\l"
	.string "Faisons de notre mieux tous les deux !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertMReject::
	.string "J'espère que ton choix\n"
	.string "est le bon…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFIntro::
	.string "Bonjour, bonjour.\n"
	.string "Je suis {STR_VAR_1}, et je suis une EXPERTE.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon1::
	.string "J'ai bien entraîné mes POKéMON.\n"
	.string "Un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}--\n"
	.string "c'est ce que j'ai.\p"
	.string "Tu ne veux pas faire équipe avec moi ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFAccept::
	.string "Bien, bien.\n"
	.string "Je m'occupe de l'inscription tout de suite.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ExpertFReject::
	.string "Peut-être pourrons-nous former une équipe\n"
	.string "la prochaine fois qu'on se croise.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerIntro::
	.string "Je suis DRAGONISTE {STR_VAR_1} !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon1::
	.string "L'équipe que j'ai entraînée est :\n"
	.string "un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1} !\p"
	.string "Alors ?\n"
	.string "Tu veux être mon partenaire ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerAccept::
	.string "OK, je vais faire de mon mieux !\n"
	.string "Je vais m'inscrire maintenant, d'accord ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_DragonTamerReject::
	.string "Tu ne trouveras pas de partenaire\n"
	.string "plus coriace que moi !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperIntro::
	.string "Je suis ORNITHOLOGUE {STR_VAR_1} !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon1::
	.string "Quels POKéMON ai-je ?\n"
	.string "Un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}.\p"
	.string "Tu ne penses pas qu'on ferait une bonne\n"
	.string "équipe ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperAccept::
	.string "Super, merci !\n"
	.string "Je m'occupe de l'inscription !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BirdKeeperReject::
	.string "Mes POKéMON et moi sommes forts.\n"
	.string "Quelle déception.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyIntro::
	.string "Je suis NINJA BOY {STR_VAR_1} !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon1::
	.string "Mon équipe POKéMON est composée d'un\n"
	.string "{STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1} !\p"
	.string "Faisons équipe en duo ensemble !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyAccept::
	.string "Youpi !\n"
	.string "Laisse-moi m'inscrire !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_NinjaBoyReject::
	.string "Tu regretteras de ne pas avoir mes\n"
	.string "POKéMON coriaces à tes côtés !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyIntro::
	.string "Bonjour !\n"
	.string "Je suis DAME PARASOL {STR_VAR_1} !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon1::
	.string "À mes côtés, j'ai mon {STR_VAR_2}\n"
	.string "qui utilise {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyMon2Ask::
	.string "un {STR_VAR_2} qui utilise\n"
	.string "{STR_VAR_1}.\p"
	.string "Ils ne sont pas mignons ?\n"
	.string "Tu veux nous rejoindre en duo ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyAccept::
	.string "Merci beaucoup !\p"
	.string "Je vais m'inscrire au comptoir.\n"
	.string "Ne nous décevons pas mutuellement !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_ParasolLadyReject::
	.string "Mes POKéMON sont terriblement forts.\n"
	.string "Quelle déception…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacIntro::
	.string "Bonjour.\n"
	.string "Je suis {STR_VAR_1}, et je suis un MANIAQUE D'INSECTES !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon1::
	.string "J'ai trouvé mes POKéMON, oui.\n"
	.string "Un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}...\n"
	.string "c'est ce que j'ai trouvé.\p"
	.string "Ça t'intéresserait de former\n"
	.string "une équipe ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacAccept::
	.string "D'accord !\n"
	.string "Compris !\p"
	.string "Je m'occupe vite de l'inscription !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_BugManiacReject::
	.string "Avec les POKéMON que j'ai trouvés,\n"
	.string "on n'aurait pas perdu…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorIntro::
	.string "Ahoy !\n"
	.string "Je suis MARIN {STR_VAR_1} !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon1::
	.string "Laisse-moi te montrer ma fierté !\n"
	.string "Un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1} !\p"
	.string "Bien sûr que tu ne vas pas refuser.\n"
	.string "On fait équipe, d'accord ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorAccept::
	.string "Je ne m'attendais pas à moins !\n"
	.string "Je vais m'inscrire.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SailorReject::
	.string "On aurait balayé l'opposition !\n"
	.string "Dommage !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorIntro::
	.string "Salut, je suis {STR_VAR_1}.\n"
	.string "Je suis un COLLECTIONNEUR.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon1::
	.string "Les joyaux de ma collection sont\n"
	.string "mon {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1} !\p"
	.string "Super, hein ?\n"
	.string "On devrait être en équipe ensemble.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorAccept::
	.string "Oh, oui !\p"
	.string "Bon, ne perdons pas de temps.\n"
	.string "Je vais nous inscrire tous les deux.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CollectorReject::
	.string "Eh bien, c'est décevant.\n"
	.string "Tu n'apprécies pas mes POKéMON.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMIntro::
	.string "Salut, je suis {STR_VAR_1}.\n"
	.string "Je suis un GARDIEN DE POKéMON.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon1::
	.string "À mes côtés, j'ai un {STR_VAR_1}\n"
	.string "qui utilise {STR_VAR_2} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1} !\p"
	.string "Tu ne penses pas qu'on ferait une équipe\n"
	.string "impressionnante ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMAccept::
	.string "C'est super !\n"
	.string "Je m'occupe de l'inscription maintenant.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerMReject::
	.string "La prochaine fois, choisis mes POKéMON,\n"
	.string "d'accord ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFIntro::
	.string "Je m'appelle {STR_VAR_1}.\n"
	.string "Je suis un GARDIEN DE POKéMON !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon1::
	.string "Laisse-moi te parler de mon équipe. J'ai\n"
	.string "un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1} !\p"
	.string "Ça te dirait de former une équipe en duo\n"
	.string "avec ma petite bande ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFAccept::
	.string "On sera au top !\n"
	.string "Je m'occupe de l'inscription rapidement !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnRangerFReject::
	.string "J'espère que tu choisiras mes POKéMON\n"
	.string "la prochaine fois.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyIntro::
	.string "Enchanté. Je suis {STR_VAR_1}.\n"
	.string "Je me considère comme une AROMA LADY.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon1::
	.string "Je voyage avec un {STR_VAR_2}\n"
	.string "qui utilise {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyMon2Ask::
	.string "un {STR_VAR_2} qui utilise\n"
	.string "{STR_VAR_1}.\p"
	.string "J'espère qu'ils te plairont.\n"
	.string "Accepterais-tu d'être mon partenaire ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyAccept::
	.string "Je suis honoré de ton acceptation.\n"
	.string "Je vais m'inscrire tout de suite.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_AromaLadyReject::
	.string "Ce serait merveilleux si on pouvait former\n"
	.string "une équipe la prochaine fois qu'on se voit.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacIntro::
	.string "Tu veux savoir qui je suis ?\n"
	.string "Je suis {STR_VAR_1}, le MANIAQUE des RUINES !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon1::
	.string "Les POKéMON que j'ai avec moi sont :\n"
	.string "un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1} !\p"
	.string "Intéressant, hein ?\n"
	.string "Et si on faisait équipe ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacAccept::
	.string "C'est une sage décision !\n"
	.string "Je vais faire les démarches d'inscription.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_RuinManiacReject::
	.string "Hmm…\n"
	.string "Je crois que mes POKéMON sont forts…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMIntro::
	.string "Je suis TOPDRESSEUR {STR_VAR_1} !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon1::
	.string "Les POKéMON que j'ai maintenant sont :\n"
	.string "un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}.\n"
	.string "Cool, non ?\p"
	.string "Tu ne trouves pas que ce serait cool\n"
	.string "qu'on forme une équipe ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMAccept::
	.string "Cool !\n"
	.string "Je m'occupe de l'inscription en un éclair !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerMReject::
	.string "Je pensais qu'on formerait\n"
	.string "la plus grande équipe de tous les temps.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFIntro::
	.string "Je suis TOPDRESSEUR {STR_VAR_1} !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon1::
	.string "L'équipe que j'élève a un\n"
	.string "{STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}.\p"
	.string "Ça te convient ?\n"
	.string "On devient partenaires en duo ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFAccept::
	.string "Ça me va !\n"
	.string "Je m'occupe de l'inscription.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CoolTrainerFReject::
	.string "Je pensais à quel super duo\n"
	.string "on ferait…$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacIntro::
	.string "Heyo !\n"
	.string "Je suis {STR_VAR_1}, le POKéMANIAC !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon1::
	.string "Qu'est-ce qu'un type comme moi a ?\n"
	.string "Un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1},\n"
	.string "c'est ça !\p"
	.string "Allons-y !\n"
	.string "On va tout défoncer en duo !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacAccept::
	.string "Bonne idée !\n"
	.string "Je vais nous inscrire tous les deux !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokemaniacReject::
	.string "Mes POKéMON sont brutaux !\n"
	.string "Ce n'est pas ma faute si tu le regrettes !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerIntro::
	.string "Yo !\n"
	.string "Je suis ALLUMEUR {STR_VAR_1} !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon1::
	.string "Tu sais ce que mon entraînement a produit ?\n"
	.string "Un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1} !\p"
	.string "Alors, qu'est-ce que tu dis ?\n"
	.string "Tu veux former une équipe ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerAccept::
	.string "D'accord !\n"
	.string "Je m'occupe de l'inscription.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_KindlerReject::
	.string "Promets-moi qu'on fera équipe\n"
	.string "la prochaine fois qu'on se croisera.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperIntro::
	.string "Je suis {STR_VAR_1}, et je suis CAMPEUR !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon1::
	.string "J'ai élevé un {STR_VAR_1}\n"
	.string "qui utilise {STR_VAR_2} et un$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperMon2Ask::
	.string "un {STR_VAR_1} utilisant {STR_VAR_2}.\p"
	.string "Tu crois que ce serait amusant de faire équipe ?\n"
	.string "Je parie que oui !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperAccept::
	.string "Yeah !\n"
	.string "J'y vais m'inscrire !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_CamperReject::
	.string "La prochaine fois, d'accord ?\n"
	.string "Je veux être dans ton équipe.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerIntro::
	.string "Salut !\n"
	.string "Je suis {STR_VAR_1}, et je suis une PIQUE-NIQUEUSE !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon1::
	.string "Les POKéMON que j'emmène sont :\n"
	.string "un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}.\p"
	.string "Ça t'intéresse de me rejoindre\n"
	.string "en équipe ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerAccept::
	.string "Merci beaucoup !\n"
	.string "Je vais faire l'inscription maintenant.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PicnickerReject::
	.string "Ce serait sympa si je pouvais te rejoindre\n"
	.string "une autre fois.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMIntro::
	.string "Je suis PSY {STR_VAR_1} !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon1::
	.string "Le duo que j'ai élevé est :\n"
	.string "un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}.\p"
	.string "Tu veux former une équipe\n"
	.string "avec moi ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMAccept::
	.string "Bien sûr !\n"
	.string "Je m'occupe de l'inscription !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicMReject::
	.string "Si on se revoit, c'est à ce moment-là\n"
	.string "que j'aimerais faire équipe avec toi.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFIntro::
	.string "Je suis {STR_VAR_1}.\n"
	.string "Je suis PSYKO.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon1::
	.string "Un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}--\n"
	.string "ce sont mes disciples.\p"
	.string "L'idée de former un duo\n"
	.string "te tente ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFAccept::
	.string "Merci.\n"
	.string "Je m'occupe de l'inscription.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PsychicFReject::
	.string "J'espère qu'il y aura une autre occasion\n"
	.string "de former une alliance.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFIntro::
	.string "Je suis ÉCOLIER {STR_VAR_1} !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon1::
	.string "Un {STR_VAR_1} utilisant {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFMon2Ask::
	.string "et un {STR_VAR_1} utilisant\n"
	.string "{STR_VAR_2} forment mon duo POKéMON.\p"
	.string "Puis-je être ton partenaire\n"
	.string "en équipe ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFAccept::
	.string "Ooh, merci !\n"
	.string "Je m'inscris au comptoir tout de suite !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SchoolKidFReject::
	.string "S'il te plaît ?\n"
	.string "Puis-je te rejoindre la prochaine fois ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFIntro::
	.string "Coucou ! Je m'appelle {STR_VAR_1} !\n"
	.string "Je suis un ÉLEVEUR POKéMON !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon1::
	.string "Les POKéMON que j'ai élevés sont un\n"
	.string "{STR_VAR_1} qui utilise {STR_VAR_2} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFMon2Ask::
	.string "un {STR_VAR_1} utilisant {STR_VAR_2}.\p"
	.string "Ça t'intéresse ?\n"
	.string "On forme une équipe en duo ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFAccept::
	.string "Très bien !\n"
	.string "Laisse-moi l'inscription !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PkmnBreederFReject::
	.string "Tu devras faire équipe avec moi\n"
	.string "la prochaine fois, d'accord ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFIntro::
	.string "Je suis {STR_VAR_1}, et je suis fier de dire\n"
	.string "que je suis un POKéFAN.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon1::
	.string "Les adorables POKéMON que j'ai élevés sont :\n"
	.string "un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1}.\p"
	.string "Ils ne sont pas adorables ?\n"
	.string "On devrait faire équipe !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFAccept::
	.string "Merci, chéri !\n"
	.string "Je vais m'inscrire !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_PokefanFReject::
	.string "Mes adorables POKéMON sont les meilleurs,\n"
	.string "je te l'assure. Comme c'est agaçant !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFIntro::
	.string "Salut, je suis NAGEUR {STR_VAR_1}.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon1::
	.string "Un {STR_VAR_1} utilisant {STR_VAR_2}$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFMon2Ask::
	.string "et un {STR_VAR_1} utilisant\n"
	.string "{STR_VAR_2} sont ce que j'ai entraînés.\p"
	.string "Toi et moi, formons une équipe.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFAccept::
	.string "C'est cool !\n"
	.string "Je vais nous inscrire tous les deux.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerFReject::
	.string "Si on se revoit, tu me dois\n"
	.string "un combat en duo !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMIntro::
	.string "Que se passe-t-il ?\n"
	.string "Je suis {STR_VAR_1}, et je suis TRIATHLETE.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon1::
	.string "J'ai deux POKéMON plutôt corrects.\n"
	.string "Un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1} !\p"
	.string "Ce serait sympa qu'on fasse équipe\n"
	.string "ensemble, qu'en dis-tu ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMAccept::
	.string "Parfait !\n"
	.string "Attends pendant que je m'inscris, d'accord ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteMReject::
	.string "J'espère que tu me laisseras te rejoindre\n"
	.string "la prochaine fois, d'accord ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFIntro::
	.string "Je suis le TRIATHLÈTE {STR_VAR_1} !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon1::
	.string "Un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFMon2Ask::
	.string "un autre {STR_VAR_2} qui sait utiliser\n"
	.string "{STR_VAR_1}. C'est mon duo.\p"
	.string "Qu'en penses-tu ?\n"
	.string "On ferait une bonne équipe, je crois.$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFAccept::
	.string "J'aime cette réponse !\n"
	.string "Je m'occupe vite de l'inscription !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmingTriathleteFReject::
	.string "Tu me donneras une autre chance de former\n"
	.string "un partenariat, n'est-ce pas ?$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMIntro::
	.string "Salut ! Bonjour !\n"
	.string "Je suis {STR_VAR_1}, et je suis NAGEUR !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon1::
	.string "Regarde ce que j'ai élevé !\n"
	.string "Un {STR_VAR_2} avec {STR_VAR_1} et$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMMon2Ask::
	.string "un {STR_VAR_2} avec {STR_VAR_1} !\p"
	.string "Cool, hein ?\n"
	.string "Ce serait cool de former une équipe aussi !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMAccept::
	.string "Merci beaucoup !\n"
	.string "Je m'occupe de cette inscription !$"

BattleFrontier_BattleTowerMultiPartnerRoom_Text_SwimmerMReject::
	.string "Si on se revoit, tu dois faire équipe\n"
	.string "avec moi. Tu le feras, hein ?$"

