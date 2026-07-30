.set LOCALID_ROCKETHIDEOUT3_LANCE, 3
.set LOCALID_ROCKETHIDEOUT3_DRAGONITE, 2
.set LOCALID_ROCKETHIDEOUT3_SILVER, 5
.set LOCALID_ROCKETHIDEOUT3_GIOVANNI, 16
.set LOCALID_ROCKETHIDEOUT3_PETREL, 15
.set LOCALID_ROCKETHIDEOUT3_MURKROW, 14
.set LOCALID_ROCKETHIDEOUT3_MURKROWSTAIRS, 17

RocketHideout_B3F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, RocketHideout_B3F_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, RocketHideout_B3F_OnLoad
	.byte 0

RocketHideout_B3F_OnLoad::
	call_if_set FLAG_HIDE_ROCKETHIDEOUT3_GATE, RocketHideout_B3F_HideGate
	call_if_eq VAR_ROCKET_PASSWORD, 2, RocketHideout_B3F_HidePetrel
	end
	
RocketHideout_B3F_HideGate::
	setmetatile 11, 11, 0x378, FALSE
	setmetatile 11, 12, 0x380, FALSE
	setmetatile 12, 11, 0x379, FALSE
	setmetatile 12, 12, 0x379, FALSE
	setmetatile 13, 11, 0x379, FALSE
	setmetatile 13, 12, 0x379, FALSE
	return
RocketHideout_B3F_HidePetrel::
	setflag FLAG_HIDE_ROCKETHIDEOUT3_PETREL
	clearflag FLAG_HIDE_ROCKETHIDEOUT3_GIOVANNI
	return

RocketHideout_B3F_OnFrame::
	map_script_2 VAR_MAHOGANY_TOWN_STATE, 6, RocketHideout_B3F_EventScript_LancePassword
	.2byte 0

RocketHideout_B3F_EventScript_LancePassword::
	lock
	delay 55
	playse SE_PIN
	applymovement LOCALID_ROCKETHIDEOUT3_LANCE, Common_Movement_ExclamationMark
	delay 20
	applymovement LOCALID_ROCKETHIDEOUT3_LANCE, Common_Movement_WalkRight1
	msgbox RocketHideout_B3F_Text_LanceGetPassword, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROCKETHIDEOUT3_LANCE, RocketHideout_B3F_Movement_LanceLeave
	applymovement LOCALID_ROCKETHIDEOUT3_DRAGONITE, RocketHideout_B3F_Movement_DragoniteLeave
	waitmovement LOCALID_ROCKETHIDEOUT3_LANCE
	waitmovement LOCALID_ROCKETHIDEOUT3_DRAGONITE
	setflag FLAG_HIDE_ROCKETHIDEOUT3_LANCE_DRAGONITE
	removeobject LOCALID_ROCKETHIDEOUT3_DRAGONITE
	removeobject LOCALID_ROCKETHIDEOUT3_LANCE
	setvar VAR_MAHOGANY_TOWN_STATE, 7
	release
	end

RocketHideout_B3F_Movement_LanceLeave:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	delay_2
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

RocketHideout_B3F_Movement_DragoniteLeave:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_8
	delay_8
	delay_8
	walk_down
	walk_left
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

RocketHideout_B3F_Text_LanceGetPassword:
    .string "LANCE : Il faut deux\n"
    .string "mots de passe pour\p"
    .string "entrer dans le quartier\n"
    .string "du boss. Ces mots\p"
    .string "de passe ne sont\n"
    .string "connus que de nous,\p"
    .string "la TEAM ROCKET. Tu\n"
    .string "n'y entreras jamais !$"

RocketHideout_B3F_EventScript_RocketKO::
	lock
	faceplayer
	msgbox RocketHideout_B3F_Text_B3FRocket, MSGBOX_DEFAULT
	release
	end

RocketHideout_B3F_Text_B3FRocket:
    .string "Urrggh… Le type en cape est\n"
    .string "incroyablement costaud…$"


RocketHideout_B3F_Trigger_MurkrowStairs::
	lock
	applymovement LOCALID_ROCKETHIDEOUT3_MURKROWSTAIRS, RocketHideout_B3F_Movement_MurkrowStairs1
	waitmovement 0
	playmoncry SPECIES_MURKROW, CRY_MODE_NORMAL
	msgbox RocketHideout_B3F_Text_MurkrowSpeak1, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROCKETHIDEOUT3_MURKROWSTAIRS, RocketHideout_B3F_Movement_MurkrowStairs2
	waitmovement 0
	setflag FLAG_HIDE_ROCKETHIDEOUT3_MURKROWSTAIRS
	removeobject LOCALID_ROCKETHIDEOUT3_MURKROWSTAIRS
	clearflag FLAG_HIDE_ROCKETHIDEOUT2_MURKROWGATE
	setvar VAR_MAHOGANY_TOWN_STATE, 11
	release
	end

RocketHideout_B3F_Movement_MurkrowStairs1:
	jump_in_place_right
	jump_in_place_right
	step_end

RocketHideout_B3F_Movement_MurkrowStairs2:
	jump_in_place_right
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

RocketHideout_B3F_Trigger_Silver::
	lock
	clearflag FLAG_HIDE_ROCKETHIDEOUT3_SILVER
	addobject LOCALID_ROCKETHIDEOUT3_SILVER
	playbgm MUS_HG_ENCOUNTER_RIVAL, TRUE
	applymovement LOCALID_ROCKETHIDEOUT3_SILVER, RocketHideout_B3F_Movement_SilverEnter
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox RocketHideout_B3F_Text_Rival, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROCKETHIDEOUT3_SILVER, RocketHideout_B3F_Movement_SilverLeave
	waitmovement 0
	setflag FLAG_HIDE_ROCKETHIDEOUT3_SILVER
	removeobject LOCALID_ROCKETHIDEOUT3_SILVER
	setvar VAR_MAHOGANY_TOWN_STATE, 8
	fadedefaultbgm
	release
	end

RocketHideout_B3F_Movement_SilverEnter:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

RocketHideout_B3F_Movement_SilverLeave:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

RocketHideout_B3F_EventScript_Door::
	lock
	goto_if_set FLAG_HIDE_ROCKETHIDEOUT3_GATE, RocketHideout_B3F_EventScript_DoorIsOpen
	goto_if_eq VAR_ROCKET_PASSWORD, 2, RocketHideout_B3F_EventScript_OpenDoor
	msgbox RocketHideout_B3F_Text_B3FLockedDoorNeedsPassword, MSGBOX_DEFAULT
	closemessage
	release
	end

RocketHideout_B3F_EventScript_OpenDoor::
	msgbox RocketHideout_B3F_Text_B3FLockedDoorOpenSesame, MSGBOX_DEFAULT
	closemessage
	playse SE_CLICK
	setmetatile 11, 11, 0x378, FALSE
	setmetatile 11, 12, 0x380, FALSE
	setmetatile 12, 11, 0x379, FALSE
	setmetatile 12, 12, 0x379, FALSE
	setmetatile 13, 11, 0x379, FALSE
	setmetatile 13, 12, 0x379, FALSE
	special DrawWholeMapView
	setflag FLAG_HIDE_ROCKETHIDEOUT3_GATE
	release
	end

RocketHideout_B3F_EventScript_DoorIsOpen::
	end

RocketHideout_B3F_EventScript_GruntF5::
	trainerbattle_single TRAINER_GRUNT_29 RocketHideout_B3F_Text_GruntF5Seen, RocketHideout_B3F_Text_GruntF5Beaten
	msgbox RocketHideout_B3F_Text_GruntF5After, MSGBOX_NPC
	goto_if_unset FLAG_GOT_PASSWORD_FROM_GRUNTF, RocketHideout_B3F_EventScript_IncrementPasswordGruntF
	end

RocketHideout_B3F_EventScript_IncrementPasswordGruntF::
	addvar VAR_ROCKET_PASSWORD, 1
	setflag FLAG_GOT_PASSWORD_FROM_GRUNTF
	end

RocketHideout_B3F_EventScript_Eto::
	trainerbattle_single TRAINER_ETO_2 RocketHideout_B3F_Text_GruntM28Seen, RocketHideout_B3F_Text_GruntM28Beaten
	msgbox RocketHideout_B3F_Text_GruntM28After, MSGBOX_NPC
	goto_if_unset FLAG_GOT_PASSWORD_FROM_ETO, RocketHideout_B3F_EventScript_IncrementPasswordEto
	end

RocketHideout_B3F_EventScript_IncrementPasswordEto::
	addvar VAR_ROCKET_PASSWORD, 1
	setflag FLAG_GOT_PASSWORD_FROM_ETO
	end

RocketHideout_B3F_EventScript_Ross::
	trainerbattle_single TRAINER_ROSS RocketHideout_B3F_Text_ScientistRossSeen, RocketHideout_B3F_Text_ScientistRossBeaten
	msgbox RocketHideout_B3F_Text_ScientistRossAfter, MSGBOX_AUTOCLOSE
	end

RocketHideout_B3F_EventScript_Mitch::
	trainerbattle_single TRAINER_MITCH RocketHideout_B3F_Text_ScientistMitchSeen, RocketHideout_B3F_Text_ScientistMitchBeaten
	msgbox RocketHideout_B3F_Text_ScientistMitchAfter, MSGBOX_AUTOCLOSE
	end

RocketHideout_B3F_EventScript_Item_IceHeal::
	finditem ITEM_ICE_HEAL
	end

RocketHideout_B3F_EventScript_Item_Protein::
	finditem ITEM_PROTEIN
	end

RocketHideout_B3F_EventScript_Item_FullHeal::
	finditem ITEM_FULL_HEAL
	end

RocketHideout_B3F_EventScript_Item_GuardSpec::
	finditem ITEM_GUARD_SPEC
	end

RocketHideout_B3F_EventScript_Item_HyperPotion::
	finditem ITEM_HYPER_POTION
	end

RocketHideout_B3F_Text_B3FLockedDoorNeedsPassword:
    .string "La porte est fermée…\p"
    .string "Il faut deux mots de passe pour l'ouvrir.$"

RocketHideout_B3F_Text_B3FLockedDoorOpenSesame:
    .string "La porte est fermée…\p"
    .string "{PLAYER} a entré les deux mots de passe.\p"
    .string "La porte s'est ouverte !$"

RocketHideout_B3F_Text_Rival:
    .string "…\p"
    .string "Je ne t'avais pas dit que j'allais\n"
    .string "détruire la TEAM ROCKET ?\p"
    .string "…Dis-moi, qui était le type en cape\n"
    .string "qui utilisait des POKéMON dragon ?\p"
    .string "Mes POKéMON n'ont pas\p"
    .string "du tout tenu le coup.\n"
    .string "C'est ce qu'il a dit qui me dérange…\p"
    .string "Il m'a dit que je n'aime pas et ne fais pas\n"
    .string "assez confiance à mes POKéMON.\p"
    .string "Ce n'est pas ma faute si mon équipe est\n"
    .string "si inutile.\p"
    .string "Je suis furieux d'avoir perdu contre\n"
    .string "un sentimental comme lui.\p"
    .string "Mais ça me fait me questionner.\p"
    .string "Est-ce que je fais quelque chose\n"
    .string "de mal ?\p"
    .string "Est-ce que l'amour a rendu son\n"
    .string "équipe si puissante ?$"

@=======[PETREL]==============================================================================================================================

RocketHideout_B3F_EventScript_Giovanni::
	lock
	faceplayer
	msgbox RocketHideout_B3F_Text_PetrelIntro, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement LOCALID_ROCKETHIDEOUT3_GIOVANNI, Common_Movement_QuestionMark
	delay 60
	msgbox RocketHideout_B3F_Text_PetrelDisbelief MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROCKETHIDEOUT3_GIOVANNI, RocketHideout_B3F_Movement_Spin
	waitmovement 0
	setflag FLAG_HIDE_ROCKETHIDEOUT3_GIOVANNI
	removeobject LOCALID_ROCKETHIDEOUT3_GIOVANNI
	clearflag FLAG_HIDE_ROCKETHIDEOUT3_PETREL
	addobject LOCALID_ROCKETHIDEOUT3_PETREL
	applymovement LOCALID_ROCKETHIDEOUT3_PETREL, RocketHideout_B3F_Movement_Spin2
	waitmovement 0
	call_if_eq VAR_FACING, DIR_EAST, RocketHideout_B3F_EventScript_FacingEast
	call_if_eq VAR_FACING, DIR_WEST, RocketHideout_B3F_EventScript_FacingWest
	msgbox RocketHideout_B3F_Text_PetrelReveal, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_PETREL_1, RocketHideout_B3F_Text_PetrelBeaten
	msgbox RocketHideout_B3F_Text_PetrelAfterBattle, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_EAST, RocketHideout_B3F_EventScript_LeaveEast
	call_if_eq VAR_FACING, DIR_WEST, RocketHideout_B3F_EventScript_LeaveWest
	call_if_eq VAR_FACING, DIR_NORTH, RocketHideout_B3F_EventScript_LeaveEast
	setflag FLAG_HIDE_ROCKETHIDEOUT3_PETREL
	playse SE_EXIT
	removeobject LOCALID_ROCKETHIDEOUT3_PETREL
	
	applymovement LOCALID_ROCKETHIDEOUT3_MURKROW, RocketHideout_B3F_Movement_Murkrow1

	delay 120

	call_if_eq VAR_FACING, DIR_EAST, RocketHideout_B3F_EventScript_FacingEastMurkrow
	call_if_eq VAR_FACING, DIR_WEST, RocketHideout_B3F_EventScript_FacingWestMurkrow

	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	waitmovement LOCALID_ROCKETHIDEOUT3_MURKROW
	playmoncry SPECIES_MURKROW, CRY_MODE_NORMAL
	msgbox RocketHideout_B3F_Text_MurkrowSpeak1, MSGBOX_DEFAULT
	msgbox RocketHideout_B3F_Text_MurkrowMimic, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROCKETHIDEOUT3_MURKROW, RocketHideout_B3F_Movement_Murkrow2
	waitmovement LOCALID_ROCKETHIDEOUT3_MURKROW

	setflag FLAG_HIDE_ROCKETHIDEOUT3_MURKROW
	playse SE_EXIT
	removeobject LOCALID_ROCKETHIDEOUT3_MURKROW
	clearflag FLAG_HIDE_ROCKETHIDEOUT2_MURKROWSTAIRS
	setflag FLAG_HIDE_ROCKETHIDEOUT2_MURKROWGATE
	setflag FLAG_HIDE_ROCKETHIDEOUT3_MURKROWSTAIRS
	setflag FLAG_HIDE_ROCKETHIDEOUT2_ARIANA_AND_GRUNT
	setvar VAR_ROCKET_PASSWORD, 3
	setvar VAR_MAHOGANY_TOWN_STATE, 9
	release
	end

RocketHideout_B3F_EventScript_FacingEastMurkrow::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement OBJ_EVENT_ID_PLAYER
	return

RocketHideout_B3F_EventScript_FacingWestMurkrow::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement OBJ_EVENT_ID_PLAYER
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement OBJ_EVENT_ID_PLAYER
	return

RocketHideout_B3F_EventScript_FacingEast::
	turnobject LOCALID_ROCKETHIDEOUT3_PETREL, DIR_WEST
	return

RocketHideout_B3F_EventScript_FacingWest::
	turnobject LOCALID_ROCKETHIDEOUT3_PETREL, DIR_EAST
	return

RocketHideout_B3F_EventScript_FacingNorth::
	turnobject LOCALID_ROCKETHIDEOUT3_PETREL, DIR_SOUTH
	return

RocketHideout_B3F_EventScript_LeaveEast::
	applymovement LOCALID_ROCKETHIDEOUT3_PETREL, RocketHideout_B3F_Movement_LeaveEast
	waitmovement 0
	return

RocketHideout_B3F_EventScript_LeaveWest::
	applymovement LOCALID_ROCKETHIDEOUT3_PETREL, RocketHideout_B3F_Movement_LeaveWest
	waitmovement 0
	return

RocketHideout_B3F_Movement_Murkrow1:
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	jump_in_place_right
	jump_in_place_left
	jump_in_place_down
	jump_in_place_up
	jump_in_place_up
	jump_in_place_up
	jump_in_place_up
	step_end

RocketHideout_B3F_Movement_Murkrow2:
	jump_in_place_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_right
	walk_faster_right
	step_end

RocketHideout_B3F_Movement_LeaveEast:
	lock_facing_direction
	walk_slow_right
	unlock_facing_direction
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_fast_right
	walk_fast_right
	step_end
RocketHideout_B3F_Movement_LeaveWest:
	lock_facing_direction
	walk_slow_left
	walk_slow_left
	unlock_facing_direction
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_right
	walk_faster_right
	walk_faster_right
	walk_faster_down
	walk_faster_down
	walk_faster_down
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_fast_right
	walk_fast_right
	step_end

RocketHideout_B3F_Movement_Spin:
	face_right
	delay_8
	face_up
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_4
	face_up
	delay_4
	face_left
	delay_4
	face_down
	delay_4
	face_right
	delay_2
	face_up
	delay_2
	face_left
	delay_2
	face_down
	step_end

RocketHideout_B3F_Movement_Spin2:
	face_right
	delay_2
	face_up
	delay_2
	face_left
	delay_2
	face_down
	step_end

RocketHideout_B3F_Text_PetrelIntro:
    .string "Muhahaha, on t'attendait.\n"
    .string "Alors, tu es {PLAYER}…\p"
    .string "Moi ? Tu ne sais pas qui je suis ?\n"
    .string "C'est moi, GIOVANNI.\p"
    .string "Le majestueux GIOVANNI en personne !\n"
    .string "Wahahaha !$"

RocketHideout_B3F_Text_PetrelDisbelief:
    .string "...Hein ?\n"
    .string "Je ne ressemble pas du tout à\l"
    .string "GIOVANNI ?\p"
    .string "Je ne lui ressemble même pas physiquement ?\n"
    .string "Comment ça se fait ? J'ai travaillé si dur\l"
    .string "pour l'imiter !$"

RocketHideout_B3F_Text_PetrelReveal:
    .string "SCOTT : … … … … …\n"
    .string "… … … … … Zzz…\p"
    .string "… … … … … Hein ?!\n"
    .string "Oh, pardon, pardon ! Je faisais la sieste !\p"
    .string "Je suis venu voir ce CONCOURS POKéMON.\n"
    .string "Je dois admettre que ça a l'air assez\l"
    .string "divertissant, mais…\p"
    .string "Considère-moi comme un puriste--je préfère\n"
    .string "les combats et les DRESSEURS coriaces.\p"
    .string "Mais c'est juste moi.\n"
    .string "{PLAYER}{KUN}, j'espère que tu apprécieras tout\p"
    .string "comme les ARÈNES, les\n"
    .string "CONCOURS, la TENTE DE COMBAT,\l"
    .string "tout le reste !$"

RocketHideout_B3F_Text_PetrelBeaten:
    .string "Je… Je n'ai rien pu faire…\p"
    .string "GIOVANNI, pardonne-moi…$"

RocketHideout_B3F_Text_PetrelAfterBattle:
    .string "PETREL : Depuis le\n"
    .string "démantèlement de\l"
    .string "la Team Rocket\p"
    .string "il y a trois ans, notre\n"
    .string "GIOVANNI a disparu.\l"
    .string "Mais nous sommes\p"
    .string "certains qu'il attendait\n"
    .string "le bon moment pour revenir.\l"
    .string "Et ce moment est arrivé !\p"
    .string "La TEAM ROCKET renaît !$"

RocketHideout_B3F_EventScript_Murkrow::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MURKROW, CRY_MODE_NORMAL
	msgbox RocketHideout_B3F_Text_MurkrowSpeak1, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RocketHideout_B3F_Text_MurkrowSpeak1:
    .string "CORNEBRE : Salut GIOVANNI.$"

RocketHideout_B3F_Text_MurkrowMimic:
    .string "CORNEVRE imite\n"
    .string "la voix de PETREL !\p"
    .string "Tu pourrais peut-être... !?$"

RocketHideout_B3F_Text_Murkrow:
    .string "CORNEVRRE : Le mot de passe est…\p"
    .string "VIVE GIOVANNI.$"

RocketHideout_B3F_Text_GruntF5Seen:
    .string "Je connais le mot de passe ?\p"
    .string "Peut-être.\p"
    .string "Mais aucun minable\n"
    .string "ne l'aura !$"

RocketHideout_B3F_Text_GruntF5Beaten:
    .string "D'accord. Arrête. Je vais te le dire.$"

RocketHideout_B3F_Text_GruntF5After:
    .string "Le mot de passe de la salle du boss\n"
    .string "est QUEUERAMOLOSS.\p"
    .string "Mais c'est inutile sans avoir\n"
    .string "deux mots de passe.$"

RocketHideout_B3F_Text_GruntM28Seen:
    .string "Hihihi ! Je me souviens de\p"
    .string "toi du puits ! Tu me\p"
    .string "défies encore ? Hah ! Tu\p"
    .string "es fou, mais tu as du\n"
    .string "courage ! Je te préviens, je\p"
    .string "me suis amélioré ! Si tu\p"
    .string "peux me battre, je te\l"
    .string "donnerai un mot de passe\n"
    .string "pour le PARC DES COMBATS.$"

RocketHideout_B3F_Text_GruntM28Beaten:
    .string "Hi hi hi ! Tu es fort !$"

RocketHideout_B3F_Text_GruntM28After:
    .string "Hi hi hi !\p"
    .string "Le mot de passe de la salle du chef…\p"
    .string "Euh…, je crois que c'est QUEUE RATTATAC.$"

RocketHideout_B3F_Text_ScientistRossSeen:
    .string "Je travaillais pour la SYLPHE SARL,\n"
    .string "mais maintenant je fais de la\p"
    .string "recherche pour la TEAM ROCKET. Un\n"
    .string "garnement comme toi doit être puni.$"

RocketHideout_B3F_Text_ScientistRossBeaten:
    .string "Une simple erreur tactique m'a coûté la victoire…$"

RocketHideout_B3F_Text_ScientistRossAfter:
    .string "Un signal radio qui rend\n"
    .string "les POKéMON fous…\p"
    .string "Mon expérience est un succès\n"
    .string "complet.\p"
    .string "Ma promotion est assurée. Cette\n"
    .string "perte ne signifie absolument rien.$"

RocketHideout_B3F_Text_ScientistMitchSeen:
    .string "Je me fiche que les POKéMON soient blessés\n"
    .string "par notre expérience.$"

RocketHideout_B3F_Text_ScientistMitchBeaten:
    .string "Réfléchir est mon point fort,\n"
    .string "pas le combat.$"

RocketHideout_B3F_Text_ScientistMitchAfter:
    .string "Si on augmente la puissance de notre\n"
    .string "signal radio pour diffuser à l'échelle\l"
    .string "nationale...\p"
    .string "Rien que d'y penser m'excite !$"
