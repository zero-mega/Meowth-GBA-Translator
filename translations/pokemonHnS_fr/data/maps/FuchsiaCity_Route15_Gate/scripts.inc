FuchsiaCity_Route15_Gate_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, FuchsiaCity_OnFrame
	.byte 0

Route15_EventScript_Officer::
	msgbox Route15FuchsiaGate_Text_Officer, MSGBOX_NPC
	end

Route15FuchsiaGate_Text_Officer:
	.string "Tu travailles sur un POKéDEX ? C'est\n"
	.string "vraiment quelque chose.\p"
	.string "N'abandonne pas !$"
