.set LOCALID_DAYCARE_LADY, 1

Route34_DayCare_MapScripts::
	.byte 0

Route34_DayCare_Bookshelf1::
	msgbox Route34_DayCare_Text_Bookshelf1, MSGBOX_SIGN
	end

Route34_DayCare_Bookshelf2::
	msgbox Route34_DayCare_Text_Bookshelf2, MSGBOX_SIGN
	end

Route34_DayCare_Bookshelf3::
	msgbox Route34_DayCare_Text_Bookshelf3, MSGBOX_SIGN
	end

Route34_DayCare_Bookshelf4::
	msgbox Route34_DayCare_Text_Bookshelf4, MSGBOX_SIGN
	end

Route34_DayCare_Text_Bookshelf1:
	.string "Un dictionnaire !\p"
	.string "{PLAYER} a ouvert le dictionnaire\n"
	.string "à une page au hasard.\p"
	.string "“BÉBÉ”\n"
	.string "Nom masculin, signifiant nourrisson.\p"
	.string "{PLAYER} a rangé le dictionnaire.$"

Route34_DayCare_Text_Bookshelf2:
	.string "Un livre sur les POKéMON !\p"
	.string "{PLAYER} a feuilleté\n"
	.string "le livre.\p"
	.string "Le mot POKéMON doit être écrit\n"
	.string "sur chaque page.\p"
	.string "{PLAYER} a rangé le livre.$"

Route34_DayCare_Text_Bookshelf3:
	.string "Un livre d'associations de\p"
	.string "mots ! {PLAYER} a\n"
	.string "feuilleté le livre. PICHU\p"
	.string "-> MIGNON MÉLO ->\l"
	.string "MIGNON TOGEPI ->\l"
	.string "CHANSON DEBUGANT ->\l"
	.string "COMBAT SMOOCHUM ->\l"
	.string "GLACE ÉLEKID ->\l"
	.string "ÉLECTRIQUE MAGBY ->\l"
	.string "FEU {PLAYER} a\p"
	.string "rangé le livre.$"

Route34_DayCare_Text_Bookshelf4:
	.string "Un livre sur les\p"
	.string "talents POKéMON !\n"
	.string "{PLAYER} a feuilleté le livre.\p"
	.string "PICHU -> STATIK\l"
	.string "MÉLO -> JOLI SOURIRE\l"
	.string "TOGEPI -> JOLI SOURIRE\l"
	.string "DEBUGANT -> COCOON\l"
	.string "SMOOCHUM -> INDIFFÉRENT\l"
	.string "ÉLEKID -> STATIK\l"
	.string "MAGBY -> CORPS ARDENT\p"
	.string "{PLAYER} a rangé le livre.$"

Route34_DayCare_EventScript_Clerk::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_ODD_EGG, Route34_DayCare_EventScript_ClerkAfter
	msgbox Route34_DayCare_Text_ClerkBefore, MSGBOX_DEFAULT
	getpartysize
	goto_if_eq VAR_RESULT, PARTY_SIZE, Route34_DayCare_EventScript_ClerkPartyFull
	msgbox Route34_DayCare_Text_ClerkQuestion, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, EASY_CHAT_TYPE_INTERVIEW
	setvar VAR_0x8005, 0
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	switch VAR_RESULT
	case 0, Route34_DayCare_EventScript_ClerkRejection
	case 1, Route34_DayCare_EventScript_GivePichu
	case 2, Route34_DayCare_EventScript_GiveCleffa
	case 3, Route34_DayCare_EventScript_GiveIgglybuff
	case 4, Route34_DayCare_EventScript_GiveTyrogue
	case 5, Route34_DayCare_EventScript_GiveSmoochum
	case 6, Route34_DayCare_EventScript_GiveElekid
	case 7, Route34_DayCare_EventScript_GiveMagby
	closemessage
	release
	end

Route34_DayCare_EventScript_GivePichu::
	giveoddegg 1
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_GiveCleffa::
	giveoddegg 2
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_GiveIgglybuff::
	giveoddegg 3
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_GiveTyrogue::
	giveoddegg 4
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_GiveSmoochum::
	giveoddegg 5
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_GiveElekid::
	giveoddegg 6
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_GiveMagby::
	giveoddegg 7
	goto Route34_DayCare_EventScript_Clerk_GaveEgg

Route34_DayCare_EventScript_Clerk_GaveEgg::
	msgbox Route34_DayCare_Text_TakeCare, MSGBOX_DEFAULT
	closemessage
	delay 30
	setflag FLAG_RECEIVED_ODD_EGG
	playfanfare MUS_OBTAIN_ITEM
	message Route34_DayCare_Text_ReceivedOddEgg
	waitfanfare
	closemessage
	release
	end

Route34_DayCare_EventScript_ClerkPartyFull::
	msgbox Route34_DayCare_Text_ClerkNoRoom, MSGBOX_DEFAULT
	closemessage
	release
	end

Route34_DayCare_EventScript_ClerkRejection::
	msgbox Route34_DayCare_Text_Rejection, MSGBOX_DEFAULT
	closemessage
	release
	end

Route34_DayCare_EventScript_ClerkAfter::
	msgbox Route34_DayCare_Text_ClerkAfter, MSGBOX_DEFAULT
	closemessage
	release
	end

Route34_DayCare_Text_ClerkBefore:
	.string "Je suis le fils du couple de la PENSION.\p"
	.string "Un OEUF BIZARRE a été trouvé avec les POKéMON\n"
	.string "d'un DRESSEUR, mais ils n'en voulaient pas...\p"
	.string "Je te l'offrirais bien...\n"
	.string "Mais comment savoir si tu en prendras\l"
	.string "bon soin ?$"

Route34_DayCare_Text_ClerkNoRoom:
	.string "On dirait que tu ne peux pas transporter\n"
	.string "un autre POKéMON de toute façon.$"

Route34_DayCare_Text_ClerkQuestion:
	.string "Réponds à cette question.\n"
	.string "Que penses-tu de cet OEUF BIZARRE ?$"

Route34_DayCare_Text_Rejection:
	.string "Hmm, je pense que cet OEUF n'est pas pour toi.\p"
	.string "Ce serait irresponsable de ma part de donner\n"
	.string "un précieux OEUF comme celui-ci\l"
	.string "à quelqu'un qui ne connaît pas bien\l"
	.string "l'élevage de Pokémon !$"

Route34_DayCare_Text_ReceivedOddEgg:
	.string "{PLAYER} a reçu l'OEUF BIZARRE.$"

Route34_DayCare_Text_TakeCare:
	.string "Je savais que tu étais le bon DRESSEUR\n"
	.string "pour le travail. Prends-en bien soin !$"

Route34_DayCare_Text_ClerkAfter:
	.string "On voit beaucoup de ces OEUFS\n"
	.string "par ici.\p"
	.string "Il y avait quelque chose de différent dans\n"
	.string "celui-là, pourtant.$"

Route34_DayCare_EventScript_Ditto::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DITTO, CRY_MODE_NORMAL
	msgbox Route34_DayCare_Text_Ditto, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route34_DayCare_Text_Ditto:
	.string "METAMORPH : Tto !$"

Route34_EventScript_DaycareMan::
	lock
	faceplayer
	special GetDaycareMonNicknames
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route34_EventScript_DaycareEggWaiting
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route34_EventScript_CheckOnOneMon
	goto_if_eq VAR_RESULT, DAYCARE_TWO_MONS, Route34_EventScript_CheckOnTwoMons
	msgbox Route34_Text_SeeWifeIfYoudLikeMeToRaiseMon, MSGBOX_DEFAULT
	release
	end

Route34_EventScript_DaycareEggWaiting::
	msgbox Route34_Text_DoYouWantEgg, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_EventScript_DaycareAcceptEgg
	msgbox Route34_Text_IWillKeepDoYouWantIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_EventScript_DaycareAcceptEgg
	msgbox Route34_Text_IllKeepIt, MSGBOX_DEFAULT
	clearflag FLAG_PENDING_DAYCARE_EGG
	special RejectEggFromDayCare
	release
	end

Route34_EventScript_DaycareAcceptEgg::
	specialvar VAR_0x8004, GetMaxPartySize @ tx_randomizer_and_challenges
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_ne VAR_RESULT, VAR_0x8004, Route34_EventScript_DaycareReceiveEgg
	msgbox Route34_Text_YouHaveNoRoomForIt, MSGBOX_DEFAULT
	release
	end

Route34_EventScript_DaycareReceiveEgg::
	message Route34_Text_ReceivedEgg
	playfanfare MUS_LEVEL_UP
	waitfanfare
	waitbuttonpress
	msgbox Route34_Text_TakeGoodCareOfIt, MSGBOX_DEFAULT
	special GiveEggFromDaycare
	clearflag FLAG_PENDING_DAYCARE_EGG
	release
	end

Route34_EventScript_CheckMonReceivedMail::
	specialvar VAR_RESULT, CheckDaycareMonReceivedMail
	call_if_eq VAR_RESULT, 1, Route34_EventScript_MonReceivedMail
	return

Route34_EventScript_MonReceivedMail::
	msgbox Route34_Text_FriendlyWithOtherTrainersMon, MSGBOX_DEFAULT
	return

Route34_EventScript_CheckOnOneMon::
	special GetDaycareMonNicknames
	msgbox Route34_Text_YourMonIsDoingFine, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route34_EventScript_CheckMonReceivedMail
	release
	end

Route34_EventScript_CheckOnTwoMons::
	special GetDaycareMonNicknames
	msgbox Route34_Text_YourMonsAreDoingFine, MSGBOX_DEFAULT
	special SetDaycareCompatibilityString
	special ShowFieldMessageStringVar4
	waitmessage
	waitbuttonpress
	setvar VAR_0x8004, 0
	call Route34_EventScript_CheckMonReceivedMail
	setvar VAR_0x8004, 1
	call Route34_EventScript_CheckMonReceivedMail
	release
	end

Route34_DayCare_EventScript_DaycareWoman::
	lock
	faceplayer
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_EGG_WAITING, Route34_DayCare_EventScript_EggWaiting
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route34_DayCare_EventScript_OneMonInDaycare
	goto_if_eq VAR_RESULT, DAYCARE_TWO_MONS, Route34_DayCare_EventScript_TwoMonsInDaycare
	msgbox Route34_DayCare_Text_WouldYouLikeUsToRaiseAMon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_DayCare_EventScript_GiveMonToRaise
	msgbox Route34_DayCare_Text_FineThenComeAgain, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_EventScript_GiveMonToRaise::
	specialvar VAR_RESULT, CountPartyNonEggMons
	goto_if_eq VAR_RESULT, 1, Route34_DayCare_EventScript_OnlyOneMon
	specialvar VAR_RESULT, CountPartyAliveNonEggMons
	goto_if_eq VAR_RESULT, 2, Route34_DayCare_EventScript_OnlyTwoAliveMons
	msgbox Route34_DayCare_Text_WhichMonShouldWeRaise, MSGBOX_DEFAULT
	fadescreen FADE_TO_BLACK
	special ChooseSendDaycareMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, Route34_DayCare_EventScript_ComeAgain
	specialvar VAR_RESULT, CountPartyAliveNonEggMons_IgnoreVar0x8004Slot
	goto_if_eq VAR_RESULT, 0, Route34_DayCare_EventScript_OnlyOneAliveMon
	specialvar VAR_0x8005, GetSelectedMonNicknameAndSpecies
	waitse
	playmoncry VAR_0x8005, CRY_MODE_NORMAL
	msgbox Route34_DayCare_Text_WellRaiseYourMon, MSGBOX_DEFAULT
	waitmoncry
	special StoreSelectedPokemonInDaycare
	callnative UpdateFollowingPokemon
	incrementgamestat GAME_STAT_USED_DAYCARE
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route34_DayCare_EventScript_CanRaiseOneMore
	release
	end

Route34_DayCare_EventScript_ComeAgain::
	msgbox Route34_DayCare_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_EventScript_CanRaiseOneMore::
	msgbox Route34_DayCare_Text_WeCanRaiseOneMore, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_DayCare_EventScript_GiveMonToRaise
	goto Route34_DayCare_EventScript_ComeAgain
	end

Route34_DayCare_EventScript_OnlyOneMon::
	msgbox Route34_DayCare_Text_YouHaveJustOneMon, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_EventScript_OnlyOneAliveMon::
	msgbox Route34_DayCare_Text_WhatWillYouBattleWith, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_EventScript_OnlyTwoAliveMons::
	msgbox Route34_DayCare_Text_YoullBeLeftWithJustOne, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_EventScript_EggWaiting::
	msgbox Route34_DayCare_Text_HusbandWasLookingForYou, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_EventScript_YourMonHasGrownXLevels::
	msgbox Route34_DayCare_Text_YourMonHasGrownXLevels, MSGBOX_DEFAULT
	return

Route34_DayCare_EventScript_DisplayLevelsGained::
	specialvar VAR_RESULT, GetNumLevelsGainedFromDaycare
	call_if_ne VAR_RESULT, 0, Route34_DayCare_EventScript_YourMonHasGrownXLevels
	return

Route34_DayCare_EventScript_OneMonInDaycare::
	msgbox Route34_DayCare_Text_GoodToSeeYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route34_DayCare_EventScript_DisplayLevelsGained
	msgbox Route34_DayCare_Text_WeCanRaiseOneMore, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_DayCare_EventScript_GiveMonToRaise
	msgbox Route34_DayCare_Text_TakeYourMonBack, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_DayCare_EventScript_TryRetrieveMon
	goto Route34_DayCare_EventScript_ComeAgain
	end

Route34_DayCare_EventScript_TryRetrieveMon::
	specialvar VAR_0x8004, GetMaxPartySize @ tx_randomizer_and_challenges
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	goto_if_eq VAR_RESULT, VAR_0x8004, Route34_DayCare_EventScript_NoRoom
	specialvar VAR_RESULT, GetDaycareState
	setvar VAR_0x8004, 0
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route34_DayCare_EventScript_CostPrompt
	special ShowDaycareLevelMenu
	waitstate
	copyvar VAR_0x8004, VAR_RESULT
	goto_if_eq VAR_RESULT, DAYCARE_EXITED_LEVEL_MENU, Route34_DayCare_EventScript_ComeAgain
	goto Route34_DayCare_EventScript_CostPrompt
	end

Route34_DayCare_EventScript_CostPrompt::
	special GetDaycareCost
	msgbox Route34_DayCare_Text_ItWillCostX, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_DayCare_EventScript_CheckEnoughMoney
	goto Route34_DayCare_EventScript_ComeAgain
	end

Route34_DayCare_EventScript_CheckEnoughMoney::
	specialvar VAR_RESULT, IsEnoughForCostInVar0x8005
	goto_if_eq VAR_RESULT, 1, Route34_DayCare_EventScript_RetrieveMon
	msgbox Route34_DayCare_Text_NotEnoughMoney, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_EventScript_RetrieveMon::
	@applymovement LOCALID_DAYCARE_LADY, Route34_DayCare_Movement_RetrieveDaycareMon
	@waitmovement 0
	specialvar VAR_RESULT, TakePokemonFromDaycare
	special SubtractMoneyFromVar0x8005
	playse SE_SHOP
	msgbox Route34_DayCare_Text_HeresYourMon, MSGBOX_DEFAULT
	waitse
	playmoncry VAR_RESULT, CRY_MODE_NORMAL
	msgbox Route34_DayCare_Text_TookBackMon, MSGBOX_DEFAULT
	waitmoncry
	specialvar VAR_RESULT, GetDaycareState
	goto_if_eq VAR_RESULT, DAYCARE_ONE_MON, Route34_DayCare_EventScript_AskRetrieveOtherMon
	goto Route34_DayCare_EventScript_ComeAgain
	end

Route34_DayCare_EventScript_AskRetrieveOtherMon::
	msgbox Route34_DayCare_Text_TakeOtherOneBackToo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_DayCare_EventScript_TryRetrieveMon
	goto Route34_DayCare_EventScript_ComeAgain
	end

Route34_DayCare_EventScript_NoRoom::
	msgbox Route34_DayCare_Text_YourTeamIsFull, MSGBOX_DEFAULT
	release
	end

Route34_DayCare_Movement_RetrieveDaycareMon:
	delay_16
	delay_16
	face_left
	delay_16
	delay_16
	face_right
	delay_16
	delay_16
	face_up
	walk_slow_up
	set_invisible
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_down
	set_visible
	walk_slow_down
	step_end

@ Unused. Possibly a commented script, or a typo end added to the above Movement script
Route34_DayCare_EventScript_UnusedEnd::
	end

Route34_DayCare_EventScript_TwoMonsInDaycare::
	msgbox Route34_DayCare_Text_GoodToSeeYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, 0
	call Route34_DayCare_EventScript_DisplayLevelsGained
	setvar VAR_0x8004, 1
	call Route34_DayCare_EventScript_DisplayLevelsGained
	msgbox Route34_DayCare_Text_TakeYourMonBack, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route34_DayCare_EventScript_TryRetrieveMon
	msgbox Route34_DayCare_Text_ComeAgain, MSGBOX_DEFAULT
	release
	end

Route34_Text_SeeWifeIfYoudLikeMeToRaiseMon:
	.string "Je suis le PENSIONNAIRE.\p"
	.string "J'aide à prendre soin des précieux\n"
	.string "POKéMON des DRESSEURS.\p"
	.string "Si tu veux que j'élève tes POKéMON,\n"
	.string "parle à ma femme.$"

Route34_Text_DoYouWantEgg:
	.string "Ah, c'est toi ! Nous gardions\p"
	.string "ton POKéMON, et mon Dieu, quelle\n"
	.string "surprise ! Ton POKéMON avait un\p"
	.string "OEUF ! On ne sait pas\p"
	.string "comment il est arrivé là,\n"
	.string "mais ton POKéMON l'avait. Tu\p"
	.string "le veux, n'est-ce pas ?$"

Route34_Text_YourMonIsDoingFine:
	.string "Ah, c'est toi ! Content de te voir.\n"
	.string "Ton {STR_VAR_1} va très bien.$"

Route34_Text_IllKeepIt:
	.string "Bon, alors je le garde.\n"
	.string "Merci !$"

Route34_Text_YouHaveNoRoomForIt:
	.string "Tu n'as pas de place…\n"
	.string "Reviens quand tu auras de la place.$"

Route34_Text_ReceivedEgg:
	.string "{PLAYER} a reçu l'OEUF\n"
	.string "du GARDIEN DE PENSION.$"

Route34_Text_TakeGoodCareOfIt:
	.string "Prends-en bien soin.$"

Route34_Text_FriendlyWithOtherTrainersMon:
	.string "Au fait, à propos de ton {STR_VAR_1},\n"
	.string "il semblait être ami avec\l"
	.string "le {STR_VAR_2} de {STR_VAR_3}.\p"
	.string "J'ai peut-être même vu qu'il recevait\n"
	.string "un MAIL.$"

@ Unused
Route34_Text_SeeWifeIfYouWantToPickUpMon:
	.string "Si tu veux récupérer tes POKéMON,\n"
	.string "parle à ma femme.$"

Route34_Text_YourMonsAreDoingFine:
	.string "Ah, c'est toi ! Tes {STR_VAR_1} et\n"
	.string "{STR_VAR_2} vont très bien.$"

Route34_Text_IWillKeepDoYouWantIt:
	.string "Je le garderai vraiment.\n"
	.string "Tu le veux bien, n'est-ce pas ?$"

Route34_DayCare_Text_WouldYouLikeUsToRaiseAMon:
	.string "Je suis la DAME DU PENSIONNAT.\p"
	.string "Nous pouvons élever des POKéMON pour toi.\p"
	.string "Tu veux qu'on en élève un ?$"

Route34_DayCare_Text_WhichMonShouldWeRaise:
	.string "Quel POKéMON devons-nous élever\n"
	.string "pour toi ?$"

Route34_DayCare_Text_WellRaiseYourMon:
	.string "Bien, nous garderons ton {STR_VAR_1}\n"
	.string "un moment.\p"
	.string "Reviens le chercher plus tard.$"

Route34_DayCare_Text_WeCanRaiseOneMore:
	.string "On peut élever deux de tes POKéMON.\n"
	.string "Veux-tu qu'on en élève un de plus ?$"

Route34_DayCare_Text_HusbandWasLookingForYou:
	.string "Mon mari te cherchait.$"

Route34_DayCare_Text_FineThenComeAgain:
	.string "Oh, d'accord.\n"
	.string "Reviens nous voir.$"

Route34_DayCare_Text_NotEnoughMoney:
	.string "Tu n'as pas assez d'argent…$"

Route34_DayCare_Text_TakeOtherOneBackToo:
	.string "Veux-tu reprendre l'autre\n"
	.string "aussi ?$"

Route34_DayCare_Text_ComeAgain:
	.string "D'accord.\n"
	.string "Reviens.$"

Route34_DayCare_Text_GoodToSeeYou:
	.string "Ah, c'est toi ! Content de te voir.\n"
	.string "Tes POKéMON ne peuvent que s'épanouir !$"

Route34_DayCare_Text_YourMonHasGrownXLevels:
	.string "En niveau, ton {STR_VAR_1} a\n"
	.string "gagné {STR_VAR_2} niveaux.$"

Route34_DayCare_Text_YourTeamIsFull:
	.string "Ton équipe POKéMON est pleine.\n"
	.string "Fais de la place, puis reviens me voir.$"

@ Unused
Route34_DayCare_Text_TakeBackWhichMon:
	.string "Quel POKéMON veux-tu reprendre ?$"

Route34_DayCare_Text_ItWillCostX:
	.string "Si tu veux récupérer ton {STR_VAR_1},\n"
	.string "ça coûtera ¥{STR_VAR_2}.$"

Route34_DayCare_Text_HeresYourMon:
	.string "Parfait !\n"
	.string "Voici ton POKéMON.$"

Route34_DayCare_Text_TookBackMon:
	.string "{PLAYER} a repris {STR_VAR_1} de\n"
	.string "la DAME de la PENSION.$"

Route34_DayCare_Text_YouHaveJustOneMon:
	.string "Oh ? Mais tu n'as qu'un seul\n"
	.string "POKéMON.\p"
	.string "Reviens une autre fois.$"

Route34_DayCare_Text_TakeYourMonBack:
	.string "Veux-tu reprendre ton POKéMON ?$"

Route34_DayCare_Text_WhatWillYouBattleWith:
	.string "Si tu me laisses ce POKéMON,\n"
	.string "avec quoi vas-tu combattre ?\p"
	.string "Reviens une autre fois.$"

Route34_DayCare_Text_YoullBeLeftWithJustOne:
	.string "Hein ?\n"
	.string "Doucement, doucement.\p"
	.string "Si tu me laisses ce POKéMON,\n"
	.string "il ne te restera qu'un seul.\p"
	.string "Tu ferais mieux d'en attraper\n"
	.string "d'autres, je te le conseille.$"
