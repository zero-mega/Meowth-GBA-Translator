SSAqua_RoomSSW_MapScripts::
	.byte 0

SSAqua_RoomSSW_EventScript_Lyle::
	trainerbattle_single TRAINER_LYLE SSAqua_RoomSSW_Text_FirebreatherLyleSeen, SSAqua_RoomSSW_Text_FirebreatherLyleBeaten
	msgbox SSAqua_RoomSSW_Text_FirebreatherLyleAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSSW_EventScript_Ken::
	trainerbattle_single TRAINER_KEN SSAqua_RoomSSW_Text_BugCatcherKenSeen, SSAqua_RoomSSW_Text_BugCatcherKenBeaten
	msgbox SSAqua_RoomSSW_Text_BugCatcherKenAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSSW_Text_FirebreatherLyleSeen:
    .string "Je vais à KANTO pour faire\n"
    .string "des spectacles de cracheur de feu !$"

SSAqua_RoomSSW_Text_FirebreatherLyleBeaten:
    .string "Pfff… La flamme est minuscule…$"

SSAqua_RoomSSW_Text_FirebreatherLyleAfterBattle:
    .string "Je suppose que le feu est faible en mer.\n"
    .string "Ça n'a pas d'importance ? Vraiment ?$"

SSAqua_RoomSSW_Text_BugCatcherKenSeen:
    .string "Je rends visite à ma grand-mère pour\n"
    .string "attraper des insectes !$"

SSAqua_RoomSSW_Text_BugCatcherKenBeaten:
    .string "Ooh, waouh. Tu es costaud !$"

SSAqua_RoomSSW_Text_BugCatcherKenAfterBattle:
    .string "Tu peux trouver plein de POKéMON\n"
    .string "dans les arbres de JOHTO !$"
