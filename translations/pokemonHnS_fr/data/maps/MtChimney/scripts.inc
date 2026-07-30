.set LOCALID_ARCHIE, 1
.set LOCALID_MAXIE, 2
.set LOCALID_TABITHA, 3
.set LOCALID_MAGMA_GRUNT_2, 22
.set LOCALID_MAGMA_GRUNT_1, 29


MtChimney_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, MtChimney_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, MtChimney_OnTransition
	.byte 0

MtChimney_OnTransition:
	setvar VAR_JAGGED_PASS_ASH_WEATHER, 1
	end

MtChimney_OnResume:
	setstepcallback STEP_CB_ASH
	end

MtChimney_EventScript_Archie::
	lock
	faceplayer
	call_if_unset FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieGoStopTeamMagma
	call_if_set FLAG_EVIL_LEADER_PLEASE_STOP, MtChimney_EventScript_ArchieBusyFighting
	closemessage
	applymovement LOCALID_ARCHIE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_EVIL_LEADER_PLEASE_STOP
	release
	end

MtChimney_EventScript_ArchieGoStopTeamMagma::
	msgbox MtChimney_Text_ArchieGoStopTeamMagma, MSGBOX_DEFAULT
	return

MtChimney_EventScript_ArchieBusyFighting::
	msgbox MtChimney_Text_ArchieIHaveMyHandsFull, MSGBOX_DEFAULT
	return

MtChimney_EventScript_Maxie::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	msgbox MtChimney_Text_MeteoriteWillActivateVolcano, MSGBOX_DEFAULT
	applymovement LOCALID_MAXIE, Common_Movement_FacePlayer
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_MAXIE, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MAXIE, Common_Movement_Delay48
	waitmovement 0
	msgbox MtChimney_Text_MaxieIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MAXIE_MT_CHIMNEY, MtChimney_Text_MaxieDefeat
	msgbox MtChimney_Text_MaxieYouHaventSeenLastOfMagma, MSGBOX_DEFAULT
	closemessage
	delay 30
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_MAXIE
	removeobject LOCALID_MAGMA_GRUNT_1
	removeobject LOCALID_TABITHA
	removeobject LOCALID_MAGMA_GRUNT_2
	setflag FLAG_GARBAGEFLAG
	fadescreenswapbuffers FADE_FROM_BLACK
	setobjectxyperm LOCALID_ARCHIE, 10, 12
	addobject LOCALID_ARCHIE
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieApproachPlayerEast
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieApproachPlayerNorth
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox MtChimney_Text_ArchieThankYou, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_EAST, MtChimney_EventScript_ArchieExitEast
	call_if_eq VAR_FACING, DIR_NORTH, MtChimney_EventScript_ArchieExitNorth
	removeobject LOCALID_ARCHIE
	setflag FLAG_GARBAGEFLAG
	setflag FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY
	clearflag FLAG_GARBAGEFLAG
	setflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	releaseall
	end

MtChimney_EventScript_ArchieApproachPlayerEast::
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieApproachPlayerEast
	waitmovement 0
	return

MtChimney_EventScript_ArchieApproachPlayerNorth::
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieApproachPlayerNorth
	waitmovement 0
	return

MtChimney_EventScript_ArchieExitEast::
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieExitEast
	waitmovement 0
	return

MtChimney_EventScript_ArchieExitNorth::
	applymovement LOCALID_ARCHIE, MtChimney_Movement_ArchieExitNorth
	waitmovement 0
	return

MtChimney_EventScript_LavaCookieLady::
	lock
	faceplayer
	showmoneybox 0, 0
	msgbox MtChimney_Text_LavaCookiesJust200, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_DeclineLavaCookie
	checkmoney 200
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_NotEnoughMoney
	msgbox MtChimney_Text_ThankYouDear, MSGBOX_DEFAULT
	checkitemspace ITEM_LAVA_COOKIE
	call_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RemoveMoney
	giveitem ITEM_LAVA_COOKIE
	goto_if_eq VAR_RESULT, FALSE, MtChimney_EventScript_BagIsFull
	hidemoneybox
	release
	end

MtChimney_EventScript_BagIsFull::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_EventScript_RemoveMoney::
	removemoney 200
	updatemoneybox
	return

MtChimney_EventScript_DeclineLavaCookie::
	msgbox MtChimney_Text_OhFineThen, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_EventScript_NotEnoughMoney::
	msgbox MtChimney_Text_YouveNotGotTheMoney, MSGBOX_DEFAULT
	hidemoneybox
	release
	end

MtChimney_Movement_ArchieApproachPlayerEast:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	step_end

MtChimney_Movement_ArchieExitEast:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_ArchieApproachPlayerNorth:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	step_end

MtChimney_Movement_ArchieExitNorth:
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused1:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused2:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused3:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused4:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused5:
	delay_16
	delay_16
	delay_16
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused6:
	delay_16
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused7:
	delay_16
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

MtChimney_Movement_Unused8:
	delay_16
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_faster_down
	step_end

MtChimney_Movement_Unused9:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused10:
	walk_down
	step_end

MtChimney_Movement_Unused11:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused12:
	delay_16
	delay_16
	walk_in_place_faster_left
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused13:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_faster_left
	delay_16
	walk_down
	walk_down
	step_end

MtChimney_Movement_Unused14:
	lock_facing_direction
	walk_fast_left
	unlock_facing_direction
	face_right
	step_end

MtChimney_Movement_Unused15:
	walk_left
	walk_in_place_faster_right
	delay_16
	step_end

MtChimney_EventScript_BusyAquaGrunt1::
	msgbox MtChimney_Text_MagmaOutnumbersUs, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyAquaGrunt2::
	msgbox MtChimney_Text_LessHabitatForWaterPokemon, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyAquaGrunt3::
	msgbox MtChimney_Text_MagmasNameSimilar, MSGBOX_SIGN
	end

MtChimney_EventScript_Tabitha::
	trainerbattle_single TRAINER_TABITHA_MT_CHIMNEY, MtChimney_Text_TabithaIntro, MtChimney_Text_TabithaDefeat
	msgbox MtChimney_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Grunt2::
	trainerbattle_single TRAINER_THEO, MtChimney_Text_Grunt2Intro, MtChimney_Text_Grunt2Defeat
	msgbox MtChimney_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_BusyMagmaGrunt1::
	msgbox MtChimney_Text_TeamAquaAlwaysMessingWithPlans, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt2::
	msgbox MtChimney_Text_MeteoritesPackAmazingPower, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt3::
	msgbox MtChimney_Text_YouBetterNotMessWithUs, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt4::
	msgbox MtChimney_Text_AquasNameSimilar, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt5::
	msgbox MtChimney_Text_DouseThemInFire, MSGBOX_SIGN
	end

MtChimney_EventScript_BusyMagmaGrunt6::
	msgbox MtChimney_Text_KeepMakingMoreLand, MSGBOX_SIGN
	end

MtChimney_EventScript_MagmaPoochyena::
	msgbox MtChimney_Text_Bufoh, MSGBOX_SIGN
	end

MtChimney_EventScript_AquaPoochyena::
	msgbox MtChimney_Text_Bushaa, MSGBOX_SIGN
	end

MtChimney_EventScript_MeteoriteMachine::
	lockall
	goto_if_unset FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, MtChimney_EventScript_MachineOn
	goto_if_set FLAG_RECEIVED_METEORITE, MtChimney_EventScript_MachineOff
	msgbox MtChimney_Text_RemoveTheMeteorite, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MtChimney_EventScript_LeaveMeteoriteAlone
	msgbox MtChimney_Text_PlayerRemovedMeteorite, MSGBOX_DEFAULT
	giveitem ITEM_METEORITE
	setflag FLAG_RECEIVED_METEORITE
	releaseall
	end

MtChimney_EventScript_LeaveMeteoriteAlone::
	msgbox MtChimney_Text_PlayerLeftMeteorite, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_MachineOff::
	msgbox MtChimney_Text_MachineMakesNoResponse, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_MachineOn::
	msgbox MtChimney_Text_MetoriteFittedOnMachine, MSGBOX_DEFAULT
	releaseall
	end

MtChimney_EventScript_RouteSign::
	msgbox MtChimney_Text_RouteSign, MSGBOX_SIGN
	end

MtChimney_EventScript_Shelby::
	trainerbattle_single TRAINER_SHELBY_1, MtChimney_Text_ShelbyIntro, MtChimney_Text_ShelbyDefeat, MtChimney_EventScript_DefeatedShelby
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_RematchShelby
	msgbox MtChimney_Text_ShelbyPostBattle, MSGBOX_DEFAULT
	release
	end

MtChimney_EventScript_DefeatedShelby::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtChimney_Text_ShelbyRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_SHELBY_1
	release
	end

MtChimney_EventScript_RematchShelby::
	trainerbattle_rematch TRAINER_SHELBY_1, MtChimney_Text_ShelbyRematchIntro, MtChimney_Text_ShelbyRematchDefeat
	msgbox MtChimney_Text_ShelbyPostRematch, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Melissa::
	trainerbattle_single TRAINER_MELISSA, MtChimney_Text_MelissaIntro, MtChimney_Text_MelissaDefeat
	msgbox MtChimney_Text_MelissaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Sheila::
	trainerbattle_single TRAINER_SHEILA, MtChimney_Text_SheilaIntro, MtChimney_Text_SheilaDefeat
	msgbox MtChimney_Text_SheilaPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Shirley::
	trainerbattle_single TRAINER_SHIRLEY, MtChimney_Text_ShirleyIntro, MtChimney_Text_ShirleyDefeat
	msgbox MtChimney_Text_ShirleyPostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Grunt1::
	trainerbattle_single TRAINER_TERU, MtChimney_Text_Grunt1Intro, MtChimney_Text_Grunt1Defeat
	msgbox MtChimney_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

MtChimney_EventScript_Sawyer::
	trainerbattle_single TRAINER_SAWYER_1, MtChimney_Text_SawyerIntro, MtChimney_Text_SawyerDefeat, MtChimney_EventScript_SawyerDefeated
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtChimney_EventScript_SawyerRematch
	msgbox MtChimney_Text_SawyerPostBattle, MSGBOX_DEFAULT
	release
	end

MtChimney_EventScript_SawyerDefeated::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtChimney_Text_SawyerRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_SAWYER_1
	release
	end

MtChimney_EventScript_SawyerRematch::
	trainerbattle_rematch TRAINER_SAWYER_1, MtChimney_Text_SawyerRematchIntro, MtChimney_Text_SawyerRematchDefeat
	msgbox MtChimney_Text_SawyerPostRematch, MSGBOX_AUTOCLOSE
	end

MtChimney_Text_MeteoriteWillActivateVolcano:
	.string "Le pouvoir contenu dans\p"
	.string "la MÉTÉORITE… En amplifiant\n"
	.string "sa puissance avec cette\l"
	.string "machine, le MONT\p"
	.string "CHIMNÉE va… Non\n"
	.string "! Il ne\l"
	.string "faut pas !$"

MtChimney_Text_MaxieIntro:
	.string "MAX : Hm ?\n"
	.string "Qui es-tu ?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "J'avais entendu ARCHIE se plaindre d'un enfant\n"
	.string "qui s'immisce dans les affaires de la\l"
	.string "TEAM AQUA.\p"
	.string "Ce doit être toi dont il parlait.\p"
	.string "Humph ! Alors tu comptes\n"
	.string "t'opposer à nous, la TEAM MAGMA ?\p"
	.string "Écoute bien.\n"
	.string "Autrefois, les êtres vivants utilisaient\l"
	.string "la terre pour vivre et grandir.\p"
	.string "C'est pourquoi la terre est primordiale !\n"
	.string "C'est le berceau de tout !\p"
	.string "C'est pourquoi la TEAM MAGMA se consacre\n"
	.string "à l'expansion des terres.\p"
	.string "C'est pour l'avancement de\n"
	.string "l'humanité et des POKéMON !\p"
	.string "Et pour cela, nous avons besoin du pouvoir de\n"
	.string "ce qui dort dans cette montagne…\p"
	.string "Oh ! Tu n'avais pas besoin d'en\n"
	.string "savoir autant.\p"
	.string "Mais peu importe !\n"
	.string "Je vais t'apprendre les conséquences de\l"
	.string "t'immiscer dans notre grand dessein !$"

MtChimney_Text_MaxieDefeat:
	.string "Quoi ?!\p"
	.string "Moi, MAX, j'ai été pris au dépourvu ?!$"

MtChimney_Text_MaxieYouHaventSeenLastOfMagma:
	.string "MAX : Mais assez.\n"
	.string "Je vais reculer cette fois.\p"
	.string "Mais ne crois pas que ce soit la dernière\n"
	.string "fois que tu vois la TEAM MAGMA.\p"
	.string "Fufufu…\p"
	.string "Même sans la MÉTÉORITE, si nous\n"
	.string "obtenons cet ORBE… Fufufu…$"

MtChimney_Text_TabithaIntro:
	.string "Héhéhé !\p"
	.string "Alors tu es venu jusqu'ici !\p"
	.string "Mais tu es trop tard !\n"
	.string "J'ai déjà livré la MÉTÉORITE\l"
	.string "de la METEORITE aux BOSS !$"

MtChimney_Text_TabithaDefeat:
	.string "Héhéhé…\p"
	.string "Même si j'ai perdu, si notre chef\n"
	.string "réveille cette chose…$"

MtChimney_Text_TabithaPostBattle:
	.string "BOSS, vite !\n"
	.string "Donne-lui l'énergie du MÉTÉORITE !\p"
	.string "Héhéhé…$"

MtChimney_Text_Grunt2Intro:
	.string "Nous, de la TEAM MAGMA, travaillons dur\n"
	.string "pour le bien de tous.\p"
	.string "Par exemple, si le pouvoir de cette chose\n"
	.string "créait plus de terre, il y aurait plus d'endroits pour vivre.\p"
	.string "Tout le monde serait heureux !$"

MtChimney_Text_Grunt2Defeat:
	.string "Hein ?\n"
	.string "Qu'est-ce que tu veux dire, j'ai perdu ?$"

MtChimney_Text_Grunt2PostBattle:
	.string "Notre CHEF dit : « Ça rendra tout le monde\n"
	.string "heureux. »\p"
	.string "Mais pourquoi tout le monde continue-t-il de nous\n"
	.string "barrer le chemin ?$"

MtChimney_Text_Grunt1Intro:
	.string "S'il y avait plus de terre, je pourrais\n"
	.string "avoir une grande maison !\p"
	.string "Je vais la construire sur de la lave solidifiée !$"

MtChimney_Text_Grunt1Defeat:
	.string "Mon rêve d'une grande maison…$"

MtChimney_Text_Grunt1PostBattle:
	.string "Un gamin comme toi devrait\n"
	.string "barboter dans les vagues !$"

MtChimney_Text_TeamAquaAlwaysMessingWithPlans:
	.string "Cette TEAM AQUA agaçante…\n"
	.string "Elle fout toujours nos plans en l'air !$"

MtChimney_Text_MeteoritesPackAmazingPower:
	.string "Les MÉTÉORITES renferment un pouvoir incroyable !$"

MtChimney_Text_YouBetterNotMessWithUs:
	.string "Tu ferais mieux de ne pas te mêler de nous !\p"
	.string "On essaie de réveiller cette chose\n"
	.string "pour le bien de tout le monde !$"

MtChimney_Text_AquasNameSimilar:
	.string "Nous sommes la TEAM MAGMA !\p"
	.string "Eux, c'est la TEAM AQUA !\p"
	.string "Ça m'énerve qu'ils utilisent\n"
	.string "un nom comme le nôtre !$"

MtChimney_Text_DouseThemInFire:
	.string "Ouais !\n"
	.string "Brûle-les avec le feu !$"

MtChimney_Text_KeepMakingMoreLand:
	.string "On va continuer à créer plus de terre !$"

MtChimney_Text_Bufoh:
	.string "Pouah !$"

MtChimney_Text_ArchieGoStopTeamMagma:
	.string "ARCHIE : Grr, {PLAYER} !\n"
	.string "J'aurais dû deviner\p"
	.string "que tu apparaîtrais !\n"
	.string "Vois par toi-même ce\p"
	.string "que les fanatiques\n"
	.string "de la TEAM\p"
	.string "MAGMA ont fait !\n"
	.string "Nous devons agir !$"

MtChimney_Text_ArchieIHaveMyHandsFull:
	.string "ARCHIE : Grrr… Je veux arrêter\p"
	.string "ce MAX, mais je ne peux\n"
	.string "pas ! Pas quand je\p"
	.string "dois me battre contre trois\n"
	.string "adversaires à la fois !$"

MtChimney_Text_ArchieThankYou:
	.string "ARTHUR : {PLAYER} !\n"
	.string "Merci !\p"
	.string "Avec ton aide, nous avons déjoué\n"
	.string "le plan destructeur de la TEAM\p"
	.string "MAGMA !\n"
	.string "Mais… Toi…\p"
	.string "De quel côté es-tu ?\p"
	.string "Ah, peu importe.\n"
	.string "Nous resterons vigilants et\p"
	.string "poursuivrons la TEAM MAGMA. {PLAYER}, on se reverra !$"

MtChimney_Text_MagmaOutnumbersUs:
	.string "Zut… La TEAM MAGMA nous surpasse en nombre !\n"
	.string "On n'arrive pas à suivre !$"

MtChimney_Text_LessHabitatForWaterPokemon:
	.string "S'ils étendent les terres, il y aura\n"
	.string "moins d'habitats pour les POKéMON EAU !$"

MtChimney_Text_MagmasNameSimilar:
	.string "Nous sommes la TEAM AQUA !\p"
	.string "Eux, c'est la TEAM MAGMA !\p"
	.string "Ça m'énerve qu'ils utilisent\n"
	.string "un nom aussi confus !$"

MtChimney_Text_Bushaa:
	.string "Bushaa !$"

MtChimney_Text_LavaCookiesJust200:
	.string "Les LAVA COOKIES sont la spécialité locale\n"
	.string "du MONT CHIMNÉE.\p"
	.string "Goûtes-en un. Seulement 200¥.$"

MtChimney_Text_ThankYouDear:
	.string "Merci, mon chéri !$"

MtChimney_Text_YouveNotGotTheMoney:
	.string "Oh, chéri. Tu ne peux rien acheter si\n"
	.string "tu n'as pas d'argent.$"

MtChimney_Text_OhFineThen:
	.string "Oh, d'accord.$"

MtChimney_Text_MetoriteFittedOnMachine:
	.string "Une MÉTÉORITE est fixée sur une machine\n"
	.string "mystérieuse...\p"
	.string "La machine semble stocker de l'énergie\n"
	.string "dans la MÉTÉORITE.$"

MtChimney_Text_RemoveTheMeteorite:
	.string "Un MÉTÉORITE est fixé sur une machine\n"
	.string "mystérieuse…\p"
	.string "Veux-tu retirer le MÉTÉORITE ?$"

MtChimney_Text_PlayerRemovedMeteorite:
	.string "{PLAYER} a retiré le MÉTÉORITE de\n"
	.string "la machine mystérieuse.$"

MtChimney_Text_PlayerLeftMeteorite:
	.string "{PLAYER} a laissé le MÉTÉORITE\n"
	.string "là où elle était.$"

MtChimney_Text_MachineMakesNoResponse:
	.string "Cette machine mystérieuse…\n"
	.string "Elle ne réagit absolument pas.$"

MtChimney_Text_RouteSign:
	.string "{DOWN_ARROW} SENTIER DÉTREMPÉ\n"
	.string "LAVARIDGE EN VUE$"

MtChimney_Text_ShelbyIntro:
	.string "Je suis allé aux sources chaudes et\n"
	.string "j'ai reposé mes os fatigués.\l"
	.string "En ce moment, je me sens fort !$"

MtChimney_Text_ShelbyDefeat:
	.string "Oh, mon Dieu.\n"
	.string "Tu es vraiment quelque chose !$"

MtChimney_Text_ShelbyPostBattle:
	.string "Eh bien, j'ai perdu. Je ne peux plus\n"
	.string "me dire EXPERT maintenant, n'est-ce pas ?$"

MtChimney_Text_ShelbyRegister:
	.string "Merci, mon enfant. C'était amusant,\n"
	.string "comme si je combattais mon\p"
	.string "propre petit-enfant. Reviens me\n"
	.string "voir pour une revanche.$"

MtChimney_Text_ShelbyRematchIntro:
	.string "Si tu peux harmoniser ton cœur avec ceux\n"
	.string "de tes POKéMON, eh bien, tu devrais\l"
	.string "pouvoir accomplir de grandes choses.$"

MtChimney_Text_ShelbyRematchDefeat:
	.string "Oh, mon Dieu.\n"
	.string "Tu es vraiment quelque chose !$"

MtChimney_Text_ShelbyPostRematch:
	.string "Peut-être que ton cœur n'est plus qu'un\n"
	.string "avec les cœurs de tes POKéMON.$"

MtChimney_Text_MelissaIntro:
	.string "J'ai le feu en moi, bébé.\n"
	.string "Je ne peux pas le supporter ! Il faut que je me batte !$"

MtChimney_Text_MelissaDefeat:
	.string "Ooh, c'était un match brûlant !$"

MtChimney_Text_MelissaPostBattle:
	.string "La chaleur du MONT CHIMNEY\n"
	.string "me réchauffe, chéri !$"

MtChimney_Text_SheilaIntro:
	.string "Je suis enfin arrivé au MONT CHIMNÉE.\n"
	.string "Je veux faire combattre mes POKéMON !$"

MtChimney_Text_SheilaDefeat:
	.string "Ta façon de te battre…\n"
	.string "C'est comme une éruption du MONT CHIMNÉE !$"

MtChimney_Text_SheilaPostBattle:
	.string "Comme je l'ai dit, je suis enfin arrivé au\n"
	.string "MONT CHIMNÉE. Ce serait dommage si\l"
	.string "je ne faisais qu'un peu de tourisme…\p"
	.string "Je veux me battre et acheter des\n"
	.string "COOKIES en souvenir.$"

MtChimney_Text_ShirleyIntro:
	.string "Depuis que je me suis baigné dans les sources chaudes,\n"
	.string "je me sens super bien !\l"
	.string "Je suis sûr que je vais gagner !$"

MtChimney_Text_ShirleyDefeat:
	.string "Aïe !\n"
	.string "J'ai froid à cause de l'eau.$"

MtChimney_Text_ShirleyPostBattle:
	.string "Il faut que je replonge dans les\n"
	.string "sources chaudes. Tu veux venir ?\p"
	.string "Je plaisante !$"

MtChimney_Text_SawyerIntro:
	.string "C'est une belle montagne ! Plein de\n"
	.string "gens sympas pour faire compagnie !$"

MtChimney_Text_SawyerDefeat:
	.string "Oh, tu es un vrai flambeur, toi aussi !$"

MtChimney_Text_SawyerPostBattle:
	.string "Je crois que j'ai besoin d'un bain aux\n"
	.string "SOURCES THERMALES de LAVARIA avec les locaux !$"

MtChimney_Text_SawyerRegister:
	.string "Tu me plais, petit bout de feu.\n"
	.string "Laisse-moi t'enregistrer dans mon POKéNAV.$"

MtChimney_Text_SawyerRematchIntro:
	.string "Je suis entouré de gens chauds\n"
	.string "par ici. Je ne vais pas perdre !$"

MtChimney_Text_SawyerRematchDefeat:
	.string "Mon Dieu, tu es toujours le même\n"
	.string "tête brûlée qu'avant !$"

MtChimney_Text_SawyerPostRematch:
	.string "En fait, il fait vraiment chaud ici.\n"
	.string "Je suis trop habillé pour ces contrées.$"

