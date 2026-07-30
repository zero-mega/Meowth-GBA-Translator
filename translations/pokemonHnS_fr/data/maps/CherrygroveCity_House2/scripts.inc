CherrygroveCity_House2_MapScripts::
	.byte 0

CherrygroveCity_House2_EventScript_GuideGent::
	lock
	faceplayer
	msgbox CherrygroveCity_GuideHouse_Text_GuideGent, MSGBOX_DEFAULT
	closemessage
	release
	end

CherrygroveCity_GuideHouse_Text_GuideGent:
	.string "Quand j'étais petit, j'étais un\n"
	.string "DRESSEUR prometteur !\p"
	.string "Voici un conseil :\n"
	.string "Attrape plein de POKéMON !\p"
	.string "Traite-les tous avec gentillesse !$"
