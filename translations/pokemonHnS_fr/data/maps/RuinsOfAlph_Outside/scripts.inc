RuinsOfAlph_Outside_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RuinsOfAlph_Outside_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

RuinsOfAlph_Outside_OnTransition: 
	callnative SetTimeBasedEncounters
	end	

RuinsOfAlph_Outside_EventScript_Quagsire::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_QUAGSIRE, CRY_MODE_NORMAL
	msgbox RuinsOfAlph_Outside_Text_Quagsire, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RuinsOfAlph_Outside_Text_Quagsire:
	.string "MARAISTE : Quag Quag$"

RuinsOfAlph_Outside_EventScript_Stan::
	trainerbattle_single TRAINER_STAN, RuinsOfAlph_Outside_Text_SuperNerdStan_Seen, RuinsOfAlph_Outside_Text_SuperNerdStan_Beaten
	msgbox RuinsOfAlph_Outside_Text_SuperNerdStan_After, MSGBOX_AUTOCLOSE
	end

RuinsOfAlph_Outside_EventScript_Nathan::
	trainerbattle_single TRAINER_NATHAN, RuinsOfAlph_Outside_Text_PsychicNathan_Seen, RuinsOfAlph_Outside_Text_PsychicNathan_Beaten
	msgbox RuinsOfAlph_Outside_Text_PsychicNathan_After, MSGBOX_AUTOCLOSE
	end

RuinsOfAlph_Outside_EventScript_Youngster1::
	lock
	faceplayer
	msgbox RuinsOfAlph_Outside_Text_Youngster1, MSGBOX_DEFAULT
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Youngster2::
	lock
	faceplayer
	msgbox RuinsOfAlph_Outside_Text_Youngster2, MSGBOX_DEFAULT
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Fisher1::
	lock
	faceplayer
	msgbox RuinsOfAlph_Outside_Text_Fisher1, MSGBOX_DEFAULT
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Fisher2::
	lock
	faceplayer
	msgbox RuinsOfAlph_Outside_Text_Fisher2, MSGBOX_DEFAULT
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Sign1::
	lock
	msgbox RuinsOfAlph_Outside_Text_MainSign, MSGBOX_SIGN
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Sign2::
	lock
	msgbox RuinsOfAlph_Outside_Text_ResearchSign, MSGBOX_SIGN
	closemessage
	release
	end

RuinsOfAlph_Outside_EventScript_Sign3::
	lock
	msgbox RuinsOfAlph_Outside_Text_MysteryChamberSign, MSGBOX_SIGN
	closemessage
	release
	end

RuinsOfAlph_Outside_Text_Scientist:
	.string "Hm ? C'est\n"
	.string "un POKéDEX,\p"
	.string "n'est-ce pas ?\n"
	.string "Puis-je le voir ?\p"
	.string "Il y a tellement\p"
	.string "de types de\p"
	.string "POKéMON.\n"
	.string "Hm ? Qu'est-ce\p"
	.string "que c'est ?\p"
	.string "Qu'est-ce que\n"
	.string "ce POKéMON ?\n"
	.string "Oh, c'est un\p"
	.string "POKéMON rare !\n"
	.string "Tu es chanceux !$"

RuinsOfAlph_Outside_Text_SuperNerdStan_Seen:
	.string "Qu'est-ce que tu veux ? J'étudie--\n"
	.string "ne me dérange pas !$"

RuinsOfAlph_Outside_Text_SuperNerdStan_Beaten:
	.string "Désolé…\n"
	.string "Je suis frustré par notre manque\p"
	.string "de vraie compréhension…$"

RuinsOfAlph_Outside_Text_SuperNerdStan_After:
	.string "Les RUINES datent d'environ 1500\n"
	.string "ans.\p"
	.string "Personne ne sait qui les a construites.\p"
	.string "On ne sait pas non plus si les statues\n"
	.string "de POKéMON ont une signification.\p"
	.string "Tout cela reste un grand mystère…$"

RuinsOfAlph_Outside_Text_PsychicNathan_Seen:
	.string "Hmmm… C'est un endroit étrange.$"

RuinsOfAlph_Outside_Text_PsychicNathan_Beaten:
	.string "…$"

RuinsOfAlph_Outside_Text_PsychicNathan_After:
	.string "J'aime réfléchir ici.$"

RuinsOfAlph_Outside_Text_MysteryChamberSign:
	.string "CHAMBRE DES PANNEAUX DE PIERRE MYSTÈRE$"

RuinsOfAlph_Outside_Text_MainSign:
	.string "RUINES D'ALPHA\n"
	.string "VISITEURS BIENVENUS$"

RuinsOfAlph_Outside_Text_ResearchSign:
	.string "CENTRE DE RECHERCHE DES RUINES D'ALPHA\p"
	.string "L'AUTORITÉ SUR LES\n"
	.string "RUINES D'ALPHA$"

RuinsOfAlph_Outside_Text_Fisher1:
	.string "En explorant les RUINES, nous avons\n"
	.string "soudain senti une présence étrange.\p"
	.string "On a tous eu peur et on s'est enfuis.\n"
	.string "Fais attention, toi aussi.$"

RuinsOfAlph_Outside_Text_Fisher2:
	.string "Les RUINES cachent un énorme secret !\p"
	.string "…Je crois…$"

RuinsOfAlph_Outside_Text_Youngster1:
	.string "Il y a plein de types de ZARBI,\n"
	.string "alors on les utilise pour nos codes secrets.$"

RuinsOfAlph_Outside_Text_Youngster2:
	.string "A… H… E… A… D… Hmm…\p"
	.string "Quoi ?\p"
	.string "Je décode ce message !$"
