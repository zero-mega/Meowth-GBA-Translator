EverGrandeCity_DrakesRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_DrakesRoom_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_DrakesRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_SidneysRoom_OnWarp
	.byte 0

@ Unused, Drake uses Sidneys identical OnWarp for some reason
EverGrandeCity_DrakesRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_DrakesRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_DrakesRoom_EventScript_PlayerTurnNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

EverGrandeCity_DrakesRoom_OnFrame:
	map_script_2 VAR_GARBAGEVAR, 3, EverGrandeCity_DrakesRoom_EventScript_WalkInCloseDoor
	.2byte 0

EverGrandeCity_DrakesRoom_EventScript_WalkInCloseDoor::
	lockall
	call PokemonLeague_EliteFour_EventScript_WalkInCloseDoor
	setvar VAR_GARBAGEVAR, 4
	releaseall
	end

EverGrandeCity_DrakesRoom_OnLoad:
	call_if_set FLAG_DEFEATED_ELITE_4_KAREN, EverGrandeCity_DrakesRoom_EventScript_ResetAdvanceToNextRoom
	call_if_eq VAR_GARBAGEVAR, 4, EverGrandeCity_DrakesRoom_EventScript_CloseDoor
	end

EverGrandeCity_DrakesRoom_EventScript_ResetAdvanceToNextRoom::
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
	return

EverGrandeCity_DrakesRoom_EventScript_CloseDoor::
	call PokemonLeague_EliteFour_EventScript_CloseDoor
	return

EverGrandeCity_DrakesRoom_EventScript_Drake::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ELITE_4_KAREN, EverGrandeCity_DrakesRoom_EventScript_PostBattleSpeech
	goto_if_set FLAG_DRAKE_REMATCH, EverGrandeCity_DrakesRoom_EventScript_DrakeRematch
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox EverGrandeCity_DrakesRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_KIP, EverGrandeCity_DrakesRoom_Text_Defeat
	goto EverGrandeCity_DrakesRoom_EventScript_Defeated
	end

EverGrandeCity_DrakesRoom_EventScript_DrakeRematch::
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox EverGrandeCity_DrakesRoom_Text_IntroSpeech2, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_KIP2, EverGrandeCity_DrakesRoom_Text_Defeat2
	goto EverGrandeCity_DrakesRoom_EventScript_Defeated
	end

EverGrandeCity_DrakesRoom_EventScript_PostBattleSpeech::
	msgbox EverGrandeCity_DrakesRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_DrakesRoom_EventScript_Defeated::
	setvar VAR_0x8004, FANCOUNTER_DEFEATED_DRAKE
	special Script_TryGainNewFanFromCounter
	setflag FLAG_DEFEATED_ELITE_4_KAREN
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox EverGrandeCity_DrakesRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_DrakesRoom_Text_IntroSpeech:
	.string "Je suis le dernier du CONSEIL DES 4\n"
	.string "de la LIGUE POKéMON, DRAGON le maître des dragons !\p"
	.string "Dans leur état naturel, les POKéMON sont\n"
	.string "des êtres vivants sauvages. Ils sont libres.\p"
	.string "Parfois, ils nous gênent.\n"
	.string "Parfois, ils nous aident.\p"
	.string "Pour que nous combattions avec les POKéMON en\n"
	.string "partenaires, sais-tu ce qu'il faut ?\p"
	.string "Sais-tu ce qui est nécessaire ?\p"
	.string "Si tu ne le sais pas, tu ne me\n"
	.string "battras jamais !$"

EverGrandeCity_DrakesRoom_Text_IntroSpeech2:
	.string "Je suis le dernier\n"
	.string "du CONSEIL DES 4\p"
	.string "de la LIGUE\n"
	.string "POKéMON, DRAGON\p"
	.string "le maître\p"
	.string "des dragons !\n"
	.string "Comment vont tes\p"
	.string "POKéMON partenaires ?\p"
	.string "Montre-moi votre lien !$"

EverGrandeCity_DrakesRoom_Text_Defeat:
	.string "Superbe, il faut le dire.$"

EverGrandeCity_DrakesRoom_Text_Defeat2:
	.string "Ha, ha, ha !\n"
	.string "Je ne peux pas m'empêcher de rire !\p"
	.string "Incroyable. Superbe.\n"
	.string "Tu es vraiment le meilleur.$"

EverGrandeCity_DrakesRoom_Text_PostBattleSpeech:
	.string "Tu mérites tout le\n"
	.string "crédit d'être arrivé\p"
	.string "si loin en tant que\p"
	.string "DRESSEUR de POKéMON.\n"
	.string "Tu sembles savoir\p"
	.string "ce qu'il faut.\n"
	.string "Oui, quelle force !\p"
	.string "Mais le chemin devant\n"
	.string "toi est encore long.\p"
	.string "Continue à\n"
	.string "t'entraîner !$"

