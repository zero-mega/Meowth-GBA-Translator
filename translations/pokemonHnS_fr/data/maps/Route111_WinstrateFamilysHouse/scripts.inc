.set LOCALID_VIVI, 1
.set LOCALID_VICTOR, 2
.set LOCALID_VICTORIA, 3
.set LOCALID_VICKY, 4

Route111_WinstrateFamilysHouse_MapScripts::
	.byte 0

Route111_WinstrateFamilysHouse_EventScript_Victor::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_VICTOR
	msgbox Route111_WinstrateFamilysHouse_Text_MySonIsStrongerThanYou, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Victoria::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_VICTORIA
	goto_if_set FLAG_RECEIVED_MACHO_BRACE, Route111_WinstrateFamilysHouse_EventScript_ReceivedMachoBrace
	msgbox Route111_WinstrateFamilysHouse_Text_LikeYouToHaveMachoBrace, MSGBOX_DEFAULT
	giveitem ITEM_MACHO_BRACE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MACHO_BRACE
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_ReceivedMachoBrace::
	msgbox Route111_WinstrateFamilysHouse_Text_PassionateAboutBattles, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Vivi::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_VIVI
	msgbox Route111_WinstrateFamilysHouse_Text_StrongerFamilyMembers, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_Vicky::
	lock
	faceplayer
	setvar VAR_0x8008, LOCALID_VICKY
	goto_if_set FLAG_TEMP_4, Route111_WinstrateFamilysHouse_EventScript_AlreadySpokenTo
	msgbox Route111_WinstrateFamilysHouse_Text_GrandsonStrong, MSGBOX_DEFAULT
	setflag FLAG_TEMP_4
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_AlreadySpokenTo::
	msgbox Route111_WinstrateFamilysHouse_Text_GrandsonStrongShort, MSGBOX_DEFAULT
	goto Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection
	end

Route111_WinstrateFamilysHouse_EventScript_FaceOriginalDirection::
	closemessage
	applymovement VAR_0x8008, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

Route111_WinstrateFamilysHouse_Text_MySonIsStrongerThanYou:
	.string "Tu es le premier DRESSEUR que je\n"
	.string "vois déployer ses POKéMON avec autant de\p"
	.string "maîtrise. Mais je dois te dire… mon\n"
	.string "fils est plus fort que toi.\p"
	.string "Il a même relevé le défi\n"
	.string "de la LIGUE POKéMON, tu sais.$"

Route111_WinstrateFamilysHouse_Text_LikeYouToHaveMachoBrace:
	.string "On utilise cette CEINTURE PRO pour\n"
	.string "renforcer plus efficacement nos POKéMON à\l"
	.string "l'entraînement. Puisque tu nous as tous\p"
	.string "battus, je ne sais pas si\n"
	.string "tu en as besoin, mais on\l"
	.string "aimerait te donner notre CEINTURE PRO.$"

Route111_WinstrateFamilysHouse_Text_PassionateAboutBattles:
	.string "En matière de combats POKéMON,\n"
	.string "nous sommes plutôt passionnés.$"

Route111_WinstrateFamilysHouse_Text_StrongerFamilyMembers:
	.string "Maman est plus forte que Papa.\p"
	.string "Je suis plus fort que Maman.\p"
	.string "Et Mamie est plus forte que moi !\p"
	.string "Mais mon grand frère est encore plus fort\n"
	.string "que Mamie.$"

Route111_WinstrateFamilysHouse_Text_GrandsonStrong:
	.string "Il ne fait aucun\p"
	.string "doute que\n"
	.string "tu es fort.\p"
	.string "Mais si tu combattais\n"
	.string "mon petit-fils,\p"
	.string "tu finirais\n"
	.string "par pleurer.\p"
	.string "Il est encore plus\n"
	.string "fort que moi !$"

Route111_WinstrateFamilysHouse_Text_GrandsonStrongShort:
	.string "Mon petit-fils doit défier le\n"
	.string "MAÎTRE de la LIGUE POKéMON.\p"
	.string "Connaissant mon petit-fils, il est\n"
	.string "peut-être déjà MAÎTRE !$"

