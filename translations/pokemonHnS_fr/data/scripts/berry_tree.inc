BerryTreeScript::
	special ObjectEventInteractionGetBerryTreeData
	switch VAR_0x8004
	case BERRY_STAGE_SPARKLING, BerryTree_EventScript_NotDoneYet
	case BERRY_STAGE_NO_BERRY, BerryTree_EventScript_NotDoneYet
	case BERRY_STAGE_PLANTED, BerryTree_EventScript_NotDoneYet
	case BERRY_STAGE_SPROUTED, BerryTree_EventScript_NotDoneYet
	case BERRY_STAGE_TALLER, BerryTree_EventScript_NotDoneYet
	case BERRY_STAGE_FLOWERING, BerryTree_EventScript_NotDoneYet
	case BERRY_STAGE_BERRIES, BerryTree_EventScript_CheckBerryFullyGrown
	end

BerryTree_EventScript_NotDoneYet::
	lock
	message ApricornTree_Text_Growing
	waitmessage
	waitbuttonpress
	release
	end

BerryTree_EventScript_Sparkling::
	lockall
	message BerryTree_Text_ExclamationPoint
	waitmessage
	waitbuttonpress
	releaseall
	end

BerryTree_EventScript_CheckSoil::
	lock
	faceplayer
	specialvar VAR_RESULT, PlayerHasBerries
	goto_if_eq VAR_RESULT, TRUE, BerryTree_EventScript_ChooseBerryToPlant
	message BerryTree_Text_ItsSoftLoamySoil
	waitmessage
	waitbuttonpress
	release
	end

BerryTree_EventScript_ChooseBerryToPlant::
	message ApricornTree_Text_Growing
	waitmessage
	waitbuttonpress
	call BerryTree_EventScript_PlantBerry

BerryTree_EventScript_CancelPlanting::
	release
	end

BerryTree_EventScript_CheckBerryStage1::
	lockall
	special ObjectEventInteractionGetBerryCountString
	checkitem ITEM_SQUIRT_BOTTLE, 1
	compare VAR_RESULT, 0
	goto_if_eq BerryTree_EventScript_DontWater
	msgbox BerryTree_Text_BerryGrowthStage1, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq BerryTree_EventScript_WaterBerry
	compare VAR_RESULT, NO
	goto_if_eq BerryTree_EventScript_DontWater

BerryTree_EventScript_CheckBerryStage2::
	lockall
	special ObjectEventInteractionGetBerryName
	checkitem ITEM_SQUIRT_BOTTLE, 1
	compare VAR_RESULT, 0
	goto_if_eq BerryTree_EventScript_DontWater
	msgbox BerryTree_Text_BerryGrowthStage2, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq BerryTree_EventScript_WaterBerry
	compare VAR_RESULT, NO
	goto_if_eq BerryTree_EventScript_DontWater

BerryTree_EventScript_CheckBerryStage3::
	lockall
	special ObjectEventInteractionGetBerryName
	checkitem ITEM_SQUIRT_BOTTLE, 1
	compare VAR_RESULT, 0
	goto_if_eq BerryTree_EventScript_DontWater
	msgbox BerryTree_Text_BerryGrowthStage3, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq BerryTree_EventScript_WaterBerry
	compare VAR_RESULT, NO
	goto_if_eq BerryTree_EventScript_DontWater

BerryTree_EventScript_CheckBerryStage4::
	call BerryTree_EventScript_GetCareAdverb
	lockall
	checkitem ITEM_SQUIRT_BOTTLE, 1
	compare VAR_RESULT, 0
	goto_if_eq BerryTree_EventScript_DontWater
	msgbox BerryTree_Text_BerryGrowthStage4, MSGBOX_YESNO
	compare VAR_RESULT, YES
	goto_if_eq BerryTree_EventScript_WaterBerry
	compare VAR_RESULT, NO
	goto_if_eq BerryTree_EventScript_DontWater

@ VAR_0x8005 here is the number of times watered
@ Buffered by ObjectEventInteractionGetBerryTreeData
BerryTree_EventScript_GetCareAdverb::
	goto_if_eq VAR_0x8005, 0, BerryTree_EventScript_SetAdverbPoor
	goto_if_eq VAR_0x8005, 4, BerryTree_EventScript_SetAdverbGreat
	bufferstring STR_VAR_2, BerryTree_Text_CareAdverbGood
	return

BerryTree_EventScript_SetAdverbGreat::
	bufferstring STR_VAR_2, BerryTree_Text_CareAdverbGreat
	return

BerryTree_EventScript_SetAdverbPoor::
	bufferstring STR_VAR_2, BerryTree_Text_CareAdverbPoor
	return

@ VAR_0x8006 here is the number of berries
BerryTree_EventScript_CheckBerryFullyGrown::
	buffernumberstring STR_VAR_2, VAR_0x8006
	lock
	faceplayer
	goto BerryTree_EventScript_PickBerry

BerryTree_EventScript_PickBerry::
	special ObjectEventInteractionPickBerryTree
	goto_if_eq VAR_0x8004, 0, BerryTree_EventScript_BerryPocketFull
	special IncrementDailyPickedBerries
	special ObjectEventInteractionRemoveBerryTree
	message BerryTree_Text_PickedTheBerry
	playfanfare MUS_OBTAIN_BERRY

	@ added to crystal:
	special ObjectEventInteractionPlantBerryTree
	incrementgamestat GAME_STAT_PLANTED_BERRIES
	special IncrementDailyPlantedBerries


	waitmessage
	waitfanfare
	release
	end

BerryTree_EventScript_BerryPocketFull::
	message BerryTree_Text_BerryPocketFull
	waitmessage
	waitbuttonpress
	release
	end

BerryTree_EventScript_ItemUsePlantBerry::
	lockall
	special ObjectEventInteractionGetBerryTreeData
	call BerryTree_EventScript_PlantBerry
	releaseall
	end

BerryTree_EventScript_DontWater::
	releaseall
	end

BerryTree_EventScript_ItemUseWailmerPail::
	special ObjectEventInteractionGetBerryTreeData
	lockall
BerryTree_EventScript_WaterBerry::
	@ special ObjectEventInteractionWaterBerryTree
	@ special DoWateringBerryTreeAnim
	@ waitstate
	@ releaseall
	message ApricornTree_Text_Growing
	waitmessage
	waitbuttonpress
	end

BerryTree_EventScript_BerryTree::
	message BerryTree_Text_BerryTreeSprouted
	waitmessage
	callnative Berry_Ready
	waitbuttonpress
	release
	end

BerryTree_EventScript_PlantBerry::
	special ObjectEventInteractionPlantBerryTree
	incrementgamestat GAME_STAT_PLANTED_BERRIES
	special IncrementDailyPlantedBerries
	return

ApricornTree_Text_Growing:
	.string "C'est un arbre à BAIES !\n"
	.string "Ces BAIES ne sont pas encore mûres.$"

BerryTree_Text_ItsSoftLoamySoil:
	.string "C'est une terre meuble et fertile.$"

BerryTree_Text_BerryGrowthStage1:
	.string "Un {STR_VAR_1} a été planté ici.\n"
	.string "Veux-tu l'arroser avec le SEAU WAILMER ?$"

BerryTree_Text_BerryGrowthStage2:
	.string "{STR_VAR_1} a germé.\n"
	.string "Veux-tu l'arroser avec le SEAU WAILMER ?$"

BerryTree_Text_BerryGrowthStage3:
	.string "Cette plante {STR_VAR_1} pousse bien.\n"
	.string "Veux-tu l'arroser avec le SEAU WAILMER ?$"

BerryTree_Text_BerryGrowthStage4:
	.string "Ces fleurs {STR_VAR_1} sont en fleur\n"
	.string "{STR_VAR_2}. Veux-tu les arroser ?$"

BerryTree_Text_CareAdverbGreat:
	.string "très joliment$"

BerryTree_Text_CareAdverbPoor:
	.string "gentiment$"

BerryTree_Text_CareAdverbGood:
	.string "joliment$"

BerryTree_Text_PickedTheBerry:
	.string "{PLAYER} a cueilli {STR_VAR_2} {STR_VAR_1}.$"

BerryTree_Text_BerryPocketFull:
	.string "La POCHE BAIES du SAC est pleine.\p"
	.string "La {STR_VAR_1} n'a pas pu être prise.$"

BerryTree_Text_ExclamationPoint:
	.string "!$"

BerryTree_Text_BerryTreeSprouted:
	.string "L'arbre à BAIES a soudainement poussé !$"
