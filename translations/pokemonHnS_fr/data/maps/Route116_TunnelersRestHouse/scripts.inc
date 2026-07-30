Route116_TunnelersRestHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route116_TunnelersRestHouse_OnTransition
	.byte 0

Route116_TunnelersRestHouse_OnTransition:
	setflag FLAG_LANDMARK_TUNNELERS_REST_HOUSE
	end

Route116_TunnelersRestHouse_EventScript_Tunneler1::
	msgbox Route116_TunnelersRestHouse_Text_WeHadToStopBoring, MSGBOX_NPC
	end

Route116_TunnelersRestHouse_EventScript_Tunneler2::
	msgbox Route116_TunnelersRestHouse_Text_ManDiggingHisWayToVerdanturf, MSGBOX_NPC
	end

Route116_TunnelersRestHouse_EventScript_Tunneler3::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, Route116_TunnelersRestHouse_EventScript_TunnelOpened
	msgbox Route116_TunnelersRestHouse_Text_GetToVerdanturfWithoutTunnel, MSGBOX_DEFAULT
	release
	end

Route116_TunnelersRestHouse_EventScript_TunnelOpened::
	msgbox Route116_TunnelersRestHouse_Text_TunnelHasGoneThrough, MSGBOX_DEFAULT
	release
	end

Route116_TunnelersRestHouse_Text_WeHadToStopBoring:
	.string "Ce TUNNEL\p"
	.string "CROMARTRE là-bas…\n"
	.string "Au début, on avait une\l"
	.string "énorme équipe qui perçait\p"
	.string "la roche avec les\n"
	.string "dernières machines.\l"
	.string "Mais les POKéMON\p"
	.string "réagissaient mal au bruit.\n"
	.string "On a dû arrêter.$"

Route116_TunnelersRestHouse_Text_ManDiggingHisWayToVerdanturf:
	.string "Il y a un homme qui\n"
	.string "creuse son\l"
	.string "chemin vers\p"
	.string "VERROVILLE\n"
	.string "tout seul.\l"
	.string "Il est désespéré\l"
	.string "de traverser.\p"
	.string "Il a besoin d'aide !$"

Route116_TunnelersRestHouse_Text_GetToVerdanturfWithoutTunnel:
	.string "Pour aller à VERGOYON sans utiliser\n"
	.string "ce TUNNEL, il faudrait traverser la\l"
	.string "mer jusqu'à ENTOILLE, naviguer jusqu'à\l"
	.string "POIVRESSELLE, puis passer par LAVELLANIA.$"

Route116_TunnelersRestHouse_Text_TunnelHasGoneThrough:
	.string "Tu as entendu ? Le TUNNEL\n"
	.string "vers VERGAZON est terminé !\p"
	.string "Parfois, si on espère assez\n"
	.string "fort, les rêves se réalisent.$"

