SaffronCity_Mart_MapScripts::
	.byte 0

SafronMart_EventScript_CooltrainerM::
	msgbox SaffronMart_Text_CooltrainerM, MSGBOX_NPC
	end
SafronMart_EventScript_CooltrainerF::
	msgbox SaffronMart_Text_CooltrainerF, MSGBOX_NPC
	end
SaffronMart_Text_CooltrainerM:
	.string "Il y a une grande TOUR RADIO\n"
	.string "à LAVANDE.$"

SaffronMart_Text_CooltrainerF:
	.string "Je veux devenir plus fort, mais\n"
	.string "je ne suis pas encore bon…\p"
	.string "Tu pourrais me montrer comment un jour ?$"
