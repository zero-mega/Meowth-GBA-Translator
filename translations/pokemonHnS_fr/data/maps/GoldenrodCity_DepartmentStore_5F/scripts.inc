GoldenrodCity_DepartmentStore_5F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodDeptElevator_OnFrame
	.byte 0


GoldenrodDeptStore5_EventScript_Lass::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_5FLass, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_PokefanM::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_5FPokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Girl::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_Girl, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Sign::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_5FDirectory, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Receptionist::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_5FReceptionistOhYourMon, MSGBOX_DEFAULT
	closemessage
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_150_TO_199, GoldenrodDeptStore5_EventScript_Receptionist_HighFriendship
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_50_TO_99, GoldenrodDeptStore5_EventScript_Receptionist_PutInEffort
	goto GoldenrodDeptStore5_EventScript_Receptionist_LowFriendship
	release
	end

GoldenrodDeptStore5_EventScript_Receptionist_HighFriendship::
	call_if_unset FLAG_GOT_RETURN, GoldenrodDeptStore5_EventScript_Receptionist_GiveReturn
	msgbox GoldenrodDeptStore_Text_5FReceptionistThisMoveShouldBePerfect, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Receptionist_LowFriendship::
	call_if_unset FLAG_GOT_FRUSTRATION, GoldenrodDeptStore5_EventScript_Receptionist_GiveFrustration
	msgbox GoldenrodDeptStore_Text_5FReceptionistItLooksEvilHowAboutThisTM, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Receptionist_GiveReturn::
	giveitem ITEM_TM_RETURN
	setflag FLAG_GOT_RETURN
	return

GoldenrodDeptStore5_EventScript_Receptionist_GiveFrustration::
	giveitem ITEM_TM_FRUSTRATION
	setflag FLAG_GOT_FRUSTRATION
	return

GoldenrodDeptStore5_EventScript_Receptionist_PutInEffort::
	msgbox GoldenrodDeptStore_Text_5FReceptionistPutInSomeMoreEffort, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore5_EventScript_Receptionist_Already::
	msgbox GoldenrodDeptStore_Text_5FReceptionistWait, MSGBOX_DEFAULT
	closemessage
	release
	end



GoldenrodDeptStore_Text_5FReceptionistOhYourMon:
    .string "Bonjour. Oh, tes POKéMON…$"

GoldenrodDeptStore_Text_5FReceptionistWait:
    .string "Attends, je t'ai déjà donné cette CT !$"

GoldenrodDeptStore_Text_5FReceptionistPutInSomeMoreEffort:
	.string "Hmm...\n"
	.string "Ce n'est pas mal, mais ce n'est pas bien non plus.\p"
	.string "Toi, en tant que DRESSEUR, tu dois\n"
	.string "faire plus d'efforts.$"


GoldenrodDeptStore_Text_5FReceptionistThisMoveShouldBePerfect:
    .string "Il t'est très attaché.\p"
    .string "Cette capacité devrait être parfaite pour\n"
    .string "un duo comme vous.$"

GoldenrodDeptStore_Text_5FReceptionistItLooksEvilHowAboutThisTM:
    .string "Ça a l'air méchant. Et cette CT\n"
    .string "pour lui ?$"

GoldenrodDeptStore_Text_5FReceptionistThereAreTMsPerfectForMon:
    .string "Il y a sûrement des CT parfaites\n"
    .string "pour tes POKéMON.$"

GoldenrodDeptStore_Text_5FLass:
    .string "Pendant la journée, une dame vient voir les\n"
    .string "POKéMON.\p"
    .string "Elle donne même des CT !$"

GoldenrodDeptStore_Text_5FPokefanM:
    .string "Tu ne peux pas renommer\n"
    .string "un POKéMON reçu en échange.\p"
    .string "Le nom reflète les sentiments\n"
    .string "du DRESSEUR d'origine pour lui.$"

GoldenrodDeptStore_Text_Girl:
	.string "La dame m'a donné RETOUR !\n"
	.string "Mon POKéMON doit vraiment m'aimer !$"

GoldenrodDeptStore_Text_5FDirectory:
    .string "Personnalise tes POKéMON\p"
    .string "5e COIN CT$"
