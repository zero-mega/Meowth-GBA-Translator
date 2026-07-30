.set LOCALID_BRINEY, 11
.set LOCALID_WANDAS_BF_OUTSIDE, 21

Route116_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route116_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, Route116_OnLoad
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route116_OnFrame
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route116_OnTransition:
	callnative SetTimeBasedEncounters
	call_if_set FLAG_RECOVERED_DEVON_GOODS, Route116_EventScript_SetWandasBoyfriendPos
	call_if_eq VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_HideMapNamePopup
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_116_NORTH, AbnormalWeather_StartGroudonWeather
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_116_SOUTH, AbnormalWeather_StartGroudonWeather
	end

Route116_RoseradeEvo::
	msgbox Route116_RoseradeEvo_Text, MSGBOX_NPC
	end

Route116_RoseradeEvo_Text:
	.string "Tu savais que certains POKéMON évoluent\n"
	.string "quand leur BEAUTÉ atteint son niveau\l"
	.string "maximum ? C'est comme ça que\p"
	.string "mon ROSELIA a évolué !$"

Route116_EventScript_SetWandasBoyfriendPos::
	setobjectxyperm LOCALID_WANDAS_BF_OUTSIDE, 38, 10
	return

Route116_OnLoad:
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_116_NORTH, AbnormalWeather_EventScript_PlaceTilesRoute116North
	call_if_eq VAR_ABNORMAL_WEATHER_LOCATION, ABNORMAL_WEATHER_ROUTE_116_SOUTH, AbnormalWeather_EventScript_PlaceTilesRoute116South
	end

Route116_OnFrame:
	map_script_2 VAR_SHOULD_END_ABNORMAL_WEATHER, 1, AbnormalWeather_EventScript_EndEventAndCleanup_1
	.2byte 0

Route116_EventScript_WandasBoyfriend::
	lock
	faceplayer
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, Route116_EventScript_BoyfriendGruntLeftTunnel
	goto_if_set FLAG_DEVON_GOODS_STOLEN, Route116_EventScript_BoyfriendGruntInTunnel
	msgbox Route116_Text_WantToDigTunnel, MSGBOX_DEFAULT
	release
	end

Route116_EventScript_BoyfriendGruntLeftTunnel::
	msgbox Route116_Text_GoonHightailedItOutOfTunnel, MSGBOX_DEFAULT
	release
	end

Route116_EventScript_BoyfriendGruntInTunnel::
	msgbox Route116_Text_DiggingTunnelWhenGoonOrderedMeOut, MSGBOX_DEFAULT
	release
	end

Route116_EventScript_DevonEmployee::
	lock
	faceplayer
	goto_if_set FLAG_MET_DEVON_EMPLOYEE, Route116_EventScript_TryGiveRepeatBallAgain
	msgbox Route116_Text_ThankYouTokenOfAppreciation, MSGBOX_DEFAULT
	goto Route116_EventScript_GiveRepeatBall
	end

Route116_EventScript_GiveRepeatBall::
	setflag FLAG_MET_DEVON_EMPLOYEE
	giveitem ITEM_REPEAT_BALL
	goto_if_eq VAR_RESULT, FALSE, Route116_EventScript_NoRoomForRepeatBall
	msgbox Route116_Text_NewBallAvailableAtMart, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, Route116_EventScript_DevonEmployeeExit
	call_if_eq VAR_FACING, DIR_SOUTH, Route116_EventScript_DevonEmployeeExit
	call_if_eq VAR_FACING, DIR_WEST, Route116_EventScript_DevonEmployeeExit
	call_if_eq VAR_FACING, DIR_EAST, Route116_EventScript_DevonEmployeeExitEast
	removeobject VAR_LAST_TALKED
	clearflag FLAG_GARBAGEFLAG
	setflag FLAG_RECEIVED_REPEAT_BALL
	release
	end

Route116_EventScript_DevonEmployeeExit::
	applymovement VAR_LAST_TALKED, Route116_Movement_DevonEmployeeExit
	waitmovement 0
	return

Route116_EventScript_DevonEmployeeExitEast::
	applymovement VAR_LAST_TALKED, Route116_Movement_DevonEmployeeExitEast
	waitmovement 0
	return

Route116_EventScript_TryGiveRepeatBallAgain::
	msgbox Route116_Text_TokenOfAppreciation, MSGBOX_DEFAULT
	goto Route116_EventScript_GiveRepeatBall
	end

Route116_EventScript_NoRoomForRepeatBall::
	msgbox Route116_Text_BagIsJamPacked, MSGBOX_DEFAULT
	release
	end

Route116_Movement_DevonEmployeeExit:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route116_Movement_DevonEmployeeExitEast:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route116_EventScript_RouteSignRustboro::
	msgbox Route116_Text_RouteSignRustboro, MSGBOX_SIGN
	end

Route116_EventScript_RusturfTunnelSign::
	msgbox Route116_Text_RusturfTunnelSign, MSGBOX_SIGN
	end

Route116_EventScript_TunnelersRestHouseSign::
	msgbox Route116_Text_TunnelersRestHouse, MSGBOX_SIGN
	end

Route116_EventScript_TrainerTipsBToStopEvolution::
	msgbox Route116_Text_TrainerTipsBToStopEvolution, MSGBOX_SIGN
	end

Route116_EventScript_TrainerTipsBagHasPockets::
	msgbox Route116_Text_TrainerTipsBagHasPockets, MSGBOX_SIGN
	end

Route116_EventScript_Briney::
	lock
	faceplayer
	msgbox Route116_Text_ScoundrelMadeOffWithPeeko, MSGBOX_DEFAULT
	setvar VAR_GARBAGEVAR, 2
	release
	end

Route116_EventScript_BrineyTrigger::
	lockall
	applymovement LOCALID_BRINEY, Common_Movement_WalkInPlaceFasterRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	msgbox Route116_Text_ScoundrelMadeOffWithPeeko, MSGBOX_DEFAULT
	setvar VAR_GARBAGEVAR, 2
	releaseall
	end

Route116_EventScript_GlassesMan::
	lock
	faceplayer
	checkitem ITEM_BLACK_GLASSES
	goto_if_eq VAR_RESULT, TRUE, Route116_EventScript_PlayerHasGlasses
	specialvar VAR_RESULT, FoundBlackGlasses
	goto_if_eq VAR_RESULT, TRUE, Route116_EventScript_FoundGlassesNotOnPlayer
	msgbox Route116_Text_CanYouHelpMeFindGlasses, MSGBOX_DEFAULT
	release
	end

Route116_EventScript_FoundGlassesNotOnPlayer::
	msgbox Route116_Text_CantFindGlassesNotHere, MSGBOX_DEFAULT
	closemessage
	goto Route116_EventScript_GlassesManExit
	end

Route116_EventScript_PlayerHasGlasses::
	msgbox Route116_Text_CanYouHelpMeFindGlasses, MSGBOX_DEFAULT
	msgbox Route116_Text_MayISeeThoseGlasses, MSGBOX_DEFAULT
	specialvar VAR_RESULT, FoundBlackGlasses
	goto_if_eq VAR_RESULT, TRUE, Route116_EventScript_FoundGlassesOnPlayer
	msgbox Route116_Text_NotWhatImLookingFor, MSGBOX_DEFAULT
	release
	end

Route116_EventScript_FoundGlassesOnPlayer::
	msgbox Route116_Text_NotWhatImLookingForMaybeTheyArentHere, MSGBOX_DEFAULT
	closemessage
	goto Route116_EventScript_GlassesManExit
	end

Route116_EventScript_GlassesManExit::
	delay 20
	call_if_eq VAR_FACING, DIR_NORTH, Route116_EventScript_GlassesManExitNormal
	call_if_eq VAR_FACING, DIR_SOUTH, Route116_EventScript_GlassesManExitNormal
	call_if_eq VAR_FACING, DIR_WEST, Route116_EventScript_GlassesManExitNormal
	call_if_eq VAR_FACING, DIR_EAST, Route116_EventScript_GlassesManExitEast
	removeobject VAR_LAST_TALKED
	release
	end

Route116_EventScript_GlassesManExitNormal::
	applymovement VAR_LAST_TALKED, Route116_Movement_GlassesManExit
	waitmovement 0
	return

Route116_EventScript_GlassesManExitEast::
	applymovement VAR_LAST_TALKED, Route116_Movement_GlassesManExitEast
	waitmovement 0
	return

Route116_Movement_GlassesManExit:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route116_Movement_GlassesManExitEast:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route116_EventScript_Joey::
	trainerbattle_single TRAINER_JOEY, Route116_Text_JoeyIntro, Route116_Text_JoeyDefeat
	msgbox Route116_Text_JoeyPostBattle, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_Jose::
	trainerbattle_single TRAINER_JOSE, Route116_Text_JoseIntro, Route116_Text_JoseDefeat
	msgbox Route116_Text_JosePostBattle, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_Jerry::
	trainerbattle_single TRAINER_ARCHER_1, Route116_Text_JerryIntro, Route116_Text_JerryDefeat, Route116_EventScript_TryRegisterJerryAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route116_EventScript_RematchJerry
	setvar VAR_0x8004, TRAINER_ARCHER_1
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, FALSE, Route116_EventScript_TryRegisterJerry
	msgbox Route116_Text_JerryPostBattle, MSGBOX_DEFAULT
	release
	end

Route116_EventScript_TryRegisterJerryAfterBattle::
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_EventScript_RegisterJerryAfterBattle
	release
	end

Route116_EventScript_RegisterJerryAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route116_Text_JerryRegister2, MSGBOX_DEFAULT
	register_matchcall TRAINER_ARCHER_1
	release
	end

Route116_EventScript_TryRegisterJerry::
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_EventScript_RegisterJerry
	msgbox Route116_Text_JerryPostBattle, MSGBOX_DEFAULT
	release
	end

Route116_EventScript_RegisterJerry::
	msgbox Route116_Text_JerryRegister1, MSGBOX_DEFAULT
	register_matchcall TRAINER_ARCHER_1
	release
	end

Route116_EventScript_RematchJerry::
	trainerbattle_rematch TRAINER_ARCHER_1, Route116_Text_JerryRematchIntro, Route116_Text_JerryRematchDefeat
	msgbox Route116_Text_JerryPostRematch, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_Clark::
	trainerbattle_single TRAINER_CLARK, Route116_Text_ClarkIntro, Route116_Text_ClarkDefeat
	msgbox Route116_Text_ClarkPostBattle, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_Janice::
	trainerbattle_single TRAINER_RIVAL_TOTODILE_1, Route116_Text_JaniceIntro, Route116_Text_JaniceDefeat
	msgbox Route116_Text_JanicePostBattle, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_Karen::
	trainerbattle_single TRAINER_KAREN_1, Route116_Text_KarenIntro, Route116_Text_KarenDefeat, Route116_EventScript_TryRegisterKarenAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route116_EventScript_RematchKaren
	setvar VAR_0x8004, TRAINER_KAREN_1
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, FALSE, Route116_EventScript_TryRegisterKaren
	msgbox Route116_Text_KarenPostBattle, MSGBOX_DEFAULT
	release
	end

Route116_EventScript_TryRegisterKarenAfterBattle::
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_EventScript_RegisterKarenAfterBattle
	release
	end

Route116_EventScript_RegisterKarenAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route116_Text_KarenRegister2, MSGBOX_DEFAULT
	register_matchcall TRAINER_KAREN_1
	release
	end

Route116_EventScript_TryRegisterKaren::
	goto_if_set FLAG_HAS_MATCH_CALL, Route116_EventScript_RegisterKaren
	msgbox Route116_Text_KarenPostBattle, MSGBOX_DEFAULT
	release
	end

Route116_EventScript_RegisterKaren::
	msgbox Route116_Text_KarenRegister1, MSGBOX_DEFAULT
	register_matchcall TRAINER_KAREN_1
	release
	end

Route116_EventScript_RematchKaren::
	trainerbattle_rematch TRAINER_KAREN_1, Route116_Text_KarenRematchIntro, Route116_Text_KarenRematchDefeat
	msgbox Route116_Text_KarenPostRematch, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_Sarah::
	trainerbattle_single TRAINER_SARAH, Route116_Text_SarahIntro, Route116_Text_SarahDefeat
	msgbox Route116_Text_SarahPostBattle, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_Dawson::
	trainerbattle_single TRAINER_JOEL, Route116_Text_DawsonIntro, Route116_Text_DawsonDefeat
	msgbox Route116_Text_DawsonPostBattle, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_Devan::
	trainerbattle_single TRAINER_KATE, Route116_Text_DevanIntro, Route116_Text_DevanDefeat
	msgbox Route116_Text_DevanPostBattle, MSGBOX_AUTOCLOSE
	end

Route116_EventScript_Johnson::
	trainerbattle_single TRAINER_JOHNSON, Route116_Text_JohnsonIntro, Route116_Text_JohnsonDefeat
	msgbox Route116_Text_JohnsonPostBattle, MSGBOX_AUTOCLOSE
	end

Route116_Text_ScoundrelMadeOffWithPeeko:
	.string "Ohhh, que dois-je faire ?\p"
	.string "On se promenait, KECKO et moi, quand\n"
	.string "un voyou bizarre nous a sauté dessus…\p"
	.string "Le scélérat s'est enfui avec mon\n"
	.string "cher KECKO !\p"
	.string "Wrrrooooooaaaar ! KECKO !$"

Route116_Text_WantToDigTunnel:
	.string "Nnn… Rugis !\p"
	.string "Je veux creuser ce tunnel !$"

Route116_Text_DiggingTunnelWhenGoonOrderedMeOut:
	.string "PAPA : {PLAYER}…\n"
	.string "J'avais le sentiment que tu viendrais.\p"
	.string "Je ne refuserais jamais d'accepter\n"
	.string "un défi de ta part.\p"
	.string "Tu comprends, n'est-ce pas ?\n"
	.string "Dans une ARÈNE, peu importe que\l"
	.string "nous soyons parent et enfant.\p"
	.string "Hein ? Attends une seconde, {PLAYER}.\n"
	.string "Tu n'as qu'un seul POKéMON qui peut\p"
	.string "combattre ?\n"
	.string "Désolé, mais tu devras revenir\l"
	.string "avec au moins deux POKéMON.$"

Route116_Text_GoonHightailedItOutOfTunnel:
	.string "Nnn… Roar !\p"
	.string "Ce crétin s'est enfui du\n"
	.string "tunnel ! Je peux retourner creuser !$"

Route116_Text_ThankYouTokenOfAppreciation:
	.string "Oh ! C'est toi !\p"
	.string "Tu es celui qui m'a aidé dans le BOIS\n"
	.string "PETALBURG, a récupéré mon colis volé et\l"
	.string "l'a même livré gracieusement à POIVRESSE !\l"
	.string "Le CAPT. POUPEAU nous a informés que le\p"
	.string "colis est bien arrivé aussi !\n"
	.string "Je te remercie beaucoup, beaucoup !\p"
	.string "Si j'étais un nuage de\p"
	.string "pluie, je t'arroserais\n"
	.string "de gratitude et te\l"
	.string "célébrerais comme un héros !\p"
	.string "Pour toi, le plus merveilleux DRESSEUR,\n"
	.string "j'ai une bonne nouvelle !\p"
	.string "Récemment, notre entreprise a développé\n"
	.string "un nouveau type de POKé BALL.\p"
	.string "En signe de notre gratitude, c'est\n"
	.string "notre cadeau à notre merveilleux DRESSEUR !$"

Route116_Text_NewBallAvailableAtMart:
	.string "Notre nouvelle POKé BALL sera\n"
	.string "disponible à la BOUTIQUE POKéMON\p"
	.string "de MÉROUVILLE. Essaie-la ! Merci\n"
	.string "et au revoir !$"

Route116_Text_BagIsJamPacked:
	.string "Ton SAC est bourré.\n"
	.string "Je ne peux pas te donner cette REPEAT BALL.$"

Route116_Text_TokenOfAppreciation:
	.string "En signe de notre gratitude pour\n"
	.string "la livraison de notre colis, j'ai\l"
	.string "un cadeau : un nouveau type de POKé BALL\l"
	.string "pour notre merveilleux DRESSEUR !$"

Route116_Text_CanYouHelpMeFindGlasses:
	.string "J'ai perdu mes lunettes…\n"
	.string "Peux-tu m'aider à les trouver ?$"

Route116_Text_MayISeeThoseGlasses:
	.string "Ces lunettes !\n"
	.string "Puis-je les voir une seconde ?$"

Route116_Text_NotWhatImLookingForMaybeTheyArentHere:
	.string "Hmm...\n"
	.string "Ce sont des LUNET.NOIRES.\l"
	.string "Ce n'est pas ce que je cherche...\p"
	.string "Peut-être que mes lunettes ne sont\n"
	.string "pas par ici...$"

Route116_Text_CantFindGlassesNotHere:
	.string "Hmm…\n"
	.string "Je ne trouve mes lunettes nulle part…\l"
	.string "Elles ne sont peut-être pas par ici…$"

Route116_Text_NotWhatImLookingFor:
	.string "Hmm…\n"
	.string "Ce sont des LUNET.NOIRES.\l"
	.string "Ce n'est pas ce que je cherche…$"

Route116_Text_RouteSignRustboro:
	.string "ROUTE 116\n"
	.string "{LEFT_ARROW} MEROUVILLE$"

Route116_Text_RusturfTunnelSign:
	.string "TUNNEL RONDOUDOU\n"
	.string "« Relie KANTEBLA et MYSTHERBE.\p"
	.string "« Le projet du tunnel a été\n"
	.string "annulé. »$"

Route116_Text_TunnelersRestHouse:
	.string "REPOS DES MINEURS$"

Route116_Text_TrainerTipsBToStopEvolution:
	.string "CONSEILS AUX DRESSEURS\p"
	.string "Si tu veux empêcher un POKéMON d'évoluer,\n"
	.string "appuie sur le bouton B pendant qu'il\l"
	.string "essaie d'évoluer.\l"
	.string "Le POKéMON surpris s'arrêtera.\p"
	.string "On appelle ça une annulation d'évolution.$"

Route116_Text_TrainerTipsBagHasPockets:
	.string "CONSEILS AUX DRESSEURS\p"
	.string "Ton SAC a plusieurs POCHES.\p"
	.string "Les objets que tu obtiens sont automatiquement\n"
	.string "placés dans les POCHES appropriées.\p"
	.string "Aucun DRESSEUR ne peut se passer\n"
	.string "de son propre SAC.$"

