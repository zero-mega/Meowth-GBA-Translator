MossdeepCity_Mart_MapScripts::
	.byte 0

MossdeepCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart 0
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

MossdeepCity_Mart_EventScript_Clerk2::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart MossdeepCity_Mart_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
MossdeepCity_Mart_Pokemart:
	.2byte ITEM_NET_BALL
	.2byte ITEM_DIVE_BALL
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_NONE
	release
	end

MossdeepCity_Mart_EventScript_Woman::
	msgbox MossdeepCity_Mart_Text_ReviveIsFantastic, MSGBOX_NPC
	end

MossdeepCity_Mart_EventScript_Boy::
	msgbox MossdeepCity_Mart_Text_MaxRepelLastsLongest, MSGBOX_NPC
	end

MossdeepCity_Mart_EventScript_Sailor::
	msgbox MossdeepCity_Mart_Text_NetAndDiveBallsRare, MSGBOX_NPC
	end

MossdeepCity_Mart_Text_ReviveIsFantastic:
	.string "RAPPEL est fantastique !\p"
	.string "Donne-le à un POKéMON évanoui,\n"
	.string "et le POKéMON se relèvera.\p"
	.string "Mais attention, RAPPEL ne restaure pas\n"
	.string "les PP utilisés des attaques.$"

MossdeepCity_Mart_Text_MaxRepelLastsLongest:
	.string "REPOUSSE MAX éloigne tous les POKéMON faibles.\p"
	.string "De tous les sprays REPOUSSE, c'est celui qui\n"
	.string "dure le plus longtemps.$"

MossdeepCity_Mart_Text_NetAndDiveBallsRare:
	.string "Les BALLS FILET et SCUBA sont\n"
	.string "des POKé BALLS rares fabriquées uniquement\p"
	.string "à ALGATIA. La BALL FILET\n"
	.string "est efficace contre les POKéMON\p"
	.string "EAU et INSECTE. La BALL\n"
	.string "SCUBA est efficace sous l'eau.$"

