GoldenrodCity_DepartmentStore_4F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, GoldenrodDeptElevator_OnFrame
	.byte 0

GoldenrodDeptStore4_EventScript_Cooltrainer::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_4FCooltrainerM, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore4_EventScript_BugCatcher::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_4FBugCatcher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore4_EventScript_GBAKid::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_4FGameboyKid, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore4_EventScript_Sign::
	lock
	faceplayer
	msgbox GoldenrodDeptStore_Text_4FDirectory, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodDeptStore_Text_4FCooltrainerM:
    .string "Hé. J'adore les POKéMON forts.\p"
    .string "Je leur donne de la PROTEINE pour\n"
    .string "booster leur ATTAQUE.$"

GoldenrodDeptStore_Text_4FBugCatcher:
    .string "Le FER augmente la DÉFENSE\n"
    .string "de ton POKéMON.$"

GoldenrodDeptStore_Text_4FGameboyKid:
    .string "Il y avait des rumeurs selon lesquelles\n"
    .string "certains POKéMON n'évoluent qu'en\l"
    .string "étant échangés via un câble\l"
    .string "Game Link.\p"
    .string "Pfff…\p"
    .string "Fausses informations.\p"
    .string "Je connais certains des POKéMON\n"
    .string "dont on parle :\l"
    .string "MACHOPEUR, KADABRA, SPECTRE et,\l"
    .string "euh, GRAVELER,\l"
    .string "mais ils évoluent tous en\l"
    .string "montant de niveau.$"

GoldenrodDeptStore_Text_4FDirectory:
    .string "Boostez vos POKéMON !\p"
    .string "4E PHARMACIE$"
