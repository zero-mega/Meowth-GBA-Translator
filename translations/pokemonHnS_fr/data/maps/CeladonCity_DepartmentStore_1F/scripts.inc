CeladonCity_DepartmentStore_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CeladonDeptElevator_OnFrame
	.byte 0

CeladonDept1_EventScript_Receptionsit::
    msgbox CeladonDeptStore_Text_1FReceptionist, MSGBOX_NPC
    end

CeladonDept1_EventScript_Gent::
    msgbox CeladonDeptStore_Text_1FGentleman, MSGBOX_NPC
    end

CeladonDept1_EventScript_Teacher::
    msgbox CeladonDeptStore_Text_1FTeacher, MSGBOX_NPC
    end

CeladonDept1_EventScript_Directory::
    msgbox CeladonDeptStore_Text_1FDirectory, MSGBOX_SIGN
    end

CeladonDeptStore_Text_1FReceptionist:
    .string "Bonjour ! Bienvenue au GRAND MAGASIN\n"
    .string "de CELADOPOLE !\p"
    .string "Le plan est sur le mur.$"

CeladonDeptStore_Text_1FGentleman:
    .string "Ce GRAND MAGASIN fait partie\n"
    .string "de la même chaîne que\p"
    .string "celui de DOUBLONVILLE. Ils ont\n"
    .string "été rénovés en même temps.$"

CeladonDeptStore_Text_1FTeacher:
    .string "C'est ma première fois ici.\p"
    .string "C'est si grand…\p"
    .string "J'ai peur de me perdre.$"

CeladonDeptStore_Text_1FDirectory:
    .string "RDC : SERVICE CLIENT\p"
    .string "1er : MARCHÉ DES DRESSEURS\p"
    .string "2e : BOUTIQUE CT\p"
    .string "3e : CADEAUX DU SAGE\p"
    .string "4e : PHARMACIE\p"
    .string "5e : TERRASSE$"
