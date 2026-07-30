.set LOCALID_BURNED_TOWER_SILVER, 3
.set LOCALID_BURNED_TOWER_EUSINE, 1

BurnedTower_1F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, BurnedTower_1F_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BurnedTower_1F_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, BurnedTower_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

BurnedTower_1F_OnTransition: 
	callnative SetTimeBasedEncounters
	end

BurnedTower_1F_OnLoad::
	goto_if_ge VAR_ECRUTEAK_CITY_STATE, 4, BurnedTower_1F_MapScript_CreateHole
	end

BurnedTower_1F_MapScript_CreateHole::
	setmetatile 16, 12, 0x37E, FALSE
	end

BurnedTower_1F_OnFrame::
	map_script_2 VAR_ECRUTEAK_CITY_STATE, 1, BurnedTower_1F_EventScript_MeetEusine
	.2byte 0

BurnedTower_1F_EventScript_MeetEusine::
	lock
	playse SE_PIN
	applymovement LOCALID_BURNED_TOWER_EUSINE, Common_Movement_ExclamationMark
	delay 60
	applymovement LOCALID_BURNED_TOWER_EUSINE, BurnedTower_Movement_Eusine1
	waitmovement 0
	msgbox BurnedTower_1FEusineIntroText, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BURNED_TOWER_EUSINE, BurnedTower_Movement_Eusine2
	waitmovement 0
	setvar VAR_ECRUTEAK_CITY_STATE, 2
	release
	end

BurnedTower_Movement_Eusine1:
	walk_down
	walk_down
	step_end

BurnedTower_Movement_Eusine2:
	walk_up
	walk_up
	step_end


BurnedTower_1FEusineIntroText:
	.string "EUSINE : Je m'appelle EUSINE.\p"
	.string "Je suis sur la piste\n"
	.string "d'un POKéMON appelé SUICUNE. Et\p"
	.string "toi, c'est… ? {PLAYER} ?\p"
	.string "Enchanté ! J'ai entendu dire\p"
	.string "que SUICUNE pourrait être dans\n"
	.string "cette TOUR CENDRÉE, alors je\l"
	.string "suis venu vérifier. Mais où\p"
	.string "exactement pourrait-il être ?$"

BurnedTower_1F_EventScript_Item_HpUp::
	finditem ITEM_HP_UP
	end

BurnedTower_1F_EventScript_Item_Ether::
	finditem ITEM_ETHER
	end

BurnedTower_1F_EventScript_Eusine::
	lock
	faceplayer
	msgbox BurnedTower_1FEusineText, MSGBOX_DEFAULT
	closemessage
	release
	end

BurnedTower_1F_EventScript_Morty::
	lock
	faceplayer
	msgbox BurnedTower_1FMortyText, MSGBOX_DEFAULT
	closemessage
	release
	end

BurnedTower_1FEusineText:
	.string "EUSINE : J'ai entendu dire que\n"
	.string "SUICUNE pourrait être dans cette TOUR\l"
	.string "CENDRÉE, alors je suis venu\p"
	.string "vérifier. Mais où exactement ?$"

BurnedTower_1FMortyText:
	.string "MORTIMER : Le CHAMPION D'ARÈNE d'ROSALIA\n"
	.string "doit étudier ce que l'on dit être\l"
	.string "les POKéMON légendaires--\l"
	.string "SUICUNE, ENTEI et RAIKOU.\p"
	.string "MORTIMER est là, alors j'ai\n"
	.string "décidé d'enquêter sur la\l"
	.string "TOUR avec lui.$"

BurnedTower_1F_EventScript_Silver::
	lock
	playse SE_PIN
	applymovement LOCALID_BURNED_TOWER_SILVER, Common_Movement_ExclamationMark
	delay 60
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	applymovement LOCALID_BURNED_TOWER_SILVER, Common_Movement_WalkLeft1
	waitmovement 0
	waitmovement 0
	msgbox BurnedTowerSilver_BeforeText, MSGBOX_DEFAULT
	call_if_eq VAR_STARTER_MON, 0, BurnedTower_1F_Silver_Battle_Cyndaquil
	call_if_eq VAR_STARTER_MON, 1, BurnedTower_1F_Silver_Battle_Totodile
	call_if_eq VAR_STARTER_MON, 2, BurnedTower_1F_Silver_Battle_Chikorita
	playbgm MUS_HG_RIVAL_EXIT, TRUE
	msgbox BurnedTowerSilver_AfterText1, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 20  @ num shakes
	setvar VAR_0x8007, 6  @ shake delay
	special ShakeCamera
	waitstate
	playse SE_CLICK
	setmetatile 16, 12, 0x37E, FALSE
	special DrawWholeMapView
	waitse
	delay 60
	special SpawnCameraObject
	removeobject OBJ_EVENT_ID_PLAYER
	playse SE_FALL
	delay 60
	msgbox BurnedTowerSilver_AfterText2, MSGBOX_AUTOCLOSE
	waitmessage
	warphole MAP_BURNED_TOWER_B1F
	setvar VAR_ECRUTEAK_CITY_STATE, 3
	release
	end

BurnedTower_1F_Silver_Battle_Cyndaquil::
	trainerbattle_no_intro TRAINER_RIVAL_CYNDAQUIL_3, BurnedTowerSilver_WinText
	return

BurnedTower_1F_Silver_Battle_Totodile::
	trainerbattle_no_intro TRAINER_RIVAL_TOTODILE_3, BurnedTowerSilver_WinText
	return

BurnedTower_1F_Silver_Battle_Chikorita::
	trainerbattle_no_intro TRAINER_RIVAL_CHIKORITA_3, BurnedTowerSilver_WinText
	return

BurnedTowerSilver_BeforeText:
	.string ".............................. …Oh, c'est toi. Je\p"
	.string "suis venu chercher des POKéMON\p"
	.string "légendaires qui seraient censés\n"
	.string "se percher ici. Mais\l"
	.string "il n'y a rien\p"
	.string "! Rien, après tout\p"
	.string "l'effort d'être venu dans\n"
	.string "ce trou ? Pas\l"
	.string "question ! C'est entièrement\p"
	.string "de ta faute !$"

BurnedTowerSilver_WinText:
	.string "...Humph !\p"
	.string "Je n'ai perdu que parce que mes\n"
	.string "POKéMON sont incroyablement faibles.\p"
	.string "Comme c'est pathétique.$"

BurnedTowerSilver_AfterText1:
	.string "...Bon, peu importe.\p"
	.string "Tu ne pourras jamais attraper\n"
	.string "un POKéMON légendaire de toute façon.$"

BurnedTowerSilver_LossText:
	.string "...Humph !\p"
	.string "C'est pour ça que je déteste combattre\n"
	.string "les lâches. C'est une perte de temps.$"

BurnedTowerSilver_AfterText2:
	.string "Humph !\p"
	.string "Qu'est-ce que tu fais en tombant\n"
	.string "dans un trou ? Quel génie !\p"
	.string "Tu l'as bien mérité !$"

BurnedTower_1F_EventScript_Nard::
	trainerbattle_single TRAINER_NARD BurnedTower_Text_NardSeen, BurnedTower_Text_NardBeaten
	msgbox BurnedTower_Text_NardAfter, MSGBOX_AUTOCLOSE
	end

BurnedTower_1F_EventScript_Richardo::
	trainerbattle_single TRAINER_RICHARDO BurnedTower_Text_RichardoSeen, BurnedTower_Text_RichardoBeaten
	msgbox BurnedTower_Text_RichardoAfter, MSGBOX_AUTOCLOSE
	end

BurnedTower_Text_NardSeen:
	.string "Ne t'inquiète pas !\p"
	.string "Nous, cracheurs de feu, connaissons le vrai\n"
	.string "pouvoir du feu mieux que quiconque !$"
BurnedTower_Text_NardBeaten:
	.string "Merci pour un combat aussi intense !$"
BurnedTower_Text_NardAfter:
	.string "La raison pour laquelle cette tour a\n"
	.string "brûlé, c'est qu'elle a été frappée\p"
	.string "par la foudre. Le feu que\n"
	.string "je crache est minuscule en comparaison…$"

BurnedTower_Text_RichardoSeen:
	.string "Je m'entraîne au vol dans la\n"
	.string "TOUR CENDRÉE ! N'essaie pas\l"
	.string "ça chez toi !$"
BurnedTower_Text_RichardoBeaten:
	.string "Pfffffffffffffff.$"
BurnedTower_Text_RichardoAfter:
	.string "Peut-être que la vie criminelle\n"
	.string "n'est pas pour moi...$"
