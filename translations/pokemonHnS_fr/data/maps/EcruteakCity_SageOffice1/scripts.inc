.set LOCALID_SAGEOFFICE_SAGE, 3

EcruteakCity_SageOffice1_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EcruteakCity_SageOffice1_OnTransition
	.byte 0

EcruteakCity_SageOffice1_OnTransition::
	goto_if_set FLAG_HIDE_TINTOWER_GUARD, EcruteakCity_SageOffice1_EventScript_SageAside
	end

EcruteakCity_SageOffice1_EventScript_SageAside::
	setobjectxyperm LOCALID_SAGEOFFICE_SAGE, 15, 2
	end

EcruteakCity_SageOffice1_EventScript_Sign::
	msgbox EcruteakCity_SageOffice1_Text_Sign, MSGBOX_SIGN
	end

EcruteakCity_SageOffice1_Text_Sign:
	.string "La cloche d'étain sonne clairement pour\n"
	.string "ceux sous l'aile de la tour.$"

EcruteakCity_SageOffice2_EventScript_SageA::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_TINTOWER_GUARD, EcruteakCity_SageOffice2_EventScript_SageA4
	checkitem ITEM_CLEAR_BELL
	goto_if_eq VAR_RESULT, TRUE, EcruteakCity_SageOffice2_EventScript_SageA2
	msgbox EcruteakTinTowerEntrance_Text_SageNoBadge, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_SageOffice2_EventScript_SageA2::
	msgbox EcruteakTinTowerEntrance_Text_SageHearsClearBell1, MSGBOX_DEFAULT
	waitmessage
	playse SE_M_PETAL_DANCE
	waitse
	playse SE_PIN
	applymovement LOCALID_SAGEOFFICE_SAGE, Common_Movement_ExclamationMark
	delay 60
	msgbox EcruteakTinTowerEntrance_Text_SageHearsClearBell2, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SAGEOFFICE_SAGE, EcruteakCity_SageOffice2_Movement_StandAside
	waitmovement 0
	setobjectxyperm LOCALID_SAGEOFFICE_SAGE, 15, 2
	setflag FLAG_HIDE_TINTOWER_GUARD
	release
	end

EcruteakCity_SageOffice2_EventScript_SageA3::
	msgbox EcruteakTinTowerEntrance_Text_SagePleaseDoGoOn, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_SageOffice2_EventScript_SageA4::
	msgbox EcruteakTinTowerEntrance_Text_SageDone, MSGBOX_DEFAULT
	closemessage
	release
	end
	
EcruteakCity_SageOffice2_EventScript_SageB::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_STATE, 10, EcruteakCity_SageOffice2_EventScript_B2
	goto_if_eq VAR_ECRUTEAK_CITY_STATE, 11, EcruteakCity_SageOffice2_EventScript_B2
	msgbox EcruteakTinTowerEntrance_Text_WanderingSage, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_SageOffice2_EventScript_B2::
	msgbox EcruteakTinTowerEntrance_Text_WanderingSageClearBell, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_SageOffice2_EventScript_SageC::
	lock
	faceplayer
	msgbox EcruteakTinTowerEntrance_Text_Gramps, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_SageOffice2_Movement_StandAside:
	walk_left
	face_down
	step_end

EcruteakTinTowerEntrance_Text_SageNoBadge:
	.string "La TOUR FER est interdite aux\n"
	.string "indignes. Désolé, mais tu dois\l"
	.string "partir.$"

EcruteakTinTowerEntrance_Text_SageWithBadge:
	.string "La TOUR CENDRÉE est interdite\n"
	.string "à quiconque n'a pas le\p"
	.string "BADGE de l'ARÈNE d'ÉCORCIA. Ah\p"
	.string "! Le BADGE d'ÉCORCIA !\n"
	.string "Passez, je vous en prie.$"

EcruteakTinTowerEntrance_Text_SageNoClearBell:
	.string "Un événement mémorable s'est produit.\p"
	.string "Je vous prie de m'excuser, mais je dois\n"
	.string "vous demander de partir.\p"
	.string "…Ce qui apaise l'âme…\p"
	.string "Le TRIO SAGE dit des choses\n"
	.string "très difficiles à comprendre…$"

EcruteakTinTowerEntrance_Text_SageHearsClearBell1:
	.string "Un événement capital s'est produit.\p"
	.string "Je vous prie de m'excuser,\n"
	.string "mais je dois vous\p"
	.string "demander de partir. ..............................$"
EcruteakTinTowerEntrance_Text_SageHearsClearBell2:
	.string "Ah ! Le son\p"
	.string "de cette Cloche Claire\p"
	.string "! C'est… C'est sublime\p"
	.string "! Je n'ai jamais\n"
	.string "entendu un son aussi\p"
	.string "beau ! Le carillon\n"
	.string "de cette cloche reflète\p"
	.string "l'âme de son porteur.\p"
	.string "Toi… Tu pourras peut-être\n"
	.string "traverser la TOUR CENDRÉE.\p"
	.string "S'il te plaît, continue.$"

EcruteakTinTowerEntrance_Text_SagePleaseDoGoOn:
	.string "Je vous en prie, continuez.$"

EcruteakTinTowerEntrance_Text_SageDone:
	.string "Le carillon de cette cloche reflète\n"
	.string "l'âme de son porteur.\p"
	.string "Toi…\n"
	.string "Tu es vraiment digne.$"

EcruteakTinTowerEntrance_Text_WanderingSage:
	.string "La TOUR CENDRÉE devant nous est une tour\n"
	.string "à neuf étages d'une beauté divine.\p"
	.string "Elle apaise l'âme de tous ceux\n"
	.string "qui la voient.$"

EcruteakTinTowerEntrance_Text_WanderingSageClearBell:
	.string "La TOUR CUIVRE a tremblé ! Un POKéMON\n"
	.string "doit être revenu au sommet !$"

EcruteakTinTowerEntrance_Text_Gramps:
	.string "Deux tours… Deux POKéMON…\p"
	.string "Mais quand l'une a brûlé, les deux\n"
	.string "POKéMON se sont envolés, pour ne jamais revenir.$"
