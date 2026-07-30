BattleFrontier_Lounge7_MapScripts::
	.byte 0

BattleFrontier_Lounge7_EventScript_LeftMoveTutor::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_1
	goto_if_set FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR, BattleFrontier_Lounge7_EventScript_AlreadyMetLeftTutor
	msgbox BattleFrontier_Lounge7_Text_LeftTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR
	goto BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove
	end

BattleFrontier_Lounge7_EventScript_AlreadyMetLeftTutor::
	msgbox BattleFrontier_Lounge7_Text_LeftTutorWelcomeBack, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove
	end

BattleFrontier_Lounge7_EventScript_ChooseLeftTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_Softboiled
	case 1, BattleFrontier_Lounge7_EventScript_SeismicToss
	case 2, BattleFrontier_Lounge7_EventScript_DreamEater
	case 3, BattleFrontier_Lounge7_EventScript_MegaPunch
	case 4, BattleFrontier_Lounge7_EventScript_MegaKick
	case 5, BattleFrontier_Lounge7_EventScript_BodySlam
	case 6, BattleFrontier_Lounge7_EventScript_RockSlide
	case 7, BattleFrontier_Lounge7_EventScript_Counter
	case 8, BattleFrontier_Lounge7_EventScript_ThunderWave
	case 9, BattleFrontier_Lounge7_EventScript_SwordsDance
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_ChooseNewLeftTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_Softboiled
	case 1, BattleFrontier_Lounge7_EventScript_SeismicToss
	case 2, BattleFrontier_Lounge7_EventScript_DreamEater
	case 3, BattleFrontier_Lounge7_EventScript_MegaPunch
	case 4, BattleFrontier_Lounge7_EventScript_MegaKick
	case 5, BattleFrontier_Lounge7_EventScript_BodySlam
	case 6, BattleFrontier_Lounge7_EventScript_RockSlide
	case 7, BattleFrontier_Lounge7_EventScript_Counter
	case 8, BattleFrontier_Lounge7_EventScript_ThunderWave
	case 9, BattleFrontier_Lounge7_EventScript_SwordsDance
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_Softboiled::
	setvar VAR_0x8008, 16
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_SeismicToss::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_DreamEater::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MegaPunch::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MegaKick::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_BodySlam::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_RockSlide::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Counter::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ThunderWave::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_SwordsDance::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_RightMoveTutor::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_2
	goto_if_set FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR, BattleFrontier_Lounge7_EventScript_AlreadyMetRightTutor
	msgbox BattleFrontier_Lounge7_Text_RightTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR
	goto BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_AlreadyMetRightTutor::
	msgbox BattleFrontier_Lounge7_Text_RightTutorWelcomeBack, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_ChooseRightTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_DefenseCurl
	case 1, BattleFrontier_Lounge7_EventScript_Snore
	case 2, BattleFrontier_Lounge7_EventScript_MudSlap
	case 3, BattleFrontier_Lounge7_EventScript_Swift
	case 4, BattleFrontier_Lounge7_EventScript_IcyWind
	case 5, BattleFrontier_Lounge7_EventScript_Endure
	case 6, BattleFrontier_Lounge7_EventScript_PsychUp
	case 7, BattleFrontier_Lounge7_EventScript_IcePunch
	case 8, BattleFrontier_Lounge7_EventScript_ThunderPunch
	case 9, BattleFrontier_Lounge7_EventScript_FirePunch
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_ChooseNewRightTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMove
	waitmessage
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_DefenseCurl
	case 1, BattleFrontier_Lounge7_EventScript_Snore
	case 2, BattleFrontier_Lounge7_EventScript_MudSlap
	case 3, BattleFrontier_Lounge7_EventScript_Swift
	case 4, BattleFrontier_Lounge7_EventScript_IcyWind
	case 5, BattleFrontier_Lounge7_EventScript_Endure
	case 6, BattleFrontier_Lounge7_EventScript_PsychUp
	case 7, BattleFrontier_Lounge7_EventScript_IcePunch
	case 8, BattleFrontier_Lounge7_EventScript_ThunderPunch
	case 9, BattleFrontier_Lounge7_EventScript_FirePunch
	case 10, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_DefenseCurl::
	setvar VAR_0x8008, 16
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Snore::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_MudSlap::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Swift::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_IcyWind::
	setvar VAR_0x8008, 24
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_Endure::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_PsychUp::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_IcePunch::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ThunderPunch::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_FirePunch::
	setvar VAR_0x8008, 48
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ElementalMoveTutor::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_3
	goto_if_set FLAG_MET_FRONTIER_ELEMENTAL_MOVE_TUTOR, BattleFrontier_Lounge7_EventScript_AlreadyMetElementalTutor
	msgbox BattleFrontier_Lounge7_Text_ElementalTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_ELEMENTAL_MOVE_TUTOR
	goto BattleFrontier_Lounge7_EventScript_ChooseElementalTutorMove
	end

BattleFrontier_Lounge7_EventScript_AlreadyMetElementalTutor::
	msgbox BattleFrontier_Lounge7_Text_ElementalTutorWelcomeBack, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseElementalTutorMove
	end

BattleFrontier_Lounge7_EventScript_ChooseElementalTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMoveElemental
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 2
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_3
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_FrenzyPlant
	case 1, BattleFrontier_Lounge7_EventScript_BlastBurn
	case 2, BattleFrontier_Lounge7_EventScript_HydroCannon
	case 3, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_ChooseNewElementalTutorMove::
	message BattleFrontier_Lounge7_Text_TeachWhichMoveElemental
	waitmessage
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 2
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_3
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge7_EventScript_FrenzyPlant
	case 1, BattleFrontier_Lounge7_EventScript_BlastBurn
	case 2, BattleFrontier_Lounge7_EventScript_HydroCannon
	case 3, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect
	end

BattleFrontier_Lounge7_EventScript_FrenzyPlant::
	setvar VAR_0x8008, 64
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_BlastBurn::
	setvar VAR_0x8008, 64
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_HydroCannon::
	setvar VAR_0x8008, 64
	goto BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection
	end

BattleFrontier_Lounge7_EventScript_ExitTutorMoveSelect::
	special CloseBattleFrontierTutorWindow
	special CloseBattlePointsWindow
	msgbox BattleFrontier_Lounge7_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge7_EventScript_CancelChooseMon::
	msgbox BattleFrontier_Lounge7_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end

@ VAR_0x8008 is the price
@ VAR_TEMP_C is the scroll multichoice ID
@ VAR_TEMP_FRONTIER_TUTOR_SELECTION is the move selection
@ VAR_TEMP_FRONTIER_TUTOR_ID is which move tutor was spoken to
BattleFrontier_Lounge7_EventScript_ConfirmMoveSelection::
	copyvar VAR_0x8004, VAR_TEMP_FRONTIER_TUTOR_SELECTION
	copyvar VAR_0x8005, VAR_TEMP_FRONTIER_TUTOR_ID
	special BufferBattleFrontierTutorMoveName
	buffernumberstring STR_VAR_2, VAR_0x8008
	copyvar VAR_0x8004, VAR_TEMP_C
	msgbox BattleFrontier_Lounge7_Text_MoveWillBeXBattlePoints, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge7_EventScript_ChooseNewMove
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, BattleFrontier_Lounge7_EventScript_TeachTutorMove
	msgbox BattleFrontier_Lounge7_Text_HaventGotEnoughPoints, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge7_EventScript_ChooseNewMove
	end

BattleFrontier_Lounge7_EventScript_TeachTutorMove::
	msgbox BattleFrontier_Lounge7_Text_TeachMoveToWhichMon, MSGBOX_DEFAULT
	special GetBattleFrontierTutorMoveIndex
	fadescreen FADE_TO_BLACK
	special CloseBattlePointsWindow
	special CloseBattleFrontierTutorWindow
	special ChooseMonForMoveTutor
	waitstate
	goto_if_eq VAR_RESULT, FALSE, BattleFrontier_Lounge7_EventScript_CancelChooseMon
	msgbox BattleFrontier_Lounge7_Text_IllTakeBattlePoints, MSGBOX_DEFAULT
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	release
	end

BattleFrontier_Lounge7_EventScript_ChooseNewMove::
	goto_if_eq VAR_TEMP_FRONTIER_TUTOR_ID, 0, BattleFrontier_Lounge7_EventScript_ChooseNewLeftTutorMove
	goto_if_eq VAR_TEMP_FRONTIER_TUTOR_ID, 2, BattleFrontier_Lounge7_EventScript_ChooseNewElementalTutorMove
	goto BattleFrontier_Lounge7_EventScript_ChooseNewRightTutorMove
	end

BattleFrontier_Lounge7_EventScript_Sailor::
	msgbox BattleFrontier_Lounge7_Text_ThinkLadiesDontGetAlong, MSGBOX_NPC
	end

BattleFrontier_Lounge7_EventScript_Gentleman::
	msgbox BattleFrontier_Lounge7_Text_LadiesWereStrongAndBeautiful, MSGBOX_NPC
	end

BattleFrontier_Lounge7_Text_LeftTutorIntro:
	.string "Buhahaha !\p"
	.string "Tu ne le dirais pas en regardant maintenant,\n"
	.string "mais j'étais autrefois une DRESSEUSE coriace.\p"
	.string "J'avais la réputation d'être la TOPDRESSEUSE\n"
	.string "la plus dure, je te le dis !\p"
	.string "… … … … … …\p"
	.string "Qu'est-ce qu'il y a ?\n"
	.string "Tu ne me crois pas.\p"
	.string "Je ne suis pas comme cette fanfarone\n"
	.string "là-bas. J'ai vraiment du talent !\p"
	.string "Laisse-moi te le prouver.\n"
	.string "Je peux apprendre à tes POKéMON des capacités\l"
	.string "spéciales et pourtant mignonnes.\p"
	.string "Mais mes leçons ne sont pas gratuites.\n"
	.string "Que dirais-tu de payer les capacités que j'enseigne\l"
	.string "avec un peu de Points de Combat ?$"

BattleFrontier_Lounge7_Text_LeftTutorWelcomeBack:
	.string "Buhahaha !\p"
	.string "Tu es revenu apprendre des capacités\n"
	.string "spéciales et pourtant mignonnes ?$"

BattleFrontier_Lounge7_Text_TeachWhichMove:
	.string "D'accord, d'accord, regarde !\n"
	.string "Quelle attaque dois-je enseigner ?$"

BattleFrontier_Lounge7_Text_MoveWillBeXBattlePoints:
	.string "La capacité {STR_VAR_1}, c'est ça ?\n"
	.string "Ça fera {STR_VAR_2} Points de Combat, d'accord ?$"

BattleFrontier_Lounge7_Text_TeachMoveToWhichMon:
	.string "D'accord, d'accord, choisis le POKéMON\n"
	.string "auquel je dois enseigner la capacité.$"

BattleFrontier_Lounge7_Text_HaventGotEnoughPoints:
	.string "Quoi…\n"
	.string "Tu n'as pas assez de Points de Combat !$"

BattleFrontier_Lounge7_Text_IllTakeBattlePoints:
	.string "Tu vois à quel point je suis habile maintenant ?\n"
	.string "Je prends tes Points de Combat, merci !$"

BattleFrontier_Lounge7_Text_YouDontWantTo:
	.string "Quoi ?\n"
	.string "Tu ne veux pas…\p"
	.string "Si tu veux voir mes talents,\n"
	.string "viens me voir quand tu veux !$"

BattleFrontier_Lounge7_Text_RightTutorIntro:
	.string "Ihihihi !\p"
	.string "Je sais que c'est difficile à voir maintenant, mais j'étais\n"
	.string "autrefois un DRESSEUR fantastique.\p"
	.string "J'avais la réputation d'être le\n"
	.string "NAGEUR le plus invincible, je te le dis !\p"
	.string "… … … … … …\p"
	.string "Qu'est-ce qui ne va pas ?\n"
	.string "Tu ne me crois pas.\p"
	.string "Je ne suis pas comme cette femme fanfarone\n"
	.string "là-bas. J'ai vraiment de l'expérience !\p"
	.string "Je peux te le prouver.\n"
	.string "Je peux apprendre à tes POKéMON des capacités\l"
	.string "dures et pourtant jolies.\p"
	.string "Mais mes leçons ne sont pas gratuites.\n"
	.string "Que dirais-tu de payer les capacités que j'enseigne\l"
	.string "avec un peu de Points de Combat ?$"

BattleFrontier_Lounge7_Text_RightTutorWelcomeBack:
	.string "Ihihihi !\p"
	.string "Es-tu venu apprendre des capacités\n"
	.string "POKéMON dures et jolies ?$"

BattleFrontier_Lounge7_Text_ThinkLadiesDontGetAlong:
	.string "Ces dames, la façon dont elles se critiquent\n"
	.string "l'une l'autre, tu crois probablement qu'elles\l"
	.string "ne s'entendent pas.\p"
	.string "Mais si c'était vrai, elles ne\n"
	.string "resteraient pas ici ensemble, n'est-ce pas ?$"

BattleFrontier_Lounge7_Text_LadiesWereStrongAndBeautiful:
	.string "Quand\n"
	.string "j'étais juste\p"
	.string "un jeune GAMIN,\p"
	.string "ces dames étaient\n"
	.string "fortes et belles.\p"
	.string "Elles étaient\n"
	.string "des idoles\p"
	.string "parmi nous jeunes.\n"
	.string "Les FILLES KIMONO\p"
	.string "sont légendaires !$"

BattleFrontier_Lounge7_Text_SoftboiledDesc::
	.string "Restaure jusqu'à\n"
	.string "la moitié des PV\n"
	.string "max du lanceur.$"

BattleFrontier_Lounge7_Text_SeismicTossDesc::
	.string "Inflige des dégâts\n"
	.string "identiques au\n"
	.string "niveau du lanceur.$"

BattleFrontier_Lounge7_Text_DreamEaterDesc::
	.string "Récupère la moitié\n"
	.string "des dégâts infligés\n"
	.string "à un ennemi endormi.$"

BattleFrontier_Lounge7_Text_MegaPunchDesc::
	.string "Un puissant coup de poing\n"
	.string "porté avec une\n"
	.string "force incroyable.$"

BattleFrontier_Lounge7_Text_MegaKickDesc::
	.string "Un coup de pied\n"
	.string "extrêmement puissant\n"
	.string "avec une force intense.$"

BattleFrontier_Lounge7_Text_BodySlamDesc::
	.string "Un plaquage corporel qui peut\n"
	.string "provoquer\n"
	.string "la paralysie.$"

BattleFrontier_Lounge7_Text_RockSlideDesc::
	.string "De gros rochers\n"
	.string "sont lancés. Peut\n"
	.string "apeurer l'ennemi.$"

BattleFrontier_Lounge7_Text_CounterDesc::
	.string "Riposte à toute attaque\n"
	.string "physique avec le\n"
	.string "double de puissance.$"

BattleFrontier_Lounge7_Text_ThunderWaveDesc::
	.string "Une faible décharge\n"
	.string "électrique qui\n"
	.string "paralyse l'ennemi.$"

BattleFrontier_Lounge7_Text_SwordsDanceDesc::
	.string "Une danse de combat qui\n"
	.string "augmente fortement\n"
	.string "l'ATTAQUE.$"

BattleFrontier_Lounge7_Text_DefenseCurlDesc::
	.string "Se recroqueville pour\n"
	.string "cacher ses points\n"
	.string "faibles et monter la DÉFENSE.$"

BattleFrontier_Lounge7_Text_SnoreDesc::
	.string "Une attaque bruyante\n"
	.string "utilisable uniquement\n"
	.string "pendant le sommeil.$"

BattleFrontier_Lounge7_Text_MudSlapDesc::
	.string "Jette de la boue au\n"
	.string "visage de l'ennemi\n"
	.string "pour réduire sa précision.$"

BattleFrontier_Lounge7_Text_SwiftDesc::
	.string "Projette des rayons en forme\n"
	.string "d'étoile\n"
	.string "qui ne ratent jamais.$"

BattleFrontier_Lounge7_Text_IcyWindDesc::
	.string "Une attaque glaciale qui\n"
	.string "baisse la VITESSE\n"
	.string "de l'ennemi.$"

BattleFrontier_Lounge7_Text_EndureDesc::
	.string "Encaisse n'importe quelle\n"
	.string "attaque pendant 1 tour\n"
	.string "en gardant 1 PV.$"

BattleFrontier_Lounge7_Text_PsychUpDesc::
	.string "Copie le(s) effet(s)\n"
	.string "de l'ennemi et les\n"
	.string "donne à l'utilisateur.$"

BattleFrontier_Lounge7_Text_IcePunchDesc::
	.string "Un coup de poing glacé\n"
	.string "qui peut geler\n"
	.string "l'ennemi.$"

BattleFrontier_Lounge7_Text_ThunderPunchDesc::
	.string "Un coup de poing électrique qui\n"
	.string "peut paralyser\n"
	.string "l'ennemi.$"

BattleFrontier_Lounge7_Text_FirePunchDesc::
	.string "Un coup de poing de feu\n"
	.string "qui peut brûler\n"
	.string "l'ennemi.$"

BattleFrontier_Lounge7_Text_ElementalTutorIntro::
	.string "Zzzzzz… Quoi, comment, quoi ?\p"
	.string "Oh, pardon, je faisais un\p"
	.string "petit somme. Je suis le\p"
	.string "MAÎTRE ÉLÉMENTAIRE. J'ai le pouvoir\p"
	.string "d'enseigner les capacités les\n"
	.string "plus puissantes aux POKéMON\l"
	.string "PLANTE, FEU et EAU.\p"
	.string "Tu es venu apprendre\n"
	.string "une telle puissance ?$"

BattleFrontier_Lounge7_Text_ElementalTutorWelcomeBack:
	.string "Zzzzzz…\p"
	.string "Quoi, comment, quoi, qui ?\p"
	.string "Oh, tu es venu apprendre la\n"
	.string "puissance de mes capacités les plus fortes ?$"

BattleFrontier_Lounge7_Text_TeachWhichMoveElemental::
	.string "Quelle attaque te semble adaptée\n"
	.string "à ton POKéMON ?$"

BattleFrontier_Lounge7_Text_StrongElementalMoveDesc::
	.string "Puissante, mais\n"
	.string "immobilise le lanceur\n"
	.string "pendant un tour.$"
