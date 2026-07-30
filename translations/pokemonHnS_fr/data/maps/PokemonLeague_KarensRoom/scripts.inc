PokemonLeague_KarensRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EliteFourRoom_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, PokemonLeague_KarensRoom_OnResume
	map_script MAP_SCRIPT_ON_LOAD, EliteFourRoom_OnLoad
	.byte 0

PokemonLeague_KarensRoom_OnResume::
	setvar VAR_0x8004, 3
	special DoPokemonLeagueLightingEffect
	end

PokemonLeague_KarensRoom_EventScript_Karen::
	lock 
	faceplayer
	goto_if_ge VAR_LEAGUE_STATE, 5, PokemonLeague_KarensRoom_EventScript_KarenDefeated
	goto_if_set FLAG_IS_CHAMPION, PokemonLeague_KarensRoom_EventScript_KarenRematch
	msgbox PokemonLeague_KarensRoom_Text_Before, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_KAREN_1, PokemonLeague_KarensRoom_Text_Beaten
	goto PokemonLeague_KarensRoom_EventScript_KarenOnDefeat

PokemonLeague_KarensRoom_EventScript_KarenRematch::
	msgbox PokemonLeague_KarensRoom_Text_RematchBefore, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_KAREN_2, PokemonLeague_KarensRoom_Text_Beaten
	goto PokemonLeague_KarensRoom_EventScript_KarenOnDefeat

PokemonLeague_KarensRoom_EventScript_KarenOnDefeat::
    clearflag FLAG_TEMP_5
	msgbox PokemonLeague_KarensRoom_Text_Defeat, MSGBOX_DEFAULT
	closemessage
	setmetatile 6, 1, 0x28E, FALSE
	setmetatile 6, 2, 0x296, FALSE	
	playse SE_BANG
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 4  @ num shakes
	setvar VAR_0x8007, 4  @ shake delay
	special ShakeCamera
	waitstate
	special DrawWholeMapView
	setvar VAR_LEAGUE_STATE, 5
	release
	end

PokemonLeague_KarensRoom_EventScript_KarenDefeated::
	msgbox PokemonLeague_KarensRoom_Text_Defeat, MSGBOX_DEFAULT
	closemessage
	release
	end

PokemonLeague_KarensRoom_Text_RematchBefore:
    .string "KAREN: Ah, it's you again.\p"
    .string "I trust you haven't forgotten\n"
    .string "my belief:\p"
    .string "True strength arises from trust\n"
    .string "in one's POKéMON.\p"
    .string "Since our last encounter, my\n"
    .string "bond with my POKéMON has\l"
    .string "deepened further.\p"
    .string "Are you ready to face a team\n"
    .string "united by an unbreakable bond?\p"
    .string "Show me the power of the bond\n"
    .string "with your POKéMON.$"

PokemonLeague_KarensRoom_Text_Before:
    .string "Je suis MELINE du CONSEIL\p"
    .string "DES 4. Tu es {PLAYER}\p"
    .string "? Amusant. J'adore les POKéMON\p"
    .string "TÉNÈBRES. Je trouve leur image\n"
    .string "sauvage et robuste si\l"
    .string "attrayante. Et ils sont\p"
    .string "si forts. Tu crois\n"
    .string "pouvoir les affronter ?\p"
    .string "Essaie de m'amuser. Allons-y.$"

PokemonLeague_KarensRoom_Text_Beaten:
    .string "Eh bien, tu es bon. J'aime ça\n"
    .string "chez un DRESSEUR.$"

PokemonLeague_KarensRoom_Text_Defeat:
    .string "POKéMON forts. POKéMON faibles.\p"
    .string "Ce n'est que la\p"
    .string "perception égoïste des gens.\n"
    .string "Les DRESSEURS vraiment habiles\p"
    .string "devraient essayer de gagner\n"
    .string "avec leurs favoris. J'aime\p"
    .string "ton style. Tu comprends\n"
    .string "ce qui est important.\p"
    .string "Vas-y--le CHAMPION t'attend.$"

