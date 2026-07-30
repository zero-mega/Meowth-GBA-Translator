BattleFrontier_BattlePyramidFloor_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattlePyramidFloor_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidFloor_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattlePyramidFloor_OnTransition
	.byte 0

BattleFrontier_BattlePyramidFloor_OnFrame:
	map_script_2 VAR_TEMP_D, 1, BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight
	map_script_2 VAR_TEMP_PLAYING_PYRAMID_MUSIC, 0, BattleFrontier_BattlePyramidFloor_EventScript_PlayPyramidMusic
	map_script_2 VAR_TEMP_F, 1, BattleFrontier_BattlePyramidFloor_EventScript_ShowMapName
	.2byte 0

BattleFrontier_BattlePyramidFloor_EventScript_UpdateLight::
	lockall
	@ pyramid_updatelight, cant use macro because it straddles the loop
	setvar VAR_0x8004, BATTLE_PYRAMID_FUNC_UPDATE_LIGHT
	setvar VAR_0x8005, 4
	setvar VAR_0x8006, PYRAMID_LIGHT_INCR_RADIUS
	setvar VAR_0x8007, SE_SAVE
	setvar VAR_RESULT, 0
BattleFrontier_BattlePyramidFloor_EventScript_UpdateLightLoop::
	special CallBattlePyramidFunction
	delay 2
	goto_if_ne VAR_RESULT, 2, BattleFrontier_BattlePyramidFloor_EventScript_UpdateLightLoop
	setvar VAR_TEMP_D, 0
	releaseall
	end

BattleFrontier_BattlePyramidFloor_EventScript_ShowMapName::
	special ShowMapNamePopup
	setvar VAR_TEMP_F, 0
	end

BattleFrontier_BattlePyramidFloor_EventScript_PlayPyramidMusic::
	playbgm MUS_B_PYRAMID, FALSE
	setvar VAR_TEMP_PLAYING_PYRAMID_MUSIC, 1
	end

BattleFrontier_BattlePyramidFloor_OnResume:
	pyramid_setfloorpal
	frontier_getstatus
	switch VAR_TEMP_CHALLENGE_STATUS
	case 0, BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge
	case CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePyramid_EventScript_WarpToLobby
	case CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge
	frontier_get FRONTIER_DATA_BATTLE_OUTCOME
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, 0, BattleFrontier_BattlePyramidFloor_EventScript_ResetParty
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	goto_if_eq VAR_RESULT, B_OUTCOME_DREW, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	goto_if_eq VAR_RESULT, B_OUTCOME_FORFEITED, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	frontier_isbattletype BATTLE_TYPE_TRAINER  @ VAR_RESULT seems to be ignored here
	setvar VAR_TEMP_D, 1
BattleFrontier_BattlePyramidFloor_EventScript_ResetParty::
	pyramid_resetparty
	end

BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_LOST
	pyramid_set PYRAMID_DATA_TRAINER_FLAGS, 255
BattleFrontier_BattlePyramid_EventScript_WarpToLobby::
	pyramid_updatelight 0, PYRAMID_LIGHT_SET_RADIUS
	pyramid_clearhelditems
	special HealPlayerParty
	warpsilent MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_LOBBY, 7, 13
	waitstate
	end

BattleFrontier_BattlePyramidFloor_EventScript_ReadyChallenge::
	pyramid_save CHALLENGE_STATUS_SAVING
	special SavePlayerParty
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	pyramid_settrainers
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidFloor_OnTransition:
	call BattleFrontier_BattlePyramidFloor_EventScript_SetLightRadius
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidFloor_EventScript_SetLightRadius::
	pyramid_updatelight 32, PYRAMID_LIGHT_SET_RADIUS
	return

BattlePyramid_WarpToNextFloor::
	call BattleFrontier_EventScript_IncrementWinStreak
	frontier_get FRONTIER_DATA_BATTLE_NUM  @ Floor number
	addvar VAR_RESULT, 1
	frontier_set FRONTIER_DATA_BATTLE_NUM, VAR_RESULT
	goto_if_eq VAR_RESULT, 7, BattlePyramid_WarpToTop
	pyramid_seedfloor
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	setvar VAR_RESULT, 0
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_FLOOR, 1, 1
	waitstate
	end

BattlePyramid_WarpToTop::
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_TOP, 17, 17
	waitstate
	end

@ TRAINER_PHILLIP is used as a placeholder
BattlePyramid_TrainerBattle::
	trainerbattle TRAINER_BATTLE_PYRAMID, TRAINER_PHILLIP, 0, BattleFacility_TrainerBattle_PlaceholderText, BattleFacility_TrainerBattle_PlaceholderText
	pyramid_showhint
	waitmessage
	waitbuttonpress
	closemessage
	releaseall
	end

BattlePyramid_FindItemBall::
	pyramid_setitem
	callstd STD_FIND_ITEM
	goto_if_eq VAR_0x8007, 0, BattlePyramid_FindItemBallEnd
	pyramid_hideitem
BattlePyramid_FindItemBallEnd::
	end

BattlePyramid_Retire::
	goto BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost

@ Also used by Trainer Hill
BattleFacility_TrainerBattle_PlaceholderText:
	.string "Ceci est un message d'exemple.$"

gText_BattlePyramidConfirmRest::
	.string "Ta quête de la PYRAMIDE DE COMBAT sera\n"
	.string "sauvegardée pour que tu puisses quitter.\l"
	.string "C'est d'accord ?$"

gText_BattlePyramidConfirmRetire::
	.string "Es-tu sûr de vouloir abandonner\n"
	.string "ton défi de la PYRAMIDE ?$"

BattlePyramid_Text_ExitHintUp1::
	.string "La sortie de cet étage est\n"
	.string "dans cette direction : {UP_ARROW}$"

BattlePyramid_Text_ExitHintLeft1::
	.string "La sortie de cet étage est\n"
	.string "dans cette direction : {LEFT_ARROW}$"

BattlePyramid_Text_ExitHintRight1::
	.string "La sortie de cet étage est\n"
	.string "dans cette direction : {RIGHT_ARROW}$"

BattlePyramid_Text_ExitHintDown1::
	.string "La sortie de cet étage est\n"
	.string "dans cette direction : {DOWN_ARROW}$"

BattlePyramid_Text_ExitHintUp2::
	.string "La sortie de cet étage est\n"
	.string "vers le {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft2::
	.string "La sortie de cet étage est\n"
	.string "vers la {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight2::
	.string "La sortie de cet étage est\n"
	.string "vers la {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown2::
	.string "La sortie de cet étage est\n"
	.string "vers le {DOWN_ARROW}.$"

BattlePyramid_Text_ExitHintUp3::
	.string "La sortie est par\n"
	.string "là {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft3::
	.string "La sortie est par\n"
	.string "là {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight3::
	.string "La sortie est par\n"
	.string "là {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown3::
	.string "La sortie est par\n"
	.string "là {DOWN_ARROW}.$"

BattlePyramid_Text_ExitHintUp4::
	.string "À cet étage, la sortie se trouve\n"
	.string "quelque part vers le {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft4::
	.string "À cet étage, la sortie se trouve\n"
	.string "quelque part vers le {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight4::
	.string "À cet étage, la sortie est quelque part\n"
	.string "dans la direction {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown4::
	.string "À cet étage, la sortie se trouve\n"
	.string "quelque part vers le {DOWN_ARROW}.$"

BattlePyramid_Text_ExitHintUp5::
	.string "La sortie ?\n"
	.string "C'est par {UP_ARROW} là.$"

BattlePyramid_Text_ExitHintLeft5::
	.string "La sortie ?\n"
	.string "C'est par là {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight5::
	.string "La sortie ?\n"
	.string "C'est par là {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown5::
	.string "La sortie ?\n"
	.string "C'est par là {DOWN_ARROW}.$"

BattlePyramid_Text_ExitHintUp6::
	.string "La sortie se trouve\n"
	.string "dans la direction {UP_ARROW}.$"

BattlePyramid_Text_ExitHintLeft6::
	.string "La sortie se trouve\n"
	.string "dans la direction {LEFT_ARROW}.$"

BattlePyramid_Text_ExitHintRight6::
	.string "La sortie se trouve\n"
	.string "vers la {RIGHT_ARROW}.$"

BattlePyramid_Text_ExitHintDown6::
	.string "La sortie se trouve\n"
	.string "dans la direction {DOWN_ARROW}.$"

BattlePyramid_Text_EightItemsRemaining1::
	.string "Tu cherches des objets ?\p"
	.string "Il reste huit objets à\n"
	.string "trouver.$"

BattlePyramid_Text_SevenItemsRemaining1::
	.string "Tu cherches des objets ?\p"
	.string "Il reste sept objets à\n"
	.string "trouver.$"

BattlePyramid_Text_SixItemsRemaining1::
	.string "Tu cherches des objets ?\p"
	.string "Il reste six objets à\n"
	.string "trouver.$"

BattlePyramid_Text_FiveItemsRemaining1::
	.string "Tu cherches des objets ?\p"
	.string "Il reste cinq objets à\n"
	.string "trouver.$"

BattlePyramid_Text_FourItemsRemaining1::
	.string "Tu cherches des objets ?\p"
	.string "Il reste quatre objets à\n"
	.string "trouver.$"

BattlePyramid_Text_ThreeItemsRemaining1::
	.string "Tu cherches des objets ?\p"
	.string "Il reste trois objets à\n"
	.string "trouver.$"

BattlePyramid_Text_TwoItemsRemaining1::
	.string "Tu cherches des objets ?\p"
	.string "Il reste deux objets à\n"
	.string "trouver.$"

BattlePyramid_Text_OneItemRemaining1::
	.string "Tu cherches des objets ?\p"
	.string "Il reste un objet à\n"
	.string "trouver.$"

BattlePyramid_Text_ZeroItemsRemaining1::
	.string "Tu cherches des objets ?\p"
	.string "Il n'y a plus rien à\n"
	.string "trouver !$"

BattlePyramid_Text_EightItemsRemaining2::
	.string "Comme tu as gagné, je vais te dire\n"
	.string "un petit secret !\p"
	.string "Il y a huit objets\n"
	.string "à ramasser par ici.$"

BattlePyramid_Text_SevenItemsRemaining2::
	.string "Comme tu as gagné, je vais te dire\n"
	.string "un petit secret !\p"
	.string "Il reste sept objets à\n"
	.string "ramasser par ici.$"

BattlePyramid_Text_SixItemsRemaining2::
	.string "Comme tu as gagné, je vais te dire\n"
	.string "un petit secret !\p"
	.string "Il reste six objets à\n"
	.string "ramasser par ici.$"

BattlePyramid_Text_FiveItemsRemaining2::
	.string "Comme tu as gagné, je vais te dire\n"
	.string "un petit secret !\p"
	.string "Il reste cinq objets à\n"
	.string "ramasser par ici.$"

BattlePyramid_Text_FourItemsRemaining2::
	.string "Comme tu as gagné, je vais te dire\n"
	.string "un petit secret !\p"
	.string "Il reste quatre objets à\n"
	.string "ramasser par ici.$"

BattlePyramid_Text_ThreeItemsRemaining2::
	.string "Comme tu as gagné, je vais te dire\n"
	.string "un petit secret !\p"
	.string "Il reste trois objets à\n"
	.string "ramasser par ici.$"

BattlePyramid_Text_TwoItemsRemaining2::
	.string "Comme tu as gagné, je vais te dire\n"
	.string "un petit secret !\p"
	.string "Il reste deux objets à\n"
	.string "ramasser par ici.$"

BattlePyramid_Text_OneItemRemaining2::
	.string "Comme tu as gagné, je vais te dire\n"
	.string "un petit secret !\p"
	.string "Il n'y a qu'un seul objet\n"
	.string "à ramasser par ici.$"

BattlePyramid_Text_ZeroItemsRemaining2::
	.string "Comme tu as gagné, je vais te dire\n"
	.string "un petit secret !\p"
	.string "Il ne reste plus rien à\n"
	.string "ramasser par ici.$"

BattlePyramid_Text_EightItemsRemaining3::
	.string "Comment va ton stock d'objets ?\p"
	.string "Je parie qu'il reste huit objets\n"
	.string "à trouver sur cet étage.$"

BattlePyramid_Text_SevenItemsRemaining3::
	.string "Comment va ton stock d'objets ?\p"
	.string "Je parie qu'il reste sept objets\n"
	.string "à trouver sur cet étage.$"

BattlePyramid_Text_SixItemsRemaining3::
	.string "Comment va ton stock d'objets ?\p"
	.string "Je dirais qu'il reste six objets\n"
	.string "à trouver sur cet étage.$"

BattlePyramid_Text_FiveItemsRemaining3::
	.string "Comment va ton stock d'objets ?\p"
	.string "Je dirais qu'il reste cinq objets\n"
	.string "à trouver sur cet étage.$"

BattlePyramid_Text_FourItemsRemaining3::
	.string "Comment va ton stock d'objets ?\p"
	.string "Je dirais qu'il reste quatre objets\n"
	.string "à trouver sur cet étage.$"

BattlePyramid_Text_ThreeItemsRemaining3::
	.string "Comment va ton stock d'objets ?\p"
	.string "Je parie qu'il reste trois objets\n"
	.string "à trouver sur cet étage.$"

BattlePyramid_Text_TwoItemsRemaining3::
	.string "Comment va ton stock d'objets ?\p"
	.string "Je dirais qu'il reste deux objets\n"
	.string "à trouver sur cet étage.$"

BattlePyramid_Text_OneItemRemaining3::
	.string "Comment va ton stock d'objets ?\p"
	.string "Je dirais qu'il ne reste qu'un objet\n"
	.string "à trouver sur cet étage.$"

BattlePyramid_Text_ZeroItemsRemaining3::
	.string "Comment va ton stock d'objets ?\p"
	.string "Je crois qu'il n'y a plus d'objets\n"
	.string "à trouver à cet étage.\l"
	.string "Fais attention !$"

BattlePyramid_Text_EightItemsRemaining4::
	.string "Tu es fort, alors tu mérites\n"
	.string "un indice !\p"
	.string "Il semble qu'il reste encore huit\n"
	.string "objets au sol.$"

BattlePyramid_Text_SevenItemsRemaining4::
	.string "Tu es fort, alors tu mérites\n"
	.string "un indice !\p"
	.string "Il semble qu'il reste encore sept\n"
	.string "objets au sol.$"

BattlePyramid_Text_SixItemsRemaining4::
	.string "Tu es fort, alors tu mérites\n"
	.string "un indice !\p"
	.string "Il semble qu'il reste encore six\n"
	.string "objets au sol.$"

BattlePyramid_Text_FiveItemsRemaining4::
	.string "Tu es fort, alors tu mérites\n"
	.string "un indice !\p"
	.string "Il semble qu'il reste encore cinq\n"
	.string "objets au sol.$"

BattlePyramid_Text_FourItemsRemaining4::
	.string "Tu es fort, alors tu mérites\n"
	.string "un indice !\p"
	.string "Il semble qu'il reste encore quatre\n"
	.string "objets au sol.$"

BattlePyramid_Text_ThreeItemsRemaining4::
	.string "Tu es fort, alors tu mérites\n"
	.string "un indice !\p"
	.string "Il semble qu'il reste encore trois\n"
	.string "objets au sol.$"

BattlePyramid_Text_TwoItemsRemaining4::
	.string "Tu es fort, alors tu mérites\n"
	.string "un indice !\p"
	.string "Il semble qu'il reste encore deux\n"
	.string "objets au sol.$"

BattlePyramid_Text_OneItemRemaining4::
	.string "Tu es fort, alors tu mérites\n"
	.string "un indice !\p"
	.string "Il semble qu'il ne reste plus qu'un seul\n"
	.string "objet au sol.$"

BattlePyramid_Text_ZeroItemsRemaining4::
	.string "Tu es fort, alors tu mérites\n"
	.string "un indice !\p"
	.string "Il ne semble plus y avoir d'\n"
	.string "objets au sol.$"

BattlePyramid_Text_EightItemsRemaining5::
	.string "À cet étage de la PYRAMIDE,\n"
	.string "j'ai entendu dire qu'il y a huit objets…$"

BattlePyramid_Text_SevenItemsRemaining5::
	.string "À cet étage de la PYRAMIDE,\n"
	.string "j'ai entendu dire qu'il y a sept objets…$"

BattlePyramid_Text_SixItemsRemaining5::
	.string "À cet étage de la PYRAMIDE,\n"
	.string "on dit qu'il y a six objets…$"

BattlePyramid_Text_FiveItemsRemaining5::
	.string "À cet étage de la PYRAMIDE,\n"
	.string "j'ai entendu dire qu'il y a cinq objets…$"

BattlePyramid_Text_FourItemsRemaining5::
	.string "À cet étage de la PYRAMIDE,\n"
	.string "j'ai entendu dire qu'il y a quatre objets…$"

BattlePyramid_Text_ThreeItemsRemaining5::
	.string "À cet étage de la PYRAMIDE,\n"
	.string "j'ai entendu dire qu'il y a trois objets…$"

BattlePyramid_Text_TwoItemsRemaining5::
	.string "À cet étage de la PYRAMIDE,\n"
	.string "on dit qu'il y a deux objets…$"

BattlePyramid_Text_OneItemRemaining5::
	.string "À cet étage de la PYRAMIDE,\n"
	.string "on dit qu'il y a un objet…$"

BattlePyramid_Text_ZeroItemsRemaining5::
	.string "À cet étage de la PYRAMIDE,\n"
	.string "on dit qu'il n'y a aucun objet…$"

BattlePyramid_Text_EightItemsRemaining6::
	.string "As-tu récupéré des objets ?\p"
	.string "Je crois qu'il reste huit autres\n"
	.string "objets à cet étage.$"

BattlePyramid_Text_SevenItemsRemaining6::
	.string "As-tu récupéré des objets ?\p"
	.string "Je crois qu'il reste sept autres\n"
	.string "objets à cet étage.$"

BattlePyramid_Text_SixItemsRemaining6::
	.string "As-tu récupéré des objets ?\p"
	.string "Je crois qu'il reste six autres\n"
	.string "objets à cet étage.$"

BattlePyramid_Text_FiveItemsRemaining6::
	.string "As-tu récupéré des objets ?\p"
	.string "Je crois qu'il reste cinq autres\n"
	.string "objets à cet étage.$"

BattlePyramid_Text_FourItemsRemaining6::
	.string "As-tu récupéré des objets ?\p"
	.string "Je crois qu'il reste quatre autres\n"
	.string "objets à cet étage.$"

BattlePyramid_Text_ThreeItemsRemaining6::
	.string "As-tu récupéré des objets ?\p"
	.string "Je crois qu'il reste trois autres\n"
	.string "objets à cet étage.$"

BattlePyramid_Text_TwoItemsRemaining6::
	.string "As-tu récupéré des objets ?\p"
	.string "Je crois qu'il reste deux autres\n"
	.string "objets à cet étage.$"

BattlePyramid_Text_OneItemRemaining6::
	.string "As-tu récupéré des objets ?\p"
	.string "Je crois qu'il reste un autre\n"
	.string "objet à cet étage.$"

BattlePyramid_Text_ZeroItemsRemaining6::
	.string "As-tu récupéré des objets ?\p"
	.string "Je crois qu'il n'y a plus d'\n"
	.string "objets à cet étage.$"

BattlePyramid_Text_SevenTrainersRemaining1::
	.string "Tu étais vraiment génial !\p"
	.string "Mais il reste encore sept DRESSEURS\n"
	.string "coriaces en dehors de moi !$"

BattlePyramid_Text_SixTrainersRemaining1::
	.string "Tu étais vraiment génial !\p"
	.string "Mais il reste encore six DRESSEURS\n"
	.string "coriaces en dehors de moi !$"

BattlePyramid_Text_FiveTrainersRemaining1::
	.string "Tu étais vraiment génial !\p"
	.string "Mais il reste encore cinq DRESSEURS\n"
	.string "coriaces en dehors de moi !$"

BattlePyramid_Text_FourTrainersRemaining1::
	.string "Tu étais vraiment génial !\p"
	.string "Mais il reste encore quatre DRESSEURS\n"
	.string "coriaces en dehors de moi !$"

BattlePyramid_Text_ThreeTrainersRemaining1::
	.string "Tu étais vraiment génial !\p"
	.string "Mais il reste encore trois DRESSEURS\n"
	.string "coriaces en dehors de moi !$"

BattlePyramid_Text_TwoTrainersRemaining1::
	.string "Tu étais vraiment génial !\p"
	.string "Mais il reste encore deux DRESSEURS\n"
	.string "coriaces en dehors de moi !$"

BattlePyramid_Text_OneTrainersRemaining1::
	.string "Tu étais vraiment génial !\p"
	.string "Mais il reste encore un DRESSEUR\n"
	.string "coriace en dehors de moi !$"

BattlePyramid_Text_ZeroTrainersRemaining1::
	.string "Tu étais vraiment génial !\p"
	.string "Il ne reste plus personne\n"
	.string "qui puisse te battre !$"

BattlePyramid_Text_SevenTrainersRemaining2::
	.string "C'est tellement frustrant !\p"
	.string "Mais il reste sept DRESSEURS !\n"
	.string "Quelqu'un va te remettre à ta place !$"

BattlePyramid_Text_SixTrainersRemaining2::
	.string "C'est tellement frustrant !\p"
	.string "Mais il reste six DRESSEURS !\n"
	.string "Quelqu'un va te remettre à ta place !$"

BattlePyramid_Text_FiveTrainersRemaining2::
	.string "C'est tellement frustrant !\p"
	.string "Mais il reste cinq DRESSEURS !\n"
	.string "Quelqu'un va te remettre à ta place !$"

BattlePyramid_Text_FourTrainersRemaining2::
	.string "C'est tellement frustrant !\p"
	.string "Mais il reste quatre DRESSEURS !\n"
	.string "Quelqu'un va te remettre à ta place !$"

BattlePyramid_Text_ThreeTrainersRemaining2::
	.string "C'est tellement frustrant !\p"
	.string "Mais il reste trois DRESSEURS !\n"
	.string "Quelqu'un va te remettre à ta place !$"

BattlePyramid_Text_TwoTrainersRemaining2::
	.string "C'est tellement frustrant !\p"
	.string "Mais il reste deux DRESSEURS !\n"
	.string "Quelqu'un va te remettre à ta place !$"

BattlePyramid_Text_OneTrainersRemaining2::
	.string "C'est tellement frustrant !\p"
	.string "Mais il ne reste qu'un DRESSEUR !\n"
	.string "Je suis sûr que tu vas être remis à ta place !$"

BattlePyramid_Text_ZeroTrainersRemaining2::
	.string "C'est tellement frustrant !\p"
	.string "Mais il n'y a plus de DRESSEURS\n"
	.string "qui peuvent t'affronter !$"

BattlePyramid_Text_SevenTrainersRemaining3::
	.string "C'est impressionnant !\p"
	.string "Mais il reste sept DRESSEURS\n"
	.string "sur cet étage. Peux-tu tous les battre ?$"

BattlePyramid_Text_SixTrainersRemaining3::
	.string "C'est impressionnant !\p"
	.string "Mais il reste six DRESSEURS\n"
	.string "sur cet étage. Peux-tu tous les battre ?$"

BattlePyramid_Text_FiveTrainersRemaining3::
	.string "C'est impressionnant !\p"
	.string "Mais il reste cinq DRESSEURS\n"
	.string "sur cet étage. Peux-tu tous les battre ?$"

BattlePyramid_Text_FourTrainersRemaining3::
	.string "C'est impressionnant !\p"
	.string "Mais il reste quatre DRESSEURS\n"
	.string "sur cet étage. Peux-tu tous les battre ?$"

BattlePyramid_Text_ThreeTrainersRemaining3::
	.string "C'est impressionnant !\p"
	.string "Mais il reste trois DRESSEURS\n"
	.string "sur cet étage. Peux-tu tous les battre ?$"

BattlePyramid_Text_TwoTrainersRemaining3::
	.string "C'est impressionnant !\p"
	.string "Mais il reste deux DRESSEURS\n"
	.string "sur cet étage. Peux-tu les battre tous les deux ?$"

BattlePyramid_Text_OneTrainersRemaining3::
	.string "C'est assez impressionnant !\p"
	.string "Mais il reste encore un DRESSEUR\n"
	.string "sur cet étage. Tu peux l'emporter ?$"

BattlePyramid_Text_ZeroTrainersRemaining3::
	.string "C'est assez impressionnant !\p"
	.string "Tu as battu tous les DRESSEURS\n"
	.string "de cet étage.$"

BattlePyramid_Text_SevenTrainersRemaining4::
	.string "Peut-être que tu pourrais vaincre\n"
	.string "les sept DRESSEURS restants à cet étage.$"

BattlePyramid_Text_SixTrainersRemaining4::
	.string "Tu pourrais peut-être affronter\n"
	.string "les six DRESSEURS restants à cet étage.$"

BattlePyramid_Text_FiveTrainersRemaining4::
	.string "Tu pourrais peut-être affronter\n"
	.string "les cinq DRESSEURS restants à cet étage.$"

BattlePyramid_Text_FourTrainersRemaining4::
	.string "Tu pourrais peut-être affronter\n"
	.string "les quatre DRESSEURS restants à cet étage.$"

BattlePyramid_Text_ThreeTrainersRemaining4::
	.string "Peut-être que tu pourrais vaincre\n"
	.string "les trois DRESSEURS restants à cet étage.$"

BattlePyramid_Text_TwoTrainersRemaining4::
	.string "Tu pourrais peut-être affronter\n"
	.string "les deux DRESSEURS restants à cet étage.$"

BattlePyramid_Text_OneTrainersRemaining4::
	.string "Peut-être que tu pourrais compléter ta série\n"
	.string "avec le seul DRESSEUR restant à cet étage.$"

BattlePyramid_Text_ZeroTrainersRemaining4::
	.string "Il ne reste plus personne qui\n"
	.string "puisse te battre…$"

BattlePyramid_Text_SevenTrainersRemaining5::
	.string "Tu as peut-être ce qu'il faut pour battre\n"
	.string "les sept DRESSEURS experts qui restent.$"

BattlePyramid_Text_SixTrainersRemaining5::
	.string "Tu as peut-être ce qu'il faut pour battre\n"
	.string "les six DRESSEURS experts qui restent.$"

BattlePyramid_Text_FiveTrainersRemaining5::
	.string "Tu as peut-être ce qu'il faut pour battre\n"
	.string "les cinq DRESSEURS experts qui restent.$"

BattlePyramid_Text_FourTrainersRemaining5::
	.string "Tu as peut-être ce qu'il faut pour battre\n"
	.string "les quatre DRESSEURS experts qui restent.$"

BattlePyramid_Text_ThreeTrainersRemaining5::
	.string "Tu as peut-être ce qu'il faut pour battre\n"
	.string "les trois DRESSEURS experts qui restent.$"

BattlePyramid_Text_TwoTrainersRemaining5::
	.string "Tu as peut-être ce qu'il faut pour battre\n"
	.string "les deux DRESSEURS experts qui restent.$"

BattlePyramid_Text_OneTrainersRemaining5::
	.string "Tu as peut-être ce qu'il faut pour battre\n"
	.string "le seul DRESSEUR expert qui reste.$"

BattlePyramid_Text_ZeroTrainersRemaining5::
	.string "Tes compétences sont irréprochables.\p"
	.string "Il n'y a plus de DRESSEURS ici\n"
	.string "qui aient une chance de te battre.$"

BattlePyramid_Text_SevenTrainersRemaining6::
	.string "Peux-tu continuer à gagner contre\n"
	.string "les sept DRESSEURS restants ?$"

BattlePyramid_Text_SixTrainersRemaining6::
	.string "Peux-tu continuer à gagner face aux\n"
	.string "six DRESSEURS restants ?$"

BattlePyramid_Text_FiveTrainersRemaining6::
	.string "Peux-tu continuer à gagner face aux\n"
	.string "cinq DRESSEURS restants ?$"

BattlePyramid_Text_FourTrainersRemaining6::
	.string "Peux-tu continuer à gagner face aux\n"
	.string "quatre DRESSEURS restants ?$"

BattlePyramid_Text_ThreeTrainersRemaining6::
	.string "Peux-tu continuer à gagner contre\n"
	.string "les trois DRESSEURS restants ?$"

BattlePyramid_Text_TwoTrainersRemaining6::
	.string "Peux-tu continuer à gagner face aux\n"
	.string "deux DRESSEURS restants ?$"

BattlePyramid_Text_OneTrainersRemaining6::
	.string "Peux-tu continuer à gagner face au\n"
	.string "dernier DRESSEUR restant ?$"

BattlePyramid_Text_ZeroTrainersRemaining6::
	.string "Il ne reste plus aucun DRESSEUR\n"
	.string "capable de t'affronter…$"
