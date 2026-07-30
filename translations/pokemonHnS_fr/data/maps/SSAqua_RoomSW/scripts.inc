SSAqua_RoomSW_MapScripts::
	.byte 0

SSAqua_RoomSW_EventScript_Cassie::
	trainerbattle_single TRAINER_CASSIE SSAqua_RoomSW_Text_BeautyCassieSeen, SSAqua_RoomSW_Text_BeautyCassieBeaten
	msgbox SSAqua_RoomSW_Text_BeautyCassieAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSW_EventScript_Clyde::
	trainerbattle_single TRAINER_CLYDE SSAqua_RoomSW_Text_GuitaristClydeSeen, SSAqua_RoomSW_Text_GuitaristClydeBeaten
	msgbox SSAqua_RoomSW_Text_GuitaristClydeAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomSW_Text_BeautyCassieSeen:
    .string "J'essaie d'oublier mes peines.\n"
    .string "Combattons !$"

SSAqua_RoomSW_Text_BeautyCassieBeaten:
    .string "Mon coeur saigne…$"

SSAqua_RoomSW_Text_BeautyCassieAfterBattle:
    .string "Un voyage est idéal pour surmonter\n"
    .string "un chagrin d'amour.\p"
    .string "Mais un trajet en Paquebot est trop court\n"
    .string "pour faire son deuil.$"

SSAqua_RoomSW_Text_GuitaristClydeSeen:
    .string "Je vais passer une audition pour mes chansons\n"
    .string "à la TOUR RADIO de DOUBLONVILLE.$"

SSAqua_RoomSW_Text_GuitaristClydeBeaten:
    .string "Ouah ! Distorsion totale !$"

SSAqua_RoomSW_Text_GuitaristClydeAfterBattleMobile:
    .string "J'allais faire mes débuts à la\n"
    .string "TOUR DE COMBAT...\p"
    .string "Je devrais retourner à CARMIN SUR MER\n"
    .string "et reprendre mon entraînement...$"

SSAqua_RoomSW_Text_GuitaristClydeAfterBattle:
    .string "En parlant de la STATION RADIO,\n"
    .string "quel est le numéro chance de cette semaine ?$"
