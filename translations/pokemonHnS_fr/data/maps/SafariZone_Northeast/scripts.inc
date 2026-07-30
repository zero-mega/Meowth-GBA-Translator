SafariZone_Northeast_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SetTimeEncounters
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

SafariZone_Northeast_AmbipomEvo::
	msgbox SafariZone_Northeast_AmbipomEvo_Text, MSGBOX_NPC
	end

SafariZone_Northeast_AmbipomEvo_Text:
	.string "J'adore le POKéMON CAPUMAIN !\n"
	.string "Ils sont si mignons !\l"
	.string "Mais tu savais qu'ils peuvent évoluer ?\p"
	.string "Si tu utilises une attaque qui fait\n"
	.string "rire tout le monde, il évolue !\p"
	.string "Et il est toujours adorable !$"

@ Event scripts for SafariZone_Northeast are in SafariZone_South/scripts.inc
