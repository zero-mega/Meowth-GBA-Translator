.set LOCALID_GRUNT, 3
.set LOCALID_DEVON_EMPLOYEE, 4
.set LOCALID_CELEBI, 17
.set LOCALID_OLD_MAN, 15
.set LOCALID_DUSCLOPS, 16

PetalburgWoods_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, PetalburgWoods_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

PetalburgWoods_OnTransition::
	callnative SetTimeBasedEncounters
	goto_if_unset FLAG_EXTRA_LEGENDARIES, PetalburgWoods_SwitchToOld
	call_if_unset FLAG_SYS_GAME_CLEAR, PetalburgWoods_NoCelebiEvent
	call_if_set FLAG_SYS_GAME_CLEAR, PetalburgWoods_YesCelebiEvent
	end

PetalburgWoods_SwitchToOld::
	setmaplayoutindex LAYOUT_PETALBURG_WOODS_OLD
	setflag FLAG_OLD_MAN_AND_DUSCLOPS
	removeobject LOCALID_OLD_MAN
	removeobject LOCALID_DUSCLOPS
	return
	end

PetalburgWoods_NoCelebiEvent::
	checkflag FLAG_GARBAGEFLAG
	call_if_unset FLAG_GARBAGEFLAG, PetalburgWoods_CelebiEvent_End
	end

PetalburgWoods_YesCelebiEvent::
	checkflag FLAG_DEFEATEDCELEBI
	call_if_set FLAG_DEFEATEDCELEBI, PetalburgWoods_CelebiEvent_End
	call_if_unset FLAG_DEFEATEDCELEBI, PetalburgWoods_YesCelebiEvent2
	end

PetalburgWoods_YesCelebiEvent2::
	setflag FLAG_GARBAGEFLAG
	end

PetalburgWoods_CelebiEvent::
	lock
	playse SE_SUDOWOODO_SHAKE
	waitse
	msgbox Text_PetalburgWoods_Celebi0, MSGBOX_SIGN
	closemessage
	checkflag FLAG_GARBAGEFLAG
	call_if_unset FLAG_GARBAGEFLAG, PetalburgWoods_CelebiEvent_End
	call_if_set FLAG_GARBAGEFLAG, PetalburgWoods_CelebiEventGo
	end

PetalburgWoods_CelebiEventGo::
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PetalburgWoods_Celebi1
	waitmovement 0
	msgbox Text_PetalburgWoods_Celebi1, MSGBOX_SIGN
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, PetalburgWoods_CelebiEvent_End
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_RAIKOU, PetalburgWoods_CelebiEvent_Continue1
	msgbox Text_PetalburgWoods_Celebi_Donthave, MSGBOX_SIGN
	end

PetalburgWoods_CelebiEvent_Continue1::
	msgbox Text_PetalburgWoods_Celebi2, MSGBOX_SIGN
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, PetalburgWoods_CelebiEvent_End
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_ENTEI, PetalburgWoods_CelebiEvent_Continue2
	msgbox Text_PetalburgWoods_Celebi_Donthave, MSGBOX_SIGN
	end

PetalburgWoods_CelebiEvent_Continue2::
	msgbox Text_PetalburgWoods_Celebi3, MSGBOX_SIGN
	special ChoosePartyMon
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, PetalburgWoods_CelebiEvent_End
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_SUICUNE, PetalburgWoods_CelebiBattle
	msgbox Text_PetalburgWoods_Celebi_Donthave, MSGBOX_SIGN
	end

PetalburgWoods_CelebiEvent_End::
	releaseall
	end

PetalburgWoods_CelebiBattle::
	faceplayer
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Movement_PetalburgWoods_Celebi1
	waitmovement 0
	msgbox Text_PetalburgWoods_Celebi4, MSGBOX_DEFAULT
	setwildbattle SPECIES_CELEBI, 50
	waitse
	playmoncry SPECIES_CELEBI, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	applymovement LOCALID_CELEBI, PetalburgWoods_EventScript_CelebiMoves
	waitmovement 0
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, PetalburgWoods_CelebiEvent_Won
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, PetalburgWoods_CelebiEvent_Won
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, PetalburgWoods_CelebiEvent_Ran
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, PetalburgWoods_CelebiEvent_Ran
	releaseall
	end

PetalburgWoods_CelebiEvent_Won::
	applymovement LOCALID_CELEBI, PetalburgWoods_EventScript_CelebiMoves2
	waitmovement 0
	setflag FLAG_DEFEATEDCELEBI
	clearflag FLAG_GARBAGEFLAG
	end

PetalburgWoods_CelebiEvent_Ran::
	applymovement LOCALID_CELEBI, PetalburgWoods_EventScript_CelebiMoves2
	waitmovement 0
	end

PetalburgWoods_EventScript_CelebiMoves:
	delay_16
	delay_16
	delay_16
	walk_down
	set_visible
	step_end

PetalburgWoods_EventScript_CelebiMoves2:
	set_invisible
	walk_up
	step_end

Text_PetalburgWoods_Celebi0:
	.string "L'arbre tremble. Tu sens aussi\p"
	.string "que quelqu'un ou quelque\n"
	.string "chose t'observe… Mais… tu\p"
	.string "ne vois aucun POKéMON…$"

Text_PetalburgWoods_Celebi1:
	.string ". . . \p"
	.string ". . . \p"
	.string "On entend une voix faible.\p"
	.string "M..ntre-moi le POKéMON du TONN.RRE…\p"
	.string ". . . \p"
	.string "M..ntre-moi le POKéMON du TONN.RRE…$"

Text_PetalburgWoods_Celebi2:
	.string ". . . \p"
	.string ". . . \p"
	.string "Sh.. me .he .OLCANO . ..MON$"

Text_PetalburgWoods_Celebi3:
	.string ". . . \p"
	.string ". . . \p"
	.string "Mon..tre-m.. AU.RORA …éMON.$"

Text_PetalburgWoods_Celebi4:
	.string ". . . \p"
	.string "Quelque chose approche…\p"
	.string ". . . $"

Text_PetalburgWoods_Celebi_Donthave:
	.string ". . . \p"
	.string "..u n'.. p… s…\p"
	.string "Tu ne l'as pas…$"

Movement_PetalburgWoods_Celebi1:
	emote_exclamation_mark
	delay_16
	delay_16
	delay_16
	delay_16
	step_end

PetalburgWoods_Dusclops::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DUSCLOPS, CRY_MODE_NORMAL
	msgbox PetalburgWoods_Text_Dusclops, MSGBOX_DEFAULT
	waitmoncry
	release
	end

PetalburgWoods_Text_Dusclops:
	.string "DUSKY : Dusk, dusk !$"

PetalburgWoods_Celebi_Sign::
	faceplayer
	goto_if_unset FLAG_ROBERTO1, PetalburgWoods_Celebi_SignFirstTime
	goto_if_set FLAG_DEFEATEDCELEBI, PetalburgWoods_Celebi_SignEventFinished
	goto_if_set FLAG_SYS_GAME_CLEAR, PetalburgWoods_Celebi_SignChampion
	msgbox Text_PetalburgWoods_Celebi_Sign, MSGBOX_NPC
	end

PetalburgWoods_Celebi_SignFirstTime::
	faceplayer
	msgbox Text_PetalburgWoods_Celebi_SignFirstTime, MSGBOX_NPC
	setflag FLAG_ROBERTO1
	end

PetalburgWoods_Celebi_SignEventFinished::
	faceplayer
	msgbox Text_PetalburgWoods_Celebi_SignEventFinished, MSGBOX_NPC
	end

PetalburgWoods_Celebi_SignChampion::
	faceplayer
	msgbox Text_PetalburgWoods_Celebi_SignEventChampion, MSGBOX_NPC
	end

Text_PetalburgWoods_Celebi_Sign:
	.string "Salut, DRESSEUR. Dangereux ? Non,\p"
	.string "non. Ne t'inquiète pas.\l"
	.string "DUSKY patrouille aux alentours.\p"
	.string "Et toi ? Comment\n"
	.string "va ton aventure ?$"

Text_PetalburgWoods_Celebi_SignFirstTime:
	.string "Oh, un jeune…\p"
	.string "Que fais-tu ici dans ces\n"
	.string "bois sombres et ombragés ?\p"
	.string ". . .\p"
	.string "Oh, je vois. Tu ne fais que passer.\p"
	.string "Quoi ? Ah, moi ?\p"
	.string "J'arrose simplement l'arbre sacré\n"
	.string "comme je l'ai toujours fait.\p"
	.string "Ah, tu te demandes pourquoi j'arrose\n"
	.string "un arbre innocent au milieu\l"
	.string "des bois, n'est-ce pas ?\p"
	.string "Mais tu vois, cet arbre est spécial.\n"
	.string "Dans ces bois vit un POKéMON MYTHIQUE\l"
	.string "C'est le GARDIEN DE LA FORÊT.\p"
	.string "J'arrose cet arbre depuis\n"
	.string "plus de vingt ans de ma vie.\p"
	.string "Et je peux t'assurer que cette histoire\n"
	.string "est aussi vraie que l'air que nous respirons.\l"
	.string "Le GARDIEN DE LA FORÊT est petit, VERT\l"
	.string "et le simple fait de le regarder…\p"
	.string "C'est comme si je contemplais un esprit de la\n"
	.string "forêt. Hélas, la dernière fois que je l'ai vu\l"
	.string "c'était il y a de très, très nombreuses années…\p"
	.string "Où peut bien être le GARDIEN ?\p"
	.string "Peut-être dois-je être plus FORT pour le\n"
	.string "faire apparaître…\p"
	.string "Ça me rend vraiment triste de voir à quel point\n"
	.string "je suis devenu faible avec les années.\p"
	.string "Bref, je vais continuer mon œuvre.\n"
	.string "À bientôt, jeune homme.$"

Text_PetalburgWoods_Celebi_SignEventFinished:
	.string ". . . \p"
	.string "Je n'en crois vraiment pas mes yeux !\n"
	.string "Tu t'es battu contre le GARDIEN !?\p"
	.string "Je n'oublierai jamais ce moment.\n"
	.string "Je continuerai d'arroser ce sanctuaire\l"
	.string "jusqu'à ce qu'il revienne un jour.$"

Text_PetalburgWoods_Celebi_SignEventChampion:
	.string "Salut encore, jeune homme.\p"
	.string "Quelque chose se passe avec l'arbre\n"
	.string "du GARDIEN.\p"
	.string "J'entends un petit murmure autour depuis\n"
	.string "plusieurs heures.\p"
	.string "Quelque chose à propos de POKéMON FOUDRE,\n"
	.string "VOLCAN et AURORE…\p"
	.string "Attends… Je connais ces descriptions…\n"
	.string "Quelque chose à propos de trois bêtes ? Mais…\p"
	.string "Pas de cette région… ? D'où venaient-ils ?\n"
	.string "JOHTO ?\p"
	.string "Et s'ils sont ici, à HOENN…\n"
	.string "Peut-être se cachent-ils dans des endroits\l"
	.string "liés à leurs descriptions ?\p"
	.string "Si tu as le temps, peut-être pourrais-tu\n"
	.string "jeter un œil. Qu'en penses-tu ?$"

PetalburgWoods_EventScript_DevonResearcherLeft::
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaEntrance
	waitmovement 0
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherLeft
	waitmovement 0
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachPlayer
	waitmovement 0
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_TONY, PetalburgWoods_Text_YoureKiddingMe
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaBackOff
	waitmovement 0
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitLeft
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherRight::
	lockall
	call PetalburgWoods_EventScript_DevonResearcherIntro
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherApproachPlayerRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox PetalburgWoods_Text_HaveYouSeenShroomish, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_ENCOUNTER_AQUA, FALSE
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaEntrance
	waitmovement 0
	msgbox PetalburgWoods_Text_IWasGoingToAmbushYou, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaApproachResearcherRight
	waitmovement 0
	applymovement LOCALID_DEVON_EMPLOYEE, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_HandOverThosePapers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight
	waitmovement 0
	msgbox PetalburgWoods_Text_YouHaveToHelpMe, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox PetalburgWoods_Text_NoOneCrossesTeamAqua, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_TONY, PetalburgWoods_Text_YoureKiddingMe
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaBackOff
	waitmovement 0
	call PetalburgWoods_EventScript_DevonResearcherPostBattle
	applymovement OBJ_EVENT_ID_PLAYER, PetalburgWoods_Movement_WatchResearcherLeave
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherExitRight
	waitmovement 0
	goto PetalburgWoods_EventScript_RemoveDevonResearcher
	end

PetalburgWoods_EventScript_DevonResearcherIntro::
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherLookAround
	waitmovement 0
	msgbox PetalburgWoods_Text_NotAOneToBeFound, MSGBOX_DEFAULT
	closemessage
	return

PetalburgWoods_EventScript_DevonResearcherPostBattle::
	msgbox PetalburgWoods_Text_YouveGotSomeNerve, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_GRUNT, PetalburgWoods_Movement_AquaRunAway
	waitmovement 0
	removeobject LOCALID_GRUNT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox PetalburgWoods_Text_ThatWasAwfullyClose, MSGBOX_DEFAULT
	giveitem ITEM_GREAT_BALL
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_BagFull
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end

PetalburgWoods_EventScript_BagFull::
	msgbox PetalburgWoods_Text_YoureLoadedWithItems, MSGBOX_DEFAULT
	goto PetalburgWoods_EventScript_DevonResearcherFinish
	end

PetalburgWoods_EventScript_DevonResearcherFinish::
	msgbox PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro, MSGBOX_DEFAULT
	applymovement LOCALID_DEVON_EMPLOYEE, PetalburgWoods_Movement_DevonResearcherStartExit
	waitmovement 0
	msgbox PetalburgWoods_Text_ICantBeWastingTime, MSGBOX_DEFAULT
	closemessage
	return

PetalburgWoods_EventScript_RemoveDevonResearcher::
	removeobject LOCALID_DEVON_EMPLOYEE
	setvar VAR_GARBAGEVAR, 1
	releaseall
	end

PetalburgWoods_Movement_DevonResearcherLookAround:
	face_up
	delay_16
	delay_4
	face_right
	delay_16
	delay_8
	face_left
	delay_16
	delay_8
	face_down
	delay_16
	face_right
	delay_16
	delay_8
	face_up
	delay_16
	step_end

PetalburgWoods_Movement_DevonResearcherExitLeft:
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerLeft:
	delay_16
	face_player
	walk_down
	walk_down
	step_end

PetalburgWoods_Movement_DevonResearcherApproachPlayerRight:
	delay_16
	face_player
	walk_down
	walk_down
	walk_down
	walk_in_place_faster_right
	step_end

PetalburgWoods_Movement_DevonResearcherExitRight:
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

PetalburgWoods_Movement_WatchResearcherLeave:
	delay_16
	delay_16
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerLeft:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherFleeToPlayerRight:
	walk_fast_down
	walk_fast_right
	walk_in_place_faster_up
	step_end

PetalburgWoods_Movement_DevonResearcherStartExit:
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	face_up
	step_end

PetalburgWoods_Movement_AquaApproachResearcherLeft:
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaBackOff:
	lock_facing_direction
	walk_up
	unlock_facing_direction
	step_end

PetalburgWoods_Movement_AquaRunAway:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachResearcherRight:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

PetalburgWoods_Movement_AquaEntrance:
	walk_down
	walk_down
	delay_16
	delay_16
	step_end

PetalburgWoods_Movement_AquaApproachPlayer:
	walk_down
	step_end

PetalburgWoods_EventScript_Boy1::
	msgbox PetalburgWoods_Text_StayOutOfTallGrass, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Boy2::
	msgbox PetalburgWoods_Text_HiddenItemsExplanation, MSGBOX_NPC
	end

PetalburgWoods_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_MIRACLE_SEED, PetalburgWoods_EventScript_ExplainMiracleSeed
	msgbox PetalburgWoods_Text_TryUsingThisItem, MSGBOX_DEFAULT
	giveitem ITEM_MIRACLE_SEED
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_MIRACLE_SEED
	release
	end

PetalburgWoods_EventScript_ExplainMiracleSeed::
	msgbox PetalburgWoods_Text_MiracleSeedExplanation, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_Sign1::
	msgbox PetalburgWoods_Text_TrainerTipsExperience, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Sign2::
	msgbox PetalburgWoods_Text_TrainerTipsPP, MSGBOX_SIGN
	end

PetalburgWoods_EventScript_Lyle::
	trainerbattle_single TRAINER_LYLE, PetalburgWoods_Text_GoBugPokemonTeam, PetalburgWoods_Text_ICouldntWin
	msgbox PetalburgWoods_Text_ImOutOfPokeBalls, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_EventScript_James::
	trainerbattle_single TRAINER_RIVAL_CYNDAQUIL_4, PetalburgWoods_Text_InstantlyPopularWithBugPokemon, PetalburgWoods_Text_CantBePopularIfILose, PetalburgWoods_EventScript_TryRegisterJames
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, PetalburgWoods_EventScript_JamesRematch
	setvar VAR_0x8004, TRAINER_RIVAL_CYNDAQUIL_4
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, FALSE, PetalburgWoods_EventScript_TryRegisterJames2
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_TryRegisterJames::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames
	release
	end

PetalburgWoods_EventScript_RegisterJames::
	msgbox PetalburgWoods_Text_IWantRematch1, MSGBOX_DEFAULT
	register_matchcall TRAINER_RIVAL_CYNDAQUIL_4
	release
	end

PetalburgWoods_EventScript_TryRegisterJames2::
	goto_if_set FLAG_HAS_MATCH_CALL, PetalburgWoods_EventScript_RegisterJames2
	msgbox PetalburgWoods_Text_PeopleRespectYou, MSGBOX_DEFAULT
	release
	end

PetalburgWoods_EventScript_RegisterJames2::
	msgbox PetalburgWoods_Text_IWantRematch2, MSGBOX_DEFAULT
	register_matchcall TRAINER_RIVAL_CYNDAQUIL_4
	release
	end

PetalburgWoods_EventScript_JamesRematch::
	trainerbattle_rematch TRAINER_RIVAL_CYNDAQUIL_4, PetalburgWoods_Text_MyPokemonHaveGrown, PetalburgWoods_Text_CantBePopularIfLose
	msgbox PetalburgWoods_Text_IveBeenTrainingHard, MSGBOX_AUTOCLOSE
	end

PetalburgWoods_Text_NotAOneToBeFound:
	.string "Hmmm…\n"
	.string "Pas une seule à trouver…$"

PetalburgWoods_Text_HaveYouSeenShroomish:
	.string "Bonjour, as-tu vu des POKéMON\n"
	.string "appelés BALIGNON par ici ?\p"
	.string "J'adore ce POKéMON.$"

PetalburgWoods_Text_IWasGoingToAmbushYou:
	.string "J'allais te tendre une embuscade, mais tu\n"
	.string "as traîné dans le BOIS PETALBURG\l"
	.string "une éternité, n'est-ce pas ?\p"
	.string "J'en ai eu marre d'attendre, alors me voilà !$"

PetalburgWoods_Text_HandOverThosePapers:
	.string "Toi ! CHERCHEUR DEVON !\p"
	.string "Donne-moi ces documents !$"

PetalburgWoods_Text_YouHaveToHelpMe:
	.string "Aiyeeeh !\p"
	.string "Tu es un DRESSEUR POKéMON, n'est-ce pas ?\n"
	.string "Tu dois m'aider, s'il te plaît !$"

PetalburgWoods_Text_NoOneCrossesTeamAqua:
	.string "Hein ? Qu'est-ce que tu fais ?\n"
	.string "Quoi, tu vas le protéger ?\p"
	.string "Personne qui s'oppose à la TEAM AQUA\n"
	.string "n'aura pitié, même pas un gamin !\p"
	.string "Viens te battre contre moi !$"

PetalburgWoods_Text_YoureKiddingMe:
	.string "Tu plaisantes ! Tu es fort !$"

PetalburgWoods_Text_YouveGotSomeNerve:
	.string "Grrr… Tu as du culot de\n"
	.string "s'immiscer dans les affaires de la\l"
	.string "TEAM AQUA ! Viens te battre\p"
	.string "encore ! J'aimerais bien dire ça,\n"
	.string "mais je n'ai plus de POKéMON…\p"
	.string "Et nous de la TEAM AQUA\n"
	.string "cherchons aussi quelque chose à MÉROUVILLE.\p"
	.string "Je te laisse partir aujourd'hui !$"

PetalburgWoods_Text_ThatWasAwfullyClose:
	.string "Ouf…\n"
	.string "C'était moins une !\p"
	.string "Grâce à toi, il ne m'a pas volé\n"
	.string "ces papiers importants.\p"
	.string "Je sais, je te donne une SUPER BALL\n"
	.string "en remerciement !$"

PetalburgWoods_Text_TeamAquaAfterSomethingInRustboro:
	.string "Ce SBIRE de la TEAM AQUA n'a-t-il pas dit\n"
	.string "qu'ils cherchaient quelque chose à\l"
	.string "MEROUVILLE aussi ?$"

PetalburgWoods_Text_ICantBeWastingTime:
	.string "Oh-oh ! C'est la crise !\n"
	.string "Je n'ai pas le temps de perdre !$"

PetalburgWoods_Text_YoureLoadedWithItems:
	.string "Tu es chargé d'objets.\n"
	.string "Je ne peux pas te donner cette SUPER BALL.$"

PetalburgWoods_Text_GoBugPokemonTeam:
	.string "J'ai attrapé plein de POKéMON !\p"
	.string "Allez, allez, allez !\n"
	.string "Mon équipe de POKéMON INSECTE !$"

PetalburgWoods_Text_ICouldntWin:
	.string "J'ai plein de POKéMON,\n"
	.string "mais je n'ai pas gagné…$"

PetalburgWoods_Text_ImOutOfPokeBalls:
	.string "J'ai attrapé plein de POKéMON.\n"
	.string "Je n'ai plus de POKé BALLS.$"

PetalburgWoods_Text_InstantlyPopularWithBugPokemon:
	.string "Si tu emmènes des POKéMON INSECTE à l'école,\n"
	.string "tu deviens instantanément populaire !$"

PetalburgWoods_Text_CantBePopularIfILose:
	.string "Je ne peux pas être populaire si je perds.$"

PetalburgWoods_Text_PeopleRespectYou:
	.string "Si tu as un gros POKéMON INSECTE,\n"
	.string "les gens te respectent pour ça.$"

PetalburgWoods_Text_IWantRematch1:
	.string "Je veux une revanche quand mes POKéMON\n"
	.string "INSECTE auront grandi !\p"
	.string "Je t'enregistre dans mon POKéNAV !$"

PetalburgWoods_Text_IWantRematch2:
	.string "Je veux une revanche quand mes POKéMON\n"
	.string "INSECTE auront grandi !\p"
	.string "Je t'enregistre dans mon POKéNAV !$"

PetalburgWoods_Text_MyPokemonHaveGrown:
	.string "Mes POKéMON INSECTE ont grandi.\n"
	.string "Je serai à nouveau populaire.$"

PetalburgWoods_Text_CantBePopularIfLose:
	.string "Je ne peux pas être populaire si je perds.$"

PetalburgWoods_Text_IveBeenTrainingHard:
	.string "On devient populaire si on a\n"
	.string "des POKéMON forts, non ?\l"
	.string "Alors je m'entraîne dur.$"

PetalburgWoods_Text_StayOutOfTallGrass:
	.string "Yo, toi !\n"
	.string "Tes POKéMON vont bien ?\p"
	.string "Si tes POKéMON sont faibles et que tu veux\n"
	.string "éviter les combats, reste loin\l"
	.string "des hautes herbes.$"

PetalburgWoods_Text_HiddenItemsExplanation:
	.string "Parfois, il y a des choses\n"
	.string "au sol même si on ne\p"
	.string "les voit pas. C'est pourquoi je\n"
	.string "vérifie toujours où je marche.$"

PetalburgWoods_Text_TryUsingThisItem:
	.string "Oh, super !\n"
	.string "C'est le BADGE de l'ARÈNE de MÉROUVILLE !\p"
	.string "Tu dois être DRESSEUR.\n"
	.string "Tu devrais essayer cet objet.$"

PetalburgWoods_Text_MiracleSeedExplanation:
	.string "C'est une GRAIN MIRACLE.\n"
	.string "Si un POKéMON tient cet objet, ses\l"
	.string "attaques de type PLANTE deviennent plus fortes.\p"
	.string "Outre la GRAIN MIRACLE, je pense qu'il y a\n"
	.string "d'autres objets pratiques que les POKéMON\l"
	.string "peuvent tenir.$"

PetalburgWoods_Text_TrainerTipsExperience:
	.string "CONSEILS DRESSEUR\p"
	.string "Tout POKéMON qui apparaît\n"
	.string "ne serait-ce qu'une fois\p"
	.string "dans un combat reçoit\n"
	.string "des Points d'Exp.\p"
	.string "Pour élever un POKéMON faible,\n"
	.string "fais-le participer\l"
	.string "aux combats !$"

PetalburgWoods_Text_TrainerTipsPP:
	.string "CONSEILS DRESSEUR En plus des Points de\p"
	.string "Vie (PV), les POKéMON ont des\n"
	.string "Points de Pouvoir (PP) utilisés pour\l"
	.string "lancer des capacités au combat. Si\p"
	.string "un POKéMON n'a plus de PP,\n"
	.string "il faut l'emmener au CENTRE POKéMON.$"

