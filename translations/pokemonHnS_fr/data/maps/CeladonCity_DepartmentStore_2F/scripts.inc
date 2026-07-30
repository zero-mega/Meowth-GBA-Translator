CeladonCity_DepartmentStore_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeladonDeptElevator_OnFrame
	.byte 0

CeladonDept2_EventScript_Pokefan::
	msgbox CeladonDeptStore2F_Text_PokefanM, MSGBOX_NPC
	end

CeladonDept2_EventScript_Youngster::
	msgbox CeladonDeptStore2F_Text_Youngster, MSGBOX_NPC
	end

CeladonDept2_EventScript_Directory::
	msgbox CeladonDeptStore2F_Text_Directory, MSGBOX_SIGN
	end

CeladonDeptStore2F_Text_PokefanM:
	.string "Je suis devenu DRESSEUR récemment.\p"
	.string "Mon fils m'a encouragé à\p"
	.string "le faire. Je suis impressionné\n"
	.string "par la sélection d'objets pratiques.$"

CeladonDeptStore2F_Text_Youngster:
	.string "Mon papa a du mal à apprendre\n"
	.string "les noms des objets et\l"
	.string "comment les utiliser…$"

CeladonDeptStore2F_Text_Directory:
	.string "Objets de qualité pour Dresseurs !\p"
	.string "2F : MARCHÉ DES DRESSEURS$"

