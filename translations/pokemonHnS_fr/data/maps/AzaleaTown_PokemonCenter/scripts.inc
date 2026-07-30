.set LOCALID_NURSE, 1

AzaleaTown_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AzaleaTown_Pokecenter_OnTransition
	.byte 0

AzaleaTown_Pokecenter_OnTransition::
	setrespawn HEAL_LOCATION_AZALEA_TOWN
	end

AzaleaPokeCenter_EventScript_Gentleman::
	lock
	faceplayer
	msgbox AzaleaPokecenter_Text_Gentleman, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaPokeCenter_EventScript_Fisher::
	lock
	faceplayer
	msgbox AzaleaPokecenter_Text_FishingGuru, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaPokeCenter_EventScript_PokefanF::
	lock
	faceplayer
	msgbox AzaleaPokecenter_Text_PokefanF, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaPokecenter_Text_Gentleman:
	.string "Tes POKéMON connaissent des capacités CS ?\p"
	.string "Ces capacités peuvent être utilisées même si\n"
	.string "ton POKéMON est K.O.$"

AzaleaPokecenter_Text_UnusedPCExplanation:
	.string "Ce type, BILL, a créé le système\n"
	.string "pour stocker les POKéMON sur PC.\p"
	.string "Le PC de BILL peut contenir jusqu'à 30\n"
	.string "POKéMON par BOÎTE.$"

AzaleaPokecenter_Text_FishingGuru:
	.string "Le PC de BILL peut stocker jusqu'à 30\n"
	.string "POKéMON par BOÎTE.$"

AzaleaPokecenter_Text_PokefanF:
	.string "Tu connais les BAIES ? Ouvre-en\p"
	.string "une, creuse-la et insère un\n"
	.string "dispositif spécial. Ensuite tu peux\p"
	.string "attraper des POKéMON avec. Avant\p"
	.string "l'invention des POKé BALLS, tout\n"
	.string "le monde utilisait des BAIES.$"
