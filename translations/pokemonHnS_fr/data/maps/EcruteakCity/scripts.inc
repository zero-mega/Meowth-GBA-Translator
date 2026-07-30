.set LOCALID_ECRUTEAK_GRAMPS, 4
.set LOCALID_ECRUTEK_SILVER, 33

EcruteakCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EcruteakCity_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

EcruteakCity_OnTransition::
	callnative SetTimeBasedEncounters
	end

EcruteakCity_Test_Lugia::
	setvar VAR_LUGIA_OR_HOOH, 1
	end
EcruteakCity_Test_League::
	setvar VAR_COMPLETED_HO_OH, 4
	setvar VAR_COMPLETED_LUGIA, 4
	end


EcruteakCity_EventScript_Trigger::
	@flagheap
	clearflag FLAG_RELEASED_BEASTS
	clearflag FLAG_AMPHAROS_HEALED
	clearflag FLAG_HIDE_ECRUTEAK_BILL
	clearflag FLAG_DEFEATED_HO_OH
	clearflag FLAG_CAUGHT_HO_OH
	clearflag FLAG_DEFEATED_LUGIA
	clearflag FLAG_CAUGHT_LUGIA
	clearflag FLAG_HIDE_ECRUTEAK_ROCKET
	clearflag FLAG_HIDE_BURNED_TOWER_NPCS  
	clearflag FLAG_HIDE_BURNED_TOWER_BEASTS
	clearflag FLAG_HIDE_BURNED_TOWER_B1F_EUSINE
	clearflag FLAG_HIDE_ECRUTEAK_CITY_SAGE
	clearflag FLAG_CAUGHT_ENTEI
	clearflag FLAG_CAUGHT_RAIKOU
	clearflag FLAG_GOT_TM_SNATCH
	clearflag FLAG_HIDE_ROUTE42_SUICUNE
	clearflag FLAG_GOT_TYROGUE
	clearflag FLAG_BEAT_KIYO
	clearflag FLAG_ENABLE_BAOBA_MATCH_CALL
	clearflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_NPCS
	clearflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_ZUKI
	clearflag FLAG_HIDE_TINTOWER_GUARD
	clearflag FLAG_HIDE_WHIRL_ISLANDS_TENTACRUEL
	clearflag FLAG_HIDE_LUGIA
	clearflag FLAG_HIDE_HO_OH

	setflag FLAG_VISITED_ECRUTEAK_CITY
	setflag FLAG_HIDE_ROUTE42_EUSINE

	setflag FLAG_HIDE_TIN_TOWER_KIMONO_GIRLS
	setflag FLAG_HIDE_WHIRL_ISLANDS_KIMONO_GIRLS
	setflag FLAG_HIDE_ECRUTEAK_CITY_THEATER_KIMONOS
	setflag FLAG_HIDE_ROUTE39_SHADOW
	setflag FLAG_HIDE_ECRUTEAK_SILVER
	setvar VAR_COMPLETED_HO_OH, 0
	setvar VAR_COMPLETED_LUGIA, 0
	setvar VAR_ECRUTEAK_CITY_THEATER, 0 
	setvar VAR_ECRUTEAK_CITY_STATE, 1
	end

EcruteakCity_Trigger_Silver::
	lockall
	opendoor 39, 40
	waitdooranim
	delay 10
	clearflag FLAG_HIDE_ECRUTEAK_SILVER
	addobject LOCALID_ECRUTEK_SILVER
	playbgm MUS_HG_ENCOUNTER_RIVAL, TRUE
	playse SE_BANG
	applymovement LOCALID_ECRUTEK_SILVER, EcruteakCity_Movement_Silver1
	applymovement OBJ_EVENT_ID_PLAYER, EcruteakCity_Movement_Silver1
	message EcruteakCity_Text_Silver1
	
	waitmovement OBJ_EVENT_ID_PLAYER
	waitmovement LOCALID_ECRUTEK_SILVER
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	closedoor 39, 40
	waitdooranim
	msgbox EcruteakCity_Text_Silver2, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_ECRUTEK_SILVER, Common_Movement_ExclamationMark
	delay 60
	turnobject LOCALID_ECRUTEK_SILVER, DIR_SOUTH
	msgbox EcruteakCity_Text_Silver3, MSGBOX_DEFAULT
	closemessage

	applymovement LOCALID_ECRUTEK_SILVER, EcruteakCity_Movement_Silver2
	waitmovement LOCALID_ECRUTEK_SILVER


	setflag FLAG_HIDE_ECRUTEAK_SILVER
	removeobject LOCALID_ECRUTEK_SILVER
	fadedefaultbgm

	setvar VAR_ECRUTEAK_CITY_THEATER, 5
	releaseall
	end

EcruteakCity_Movement_Silver1:
	delay_16
	lock_facing_direction
	walk_down
	unlock_facing_direction
	step_end

EcruteakCity_Movement_Silver2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

EcruteakCity_Text_Silver1:
	.string "BOUM !!$"

EcruteakCity_Text_Silver2:
	.string "{RIVAL} : Comment... ? Comment est-ce\n"
	.string "possible ? Comment puis-je perdre contre de simples\l"
	.string "FILLES KIMONO... ?$"

EcruteakCity_Text_Silver3:
	.string "{RIVAL} : Tu m'observais,\n"
	.string "{PLAYER}…\p"
	.string "Ouais, c'est ça !\p"
	.string "Je n'aurais jamais cru que battre cinq\n"
	.string "FILLES KIMONO serait si dur…\p"
	.string "J'ai été réduit en bouillie…\p"
	.string "…\p"
	.string "Tu dois être venu pour la même raison,\n"
	.string "n'est-ce pas ?\p"
	.string "Ne te laisse pas aller juste parce que tu\n"
	.string "as battu la TEAM ROCKET !\p"
	.string "Ces FILLES KIMONO sont incroyablement\n"
	.string "fortes.\p"
	.string "Vois si tu peux les battre.\p"
	.string "Mais je ne reviens pas, je ne veux pas\n"
	.string "te voir gagner.$"

EcruteakCity_EventScript_Gramps::
	lock
	faceplayer
	msgbox EcruteakCity_Text_Gramps1, MSGBOX_DEFAULT
	closemessage
	release
	end
		
EcruteakCity_EventScript_Lass::
	lock
	faceplayer
	msgbox EcruteakCity_Text_Lass1, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_RELEASED_BEASTS, EcruteakCity_EventScript_Girl2
	msgbox EcruteakCity_Text_Lass2, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_Girl2::
	msgbox EcruteakCity_Text_Lass2_ReleasedBeasts, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScrip_Man::
	lock
	faceplayer
	goto_if_set FLAG_AMPHAROS_HEALED, EcruteakCity_EventScrip_Man2
	msgbox EcruteakCity_Text_Fisher, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScrip_Man2::
	msgbox EcruteakCity_Text_Fisher_JasmineReturned, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_Youngster::
	lock
	faceplayer
	msgbox EcruteakCity_Text_Youngster, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_SageRight::
	lock
	faceplayer
	msgbox EcruteakCity_Text_Gramps2, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_SageTower::
	lock
	faceplayer
	msgbox EcruteakCity_Text_Gramps3, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_SageGym::
	lock
	faceplayer
	msgbox EcruteakCity_Text_SageGym, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_EventScript_TheaterSign::
	lock
	msgbox EcruteakCity_Text_DanceTheaterSign, MSGBOX_SIGN
	closemessage
	release
	end	

EcruteakCity_EventScript_OfficeSign::
	lock
	msgbox EcruteakCity_Text_OfficeSign, MSGBOX_SIGN
	closemessage
	release
	end	

EcruteakCity_EventScript_BurnedSign::
	lock
	msgbox EcruteakCity_Text_BurnedTowerSign, MSGBOX_SIGN
	closemessage
	release
	end	

EcruteakCity_EventScript_CitySign::
	lock
	msgbox EcruteakCity_Text_Sign, MSGBOX_SIGN
	closemessage
	release
	end	

EcruteakCity_EventScript_GymSign::
	lock
	msgbox EcruteakCity_Text_GymSign, MSGBOX_SIGN
	closemessage
	release
	end

EcruteakCity_EventScript_Eevee::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_EEVEE, CRY_MODE_NORMAL
	msgbox EcruteakCity_Text_Eevee, MSGBOX_DEFAULT
	waitmoncry
	release
	end

EcruteakCity_EventScript_Vulpix::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_VULPIX, CRY_MODE_NORMAL
	msgbox EcruteakCity_Text_Vulpix, MSGBOX_DEFAULT
	waitmoncry
	release
	end

EcruteakCity_EventScript_Item_RareCandy::
	finditem ITEM_RARE_CANDY
	end

EcruteakCity_Text_Eevee:
	.string "EVOLI : Veee !$"

EcruteakCity_Text_Vulpix:
	.string "GOUPIX : Vullll Pix !$"


EcruteakCity_Text_UnusedMissingDaughter:
	.string "Oh, non. Oh, non…\p"
	.string "Ma fille a disparu.\p"
	.string "Non… Elle ne serait pas allée à la\n"
	.string "TOUR CENDRÉE.\p"
	.string "Je lui avais dit de ne pas s'en approcher…\p"
	.string "Des gens semblent y disparaître…\p"
	.string "Oh, que dois-je faire… ?$"

EcruteakCity_Text_Gramps1:
	.string "ECRUTEAK avait autrefois deux tours :\n"
	.string "une à l'est et une à l'ouest.$"

EcruteakCity_Text_Gramps2:
	.string "Ah, mon enfant. As-tu appris à\n"
	.string "danser comme les FILLES KIMONO ?\p"
	.string "Si tu vas à leur THÉÂTRE DE DANSE,\n"
	.string "un drôle de vieil homme te donnera\l"
	.string "quelque chose de sympa, paraît-il.$"

EcruteakCity_Text_Lass1:
	.string "Je vais m'entraîner au THÉÂTRE DE DANSE.\n"
	.string "Tu veux me rejoindre ?$"

EcruteakCity_Text_Lass2:
	.string "La tour qui était ici… Ma\p"
	.string "grand-mère m'a dit qu'elle était beaucoup\n"
	.string "plus haute. On dit qu'il\p"
	.string "y a des fantômes maintenant.$"

EcruteakCity_Text_Lass2_ReleasedBeasts:
	.string "Trois grands POKéMON se sont enfuis dans des\n"
	.string "directions différentes. C'étaient quoi ?$"

EcruteakCity_Text_Fisher:
	.string "J'ai entendu une rumeur sur le PHARE\n"
	.string "d'OLIVILLE.\p"
	.string "Le POKéMON qui sert de balise est tombé malade.\n"
	.string "On dirait qu'ils\l"
	.string "ont des ennuis.$"

EcruteakCity_Text_Fisher_JasmineReturned:
	.string "Le POKéMON du PHARE D'OLIVILLE\n"
	.string "a été soigné.\p"
	.string "Les bateaux peuvent de nouveau naviguer\n"
	.string "en mer la nuit.$"

EcruteakCity_Text_Youngster:
	.string "J'ai entendu que des POKéMON déchaînés\n"
	.string "font des ravages au LAC COLÈRE. J'aimerais voir ça.$"

EcruteakCity_Text_Gramps3:
	.string "Dans le passé\p"
	.string "lointain…\n"
	.string "Cette tour a brûlé dans\p"
	.string "un incendie. Trois\n"
	.string "POKéMON sans\p"
	.string "nom y périrent.\n"
	.string "Un arc-en-ciel\p"
	.string "apparut ensuite…\p"
	.string "C'est une\n"
	.string "légende triste.$"

EcruteakCity_Text_SageGym:
	.string "Le CHAMPION d'ARÈNE MORTY n'est pas là en ce\n"
	.string "moment. Tu le trouveras peut-être à la\l"
	.string "TOUR CENDRÉE.$"

EcruteakCity_Text_Sign:
	.string "ROSALIA\n"
	.string "Une Ville Historique\p"
	.string "Où le Passé Rencontre le Présent$"

EcruteakCity_Text_TinTowerSign:
	.string "TOUR CENDRÉE\p"
	.string "On dit qu'un POKéMON légendaire\n"
	.string "se repose ici.$"

EcruteakCity_Text_OfficeSign:
	.string "Poste de barrière vers la TOUR CUIVRE\p"
	.string "Interdit aux indignes.$"

EcruteakCity_Text_GymSign:
	.string "ARÈNE POKéMON D'ECRUTEAK\n"
	.string "CHAMPION D'ARÈNE : MORTY\p"
	.string "Le voyant mystique du futur$"

EcruteakCity_Text_DanceTheaterSign:
	.string "THÉÂTRE DE DANSE D'ECRUTEAK$"

EcruteakCity_Text_BurnedTowerSign:
	.string "TOUR CENDRÉE\p"
	.string "Elle a été détruite par un incendie\n"
	.string "mystérieux.\p"
	.string "Restez à l'écart, c'est dangereux.$"
