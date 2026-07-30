Route46_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route29_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route46_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route46_EventScript_Bailey::
	trainerbattle_single TRAINER_BAILEY, Route46_Text_HikerBaileySeen, Route46_Text_HikerBaileyBeaten
	msgbox Route46_Text_HikerBaileyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route46_EventScript_Ted::
	trainerbattle_single TRAINER_TED, Route46_Text_CamperTedSeen, Route46_Text_CamperTedBeaten
	msgbox Route46_Text_CamperTedAfterBattle, MSGBOX_AUTOCLOSE
	end

Route46_EventScript_Erin::
	trainerbattle_single TRAINER_ERIN, Route46_Text_PicnickerErinSeen, Route46_Text_PicnickerErinBeaten
	msgbox Route46_Text_PicnickerErinAfterBattle, MSGBOX_AUTOCLOSE
	end

Route46_EventScript_Sign::
	lock
	msgbox Route46_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route46_EventScript_Item_Revive::
	finditem ITEM_REVIVE
	end

Route46_Text_HikerBaileySeen:
	.string "D'accord ! Je vais te montrer la\n"
	.string "puissance des POKéMON de montagne !$"

Route46_Text_HikerBaileyBeaten:
	.string "Pitié ! Tu m'as montré ta\n"
	.string "puissance !$"

Route46_Text_HikerBaileyAfterBattle:
	.string "C'est fini. Ça ne me dérange pas.\n"
	.string "Les MONTAGNARDS sont comme ça.$"

Route46_Text_CamperTedSeen:
	.string "J'élève des POKéMON aussi !\p"
	.string "Veux-tu te battre avec moi ?$"

Route46_Text_CamperTedBeaten:
	.string "Quoi… ?$"

Route46_Text_CamperTedAfterBattle:
	.string "J'ai fait de mon mieux mais je suis\n"
	.string "venu à court.\p"
	.string "Pas d'excuses : j'admets ma défaite.$"

Route46_Text_PicnickerErinSeen:
	.string "J'élève des POKéMON aussi !\p"
	.string "Tu veux te battre avec moi ?$"

Route46_Text_PicnickerErinBeaten:
	.string "Oh, mince !$"

Route46_Text_PicnickerErinAfterBattle:
	.string "J'ai visité beaucoup d'ARÈNES, mais celle\n"
	.string "de DOUBLONVILLE est ma préférée.\p"
	.string "Elle est remplie de jolies fleurs !$"

Route46_Text_PicnickerErin2Beaten:
	.string "Snif… Je perds tout le temps !\p"
	.string "Je vais devoir redoubler d'efforts !\n"
	.string "En tout cas, merci de t'être battu\n"
	.string "contre moi encore et encore.\p"
	.string "Voici ce cadeau de\n"
	.string "l'autre fois.$"

Route46_Text_Sign:
	.string "ROUTE 46\n"
	.string "ROUTE MONTAGNE EN VUE$"
