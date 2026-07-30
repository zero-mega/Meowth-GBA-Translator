.set LOCALID_GRUNT_1, 1
.set LOCALID_GRUNT_2, 2
.set LOCALID_SHELLY, 3
.set LOCALID_SCIENTIST, 5
.set LOCALID_GRUNT_3, 7
.set LOCALID_GRUNT_4, 8

Route119_WeatherInstitute_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route119_WeatherInstitute_2F_OnTransition
	.byte 0

Route119_WeatherInstitute_2F_OnTransition:
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 0, Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaHere
	call_if_eq VAR_WEATHER_INSTITUTE_STATE, 1, Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaGone
	call_if_set FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_2F_EventScript_SetScientistPosGameClear
	end

Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaHere::
	setobjectxyperm LOCALID_SCIENTIST, 1, 6
	setobjectmovementtype LOCALID_SCIENTIST, MOVEMENT_TYPE_FACE_RIGHT
	return

Route119_WeatherInstitute_2F_EventScript_SetScientistPosAquaGone::
	setobjectxyperm LOCALID_SCIENTIST, 4, 6
	setobjectmovementtype LOCALID_SCIENTIST, MOVEMENT_TYPE_FACE_RIGHT
	return

Route119_WeatherInstitute_2F_EventScript_SetScientistPosGameClear::
	setobjectxyperm LOCALID_SCIENTIST, 2, 2
	setobjectmovementtype LOCALID_SCIENTIST, MOVEMENT_TYPE_FACE_UP
	return

Route119_WeatherInstitute_2F_EventScript_Grunt5::
	trainerbattle_single TRAINER_BUGSY_1, Route119_WeatherInstitute_2F_Text_Grunt5Intro, Route119_WeatherInstitute_2F_Text_Grunt5Defeat
	msgbox Route119_WeatherInstitute_2F_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_Grunt2::
	trainerbattle_single TRAINER_ZUKI, Route119_WeatherInstitute_2F_Text_Grunt2Intro, Route119_WeatherInstitute_2F_Text_Grunt2Defeat
	msgbox Route119_WeatherInstitute_2F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_Grunt3::
	trainerbattle_single TRAINER_FALKNER_1, Route119_WeatherInstitute_2F_Text_Grunt3Intro, Route119_WeatherInstitute_2F_Text_Grunt3Defeat
	msgbox Route119_WeatherInstitute_2F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_Shelly::
	trainerbattle_single TRAINER_DEVIN, Route119_WeatherInstitute_2F_Text_ShellyIntro, Route119_WeatherInstitute_2F_Text_ShellyDefeat, Route119_WeatherInstitute_2F_EventScript_ShellyDefeated
	msgbox Route119_WeatherInstitute_2F_Text_ShellyPostBattle, MSGBOX_AUTOCLOSE
	end

Route119_WeatherInstitute_2F_EventScript_ShellyDefeated::
	msgbox Route119_WeatherInstitute_2F_Text_ShellyPostBattle, MSGBOX_DEFAULT
	closemessage
	addobject LOCALID_GRUNT_3
	applymovement LOCALID_GRUNT_3, Route119_WeatherInstitute_2F_Movement_GruntApproachShelly
	applymovement OBJ_EVENT_ID_PLAYER, Route119_WeatherInstitute_2F_Movement_ShovePlayerOutOfWay
	waitmovement 0
	msgbox Route119_WeatherInstitute_2F_Text_TeamMagmaJustPassedBy, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_SHELLY, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_SHELLY, Common_Movement_Delay48
	waitmovement 0
	msgbox Route119_WeatherInstitute_2F_Text_WeHaveToHurryToMtPyre, MSGBOX_DEFAULT
	closemessage
	setvar VAR_WEATHER_INSTITUTE_STATE, 1
	clearflag FLAG_GARBAGEFLAG
	fadedefaultbgm
	fadescreen FADE_TO_BLACK
	setflag FLAG_GARBAGEFLAG
	setflag FLAG_GARBAGEFLAG
	removeobject LOCALID_GRUNT_1
	removeobject LOCALID_GRUNT_2
	removeobject LOCALID_SHELLY
	removeobject LOCALID_GRUNT_4
	removeobject LOCALID_GRUNT_3
	applymovement OBJ_EVENT_ID_PLAYER, Route119_WeatherInstitute_2F_Movement_PlayerReturnToPosition
	waitmovement 0
	fadescreen FADE_FROM_BLACK
	applymovement LOCALID_SCIENTIST, Route119_WeatherInstitute_2F_Movement_ScientistApproachPlayer
	waitmovement 0
	copyobjectxytoperm LOCALID_SCIENTIST
	goto Route119_WeatherInstitute_2F_EventScript_ReceiveCastform
	end

Route119_WeatherInstitute_2F_EventScript_ReceiveCastform::
	msgbox Route119_WeatherInstitute_2F_Text_ThanksPleaseTakePokemon, MSGBOX_DEFAULT
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_CASTFORM
	givemon SPECIES_CASTFORM, 25, ITEM_MYSTIC_WATER
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, Route119_WeatherInstitute_2F_EventScript_ReceiveCastformParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, Route119_WeatherInstitute_2F_EventScript_ReceiveCastformPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end

Route119_WeatherInstitute_2F_EventScript_ReceiveCastformParty::
	call Route119_WeatherInstitute_2F_EventScript_ReceivedCastformFanfare
	specialvar VAR_RESULT, IsNuzlockeNicknamingActive
	goto_if_eq VAR_RESULT, TRUE, Route119_WeatherInstitute_2F_EventScript_ReceiveCastformParty_Nuzlocke
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route119_WeatherInstitute_2F_EventScript_ExplainCastform
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto Route119_WeatherInstitute_2F_EventScript_ExplainCastform
	end

Route119_WeatherInstitute_2F_EventScript_ReceiveCastformParty_Nuzlocke::
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto Route119_WeatherInstitute_2F_EventScript_ExplainCastform
	end

Route119_WeatherInstitute_2F_EventScript_ReceiveCastformPC::
	call Route119_WeatherInstitute_2F_EventScript_ReceivedCastformFanfare
	specialvar VAR_RESULT, IsNuzlockeNicknamingActive
	goto_if_eq VAR_RESULT, TRUE, Route119_WeatherInstitute_2F_EventScript_ReceiveCastformPC_Nuzlocke
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route119_WeatherInstitute_2F_EventScript_SendCastformToPC
	call Common_EventScript_NameReceivedBoxMon
	goto Route119_WeatherInstitute_2F_EventScript_SendCastformToPC
	end

Route119_WeatherInstitute_2F_EventScript_ReceiveCastformPC_Nuzlocke::
	call Common_EventScript_NameReceivedBoxMon
	goto Route119_WeatherInstitute_2F_EventScript_SendCastformToPC
	end
	
Route119_WeatherInstitute_2F_EventScript_SendCastformToPC::
	call Common_EventScript_TransferredToPC
	goto Route119_WeatherInstitute_2F_EventScript_ExplainCastform
	end

Route119_WeatherInstitute_2F_EventScript_ReceivedCastformFanfare::
	playfanfare MUS_OBTAIN_ITEM
	message Route119_WeatherInstitute_2F_Text_PlayerReceivedCastform
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_CASTFORM
	return

Route119_WeatherInstitute_2F_EventScript_ExplainCastform::
	msgbox Route119_WeatherInstitute_2F_Text_PokemonChangesWithWeather, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_CASTFORM
	release
	end

Route119_WeatherInstitute_2F_EventScript_ScientistMentionWeather::
	goto_if_set FLAG_SYS_GAME_CLEAR, Route119_WeatherInstitute_2F_EventScript_TryStartAbnormalWeather
	msgbox Route119_WeatherInstitute_2F_Text_ChangingWeatherRidiculous, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_EventScript_TryStartAbnormalWeather::
	setvar VAR_0x8004, 0
	call_if_set FLAG_DEFEATED_KYOGRE, Route119_WeatherInstitute_2F_EventScript_LegendaryDefeated
	call_if_set FLAG_DEFEATED_GROUDON, Route119_WeatherInstitute_2F_EventScript_LegendaryDefeated
	goto_if_eq VAR_0x8004, 2, Route119_WeatherInstitute_2F_EventScript_NoAbnormalWeather  @ Both defeated
	call_if_unset FLAG_TEMP_2, Route119_WeatherInstitute_2F_EventScript_CreateAbnormalWeather
	specialvar VAR_RESULT, GetAbnormalWeatherMapNameAndType
	goto_if_eq VAR_RESULT, 1, Route119_WeatherInstitute_2F_EventScript_KyogreWeather
	msgbox Route119_WeatherInstitute_2F_Text_GroudonWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_EventScript_KyogreWeather::
	msgbox Route119_WeatherInstitute_2F_Text_KyogreWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_EventScript_CreateAbnormalWeather::
	special CreateAbnormalWeatherEvent
	setflag FLAG_TEMP_2
	return

Route119_WeatherInstitute_2F_EventScript_LegendaryDefeated::
	addvar VAR_0x8004, 1
	return

Route119_WeatherInstitute_2F_EventScript_NoAbnormalWeather::
	msgbox Route119_WeatherInstitute_2F_Text_NoAbnormalWeather, MSGBOX_DEFAULT
	release
	end

Route119_WeatherInstitute_2F_Movement_GruntApproachShelly:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Route119_WeatherInstitute_2F_Movement_ShovePlayerOutOfWay:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	ride_water_current_up
	walk_in_place_faster_down
	step_end

Route119_WeatherInstitute_2F_Movement_PlayerReturnToPosition:
	slide_down
	walk_in_place_faster_left
	step_end

Route119_WeatherInstitute_2F_Movement_ScientistApproachPlayer:
	walk_right
	walk_right
	walk_right
	step_end

Route119_WeatherInstitute_2F_EventScript_WeatherScientist::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_CASTFORM, Route119_WeatherInstitute_2F_EventScript_ScientistMentionWeather
	goto Route119_WeatherInstitute_2F_EventScript_ReceiveCastform
	end

Route119_WeatherInstitute_2F_Text_Grunt2Intro:
	.string "L'INSTITUT a créé un type de\n"
	.string "POKéMON lié à la météo.\l"
	.string "On est là pour les récupérer !$"

Route119_WeatherInstitute_2F_Text_Grunt2Defeat:
	.string "Notre plan est gâché par un gamin ?$"

Route119_WeatherInstitute_2F_Text_Grunt2PostBattle:
	.string "Si les POKéMON qu'ils ont créés ici peuvent\n"
	.string "contrôler la météo librement, alors nous de\l"
	.string "la TEAM AQUA en avons absolument besoin !$"

Route119_WeatherInstitute_2F_Text_Grunt3Intro:
	.string "Nous sommes la TEAM AQUA !\n"
	.string "Nous apparaissons partout où il y a\l"
	.string "quelque chose de rare !$"

Route119_WeatherInstitute_2F_Text_Grunt3Defeat:
	.string "Tu m'as eu !$"

Route119_WeatherInstitute_2F_Text_Grunt3PostBattle:
	.string "Tu n'as aucune idée de ce que la TEAM AQUA\n"
	.string "essaie d'accomplir !\l"
	.string "Reste hors de notre chemin !$"

Route119_WeatherInstitute_2F_Text_Grunt5Intro:
	.string "Ne me dis pas que tu cherches\n"
	.string "ce POKéMON météo, toi aussi ?\p"
	.string "C'est interdit !\n"
	.string "On était là pour le récupérer en premier !$"

Route119_WeatherInstitute_2F_Text_Grunt5Defeat:
	.string "Oh, tu veux bien regarder mes POKéMON ?$"

Route119_WeatherInstitute_2F_Text_Grunt5PostBattle:
	.string "Humph, et alors ?\n"
	.string "Ce qu'on veut…\p"
	.string "Ce qu'on veut vraiment n'est pas ici…\n"
	.string "Ihihihihi…$"

Route119_WeatherInstitute_2F_Text_ShellyIntro:
	.string "Ahahahaha !\p"
	.string "Tu vas t'immiscer dans les affaires\n"
	.string "de la TEAM AQUA ?\p"
	.string "Tu es soit absolument intrépide,\n"
	.string "soit complètement ignorant, soit les deux !\p"
	.string "Tu es si mignon que c'en est dégoûtant !\n"
	.string "Je vais t'écraser, gamin !$"

Route119_WeatherInstitute_2F_Text_ShellyDefeat:
	.string "Ahahahaha !\n"
	.string "Tu es d'une force dégoûtante !$"

Route119_WeatherInstitute_2F_Text_ShellyPostBattle:
	.string "C'est déjà assez d'avoir la TEAM MAGMA\n"
	.string "qui sème la pagaille, et maintenant toi !\p"
	.string "Qu'est-ce qui te pousse à fouiner\n"
	.string "dans nos affaires, au juste ?$"

Route119_WeatherInstitute_2F_Text_TeamMagmaJustPassedBy:
	.string "Situation d'urgence ! Une bande\p"
	.string "de la TEAM MAGMA vient\n"
	.string "de passer l'INSTITUT MÉTÉO. Ils\p"
	.string "semblent se diriger vers\n"
	.string "le MONT SÉPIA !$"

Route119_WeatherInstitute_2F_Text_WeHaveToHurryToMtPyre:
	.string "Quoi ?! On ne peut pas\p"
	.string "perdre plus de temps ici !\n"
	.string "Il faut se dépêcher d'aller au\p"
	.string "MONT SÉPIA aussi ! Ahahahaha\n"
	.string "! TEAM MAGMA, attendez-nous !$"

Route119_WeatherInstitute_2F_Text_ThanksPleaseTakePokemon:
	.string "Merci !\n"
	.string "Grâce à toi, nous sommes en sécurité !\p"
	.string "C'est peut-être une drôle de façon de te remercier,\n"
	.string "mais prends ce POKéMON.$"

@ Unused
Route119_WeatherInstitute_2F_Text_NoRoomForPokemon:
	.string "Hm ? Tu ne sembles pas avoir de place\n"
	.string "pour ce POKéMON.$"

Route119_WeatherInstitute_2F_Text_PlayerReceivedCastform:
	.string "{PLAYER} a reçu MORPHÉO !$"

Route119_WeatherInstitute_2F_Text_PokemonChangesWithWeather:
	.string "Ce POKéMON change de forme selon\n"
	.string "les conditions météo.\p"
	.string "Il y en a plein à l'\n"
	.string "INSTITUT — prends-en un.$"

Route119_WeatherInstitute_2F_Text_ChangingWeatherRidiculous:
	.string "Ça fait des années que je fais des recherches\n"
	.string "sur la pluie, mais c'est ridicule de penser\l"
	.string "que les humains peuvent changer le temps librement.$"

Route119_WeatherInstitute_2F_Text_GroudonWeather:
	.string "Je surveille les conditions météo\n"
	.string "de la région de HOENN.\p"
	.string "Actuellement, une sécheresse a été\n"
	.string "enregistrée à {STR_VAR_1}.\p"
	.string "Est-ce que ça voudrait dire que, quelque part\n"
	.string "près de {STR_VAR_1}…$"

Route119_WeatherInstitute_2F_Text_KyogreWeather:
	.string "Je surveille les conditions météo\n"
	.string "de la région de HOENN.\p"
	.string "Actuellement, de fortes pluies ont été\n"
	.string "enregistrées au-dessus de {STR_VAR_1}.\p"
	.string "Est-ce que ça voudrait dire que, quelque part\n"
	.string "près de {STR_VAR_1}…$"

Route119_WeatherInstitute_2F_Text_NoAbnormalWeather:
	.string "Les conditions météo anormales ne\n"
	.string "sont plus signalées.\p"
	.string "Une pluie occasionnelle est une\n"
	.string "bénédiction, vraiment.$"

