PokemonLeague_BrunosRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EliteFourRoom_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, PokemonLeague_BrunosRoom_OnResume
	map_script MAP_SCRIPT_ON_LOAD, EliteFourRoom_OnLoad
	.byte 0

PokemonLeague_BrunosRoom_OnResume::
	setvar VAR_0x8004, 2
	special DoPokemonLeagueLightingEffect
	end

PokemonLeague_BrunosRoom_EventScript_Bruno::
	lock 
	faceplayer
	goto_if_ge VAR_LEAGUE_STATE, 4, PokemonLeague_BrunosRoom_EventScript_BrunoDefeated
	goto_if_set FLAG_IS_CHAMPION, PokemonLeague_BrunosRoom_EventScript_BrunoRematch
	msgbox PokemonLeague_BrunosRoom_Text_Before, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_BRUNO_1, PokemonLeague_BrunosRoom_Text_Beaten
	goto PokemonLeague_BrunosRoom_EventScript_BrunoOnDefeat

PokemonLeague_BrunosRoom_EventScript_BrunoRematch::
	msgbox PokemonLeague_BrunosRoom_Text_RematchBefore, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_BRUNO_2, PokemonLeague_BrunosRoom_Text_Beaten
	goto PokemonLeague_BrunosRoom_EventScript_BrunoOnDefeat

PokemonLeague_BrunosRoom_EventScript_BrunoOnDefeat::
	clearflag FLAG_TEMP_5	
	msgbox PokemonLeague_BrunosRoom_Text_Defeat, MSGBOX_DEFAULT
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
	setvar VAR_LEAGUE_STATE, 4
	release
	end

PokemonLeague_BrunosRoom_EventScript_BrunoDefeated::
	msgbox PokemonLeague_BrunosRoom_Text_Defeat, MSGBOX_DEFAULT
	closemessage
	release
	end

PokemonLeague_BrunosRoom_Text_RematchBefore:
    .string "ALDO : Content de te revoir, jeune\n"
    .string "guerrier.\p"
    .string "Grâce à un entraînement rigoureux,\n"
    .string "nous sommes devenus plus forts.\p"
    .string "Ma volonté de roc est encore plus\n"
    .string "ferme et inflexible.\p"
    .string "Es-tu prêt à relever un défi\n"
    .string "encore plus grand ?\p"
    .string "Montre-moi les fruits de ton\n"
    .string "entraînement.\p"
    .string "Hoo hah !$"

PokemonLeague_BrunosRoom_Text_Before:
    .string "Je suis ALDO du\p"
    .string "CONSEIL DES 4.\n"
    .string "Je m'entraîne toujours\p"
    .string "à l'extrême parce\p"
    .string "que je crois en\p"
    .string "notre potentiel.\n"
    .string "C'est ainsi que nous\p"
    .string "devenons forts.\n"
    .string "{PLAYER}, montre-moi\p"
    .string "ta force !$"

PokemonLeague_BrunosRoom_Text_Beaten:
    .string "Pourquoi ? Comment avons-nous pu perdre ?$"

PokemonLeague_BrunosRoom_Text_Defeat:
    .string "Ayant perdu, je n'ai pas le droit de\n"
    .string "dire quoi que ce soit…\p"
    .string "Affronte ton prochain défi !$"
