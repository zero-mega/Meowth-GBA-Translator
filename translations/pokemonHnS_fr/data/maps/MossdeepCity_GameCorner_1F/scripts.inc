MossdeepCity_GameCorner_1F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, MossdeepCity_GameCorner_1F_OnFrame
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, MossdeepCity_GameCorner_1F_OnWarp
	map_script MAP_SCRIPT_ON_LOAD, CableClub_OnLoad
	.byte 0

MossdeepCity_GameCorner_1F_OnWarp:
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_CheckTurnAttendant
	.2byte 0

MossdeepCity_GameCorner_1F_OnFrame:
	map_script_2 VAR_CABLE_CLUB_STATE, USING_MINIGAME, CableClub_EventScript_ExitMinigameRoom
	.2byte 0

@ Script is redundant, the label in the goto also does lock and faceplayer
MossdeepCity_GameCorner_1F_EventScript_InfoMan::
	lock
	faceplayer
	goto MossdeepCity_GameCorner_1F_EventScript_InfoMan2
	release
	end

@ Script is redundant, the label in the goto also does lock and faceplayer
MossdeepCity_GameCorner_1F_EventScript_OldMan::
	lock
	faceplayer
	goto MossdeepCity_GameCorner_1F_EventScript_OldMan2
	release
	end


@ Everything below is leftover from RS
@ The house that was here in RS was moved to Sootopolis and replaced by the Game Corner
@ The text below is unused and duplicated in its replacement in Sootopolis City
@ And the BG Door event was moved inaccessibly into a wall

RS_MysteryEventsHouse_EventScript_Door::
	msgbox RS_MysteryEventsHouse_Text_DoorIsLocked, MSGBOX_SIGN
	end

RS_MysteryEventsHouse_Text_OldManGreeting:
	.string "Quand j'étais jeune, j'ai parcouru le monde\n"
	.string "en tant que DRESSEUR de POKéMON.\p"
	.string "Maintenant que je suis un vieux radoteur,\n"
	.string "mon seul amusement est de regarder les jeunes\l"
	.string "DRESSEURS se battre.$"

RS_MysteryEventsHouse_Text_DoorIsLocked:
	.string "La porte semble verrouillée.$"

RS_MysteryEventsHouse_Text_ChallengeVisitingTrainer:
	.string "Un DRESSEUR nommé {STR_VAR_1} visite\n"
	.string "ma maison.\p"
	.string "Tu veux défier\n"
	.string "{STR_VAR_1} ?$"

RS_MysteryEventsHouse_Text_YouWontBattle:
	.string "Tu ne veux pas te battre ? Je suis déçu\n"
	.string "de ne pas pouvoir te voir combattre…$"

RS_MysteryEventsHouse_Text_KeepItToA3On3:
	.string "Oh, bien, bien !\p"
	.string "Mais ma maison n'est pas très solide.\p"
	.string "Pourrais-je te demander de te limiter\n"
	.string "à un combat 3 contre 3 ?$"

RS_MysteryEventsHouse_Text_SaveYourProgress:
	.string "Avant que vous deux combattiez, vous devriez\n"
	.string "sauvegarder votre progression.$"

RS_MysteryEventsHouse_Text_HopeToSeeAGoodMatch:
	.string "J'espère voir un bon match !$"

RS_MysteryEventsHouse_Text_BattleTie:
	.string "Alors, ça s'est terminé par une impasse.\p"
	.string "C'était un match brillant où\n"
	.string "aucun des deux n'a cédé un pouce !$"

RS_MysteryEventsHouse_Text_BattleWon:
	.string "C'était superbe !\p"
	.string "Pourquoi, c'était comme me revoir\n"
	.string "dans ma jeunesse !$"

RS_MysteryEventsHouse_Text_BattleLost:
	.string "Ah, tant pis pour toi !\p"
	.string "Mais c'était un bon match.\n"
	.string "J'espère que tu gagneras la prochaine fois.$"
