FuchsiaCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FuchsiaCity_EventScript_CityEnter
	.byte 0

FuchsiaCity_OnFrame::
	map_script_2 VAR_FUCHSIA_CITY_STATE, 0,  FuchsiaCity_EventScript_BaobaCall
	.2byte 0

FuchsiaCity_EventScript_CityEnter::
	setflag FLAG_VISITED_FUCHSIA_CITY
	end

FuchsiaCity_EventScript_BaobaCall::
	pokenavcall FuchsiaCity_Text_Baoba
	waitmessage
	delay 30
	setvar VAR_BAOBA_QUEST_STATE, 1
	setvar VAR_FUCHSIA_CITY_STATE, 1
	end

FuchsiaCity_Text_Baoba:
	.string "GARDIEN BAOBA : {PLAYER} !\p"
	.string "C'est le GARDIEN BAOBA.\p"
	.string "Quelque chose d'affreux s'est passé !\n"
	.string "Ma vieille ZONE SAFARI à CARMIN SUR MER\l"
	.string "a été rachetée et rouverte !\p"
	.string "Et apparemment elle a de nouveaux\n"
	.string "POKéMON exotiques !\p"
	.string "Ça nuit à mes affaires !\p"
	.string "{PLAYER}, tu dois t'aventurer dans la\n"
	.string "nouvelle ZONE SAFARI et attraper un POKéMON\l"
	.string "pour me le montrer. Je dois en savoir plus sur ces\l"
	.string "POKéMON « exotiques ».\p"
	.string "S'il te plaît {PLAYER}, mes affaires\n"
	.string "dépendent de toi !$"

FuchsiaCity_EventScript_Dratini::
	lock
	showmonpic SPECIES_DRATINI, 10, 3
	delay 60
	hidemonpic
	release
	end
FuchsiaCity_EventScript_Kangaskhan::
	lock
	showmonpic SPECIES_KANGASKHAN, 10, 3
	delay 60
	hidemonpic
	release
	end
FuchsiaCity_EventScript_Cubone::
	lock
	showmonpic SPECIES_CUBONE, 10, 3
	delay 60
	hidemonpic
	release
	end
FuchsiaCity_EventScript_Omanyte::
	lock
	showmonpic SPECIES_OMANYTE, 10, 3
	delay 60
	hidemonpic
	release
	end
FuchsiaCity_EventScript_Kabuto::
	lock
	showmonpic SPECIES_KABUTO, 10, 3
	delay 60
	hidemonpic
	release
	end

FuchsiaCity_EventScript_Youngster::
	msgbox FuchsiaCity_Text_Youngster, MSGBOX_NPC
	end

FuchsiaCity_EventScript_PokefanM::
	msgbox FuchsiaCity_Text_PokefanM, MSGBOX_NPC
	end

FuchsiaCity_EventScript_Teacher::
	msgbox FuchsiaCity_Text_Teacher, MSGBOX_NPC
	end

FuchsiaCity_EventScript_CitySign::
	msgbox FuchsiaCity_Text_Sign, MSGBOX_SIGN
	end

FuchsiaCity_EventScript_GymSign::
	msgbox FuchsiaCity_Text_GymSign, MSGBOX_SIGN
	end

FuchsiaCity_EventScript_SafariZone::
	msgbox FuchsiaCity_Text_SafariZone, MSGBOX_NPC
	end

FuchsiaCity_Text_Youngster:
	.string "Un des CONSEILS DES 4 était autrefois\n"
	.string "le CHAMPION de l'ARÈNE de FUCHSIA.$"

FuchsiaCity_Text_PokefanM:
	.string "La fille de KOGA lui a succédé comme\n"
	.string "CHAMPIONNE d'ARÈNE après qu'il ait rejoint le\l"
	.string "CONSEIL 4.$"

FuchsiaCity_Text_Teacher:
	.string "La ZONE SAFARI est sous nouvelle\n"
	.string "direction.\p"
	.string "Et elle regorge de nouveaux POKéMON !$"

FuchsiaCity_Text_Sign:
	.string "PARMANIE\p"
	.string "Admirez ! C'est Rose Passion !$"

FuchsiaCity_Text_GymSign:
	.string "CRAMOIS'ÎLE ARENE POKéMON\n"
	.string "CHAMPION : JANINE\p"
	.string "La Maîtresse Ninja Empoisonnée$"

FuchsiaCity_Text_SafariZoneOfficeSign:
	.string "Il y a un avis ici…\p"
	.string "Le BUREAU DE LA ZONE SAFARI est fermé\n"
	.string "jus'à nouvel ordre.$"

FuchsiaCity_Text_SafariZone:
	.string "ZONE SAFARI\n"
	.string "MAINTENANT LA PROPRIÉTÉ\l"
	.string "DE DEVON S.A.R.L.$"

FuchsiaCity_Text_SafariZoneClosedSign:
	.string "Le GARDIEN est en voyage à l'étranger.\p"
	.string "Par conséquent, la ZONE SAFARI est\n"
	.string "fermée.$"

FuchsiaCity_Text_NoLitteringSign:
	.string "Interdiction de jeter des déchets.\p"
	.string "Emportez vos ordures avec vous.$"

