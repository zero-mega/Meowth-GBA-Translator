Route113_GlassWorkshop_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route113_GlassWorkshop_OnTransition
	.byte 0

	.set BLUE_FLUTE_PRICE,   250
	.set YELLOW_FLUTE_PRICE, 500
	.set RED_FLUTE_PRICE,    500
	.set WHITE_FLUTE_PRICE,  1000
	.set BLACK_FLUTE_PRICE,  1000
	.set PRETTY_CHAIR_PRICE, 6000
	.set PRETTY_DESK_PRICE,  8000
	.set LOWEST_ASH_PRICE,   BLUE_FLUTE_PRICE

Route113_GlassWorkshop_OnTransition:
	setflag FLAG_LANDMARK_GLASS_WORKSHOP
	call_if_eq VAR_GLASS_WORKSHOP_STATE, 1, Route113_GlassWorkshop_EventScript_ReenterWorkshopAfterSootSack
	end

Route113_GlassWorkshop_EventScript_ReenterWorkshopAfterSootSack::
	setvar VAR_GLASS_WORKSHOP_STATE, 2
	return

Route113_GlassWorkshop_EventScript_GlassWorker::
	lock
	faceplayer
	goto_if_ge VAR_GLASS_WORKSHOP_STATE, 10, Route113_GlassWorkshop_EventScript_GiveItemAfterNoRoom
	goto_if_eq VAR_GLASS_WORKSHOP_STATE, 2, Route113_GlassWorkshop_EventScript_CheckCollectedAsh
	goto_if_eq VAR_GLASS_WORKSHOP_STATE, 1, Route113_GlassWorkshop_EventScript_ExplainSootSack
	msgbox Route113_GlassWorkshop_Text_GoCollectAshWithThis, MSGBOX_DEFAULT
	giveitem ITEM_SOOT_SACK
	setvar VAR_GLASS_WORKSHOP_STATE, 1
	msgbox Route113_GlassWorkshop_Text_ExplainSootSack, MSGBOX_DEFAULT
	release
	end

Route113_GlassWorkshop_EventScript_ExplainSootSack::
	msgbox Route113_GlassWorkshop_Text_ExplainSootSack, MSGBOX_DEFAULT
	release
	end

Route113_GlassWorkshop_EventScript_CheckCollectedAsh::
	checkitem ITEM_SOOT_SACK
	goto_if_eq VAR_RESULT, FALSE, Route113_GlassWorkshop_EventScript_SootSackNotInBag
	msgbox Route113_GlassWorkshop_Text_LetsSeeCollectedAshes, MSGBOX_DEFAULT
	goto_if_lt VAR_ASH_GATHER_COUNT, LOWEST_ASH_PRICE, Route113_GlassWorkshop_EventScript_NotEnoughAsh
	message Route113_GlassWorkshop_Text_WhichGlassItemWoudYouLike
	waitmessage
	goto Route113_GlassWorkshop_EventScript_ChooseGlassItem
	end

Route113_GlassWorkshop_EventScript_SootSackNotInBag::
	msgbox Route113_GlassWorkshop_Text_HaventGotYourSootSack, MSGBOX_DEFAULT
	release
	end

Route113_GlassWorkshop_EventScript_ChooseGlassItem::
	setvar VAR_0x8009, 0
	setvar VAR_0x8004, SCROLL_MULTI_GLASS_WORKSHOP_VENDOR
	special ShowScrollableMultichoice
	waitstate
	switch VAR_RESULT
	case 0, Route113_GlassWorkshop_EventScript_BlueFlute
	case 1, Route113_GlassWorkshop_EventScript_YellowFlute
	case 2, Route113_GlassWorkshop_EventScript_RedFlute
	case 3, Route113_GlassWorkshop_EventScript_WhiteFlute
	case 4, Route113_GlassWorkshop_EventScript_BlackFlute
	case 5, Route113_GlassWorkshop_EventScript_PrettyChair
	case 6, Route113_GlassWorkshop_EventScript_PrettyDesk
	case 7, Route113_GlassWorkshop_EventScript_CancelGlassItemSelect
	case MULTI_B_PRESSED, Route113_GlassWorkshop_EventScript_CancelGlassItemSelect
	end

Route113_GlassWorkshop_EventScript_BlueFlute::
	setvar VAR_0x8008, ITEM_BLUE_FLUTE
	bufferitemname STR_VAR_1, VAR_0x8008
	setvar VAR_0x800A, BLUE_FLUTE_PRICE
	goto_if_lt VAR_ASH_GATHER_COUNT, BLUE_FLUTE_PRICE, Route113_GlassWorkshop_EventScript_NotEnoughAshForItem
	msgbox Route113_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route113_GlassWorkshop_EventScript_ChooseDifferentItem
	setvar VAR_GLASS_WORKSHOP_STATE, 10
	subvar VAR_ASH_GATHER_COUNT, BLUE_FLUTE_PRICE
	goto Route113_GlassWorkshop_EventScript_MakeGlassItem
	end

Route113_GlassWorkshop_EventScript_YellowFlute::
	setvar VAR_0x8008, ITEM_YELLOW_FLUTE
	bufferitemname STR_VAR_1, VAR_0x8008
	setvar VAR_0x800A, YELLOW_FLUTE_PRICE
	goto_if_lt VAR_ASH_GATHER_COUNT, YELLOW_FLUTE_PRICE, Route113_GlassWorkshop_EventScript_NotEnoughAshForItem
	msgbox Route113_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route113_GlassWorkshop_EventScript_ChooseDifferentItem
	setvar VAR_GLASS_WORKSHOP_STATE, 11
	subvar VAR_ASH_GATHER_COUNT, YELLOW_FLUTE_PRICE
	goto Route113_GlassWorkshop_EventScript_MakeGlassItem
	end

Route113_GlassWorkshop_EventScript_RedFlute::
	setvar VAR_0x8008, ITEM_RED_FLUTE
	bufferitemname STR_VAR_1, VAR_0x8008
	setvar VAR_0x800A, RED_FLUTE_PRICE
	goto_if_lt VAR_ASH_GATHER_COUNT, RED_FLUTE_PRICE, Route113_GlassWorkshop_EventScript_NotEnoughAshForItem
	msgbox Route113_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route113_GlassWorkshop_EventScript_ChooseDifferentItem
	setvar VAR_GLASS_WORKSHOP_STATE, 12
	subvar VAR_ASH_GATHER_COUNT, RED_FLUTE_PRICE
	goto Route113_GlassWorkshop_EventScript_MakeGlassItem
	end

Route113_GlassWorkshop_EventScript_WhiteFlute::
	setvar VAR_0x8008, ITEM_WHITE_FLUTE
	bufferitemname STR_VAR_1, VAR_0x8008
	setvar VAR_0x800A, WHITE_FLUTE_PRICE
	goto_if_lt VAR_ASH_GATHER_COUNT, WHITE_FLUTE_PRICE, Route113_GlassWorkshop_EventScript_NotEnoughAshForItem
	msgbox Route113_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route113_GlassWorkshop_EventScript_ChooseDifferentItem
	setvar VAR_GLASS_WORKSHOP_STATE, 13
	subvar VAR_ASH_GATHER_COUNT, WHITE_FLUTE_PRICE
	goto Route113_GlassWorkshop_EventScript_MakeGlassItem
	end

Route113_GlassWorkshop_EventScript_BlackFlute::
	setvar VAR_0x8008, ITEM_BLACK_FLUTE
	bufferitemname STR_VAR_1, VAR_0x8008
	setvar VAR_0x800A, BLACK_FLUTE_PRICE
	goto_if_lt VAR_ASH_GATHER_COUNT, BLACK_FLUTE_PRICE, Route113_GlassWorkshop_EventScript_NotEnoughAshForItem
	msgbox Route113_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route113_GlassWorkshop_EventScript_ChooseDifferentItem
	setvar VAR_GLASS_WORKSHOP_STATE, 14
	subvar VAR_ASH_GATHER_COUNT, BLACK_FLUTE_PRICE
	goto Route113_GlassWorkshop_EventScript_MakeGlassItem
	end

Route113_GlassWorkshop_EventScript_PrettyChair::
	setvar VAR_0x8009, 1
	setvar VAR_0x8008, DECOR_PRETTY_CHAIR
	bufferdecorationname STR_VAR_1, VAR_0x8008
	setvar VAR_0x800A, PRETTY_CHAIR_PRICE
	goto_if_lt VAR_ASH_GATHER_COUNT, PRETTY_CHAIR_PRICE, Route113_GlassWorkshop_EventScript_NotEnoughAshForItem
	msgbox Route113_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route113_GlassWorkshop_EventScript_ChooseDifferentItem
	setvar VAR_GLASS_WORKSHOP_STATE, 15
	subvar VAR_ASH_GATHER_COUNT, PRETTY_CHAIR_PRICE
	goto Route113_GlassWorkshop_EventScript_MakeGlassItem
	end

Route113_GlassWorkshop_EventScript_PrettyDesk::
	setvar VAR_0x8009, 1
	setvar VAR_0x8008, DECOR_PRETTY_DESK
	bufferdecorationname STR_VAR_1, VAR_0x8008
	setvar VAR_0x800A, PRETTY_DESK_PRICE
	goto_if_lt VAR_ASH_GATHER_COUNT, PRETTY_DESK_PRICE, Route113_GlassWorkshop_EventScript_NotEnoughAshForItem
	msgbox Route113_GlassWorkshop_Text_IsThatTheItemForYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route113_GlassWorkshop_EventScript_ChooseDifferentItem
	setvar VAR_GLASS_WORKSHOP_STATE, 16
	subvar VAR_ASH_GATHER_COUNT, PRETTY_DESK_PRICE
	goto Route113_GlassWorkshop_EventScript_MakeGlassItem
	end

Route113_GlassWorkshop_EventScript_CancelGlassItemSelect::
	msgbox Route113_GlassWorkshop_Text_AllThatAshButDontWantAnything, MSGBOX_DEFAULT
	release
	end

Route113_GlassWorkshop_EventScript_NotEnoughAsh::
	setvar VAR_0x800A, LOWEST_ASH_PRICE
	subvar VAR_0x800A, VAR_ASH_GATHER_COUNT
	buffernumberstring STR_VAR_1, VAR_0x800A
	msgbox Route113_GlassWorkshop_Text_NotEnoughAshNeedX, MSGBOX_DEFAULT
	release
	end

Route113_GlassWorkshop_EventScript_NotEnoughAshForItem::
	subvar VAR_0x800A, VAR_ASH_GATHER_COUNT
	buffernumberstring STR_VAR_2, VAR_0x800A
	message Route113_GlassWorkshop_Text_NotEnoughAshToMakeItem
	waitmessage
	goto Route113_GlassWorkshop_EventScript_ChooseGlassItem
	end

Route113_GlassWorkshop_EventScript_ChooseDifferentItem::
	message Route113_GlassWorkshop_Text_WhichWouldYouLike
	waitmessage
	goto Route113_GlassWorkshop_EventScript_ChooseGlassItem
	end

Route113_GlassWorkshop_EventScript_MakeGlassItem::
	msgbox Route113_GlassWorkshop_Text_IllMakeItemForYou, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	playse SE_SELECT
	delay 30
	fadescreen FADE_FROM_BLACK
	msgbox Route113_GlassWorkshop_Text_IveFinishedGlassItem, MSGBOX_DEFAULT
	call_if_eq VAR_0x8009, 0, Route113_GlassWorkshop_EventScript_GiveGlassFlute
	call_if_eq VAR_0x8009, 1, Route113_GlassWorkshop_EventScript_GiveGlassDecor
	setvar VAR_GLASS_WORKSHOP_STATE, 2
	release
	end

Route113_GlassWorkshop_EventScript_GiveGlassFlute::
	giveitem VAR_0x8008
	goto_if_eq VAR_RESULT, FALSE, Route113_GlassWorkshop_EventScript_NoRoomForFlute
	return

Route113_GlassWorkshop_EventScript_GiveGlassDecor::
	givedecoration VAR_0x8008
	goto_if_eq VAR_RESULT, FALSE, Route113_GlassWorkshop_EventScript_NoRoomForDecor
	return

Route113_GlassWorkshop_EventScript_NoRoomForFlute::
	call Common_EventScript_BagIsFull
	msgbox Route113_GlassWorkshop_Text_NoRoomInBag, MSGBOX_DEFAULT
	release
	end

Route113_GlassWorkshop_EventScript_NoRoomForDecor::
	call Common_EventScript_NoRoomForDecor
	msgbox Route113_GlassWorkshop_Text_NoRoomInPC, MSGBOX_DEFAULT
	release
	end

Route113_GlassWorkshop_EventScript_GiveItemAfterNoRoom::
	switch VAR_GLASS_WORKSHOP_STATE
	case 10, Route113_GlassWorkshop_EventScript_GiveBlueFlute
	case 11, Route113_GlassWorkshop_EventScript_GiveYellowFlute
	case 12, Route113_GlassWorkshop_EventScript_GiveRedFlute
	case 13, Route113_GlassWorkshop_EventScript_GiveWhiteFlute
	case 14, Route113_GlassWorkshop_EventScript_GiveBlackFlute
	case 15, Route113_GlassWorkshop_EventScript_GivePrettyChair
	case 16, Route113_GlassWorkshop_EventScript_GivePrettyDesk
	end

Route113_GlassWorkshop_EventScript_GiveBlueFlute::
	setvar VAR_0x8009, 0
	setvar VAR_0x8008, ITEM_BLUE_FLUTE
	bufferitemname STR_VAR_1, VAR_0x8008
	goto Route113_GlassWorkshop_EventScript_TryGiveItemAgain
	end

Route113_GlassWorkshop_EventScript_GiveYellowFlute::
	setvar VAR_0x8009, 0
	setvar VAR_0x8008, ITEM_YELLOW_FLUTE
	bufferitemname STR_VAR_1, VAR_0x8008
	goto Route113_GlassWorkshop_EventScript_TryGiveItemAgain
	end

Route113_GlassWorkshop_EventScript_GiveRedFlute::
	setvar VAR_0x8009, 0
	setvar VAR_0x8008, ITEM_RED_FLUTE
	bufferitemname STR_VAR_1, VAR_0x8008
	goto Route113_GlassWorkshop_EventScript_TryGiveItemAgain
	end

Route113_GlassWorkshop_EventScript_GiveWhiteFlute::
	setvar VAR_0x8009, 0
	setvar VAR_0x8008, ITEM_WHITE_FLUTE
	bufferitemname STR_VAR_1, VAR_0x8008
	goto Route113_GlassWorkshop_EventScript_TryGiveItemAgain
	end

Route113_GlassWorkshop_EventScript_GiveBlackFlute::
	setvar VAR_0x8009, 0
	setvar VAR_0x8008, ITEM_BLACK_FLUTE
	bufferitemname STR_VAR_1, VAR_0x8008
	goto Route113_GlassWorkshop_EventScript_TryGiveItemAgain
	end

Route113_GlassWorkshop_EventScript_GivePrettyChair::
	setvar VAR_0x8009, 1
	setvar VAR_0x8008, DECOR_PRETTY_CHAIR
	bufferdecorationname STR_VAR_1, DECOR_PRETTY_CHAIR
	goto Route113_GlassWorkshop_EventScript_TryGiveItemAgain
	end

Route113_GlassWorkshop_EventScript_GivePrettyDesk::
	setvar VAR_0x8009, 1
	setvar VAR_0x8008, DECOR_PRETTY_DESK
	bufferdecorationname STR_VAR_1, DECOR_PRETTY_DESK
	goto Route113_GlassWorkshop_EventScript_TryGiveItemAgain
	end

Route113_GlassWorkshop_EventScript_TryGiveItemAgain::
	msgbox Route113_GlassWorkshop_Text_IveFinishedGlassItem, MSGBOX_DEFAULT
	call_if_eq VAR_0x8009, 0, Route113_GlassWorkshop_EventScript_GiveGlassFlute
	call_if_eq VAR_0x8009, 1, Route113_GlassWorkshop_EventScript_GiveGlassDecor
	setvar VAR_GLASS_WORKSHOP_STATE, 2
	release
	end

Route113_GlassWorkshop_EventScript_NinjaBoy::
	msgbox Route113_GlassWorkshop_Text_FunToBlowGlassFlute, MSGBOX_NPC
	end

Route113_GlassWorkshop_Text_GoCollectAshWithThis:
	.string "Cette zone est couverte de cendres volcaniques,\n"
	.string "huff-puff !\p"
	.string "J'ai un don spécial, huff-puff.\p"
	.string "Je fabrique du verre avec les cendres volcaniques\n"
	.string "et je crée des objets, huff-puff.\p"
	.string "Va collecter des cendres avec ça, huff-puff.$"

Route113_GlassWorkshop_Text_ExplainSootSack:
	.string "Prends ce SAC À CENDRES et marche\n"
	.string "dans des tas de cendres, pouf-pouf.\p"
	.string "Et il se remplira de cendres\n"
	.string "volcaniques, pouf-pouf.\p"
	.string "Tu peux vérifier la quantité\n"
	.string "dans ton SAC.\p"
	.string "Une fois que tu en as accumulé\n"
	.string "une bonne quantité, viens me voir, pouf-pouf.$"

Route113_GlassWorkshop_Text_LetsSeeCollectedAshes:
	.string "Tu as collecté des cendres, huff-puff ?\n"
	.string "Laisse-moi voir, huff-puff.$"

Route113_GlassWorkshop_Text_NotEnoughAshNeedX:
	.string "Hmmm…\n"
	.string "There's not enough ash here, huff-puff.\l"
	.string "I can't make glass with this, huff-puff.\p"
	.string "Let's see… {STR_VAR_1} is the number of steps\n"
	.string "you'll need to walk for me to make you\l"
	.string "a BLUE FLUTE, huff-puff.$"

Route113_GlassWorkshop_Text_WhichGlassItemWoudYouLike:
	.string "Oh ! Tu as beaucoup de\n"
	.string "cendres, huff-huff ! Je vais te\p"
	.string "faire un objet en verre, huff-huff\n"
	.string "! Lequel veux-tu, huff-huff ?$"

Route113_GlassWorkshop_Text_IsThatTheItemForYou:
	.string "Un {STR_VAR_1}, huff-puff ?\n"
	.string "C'est celui qu'il te faut, huff-puff ?$"

Route113_GlassWorkshop_Text_WhichWouldYouLike:
	.string "Lequel préfères-tu, huff-puff ?$"

Route113_GlassWorkshop_Text_IllMakeItemForYou:
	.string "Un {STR_VAR_1}, c'est ça, huff-huff !\p"
	.string "OK ! Je vais te le\n"
	.string "faire, huff-huff. Attends un peu, huff-huff.$"

Route113_GlassWorkshop_Text_NotEnoughAshToMakeItem:
	.string "Un {STR_VAR_1},\p"
	.string "huff-puff ?\n"
	.string "Il n'y a pas assez de\p"
	.string "cendres ici pour faire\n"
	.string "ça, pourtant, huff-puff.\l"
	.string "Voyons…\p"
	.string "Reviens quand il y\n"
	.string "aura plus de cendres !{STR_VAR_2}$"

Route113_GlassWorkshop_Text_AllThatAshButDontWantAnything:
	.string "Tu as collecté toute cette cendre, mais tu\n"
	.string "ne veux rien, huff-puff ?$"

Route113_GlassWorkshop_Text_IveFinishedGlassItem:
	.string "Ah, j'ai fini ton {STR_VAR_1}.\n"
	.string "Prends-le, huff-huff.$"

Route113_GlassWorkshop_Text_NoRoomInBag:
	.string "Oh ?\n"
	.string "Tu n'as plus de place dans ton SAC, huff huff.\p"
	.string "Je vais le garder, alors reviens plus tard,\n"
	.string "huff huff.$"

Route113_GlassWorkshop_Text_NoRoomInPC:
	.string "Oh ?\n"
	.string "Tu n'as plus de place dans ton PC, huff huff ?\p"
	.string "Je vais le garder, alors reviens plus tard,\n"
	.string "huff huff.$"

Route113_GlassWorkshop_Text_HaventGotYourSootSack:
	.string "Hein ? Tu n'as pas ton SAC À SUIE\n"
	.string "sur toi, huff-huff.\p"
	.string "Tu dois l'avoir sur toi pour\n"
	.string "ramasser la cendre volcanique, huff-huff.$"

Route113_GlassWorkshop_Text_FunToBlowGlassFlute:
	.string "C'est amusant de souffler dans une flûte de verre\n"
	.string "pendant que mon patron parle.\p"
	.string "Huff-huff ! Puff-puff !$"

