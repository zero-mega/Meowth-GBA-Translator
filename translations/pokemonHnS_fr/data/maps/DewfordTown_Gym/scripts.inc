DewfordTown_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_Gym_OnTransition
	.byte 0

DewfordTown_Gym_OnTransition:
	call DewfordTown_Gym_EventScript_SetFlashLevel
	end

DewfordTown_Gym_EventScript_SetFlashLevel::
	goto_if_defeated TRAINER_DICK, DewfordTown_Gym_EventScript_SetLightsOn
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
	copyvar VAR_0x8001, VAR_0x8000
	goto_if_eq VAR_0x8000, 0, DewfordTown_Gym_EventScript_SetFlashLevel7
	goto_if_eq VAR_0x8000, 1, DewfordTown_Gym_EventScript_SetFlashLevel6
	goto_if_eq VAR_0x8000, 2, DewfordTown_Gym_EventScript_SetFlashLevel5
	goto_if_eq VAR_0x8000, 3, DewfordTown_Gym_EventScript_SetFlashLevel4
	goto_if_eq VAR_0x8000, 4, DewfordTown_Gym_EventScript_SetFlashLevel3
	goto_if_eq VAR_0x8000, 5, DewfordTown_Gym_EventScript_SetFlashLevel2
	goto DewfordTown_Gym_EventScript_SetFlashLevel1

DewfordTown_Gym_EventScript_SetLightsOn::
	setflashlevel 0
	return

@ Brightest
DewfordTown_Gym_EventScript_SetFlashLevel1::
	setflashlevel 1
	return

DewfordTown_Gym_EventScript_SetFlashLevel2::
	setflashlevel 2
	return

DewfordTown_Gym_EventScript_SetFlashLevel3::
	setflashlevel 3
	return

DewfordTown_Gym_EventScript_SetFlashLevel4::
	setflashlevel 4
	return

DewfordTown_Gym_EventScript_SetFlashLevel5::
	setflashlevel 5
	return

DewfordTown_Gym_EventScript_SetFlashLevel6::
	setflashlevel 6
	return

@ Darkest
DewfordTown_Gym_EventScript_SetFlashLevel7::
	setflashlevel 7
	return

DewfordTown_Gym_EventScript_BrightenRoom::
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
	nop1
	goto_if_eq VAR_0x8000, VAR_0x8001, DewfordTown_Gym_EventScript_NoLightChange
	copyvar VAR_0x8001, VAR_0x8000
	goto_if_eq VAR_0x8000, 1, DewfordTown_Gym_EventScript_AnimateFlash1Trainer
	goto_if_eq VAR_0x8000, 2, DewfordTown_Gym_EventScript_AnimateFlash2Trainers
	goto_if_eq VAR_0x8000, 3, DewfordTown_Gym_EventScript_AnimateFlash3Trainers
	goto_if_eq VAR_0x8000, 4, DewfordTown_Gym_EventScript_AnimateFlash4Trainers
	goto_if_eq VAR_0x8000, 5, DewfordTown_Gym_EventScript_AnimateFlash5Trainers
	goto_if_eq VAR_0x8000, 6, DewfordTown_Gym_EventScript_AnimateFlash6Trainers

DewfordTown_Gym_EventScript_NoLightChange::
	return

@ NOTE: A little confusingly, a larger animateflash param value is a smaller flash radius
DewfordTown_Gym_EventScript_AnimateFlash1Trainer::
	playse SE_SWITCH
	animateflash 6
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash2Trainers::
	playse SE_SWITCH
	animateflash 5
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash3Trainers::
	playse SE_SWITCH
	animateflash 4
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash4Trainers::
	playse SE_SWITCH
	animateflash 3
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash5Trainers::
	playse SE_SWITCH
	animateflash 2
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash6Trainers::
	playse SE_SWITCH
	animateflash 1
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlashFullBrightness::
	playse SE_SWITCH
	animateflash 0
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_CountTrainersDefeated::
	setvar VAR_0x8000, 0
	goto_if_not_defeated TRAINER_TAKAO, DewfordTown_Gym_EventScript_CheckJocelyn
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckJocelyn::
	goto_if_not_defeated TRAINER_JOCELYN, DewfordTown_Gym_EventScript_CheckLaura
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckLaura::
	goto_if_not_defeated TRAINER_LAURA, DewfordTown_Gym_EventScript_CheckBrenden
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckBrenden::
	goto_if_not_defeated TRAINER_BRENDEN, DewfordTown_Gym_EventScript_CheckCristian
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckCristian::
	goto_if_not_defeated TRAINER_HARVEY, DewfordTown_Gym_EventScript_CheckLilith
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckLilith::
	goto_if_not_defeated TRAINER_LILITH, DewfordTown_Gym_EventScript_StopCountingTrainers
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_StopCountingTrainers::
	return

DewfordTown_Gym_EventScript_Brawly::
	trainerbattle_single TRAINER_DICK, DewfordTown_Gym_Text_BrawlyIntro, DewfordTown_Gym_Text_BrawlyDefeat, DewfordTown_Gym_EventScript_BrawlyDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_Gym_EventScript_BrawlyRematch
	goto_if_unset FLAG_RECEIVED_TM_BULK_UP, DewfordTown_Gym_EventScript_GiveBulkUp2
	msgbox DewfordTown_Gym_Text_BrawlyPostBattle, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_BrawlyDefeated::
	call DewfordTown_Gym_EventScript_AnimateFlashFullBrightness
	message DewfordTown_Gym_Text_ReceivedKnuckleBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_AZALEA_TOWN_GYM
	setflag FLAG_BADGE02_GET
	addvar VAR_GARBAGEVAR, 1
	call_if_eq VAR_GARBAGEVAR, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 2
	call Common_EventScript_SetGymTrainers
	call DewfordTown_Gym_EventScript_GiveBulkUp
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox DewfordTown_Gym_Text_RegisteredBrawly, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_BRAWLY_MATCH_CALL
	setvar VAR_ROXANNE_CALL_STEP_COUNTER, 0
	setflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	release
	end

DewfordTown_Gym_EventScript_GiveBulkUp::
	giveitem ITEM_TM_BULK_UP
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
	msgbox DewfordTown_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_BULK_UP
	return

DewfordTown_Gym_EventScript_GiveBulkUp2:
	giveitem ITEM_TM_BULK_UP
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	msgbox DewfordTown_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_BULK_UP
	release
	end

DewfordTown_Gym_EventScript_BrawlyRematch::
	trainerbattle_rematch_double TRAINER_DICK, DewfordTown_Gym_Text_BrawlyPreRematch, DewfordTown_Gym_Text_BrawlyRematchDefeat, DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons
	msgbox DewfordTown_Gym_Text_BrawlyPostRematch, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_Takao::
	trainerbattle_single TRAINER_TAKAO, DewfordTown_Gym_Text_TakaoIntro, DewfordTown_Gym_Text_TakaoDefeat, DewfordTown_Gym_EventScript_TakaoBrightenRoom
	msgbox DewfordTown_Gym_Text_TakaoPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_TakaoBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Jocelyn::
	trainerbattle_single TRAINER_JOCELYN, DewfordTown_Gym_Text_JocelynIntro, DewfordTown_Gym_Text_JocelynDefeat, DewfordTown_Gym_EventScript_JocelynBrightenRoom
	msgbox DewfordTown_Gym_Text_JocelynPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_JocelynBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Laura::
	trainerbattle_single TRAINER_LAURA, DewfordTown_Gym_Text_LauraIntro, DewfordTown_Gym_Text_LauraDefeat, DewfordTown_Gym_EventScript_LauraBrightenRoom
	msgbox DewfordTown_Gym_Text_LauraPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_LauraBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Brenden::
	trainerbattle_single TRAINER_BRENDEN, DewfordTown_Gym_Text_BrendenIntro, DewfordTown_Gym_Text_BrendenDefeat, DewfordTown_Gym_EventScript_BrendenBrightenRoom
	msgbox DewfordTown_Gym_Text_BrendenPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_BrendenBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Cristian::
	trainerbattle_single TRAINER_HARVEY, DewfordTown_Gym_Text_CristianIntro, DewfordTown_Gym_Text_CristianDefeat, DewfordTown_Gym_EventScript_CristianBrightenRoom
	msgbox DewfordTown_Gym_Text_CristianPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_CristianBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Lilith::
	trainerbattle_single TRAINER_LILITH, DewfordTown_Gym_Text_LilithIntro, DewfordTown_Gym_Text_LilithDefeat, DewfordTown_Gym_EventScript_LilithBrightenRoom
	msgbox DewfordTown_Gym_Text_LilithPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_LilithBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_AZALEA_TOWN_GYM, DewfordTown_Gym_EventScript_GymGuidePostVictory
	msgbox DewfordTown_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_GymGuidePostVictory::
	msgbox DewfordTown_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
	goto DewfordTown_Gym_EventScript_GymStatue
	end

DewfordTown_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
	goto DewfordTown_Gym_EventScript_GymStatue
	end

DewfordTown_Gym_EventScript_GymStatueCertified::
	msgbox DewfordTown_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Gym_EventScript_GymStatue::
	msgbox DewfordTown_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Gym_Text_GymGuideAdvice:
	.string "Hé, comment ça va, futur CHAMPION\n"
	.string "{PLAYER} ?\p"
	.string "BRAWLY, le CHAMPION d'ARÈNE d'ALGATIA,\n"
	.string "utilise des POKéMON de type COMBAT.\p"
	.string "L'affronter avec des POKéMON de type\n"
	.string "NORMAL, c'est chercher les ennuis.\p"
	.string "Les POKéMON COMBAT vont sévèrement\n"
	.string "frapper les POKéMON NORMAL,\l"
	.string "alors fais attention !\p"
	.string "Pire encore, l'ARÈNE est sombre comme\n"
	.string "le fond de l'océan.\p"
	.string "Mais ça s'éclaircira après avoir battu\n"
	.string "les DRESSEURS sur ton chemin.\p"
	.string "Allez, vas-y !$"

DewfordTown_Gym_Text_GymGuidePostVictory:
	.string "Ouah ! C'est devenu trop lumineux ici !\p"
	.string "Ton avenir est lumineux aussi !$"

DewfordTown_Gym_Text_TakaoIntro:
	.string "La force prime !\n"
	.string "Allez !$"

DewfordTown_Gym_Text_TakaoDefeat:
	.string "Pas assez de puissance…$"

DewfordTown_Gym_Text_TakaoPostBattle:
	.string "Ta technique a surpassé ma force !\n"
	.string "Ta technique est remarquable !$"

DewfordTown_Gym_Text_JocelynIntro:
	.string "Pas besoin que BRAWLY\n"
	.string "s'en mêle !\p"
	.string "Je vais t'écraser !$"

DewfordTown_Gym_Text_JocelynDefeat:
	.string "Mais… Comment ?\n"
	.string "Comment ai-je pu perdre si facilement ?$"

DewfordTown_Gym_Text_JocelynPostBattle:
	.string "Je ne vais pas gâcher cette défaite.\n"
	.string "Je vais m'en servir pour m'entraîner !\p"
	.string "Un jour je deviendrai CHAMPION D'ARENE…\p"
	.string "Non, je deviendrai le CHAMPION\n"
	.string "de la LIGUE POKéMON !$"

DewfordTown_Gym_Text_LauraIntro:
	.string "Ne me repousse pas comme ça !\n"
	.string "Ce n'est pas ma faute si tu pleures !$"

DewfordTown_Gym_Text_LauraDefeat:
	.string "Waaaaaaah !\n"
	.string "J'ai perdu !$"

DewfordTown_Gym_Text_LauraPostBattle:
	.string "Je me bats dans le noir pour rendre\n"
	.string "mon coeur plus fort.\p"
	.string "Mais comme c'est si sombre, je ne vois\n"
	.string "jamais le visage de BRAWLY...$"

DewfordTown_Gym_Text_LilithIntro:
	.string "Ufufu…\n"
	.string "Tu tournes en rond dans le noir ?$"

DewfordTown_Gym_Text_LilithDefeat:
	.string "Oh, toi…\n"
	.string "Je ne veux pas te connaître !$"

DewfordTown_Gym_Text_LilithPostBattle:
	.string "Tu mérites de rester perdu et de\n"
	.string "revenir à l'entrée !$"

DewfordTown_Gym_Text_BrendenIntro:
	.string "Je vais te montrer le courage\n"
	.string "d'un marin !$"

DewfordTown_Gym_Text_BrendenDefeat:
	.string "Comment c'est arrivé ?\n"
	.string "Ce n'est pas mon genre de perdre comme ça !$"

DewfordTown_Gym_Text_BrendenPostBattle:
	.string "Oh, oui ! Tu mérites de voir\n"
	.string "notre CHAMPION D'ARÈNE.$"

DewfordTown_Gym_Text_CristianIntro:
	.string "Si tu veux passer, ce sera\n"
	.string "par moi !$"

DewfordTown_Gym_Text_CristianDefeat:
	.string "Grrrrr !\n"
	.string "Largement surpassé !$"

DewfordTown_Gym_Text_CristianPostBattle:
	.string "Tu as gagné !\n"
	.string "Va chercher ce BADGE !$"

DewfordTown_Gym_Text_BrawlyIntro:
	.string "Je suis BRAWLY ! Le\n"
	.string "CHAMPION d'ARÈNE d'ALGATIA ! J'ai\p"
	.string "été façonné par les vagues\n"
	.string "violentes de ces parages,\l"
	.string "et je ne fais\p"
	.string "qu'un avec elles !\n"
	.string "Montre-moi ta force !$"

DewfordTown_Gym_Text_BrawlyDefeat:
	.string "Waouh, wow ! Tu as fait\n"
	.string "une plus grosse splash que je\p"
	.string "ne l'attendais ! Tu m'as submergé\p"
	.string "! OK, tu m'as eu.\n"
	.string "Prends ce BADGE D'ARÈNE !$"

DewfordTown_Gym_Text_ReceivedKnuckleBadge:
	.string "{PLAYER} a reçu le BADGE POING\n"
	.string "de BRAWLY.$"

DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis:
	.string "Le BADGE POING rend tous\n"
	.string "les POKéMON jusqu'au Niveau 30,\l"
	.string "même ceux obtenus par échange,\p"
	.string "obéissants sans question. Et tu\n"
	.string "pourras utiliser la CS FLASH\p"
	.string "hors combat. Si tu veux,\n"
	.string "prends aussi cette MACHINE TECHNIQUE.$"

DewfordTown_Gym_Text_ExplainBulkUp:
	.string "Cette CT08 contient GONFLETTE.\p"
	.string "C'est une attaque qui augmente l'ATTAQUE\n"
	.string "et la DÉFENSE.\p"
	.string "... ... ... ... ... ...$"

DewfordTown_Gym_Text_RegisteredBrawly:
	.string "CHAMPION D'ARÈNE BASTIEN\n"
	.string "enregistré dans le POKéNAV.$"

DewfordTown_Gym_Text_BrawlyPostBattle:
	.string "Je vois ton talent devenir une vague géante\n"
	.string "pour provoquer une tempête d'étonnement\l"
	.string "parmi les DRESSEURS un jour !$"

DewfordTown_Gym_Text_GymStatue:
	.string "ALGATIA ARENE POKéMON$"

DewfordTown_Gym_Text_GymStatueCertified:
	.string "ALGATIA ARENE POKéMON\p"
	.string "DRESSEURS CERTIFIÉS DE BRAWLY :\n"
	.string "{PLAYER}$"

DewfordTown_Gym_Text_BrawlyPreRematch:
	.string "BALTO : Une vague peut reculer, mais elle\n"
	.string "revient toujours sur le rivage.\p"
	.string "Une vague de talent géante comme toi…\n"
	.string "Je savais que tu reviendrais !\p"
	.string "Montre-moi jusqu'où\n"
	.string "tu es monté !$"

DewfordTown_Gym_Text_BrawlyRematchDefeat:
	.string "Ouah !\n"
	.string "Submergé encore !$"

DewfordTown_Gym_Text_BrawlyPostRematch:
	.string "BRAWLY : Le combat est vaste et profond.\n"
	.string "On n'en voit pas le fond.\l"
	.string "C'est comme la mer de HOENN !$"

DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons:
	.string "BRAWLY : Une vague peut reculer,\n"
	.string "mais elle revient toujours sur le\p"
	.string "rivage.\n"
	.string "Une vague de talent comme toi…\p"
	.string "Je savais que tu reviendrais !\n"
	.string "Oh ? Tu n'as qu'un seul POKéMON\p"
	.string "qui peut combattre.\n"
	.string "Désolé, mais j'aimerais que tu reviennes avec au moins deux POKéMON.$"
