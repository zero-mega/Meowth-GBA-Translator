FortreeCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, FortreeCity_OnResume
	.byte 0

FortreeCity_OnTransition:
	setflag FLAG_VISITED_VIRIDIAN_CITY
	end

FortreeCity_OnResume:
	setstepcallback STEP_CB_FORTREE_BRIDGE
	end

FortreeCity_EventScript_Man::
	msgbox FortreeCity_Text_SawGiganticPokemonInSky, MSGBOX_NPC
	end

FortreeCity_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_KECLEON_FLED_FORTREE, FortreeCity_EventScript_WomanGymAccessible
	msgbox FortreeCity_Text_SomethingBlockingGym, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_WomanGymAccessible::
	msgbox FortreeCity_Text_ThisTimeIllBeatWinona, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_Girl::
	msgbox FortreeCity_Text_TreesGrowByDrinkingRainwater, MSGBOX_NPC
	end

FortreeCity_EventScript_OldMan::
	msgbox FortreeCity_Text_EveryoneHealthyAndLively, MSGBOX_NPC
	end

FortreeCity_EventScript_Boy::
	msgbox FortreeCity_Text_BugPokemonComeThroughWindow, MSGBOX_NPC
	end

FortreeCity_EventScript_GameboyKid::
	msgbox FortreeCity_Text_PokemonThatEvolveWhenTraded, MSGBOX_NPC
	end

FortreeCity_EventScript_CitySign::
	msgbox FortreeCity_Text_CitySign, MSGBOX_SIGN
	end

FortreeCity_EventScript_GymSign::
	msgbox FortreeCity_Text_GymSign, MSGBOX_SIGN
	end

FortreeCity_EventScript_Kecleon::
	lock
	faceplayer
	checkitem ITEM_DEVON_SCOPE
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_EventScript_AskUseDevonScope
	msgbox FortreeCity_Text_SomethingUnseeable, MSGBOX_DEFAULT
	release
	end

FortreeCity_EventScript_AskUseDevonScope::
	msgbox FortreeCity_Text_UnseeableUseDevonScope, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FortreeCity_EventScript_UseDevonScope
	release
	end

FortreeCity_EventScript_UseDevonScope::
	msgbox FortreeCity_Text_UsedDevonScopePokemonFled, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Movement_KecleonAppears
	waitmovement 0
	waitse
	playmoncry SPECIES_KECLEON, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	applymovement VAR_LAST_TALKED, FortreeCity_Movement_KecleonFlee
	waitmovement 0
	removeobject VAR_LAST_TALKED
	setflag FLAG_KECLEON_FLED_FORTREE
	release
	end

FortreeCity_Movement_KecleonFlee:
	walk_right
	step_end

FortreeCity_Text_SawGiganticPokemonInSky:
	.string "Personne ne me\n"
	.string "croit, mais j'ai\p"
	.string "vu un POKéMON\n"
	.string "gigantesque dans le\p"
	.string "ciel. Il semblait\n"
	.string "onduler en volant\p"
	.string "vers le nord…$"

FortreeCity_Text_SomethingBlockingGym:
	.string "Je veux aller à l'ARÈNE POKéMON,\n"
	.string "mais quelque chose bloque le chemin.\p"
	.string "Après tout le mal que je me suis donné pour\n"
	.string "m'entraîner sur la ROUTE 120…$"

FortreeCity_Text_ThisTimeIllBeatWinona:
	.string "J'ai mes POKéMON fétiches avec moi.\n"
	.string "Cette fois, je vais battre ALIZÉE.$"

FortreeCity_Text_TreesGrowByDrinkingRainwater:
	.string "Le sol absorbe la pluie, et\n"
	.string "les arbres poussent en buvant cette eau…\p"
	.string "Notre FORGEFRAISE existe parce qu'il y a\n"
	.string "à la fois de l'eau et du sol.$"

FortreeCity_Text_EveryoneHealthyAndLively:
	.string "La VILLE est composée de maisons construites\n"
	.string "sur des arbres.\p"
	.string "Peut-être à cause de ce mode de vie,\n"
	.string "tout le monde est en forme et plein de vie.\p"
	.string "Moi-même--je me sens comme si j'avais\n"
	.string "rajeuni de trente ans.$"

FortreeCity_Text_BugPokemonComeThroughWindow:
	.string "Vivre au sommet des arbres,\p"
	.string "c'est bien. Mais parfois des\n"
	.string "POKéMON INSECTE entrent par les\l"
	.string "fenêtres. Ça peut vraiment surprendre.$"

FortreeCity_Text_PokemonThatEvolveWhenTraded:
	.string "Il y a des POKéMON qui évoluent quand\n"
	.string "tu les échanges ! C'est ce que j'ai entendu.$"

FortreeCity_Text_SomethingUnseeable:
	.string "Quelque chose d'invisible bloque le chemin.$"

FortreeCity_Text_UnseeableUseDevonScope:
	.string "Quelque chose d'invisible bloque le chemin.\p"
	.string "Veux-tu utiliser le SCOPE SYLPHE ?$"

FortreeCity_Text_UsedDevonScopePokemonFled:
	.string "{PLAYER} utilise le DEVON SCOPE.\p"
	.string "Un POKéMON invisible est devenu\n"
	.string "complètement visible !\p"
	.string "Le POKéMON effrayé s'est enfui !$"

FortreeCity_Text_CitySign:
	.string "FORTREE\n"
	.string "“La cité perchée qui s'ébroue avec\l"
	.string "la nature.”$"

FortreeCity_Text_GymSign:
	.string "ARÈNE POKéMON DE FORGEFRAISE\n"
	.string "CHAMPION D'ARÈNE : ALIZÉE\p"
	.string "“La maîtresse des oiseaux prenant son envol\n"
	.string "vers le monde.”$"
