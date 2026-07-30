.set FOUND_FIRST_SWITCH, FLAG_TEMP_1
.set SWITCH1_ID,         VAR_0x8004
.set SWITCH2_ID,         VAR_0x8005
.set TRASH_CAN_ID,       VAR_0x8008

.set CHECK_VISITOR_STATE, 6
.set TYPE, VAR_0x8003
.set ARGUMENT, VAR_0x8004

VermilionCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, VermilionCity_Gym_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_Gym_OnTransition
	.byte 0

VermilionCity_Gym_OnLoad::
	call_if_set FOUND_FIRST_SWITCH, VermilionCity_Gym_EventScript_SetOneBeamOff
	call_if_set FLAG_FOUND_BOTH_VERMILION_GYM_SWITCHES, VermilionCity_Gym_EventScript_SetBeamsOff
	end

VermilionCity_Gym_EventScript_SetOneBeamOff::
	setmetatile 3, 6, METATILE_VermilionGym_Beam_Node_TopLeft_HalfOn, 1
	setmetatile 4, 6, METATILE_VermilionGym_Beam_Node_TopLeft_Edge_HalfOn, 1
	setmetatile 5, 6, METATILE_VermilionGym_Beam_MidTop_HalfOn, 1
	setmetatile 6, 6, METATILE_VermilionGym_Beam_Node_TopRight_Edge_HalfOn, 1
	setmetatile 7, 6, METATILE_VermilionGym_Beam_Node_TopRight_HalfOn, 1
	setmetatile 3, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_HalfOn, 1
	setmetatile 4, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_Edge_HalfOn, 1
	setmetatile 5, 7, METATILE_VermilionGym_Beam_MidBottom_HalfOn, 1
	setmetatile 6, 7, METATILE_VermilionGym_Beam_Node_BottomRight_Edge_HalfOn, 1
	setmetatile 7, 7, METATILE_VermilionGym_Beam_Node_BottomRight_HalfOn, 1
	return

VermilionCity_Gym_EventScript_SetBeamsOff::
	setmetatile 3, 6, METATILE_VermilionGym_Beam_Node_TopLeft_Off, 1
	setmetatile 4, 6, METATILE_VermilionGym_Beam_Node_TopLeft_Edge_Off, 0
	setmetatile 5, 6, METATILE_VermilionGym_Floor, 0
	setmetatile 6, 6, METATILE_VermilionGym_Beam_Node_TopRight_Edge_Off, 0
	setmetatile 7, 6, METATILE_VermilionGym_Beam_Node_TopRight_Off, 1
	setmetatile 3, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_Off, 1
	setmetatile 4, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_Edge_Off, 0
	setmetatile 5, 7, METATILE_VermilionGym_Floor, 0
	setmetatile 6, 7, METATILE_VermilionGym_Beam_Node_BottomRight_Edge_Off, 0
	setmetatile 7, 7, METATILE_VermilionGym_Beam_Node_BottomRight_Off, 1
	return

VermilionCity_Gym_OnTransition::
	call VermilionCity_Gym_EventScript_InitTrashCans
	end

VermilionCity_Gym_EventScript_InitTrashCans::
	goto_if_set FLAG_FOUND_BOTH_VERMILION_GYM_SWITCHES, VermilionCity_Gym_EventScript_Return
	special SetVermilionTrashCans
	copyvar VAR_TEMP_0, SWITCH1_ID
	copyvar VAR_TEMP_1, SWITCH2_ID
	return

VermilionCity_Gym_EventScript_Return::
	end

VermilionCity_Gym_EventScript_TrashCan1::
	lockall
	setvar TRASH_CAN_ID, 1
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan2::
	lockall
	setvar TRASH_CAN_ID, 2
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan3::
	lockall
	setvar TRASH_CAN_ID, 3
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan4::
	lockall
	setvar TRASH_CAN_ID, 4
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan5::
	lockall
	setvar TRASH_CAN_ID, 5
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan6::
	lockall
	setvar TRASH_CAN_ID, 6
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan7::
	lockall
	setvar TRASH_CAN_ID, 7
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan8::
	lockall
	setvar TRASH_CAN_ID, 8
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan9::
	lockall
	setvar TRASH_CAN_ID, 9
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan10::
	lockall
	setvar TRASH_CAN_ID, 10
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan11::
	lockall
	setvar TRASH_CAN_ID, 11
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan12::
	lockall
	setvar TRASH_CAN_ID, 12
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan13::
	lockall
	setvar TRASH_CAN_ID, 13
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan14::
	lockall
	setvar TRASH_CAN_ID, 14
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan15::
	lockall
	setvar TRASH_CAN_ID, 15
	goto VermilionCity_Gym_EventScript_TrashCan
	end

VermilionCity_Gym_EventScript_TrashCan::
	copyvar SWITCH1_ID, VAR_TEMP_0
	copyvar SWITCH2_ID, VAR_TEMP_1
	goto_if_set FLAG_FOUND_BOTH_VERMILION_GYM_SWITCHES, VermilionCity_Gym_EventScript_LocksAlreadyOpen
	goto_if_set FOUND_FIRST_SWITCH, VermilionCity_Gym_EventScript_TrySwitchTwo
	goto_if_eq SWITCH1_ID, TRASH_CAN_ID, VermilionCity_Gym_EventScript_FoundSwitchOne
	msgbox VermilionCity_Gym_Text_NopeOnlyTrashHere
	releaseall
	end

VermilionCity_Gym_EventScript_FoundSwitchOne::
	msgbox VermilionCity_Gym_Text_SwitchUnderTrashFirstLockOpened
	playse SE_PIN
	waitse
	call VermilionCity_Gym_EventScript_SetOneBeamOff
	special DrawWholeMapView
	setflag FOUND_FIRST_SWITCH
	releaseall
	end

VermilionCity_Gym_EventScript_TrySwitchTwo::
	goto_if_eq SWITCH2_ID, TRASH_CAN_ID, VermilionCity_Gym_EventScript_FoundSwitchTwo
	msgbox VermilionCity_Gym_Text_OnlyTrashLocksWereReset
	clearflag FOUND_FIRST_SWITCH
	special SetVermilionTrashCans
	copyvar VAR_TEMP_0, SWITCH1_ID
	copyvar VAR_TEMP_1, SWITCH2_ID
	call VermilionCity_Gym_EventScript_SetBeamsOn
	special DrawWholeMapView
	releaseall
	end

VermilionCity_Gym_EventScript_FoundSwitchTwo::
	msgbox VermilionCity_Gym_Text_SecondLockOpened
	closemessage
	call VermilionCity_Gym_EventScript_SetBeamsOff
	special DrawWholeMapView
	playse SE_UNLOCK
	waitse
	setflag FLAG_FOUND_BOTH_VERMILION_GYM_SWITCHES
	releaseall
	end

VermilionCity_Gym_EventScript_LocksAlreadyOpen::
	msgbox VermilionCity_Gym_Text_NopeOnlyTrashHere
	releaseall
	end

VermilionCity_Gym_EventScript_SetBeamsOn::
	setmetatile 3, 6, METATILE_VermilionGym_Beam_Node_TopLeft_On, 1
	setmetatile 4, 6, METATILE_VermilionGym_Beam_Node_TopLeft_Edge_On, 1
	setmetatile 5, 6, METATILE_VermilionGym_Beam_MidTop, 1
	setmetatile 6, 6, METATILE_VermilionGym_Beam_Node_TopRight_Edge_On, 1
	setmetatile 7, 6, METATILE_VermilionGym_Beam_Node_TopRight_On, 1
	setmetatile 3, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_On, 1
	setmetatile 4, 7, METATILE_VermilionGym_Beam_Node_BottomLeft_Edge_On, 1
	setmetatile 5, 7, METATILE_VermilionGym_Beam_MidBottom, 1
	setmetatile 6, 7, METATILE_VermilionGym_Beam_Node_BottomRight_Edge_On, 1
	setmetatile 7, 7, METATILE_VermilionGym_Beam_Node_BottomRight_On, 1
	return

VermilionCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_VERMILION_GYM, VermilionCity_Gym_EventScript_GymGuyPostVictory
	msgbox VermilionCity_Gym_Text_GymGuyAdvice
	release
	end

VermilionCity_Gym_EventScript_GymGuyPostVictory::
	msgbox VermilionCity_Gym_Text_GymGuyPostVictory
	release
	end

VermilionCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE11_GET, VermilionCity_Gym_EventScript_GymStatuePostVictory
	msgbox VermilionCity_Gym_Text_GymStatue
	releaseall
	end

VermilionCity_Gym_EventScript_GymStatuePostVictory::
	msgbox VermilionCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end

VermilionCity_Gym_EventScript_Gregory::
	trainerbattle_single TRAINER_GREGORY VermilionGym_Text_GentlemanGregorySeen, VermilionGym_Text_GentlemanGregoryBeaten
	msgbox VermilionGym_Text_GentlemanGregoryAfter, MSGBOX_AUTOCLOSE
	end

VermilionCity_Gym_EventScript_Vincent::
	trainerbattle_single TRAINER_VINCENT VermilionGym_Text_GuitaristVincentSeen, VermilionGym_Text_GuitaristVincentBeaten
	msgbox VermilionGym_Text_GuitaristVincentAfter, MSGBOX_AUTOCLOSE
	end

VermilionCity_Gym_EventScript_Horton::
	trainerbattle_single TRAINER_HORTON VermilionGym_Text_JugglerHortonSeen, VermilionGym_Text_JugglerHortonBeaten
	msgbox VermilionGym_Text_JugglerHortonAfter, MSGBOX_AUTOCLOSE
	end

VermilionCity_Gym_EventScript_Surge::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_VERMILION_GYM, VermilionCity_Gym_EventScript_Surge_Defeated
	msgbox VermilionGym_Text_LtSurgeIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_LTSURGE, VermilionGym_Text_LtSurgeWinLoss
	message VermilionGym_Text_ReceivedThunderBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox VermilionGym_Text_ThunderBadgeInfo, MSGBOX_DEFAULT
	setflag FLAG_BADGE11_GET
	setflag FLAG_DEFEATED_VERMILION_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 11
	call Common_EventScript_SetGymTrainers
	checkitem ITEM_TM_THUNDERBOLT
	call_if_eq VAR_RESULT, TRUE, VermilionCity_Gym_EventScript_GiveThunderstone
	call_if_eq VAR_RESULT, FALSE, VermilionCity_Gym_EventScript_GiveTM
	clearflag FLAG_HIDE_PLANT_SURGE
	closemessage
	release
	end

VermilionCity_Gym_EventScript_GiveThunderstone::
	msgbox VermilionGym_Text_LtSurgeThunderstone, MSGBOX_DEFAULT
	giveitem ITEM_THUNDER_STONE
	return
VermilionCity_Gym_EventScript_GiveTM::
	msgbox VermilionGym_Text_LtSurgeTm, MSGBOX_DEFAULT
	giveitem ITEM_TM_THUNDERBOLT
	return

VermilionCity_Gym_EventScript_Surge_Defeated::
	msgbox VermilionGym_Text_LtSurgePostBattle, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionGym_Text_LtSurgeIntro:
	.string "MAJOR BOB : Hé,\p"
	.string "petit morveux !\n"
	.string "Il faut te\l"
	.string "rendre hommage.\p"
	.string "Ce n'est peut-être\n"
	.string "pas très malin de\p"
	.string "me défier, mais\n"
	.string "j'apprécie ton courage !\p"
	.string "Montre-moi ce\n"
	.string "que tu as !$"

VermilionGym_Text_LtSurgeWinLoss:
	.string "MAJOR BOB : Arrrgh ! Tu es fort !\p"
	.string "OK, gamin. Tu gagnes le BADGE TONNERRE !$"

VermilionGym_Text_ReceivedThunderBadge:
	.string "{PLAYER} a reçu le BADGE FOUDRE.$"

VermilionGym_Text_ThunderBadgeInfo:
	.string "MAJOR BOB : Le BADGE\n"
	.string "FOUDRE augmente la VITESSE des\p"
	.string "POKéMON. Considère-le comme la preuve\n"
	.string "que tu m'as vaincu.\p"
	.string "Porte-le fièrement, OK ?$"

VermilionGym_Text_LtSurgeTm:
	.string "Et prends cette CT. Elle m'a bien\n"
	.string "servi pendant la guerre !$"

VermilionGym_Text_LtSurgeThunderstone:
	.string "Et prends cette pierre. Elle a un vrai\n"
	.string "pouvoir de tonnerre !$"


VermilionGym_Text_LtSurgePostBattle:
	.string "MAJOR BOB : Hé, gamin ! Toujours en train de\n"
	.string "bosser dur ?\p"
	.string "Mes POKéMON et moi, on continue !$"

VermilionGym_Text_SurgeRematch:
	.string "MAJOR BOB : Alors, tu es\n"
	.string "maintenant CHAMPION de KANTO ! Beau\p"
	.string "travail, gamin ! Mais ne\n"
	.string "crois pas que j'ai fini\p"
	.string "! On remet ça ?$"

VermilionGym_Text_SurgeRematchDefeat:
	.string "MAJOR BOB : Arrrgh ! Tu es toujours\n"
	.string "aussi fort !$"

VermilionGym_Text_GentlemanGregorySeen:
	.string "Tu es là pour battre le MAJOR BOB ?\p"
	.string "Pas si je peux t'en empêcher !$"

VermilionGym_Text_GentlemanGregoryBeaten:
	.string "Désolé de t'avoir déçu,\n"
	.string "MAJOR BOB, monsieur !$"

VermilionGym_Text_GentlemanGregoryAfter:
	.string "Quand j'étais encore dans l'armée,\n"
	.string "le MAJOR BOB m'a sauvé la vie.$"

VermilionGym_Text_GuitaristVincentSeen:
	.string "MAJOR BOB a reconnu mon potentiel\n"
	.string "avec les POKéMON électriques.\p"
	.string "Tu penses pouvoir me battre ?$"

VermilionGym_Text_GuitaristVincentBeaten:
	.string "Ooh, quelle secousse !$"

VermilionGym_Text_GuitaristVincentAfter:
	.string "Maman m'a dit de ne pas\n"
	.string "quitter mon travail, mais que suis-je\l"
	.string "censé faire quand je n'y\l"
	.string "arrive pas non plus ?$"

VermilionGym_Text_JugglerHortonSeen:
	.string "Je vais te terrasser !\n"
	.string "Prépare-toi à être choqué !$"

VermilionGym_Text_JugglerHortonBeaten:
	.string "Gwaaah ! J'ai été écrasé…$"

VermilionGym_Text_JugglerHortonAfter:
	.string "Ne te repose pas sur ta victoire\n"
	.string "contre moi…\p"
	.string "LT.SURGE est coriace.$"

VermilionCity_Gym_Text_GymGuyAdvice::
    .string "Yo !\n"
    .string "Futur CHAMPION !\p"
    .string "Le MAJOR BOB\p"
    .string "a un surnom.\n"
    .string "Les gens l'appellent\p"
    .string "l'Américain\n"
    .string "de l'Éclair !\p"
    .string "C'est un expert\n"
    .string "des POKéMON\p"
    .string "de type ÉLECTRIK.\p"
    .string "Ses POKéMON sont\p"
    .string "rapides et puissants.\n"
    .string "Fais attention !$"

VermilionCity_Gym_Text_GymGuyPostVictory::
	.string "Ouf ! Quel combat électrisant\n"
	.string " !\p"
	.string "Ça m'a vraiment rendu nerveux.$"

VermilionCity_Gym_Text_GymStatue::
    .string "ARÈNE POKéMON DE CARMIN SUR MER\n"
    .string "CHAMPION D'ARÈNE : LT.SURGE\p"
    .string "DRESSEURS VAINQUEURS :\n"
    .string "BLEU, ROUGE$"


VermilionCity_Gym_Text_GymStatuePlayerWon::
    .string "ARÈNE POKéMON DE CARMIN SUR MER\n"
    .string "CHAMPION : MAJOR BOB\p"
    .string "DRESSEURS VAINQUEURS :\n"
    .string "BLEU, ROUGE, {PLAYER}$"

VermilionCity_Gym_Text_NopeOnlyTrashHere::
    .string "Non !\n"
    .string "Il n'y a que des déchets ici.$"

VermilionCity_Gym_Text_SwitchUnderTrashFirstLockOpened::
    .string "Hé ! Il y a un interrupteur sous la\n"
    .string "poubelle ! Active-le !\p"
    .string "Le premier verrou électrique s'est ouvert !$"

VermilionCity_Gym_Text_SecondLockOpened::
    .string "Le deuxième verrou électrique s'est ouvert !\n"
    .string "La porte motorisée s'est ouverte !$"

VermilionCity_Gym_Text_OnlyTrashLocksWereReset::
    .string "Non !\n"
    .string "Il n'y a que des déchets ici.\p"
    .string "Hé !\n"
    .string "Les verrous électriques ont été réinitialisés !$"

