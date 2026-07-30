SlateportCity_PokemonFanClub_MapScripts::
	.byte 0

SlateportCity_PokemonFanClub_EventScript_Chairman::
	lock
	faceplayer
	goto_if_unset FLAG_ENTERED_CONTEST, SlateportCity_PokemonFanClub_EventScript_ChairmanNotEnteredContest
	call_if_unset FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN, SlateportCity_PokemonFanClub_EventScript_MeetChairman
	switch VAR_SLATEPORT_FAN_CLUB_STATE
	case 0, SlateportCity_PokemonFanClub_EventScript_ChairmanFirstAssessment
	case 1, SlateportCity_PokemonFanClub_EventScript_ChairmanTryAssessPokemon
	case 2, SlateportCity_PokemonFanClub_EventScript_NoMoreScarves
	release
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanFirstAssessment::
	setvar VAR_SLATEPORT_FAN_CLUB_STATE, 1
	msgbox SlateportCity_PokemonFanClub_Text_AllowMeToExamineYourPokemon, MSGBOX_DEFAULT
	goto SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanTryAssessPokemon::
	setvar VAR_TEMP_2, 0
	call_if_set FLAG_RECEIVED_YELLOW_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_GREEN_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_PINK_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_BLUE_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_set FLAG_RECEIVED_RED_SCARF, SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf
	call_if_eq VAR_TEMP_2, CONTEST_CATEGORIES_COUNT, SlateportCity_PokemonFanClub_EventScript_ReceivedAllScarves
	goto_if_eq VAR_SLATEPORT_FAN_CLUB_STATE, 2, SlateportCity_PokemonFanClub_EventScript_NoMoreScarves
	msgbox SlateportCity_PokemonFanClub_Text_HowIsYourPokemonGrowing, MSGBOX_DEFAULT
	goto SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon
	end

SlateportCity_PokemonFanClub_EventScript_NoMoreScarves::
	msgbox SlateportCity_PokemonFanClub_Text_NothingElseToGiveYou, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanAssessLeadMon::
	msgbox SlateportCity_PokemonFanClub_Text_HmHmISee, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, 0
	call_if_unset FLAG_RECEIVED_YELLOW_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonTough
	call_if_unset FLAG_RECEIVED_GREEN_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonSmart
	call_if_unset FLAG_RECEIVED_PINK_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonCute
	call_if_unset FLAG_RECEIVED_BLUE_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonBeauty
	call_if_unset FLAG_RECEIVED_RED_SCARF, SlateportCity_PokemonFanClub_EventScript_CheckMonCool
	bufferleadmonspeciesname STR_VAR_1
	switch VAR_TEMP_1
	case 0, SlateportCity_PokemonFanClub_EventScript_NoHighConditions
	case 1, SlateportCity_PokemonFanClub_EventScript_GiveRedScarf
	case 2, SlateportCity_PokemonFanClub_EventScript_GiveBlueScarf
	case 3, SlateportCity_PokemonFanClub_EventScript_GivePinkScarf
	case 4, SlateportCity_PokemonFanClub_EventScript_GiveGreenScarf
	case 5, SlateportCity_PokemonFanClub_EventScript_GiveYellowScarf
	release
	end

SlateportCity_PokemonFanClub_EventScript_ReceivedAllScarves::
	setvar VAR_SLATEPORT_FAN_CLUB_STATE, 2
	return

SlateportCity_PokemonFanClub_EventScript_CountReceivedScarf::
	addvar VAR_TEMP_2, 1
	return

SlateportCity_PokemonFanClub_EventScript_NoHighConditions::
	msgbox SlateportCity_PokemonFanClub_Text_GiveMonMorePokeblocks, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveRedScarf::
	checkitemspace ITEM_RED_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_RED_SCARF
	giveitem ITEM_RED_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainRedScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveBlueScarf::
	checkitemspace ITEM_BLUE_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_BLUE_SCARF
	giveitem ITEM_BLUE_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainBlueScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GivePinkScarf::
	checkitemspace ITEM_PINK_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_PINK_SCARF
	giveitem ITEM_PINK_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainPinkScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveGreenScarf::
	checkitemspace ITEM_GREEN_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_GREEN_SCARF
	giveitem ITEM_GREEN_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainGreenScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveYellowScarf::
	checkitemspace ITEM_YELLOW_SCARF
	goto_if_eq VAR_RESULT, FALSE, SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf
	msgbox SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_YELLOW_SCARF
	giveitem ITEM_YELLOW_SCARF
	msgbox SlateportCity_PokemonFanClub_Text_ExplainYellowScarf, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_NoRoomForScarf::
	msgbox SlateportCity_PokemonFanClub_Text_NoSpaceForReward, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_CheckMonCool::
	specialvar VAR_RESULT, CheckLeadMonCool
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonCool
	return

SlateportCity_PokemonFanClub_EventScript_SetMonCool::
	setvar VAR_TEMP_1, 1
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonBeauty::
	specialvar VAR_RESULT, CheckLeadMonBeauty
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonBeauty
	return

SlateportCity_PokemonFanClub_EventScript_SetMonBeauty::
	setvar VAR_TEMP_1, 2
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonCute::
	specialvar VAR_RESULT, CheckLeadMonCute
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonCute
	return

SlateportCity_PokemonFanClub_EventScript_SetMonCute::
	setvar VAR_TEMP_1, 3
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonSmart::
	specialvar VAR_RESULT, CheckLeadMonSmart
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonSmart
	return

SlateportCity_PokemonFanClub_EventScript_SetMonSmart::
	setvar VAR_TEMP_1, 4
	return

SlateportCity_PokemonFanClub_EventScript_CheckMonTough::
	specialvar VAR_RESULT, CheckLeadMonTough
	call_if_eq VAR_RESULT, TRUE, SlateportCity_PokemonFanClub_EventScript_SetMonTough
	return

SlateportCity_PokemonFanClub_EventScript_SetMonTough::
	setvar VAR_TEMP_1, 5
	return

SlateportCity_PokemonFanClub_EventScript_ChairmanNotEnteredContest::
	goto_if_set FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN, SlateportCity_PokemonFanClub_EventScript_ChairmanEnterContest
	msgbox SlateportCity_PokemonFanClub_Text_MeetChairman, MSGBOX_DEFAULT
	setflag FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN
	release
	end

SlateportCity_PokemonFanClub_EventScript_ChairmanEnterContest::
	msgbox SlateportCity_PokemonFanClub_Text_LikeToSeeEnteredContestPokemon, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_MeetChairman::
	msgbox SlateportCity_PokemonFanClub_Text_MeetChairman, MSGBOX_DEFAULT
	setflag FLAG_MET_SLATEPORT_FANCLUB_CHAIRMAN
	return

SlateportCity_PokemonFanClub_EventScript_SootheBellWoman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SOOTHE_BELL, SlateportCity_PokemonFanClub_EventScript_ReceivedSootheBell
	msgbox SlateportCity_PokemonFanClub_Text_ShowMePokemonThatLoveYou, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_150_TO_199, SlateportCity_PokemonFanClub_EventScript_GiveSootheBell
	release
	end

SlateportCity_PokemonFanClub_EventScript_GiveSootheBell::
	playse SE_PIN
	applymovement VAR_LAST_TALKED, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_LAST_TALKED, Common_Movement_Delay48
	waitmovement 0
	msgbox SlateportCity_PokemonFanClub_Text_PokemonAdoresYou, MSGBOX_DEFAULT
	giveitem ITEM_SOOTHE_BELL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_SOOTHE_BELL
	release
	end

SlateportCity_PokemonFanClub_EventScript_ReceivedSootheBell::
	msgbox SlateportCity_PokemonFanClub_Text_TreatPokemonWithLove, MSGBOX_DEFAULT
	release
	end

SlateportCity_PokemonFanClub_EventScript_Man::
	msgbox SlateportCity_PokemonFanClub_Text_PokemonDontLikeFainting, MSGBOX_NPC
	end

SlateportCity_PokemonFanClub_EventScript_Twin::
	msgbox SlateportCity_PokemonFanClub_Text_MonEnjoyedProtein, MSGBOX_NPC
	end

SlateportCity_PokemonFanClub_EventScript_Skitty::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SKITTY, CRY_MODE_NORMAL
	msgbox SlateportCity_PokemonFanClub_Text_Skitty, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SlateportCity_PokemonFanClub_EventScript_Zigzagoon::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ZIGZAGOON, CRY_MODE_NORMAL
	msgbox SlateportCity_PokemonFanClub_Text_Zigzagoon, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SlateportCity_PokemonFanClub_EventScript_Azumarill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZUMARILL, CRY_MODE_NORMAL
	msgbox SlateportCity_PokemonFanClub_Text_Azumarill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

SlateportCity_PokemonFanClub_Text_MeetChairman:
	.string "Euh-hém ! Je suis le PRÉSIDENT du\n"
	.string "FAN CLUB POKéMON !\p"
	.string "En tant que PRÉSIDENT, je suis naturellement\n"
	.string "le plus important !\p"
	.string "Personne ne peut me battre quand il s'agit\n"
	.string "d'élever des POKéMON. Personne !\p"
	.string "Eh bien, laisse-moi te parler des\n"
	.string "CONCOURS POKéMON.\p"
	.string "Ce sont des événements où on peut montrer\n"
	.string "ses POKéMON au monde entier !\p"
	.string "Cependant, ils se tiennent\n"
	.string "dans des villes lointaines,\p"
	.string "alors je ne peux pas y participer assez souvent.\n"
	.string "C'est pourquoi on se réunit ici pour montrer\l"
	.string "nos POKéMON, et voir ceux des autres.$"

SlateportCity_PokemonFanClub_Text_LikeToSeeEnteredContestPokemon:
	.string "Les POKéMON d'un DRESSEUR qui a\n"
	.string "participé à un CONCOURS POKéMON…\l"
	.string "Ça, j'aimerais voir.$"

SlateportCity_PokemonFanClub_Text_AllowMeToExamineYourPokemon:
	.string "Euh-hém ! Je vois que tu as participé à\n"
	.string "un CONCOURS POKéMON !\p"
	.string "S'il te plaît ! Permets-moi d'examiner\n"
	.string "comment tu as élevé tes POKéMON.\p"
	.string "Rien ne me réjouit plus que de voir des POKéMON\n"
	.string "élevés par d'autres DRESSEURS.\p"
	.string "Les expressions heureuses des POKéMON\n"
	.string "élevés avec les bons soins…\p"
	.string "Les yeux bienveillants du DRESSEUR qui\n"
	.string "a nourri et élevé le POKéMON…\p"
	.string "La simple pensée remplit mon coeur\n"
	.string "d'une joie débordante.\p"
	.string "Oh ! Je vous demande pardon !\n"
	.string "Pardonnez-moi de bavarder ainsi !\p"
	.string "S'il te plaît ! Permets-moi d'examiner\n"
	.string "à quel point ton POKéMON a grandi !$"

SlateportCity_PokemonFanClub_Text_HowIsYourPokemonGrowing:
	.string "Comment grandit ton POKéMON ?\n"
	.string "Laisse-moi l'examiner.$"

SlateportCity_PokemonFanClub_Text_HmHmISee:
	.string "Hm, hm…\n"
	.string "Je vois…$"

SlateportCity_PokemonFanClub_Text_GiveMonMorePokeblocks:
	.string "Hmmm… Ce n'est pas mal, mais ce n'est pas\n"
	.string "bon non plus…\p"
	.string "Toi, le DRESSEUR, tu dois mettre plus\n"
	.string "d'efforts à élever ce POKéMON !\p"
	.string "Par exemple, que dirais-tu de lui donner\n"
	.string "plus de {POKEBLOCK}S ?$"

SlateportCity_PokemonFanClub_Text_NoSpaceForReward:
	.string "Oh, mon…\p"
	.string "Ton POKéMON se développe très bien,\n"
	.string "tu mérites donc une récompense.\p"
	.string "Malheureusement, tu n'as pas de place pour\n"
	.string "ça dans ton SAC.$"

SlateportCity_PokemonFanClub_Text_MonMostImpressiveGiveItThis:
	.string "Ton {STR_VAR_1}, il grandit de façon\n"
	.string "très impressionnante !\l"
	.string "C'est un super spécimen !\p"
	.string "Mais ! Si tu lui donnais ceci,\n"
	.string "il grandirait encore mieux ! En effet !$"

SlateportCity_PokemonFanClub_Text_ExplainRedScarf:
	.string "Fais tenir ce FOULARD ROUGE à un POKéMON.\p"
	.string "Tout le monde reconnaîtra le sang-froid\n"
	.string "de ce POKéMON !$"

SlateportCity_PokemonFanClub_Text_ExplainBlueScarf:
	.string "Fais tenir ce FOULARD BLEU à un POKéMON.\p"
	.string "Sa beauté sera accentuée bien\n"
	.string "plus qu'actuellement !$"

SlateportCity_PokemonFanClub_Text_ExplainPinkScarf:
	.string "Fais tenir ce FOULARD ROSE à un POKéMON.\p"
	.string "Ça fera ressortir la gentillesse du\n"
	.string "POKéMON encore plus !$"

SlateportCity_PokemonFanClub_Text_ExplainGreenScarf:
	.string "Fais tenir ce FOULARD VERT à un POKéMON.\p"
	.string "Ça améliorera\n"
	.string "l'intelligence des POKéMON !$"

SlateportCity_PokemonFanClub_Text_ExplainYellowScarf:
	.string "Fais tenir ce FOULARD JAUNE à un POKéMON.\p"
	.string "Ça renforcera la robustesse de ton POKéMON\n"
	.string "encore plus !$"

SlateportCity_PokemonFanClub_Text_NothingElseToGiveYou:
	.string "Je suis désolé, mais je n'ai plus rien\n"
	.string "à te donner ! Rien du tout !\p"
	.string "Après tout, tu as le don d'élever\n"
	.string "des POKéMON sans recourir\l"
	.string "à aucun objet !$"

SlateportCity_PokemonFanClub_Text_ShowMePokemonThatLoveYou:
	.string "J'adore voir des POKéMON qui\n"
	.string "aiment leurs DRESSEURS.\p"
	.string "Les POKéMON sont très sensibles\n"
	.string "aux sentiments de leurs DRESSEURS.\p"
	.string "Si tu traites tes POKéMON avec\n"
	.string "amour et soin, ils t'aimeront en\p"
	.string "retour.\n"
	.string "Quand tes POKéMON t'aimeront, viens me les montrer.$"

SlateportCity_PokemonFanClub_Text_PokemonAdoresYou:
	.string "Ton POKéMON t'adore vraiment.\p"
	.string "Pour toi, DRESSEUR plein de compassion,\n"
	.string "un cadeau du FAN CLUB !$"

SlateportCity_PokemonFanClub_Text_TreatPokemonWithLove:
	.string "Les POKéMON sont très sensibles aux\n"
	.string "sentiments de leurs DRESSEURS.\p"
	.string "Si tu traites tes POKéMON avec amour\n"
	.string "et attention, ils t'aimeront en retour.$"

SlateportCity_PokemonFanClub_Text_PokemonDontLikeFainting:
	.string "Si tu laisses un POKéMON s'évanouir\n"
	.string "en combat, il finira par le détester.\p"
	.string "Bientôt, il te fera moins confiance\n"
	.string "en tant que DRESSEUR.\p"
	.string "En d'autres termes, il ne t'aimera\n"
	.string "certainement pas beaucoup.$"

SlateportCity_PokemonFanClub_Text_MonEnjoyedProtein:
	.string "Les POKéMON aiment qu'on utilise des objets\n"
	.string "sur eux ?\p"
	.string "Le mien avait l'air très content quand\n"
	.string "je lui ai donné de la PROTÉINE.$"

SlateportCity_PokemonFanClub_Text_Skitty:
	.string "SKITTY : Fffnyaaaah…$"

SlateportCity_PokemonFanClub_Text_Zigzagoon:
	.string "ZIGZAGOON : Kyuuu…$"

SlateportCity_PokemonFanClub_Text_Azumarill:
	.string "AZUMARILL : Marimari ?$"

