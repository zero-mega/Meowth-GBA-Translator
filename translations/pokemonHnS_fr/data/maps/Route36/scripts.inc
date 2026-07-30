.set LOCALID_ROUTE36_SUDOWOODO, 6
.set LOCALID_ROUTE36_ROCKSMASHGUY, 3

Route36_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route36_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route36_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route36_EventScript_RockSmashGuy::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SUDOWOODO, Route36_EventScript_RockSmashGuy2
	msgbox Route36_Text_RockSmashGuy1, MSGBOX_DEFAULT
	closemessage
	release
	end
Route36_EventScript_RockSmashGuy2::
	goto_if_set FLAG_RECEIVED_HM_ROCK_SMASH, Route36_EventScript_RockSmashGuy3
	msgbox Route36_Text_RockSmashGuy2, MSGBOX_DEFAULT
	giveitem ITEM_HM_ROCK_SMASH
	setflag FLAG_RECEIVED_HM_ROCK_SMASH
Route36_EventScript_RockSmashGuy3::
	msgbox Route36_Text_RockSmashGuy3
	closemessage
	release
	end

Route36_EventScript_Lass::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SUDOWOODO, Route36_EventScript_Lass2
	msgbox Route36_Text_Lass1, MSGBOX_DEFAULT
	closemessage
	release
	end
Route36_EventScript_Lass2::
	msgbox Route36_Text_Lass2_ClearedSudowoodo, MSGBOX_DEFAULT
	closemessage
	release
	end

Route36_EventScript_Arthur::
	lock
	faceplayer
	goto_if_set FLAG_GOT_HARD_STONE, Route36_EventScript_ArthurCompleted
	msgbox Route36_Text_MeetArthur, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, Route36_EventScript_ArthurNope
	case 1, Route36_EventScript_ArthurNope
	case 2, Route36_EventScript_ArthurNope
	case 3, Route36_EventScript_ArthurNope
	case 4, Route36_EventScript_ArthurYes
	case 5, Route36_EventScript_ArthurNope
	case 6, Route36_EventScript_ArthurNope
	case 7, Route36_EventScript_ArthurCancel
	case MULTI_B_PRESSED, Route36_EventScript_ArthurCancel
	closemessage
	release
	end
Route36_EventScript_ArthurYes::
	msgbox Route36_Text_ArthurGivesGift, MSGBOX_DEFAULT
	giveitem ITEM_HARD_STONE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_HARD_STONE
	msgbox Route36_Text_ArthurGaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end
Route36_EventScript_ArthurNope::
	msgbox Route36_Text_ArthurNope, MSGBOX_DEFAULT
	closemessage
	release
	end
Route36_EventScript_ArthurCancel::
	closemessage
	release
	end
Route36_EventScript_ArthurCompleted::
	msgbox Route36_Text_ArthurThursday, MSGBOX_DEFAULT
	closemessage
	release
	end


Route36_EventScript_SudoWoodo::
	lock
	msgbox Route36_Text_OddTree, MSGBOX_DEFAULT
	checkitem ITEM_SQUIRT_BOTTLE
	goto_if_eq VAR_RESULT, TRUE, Route36_EventScript_SudoWoodoChoice
	closemessage
	release
	end
Route36_EventScript_SudoWoodoChoice::
	msgbox Route36_Text_UseSquirtbottle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route36_EventScript_SudoWoodoWater
	closemessage
	release
	end
Route36_EventScript_SudoWoodoWater::
	msgbox Route36_Text_UsedSquirtbottle, MSGBOX_DEFAULT
	playse SE_DOWNPOUR
	waitse
	closemessage
	playse SE_SUDOWOODO_SHAKE	
	applymovement LOCALID_ROUTE36_SUDOWOODO, Route36_Movement_SudoWoodo
	waitmovement 0
	faceplayer
	msgbox Route36_Text_SudowoodoAttacked	
	closemessage
	waitse
	playmoncry SPECIES_SUDOWOODO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_ROUTE36_SUDOWOODO
	setwildbattle SPECIES_SUDOWOODO, 20
	@setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	@clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Route36_EventScript_Defeated_Sudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route36_EventScript_RanSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, Route36_EventScript_RanSudowoodo
Route36_EventScript_Defeated_Sudowoodo::
	setflag FLAG_HIDE_SUDOWOODO
	removeobject LOCALID_ROUTE36_SUDOWOODO
	checkitem ITEM_HM_ROCK_SMASH
	call_if_eq VAR_RESULT, FALSE, Route36_EventScript_RockSmashGuySudoWoodo
	release
	end

Route36_EventScript_RanSudowoodo::
	turnobject LOCALID_ROUTE36_SUDOWOODO, DIR_NORTH
	release
	end

Route36_EventScript_RockSmashGuySudoWoodo:
	playse SE_PIN
	applymovement LOCALID_ROUTE36_ROCKSMASHGUY, Common_Movement_ExclamationMark
	turnobject LOCALID_ROUTE36_ROCKSMASHGUY, DIR_WEST
	waitmovement 0
	applymovement LOCALID_ROUTE36_ROCKSMASHGUY, Route36_Movement_RockSmashGuy
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitse
	playse SE_LEDGE
	waitmovement 0
	return

Route36_Movement_RockSmashGuy:
	jump_in_place_left
	delay_2
	jump_in_place_left
	delay_2
	jump_in_place_left
	delay_2
	jump_in_place_left
	step_end

Route36_EventScript_Mark::
	trainerbattle_single TRAINER_MARK Route36_Text_PsychicMarkSeen, Route36_Text_PsychicMarkBeaten
	msgbox Route36_Text_PsychicMarkAfter, MSGBOX_AUTOCLOSE
	end

Route36_EventScript_Schoolboy::
	trainerbattle_single TRAINER_ALAN Route36_Text_SchoolboyAlan1Seen, Route36_Text_SchoolboyAlan1Beaten
	msgbox Route36_Text_SchoolboyAlanAfter, MSGBOX_AUTOCLOSE
	end

Route36_EventScript_Sign::
	lock
	msgbox Route36_Text_Sign_RuinsNorth, MSGBOX_SIGN
	closemessage
	release
	end

Route36_EventScript_Sign2::
	lock
	msgbox Route36_Text_Tips1, MSGBOX_SIGN
	closemessage
	release
	end

Route36_Movement_SudoWoodo:
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	step_end

Route36_Text_UseSquirtbottle:
	.string "Utiliser le FLACON ?$"

Route36_Text_UsedSquirtbottle:
	.string "{PLAYER} a utilisé le VAPÉTISEUR.$"

Route36_Text_SudowoodoAttacked:
	.string "L'arbre bizarre n'aime pas la\n"
	.string "BOUTEILLE SQUIRT !\p"
	.string "L'arbre bizarre a attaqué !$"

Route36_Text_RockSmashGuy1:
	.string "Waouh !\p"
	.string "J'allais casser cet arbre\n"
	.string "avec mon coup de poing direct.\p"
	.string "Mais je n'ai pas pu ! Je suis nul !$"

Route36_Text_RockSmashGuy2:
	.string "Tu as débarrassé cet horrible arbre ?\p"
	.string "Je suis impressionné !\n"
	.string "Je veux te donner ça.$"

Route36_Text_RockSmashGuy3:
	.string "Ça, c'est ÉCLATE-ROC.\p"
	.string "Tu peux briser des rochers d'un seul\n"
	.string "coup bien placé.\p"
	.string "S'il y a des rochers sur ton chemin,\n"
	.string "écrase-les !$"

Route36_Text_OddTree:
	.string "Un arbre bizarre bloque le chemin.$"

Route36_Text_Lass1:
	.string "Fais attention la nuit sur cette\p"
	.string "route ! J'ai vu un POKéMON\n"
	.string "qui ressemblait à GROWLITHE, mais\l"
	.string "il avait une aura effrayante.$"

Route36_Text_Lass2_ClearedSudowoodo:
	.string "Cet arbre bizarre a disparu sans\n"
	.string "laisser de trace.\p"
	.string "Oh ! Cet arbre était vraiment un\n"
	.string "POKéMON ?$"

Route36_Text_PsychicMarkSeen:
	.string "Je vais lire dans tes pensées !$"

Route36_Text_PsychicMarkBeaten:
	.string "Je t'ai mal jugé !$"

Route36_Text_PsychicMarkAfter:
	.string "Je serais fort si seulement je pouvais\n"
	.string "deviner ce que pense mon adversaire.$"

Route36_Text_SchoolboyAlan1Seen:
	.string "Grâce à mes études, je suis prêt\n"
	.string "pour n'importe quel POKéMON !$"

Route36_Text_SchoolboyAlan1Beaten:
	.string "Oups ! Erreur de calcul ?$"

Route36_Text_SchoolboyAlanAfter:
	.string "Mince. J'étudie cinq heures par jour aussi.\p"
	.string "Il y a plus à apprendre que de\n"
	.string "lire des livres.$"

Route36_Text_MeetArthur:
	.string "ARTHUR : Qui es-tu ? Je\n"
	.string "suis ARTHUR de la FAMILLE DES\p"
	.string "JOURS. Si tu devines mon jour\n"
	.string "préféré, je te donnerai une récompense.$"

Route36_Text_ArthurNope:
	.string "Pas tout à fait !$"

Route36_Text_ArthurGivesGift:
	.string "Tiens. Tu peux prendre ça.$"

Route36_Text_ArthurGaveGift:
	.string "ARTHUR : Un POKéMON qui utilise des attaques\n"
	.string "de type ROCHE devrait tenir ça.\p"
	.string "Ça renforce les attaques ROCHE.$"

Route36_Text_ArthurThursday:
	.string "ARTHUR : Je suis ARTHUR du jeudi.\n"
	.string "Je suis le cinquième fils sur sept.$"

Route36_Text_Sign:
	.string "ROUTE 36$"

Route36_Text_Sign_RuinsNorth:
	.string "RUINES D'ALPHA\n"
	.string "ENTRÉE NORD$"

Route36_Text_Tips1:
	.string "CONSEILS AUX DRESSEURS\n"
	.string "Les stats des POKéMON varient--même au sein\l"
	.string "de la même espèce.\p"
	.string "Leurs stats peuvent être similaires au début.\p"
	.string "Cependant, les différences deviendront\n"
	.string "prononcées à mesure que les POKéMON grandissent.$"

Route36_Text_Tips2:
	.string "CONSEILS AUX DRESSEURS. Utilise\n"
	.string "TUNNEL pour revenir à\n"
	.string "l'entrée d'un lieu. C'est\p"
	.string "pratique pour explorer les\n"
	.string "grottes et autres sites.$"
