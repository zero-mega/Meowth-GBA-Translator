MossdeepCity_House3_MapScripts::
	.byte 0

MossdeepCity_House3_EventScript_SuperRodFisherman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_SUPER_ROD, MossdeepCity_House3_EventScript_ReceivedSuperRod
	msgbox MossdeepCity_House3_Text_YouWantSuperRod, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MossdeepCity_House3_EventScript_DeclineSuperRod
	msgbox MossdeepCity_House3_Text_SuperRodIsSuper, MSGBOX_DEFAULT
	giveitem ITEM_SUPER_ROD
	setflag FLAG_RECEIVED_SUPER_ROD
	msgbox MossdeepCity_House3_Text_TryDroppingRodInWater, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_EventScript_ReceivedSuperRod::
	msgbox MossdeepCity_House3_Text_GoAfterSeafloorPokemon, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_EventScript_DeclineSuperRod::
	msgbox MossdeepCity_House3_Text_DontYouLikeToFish, MSGBOX_DEFAULT
	release
	end

MossdeepCity_House3_Text_YouWantSuperRod:
	.string "Hé, DRESSEUR !\n"
	.string "Une SUPER CANNE, c'est vraiment super !\p"
	.string "Dis ce que tu veux, mais ce bébé peut\n"
	.string "attraper des POKéMON que les autres cannes\p"
	.string "ne peuvent pas !\n"
	.string "Essaie !$"

MossdeepCity_House3_Text_SuperRodIsSuper:
	.string "Tu parles !\n"
	.string "Après tout, une MÉGA CANNE est vraiment super !$"

MossdeepCity_House3_Text_TryDroppingRodInWater:
	.string "S'il y a de l'eau, essaie de lancer ta CANNE\n"
	.string "et vois ce qui mord !$"

MossdeepCity_House3_Text_DontYouLikeToFish:
	.string "Hein ?\n"
	.string "Tu n'aimes pas pêcher ?$"

MossdeepCity_House3_Text_GoAfterSeafloorPokemon:
	.string "Va à la pêche aux POKéMON des fonds marins\n"
	.string "avec ta MÉGA CANNE.$"

