.set LOCALID_TWIN, 2

VerdanturfTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_OnTransition
	.byte 0

VerdanturfTown_OnTransition:
	setflag FLAG_VISITED_OLIVINE_CITY
	setvar VAR_CONTEST_HALL_STATE, 0
	end

VerdanturfTown_LickyEvo::
	msgbox VerdanturfTown_LickyEvo_Text, MSGBOX_NPC
	end

VerdanturfTown_LickyEvo_Text:
	.string "EXCELLANGUE évolue en roulant.\n"
	.string "Essaie de faire ça !$"

VerdanturfTown_EventScript_Twin::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_TwinTunnelOpen
	msgbox VerdanturfTown_Text_ManTryingToDigTunnel, MSGBOX_DEFAULT
	applymovement LOCALID_TWIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VerdanturfTown_EventScript_TwinTunnelOpen::
	msgbox VerdanturfTown_Text_ManDugTunnelForLove, MSGBOX_DEFAULT
	applymovement LOCALID_TWIN, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

VerdanturfTown_EventScript_Man::
	msgbox VerdanturfTown_Text_AirCleanHere, MSGBOX_NPC
	end

VerdanturfTown_EventScript_Camper::
	msgbox VerdanturfTown_Text_MakeBattleTentDebut, MSGBOX_NPC
	end

VerdanturfTown_EventScript_Boy::
	lock
	faceplayer
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_EventScript_BoyTunnelOpen
	msgbox VerdanturfTown_Text_GuyTryingToBustThroughCave, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_EventScript_BoyTunnelOpen::
	msgbox VerdanturfTown_Text_EasyToGetToRustboroNow, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_EventScript_TownSign::
	msgbox VerdanturfTown_Text_TownSign, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_WandasHouseSign::
	msgbox VerdanturfTown_Text_WandasHouse, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_BattleTentSign::
	msgbox VerdanturfTown_Text_BattleTentSign, MSGBOX_SIGN
	end

VerdanturfTown_EventScript_RusturfTunnelSign::
	msgbox VerdanturfTown_Text_RusturfTunnelSign, MSGBOX_SIGN
	end

VerdanturfTown_Text_ManTryingToDigTunnel:
	.string "Mon papa m'a dit. Il dit\p"
	.string "que ce tunnel est plein de\n"
	.string "POKéMON timides. Ils ont tous peur\p"
	.string "du bruit fort et font un\n"
	.string "grand vacarme. Alors ils ont dû\p"
	.string "arrêter le grand projet de tunnel.\n"
	.string "Mais il y a un\p"
	.string "homme. Il essaie de creuser\n"
	.string "le tunnel tout seul !$"

VerdanturfTown_Text_ManDugTunnelForLove:
	.string "Un homme a creusé un tunnel pour\n"
	.string "une femme qu'il aimait.\p"
	.string "Je ne comprends pas vraiment, mais bon !$"

VerdanturfTown_Text_AirCleanHere:
	.string "Selon la direction des vents, les cendres\n"
	.string "volcaniques ne sont jamais soufflées dans cette direction.\p"
	.string "L'air est propre et délicieux ici.\n"
	.string "Vivre ici devrait faire du bien même\l"
	.string "aux personnes fragiles et malades.$"

VerdanturfTown_Text_MakeBattleTentDebut:
	.string "Mon POKéMON et moi, on est sur\n"
	.string "une belle série de victoires. Alors j'ai\p"
	.string "décidé de faire mes débuts à la\n"
	.string "TENTE DE COMBAT dans cette ville.$"

VerdanturfTown_Text_GuyTryingToBustThroughCave:
	.string "Tu as vu la grotte à\n"
	.string "côté du MARCHÉ POKéMON ? Il\p"
	.string "y a un type qui essaie\n"
	.string "de casser des rochers pour sortir\l"
	.string "de l'autre côté. Ce serait génial\p"
	.string "si on pouvait passer… Ça\n"
	.string "faciliterait les visites à MÉROUVILLE.$"

VerdanturfTown_Text_EasyToGetToRustboroNow:
	.string "Cette grotte à côté du POKé-MARCHÉ\n"
	.string "est maintenant un tunnel vers l'autre côté.\p"
	.string "C'est génial-c'est facile d'aller acheter\n"
	.string "de nouveaux produits DEVON à MEROUVILLE maintenant.$"

VerdanturfTown_Text_TownSign:
	.string "VERGOIGNON\p"
	.string "“Les hautes terres balayées par le vent avec la\n"
	.string "douce fragrance de l'herbe.”$"

VerdanturfTown_Text_WandasHouse:
	.string "MAISON DE WANDA$"

VerdanturfTown_Text_BattleTentSign:
	.string "LIEU DE LA TENTE DE COMBAT MYOKARA\n"
	.string "“Régalez-vous de combats !”$"

VerdanturfTown_Text_RusturfTunnelSign:
	.string "TUNNEL RONDOUDOU\n"
	.string "“Relie KANTEBLA et MYSTHERBE.\p"
	.string "“Le projet du tunnel a été\n"
	.string "annulé.”$"

