.set LOCALID_NURSE, 1

LavenderTown_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavenderTown_PokemonCenter_OnTransition
	.byte 0

LavenderTown_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_LAVENDER_TOWN
	end

LavenderTown_PokemonCenter_EventScript_Gent::
	msgbox LavenderTown_PokemonCenter1F_Text_Gentleman, MSGBOX_NPC
	end

LavenderTown_PokemonCenter_EventScript_Teacher::
	msgbox LavenderTown_PokemonCenter1F_Text_Teacher, MSGBOX_NPC
	end

LavenderTown_PokemonCenter_EventScript_Youngster::
	goto_if_set FLAG_RETURNED_MACHINE_PART, LavenderTown_PokemonCenter_EventScript_YoungsterReturnedMachinePart
	msgbox LavenderTown_PokemonCenter1F_Text_Youngster, MSGBOX_NPC
	end

LavenderTown_PokemonCenter_EventScript_YoungsterReturnedMachinePart::
	msgbox LavenderTown_PokemonCenter1F_Text_Youngster_ReturnedMachinePart, MSGBOX_NPC
	end

LavenderTown_PokemonCenter1F_Text_Gentleman:
	.string "Au nord de LAVANVILLE se trouve le\n"
	.string "TUNNEL ROCHEUX. Traverse-le pour aller\l"
	.string "à la CENTRALE.$"

LavenderTown_PokemonCenter1F_Text_Teacher:
	.string "Il y a une émission radio qui diffuse\n"
	.string "de la musique POKé FLÛTE.\p"
	.string "Oh ? Ah, ta radio a besoin d'une\n"
	.string "AMÉLIORATION RADIO pour la capter.\p"
	.string "Peut-être que la STATION RADIO ici\n"
	.string "en ville peut t'en fournir une ?$"

LavenderTown_PokemonCenter1F_Text_Youngster:
	.string "Si la CENTRALE n'est pas en marche,\n"
	.string "le TRAIN MAGNÉTIQUE ne roule pas non\p"
	.string "plus… Ça veut aussi dire que la\n"
	.string "TOUR RADIO ne peut pas diffuser…$"

LavenderTown_PokemonCenter1F_Text_Youngster_ReturnedMachinePart:
	.string "Le DIRECTEUR de la RADIO\n"
	.string "était vraiment content.\p"
	.string "Il a dit qu'ils sont de retour à l'antenne\n"
	.string "car la CENTRALE fonctionne à nouveau\l"
	.string "normalement.$"
