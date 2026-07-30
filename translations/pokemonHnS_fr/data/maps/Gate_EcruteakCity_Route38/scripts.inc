Gate_EcruteakCity_Route38_MapScripts::
	.byte 0

Route38_EventScript_Officer::
	lock
	faceplayer
	msgbox Route38_Text_EcruteakGateOfficer, MSGBOX_DEFAULT
	closemessage
	release
	end

Route38_Text_EcruteakGateOfficer:
	.string "D'où tu viens, dis-tu\p"
	.string "? BOURG GEON ?\p"
	.string "Le PROF.ORME habite là-bas,\n"
	.string "non ? Tu as\p"
	.string "fait un long chemin\n"
	.string "pour arriver ici.$"
