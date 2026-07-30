.set LOCALID_NURSE, 1

SafariZoneGate_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SafariZoneGate_PokemonCenter_OnTransition
	.byte 0

SafariZoneGate_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_SAFARI_ZONE_GATE
	end

SafariZoneGate_PokemonCenter_EventScript_NPC1::
	lock
	faceplayer
	msgbox SafariZoneGate_PokemonCenter_Text_NPC1, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_PokemonCenter_EventScript_NPC2::
	lock
	faceplayer
	msgbox SafariZoneGate_PokemonCenter_Text_NPC2, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_PokemonCenter_Text_Boy::
	lock
	faceplayer
	msgbox SafariZoneGate_PokemonCenter_Text_SafariSong, MSGBOX_DEFAULT
	closemessage
	release
	end

SafariZoneGate_PokemonCenter_Text_NPC1:
	.string "Ceux qui viennent dans un CENTRE POKéMON\n"
	.string "prendent généralement bien soin de leurs POKéMON.\p"
	.string "Tu es d'accord ?$"

SafariZoneGate_PokemonCenter_Text_NPC2:
	.string "Après une longue marche en montagne pour\n"
	.string "trouver un CENTRE POKéMON, quand tu es sur\l"
	.string "le point de t'effondrer…\p"
	.string "Alors on a l'impression d'être au paradis !$"

SafariZoneGate_PokemonCenter_Text_SafariSong:
	.string "Safari, safari, c'est tellement amusant.\n"
	.string "Safari, safari, tellement intéressant, hein !\p"
	.string "Tant de POKéMON nous attendent !\p"
	.string "...C'est une chanson que j'ai inventée.\n"
	.string "Je la chante quand je suis au PARC SAFARI.$"
