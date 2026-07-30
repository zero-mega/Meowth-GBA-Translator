NationalPark_Normal_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, NationalPark_Normal_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

NationalPark_Normal_OnTransition: 
	callnative SetTimeBasedEncounters
	end

NationalPark_Normal_EventScript_Lass::
	lock
	faceplayer
	msgbox NationalPark_Normal_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

NationalPark_Normal_EventScript_Youngster1::
	lock
	faceplayer
	msgbox NationalPark_Normal_Text_Youngster1, MSGBOX_DEFAULT
	closemessage
	release
	end

NationalPark_Normal_EventScript_Youngster2::
	lock
	faceplayer
	msgbox NationalPark_Normal_Text_Youngster2, MSGBOX_DEFAULT
	closemessage
	release
	end

NationalPark_Normal_EventScript_Teacher2::
	lock
	faceplayer
	msgbox NationalPark_Normal_Text_Teacher2, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	release
	end

NationalPark_Normal_EventScript_TeacherQuickclaw::
	lock
	faceplayer
	goto_if_set FLAG_GOT_QUICK_CLAW, NationalPark_Normal_EventScript_TeacherQuickclaw2
	msgbox NationalPark_Normal_Text_Teacher1, MSGBOX_DEFAULT
	giveitem ITEM_QUICK_CLAW
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	setflag FLAG_GOT_QUICK_CLAW
NationalPark_Normal_EventScript_TeacherQuickclaw2::
	msgbox NationalPark_Normal_Text_Teacher1_QuickClaw, MSGBOX_DEFAULT
	closemessage
	release
	end

NationalPark_Normal_EventScript_Persian::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PERSIAN, CRY_MODE_NORMAL
	msgbox NationalPark_Normal_Text_Persian, MSGBOX_DEFAULT
	waitmoncry
	release
	end



NationalPark_Normal_Text_Lass:
	.string "Regarde ! Regarde mon sac !\p"
	.string "J'ai imprimé mes favoris de mon\n"
	.string "POKéDEX et je les ai collés sur mon sac.$"

NationalPark_Normal_Text_PokefanF:
	.string "C'est une LETTRE de ma fille.\n"
	.string "Ça me remonte le moral.$"

NationalPark_Normal_Text_Teacher1:
	.string "Faites attention, s'il vous plaît !\p"
	.string "…Oups, il faut que j'arrête de penser comme\n"
	.string "une institutrice tout le temps.\p"
	.string "Tu dois être un dresseur POKéMON.\p"
	.string "Puisque tu travailles si dur, je\n"
	.string "veux que tu aies ça.$"

NationalPark_Normal_Text_Teacher1_QuickClaw:
	.string "Fais tenir cette VIVE GRIFFE à un POKéMON.\p"
	.string "Parfois, il attaquera en premier\n"
	.string "pendant le combat.$"

NationalPark_Normal_Text_Youngster1:
	.string "Je joue avec des autocollants imprimés\n"
	.string "avec mon POKéDEX.$"

NationalPark_Normal_Text_Youngster2:
	.string "J'aurai l'autocollant POKéDEX\n"
	.string "de l'autre si je gagne.$"

NationalPark_Normal_Text_Teacher2:
	.string "Je me promène dans le PARC, mais je\n"
	.string "n'entre jamais dans les hautes herbes.\p"
	.string "Les DRESSEURS veulent toujours se battre…\p"
	.string "Tu as dû participer à beaucoup de combats.\n"
	.string "Laisse-moi soigner tes POKéMON.$"

NationalPark_Normal_Text_Persian:
	.string "PERSIAN : Fufushaa !$"

NationalPark_Normal_EventScript_Jack::
	trainerbattle_single TRAINER_JACK NationalPark_Normal_Text_SchoolboyJack1_Seen, NationalPark_Normal_Text_SchoolboyJack1_Beaten
	msgbox NationalPark_Normal_Text_SchoolboyJack_After, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_Beverly::
	trainerbattle_single TRAINER_BEVERLY NationalPark_Normal_Text_PokefanFBeverly1_Seen, NationalPark_Normal_Text_PokefanFBeverly1_Beaten
	msgbox NationalPark_Normal_Text_PokefanFBeverly_After, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_William::
	trainerbattle_single TRAINER_WILLIAM NationalPark_Normal_Text_PokefanmWilliam_Seen, NationalPark_Normal_Text_PokefanmWilliam_Beaten
	msgbox NationalPark_Normal_Text_PokefanmWilliam_After, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_Krise::
	trainerbattle_single TRAINER_KRISE NationalPark_Normal_Text_LassKrise_Seen, NationalPark_Normal_Text_LassKrise_Beaten
	msgbox NationalPark_Normal_Text_LassKrise_After, MSGBOX_AUTOCLOSE
	end

NationalPark_Normal_EventScript_TM_Dig::
	finditem ITEM_TM_DIG
	end

NationalPark_Normal_EventScript_Item_Soothe_Bell::
	finditem ITEM_SOOTHE_BELL
	end

NationalPark_Normal_Text_SchoolboyJack1_Seen:
	.string "Le monde des POKéMON est profond.\p"
	.string "Il reste encore beaucoup de choses\n"
	.string "qu'on ne connaît pas.\p"
	.string "Mais j'en sais plus que toi !$"

NationalPark_Normal_Text_SchoolboyJack1_Beaten:
	.string "Qu-qu-quoi ?$"

NationalPark_Normal_Text_SchoolboyJack_After:
	.string "Il y a beaucoup à apprendre.\p"
	.string "Par exemple...\p"
	.string "Il existe 50 sortes de CT.\p"
	.string "Les POKéMON échangés montent de niveau plus vite.$"

NationalPark_Normal_Text_PokefanFBeverly1_Seen:
	.string "Mes POKéMON sont tout simplement adorables.\p"
	.string "Laisse-moi te dire à quel point mes\n"
	.string "chéris me rendent fière.$"

NationalPark_Normal_Text_PokefanFBeverly1_Beaten:
	.string "Je peux te battre en fierté, mais…$"

NationalPark_Normal_Text_PokefanFBeverly_After:
	.string "Je dois dire, tes POKéMON sont\n"
	.string "plutôt mignons, eux aussi.$"

NationalPark_Normal_Text_PokefanmWilliam_Seen:
	.string "On adore nos POKéMON, même s'ils\n"
	.string "nous détestent.\p"
	.string "C'est ça, être un FAN.$"

NationalPark_Normal_Text_PokefanmWilliam_Beaten:
	.string "M-mes POKéMON !$"

NationalPark_Normal_Text_PokefanmWilliam_After:
	.string "J'ai perdu le combat, mais mes POKéMON remportent\n"
	.string "le prix du plus beau.$"

NationalPark_Normal_Text_LassKrise_Seen:
	.string "Bonjour ? Pourquoi tu me fixes ?\p"
	.string "Oh, un combat ?$"

NationalPark_Normal_Text_LassKrise_Beaten:
	.string "…Hmm…$"

NationalPark_Normal_Text_LassKrise_After:
	.string "Je pensais que tu me regardais\n"
	.string "parce que je suis mignon !$"

NationalPark_Normal_Text_Sign_RelaxationSquare:
	.string "PLACE DE DÉTENTE\n"
	.string "PARC NATIONAL$"

NationalPark_Normal_Text_Sign_BattleNotice:
	.string "Qu'est-ce que cet avis ?\p"
	.string "Merci de ne combattre que dans l'herbe.\p"
	.string "BUREAU DU GARDIEN DU PARC NATIONAL$"

NationalPark_Normal_Text_TrainerTips:
	.string "CONSEILS DRESSEUR\p"
	.string "Imprime une LETTRE en l'ouvrant puis\n"
	.string "en appuyant sur START.$"
