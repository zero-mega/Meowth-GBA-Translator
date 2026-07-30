PalletTown_Lab_MapScripts::
	.byte 0

PalletTown_Lab_EventScript_Oak::
	lock
	faceplayer
	call_if_unset FLAG_SYS_NATIONAL_DEX, PalletTown_Lab_EventScript_OakGiveNatDex_ForPlaytesters
	goto_if_eq VAR_PALLETTOWN_LABSTATE, 1, PalletTown_Lab_EventScript_OakBadgeCheck
	goto_if_eq VAR_PALLETTOWN_LABSTATE, 2, PalletTown_Lab_EventScript_OakDex
	msgbox PalletTown_Lab_Text_OakWelcomeKanto, MSGBOX_DEFAULT
	msgbox PalletTown_Lab_Text_OakLabGoodbye, MSGBOX_DEFAULT
	setvar VAR_PALLETTOWN_LABSTATE, 1
	closemessage
	release
	end

PalletTown_Lab_EventScript_OakGiveNatDex_ForPlaytesters::
	setflag FLAG_SYS_NATIONAL_DEX
	special EnableNationalPokedex
	return

PalletTown_Lab_EventScript_OakBadgeCheck::
	goto_if_ge VAR_NUM_BADGES, 16, PalletTown_Lab_EventScript_Oak16Badges
	goto_if_ge VAR_NUM_BADGES, 9, PalletTown_Lab_EventScript_Oak9Badges
	msgbox PalletTown_Lab_Text_OakNoKantoBadges, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_Lab_EventScript_Oak16Badges::
	msgbox PalletTown_Lab_Text_OakOpenMtSilver, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_INDIGOJUNCTION_HIDE_SILVER_GUARD
	setvar VAR_PALLETTOWN_LABSTATE, 2
	release
	end

PalletTown_Lab_EventScript_Oak9Badges::
	msgbox PalletTown_Lab_Text_OakYesKantoBadges, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_Lab_EventScript_OakDex::
	msgbox PalletTown_Lab_Text_OakLabDexCheck, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_Lab_EventScript_Assistant1::
	msgbox PalletTown_Lab_Text_OaksAssistant1, MSGBOX_NPC
	end

PalletTown_Lab_EventScript_Assistant2::
	msgbox PalletTown_Lab_Text_OaksAssistant2, MSGBOX_NPC
	end

PalletTown_Lab_EventScript_Assistant3::
	msgbox PalletTown_Lab_Text_OaksAssistant3, MSGBOX_NPC
	end

PalletTown_Lab_EventScript_PC::
	msgbox PalletTown_Lab_Text_OaksLabPC, MSGBOX_SIGN
	end

PalletTown_Lab_Text_OakLabDexCheck:
	.string "Comment avance ton POKéDEX ?$"

PalletTown_Lab_Text_OakWelcomeKanto:
	.string "CHEN : Ah, {PLAYER} !\n"
	.string "C'est gentil de venir jusqu'ici\l"
	.string "à KANTO.\p"
	.string "Que penses-tu des DRESSEURS\n"
	.string "d'ici ? Plutôt coriaces, hein ?$"

PalletTown_Lab_Text_OakLabGoodbye:
	.string "Si tu es dans le coin, j'espère\n"
	.string "que tu reviendras nous voir.$"

PalletTown_Lab_Text_OakOpenMtSilver:
	.string "CHEN : Waouh ! C'est excellent !\p"
	.string "Tu as collecté les BADGES des ARÈNES\n"
	.string "de KANTO. Bien joué !\p"
	.string "J'avais raison dans mon évaluation de\n"
	.string "toi.\p"
	.string "Je vais te dire quoi, {PLAYER}. Je vais faire\n"
	.string "des arrangements pour que tu puisses aller\l"
	.string "au MONT ARGENTA.\p"
	.string "Le MONT ARGENTA est une grande montagne qui\n"
	.string "abrite de nombreux POKéMON sauvages.\p"
	.string "C'est trop dangereux pour un dresseur\n"
	.string "moyen, donc c'est interdit. Mais\l"
	.string "nous pouvons faire une exception dans ton\l"
	.string "cas, {PLAYER}.\p"
	.string "Va à la PLATEAU INDIGO. Tu peux\n"
	.string "atteindre le MONT ARGENTA de là.$"

PalletTown_Lab_Text_OakNoKantoBadges:
	.string "PROF. CHEN : Hmm ? Tu ne collectionnes pas\n"
	.string "les BADGES D'ARENE de KANTO ?\p"
	.string "Les CHAMPIONS D'ARENE de KANTO sont aussi\n"
	.string "forts que ceux que tu as affrontés à JOHTO.\p"
	.string "Je te recommande de les défier.$"

PalletTown_Lab_Text_OakYesKantoBadges:
	.string "CHEN : Ah, tu collectionnes les\n"
	.string "BADGES d'ARÈNE de KANTO. J'imagine que\p"
	.string "c'est dur, mais l'expérience t'aidera\n"
	.string "sûrement. Viens me voir quand\p"
	.string "tu les auras tous. J'aurai\p"
	.string "un cadeau pour toi. Continue\p"
	.string "à te battre, {PLAYER} !$"

PalletTown_Lab_Text_OaksAssistant1:
	.string "L'émission radio POKéMON AVENTURE\n"
	.string "du PROF n'est pas diffusée ici à KANTO.\p"
	.string "C'est dommage... j'aimerais l'entendre.$"

PalletTown_Lab_Text_OaksAssistant2:
	.string "Grâce à ton travail sur le POKéDEX,\n"
	.string "la recherche du PROF avance\l"
	.string "super bien.$"

PalletTown_Lab_Text_OaksAssistant3:
	.string "Ne le dis à personne, mais POKéMON TALK\n"
	.string "du PROF. CHEN n'est pas en direct.$"

PalletTown_Lab_Text_OaksLabPC:
	.string "Il y a un message\p"
	.string "électronique sur le PC. …\p"
	.string "PROF.CHEN, comment avancent tes recherches\n"
	.string "? Je continue à travailler\p"
	.string "dur. J'ai entendu des rumeurs\p"
	.string "disant que {PLAYER} se\n"
	.string "fait une belle réputation.\p"
	.string "J'en suis ravi. ORME\p"
	.string "de BOURG GEON 8-)$"
