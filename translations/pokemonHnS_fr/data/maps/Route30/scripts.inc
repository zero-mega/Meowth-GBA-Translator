.set LOCALID_ROUTE_30_JOEY, 6

Route30_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route30_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route30_OnFrame
	.byte 0

Route30_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route30_OnFrame::
	map_script_2 VAR_CHERRYGROVE_CITY_STATE, 2, Route30_EventScript_ElmCall_Trigger
	.2byte 0
	
Route30_EventScript_Boy::
	lock
	faceplayer
	goto_if_set FLAG_ADVENTURE_STARTED, Route30_EventScript_Boy2
	msgbox Route30_Text_YoungsterDirectionsToMrPokemon, MSGBOX_DEFAULT
	closemessage
	release
	end

Route30_EventScript_Boy2::
	lock
	faceplayer
	msgbox Route30_Text_YoungsterEveryoneIsBattling, MSGBOX_DEFAULT
	closemessage
	release
	end

Route30_EventScript_Girl::
	lock
	faceplayer
	msgbox Route30_Text_CooltrainerF, MSGBOX_DEFAULT
	closemessage
	release
	end

Route30_EventScript_Youngster_Joey_Fighting::
	lock
	msgbox Route30_Text_UseTackle, 	MSGBOX_AUTOCLOSE
	waitmessage
	playse SE_PIN
	applymovement LOCALID_ROUTE_30_JOEY, Common_Movement_QuestionMark
	delay 30
	faceplayer
	msgbox Route30_Text_ThisIsABigBattle, MSGBOX_AUTOCLOSE
	waitmessage
	turnobject LOCALID_ROUTE_30_JOEY DIR_NORTH
	release
	end


Route30_EventScript_Youngster_Joey::
	trainerbattle_single TRAINER_JOEY, Route30_Text_YoungsterJoey1Seen, Route30_Text_YoungsterJoey1Beaten
	msgbox Route30_Text_YoungsterJoey1After, MSGBOX_AUTOCLOSE
	end

Route30_EventScript_Youngster_Mikey::
	trainerbattle_single TRAINER_MIKEY, Route30_Text_YoungsterMikeySeen, Route30_Text_YoungsterMikeyBeaten
	msgbox Route30_Text_YoungsterMikeyAfter, MSGBOX_AUTOCLOSE
	end
	
Route30_EventScript_Bugcatcher_Don::
	trainerbattle_single TRAINER_DON, Route30_Text_BugCatcherDonSeen, Route30_Text_BugCatcherDonBeaten
	msgbox Route30_Text_BugCatcherDonAfter, MSGBOX_AUTOCLOSE
	end

Route30_EventScript_ElmCall_Trigger::
	lock
	pokenavcall Route30_Text_Elm_Disaster
	waitmessage
	delay 30
	setvar VAR_CHERRYGROVE_CITY_STATE, 3
	release
	end

Route30_EventScript_Sign::
	lock
	msgbox Route30_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end

Route30_EventScript_TrainerTips::
	lock
	msgbox Route30_Text_TrainerTips, MSGBOX_SIGN
	closemessage
	release
	end	

Route30_EventScript_Poliwag::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_POLIWAG, CRY_MODE_NORMAL
	msgbox Route30_Text_Poliwag, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route30_EventScript_Mailbox::
	msgbox Route30_Text_Mailbox, MSGBOX_SIGN
	end

Route30_Text_Mailbox:
	.string "Maison de M. POKéMON$"

Route30_Text_UseTackle:
	.string "Vas-y, RATTATA !\p"
	.string "CHARGE !$"

Route30_Text_ThisIsABigBattle:
	.string "Quoi ? C'est un gros combat !\n"
	.string "Laisse-moi tranquille !$"

Route30_Text_YoungsterJoey1Seen:
	.string "Je viens de perdre, alors j'essaie de\n"
	.string "trouver plus de POKéMON.\p"
	.string "Attends ! Tu as l'air faible ! Allez,\n"
	.string "combattons !$"

Route30_Text_YoungsterJoey1Beaten:
	.string "Argh ! Encore perdu !\n"
	.string "Bon sang !$"

Route30_Text_YoungsterJoey1After:
	.string "Faut-il que j'aie plus de POKéMON\n"
	.string "pour mieux me battre ?\p"
	.string "Non ! Je garde celui-ci\n"
	.string "quoi qu'il arrive !$"

Route30_Text_YoungsterMikeySeen:
	.string "Tu es un Dresseur POKéMON,\n"
	.string "n'est-ce pas ?\p"
	.string "Alors il faut combattre !$"

Route30_Text_YoungsterMikeyBeaten:
	.string "C'est bizarre.\n"
	.string "J'avais gagné avant.$"

Route30_Text_YoungsterMikeyAfter:
	.string "Devenir un bon Dresseur, c'est\n"
	.string "vraiment dur.\p"
	.string "Je vais combattre d'autres\n"
	.string "personnes pour m'améliorer.$"

Route30_Text_BugCatcherDonSeen:
	.string "Au lieu d'un POKéMON insecte,\n"
	.string "j'ai trouvé un dresseur !$"

Route30_Text_BugCatcherDonBeaten:
	.string "Argh ! Tu es trop fort !$"

Route30_Text_BugCatcherDonAfter:
	.string "Il ne me reste plus de POKé BALLS\n"
	.string "alors que j'attrapais des POKéMON.\p"
	.string "J'aurais dû en acheter plus…$"

Route30_Text_YoungsterDirectionsToMrPokemon:
	.string "La maison de M. POKéMON ?\n"
	.string "C'est un peu plus loin.$"

Route30_Text_YoungsterEveryoneIsBattling:
	.string "Tout le monde s'amuse\n"
	.string "à combattre !\p"
	.string "Toi aussi !$"

Route30_Text_CooltrainerF:
	.string "Je ne suis pas DRESSEUR.\p"
	.string "Mais si tu croises le regard d'un DRESSEUR,\n"
	.string "prépare-toi à combattre.$"

Route30_Text_Sign:
	.string "ROUTE 30\p"
	.string "MAUVILLE - VILLE GRIOTTE$"

Route30_Text_MrPokemonsHouseDirectionsSign:
	.string "MAISON DE M. POKéMON\n"
	.string "TOUT DROIT !$"

Route30_Text_MrPokemonsHouseSign:
	.string "MAISON DE MONSIEUR POKéMON$"

Route30_Text_TrainerTips:
	.string "CONSEILS AUX DRESSEURS\p"
	.string "Ne volez pas les POKéMON\n"
	.string "des autres !\p"
	.string "Les POKé BALLS ne doivent être lancées\n"
	.string "que sur des POKéMON sauvages !$"

Route30_Text_YoungsterJoeyGiveHPUp:
	.string "J'ai encore perdu…\n"
	.string "Gee, tu es costaud !\p"
	.string "Oh oui, j'ai presque oublié\n"
	.string "que je devais te donner ça.\p"
	.string "Utilise-le pour devenir encore\n"
	.string "plus fort, OK ?\p"
	.string "Je vais devenir plus fort aussi.$"

Route30_Text_Elm_Disaster:
	.string "PROF. ORME : A-allô ? {PLAYER} ? C'est\n"
	.string "une catastrophe !\p"
	.string "Euh, um, c'est terrible !\p"
	.string "Que dois-je faire ? Ça…\n"
	.string "Oh, non…\p"
	.string "Reviens ici tout de suite !$"


Route30_Text_Poliwag:
	.string "PTITARD : Wag waag !$"
