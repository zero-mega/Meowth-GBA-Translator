.set LOCALID_MINT_CLERK, 3

GoldenrodCity_FlowerShop_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, GoldenrodCity_FlowerShop_OnTransition
	.byte 0

GoldenrodCity_FlowerShop_OnTransition::
	call_if_unset FLAG_MINTS_ENABLED, GoldenrodCity_FlowerShop_HideMintClerk
	call_if_set FLAG_MINTS_ENABLED, GoldenrodCity_FlowerShop_ShowMintClerk
	end

GoldenrodCity_FlowerShop_HideMintClerk::
	goto_if_set FLAG_SYS_GAME_CLEAR, GoldenrodCity_FlowerShop_ShowMintClerkPostgame
	setflag FLAG_MINTS_CLERK
	removeobject LOCALID_MINT_CLERK
	return

GoldenrodCity_FlowerShop_ShowMintClerkPostgame::
	clearflag FLAG_MINTS_CLERK
	addobject LOCALID_MINT_CLERK
	end

GoldenrodCity_FlowerShop_ShowMintClerk::
	clearflag FLAG_MINTS_CLERK
	addobject LOCALID_MINT_CLERK
	return

GoldenrodCity_FlowerShop_EventScript_Owner::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SUDOWOODO, GoldenrodCity_FlowerShop_EventScript_Normal
	goto_if_set FLAG_RECEIVED_SQUIRTBOTTLE, GoldenrodCity_FlowerShop_EventScript_GotSquirtBottle
	goto_if_set FLAG_BADGE03_GET, GoldenrodCity_FlowerShop_EventScript_GiveSquirtBottle
	msgbox GoldenrodCity_FlowerShop_Text_Owner1, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_FlowerShop_EventScript_GiveSquirtBottle::
	lock
	faceplayer
	msgbox GoldenrodCity_FlowerShop_Text_Owner2, MSGBOX_DEFAULT
	giveitem ITEM_SQUIRT_BOTTLE
	setflag FLAG_RECEIVED_SQUIRTBOTTLE
	closemessage
	release
	end

GoldenrodCity_FlowerShop_EventScript_GotSquirtBottle::
	lock
	faceplayer
	msgbox GoldenrodCity_FlowerShop_Text_Owner3, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_FlowerShop_EventScript_Normal::
	lock
	faceplayer
	msgbox GoldenrodCity_FlowerShop_Text_Owner4, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_FlowerShop_EventScript_Floria1::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SUDOWOODO, GoldenrodCity_FlowerShop_EventScript_Floria3
	goto_if_set FLAG_BADGE03_GET, GoldenrodCity_FlowerShop_EventScript_Floria2
	msgbox GoldenrodCity_FlowerShop_Text_Floria, MSGBOX_DEFAULT
	closemessage
	release
	end
	
GoldenrodCity_FlowerShop_EventScript_Floria2::
	msgbox GoldenrodCity_FlowerShop_Text_FloriaYouBeatWhitney, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_FlowerShop_EventScript_Floria3::
	msgbox GoldenrodCity_FlowerShop_Text_FloriaItWasAMon, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_FlowerShop_Text_Floria:
	.string "Quand j'ai parlé à ma sœur de l'arbre\n"
	.string "qui bouge, elle a dit que c'était dangereux.\p"
	.string "Si je bats BLAIRE, je me demande si\n"
	.string "elle me prêtera sa gourde…$"

GoldenrodCity_FlowerShop_Text_Owner1:
.string "Apparemment, il y\n"
.string "a un arbre\p"
.string "étrange\n"
.string "sur la ROUTE 36.\p"
.string "On dit\p"
.string "qu'il danse\n"
.string "quand on\p"
.string "l'arrose…\n"
.string "Oh, bien sûr,\p"
.string "c'est une\n"
.string "blague !\l"
.string "Ou peut-être pas…$"

GoldenrodCity_FlowerShop_Text_Owner2:
.string "Apparemment, il y\n"
.string "a un arbre\p"
.string "étrange\n"
.string "sur la ROUTE 36.\p"
.string "On dit\n"
.string "qu'il danse\p"
.string "quand on\p"
.string "l'arrose…\n"
.string "Oh, c'est un\p"
.string "BADGE BASIQUE de\n"
.string "MAUVILLE ?\l"
.string "Tu es sur la bonne\p"
.string "voie, {PLAYER} !$"

GoldenrodCity_FlowerShop_Text_Owner3:
.string "L'arbre bizarre est sur la ROUTE 36.\n"
.string "Fais attention !$"

GoldenrodCity_FlowerShop_Text_Owner4:
    .string "Lalala lalalala. Bois beaucoup d'eau,\n"
    .string "ma chérie !$"

GoldenrodCity_FlowerShop_Text_FloriaYouBeatWhitney:
    .string "Ouah, tu as battu BLANCHE ? Cool !$"

GoldenrodCity_FlowerShop_Text_FloriaItWasAMon:
    .string "Alors c'était bien un POKéMON !$"
