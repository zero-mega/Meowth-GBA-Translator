.set LOCALID_NURSE, 1

CeruleanCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeruleanCity_PokemonCenter_OnTransition
	.byte 0

CeruleanCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_CERULEAN_CITY
	end

CeruleanCity_PokemonCenter_EventScript_Nerd::
	msgbox CeruleanCity_PokemonCenter1F_Text_SuperNerd, MSGBOX_NPC
	end

CeruleanCity_PokemonCenter_EventScript_Guy::
	msgbox CeruleanCity_PokemonCenter1F_Text_GymGuide, MSGBOX_NPC
	end

CeruleanCity_PokemonCenter1F_Text_SuperNerd:
	.string "Pour les combats, je préfère utiliser\n"
	.string "des POKéMON que j'ai élevés,\p"
	.string "même s'ils sont plus faibles\n"
	.string "que des POKéMON fraîchement attrapés.$"

CeruleanCity_PokemonCenter1F_Text_GymGuide:
	.string "Le MAGLEV voyage à plus de 550 km/h.\n"
	.string "Il relie KANTO et JOHTO en un rien\l"
	.string "de temps.\p"
	.string "Il rend vraiment JOHTO accessible.$"
