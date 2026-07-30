VerdanturfTown_Mart_MapScripts::
	.byte 0

VerdanturfTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_Mart_EventScript_Clerk2::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart VerdanturfTown_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
VerdanturfTown_Mart_Pokemart:
	.2byte ITEM_NEST_BALL
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_POKE_DOLL
	.2byte ITEM_NONE
	release
	end

VerdanturfTown_Mart_EventScript_Boy::
	msgbox VerdanturfTown_Mart_Text_XSpecialIsCrucial, MSGBOX_NPC
	end

VerdanturfTown_Mart_EventScript_ExpertF::
	msgbox VerdanturfTown_Mart_Text_NoStrategyGuidesForBattleTent, MSGBOX_NPC
	end

VerdanturfTown_Mart_EventScript_Lass::
	msgbox VerdanturfTown_Mart_Text_NestBallOnWeakenedPokemon, MSGBOX_NPC
	end

VerdanturfTown_Mart_Text_XSpecialIsCrucial:
	.string "Pour tout match de POKéMON, l'ATTAQUE\n"
	.string "SPÉCIALE est cruciale. Elle augmente la\p"
	.string "puissance de certaines attaques, même\n"
	.string "si c'est pour un combat.$"

VerdanturfTown_Mart_Text_NoStrategyGuidesForBattleTent:
	.string "On ne semble pas vendre de guides de stratégie\n"
	.string "gagnante pour la TENTE DE COMBAT…\p"
	.string "Il semble qu'il faille finalement compter sur\n"
	.string "ses propres talents…$"

VerdanturfTown_Mart_Text_NestBallOnWeakenedPokemon:
	.string "La FAIBLO BALL est plus efficace sur\n"
	.string "les POKéMON affaiblis.\p"
	.string "MYSTHERBE est le seul endroit où on peut\n"
	.string "l'acheter.$"

