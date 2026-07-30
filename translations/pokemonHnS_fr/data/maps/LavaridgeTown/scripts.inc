.set LOCALID_RIVAL_ON_BIKE, 7
.set LOCALID_RIVAL, 8

LavaridgeTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LavaridgeTown_OnFrame
	.byte 0

LavaridgeTown_OnTransition:
	setflag FLAG_VISITED_GOLDENROD_CITY
	call_if_set FLAG_WHITEOUT_TO_LAVARIDGE, LavaridgeTown_EventScript_ClearLavaridgeWhiteOut
	call_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, LavaridgeTown_EventScript_ShowMtChimneyTrainers
	call Common_EventScript_SetupRivalGfxId
	call Common_EventScript_SetupRivalOnBikeGfxId
	call_if_eq VAR_GARBAGEVAR, 1, LavaridgeTown_EventScript_CheckSetRivalPos
	call_if_eq VAR_GARBAGEVAR, 1, LavaridgeTown_EventScript_HideMapNamePopup
	end

LavaridgeTown_EventScript_ClearLavaridgeWhiteOut::
	clearflag FLAG_WHITEOUT_TO_LAVARIDGE
	return

LavaridgeTown_EventScript_CheckSetRivalPos::
	getplayerxy VAR_0x8004, VAR_0x8005
	goto_if_eq VAR_0x8004, 9, LavaridgeTown_EventScript_SetRivalPos
	return

LavaridgeTown_EventScript_SetRivalPos::
	setobjectxyperm LOCALID_RIVAL, 11, 9
	setobjectxyperm LOCALID_RIVAL_ON_BIKE, 9, 8
	setobjectmovementtype LOCALID_RIVAL_ON_BIKE, MOVEMENT_TYPE_FACE_UP
	clearflag FLAG_GARBAGEFLAG
	return

LavaridgeTown_EventScript_ShowMtChimneyTrainers::
	clearflag FLAG_GARBAGEFLAG
	return

LavaridgeTown_EventScript_HideMapNamePopup::
	setflag FLAG_HIDE_MAP_NAME_POPUP
	return

LavaridgeTown_OnFrame:
	map_script_2 VAR_GARBAGEVAR, 1, LavaridgeTown_EventScript_RivalGiveGoGoggles
	.2byte 0

LavaridgeTown_EventScript_RivalGiveGoGoggles::
	lockall
	getplayerxy VAR_0x8008, VAR_0x8009
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalNoticePlayer
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExitHerbShop
	delay 20
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LavaridgeTown_EventScript_PlayMayMusic
	call_if_eq VAR_RESULT, FEMALE, LavaridgeTown_EventScript_PlayBrendanMusic
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalApproachPlayer1
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalApproachPlayer2
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LavaridgeTown_EventScript_MayGiveGoGoggles
	goto_if_eq VAR_RESULT, FEMALE, LavaridgeTown_EventScript_BrendanGiveGoGoggles
	end

LavaridgeTown_EventScript_MayGiveGoGoggles::
	msgbox LavaridgeTown_Text_MayNiceBadgesTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_GO_GOGGLES
	setflag FLAG_RECEIVED_GO_GOGGLES
	goto_if_unset FLAG_MINTS_ENABLED, LavaridgeTown_EventScript_MayGiveGoGogglesNoMints
	msgbox LavaridgeTown_Text_MayExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
	goto LavaridgeTown_EventScript_RivalExit
	end

LavaridgeTown_EventScript_MayGiveGoGogglesNoMints::
	msgbox LavaridgeTown_Text_MayExplainGoGogglesChallengeDadNoMints, MSGBOX_DEFAULT
	goto LavaridgeTown_EventScript_RivalExit
	end

LavaridgeTown_EventScript_BrendanGiveGoGoggles::
	msgbox LavaridgeTown_Text_BrendanNiceBadgesTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_GO_GOGGLES
	setflag FLAG_RECEIVED_GO_GOGGLES
	msgbox LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad, MSGBOX_DEFAULT
	goto LavaridgeTown_EventScript_RivalExit
	end

LavaridgeTown_EventScript_RivalExit::
	closemessage
	removeobject LOCALID_RIVAL
	addobject LOCALID_RIVAL_ON_BIKE
	delay 30
	call_if_eq VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExit1
	call_if_ne VAR_0x8008, 9, LavaridgeTown_EventScript_RivalExit2
	removeobject LOCALID_RIVAL_ON_BIKE
	setvar VAR_GARBAGEVAR, 2
	clearflag FLAG_HIDE_MAP_NAME_POPUP
	savebgm MUS_DUMMY
	fadedefaultbgm
	releaseall
	end

LavaridgeTown_EventScript_PlayMayMusic::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	return

LavaridgeTown_EventScript_PlayBrendanMusic::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	return

LavaridgeTown_EventScript_RivalNoticePlayer::
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExitHerbShop::
	opendoor 12, 15
	waitdooranim
	addobject LOCALID_RIVAL
	applymovement LOCALID_RIVAL, LavaridgeTown_Movement_RivalExitHerbShop
	waitmovement 0
	closedoor 12, 15
	waitdooranim
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalApproachPlayer1::
	applymovement LOCALID_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer1
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalApproachPlayer2::
	applymovement LOCALID_RIVAL, LavaridgeTown_Movement_RivalApproachPlayer2
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExit1::
	applymovement OBJ_EVENT_ID_PLAYER, LavaridgeTown_Movement_PlayerWatchRivalExit
	applymovement LOCALID_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit1
	waitmovement 0
	return

LavaridgeTown_EventScript_RivalExit2::
	applymovement LOCALID_RIVAL_ON_BIKE, LavaridgeTown_Movement_RivalExit2
	waitmovement 0
	return

LavaridgeTown_Movement_RivalExit2:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

LavaridgeTown_Movement_PlayerWatchRivalExit:
	delay_16
	delay_8
	walk_in_place_faster_right
	step_end

LavaridgeTown_Movement_RivalExit1:
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

LavaridgeTown_Movement_RivalApproachPlayer2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

LavaridgeTown_Movement_RivalApproachPlayer1:
	walk_left
	walk_left
	walk_up
	step_end

LavaridgeTown_Movement_RivalExitHerbShop:
	walk_down
	step_end

LavaridgeTown_EventScript_HotSpringsTrigger::
	specialvar VAR_RESULT, GetPlayerFacingDirection
	goto_if_eq VAR_RESULT, DIR_SOUTH, LavaridgeTown_EventScript_EnteredHotSprings
	end

LavaridgeTown_EventScript_EnteredHotSprings::
	incrementgamestat GAME_STAT_ENTERED_HOT_SPRINGS
	end

LavaridgeTown_EventScript_ExpertM::
	msgbox LavaridgeTown_Text_HotSpringsNeverRunDry, MSGBOX_NPC
	end

LavaridgeTown_EventScript_OldMan::
	msgbox LavaridgeTown_Text_PokemonNippedBackside, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_Twin::
	msgbox LavaridgeTown_Text_BatheInHotSpringsEveryDay, MSGBOX_NPC
	end

LavaridgeTown_EventScript_HotSpringsOldWoman1::
	msgbox LavaridgeTown_Text_IfPokemonInHotSprings, MSGBOX_NPC
	end

LavaridgeTown_EventScript_HotSpringsOldWoman2::
	msgbox LavaridgeTown_Text_HotSpringsClaims, MSGBOX_NPC
	end

LavaridgeTown_EventScript_ExpertF::
	msgbox LavaridgeTown_Text_OhYouLikeHotSprings, MSGBOX_NPC
	end

LavaridgeTown_EventScript_EggWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_LAVARIDGE_EGG, LavaridgeTown_EventScript_ReceivedEgg
	msgbox LavaridgeTown_Text_HaveEggWillYouTakeIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LavaridgeTown_EventScript_DeclineEgg
	getpartysize
	goto_if_eq VAR_RESULT, PARTY_SIZE, LavaridgeTown_EventScript_NoRoomForEgg
	msgbox LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_LAVARIDGE_EGG
	playfanfare MUS_OBTAIN_ITEM
	message LavaridgeTown_Text_ReceivedTheEgg
	waitfanfare
	giveegg SPECIES_WYNAUT
	release
	end

LavaridgeTown_EventScript_ReceivedEgg::
	msgbox LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_NoRoomForEgg::
	msgbox LavaridgeTown_Text_NoRoomForThisEgg, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_DeclineEgg::
	msgbox LavaridgeTown_Text_AsYouWishThen, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_EventScript_TownSign::
	msgbox LavaridgeTown_Text_TownSign, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_GymSign::
	msgbox LavaridgeTown_Text_GymSign, MSGBOX_SIGN
	end

LavaridgeTown_EventScript_HerbShopSign::
	msgbox LavaridgeTown_Text_HerbShopSign, MSGBOX_SIGN
	end

LavaridgeTown_Text_MayNiceBadgesTakeThis:
	.string "FLORA : {PLAYER}{KUN} ! Ça fait un\p"
	.string "bail ! Oh ? Pendant que je\n"
	.string "visitais les sources chaudes, tu as obtenu\p"
	.string "le BADGE d'ARÈNE de VERMILAVA. Tu\n"
	.string "as dû attraper de bons POKéMON…\l"
	.string "Non, je crois que tu les\p"
	.string "as bien élevés. Je suppose que\n"
	.string "ça irait que tu aies ça.$"

LavaridgeTown_Text_MayExplainGoGogglesChallengeDad:
	.string "Dis, hé, {PLAYER} !\n"
	.string "Je t'ai retrouvé aujourd'hui !\l"
	.string "Que devrais-je faire ? Demander ton conseil ?\p"
	.string "Pourquoi pas ? Je te parle déjà !\n"
	.string "{KUN}, tu en as marre de moi ?\p"
	.string "Nah, pas possible.\n"
	.string "Tu m'écoutes ?\p"
	.string "Je cherche un conseil--c'est de ça\n"
	.string "qu'il s'agit.\p"
	.string "C'est à propos d'un objet à tenir pour\n"
	.string "mon {PLAYER} qui serait bien.\p"
	.string "Mon indécision me rend mélancolique.{KUN}$"

LavaridgeTown_Text_BrendanNiceBadgesTakeThis:
	.string "BRICE : {PLAYER}, salut, ça fait un moment.\n"
	.string "Comment ça va ?\p"
	.string "Hmm…\n"
	.string "C'est une belle collection de BADGES.\p"
	.string "Bon, alors.\n"
	.string "Tu pourrais bien prendre ceci.$"

LavaridgeTown_Text_BrendanExplainGoGogglesChallengeDad:
	.string "BRENDAN : Garde-les avec toi si tu comptes\n"
	.string "aller dans ce désert près de la\l"
	.string "ROUTE 111.\p"
	.string "Il devrait y avoir des POKéMON qui\n"
	.string "vivent exclusivement dans le désert.\l"
	.string "Tu pourrais les chercher.\p"
	.string "Pour moi…\n"
	.string "Je songe à défier NORMAN,\l"
	.string "le CHAMPION d'ARÈNE de POIVRESSE.\p"
	.string "Contrairement à toi, {PLAYER}, ton père a l'air\n"
	.string "vraiment costaud.\p"
	.string "Oh, et va voir les HERBES\n"
	.string "NATURE au FLEURISTE !\p"
	.string "À plus !$"

LavaridgeTown_Text_MayExplainGoGogglesChallengeDadNoMints:
	.string "FLORA : Avec\n"
	.string "ces LUNET.\l"
	.string "SABLE, tu\p"
	.string "n'auras aucun\n"
	.string "problème à traverser le\p"
	.string "désert près de\n"
	.string "la ROUTE 111.\p"
	.string "Bonne chance,\n"
	.string "{PLAYER}{KUN} !{PLAYER}{KUN}$"

LavaridgeTown_Text_HaveEggWillYouTakeIt:
	.string "I have here an EGG.\p"
	.string "I'd hoped to hatch it by covering it in\n"
	.string "hot sand by the hot springs.\l"
	.string "But that doesn't seem to be enough…\p"
	.string "I've heard it would be best if it were\n"
	.string "kept together with POKéMON and\l"
	.string "carried about.\p"
	.string "You are a TRAINER, yes?\n"
	.string "And your POKéMON radiate vitality.\p"
	.string "So, what say you?\n"
	.string "Will you take this EGG to hatch?$"

LavaridgeTown_Text_HopeYoullWalkPlentyWithEgg:
	.string "Bien ! J'espère que tu marcheras beaucoup\n"
	.string "avec cet OEUF !$"

LavaridgeTown_Text_ReceivedTheEgg:
	.string "{PLAYER} a reçu l'OEUF.$"

LavaridgeTown_Text_NoRoomForThisEgg:
	.string "Oh ? Tu as trop de POKéMON.\n"
	.string "Il n'y a pas de place pour cet OEUF…$"

LavaridgeTown_Text_AsYouWishThen:
	.string "Comme tu veux, alors…\p"
	.string "Si tu changes d'avis sur l'éclosion de cet\n"
	.string "OEUF, je serai ici.$"

LavaridgeTown_Text_EverySoOftenEggFoundAtDayCare:
	.string "De temps en temps, on trouve un OEUF\n"
	.string "à la PENSION POKéMON.\p"
	.string "Du moins, c'est ce que raconte la rumeur.$"

LavaridgeTown_Text_HotSpringsNeverRunDry:
	.string "On puise autant d'eau chaude qu'on a\n"
	.string "besoin, et pourtant les sources chaudes ne\p"
	.string "tarissent jamais. Ce n'est pas magique\p"
	.string "? Ces sources chaudes apparaissent près\n"
	.string "de volcans actifs. Des veines d'eau\l"
	.string "sous terre sont chauffées par la\l"
	.string "magma et jaillissent en sources chaudes.$"

LavaridgeTown_Text_PokemonNippedBackside:
	.string "Être enterré dans ce sable\n"
	.string "chaud, c'est… Soupir… Si chaud\p"
	.string "et divin… Hein ? Gyaah\p"
	.string "! Aïe ! Un POKéMON\p"
	.string "m'a mordu les fesses !$"

LavaridgeTown_Text_OhYouLikeHotSprings:
	.string "Oh, tu aimes les sources chaudes ?\p"
	.string "C'est surprenant pour quelqu'un d'aussi jeune\n"
	.string "que toi.$"

LavaridgeTown_Text_BatheInHotSpringsEveryDay:
	.string "Je prends un bain de source chaude tous les jours.\p"
	.string "Je veux devenir une belle et forte\n"
	.string "CHAMPIONNE D'ARÈNE comme FLORA.$"

LavaridgeTown_Text_IfPokemonInHotSprings:
	.string "Si les gens mettaient des POKéMON dans des sources chaudes,\n"
	.string "ce serait vraiment bizarre.\p"
	.string "Ça pourrait être un bain électrique, ou\n"
	.string "un bain moussant, ou même un bain de lave…$"

LavaridgeTown_Text_HotSpringsClaims:
	.string "On prétend que ces sources chaudes\n"
	.string "sont bonnes pour calmer la tension nerveuse,\l"
	.string "soulager les muscles endoloris, résoudre\l"
	.string "les problèmes amoureux et attirer\l"
	.string "l'argent…$"

LavaridgeTown_Text_TownSign:
	.string "LAVARIDGE\p"
	.string "“Sources chaudes du CENTRE POKéMON\n"
	.string "Un excellent endroit pour se détendre !”$"

LavaridgeTown_Text_GymSign:
	.string "ARÈNE POKéMON DE LAVARIDGE\n"
	.string "CHAMPIONNE : FLORA\l"
	.string "“Une passion ardente qui brûle !”$"

LavaridgeTown_Text_HerbShopSign:
	.string "BOUTIQUE D'HERBES POKéMON\n"
	.string "“Amer mais efficace !”$"

