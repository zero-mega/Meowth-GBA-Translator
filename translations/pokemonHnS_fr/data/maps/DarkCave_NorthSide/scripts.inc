DarkCave_NorthSide_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DarkCave_NorthSide_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

DarkCave_NorthSide_OnTransition: 
	callnative SetTimeBasedEncounters
	end

DarkCave2_EventScript_Item_BlackFlute::
	finditem ITEM_BLACK_FLUTE
	end

DarkCave2_EventScript_Item_StarPiece::
	finditem ITEM_STAR_PIECE
	end

DarkCave2_EventScript_BlackGlasses::
	lock
	faceplayer
	goto_if_set FLAG_GOT_BLACK_GLASSES, DarkCave2_EventScript_BlackGlassesGot
	msgbox DarkCave2_Text_Nerd, MSGBOX_DEFAULT
	giveitem ITEM_BLACK_GLASSES
	setflag FLAG_GOT_BLACK_GLASSES
	closemessage
	release
	end

DarkCave2_EventScript_BlackGlassesGot::
	msgbox DarkCave2_Text_Nerd2, MSGBOX_DEFAULT
	closemessage
	release
	end

DarkCave2_Text_Nerd:
    .string "Waouh ! Tu m'as fait sursauter\p"
    .string "! J'avais mes LUNETTES NOIRES, alors\n"
    .string "je ne t'ai pas du tout\p"
    .string "remarqué. Qu'est-ce que je fais ici\p"
    .string "? Hé, ne t'inquiète pas pour\p"
    .string "ça. Je te donne une\n"
    .string "paire de LUNETTES NOIRES, alors\n"
    .string "oublie m'avoir vu, OK ?$"

DarkCave2_Text_Nerd2:
    .string "Les LUNET.NOIRES augmentent la puissance\n"
    .string "des capacités de type TÉNÈBRES.$"
