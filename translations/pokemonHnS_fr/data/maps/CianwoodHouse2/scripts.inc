CianwoodHouse2_MapScripts::
	.byte 0

CianwoodHouse2_EventScript_Teacher::
	lock
	faceplayer
	msgbox CianwoodCity_Text_LugiaHouseTeacher, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse2_EventScript_Lass::
	lock
	faceplayer
	msgbox CianwoodCity_Text_LugiaHouseLass, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse2_EventScript_Twin::
	lock
	faceplayer
	msgbox CianwoodCity_Text_LugiaHouseTwin, MSGBOX_DEFAULT
	closemessage
	release
	end
	
CianwoodCity_Text_LugiaHouseTeacher:
	.string "Tu viens d'OLIVILLE ?\p"
	.string "Tu te souviens des quatre îles\n"
	.string "en chemin ?\p"
	.string "J'ai entendu dire qu'une créa-\n"
	.string "ture marine mythique s'y cache.$"

CianwoodCity_Text_LugiaHouseLass:
	.string "J'ai entendu dire qu'on ne peut le voir\n"
	.string "que si on a une ARGENT'AILE.\p"
	.string "Il doit avoir la même odeur\n"
	.string "que la créature.$"

CianwoodCity_Text_LugiaHouseTwin:
	.string "J'ai entendu dire que les tourbillons\n"
	.string "autour des îles sont causés par\l"
	.string "une créature marine.\p"
	.string "Il te faudra peut-être une capacité spéciale\n"
	.string "pour les traverser.$"
