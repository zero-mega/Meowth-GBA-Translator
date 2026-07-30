.set LOCALID_ATTENDANT, 1
.set LOCALID_BRANDON, 2

BattleFrontier_BattlePyramidTop_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, BattleFrontier_BattlePyramidTop_OnResume
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BattleFrontier_BattlePyramidTop_OnFrame
	map_script MAP_SCRIPT_ON_TRANSITION, BattleFrontier_BattlePyramidTop_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, BattleFrontier_BattlePyramidTop_OnWarp
	.byte 0

BattleFrontier_BattlePyramidTop_OnTransition:
	pyramid_updatelight 200, PYRAMID_LIGHT_SET_RADIUS
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidTop_OnWarp:
	map_script_2 VAR_TEMP_1, 0, BattleFrontier_BattlePyramidTop_EventScript_SetUpObjects
	.2byte 0

BattleFrontier_BattlePyramidTop_EventScript_SetUpObjects::
	setvar VAR_TEMP_1, 1
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	goto_if_ne VAR_TEMP_C, 0, BattleFrontier_BattlePyramidTop_EventScript_EndSetUpObjects
	setobjectxyperm LOCALID_BRANDON, 0, 0
BattleFrontier_BattlePyramidTop_EventScript_EndSetUpObjects::
	end

BattleFrontier_BattlePyramidTop_OnResume:
	frontier_getbrainstatus
	goto_if_eq VAR_RESULT, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattlePyramidTop_EventScript_CheckChallengeStatus
	call BattleFrontier_EventScript_SetBrainObjectGfx
BattleFrontier_BattlePyramidTop_EventScript_CheckChallengeStatus::
	copyvar VAR_TEMP_C, VAR_RESULT
	frontier_getstatus
	switch VAR_TEMP_CHALLENGE_STATUS
	case 0, BattleFrontier_BattlePyramidTop_EventScript_ReadyChallenge
	case CHALLENGE_STATUS_SAVING, BattleFrontier_BattlePyramid_EventScript_WarpToLobby
	case CHALLENGE_STATUS_PAUSED, BattleFrontier_BattlePyramidTop_EventScript_ReadyChallenge
	frontier_get FRONTIER_DATA_BATTLE_OUTCOME
	goto_if_eq VAR_RESULT, B_OUTCOME_LOST, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	goto_if_eq VAR_RESULT, B_OUTCOME_DREW, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	goto_if_eq VAR_RESULT, B_OUTCOME_FORFEITED, BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost
	end

BattleFrontier_BattlePyramidTop_OnFrame:
	map_script_2 VAR_TEMP_PLAYING_PYRAMID_MUSIC, 0, BattleFrontier_BattlePyramidTop_EventScript_PlayPyramidMusic
	map_script_2 VAR_TEMP_F, 1, BattleFrontier_BattlePyramidTop_EventScript_ShowMapName
	.2byte 0

BattleFrontier_BattlePyramidTop_EventScript_PlayPyramidMusic::
	playbgm MUS_B_PYRAMID_TOP, FALSE
	setvar VAR_TEMP_PLAYING_PYRAMID_MUSIC, 1
	end

BattleFrontier_BattlePyramidTop_EventScript_ShowMapName::
	special ShowMapNamePopup
	setvar VAR_TEMP_F, 0
	end

BattleFrontier_BattlePyramidTop_EventScript_ReadyChallenge::
	pyramid_save CHALLENGE_STATUS_SAVING
	special SavePlayerParty
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, 0
	pyramid_settrainers
	frontier_setpartyorder FRONTIER_PARTY_SIZE
	setvar VAR_TEMP_F, 1
	end

BattleFrontier_BattlePyramidTop_EventScript_Attendant::
	lock
	faceplayer
	goto_if_ne VAR_TEMP_D, 0, BattleFrontier_BattlePyramidTop_EventScript_StepForwardWhenReady
	goto_if_ne VAR_TEMP_C, FRONTIER_BRAIN_NOT_READY, BattleFrontier_BattlePyramidTop_EventScript_BrandonHereMoveAside
	msgbox BattleFrontier_BattlePyramidTop_Text_ReachedSummitUpYouGo, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePyramidTop_Movement_AttendantMoveAside
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, BattleFrontier_BattlePyramidTop_Movement_PlayerClimbToTop
	waitmovement 0
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePyramidTop_Movement_AttendantBlockPath
	waitmovement 0
	message BattleFrontier_BattlePyramidTop_Text_PlayerConqueredPyramid
	waitmessage
	playfanfare MUS_OBTAIN_B_POINTS
	waitfanfare
	closemessage
BattleFrontier_BattlePyramidTop_EventScript_WarpToLobbyWon::
	frontier_set FRONTIER_DATA_CHALLENGE_STATUS, CHALLENGE_STATUS_WON
	warp MAP_BATTLE_FRONTIER_BATTLE_PYRAMID_LOBBY, 7, 13
	waitstate
	end

BattleFrontier_BattlePyramidTop_EventScript_StepForwardWhenReady::
	msgbox BattleFrontier_BattlePyramidTop_Text_StepForwardWhenReady, MSGBOX_DEFAULT
	closemessage
	end

BattleFrontier_BattlePyramidTop_EventScript_BrandonHereMoveAside::
	msgbox BattleFrontier_BattlePyramidTop_Text_ChiefBeatYouHere, MSGBOX_DEFAULT
	applymovement LOCALID_ATTENDANT, BattleFrontier_BattlePyramidTop_Movement_AttendantMoveAside
	setvar VAR_TEMP_D, 1
	closemessage
	end

BattleFrontier_BattlePyramidTop_EventScript_BattleBrandon::
	lockall
	switch VAR_TEMP_C
	case FRONTIER_BRAIN_GOLD, BattleFrontier_BattlePyramidTop_EventScript_BrandonIntroGold
	case FRONTIER_BRAIN_STREAK, BattleFrontier_BattlePyramidTop_EventScript_BrandonHeardSilverSpeech
	case FRONTIER_BRAIN_STREAK_LONG, BattleFrontier_BattlePyramidTop_EventScript_BrandonHeardGoldSpeech
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePyramidTop_EventScript_BrandonHeardSilverSpeech
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, BattleFrontier_BattlePyramidTop_Movement_CameraPanUp
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidTop_Text_ExplorationsAreGrandestAdventure, MSGBOX_DEFAULT
	closemessage
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
	applymovement LOCALID_BRANDON, BattleFrontier_BattlePyramidTop_Movement_BrandonApproachPlayer
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidTop_Text_ImPyramidKingBrandon, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidTop_EventScript_BattleBrandonSilver
	end

BattleFrontier_BattlePyramidTop_EventScript_BrandonHeardSilverSpeech::
	applymovement LOCALID_BRANDON, BattleFrontier_BattlePyramidTop_Movement_BrandonApproachPlayer
	waitmovement 0
BattleFrontier_BattlePyramidTop_EventScript_BattleBrandonSilver::
	msgbox BattleFrontier_BattlePyramidTop_Text_BringCourageToOurBattle, MSGBOX_DEFAULT
	call BattleFrontier_BattlePyramidTop_EventScript_DoBrandonBattle
	playbgm MUS_B_PYRAMID_TOP, FALSE
	goto_if_eq VAR_RESULT, 1, BattleFrontier_BattlePyramidTop_EventScript_DefeatedBrandonSilver
	goto BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost

BattleFrontier_BattlePyramidTop_EventScript_DefeatedBrandonSilver::
	frontier_getsymbols
	goto_if_ne VAR_RESULT, 0, BattleFrontier_BattlePyramidTop_EventScript_WarpToLobbyWon
	msgbox BattleFrontier_BattlePyramidTop_Text_BrandonFrontierPassPlease, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_SYMBOL
	message BattleFrontier_BattlePyramidTop_Text_ReceivedBraveSymbol
	waitmessage
	waitfanfare
	frontier_givesymbol
	msgbox BattleFrontier_BattlePyramidTop_Text_LookForwardToNextMeeting, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidTop_EventScript_WarpToLobbyWon

BattleFrontier_BattlePyramidTop_EventScript_BrandonIntroGold::
	frontier_get FRONTIER_DATA_HEARD_BRAIN_SPEECH
	goto_if_ne VAR_RESULT, FALSE, BattleFrontier_BattlePyramidTop_EventScript_BrandonHeardGoldSpeech
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, BattleFrontier_BattlePyramidTop_Movement_CameraPanUp
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidTop_Text_BrandonYouveReturned, MSGBOX_DEFAULT
	closemessage
	frontier_set FRONTIER_DATA_HEARD_BRAIN_SPEECH
	applymovement LOCALID_BRANDON, BattleFrontier_BattlePyramidTop_Movement_BrandonApproachPlayer
	waitmovement 0
	msgbox BattleFrontier_BattlePyramidTop_Text_MyCourageIsOffMeter, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidTop_EventScript_BattleBrandonGold
	end

BattleFrontier_BattlePyramidTop_EventScript_BrandonHeardGoldSpeech::
	applymovement LOCALID_BRANDON, BattleFrontier_BattlePyramidTop_Movement_BrandonApproachPlayer
	waitmovement 0
BattleFrontier_BattlePyramidTop_EventScript_BattleBrandonGold::
	msgbox BattleFrontier_BattlePyramidTop_Text_EverythingYouHave, MSGBOX_DEFAULT
	call BattleFrontier_BattlePyramidTop_EventScript_DoBrandonBattle
	playbgm MUS_B_PYRAMID_TOP, FALSE
	goto_if_eq VAR_RESULT, 1, BattleFrontier_BattlePyramidTop_EventScript_DefeatedBrandonGold
	goto BattleFrontier_BattlePyramid_EventScript_WarpToLobbyLost

BattleFrontier_BattlePyramidTop_EventScript_DefeatedBrandonGold::
	frontier_getsymbols
	goto_if_eq VAR_RESULT, 2, BattleFrontier_BattlePyramidTop_EventScript_WarpToLobbyWon
	msgbox BattleFrontier_BattlePyramidTop_Text_BrandonRemarkableHaveThis, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_SYMBOL
	message BattleFrontier_BattlePyramidTop_Text_BraveSymbolTookGoldenShine
	waitmessage
	waitfanfare
	frontier_givesymbol
	msgbox BattleFrontier_BattlePyramidTop_Text_FarewellForNow, MSGBOX_DEFAULT
	goto BattleFrontier_BattlePyramidTop_EventScript_WarpToLobbyWon

BattleFrontier_BattlePyramidTop_EventScript_DoBrandonBattle::
	closemessage
	setvar VAR_0x8004, SPECIAL_BATTLE_PYRAMID
	setvar VAR_0x8005, 0
	special DoSpecialTrainerBattle
	waitstate
	return

BattleFrontier_BattlePyramidTop_Movement_AttendantMoveAside:
	walk_right
	walk_in_place_faster_left
	step_end

BattleFrontier_BattlePyramidTop_Movement_AttendantBlockPath:
	walk_left
	walk_in_place_faster_up
	step_end

BattleFrontier_BattlePyramidTop_Movement_PlayerClimbToTop:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_faster_down
	step_end

BattleFrontier_BattlePyramidTop_Movement_BrandonApproachPlayer:
	walk_fast_down
	step_end

BattleFrontier_BattlePyramidTop_Movement_CameraPanUp:
	walk_slow_up
	walk_slow_up
	delay_16
	step_end

BattleFrontier_BattlePyramidTop_Text_ReachedSummitUpYouGo:
	.string "C'est un plaisir de te voir\n"
	.string "ici ! Tu as atteint le\l"
	.string "sommet de la PYRAMIDE DU\p"
	.string "COMBAT ! Au-dessus se trouve\n"
	.string "le point d'observation de la\p"
	.string "PYRAMIDE. C'est un lieu ouvert\n"
	.string "uniquement à ceux qui ont\p"
	.string "conquis la PYRAMIDE. Maintenant, s'il\n"
	.string "te plaît ! Monte !$"

BattleFrontier_BattlePyramidTop_Text_PlayerConqueredPyramid:
	.string "Le nouveau conquérant de la PYRAMIDE !\n"
	.string "Que le nom {PLAYER} soit connu !$"

BattleFrontier_BattlePyramidTop_Text_ChiefBeatYouHere:
	.string "C'est un plaisir de te voir ici !\p"
	.string "Malheureusement, tu étais deuxième d'une\n"
	.string "infime fraction de temps !\p"
	.string "Notre chef a déjà conquis\n"
	.string "la PYRAMIDE avant toi.\p"
	.string "Cependant, mon jeune explorateur…\n"
	.string "Tu es un DRESSEUR !\p"
	.string "Affirme ta puissance et prends la gloire\n"
	.string "du sommet à notre chef !\p"
	.string "Maintenant, s'il te plaît ! Quand tu seras prêt,\n"
	.string "fais un pas de courage de plus !$"

BattleFrontier_BattlePyramidTop_Text_ExplorationsAreGrandestAdventure:
	.string "Jeune aventurier… Ne trouves-tu pas\p"
	.string "que les explorations sont les\n"
	.string "plus grandes des aventures ?\p"
	.string "Ta propre intelligence ! Ta\p"
	.string "propre force ! Tes propres\p"
	.string "POKéMON ! Et, surtout, seul\p"
	.string "ton courage pour te guider\n"
	.string "à travers des mondes inconnus…$"

BattleFrontier_BattlePyramidTop_Text_ImPyramidKingBrandon:
	.string "Aah, oui, en\n"
	.string "effet cette\p"
	.string "vie est grandiose !\p"
	.string "Grandiose, elle\n"
	.string "l'est ! Hein ?\p"
	.string "Je suis BRANDON !\p"
	.string "Je suis le ROI DE LA\n"
	.string "PYRAMIDE, ce\l"
	.string "qui signifie\p"
	.string "que je suis le maître de\n"
	.string "la PYRAMIDE DE COMBAT !$"

BattleFrontier_BattlePyramidTop_Text_BringCourageToOurBattle:
	.string "Alors !\n"
	.string "Apporte ton courage à notre combat !$"

BattleFrontier_BattlePyramidTop_Text_BrandonFrontierPassPlease:
	.string "BRANDON : Hahahah ! Grandiose, c'était !\n"
	.string "Grandiose, oui, en effet ! Bien joué\p"
	.string "! Tu as gagné la reconnaissance !\n"
	.string "Ton PASSE ZONE, s'il te plaît !$"

BattleFrontier_BattlePyramidTop_Text_ReceivedBraveSymbol:
	.string "Le Symbole Courage a été gravé\n"
	.string "sur le PASSE PARADIS !$"

BattleFrontier_BattlePyramidTop_Text_LookForwardToNextMeeting:
	.string "Jeune explorateur !\n"
	.string "J'attends avec impatience notre prochaine rencontre !$"

BattleFrontier_BattlePyramidTop_Text_BrandonYouveReturned:
	.string "BRANDON\n"
	.string ": …Tu es\p"
	.string "enfin revenu,\n"
	.string "jeune\p"
	.string "explorateur…\n"
	.string "Ton amour de\p"
	.string "l'aventure\p"
	.string "semble venir\p"
	.string "profondément\p"
	.string "de ton cœur.\p"
	.string "Montre-moi ta\n"
	.string "détermination !$"

BattleFrontier_BattlePyramidTop_Text_MyCourageIsOffMeter:
	.string "Bon, alors !\p"
	.string "Je sens que mon courage est\n"
	.string "au maximum !$"

BattleFrontier_BattlePyramidTop_Text_EverythingYouHave:
	.string "Tout ce que tu as !\n"
	.string "Je suis prêt à tout encaisser !$"

BattleFrontier_BattlePyramidTop_Text_BrandonRemarkableHaveThis:
	.string "BRANDON : Hahahah !\n"
	.string "Remarquable !\l"
	.string "Oui, c'est grandiose, en effet !\p"
	.string "Jeune explorateur !\p"
	.string "Tu m'as battu de bout en bout !\n"
	.string "Tiens ! Je veux que tu prennes ça !$"

BattleFrontier_BattlePyramidTop_Text_BraveSymbolTookGoldenShine:
	.string "Le Symbole Courage a pris\n"
	.string "une lueur dorée !$"

BattleFrontier_BattlePyramidTop_Text_FarewellForNow:
	.string "Ah, oui ! Ça montre bien que\n"
	.string "j'ai encore beaucoup à apprendre !\p"
	.string "Que nos chemins se croisent à nouveau !\n"
	.string "Adieu pour l'instant, jeune explorateur !$"

BattleFrontier_BattlePyramidTop_Text_StepForwardWhenReady:
	.string "Maintenant, quand tu seras prêt, prends ton courage\n"
	.string "et avance.$"

