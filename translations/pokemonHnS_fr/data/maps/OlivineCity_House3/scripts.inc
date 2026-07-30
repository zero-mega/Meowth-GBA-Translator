OlivineCity_House3_MapScripts::
	.byte 0

OlivineCityHouse3_EventScriptFishingGuru::
	lock
	faceplayer
	checkitem ITEM_GOOD_ROD
	goto_if_eq VAR_RESULT, TRUE, OlivineCityHouse3_EventScriptFishingGuru2
	msgbox OlivineCity_Text_OfferGoodRod, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, OlivineCityHouse3_EventScriptFishingGuruRefused
	msgbox OlivineCity_Text_GiveGoodRod, MSGBOX_DEFAULT
	giveitem ITEM_GOOD_ROD
	msgbox OlivineCity_Text_GaveGoodRod, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCityHouse3_EventScriptFishingGuru2::
	msgbox OlivineCity_Text_HaveGoodRod, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCityHouse3_EventScriptFishingGuruRefused::
	msgbox OlivineCity_Text_DontWantGoodRod, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_OfferGoodRod:
	.string "OLIVILLE est sur la mer !\p"
	.string "Et si c'est sur la mer, il y a\n"
	.string "forcément du poisson !\p"
	.string "Je pêche ici depuis 30 ans.\p"
	.string "Tu aimerais affronter la mer\n"
	.string "et essayer la pêche ?$"

OlivineCity_Text_GiveGoodRod:
	.string "Ah, hahah ! Nous avons là\n"
	.string "un futur pêcheur en herbe !$"

OlivineCity_Text_GaveGoodRod:
	.string "Les poissons ne se trouvent pas seulement\n"
	.string "dans la mer--ils sont partout où il y a\l"
	.string "d'eau.\p"
	.string "Au fait, ton POKéDEX indique les groupes\n"
	.string "de pêche pour les POKéMON.\p"
	.string "Différents endroits peuvent contenir\n"
	.string "des types de poissons similaires.$"

OlivineCity_Text_DontWantGoodRod:
	.string "Quoooi ? Tu n'aimes pas pêcher !?\n"
	.string "C'est incompréhensible !$"

OlivineCity_Text_HaveGoodRod:
	.string "Comment ça va ?\n"
	.string "Tu as attrapé le gros ?$"
