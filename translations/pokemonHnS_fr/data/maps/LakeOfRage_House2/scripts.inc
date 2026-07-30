LakeOfRage_House2_MapScripts::
	.byte 0

LakeOfRage_House2_EventScript_Fisher::
	lock
	faceplayer
	goto_if_ge VAR_MAHOGANY_TOWN_STATE, 14, LakeOfRage_House2_EventScript_FisherAfterRockets
	goto_if_eq VAR_LAKE_OF_RAGE_FISHERMAN, 0, LakeOfRage_House2_EventScript_FisherFirstMeeting
	msgbox LakeOfRage_House2_Text_MenInBlack, MSGBOX_DEFAULT
	closemessage
	release
	end	

LakeOfRage_House2_EventScript_FisherFirstMeeting::
	msgbox LakeOfRage_House2_Text_LakeHistory, MSGBOX_DEFAULT
	msgbox LakeOfRage_House2_Text_MenInBlack, MSGBOX_DEFAULT
	setvar VAR_LAKE_OF_RAGE_FISHERMAN, 1
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherAfterRockets::
	goto_if_eq VAR_LAKE_OF_RAGE_FISHERMAN, 2, LakeOfRage_House2_EventScript_FisherAnotherMagikarp
	msgbox LakeOfRage_House2_Text_WorldsLargest, MSGBOX_DEFAULT
	msgbox LakeOfRage_House2_Text_ForMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_House2_EventScript_FisherNo
	getpartysize
	goto_if_eq VAR_RESULT, 1, LakeOfRage_House2_EventScript_LastMon
	special ChoosePartyMon
	waitstate
	lock
	showmoneybox 0, 0
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, LakeOfRage_House2_EventScript_FisherNoMoneyBox
	removegenericmon SPECIES_MAGIKARP
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_House2_EventScript_FisherNotMagikarp
	goto_if_eq VAR_RESULT, MON_SATISFACTORY, LakeOfRage_House2_EventScript_FisherSatisfied
	goto_if_eq VAR_RESULT, MON_UNSATISFACTORY, LakeOfRage_House2_EventScript_FisherSmallMagikarp

LakeOfRage_House2_EventScript_FisherNo::
	msgbox LakeOfRage_House2_Text_Refused, MSGBOX_DEFAULT
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherNoMoneyBox::
	msgbox LakeOfRage_House2_Text_Refused, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherNotMagikarp::
	msgbox LakeOfRage_House2_Text_NotMagikarp, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherSmallMagikarp::
	setvar VAR_LAKE_OF_RAGE_FISHERMAN, 2
	msgbox LakeOfRage_House2_Text_TooShort, MSGBOX_DEFAULT
	addmoney 2000
	updatemoneybox
	playse SE_SHOP
	waitse
	hidemoneybox
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherAnotherMagikarp::
	msgbox LakeOfRage_House2_Text_ForMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_House2_EventScript_FisherNo
	getpartysize
	goto_if_eq VAR_RESULT, 1, LakeOfRage_House2_EventScript_LastMon
	special ChoosePartyMon
	waitstate
	lock
	showmoneybox 0, 0
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, LakeOfRage_House2_EventScript_FisherNoMoneyBox
	removegenericmon SPECIES_MAGIKARP
	goto_if_eq VAR_RESULT, FALSE, LakeOfRage_House2_EventScript_FisherNotMagikarp
	goto_if_eq VAR_RESULT, MON_SATISFACTORY, LakeOfRage_House2_EventScript_FisherSatisfied
	goto_if_eq VAR_RESULT, MON_UNSATISFACTORY, LakeOfRage_House2_EventScript_FisherSmallMagikarp

LakeOfRage_House2_EventScript_LastMon::
	msgbox LakeOfRage_House2_Text_LastMon, MSGBOX_DEFAULT
	closemessage
	release
	end

LakeOfRage_House2_EventScript_FisherSatisfied::
	setvar VAR_LAKE_OF_RAGE_FISHERMAN, 2
	msgbox LakeOfRage_House2_Text_BigPayout, MSGBOX_DEFAULT
	addmoney 100000
	updatemoneybox
	playse SE_SHOP
	waitse
	hidemoneybox
	closemessage
	release
	end

LakeOfRage_House2_Text_LakeHistory:
    .string "Le LAC COLÈRE est\n"
    .string "en fait un cratère\p"
    .string "fait par un\n"
    .string "LÉVIATOR en furie.\p"
    .string "Le cratère s'est\n"
    .string "rempli d'eau de pluie\p"
    .string "et est devenu un lac.\n"
    .string "C'est une histoire\p"
    .string "tragique…$"

LakeOfRage_House2_Text_MenInBlack:
    .string "Le LAC n'a pas été normal depuis\n"
    .string "l'arrivée de ces hommes en noir.$"

LakeOfRage_House2_Text_LastMon:
    .string "Eh bien, ne me prends pas mon\n"
    .string "dernier POKéMON !$"

LakeOfRage_House2_Text_WorldsLargest:
    .string "Le LAC COLÈRE est revenu à la\p"
    .string "normale. Les MAGICARPE sont revenus. Je pourrais\p"
    .string "encore réaliser mon rêve d'avoir le plus\n"
    .string "grand MAGICARPE du monde. En fait… Je\p"
    .string "te paierai 2000 ¥ pour chaque MAGICARPE\n"
    .string "que tu me donnes, et 100 000\l"
    .string "¥ pour un ÉNORME MAGICARPE !$"

LakeOfRage_House2_Text_ForMe:
	.string "Alors… Tu as un MAGICARPE\n"
	.string "pour moi ?$"

LakeOfRage_House2_Text_HaveMagikarp:
    .string "Ah, tu as un MAGICARPE ! Voyons\n"
    .string "comme ce bébé est grand.$"

LakeOfRage_House2_Text_BigPayout:
    .string "Waouh ! Celui-ci est exceptionnel !\p"
    .string "Je te tire mon chapeau !\p"
    .string "Voici un petit quelque chose pour\n"
    .string "ton peine.$"

LakeOfRage_House2_Text_Bonus:
    .string "Le record est l'important.\p"
    .string "Considère ça comme un bonus !$"

LakeOfRage_House2_Text_TooShort:
    .string "Waouh ! Celui-ci est exceptionnel !\p"
    .string "…J'aimerais pouvoir le dire, mais j'en ai\n"
    .string "déjà vu un plus grand.\p"
    .string "Je suppose qu'il a quand même de la valeur.$"

LakeOfRage_House2_Text_NotMagikarp:
    .string "Quoi ? Ce n'est pas un MAGICARPE !$"

LakeOfRage_House2_Text_Refused:
    .string "Oh… Tu n'en as pas un assez bien\n"
    .string "pour me le montrer ? Peut-être la prochaine fois.$"
