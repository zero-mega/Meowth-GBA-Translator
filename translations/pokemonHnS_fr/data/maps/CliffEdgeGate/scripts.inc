CliffEdgeGate_MapScripts::
	.byte 0

CliffEdgeGate_EventScript_Woman::
	lock
	faceplayer
	msgbox CliffEdgeGate_Text_IntroOpen, MSGBOX_DEFAULT
	closemessage
	release
	end

CliffEdgeGate_EventScript_Picnicker::
	lock
	faceplayer
	msgbox CliffEdgeGate_Text_Expectations, MSGBOX_DEFAULT
	closemessage
	release
	end

CliffEdgeGate_Text_IntroOpen:
	.string "Tu savais ? Il y a un PARC\n"
	.string "SAFARI juste au coin de la rue.\p"
	.string "C'est vraiment amusant ! Tu verras beaucoup\n"
	.string "de POKéMON différents, et tu peux tous\l"
	.string "les attraper ! Il n'y a aucune\p"
	.string "raison de ne pas y aller, non\n"
	.string "? Juste au coin de la rue.$"

CliffEdgeGate_Text_Expectations:
	.string "J'apprécie que tout le monde\n"
	.string "attende ça avec impatience.\p"
	.string "Mais la dame à l'accueil semble\n"
	.string "un peu trop dramatique…\p"
	.string "Ne te fais pas trop d'illusions !$"

CliffEdgeGate_EventScript_CaveSign::
	lock
	msgbox CliffEdgeGate_Text_SignOpen, MSGBOX_SIGN
	closemessage
	release
	end

CliffEdgeGate_Text_SignOpen:
	.string "Tout est palpitant !\n"
	.string "Explorez pour trouver des POKéMON sauvages !\l"
	.string "Parc Safari du GARDIEN BAOBA\l"
	.string "Ouvert et opérationnel !$"

