PokemonLeague_KogasRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EliteFourRoom_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, PokemonLeague_KogasRoom_OnResume
	map_script MAP_SCRIPT_ON_LOAD, EliteFourRoom_OnLoad
	.byte 0

PokemonLeague_KogasRoom_OnResume::
	setvar VAR_0x8004, 1
	special DoPokemonLeagueLightingEffect
	end

PokemonLeague_KogasRoom_EventScript_Koga::
	lock 
	faceplayer
	goto_if_ge VAR_LEAGUE_STATE, 3, PokemonLeague_KogasRoom_EventScript_KogaDefeated
	goto_if_set FLAG_IS_CHAMPION, PokemonLeague_KogasRoom_EventScript_KogaRematch
	msgbox PokemonLeague_KogasRoom_Text_Before, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_KOGA_1, PokemonLeague_KogasRoom_Text_Beaten
	goto PokemonLeague_KogasRoom_EventScript_KogaOnDefeat

PokemonLeague_KogasRoom_EventScript_KogaRematch::
	msgbox PokemonLeague_KogasRoom_Text_RematchBefore, MSGBOX_DEFAULT
	setflag FLAG_TEMP_3
	setflag FLAG_TEMP_5
	trainerbattle_no_intro TRAINER_KOGA_2, PokemonLeague_KogasRoom_Text_Beaten
	goto PokemonLeague_KogasRoom_EventScript_KogaOnDefeat

PokemonLeague_KogasRoom_EventScript_KogaOnDefeat::
	clearflag FLAG_TEMP_5
	msgbox PokemonLeague_KogasRoom_Text_Defeat, MSGBOX_DEFAULT
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
	setvar VAR_LEAGUE_STATE, 3
	release
	end

PokemonLeague_KogasRoom_EventScript_KogaDefeated::
	msgbox PokemonLeague_KogasRoom_Text_Defeat, MSGBOX_DEFAULT
	closemessage
	release
	end

PokemonLeague_KogasRoom_Text_RematchBefore:
    .string "KOGA : Fwahahahaha ! Tu\p"
    .string "reviens, brave challenger. Mes compétences\p"
    .string "ninja se sont affûtées. De\p"
    .string "nouveaux pièges sinistres t'attendent.\p"
    .string "Poison, sommeil, et plus\n"
    .string "encore… Sois prêt !\p"
    .string "Fwahahahaha ! Montre-moi comment\p"
    .string "tu as grandi !$"

PokemonLeague_KogasRoom_Text_Before:
    .string "Fwahahahaha !\p"
    .string "Je suis KOGA du\p"
    .string "CONSEIL DES 4.\p"
    .string "Je vis dans\n"
    .string "l'ombre,\p"
    .string "un ninja !\p"
    .string "Mon style\n"
    .string "complexe\p"
    .string "va te\p"
    .string "confondre !\n"
    .string "Prépare-toi !$"

PokemonLeague_KogasRoom_Text_Beaten:
    .string "Ah !\n"
    .string "Tu as prouvé ta valeur !$"

PokemonLeague_KogasRoom_Text_Defeat:
    .string "Je t'ai soumis tout ce que\n"
    .string "je pouvais.\p"
    .string "Mais mes efforts ont échoué. Je dois\n"
    .string "affûter mes compétences.\p"
    .string "Passe à la salle suivante et mets\n"
    .string "tes capacités à l'épreuve !$"
