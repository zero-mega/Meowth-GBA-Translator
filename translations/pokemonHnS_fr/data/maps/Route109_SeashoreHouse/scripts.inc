Route109_SeashoreHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route109_SeashoreHouse_OnTransition
	.byte 0

Route109_SeashoreHouse_OnTransition:
	setflag FLAG_LANDMARK_SEASHORE_HOUSE
	end

Route109_SeashoreHouse_EventScript_Owner::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_6_SODA_POP, Route109_SeashoreHouse_EventScript_AlreadyReceivedSodaPop
	goto_if_set FLAG_DEFEATED_SEASHORE_HOUSE, Route109_SeashoreHouse_EventScript_DefeatedTrainers
	goto_if_set FLAG_TEMP_2, Route109_SeashoreHouse_EventScript_AlreadyGaveIntroduction
	msgbox Route109_SeashoreHouse_Text_SeashoreHouseIntro, MSGBOX_DEFAULT
	setflag FLAG_TEMP_2
	release
	end

Route109_SeashoreHouse_EventScript_AlreadyGaveIntroduction::
	msgbox Route109_SeashoreHouse_Text_ShowMeSomeHotMatches, MSGBOX_DEFAULT
	release
	end

Route109_SeashoreHouse_EventScript_DefeatedTrainers::
	msgbox Route109_SeashoreHouse_Text_TakeTheseSodaPopBottles, MSGBOX_DEFAULT
	giveitem ITEM_SODA_POP, 6
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_BagFull
	setflag FLAG_RECEIVED_6_SODA_POP
	release
	end

Route109_SeashoreHouse_EventScript_BagFull::
	msgbox Route109_SeashoreHouse_Text_BagFull, MSGBOX_DEFAULT
	release
	end

Route109_SeashoreHouse_EventScript_AlreadyReceivedSodaPop::
	showmoneybox 0, 0
	msgbox Route109_SeashoreHouse_Text_WantToBuySodaPop, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route109_SeashoreHouse_EventScript_BuySodaPop
	msgbox Route109_SeashoreHouse_Text_ThatsTooBad, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_BuySodaPop::
	checkmoney 300
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_NotEnoughMoney
	checkitemspace ITEM_SODA_POP
	goto_if_eq VAR_RESULT, FALSE, Route109_SeashoreHouse_EventScript_NotEnoughSpace
	msgbox Route109_SeashoreHouse_Text_HereYouGo, MSGBOX_DEFAULT
	removemoney 300
	updatemoneybox
	giveitem ITEM_SODA_POP
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_NotEnoughMoney::
	msgbox Route109_SeashoreHouse_Text_NotEnoughMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_NotEnoughSpace::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

Route109_SeashoreHouse_EventScript_Dwayne::
	trainerbattle_single TRAINER_DWAYNE, Route109_SeashoreHouse_Text_DwayneIntro, Route109_SeashoreHouse_Text_DwayneDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_DwaynePostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_Johanna::
	trainerbattle_single TRAINER_JOHANNA, Route109_SeashoreHouse_Text_JohannaIntro, Route109_SeashoreHouse_Text_JohannaDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_JohannaPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_Simon::
	trainerbattle_single TRAINER_SIMON, Route109_SeashoreHouse_Text_SimonIntro, Route109_SeashoreHouse_Text_SimonDefeated, Route109_SeashoreHouse_EventScript_CheckTrainersCompletion
	msgbox Route109_SeashoreHouse_Text_SimonPostBattle, MSGBOX_AUTOCLOSE
	end

Route109_SeashoreHouse_EventScript_CheckTrainersCompletion::
	goto_if_not_defeated TRAINER_DWAYNE, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	goto_if_not_defeated TRAINER_JOHANNA, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	goto_if_not_defeated TRAINER_SIMON, Route109_SeashoreHouse_EventScript_TrainersNotCompleted
	setflag FLAG_DEFEATED_SEASHORE_HOUSE
	release
	end

Route109_SeashoreHouse_EventScript_TrainersNotCompleted::
	release
	end

Route109_SeashoreHouse_Text_SeashoreHouseIntro:
	.string "Je suis le propriétaire de la MAISON\n"
	.string "BORD DE MER. Mais tu peux m'appeler\p"
	.string "M. MER ! Ce que j'aime par-dessus\n"
	.string "tout, c'est voir des combats POKéMON\p"
	.string "chauds. Montre-moi que ton cœur brûle\p"
	.string "! Si tu bats tous les\n"
	.string "DRESSEURS ici, je récompenserai tes efforts.$"

Route109_SeashoreHouse_Text_ShowMeSomeHotMatches:
	.string "Montre-moi des combats brûlants !\p"
	.string "Je dirige cette MAISON DE LA CÔTE juste\n"
	.string "pour ça !$"

Route109_SeashoreHouse_Text_TakeTheseSodaPopBottles:
	.string "Tu es brûlant !\n"
	.string "Ces combats étaient enflammés !\l"
	.string "Je suis plus que satisfait !\p"
	.string "En remerciement de m'avoir montré\n"
	.string "ta série de victoires, je veux que tu prennes ça.\p"
	.string "C'est une demi-douzaine de bouteilles de SODA COOL !$"

Route109_SeashoreHouse_Text_BagFull:
	.string "Oh, mais dis donc, ton SAC est plein à craquer.\n"
	.string "Je vais garder ça pour toi.$"

Route109_SeashoreHouse_Text_WantToBuySodaPop:
	.string "Tu veux du SODA COOL ?\n"
	.string "Les POKéMON adorent ça !\p"
	.string "Seulement 300¥ la bouteille !\n"
	.string "Achètes-en !$"

Route109_SeashoreHouse_Text_HereYouGo:
	.string "Voilà !$"

Route109_SeashoreHouse_Text_NotEnoughMoney:
	.string "Tu n'as pas assez d'argent.$"

Route109_SeashoreHouse_Text_ThatsTooBad:
	.string "Non ?\n"
	.string "C'est dommage.$"

Route109_SeashoreHouse_Text_DwayneIntro:
	.string "Si tu cherches un combat à la\n"
	.string "MAISON SUR LA PLAGE, tu ne trouveras pas\l"
	.string "de DRESSEUR plus chaud que moi, matelot !$"

Route109_SeashoreHouse_Text_DwayneDefeated:
	.string "Quel combat chaud !\n"
	.string "J'accepte cette défaite, matelot !$"

Route109_SeashoreHouse_Text_DwaynePostBattle:
	.string "Quand je suis à POIVRESSE, j'adore\n"
	.string "les combats chauds et le SODA COOL glacé !$"

Route109_SeashoreHouse_Text_JohannaIntro:
	.string "Les combats ennuyeux ne valent pas l'effort.\p"
	.string "Les combats ardents sont ce qui muscle\n"
	.string "les DRESSEURS et les POKéMON !$"

Route109_SeashoreHouse_Text_JohannaDefeated:
	.string "C'est chaud !$"

Route109_SeashoreHouse_Text_JohannaPostBattle:
	.string "Ouf, j'ai soif.\n"
	.string "Je vais peut-être prendre un SODA COOL.$"

Route109_SeashoreHouse_Text_SimonIntro:
	.string "Je vais te montrer à quel point\n"
	.string "mes POKéMON sont forts, mais ne pleure pas !$"

Route109_SeashoreHouse_Text_SimonDefeated:
	.string "…J'ai perdu, mais je ne pleurerai pas…$"

Route109_SeashoreHouse_Text_SimonPostBattle:
	.string "Si un de mes POKéMON connaissait l'attaque\n"
	.string "pour me porter sur l'eau, je\l"
	.string "pourrais me débarrasser de cette bouée.$"

