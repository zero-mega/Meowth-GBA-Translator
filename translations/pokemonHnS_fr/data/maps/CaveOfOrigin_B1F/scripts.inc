.set LOCALID_WALLACE, 1

CaveOfOrigin_B1F_MapScripts::
	.byte 0

CaveOfOrigin_B1F_EventScript_Wallace::
	lock
	faceplayer
	msgbox CaveOfOrigin_B1F_Text_WallaceStory, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_WALLACE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 60
	playse SE_PIN
	applymovement LOCALID_WALLACE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_WALLACE, Common_Movement_Delay48
	waitmovement 0
	delay 30
	applymovement LOCALID_WALLACE, Common_Movement_FacePlayer
	waitmovement 0
	message CaveOfOrigin_B1F_Text_WhereIsRayquaza
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_WheresRayquaza::
	multichoice 0, 0, MULTI_WHERES_RAYQUAZA, FALSE
	switch VAR_RESULT
	case 0, CaveOfOrigin_B1F_EventScript_AtCaveOfOrigin
	case 1, CaveOfOrigin_B1F_EventScript_AtMtPyre
	case 2, CaveOfOrigin_B1F_EventScript_AtSkyPillar
	case 3, CaveOfOrigin_B1F_EventScript_DontRemember
	goto CaveOfOrigin_B1F_EventScript_DontRemember
	end

CaveOfOrigin_B1F_EventScript_AtCaveOfOrigin::
	message CaveOfOrigin_B1F_Text_ButWereInCaveOfOrigin
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_AtMtPyre::
	message CaveOfOrigin_B1F_Text_OldLadyDidntMentionThat
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_DontRemember::
	message CaveOfOrigin_B1F_Text_CantYouRememberSomehow
	waitmessage
	goto CaveOfOrigin_B1F_EventScript_WheresRayquaza

CaveOfOrigin_B1F_EventScript_AtSkyPillar::
	msgbox CaveOfOrigin_B1F_Text_WellHeadToSkyPillar, MSGBOX_DEFAULT
	closemessage
	playse SE_EXIT
	fadescreenspeed FADE_TO_BLACK, 4
	setflag FLAG_WALLACE_GOES_TO_SKY_PILLAR
	setvar VAR_GARBAGEVAR, 3
	removeobject LOCALID_WALLACE
	clearflag FLAG_GARBAGEFLAG
	fadescreen FADE_FROM_BLACK
	release
	end

CaveOfOrigin_B1F_Text_WallaceStory:
	.string "Ah, alors tu es {PLAYER}{KUN} ?\n"
	.string "J'ai entendu parler de tes exploits.\p"
	.string "Je m'appelle WALLACE.\p"
	.string "J'étais autrefois le CHAMPION d'ARÈNE de\n"
	.string "ATALANOPOLIS, mais quelque chose est arrivé.\p"
	.string "Alors maintenant, j'ai confié mon mentor JUAN\n"
	.string "à la gestion de l'ARÈNE.\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "GROUDON et KYOGRE, les deux POKéMON\n"
	.string "qui sèment le chaos ici, sont considérés\l"
	.string "comme des POKéMON super-anciens.\p"
	.string "Mais il n'y a pas que deux POKéMON\n"
	.string "super-anciens.\p"
	.string "Il y en a un autre quelque part.\p"
	.string "Quelque part, il y a un POKéMON\n"
	.string "super-ancien nommé RAYQUAZA.\p"
	.string "On dit que c'est RAYQUAZA qui\n"
	.string "a calmé les deux combattants dans\l"
	.string "le passé lointain.\p"
	.string "Mais même moi, je n'ai aucune idée de\n"
	.string "l'emplacement de RAYQUAZA…$"

CaveOfOrigin_B1F_Text_WhereIsRayquaza:
	.string "MARC : {PLAYER}{KUN}, tu sais peut-être\n"
	.string "où se trouve RAYQUAZA maintenant ?\p"
	.string "Si tu le sais, dis-le-moi, s'il te plaît.$"

CaveOfOrigin_B1F_Text_ButWereInCaveOfOrigin:
	.string "PIERRE : La GROTTE ORIGINE ?\p"
	.string "Mais elle est juste ici !\n"
	.string "Tu dois faire mieux que ça !\p"
	.string "S'il te plaît, réfléchis à\n"
	.string "où RAYQUAZA pourrait être en ce moment.$"

CaveOfOrigin_B1F_Text_OldLadyDidntMentionThat:
	.string "ALIZA : MONT SÉPIA ? Mais\p"
	.string "quand j'ai rencontré la vieille dame\n"
	.string "là-bas plus tôt, elle n'en a\p"
	.string "pas parlé. Je doute fortement que\n"
	.string "la vieille dame essaierait de me\p"
	.string "cacher quelque chose… {PLAYER}{KUN}, pourrais-tu y\n"
	.string "réfléchir plus attentivement pour moi ?$"

CaveOfOrigin_B1F_Text_CantYouRememberSomehow:
	.string "WALLACE : Hein ? Tu ne te souviens pas ?\n"
	.string "Hmm… C'est un problème…\p"
	.string "Tu ne peux vraiment pas t'en souvenir ?$"

CaveOfOrigin_B1F_Text_WellHeadToSkyPillar:
	.string "PIERRE : Le PILIER CÉLESTE ?\p"
	.string "C'est ça !\n"
	.string "Ce doit être le PILIER CÉLESTE !\p"
	.string "{PLAYER}{KUN}, pas une minute à perdre !\n"
	.string "On file au PILIER CÉLESTE tout de suite !$"

