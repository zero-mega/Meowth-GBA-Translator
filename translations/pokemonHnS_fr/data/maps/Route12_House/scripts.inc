Route12_House_MapScripts::
	.byte 0

Route12_House_EventScript_SuperRod::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SUPER_ROD, Route12_House_EventScript_SuperRodGot
	msgbox Route12_House_Text_OfferSuperRod, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Route12_House_EventScript_SuperRodRefused
	msgbox Route12_House_Text_GiveSuperRod, MSGBOX_DEFAULT
	giveitem ITEM_SUPER_ROD
	msgbox Route12_House_Text_GaveSuperRod, MSGBOX_DEFAULT
	setflag FLAG_GOT_SUPER_ROD
	closemessage
	release
	end

Route12_House_EventScript_SuperRodRefused::
	msgbox Route12_House_Text_DontWantSuperRod, MSGBOX_DEFAULT
	closemessage
	release
	end

Route12_House_EventScript_SuperRodGot::
	msgbox Route12_House_Text_GaveSuperRod, MSGBOX_NPC
	release
	end

Route12_House_Text_OfferSuperRod:
	.string "Je suis le jeune frère du PÊCHEUR\n"
	.string "LÉGENDAIRE.\p"
	.string "Je vois que tu aimes la pêche.\p"
	.string "J'en suis absolument certain\n"
	.string "!\p"
	.string "Alors ? J'ai raison, non ?$"

Route12_House_Text_GiveSuperRod:
	.string "Oui, oui. Comme je le pensais !\p"
	.string "Tiens, fan de pêche ! Prends ça,\n"
	.string "c'est une SUPER CANNE.$"

Route12_House_Text_GaveSuperRod:
	.string "Essaie ta chance à la pêche\n"
	.string "partout où il y a de\p"
	.string "l'eau. Souviens-toi, tu peux attraper\n"
	.string "différents POKéMON avec différentes CANNES.$"

Route12_House_Text_DontWantSuperRod:
	.string "Hein ? Mes propres yeux m'ont trompé ?$"

