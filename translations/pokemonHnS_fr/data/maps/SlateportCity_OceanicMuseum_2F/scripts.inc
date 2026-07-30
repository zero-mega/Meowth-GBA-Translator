.set LOCALID_CAPT_STERN, 1
.set LOCALID_ARCHIE, 2
.set LOCALID_GRUNT_1, 3
.set LOCALID_GRUNT_2, 4

SlateportCity_OceanicMuseum_2F_MapScripts::
	.byte 0

SlateportCity_OceanicMuseum_2F_EventScript_CaptStern::
	lock
	faceplayer
	msgbox SlateportCity_OceanicMuseum_2F_Text_ThankYouForTheParts, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, TRUE
	addobject LOCALID_GRUNT_1
	applymovement LOCALID_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_FirstGruntEnter
	waitmovement 0
	addobject LOCALID_GRUNT_2
	applymovement LOCALID_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_SecondGruntEnter
	waitmovement 0
	applymovement LOCALID_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_FirstGruntApproach
	applymovement LOCALID_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_SecondGruntApproach
	waitmovement 0
	call_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts
	call_if_eq VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts
	msgbox SlateportCity_OceanicMuseum_2F_Text_WellTakeThoseParts, MSGBOX_DEFAULT
	call_if_ne VAR_FACING, DIR_EAST, SlateportCity_OceanicMuseum_2F_EventScript_SternFaceGrunts
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternWhoAreYou, MSGBOX_DEFAULT
	msgbox SlateportCity_OceanicMuseum_2F_Text_WereTeamAqua, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle
	waitmovement 0
	call_if_eq VAR_FACING, DIR_SOUTH, SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntSouth
	call_if_eq VAR_FACING, DIR_WEST, SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntWest
	trainerbattle_no_intro TRAINER_TODD, SlateportCity_OceanicMuseum_2F_Text_Grunt1Defeat
	msgbox SlateportCity_OceanicMuseum_2F_Text_BossGoingToBeFurious, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated
	waitmovement 0
	applymovement LOCALID_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_LetMeTakeCareOfThis, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_TOM, SlateportCity_OceanicMuseum_2F_Text_Grunt2Defeat
	applymovement LOCALID_GRUNT_1, SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated
	waitmovement 0
	applymovement LOCALID_GRUNT_1, Common_Movement_WalkInPlaceFasterDown
	applymovement LOCALID_GRUNT_2, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_MeddlingKid, MSGBOX_DEFAULT
	closemessage
	delay 35
	addobject LOCALID_ARCHIE
	applymovement LOCALID_ARCHIE, SlateportCity_OceanicMuseum_2F_Movement_ArchieEnter
	applymovement LOCALID_GRUNT_2, SlateportCity_OceanicMuseum_2F_Movement_GruntMoveForArchie
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_CameToSeeWhatsTakingSoLong, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ARCHIE, SlateportCity_OceanicMuseum_2F_Movement_ArchieApproachPlayer
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_ArchieWarning, MSGBOX_DEFAULT
	closemessage
	savebgm MUS_DUMMY
	fadedefaultbgm
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_ARCHIE
	removeobject LOCALID_GRUNT_1
	removeobject LOCALID_GRUNT_2
	fadescreen FADE_FROM_BLACK
	delay 30
	setflag FLAG_GARBAGEFLAG
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternThankYouForSavingUs, MSGBOX_DEFAULT
	setvar VAR_0x8004, ITEM_DEVON_GOODS
	call Common_EventScript_PlayerHandedOverTheItem
	msgbox SlateportCity_OceanicMuseum_2F_Text_SternIveGotToGo, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	callnative UpdateFollowingPokemon
	removeobject LOCALID_CAPT_STERN
	setflag FLAG_GARBAGEFLAG
	call_if_eq VAR_REGISTER_BIRCH_STATE, 0, SlateportCity_OceanicMuseum_2F_EventScript_ReadyRegisterBirch
	setflag FLAG_DELIVERED_DEVON_GOODS
	clearflag FLAG_GARBAGEFLAG
	setflag FLAG_GARBAGEFLAG
	setvar VAR_SLATEPORT_OUTSIDE_MUSEUM_STATE, 1
	fadescreen FADE_FROM_BLACK
	release
	end

SlateportCity_OceanicMuseum_2F_EventScript_ReadyRegisterBirch::
	setvar VAR_REGISTER_BIRCH_STATE, 1
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerFaceGrunts::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_SternFaceGrunts::
	applymovement LOCALID_CAPT_STERN, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntSouth::
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntSouth
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_EventScript_PlayerApproachGruntWest::
	applymovement OBJ_EVENT_ID_PLAYER, SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntWest
	waitmovement 0
	return

SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntSouth:
	walk_left
	walk_down
	walk_in_place_faster_left
	step_end

SlateportCity_OceanicMuseum_2F_Movement_PlayerApproachGruntWest:
	walk_up
	walk_left
	walk_left
	walk_down
	walk_in_place_faster_left
	step_end

SlateportCity_OceanicMuseum_2F_Movement_Unused:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	delay_8
	step_end

SlateportCity_OceanicMuseum_2F_Movement_ArchieApproachPlayer:
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_ArchieEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntApproachToBattle:
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_FirstGruntEnter:
	walk_down
	walk_right
	walk_in_place_faster_down
	step_end

SlateportCity_OceanicMuseum_2F_Movement_FirstGruntApproach:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntDefeated:
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

SlateportCity_OceanicMuseum_2F_Movement_SecondGruntEnter:
	walk_down
	step_end

SlateportCity_OceanicMuseum_2F_Movement_SecondGruntApproach:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SlateportCity_OceanicMuseum_2F_Movement_GruntMoveForArchie:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_8
	walk_fast_down
	walk_in_place_faster_up
	step_end

SlateportCity_OceanicMuseum_2F_EventScript_WaterQualitySample1::
	msgbox SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample1, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_WaterQualitySample2::
	msgbox SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample2, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_PressureExperiment::
	msgbox SlateportCity_OceanicMuseum_2F_Text_PressureExperiment, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_HoennModel::
	msgbox SlateportCity_OceanicMuseum_2F_Text_HoennModel, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_DeepSeawaterDisplay::
	msgbox SlateportCity_OceanicMuseum_2F_Text_DeepSeawaterDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SurfaceSeawaterDisplay::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SurfaceSeawaterDisplay, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SSTidalReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SSTidalReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SubmarineReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SubmarineReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SubmersibleReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SumbersibleReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_SSAnneReplica::
	msgbox SlateportCity_OceanicMuseum_2F_Text_SSAnneReplica, MSGBOX_SIGN
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron1::
	msgbox SlateportCity_OceanicMuseum_2F_Text_RemindsMeOfAbandonedShip, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron2::
	msgbox SlateportCity_OceanicMuseum_2F_Text_DontRunInMuseum, MSGBOX_NPC
	end

SlateportCity_OceanicMuseum_2F_EventScript_MuseumPatron3::
	lock
	faceplayer
	msgbox SlateportCity_OceanicMuseum_2F_Text_WantToRideSubmarine, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SlateportCity_OceanicMuseum_2F_Text_ThankYouForTheParts:
	.string "Oui ? Si tu cherches SERGENT,\n"
	.string "c'est moi.\p"
	.string "Ah ! Ce doit être les pièces que j'ai commandées\n"
	.string "à M. PIERRE de DEVON.\p"
	.string "Merci ! C'est super !\n"
	.string "On peut préparer notre expédition maintenant.$"

SlateportCity_OceanicMuseum_2F_Text_WellTakeThoseParts:
	.string "Héhéhé, attends !\n"
	.string "On va prendre ces pièces !$"

SlateportCity_OceanicMuseum_2F_Text_SternWhoAreYou:
	.string "CAPT. STERN : Q-quoi ?\n"
	.string "Qui êtes-vous ?$"

SlateportCity_OceanicMuseum_2F_Text_WereTeamAqua:
	.string "Nous sommes la TEAM AQUA !\p"
	.string "Notre CHEF veut ces pièces !\n"
	.string "Ferme-la et donne-les !$"

SlateportCity_OceanicMuseum_2F_Text_Grunt1Defeat:
	.string "Awaaaah !\n"
	.string "Un gamin m'a battu !$"

SlateportCity_OceanicMuseum_2F_Text_BossGoingToBeFurious:
	.string "Oh, mince, quelle catastrophe…\n"
	.string "Le BOSS va être furieux…$"

SlateportCity_OceanicMuseum_2F_Text_LetMeTakeCareOfThis:
	.string "Humph, pleurnichard !\n"
	.string "Laisse-moi m'occuper de ça !$"

SlateportCity_OceanicMuseum_2F_Text_Grunt2Defeat:
	.string "Quoi ?!\n"
	.string "J'ai perdu, moi aussi !$"

SlateportCity_OceanicMuseum_2F_Text_MeddlingKid:
	.string "Et maintenant ? Si on n'a\n"
	.string "pas les pièces, on est fichus\p"
	.string "! Arrgh, je n'avais pas prévu\n"
	.string "qu'un gamin s'en mêle !$"

SlateportCity_OceanicMuseum_2F_Text_CameToSeeWhatsTakingSoLong:
	.string "Je suis venu voir ce qui prenait si longtemps\n"
	.string "pour récupérer des pièces, et vous autres\l"
	.string "nuls êtes bloqués par un simple gamin ?$"

SlateportCity_OceanicMuseum_2F_Text_ArchieWarning:
	.string "Nous sommes la TEAM AQUA,\n"
	.string "et nous aimons la mer !\p"
	.string "Et je suis le leader de la TEAM AQUA,\n"
	.string "ARCHIE !\p"
	.string "Pourquoi t'immisces-tu dans nos affaires ?\p"
	.string "…Non ! Impossible !\n"
	.string "Tu n'es pas de la TEAM MAGMA ?\p"
	.string "Attends, ça ne peut pas être vrai.\n"
	.string "Tu n'es pas habillé pour ça.\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "POKéMON, humains… Toute vie dépend\n"
	.string "de la mer.\p"
	.string "Alors, la TEAM AQUA se consacre\n"
	.string "à l'expansion de la mer.\p"
	.string "Tu n'es pas d'accord ? Ce que nous faisons\n"
	.string "est une entreprise magnifique.\p"
	.string "Ah, bon…\n"
	.string "Tu es encore trop jeune pour comprendre\l"
	.string "notre noble objectif.\p"
	.string "Mais, je t'avertis, ne pense même pas\n"
	.string "à interférer à nouveau avec nos plans.\p"
	.string "Les conséquences te coûteront\n"
	.string "cher !\p"
	.string "Et n'oublie pas ça !$"

SlateportCity_OceanicMuseum_2F_Text_SternThankYouForSavingUs:
	.string "CAPITAINE LISETTE : Tu es… Ah,\n"
	.string "d'accord, tu es {PLAYER}{KUN}… Bref, c'était\p"
	.string "une situation tendue ! Merci de\n"
	.string "nous avoir sauvés ! Oh, oui,\p"
	.string "j'oubliais presque que tu as même\n"
	.string "apporté les pièces de DEVON !$"

SlateportCity_OceanicMuseum_2F_Text_SternIveGotToGo:
	.string "CAPT. KUSTO : Oups ! Il\n"
	.string "n'y a pas de temps à\p"
	.string "perdre ! On doit partir pour\n"
	.string "notre expédition sur le fond\p"
	.string "marin très bientôt. Merci encore,\n"
	.string "mais je dois y aller\p"
	.string "! N'hésite pas à te\n"
	.string "promener et visiter nos installations.$"

SlateportCity_OceanicMuseum_2F_Text_RemindsMeOfAbandonedShip:
	.string "J'ai vu une maquette de navire ici.\p"
	.string "Ça m'a rappelé le CARGO CÉLESTE\n"
	.string "près de LOUVIÈRE…$"

SlateportCity_OceanicMuseum_2F_Text_DontRunInMuseum:
	.string "Ne cours pas dans le\n"
	.string "MUSÉE !$"

SlateportCity_OceanicMuseum_2F_Text_WantToRideSubmarine:
	.string "Waouh, le sous-marin est génial !\n"
	.string "Je veux faire un tour !$"

SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample1:
	.string "“ÉCHANTILLON QUALITÉ EAU 1\n"
	.string "”, dit l'étiquette. La mer\p"
	.string "est toute connectée, mais l'eau\n"
	.string "semble différer selon les régions.$"

SlateportCity_OceanicMuseum_2F_Text_WaterQualitySample2:
	.string "“ÉCHANTILLON QUALITÉ EAU 2”,\n"
	.string "dit l'étiquette.\p"
	.string "La salinité de l'eau de mer diffère-t-elle\n"
	.string "selon les régions, aussi ?$"

SlateportCity_OceanicMuseum_2F_Text_PressureExperiment:
	.string "Une balle en caoutchouc\n"
	.string "se dilate et\p"
	.string "se contracte.\n"
	.string "“Dans la mer, le\p"
	.string "poids de l'eau lui-même\n"
	.string "exerce une\p"
	.string "pression énorme.”\n"
	.string "La science est\l"
	.string "fascinante !$"

SlateportCity_OceanicMuseum_2F_Text_HoennModel:
	.string "“MAQUETTE DE LA RÉGION HOENN”\p"
	.string "C'est une maquette miniature de la\n"
	.string "région HOENN.\p"
	.string "Où se trouve BOURG-EN-VOL sur celle-ci ?$"

SlateportCity_OceanicMuseum_2F_Text_DeepSeawaterDisplay:
	.string "C'est une exposition sur le flux de l'eau de mer.\p"
	.string "“Près du fond de la mer, l'eau\n"
	.string "circule en raison de différences de facteurs\l"
	.string "comme la température et la salinité.”$"

SlateportCity_OceanicMuseum_2F_Text_SurfaceSeawaterDisplay:
	.string "C'est une exposition sur le flux de l'eau de\p"
	.string "mer. “Vers la surface, l'eau de mer\n"
	.string "circule en courants poussés par le vent.”$"

SlateportCity_OceanicMuseum_2F_Text_SSTidalReplica:
	.string "“LE FERRY S.S. MARÉE\p"
	.string "“Une réplique à l'échelle du navire en\n"
	.string "construction au CHANTIER NAVAL DE POIVRE.”$"

SlateportCity_OceanicMuseum_2F_Text_SubmarineReplica:
	.string "“EXPLORATEUR SOUS-MARIN 1\p"
	.string "“Une réplique du sous-marin d'exploration\n"
	.string "des fonds marins haute performance.”$"

SlateportCity_OceanicMuseum_2F_Text_SumbersibleReplica:
	.string "“NACELLE SOUS-MARINE\p"
	.string "“Réplique d'une nacelle compacte\n"
	.string "sans pilote pour l'exploration des fonds marins.”$"

SlateportCity_OceanicMuseum_2F_Text_SSAnneReplica:
	.string "“S.S. ANNE\p"
	.string "“Réplique du paquebot de luxe qui\n"
	.string "fait le tour du globe.”$"

