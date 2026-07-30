.set LOCALID_WALLYS_DAD, 1

PetalburgCity_WallysHouse_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PetalburgCity_WallysHouse_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, PetalburgCity_WallysHouse_OnWarp
	.byte 0

PetalburgCity_WallysHouse_OnWarp:
	map_script_2 VAR_GARBAGEVAR, 4, PetalburgCity_WallysHouse_EventScript_PlayerWallysDadFaceEachOther
	.2byte 0

PetalburgCity_WallysHouse_EventScript_PlayerWallysDadFaceEachOther::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	turnobject LOCALID_WALLYS_DAD, DIR_WEST
	end

PetalburgCity_WallysHouse_OnFrame:
	map_script_2 VAR_GARBAGEVAR, 4, PetalburgCity_WallysHouse_EventScript_GiveHMSurf
	.2byte 0

PetalburgCity_WallysHouse_EventScript_GiveHMSurf::
	lockall
	msgbox PetalburgCity_WallysHouse_Text_PleaseExcuseUs, MSGBOX_DEFAULT
	giveitem ITEM_HM_SURF
	setflag FLAG_RECEIVED_HM_SURF
	msgbox PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces, MSGBOX_DEFAULT
	setvar VAR_GARBAGEVAR, 5
	releaseall
	end

PetalburgCity_WallysHouse_EventScript_WallysDad::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad
	goto_if_set FLAG_RECEIVED_HM_SURF, PetalburgCity_WallysHouse_EventScript_ReceievedHMSurf
	goto_if_set FLAG_THANKED_FOR_PLAYING_WITH_WALLY, PetalburgCity_WallysHouse_EventScript_PlayedWithWally
	msgbox PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally, MSGBOX_DEFAULT
	setflag FLAG_THANKED_FOR_PLAYING_WITH_WALLY
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceievedHMSurf::
	msgbox PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_DefeatedWallyInVictoryRoad::
	msgbox PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_PlayedWithWally::
	msgbox PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_WallysMom::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_SURF, PetalburgCity_WallysHouse_EventScript_ReceivedHMSurf
	msgbox PetalburgCity_WallysHouse_Text_WallyWasReallyHappy, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_EventScript_ReceivedHMSurf::
	msgbox PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling, MSGBOX_DEFAULT
	release
	end

PetalburgCity_WallysHouse_Text_ThanksForPlayingWithWally:
	.string "Tu es…\n"
	.string "Ah, tu dois être\p"
	.string "{PLAYER}{KUN}, n'est-ce pas ?\n"
	.string "Merci d'avoir joué avec WALLY un peu plus tôt.\p"
	.string "Il est fragile et maladif depuis\n"
	.string "qu'il est bébé.\p"
	.string "Nous l'avons envoyé chez des parents\n"
	.string "à VERROVILLE pour qu'il\p"
	.string "respire l'air de la mer.\n"
	.string "Mais il est revenu seul, en disant\p"
	.string "qu'il voulait devenir DRESSEUR.\n"
	.string "Il a l'air si heureux depuis qu'il\p"
	.string "a un POKéMON.\n"
	.string "Merci encore, {PLAYER}{KUN}.$"

PetalburgCity_WallysHouse_Text_WonderHowWallyIsDoing:
	.string "Je me demande comment va notre WALLY ?$"

PetalburgCity_WallysHouse_Text_PleaseExcuseUs:
	.string "{PLAYER}{KUN} ! Excuse-nous de\n"
	.string "t'avoir traîné ici comme ça.\p"
	.string "Mais notre WALLY est devenu très en forme\n"
	.string "depuis qu'il est allé à VERROVILLE.\p"
	.string "On te doit tout !\p"
	.string "Quand WALLY a quitté la ville, tu l'as aidé\n"
	.string "à attraper un POKéMON, non ?\p"
	.string "Je pense que ça a vraiment rendu WALLY\n"
	.string "heureux.\p"
	.string "En fait, pas seulement WALLY.\n"
	.string "Ça m'a rendu heureux aussi, son père.\p"
	.string "Heureux qu'il ait un si grand\n"
	.string "ami comme toi.\p"
	.string "Ce n'est pas un pot-de-vin ou quoi que ce soit, mais\n"
	.string "j'aimerais vraiment que tu prennes ça.$"

PetalburgCity_WallysHouse_Text_SurfGoAllSortsOfPlaces:
	.string "Si ton POKéMON sait SURF, tu pourras\n"
	.string "aller dans toutes sortes d'endroits.$"

PetalburgCity_WallysHouse_Text_WallyIsComingHomeSoon:
	.string "WALLY rentre bientôt à la maison.\n"
	.string "J'ai hâte.$"

PetalburgCity_WallysHouse_Text_YouMetWallyInEverGrandeCity:
	.string "Oh ? Tu as rencontré ALAIN à\n"
	.string "ATELIER ILE ?\p"
	.string "Oh, {PLAYER}{KUN}, ne sois pas bête.\p"
	.string "Il ne pourrait pas aller si loin\n"
	.string "tout seul.\l"
	.string "Il est rentré chez lui.$"

PetalburgCity_WallysHouse_Text_WallyWasReallyHappy:
	.string "PETER était vraiment heureux quand il nous\n"
	.string "a dit qu'il avait attrapé un POKéMON.\p"
	.string "Ça faisait des lustres que je\n"
	.string "ne l'avais pas vu sourire ainsi.$"

PetalburgCity_WallysHouse_Text_WallyLeftWithoutTelling:
	.string "Je veux que tu gardes ça\n"
	.string "secret pour mon mari… Mais notre\p"
	.string "TIMMY a quitté VERCHALORS sans\n"
	.string "rien dire à personne. Tu\p"
	.string "sais, TIMMY est fragile, mais\n"
	.string "il est étonnamment déterminé. Je\p"
	.string "suis sûre qu'il reviendra sain\n"
	.string "et sauf un jour !$"

