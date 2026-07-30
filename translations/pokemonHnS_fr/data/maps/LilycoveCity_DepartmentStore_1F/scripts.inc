.set LOCALID_LOTTERY_CLERK, 2

LilycoveCity_DepartmentStore_1F_MapScripts::
	.byte 0

LilycoveCity_DepartmentStore_1F_EventScript_Greeter::
	msgbox LilycoveCity_DepartmentStore_1F_Text_WelcomeToDeptStore, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_1F_EventScript_LotteryClerk::
	lock
	faceplayer
	dotimebasedevents
	goto_if_ne VAR_POKELOT_PRIZE_ITEM, ITEM_NONE, LilycoveCity_DepartmentStore_1F_EventScript_GivePrizeFromEarlier
	goto_if_set FLAG_DAILY_PICKED_LOTO_TICKET, LilycoveCity_DepartmentStore_1F_EventScript_ComeBackTomorrow
	msgbox LilycoveCity_DepartmentStore_1F_Text_LotteryCornerDrawTicket, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LilycoveCity_DepartmentStore_1F_EventScript_PleaseVisitAgain
	setflag FLAG_DAILY_PICKED_LOTO_TICKET
	message LilycoveCity_DepartmentStore_1F_Text_PleasePickTicket
	waitmessage
	special RetrieveLotteryNumber
	copyvar VAR_0x8008, VAR_RESULT
	special BufferLottoTicketNumber
	msgbox LilycoveCity_DepartmentStore_1F_Text_TicketNumberIsXPleaseWait, MSGBOX_DEFAULT
	applymovement 4, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	playse SE_PC_ON
	@special DoLotteryCornerComputerEffect
	special PickLotteryCornerTicket
	delay 220
	@special EndLotteryCornerComputerEffect
	delay 10
	applymovement 4, Common_Movement_FacePlayer
	waitmovement 0
	goto_if_eq VAR_0x8004, 0, LilycoveCity_DepartmentStore_1F_EventScript_NoMatch
	incrementgamestat GAME_STAT_WON_POKEMON_LOTTERY
	call_if_eq VAR_0x8006, 0, LilycoveCity_DepartmentStore_1F_EventScript_TicketMatchPartyMon
	call_if_eq VAR_0x8006, 1, LilycoveCity_DepartmentStore_1F_EventScript_TicketMatchPCMon
	bufferitemname STR_VAR_1, VAR_0x8005
	call_if_eq VAR_0x8004, 1, LilycoveCity_DepartmentStore_1F_EventScript_TwoDigitMatch
	call_if_eq VAR_0x8004, 2, LilycoveCity_DepartmentStore_1F_EventScript_ThreeDigitMatch
	call_if_eq VAR_0x8004, 3, LilycoveCity_DepartmentStore_1F_EventScript_FourDigitMatch
	call_if_eq VAR_0x8004, 4, LilycoveCity_DepartmentStore_1F_EventScript_FullMatch
	giveitem VAR_0x8005
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_DepartmentStore_1F_EventScript_RecordPrizeNoRoom
	special TryPutLotteryWinnerReportOnAir
	goto LilycoveCity_DepartmentStore_1F_EventScript_PleaseVisitAgain2
	end

LilycoveCity_DepartmentStore_1F_EventScript_TicketMatchPartyMon::
	msgbox LilycoveCity_DepartmentStore_1F_Text_TicketMatchesPartyMon, MSGBOX_DEFAULT
	return

LilycoveCity_DepartmentStore_1F_EventScript_TicketMatchPCMon::
	msgbox LilycoveCity_DepartmentStore_1F_Text_TicketMatchesPCMon, MSGBOX_DEFAULT
	return

LilycoveCity_DepartmentStore_1F_EventScript_ComeBackTomorrow::
	msgbox LilycoveCity_DepartmentStore_1F_Text_ComeBackTomorrow, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStore_1F_EventScript_PleaseVisitAgain::
	msgbox LilycoveCity_DepartmentStore_1F_Text_PleaseVisitAgain, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStore_1F_EventScript_NoMatch::
	msgbox LilycoveCity_DepartmentStore_1F_Text_NoNumbersMatched, MSGBOX_DEFAULT
	goto LilycoveCity_DepartmentStore_1F_EventScript_PleaseVisitAgain2
	end

LilycoveCity_DepartmentStore_1F_EventScript_PleaseVisitAgain2::
	msgbox LilycoveCity_DepartmentStore_1F_Text_PleaseVisitAgain2, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStore_1F_EventScript_TwoDigitMatch::
	msgbox LilycoveCity_DepartmentStore_1F_Text_TwoDigitsMatched, MSGBOX_DEFAULT
	return

LilycoveCity_DepartmentStore_1F_EventScript_ThreeDigitMatch::
	msgbox LilycoveCity_DepartmentStore_1F_Text_ThreeDigitsMatched, MSGBOX_DEFAULT
	return

LilycoveCity_DepartmentStore_1F_EventScript_FourDigitMatch::
	msgbox LilycoveCity_DepartmentStore_1F_Text_FourDigitsMatched, MSGBOX_DEFAULT
	return

LilycoveCity_DepartmentStore_1F_EventScript_FullMatch::
	msgbox LilycoveCity_DepartmentStore_1F_Text_AllFiveDigitsMatched, MSGBOX_DEFAULT
	return

LilycoveCity_DepartmentStore_1F_EventScript_RecordPrizeNoRoom::
	copyvar VAR_POKELOT_PRIZE_PLACE, VAR_0x8004
	copyvar VAR_POKELOT_PRIZE_ITEM, VAR_0x8005
	goto LilycoveCity_DepartmentStore_1F_EventScript_NoRoomForPrize
	end

LilycoveCity_DepartmentStore_1F_EventScript_NoRoomForPrize::
	msgbox LilycoveCity_DepartmentStore_1F_Text_NoRoomForThis, MSGBOX_DEFAULT
	release
	end

LilycoveCity_DepartmentStore_1F_EventScript_GivePrizeFromEarlier::
	msgbox LilycoveCity_DepartmentStore_1F_Text_PrizeWeveBeenHolding, MSGBOX_DEFAULT
	giveitem VAR_POKELOT_PRIZE_ITEM
	goto_if_eq VAR_RESULT, FALSE, LilycoveCity_DepartmentStore_1F_EventScript_NoRoomForPrize
	copyvar VAR_0x8004, VAR_POKELOT_PRIZE_PLACE
	copyvar VAR_0x8005, VAR_POKELOT_PRIZE_ITEM
	special TryPutLotteryWinnerReportOnAir
	setvar VAR_POKELOT_PRIZE_ITEM, ITEM_NONE
	setvar VAR_POKELOT_PRIZE_PLACE, 0
	release
	end

LilycoveCity_DepartmentStore_1F_EventScript_PokefanF::
	msgbox LilycoveCity_DepartmentStore_1F_Text_IBuyAllSortsOfThings, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_1F_EventScript_LittleGirl::
	msgbox LilycoveCity_DepartmentStore_1F_Text_MomBuyingMeFurniture, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_1F_EventScript_PokefanM::
	msgbox LilycoveCity_DepartmentStore_1F_Text_BuyingSomethingForAzumarill, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_1F_EventScript_Azumarill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, CRY_MODE_NORMAL
	msgbox LilycoveCity_DepartmentStore_1F_Text_Azumarill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

LilycoveCity_DepartmentStore_1F_EventScript_FloorNamesSign::
	msgbox LilycoveCity_DepartmentStore_1F_Text_FloorNamesSign, MSGBOX_SIGN
	end

LilycoveCity_DepartmentStore_1F_TraderWoman::
	msgbox LilycoveCity_DepartmentStore_1F_TraderWoman_Text, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_1F_Machine::
	playse SE_PC_ON
	delay 40
	checkmoney 10000, 0
	compare VAR_RESULT, TRUE
	goto_if_eq SCRIPT_SelfTrade_V1
	compare VAR_RESULT, FALSE
	goto_if_eq LilycoveCity_DepartmentStore_1F_Machine_NoMoney
	end

LilycoveCity_DepartmentStore_1F_Machine_NoMoney::
	msgbox LilycoveCity_DepartmentStore_1F_Machine_NoMoney_Text, MSGBOX_NPC
	end

SCRIPT_SelfTrade_V1::
	lock
	faceplayer
	msgbox SCRIPT_SelfTrade_Text_IllTradeIfYouWant, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SCRIPT_SelfTrade_DeclineTrade
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, 255
	goto_if_eq SCRIPT_SelfTrade_DeclineTrade
	copyvar VAR_0x8005, VAR_0x8004
	setvar VAR_0x8004, 6
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	removemoney 10000, 0
	msgbox SCRIPT_SelfTrade_Text_ComeBack, MSGBOX_DEFAULT
	release
	end

SCRIPT_SelfTrade_V2::
	lock
	faceplayer
	msgbox SCRIPT_SelfTrade_Text_IllTradeIfYouWant, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq SCRIPT_SelfTrade_DeclineTrade
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, 255
	goto_if_eq SCRIPT_SelfTrade_DeclineTrade
	copyvar VAR_0x8005, VAR_0x8004
	setvar VAR_0x8004, 7
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	setvar VAR_0x8004, 8
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	msgbox SCRIPT_SelfTrade_Text_ComeBack, MSGBOX_DEFAULT
	release
	end

SCRIPT_SelfTrade_DeclineTrade::
	msgbox SCRIPT_SelfTrade_Text_YouDontWantToThatsOkay, MSGBOX_DEFAULT
	release
	end

SCRIPT_SelfTrade_Text_IllTradeIfYouWant:
	.string "Bienvenue dans l'application AUTO-ÉCHANGE\n"
	.string "de DEVON CORPORATION.\p"
	.string "Un de tes POKéMON sera auto-échangé.\n"
	.string "Une opération coûte 10.000¥.\p"
	.string "Veux-tu continuer vers\n"
	.string "la sélection de POKéMON ?$"

SCRIPT_SelfTrade_Text_ComeBack:
	.string "Merci d'utiliser les produits\n"
	.string "DEVON S.A.R.L.$"

SCRIPT_SelfTrade_Text_YouDontWantToThatsOkay:
	.string "Merci d'utiliser les produits\n"
	.string "de DEVON S.A.R.L.$"

LilycoveCity_DepartmentStore_1F_Machine_NoMoney_Text:
	.string "Désolé, tu n'as pas assez\n"
	.string "d'argent. 10 000 ¥ sont\p"
	.string "requis pour une utilisation. Merci\n"
	.string "d'utiliser les produits DEVON SARL.$"

LilycoveCity_DepartmentStore_1F_TraderWoman_Text:
	.string "Bienvenue aux GRANDS MAGASINS de LILYCOVE !\p"
	.string "Veux-tu connaître la nouvelle\n"
	.string "technologie développée par DEVON S.A. ?\p"
	.string "C'est une appli AUTO-ÉCHANGEUR !\p"
	.string "Avec l'aide d'un simple programme\n"
	.string "informatique, tu peux envoyer un POKéMON sur\l"
	.string "un serveur DEVON S.A. et le récupérer\l"
	.string "en quelques secondes !\p"
	.string "Cela peut déclencher les conditions\n"
	.string "d'ÉVOLUTION de certaines espèces.\p"
	.string "Cependant, maintenir un système aussi complexe\n"
	.string "peut coûter cher.\p"
	.string "Tu as la possibilité de payer une\n"
	.string "licence à vie pour 1.000.000¥,\l"
	.string "ou de l'utiliser en payant à chaque\l"
	.string "utilisation, ce qui coûte 10.000¥.\p"
	.string "Si tu veux l'essayer, utilise\n"
	.string "l'ordinateur à ta droite !\p"
	.string "Merci d'utiliser les produits\n"
	.string "DEVON S.A. !$"

LilycoveCity_DepartmentStore_1F_Text_WelcomeToDeptStore:
	.string "Bienvenue au GRAND MAGASIN DE LILYCOVE.$"

LilycoveCity_DepartmentStore_1F_Text_IBuyAllSortsOfThings:
	.string "Chaque fois que je viens au GRAND MAGASIN,\n"
	.string "je finis par acheter toutes sortes\l"
	.string "de choses, c'est tellement amusant.$"

LilycoveCity_DepartmentStore_1F_Text_MomBuyingMeFurniture:
	.string "Aujourd'hui, ma maman va m'acheter\n"
	.string "de beaux meubles.$"

LilycoveCity_DepartmentStore_1F_Text_BuyingSomethingForAzumarill:
	.string "J'achète quelque chose pour mon AZUMARILL\n"
	.string "en récompense d'une victoire au CONCOURS.$"

LilycoveCity_DepartmentStore_1F_Text_Azumarill:
	.string "AZUMARILL : Maririroo !$"

LilycoveCity_DepartmentStore_1F_Text_FloorNamesSign:
	.string "RDC : ACCUEIL\n"
	.string "    COIN LOTERIE\p"
	.string "1ER : ZONE DRESSEUR\p"
	.string "2E : COLLECTION COMBAT\p"
	.string "3E : COIN CT\p"
	.string "4E : ÉTAGE POKéPOUPEE\p"
	.string "TOIT : PLAZA DU TOIT$"

@ Unused
LilycoveCity_DepartmentStore_1F_Text_WirelessCommIsFun:
	.string "La communication sans fil, c'est amusant, non\n"
	.string "? Je pense que ça permet de\p"
	.string "faire des choses impossibles avant. Par exemple,\n"
	.string "tu peux maintenant échanger avec des gens\p"
	.string "avec qui tu ne pouvais pas\n"
	.string "avant. Je pense que ça va\p"
	.string "changer le monde des POKéMON !$"

@ Unused
LilycoveCity_DepartmentStore_1F_Text_SpreadWordAboutWirelessComm:
	.string "Je veux faire connaître à quel point\n"
	.string "la Communication Sans Fil peut être amusante.$"

