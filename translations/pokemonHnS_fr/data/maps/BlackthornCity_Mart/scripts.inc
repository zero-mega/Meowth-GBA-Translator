BlackthornCity_Mart_MapScripts::
	.byte 0

BlackthornMart_EventScript_CoolTrainerM::
	msgbox BlackthornMart_Text_CooltrainerM, MSGBOX_NPC
	end

BlackthornMart_EventScript_BlackBelt::
	msgbox BlackthornMart_Text_BlackBelt, MSGBOX_NPC
	end

BlackthornMart_Text_CooltrainerM:
	.string "On ne peut pas acheter de RAPPEL MAX, mais il\n"
	.string "restaure complètement un POKéMON K.O.\p"
	.string "Attention — il ne restaure pas les PP, les\n"
	.string "POINTS DE PUISSANCE nécessaires aux capacités.$"

BlackthornMart_Text_BlackBelt:
	.string "REPOUSSE MAX éloigne les POKéMON faibles\n"
	.string "de toi.\p"
	.string "C'est le REPOUSSE qui dure le plus longtemps\n"
	.string "de tous les sprays.$"
