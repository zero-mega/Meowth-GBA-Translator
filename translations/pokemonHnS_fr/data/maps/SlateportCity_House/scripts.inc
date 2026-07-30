SlateportCity_House_MapScripts::
	.byte 0

SlateportCity_House_EventScript_PokefanM::
	msgbox SlateportCity_House_Text_NatureToDoWithStatGains, MSGBOX_NPC
	end

SlateportCity_House_EventScript_Girl::
	msgbox SlateportCity_House_Text_MustBeGoingToBattleTent, MSGBOX_NPC
	end

SlateportCity_House_Text_NatureToDoWithStatGains:
	.string "Mon POKéMON a une nature PRESSÉE.\p"
	.string "Il a une VITESSE plus élevée que\n"
	.string "mes autres POKéMON.\p"
	.string "Peut-être que leur nature a quelque chose\n"
	.string "à voir avec les gains de stats des POKéMON.$"

SlateportCity_House_Text_MustBeGoingToBattleTent:
	.string "Tu es DRESSEUR, pas vrai ?\p"
	.string "Puisque tu es venu à MYOKARA,\n"
	.string "tu dois aller à la TENTE DE COMBAT.$"

