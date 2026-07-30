.set LOCALID_NURSE, 1

RustboroCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

RustboroCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_RUSTBORO_CITY
	call Common_EventScript_UpdateBrineyLocation
	end

RustboroCity_PokemonCenter_1F_ProbopassEvo::
	msgbox RustboroCity_PokemonCenter_1F_ProbopassEvo_Text, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_ProbopassEvo_Text:
	.string "NOSEPASS evolves and changes\n"
	.string "its typing to ROCK and STEEL.\p"
	.string "But in order to evolve, it needs\n"
	.string "to be exposed to a strong\l"
	.string "magnetic field.\p"
	.string "It's difficult finding a place\n"
	.string "like this in HOENN, so scientists\l"
	.string "discovered that making NOSEPASS\l"
	.string "hold a THUNDER STONE makes him\l"
	.string "evolve easier by multiplying\l"
	.string "its own magnetic field by two!\p"
	.string "I wonder what THUNDER STONES are\n"
	.string "made of.$"

RustboroCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

RustboroCity_PokemonCenter_1F_EventScript_Man::
	msgbox RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_Boy::
	msgbox RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_EventScript_Girl::
	msgbox RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor, MSGBOX_NPC
	end

RustboroCity_PokemonCenter_1F_Text_PokemonHavePersonalities:
	.string "Mon POKéMON a une nature NAÏF,\n"
	.string "et celui de mon ami une\p"
	.string "nature JOVIALE. C'est fascinant comme les\n"
	.string "POKéMON ont des personnalités !$"

RustboroCity_PokemonCenter_1F_Text_MaleAndFemalePokemon:
	.string "Comme les humains, il y\n"
	.string "a des POKéMON mâles et\p"
	.string "femelles. Mais personne ne semble\n"
	.string "savoir en quoi ils diffèrent.$"

RustboroCity_PokemonCenter_1F_Text_HMCutNextDoor:
	.string "Le voisin m'a donné une CS !\p"
	.string "Je l'ai utilisée pour apprendre à mon POKéMON\n"
	.string "à COUPE les petits arbres.$"

