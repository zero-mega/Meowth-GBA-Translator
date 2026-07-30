PalletTown_House2_MapScripts::
	.byte 0

PalletTown_House2_EventScript_Daisy::
	lock
	faceplayer
	goto_if_unset FLAG_HIDE_CINNABAR_BLUE, PalletTown_House2_EventScript_Blue
	goto_if_unset FLAG_DAILY_DAISY_GROOMED, PalletTown_House2_EventScript_DaisyGrooming
	msgbox PalletTown_House2_Text_AlreadyGroomed, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_House2_EventScript_Blue::
	msgbox PalletTown_House2_Text_Hello, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_House2_EventScript_DaisyDeclineGrooming::
	msgbox PalletTown_House2_Text_Refused, MSGBOX_DEFAULT
	closemessage
	release
	end
PalletTown_House2_EventScript_Egg::
	msgbox PalletTown_House2_Text_CantGroomEgg, MSGBOX_DEFAULT
	closemessage
	release
	end

PalletTown_House2_EventScript_DaisyGrooming::
	msgbox PalletTown_House2_Text_OfferGrooming, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, PalletTown_House2_EventScript_DaisyDeclineGrooming
	msgbox PalletTown_House2_Text_WhichMon, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	lock
	faceplayer
	bufferpartymonnick STR_VAR_1, VAR_0x8004
	goto_if_ge VAR_0x8004, PARTY_SIZE, PalletTown_House2_EventScript_DaisyDeclineGrooming
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, PalletTown_House2_EventScript_Egg
	goto_if_eq VAR_RESULT, FALSE, PalletTown_House2_EventScript_DaisyDeclineGrooming
	
	msgbox PalletTown_House2_Text_Alright
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HaircutBrother1
	fadescreen FADE_FROM_BLACK
	special BufferMonNickname
	msgbox PalletTown_House2_Text_AllDone
	setflag FLAG_DAILY_DAISY_GROOMED
	release
	end

PalletTown_House2_Text_Hello:
	.string "DAISY : Salut ! Mon petit frère est le\n"
	.string "CHAMPION D'ARÈNE d'ARGENTA.\p"
	.string "Mais il part si souvent en voyage\n"
	.string "que ça pose des problèmes aux\l"
	.string "DRESSEURS.$"

PalletTown_House2_Text_OfferGrooming:
	.string "DAISY : Salut ! Bon timing. Je vais\n"
	.string "prendre le thé.\p"
	.string "Tu veux me rejoindre ?\p"
	.string "Oh, tes POKéMON sont un peu sales.\p"
	.string "Tu veux que j'en toilette un ?$"

PalletTown_House2_Text_WhichMon:
	.string "MARGUERITE : Lequel dois-je toiletter ?$"

PalletTown_House2_Text_Alright:
	.string "MARGUERITE : OK, je vais le rendre\n"
	.string "joli en un rien de temps.$"

PalletTown_House2_Text_AllDone:
	.string "FLORÈNE : Voilà ! C'est fini.\p"
	.string "Tu vois ? {STR_VAR_1} est beau,\n"
	.string "non ?\p"
	.string "C'est un POKéMON tellement mignon.$"

PalletTown_House2_Text_AlreadyGroomed:
	.string "Daisy : J'ai toujours le thé à cette\n"
	.string "heure-ci. Viens me rejoindre.$"

PalletTown_House2_Text_Refused:
	.string "MARGUERITE : Tu ne veux pas en faire\n"
	.string "toilter un ?\p"
	.string "OK, on va juste prendre le thé.$"

PalletTown_House2_Text_CantGroomEgg:
	.string "MARGUERITE : Oh, désolée. Je ne peux\n"
	.string "pas toiletter un ŒUF.$"
