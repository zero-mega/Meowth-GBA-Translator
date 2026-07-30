Route117_PokemonDayCare_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route117_PokemonDayCare_OnTransition
	.byte 0

Route117_PokemonDayCare_OnTransition:
	setflag FLAG_LANDMARK_POKEMON_DAYCARE
	end

Route117_PokemonDayCare_Incense::
	msgbox Route117_PokemonDayCare_Incense_Text, MSGBOX_NPC
	end

Route117_PokemonDayCare_Incense_Text:
	.string "Certains POKéMON ne peuvent être obtenus que\n"
	.string "s'ils sont élevés avec un objet appelé\l"
	.string "ENCENS. Il y en a 2 types.\p"
	.string "Combien de POKéMON peut-on obtenir ?\n"
	.string "Eh bien, actuellement 9 POKéMON différents\l"
	.string "peuvent être obtenus avec de l'ENCENS.$"
