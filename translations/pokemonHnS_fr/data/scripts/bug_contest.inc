BugContest_EventScript_Start::
	end

BugContest_EventScript_WhiteOut::
	lockall
	delay 200
	msgbox BugContest_Text_WhiteOut, MSGBOX_DEFAULT
	closemessage
	goto BugContest_EventScript_End
	end

BugContest_EventScript_TimesUp::
	lockall
	playse SE_DING_DONG
	msgbox BugContest_Text_TimesUp, MSGBOX_DEFAULT
	closemessage
	waitse
	getpartysize
	goto_if_eq VAR_RESULT, 1, BugContest_EventScript_Didntcatch
	fadescreen FADE_TO_BLACK
	setvar VAR_BUG_CONTEST_STATE, 3
	
	msgbox BugContest_Text_Judging0, MSGBOX_DEFAULT
	closemessage
	BugContest_EventScript_TimesUp2::
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BugContest_EventScript_WrongChoiceMon
	goto_if_eq VAR_0x8004, 0, BugContest_EventScript_WrongChoiceMon
	fadescreen FADE_TO_BLACK
	warp MAP_NATIONAL_PARK_BUG_CONTEST, 5
	delay 90
	end

BugContest_EventScript_WrongChoiceMon::
	msgbox BugContest_Text_WrongChoiceMon, MSGBOX_DEFAULT
	goto BugContest_EventScript_TimesUp2
	end

BugContestEventScript_Judging::
	msgbox BugContest_Text_Judging1, MSGBOX_DEFAULT
	closemessage
	special JudgeBugContestMon
	call_if_eq VAR_RESULT, 1, BugContest_EventScript_First
	call_if_eq VAR_RESULT, 2, BugContest_EventScript_Second
	call_if_eq VAR_RESULT, 3, BugContest_EventScript_Third
	special TransferBugContestMon
	delay 20
	giveitem VAR_0x8005
	msgbox BugContest_Text_TransferAndReturn, MSGBOX_DEFAULT
	playse SE_SUCCESS
	waitse
	msgbox BugContest_Text_TakePartInFuture, MSGBOX_DEFAULT
	closemessage
	goto BugContest_EventScript_End
	end

BugContest_EventScript_Didntcatch::
	msgbox BugContest_Text_DidntCatch, MSGBOX_DEFAULT
	playse SE_SUCCESS
	closemessage
	fadescreen FADE_TO_BLACK
	goto BugContest_EventScript_End
	end

BugContest_EventScript_First::
	msgbox BugContest_Text_First1, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_BERRY
	waitfanfare
	msgbox BugContest_Text_First2, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_BERRY
	waitfanfare
	msgbox BugContest_Text_First3, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_BADGE
	waitfanfare
	closemessage
	return

BugContest_EventScript_Second::
	msgbox BugContest_Text_Second1, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_BERRY
	waitfanfare
	msgbox BugContest_Text_Second2, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_BERRY
	waitfanfare
	msgbox BugContest_Text_Second3, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_BADGE
	waitfanfare
	closemessage
	return

BugContest_EventScript_Third::
	msgbox BugContest_Text_Third1, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_BERRY
	waitfanfare
	msgbox BugContest_Text_Third2, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_BERRY
	waitfanfare
	msgbox BugContest_Text_Third3, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_BADGE
	waitfanfare
	closemessage
	return

BugContest_EventScript_End::
	special HealPlayerParty
	special LoadPlayerParty
	special ExitBugContestMode
	setvar VAR_BUG_CONTEST_STATE, 0
	special RemoveSafariBalls
	goto_if_eq VAR_TEMP_1, 1, BugContest_EventScript_SideEnd
	warp MAP_GATE_NATIONAL_PARK, 7, 2
	releaseall
	end

BugContest_EventScript_SideEnd::
	warp MAP_GATE_NATIONAL_PARK, 35, 7
	releaseall
	end

BugContest_Text_Judging0::
	.string "Le concours est maintenant terminé.\n"
	.string "Choisis le POKéMON que tu veux\l"
	.string "garder pour le jugement.$"

BugContest_Text_Judging1::
	.string "Nous allons maintenant juger les POKéMON\n"
	.string "que tu as attrapés.\p"
	.string "...................\n"
	.string "...................\p"
	.string "Nous avons choisi les gagnants ! Tu es\n"
	.string "prêt pour ça ?$"

BugContest_Text_WrongChoiceMon:
	.string "Choisis le POKéMON que tu veux\n"
	.string "garder et faire juger.$"

BugContest_Text_DidntCatch:
	.string "Oh non ! Tu n'as pas attrapé de POKéMON.\n"
	.string "Tu es disqualifié.\p"
	.string "Ton équipe va maintenant être rendue.$"

BugContest_Text_TimesUp:
	.string "Ding-dong ! Le temps est écoulé !$"

BugContest_Text_WhiteOut:
	.string "{PLAYER} n'a plus de POKéMON utilisables.\n"
	.string "{PLAYER} a abandonné le concours.$"

BugContest_Text_First1:
	.string "La troisième place revient à la TOPDRESSEUSE\n"
	.string "BELINDA, qui a attrapé un PAPILUSION\l"
	.string "frétillant !$"
BugContest_Text_First2:
	.string "Deuxième place : le CAPTURINSECTE\n"
	.string "SHAUN, qui a attrapé un SCARABRUTE\l"
	.string "frétillant !$"
BugContest_Text_First3:
	.string "Le gagnant de la Course aux Insectes\n"
	.string "est...\p"
	.string "{PLAYER}, qui a attrapé\n"
	.string "un {STR_VAR_1} énorme !$"

BugContest_Text_Second1:
	.string "La deuxième place revient à la TOPDRESSEUSE\n"
	.string "BELINDA, qui a attrapé un PAPILUSION\l"
	.string "frétillant !$"
BugContest_Text_Second2:
	.string "La deuxième place revient à {PLAYER}, qui\n"
	.string "a attrapé un {STR_VAR_1} ondulant !$"
BugContest_Text_Second3:
	.string "Le gagnant de la Course Insecte est…\n"
	.string "…\p"
	.string "L'ATTRAPEUR SHAUN, qui a attrapé un\n"
	.string "SCARABRUTE énorme !$"


BugContest_Text_Third1:
	.string "La troisième place revient à {PLAYER}, qui\n"
	.string "a attrapé un {STR_VAR_1} frétillant !$"
BugContest_Text_Third2:
	.string "La deuxième place revient à la TOPDRESSEUSE\n"
	.string "BELINDA, qui a attrapé un PAPILUSION\l"
	.string "tortillant !$"
BugContest_Text_Third3:
	.string "Le gagnant de la Course Insecte est…\n"
	.string "…\p"
	.string "L'ATTRAPEUR SHAUN, qui a attrapé un\n"
	.string "SCARABRUTE énorme !$"

BugContest_Text_TakePartInFuture:
	.string "Merci d'avoir participé !\n"
	.string "Nous espérons que tu participeras\l"
	.string "à l'avenir.$"

BugContest_Text_TransferAndReturn:
	.string "Ton POKéMON INSECTE choisi sera maintenant\n"
	.string "envoyé au PC et ton équipe\l"
	.string "te sera rendue.$"
