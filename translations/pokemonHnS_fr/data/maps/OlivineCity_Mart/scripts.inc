OlivineCity_Mart_MapScripts::
	.byte 0

OlivineCity_EventScript_Trainer1::
	lock
	faceplayer
	msgbox OlivineCity_Text_MartCooltrainerF, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_Lass::
	lock
	faceplayer
	msgbox OlivineCity_Text_MartLass, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_MartCooltrainerF:
	.string "Tes POKéMON connaissent-ils déjà\n"
	.string "la capacité pour transporter les gens\l"
	.string "sur l'eau ?$"

OlivineCity_Text_MartLass:
	.string "Mon PAPILUSION vient de mon petit ami\n"
	.string "à l'étranger.\p"
	.string "Il m'a apporté une LETTRE de sa part.\p"
	.string "Tu veux savoir ce qu'elle dit ?\p"
	.string "Voyons voir… Non ! C'est\n"
	.string "un secret !$"
