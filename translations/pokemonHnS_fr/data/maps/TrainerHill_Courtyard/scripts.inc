TrainerHill_Courtyard_MapScripts::
map_script MAP_SCRIPT_ON_TRANSITION, TrainerHill_Courtyard_OnTransition
	.byte 0

TrainerHill_Courtyard_OnTransition::
	setvar VAR_TRAINER_HILL_IS_ACTIVE, 0
	end

TrainerHill_Courtyard_EventScript_BattleTowerSign::
	lock
	msgbox BattleTowerOutsideSignText, MSGBOX_SIGN	
	closemessage	
	release
	end

TrainerHill_Courtyard_EventScript_Tent_Factory::
	lock
	msgbox BattleTower_Battle_Tent_Text_Factory, MSGBOX_SIGN	
	closemessage	
	release
	end

TrainerHill_Courtyard_EventScript_Tent_Palace::
	lock
	msgbox BattleTower_Battle_Tent_Text_Palace, MSGBOX_SIGN	
	closemessage	
	release
	end

TrainerHill_Courtyard_EventScript_Tent_Arena::
	lock
	msgbox BattleTower_Battle_Tent_Text_Arena, MSGBOX_SIGN	
	closemessage	
	release
	end
	
TrainerHill_Courtyard_EventScript_Engineer::
	lock
	faceplayer
	msgbox BattleTowerOutsideText_Closed, MSGBOX_DEFAULT
	closemessage
	release
	end

TrainerHill_Courtyard_EventScript_Youngster::
	lock
	faceplayer
	msgbox BattleTowerOutsideYoungsterText, MSGBOX_DEFAULT
	closemessage
	release
	end

TrainerHill_Courtyard_EventScript_Beauty::
	lock
	faceplayer
	msgbox BattleTowerOutsideBeautyText, MSGBOX_DEFAULT
	closemessage
	release
	end

TrainerHill_Courtyard_EventScript_Sailor::
	lock
	faceplayer
	msgbox BattleTowerOutsideSailorText, MSGBOX_DEFAULT
	closemessage
	release
	end

BattleTowerOutsideYoungsterText:
	.string "Ouah, le MONT DRESSEUR est énorme !\p"
	.string "Il doit y avoir plein de\n"
	.string "POKéMON différents là-dedans !$"

BattleTowerOutsideBeautyText:
	.string "Dans les TENTES DE COMBAT, tu\n"
	.string "ne peux utiliser que trois\p"
	.string "POKéMON. C'est si dur de\n"
	.string "décider lesquels envoyer au combat…$"

BattleTowerOutsideSailorText:
	.string "Héhéhé, je me suis échappé du travail.\p"
	.string "Je ne peux pas partir tant que je n'ai pas gagné !\p"
	.string "Je dois tout gagner. C'est obligatoire !$"

BattleTowerOutsideSignText:
	.string "{UP_ARROW} ENTRÉE DU MONT DRESSEUR\p"
	.string "« À vos marques, DRESSEURS de\n"
	.string "plein feu ! »\p"
	.string "{RIGHT_ARROW} TENTES DE COMBAT.$"

BattleTower_Battle_Tent_Text_Factory:
	.string "TENTE DE COMBAT : USINE\n"
	.string "« Trouve-le ! Le POKéMON ultime ! »$"

BattleTower_Battle_Tent_Text_Palace:
	.string "TENTE DE COMBAT : PALAIS\n"
	.string "« Régalez vos yeux de combats ! »$"

BattleTower_Battle_Tent_Text_Arena:
	.string "TENTE DE COMBAT : ARÈNE\n"
	.string "« Que les plus grandes équipes se réunissent ! »$"

BattleTowerOutsideText_Closed:
	.string "La COLLINE DES DRESSEURS est\n"
	.string "actuellement fermée pour réparations.$"


TrainerHill_Courtyard_EventScript_LeftMoveTutor::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_1
	goto_if_set FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR, TrainerHill_Courtyard_EventScript_AlreadyMetLeftTutor
	msgbox TrainerHill_Courtyard_Text_LeftTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_BEAUTY_MOVE_TUTOR
	goto TrainerHill_Courtyard_EventScript_ChooseLeftTutorMove
	end

TrainerHill_Courtyard_EventScript_AlreadyMetLeftTutor::
	msgbox TrainerHill_Courtyard_Text_LeftTutorWelcomeBack, MSGBOX_DEFAULT
	goto TrainerHill_Courtyard_EventScript_ChooseLeftTutorMove
	end

TrainerHill_Courtyard_EventScript_ChooseLeftTutorMove::
	message TrainerHill_Courtyard_Text_TeachWhichMove
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, TrainerHill_Courtyard_EventScript_Softboiled
	case 1, TrainerHill_Courtyard_EventScript_SeismicToss
	case 2, TrainerHill_Courtyard_EventScript_DreamEater
	case 3, TrainerHill_Courtyard_EventScript_MegaPunch
	case 4, TrainerHill_Courtyard_EventScript_MegaKick
	case 5, TrainerHill_Courtyard_EventScript_BodySlam
	case 6, TrainerHill_Courtyard_EventScript_RockSlide
	case 7, TrainerHill_Courtyard_EventScript_Counter
	case 8, TrainerHill_Courtyard_EventScript_ThunderWave
	case 9, TrainerHill_Courtyard_EventScript_SwordsDance
	case 10, TrainerHill_Courtyard_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, TrainerHill_Courtyard_EventScript_ExitTutorMoveSelect
	end

TrainerHill_Courtyard_EventScript_ChooseNewLeftTutorMove::
	message TrainerHill_Courtyard_Text_TeachWhichMove
	waitmessage
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 0
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_1
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, TrainerHill_Courtyard_EventScript_Softboiled
	case 1, TrainerHill_Courtyard_EventScript_SeismicToss
	case 2, TrainerHill_Courtyard_EventScript_DreamEater
	case 3, TrainerHill_Courtyard_EventScript_MegaPunch
	case 4, TrainerHill_Courtyard_EventScript_MegaKick
	case 5, TrainerHill_Courtyard_EventScript_BodySlam
	case 6, TrainerHill_Courtyard_EventScript_RockSlide
	case 7, TrainerHill_Courtyard_EventScript_Counter
	case 8, TrainerHill_Courtyard_EventScript_ThunderWave
	case 9, TrainerHill_Courtyard_EventScript_SwordsDance
	case 10, TrainerHill_Courtyard_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, TrainerHill_Courtyard_EventScript_ExitTutorMoveSelect
	end

TrainerHill_Courtyard_EventScript_Softboiled::
	setvar VAR_0x8008, 16
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_SeismicToss::
	setvar VAR_0x8008, 24
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_DreamEater::
	setvar VAR_0x8008, 24
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_MegaPunch::
	setvar VAR_0x8008, 24
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_MegaKick::
	setvar VAR_0x8008, 48
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_BodySlam::
	setvar VAR_0x8008, 48
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_RockSlide::
	setvar VAR_0x8008, 48
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_Counter::
	setvar VAR_0x8008, 48
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_ThunderWave::
	setvar VAR_0x8008, 48
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_SwordsDance::
	setvar VAR_0x8008, 48
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_RightMoveTutor::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_2
	goto_if_set FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR, TrainerHill_Courtyard_EventScript_AlreadyMetRightTutor
	msgbox TrainerHill_Courtyard_Text_RightTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_SWIMMER_MOVE_TUTOR
	goto TrainerHill_Courtyard_EventScript_ChooseRightTutorMove
	end

TrainerHill_Courtyard_EventScript_AlreadyMetRightTutor::
	msgbox TrainerHill_Courtyard_Text_RightTutorWelcomeBack, MSGBOX_DEFAULT
	goto TrainerHill_Courtyard_EventScript_ChooseRightTutorMove
	end

TrainerHill_Courtyard_EventScript_ChooseRightTutorMove::
	message TrainerHill_Courtyard_Text_TeachWhichMove
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, TrainerHill_Courtyard_EventScript_DefenseCurl
	case 1, TrainerHill_Courtyard_EventScript_Snore
	case 2, TrainerHill_Courtyard_EventScript_MudSlap
	case 3, TrainerHill_Courtyard_EventScript_Swift
	case 4, TrainerHill_Courtyard_EventScript_IcyWind
	case 5, TrainerHill_Courtyard_EventScript_Endure
	case 6, TrainerHill_Courtyard_EventScript_PsychUp
	case 7, TrainerHill_Courtyard_EventScript_IcePunch
	case 8, TrainerHill_Courtyard_EventScript_ThunderPunch
	case 9, TrainerHill_Courtyard_EventScript_FirePunch
	case 10, TrainerHill_Courtyard_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, TrainerHill_Courtyard_EventScript_ExitTutorMoveSelect
	end

TrainerHill_Courtyard_EventScript_ChooseNewRightTutorMove::
	message TrainerHill_Courtyard_Text_TeachWhichMove
	waitmessage
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 1
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_2
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, TrainerHill_Courtyard_EventScript_DefenseCurl
	case 1, TrainerHill_Courtyard_EventScript_Snore
	case 2, TrainerHill_Courtyard_EventScript_MudSlap
	case 3, TrainerHill_Courtyard_EventScript_Swift
	case 4, TrainerHill_Courtyard_EventScript_IcyWind
	case 5, TrainerHill_Courtyard_EventScript_Endure
	case 6, TrainerHill_Courtyard_EventScript_PsychUp
	case 7, TrainerHill_Courtyard_EventScript_IcePunch
	case 8, TrainerHill_Courtyard_EventScript_ThunderPunch
	case 9, TrainerHill_Courtyard_EventScript_FirePunch
	case 10, TrainerHill_Courtyard_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, TrainerHill_Courtyard_EventScript_ExitTutorMoveSelect
	end

TrainerHill_Courtyard_EventScript_DefenseCurl::
	setvar VAR_0x8008, 16
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_Snore::
	setvar VAR_0x8008, 24
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_MudSlap::
	setvar VAR_0x8008, 24
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_Swift::
	setvar VAR_0x8008, 24
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_IcyWind::
	setvar VAR_0x8008, 24
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_Endure::
	setvar VAR_0x8008, 48
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_PsychUp::
	setvar VAR_0x8008, 48
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_IcePunch::
	setvar VAR_0x8008, 48
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_ThunderPunch::
	setvar VAR_0x8008, 48
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_FirePunch::
	setvar VAR_0x8008, 48
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_ElementalMoveTutor::
	lock
	faceplayer
	setvar VAR_TEMP_C, SCROLL_MULTI_BF_MOVE_TUTOR_3
	goto_if_set FLAG_MET_FRONTIER_ELEMENTAL_MOVE_TUTOR, TrainerHill_Courtyard_EventScript_AlreadyMetElementalTutor
	msgbox TrainerHill_Courtyard_Text_ElementalTutorIntro, MSGBOX_DEFAULT
	setflag FLAG_MET_FRONTIER_ELEMENTAL_MOVE_TUTOR
	goto TrainerHill_Courtyard_EventScript_ChooseElementalTutorMove
	end

TrainerHill_Courtyard_EventScript_AlreadyMetElementalTutor::
	msgbox TrainerHill_Courtyard_Text_ElementalTutorWelcomeBack, MSGBOX_DEFAULT
	goto TrainerHill_Courtyard_EventScript_ChooseElementalTutorMove
	end

TrainerHill_Courtyard_EventScript_ChooseElementalTutorMove::
	message TrainerHill_Courtyard_Text_TeachWhichMoveElemental
	waitmessage
	special ShowBattlePointsWindow
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 2
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_3
	setvar VAR_0x8006, 0
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, TrainerHill_Courtyard_EventScript_FrenzyPlant
	case 1, TrainerHill_Courtyard_EventScript_BlastBurn
	case 2, TrainerHill_Courtyard_EventScript_HydroCannon
	case 3, TrainerHill_Courtyard_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, TrainerHill_Courtyard_EventScript_ExitTutorMoveSelect
	end

TrainerHill_Courtyard_EventScript_ChooseNewElementalTutorMove::
	message TrainerHill_Courtyard_Text_TeachWhichMoveElemental
	waitmessage
	setvar VAR_TEMP_FRONTIER_TUTOR_ID, 2
	setvar VAR_0x8004, SCROLL_MULTI_BF_MOVE_TUTOR_3
	setvar VAR_0x8006, 1
	special ShowScrollableMultichoice
	waitstate
	copyvar VAR_TEMP_FRONTIER_TUTOR_SELECTION, VAR_RESULT
	switch VAR_RESULT
	case 0, TrainerHill_Courtyard_EventScript_FrenzyPlant
	case 1, TrainerHill_Courtyard_EventScript_BlastBurn
	case 2, TrainerHill_Courtyard_EventScript_HydroCannon
	case 3, TrainerHill_Courtyard_EventScript_ExitTutorMoveSelect
	case MULTI_B_PRESSED, TrainerHill_Courtyard_EventScript_ExitTutorMoveSelect
	end

TrainerHill_Courtyard_EventScript_FrenzyPlant::
	setvar VAR_0x8008, 64
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_BlastBurn::
	setvar VAR_0x8008, 64
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_HydroCannon::
	setvar VAR_0x8008, 64
	goto TrainerHill_Courtyard_EventScript_ConfirmMoveSelection
	end

TrainerHill_Courtyard_EventScript_ExitTutorMoveSelect::
	special CloseBattleFrontierTutorWindow
	special CloseBattlePointsWindow
	msgbox TrainerHill_Courtyard_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end

TrainerHill_Courtyard_EventScript_CancelChooseMon::
	msgbox TrainerHill_Courtyard_Text_YouDontWantTo, MSGBOX_DEFAULT
	release
	end

@ VAR_0x8008 is the price
@ VAR_TEMP_C is the scroll multichoice ID
@ VAR_TEMP_FRONTIER_TUTOR_SELECTION is the move selection
@ VAR_TEMP_FRONTIER_TUTOR_ID is which move tutor was spoken to
TrainerHill_Courtyard_EventScript_ConfirmMoveSelection::
	copyvar VAR_0x8004, VAR_TEMP_FRONTIER_TUTOR_SELECTION
	copyvar VAR_0x8005, VAR_TEMP_FRONTIER_TUTOR_ID
	special BufferBattleFrontierTutorMoveName
	buffernumberstring STR_VAR_2, VAR_0x8008
	copyvar VAR_0x8004, VAR_TEMP_C
	msgbox TrainerHill_Courtyard_Text_MoveWillBeXBattlePoints, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_EventScript_ChooseNewMove
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, TrainerHill_Courtyard_EventScript_TeachTutorMove
	msgbox TrainerHill_Courtyard_Text_HaventGotEnoughPoints, MSGBOX_DEFAULT
	goto TrainerHill_Courtyard_EventScript_ChooseNewMove
	end

TrainerHill_Courtyard_EventScript_TeachTutorMove::
	msgbox TrainerHill_Courtyard_Text_TeachMoveToWhichMon, MSGBOX_DEFAULT
	special GetBattleFrontierTutorMoveIndex
	fadescreen FADE_TO_BLACK
	special CloseBattlePointsWindow
	special CloseBattleFrontierTutorWindow
	special ChooseMonForMoveTutor
	waitstate
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Courtyard_EventScript_CancelChooseMon
	msgbox TrainerHill_Courtyard_Text_IllTakeBattlePoints, MSGBOX_DEFAULT
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	release
	end

TrainerHill_Courtyard_EventScript_ChooseNewMove::
	goto_if_eq VAR_TEMP_FRONTIER_TUTOR_ID, 0, TrainerHill_Courtyard_EventScript_ChooseNewLeftTutorMove
	goto_if_eq VAR_TEMP_FRONTIER_TUTOR_ID, 2, TrainerHill_Courtyard_EventScript_ChooseNewElementalTutorMove
	goto TrainerHill_Courtyard_EventScript_ChooseNewRightTutorMove
	end

TrainerHill_Courtyard_Text_LeftTutorIntro:
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

TrainerHill_Courtyard_Text_LeftTutorWelcomeBack:
	.string "Buhahaha !\p"
	.string "Tu es revenu apprendre des capacités\n"
	.string "spéciales et pourtant mignonnes ?$"

TrainerHill_Courtyard_Text_TeachWhichMove:
	.string "D'accord, d'accord, regarde !\n"
	.string "Quelle attaque dois-je enseigner ?$"

TrainerHill_Courtyard_Text_MoveWillBeXBattlePoints:
	.string "La capacité {STR_VAR_1}, c'est ça ?\n"
	.string "Ça fera {STR_VAR_2} Points de Combat, d'accord ?$"

TrainerHill_Courtyard_Text_TeachMoveToWhichMon:
	.string "D'accord, d'accord, choisis le POKéMON\n"
	.string "auquel je dois enseigner la capacité.$"

TrainerHill_Courtyard_Text_HaventGotEnoughPoints:
	.string "Quoi…\n"
	.string "Tu n'as pas assez de Points de Combat !$"

TrainerHill_Courtyard_Text_IllTakeBattlePoints:
	.string "Tu vois à quel point je suis habile maintenant ?\n"
	.string "Je prends tes Points de Combat, merci !$"

TrainerHill_Courtyard_Text_YouDontWantTo:
	.string "Quoi ?\n"
	.string "Tu ne veux pas…\p"
	.string "Si tu veux voir mes talents,\n"
	.string "viens me voir quand tu veux !$"

TrainerHill_Courtyard_Text_RightTutorIntro:
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

TrainerHill_Courtyard_Text_RightTutorWelcomeBack:
	.string "Ihihihi !\p"
	.string "Es-tu venu apprendre des capacités\n"
	.string "POKéMON dures et jolies ?$"

TrainerHill_Courtyard_Text_ThinkLadiesDontGetAlong:
	.string "Ces dames, la façon dont elles se critiquent\n"
	.string "l'une l'autre, tu crois probablement qu'elles\l"
	.string "ne s'entendent pas.\p"
	.string "Mais si c'était vrai, elles ne\n"
	.string "resteraient pas ici ensemble, n'est-ce pas ?$"

TrainerHill_Courtyard_Text_LadiesWereStrongAndBeautiful:
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

TrainerHill_Courtyard_Text_SoftboiledDesc::
	.string "Restaure jusqu'à\n"
	.string "la moitié des PV\n"
	.string "max du lanceur.$"

TrainerHill_Courtyard_Text_SeismicTossDesc::
	.string "Inflige des dégâts\n"
	.string "identiques au\n"
	.string "niveau du lanceur.$"

TrainerHill_Courtyard_Text_DreamEaterDesc::
	.string "Récupère la moitié\n"
	.string "des dégâts infligés\n"
	.string "à un ennemi endormi.$"

TrainerHill_Courtyard_Text_MegaPunchDesc::
	.string "Un puissant coup de poing\n"
	.string "porté avec une\n"
	.string "force incroyable.$"

TrainerHill_Courtyard_Text_MegaKickDesc::
	.string "Un coup de pied\n"
	.string "extrêmement puissant\n"
	.string "avec une force intense.$"

TrainerHill_Courtyard_Text_BodySlamDesc::
	.string "Un plaquage corporel qui peut\n"
	.string "provoquer\n"
	.string "la paralysie.$"

TrainerHill_Courtyard_Text_RockSlideDesc::
	.string "De gros rochers\n"
	.string "sont lancés. Peut\n"
	.string "apeurer l'ennemi.$"

TrainerHill_Courtyard_Text_CounterDesc::
	.string "Riposte à toute attaque\n"
	.string "physique avec le\n"
	.string "double de puissance.$"

TrainerHill_Courtyard_Text_ThunderWaveDesc::
	.string "Une faible décharge\n"
	.string "électrique qui\n"
	.string "paralyse l'ennemi.$"

TrainerHill_Courtyard_Text_SwordsDanceDesc::
	.string "Une danse de combat qui\n"
	.string "augmente fortement\n"
	.string "l'ATTAQUE.$"

TrainerHill_Courtyard_Text_DefenseCurlDesc::
	.string "Se recroqueville pour\n"
	.string "cacher ses points\n"
	.string "faibles et monter la DÉFENSE.$"

TrainerHill_Courtyard_Text_SnoreDesc::
	.string "Une attaque bruyante\n"
	.string "utilisable uniquement\n"
	.string "pendant le sommeil.$"

TrainerHill_Courtyard_Text_MudSlapDesc::
	.string "Jette de la boue au\n"
	.string "visage de l'ennemi\n"
	.string "pour réduire sa précision.$"

TrainerHill_Courtyard_Text_SwiftDesc::
	.string "Projette des rayons en forme\n"
	.string "d'étoile\n"
	.string "qui ne ratent jamais.$"

TrainerHill_Courtyard_Text_IcyWindDesc::
	.string "Une attaque glaciale qui\n"
	.string "baisse la VITESSE\n"
	.string "de l'ennemi.$"

TrainerHill_Courtyard_Text_EndureDesc::
	.string "Encaisse n'importe quelle\n"
	.string "attaque pendant 1 tour\n"
	.string "en gardant 1 PV.$"

TrainerHill_Courtyard_Text_PsychUpDesc::
	.string "Copie le(s) effet(s)\n"
	.string "de l'ennemi et les\n"
	.string "donne à l'utilisateur.$"

TrainerHill_Courtyard_Text_IcePunchDesc::
	.string "Un coup de poing glacé\n"
	.string "qui peut geler\n"
	.string "l'ennemi.$"

TrainerHill_Courtyard_Text_ThunderPunchDesc::
	.string "Un coup de poing électrique qui\n"
	.string "peut paralyser\n"
	.string "l'ennemi.$"

TrainerHill_Courtyard_Text_FirePunchDesc::
	.string "Un coup de poing de feu\n"
	.string "qui peut brûler\n"
	.string "l'ennemi.$"

TrainerHill_Courtyard_Text_ElementalTutorIntro::
	.string "Zzzzzz… Quoi, comment, quoi ?\p"
	.string "Oh, pardon, je faisais un\p"
	.string "petit somme. Je suis le\p"
	.string "MAÎTRE ÉLÉMENTAIRE. J'ai le pouvoir\p"
	.string "d'enseigner les capacités les\n"
	.string "plus puissantes aux POKéMON\l"
	.string "PLANTE, FEU et EAU.\p"
	.string "Tu es venu apprendre\n"
	.string "une telle puissance ?$"

TrainerHill_Courtyard_Text_ElementalTutorWelcomeBack:
	.string "Zzzzzz…\p"
	.string "Quoi, comment, quoi, qui ?\p"
	.string "Oh, tu es venu apprendre la\n"
	.string "puissance de mes capacités les plus fortes ?$"

TrainerHill_Courtyard_Text_TeachWhichMoveElemental::
	.string "Quelle attaque te semble adaptée\n"
	.string "à ton POKéMON ?$"

TrainerHill_Courtyard_Text_StrongElementalMoveDesc::
	.string "Puissante, mais\n"
	.string "immobilise le lanceur\n"
	.string "pendant un tour.$"

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkWelcome::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize, MSGBOX_DEFAULT
	special ShowBattlePointsWindow
	return

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkGoodbye::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ThankYouVisitWithPoints, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize::
	specialvar VAR_TEMP_1, GetFrontierBattlePoints
	goto_if_ge VAR_TEMP_1, VAR_0x8008, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryGivePrize
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_DontHaveEnoughPoints, MSGBOX_DEFAULT
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR2_CLERK, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor2
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseVitamin
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseHoldItem
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryGivePrize::
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryGiveDecor
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR2_CLERK, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryGiveDecor
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryGiveItem
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryGiveDecor::
	checkdecorspace VAR_0x8009
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_NoRoomForDecor
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	adddecoration VAR_0x8009
	special UpdateBattlePointsWindow
	playse SE_SHOP
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_WellSendItToPC, MSGBOX_DEFAULT
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor2
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_NoRoomForDecor::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_PCIsFull, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryGiveItem::
	checkitemspace VAR_0x8009
	goto_if_eq VAR_RESULT, FALSE, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_BagFull
	copyvar VAR_0x8004, VAR_0x8008
	special TakeFrontierBattlePoints
	additem VAR_0x8009
	special UpdateBattlePointsWindow
	playse SE_SHOP
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_HereIsYourPrize, MSGBOX_DEFAULT
	goto_if_eq VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseVitamin
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseHoldItem
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_BagFull::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_DontHaveSpaceToHoldIt, MSGBOX_DEFAULT
	special CloseBattlePointsWindow
	release
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_DecorClerk1::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_DECOR1_CLERK
	call TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_DECOR_VENDOR_1
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_KissPoster
	case 1, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_KissCushion
	case 2, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_SmoochumDoll
	case 3, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TogepiDoll
	case 4, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_MeowthDoll
	case 5, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClefairyDoll
	case 6, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_DittoDoll
	case 7, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_CyndaquilDoll
	case 8, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChikoritaDoll
	case 9, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TotodileDoll
	case 10, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_KissPoster::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmKissPoster, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 16
	setvar VAR_0x8009, DECOR_KISS_POSTER
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_KissCushion::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmKissCushion, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 32
	setvar VAR_0x8009, DECOR_KISS_CUSHION
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_SmoochumDoll::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmSmoochumDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 32
	setvar VAR_0x8009, DECOR_SMOOCHUM_DOLL
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TogepiDoll::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmTogepiDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, DECOR_TOGEPI_DOLL
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_MeowthDoll::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmMeowthDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, DECOR_MEOWTH_DOLL
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClefairyDoll::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmClefairyDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, DECOR_CLEFAIRY_DOLL
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_DittoDoll::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmDittoDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, DECOR_DITTO_DOLL
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_CyndaquilDoll::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmCyndaquilDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 80
	setvar VAR_0x8009, DECOR_CYNDAQUIL_DOLL
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChikoritaDoll::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmChikoritaDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 80
	setvar VAR_0x8009, DECOR_CHIKORITA_DOLL
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TotodileDoll::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmTotodileDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor1
	setvar VAR_0x8008, 80
	setvar VAR_0x8009, DECOR_TOTODILE_DOLL
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_DecorClerk2::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_DECOR2_CLERK
	call TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor2
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor2::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_DECOR_VENDOR_2
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_LaprasDoll
	case 1, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_SnorlaxDoll
	case 2, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_VenusaurDoll
	case 3, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_CharizardDoll
	case 4, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_BlastoiseDoll
	case 5, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_LaprasDoll::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmLaprasDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor2
	setvar VAR_0x8008, 128
	setvar VAR_0x8009, DECOR_LAPRAS_DOLL
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_SnorlaxDoll::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmSnorlaxDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor2
	setvar VAR_0x8008, 128
	setvar VAR_0x8009, DECOR_SNORLAX_DOLL
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_VenusaurDoll::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmVenusaurDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor2
	setvar VAR_0x8008, 256
	setvar VAR_0x8009, DECOR_VENUSAUR_DOLL
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_CharizardDoll::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmCharizardDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor2
	setvar VAR_0x8008, 256
	setvar VAR_0x8009, DECOR_CHARIZARD_DOLL
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_BlastoiseDoll::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmBlastoiseDoll, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseDecor2
	setvar VAR_0x8008, 256
	setvar VAR_0x8009, DECOR_BLASTOISE_DOLL
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_VitaminClerk::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_VITAMIN_CLERK
	call TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseVitamin
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseVitamin::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_VITAMIN_VENDOR
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Protein
	case 1, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Calcium
	case 2, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Iron
	case 3, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Zinc
	case 4, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Carbos
	case 5, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_HpUp
	case 6, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_YouAlreadyHaveThis::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_YouAlreadyHaveThis, MSGBOX_DEFAULT
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseVitamin
	release
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Protein::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmProtein, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_PROTEIN
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Calcium::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmCalcium, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_CALCIUM
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Iron::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmIron, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_IRON
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Zinc::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmZinc, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_ZINC
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Carbos::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmCarbos, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_CARBOS
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_HpUp::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmHpUp, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseVitamin
	setvar VAR_0x8008, 1
	setvar VAR_0x8009, ITEM_HP_UP
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_HoldItemClerk::
	lock
	faceplayer
	setvar VAR_TEMP_2, EXCHANGE_CORNER_HOLD_ITEM_CLERK
	call TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkWelcome
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseHoldItem
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseHoldItem::
	setvar VAR_0x8004, SCROLL_MULTI_BF_EXCHANGE_CORNER_HOLD_ITEM_VENDOR
	special ShowFrontierExchangeCornerItemIconWindow
	special ShowScrollableMultichoice
	waitstate
	special CloseFrontierExchangeCornerItemIconWindow
	switch VAR_RESULT
	case 0, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Leftovers
	case 1, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_WhiteHerb
	case 2, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_QuickClaw
	case 3, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_MentalHerb
	case 4, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Brightpowder
	case 5, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChoiceBand
	case 6, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_KingsRock
	case 7, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_FocusBand
	case 8, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ScopeLens
	case 9, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkGoodbye
	case MULTI_B_PRESSED, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ClerkGoodbye
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Leftovers::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmLeftovers, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_LEFTOVERS
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_WhiteHerb::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmWhiteHerb, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_WHITE_HERB
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_QuickClaw::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmQuickClaw, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_QUICK_CLAW
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_MentalHerb::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmMentalHerb, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 48
	setvar VAR_0x8009, ITEM_MENTAL_HERB
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Brightpowder::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmBrightpowder, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_BRIGHT_POWDER
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChoiceBand::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmChoiceBand, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_CHOICE_BAND
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_KingsRock::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmKingsRock, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_KINGS_ROCK
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_FocusBand::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmFocusBand, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_FOCUS_BAND
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ScopeLens::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmScopeLens, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_ChooseHoldItem
	setvar VAR_0x8008, 64
	setvar VAR_0x8009, ITEM_SCOPE_LENS
	goto TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_TryPurchasePrize
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Man::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_GoGetYourOwnDoll, MSGBOX_NPC
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Sailor::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_ItemsWillGetMonTougher, MSGBOX_NPC
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_PokefanF::
	lock
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_GetYouAnythingYouWant, MSGBOX_DEFAULT
	release
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_RichBoy::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_WishIHadAllDolls, MSGBOX_NPC
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_Girl::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_Text_MoreBattlePointsForRecord, MSGBOX_NPC
	end

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_OldWTMan::
	msgbox TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_OldWTMan_Text, MSGBOX_NPC
	end

TrainerHill_Courtyard_ExchangeServiceCorner_Text_YouAlreadyHaveThis:
	.string "Tu possèdes déjà cet objet.$"

TrainerHill_Courtyard_ExchangeServiceCorner_EventScript_OldWTMan_Text:
	.string "Salut ! Si tu cherches le\n"
	.string "WONDERTRADE, ils sont maintenant dans\l"
	.string "chaque CENTRE POKéMON. Amuse-toi bien !$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_WelcomePleaseChoosePrize:
	.string "Bonjour, ici le SERVICE\n"
	.string "D'ÉCHANGE.\p"
	.string "Nous échangeons les Points de Combat que tu\n"
	.string "as collectés contre de jolis prix.\p"
	.string "Choisis un prix dans cette liste, s'il te plaît.$"

@ Unused
TrainerHill_Courtyard_ExchangeServiceCorner_Text_PleaseChoosePrize:
	.string "Choisis un lot dans cette liste.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmKissPoster:
	.string "Tu as choisi l'AFFICHE BAISER.\n"
	.string "Est-ce correct ?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmKissCushion:
	.string "Tu as choisi le COUSSIN BAISER.\n"
	.string "Est-ce correct ?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmSmoochumDoll:
	.string "Tu as choisi la POUPÉE LIPPOUTI.\n"
	.string "Est-ce correct ?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmTogepiDoll:
	.string "Tu as choisi la POUPÉE TOGEPI.\n"
	.string "Est-ce correct ?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmMeowthDoll:
	.string "Tu as choisi la POUPÉE MIAOUSS.\n"
	.string "Est-ce correct ?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmClefairyDoll:
	.string "Tu as choisi la POUPÉE MÉLOFÉE.\n"
	.string "Est-ce correct ?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmDittoDoll:
	.string "Tu as choisi la POUPÉE MÉTAMORPH.\n"
	.string "Est-ce correct ?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmCyndaquilDoll:
	.string "Tu as choisi la POUPÉE HÉRICENDRE.\n"
	.string "Est-ce correct ?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmChikoritaDoll:
	.string "Tu as choisi la POUPÉE GERMINIA.\n"
	.string "Est-ce correct ?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmTotodileDoll:
	.string "Tu as choisi la POUPÉE KAIMINUS.\n"
	.string "Est-ce correct ?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmLaprasDoll:
	.string "Tu as choisi la POUPÉE LOKHLASS.\n"
	.string "Est-ce correct ?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmSnorlaxDoll:
	.string "Tu as choisi la POUPÉE RONFLEX.\n"
	.string "Est-ce correct ?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmVenusaurDoll:
	.string "Tu as choisi la POUPÉE FLORIZARRE.\n"
	.string "Est-ce correct ?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmCharizardDoll:
	.string "Tu as choisi la POUPÉE DRACAUFEU.\n"
	.string "Est-ce correct ?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmBlastoiseDoll:
	.string "Tu as choisi la POUPÉE TORTANK.\n"
	.string "Est-ce correct ?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmProtein:
	.string "Tu as choisi la PROTEINE.\n"
	.string "Est-ce correct ?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmCalcium:
	.string "Tu as choisi le CALCIUM.\n"
	.string "Est-ce correct ?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmIron:
	.string "Tu as choisi le FER.\n"
	.string "Est-ce correct ?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmZinc:
	.string "Tu as choisi le ZINC.\n"
	.string "Est-ce correct ?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmCarbos:
	.string "Tu as choisi le CARBONE.\n"
	.string "Est-ce correct ?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmHpUp:
	.string "Tu as choisi le PV PLUS.\n"
	.string "Est-ce correct ?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmBrightpowder:
	.string "Tu as choisi la POUDRE CLAIRE.\n"
	.string "Est-ce correct ?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmWhiteHerb:
	.string "Tu as choisi l'HERBE BLANCHE.\n"
	.string "Est-ce correct ?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmQuickClaw:
	.string "Tu as choisi la VIVE GRIFFE.\n"
	.string "Est-ce correct ?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmMentalHerb:
	.string "Tu as choisi l'HERBE MENTALE.\n"
	.string "Est-ce correct ?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmChoiceBand:
	.string "Tu as choisi le BANDEAU CHOIX.\n"
	.string "Est-ce correct ?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmKingsRock:
	.string "Tu as choisi la ROCHE ROYALE.\n"
	.string "Est-ce correct ?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmFocusBand:
	.string "Tu as choisi le BANDEAU.\n"
	.string "Est-ce correct ?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmScopeLens:
	.string "Tu as choisi la LOUPE.\n"
	.string "Est-ce correct ?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ConfirmLeftovers:
	.string "Tu as choisi les RESTES.\n"
	.string "Est-ce correct ?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_WellSendItToPC:
	.string "Merci !\n"
	.string "On l'enverra sur ton PC à la maison.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_HereIsYourPrize:
	.string "Voici ton prix !$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_DontHaveEnoughPoints:
	.string "Je suis désolé…\n"
	.string "Tu n'as pas assez de Points de Combat…$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_PCIsFull:
	.string "Je suis vraiment désolé…\n"
	.string "Ton PC semble être plein…$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_DontHaveSpaceToHoldIt:
	.string "Je suis vraiment désolé…\n"
	.string "Tu n'as pas de place pour le prendre…$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ThankYouVisitWithPoints:
	.string "Merci beaucoup.\p"
	.string "Reviens nous voir quand tu auras\n"
	.string "accumulé des Points de Combat.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_WishIHadAllDolls:
	.string "Oh, c'est trop mignon !\n"
	.string "J'aimerais les avoir ! De\l"
	.string "jolis coussins ! De\l"
	.string "grandes PELUCHES ! De\l"
	.string "petites PELUCHES ! Je\l"
	.string "les veux toutes !$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_GetYouAnythingYouWant:
	.string "Laisse faire maman !\p"
	.string "Si c'est ce que tu veux, j'irai au bout\n"
	.string "du monde pour te l'obtenir, chéri !$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ItemsWillGetMonTougher:
	.string "Si je récupère les objets ici,\n"
	.string "mes POKéMON deviendront plus forts.\p"
	.string "Tu paries !\n"
	.string "C'est sûr !$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_GoGetYourOwnDoll:
	.string "Hah ?\n"
	.string "Qu'est-ce que tu regardes ?\p"
	.string "Je n'aime pas que tu fixes ma poupée\n"
	.string "comme ça.\p"
	.string "Si tu en veux une, va t'en chercher une !\n"
	.string "N'est-ce pas, KISSOUMI ?$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_MoreBattlePointsForRecord:
	.string "Tu savais ?\p"
	.string "Si tu améliores ton record dans l'une des\n"
	.string "installations de COMBAT, ils commencent\l"
	.string "à te donner de plus en plus de Points de Combat.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_KissPosterDesc::
	.string "Un grand poster avec un motif LIPPOUTI.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_KissCushionDesc::
	.string "Un coussin LIPPOUTI.\n"
	.string "À placer sur un tapis ou un bureau.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_SmoochumDollDesc::
	.string "Une POUPÉE LIPPOUTI.\n"
	.string "Place-la sur un tapis ou un bureau.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_TogepiDollDesc::
	.string "Une POUPÉE TOGEPI.\n"
	.string "Place-la sur un tapis ou un bureau.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_MeowthDollDesc::
	.string "Une POUPÉE MIAOUSS.\n"
	.string "Place-la sur un tapis ou un bureau.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ClefairyDollDesc::
	.string "Une POUPÉE MÉLOFÉE.\n"
	.string "Place-la sur un tapis ou un bureau.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_DittoDollDesc::
	.string "Une POUPÉE MÉTAMORPH.\n"
	.string "Place-la sur un tapis ou un bureau.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_CyndaquilDollDesc::
	.string "Une POUPÉE HÉRICENDRE.\n"
	.string "À placer sur un tapis ou un bureau.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ChikoritaDollDesc::
	.string "Une POUPÉE GERMIGNON.\n"
	.string "À placer sur un tapis ou un bureau.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_TotodileDollDesc::
	.string "Une POUPÉE KAIMINUS.\n"
	.string "Place-la sur un tapis ou un bureau.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_LargeDollDesc::
	.string "Une grande POUPÉE.\n"
	.string "Place-la sur un tapis ou un bureau.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ProteinDesc::
	.string "Un billet étrange qui te mènera\n"
	.string "vers une île abandonnée.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_CalciumDesc::
	.string "Un billet étrange qui te mènera\n"
	.string "vers une île abandonnée.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_IronDesc::
	.string "Un billet étrange qui te mènera\n"
	.string "vers une île abandonnée.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ZincDesc::
	.string "Une… vieille carte ? Peut-être\n"
	.string "qu'elle te mènera quelque part.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_CarbosDesc::
	.string "Gain EV x10, mais divise la vitesse par 2.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_HPUpDesc::
	.string "Une boîte particulière fabriquée\n"
	.string "par SYLPHE SARL.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_LeftoversDesc::
	.string "Objet tenu qui restaure progressivement\n"
	.string "les PV en combat.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_WhiteHerbDesc::
	.string "Un objet tenu qui restaure toute\n"
	.string "stat baissée.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_QuickClawDesc::
	.string "Objet tenu qui permet\n"
	.string "parfois de frapper en premier.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_MentalHerbDesc::
	.string "Objet tenu qui sort les POKéMON\n"
	.string "de l'attirance.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_BrightpowderDesc::
	.string "Objet tenu qui lance un éclair\n"
	.string "pour baisser la précision.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ChoiceBandDesc::
	.string "Augmente la puissance d'une attaque,\n"
	.string "mais n'autorise que celle-ci.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_KingsRockDesc::
	.string "Un objet tenu qui peut faire\n"
	.string "sursauter l'ennemi quand il est touché.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_FocusBandDesc::
	.string "Un objet tenu qui empêche\n"
	.string "parfois de s'évanouir.$"

TrainerHill_Courtyard_ExchangeServiceCorner_Text_ScopeLensDesc::
	.string "Un objet tenu qui augmente\n"
	.string "le taux de critique.$"
