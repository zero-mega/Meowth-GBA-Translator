.set LOCALID_NURSE, 1
.set LOCALID_ECRUTEAK_BILL, 6

EcruteakCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EcruteakCity_PokemonCenter_OnTransition
	.byte 0

EcruteakCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_ECRUTEAK_CITY
	end

EcruteakCity_PokemonCenter_EventScript_Bill::
	lock
	delay 30
	playse SE_PC_OFF
	delay 55
	faceplayer
	msgbox EcruteakCity_PokemonCenter1F_Text_Bill1, MSGBOX_DEFAULT
	msgbox EcruteakCity_PokemonCenter1F_Text_Bill2, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_FACING, DIR_NORTH, EcruteakCity_PokemonCenter_EventScript_BillLeaveBot
	call_if_eq VAR_FACING, DIR_WEST, EcruteakCity_PokemonCenter_EventScript_BillLeaveTop
	playse SE_EXIT
	setflag FLAG_HIDE_ECRUTEAK_BILL
	removeobject LOCALID_ECRUTEAK_BILL
	setflag FLAG_SYS_PC_BILL
	clearflag FLAG_HIDE_GOLDENROD_BILL
	release
	end

EcruteakCity_PokemonCenter_EventScript_BillFaceDown::
	turnobject LOCALID_ECRUTEAK_BILL, DIR_SOUTH
	return

EcruteakCity_PokemonCenter_EventScript_BillFaceRight::
	turnobject LOCALID_ECRUTEAK_BILL, DIR_EAST
	return

EcruteakCity_PokemonCenter_EventScript_BillLeaveTop::
	applymovement LOCALID_ECRUTEAK_BILL, EcruteakCity_PokemonCenter_Movement_BillTop
	waitmovement 0
	return

EcruteakCity_PokemonCenter_EventScript_BillLeaveBot::
	applymovement LOCALID_ECRUTEAK_BILL, EcruteakCity_PokemonCenter_Movement_BillBot
	waitmovement 0
	return

EcruteakCity_PokemonCenter_EventScript_Hiker::
	lock
	faceplayer
	msgbox EcruteakCity_PokemonCenter1F_Text_PokefanM, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_PokemonCenter_EventScript_Woman::
	lock
	faceplayer
	msgbox EcruteakCity_PokemonCenter1F_Text_CooltrainerF, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_PokemonCenter_EventScript_Nerd::
	lock
	faceplayer
	msgbox EcruteakCity_PokemonCenter1F_Text_GymGuide, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_PokemonCenter_Movement_BillTop:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

EcruteakCity_PokemonCenter_Movement_BillBot:
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end


EcruteakCity_PokemonCenter1F_Text_Bill1:
	.string "Salut, je suis PIERRE. Et toi, tu es qui ?\p"
	.string "Hmm, {PLAYER}, hein ?\n"
	.string "Tu arrives au bon moment.$"

EcruteakCity_PokemonCenter1F_Text_Bill2:
	.string "Je viens de finir les\n"
	.string "ajustements sur mon\p"
	.string "Système de\n"
	.string "Stockage POKéMON.\p"
	.string "Tu connais\p"
	.string "ce PC que tu\n"
	.string "utilises pour stocker\l"
	.string "tous tes POKéMON ?\p"
	.string "Je l'ai développé !\n"
	.string "BILL m'a aidé aussi.\l"
	.string "J'espère qu'il\p"
	.string "te sera utile !$"

EcruteakCity_PokemonCenter1F_Text_PokefanM:
	.string "La façon dont les FILLES KIMONO dansent est\n"
	.string "merveilleuse.\p"
	.string "Comme la façon dont elles utilisent leurs\n"
	.string "POKéMON.$"

EcruteakCity_PokemonCenter1F_Text_PokefanM_Mobile:
	.string "Tu espères sûrement te battre contre\n"
	.string "plus de gens, non ?\p"
	.string "Il y a apparemment un endroit où\n"
	.string "les Dresseurs se rassemblent.\p"
	.string "Où, tu demandes ?\p"
	.string "C'est un peu après OLIVILLE.$"

EcruteakCity_PokemonCenter1F_Text_CooltrainerF:
	.string "MORTY, le CHAMPION D'ARÈNE, est tellement\n"
	.string "cool.\p"
	.string "Ses POKéMON sont vraiment coriaces aussi.$"

EcruteakCity_PokemonCenter1F_Text_GymGuide:
	.string "LE LAC COLÈRE…\p"
	.string "L'apparition d'un essaim de\n"
	.string "LÉVIATOR…\p"
	.string "Je sens un complot. J'en suis sûr !$"

