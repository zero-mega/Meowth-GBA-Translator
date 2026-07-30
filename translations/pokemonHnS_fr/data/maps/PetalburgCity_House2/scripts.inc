PetalburgCity_House2_MapScripts::
	.byte 0

PetalburgCity_House2_EventScript_Woman::
	msgbox PetalburgCity_House2_Text_NormanBecameGymLeader, MSGBOX_NPC
	end

PetalburgCity_House2_EventScript_SchoolKid::
	msgbox PetalburgCity_House2_Text_BattledNormanOnce, MSGBOX_NPC
	end

PetalburgCity_House2_Text_NormanBecameGymLeader:
	.string "PIERRE est devenu le nouveau\n"
	.string "CHAMPION D'ARÈNE de notre ville.\p"
	.string "Je crois qu'il a fait venir sa famille\n"
	.string "de quelque part au loin.$"

PetalburgCity_House2_Text_BattledNormanOnce:
	.string "J'ai combattu NORMAN une fois, mais ouf,\n"
	.string "il était bien trop fort.\p"
	.string "Comment le dirais-je ?\p"
	.string "J'ai juste eu l'impression qu'il\n"
	.string "vit pour les POKéMON.$"

