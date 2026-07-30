GoldenrodCity_DepartmentStore_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodDeptElevator_OnFrame
	.byte 0

GoldenrodDeptStore2_EventScript_Youngster::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_2FYoungster, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore2_EventScript_CooltrainerF::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_2FCooltrainerF, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore2_EventScript_Gent::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_2FGentleman, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore2_EventScript_Sign::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_2FDirectory, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore_Text_2FYoungster:
    .string "Le POKéGEAR peut stocker jusqu'à 25 numéros\n"
    .string "de téléphone.\p"
    .string "C'est dur de décider lesquels\n"
    .string "garder.$"

GoldenrodDeptStore_Text_2FCooltrainerF:
    .string "J'ai eu mon ABRA au CASINO.\p"
    .string "Maintenant c'est mon meilleur partenaire.$"

GoldenrodDeptStore_Text_2FGentleman:
    .string "Ce GRAND MAGASIN me fait\n"
    .string "réaliser que DOUBLONVILLE est une\p"
    .string "grande ville. La sélection\n"
    .string "ici est inégalée ailleurs.$"

GoldenrodDeptStore_Text_2FDirectory:
    .string "Votre Compagnon de Voyage\p"
    .string "2F MARCHÉ DES DRESSEURS$"
