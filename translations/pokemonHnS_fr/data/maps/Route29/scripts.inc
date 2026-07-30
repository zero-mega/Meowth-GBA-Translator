Route29_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route29_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route29_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route29_Trigger_Monview::
	special SpawnCameraObject
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkUp1 
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkUp1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkUp1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkUp1
	waitmovement 0
	message Route29_Text_PressAorB
	waitbuttonpress
	closemessage
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkDown1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkDown1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkDown1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkDown1
	waitmovement 0
	special RemoveCameraObject
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0
	end

Route29_Text_PressAorB:
	.string "Appuie sur A ou B pour arrêter la lecture.$"

Route29_EventScript_OldMan::
	lock
	faceplayer
	goto_if_set FLAG_ADVENTURE_STARTED, Route29_EventScript_OldMan2
	msgbox Route29_Text_OldMan1, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_OldMan2::
	msgbox Route29_Text_OldMan2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route29_EventScript_OldMan_Tutorial
	waitmessage
	msgbox Route29_Text_OldManDeclined, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_OldMan_Tutorial::
	msgbox Route29_Text_OldManExplanation, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_Lass::
	lock
	faceplayer
	msgbox Route29_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_Youngster::
	lock
	faceplayer
	msgbox Route29_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end


Route29_EventScript_Tuscany::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SILK_SCARF, Route29_EventScript_TuscanyCompleted
	msgbox Route29_Text_MeetTuscany, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, Route29_EventScript_TuscanyNope
	case 1, Route29_EventScript_TuscanyNope
	case 2, Route29_EventScript_TuscanyYes
	case 3, Route29_EventScript_TuscanyNope
	case 4, Route29_EventScript_TuscanyNope
	case 5, Route29_EventScript_TuscanyNope
	case 6, Route29_EventScript_TuscanyNope
	case 7 Route29_EventScript_TuscanyCancel
	case MULTI_B_PRESSED, Route29_EventScript_TuscanyCancel
	closemessage
	release
	end
Route29_EventScript_TuscanyYes::
	msgbox Route29_Text_TuscanyGivesGift, MSGBOX_DEFAULT
	giveitem ITEM_SILK_SCARF
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_SILK_SCARF
	msgbox Route29_Text_TuscanyGaveGift, MSGBOX_DEFAULT
	closemessage
	release
	end
Route29_EventScript_TuscanyNope::
	msgbox Route29_Text_TuscanyNope, MSGBOX_DEFAULT
	closemessage
	release
	end
Route29_EventScript_TuscanyCancel::
	closemessage
	release
	end
Route29_EventScript_TuscanyCompleted::
	msgbox Route29_Text_TuscanyTuesday, MSGBOX_DEFAULT
	closemessage
	release
	end



Route29_EventScript_Girl::
	lock
	faceplayer
	msgbox Route29_Text_Girl, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_Boy::
	lock
	faceplayer
	goto_if_set FLAG_NIGHT_POKEMON, Route29_EventScript_Boy2
	msgbox Route29_Text_Boy_WaitingForDay, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_Boy2::
	msgbox Route29_Text_Boy_WaitingForNight, MSGBOX_DEFAULT
	closemessage
	release
	end

Route29_EventScript_Sign::
	lock
	msgbox Route29_Text_Sign1, MSGBOX_SIGN
	closemessage
	release
	end

Route29_EventScript_ItemPotion::
	finditem ITEM_POTION
	end

Route29_Text_OldMan1:
	.string "Les POKéMON se cachent dans l'herbe.\n"
	.string "On ne sait jamais quand ils sortiront…$"

Route29_Text_OldMan2:
	.string "Je t'ai vu quelques fois. Combien\n"
	.string "de POKéMON as-tu attrapés ?\p"
	.string "Tu veux que je t'explique\n"
	.string "comment attraper des POKéMON ?$"

Route29_Text_OldManExplanation:
	.string "Si tu les affaiblis d'abord, les\n"
	.string "POKéMON sont plus faciles à attraper.\p"
	.string "Ensuite, lance une BALL depuis ton\n"
	.string "SAC ! N'importe quelle BALL fera\p"
	.string "l'affaire. Si tu veux en savoir\n"
	.string "plus, va à l'ACADÉMIE de MAUVILLE\p"
	.string "! Les élèves savent beaucoup\n"
	.string "de choses sur les POKéMON.$"

Route29_Text_OldManDeclined:
	.string "Oh. D'accord, alors. Explore chaque\p"
	.string "route pour trouver différents types\n"
	.string "de POKéMON. Ton POKéDEX montre\p"
	.string "aussi où tu peux les\n"
	.string "trouver ! Si tu veux\p"
	.string "en savoir plus, va\n"
	.string "à l'ACADÉMIE de MAUVILLE\p"
	.string "! Les élèves savent\n"
	.string "beaucoup sur les POKéMON.$"

Route29_Text_Youngster:
	.string "Yo. Comment vont tes POKéMON ?\p"
	.string "S'ils sont faibles et pas prêts\n"
	.string "au combat, évite les hautes herbes.$"

Route29_Text_Lass:
	.string "Tu vois ces saillies ? C'est\n"
	.string "effrayant de sauter. Mais tu peux\p"
	.string "aller à BOURG GEON sans\n"
	.string "marcher dans les hautes herbes.$"

Route29_Text_Girl:
	.string "Je voulais faire une pause,\n"
	.string "alors j'ai sauvegardé pour enregistrer ma progression.$"

Route29_Text_Boy_WaitingForDay:
	.string "J'attends des POKéMON qui\n"
	.string "n'apparaissent que plus tard dans la journée.$"

Route29_Text_Boy_WaitingForNight:
	.string "J'attends des POKéMON qui\n"
	.string "n'apparaissent que la nuit.$"

Route29_Text_MeetTuscany:
	.string "TUSCANY : Je crois que c'est\n"
	.string "la première fois qu'on se rencontre ?\p"
	.string "Je suis TUSCANY de la FAMILLE DES JOURS.\p"
	.string "Si tu devines mon jour préféré,\n"
	.string "je te donnerai une récompense.$"

Route29_Text_TuscanyNope:
	.string "Pas tout à fait !$"

Route29_Text_TuscanyGivesGift:
	.string "Oui ! Pour te faire connaître,\n"
	.string "accepte ce cadeau, un FOULARD\l"
	.string "SOIE.$"

Route29_Text_TuscanyGaveGift:
	.string "TUSCANY : Tu ne trouves pas que\n"
	.string "c'est adorable ?\p"
	.string "Il renforce les attaques de type\n"
	.string "NORMAL.\p"
	.string "Je suis sûre que ça te sera utile.$"

Route29_Text_TuscanyTuesday:
	.string "TUSCANY : Tu as rencontré\n"
	.string "MONICA, ma grande sœur ?\p"
	.string "Ou mon petit frère WESLEY\p"
	.string "? Je suis le\n"
	.string "troisième de sept enfants.$"

Route29_Text_Sign1:
	.string "ROUTE 29\p"
	.string "VILLE GRIOTTE - BOURG GÉON$"

