Route33_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route33_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route33_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route33_EventScript_HikerAnthony::
	trainerbattle_single TRAINER_ANTHONY, Route33_Text_HikerAnthony2Seen, Route33_Text_HikerAnthony2Beaten
	msgbox Route33_Text_HikerAnthony2After, MSGBOX_AUTOCLOSE
	end

Route33_EventScript_Lass::
	lock
	faceplayer
	msgbox Route33_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

Route33_Text_HikerAnthony2Seen:
	.string "J'ai traversé le tunnel,\n"
	.string "mais j'ai encore plein\l"
	.string "d'énergie.$"

Route33_Text_HikerAnthony2Beaten:
	.string "Ouah ! Tu as plus de punch\n"
	.string "que moi !$"

Route33_Text_HikerAnthony2After:
	.string "Nous, les MONTAGNARDS, sommes à notre\n"
	.string "meilleur en montagne.$"

Route33_Text_HikerAnthonyDunsparce:
	.string "Hé, tu as attrapé un INSOLOURDO ?\p"
	.string "Moi aussi j'en ai attrapé un.\p"
	.string "Regarde-le à la lumière.\n"
	.string "Il a une drôle de tête !$"

Route33_Text_Lass:
	.string "Huff, huff… Cette grotte était\p"
	.string "plus grande que prévu.\n"
	.string "Je me suis trop\p"
	.string "fatigué à chercher MARILL\n"
	.string "et je suis sorti.$"
