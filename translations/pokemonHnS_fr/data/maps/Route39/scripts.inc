.set LOCALID_R39_SHADOW, 17
.set LOCALID_R39_BAOBA, 2

Route39_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route39_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route39_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route39_EventScript_Item_TM::
	finditem ITEM_TM_BRICK_BREAK
	end

Route39_EventScript_Item_Nugget::
	finditem ITEM_BIG_NUGGET
	end

Route39_EventScript_LegendaryTrigger::
	lock
	clearflag FLAG_HIDE_ROUTE39_SHADOW
	addobject LOCALID_R39_SHADOW
	playse SE_M_RAZOR_WIND
	applymovement LOCALID_R39_SHADOW, Route39_Movement_ShadowSlideDown
	waitmovement 0
	setflag FLAG_HIDE_ROUTE39_SHADOW
	removeobject LOCALID_R39_SHADOW
	playse SE_PIN
	applymovement LOCALID_R39_BAOBA, Common_Movement_QuestionMark
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_QuestionMark
	turnobject LOCALID_R39_BAOBA DIR_SOUTH
	turnobject OBJ_EVENT_ID_PLAYER DIR_SOUTH
	delay 60

	getplayerxy VAR_TEMP_0, VAR_TEMP_1

	call_if_eq VAR_TEMP_1, 20, Route39_EventScript_BaobaMovement1
	call_if_eq VAR_TEMP_1, 21, Route39_EventScript_BaobaMovement2
	call_if_eq VAR_TEMP_1, 22, Route39_EventScript_BaobaMovement3
	call_if_eq VAR_TEMP_1, 23, Route39_EventScript_BaobaMovement4

	turnobject LOCALID_R39_BAOBA DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER DIR_WEST
Route39_EventScript_ChooseLegend::
	msgbox Route39_Text_ChooseLegend, MSGBOX_DEFAULT
	multichoice 20, 8, MULTI_GOLDSILVER, FALSE
	switch VAR_RESULT
	case 0, Route39_EventScript_LegendaryTriggerGold
	case 1, Route39_EventScript_LegendaryTriggerSilver
	case MULTI_B_PRESSED, Route39_EventScript_ChooseLegend
	release
	end

Route39_EventScript_BaobaMovement1::
	applymovement LOCALID_R39_BAOBA, Route39_Movement_Baoba1
	waitmovement 0
	return
Route39_EventScript_BaobaMovement2::
	applymovement LOCALID_R39_BAOBA, Route39_Movement_Baoba2
	waitmovement 0
	return
Route39_EventScript_BaobaMovement3::
	applymovement LOCALID_R39_BAOBA, Route39_Movement_Baoba3
	waitmovement 0
	return
Route39_EventScript_BaobaMovement4::
	applymovement LOCALID_R39_BAOBA, Route39_Movement_Baoba4
	waitmovement 0
	return

Route39_Movement_Baoba1:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end
Route39_Movement_Baoba2:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end
Route39_Movement_Baoba3:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end
Route39_Movement_Baoba4:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end

Route39_EventScript_LegendaryTriggerGold::
	setvar VAR_LUGIA_OR_HOOH, 2
	goto Route39_EventScript_BaobaIntro

Route39_EventScript_LegendaryTriggerSilver::
	setvar VAR_LUGIA_OR_HOOH, 1
	goto Route39_EventScript_BaobaIntro

Route39_EventScript_BaobaIntro::
	msgbox Route39_Text_BaobaIntro, MSGBOX_DEFAULT
	playse MUS_HG_POKEGEAR_REGISTERED
	msgbox Route39_Text_Registered, MSGBOX_DEFAULT
	waitse
	msgbox Route39_Text_WillCall, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_R39_BAOBA, Route39_Movement_BaobaLeave
	waitmovement 0
	setflag FLAG_ENABLE_BAOBA_MATCH_CALL
	removeobject LOCALID_R39_BAOBA
	release
	end

Route39_Text_ChooseLegend::
	.string "BAOBA : MON DIEU ! Cette ombre\n"
	.string "appartenait-elle à un POKéMON ?\p"
	.string "Tu as pu bien la voir ?\n"
	.string "Je ne peux pas dire de quelle couleur elle était...$"

Route39_Text_BaobaIntro::
	.string "Comme c'est étrange…\p"
	.string "…Ohh !\n"
	.string "Ce que tu tiens, c'est…\l"
	.string "ce qu'on appelle… un POKéDEX !\p"
	.string "Je n'en avais pas vu depuis des lustres.\p"
	.string "Je m'appelle BAOBA !\n"
	.string "J'ai autrefois dirigé une ZONE SAFARI à\l"
	.string "PARMANIE, mais elle\l"
	.string "devenait dépassée avec\l"
	.string "les nouvelles options de divertissement.\p"
	.string "J'ai décidé de partir à\n"
	.string "l'étranger pour apprendre\l"
	.string "les dernières technologies et ouvrir une\l"
	.string "ZONE SAFARI de pointe à OLIVILLE.\p"
	.string "Ce n'est peut-être pas un hasard\n"
	.string "que nous discutions.\p"
	.string "Pourquoi ne pas enregistrer nos numéros\n"
	.string "dans le POKéKÉA ?\p"
	.string "Je pourrai t'appeler une fois la\n"
	.string "ZONE SAFARI ouverte avant d'appeler\l"
	.string "qui que ce soit d'autre !$"

Route39_Text_Registered:
	.string "{PLAYER} a enregistré BAOBA\n"
	.string "dans le POKéGEAR !$"


Route39_Text_WillCall:
	.string "BAOBA : Je te préviendrai\n"
	.string "bientôt sur le POKéGEAR !$"

Route39_Movement_BaobaLeave:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

Route39_Movement_ShadowSlideDown:
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	slide_down
	step_end

Route39_EventScript_Woman::
	lock
	faceplayer
	msgbox Route39_Text_Woman, MSGBOX_DEFAULT
	closemessage
	release
	end

Route39_Text_Woman:
	.string "Cette ombre… C'était peut-être un\n"
	.string "géant ROUSSIL ?$"

Route39_EventScript_Miltank::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MILTANK, CRY_MODE_NORMAL
	msgbox Route39_Text_Miltank, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route39_Text_Miltank:
	.string "MILTANK : Meuuuh !$"

Route39_EventScript_Eugene::
	trainerbattle_single TRAINER_EUGENE, Route39_Text_SailorEugeneSeen, Route39_Text_SailorEugeneBeaten
	msgbox Route39_Text_SailorEugeneAfter, MSGBOX_AUTOCLOSE
	end

Route39_Text_SailorEugeneSeen:
	.string "Je viens de rentrer à OLIVILLE.\p"
	.string "Alors, un combat POKéMON ?$"

Route39_Text_SailorEugeneBeaten:
	.string "Awaaargh !$"

Route39_Text_SailorEugeneAfter:
	.string "Mes POKéMON ont été capturés et\n"
	.string "élevés à l'étranger.\p"
	.string "Ce sont mes compagnons lors\n"
	.string "de ces longs voyages.$"

Route39_EventScript_Derek::
	trainerbattle_single TRAINER_DEREK, Route39_Text_PokefanMDerekSeen, Route39_Text_PokefanMDerekBeaten
	msgbox Route39_Text_PokefanMDerekAfter, MSGBOX_AUTOCLOSE
	end

Route39_Text_PokefanMDerekSeen:
	.string "C'est le moment de me vanter\n"
	.string "de mon PIKACHU !$"

Route39_Text_PokefanMDerekBeaten:
	.string "Je n'ai pas eu le temps de montrer\n"
	.string "PIKACHU…$"

Route39_Text_PokefanMDerekAfter:
	.string "Je n'écoute pas tes\n"
	.string "fanfaronnades !\p"
	.string "Nous, les POKé FANS, avons pour politique\n"
	.string "de ne pas écouter les fanfaronnades !$"

Route39_EventScript_Ruth::
	trainerbattle_single TRAINER_RUTH, Route39_Text_PokefanFRuthSeen, Route39_Text_PokefanFRuthBeaten
	msgbox Route39_Text_PokefanFRuthAfter, MSGBOX_AUTOCLOSE
	end

Route39_Text_PokefanFRuthSeen:
	.string "Quels POKéMON adorables.\p"
	.string "Montrons nos POKéMON\n"
	.string "en même temps.$"

Route39_Text_PokefanFRuthBeaten:
	.string "Je ne suis pas fâché de perdre.$"

Route39_Text_PokefanFRuthAfter:
	.string "Tu connais les bébés\n"
	.string "POKéMON ?\p"
	.string "Je parie qu'ils sont adorables !$"

Route39_EventScript_Norman::
	trainerbattle_single TRAINER_NORMAN, Route39_Text_PsychicNormanSeen, Route39_Text_PsychicNormanBeaten
	msgbox Route39_Text_PsychicNormanAfter, MSGBOX_AUTOCLOSE
	end

Route39_Text_PsychicNormanSeen:
	.string "Laisse-moi voir ce que tes\n"
	.string "POKéMON savent faire.$"

Route39_Text_PsychicNormanBeaten:
	.string "Ooh, tes POKéMON ont\n"
	.string "du potentiel.$"

Route39_Text_PsychicNormanAfter:
	.string "Tu sais que les POKéMON ont des\n"
	.string "capacités différentes ?\p"
	.string "Les humains aussi.\n"
	.string "Chacun a un\l"
	.string "potentiel différent.$"

Route39_EventScript_Jamie::
	trainerbattle_single TRAINER_JAMIE, Route39_Text_PokefanFJaimeSeen, Route39_Text_PokefanFJaimeBeaten
	msgbox Route39_Text_PokefanFJaimeAfter, MSGBOX_AUTOCLOSE
	end

Route39_Text_PokefanFJaimeSeen:
	.string "Tu arrives au bon\n"
	.string "moment.\p"
	.string "Combattons.$"

Route39_Text_PokefanFJaimeBeaten:
	.string "Oh, quel dommage…$"

Route39_Text_PokefanFJaimeAfter:
	.string "J'ai rencontré NOCTALI la nuit\n"
	.string "ici sur la ROUTE 39.\p"
	.string "Je ne sais pas pourquoi, mais il\n"
	.string "semble aimer quand je\l"
	.string "m'entraîne ici.\p"
	.string "Il devient plus amical\n"
	.string "en s'entraînant ici qu'\l"
	.string "que nulle part ailleurs.$"

Route39_EventScript_Sign1::
	lock
	msgbox Route39_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route39_Text_Sign:
	.string "ROUTE 39\p"
	.string "OLIVILLE - ROSALIA$"

Route39_EventScript_Sign2::
	lock
	msgbox Route39_Text_MoomooFarmSign, MSGBOX_SIGN
	closemessage
	release
	end

Route39_Text_MoomooFarmSign:
	.string "FERME MEUMEU\p"
	.string "Savourez notre lait frais et délicieux$"

Route39_EventScript_Sign3::
	lock
	msgbox Route39_Text_TrainerTips, MSGBOX_SIGN
	closemessage
	release
	end

Route39_Text_TrainerTips:
	.string "CONSEILS DRESSEUR\p"
	.string "Utilise COUP D'BOULE sur les arbres pour\n"
	.string "faire tomber des POKéMON.\p"
	.string "Différents types de POKéMON\n"
	.string "tombent des arbres.\p"
	.string "Utilise COUP D'BOULE sur tous\n"
	.string "les arbres que tu vois !$"
