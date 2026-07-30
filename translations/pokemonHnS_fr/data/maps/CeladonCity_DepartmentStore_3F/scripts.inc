CeladonCity_DepartmentStore_3F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeladonDeptElevator_OnFrame
	.byte 0

CeladonDept3_EventScript_Youngster::
	msgbox CeladonDeptStore3F_Text_Youngster, MSGBOX_NPC
	end
CeladonDept3_EventScript_Gbakid1::
	msgbox CeladonDeptStore3F_Text_GameboyKid1, MSGBOX_NPC
	end
CeladonDept3_EventScript_Gbakid2::
	msgbox CeladonDeptStore3F_Text_GameboyKid2, MSGBOX_NPC
	end
CeladonDept3_EventScript_SuperNerd::
	msgbox CeladonDeptStore3F_Text_SuperNerd, MSGBOX_NPC
	end
CeladonDept3_EventScript_Directory::
	msgbox CeladonDeptStore3F_Text_Directory, MSGBOX_SIGN
	end

CeladonDeptStore3F_Text_Youngster:
	.string "Je n'arrive pas à décider sur quel POKéMON\n"
	.string "utiliser cette CT…$"

CeladonDeptStore3F_Text_GameboyKid1:
	.string "Oh-oh ! J'ai échangé mon POKéMON sans\n"
	.string "retirer l'AMÉLIORATOR de dessus.$"

CeladonDeptStore3F_Text_GameboyKid2:
	.string "Ouais ! Je vais enfin avoir un\n"
	.string "PORYGON !\p"
	.string "Je ne suis pas doué aux machines à sous, alors je\n"
	.string "n'ai jamais pu avoir assez de jetons…\p"
	.string "…Hein ?\p"
	.string "Le PORYGON échangé s'est transformé en\n"
	.string "un autre POKéMON !$"

CeladonDeptStore3F_Text_SuperNerd:
	.string "La BOUTIQUE CT vend des capacités rares.$"

CeladonDeptStore3F_Text_Directory:
	.string "3F : BOUTIQUE CT\p"
	.string "Rends tes POKéMON plus forts !$"

