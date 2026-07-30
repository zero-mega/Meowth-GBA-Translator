.set LOCALID_WOMAN, 8
.set LOCALID_GRUNT_1, 10
.set LOCALID_GRUNT_2, 11
.set LOCALID_GRUNT_3, 12
.set LOCALID_GRUNT_4, 13
.set LOCALID_MAXIE, 14
.set LOCALID_SCOTT, 16
.set LOCALID_JIRACHI, 18

MossdeepCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MossdeepCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

MossdeepCity_OnTransition:
	callnative SetTimeBasedEncounters
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_1
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_2
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_3
	clearflag FLAG_MOSSDEEP_GYM_SWITCH_4
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	end

MossdeepCity_EventScript_Evo::
	msgbox MossdeepCity_EventScript_Evo_Text, MSGBOX_NPC
	end

MossdeepCity_EventScript_Evo_Text:
	.string "Le POKéMON ÉVOLI évolue\n"
	.string "de bien des façons.\p"
	.string "Avec une PIERRE FOUDRE, PIERRE FEU,\n"
	.string "PIERRE EAU… Comme, par exemple,\l"
	.string "ÉLEKTEK et MAGMAR.\p"
	.string "Eux aussi évoluent avec des PIERRES.$"

MossdeepCity_EventScript_Evo2::
	msgbox MossdeepCity_EventScript_Evo2_Text, MSGBOX_NPC
	end

MossdeepCity_EventScript_Evo2_Text:
	.string "My wife loves the POKéMON EEVEE.\p"
	.string "She knows all the ways they can\n"
	.string "evolve. Like, when HOLDING a WATER\l"
	.string "STONE, or a LEAF STONE.\p"
	.string "Yes, HOLDING, not using!\n"
	.string "Did you know about it? I didn't.\p"
	.string "Or being HAPPY during day or night.\p"
	.string "Or being cute whilst using a\n"
	.string "FAIRY TYPE move!\p"
	.string "…\p"
	.string "Do you know where EEVEE are?\n"
	.string "Maybe I should capture one for her.\p"
	.string "She's gonna love it!$"

MossdeepCity_EventScript_PokefanF::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_PokefanFMagmaGone
	msgbox MossdeepCity_Text_SpaceCenterReceivedLetter, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_PokefanFMagmaGone::
	msgbox MossdeepCity_Text_SpaceCenterLaunchingRockets, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_Sailor::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_DIVE, MossdeepCity_EventScript_SailorMagmaGone
	msgbox MossdeepCity_Text_MossdeepTargetedByMagma, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_SailorMagmaGone::
	msgbox MossdeepCity_Text_FeelReliefOnLand, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_NinjaBoy::
	msgbox MossdeepCity_Text_WailmerWatching, MSGBOX_NPC
	end

MossdeepCity_EventScript_ExpertM::
	msgbox MossdeepCity_Text_LifeNeedsSeaToLive, MSGBOX_NPC
	end

MossdeepCity_EventScript_Girl::
	msgbox MossdeepCity_Text_NiceIfWorldCoveredByFlowers, MSGBOX_NPC
	end

MossdeepCity_EventScript_Woman::
	goto_if_set FLAG_JIRACHI, MossdeepCity_EventScript_Woman2
	msgbox MossdeepCity_Text_SpecialSpaceCenterRock, MSGBOX_NPC
	end

MossdeepCity_EventScript_Woman2::
	msgbox MossdeepCity_Text_SpecialSpaceCenterRock2, MSGBOX_NPC
	end

MossdeepCity_EventScript_WhiteRock::
	msgbox MossdeepCity_Text_ItsAWhiteRock, MSGBOX_SIGN
	closemessage
	goto_if_set FLAG_JIRACHI, MossdeepCity_EventScript_WhiteRockEnd
	goto_if_unset FLAG_EXTRA_LEGENDARIES, MossdeepCity_EventScript_WhiteRockEnd
	goto_if_set FLAG_SYS_GAME_CLEAR, MossdeepCity_EventScript_Jirachi
	end

MossdeepCity_EventScript_WhiteRockEnd::
	end

MossdeepCity_EventScript_Jirachi::
	lockall
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_EventScript_JirachiMoves
	applymovement LOCALID_WOMAN, MossdeepCity_EventScript_JirachiMoves2
	waitmovement 0
	msgbox MossdeepCity_Text_ItsAWhiteRock2, MSGBOX_DEFAULT
	waitmessage
	waitse
	playmoncry SPECIES_JIRACHI, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_JIRACHI, 50
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	applymovement LOCALID_JIRACHI, MossdeepCity_EventScript_JirachiMoves3
	waitmovement 0
	msgbox MossdeepCity_Text_ItsAWhiteRock3, MSGBOX_DEFAULT
	closemessage
	special BattleSetup_StartLegendaryBattle
	waitstate
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, MossdeepCity_EventScript_JirachiWon
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, MossdeepCity_EventScript_JirachiWon
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, MossdeepCity_EventScript_JirachiRan
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, MossdeepCity_EventScript_JirachiRan
	release
	end

MossdeepCity_EventScript_JirachiWon::
	setflag FLAG_JIRACHI
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	callnative UpdateFollowingPokemon
	goto Common_EventScript_RemoveStaticPokemon
	releaseall
	end

MossdeepCity_EventScript_JirachiRan::
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	applymovement LOCALID_JIRACHI, MossdeepCity_EventScript_JirachiMoves4
	waitmovement 0
	releaseall
	end

MossdeepCity_EventScript_JirachiMoves:
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	jump_in_place_up
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

MossdeepCity_EventScript_JirachiMoves2:
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	jump_in_place_right
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

MossdeepCity_EventScript_JirachiMoves3:
	delay_16
	delay_16
	delay_16
	set_visible
	walk_down
	step_end

MossdeepCity_EventScript_JirachiMoves4:
	set_invisible
	walk_up
	step_end

MossdeepCity_Text_ItsAWhiteRock2:
	.string "Quelque chose…\p"
	.string "…\p"
	.string "Quelque chose bouge…\n"
	.string "…$"

MossdeepCity_Text_ItsAWhiteRock3:
	.string "Quelque chose t'a sauté dessus\n"
	.string "derrière le rocher blanc !$"

MossdeepCity_EventScript_GymSign::
	msgbox MossdeepCity_Text_GymSign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_CitySign::
	msgbox MossdeepCity_Text_CitySign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_SpaceCenterSign::
	msgbox MossdeepCity_Text_SpaceCenterSign, MSGBOX_SIGN
	end

MossdeepCity_EventScript_VisitedMossdeep::
	setflag FLAG_VISITED_CELADON_CITY
	setvar VAR_TEMP_1, 1
	end

MossdeepCity_EventScript_TeamMagmaEnterSpaceCenter::
	lockall
	applymovement LOCALID_MAXIE, MossdeepCity_Movement_MaxieGestureToSpaceCenter
	waitmovement 0
	applymovement LOCALID_GRUNT_1, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_GRUNT_2, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_GRUNT_3, MossdeepCity_Movement_GruntFaceSpaceCenter
	applymovement LOCALID_GRUNT_4, MossdeepCity_Movement_GruntFaceSpaceCenter
	waitmovement 0
	applymovement LOCALID_MAXIE, MossdeepCity_Movement_MaxieEnterSpaceCenter
	applymovement LOCALID_GRUNT_1, MossdeepCity_Movement_Grunt1EnterSpaceCenter
	applymovement LOCALID_GRUNT_2, MossdeepCity_Movement_Grunt2EnterSpaceCenter
	applymovement LOCALID_GRUNT_3, MossdeepCity_Movement_Grunt3EnterSpaceCenter
	applymovement LOCALID_GRUNT_4, MossdeepCity_Movement_Grunt4EnterSpaceCenter
	waitmovement 0
	removeobject LOCALID_MAXIE
	removeobject LOCALID_GRUNT_1
	removeobject LOCALID_GRUNT_2
	removeobject LOCALID_GRUNT_3
	removeobject LOCALID_GRUNT_4
	delay 30
	setvar VAR_GARBAGEVAR, 2
	setflag FLAG_GARBAGEFLAG
	releaseall
	end

MossdeepCity_Movement_MaxieGestureToSpaceCenter:
	delay_16
	face_right
	delay_16
	delay_16
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	step_end

MossdeepCity_Movement_GruntFaceSpaceCenter:
	face_right
	delay_16
	delay_16
	delay_16
	step_end

MossdeepCity_Movement_MaxieEnterSpaceCenter:
	walk_down
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt1EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt2EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt3EnterSpaceCenter:
	delay_16
	delay_8
	walk_down
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_Movement_Grunt4EnterSpaceCenter:
	delay_16
	delay_8
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

MossdeepCity_EventScript_Man::
	lock
	faceplayer
	msgbox MossdeepCity_Text_SurfExhilarating, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

MossdeepCity_EventScript_KingsRockBoy::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_KINGS_ROCK, MossdeepCity_EventScript_ReceivedKingsRock
	msgbox MossdeepCity_Text_WantKingsRockStevenGaveMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_EventScript_DeclineKingsRock
	msgbox MossdeepCity_Text_YouCanKeepIt, MSGBOX_DEFAULT
	giveitem ITEM_KINGS_ROCK
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_KINGS_ROCK
	release
	end

MossdeepCity_EventScript_ReceivedKingsRock::
	msgbox MossdeepCity_Text_StevensHouseOverThere, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_DeclineKingsRock::
	msgbox MossdeepCity_Text_WhatToDoWithWeirdRock, MSGBOX_DEFAULT
	release
	end

MossdeepCity_EventScript_BlackBelt::
	msgbox MossdeepCity_Text_SootopolisNewGymLeader, MSGBOX_NPC
	end

MossdeepCity_EventScript_Scott::
	lock
	faceplayer
	msgbox MossdeepCity_Text_ScottSomethingWrongWithTown, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, MossdeepCity_EventScript_ScottExitNorth
	call_if_eq VAR_FACING, DIR_EAST, MossdeepCity_EventScript_ScottExitEast
	addvar VAR_SCOTT_STATE, 1
	removeobject LOCALID_SCOTT
	release
	end

MossdeepCity_EventScript_ScottExitNorth::
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_SCOTT, MossdeepCity_Movement_ScottExitNorth
	waitmovement 0
	return

MossdeepCity_EventScript_ScottExitEast::
	applymovement OBJ_EVENT_ID_PLAYER, MossdeepCity_Movement_PlayerWatchScottExit
	applymovement LOCALID_SCOTT, MossdeepCity_Movement_ScottExitEast
	waitmovement 0
	return

MossdeepCity_Movement_PlayerWatchScottExit:
	delay_16
	delay_16
	walk_in_place_faster_left
	step_end

MossdeepCity_Movement_ScottExitNorth:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MossdeepCity_Movement_ScottExitEast:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

MossdeepCity_Text_WantKingsRockStevenGaveMe:
	.string "J'ai reçu ça de PIERRE, mais je\n"
	.string "ne sais pas à quoi ça\p"
	.string "sert. Je crois que c'est appelé\n"
	.string "ROCHER ROYAL. Tu le veux ?$"

MossdeepCity_Text_YouCanKeepIt:
	.string "Pourquoi tu le voudrais ?\n"
	.string "Tu es bizarre.\p"
	.string "Tu peux le garder, mais garde ça secret\n"
	.string "pour PIERRE.$"

MossdeepCity_Text_StevensHouseOverThere:
	.string "La maison de PIERRE est juste là !$"

MossdeepCity_Text_WhatToDoWithWeirdRock:
	.string "Ouais, tu trouves ça aussi ! Qu'est-ce qu'on est\n"
	.string "censé faire avec une pierre bizarre ?$"

MossdeepCity_Text_WailmerWatching:
	.string "Autour d'ALGATIA, on peut\n"
	.string "voir des WAILMER sauvages.\p"
	.string "C'est appelé, euh… Comment\n"
	.string "c'était déjà… WAI,\p"
	.string "WAI, WAI… Observation\p"
	.string "de WAILMER !$"

MossdeepCity_Text_SpaceCenterReceivedLetter:
	.string "Le CENTRE SPATIAL de l'île a lancé\n"
	.string "d'énormes fusées.\p"
	.string "Il y a eu une sorte d'agitation\n"
	.string "à propos d'une lettre reçue récemment.$"

MossdeepCity_Text_SpaceCenterLaunchingRockets:
	.string "Le CENTRE SPATIAL de l'île a lancé\n"
	.string "d'énormes fusées.$"

MossdeepCity_Text_MossdeepTargetedByMagma:
	.string "I heard from a SAILOR buddy that\n"
	.string "TEAM AQUA set up shop in LILYCOVE.\p"
	.string "I also heard that someone came along\n"
	.string "and wiped the floor with them!\p"
	.string "But MOSSDEEP here's been targeted\n"
	.string "by that TEAM MAGMA.\p"
	.string "If you want to know what they're up to,\n"
	.string "go visit the SPACE CENTER.$"

MossdeepCity_Text_FeelReliefOnLand:
	.string "Je suis MARIN, donc la mer est évidemment\n"
	.string "plus importante pour moi.\p"
	.string "Mais tu sais ? Quand je reviens sur terre\n"
	.string "après une longue traversée, je ressens du soulagement !$"

MossdeepCity_Text_NiceIfWorldCoveredByFlowers:
	.string "Ce ne serait pas chouette ?\p"
	.string "Si le monde entier était couvert de\n"
	.string "plantes et de fleurs comme cette île ?$"

MossdeepCity_Text_LifeNeedsSeaToLive:
	.string "Toute vie a besoin de la mer\n"
	.string "pour vivre, même si elle fait sa\p"
	.string "maison sur la terre. La vie,\n"
	.string "après son cours, devient sol et\p"
	.string "retourne à la terre. Et la\n"
	.string "mer est toujours liée à la\p"
	.string "terre. Oui, comme ce rivage même.$"

MossdeepCity_Text_SurfExhilarating:
	.string "Un voyage en bateau, c'est bien.\p"
	.string "Mais traverser la mer avec des POKéMON\n"
	.string "en utilisant SURF…\p"
	.string "C'est un voyage exaltant !\n"
	.string "Tu es d'accord, jeune homme ?$"

MossdeepCity_Text_SpecialSpaceCenterRock:
	.string "Cette roche a une\n"
	.string "signification spéciale pour\p"
	.string "les gens du CENTRE SPATIAL.\n"
	.string "Ils l'ont mise\p"
	.string "ici comme souhait\n"
	.string "pour des lancements\p"
	.string "réussis.\n"
	.string "Bonne chance à eux !$"

MossdeepCity_Text_SpecialSpaceCenterRock2:
	.string "Qu'est-ce que c'était ? Ce n'était pas mon voeu !$"

MossdeepCity_Text_ItsAWhiteRock:
	.string "C'est un rocher blanc.\p"
	.string "Il émane une énergie mystérieuse…$"

MossdeepCity_Text_GymSign:
	.string "ARÈNE POKéMON DE MOSSDEEP\n"
	.string "CHAMPIONS D'ARÈNE : LIZA ET TATE\p"
	.string "“La combinaison mystique !”$"

MossdeepCity_Text_CitySign:
	.string "ATALANOPOLIS\n"
	.string "“Notre devise : Chérissez les POKéMON !”$"

MossdeepCity_Text_SpaceCenterSign:
	.string "CENTRE SPATIAL ALGATIA\n"
	.string "“L'endroit le plus proche de l'espace.”$"

MossdeepCity_Text_ScottSomethingWrongWithTown:
	.string "SCOTT: {PLAYER}{KUN}, feeling good?\n"
	.string "I'm doing great!\p"
	.string "I'd heard MOSSDEEP's GYM LEADER is\n"
	.string "pretty strong, so I decided to come\l"
	.string "take a look-see for myself.\p"
	.string "But there's something wrong about\n"
	.string "this town.\p"
	.string "People are going on about a warning\n"
	.string "letter and the SPACE CENTER…\p"
	.string "I don't think it concerns me in any\n"
	.string "way, though.$"

MossdeepCity_Text_SootopolisNewGymLeader:
	.string "Ahh… C'est agréable de laisser les\n"
	.string "vagues laver mes pieds… En parlant\p"
	.string "des vagues, tu connais cette ville\n"
	.string "insulaire ATALANOPOLIS ? Je crois\p"
	.string "que l'ARÈNE là-bas a eu\n"
	.string "un nouveau CHAMPION. Les gens\p"
	.string "me disent que le nouveau\n"
	.string "CHAMPION a autrefois formé ALIZA.$"
