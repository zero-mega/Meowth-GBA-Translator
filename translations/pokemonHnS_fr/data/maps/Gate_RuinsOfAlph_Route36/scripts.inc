Gate_RuinsOfAlph_Route36_MapScripts::
	.byte 0

Gate_RuinsOfAlph_Route36_EventScript_Officer::
	lock
	faceplayer
	msgbox Gate_RuinsOfAlph_Route36_Text_Officer, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_RuinsOfAlph_Route36_EventScript_PokefanM::
	lock
	faceplayer
	msgbox Gate_RuinsOfAlph_Route36_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_RuinsOfAlph_Route36_EventScript_Youngster::
	lock
	faceplayer
	msgbox Gate_RuinsOfAlph_Route36_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_RuinsOfAlph_Route36_Text_Officer:
	.string "RUINES D'ALPHA\p"
	.string "Site touristique à voir et à toucher\p"
	.string "Essayez les dalles coulissantes !$"

Gate_RuinsOfAlph_Route36_Text_PokefanM:
	.string "Tu étudies les RUINES ?\p"
	.string "Je vois un futur scientifique.$"

Gate_RuinsOfAlph_Route36_Text_Youngster:
	.string "Il y a des dessins sur des panneaux\n"
	.string "de pierre.\p"
	.string "J'ai essayé de les déplacer.\n"
	.string "Je me demande ce que c'est.$"
