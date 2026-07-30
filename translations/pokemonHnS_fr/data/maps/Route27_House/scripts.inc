Route27_House_MapScripts::
	.byte 0

Route27_House_EventScript_Woman::
	lock
	faceplayer
	goto_if_unset FLAG_GOT_TM_SANDSTORM, Route27_House_EventScript_WomanBeforeGiven
	msgbox SandstormHouse_Text_TM37Description, MSGBOX_DEFAULT
	closemessage
	release
	end

Route27_House_EventScript_WomanBeforeGiven::
	msgbox SandstormHouse_Text_Woman1, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	goto_if_ge VAR_RESULT, FRIENDSHIP_150_TO_199, Route27_House_EventScript_WomanHighFriendship
	playfirstmoncry
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerLookAway
	waitmovement OBJ_EVENT_ID_FOLLOWER
	applymovement OBJ_EVENT_ID_FOLLOWER Common_Movement_QuestionMark
	waitmovement 0
	msgbox SandstormHouse_Text_DisloyalMon, MSGBOX_DEFAULT
	closemessage
	release
	end

Route27_House_EventScript_WomanHighFriendship::
	playfirstmoncry
	applymovement OBJ_EVENT_ID_FOLLOWER FollowerDance
	waitmovement 0
	applymovement OBJ_EVENT_ID_FOLLOWER ContestHall_Movement_Heart
	waitmovement 0
	msgbox SandstormHouse_Text_LoyalMon, MSGBOX_DEFAULT
	giveitem ITEM_TM_SANDSTORM
	setflag FLAG_GOT_TM_SANDSTORM
	msgbox SandstormHouse_Text_TM37Description, MSGBOX_DEFAULT
	closemessage
	release
	end

Route27_Movement_FollowerJump:
	jump_in_place_down
	jump_in_place_down
	step_end

SandstormHouse_Text_Woman1:
    .string "Où vas-tu avec des\n"
    .string "POKéMON ? La LIGUE\p"
    .string "POKéMON ? Tes\p"
    .string "POKéMON sont-ils assez\n"
    .string "loyaux pour gagner\p"
    .string "? Voyons voir…$"

SandstormHouse_Text_LoyalMon:
    .string "Ah ! Ton POKéMON te fait beaucoup\n"
    .string "confiance.\p"
    .string "C'est agréable de voir un bon DRESSEUR.\p"
    .string "Tiens. Un cadeau pour ton voyage.$"

SandstormHouse_Text_TM37Description:
    .string "La CT37 contient TEMPÊTES DE SABLE.\p"
    .string "C'est une attaque qui inflige des dégâts\n"
    .string "aux deux combattants.\p"
    .string "C'est réservé aux Dresseurs avancés.\p"
    .string "Utilise-la si tu oses. Bonne chance !$"

SandstormHouse_Text_DisloyalMon:
    .string "S'il ne te fait pas plus\n"
    .string "confiance, ça pourrait être difficile. La\p"
    .string "confiance est le lien qui unit\n"
    .string "les POKéMON et les DRESSEURS.$"


