GoldenrodCity_House2_MapScripts::
	.byte 0

GoldenrodCity_House2_EventScript_Man::
	faceplayer
	lock
	msgbox GoldenrodPPSpeechHouse_Text_Man, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_House2_EventScript_Woman::
	faceplayer
	lock
	msgbox GoldenrodPPSpeechHouse_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodPPSpeechHouse_Text_Man:
    .string "Une fois en combat, mon POKéMON\n"
    .string "ne pouvait plus utiliser d'attaques. Les\p"
    .string "POINTS DE POUVOIR, ou PP,\n"
    .string "de ses attaques étaient épuisés.$"

GoldenrodPPSpeechHouse_Text_Lass:
    .string "Parfois, un POKéMON en pleine forme\n"
    .string "ne peut pas utiliser ses attaques.\p"
    .string "Si ça arrive, soigne-le dans un\n"
    .string "CENTRE POKéMON ou utilise un objet.$"
