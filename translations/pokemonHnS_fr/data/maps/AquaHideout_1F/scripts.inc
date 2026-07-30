AquaHideout_1F_MapScripts::
	.byte 0

@ The below two entrance guards give hints about what to do to progress the story
AquaHideout_1F_EventScript_HideoutEntranceGrunt1::
	lock
	faceplayer
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_SlateportHint1
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_MagmaHideoutHint1
	msgbox AquaHideout_1F_Text_OurBossIsSnatchingSomething, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_MagmaHideoutHint1::
	msgbox AquaHideout_1F_Text_WhereMightMagmaHideoutBe, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_SlateportHint1::
	msgbox AquaHideout_1F_Text_BossWentToJackASubmarine, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_HideoutEntranceGrunt2::
	lock
	faceplayer
	goto_if_set FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT, AquaHideout_1F_EventScript_SlateportHint2
	goto_if_set FLAG_RECEIVED_RED_OR_BLUE_ORB, AquaHideout_1F_EventScript_MagmaHideoutHint2
	msgbox AquaHideout_1F_Text_BossIsOnRoute122, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_MagmaHideoutHint2::
	msgbox AquaHideout_1F_Text_TeamMagmaAtMtChimney, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_SlateportHint2::
	msgbox AquaHideout_1F_Text_BossIsInSlateportCity, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_EventScript_Grunt1::
	trainerbattle_single TRAINER_SAYO, AquaHideout_1F_Text_Grunt1Intro, AquaHideout_1F_Text_Grunt1Defeat, AquaHideout_1F_EventScript_Grunt1Defeated
	msgbox AquaHideout_1F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_1F_EventScript_Grunt1Defeated::
	msgbox AquaHideout_1F_Text_Grunt1PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_1F_Text_OurBossIsSnatchingSomething:
	.string "Quoi ? Quoi ?\n"
	.string "Que veux-tu de la\p"
	.string "TEAM AQUA ? Notre\n"
	.string "BOSS n'est pas là\p"
	.string "! Il est parti\n"
	.string "voler quelque chose d'important\p"
	.string "! … … …\n"
	.string "… … …$"

AquaHideout_1F_Text_WhereMightMagmaHideoutBe:
	.string "Quoi ? Quoi ?\n"
	.string "Tu es un sbire de la TEAM MAGMA ?\p"
	.string "J'ai entendu dire que la TEAM MAGMA essaie\n"
	.string "d'éveiller un POKéMON formidable dans leur\l"
	.string "REPAIRE.\p"
	.string "Mais où se trouve leur REPAIRE ?$"

AquaHideout_1F_Text_BossWentToJackASubmarine:
	.string "Quoi ? Quoi ? Que veux-tu\n"
	.string "de la TEAM AQUA ? Notre\p"
	.string "BOSS n'est pas là ! Il\n"
	.string "est parti voler un sous-marin !\p"
	.string "… … Où est-il allé ?\n"
	.string "Wahaha ! Tu crois vraiment\p"
	.string "que je vais te dire\n"
	.string "quelque chose d'aussi crucial ?$"

AquaHideout_1F_Text_BossIsOnRoute122:
	.string "Quoi ? Quoi ?\n"
	.string "Que veux-tu de la\p"
	.string "TEAM AQUA ? Notre\n"
	.string "BOSS n'est pas là\p"
	.string "! Il est en\n"
	.string "route vers le MONT\p"
	.string "CHIMNÉE ! … …\n"
	.string "… … … …$"

AquaHideout_1F_Text_TeamMagmaAtMtChimney:
	.string "Quoi ? Quoi ?\n"
	.string "Tu es un sbire de la TEAM MAGMA ?\p"
	.string "J'ai entendu dire que la TEAM MAGMA\n"
	.string "cherche un POKéMON formidable au MONT CHIMNÉE.\p"
	.string "Mais à quoi ressemble ce POKéMON ?$"

AquaHideout_1F_Text_BossIsInSlateportCity:
	.string "Quoi ? Quoi ? Que veux-tu\n"
	.string "de la TEAM AQUA ? Notre\p"
	.string "BOSS n'est pas là ! Il\n"
	.string "est en route vers POIVRESSE !\p"
	.string "… … Pourquoi est-il parti ?\n"
	.string "Wahaha ! Tu crois vraiment\p"
	.string "que je vais te dire\n"
	.string "quelque chose d'aussi crucial ?$"

AquaHideout_1F_Text_Grunt1Intro:
	.string "Ayiyiyi !\n"
	.string "Personnage suspect repéré !$"

AquaHideout_1F_Text_Grunt1Defeat:
	.string "Grrrrr…\n"
	.string "J'ai perdu !$"

AquaHideout_1F_Text_Grunt1PostBattle:
	.string "J'ai pris la défaite pour l'ÉQUIPE,\n"
	.string "mais j'ai fait mon travail…$"

