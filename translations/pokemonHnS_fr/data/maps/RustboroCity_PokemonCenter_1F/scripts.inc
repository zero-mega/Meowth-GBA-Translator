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
	.string "LE MONDE DES MAÎTRES\n"
	.string "Bonjour, téléspectateurs.\p"
	.string "Vous connaissez peut-être un DRESSEUR\n"
	.string "nommé {STR_VAR_1}.\l"
	.string "{STR_VAR_1} est célèbre comme maître de\p"
	.string "l'attrapage de POKéMON.\n"
	.string "La quête de {STR_VAR_1} pour les POKéMON dépend\l"
	.string "entièrement d'une recherche minutieuse à pied.\l"
	.string "Un jour mémorable, le DRESSEUR a marché\l"
	.string "environ {STR_VAR_2} pas.\l"
	.string "Le nombre total de POKéMON attrapés\p"
	.string "ce jour-là a atteint\n"
	.string "l'impressionnant {STR_VAR_3} !$"

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

