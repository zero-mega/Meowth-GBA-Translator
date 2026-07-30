.set LOCALID_WALLY, 6
.set LOCALID_WALLYS_UNCLE, 7
.set LOCALID_SCOTT, 11

MauvilleCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MauvilleCity_OnTransition
	.byte 0

MauvilleCity_OnTransition:
	setflag FLAG_VISITED_BLACKTHORN_CITY
	clearflag FLAG_FORCE_MIRAGE_TOWER_VISIBLE
	clearflag FLAG_GARBAGEFLAG
	setflag FLAG_SYS_TV_START
	clearflag FLAG_MAUVILLE_GYM_BARRIERS_STATE
	setvar VAR_GARBAGEVAR, 0
	call_if_set FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON, MauvilleCity_EventScript_MoveWattsonBackToGym
	end

MauvilleCity_EventScript_MoveWattsonBackToGym::
	clearflag FLAG_GARBAGEFLAG
	setflag FLAG_GARBAGEFLAG
	setflag FLAG_WATTSON_REMATCH_AVAILABLE
	return

MauvilleCity_EventScript_MagnezoneEvo::
	msgbox MauvilleCity_EventScript_MagnezoneEvo_Text, MSGBOX_NPC
	end

MauvilleCity_EventScript_MagnezoneEvo_Text:
	.string "Tu savais que MAGNETON peut\n"
	.string "évoluer ? Tu sais comment ?\p"
	.string "Parce que… J'aimerais bien le\p"
	.string "savoir.\n"
	.string "Je sais que c'était lié à une\p"
	.string "PIERRE. Une PIERRE FOUDRE,\n"
	.string "pour être exact !\l"
	.string "Mais ce n'était pas en l'utilisant. C'était en combattant ? En la tenant ? Je n'en sais vraiment rien…$"

MauvilleCity_EventScript_Boy::
	msgbox MauvilleCity_Text_NurseHurtMonBackToHealth, MSGBOX_NPC
	end

MauvilleCity_EventScript_Maniac::
	msgbox MauvilleCity_Text_AllSortsOfPeopleComeThrough, MSGBOX_NPC
	end

MauvilleCity_EventScript_Woman::
	msgbox MauvilleCity_Text_RydelVeryGenerous, MSGBOX_NPC
	end

MauvilleCity_EventScript_RichBoy::
	msgbox MauvilleCity_Text_PokemonCanJumpYouOnBike, MSGBOX_NPC
	end

MauvilleCity_EventScript_CitySign::
	msgbox MauvilleCity_Text_CitySign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_GymSign::
	msgbox MauvilleCity_Text_GymSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_BikeShopSign::
	msgbox MauvilleCity_Text_BikeShopSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_GameCornerSign::
	msgbox MauvilleCity_Text_GameCornerSign, MSGBOX_SIGN
	end

MauvilleCity_EventScript_SchoolKidM::
	lock
	faceplayer
	goto_if_set FLAG_TV_EXPLAINED, MauvilleCity_EventScript_TVExplained
	msgbox MauvilleCity_Text_ExplainTV, MSGBOX_DEFAULT
	setflag FLAG_TV_EXPLAINED
	release
	end

MauvilleCity_EventScript_TVExplained::
	msgbox MauvilleCity_Text_BeenCheckingOutTV, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_WallysUncle::
	lock
	faceplayer
	goto_if_set FLAG_DECLINED_WALLY_BATTLE_MAUVILLE, MauvilleCity_EventScript_UncleAskPlayerToBattleWally
	msgbox MauvilleCity_Text_UncleHesTooPeppy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_WALLYS_UNCLE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MauvilleCity_EventScript_UncleAskPlayerToBattleWally::
	msgbox MauvilleCity_Text_UncleCanYouBattleWally, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_WALLYS_UNCLE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MauvilleCity_EventScript_Wally::
	lockall
	goto_if_set FLAG_DECLINED_WALLY_BATTLE_MAUVILLE, MauvilleCity_EventScript_WallyRequestBattleAgain
	applymovement LOCALID_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MauvilleCity_Text_WallyWantToChallengeGym, MSGBOX_DEFAULT
	msgbox MauvilleCity_Text_UncleYourePushingIt, MSGBOX_DEFAULT
	msgbox MauvilleCity_Text_WallyWeCanBeatAnyone, MSGBOX_DEFAULT
	applymovement LOCALID_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_WALLY, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_WALLY, Common_Movement_Delay48
	waitmovement 0
	msgbox MauvilleCity_Text_WallyWillYouBattleMe, MSGBOX_YESNO
	goto MauvilleCity_EventScript_BattleWallyPrompt
	end

MauvilleCity_EventScript_BattleWallyPrompt::
	call_if_eq VAR_RESULT, YES, MauvilleCity_EventScript_BattleWally
	goto_if_eq VAR_RESULT, NO, MauvilleCity_EventScript_DeclineWallyBattle
	closemessage
	switch VAR_FACING
	case DIR_NORTH, MauvilleCity_EventScript_WallyAndUncleExitNorth
	case DIR_EAST, MauvilleCity_EventScript_WallyAndUncleExitEast
	end

MauvilleCity_EventScript_WallyAndUncleExitNorth::
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitNorth1
	applymovement LOCALID_WALLY, MauvilleCity_Movement_WallyExitNorth1
	applymovement LOCALID_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitNorth1
	waitmovement 0
	applymovement LOCALID_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerFaceUncleNorth
	applymovement LOCALID_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleApproachPlayerNorth
	waitmovement 0
	msgbox MauvilleCity_Text_UncleVisitUsSometime, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitNorth2
	applymovement LOCALID_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitNorth2
	applymovement LOCALID_WALLY, MauvilleCity_Movement_WallyExitNorth2
	waitmovement 0
	goto MauvilleCity_EventScript_DefeatedWally
	end

MauvilleCity_EventScript_WallyAndUncleExitEast::
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitEast1
	applymovement LOCALID_WALLY, MauvilleCity_Movement_WallyExitEast1
	applymovement LOCALID_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitEast1
	waitmovement 0
	applymovement LOCALID_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 30
	applymovement LOCALID_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleApproachPlayerEast
	waitmovement 0
	msgbox MauvilleCity_Text_UncleVisitUsSometime, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerWatchWallyExitEast2
	applymovement LOCALID_WALLYS_UNCLE, MauvilleCity_Movement_WallysUncleExitEast2
	applymovement LOCALID_WALLY, MauvilleCity_Movement_WallyExitEast2
	waitmovement 0
	goto MauvilleCity_EventScript_DefeatedWally
	end

MauvilleCity_EventScript_DefeatedWally::
	removeobject LOCALID_WALLY
	removeobject LOCALID_WALLYS_UNCLE
	clearflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	clearflag FLAG_GARBAGEFLAG
	setflag FLAG_DEFEATED_WALLY_MAUVILLE
	setvar VAR_WALLY_CALL_STEP_COUNTER, 0
	setflag FLAG_ENABLE_FIRST_WALLY_POKENAV_CALL
	call_if_eq VAR_FACING, DIR_NORTH, MauvilleCity_EventScript_ScottApproachPlayerNorth
	call_if_eq VAR_FACING, DIR_EAST, MauvilleCity_EventScript_ScottApproachPlayerEast
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox MauvilleCity_Text_ScottYouDidntHoldBack, MSGBOX_DEFAULT
	closemessage
	addvar VAR_SCOTT_STATE, 1
	call_if_eq VAR_FACING, DIR_NORTH, MauvilleCity_EventScript_ScottExitNorth
	call_if_eq VAR_FACING, DIR_EAST, MauvilleCity_EventScript_ScottExitEast
	removeobject LOCALID_SCOTT
	releaseall
	end

MauvilleCity_EventScript_ScottApproachPlayerNorth::
	addobject LOCALID_SCOTT
	applymovement LOCALID_SCOTT, MauvilleCity_Movement_ScottApproachPlayerNorth
	waitmovement 0
	return

MauvilleCity_EventScript_ScottApproachPlayerEast::
	setobjectxyperm LOCALID_SCOTT, 12, 13
	addobject LOCALID_SCOTT
	applymovement LOCALID_SCOTT, MauvilleCity_Movement_ScottApproachPlayerEast
	waitmovement 0
	return

MauvilleCity_EventScript_ScottExitNorth::
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerWatchScottExitNorth
	applymovement LOCALID_SCOTT, MauvilleCity_Movement_ScottExitNorth
	waitmovement 0
	return

MauvilleCity_EventScript_ScottExitEast::
	applymovement OBJ_EVENT_ID_PLAYER, MauvilleCity_Movement_PlayerWatchScottExitEast
	applymovement LOCALID_SCOTT, MauvilleCity_Movement_ScottExitEast
	waitmovement 0
	return

MauvilleCity_EventScript_BattleWally::
	msgbox MauvilleCity_Text_WallyHereICome, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLY_MAUVILLE, MauvilleCity_Text_WallyDefeat
	applymovement LOCALID_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MauvilleCity_Text_WallyIllGoBackToVerdanturf, MSGBOX_DEFAULT
	applymovement LOCALID_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MauvilleCity_Text_ThankYouNotEnoughToBattle, MSGBOX_DEFAULT
	applymovement LOCALID_WALLY, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox MauvilleCity_Text_UncleNoNeedToBeDown, MSGBOX_DEFAULT
	return

MauvilleCity_EventScript_DeclineWallyBattle::
	setflag FLAG_DECLINED_WALLY_BATTLE_MAUVILLE
	msgbox MauvilleCity_Text_WallyMyUncleWontKnowImStrong, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_WallyRequestBattleAgain::
	applymovement LOCALID_WALLY, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MauvilleCity_Text_WallyPleaseBattleMe, MSGBOX_YESNO
	goto MauvilleCity_EventScript_BattleWallyPrompt
	end

MauvilleCity_Movement_WallyExitNorth1:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	step_end

MauvilleCity_Movement_WallyExitEast1:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_WallyExitNorth2:
	delay_16
	delay_16
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_8
	step_end

MauvilleCity_Movement_WallyExitEast2:
	delay_16
	delay_16
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	delay_8
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitNorth2:
	delay_16
	delay_8
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitEast2:
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchScottExitNorth:
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchScottExitEast:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitEast1:
	delay_16
	walk_in_place_faster_down
	step_end

MauvilleCity_Movement_PlayerWatchWallyExitNorth1:
	delay_16
	walk_in_place_faster_left
	step_end

MauvilleCity_Movement_WallysUncleExitNorth1:
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

MauvilleCity_Movement_WallysUncleExitEast1:
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_PlayerFaceUncleNorth:
	delay_16
	delay_8
	delay_4
	walk_in_place_faster_down
	step_end

MauvilleCity_Movement_WallysUncleApproachPlayerNorth:
	walk_right
	walk_right
	walk_in_place_faster_up
	step_end

MauvilleCity_Movement_WallysUncleApproachPlayerEast:
	walk_right
	walk_up
	step_end

MauvilleCity_Movement_WallysUncleExitNorth2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_WallysUncleExitEast2:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_ScottApproachPlayerNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_up
	step_end

MauvilleCity_Movement_ScottApproachPlayerEast:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	step_end

MauvilleCity_Movement_ScottExitNorth:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_Movement_ScottExitEast:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MauvilleCity_EventScript_Wattson::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON, MauvilleCity_EventScript_ReceivedThunderbolt
	goto_if_eq VAR_NEW_MAUVILLE_STATE, 2, MauvilleCity_EventScript_CompletedNewMauville
	goto_if_set FLAG_GOT_BASEMENT_KEY_FROM_WATTSON, MauvilleCity_EventScript_BegunNewMauville
	msgbox MauvilleCity_Text_WattsonNeedFavorTakeKey, MSGBOX_DEFAULT
	giveitem ITEM_BASEMENT_KEY
	setflag FLAG_GOT_BASEMENT_KEY_FROM_WATTSON
	msgbox MauvilleCity_Text_WattsonWontBeChallenge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_BegunNewMauville::
	msgbox MauvilleCity_Text_WattsonWontBeChallenge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_CompletedNewMauville::
	msgbox MauvilleCity_Text_WattsonThanksTakeTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_THUNDERBOLT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_TM_THUNDERBOLT_FROM_WATTSON
	msgbox MauvilleCity_Text_WattsonYoungTakeCharge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_ReceivedThunderbolt::
	msgbox MauvilleCity_Text_WattsonYoungTakeCharge, MSGBOX_DEFAULT
	release
	end

MauvilleCity_EventScript_RegisterWallyCall::
	lockall
	pokenavcall MauvilleCity_Text_WallyPokenavCall
	waitmessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MauvilleCity_Text_RegisteredWally, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WALLY_MATCH_CALL
	clearflag FLAG_ENABLE_FIRST_WALLY_POKENAV_CALL
	releaseall
	end

MauvilleCity_Text_UncleHesTooPeppy:
	.string "ONCLE : C'est grâce aux POKéMON que\n"
	.string "ce garçon a plus d'énergie, je suppose...\l"
	.string "Mais il est devenu un peu trop énergique...$"

MauvilleCity_Text_WallyWantToChallengeGym:
	.string "PETER : Oh, ONCLE, s'il te plaît ?\p"
	.string "Je veux défier cette ARÈNE et voir à\n"
	.string "quel point je me suis amélioré. S'il te\p"
	.string "plaît ? Je peux, s'il te plaît ?$"

MauvilleCity_Text_UncleYourePushingIt:
	.string "ONCLE : Attends, ALAIN.\p"
	.string "Depuis que tu vis avec des POKéMON,\n"
	.string "tu es devenu bien plus fort.\p"
	.string "Mais tu ne crois pas que c'est un peu tôt\n"
	.string "de défier une ARÈNE d'un coup ?$"

MauvilleCity_Text_WallyWeCanBeatAnyone:
	.string "WALLY : Je n'en fais pas trop.\p"
	.string "Si je combine mes forces avec RALTS,\n"
	.string "on peut battre n'importe qui !$"

MauvilleCity_Text_WallyWillYouBattleMe:
	.string "ALAIN : Oh ! Salut, {PLAYER} !\p"
	.string "Je suis devenu bien plus fort depuis\n"
	.string "qu'on s'est rencontrés.\p"
	.string "{PLAYER}, je veux que toi et mon ONCLE\n"
	.string "compreniez ça.\p"
	.string "{PLAYER}, s'il te plaît, veux-tu\n"
	.string "combattre contre moi ?$"

MauvilleCity_Text_WallyMyUncleWontKnowImStrong:
	.string "WALLY : Oh... Si tu ne veux pas te battre,\n"
	.string "{PLAYER}, mon ONCLE ne saura pas\l"
	.string "que je suis devenu vraiment fort.$"

MauvilleCity_Text_UncleCanYouBattleWally:
	.string "ONCLE : {PLAYER}{KUN}, c'est bien ça ?\n"
	.string "Au nom d'ALAIN, peux-tu\l"
	.string "te battre contre lui juste cette fois ?\p"
	.string "Je ne pense pas qu'il va écouter\n"
	.string "la raison dans son état actuel.$"

MauvilleCity_Text_WallyPleaseBattleMe:
	.string "POKÉN : {PLAYER}, s'il te plaît !\n"
	.string "Combats avec moi, s'il te plaît.$"

MauvilleCity_Text_WallyHereICome:
	.string "WALLY : {PLAYER}, merci.\p"
	.string "OK… J'arrive !$"

MauvilleCity_Text_WallyDefeat:
	.string "WALLY : … … … … … … …\p"
	.string "… … … … … … … …\p"
	.string "J'ai perdu…$"

MauvilleCity_Text_WallyIllGoBackToVerdanturf:
	.string "POPI : ONCLE…\n"
	.string "Je retourne à VERGOYON…$"

MauvilleCity_Text_ThankYouNotEnoughToBattle:
	.string "{PLAYER}, merci.\n"
	.string "Être DRESSEUR, c'est dur, n'est-ce pas ?\p"
	.string "Ce n'est pas suffisant de simplement\n"
	.string "collectionner des POKéMON forts.\l"
	.string "Il faut aussi les comprendre.$"

MauvilleCity_Text_UncleNoNeedToBeDown:
	.string "ONCLE : ALAIN, pas besoin d'être\n"
	.string "si abattu.\p"
	.string "Pourquoi, qu'est-ce qui t'empêche de devenir\n"
	.string "de plus en plus fort ?\p"
	.string "Allez, rentrons à la maison.\n"
	.string "Tout le monde t'attend.$"

MauvilleCity_Text_UncleVisitUsSometime:
	.string "ONCLE : {PLAYER}{KUN}, je viens de réaliser\n"
	.string "que tu dois être le DRESSEUR\l"
	.string "qui a surveillé TIMMY quand il\l"
	.string "a attrapé son POKéMON. Pourquoi ne\p"
	.string "pas nous rendre visite à VERCHALORS\n"
	.string "un de ces jours ? Je\l"
	.string "suis sûr que TIMMY serait content.$"


MauvilleCity_Text_WallyPokenavCall:
	.string "… … … …\n"
	.string "… … … …\p"
	.string "… … … Bip\p"
	.string "! TIMMY : Oh,\n"
	.string "bonjour, {PLAYER} ! Je\p"
	.string "voulais juste te dire\n"
	.string "que mon {STR_VAR_1} a\p"
	.string "évolué ! Merci\n"
	.string "pour tout !$"

MauvilleCity_Text_RegisteredWally:
	.string "WALLY enregistré\n"
	.string "dans le POKéNAV.$"

MauvilleCity_Text_ScottYouDidntHoldBack:
	.string "SCOTT : Héhé…\n"
	.string "Je regardais\p"
	.string "ce match !\n"
	.string "Tu es ami avec\p"
	.string "ce garçon WALLY,\n"
	.string "n'est-ce pas ?\p"
	.string "Mais tu\n"
	.string "es encore\p"
	.string "plus fort !\p"
	.string "Impressionnant,\n"
	.string "{PLAYER}{KUN} !$"

MauvilleCity_Text_WattsonNeedFavorTakeKey:
	.string "VOLTEK : Oh, {PLAYER}{KUN} !\n"
	.string "Tu as l'air plein d'énergie !\l"
	.string "C'est une bonne chose, wahahahaha !\p"
	.string "Bien ! J'ai décidé !\n"
	.string "J'ai besoin d'un service, {PLAYER}{KUN} !\p"
	.string "LAVILLIA a un secteur souterrain\n"
	.string "appelé NOUVELLE LAVILLIA.\p"
	.string "{PLAYER}{KUN}, j'aimerais que tu y ailles et\n"
	.string "que tu coupes le GÉNÉRATEUR.\p"
	.string "Le GÉNÉRATEUR tourne un peu à la folie.\n"
	.string "Ça devient dangereux.\p"
	.string "Tiens, voici la CLÉ pour entrer dans\n"
	.string "NOUVELLE LAVILLIA.$"

MauvilleCity_Text_WattsonWontBeChallenge:
	.string "VOLTERE : Ne t'en fais pas.\n"
	.string "Ce ne sera pas un défi\p"
	.string "pour toi. L'entrée de NEW LAVARIA\n"
	.string "est à une petite SURF de\p"
	.string "la ROUTE 110. Voilà, tu as\n"
	.string "ma confiance ! Wahahahaha !$"

MauvilleCity_Text_WattsonThanksTakeTM:
	.string "VOLTÈRE : Wahahahaha !\p"
	.string "Je le savais, {PLAYER}{KUN} ! Je savais que j'avais\n"
	.string "fait le bon choix en te demandant !\p"
	.string "Voici ma gratitude--une CT contenant\n"
	.string "TONNERRE !\p"
	.string "Vas-y, tu l'as mérité !$"

MauvilleCity_Text_WattsonYoungTakeCharge:
	.string "VOLTÈRE : Wahahahaha !\p"
	.string "Ça me réjouit de voir\n"
	.string "les jeunes prendre les choses en main !$"

MauvilleCity_Text_NurseHurtMonBackToHealth:
	.string "Tu sais, c'est cool les combats\n"
	.string "de POKéMON et tout ça…\p"
	.string "Mais si ton POKéMON est blessé,\n"
	.string "il faut le soigner.$"

MauvilleCity_Text_AllSortsOfPeopleComeThrough:
	.string "Les routes de cette ville s'étirent au nord\n"
	.string "et au sud, et à l'est et à l'ouest.\p"
	.string "À cause de ça, on voit passer toutes sortes de\n"
	.string "gens.$"

MauvilleCity_Text_RydelVeryGenerous:
	.string "Tu es déjà allé chez CYCLES RYDEL ?\p"
	.string "RYDEL, le propriétaire, est un homme très\n"
	.string "généreux.$"

MauvilleCity_Text_PokemonCanJumpYouOnBike:
	.string "Même si tu roules à VÉLO,\n"
	.string "des POKéMON sauvages pourraient te sauter dessus.$"

MauvilleCity_Text_CitySign:
	.string "ATALANOPOLIS\n"
	.string "« La cité pleine de vie ! »$"

MauvilleCity_Text_GymSign:
	.string "ARÈNE POKéMON DE LAVILLA\n"
	.string "CHAMPION : VOLTÈRE\l"
	.string "« L'homme joyeusement électrifiant ! »$"

MauvilleCity_Text_BikeShopSign:
	.string "« Roule sur le gravier et secoue\n"
	.string "ton âme ! »\l"
	.string "CYCLES DE VELO$"

MauvilleCity_Text_GameCornerSign:
	.string "« Le terrain de jeu pour tous ! »\n"
	.string "CASINO DE MYOKARA$"

MauvilleCity_Text_ExplainTV:
	.string "Salut, tu regardes\p"
	.string "la télé ?\n"
	.string "Ils ont ajouté plein\p"
	.string "de nouvelles émissions\n"
	.string "cool récemment.\p"
	.string "La télé c'est génial.\n"
	.string "J'ai vu mes amis\p"
	.string "à l'écran !\p"
	.string "Tu devrais regarder\n"
	.string "aussi, {PLAYER}{KUN} !$"

MauvilleCity_Text_BeenCheckingOutTV:
	.string "Salut, tu as regardé la TV ?$"
