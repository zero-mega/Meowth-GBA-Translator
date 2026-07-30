AquaHideout_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, AquaHideout_B1F_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, AquaHideout_B1F_OnTransition
	.byte 0

AquaHideout_B1F_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, AquaHideout_B1F_EventScript_TryRemoveElectrode
	end

AquaHideout_B1F_EventScript_TryRemoveElectrode::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return

AquaHideout_B1F_OnTransition:
	call_if_unset FLAG_DEFEATED_ELECTRODE_1_AQUA_HIDEOUT, AquaHideout_B1F_EventScript_ShowElectrode1
	call_if_unset FLAG_DEFEATED_ELECTRODE_2_AQUA_HIDEOUT, AquaHideout_B1F_EventScript_ShowElectrode2
	end

AquaHideout_B1F_EventScript_ShowElectrode1::
	clearflag FLAG_GARBAGEFLAG
	return

AquaHideout_B1F_EventScript_ShowElectrode2::
	clearflag FLAG_GARBAGEFLAG
	return

AquaHideout_B1F_EventScript_Electrode1::
	lock
	faceplayer
	setwildbattle SPECIES_ELECTRODE, 30
	waitse
	playmoncry SPECIES_ELECTRODE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, AquaHideout_B1F_EventScript_DefeatedElectrode1
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, AquaHideout_B1F_EventScript_DefeatedElectrode1
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, AquaHideout_B1F_EventScript_DefeatedElectrode1
	setflag FLAG_DEFEATED_ELECTRODE_1_AQUA_HIDEOUT
	release
	end

AquaHideout_B1F_EventScript_DefeatedElectrode1::
	setflag FLAG_DEFEATED_ELECTRODE_1_AQUA_HIDEOUT
	goto Common_EventScript_RemoveStaticPokemon
	end

AquaHideout_B1F_EventScript_Electrode2::
	lock
	faceplayer
	setwildbattle SPECIES_ELECTRODE, 30
	waitse
	playmoncry SPECIES_ELECTRODE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	dowildbattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, AquaHideout_B1F_EventScript_DefeatedElectrode2
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, AquaHideout_B1F_EventScript_DefeatedElectrode2
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, AquaHideout_B1F_EventScript_DefeatedElectrode2
	setflag FLAG_DEFEATED_ELECTRODE_2_AQUA_HIDEOUT
	release
	end

AquaHideout_B1F_EventScript_DefeatedElectrode2::
	setflag FLAG_DEFEATED_ELECTRODE_2_AQUA_HIDEOUT
	goto Common_EventScript_RemoveStaticPokemon
	end

AquaHideout_B1F_EventScript_Grunt2::
	trainerbattle_single TRAINER_SCOTT, AquaHideout_B1F_Text_Grunt2Intro, AquaHideout_B1F_Text_Grunt2Defeat, AquaHideout_B1F_EventScript_Grunt2Defeated
	msgbox AquaHideout_B1F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B1F_EventScript_Grunt2Defeated::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox AquaHideout_B1F_Text_Grunt2PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B1F_EventScript_Grunt3::
	trainerbattle_single TRAINER_SEAN, AquaHideout_B1F_Text_Grunt3Intro, AquaHideout_B1F_Text_Grunt3Defeat, AquaHideout_B1F_EventScript_Grunt3Defeated
	msgbox AquaHideout_B1F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B1F_EventScript_Grunt3Defeated::
	msgbox AquaHideout_B1F_Text_Grunt3PostBattle, MSGBOX_DEFAULT
	release
	end

AquaHideout_B1F_EventScript_Grunt5::
	trainerbattle_single TRAINER_SID, AquaHideout_B1F_Text_Grunt5Intro, AquaHideout_B1F_Text_Grunt5Defeat
	msgbox AquaHideout_B1F_Text_Grunt5PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B1F_EventScript_Grunt7::
	trainerbattle_single TRAINER_STEPHEN, AquaHideout_B1F_Text_Grunt7Intro, AquaHideout_B1F_Text_Grunt7Defeat
	msgbox AquaHideout_B1F_Text_Grunt7PostBattle, MSGBOX_AUTOCLOSE
	end

AquaHideout_B1F_Text_Grunt2Intro:
	.string "Si tu veux connaître le secret de notre\n"
	.string "PLANQUE, il faut d'abord me battre !$"

AquaHideout_B1F_Text_Grunt2Defeat:
	.string "Je ne peux pas gagner du tout…$"

AquaHideout_B1F_Text_Grunt2PostBattle:
	.string "Le secret de notre REPAIRE ?\p"
	.string "Eh bien, disons que...\n"
	.string "Il y a un sous-marin au fond !\p"
	.string "Mais maintenant...\n"
	.string "Héhéhéhé...$"

AquaHideout_B1F_Text_Grunt3Intro:
	.string "Carburant chargé, RAS !\n"
	.string "Collations de croisière chargées, RAS !\p"
	.string "Il ne reste plus qu'à éliminer\n"
	.string "un fâcheux intrus !$"

AquaHideout_B1F_Text_Grunt3Defeat:
	.string "J'ai pris une sacrée raclée !$"

AquaHideout_B1F_Text_Grunt3PostBattle:
	.string "Humph !\n"
	.string "C'était censé arriver !\p"
	.string "Ma mission était juste de te retenir !$"

AquaHideout_B1F_Text_Grunt5Intro:
	.string "Bâillement… Garder la PLANQUE m'ennuie.\n"
	.string "Je vais t'affronter.$"

AquaHideout_B1F_Text_Grunt5Defeat:
	.string "Bâillement…\n"
	.string "Oh, j'ai perdu…$"

AquaHideout_B1F_Text_Grunt5PostBattle:
	.string "Si tu te précipites trop, d'autres membres\n"
	.string "de la TEAM AQUA pourraient t'attraper.$"

AquaHideout_B1F_Text_Grunt7Intro:
	.string "Hé !\n"
	.string "Toi là !\p"
	.string "Lequel tu trouves plus cool ?\n"
	.string "L'uniforme de la TEAM AQUA ou de la TEAM MAGMA ?$"

AquaHideout_B1F_Text_Grunt7Defeat:
	.string "J'ai perdu de façon cool…$"

AquaHideout_B1F_Text_Grunt7PostBattle:
	.string "Si tu as une belle tenue, tu as l'air bien\n"
	.string "même en perdant, tu ne trouves pas ?$"
