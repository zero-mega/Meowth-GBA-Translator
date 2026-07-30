.set LOCALID_SS_TIDAL, 2
.set LOCALID_FERRY_ATTENDANT, 3
.set LOCALID_MANIAC_1, 9
.set LOCALID_MANIAC_2, 10
.set LOCALID_GIRL, 12
.set LOCALID_CAMPER, 14
.set LOCALID_FISHERMAN_2, 18
.set LOCALID_MAN_4, 23

BattleFrontier_OutsideWest_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_OutsideWest_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

BattleFrontier_OutsideWest_OnTransition:
	callnative SetTimeBasedEncounters
	setvar VAR_BRAVO_TRAINER_BATTLE_TOWER_ON, 0
	setflag FLAG_HIDE_BATTLE_TOWER_REPORTER
	end

BattleFrontier_OutsideWest_EventScript_Sailor::
	lock
	faceplayer
	msgbox BattleFrontierOutsideWest_Text_SailorReturn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideWest_AsYouLike
	msgbox EventTicket_Text_SailHome, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	hideobjectat LOCALID_FERRY_ATTENDANT, MAP_BATTLE_FRONTIER_OUTSIDE_WEST
	setvar VAR_0x8004, LOCALID_SS_TIDAL
	call Common_EventScript_FerryDepartIsland
	warpsilent MAP_VERMILION_CITY_PORT_INSIDE, 8, 9
	waitstate
	release
	end

BattleFrontier_OutsideWest_AsYouLike::
	msgbox EventTicket_Text_AsYouLike, MSGBOX_DEFAULT
	release
	end

BattleFrontierOutsideWest_Text_SailorReturn:
	.string "Tu veux retourner à CARMIN SUR MER ?$"

BattleFrontier_OutsideWest_EventScript_FerryAttendant::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_MayISeeYourTicket, MSGBOX_DEFAULT
	checkitem ITEM_SS_TICKET
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_OutsideWest_EventScript_NoSSTicket
	message BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo
	waitmessage
	goto BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination
	end

BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination::
	multichoicedefault 18, 6, MULTI_SSTIDAL_BATTLE_FRONTIER, 2, FALSE
	switch VAR_RESULT
	case 0, BattleFrontier_OutsideWest_EventScript_FerryToSlateport
	case 1, BattleFrontier_OutsideWest_EventScript_FerryToLilycove
	case 2, BattleFrontier_OutsideWest_EventScript_CancelFerrySelect
	case MULTI_B_PRESSED, BattleFrontier_OutsideWest_EventScript_CancelFerrySelect
	end

BattleFrontier_OutsideWest_EventScript_NoSSTicket::
	msgbox BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_FerryToSlateport::
	msgbox BattleFrontier_OutsideWest_Text_SlateportItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination
	msgbox BattleFrontier_OutsideWest_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	call BattleFrontier_OutsideWest_EventScript_BoardFerry
	warp MAP_SLATEPORT_CITY_HARBOR, 8, 11
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_FerryToLilycove::
	msgbox BattleFrontier_OutsideWest_Text_LilycoveItIs, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination
	msgbox BattleFrontier_OutsideWest_Text_PleaseBoardFerry, MSGBOX_DEFAULT
	call BattleFrontier_OutsideWest_EventScript_BoardFerry
	warp MAP_LILYCOVE_CITY_HARBOR, 8, 11
	waitstate
	release
	end

BattleFrontier_OutsideWest_EventScript_ChooseNewFerryDestination::
	message BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo
	waitmessage
	goto BattleFrontier_OutsideWest_EventScript_ChooseFerryDestination
	end

BattleFrontier_OutsideWest_EventScript_BoardFerry::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 30
	hideobjectat LOCALID_FERRY_ATTENDANT, MAP_BATTLE_FRONTIER_OUTSIDE_WEST
	setvar VAR_0x8004, LOCALID_SS_TIDAL
	call Common_EventScript_FerryDepartIsland
	return

BattleFrontier_OutsideWest_EventScript_CancelFerrySelect::
	msgbox BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_BattleDomeSign::
	msgbox BattleFrontier_OutsideWest_Text_BattleDomeSign, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattleFactorySign::
	msgbox BattleFrontier_OutsideWest_Text_BattleFactorySign, MSGBOX_SIGN
	end

BattleFrontier_OutsideWest_EventScript_BattlePikeSign::
	msgbox BattleFrontier_OutsideWest_Text_BattlePikeSign, MSGBOX_SIGN
	end

@ Unused. Of note, Battle Tower is in the East section in the final release
BattleFrontier_OutsideWest_EventScript_UnusedNPC1::
	msgbox BattleFrontier_OutsideWest_Text_ThisIsBattleTower, MSGBOX_NPC
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC2::
	msgbox BattleFrontier_OutsideWest_Text_CantFindBattleTower, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Boy1::
	msgbox BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Engineer::
	msgbox BattleFrontier_OutsideWest_Text_Reparations, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Engineer2::
	msgbox BattleFrontier_OutsideWest_Text_Reparations2, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Engineer3::
	msgbox BattleFrontier_OutsideWest_Text_Reparations3, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Engineer4::
	msgbox BattleFrontier_OutsideWest_Text_Reparations4, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Fisherman2::
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere
	waitmessage
	applymovement LOCALID_FISHERMAN_2, Common_Movement_FaceAwayPlayer
	waitmovement 0
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_Man1::
	msgbox BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Maniac1::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk
	end

BattleFrontier_OutsideWest_EventScript_Maniac2::
	lock
	goto BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk
	end

BattleFrontier_OutsideWest_EventScript_FactoryChallengersTalk::
	applymovement LOCALID_MANIAC_1, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons, MSGBOX_DEFAULT
	applymovement LOCALID_MANIAC_2, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons, MSGBOX_DEFAULT
	closemessage
	delay 25
	applymovement LOCALID_MANIAC_1, Common_Movement_WalkInPlaceFasterUp
	applymovement LOCALID_MANIAC_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_Camper::
	lock
	faceplayer
	delay 20
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_CamperAlreadyFacingFactory
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_CamperFaceFactory
	msgbox BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_CamperFaceFactory::
	applymovement LOCALID_CAMPER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_CamperAlreadyFacingFactory::
	return

BattleFrontier_OutsideWest_EventScript_Girl::
	lock
	faceplayer
	message BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper
	waitmessage
	call_if_eq VAR_FACING, DIR_NORTH, BattleFrontier_OutsideWest_EventScript_GirlShudderNorth
	call_if_eq VAR_FACING, DIR_SOUTH, BattleFrontier_OutsideWest_EventScript_GirlShudderSouth
	call_if_eq VAR_FACING, DIR_WEST, BattleFrontier_OutsideWest_EventScript_GirlShudderWest
	call_if_eq VAR_FACING, DIR_EAST, BattleFrontier_OutsideWest_EventScript_GirlShudderEast
	waitbuttonpress
	release
	end

BattleFrontier_OutsideWest_EventScript_GirlShudderNorth::
	applymovement LOCALID_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderNorth
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderSouth::
	applymovement LOCALID_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderSouth
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderWest::
	applymovement LOCALID_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderWest
	waitmovement 0
	return

BattleFrontier_OutsideWest_EventScript_GirlShudderEast::
	applymovement LOCALID_GIRL, BattleFrontier_OutsideWest_Movement_GirlShudderEast
	waitmovement 0
	return

BattleFrontier_OutsideWest_Movement_GirlShudderNorth:
	walk_in_place_faster_down
	walk_in_place_faster_down
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderSouth:
	walk_in_place_faster_up
	walk_in_place_faster_up
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderWest:
	walk_in_place_faster_right
	walk_in_place_faster_right
	step_end

BattleFrontier_OutsideWest_Movement_GirlShudderEast:
	walk_in_place_faster_left
	walk_in_place_faster_left
	step_end

BattleFrontier_OutsideWest_EventScript_Woman2::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors, MSGBOX_DEFAULT
	random 2
	goto_if_eq VAR_RESULT, 1, BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors
	goto BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors
	end

BattleFrontier_OutsideWest_EventScript_WomanWonRockPaperScissors::
	msgbox BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_WomanLostRockPaperScissors::
	msgbox BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Fisherman1::
	msgbox BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Fisherman_Milotic::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MILOTIC, CRY_MODE_NORMAL
	msgbox BattleFrontier_OutsideWest_Text_Milotic, MSGBOX_DEFAULT
	waitmoncry
	release
	end

@ Unused
BattleFrontier_OutsideWest_EventScript_UnusedNPC3::
	msgbox BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Gentleman::
	msgbox BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Lass::
	msgbox BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_ExpertM::
	msgbox BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man2::
	msgbox BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman1::
	msgbox BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan1::
	msgbox BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_FatMan2::
	msgbox BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Woman3::
	lock
	msgbox BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_Boy2::
	lock
	msgbox BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering, MSGBOX_DEFAULT
	release
	end

BattleFrontier_OutsideWest_EventScript_OldMan::
	msgbox BattleFrontier_OutsideWest_Text_DomeAceIsMine, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_EventScript_Man4::
	lock
	faceplayer
	msgbox BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_MAN_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

BattleFrontier_OutsideWest_EventScript_PokefanF::
	msgbox BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier, MSGBOX_NPC
	end

BattleFrontier_OutsideWest_Text_BattleDomeSign:
	.string "C'est le DÔME DE COMBAT !\n"
	.string "Ton chemin vers la superstar invincible !$"

BattleFrontier_OutsideWest_Text_BattleFactorySign:
	.string "C'est l'USINE DE COMBAT !\n"
	.string "Cherche les POKéMON les plus durs !$"

BattleFrontier_OutsideWest_Text_BattlePikeSign:
	.string "C'est la TOUR DE COMBAT !\n"
	.string "Choisis l'un des trois chemins !$"

BattleFrontier_OutsideWest_Text_ThisIsBattleTower:
	.string "C'est la TOUR DE COMBAT.\p"
	.string "Les DRESSEURS y amènent leurs POKéMON les mieux\n"
	.string "entraînés pour des matchs à élimination.$"

BattleFrontier_OutsideWest_Text_MayISeeYourTicket:
	.string "Bonjour, êtes-vous ici pour le ferry ?\n"
	.string "Puis-je voir votre PASSE ?$"

BattleFrontier_OutsideWest_Text_MustHaveTicketToBoard:
	.string "{PLAYER} n'a pas le BILLET...\p"
	.string "Je suis vraiment désolé.\p"
	.string "Tu dois avoir un BILLET pour\n"
	.string "monter sur le ferry.$"

BattleFrontier_OutsideWest_Text_WhereWouldYouLikeToGo:
	.string "{PLAYER} a montré le TICKET.\p"
	.string "Parfait ! C'est tout ce qu'il faut !\p"
	.string "Et où aimerais-tu aller ?$"

BattleFrontier_OutsideWest_Text_SlateportItIs:
	.string "POIVRESSELLE, alors !$"

BattleFrontier_OutsideWest_Text_LilycoveItIs:
	.string "LILYCOVE, c'est décidé !$"

BattleFrontier_OutsideWest_Text_SailWithUsAnotherTime:
	.string "Reviens naviguer avec nous une autre fois !$"

BattleFrontier_OutsideWest_Text_PleaseBoardFerry:
	.string "Montez à bord du ferry et attendez\n"
	.string "le départ.$"

BattleFrontier_OutsideWest_Text_ThenWhereWouldYouLikeToGo:
	.string "Alors, où aimerais-tu aller ?$"

BattleFrontier_OutsideWest_Text_BestOutOfAllMyFriends:
	.string "Je suis le meilleur de tous mes amis.\n"
	.string "Mais ici…\l"
	.string "Je n'ai servi à rien !$"

BattleFrontier_OutsideWest_Text_CantFindBattleTower:
	.string "Je veux aller à la TOUR DE COMBAT,\n"
	.string "mais je ne la trouve pas même avec\l"
	.string "une carte de la ZONE DE COMBAT.\p"
	.string "Cet endroit est vraiment trop grand !$"

BattleFrontier_OutsideWest_Text_GotSeasickOnWayHere:
	.string "Je voulais relever un défi dès mon\n"
	.string "arrivée ici.\p"
	.string "Mais en chemin, j'ai eu le mal de mer...\n"
	.string "Beuuurk...$"

BattleFrontier_OutsideWest_Text_OnlyToughTrainersBroughtHere:
	.string "Il's pas as si juste anyone\n"
	.string "peut venir ici, tu savoir? Seulement\p"
	.string "those TRAINERS qui've été recognized as\n"
	.string "tough sont brought ici. Ça's pourquoi\p"
	.string "beaucoup TRAINERS don't even savoir\n"
	.string "about le PARC DES COMBATS.$"

BattleFrontier_OutsideWest_Text_SureWeCanChallengeWithNoMons:
	.string "Hé, frère…\p"
	.string "Tu es sûr qu'on peut relever des défis\n"
	.string "même si on n'a pas de POKéMON ?$"

BattleFrontier_OutsideWest_Text_BigGuySaidIllLendYouMons:
	.string "Euh...\n"
	.string "Ça va aller, j'en suis sûr.\p"
	.string "Je crois...\p"
	.string "Mais tu te souviens de ce grand type effrayant ?\n"
	.string "Il a dit : “Je te prête des POKéMON !”$"

BattleFrontier_OutsideWest_Text_WhosRaisingThoseRentalMons:
	.string "C'est l'USINE DE COMBAT.\n"
	.string "Tu peux y louer des POKéMON forts.\p"
	.string "Mais ça me fait réfléchir.\n"
	.string "Qui élève ces POKéMON de location ?$"

BattleFrontier_OutsideWest_Text_ScaredOfPikeBecauseSeviper:
	.string "J'ai peur d'entrer dans le RAYON VERT\n"
	.string "à cause de SEVIPER…\p"
	.string "M-mais je suis venu jusqu'ici, alors je\n"
	.string "vais tout conquérir !\l"
	.string "…Frissons…$"

BattleFrontier_OutsideWest_Text_LetsPlayRockPaperScissors:
	.string "Jouons à pierre, feuille, ciseaux !\n"
	.string "Un, deux, trois !\p"
	.string "… … … … … …$"

BattleFrontier_OutsideWest_Text_WonIllTakePikeChallenge:
	.string "Youpi ! J'ai gagné !\n"
	.string "Je vais relever le défi de la TOUR DE COMBAT !$"

BattleFrontier_OutsideWest_Text_LostIllPutOffPikeChallenge:
	.string "Oh, non...\n"
	.string "J'ai perdu.\p"
	.string "Je ne suis pas très chanceux aujourd'hui.\n"
	.string "Je reporterai mon défi au PARcours\l"
	.string "de Combat jusqu'à demain.$"

BattleFrontier_OutsideWest_Text_ChooseFishingOverBattling:
	.string "Je crois être la seule personne ici qui,\n"
	.string "pour une raison inconnue, choisirait\l"
	.string "la pêche plutôt que le combat.\p"
	.string "Hein ? On ne peut rien attraper ici ?\n"
	.string "C'est décevant…$"

BattleFrontier_OutsideWest_Text_KeepBattlingUntilIGetSymbol:
	.string "Aujourd'hui, je vais continuer à combattre,\n"
	.string "quoi qu'il arrive, jusqu'à obtenir un Symbole.$"

BattleFrontier_OutsideWest_Text_YoureOffToChallengeDome:
	.string "Oh ? Tu vas défier\n"
	.string "le DOME DE COMBAT ?\p"
	.string "Je te souhaite bonne chance.\n"
	.string "Gagnons tous les deux et retrouvons-nous\l"
	.string "en défi.$"

BattleFrontier_OutsideWest_Text_DomeIsHereGrandpa:
	.string "Papy, par ici !\n"
	.string "Le DÔME DE COMBAT est là !\l"
	.string "Vas-y, Papy !$"

BattleFrontier_OutsideWest_Text_WontLetGentlemenBeatMe:
	.string "Ah, donc voici le DOME DE COMBAT ?\n"
	.string "Je ne me laisserai pas battre par des messieurs !\p"
	.string "Mais où est l'entrée ?$"

BattleFrontier_OutsideWest_Text_NothingHereNotLongAgo:
	.string "Il n'y avait rien ici il n'y a pas\n"
	.string "si longtemps.\p"
	.string "Mais regarde cet endroit maintenant ! Incroyable !\n"
	.string "Je vais amener ma mère pour qu'elle voie ça.$"

BattleFrontier_OutsideWest_Text_FinallyArrivedAtFrontier:
	.string "Je suis enfin arrivée à la ZONE\n"
	.string "DE COMBAT !\p"
	.string "Je suis sûre d'attirer l'attention\n"
	.string "avec mon look et mon talent !$"

BattleFrontier_OutsideWest_Text_SquareFilledWithToughPeople:
	.string "Miam, miam…\p"
	.string "On dirait que cette place est remplie\n"
	.string "de gens coriaces.\p"
	.string "Miam, miam…$"

BattleFrontier_OutsideWest_Text_MetOlderGirlAtPike:
	.string "Crunch, munch…\p"
	.string "Il y a quelque\n"
	.string "temps, j'ai\p"
	.string "rencontré cette fille\n"
	.string "plus âgée au\p"
	.string "BARRAGE DE COMBAT.\p"
	.string "Elle avait ces yeux\n"
	.string "qui semblaient voir\p"
	.string "à travers tout…\n"
	.string "Elle était\p"
	.string "vraiment forte !$"

BattleFrontier_OutsideWest_Text_LastTimeOurEyesMet:
	.string "Hein ? Écoute-toi parler ! C'est rien\n"
	.string "du tout ! La dernière fois que\p"
	.string "je l'ai encouragé, nos regards se sont\n"
	.string "croisés et des étincelles ont jailli !$"

BattleFrontier_OutsideWest_Text_DomeAceLookedBecauseOfMyCheering:
	.string "Quoooooi ?!\n"
	.string "Pfft !\p"
	.string "Ça n'est arrivé que parce que\n"
	.string "j'étais assis à côté de toi !\p"
	.string "L'AS DU DÔME ne nous a regardés\n"
	.string "que parce que mes encouragements étaient si forts !$"

BattleFrontier_OutsideWest_Text_DomeAceIsMine:
	.string "Oh, taisez-vous !\n"
	.string "Baissez le volume !\p"
	.string "Vous, les fans opportunistes, devriez vous en tenir\n"
	.string "à encourager un CHAMPION D'ARÈNE !\p"
	.string "L'AS DU DÔME est à moi !\n"
	.string "Mon seul idole !$"

BattleFrontier_OutsideWest_Text_FansOverThereUsedToBeTrainers:
	.string "Ces gens qui se disputent là-bas…\p"
	.string "C'est difficile à croire, mais ils étaient\n"
	.string "autrefois DRESSEURS, et de bons en plus.\p"
	.string "Ils étaient incroyablement coriaces,\n"
	.string "et ils étaient célèbres aussi.\p"
	.string "Mais ils ont été anéantis par un\n"
	.string "certain DRESSEUR lors d'un tournoi.\p"
	.string "Ils ont été si complètement battus,\n"
	.string "qu'ils sont tombés amoureux du DRESSEUR.\p"
	.string "Maintenant ils ne sont que des fans du DRESSEUR.\n"
	.string "Ils vont l'encourager au\l"
	.string "DÔME DE COMBAT chaque jour maintenant.$"

BattleFrontier_OutsideWest_Text_MonWithLongTailInFrontier:
	.string "Jusqu'à il y a quelques\n"
	.string "semaines, il y avait\p"
	.string "une grotte ici au\n"
	.string "PARC DES COMBATS !\p"
	.string "À l'intérieur, tu pouvais\n"
	.string "trouver des objets rares.\p"
	.string "Elle a été fermée\n"
	.string "pour rénovation.$"

BattleFrontier_OutsideWest_Text_Reparations:
    .string "Attention ! La grotte sous le\p"
    .string "PARC DES COMBATS s'est effondrée il\n"
    .string "n'y a pas longtemps. On renforce\p"
    .string "la structure pour que ça ne\n"
    .string "se reproduise pas. Jusqu'à la fin\p"
    .string "des réparations, il faudra contourner\n"
    .string "par les ponts de bois.$"

BattleFrontier_OutsideWest_Text_Reparations2:
    .string "Attention où tu mets les pieds !\p"
    .string "On répare encore les dégâts de\n"
    .string "l'effondrement de la grotte.\p"
    .string "Ces ponts en bois ne sont que\n"
    .string "temporaires, alors fais attention !$"

BattleFrontier_OutsideWest_Text_Reparations3:
    .string "Ugh… Encore une journée de réparations.\n"
    .string "L'éboulement de la grotte a tout\p"
    .string "gâché. J'espère juste que ces supports\n"
    .string "tiendront jusqu'à la fin des travaux.$"

BattleFrontier_OutsideWest_Text_Reparations4:
    .string "Ces MACKOGNEUR et MACKOGNEUR sont d'une\n"
    .string "énorme aide pour les réparations !\p"
    .string "Sans eux, la reconstruction après l'\n"
    .string "effondrement prendrait une éternité !$"

BattleFrontier_OutsideWest_Text_Milotic:
	.string "MILOTIC : Milooo !$"
