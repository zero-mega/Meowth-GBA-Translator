Route39_FarmHouse_MapScripts::
	.byte 0


Route39House_EventScript_FarmerF::
	lock
	faceplayer
	goto_if_eq VAR_ROUTE39_BARN, 5, Route39House_EventScript_FarmerFAfter
	msgbox Route39_Text_FarmerFInTrouble, MSGBOX_DEFAULT
	closemessage
	release
	end

Route39House_EventScript_FarmerFAfter::
	goto_if_set FLAG_GOT_TM_SNATCH, Route39House_EventScript_FarmerFAfterTM
	msgbox Route39_Text_FarmerFHealedMiltank, MSGBOX_DEFAULT
	giveitem ITEM_TM_SNATCH
	msgbox Route39_Text_FarmerFSnatchSpeech, MSGBOX_DEFAULT
	closemessage 
	setflag FLAG_GOT_TM_SNATCH
	release
	end

Route39House_EventScript_FarmerFAfterTM::
	msgbox Route39_Text_FarmerFSnatchSpeech, MSGBOX_DEFAULT
	closemessage
	release
	end

Route39_FarmHouse_EventScript_FarmerM::
	lock
	faceplayer
	goto_if_lt VAR_ROUTE39_BARN, 5, Route39_FarmHouse_EventScript_FarmerM_Sick
	showmoneybox 0, 0
	msgbox Route39_Text_FarmerMBuyMilk, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route39_FarmHouse_EventScript_FarmerMBuyMilk
	msgbox Route39_Text_FarmerMNoSale, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	end

Route39_FarmHouse_EventScript_FarmerMBuyMilk::
	checkmoney 500, 0
	goto_if_eq VAR_RESULT, FALSE, Route39_FarmHouse_EventScript_FarmerM_NotEnough
	additem ITEM_MOOMOO_MILK
	goto_if_eq VAR_RESULT, FALSE, Route39_FarmHouse_EventScript_FarmerM_BagFull
	removemoney 500
	updatemoneybox 0
	msgbox Route39FarmHouse_Text_WouldYouLikeAnother, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route39_FarmHouse_EventScript_FarmerMBuyMilk

	
	msgbox Route39_Text_FarmerMGotMilk, MSGBOX_DEFAULT
	closemessage
	playse MUS_OBTAIN_ITEM
	msgbox Route39_Text_GotMilk, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	release
	end

Route39_FarmHouse_EventScript_FarmerM_Sick::
	msgbox Route39_Text_FarmerMSickCow, MSGBOX_DEFAULT
	closemessage
	release
	end

Route39_FarmHouse_EventScript_FarmerM_BagFull::
	msgbox Route39_Text_FarmerMNoRoom, MSGBOX_DEFAULT
	hidemoneybox
	closemessage
	release
	end

Route39_FarmHouse_EventScript_FarmerM_NotEnough::
	msgbox Route39_Text_FarmerMNoMoney, MSGBOX_DEFAULT
	closemessage
	hidemoneybox
	release
	end

Route39_Text_FarmerMSickCow:
	.string "Mon ÉCUMUMU ne me donne plus\n"
	.string "de lait.\p"
	.string "Cette FERME a du lait réputé.\p"
	.string "Tout le monde en veut.\p"
	.string "Il me donnera plein de lait si\n"
	.string "je lui donne plein de BAIES,\l"
	.string "je crois.$"

Route39_Text_FarmerMBuyMilk:
	.string "Qu'est-ce que tu penses de mon LAIT MEUMEU ?\p"
	.string "C'est ma fierté, là.\p"
	.string "Donne-le aux POKéMON pour restaurer les PV !\p"
	.string "Je te le vends pour seulement\n"
	.string "500¥.$"

Route39_Text_FarmerMGotMilk:
	.string "Tiens !\n"
	.string "Bois et profite !$"

Route39_Text_FarmerMNoMoney:
	.string "Désolé.\n"
	.string "Pas d'argent, pas de vente !$"

Route39_Text_FarmerMNoRoom:
	.string "Je crois que ton SAC est plein.$"

Route39_Text_FarmerMNoSale:
	.string "Tu n'en veux pas ?\n"
	.string "Reviens, tu entends ?$"

Route39FarmHouse_Text_WouldYouLikeAnother:
	.string "Encore un ?$"

Route39_Text_GotMilk:
	.string "{PLAYER} a obtenu du LAIT MEUMEU.$"

Route39_Text_FarmerMMilking:
	.string "Je ferais mieux d'aller traire.$"

Route39_Text_FarmerFInTrouble:
	.string "Notre lait part même jusqu'à\n"
	.string "KANTO.\p"
	.string "Alors si notre MEUMEU ne nous donne\n"
	.string "pas de lait, on est dans le pétrin.$"

Route39_Text_FarmerFHealedMiltank:
	.string "Tu as soigné notre ÉCRÉMEUH, chéri.\n"
	.string "Maintenant elle donne du LAIT MEUMEU.\p"
	.string "Voilà quelque chose pour ta peine.$"

Route39_Text_FarmerFSnatchSpeech:
	.string "Ça, c'est SIPHON.\p"
	.string "C'est une capacité rusée qui\n"
	.string "permet à un POKéMON de voler\l"
	.string "la capacité d'un adversaire juste\p"
	.string "avant qu'elle soit utilisée.\n"
	.string "Si plusieurs POKéMON utilisent\l"
	.string "SIPHON, seul le plus lent finira\p"
	.string "par voler la capacité.\n"
	.string "Utilise-la intelligemment. Le timing est tout.$"
