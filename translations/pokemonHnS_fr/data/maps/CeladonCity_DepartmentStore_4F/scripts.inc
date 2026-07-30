CeladonCity_DepartmentStore_4F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeladonDeptElevator_OnFrame
	.byte 0

CeladonDept_EventScript_Supernerd::
	msgbox CeladonDeptStore4F_Text_SuperNerd, MSGBOX_NPC
	end
CeladonDept_EventScript_Youngster::
	msgbox CeladonDeptStore4F_Text_Youngster, MSGBOX_NPC
	end
CeladonDept_EventScript_Directory::
	msgbox CeladonDeptStore4F_Text_Directory, MSGBOX_NPC
	end

CeladonDeptStore4F_Text_SuperNerd:
	.string "Je suis ici pour acheter du COURRIER SURF\n"
	.string "à envoyer à ma copine.\p"
	.string "Attends, ils sont en rupture de stock ?$"

CeladonDeptStore4F_Text_Youngster:
	.string "C'est le seul endroit où on\n"
	.string "pouvait acheter la LETTRE AMOUR. Du\p"
	.string "moins, c'était le cas. Ils disent\n"
	.string "qu'ils sont en rupture de stock.$"

CeladonDeptStore4F_Text_Directory:
	.string "Exprimez-vous avec des cadeaux !\p"
	.string "4e étage : CADEAUX SAGES$"
