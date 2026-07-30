EverGrandeCity_PhoebesRoom_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_PhoebesRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_PhoebesRoom_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_PhoebesRoom_OnFrame
	.byte 0

EverGrandeCity_PhoebesRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_PhoebesRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_PhoebesRoom_EventScript_PlayerTurnNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

EverGrandeCity_PhoebesRoom_OnFrame:
	map_script_2 VAR_GARBAGEVAR, 1, EverGrandeCity_PhoebesRoom_EventScript_WalkInCloseDoor
	.2byte 0

EverGrandeCity_PhoebesRoom_EventScript_WalkInCloseDoor::
	lockall
	call PokemonLeague_EliteFour_EventScript_WalkInCloseDoor
	setvar VAR_GARBAGEVAR, 2
	releaseall
	end

EverGrandeCity_PhoebesRoom_OnLoad:
	call_if_set FLAG_DEFEATED_ELITE_4_KOGA, EverGrandeCity_PhoebesRoom_EventScript_ResetAdvanceToNextRoom
	call_if_eq VAR_GARBAGEVAR, 2, EverGrandeCity_PhoebesRoom_EventScript_CloseDoor
	end

EverGrandeCity_PhoebesRoom_EventScript_ResetAdvanceToNextRoom::
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
	return

EverGrandeCity_PhoebesRoom_EventScript_CloseDoor::
	call PokemonLeague_EliteFour_EventScript_CloseDoor
	return

EverGrandeCity_PhoebesRoom_EventScript_Phoebe::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ELITE_4_KOGA, EverGrandeCity_PhoebesRoom_EventScript_PostBattleSpeech
	goto_if_set FLAG_PHOEBE_REMATCH, EverGrandeCity_PhoebesRoom_EventScript_PhoebeRematch
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox EverGrandeCity_PhoebesRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_PHOEBE, EverGrandeCity_PhoebesRoom_Text_Defeat
	goto EverGrandeCity_PhoebesRoom_EventScript_Defeated
	end

EverGrandeCity_PhoebesRoom_EventScript_PhoebeRematch::
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox EverGrandeCity_PhoebesRoom_Text_IntroSpeech2, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_LUCY_BF_BRAIN, EverGrandeCity_PhoebesRoom_Text_Defeat2
	goto EverGrandeCity_PhoebesRoom_EventScript_Defeated
	end

EverGrandeCity_PhoebesRoom_EventScript_PostBattleSpeech::
	msgbox EverGrandeCity_PhoebesRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_PhoebesRoom_EventScript_Defeated::
	setflag FLAG_DEFEATED_ELITE_4_KOGA
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox EverGrandeCity_PhoebesRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_PhoebesRoom_Text_IntroSpeech:
	.string "Ahahaha !\p"
	.string "Je suis AGLAÉ du CONSEIL DES 4.\n"
	.string "Je me suis entraînée\p"
	.string "au MONT PYRE.\n"
	.string "Pendant mon\p"
	.string "entraînement, j'ai gagné\n"
	.string "la capacité de communiquer\p"
	.string "avec les esprits.\n"
	.string "Montre-moi ta force !$"

EverGrandeCity_PhoebesRoom_Text_IntroSpeech2:
	.string "Ahahaha ! C'est encore toi ! Je suis\p"
	.string "ATALIA du CONSEIL DES 4. Le lien\n"
	.string "que j'ai développé avec mes POKéMON est\l"
	.string "encore plus fort ! Essaie donc de\p"
	.string "voir si tu peux même infliger des\n"
	.string "dégâts à mes POKéMON. Car ce ne\p"
	.string "sera pas comme la dernière fois !$"

EverGrandeCity_PhoebesRoom_Text_Defeat:
	.string "Oh, zut.\n"
	.string "J'ai encore perdu.$"

EverGrandeCity_PhoebesRoom_Text_Defeat2:
	.string "Oh, zut…\n"
	.string "Encore une fois.$"

EverGrandeCity_PhoebesRoom_Text_PostBattleSpeech:
	.string "Il y a un lien certain\n"
	.string "entre toi et tes POKéMON aussi.\p"
	.string "Je ne l'ai pas reconnu,\n"
	.string "donc c'est naturel que j'aie\p"
	.string "perdu. Ouais, j'aimerais voir jusqu'où\n"
	.string "ton lien te mènera. Vas-y,\p"
	.string "passe à la salle suivante.$"

