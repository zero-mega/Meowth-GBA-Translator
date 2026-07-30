CaveOfOrigin_UnusedRubySapphireMap1_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, CaveOfOrigin_UnusedRubySapphireMap1_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, SetTimeEncounters
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

CaveOfOrigin_UnusedRubySapphireMap1_OnLoad:
	call_if_unset FLAG_REGI_DOORS_OPENED, CaveOfOrigin_UnusedRubySapphireMap1_CloseRegiEntrance
	end

CaveOfOrigin_UnusedRubySapphireMap1_CloseRegiEntrance::
	setmetatile 14, 14, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 14, 15, METATILE_General_RockWall_SandBase, TRUE
	return

CaveOfOrigin_UnusedRubySapphireMap1_Scientist1::
	msgbox CaveOfOrigin_UnusedRubySapphireMap1_Scientist1_Text, MSGBOX_NPC
	release
	end

CaveOfOrigin_UnusedRubySapphireMap1_Scientist2::
	msgbox CaveOfOrigin_UnusedRubySapphireMap1_Scientist2_Text, MSGBOX_NPC
	release
	end

CaveOfOrigin_UnusedRubySapphireMap1_Scientist3::
	msgbox CaveOfOrigin_UnusedRubySapphireMap1_Scientist3_Text, MSGBOX_NPC
	release
	end

CaveOfOrigin_UnusedRubySapphireMap1_Kirlia::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KIRLIA, CRY_MODE_NORMAL
	msgbox CaveOfOrigin_UnusedRubySapphireMap1_Kirlia_Text, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CaveOfOrigin_UnusedRubySapphireMap1_Scientist1_Text:
	.string "J'ai vu ce genre de structure\n"
	.string "rocheuse dans d'autres endroits, comme la\p"
	.string "ROUTE 132. Quelle est la signification\n"
	.string "de ces formations rocheuses ? Je\p"
	.string "suis sûr qu'elles sont artificielles.\n"
	.string "Tu as une idée ?$"

CaveOfOrigin_UnusedRubySapphireMap1_Scientist2_Text:
	.string "À chaque orage,\n"
	.string "la foudre frappe\l"
	.string "cette petite île.\p"
	.string "On dit que\n"
	.string "c'est lié à\l"
	.string "un POKéMON légendaire…$"

CaveOfOrigin_UnusedRubySapphireMap1_Scientist3_Text:
	.string "Nous recherchons un\n"
	.string "phénomène étrange\l"
	.string "qui se produit depuis\l"
	.string "quelques mois.\l"
	.string "Cette île\l"
	.string "est au centre\p"
	.string "de nos recherches.\n"
	.string "C'est fascinant !$"

CaveOfOrigin_UnusedRubySapphireMap1_Kirlia_Text:
	.string "KIRI : Kir !$"
