.set LOCALID_KYOGRE, 1
.set LOCALID_ARCHIE, 2
.set LOCALID_MAXIE, 3
.set LOCALID_GRUNT_1, 4
.set LOCALID_GRUNT_2, 5
.set LOCALID_KYOGRE_SLEEPING, 7

SeafloorCavern_Room9_MapScripts::
	.byte 0

SeafloorCavern_Room9_EventScript_ArchieAwakenKyogre::
	lockall
	setvar VAR_0x8004, LOCALID_ARCHIE
	setvar VAR_0x8005, LOCALID_MAXIE
	setvar VAR_0x8006, LOCALID_GRUNT_1
	setvar VAR_0x8007, LOCALID_GRUNT_2
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, SeafloorCavern_Room9_Movement_Delay32
	waitmovement 0
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	msgbox SeafloorCavern_Room9_Text_ArchieHoldItRightThere, MSGBOX_DEFAULT
	closemessage
	addobject VAR_0x8004
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	applymovement VAR_0x8004, SeafloorCavern_Room9_Movement_ArchieApproachPlayer
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieSoItWasYou, MSGBOX_DEFAULT
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieBeholdKyogre, MSGBOX_DEFAULT
	applymovement VAR_0x8004, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieYouMustDisappear, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_CASSIE, SeafloorCavern_Room9_Text_ArchieDefeat
	msgbox SeafloorCavern_Room9_Text_ArchieWithThisRedOrb, MSGBOX_DEFAULT
	setweather WEATHER_NONE
	doweather
	special Script_FadeOutMapMusic
	waitstate
	msgbox SeafloorCavern_Room9_Text_RedOrbShinesByItself, MSGBOX_DEFAULT
	special WaitWeather
	waitstate
	setvar VAR_RESULT, 1
	playse SE_M_DETECT
	dofieldeffectsparkle 16, 42, 0
	waitfieldeffect FLDEFF_SPARKLE
	closemessage
	setvar VAR_RESULT, 0
	playfanfare MUS_AWAKEN_LEGEND
	playse SE_ORB
	special DoOrbEffect
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 150
	removeobject LOCALID_KYOGRE_SLEEPING
	addobject LOCALID_KYOGRE
	waitstate
	delay 60
	applymovement LOCALID_KYOGRE, SeafloorCavern_Room9_Movement_KyogreApproach
	waitmovement 0
	special FadeOutOrbEffect
	waitstate
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_KYOGRE, SeafloorCavern_Room9_Movement_KyogreExit
	waitmovement 0
	removeobject LOCALID_KYOGRE
	delay 4
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 30
	setvar VAR_0x8004, LOCALID_ARCHIE
	setvar VAR_0x8005, LOCALID_MAXIE
	setvar VAR_0x8006, LOCALID_GRUNT_1
	setvar VAR_0x8007, LOCALID_GRUNT_2
	msgbox SeafloorCavern_Room9_Text_ArchieWhereDidKyogreGo, MSGBOX_DEFAULT
	playse SE_PC_LOGIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieAMessageFromOutside, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8004, SeafloorCavern_Room9_Movement_ArchieListenMessage
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieWhatRainingTooHard, MSGBOX_DEFAULT
	closemessage
	playse SE_PC_OFF
	delay 20
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieWhyDidKyogreDisappear, MSGBOX_DEFAULT
	closemessage
	addobject VAR_0x8005
	addobject VAR_0x8006
	addobject VAR_0x8007
	applymovement VAR_0x8007, SeafloorCavern_Room9_Movement_MagmaGruntArrive
	applymovement VAR_0x8006, SeafloorCavern_Room9_Movement_MagmaGruntArrive
	applymovement VAR_0x8005, SeafloorCavern_Room9_Movement_MaxieArrive
	waitmovement 0
	applymovement VAR_0x8004, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_MaxieWhatHaveYouWrought, MSGBOX_DEFAULT
	playse SE_PIN
	applymovement VAR_0x8004, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement VAR_0x8004, Common_Movement_Delay48
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_ArchieDontGetAllHighAndMighty, MSGBOX_DEFAULT
	msgbox SeafloorCavern_Room9_Text_MaxieWeDontHaveTimeToArgue, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_0x8005, SeafloorCavern_Room9_Movement_MaxieExit
	applymovement VAR_0x8004, SeafloorCavern_Room9_Movement_ArchieExit
	waitmovement 0
	msgbox SeafloorCavern_Room9_Text_MaxieComeOnPlayer, MSGBOX_DEFAULT
	setvar VAR_GARBAGEVAR, 1
	setvar VAR_GARBAGEVAR, 1
	clearflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_GROUDON
	clearflag FLAG_HIDE_SOOTOPOLIS_CITY_KYOGRE
	setflag FLAG_GARBAGEFLAG
	setflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	setflag FLAG_SYS_WEATHER_CTRL
	setflag FLAG_KYOGRE_ESCAPED_SEAFLOOR_CAVERN
	setflag FLAG_GARBAGEFLAG
	setvar VAR_STEVENS_HOUSE_STATE, 2
	setvar VAR_SEAFLOOR_CAVERN_STATE, 1
	setflag FLAG_GARBAGEFLAG
	setflag FLAG_GARBAGEFLAG
	setflag FLAG_GARBAGEFLAG
	setflag FLAG_GARBAGEFLAG
	setflag FLAG_GARBAGEFLAG
	setflag FLAG_HIDE_MAP_NAME_POPUP
	warp MAP_ROUTE128, 38, 22
	waitstate
	releaseall
	end

SeafloorCavern_Room9_Movement_ArchieApproachPlayer:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

SeafloorCavern_Room9_Movement_Unused1:
	walk_left
	walk_left
	step_end

SeafloorCavern_Room9_Movement_ArchieListenMessage:
	walk_left
	delay_16
	step_end

SeafloorCavern_Room9_Movement_Unused2:
	walk_right
	step_end

SeafloorCavern_Room9_Movement_ArchieExit:
	face_up
	lock_facing_direction
	walk_down
	unlock_facing_direction
	walk_in_place_faster_right
	step_end

SeafloorCavern_Room9_Movement_KyogreApproach:
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

SeafloorCavern_Room9_Movement_KyogreExit:
	slide_up
	slide_up
	step_end

SeafloorCavern_Room9_Movement_MaxieArrive:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

SeafloorCavern_Room9_Movement_MaxieExit:
	walk_right
	walk_right
	step_end

SeafloorCavern_Room9_Movement_MagmaGruntArrive:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

SeafloorCavern_Room9_Movement_Delay32:
	delay_16
	delay_16
	step_end

SeafloorCavern_Room9_Text_ArchieHoldItRightThere:
	.string "ARCHIE : Halte là.$"

SeafloorCavern_Room9_Text_ArchieSoItWasYou:
	.string "ARCHIE : Fufufu…\n"
	.string "C'était donc toi, après tout.$"

SeafloorCavern_Room9_Text_ArchieBeholdKyogre:
	.string "ARTHUR : Contemple !\p"
	.string "Vois comme c'est beau, la forme endormie\n"
	.string "du POKéMON ancien KYOGRE !\p"
	.string "J'ai attendu si longtemps que ce jour\n"
	.string "arrive…$"

SeafloorCavern_Room9_Text_ArchieYouMustDisappear:
	.string "ARTHUR : Ça m'étonne que tu aies réussi\n"
	.string "à me poursuivre jusqu'ici.\p"
	.string "Mais c'est fini maintenant.\p"
	.string "Pour la réalisation de mon rêve,\n"
	.string "tu dois disparaître maintenant !$"

SeafloorCavern_Room9_Text_ArchieDefeat:
	.string "Quoi ?!\n"
	.string "J'ai perdu contre un simple enfant ?!$"

SeafloorCavern_Room9_Text_ArchieWithThisRedOrb:
	.string "ARTHUR : Fufufu…\p"
	.string "Je te félicite. Je dois reconnaître\n"
	.string "que tu es vraiment doué.\p"
	.string "Mais !\n"
	.string "J'ai ceci en ma possession !\p"
	.string "Avec cet ORBE ROUGE, je peux faire que KYOGRE…$"

SeafloorCavern_Room9_Text_RedOrbShinesByItself:
	.string "L'ORBE ROUGE a soudain commencé\n"
	.string "à briller tout seul !$"

SeafloorCavern_Room9_Text_ArchieWhereDidKyogreGo:
	.string "ARCHIE : Quoi ?!\p"
	.string "Je n'ai rien fait.\n"
	.string "Pourquoi l'ORBE ROUGE…\p"
	.string "Où est KYOGRE passé ?$"

SeafloorCavern_Room9_Text_ArchieAMessageFromOutside:
	.string "ARTHUR : Hm ? C'est un message de nos\n"
	.string "membres dehors…$"

SeafloorCavern_Room9_Text_ArchieWhatRainingTooHard:
	.string "ARCHIE : Oui, qu'est-ce qu'il y a ?\p"
	.string "Hm…\n"
	.string "Il pleut fort ?\p"
	.string "Bien… Ça aurait dû arriver.\n"
	.string "C'est pour ça qu'on a réveillé KYOGRE,\l"
	.string "pour réaliser la vision de la TEAM AQUA\l"
	.string "d'agrandir la mer.\p"
	.string "Quoi ?!\p"
	.string "Il pleut beaucoup plus fort que ce qu'on\n"
	.string "avait prévu ? Tu es en danger ?\p"
	.string "Ça ne peut pas être…\n"
	.string "C'est tout simplement impossible…\p"
	.string "Tiens ta position et surveille\n"
	.string "la situation !$"

SeafloorCavern_Room9_Text_ArchieWhyDidKyogreDisappear:
	.string "ARTHUR : Quelque chose ne va pas…\p"
	.string "L'ORBE ROUGE est censé réveiller\n"
	.string "et contrôler KYOGRE…\p"
	.string "Mais… Pourquoi ?\n"
	.string "Pourquoi KYOGRE a-t-il disparu ?\p"
	.string "Pourquoi ?!$"

SeafloorCavern_Room9_Text_MaxieWhatHaveYouWrought:
	.string "MAX : Qu'as-tu fait ? ARTHUR…\p"
	.string "Tu as enfin réveillé KYOGRE,\n"
	.string "n'est-ce pas ? Que va-t-il\p"
	.string "arriver au monde si cette\n"
	.string "averse continue pour l'éternité ?\p"
	.string "La masse terrestre du monde\n"
	.string "sera engloutie par la mer…$"

SeafloorCavern_Room9_Text_ArchieDontGetAllHighAndMighty:
	.string "ARTHUR : Q-Quoi ?! Ne te\n"
	.string "laisse pas aller avec moi !\p"
	.string "N'est-ce pas toi, la TEAM MAGMA,\n"
	.string "qui a enragé GROUDON ? Tant\p"
	.string "que j'ai cette GEMME ROUGE,\n"
	.string "je devrais pouvoir contrôler KYOGRE…\p"
	.string "Je devrais pouvoir le contrôler…$"

SeafloorCavern_Room9_Text_MaxieWeDontHaveTimeToArgue:
	.string "MAX : On n'a pas le temps de\n"
	.string "se disputer ici !\p"
	.string "Sors et vois par toi-même !\p"
	.string "Vois si ce que tu as accompli est le\n"
	.string "monde que nous désirions !$"

SeafloorCavern_Room9_Text_MaxieComeOnPlayer:
	.string "MAX : {PLAYER}, allez, il faut\n"
	.string "que tu sortes d'ici aussi !$"
