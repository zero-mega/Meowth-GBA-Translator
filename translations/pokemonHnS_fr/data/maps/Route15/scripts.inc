Route15_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route15_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route15_OnTransition:
	callnative SetTimeBasedEncounters
	end

Route15_EventScript_Colette::
	trainerbattle_single TRAINER_COLETTE Route15_Text_TeacherColetteSeen, Route15_Text_TeacherColetteBeaten
	msgbox Route15_Text_TeacherColetteAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Hillary::
	trainerbattle_single TRAINER_HILLARY Route15_Text_TeacherHillarySeen, Route15_Text_TeacherHillaryBeaten
	msgbox Route15_Text_TeacherHillaryAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Kipp::
	trainerbattle_single TRAINER_KIPP Route15_Text_SchoolboyKippSeen, Route15_Text_SchoolboyKippBeaten
	msgbox Route15_Text_SchoolboyKippAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Tommy::
	trainerbattle_single TRAINER_TOMMY Route15_Text_SchoolboyTommySeen, Route15_Text_SchoolboyTommyBeaten
	msgbox Route15_Text_SchoolboyTommyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Johnny::
	trainerbattle_single TRAINER_JOHNNY Route15_Text_SchoolboyJohnnySeen, Route15_Text_SchoolboyJohnnyBeaten
	msgbox Route15_Text_SchoolboyJohnnyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Billy::
	trainerbattle_single TRAINER_BILLY Route15_Text_SchoolboyBillySeen, Route15_Text_SchoolboyBillyBeaten
	msgbox Route15_Text_SchoolboyBillyAfterBattle, MSGBOX_AUTOCLOSE
	end

Route15_EventScript_Sign::
	msgbox Route15_Text_Sign, MSGBOX_SIGN
	end

Route15_EventScript_PPup::
	finditem ITEM_PP_UP
	end

Route15_Text_TeacherColetteSeen:
	.string "Tu n'as rien oublié ?$"

Route15_Text_TeacherColetteBeaten:
	.string "Kyaaah !$"

Route15_Text_TeacherColetteAfterBattle:
	.string "Avant de devenir professeur, j'oubliais\n"
	.string "souvent beaucoup de choses.$"

Route15_Text_TeacherHillarySeen:
	.string "Les jours ensoleillés, je pense que les\n"
	.string "enfants préféreraient jouer dans la cour\l"
	.string "plutôt qu'étudier en classe.$"

Route15_Text_TeacherHillaryBeaten:
	.string "Je ne voulais pas perdre…$"

Route15_Text_TeacherHillaryAfterBattle:
	.string "Étudier, c'est important, mais\n"
	.string "l'exercice est tout aussi vital.$"

Route15_Text_SchoolboyKippSeen:
	.string "Attends. Je dois appeler ma mère.$"

Route15_Text_SchoolboyKippBeaten:
	.string "Pardon, Maman ! J'ai été battu !$"

Route15_Text_SchoolboyKippAfterBattle:
	.string "Ma maman s'inquiète tellement pour moi que\n"
	.string "je dois l'appeler tout le temps.$"

Route15_Text_SchoolboyTommySeen:
	.string "Combattons. Je ne perdrai pas !$"

Route15_Text_SchoolboyTommyBeaten:
	.string "J'ai oublié de faire mes devoirs !$"

Route15_Text_SchoolboyTommyAfterBattle:
	.string "Sayonara ! Je viens d'apprendre ça\n"
	.string "en cours de japonais.$"

Route15_Text_SchoolboyJohnnySeen:
	.string "Nous sommes en sortie scolaire à la\n"
	.string "TOUR RADIO de LAVENDER VILLE pour les sciences sociales.$"

Route15_Text_SchoolboyJohnnyBeaten:
	.string "Tu es redoutablement fort !$"

Route15_Text_SchoolboyJohnnyAfterBattle:
	.string "J'en ai marre de marcher. J'ai besoin\n"
	.string "de faire une pause.$"

Route15_Text_SchoolboyBillySeen:
	.string "Mon cours préféré, c'est l'ARÈNE !$"

Route15_Text_SchoolboyBillyBeaten:
	.string "Oh, non ! Comment ai-je pu perdre ?$"

Route15_Text_SchoolboyBillyAfterBattle:
	.string "Si les POKéMON étaient une matière à l'école,\n"
	.string "je serais le meilleur !$"

Route15_Text_Sign:
	.string "ROUTE 15\p"
	.string "PARMANIE - LAVANDE$"

