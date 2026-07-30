.set LOCALID_NURSE, 1

FortreeCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FortreeCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

FortreeCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_FORTREE_CITY
	end

FortreeCity_PokemonCenter_1F_RhyperiorEvo::
	msgbox FortreeCity_PokemonCenter_1F_RhyperiorEvo_Text, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_RhyperiorEvo_Text:
	.string "RHINOFÉROS évolue par échange. Mais seulement\n"
	.string "s'il est échangé avec un objet.\p"
	.string "Quel objet, demandes-tu ? Eh bien…\p"
	.string "Ma mémoire n'est plus ce qu'elle\n"
	.string "était il y a trente ans…\l"
	.string "C'était un… HARD… HARD… Ah. Je\p"
	.string "n'arrive pas à m'en souvenir.$"

FortreeCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

FortreeCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox FortreeCity_PokemonCenter_1F_Text_GoToSafariZone, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_EventScript_Man::
	msgbox FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_EventScript_Boy::
	msgbox FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav, MSGBOX_NPC
	end

FortreeCity_PokemonCenter_1F_Text_GoToSafariZone:
	.string "Écoute, gamine, tu bosses\n"
	.string "sur un POKéDEX ?\p"
	.string "Hmm… Va au PARC SAFARI.\n"
	.string "C'est mon conseil.$"

FortreeCity_PokemonCenter_1F_Text_RecordCornerIsNeat:
	.string "Tu as fait quelque chose au\n"
	.string "COIN RECORD ?\p"
	.string "C'est assez sympa. Ça mélange les\n"
	.string "records des DRESSEURS.\p"
	.string "Je ne sais pas trop comment ça marche,\n"
	.string "mais c'est cool. C'est excitant, même !$"

FortreeCity_PokemonCenter_1F_Text_DoYouKnowAboutPokenav:
	.string "Oh, waouh, tu\n"
	.string "as un POKéNAV !\p"
	.string "Et il est\n"
	.string "comme le mien !\p"
	.string "Tu connais le\n"
	.string "système APPEL\p"
	.string "du POKéNAV ?\n"
	.string "C'est super pratique\p"
	.string "pour garder\n"
	.string "contact !$"

