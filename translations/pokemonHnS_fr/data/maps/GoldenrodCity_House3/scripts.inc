GoldenrodCity_House3_MapScripts::
	.byte 0

GoldenrodCity_House3_EventScript_PokefanM::
	lock
	faceplayer
	msgbox GoldenrodHappinessRater_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_House3_EventScript_Twin::
	lock
	faceplayer
	msgbox GoldenrodHappinessRater_Text_Twin, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodHappinessRater_Text_PokefanM:
    .string "Je perds tout le temps en combat, et mes\n"
    .string "POKéMON finissent par s'évanouir...\p"
    .string "C'est peut-être pour ça qu'ils\n"
    .string "ne m'aiment pas beaucoup...$"

GoldenrodHappinessRater_Text_Twin:
    .string "Quand j'utilise un objet sur mon POKéMON,\n"
    .string "il a l'air vraiment content !$"
