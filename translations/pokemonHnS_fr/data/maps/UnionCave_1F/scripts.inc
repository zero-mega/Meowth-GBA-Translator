UnionCave_1F_MapScripts::
	.byte 0


UnionCave_1F_Trigger_Monview::
	special SpawnCameraObject
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkRight1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkRight1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkRight1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkRight1
	waitmovement 0
	message Route29_Text_PressAorB
	waitbuttonpress
	closemessage
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkLeft1
	waitmovement 0
	applymovement2 OBJ_EVENT_ID_CAMERA, Common_Movement_WalkLeft1
	waitmovement 0
	special RemoveCameraObject
	applymovement2 OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement 0
	end


UnionCave_1F_EventScript_HikerRussell::
	trainerbattle_single TRAINER_RUSSELL, UnionCave_1F_Text_HikerRussellSeen, UnionCave_1F_Text_HikerRussellBeaten
	msgbox UnionCave_1F_Text_HikerRussellAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_1F_EventScript_PokemaniacLarry::
	trainerbattle_single TRAINER_LARRY, UnionCave_1F_Text_PokemaniacLarrySeen, UnionCave_1F_Text_PokemaniacLarryBeaten
	msgbox UnionCave_1F_Text_PokemaniacLarryAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_1F_EventScript_HikerDaniel::
	trainerbattle_single TRAINER_DANIEL, UnionCave_1F_Text_HikerDanielSeen, UnionCave_1F_Text_HikerDanielBeaten
	msgbox UnionCave_1F_Text_HikerDanielAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_1F_EventScript_FirebreatherBill::
	trainerbattle_single TRAINER_BILL, UnionCave_1F_Text_FirebreatherBillSeen, UnionCave_1F_Text_FirebreatherBillBeaten
	msgbox UnionCave_1F_Text_FirebreatherBillAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_1F_EventScript_FirebreatherRay::
	trainerbattle_single TRAINER_RAY, UnionCave_1F_Text_FirebreatherRaySeen, UnionCave_1F_Text_FirebreatherRayBeaten
	msgbox UnionCave_1F_Text_FirebreatherRayAfter, MSGBOX_AUTOCLOSE
	end	

UnionCave_1F_EventScript_Item_Potion::
	finditem ITEM_POTION
	end

UnionCave_1F_EventScript_Item_GreatBall::
	finditem ITEM_GREAT_BALL
	end

UnionCave_1F_EventScript_Item_Xattack::
	finditem ITEM_X_ATTACK
	end

UnionCave_1F_EventScript_Item_Awakening::
	finditem ITEM_AWAKENING
	end

UnionCave_1F_Text_HikerRussellSeen:
	.string "Tu vas à ECORCEK, n'est-ce pas ?\p"
	.string "Laisse mes POKéMON voir si tu es assez bon\n"
	.string "pour combattre.$"

UnionCave_1F_Text_HikerRussellBeaten:
	.string "Oh, oh, oh !$"

UnionCave_1F_Text_HikerRussellAfter:
	.string "D'accord, alors ! J'ai décidé.\p"
	.string "Je ne pars pas tant que mes POKéMON\n"
	.string "ne seront pas plus forts !$"

UnionCave_1F_Text_PokemaniacLarrySeen:
	.string "Je parcours le monde à la\n"
	.string "recherche de POKéMON. Tu cherches des\p"
	.string "POKéMON aussi ? Alors tu es\p"
	.string "mon rival en collection !$"

UnionCave_1F_Text_PokemaniacLarryBeaten:
	.string "Argh. Mes pauvres POKéMON…$"

UnionCave_1F_Text_PokemaniacLarryAfter:
	.string "Chaque vendredi, on entend des rugissements\n"
	.string "de POKéMON au fond de la grotte.$"

UnionCave_1F_Text_HikerDanielSeen:
	.string "Whoa ! Quelle surprise !\p"
	.string "Je ne m'attendais pas à voir quelqu'un ici !$"

UnionCave_1F_Text_HikerDanielBeaten:
	.string "Ouah ! J'ai été battu à plate couture !$"

UnionCave_1F_Text_HikerDanielAfter:
	.string "On m'a arnaqué pour acheter une\n"
	.string "QUEUE RAMOLOSS.\p"
	.string "Je plains ce pauvre POKéMON.$"

UnionCave_1F_Text_FirebreatherBillSeen:
	.string "Les ULTRASONS de NOSFERAPTI rendent mes\n"
	.string "POKéMON confus.\p"
	.string "Ça m'énerve sérieusement !$"

UnionCave_1F_Text_FirebreatherBillBeaten:
	.string "J'ai flambé !$"

UnionCave_1F_Text_FirebreatherBillAfter:
	.string "Le week-end, on peut entendre d'étranges\n"
	.string "rugissements au fond de la grotte.$"

UnionCave_1F_Text_FirebreatherRaySeen:
	.string "S'il y a de la lumière, une grotte n'est pas effrayante.\p"
	.string "Si tu es fort, les POKéMON ne sont\n"
	.string "pas effrayants.$"

UnionCave_1F_Text_FirebreatherRayBeaten:
	.string "FLAMMES !$"

UnionCave_1F_Text_FirebreatherRayAfter:
	.string "C'est le feu de mon POKéMON\n"
	.string "qui éclaire cette grotte.$"
