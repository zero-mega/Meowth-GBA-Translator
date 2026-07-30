AbandonedShip_CaptainsOffice_MapScripts::
	.byte 0

AbandonedShip_CaptainsOffice_EventScript_CaptSternAide::
	lock
	faceplayer
	goto_if_set FLAG_EXCHANGED_SCANNER, AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus
	checkitem ITEM_SCANNER
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_CaptainsOffice_EventScript_CanYouDeliverScanner
	goto_if_set FLAG_ITEM_GARBAGEFLAG, AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus
	msgbox AbandonedShip_CaptainsOffice_Text_NoSuccessFindingScanner, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_EventScript_CanYouDeliverScanner::
	msgbox AbandonedShip_CaptainsOffice_Text_OhCanYouDeliverScanner, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_EventScript_ThisIsSSCactus::
	msgbox AbandonedShip_CaptainsOffice_Text_ThisIsSSCactus, MSGBOX_DEFAULT
	release
	end

AbandonedShip_CaptainsOffice_Text_NoSuccessFindingScanner:
	.string "J'enquête sur ce navire pour le\n"
	.string "CAPT. LOUGE.\p"
	.string "Il m'a aussi demandé de trouver un\n"
	.string "SCANNER, mais sans succès pour l'instant…$"

AbandonedShip_CaptainsOffice_Text_OhCanYouDeliverScanner:
	.string "Oh ! C'est un SCANNER !\p"
	.string "Écoute, tu pourrais me le livrer\n"
	.string "au CAPT. STERN ?\p"
	.string "Je veux examiner ce navire un\n"
	.string "peu plus.$"

AbandonedShip_CaptainsOffice_Text_ThisIsSSCactus:
	.string "Ce navire s'appelle S.S. CACTUS.\n"
	.string "Il semble dater d'une époque révolue.$"

