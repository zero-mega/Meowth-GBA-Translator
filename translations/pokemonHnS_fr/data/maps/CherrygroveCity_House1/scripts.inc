CherrygroveCity_House1_MapScripts::
	.byte 0

CherrygroveCity_House1_EventScript_Baldingman::
	lock
	faceplayer
	msgbox CherrygroveCity_GymSpeechHouse_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

CherrygroveCity_House1_EventScript_Kid::
	lock
	faceplayer
	msgbox CherrygroveCity_GymSpeechHouse_Text_BugCatcher, MSGBOX_DEFAULT
	closemessage
	release
	end

CherrygroveCity_GymSpeechHouse_Text_PokefanM:
	.string "Tu essaies de voir à quel point tu es bon\n"
	.string "en tant que DRESSEUR de POKéMON ?\p"
	.string "Tu ferais mieux de visiter les ARÈNES\n"
	.string "POKéMON partout à JOHTO et de\l"
	.string "collecter des BADGES.$"

CherrygroveCity_GymSpeechHouse_Text_BugCatcher:
	.string "Quand je serai grand, je\n"
	.string "serai CHAMPION D'ARÈNE ! Je\p"
	.string "fais combattre mes POKéMON avec\n"
	.string "ceux de mon ami pour\l"
	.string "les rendre plus forts !$"
