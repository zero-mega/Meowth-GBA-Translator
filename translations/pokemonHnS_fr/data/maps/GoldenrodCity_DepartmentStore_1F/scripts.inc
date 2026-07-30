GoldenrodCity_DepartmentStore_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodDeptElevator_OnFrame
	.byte 0

GoldenrodDeptStore1_EventScript_Receptionist::
	lock
	faceplayer
	msgbox GoldenrodDeptStor1_Text_Receptionist, MSGBOX_DEFAULT
	closemessage
	release
	end
GoldenrodDeptStore1_EventScript_Gentleman::
	lock
	faceplayer
	msgbox GoldenrodDeptStore1_Text_Gentleman, MSGBOX_DEFAULT
	closemessage
	release
	end
GoldenrodDeptStore1_EventScript_PokefanF::
	lock
	faceplayer
	msgbox GoldenrodDeptStore1_Text_PokefanF, MSGBOX_DEFAULT
	closemessage
	release
	end
GoldenrodDeptStore1_EventScript_BugCatcher::
	lock
	faceplayer
	msgbox GoldenrodDeptStore1_Text_BugCatcher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore1_EventScript_Directory::
	lock
	msgbox GoldenrodDeptStore1_Text_Directory, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodDeptStor1_Text_Receptionist:
    .string "Bienvenue au GRAND MAGASIN DE DOUBLONVILLE.$"

GoldenrodDeptStore1_Text_Gentleman:
    .string "Le GRAND MAGASIN a une bonne\n"
    .string "sélection.\p"
    .string "Mais certains objets ne sont disponibles\n"
    .string "qu'en prix de la SALLE DE JEUX.$"

GoldenrodDeptStore1_Text_PokefanF:
    .string "Je suis prête à faire du shopping aujourd'hui !$"

GoldenrodDeptStore1_Text_BugCatcher:
    .string "Maman est douée pour les bonnes affaires.\p"
    .string "Elle achète toujours des trucs\n"
    .string "à bas prix.$"

GoldenrodDeptStore1_Text_Directory:
    .string "RDC ACCUEIL\n"
    .string "VOUS ÊTES ICI.\p"
    .string "1ER MARCHÉ DES DRESSEURS\p"
    .string "2E COLLECTION DE COMBAT\p"
    .string "3E BOÎTE DE MÉDECINE\p"
    .string "4E COIN CT\p"
    .string "5E PLACE TRANQUILLE\p"
    .string "BELVÉDÈRE$"
