.set LOCALID_INDIGOJUNCTION_POLICEMAN, 1
.set LOCALID_INDIGOJUNCTION_JANINE, 4

ReceptionGate_MapScripts::
	.byte 0

ReceptionGate_EventScript_Janine::
    lock
    faceplayer
    msgbox ReceptionGate_Text_Janine, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_ROUTE22_JANINE
    removeobject LOCALID_INDIGOJUNCTION_JANINE
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_JANINE
    release
    end

ReceptionGate_Text_Janine:
    .string "JANO : Je suis en route vers la\n"
    .string "maison de mon père pour lui apporter\p"
    .string "son déjeuner. Le CONSEIL DES 4 n'a\n"
    .string "pas de repos jour et nuit. C'est\l"
    .string "un travail si dur, tu sais ?\p"
    .string "Si tu es prêt pour un autre\n"
    .string "combat, je serai au DOJO plus tard.$"


ReceptionGate_EventScript_Officer::
    msgbox VictoryRoadGate_Text_EightBadges, MSGBOX_NPC
    end

ReceptionGate_Trigger::
    lock
    playse SE_PIN
    applymovement LOCALID_INDIGOJUNCTION_POLICEMAN, Common_Movement_ExclamationMark
    delay 20
    goto_if_lt VAR_ECRUTEAK_CITY_THEATER, 8, ReceptionGate_EventScript_Kimono
    msgbox VictoryRoadGate_Text_Officer, MSGBOX_DEFAULT
    goto_if_unset FLAG_BADGE08_GET, ReceptionGate_EventScript_NotEnough
    msgbox VictoryRoadGate_Text_EightBadges, MSGBOX_DEFAULT
    closemessage
    setvar VAR_ROUTE27_STATE, 2
    release
    end

ReceptionGate_EventScript_Kimono::
    msgbox VictoryRoadGate_Text_Kimono, MSGBOX_DEFAULT
    closemessage
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
    waitmovement 0
    release
    end 

ReceptionGate_EventScript_NotEnough::
    msgbox VictoryRoadGate_Text_NotEnoughBadges, MSGBOX_DEFAULT
    closemessage
    applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
    waitmovement 0
    release
    end

ReceptionGate_EventScript_SilverGuard::
    msgbox VictoryRoadGate_Text_LeftBlackBelt, MSGBOX_NPC
    end
ReceptionGate_EventScript_KantoGuard::
    msgbox VictoryRoadGate_Text_RightBlackBelt, MSGBOX_NPC
    end

VictoryRoadGate_Text_Officer:
    .string "Seuls les Dresseurs qui se sont prouvés\n"
    .string "peuvent passer.$"

VictoryRoadGate_Text_Kimono:
    .string "Désolé gamin, ce chemin est fermé jusqu'à\n"
    .string "ce que quelqu'un s'occupe de ce\l"
    .string "POKéMON légendaire...$"

VictoryRoadGate_Text_NotEnoughBadges:
    .string "Tu n'as pas tous les BADGES D'ARÈNE\n"
    .string "de JOHTO.\p"
    .string "Désolé, mais je ne peux pas te laisser\n"
    .string "passer.$"

VictoryRoadGate_Text_EightBadges:
    .string "Oh ! Les huit BADGES de JOHTO !\p"
    .string "Passe, s'il te plaît !$"

VictoryRoadGate_Text_LeftBlackBelt:
    .string "Ce chemin mène au MONT ARGENTA.\p"
    .string "Tu y verras des POKéMON\n"
    .string "terriblement forts.$"

VictoryRoadGate_Text_RightBlackBelt:
    .string "Direction la LIGUE POKéMON ?\p"
    .string "Le CONSEIL DES 4 est si fort que c'est\n"
    .string "flippant, et ils t'attendent !$"
