.set LOCALID_MATT, 1
.set LOCALID_SUBMARINE, 4

AquaHideout_B2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, AquaHideout_B2F_OnTransition
	.byte 0

AquaHideout_B2F_OnTransition:
	call_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, AquaHideout_B2F_EventScript_PreventMattNoticing
	end

AquaHideout_B2F_EventScript_PreventMattNoticing::
	setvar VAR_TEMP_1, 1
	return

AquaHideout_B2F_EventScript_MattNoticePlayer::
	lockall
	setvar VAR_0x8008, LOCALID_MATT
	playse SE_PIN
	applymovement VAR_0x8008, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	setvar VAR_TEMP_1, 1
	releaseall
	end

AquaHideout_B2F_EventScript_Matt::
	trainerbattle_single TRAINER_MATT, AquaHideout_B2F_Text_MattIntro, AquaHideout_B2F_Text_MattDefeat, AquaHideout_B2F_EventScript_SubmarineEscape
	msgbox AquaHideout_B2F_Text_MattPostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B2F_EventScript_SubmarineEscape::
	setvar VAR_0x8008, LOCALID_MATT
	setvar VAR_0x8009, LOCALID_SUBMARINE
	applymovement VAR_0x8008, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 20
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	msgbox AquaHideout_B2F_Text_OurBossGotThroughHisPreparations, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8008, Common_Movement_WalkInPlaceFasterLeft
	applymovement VAR_0x8009, AquaHideout_B2F_Movement_SumbarineDepartLeft
	waitmovement 0
	removeobject VAR_0x8009
	delay 20
	applymovement VAR_0x8008, Common_Movement_FacePlayer
	waitmovement 0
	msgbox AquaHideout_B2F_Text_MattPostBattle, MSGBOX_DEFAULT
	setflag FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE
	setflag FLAG_GARBAGEFLAG
	release
	end

AquaHideout_B2F_Movement_SumbarineDepartLeft:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

@ Unused
AquaHideout_B2F_Movement_SumbarineDepartRight:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

AquaHideout_B2F_EventScript_Grunt4::
	trainerbattle_single TRAINER_SETH, AquaHideout_B2F_Text_Grunt4Intro, AquaHideout_B2F_Text_Grunt4Defeat, AquaHideout_B2F_EventScript_Grunt4Defeated
	msgbox AquaHideout_B2F_Text_Grunt4PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_EventScript_Grunt4Defeated::
	msgbox AquaHideout_B2F_Text_Grunt4PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B2F_EventScript_Grunt6::
	trainerbattle_single TRAINER_STANLY, AquaHideout_B2F_Text_Grunt6Intro, AquaHideout_B2F_Text_Grunt6Defeat
	msgbox AquaHideout_B2F_Text_Grunt6PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_EventScript_Grunt8::
	trainerbattle_single TRAINER_STEVE, AquaHideout_B2F_Text_Grunt8Intro, AquaHideout_B2F_Text_Grunt8Defeat
	msgbox AquaHideout_B2F_Text_Grunt8PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B2F_Text_MattIntro:
	.string "Héhéhé…\p"
	.string "Tu es déjà là ?\n"
	.string "On t'a sous-estimé !\p"
	.string "Mais c'est fini !\p"
	.string "Je suis d'un tout autre niveau que les\n"
	.string "SBIRES que tu as vus jusqu'ici.\p"
	.string "Je ne perds pas de temps.\n"
	.string "Je vais te pulvériser !$"

AquaHideout_B2F_Text_MattDefeat:
	.string "Héhéhé…\n"
	.string "Alors, j'ai perdu aussi…$"

AquaHideout_B2F_Text_OurBossGotThroughHisPreparations:
	.string "Héhéhé !\p"
	.string "Pendant que je jouais avec toi, notre CHEF\n"
	.string "a terminé ses préparations !$"

AquaHideout_B2F_Text_MattPostBattle:
	.string "Héhéhé ! Notre BOSS\p"
	.string "est déjà parti vers\n"
	.string "une grotte sous la\p"
	.string "mer ! Si\n"
	.string "tu veux le\l"
	.string "suivre, vas-y !\p"
	.string "On ne te\n"
	.string "retient pas !$"

AquaHideout_B2F_Text_Grunt4Intro:
	.string "Wahahah, j'en avais marre d'attendre !\n"
	.string "Tu me dois un combat, toi aussi !$"

AquaHideout_B2F_Text_Grunt4Defeat:
	.string "Fatigué d'attendre…\n"
	.string "Perdu et hébété…$"

AquaHideout_B2F_Text_Grunt4PostBattle:
	.string "BOSS…\n"
	.string "C'est assez bien comme ça ?$"

AquaHideout_B2F_Text_Grunt6Intro:
	.string "Panneaux de téléportation, la fierté\n"
	.string "de la PLANQUE !\p"
	.string "Tu n'as aucune idée d'où tu es,\n"
	.string "n'est-ce pas ?\p"
	.string "Héhéhé !\n"
	.string "Tu es perdu !$"

AquaHideout_B2F_Text_Grunt6Defeat:
	.string "Qu'est-ce qui ne va pas chez toi ?\n"
	.string "Tu n'es pas fatigué du tout !$"

AquaHideout_B2F_Text_Grunt6PostBattle:
	.string "Ça me rappelle… Je ne me souviens\n"
	.string "plus où j'ai mis la MASTER\p"
	.string "BALL. Si je ne la garde\n"
	.string "pas, notre BOSS va me gronder…$"

AquaHideout_B2F_Text_Grunt8Intro:
	.string "Quand j'ai rejoint la TEAM AQUA, la première\n"
	.string "chose que j'ai dû apprendre, c'est comment ces\l"
	.string "panneaux de téléportation sont reliés.$"

AquaHideout_B2F_Text_Grunt8Defeat:
	.string "J'étais trop occupé à penser\n"
	.string "aux panneaux de téléportation…$"

AquaHideout_B2F_Text_Grunt8PostBattle:
	.string "Il faut que j'apprenne à combattre\n"
	.string "plus efficacement…$"
