.set LOCALID_GROUDON, 1
.set LOCALID_GRUNT_1, 2
.set LOCALID_GRUNT_2, 3
.set LOCALID_GRUNT_3, 4
.set LOCALID_TABITHA, 5
.set LOCALID_MAXIE, 6
.set LOCALID_GROUDON_SLEEPING, 7

MagmaHideout_4F_MapScripts::
	.byte 0

MagmaHideout_4F_EventScript_Maxie::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	msgbox MagmaHideout_4F_Text_MaxieAwakenGroudon, MSGBOX_DEFAULT
	closemessage
	delay 20
	setvar VAR_RESULT, 1
	playse SE_M_DETECT
	dofieldeffectsparkle 18, 42, 0
	waitfieldeffect FLDEFF_SPARKLE
	setvar VAR_RESULT, 1
	playfanfare MUS_AWAKEN_LEGEND
	playse SE_ORB
	special DoOrbEffect
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 150
	removeobject LOCALID_GROUDON_SLEEPING
	addobject LOCALID_GROUDON
	waitstate
	delay 60
	applymovement LOCALID_GROUDON, MagmaHideout_4F_Movement_GroudonApproach
	waitmovement 0
	special FadeOutOrbEffect
	waitstate
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_GROUDON, MagmaHideout_4F_Movement_GroudonExit
	waitmovement 0
	removeobject LOCALID_GROUDON
	delay 4
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 30
	applymovement LOCALID_MAXIE, MagmaHideout_4F_Movement_MaxieLookAround
	waitmovement 0
	msgbox MagmaHideout_4F_Text_MaxieGroudonWhatsWrong, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 30
	applymovement LOCALID_MAXIE, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MagmaHideout_4F_Text_MaxieOhItWasYou, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_MAXIE_MAGMA_HIDEOUT, MagmaHideout_4F_Text_MaxieDefeat
	msgbox MagmaHideout_4F_Text_MaxieImGoingAfterGroudon, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	setvar VAR_GARBAGEVAR, 1
	setflag FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT
	setvar VAR_SLATEPORT_HARBOR_STATE, 1
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MAXIE
	removeobject LOCALID_GRUNT_1
	removeobject LOCALID_GRUNT_2
	removeobject LOCALID_GRUNT_3
	removeobject LOCALID_TABITHA
	setflag FLAG_GARBAGEFLAG
	fadescreen FADE_FROM_BLACK
	releaseall
	end

MagmaHideout_4F_Movement_GroudonApproach:
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	step_end

MagmaHideout_4F_Movement_GroudonExit:
	slide_up
	slide_up
	step_end

MagmaHideout_4F_Movement_MaxieLookAround:
	face_left
	delay_16
	face_right
	delay_16
	face_left
	delay_16
	face_right
	delay_16
	face_up
	delay_16
	delay_16
	step_end

MagmaHideout_4F_EventScript_Grunt11::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_11, MagmaHideout_4F_Text_Grunt11Intro, MagmaHideout_4F_Text_Grunt11Defeat
	msgbox MagmaHideout_4F_Text_Grunt11PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Grunt12::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_12, MagmaHideout_4F_Text_Grunt12Intro, MagmaHideout_4F_Text_Grunt12Defeat
	msgbox MagmaHideout_4F_Text_Grunt12PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Grunt13::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_13, MagmaHideout_4F_Text_Grunt13Intro, MagmaHideout_4F_Text_Grunt13Defeat
	msgbox MagmaHideout_4F_Text_Grunt13PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Tabitha::
	trainerbattle_single TRAINER_TABITHA_MAGMA_HIDEOUT, MagmaHideout_4F_Text_TabithaIntro, MagmaHideout_4F_Text_TabithaDefeat
	msgbox MagmaHideout_4F_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_Text_Grunt11Intro:
	.string "Moi aussi je veux voir GROUDON, mais ils\n"
	.string "ne me laissent pas voir même sa queue…\p"
	.string "Ça me frustre vraiment.\p"
	.string "Oh, non !\n"
	.string "J'ai bavardé sur GROUDON !$"

MagmaHideout_4F_Text_Grunt11Defeat:
	.string "Je suppose qu'il est impossible de gagner\n"
	.string "si on n'a pas l'esprit calme…$"

MagmaHideout_4F_Text_Grunt11PostBattle:
	.string "Je me demande si GROUDON a même une queue ?$"

MagmaHideout_4F_Text_Grunt12Intro:
	.string "Fuhahaha !\n"
	.string "Bientôt ! Très bientôt !\l"
	.string "Notre grand objectif sera atteint !$"

MagmaHideout_4F_Text_Grunt12Defeat:
	.string "Grrr…\n"
	.string "J'ai fait tout ce chemin, et maintenant ça ?$"

MagmaHideout_4F_Text_Grunt12PostBattle:
	.string "MAXIE, monsieur !\n"
	.string "Un intrus se dirige vers vous !$"

MagmaHideout_4F_Text_Grunt13Intro:
	.string "Ce n'est pas fini !\n"
	.string "Tu ne passeras pas si facilement !$"

MagmaHideout_4F_Text_Grunt13Defeat:
	.string "J'étais si facile à terrasser ?$"

MagmaHideout_4F_Text_Grunt13PostBattle:
	.string "A-allez, encore un combat…$"

MagmaHideout_4F_Text_TabithaIntro:
	.string "Héhéhé !\n"
	.string "Tu es arrivé jusqu'ici, alors je vais te le dire !\p"
	.string "C'est ça !\n"
	.string "Devant, GROUDON dort !\p"
	.string "MAX a rejoint GROUDON il y a\n"
	.string "quelques secondes !\p"
	.string "Il va bientôt se réveiller !\n"
	.string "Héhé ! Héhéhé !$"

MagmaHideout_4F_Text_TabithaDefeat:
	.string "Encore à terre…\n"
	.string "Héhé…$"

MagmaHideout_4F_Text_TabithaPostBattle:
	.string "…Et pendant que tu perdais du temps avec moi,\n"
	.string "MAXIE aurait dû réveiller GROUDON…$"

MagmaHideout_4F_Text_MaxieAwakenGroudon:
	.string "MAX : GROUDON…\p"
	.string "Rien n'a pu te réveiller de ton\n"
	.string "sommeil baigné de magma…\p"
	.string "Cette GEMME BLEUE est ce que tu\n"
	.string "cherchais. N'est-ce pas ?\p"
	.string "Je t'ai apporté la GEMME BLEUE.\n"
	.string "Que son éclat te réveille !\p"
	.string "Et montre-moi…\n"
	.string "Montre-moi toute l'étendue de ton pouvoir !$"

MagmaHideout_4F_Text_MaxieGroudonWhatsWrong:
	.string "MAX : GROUDON !\n"
	.string "Qu'est-ce qui ne va pas ?\p"
	.string "La GEMME BLEUE n'était pas la clé ?\p"
	.string "GROUDON !\n"
	.string "Où es-tu passé…$"

MagmaHideout_4F_Text_MaxieOhItWasYou:
	.string "MAX : Oh, c'était toi ?\p"
	.string "Je t'ai vu fouiner sans invitation\n"
	.string "ici et là…\p"
	.string "Je comprends maintenant !\n"
	.string "Tu as dû faire un coup bas !$"

MagmaHideout_4F_Text_MaxieDefeat:
	.string "Qu'est-ce qui te rend si doué avec\n"
	.string "les POKéMON ?$"

MagmaHideout_4F_Text_MaxieImGoingAfterGroudon:
	.string "MAX : Il doit y\n"
	.string "avoir une raison\p"
	.string "pour laquelle\n"
	.string "GROUDON a fui…\p"
	.string "C'est ce que tu\n"
	.string "essaies de dire,\p"
	.string "n'est-ce pas,\n"
	.string "{PLAYER} ?\p"
	.string "Nous devons\n"
	.string "réfléchir à\p"
	.string "notre prochaine\n"
	.string "étape.$"
