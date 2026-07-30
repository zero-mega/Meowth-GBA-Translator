.set LOCALID_NURSE, 1

MahoganyTown_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MahoganyTown_PokemonCenter_OnTransition
	.byte 0

MahoganyTown_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_MAHOGANYTOWN
	end

MahoganyTown_PokemonCenter_EventScript_Hiker::
	msgbox MahoganyTown_PokemonCenter_Text_PokefanM, MSGBOX_NPC
	end
	
MahoganyTown_PokemonCenter_EventScript_Boy::
	msgbox MahoganyTown_PokemonCenter_Text_Youngster, MSGBOX_NPC
	end

MahoganyTown_PokemonCenter_EventScript_Girl::
	msgbox MahoganyTown_PokemonCenter_Text_CooltrainerF, MSGBOX_NPC
	end

MahoganyTown_PokemonCenter_Text_PokefanM:
    .string "Qu'est-ce que c'est ? La TEAM ROCKET\n"
    .string "est de retour ?\p"
    .string "J'ai vu des hommes en noir au LAC\n"
    .string "COLÈRE…$"

MahoganyTown_PokemonCenter_Text_Youngster:
    .string "J'empêche mes POKéMON d'évoluer\n"
    .string "trop tôt.\p"
    .string "Je leur fais apprendre certaines attaques\n"
    .string "avant de les laisser évoluer.$"

MahoganyTown_PokemonCenter_Text_CooltrainerF:
    .string "Les POKéMON deviennent plus forts quand ils\n"
    .string "évoluent,\p"
    .string "mais ils apprennent aussi les capacités plus\n"
    .string "lentement.$"
