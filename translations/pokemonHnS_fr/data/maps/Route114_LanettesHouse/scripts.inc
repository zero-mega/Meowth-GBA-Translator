Route114_LanettesHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route114_LanettesHouse_OnTransition
	.byte 0

Route114_LanettesHouse_OnTransition:
	setflag FLAG_LANDMARK_BillS_HOUSE
	end

Route114_LanettesHouse_EventScript_Bill::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_DOLL_Bill, Route114_LanettesHouse_EventScript_OfferAdvice
	setflag FLAG_SYS_PC_BILL
	msgbox Route114_LanettesHouse_Text_EverythingClutteredKeepThis, MSGBOX_DEFAULT
	givedecoration DECOR_LOTAD_DOLL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowNoRoomForDecor
	setflag FLAG_RECEIVED_DOLL_Bill
	release
	end

Route114_LanettesHouse_EventScript_OfferAdvice::
	msgbox Route114_LanettesHouse_Text_OrganizeYourBoxes, MSGBOX_DEFAULT
	release
	end

Route114_LanettesHouse_EventScript_Notebook::
	lockall
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage2
	msgbox Route114_LanettesHouse_Text_ClosedTheNotebook, MSGBOX_DEFAULT
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage2::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage2, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, Route114_LanettesHouse_EventScript_NotebookPage3
	releaseall
	end

Route114_LanettesHouse_EventScript_NotebookPage3::
	msgbox Route114_LanettesHouse_Text_ResearchNotesPage3, MSGBOX_DEFAULT
	return

Route114_LanettesHouse_EventScript_PC::
	msgbox Route114_LanettesHouse_Text_EmailFromBill, MSGBOX_SIGN
	end

Route114_LanettesHouse_Text_EverythingClutteredKeepThis:
	.string "BILL : Oh ! {PLAYER}{KUN} !\p"
	.string "Désolé que tout soit en désordre…\n"
	.string "Quand je me plonge dans la\l"
	.string "recherche, ça finit toujours comme\p"
	.string "ça… C'est embarrassant… Garde le\n"
	.string "secret en échange de ça.$"

Route114_LanettesHouse_Text_OrganizeYourBoxes:
	.string "Puis-je vous donner un conseil sur mon\n"
	.string "Système de Stockage POKéMON ?\p"
	.string "Vous devriez organiser vos BOÎTES pour\n"
	.string "savoir quels POKéMON s'y trouvent.$"

Route114_LanettesHouse_Text_ResearchNotesPage1:
	.string "Ce sont les notes de recherche de BILL.\n"
	.string "Il y a des informations sur les BOÎTES.\p"
	.string "Concevoir des BOÎTES pouvant contenir 30 POKéMON chacune.\p"
	.string "Chaque DRESSEUR devrait pouvoir stocker\n"
	.string "450 POKéMON sur le système PC.\p"
	.string "Continuer la lecture ?$"

Route114_LanettesHouse_Text_ResearchNotesPage2:
	.string "Un système de marquage devrait être ajouté\n"
	.string "pour organiser plus facilement les POKéMON.\p"
	.string "Le nom et le fond d'écran de chaque\n"
	.string "BOÎTE seront modifiables pour plaire\l"
	.string "aux POKéMON stockés.\p"
	.string "Continuer la lecture ?$"

Route114_LanettesHouse_Text_ResearchNotesPage3:
	.string "Quand tu stockes un\n"
	.string "POKéMON, il devrait être\p"
	.string "envoyé à la BOÎTE\n"
	.string "inspectée en dernier.\p"
	.string "Si cette BOÎTE est pleine, le récepteur\n"
	.string "cherchera une autre BOÎTE disponible.\l"
	.string "C'est pratique !$"

Route114_LanettesHouse_Text_ClosedTheNotebook:
	.string "{PLAYER} a fermé le carnet.$"

Route114_LanettesHouse_Text_EmailFromBill:
	.string "Il y a un e-mail de quelqu'un sur\n"
	.string "le PC.\p"
	.string "“… … … … … … …\p"
	.string "“Ton Système de Stockage offre plus\n"
	.string "de commodité que le mien.\p"
	.string "“Il a plein de fonctionnalités conviviales\n"
	.string "qui le rendent amusant et utile aussi.\p"
	.string "“Ça me rend fier d'avoir participé\n"
	.string "à son développement.\p"
	.string "“J'espère que tu continueras\n"
	.string "les recherches sur les Systèmes de Stockage.\p"
	.string "“De BILL\n"
	.string "… … … … … … … …”$"

