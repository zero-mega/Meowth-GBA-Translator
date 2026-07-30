.set LOCALID_GOLDENROD_ROCKET_SCOUT, 11

GoldenrodCity_MapScripts::
	.byte 0

GoldenrodCity_EventScript_Trigger:: @flagheap
	call_if_unset FLAG_SHOWN_ELM_TOGEPI, GoldenrodCity_Elm_Togepi_Call
	setflag FLAG_VISITED_GOLDENROD_CITY
	setflag FLAG_HIDE_GOLDENROD_ROCKETS
	setflag FLAG_HIDE_GOLDENROD_BILL
	setflag FLAG_HIDE_GOLDENROD_UNDERGROUND_KIMONO
	setflag FLAG_HIDE_GOLDENROD_UNDERGROUND_SILVER
	setflag FLAG_HIDE_ROCKET_GOLDENROD_RADIOTOWER_1
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_PETREL
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR_2
	
	clearflag FLAG_HIDE_GOLDENROD_BEAUTY
	clearflag FLAG_HIDE_GOLDENROD_ROCKET_SCOUT
	clearflag FLAG_HIDE_GOLDENROD_NPCS
	clearflag FLAG_GOT_RETURN
	clearflag FLAG_GOT_FRUSTRATION
	clearflag FLAG_RECEIVED_BIKE
	clearflag FLAG_RECEIVED_SQUIRTBOTTLE
	clearflag FLAG_GOT_EEVEE
	clearflag FLAG_SYS_PC_BILL
	clearflag FLAG_RETURNED_MACHINE_PART
	clearflag FLAG_UNLOCKED_GOLDENROD_UNDERGROUND_DOOR
	clearflag FLAG_GOLDENROD_MACHOKE_1
	clearflag FLAG_GOLDENROD_MACHOKE_2
	clearflag FLAG_GOLDENROD_MACHOKE_3
	clearflag FLAG_COMPLETED_SWITCHES
	clearflag FLAG_ENABLE_RADIO
	clearflag FLAG_KANTO_RADIO_GOT
	clearflag FLAG_GOLDENROD_NPC_TRADE_COMPLETED
	clearflag FLAG_GOT_SKILL_SWAP
	clearflag FLAG_HIDE_RADIOTOWER_GATE
	clearflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR
	clearflag FLAG_GOT_MARY_BRIGHT_POWDER
	clearflag FLAG_GOT_QUICK_CLAW
	clearflag FLAG_GOT_MAGNET

	setvar VAR_BUG_CONTEST_STATE, 0
	setvar VAR_KENYA, 0
	setvar VAR_LUGIA_OR_HOOH, 0
	setvar VAR_TRAIN, 0
	setvar VAR_ELEVATOR, 0
	setvar VAR_GOLDENROD_CITY_STATE, 1
	release
	end

GoldenrodCity_Trigger_Music::
	goto_if_lt VAR_GOLDENROD_CITY_STATE, 6, GoldenrodCity_Trigger_MusicNotYet
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 11, GoldenrodCity_Trigger_MusicNotYet
	playbgm MUS_HG_ROCKET_TAKEOVER, TRUE
	setvar VAR_TEMP_0, 1 
	end

GoldenrodCity_Trigger_MusicNotYet::
	setvar VAR_TEMP_0, 1
	end

GoldenrodCity_Elm_Togepi_Call::
	lock
	pokenavcall GoldenrodCity_Text_ElmCall
	waitmessage
	delay 30
	release
	return

GoldenrodCity_EventScript_PokefanM::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Youngster::
	msgbox GoldenrodCity_Text_Youngster1, MSGBOX_NPC
	end

GoldenrodCity_EventScript_Youngster2::
	msgbox GoldenrodCity_Text_Youngster2, MSGBOX_NPC
	end

GoldenrodCity_EventScript_CooltrainerF::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_GOLDENROD_ROCKET_SCOUT, GoldenrodCity_EventScript_CooltrainerFCleared
	msgbox GoldenrodCity_Text_CooltrainerF1, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_CooltrainerFCleared::
	msgbox GoldenrodCity_Text_CooltrainerF1_Cleared, MSGBOX_NPC
	end

GoldenrodCity_EventScript_Lass::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Lass, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Gramps::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Gramps, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_NameRaterSign::
	msgbox GoldenrodCity_Text_NameRaterSign, MSGBOX_SIGN
	end

GoldenrodCity_EventScript_RocketScout::
	lock
	msgbox GoldenrodCity_Text_RocketScout1, MSGBOX_DEFAULT
	closemessage
	PLAYSE SE_PIN
	applymovement LOCALID_GOLDENROD_ROCKET_SCOUT, Common_Movement_ExclamationMark
	delay 20
	faceplayer
	msgbox GoldenrodCity_Text_RocketScout2, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_GOLDENROD_ROCKET_SCOUT, DIR_NORTH
	release
	end

GoldenrodCity_EventScript_Rocket1::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Rocket1, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Rocket2::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Rocket2, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Rocket3::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Rocket3, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Rocket4::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Rocket4, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Rocket5::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Rocket5, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Rocket6::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Rocket6, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Woman::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Woman, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Hiker::
	lock
	faceplayer
	goto_if_set FLAG_DAY_POKEMON, GoldenrodCity_EventScript_Hiker2
	msgbox GoldenrodCity_Text_HikerDay, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Hiker2::
	msgbox GoldenrodCity_Text_HikerNight, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_EventScript_Snubbull::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SNUBBULL, CRY_MODE_NORMAL
	msgbox GoldenrodCity_Text_Snubbull, MSGBOX_DEFAULT
	waitmoncry
	release
	end

GoldenrodCity_EventScript_Mime::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MR_MIME, CRY_MODE_NORMAL
	msgbox GoldenrodCity_Text_MrMime, MSGBOX_DEFAULT
	waitmoncry
	release
	end

GoldenrodCity_EventScript_SignUnderground::
	lock
	msgbox GoldenrodCity_Text_UndergroundSouthSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignDept::
	lock
	msgbox GoldenrodCity_Text_DeptStoreSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignBike::
	lock
	msgbox GoldenrodCity_Text_BikeShopSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignTrain::
	lock
	msgbox GoldenrodCity_Text_StationSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignGym::
	lock
	msgbox GoldenrodCity_Text_GymSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignFlower::
	lock
	msgbox GoldenrodCity_Text_FlowerShopSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignRadio::
	lock
	msgbox GoldenrodCity_Text_RadioTowerSign, MSGBOX_SIGN
	closemessage
	release
	end
GoldenrodCity_EventScript_SignGameCorner::
	lock
	msgbox GoldenrodCity_Text_GameCornerSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_EventScript_Beauty::
	lock
	faceplayer
	msgbox GoldenrodCity_Text_Beauty, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_Text_Beauty:
	.string "C'est l'ARÈNE de DOUBLONVILLE !\p"
	.string "Notre CHAMPIONNE CAROLINE n'est pas\n"
	.string "là pour l'instant. Elle est peut-être à la\l"
	.string "TOUR RADIO.$"

GoldenrodCity_Text_Woman:
	.string "Je m'entraînais à l'ARÈNE de WHITNEY,\n"
	.string "mais tous ses pleurs me donnaient\l"
	.string "mal à la tête.$"

GoldenrodCity_Text_HikerDay:
	.string "Quand je suis entré au CASINO,\n"
	.string "c'était la nuit... Combien de temps suis-je\l"
	.string "resté là-dedans ?!$"

GoldenrodCity_Text_HikerNight:
	.string "Quand je suis entré au CASINO,\n"
	.string "c'était le jour... Combien de temps suis-je\l"
	.string "resté là-dedans ?!$"

GoldenrodCity_Text_Snubbull:
	.string "SNEBULL : SNEUUUBUUUULL !$"

GoldenrodCity_Text_MrMime:
	.string "............................$"

GoldenrodCity_Text_ElmCall:
	.string "PROF.ORME : Bonjour, {PLAYER} ?\n"
	.string "Cet ŒUF a-t-il éclos ?\p"
	.string "Une fois éclos, n'oublie pas de\n"
	.string "l'apporter au labo ! Je dois\l"
	.string "le voir !$"

GoldenrodCity_Text_PokefanM:
	.string "Ils ont construit la nouvelle TOUR RADIO\n"
	.string "pour remplacer l'ancienne qui grincait.$"

GoldenrodCity_Text_Youngster1:
	.string "Je sais qu'il y a une nouvelle BOUTIQUE DE VÉLOS,\n"
	.string "mais je ne la trouve nulle part.$"

GoldenrodCity_Text_CooltrainerF1:
	.string "Cet homme en noir est habillé\n"
	.string "comme un membre de la TEAM ROCKET ?\p"
	.string "C'est ridicule !$"

GoldenrodCity_Text_CooltrainerF1_Cleared:
	.string "Cet homme en noir faisait vraiment partie\n"
	.string "de la TEAM ROCKET ? Je n'arrive pas à y croire !$"

GoldenrodCity_Text_CooltrainerF2:
	.string "La TOUR RADIO de DOUBLONVILLE\n"
	.string "est un vrai repère.\p"
	.string "Ils font une campagne en ce moment.\p"
	.string "Ils te donneront une RADIO flambant neuve\n"
	.string "si tu réussis leur quiz.$"

GoldenrodCity_Text_CooltrainerF2_GotCard:
	.string "Oh, ton POKéKÉA fonctionne déjà\n"
	.string "comme radio !$"

GoldenrodCity_Text_Youngster2:
	.string "E-he-he-he…\p"
	.string "J'ai eu des ennuis pour avoir joué\n"
	.string "dans le sous-sol du GRAND MAGASIN.$"

GoldenrodCity_Text_Lass:
	.string "Cet homme à l'intérieur évalue les\n"
	.string "surnoms de tes POKéMON.\p"
	.string "Il peut même les renommer.$"

GoldenrodCity_Text_Gramps:
	.string "Ouf ! Cette ville est si grande,\n"
	.string "je ne trouve rien du tout.$"

GoldenrodCity_Text_RocketScout1:
	.string "Alors voici la TOUR RADIO…$"

GoldenrodCity_Text_RocketScout2:
	.string "Qu'est-ce que tu veux, peste ?\n"
	.string "Dégage !$"

GoldenrodCity_Text_Rocket1:
	.string "Hors de mon chemin !\n"
	.string "Dégage, gamin !$"

GoldenrodCity_Text_Rocket2:
	.string "Prendre le contrôle de la TOUR RADIO…\p"
	.string "Quoi ? Ce n'est pas ton affaire !$"

GoldenrodCity_Text_Rocket3:
	.string "Les POKéMON ? Ce ne sont que des outils\n"
	.string "pour gagner de l'argent !$"

GoldenrodCity_Text_Rocket4:
	.string "Notre rêve va bientôt se réaliser…\p"
	.string "Ce fut une longue et dure lutte…$"

GoldenrodCity_Text_Rocket5:
	.string "Hé, morveux ! T'as rien à faire ici !\n"
	.string "Dégage !$"

GoldenrodCity_Text_Rocket6:
	.string "Viens goûter la terreur de\n"
	.string "la TEAM ROCKET !$"

GoldenrodCity_Text_StationSign:
	.string "GARE DE DOUBLONVILLE$"

GoldenrodCity_Text_RadioTowerSign:
	.string "TOUR RADIO DE DOUBLONVILLE$"

GoldenrodCity_Text_DeptStoreSign:
	.string "Large sélection d'articles POKéMON !\p"
	.string "GRAND MAGASIN DE DOUBLONVILLE$"

GoldenrodCity_Text_GymSign:
	.string "ARÈNE POKéMON DE DOUBLONVILLE\n"
	.string "CHAMPIONNE D'ARÈNE : WHITNEY\p"
	.string "La fille incroyablement mignonne !$"

GoldenrodCity_Text_CitySign:
	.string "DOUBLONVILLE\p"
	.string "La ville festive au charme opulent$"

GoldenrodCity_Text_BikeShopSign:
	.string "Le monde est une piste cyclable !\n"
	.string "MAGASIN DE VÉLOS$"

GoldenrodCity_Text_GameCornerSign:
	.string "Ton terrain de jeu !\p"
	.string "CASINO DE DOUBLONVILLE$"

GoldenrodCity_Text_NameRaterSign:
	.string "JUGE DE SURNOMS\p"
	.string "Faites évaluer les surnoms de vos POKéMON$"

GoldenrodCity_Text_UndergroundNorthSign:
	.string "ENTRÉE SOUTERRAIN$"

GoldenrodCity_Text_UndergroundSouthSign:
	.string "ENTRÉE SOUTERRAIN$"


GoldenrodCity_Text_FlowerShopSign:
	.string "FLEURISTE ÉPANOUISSEMENT$"

GoldenrodCity_Text_MoveTutorAsk:
	.string "Je peux apprendre à tes POKéMON des\n"
	.string "capacités incroyables !\p"
	.string "Dois-je en enseigner une ?$"

GoldenrodCity_Text_MoveTutorCost:
	.string "Ça te coûtera 1000 jetons.\n"
	.string "OK ?$"

GoldenrodCity_Text_MoveTutorDecline:
	.string "Oh… Mais ces attaques sont géniales !$"

GoldenrodCity_Text_MoveTutorWhich:
	.string "Wahahah ! Tu ne le regretteras pas !\p"
	.string "Quelle capacité dois-je enseigner ?$"

GoldenrodCity_Text_MoveTutorNoCash:
	.string "Dommage. Il va falloir que je\n"
	.string "demande de l'argent à la maison…$"

GoldenrodCity_Text_MoveTutorUnderstand:
	.string "Si tu comprends cette capacité,\n"
	.string "tu es un vrai Dresseur.$"

GoldenrodCity_Text_MoveTutorFarewell:
	.string "Wahahah ! Adieu, gamin !$"

GoldenrodCity_Text_MoveTutorBut:
	.string "M-mais…$"

GoldenrodCity_Text_MoveTutorNotEnoughCoins:
	.string "…Tu n'as pas assez de jetons…$"
