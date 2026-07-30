Route1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route1_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route1_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route1_EventScript_SchoolboyDanny::
	trainerbattle_single TRAINER_DANNY, Route1_Text_SchoolboyDanny_Seen, Route1_Text_SchoolboyDanny_Beaten
	msgbox Route1_Text_SchoolboyDanny_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route1_EventScript_Quinn::
	trainerbattle_single TRAINER_QUINN, Route1_Text_CooltrainerFQuinn_Seen, Route1_Text_CooltrainerFQuinn_Beaten
	msgbox Route1_Text_CooltrainerFQuinn_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route1_EventScript_Sign::
	msgbox Route1_Text_Sign, MSGBOX_SIGN
	end

Route1_Text_SchoolboyDanny_Seen:
	.string "Quand des Dresseurs se rencontrent,\n"
	.string "la première chose à faire, c'est se battre.$"

Route1_Text_SchoolboyDanny_Beaten:
	.string "Snif… J'ai un palmarès de défaites…$"

Route1_Text_SchoolboyDanny_AfterBattle:
	.string "Pour les Dresseurs, c'est courant de\n"
	.string "se battre quand on se croise.$"

Route1_Text_CooltrainerFQuinn_Seen:
	.string "Hé, toi ! Tu veux te battre ?$"

Route1_Text_CooltrainerFQuinn_Beaten:
	.string "À plat ventre…$"

Route1_Text_CooltrainerFQuinn_AfterBattle:
	.string "Tu es fort.\p"
	.string "Tu as visiblement beaucoup\n"
	.string "t'entraîné.$"

Route1_Text_Sign:
	.string "ROUTE 1\p"
	.string "BOURG PALETTE - JADIELLE$"
