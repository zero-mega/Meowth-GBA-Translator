Route26_House2_MapScripts::
	.byte 0

Route26_House2_EventScript_Book::
	lock
	msgbox DayOfWeekSiblingsHouse_Text_Pokedex1, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE,Route26_House2_EventScript_BookRead
	closemessage
	release
	end

Route26_House2_EventScript_BookRead::
	msgbox DayOfWeekSiblingsHouse_Text_Pokedex2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route26_House2_EventScript_BookRead2
	closemessage
	release
	end
	
Route26_House2_EventScript_BookRead2::
	msgbox DayOfWeekSiblingsHouse_Text_Pokedex3, MSGBOX_DEFAULT
	closemessage
	release
	end

DayOfWeekSiblingsHouse_Text_Pokedex1:
    .string "Il y a quelque chose d'écrit ici.\p"
    .string "Le lire ?$"

DayOfWeekSiblingsHouse_Text_Pokedex2:
    .string "À mes frères et soeurs :\p"
    .string "Nous sommes fiers de servir les\n"
    .string "Dresseurs de POKéMON.\p"
    .string "Quand des Dresseurs vous parlent,\n"
    .string "donnez-leur quelque chose d'utile.\p"
    .string "Avec amour,\n"
    .string "MONICA\p"
    .string "Continuer à lire ?$"

DayOfWeekSiblingsHouse_Text_Pokedex3:
    .string "Lundi, MONICA\n"
    .string "ROUTE 40\p"
    .string "Mardi, TUSCANY\n"
    .string "ROUTE 29\p"
    .string "Mercredi, WESLEY\n"
    .string "LAC COLÈRE\p"
    .string "Jeudi,\n"
    .string "ARTHUR\p"
    .string "ROUTE\n"
    .string "36\p"
    .string "Vendredi,\n"
    .string "FRIEDA\p"
    .string "ROUTE\n"
    .string "35$"
