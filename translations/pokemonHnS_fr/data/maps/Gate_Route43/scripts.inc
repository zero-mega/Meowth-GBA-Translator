Gate_Route43_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Gate_Route43_Rocket_OnFrame
	.byte 0

Gate_Route43_Rocket_OnFrame::
	map_script_2 VAR_TEMP_0, 0, Gate_Route43_RocketChecker
	.2byte 0

Gate_Route43_RocketChecker::
	setvar VAR_TEMP_0, 1
	goto_if_eq VAR_MAHOGANY_TOWN_STATE, 1, Gate_Route43_Rocket_EventScript_Shakedown
	goto_if_eq VAR_MAHOGANY_TOWN_STATE, 2, Gate_Route43_Rocket_EventScript_Shakedown
	goto_if_eq VAR_MAHOGANY_TOWN_STATE, 3, Gate_Route43_Rocket_EventScript_Shakedown
	goto_if_eq VAR_MAHOGANY_TOWN_STATE, 4, Gate_Route43_Rocket_EventScript_Shakedown
	goto_if_eq VAR_MAHOGANY_TOWN_STATE, 5, Gate_Route43_Rocket_EventScript_Shakedown
	end

Gate_Route43_Rocket_EventScript_Shakedown::
	lock
	showmoneybox 0, 0
	msgbox Gate_Route43_Rocket_Text_TollFee, MSGBOX_DEFAULT
	checkmoney 500
	goto_if_eq VAR_RESULT, FALSE, Gate_Route43_Rocket_EventScript_ShakedownBroke
	removemoney 500
	playse SE_SHOP
	updatemoneybox
	msgbox Gate_Route43_Rocket_Text_ThankYou, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Gate_Route43_Rocket_EventScript_ShakedownBroke::
	checkmoney 1
	goto_if_eq VAR_RESULT, FALSE, Gate_Route43_Rocket_EventScript_KickOut
	msgbox Gate_Route43_Rocket_Text_AllYouGot, MSGBOX_DEFAULT
	removemoney 500
	playse SE_SHOP
	updatemoneybox
	msgbox Gate_Route43_Rocket_Text_ThankYou, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Gate_Route43_Rocket_EventScript_KickOut::
	msgbox Gate_Route43_Rocket_Text_KickOut, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	release
	end

Gate_Route43_Rocket_EventScript_Policeman::
	lock
	faceplayer
	goto_if_set FLAG_GOT_TM_FROM_MAHOGANY_COP, Gate_Route43_Rocket_EventScript_PolicemanAfter
	msgbox Route43Gate_Text_OfficerFoundTM, MSGBOX_DEFAULT
	giveitem ITEM_TM_SLUDGE_BOMB
	setflag FLAG_GOT_TM_FROM_MAHOGANY_COP
	closemessage
	release
	end

Gate_Route43_Rocket_EventScript_PolicemanAfter::
	msgbox Gate_Route43_Text_OfficerAvoidGrass, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_Route43_Rocket_EventScript_Rockets::
	msgbox Gate_Route43_Rocket_Text_MakingABundle, MSGBOX_NPC
	end

Gate_Route43_Rocket_Text_TollFee:
    .string "Halte là, gamin !\p"
    .string "Le péage est de 500¥ pour\n"
    .string "passer.$"

Gate_Route43_Rocket_Text_ThankYou:
    .string "Merci beaucoup !$"

Gate_Route43_Rocket_Text_AllYouGot:
    .string "Alors paie ce que tu as, s'il te plaît.$"

Gate_Route43_Rocket_Text_KickOut:
	.string "Waouh ! Tu es complètement\p"
	.string "fauché ! J'ai presque pitié\p"
	.string "de toi. OK, tu\p"
	.string "peux passer… Mais ne\p"
	.string "le dis pas à\n"
	.string "l'autre garde, OK ?$"

Gate_Route43_Rocket_Text_MakingABundle:
    .string "Héhéhé. On fait des affaires.\p"
    .string "Tout le monde veut voir ce qui se passe au\n"
    .string "LAC COLÈRE.$"

Route43Gate_Text_OfficerFoundTM:
    .string "J'ai été chassé de mon poste par des\n"
    .string "voyous en noir.\p"
    .string "Ils ont laissé ça derrière eux.\p"
    .string "Ça me met mal à l'aise. Tu pourrais\n"
    .string "l'emporter ?$"

Gate_Route43_Text_ReceivedTM30:
    .string "{PLAYER} a reçu CT36.$"

Gate_Route43_Text_OfficerAvoidGrass:
    .string "Utilise cette porte pour éviter\n"
    .string "de marcher dans l'herbe.$"
