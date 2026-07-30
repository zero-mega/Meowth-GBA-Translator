.set LOCALID_NURSE, 1

SaffronCity_PokemonCenter_MapScripts::
map_script MAP_SCRIPT_ON_TRANSITION, SaffronCity_PokemonCenter_OnTransition
	.byte 0

SaffronCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_SAFFRON_CITY
	end

SaffronCity_PokemonCenter_EventScript_Teacher::
	msgbox SaffronCity_PokemonCenter1F_Text_Teacher, MSGBOX_NPC	
	end

SaffronCity_PokemonCenter_EventScript_Fisher::
	goto_if_set FLAG_RETURNED_MACHINE_PART, SaffronCity_PokemonCenter_EventScript_FisherReturnedMachinePart
	msgbox SaffronCity_PokemonCenter1F_Text_Fisher, MSGBOX_NPC	
	end
SaffronCity_PokemonCenter_EventScript_FisherReturnedMachinePart::
	msgbox SaffronCity_PokemonCenter1F_Text_Fisher_ReturnedPart, MSGBOX_NPC
	end

SaffronCity_PokemonCenter_EventScript_Youngster::
	msgbox SaffronCity_PokemonCenter1F_Text_Youngster, MSGBOX_NPC
	end

SaffronCity_PokemonCenter1F_Text_Teacher:
	.string "À quoi ressemblent les CENTRES POKéMON\n"
	.string "de JOHTO ?\p"
	.string "…Ah, je vois. Donc ils ne sont pas très\n"
	.string "différents de ceux de KANTO.\p"
	.string "Je peux aller à JOHTO sans\n"
	.string "me faire de souci, alors !$"

SaffronCity_PokemonCenter1F_Text_Fisher:
	.string "Je suis juste passé par la\n"
	.string "GROTTE.\p"
	.string "Il y avait du grabuge à la\n"
	.string "CENTRALE.$"

SaffronCity_PokemonCenter1F_Text_Fisher_ReturnedPart:
	.string "Il y a une grotte bizarre à AZURIA.\p"
	.string "En tant que pro RANDONNEUR, je devrais l'explorer,\n"
	.string "mais cet endroit me fait même peur à moi.$"

SaffronCity_PokemonCenter1F_Text_Youngster:
	.string "Le siège de la SYLPHE SARL et la\n"
	.string "GARE MAGNET — ce sont\l"
	.string "les endroits à voir à SAFRANIA.$"
