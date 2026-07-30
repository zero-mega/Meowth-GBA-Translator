.set LOCALID_DIRECTOR_OFFICE, 1
.set LOCALID_GOLDENROD_ARCHER, 2
.set LOCALID_GOLDENROD_ARIANA, 3
.set LOCALID_PETREL_OFFICE, 4
.set LOCALID_DIRECTOR_STUDIO, 5

GoldenrodCity_RadioTower_5F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, GoldenrodCity_RadioTower_5F_OnLoad
	.byte 0

GoldenrodCity_RadioTower_5F_OnLoad::
	call_if_eq VAR_GOLDENROD_CITY_STATE, 6, GoldenrodCity_RadioTower_5F_MapScript_HidePetrel
	end

GoldenrodCity_RadioTower_5F_MapScript_HidePetrel::
	clearflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_PETREL
	return


@=======[OFFICE]==============================================================================================================================

GoldenrodCity_RadioTower_5F_EventScript_Petrel::
	lock
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 10, GoldenrodCity_RadioTower_5F_EventScript_Director
	goto_if_eq VAR_FACING, DIR_SOUTH, GoldenrodCity_RadioTower_5F_EventScript_PetrelNorth
	faceplayer
	msgbox GoldenrodCity_RadioTower_5F_Text_FakeDirector1, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DIRECTOR_OFFICE, GoldenrodCity_RadioTower_5F_Movement_Spin
	waitmovement 0
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR
	removeobject LOCALID_DIRECTOR_OFFICE
	clearflag FLAG_HIDE_GOLDENROD_RADIOTOWER_PETREL
	addobject LOCALID_PETREL_OFFICE
	applymovement LOCALID_PETREL_OFFICE, GoldenrodCity_RadioTower_5F_Movement_Spin2
	waitmovement 0
	msgbox GoldenrodCity_RadioTower_5F_Text_FakeDirector2, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_PETREL_2, GoldenrodCity_RadioTower_5F_Text_FakeDirectorWin
	msgbox GoldenrodCity_RadioTower_5F_Text_FakeDirectorAfter, MSGBOX_DEFAULT
	giveitem ITEM_BASEMENT_KEY
	setvar VAR_GOLDENROD_CITY_STATE, 7
	clearflag FLAG_HIDE_GOLDENROD_UNDERGROUND_KIMONO
	closemessage
	release
	end

GoldenrodCity_RadioTower_5F_EventScript_PetrelNorth::
	end

GoldenrodCity_RadioTower_5F_EventScript_Petrel2::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_5F_Text_FakeDirectorAfter2, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_5F_EventScript_Director::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorIntro, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_5F_Movement_Spin:
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


GoldenrodCity_RadioTower_5F_Movement_Spin2:
	face_right
	delay_2
	face_up
	delay_2
	face_left
	delay_2
	face_down
	step_end


GoldenrodCity_RadioTower_5F_Text_FakeDirector1:
	.string "T-toi ! Tu es venu me sauver ?$"

GoldenrodCity_RadioTower_5F_Text_FakeDirector2:
	.string "C'est ce que tu attendais ? Raté\p"
	.string "! Je suis un imposteur ! Je\p"
	.string "me suis fait passer pour le vrai\n"
	.string "pour préparer notre prise de pouvoir. Tu\p"
	.string "veux savoir où on a caché le\n"
	.string "vrai DIRECTEUR ? Bien sûr, je\p"
	.string "vais te le dire. Mais seulement\n"
	.string "si tu peux me battre !$"

GoldenrodCity_RadioTower_5F_Text_FakeDirectorWin:
	.string "OK, OK. Je vais te dire où il est.$"

GoldenrodCity_RadioTower_5F_Text_FakeDirectorAfter:
	.string "Le boss a enfermé le\n"
	.string "DIRECTEUR dans l'ENTREPÔT SOUTERRAIN. C'est\p"
	.string "au fond du SOUTERRAIN. Je\n"
	.string "suis sympa, je vais te\p"
	.string "donner la CLÉ SOUS-SOL pour\n"
	.string "accéder à l'ENTREPÔT SOUTERRAIN.\l"
	.string "Mais je doute que\p"
	.string "tu ailles si loin.$"

GoldenrodCity_RadioTower_5F_Text_FakeDirectorAfter2:
	.string "Le boss a enfermé le\n"
	.string "DIRECTEUR dans l'ENTREPÔT SOUTERRAIN. C'est\p"
	.string "au fond du SOUTERRAIN. Tu\n"
	.string "peux utiliser la CLÉ SOUS-SOL\p"
	.string "pour accéder à l'ENTREPÔT SOUTERRAIN.\n"
	.string "Mais je doute que\p"
	.string "tu ailles si loin.$"

@=======[STUDIO]==============================================================================================================================

GoldenrodCity_RadioTower_5F_EventScript_Ben::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_5F_Text_Ben, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodRaidoTower4_EventScript_ARIANA::
	trainerbattle_single TRAINER_ARIANA_2 GoldenrodCity_RadioTower_5F_Text_ExecutiveF1Seen, GoldenrodCity_RadioTower_5F_Text_ExecutiveF1Beaten
	msgbox GoldenrodCity_RadioTower_5F_Text_ExecutiveF1After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_RadioTower_5F_EventScript_Archer::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_5F_Text_RocketBossSeen, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_ARCHER, GoldenrodCity_RadioTower_5F_Text_RocketBossBeaten
	msgbox GoldenrodCity_RadioTower_5F_Text_RocketBossAfter, MSGBOX_DEFAULT
	delay 55
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_GOLDENROD_ROCKETS
	playse SE_EXIT
	setvar VAR_GOLDENROD_CITY_STATE, 10
	removeobject LOCALID_GOLDENROD_ARCHER
	removeobject LOCALID_GOLDENROD_ARIANA
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_PETREL
	clearflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR
	removeobject LOCALID_PETREL_OFFICE
	addobject LOCALID_DIRECTOR_STUDIO
	playbgm MUS_HG_GOLDENROD, TRUE
	delay 120
	fadescreen FADE_FROM_BLACK
	goto_if_eq VAR_FACING, DIR_SOUTH, GoldenrodCity_RadioTower_5F_EventScript_WingTop
	goto_if_eq VAR_FACING, DIR_WEST, GoldenrodCity_RadioTower_5F_EventScript_WingMid
	goto_if_eq VAR_FACING, DIR_NORTH, GoldenrodCity_RadioTower_5F_EventScript_WingBot
	release
	end

GoldenrodCity_RadioTower_5F_EventScript_WingTop::
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerTop
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorThanks, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_LUGIA_OR_HOOH, 1,  GoldenrodCity_RadioTower_5F_EventScript_GiveTidalWing
	call_if_eq VAR_LUGIA_OR_HOOH, 2, GoldenrodCity_RadioTower_5F_EventScript_GiveClearWing
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_LeaveTop
	waitmovement 0
	goto GoldenrodCity_RadioTower_5F_Fakeout
	end

GoldenrodCity_RadioTower_5F_EventScript_WingMid::
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerMid
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorThanks, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_LUGIA_OR_HOOH, 1,  GoldenrodCity_RadioTower_5F_EventScript_GiveTidalWing
	call_if_eq VAR_LUGIA_OR_HOOH, 2, GoldenrodCity_RadioTower_5F_EventScript_GiveClearWing
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_LeaveMid
	waitmovement 0
	goto GoldenrodCity_RadioTower_5F_Fakeout
	end

GoldenrodCity_RadioTower_5F_EventScript_WingBot::
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerBot
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorThanks, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_LUGIA_OR_HOOH, 1,  GoldenrodCity_RadioTower_5F_EventScript_GiveTidalWing
	call_if_eq VAR_LUGIA_OR_HOOH, 2, GoldenrodCity_RadioTower_5F_EventScript_GiveClearWing
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_LeaveBot
	waitmovement 0
	goto GoldenrodCity_RadioTower_5F_Fakeout
	end

GoldenrodCity_RadioTower_5F_EventScript_GiveTidalWing::
	giveitem ITEM_SILVER_WING
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorTidalWingExplanation, MSGBOX_DEFAULT
	closemessage
	release
	return

GoldenrodCity_RadioTower_5F_EventScript_GiveClearWing::
	giveitem ITEM_RAINBOW_WING
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorClearWingExplanation, MSGBOX_DEFAULT
	closemessage
	release
	return

GoldenrodCity_RadioTower_5F_Fakeout::
	playse SE_PIN
	applymovement LOCALID_DIRECTOR_STUDIO, Common_Movement_ExclamationMark
	delay 60
	turnobject LOCALID_DIRECTOR_STUDIO, DIR_WEST
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorLegendary, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_Leave1
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_DIRECTOR_STUDIO, Common_Movement_ExclamationMark
	delay 60
	turnobject LOCALID_DIRECTOR_STUDIO, DIR_SOUTH
	msgbox GoldenrodCity_RadioTower_5F_Text_DirectorFakeout, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DIRECTOR_STUDIO, GoldenrodCity_RadioTower_5F_Movement_Leave2
	waitmovement 0
	setflag FLAG_HIDE_GOLDENROD_RADIOTOWER_DIRECTOR_2
	removeobject LOCALID_DIRECTOR_STUDIO
	setvar VAR_MAHOGANY_TOWN_STATE, 17
	release
	end

GoldenrodCity_RadioTower_5F_EventScript_Trigger_NPCS::
	clearflag FLAG_HIDE_GOLDENROD_NPCS
	setvar VAR_GOLDENROD_CITY_STATE, 11
	end

GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerTop:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

GoldenrodCity_RadioTower_5F_Movement_LeaveTop:
	walk_right
	walk_right
	walk_right
	step_end

GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerMid:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	step_end


GoldenrodCity_RadioTower_5F_Movement_LeaveMid:
	walk_right
	walk_right
	step_end

GoldenrodCity_RadioTower_5F_Movement_WalkToPlayerBot:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	step_end

GoldenrodCity_RadioTower_5F_Movement_LeaveBot:
	walk_right
	walk_right
	walk_right
	step_end

GoldenrodCity_RadioTower_5F_Movement_Leave1:
	walk_up
	walk_up
	step_end

GoldenrodCity_RadioTower_5F_Movement_Leave2:
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

GoldenrodCity_RadioTower_5F_Text_ExecutiveF1Seen:
	.string "Tu te souviens de moi, du REPAIRE\n"
	.string "d'ACAJOU ? Mon boss m'a grondé mais\p"
	.string "je suis plus fort. J'ai perdu la\p"
	.string "dernière fois, mais pas cette fois.$"

GoldenrodCity_RadioTower_5F_Text_ExecutiveF1Beaten:
	.string "Ça ne peut pas arriver !\p"
	.string "J'ai combattu dur, mais j'ai quand même perdu…\p"
	.string "Je suis vraiment désolé GIOVANNI…$"

GoldenrodCity_RadioTower_5F_Text_ExecutiveF1After:
	.string "{PLAYER}, c'est bien toi ?\p"
	.string "Un morveux comme toi n'appréciera pas\n"
	.string "la magnificence de la TEAM ROCKET.\p"
	.string "Dommage. J'admire vraiment\n"
	.string "ta puissance.$"

GoldenrodCity_RadioTower_5F_Text_RocketBossSeen:
	.string "Oh ? Tu es arrivé jusqu'ici ?\p"
	.string "Tu dois être un\p"
	.string "sacré dresseur.\n"
	.string "Nous avons l'intention de\p"
	.string "prendre le contrôle\n"
	.string "de cette TOUR\p"
	.string "RADIO et annoncer\n"
	.string "notre retour.\p"
	.string "La TEAM ROCKET renaît !\n"
	.string "Tu ne nous arrêteras pas !$"

GoldenrodCity_RadioTower_5F_Text_RocketBossBeaten:
	.string "Non ! Pardonne-moi, GIOVANNI !$"

GoldenrodCity_RadioTower_5F_Text_RocketBossAfter:
	.string "Comment est-ce possible ?\p"
	.string "Nos rêves sont réduits à néant.\p"
	.string "Je n'étais pas à la hauteur après tout.\p"
	.string "Comme GIOVANNI avant moi, je vais\n"
	.string "dissoudre la TEAM ROCKET aujourd'hui.\p"
	.string "Adieu.$"

GoldenrodCity_RadioTower_5F_Text_DirectorThanks:
	.string "DIRECTEUR : {PLAYER}, merci !\p"
	.string "Tes actions courageuses ont sauvé\n"
	.string "les POKéMON du pays.\p"
	.string "Ce n'est pas grand-chose, mais\n"
	.string "prends ça, s'il te plaît.$"

GoldenrodCity_RadioTower_5F_Text_DirectorClearWingExplanation:
	.string "Il y avait autrefois une tour juste ici\n"
	.string "à DOUBLONVILLE.\p"
	.string "Mais elle était vieille et grinceante.\p"
	.string "Alors on l'a remplacée par notre TOUR\n"
	.string "RADIO.\p"
	.string "On a déterré cette aile pendant\n"
	.string "la construction.\p"
	.string "J'ai entendu que toutes sortes de POKéMON\n"
	.string "vivaient à DOUBLONVILLE dans le passé.\p"
	.string "Peut-être…\p"
	.string "Cette aile a un lien avec la\n"
	.string "TOUR CENDRÉE à ROSYÈRES…\p"
	.string "OK, je ferais mieux d'aller à mon BUREAU.$"

GoldenrodCity_RadioTower_5F_Text_DirectorTidalWingExplanation:
	.string "Il y avait autrefois une tour juste ici\n"
	.string "à DOUBLONVILLE.\p"
	.string "Mais elle était vieille et grinceante.\p"
	.string "Alors on l'a remplacée par notre TOUR\n"
	.string "RADIO.\p"
	.string "On a déterré cette aile pendant\n"
	.string "la construction.\p"
	.string "J'ai entendu que toutes sortes de POKéMON\n"
	.string "vivaient à DOUBLONVILLE dans le passé.\p"
	.string "Peut-être…\p"
	.string "Cette aile a un lien avec les\n"
	.string "ÎLES TOURBILLON près d'OLIVILLE…\p"
	.string "OK, je ferais mieux d'aller à mon BUREAU.$"

GoldenrodCity_RadioTower_5F_Text_DirectorLegendary:
	.string "Ah!\p"
	.string "That reminds me…\p"
	.string "That wing I gave you... I think\n"
	.string "it's related to the LEGENDARY\l"
	.string "POKéMON.\p"
	.string "But! The LEGENDARY POKéMON won't\n"
	.string "appear with just that wing...\p"
	.string "Apparently there is something else\n"
	.string "you need... Or something like that.\p"
	.string "I wonder what it was...\p"
	.string "I can't remember.$"

GoldenrodCity_RadioTower_5F_Text_DirectorFakeout:
	.string "Tu attends quelque chose ? C'est ce\n"
	.string "qu'on appelle une FEINTE. Il faut\p"
	.string "vraiment que je retourne à mon\n"
	.string "BUREAU cette fois. À plus !$"

GoldenrodCity_RadioTower_5F_Text_DirectorIntro:
	.string "DIRECTEUR : Bonjour, {PLAYER} !\p"
	.string "Tu sais, j'adore les POKéMON.\p"
	.string "J'ai construit cette TOUR RADIO pour pouvoir\n"
	.string "exprimer mon amour des POKéMON.\p"
	.string "Ce serait bien si les gens appréciaient\n"
	.string "nos émissions.$"

GoldenrodCity_RadioTower_5F_Text_Ben:
	.string "BEN : Tu écoutes notre musique ?$"

GoldenrodCity_RadioTower_5F_Text_DirectorOfficeSign:
	.string "5E BUREAU DU DIRECTEUR$"

GoldenrodCity_RadioTower_5F_Text_Studio1Sign:
	.string "5E STUDIO 1$"
