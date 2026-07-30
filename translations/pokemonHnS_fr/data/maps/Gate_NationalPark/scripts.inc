Gate_NationalPark_MapScripts::
	.byte 0

Gate_NationalPark_EventScript_Attendant::
	lockall
	faceplayer
	goto_if_set FLAG_DAILY_BUG_CONTEST_COMPLETED, Gate_NationalPark_EventScript_AttendantAlreadyPlayed
	msgbox Route35NationalParkGate_Text_OfficerAskToParticipate, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Gate_NationalPark_EventScript_AttendantStart
	msgbox Route35NationalParkGate_Text_TakePartInFuture, MSGBOX_DEFAULT
	releaseall
	end

Gate_NationalPark_EventScript_AttendantStart::
	msgbox Route35NationalParkGate_Text_OfficerAskToUseFirstMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Gate_NationalPark_EventScript_AttendantCancel
	getpartysize
	call_if_eq VAR_RESULT, 1, Gate_NationalPark_EventScript_OnlyOneMon
	msgbox Route35NationalParkGate_Text_OfficerHoldYourMon, MSGBOX_DEFAULT
	closemessage
	special SavePlayerParty
	remove5mons
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, Gate_NationalPark_EventScript_AttendantFaint
	playfanfare MUS_OBTAIN_ITEM
	message Route35NationalParkGate_Text_MonLeftWithHelper
	waitfanfare
	closemessage
	msgbox Route35NationalParkGate_Text_OfficerGiveParkBalls, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_SAFARI_BALL, 30
	closemessage
	msgbox Route35NationalParkGate_Text_OfficerExplainRules, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_WEST, Gate_NationalPark_EventScript_AttendantEnterTop
	call_if_eq VAR_FACING, DIR_NORTH, Gate_NationalPark_EventScript_AttendantEnterBot
	playse SE_EXIT
	clearflag FLAG_HIDE_BUG_CONTEST_ATTENDANT_SIDE
	special EnterBugContestMode
	setvar VAR_BUG_CONTEST_STATE, 1
	warp MAP_NATIONAL_PARK_BUG_CONTEST, 1
	waitstate
	end

Gate_NationalPark_EventScript_OnlyOneMon::
	special SavePlayerParty
	msgbox Route35NationalParkGate_Text_OfficerGiveParkBalls, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_SAFARI_BALL, 30
	closemessage
	msgbox Route35NationalParkGate_Text_OfficerExplainRules, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_WEST, Gate_NationalPark_EventScript_AttendantEnterTop
	call_if_eq VAR_FACING, DIR_NORTH, Gate_NationalPark_EventScript_AttendantEnterBot
	playse SE_EXIT
	clearflag FLAG_HIDE_BUG_CONTEST_ATTENDANT_SIDE
	special EnterBugContestMode
	setvar VAR_BUG_CONTEST_STATE, 1
	warp MAP_NATIONAL_PARK_BUG_CONTEST, 1
	waitstate
	end

Gate_NationalPark_EventScript_AttendantEnterTop::
	applymovement OBJ_EVENT_ID_PLAYER, Gate_NationalPark_Movement_Player_EnterParkTop
	waitmovement 0
	return

Gate_NationalPark_EventScript_AttendantEnterBot::
	applymovement OBJ_EVENT_ID_PLAYER, Gate_NationalPark_Movement_Player_EnterParkBot
	waitmovement 0
	return


Gate_NationalPark_EventScript_AttendantFaint::	
	msgbox Route35NationalParkGate_Text_FirstMonCantBattle, MSGBOX_DEFAULT
	closemessage
	release
	end	

Gate_NationalPark_EventScript_AttendantCancel::	
	msgbox Route35NationalParkGate_Text_TakePartInFuture, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_NationalPark_EventScript_AttendantAlreadyPlayed::
	msgbox Route35NationalParkGate_Text_ContestIsOver, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_NationalPark_EventScript_AttendantExit::
	special LoadPlayerParty
	setvar VAR_BUG_CONTEST_STATE, 0
	release
	end

Gate_NationalPark_Movement_Player_EnterParkTop:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

Gate_NationalPark_Movement_Player_EnterParkBot:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	step_end

Gate_NationalPark_EventScript_BAttendant::
	lockall
	faceplayer
	goto_if_set FLAG_DAILY_BUG_CONTEST_COMPLETED, Gate_NationalPark_EventScript_AttendantAlreadyPlayed
	msgbox Route35NationalParkGate_Text_OfficerAskToParticipate, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Gate_NationalPark_EventScript_BAttendantStart
	msgbox Route35NationalParkGate_Text_TakePartInFuture, MSGBOX_DEFAULT
	releaseall
	end

Gate_NationalPark_EventScript_BAttendantStart::
	msgbox Route35NationalParkGate_Text_OfficerAskToUseFirstMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Gate_NationalPark_EventScript_AttendantCancel
	getpartysize
	call_if_eq VAR_RESULT, 1, Gate_NationalPark_EventScript_OnlyOneMonB
	msgbox Route35NationalParkGate_Text_OfficerHoldYourMon, MSGBOX_DEFAULT
	closemessage
	special SavePlayerParty
	remove5mons
	goto_if_eq VAR_RESULT, MON_CANT_GIVE, Gate_NationalPark_EventScript_AttendantFaint
	playfanfare MUS_OBTAIN_ITEM
	message Route35NationalParkGate_Text_MonLeftWithHelper
	waitfanfare
	closemessage
	msgbox Route35NationalParkGate_Text_OfficerGiveParkBalls, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_SAFARI_BALL, 30
	closemessage
	msgbox Route35NationalParkGate_Text_OfficerExplainRules, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_EAST, Gate_NationalPark_EventScript_AttendantBEnterTop
	call_if_eq VAR_FACING, DIR_NORTH, Gate_NationalPark_EventScript_AttendantBEnterBot
	playse SE_EXIT
	special EnterBugContestMode
	setflag FLAG_HIDE_BUG_CONTEST_ATTENDANT_SIDE
	setvar VAR_BUG_CONTEST_STATE, 5
	warp MAP_NATIONAL_PARK_BUG_CONTEST, 40, 19
	waitstate
	end

Gate_NationalPark_EventScript_OnlyOneMonB::
	special SavePlayerParty
	msgbox Route35NationalParkGate_Text_OfficerGiveParkBalls, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_SAFARI_BALL, 30
	closemessage
	msgbox Route35NationalParkGate_Text_OfficerExplainRules, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_EAST, Gate_NationalPark_EventScript_AttendantBEnterTop
	call_if_eq VAR_FACING, DIR_NORTH, Gate_NationalPark_EventScript_AttendantBEnterBot
	playse SE_EXIT
	special EnterBugContestMode
	setflag FLAG_HIDE_BUG_CONTEST_ATTENDANT_SIDE
	setvar VAR_BUG_CONTEST_STATE, 5
	warp MAP_NATIONAL_PARK_BUG_CONTEST, 40, 19
	waitstate
	end

Gate_NationalPark_EventScript_AttendantBEnterTop::
	applymovement OBJ_EVENT_ID_PLAYER, Gate_NationalPark_Movement_Player_EnterParkTopB
	waitmovement 0
	return

Gate_NationalPark_EventScript_AttendantBEnterBot::
	applymovement OBJ_EVENT_ID_PLAYER, Gate_NationalPark_Movement_Player_EnterParkBotB
	waitmovement 0
	return

Gate_NationalPark_Movement_Player_EnterParkTopB:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_in_place_left
	step_end

Gate_NationalPark_Movement_Player_EnterParkBotB:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_left
	step_end

Route35NationalParkGate_Text_OfficerAskToParticipate:
	.string "Bonjour Dresseur ! La Chasse aux Insectes\n"
	.string "a lieu aujourd'hui.\p"
	.string "Les règles sont simples.\p"
	.string "Avec un de tes POKéMON, attrape un\n"
	.string "POKéMON insecte pour qu'il soit jugé.\p"
	.string "Tu veux essayer ?$"

Route35NationalParkGate_Text_OfficerGiveParkBalls:
	.string "Tout l'EXP que tes POKéMON gagnent pendant\n"
	.string "le concours sera annulé quand\l"
	.string "tu partiras.\p"
	.string "Voici les SAFARI BALLS pour le\n"
	.string "Concours.$"

Route35NationalParkGate_Text_ReceivedParkBalls:
	.string "{PLAYER} a reçu des SAFARI BALLS.$"

Route35NationalParkGate_Text_OfficerExplainRules:
	.string "La personne\n"
	.string "qui attrape\p"
	.string "le POKéMON insecte\n"
	.string "le plus fort\p"
	.string "est le gagnant.\n"
	.string "Si tu n'as plus\l"
	.string "de SAFARI BALLS,\p"
	.string "tu es disqualifié.\n"
	.string "Bonne chance !$"

Route35NationalParkGate_Text_OfficerAskToUseFirstMon:
	.string "Si tu as plus d'un\n"
	.string "POKéMON, tu devras utiliser le\l"
	.string "premier POKéMON de ton équipe.\p"
	.string "Ça te convient ?$"

Route35NationalParkGate_Text_OfficerHoldYourMon:
	.string "Très bien, nous garderons tes autres POKéMON\n"
	.string "pendant que tu participes.$"

Route35NationalParkGate_Text_MonLeftWithHelper:
	.string "Les POKéMON de {PLAYER} ont été confiés\n"
	.string "à l'ASSISTANT DE CONCOURS.$"

Route35NationalParkGate_Text_ChooseMonAndComeBack:
	.string "Choisis le POKéMON à utiliser\n"
	.string "au CONCOURS, puis viens me voir.$"

Route35NationalParkGate_Text_TakePartInFuture:
	.string "OK. On espère que tu participeras\n"
	.string "à l'avenir.$"

Route35NationalParkGate_Text_FirstMonCantBattle:
	.string "Oh-oh… Le premier POKéMON de ton\n"
	.string "équipe ne peut pas combattre.\p"
	.string "Échange-le avec le POKéMON que tu\n"
	.string "veux utiliser, puis reviens me voir.$"

Route35NationalParkGate_Text_MakeRoom:
	.string "Oups… Ton équipe et ta\n"
	.string "BOÎTE PC sont pleines.\p"
	.string "Tu n'as pas de place pour mettre le POKéMON\n"
	.string "insecte que tu attrapes.\p"
	.string "Fais de la place dans ton équipe ou\n"
	.string "ta BOÎTE PC, puis reviens me voir.$"

Route35NationalParkGate_Text_EggAsFirstMon:
	.string "Oh oh… Tu as un ŒUF comme premier\n"
	.string "POKéMON dans ton équipe.\p"
	.string "Échange-le avec le POKéMON\n"
	.string "que tu veux utiliser, puis reviens me voir.$"

Route35NationalParkGate_Text_ContestIsOver:
	.string "Le Concours d'aujourd'hui est terminé.\n"
	.string "Nous espérons que tu participeras à l'avenir.$"

Route35NationalParkGate_EventScript_Policeman::
	lock
	faceplayer
	msgbox Route35NationalParkGate_Text_WeHoldContests, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35NationalParkGate_EventScript_BC1::
	lock
	faceplayer
	msgbox Route35NationalParkGate_Text_YoungsterWonders, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35NationalParkGate_EventScript_BC2::
	lock
	faceplayer
	msgbox Route35NationalParkGate_Text_BC2, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35NationalParkGate_EventScript_Rocker::
	lock
	faceplayer
	msgbox Route35NationalParkGate_Text_Rocker, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35NationalParkGate_EventScript_Beauty::
	lock
	faceplayer
	msgbox Route35NationalParkGate_Text_Beauty, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35NationalParkGate_Text_Rocker:
	.string "J'adore les POKéMON OISEAU ! J'ai trouvé un\n"
	.string "oiseau de type TÉNÈBRES dans le parc\l"
	.string "la nuit dernière !$"

Route35NationalParkGate_Text_BC2:
	.string "J'ai attrapé un INSÉCATEUR énorme !$"

Route35NationalParkGate_Text_Beauty:
	.string "Il gagne toujours ces concours !$"

Route35NationalParkGate_Text_WeHoldContests:
	.string "On organise régulièrement des Concours\n"
	.string "dans le PARC. Tu devrais essayer !$"

Route35NationalParkGate_Text_YoungsterWonders:
	.string "Quand aura lieu le prochain Concours\n"
	.string "de Capture d'Insectes ?$"

Route35NationalParkGate_Text_ContestExplanation:
	.string "Le Concours de Capture d'Insectes\n"
	.string "a lieu le mardi, jeudi\p"
	.string "et samedi. Tu gagnes des\n"
	.string "points en attrapant des\p"
	.string "POKéMON INSECTE. Le gagnant\n"
	.string "reçoit une CT !$"
