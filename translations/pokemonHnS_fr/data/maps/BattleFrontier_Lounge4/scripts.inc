BattleFrontier_Lounge4_MapScripts::
	.byte 0

BattleFrontier_Lounge4_EventScript_Woman::
	msgbox BattleFrontier_Lounge4_Text_WonderIfInterviewsAiring, MSGBOX_NPC
	end

BattleFrontier_Lounge4_EventScript_Cook::
	msgbox BattleFrontier_Lounge4_Text_IfIOpenedRestaurantHere, MSGBOX_NPC
	end

BattleFrontier_Lounge4_EventScript_Man::
	msgbox BattleFrontier_Lounge4_Text_NeedBreatherAfterBattles, MSGBOX_NPC
	end

BattleFrontier_Lounge4_Text_WonderIfInterviewsAiring:
	.string "Je me demande s'ils vont diffuser des interviews\n"
	.string "avec des DRESSEURS coriaces aujourd'hui ?$"

BattleFrontier_Lounge4_Text_IfIOpenedRestaurantHere:
	.string "Si j'ouvrais un restaurant ici,\n"
	.string "ça rapporterait à coup sûr.$"

BattleFrontier_Lounge4_Text_NeedBreatherAfterBattles:
	.string "Ouf…\p"
	.string "J'ai besoin de reprendre mon souffle après\n"
	.string "des combats intenses…\p"
	.string "Mais même maintenant, je ne prends jamais\n"
	.string "de pause pour élaborer stratégie et combos.$"

