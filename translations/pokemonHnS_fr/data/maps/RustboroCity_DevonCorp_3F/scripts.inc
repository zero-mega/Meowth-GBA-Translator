.set LOCALID_DEVON_EMPLOYEE, 2

RustboroCity_DevonCorp_3F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_3F_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, RustboroCity_DevonCorp_3F_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RustboroCity_DevonCorp_3F_OnFrame
	.byte 0

RustboroCity_DevonCorp_3F_OnTransition:
	call_if_eq VAR_GARBAGEVAR, 0, RustboroCity_DevonCorp_3F_EventScript_SetEmployeePos
	end

RustboroCity_DevonCorp_3F_EventScript_SetEmployeePos::
	setobjectxyperm LOCALID_DEVON_EMPLOYEE, 3, 2
	setobjectmovementtype LOCALID_DEVON_EMPLOYEE, MOVEMENT_TYPE_FACE_LEFT
	return

RustboroCity_DevonCorp_3F_OnWarp:
	map_script_2 VAR_GARBAGEVAR, 0, RustboroCity_DevonCorp_3F_EventScript_PlayerFaceEast
	.2byte 0

RustboroCity_DevonCorp_3F_EventScript_PlayerFaceEast::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	end

RustboroCity_DevonCorp_3F_OnFrame:
	map_script_2 VAR_GARBAGEVAR, 0, RustboroCity_DevonCorp_3F_EventScript_MeetPresident
	.2byte 0

RustboroCity_DevonCorp_3F_EventScript_MeetPresident::
	lockall
	msgbox RustboroCity_DevonCorp_3F_Text_ThisIs3rdFloorWaitHere, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeWalkOffscreen
	waitmovement 0
	delay 80
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeReturnToPlayer
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_WordWithPresidentComeWithMe, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_FOLLOW_ME, FALSE
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_LeadPlayerToPresident
	applymovement OBJ_EVENT_ID_PLAYER, RustboroCity_DevonCorp_3F_Movement_PlayerFollowToPresident
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_PleaseGoAhead, MSGBOX_DEFAULT
	closemessage
	fadedefaultbgm
	applymovement LOCALID_DEVON_EMPLOYEE, RustboroCity_DevonCorp_3F_Movement_EmployeeFaceDesk
	applymovement OBJ_EVENT_ID_PLAYER, RustboroCity_DevonCorp_3F_Movement_PlayerApproachDesk
	waitmovement 0
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneIHaveFavor, MSGBOX_DEFAULT
	giveitem ITEM_LETTER
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneWantYouToHaveThis, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message RustboroCity_DevonCorp_3F_Text_ReceivedPokenav
	waitfanfare
	setflag FLAG_SYS_POKENAV_GET
	setflag FLAG_RECEIVED_POKENAV
	setflag FLAG_HIDE_RUSTBORO_CITY_POKEMON_SCHOOL_SCOTT
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneExplainPokenavRestUp, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox RustboroCity_DevonCorp_3F_Text_MrStoneGoWithCautionAndCare, MSGBOX_DEFAULT
	setflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	setvar VAR_GARBAGEVAR, 1
	clearflag FLAG_GARBAGEFLAG
	setvar VAR_GARBAGEVAR, 1
	setvar VAR_GARBAGEVAR, 6
	releaseall
	end

RustboroCity_DevonCorp_3F_Movement_Unused:
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_left
	step_end

RustboroCity_DevonCorp_3F_Movement_LeadPlayerToPresident:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_faster_left
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeFaceDesk:
	delay_16
	walk_in_place_faster_down
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeWalkOffscreen:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RustboroCity_DevonCorp_3F_Movement_EmployeeReturnToPlayer:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	walk_left
	step_end

RustboroCity_DevonCorp_3F_Movement_PlayerFollowToPresident:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RustboroCity_DevonCorp_3F_Movement_PlayerApproachDesk:
	delay_16
	delay_16
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

RustboroCity_DevonCorp_3F_EventScript_MrStone::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_EXP_SHARE, RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor
	goto_if_set FLAG_DELIVERED_STEVEN_LETTER, RustboroCity_DevonCorp_3F_EventScript_GiveExpShare
	msgbox RustboroCity_DevonCorp_3F_Text_CountingOnYou, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_GiveExpShare::
	msgbox RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter, MSGBOX_DEFAULT
	giveitem ITEM_EXP_SHARE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_EXP_SHARE
	msgbox RustboroCity_DevonCorp_3F_Text_ExplainExpShare, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_MrStoneAfterFavor::
	msgbox RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

RustboroCity_DevonCorp_3F_EventScript_Employee::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_REPEAT_BALL, RustboroCity_DevonCorp_3F_EventScript_EmployeeBalls
	msgbox RustboroCity_DevonCorp_3F_Text_VisitCaptSternShipyard, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_3F_EventScript_EmployeeBalls::
	msgbox RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_3F_EventScript_RareRocksDisplay::
	msgbox RustboroCity_DevonCorp_3F_Text_RareRocksDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_3F_Text_MrStoneIHaveFavor:
	.string "Je suis M. PIERRE, le PRÉSIDENT de\n"
	.string "DEVON S.A.\p"
	.string "Je viens juste d'avoir\p"
	.string "des nouvelles sur toi !\n"
	.string "Tu as sauvé notre\p"
	.string "personnel non pas une,\n"
	.string "mais deux fois !\p"
	.string "J'ai une faveur à\n"
	.string "demander à une personne\p"
	.string "extraordinaire comme toi.\n"
	.string "Je comprends que tu es en voyage.\p"
	.string "Mais pourrais-tu livrer ceci\n"
	.string "au CAPT. POIVRE à POIVRESSE ?$"

RustboroCity_DevonCorp_3F_Text_MrStoneWantYouToHaveThis:
	.string "M. PIERRE : Maintenant, tu dois savoir que\n"
	.string "je suis un grand PRÉSIDENT.\p"
	.string "Alors, je ne serais jamais aussi mesquin que de\n"
	.string "te demander de garder notre conversation secrète.\p"
	.string "C'est notre petit secret !$"

RustboroCity_DevonCorp_3F_Text_ReceivedPokenav:
	.string "{PLAYER} a reçu un POKéNAV.$"

RustboroCity_DevonCorp_3F_Text_MrStoneExplainPokenavRestUp:
	.string "MR. PIERRE : Cet appareil…\p"
	.string "C'est un POKéNAV, ou POKéNAV pour faire court.\n"
	.string "C'est un outil indispensable pour tout\p"
	.string "DRESSEUR en aventure.\n"
	.string "Il a une carte de la région de HOENN.\p"
	.string "Tu peux facilement vérifier\p"
	.string "les emplacements de\n"
	.string "VERGONHA et POIVRESSE !\p"
	.string "Au fait, j'ai entendu dire que des criminels\n"
	.string "sinistres--MAGMA et AQUA, je crois--\l"
	.string "ont causé des problèmes partout.\p"
	.string "Je pense qu'il serait préférable que tu te\n"
	.string "reposes avant de repartir.$"

RustboroCity_DevonCorp_3F_Text_MrStoneGoWithCautionAndCare:
	.string "M. PIERRE : Eh bien, {PLAYER}{KUN},\n"
	.string "vas-y avec prudence et attention !$"

RustboroCity_DevonCorp_3F_Text_CountingOnYou:
	.string "M. PIERRE : Je compte sur toi !$"

RustboroCity_DevonCorp_3F_Text_ThankYouForDeliveringLetter:
	.string "M. PIERRE : Tu as livré\n"
	.string "ma LETTRE ? Merci beaucoup !\p"
	.string "Voici ma façon de te remercier.\n"
	.string "Ça devrait t'aider, toi, DRESSEUR.$"

RustboroCity_DevonCorp_3F_Text_ExplainExpShare:
	.string "M. PIERRE : Si tu actives le MULTI EXP,\n"
	.string "tous les POKéMON de l'équipe gagneront\l"
	.string "la moitié des Points d'EXP du combat.\p"
	.string "Je dirais que le MULTI EXP est très utile\n"
	.string "pour élever des POKéMON faibles.$"

RustboroCity_DevonCorp_3F_Text_NotFamiliarWithTrends:
	.string "M. ROCHARD : Depuis ma jeunesse, je\n"
	.string "me suis immergé dans le travail. Par\p"
	.string "conséquent, je ne connais pas les tendances\n"
	.string "et ce genre de choses. Mais est-ce\p"
	.string "que tous les jeunes veulent devenir\n"
	.string "DRESSEURS de la LIGUE POKéMON ?$"

RustboroCity_DevonCorp_3F_Text_ThisIs3rdFloorWaitHere:
	.string "C'est le troisième étage de\n"
	.string "DEVON S.A.\p"
	.string "Le BUREAU du PRÉSIDENT est\n"
	.string "à cet étage.\p"
	.string "Bref, je ne peux pas te dire à quel point je suis\n"
	.string "reconnaissant pour ce que tu as fait.\p"
	.string "Euh… Au fait, ce colis\n"
	.string "que tu as récupéré pour nous…\p"
	.string "Pourrais-tu le livrer au\n"
	.string "CHANTIER NAVAL de POIVRESSE ?\p"
	.string "Ce serait terrible si ces voleurs\n"
	.string "essayaient de le reprendre.\p"
	.string "Euh… Héhéhé, alors, euh, pourrais-je compter\n"
	.string "sur toi pour faire ça ?\p"
	.string "Oh, c'est vrai.\n"
	.string "Pourrais-tu attendre ici une seconde ?$"

RustboroCity_DevonCorp_3F_Text_WordWithPresidentComeWithMe:
	.string "Notre PRÉSIDENT aimerait avoir\n"
	.string "un mot avec toi.\p"
	.string "Viens avec moi.$"

RustboroCity_DevonCorp_3F_Text_PleaseGoAhead:
	.string "Je vous en prie, allez-y.$"

RustboroCity_DevonCorp_3F_Text_VisitCaptSternShipyard:
	.string "Si tu visites le CHANTIER NAVAL de POIVRESSE,\n"
	.string "tu devrais aller voir le CAPT. STERN.$"

RustboroCity_DevonCorp_3F_Text_RepeatAndTimerHugelyPopular:
	.string "Les nouveaux produits DEVON, la REPEAT BALL\n"
	.string "et la TIMER BALL, sont devenus très\l"
	.string "populaires parmi les DRESSEURS.$"

RustboroCity_DevonCorp_3F_Text_RareRocksDisplay:
	.string "C'est une collection de roches et pierres rares\n"
	.string "assemblée par le PRÉSIDENT.$"

