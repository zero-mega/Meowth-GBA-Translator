VerdanturfTown_FriendshipRatersHouse_MapScripts::
	.byte 0

VerdanturfTown_FriendshipRatersHouse_EventScript_FriendshipRater::
	lock
	faceplayer
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_SeeHowMuchPokemonLikesYou, MSGBOX_DEFAULT
	specialvar VAR_RESULT, GetLeadMonFriendshipScore
	switch VAR_RESULT
	case FRIENDSHIP_NONE, VerdanturfTown_FriendshipRatersHouse_EventScript_DetestsYou
	case FRIENDSHIP_1_TO_49, VerdanturfTown_FriendshipRatersHouse_EventScript_VeryWary
	case FRIENDSHIP_50_TO_99, VerdanturfTown_FriendshipRatersHouse_EventScript_NotUsedToYou
	case FRIENDSHIP_100_TO_149, VerdanturfTown_FriendshipRatersHouse_EventScript_GettingUsedToYou
	case FRIENDSHIP_150_TO_199, VerdanturfTown_FriendshipRatersHouse_EventScript_LikesYouQuiteALot
	case FRIENDSHIP_200_TO_254, VerdanturfTown_FriendshipRatersHouse_EventScript_VeryHappy
	case FRIENDSHIP_MAX, VerdanturfTown_FriendshipRatersHouse_EventScript_AdoresYou
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_DetestsYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_DetestsYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_VeryWary::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_VeryWary, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_NotUsedToYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_NotUsedToYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_GettingUsedToYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_GettingUsedToYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_LikesYouQuiteALot::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_LikesYouQuiteALot, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_VeryHappy::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_VeryHappy, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_AdoresYou::
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_AdoresYou, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_FriendshipRatersHouse_EventScript_Pikachu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_PIKACHU, CRY_MODE_NORMAL
	msgbox VerdanturfTown_FriendshipRatersHouse_Text_Pikachu, MSGBOX_DEFAULT
	waitmoncry
	release
	end

VerdanturfTown_FriendshipRatersHouse_Text_SeeHowMuchPokemonLikesYou:
	.string "Laisse-moi voir ton POKéMON.\n"
	.string "Je vais vérifier à quel point il t'aime.\p"
	.string "Oh.\n"
	.string "Ton POKéMON…$"

VerdanturfTown_FriendshipRatersHouse_Text_AdoresYou:
	.string "Il t'adore.\n"
	.string "Il ne pourrait pas t'aimer davantage.\l"
	.string "Je me sens heureux rien qu'en le voyant.$"

VerdanturfTown_FriendshipRatersHouse_Text_VeryHappy:
	.string "Il a l'air très heureux.\n"
	.string "Il t'aime énormément, c'est évident.$"

VerdanturfTown_FriendshipRatersHouse_Text_LikesYouQuiteALot:
	.string "Il t'aime beaucoup.\n"
	.string "Il semble vouloir qu'on s'occupe un peu de lui.$"

VerdanturfTown_FriendshipRatersHouse_Text_GettingUsedToYou:
	.string "Il s'habitue à toi.\n"
	.string "Il semble avoir confiance en toi.$"

VerdanturfTown_FriendshipRatersHouse_Text_NotUsedToYou:
	.string "Il ne t'a pas encore beaucoup habitué.\n"
	.string "Il ne t'aime ni ne te déteste.$"

VerdanturfTown_FriendshipRatersHouse_Text_VeryWary:
	.string "Il est très méfiant.\n"
	.string "Il a un regard féroce effrayant.\l"
	.string "Il ne t'aime pas beaucoup.$"

VerdanturfTown_FriendshipRatersHouse_Text_DetestsYou:
	.string "C'est difficile à dire...\p"
	.string "Ton POKéMON te déteste carrément.\n"
	.string "Ça ne te met pas mal à l'aise ?$"

VerdanturfTown_FriendshipRatersHouse_Text_Pikachu:
	.string "PIKACHU : Pika pika !$"

