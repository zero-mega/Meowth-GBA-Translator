Gate_GoldenrodCity_Route35_MapScripts::
	.byte 0

Gate_GoldenrodCity_Route35_EventScript_Randy::
	lock
	faceplayer
	goto_if_eq VAR_KENYA, 3, Gate_GoldenrodCity_Route35_EventScript_RandyPostKenya
	goto_if_eq VAR_KENYA, 2, Gate_GoldenrodCity_Route35_EventScript_RandyDeliveredKenya
	goto_if_eq VAR_KENYA, 1, Gate_GoldenrodCity_Route35_EventScript_RandyHaveKenya
	msgbox Route35GoldenrodGate_Text_RandyAskFavor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, Gate_GoldenrodCity_Route35_EventScript_RandyCancel
	closemessage

	msgbox Route35GoldenrodGate_Text_RandyThanks, MSGBOX_DEFAULT

	@HnS named gift pokemon setup
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_SPEAROW
	bufferspeciesname STR_VAR_1, SPECIES_SPEAROW
	givenamedmon 1
	call Common_EventScript_GiftMonNamed

	setvar VAR_KENYA, 1
	release
	end

Gate_GoldenrodCity_Route35_EventScript_RandyCancel::
	msgbox Route35GoldenrodGate_Text_RandyNeverMind, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_GoldenrodCity_Route35_EventScript_RandyHaveKenya::
	msgbox Route35GoldenrodGate_Text_RandyWeirdTree, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_GoldenrodCity_Route35_EventScript_RandyDeliveredKenya::
	msgbox Route35GoldenrodGate_Text_ThanksForDelivery, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_HP_UP
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox Route35GoldenrodGate_Text_RandyMyPalSnoozing, MSGBOX_DEFAULT
	closemessage
	setvar VAR_KENYA, 3
	release
	end

Gate_GoldenrodCity_Route35_EventScript_RandyPostKenya::
	msgbox Route35GoldenrodGate_Text_RandyMyPalSnoozing, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_GoldenrodCity_Route35_EventScript_Lady::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SUDOWOODO, Gate_GoldenrodCity_Route35_EventScript_Lady2
	msgbox Route35GoldenrodGate_Text_PokefanF_TreeBlocking, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_GoldenrodCity_Route35_EventScript_Lady2::
	msgbox Route35GoldenrodGate_Text_PokefanF_Lullaby, MSGBOX_DEFAULT
	closemessage
	release
	end

Gate_GoldenrodCity_Route35_EventScript_Fisher::
	lock
	faceplayer
	msgbox Route35GoldenrodGate_Text_Fisher, MSGBOX_DEFAULT
	closemessage
	release
	end

Route35GoldenrodGate_Text_RandyAskFavor:
	.string "Excuse-moi, gamin ! Tu peux me\n"
	.string "rendre un service ? Tu peux\p"
	.string "emmener ce POKéMON avec une LETTRE\n"
	.string "à mon ami ? Il\p"
	.string "est sur la ROUTE 31.$"

Route35GoldenrodGate_Text_RandyThanks:
	.string "Tu veux bien ? Parfait ! Merci,\p"
	.string "gamin ! Mon pote est un gros\n"
	.string "type qui dort tout le temps. Tu\p"
	.string "le reconnaîtras tout de suite !$"

Route35GoldenrodGate_Text_ReceivedMonWithMail:
	.string "{PLAYER} a reçu un POKéMON avec une LETTRE.$"

Route35GoldenrodGate_Text_RandyWeirdTree:
	.string "Assure-toi de le mettre en tête de\n"
	.string "ton équipe quand tu trouveras mon ami !\p"
	.string "ROUTE 31 !\p"
	.string "Oh, oui. Il y avait un arbre bizarre\n"
	.string "qui bloquait la route.\p"
	.string "Je me demande s'il a été dégagé ?$"

Route35GoldenrodGate_Text_CantCarryMoreMon:
	.string "Tu ne peux pas porter un autre POKéMON…$"

Route35GoldenrodGate_Text_RandyNeverMind:
	.string "Oh… Laisse tomber, alors…$"

Route35GoldenrodGate_Text_ThanksForDelivery:
	.string "Merci, gamin ! Tu as fait la livraison\n"
	.string "pour moi !\p"
	.string "Voici quelque chose pour tes peines !$"

Route35GoldenrodGate_Text_RandyMyPalSnoozing:
	.string "Mon pote faisait la sieste, non ?\n"
	.string "Hein, qu'est-ce que j'ai dit ?$"

Route35GoldenrodGate_Text_PokefanF_TreeBlocking:
	.string "Un arbre étrange bloque la route.\p"
	.string "Il se tortille si on lui parle.\p"
	.string "J'ai entendu qu'il est devenu sauvage quand quelqu'un\n"
	.string "l'a arrosé avec une SQUIRTBOUTLE.$"

Route35GoldenrodGate_Text_PokefanF_Lullaby:
	.string "J'aime la Berceuse POKéMON qu'ils passent\n"
	.string "à la radio.$"

Route35GoldenrodGate_Text_Fisher:
	.string "Je me demande combien d'espèces de POKéMON\n"
	.string "il y a dans le monde.\p"
	.string "Il y a trois ans, le PROF.CHêNE disait qu'il\n"
	.string "y en avait 150 différentes.\p"
	.string "Mais récemment j'ai entendu qu'il y en a\n"
	.string "plus de 400 !$"
