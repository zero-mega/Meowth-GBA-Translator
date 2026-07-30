.set LOCALID_WOMAN_1, 19
.set LOCALID_MAN_1, 20

LilycoveCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LilycoveCity_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, LilycoveCity_OnLoad
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

LilycoveCity_OnTransition:
	callnative SetTimeBasedEncounters
	setflag FLAG_VISITED_SAFFRON_CITY
	setvar VAR_CONTEST_HALL_STATE, 0
	setflag FLAG_GARBAGEFLAG
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	call Common_EventScript_SetupRivalGfxId
	end

LilycoveCity_OnLoad:
	call_if_unset FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_SetWailmerMetatiles
	end

LilycoveCity_EventScript_SetWailmerMetatiles::
	setmetatile 76, 12, METATILE_Lilycove_Wailmer0, TRUE
	setmetatile 77, 12, METATILE_Lilycove_Wailmer1, TRUE
	setmetatile 76, 13, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 77, 13, METATILE_Lilycove_Wailmer3, TRUE
	setmetatile 76, 14, METATILE_Lilycove_Wailmer0_Alt, TRUE
	setmetatile 77, 14, METATILE_Lilycove_Wailmer1_Alt, TRUE
	setmetatile 76, 15, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 77, 15, METATILE_Lilycove_Wailmer3, TRUE
	setmetatile 77, 16, METATILE_Lilycove_Wailmer0_Alt, TRUE
	setmetatile 78, 16, METATILE_Lilycove_Wailmer1_Alt, TRUE
	setmetatile 77, 17, METATILE_Lilycove_Wailmer2, TRUE
	setmetatile 78, 17, METATILE_Lilycove_Wailmer3, TRUE
	return

LilycoveCity_EventScript_BerryGentleman::
	lock
	faceplayer
	dotimebasedevents
	goto_if_set FLAG_DAILY_LILYCOVE_RECEIVED_BERRY, LilycoveCity_EventScript_ReceivedBerry
	msgbox LilycoveCity_Text_BerrySuitsYou, MSGBOX_DEFAULT
	random 10
	addvar VAR_RESULT, FIRST_BERRY_INDEX
	giveitem VAR_RESULT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_DAILY_LILYCOVE_RECEIVED_BERRY
	msgbox LilycoveCity_Text_BecauseYoureTrainer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_ReceivedBerry::
	msgbox LilycoveCity_Text_PokeblocksSuitPokemon, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Man3::
	msgbox LilycoveCity_Text_ContestHallInTown, MSGBOX_NPC
	end

LilycoveCity_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_GirlAquaGone
	msgbox LilycoveCity_Text_StrangeCaveInCove, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_GirlAquaGone::
	msgbox LilycoveCity_Text_GoingToMoveDeleterForHMs, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_RichBoy::
	msgbox LilycoveCity_Text_ImFromKanto, MSGBOX_NPC
	end

LilycoveCity_EventScript_Sailor2::
	lock
	faceplayer
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Sailor2AquaGone
	msgbox LilycoveCity_Text_TeamAquaBeenTrainingWailmer, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Sailor2AquaGone::
	msgbox LilycoveCity_Text_SomeonePuntedTeamAquaOut, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Woman2::
	lock
	faceplayer
	goto_if_set FLAG_TEAM_AQUA_ESCAPED_IN_SUBMARINE, LilycoveCity_EventScript_Woman2AquaGone
	msgbox LilycoveCity_Text_SomeoneStoleMyPokemon, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Woman2AquaGone::
	msgbox LilycoveCity_Text_MissingPokemonCameBack, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Man2::
	msgbox LilycoveCity_Text_ImArtDealer, MSGBOX_NPC
	end

LilycoveCity_EventScript_ExpertM1::
	msgbox LilycoveCity_Text_SeaRemainsForeverYoung, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ExpertF::
	msgbox LilycoveCity_Text_SixtyYearsAgoHusbandProposed, MSGBOX_SIGN
	end

LilycoveCity_EventScript_ExpertM2::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_EventScript_ExpertM2AquaGone
	msgbox LilycoveCity_Text_TeamAquaRenovatedCavern, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_ExpertM2AquaGone::
	msgbox LilycoveCity_Text_TeamAquaLotGoneForGood, MSGBOX_DEFAULT
	release
	end

LilycoveCity_EventScript_Sailor1::
	msgbox LilycoveCity_Text_HeardTowerCalledSkyPillar, MSGBOX_NPC
	end

LilycoveCity_EventScript_FatMan::
	msgbox LilycoveCity_Text_SawTallTowerOnRoute131, MSGBOX_NPC
	end

LilycoveCity_EventScript_Man1::
	lockall
	msgbox LilycoveCity_Text_JustArrivedAndSawRarePokemon, MSGBOX_NPC
	applymovement LOCALID_MAN_1, Common_Movement_FaceOriginalDirection
	end

LilycoveCity_EventScript_Woman1::
	lockall
	msgbox LilycoveCity_Text_HoneymoonVowToSeeRarePokemon, MSGBOX_NPC
	applymovement LOCALID_WOMAN_1, Common_Movement_FaceOriginalDirection
	end

LilycoveCity_EventScript_CitySign::
	msgbox LilycoveCity_Text_CitySign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_GymSign::
	msgbox LilycoveCity_Text_GymSign, MSGBOX_SIGN
	end

LilycoveCity_Text_GymSign:
	.string "CENTRE D'ENTRAÎNEMENT EXTRÊME.\p"
	.string "Maximise facilement le potentiel\n"
	.string "de tes POKéMON !$"

LilycoveCity_EventScript_ContestHallSign::
	msgbox LilycoveCity_Text_ContestHallSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MotelSign::
	msgbox LilycoveCity_Text_MotelSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MuseumSign::
	lockall
	specialvar VAR_0x8004, CountPlayerMuseumPaintings
	switch VAR_0x8004
	case 0, LilycoveCity_EventScript_MuseumSignNoPaintings
	msgbox LilycoveCity_Text_MuseumSignPlayersExhibit, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_MuseumSignNoPaintings::
	msgbox LilycoveCity_Text_MuseumSign, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_HarborSign::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_HarborSignFerryReady
	msgbox LilycoveCity_Text_HarborSignUnderConstruction, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_HarborSignFerryReady::
	msgbox LilycoveCity_Text_HarborSign, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_TrainerFanClubSign::
	msgbox LilycoveCity_Text_TrainerFanClubSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_DepartmentStoreSign::
	msgbox LilycoveCity_Text_DepartmentStoreSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_MoveDeletersHouseSign::
	msgbox LilycoveCity_Text_MoveDeletersHouseSign, MSGBOX_SIGN
	end

LilycoveCity_EventScript_WailmerTrainerGrunt::
	lockall
	goto_if_set FLAG_MET_WAILMER_TRAINER, LilycoveCity_EventScript_MetWailmerTrainer
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_Text_GetLostMessingUpTraining, MSGBOX_DEFAULT
	applymovement VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_MET_WAILMER_TRAINER
	releaseall
	end

LilycoveCity_EventScript_MetWailmerTrainer::
	msgbox LilycoveCity_Text_WailmerLeapOutOfWater, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_EventScript_AquaGrunt1::
	msgbox LilycoveCity_Text_MovedLootIntoHideoutToday, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt2::
	msgbox LilycoveCity_Text_ChanceToDoBigThings, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt3::
	msgbox LilycoveCity_Text_DontGoNearCaveInCove, MSGBOX_NPC
	end

LilycoveCity_EventScript_AquaGrunt4::
	msgbox LilycoveCity_Text_IfWorldBecomesOurs, MSGBOX_NPC
	end

LilycoveCity_EventScript_Rival::
	lock
	faceplayer
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, LilycoveCity_EventScript_May
	goto_if_eq VAR_RESULT, FEMALE, LilycoveCity_EventScript_Brendan
	end

LilycoveCity_EventScript_May::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattleAgain
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_MayAskToBattle
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineMayBattle
	msgbox LilycoveCity_Text_MayWontBeBeaten, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LilycoveCity_EventScript_BattleMayTreecko
	case 1, LilycoveCity_EventScript_BattleMayTorchic
	case 2, LilycoveCity_EventScript_BattleMayMudkip
	end

LilycoveCity_EventScript_MayAskToBattleAgain::
	msgbox LilycoveCity_Text_MayBattleMe, MSGBOX_YESNO
	return

LilycoveCity_EventScript_MayAskToBattle::
	msgbox LilycoveCity_Text_MayShoppingLetsBattle, MSGBOX_YESNO
	return

LilycoveCity_EventScript_DeclineMayBattle::
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
	msgbox LilycoveCity_Text_MayNotRaisingPokemon, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

LilycoveCity_EventScript_Brendan::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattleAgain
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE, LilycoveCity_EventScript_BrendanAskToBattle
	goto_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DeclineBrendanBattle
	msgbox LilycoveCity_Text_BrendanWontBeBeaten, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, LilycoveCity_EventScript_BattleBrendanTreecko
	case 1, LilycoveCity_EventScript_BattleBrendanTorchic
	case 2, LilycoveCity_EventScript_BattleBrendanMudkip
	end

LilycoveCity_EventScript_BrendanAskToBattleAgain::
	msgbox LilycoveCity_Text_BrendanBattleMe, MSGBOX_YESNO
	return

LilycoveCity_EventScript_BrendanAskToBattle::
	msgbox LilycoveCity_Text_BrendanShoppingLetsBattle, MSGBOX_YESNO
	return

LilycoveCity_EventScript_DeclineBrendanBattle::
	setflag FLAG_DECLINED_RIVAL_BATTLE_LILYCOVE
	msgbox LilycoveCity_Text_BrendanNoConfidence, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end

LilycoveCity_EventScript_BattleMayTreecko::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TREECKO, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleMayTorchic::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_TORCHIC, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleMayMudkip::
	trainerbattle_no_intro TRAINER_MAY_LILYCOVE_MUDKIP, LilycoveCity_Text_MayDefeat
	goto LilycoveCity_EventScript_DefeatedMay
	end

LilycoveCity_EventScript_BattleBrendanTreecko::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TREECKO, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_BattleBrendanTorchic::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_TORCHIC, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_BattleBrendanMudkip::
	trainerbattle_no_intro TRAINER_BRENDAN_LILYCOVE_MUDKIP, LilycoveCity_Text_BrendanDefeat
	goto LilycoveCity_EventScript_DefeatedBrendan
	end

LilycoveCity_EventScript_DefeatedMay::
	msgbox LilycoveCity_Text_MayGoingBackToLittleroot, MSGBOX_DEFAULT
	setvar VAR_RESULT, FALSE
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_MayCollectBadges
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_MayPokemonLeague
	clearflag FLAG_HIDE_LITTLEROOT_TOWN_MAYS_HOUSE_RIVAL_BEDROOM
	clearflag FLAG_GARBAGEFLAG
	goto LilycoveCity_EventScript_RivalFlyAway
	end

LilycoveCity_EventScript_CheckFinalBadge::
	goto_if_set FLAG_BADGE08_GET, LilycoveCity_EventScript_HasFinalBadge
	return

LilycoveCity_EventScript_HasFinalBadge::
	setvar VAR_RESULT, TRUE
	return

LilycoveCity_EventScript_MayCollectBadges::
	msgbox LilycoveCity_Text_MayYouGoingToCollectBadges, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_MayPokemonLeague::
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_MayBattleFrontier
	msgbox LilycoveCity_Text_MayYouGoingToPokemonLeague, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_MayBattleFrontier::
	msgbox LilycoveCity_Text_MayYouGoingToBattleFrontier, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_DefeatedBrendan::
	msgbox LilycoveCity_Text_BrendanGoingBackToLittleroot, MSGBOX_DEFAULT
	setvar VAR_RESULT, FALSE
	call_if_set FLAG_BADGE06_GET, LilycoveCity_EventScript_CheckFinalBadge
	call_if_eq VAR_RESULT, FALSE, LilycoveCity_EventScript_BrendanCollectBadges
	call_if_eq VAR_RESULT, TRUE, LilycoveCity_EventScript_BrendanPokemonLeague
	clearflag FLAG_GARBAGEFLAG
	clearflag FLAG_GARBAGEFLAG
	goto LilycoveCity_EventScript_RivalFlyAway
	end

LilycoveCity_EventScript_BrendanCollectBadges::
	msgbox LilycoveCity_Text_BrendanYouGoingToCollectBadges, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_BrendanPokemonLeague::
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_EventScript_BrendanBattleFrontier
	msgbox LilycoveCity_Text_BrendanYouGoingToPokemonLeague, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_BrendanBattleFrontier::
	msgbox LilycoveCity_Text_BrendanYouGoingToBattleFrontier, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_RivalFlyAway::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 50
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	removeobject VAR_LAST_TALKED
	waitfieldeffect FLDEFF_NPCFLY_OUT
	savebgm MUS_DUMMY
	fadedefaultbgm
	setflag FLAG_MET_RIVAL_LILYCOVE
	release
	end

LilycoveCity_EventScript_SchoolKidM::
	lock
	faceplayer
	msgbox LilycoveCity_Text_DoYouKnowAboutBerryBlender, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, LilycoveCity_EventScript_KnowAboutBerryBlender
	call_if_eq VAR_RESULT, NO, LilycoveCity_EventScript_DontKnowAboutBerryBlender
	release
	end

LilycoveCity_EventScript_KnowAboutBerryBlender::
	msgbox LilycoveCity_Text_FasterSpinBetterPokeblocks, MSGBOX_DEFAULT
	return

LilycoveCity_EventScript_DontKnowAboutBerryBlender::
	msgbox LilycoveCity_Text_ExplainBerryBlender, MSGBOX_DEFAULT
	return

LilycoveCity_Text_MayShoppingLetsBattle:
	.string "FLORA : Oh, hé ?\n"
	.string "{PLAYER}{KUN}, tu fais\p"
	.string "des courses aussi ?\n"
	.string "J'ai acheté plein de POUPEES et\p"
	.string "de POSTERS.\n"
	.string "Bien sûr, j'ai aussi acheté plein de\l"
	.string "BAIES et de POKé BALLS.\p"
	.string "Mais je n'ai pas assez d'argent.\n"
	.string "Tu as l'air d'avoir plein d'argent,\p"
	.string "{PLAYER}{KUN}.\n"
	.string "Tu es vraiment incroyable !$"

LilycoveCity_Text_MayNotRaisingPokemon:
	.string "FLORA : Oh, pourquoi ? {PLAYER}{KUN},\n"
	.string "tu n'as pas élevé tes\p"
	.string "POKéMON ? Ce n'est pas\n"
	.string "très bien pour un DRESSEUR…$"

LilycoveCity_Text_MayBattleMe:
	.string "FLORA : Allez, bats-toi avec moi, pour que je puisse\n"
	.string "voir tes POKéMON !$"

LilycoveCity_Text_MayWontBeBeaten:
	.string "FLORA : Les POKéMON que j'ai élevés ne seront\n"
	.string "pas battus par les tiens, {PLAYER}{KUN} !$"

LilycoveCity_Text_MayDefeat:
	.string "… … … … … … … …\p"
	.string "Je me souviens du combat que j'ai eu\n"
	.string "avec toi, {PLAYER}{KUN}, sur la ROUTE 103.\p"
	.string "Ce combat t'a aidé à devenir aussi\n"
	.string "fort, {PLAYER}{KUN}, n'est-ce pas ?$"

LilycoveCity_Text_MayGoingBackToLittleroot:
	.string "FLORA : Je pense retourner bientôt à\n"
	.string "BOURG-EN-VOL.\p"
	.string "J'ai attrapé une bonne équipe de POKéMON,\n"
	.string "et mon POKéDEX avance bien, alors\l"
	.string "je rentre montrer ça à mon père.$"

LilycoveCity_Text_MayYouGoingToCollectBadges:
	.string "{PLAYER}{KUN}, qu'est-ce que tu vas faire ?\p"
	.string "Rassembler tous les BADGES\n"
	.string "d'ARÈNE et relever le défi de la\p"
	.string "LIGUE POKéMON ?\n"
	.string "Eh bien, pendant que tu réunis\l"
	.string "les BADGES, {PLAYER}{KUN}, je vais\p"
	.string "travailler sur mon POKéDEX. Je le compléterai avant toi ! À plus !$"

LilycoveCity_Text_MayYouGoingToPokemonLeague:
	.string "{PLAYER}{KUN}, qu'est-ce que tu vas faire\p"
	.string "? Tu vas relever le défi\n"
	.string "de la LIGUE POKéMON ?\p"
	.string "Ou, tu vas compléter ton\n"
	.string "POKéDEX ? J'ai peut-être perdu\p"
	.string "contre toi en combat, mais\n"
	.string "je finirai mon POKéDEX avant\p"
	.string "toi ! À plus !$"

LilycoveCity_Text_MayYouGoingToBattleFrontier:
	.string "{PLAYER}{KUN}, qu'est-ce que tu vas faire\p"
	.string "? Tu vas relever le défi\n"
	.string "du PARC DES COMBATS ?\p"
	.string "Ou, tu vas compléter ton\n"
	.string "POKéDEX ? J'ai peut-être perdu\p"
	.string "contre toi en combat, mais\n"
	.string "je finirai mon POKéDEX avant\p"
	.string "toi ! À plus !$"

LilycoveCity_Text_BrendanShoppingLetsBattle:
	.string "BRENDAN : Oh, hé, c'est {PLAYER}. Je\p"
	.string "fais une course pour mon père.\n"
	.string "Non, je n'achète pas de POUPEÉES.\p"
	.string "Bon, ça fait un moment. Tu\p"
	.string "veux qu'on se batte pour voir\n"
	.string "qui élève mieux ses POKéMON ?$"

LilycoveCity_Text_BrendanNoConfidence:
	.string "BRICE : Oh, qu'est-ce qui ne va pas ?\n"
	.string "Tu n'as pas confiance en toi ?$"

LilycoveCity_Text_BrendanBattleMe:
	.string "BRENDAN : Tu veux te battre pour voir\n"
	.string "qui élève mieux ses POKéMON ?$"

LilycoveCity_Text_BrendanWontBeBeaten:
	.string "BRENDAN : Aïe, mais tu sais que je ne vais\n"
	.string "pas perdre contre {PLAYER}.$"

LilycoveCity_Text_BrendanDefeat:
	.string "Humph...\n"
	.string "Tu as beaucoup élevé tes POKéMON.\p"
	.string "Ça pique un peu... j'avais une longueur\n"
	.string "d'avance sur toi en tant que DRESSEUR...$"

LilycoveCity_Text_BrendanGoingBackToLittleroot:
	.string "BRICE : Je…\n"
	.string "Je compte rentrer à BOURG-EN-VOL.\p"
	.string "Tu sais, j'aide mon père sur son\n"
	.string "POKéDEX. Il avance plutôt bien,\l"
	.string "alors je devrais aller lui montrer.$"

LilycoveCity_Text_BrendanYouGoingToCollectBadges:
	.string "{PLAYER}, qu'est-ce que tu vas faire ?\p"
	.string "Collectionner tous les BADGES D'ARENE et relever\n"
	.string "le défi de la LIGUE POKéMON ?\p"
	.string "Je vais peut-être faire pareil…\p"
	.string "Bon, en tout cas, tiens bon !$"

LilycoveCity_Text_BrendanYouGoingToPokemonLeague:
	.string "{PLAYER}, qu'est-ce que tu vas faire\p"
	.string "? Puisque tu es si fort,\n"
	.string "tu vas relever le défi de\p"
	.string "la LIGUE POKéMON ? Hé, même\n"
	.string "moi--si j'entraînais mes POKéMON un peu\l"
	.string "plus, je serais plus fort que\p"
	.string "toi, {PLAYER}. Bref, bon courage !$"

LilycoveCity_Text_BrendanYouGoingToBattleFrontier:
	.string "{PLAYER}, qu'est-ce que tu vas faire ?\p"
	.string "Tu vas relever le défi du\n"
	.string "PARC DES COMBATS ?\p"
	.string "Ou, tu vas compléter ton\n"
	.string "POKéDEX ?\p"
	.string "Puisque tu es si fort, tu devrais\n"
	.string "envisager le PARC DES COMBATS.\p"
	.string "Hé, si j'entraîne mes POKéMON un peu plus,\n"
	.string "je deviendrai plus fort que toi, {PLAYER}.\p"
	.string "Peut-être que je devrais aller au\n"
	.string "PARC DES COMBATS.\p"
	.string "Bref, tiens bon !$"

LilycoveCity_Text_MovedLootIntoHideoutToday:
	.string "Héhéhé...\p"
	.string "On a encore déplacé du butin\n"
	.string "dans notre REPAIRE secret aujourd'hui...\p"
	.string "Q-qui êtes-vous ?!\n"
	.string "Je parlais tout seul !$"

LilycoveCity_Text_ChanceToDoBigThings:
	.string "Je ne suis qu'un SBIRE, alors je ne sais pas\n"
	.string "ce que pense le BOSS…\p"
	.string "Mais en étant dans la TEAM AQUA, je sais\n"
	.string "que j'aurai l'occasion de faire de grandes choses !\p"
	.string "Q-qui es-tu ?!\n"
	.string "Je parlais tout seul !$"

LilycoveCity_Text_DontGoNearCaveInCove:
	.string "Hé, toi !\p"
	.string "Ne t'approche pas de la grotte dans l'anse !\p"
	.string "Pourquoi ? Pas besoin de raison !\n"
	.string "Je suis un adulte, alors écoute-moi !$"

LilycoveCity_Text_IfWorldBecomesOurs:
	.string "Si tout ce vaste monde devenait nôtre,\n"
	.string "à la TEAM AQUA, ce serait un endroit\l"
	.string "plus heureux pour les POKéMON aussi.$"

LilycoveCity_Text_WailmerLeapOutOfWater:
	.string "Allez ! WAILMER !\n"
	.string "Sors de l'eau maintenant !$"

LilycoveCity_Text_GetLostMessingUpTraining:
	.string "Hein ? Qu'est-ce que tu veux ?\p"
	.string "Tu gênes notre entraînement,\n"
	.string "alors tu peux dégager ?$"

LilycoveCity_Text_ContestHallInTown:
	.string "Il y a une SALLE DE CONCOURS POKéMON\n"
	.string "dans cette ville. \p"
	.string "Ça veut dire que des POKéMON bien élevés\n"
	.string "viendront de tout le pays.\p"
	.string "Mon cœur gonfle d'excitation !$"

LilycoveCity_Text_StrangeCaveInCove:
	.string "Tu as vu cette étrange grotte dans\n"
	.string "la crique au bord de la ville ?$"

LilycoveCity_Text_GoingToMoveDeleterForHMs:
	.string "Je vais apprendre de nouveaux mouvements\n"
	.string "à mes POKéMON pour participer à un CONCOURS.\p"
	.string "Alors, je vais voir l'EFFACEUR DE CAPACITÉS\n"
	.string "et lui faire oublier les CS.$"

LilycoveCity_Text_ImFromKanto:
	.string "Je viens de KANTO.\p"
	.string "La région de HOENN est magnifique avec\n"
	.string "toute son eau et sa nature verdoyante.\p"
	.string "Hein ? Attends une seconde…\p"
	.string "Il pourrait y avoir des POKéMON rares qui vivent\n"
	.string "uniquement dans cette région ?$"

LilycoveCity_Text_TeamAquaBeenTrainingWailmer:
	.string "La TEAM AQUA entraîne ses WAILMER\n"
	.string "dans l'anse. Nous, MARINS, ne pouvons\p"
	.string "pas sortir nos bateaux en mer\n"
	.string "avec eux sur le chemin !$"

LilycoveCity_Text_SomeonePuntedTeamAquaOut:
	.string "Ahoy, tu savais ?\p"
	.string "Quelqu'un a balayé la TEAM AQUA\n"
	.string "pour nous !\p"
	.string "Ça a fait sortir les WAILMER de la crique,\n"
	.string "on peut remettre nos bateaux à l'eau.$"

LilycoveCity_Text_SomeoneStoleMyPokemon:
	.string "Je faisais une petite sieste relaxante\n"
	.string "à l'auberge au bord de mer au son des vagues…\p"
	.string "Quand quelqu'un a volé mon POKéMON !\p"
	.string "Qui est le ravisseur ?\n"
	.string "La TEAM AQUA ? C'est la TEAM AQUA ?$"

LilycoveCity_Text_MissingPokemonCameBack:
	.string "Mon POKéMON disparu…\n"
	.string "Il est revenu sans que je m'en aperçoive !$"

LilycoveCity_Text_ImArtDealer:
	.string "Je suis un MARCHAND D'ART.\p"
	.string "J'achète et vends de belles œuvres,\n"
	.string "surtout des peintures.\p"
	.string "J'ai entendu dire que le MUSÉE ici expose\n"
	.string "des œuvres magnifiques…$"

LilycoveCity_Text_SeaRemainsForeverYoung:
	.string "Même si nous vieillissons et ridons,\n"
	.string "la mer reste éternellement jeune avec\l"
	.string "l'éclat de la vie…\p"
	.string "Fwohoho fwohohohoho…$"

LilycoveCity_Text_SixtyYearsAgoHusbandProposed:
	.string "C'est ici que mon mari m'a demandée\n"
	.string "en mariage, il y a soixante ans.\l"
	.string "La mer reste aussi belle qu'autrefois.\p"
	.string "Mufufufu mufufufufufu…$"

LilycoveCity_Text_TeamAquaRenovatedCavern:
	.string "Hm, tu connais la\n"
	.string "grotte particulière\p"
	.string "dans cette crique ?\n"
	.string "C'était une\l"
	.string "formation\p"
	.string "naturelle,\n"
	.string "mais ensuite\p"
	.string "ça a changé…\n"
	.string "C'est mystérieux !$"

LilycoveCity_Text_TeamAquaLotGoneForGood:
	.string "Cette grotte dans la crique…\p"
	.string "Je ne l'ai pas remarquée tout de suite,\n"
	.string "mais elle est complètement vide maintenant.\p"
	.string "Ces voyous de la TEAM AQUA ont dû\n"
	.string "partir pour de bon.$"

LilycoveCity_Text_CitySign:
	.string "LILYCOVE\p"
	.string "« Là où la terre finit et où\n"
	.string "la mer commence. »$"

LilycoveCity_Text_ContestHallSign:
	.string "SALLE DE CONCOURS POKéMON\n"
	.string "« Le lieu de rencontre des DRESSEURS ! »$"

LilycoveCity_Text_MotelSign:
	.string "MOTEL LYS COVE\p"
	.string "« Souvenez-vous de nous, le LYS COVE\n"
	.string "de LILYCOVE. »$"

LilycoveCity_Text_MuseumSign:
	.string "MUSÉE LILYCOVE\p"
	.string "« Collection de chefs-d'œuvre POKéMON\n"
	.string "en exposition ! »$"

LilycoveCity_Text_MuseumSignPlayersExhibit:
	.string "MUSÉE LILYCOVE\p"
	.string "« Collection POKéMON de {PLAYER}\n"
	.string "en exposition ! »$"

LilycoveCity_Text_HarborSignUnderConstruction:
	.string "PORT DE LILYVERRE\p"
	.string "« Le ferry S.S. MARÉE est en\n"
	.string "construction à POIVRESSELLE.\p"
	.string "« Le service devrait commencer\n"
	.string "bientôt. »$"

LilycoveCity_Text_HarborSign:
	.string "PORT DE LILYCOVE\p"
	.string "« Profitez d'une croisière agréable\n"
	.string "sur le ferry S.S. MARÉE. »$"

LilycoveCity_Text_TrainerFanClubSign:
	.string "FAN CLUB DES DRESSEURS POKéMON\p"
	.string "Les noms des DRESSEURS sont griffonnés\n"
	.string "partout sur le panneau…$"

LilycoveCity_Text_DepartmentStoreSign:
	.string "GRAND MAGASIN DE LILYVERRE\p"
	.string "« Débordant de superbes marchandises\n"
	.string "et d'excitation !\p"
	.string "« Un super endroit pour trouver ce\n"
	.string "qu'il vous faut ! »$"

LilycoveCity_Text_MoveDeletersHouseSign:
	.string "MAISON du EFFACEUR DE CAPACITÉS\p"
	.string "« Capacités POKéMON indésirables effacées. »$"

LilycoveCity_Text_DoYouKnowAboutBerryBlender:
	.string "Tu connais la machine\n"
	.string "MIXEUR À BAIES ?$"

LilycoveCity_Text_FasterSpinBetterPokeblocks:
	.string "Les gens doivent travailler ensemble pour le\n"
	.string "faire tourner plus vite.\p"
	.string "Plus tu le fais tourner vite, meilleurs\n"
	.string "seront les {POKEBLOCK}S, paraît-il.$"

LilycoveCity_Text_ExplainBerryBlender:
	.string "On l'utilise pour fabriquer une sorte de\n"
	.string "caramel appelé {POKEBLOCK}.\p"
	.string "Si tu donnes un bon {POKEBLOCK} à un POKéMON,\n"
	.string "sa condition s'améliorera beaucoup.$"

LilycoveCity_Text_HeardTowerCalledSkyPillar:
	.string "J'ai entendu dire qu'il y a une tour quelque part sur\n"
	.string "les routes maritimes.\p"
	.string "On l'appelle le PILIER CELESTE, paraît-il.$"

LilycoveCity_Text_SawTallTowerOnRoute131:
	.string "J'ai vu cette grande tour quelque part\n"
	.string "autour de la ROUTE 131.\p"
	.string "Est-ce que ça pourrait être… ?$"

LilycoveCity_Text_JustArrivedAndSawRarePokemon:
	.string "Nous venons d'arriver ici pour\n"
	.string "notre lune de miel.\p"
	.string "Nous avons vu un POKéMON de type DRAGON\n"
	.string "voler très haut dans le ciel.\p"
	.string "Est-ce que des POKéMON cool comme ça vivent\n"
	.string "dans la région de HOENN ?$"

LilycoveCity_Text_HoneymoonVowToSeeRarePokemon:
	.string "Pendant notre lune de miel, nous avons juré de voir\n"
	.string "autant de POKéMON rares que possible.\p"
	.string "Alors nous étions déçus de ne pas en voir\n"
	.string "beaucoup ici…\p"
	.string "Mais on a vu un POKéMON rare voler !$"
