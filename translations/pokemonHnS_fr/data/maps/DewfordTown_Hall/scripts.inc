.set LOCALID_EXPERT_M, 4
.set LOCALID_TWIN, 5
.set LOCALID_SCHOOL_KID_M, 7
.set LOCALID_PSYCHIC_M, 8

DewfordTown_Hall_MapScripts::
	.byte 0

DewfordTown_Hall_EventScript_Girl::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	special IsTrendyPhraseBoring
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_Hall_EventScript_GirlBoredOfTrend
	msgbox DewfordTown_Hall_Text_CantImagineLifeWithoutTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_GirlBoredOfTrend::
	msgbox DewfordTown_Hall_Text_GettingBoredOfTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Woman::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_TeachingMonAboutTrend, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Man::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	special BufferDeepLinkPhrase
	msgbox DewfordTown_Hall_Text_DeepLinkBetweenXAndY, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DewfordTown_Hall_EventScript_ConfirmTrendLink
	goto_if_eq VAR_RESULT, NO, DewfordTown_Hall_EventScript_RejectTrendLink
	end

DewfordTown_Hall_EventScript_ConfirmTrendLink::
	msgbox DewfordTown_Hall_Text_MyHunchWasRight, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_RejectTrendLink::
	msgbox DewfordTown_Hall_Text_NotEasyToKeepUp, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_ExpertM::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_TVShowAboutTrend, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_EXPERT_M, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

DewfordTown_Hall_EventScript_Twin::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_TWIN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	release
	end

DewfordTown_Hall_EventScript_LittleBoy::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_CollectTrendMerchandise, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_EventScript_Bookshelf::
	lockall
	call Common_EventScript_BufferTrendyPhrase
	msgbox DewfordTown_Hall_Text_BooksAboutTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_Painting::
	lockall
	call Common_EventScript_BufferTrendyPhrase
	special GetDewfordHallPaintingNameIndex
	switch VAR_RESULT
	case 0, DewfordTown_Hall_EventScript_ScreamTitle
	case 4, DewfordTown_Hall_EventScript_ScreamTitle
	case 1, DewfordTown_Hall_EventScript_SmileTitle
	case 5, DewfordTown_Hall_EventScript_ScreamTitle
	case 2, DewfordTown_Hall_EventScript_LastTitle
	case 6, DewfordTown_Hall_EventScript_LastTitle
	case 3, DewfordTown_Hall_EventScript_BirthTitle
	case 7, DewfordTown_Hall_EventScript_LastTitle
	end

DewfordTown_Hall_EventScript_ScreamTitle::
	msgbox DewfordTown_Hall_Text_TrendsScream, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_SmileTitle::
	msgbox DewfordTown_Hall_Text_TrendsSmile, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_LastTitle::
	msgbox DewfordTown_Hall_Text_LastTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_BirthTitle::
	msgbox DewfordTown_Hall_Text_BirthOfTrend, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_SchoolKidM::
	lockall
	setvar VAR_0x8008, 0
	goto DewfordTown_Hall_EventScript_DoTrendDebate
	end

DewfordTown_Hall_EventScript_PsychicM::
	lockall
	setvar VAR_0x8008, 1
	goto DewfordTown_Hall_EventScript_DoTrendDebate
	end

DewfordTown_Hall_EventScript_DoTrendDebate::
	call Common_EventScript_BufferTrendyPhrase
	special GetDewfordHallPaintingNameIndex
	switch VAR_RESULT
	case 0, DewfordTown_Hall_EventScript_TrendDebate1
	case 1, DewfordTown_Hall_EventScript_TrendDebate1
	case 2, DewfordTown_Hall_EventScript_TrendDebate2
	case 3, DewfordTown_Hall_EventScript_TrendDebate2
	case 4, DewfordTown_Hall_EventScript_TrendDebate3
	case 5, DewfordTown_Hall_EventScript_TrendDebate3
	case 6, DewfordTown_Hall_EventScript_TrendDebate4
	case 7, DewfordTown_Hall_EventScript_TrendDebate5
	end

DewfordTown_Hall_EventScript_TrendDebate1::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_SawTrendCoolestThing, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_AllegedTrendNotAuthentic, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate2::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_ComposedTrendThemeSong, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_WorkOnYourSinging, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate3::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_OrganizeTrendParty, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_BrilliantIndeed, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate4::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_TrendHasBecomePartOfLife, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_TrendDebate5::
	call DewfordTown_Hall_EventScript_DebateReact1
	msgbox DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible, MSGBOX_DEFAULT
	call DewfordTown_Hall_EventScript_DebateReact2
	msgbox DewfordTown_Hall_Text_WellBeTrendDuo, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Hall_EventScript_DontMovePlayer1::
	return

DewfordTown_Hall_EventScript_DebateReact1::
	applymovement LOCALID_PSYCHIC_M, DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft
	waitmovement 0
	goto_if_eq VAR_0x8008, 0, DewfordTown_Hall_EventScript_PlayerReactWest
	goto_if_eq VAR_0x8008, 1, DewfordTown_Hall_EventScript_DontMovePlayer2
	end

DewfordTown_Hall_EventScript_PlayerReactWest::
	goto_if_eq VAR_FACING, DIR_EAST, DewfordTown_Hall_EventScript_DontMovePlayer1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	return

DewfordTown_Hall_EventScript_DontMovePlayer2::
	return

DewfordTown_Hall_EventScript_DebateReact2::
	applymovement LOCALID_SCHOOL_KID_M, DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight
	waitmovement 0
	goto_if_eq VAR_0x8008, 0, DewfordTown_Hall_EventScript_PlayerReactNorthSouth
	goto_if_eq VAR_0x8008, 1, DewfordTown_Hall_EventScript_PlayerReactEast
	end

DewfordTown_Hall_EventScript_PlayerReactNorthSouth::
	call_if_eq VAR_FACING, DIR_NORTH, DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp
	call_if_eq VAR_FACING, DIR_SOUTH, DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown
	return

DewfordTown_Hall_EventScript_PlayerWalkInPlaceUp::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	return

DewfordTown_Hall_EventScript_PlayerWalkInPlaceDown::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	return

DewfordTown_Hall_EventScript_PlayerReactEast::
	goto_if_eq VAR_FACING, DIR_WEST, DewfordTown_Hall_EventScript_DontMovePlayer1
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	return

DewfordTown_Hall_Movement_PsychicWalkInPlaceLeft:
	walk_in_place_left
	step_end

DewfordTown_Hall_Movement_SchoolKidWalkInPlaceRight:
	walk_in_place_right
	step_end

DewfordTown_Hall_EventScript_SludgeBombMan::
	lock
	faceplayer
	call Common_EventScript_BufferTrendyPhrase
	goto_if_set FLAG_RECEIVED_TM_SLUDGE_BOMB, DewfordTown_Hall_EventScript_ReceivedSludgeBomb
	msgbox DewfordTown_Hall_Text_GiveYouSludgeBomb, MSGBOX_DEFAULT
	giveitem ITEM_TM_SLUDGE_BOMB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_SLUDGE_BOMB
	release
	end

DewfordTown_Hall_EventScript_ReceivedSludgeBomb::
	msgbox DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo, MSGBOX_DEFAULT
	release
	end

DewfordTown_Hall_Text_CantImagineLifeWithoutTrend:
	.string "Qu'est-ce qui est à la mode ?\n"
	.string "« {STR_VAR_1} », bien sûr !\p"
	.string "Je ne peux pas imaginer la\n"
	.string "vie sans « {STR_VAR_1} » !$"

DewfordTown_Hall_Text_GettingBoredOfTrend:
	.string "Qu'est-ce qui est à la mode ? Eh bien, ça doit être\n"
	.string "« {STR_VAR_1} » !\p"
	.string "Mais j'en ai un peu marre.\p"
	.string "Je devrais chercher la prochaine grande tendance.$"

DewfordTown_Hall_Text_TeachingMonAboutTrend:
	.string "J'apprends à mon POKéMON\n"
	.string "« {STR_VAR_1} »,\l"
	.string "mais ça ne marche pas bien.\p"
	.string "C'est un peu trop, je crois.$"

DewfordTown_Hall_Text_DeepLinkBetweenXAndY:
	.string "J'étudie le mot à la mode\n"
	.string "« {STR_VAR_1} » maintenant.\p"
	.string "Est-il vrai qu'il y a un lien profond\n"
	.string "entre « {STR_VAR_1} »\l"
	.string "et « {STR_VAR_2} » ?$"

DewfordTown_Hall_Text_MyHunchWasRight:
	.string "Oh !\n"
	.string "Alors, mon intuition était bonne !\p"
	.string "Je suis un pas plus près d'être branché et\n"
	.string "happening, youpi !$"

DewfordTown_Hall_Text_NotEasyToKeepUp:
	.string "Quoi ?!\n"
	.string "C'est vrai ?!\p"
	.string "Ce n'est pas facile pour un vieux comme moi\n"
	.string "de suivre les tendances !$"

DewfordTown_Hall_Text_TVShowAboutTrend:
	.string "Toute cette histoire de\n"
	.string "« {STR_VAR_1} »…\l"
	.string "Il n'y a pas une émission TV là-dessus ?$"

DewfordTown_Hall_Text_IsTrendMorePopularAcrossSea:
	.string "De l'autre côté de la mer…\p"
	.string "« {STR_VAR_1} » est-il\n"
	.string "encore plus populaire ?$"

DewfordTown_Hall_Text_CollectTrendMerchandise:
	.string "Je collectionne les produits\n"
	.string "officiels sous licence\l"
	.string "« {STR_VAR_1} ».\p"
	.string "J'ai des POUPEES officielles\n"
	.string "« {STR_VAR_1} »…\p"
	.string "Des vêtements de marque\n"
	.string "« {STR_VAR_1} »…\p"
	.string "Et des livres illustrés sous\n"
	.string "licence officielle\l"
	.string "« {STR_VAR_1} ».\p"
	.string "Héhéh, j'ai tout !\n"
	.string "Je ne partage rien avec toi !$"

DewfordTown_Hall_Text_BooksAboutTrend:
	.string "IDENTIFIER LES BONS\n"
	.string "« {STR_VAR_1} » ET\l"
	.string "LES MAUVAIS « {STR_VAR_1} »…\p"
	.string "LE LIEN ENTRE\n"
	.string "« {STR_VAR_1} » ET\l"
	.string "LES POKéMON…\p"
	.string "« {STR_VAR_1} »\n"
	.string "UTILES…\p"
	.string "C'est rempli de livres sur\n"
	.string "« {STR_VAR_1} ».$"

DewfordTown_Hall_Text_TrendsScream:
	.string "« CRI DE {STR_VAR_1} »\n"
	.string "est le titre.$"

DewfordTown_Hall_Text_TrendsSmile:
	.string "« SOURIRE DE {STR_VAR_1} »\n"
	.string "est le titre.$"

DewfordTown_Hall_Text_LastTrend:
	.string "Il s'intitule « LE DERNIER\n"
	.string "{STR_VAR_1} ».$"

DewfordTown_Hall_Text_BirthOfTrend:
	.string "Il s'intitule « LA NAISSANCE\n"
	.string "DE {STR_VAR_1} ».$"

DewfordTown_Hall_Text_SawTrendCoolestThing:
	.string "J'ai vu « {STR_VAR_1} » !\n"
	.string "Cool, hein ? C'est, genre, la\p"
	.string "chose la plus cool !\p"
	.string "C'était génial ! C'était le\n"
	.string "vrai truc, oh oui !$"

DewfordTown_Hall_Text_AllegedTrendNotAuthentic:
	.string "Oh, non, non, non. Ce\p"
	.string "prétendu « {STR_VAR_1} » que\n"
	.string "tu prétends avoir vu… ce\l"
	.string "n'est pas ça. L'article authentique\p"
	.string "est bien… Comment dire ?\n"
	.string "Plus vif, mais plus\l"
	.string "doux ! Ah, peu\p"
	.string "importe. C'est stupéfiant !$"

DewfordTown_Hall_Text_ComposedTrendThemeSong:
	.string "Hé, écoute, j'ai composé un thème\n"
	.string "pour « {STR_VAR_1} ».\p"
	.string "« {STR_VAR_1} »\n"
	.string "est très populaire en ce moment.\p"
	.string "OK, écoute !\n"
	.string "… …\p"
	.string "Oh !\n"
	.string "{STR_VAR_1} !\p"
	.string "Magnifique\n"
	.string "{STR_VAR_1} !$"

DewfordTown_Hall_Text_WorkOnYourSinging:
	.string "… … Je dirais, mon\p"
	.string "vieux, que tu ferais\n"
	.string "bien de travailler ton\l"
	.string "chant avant de t'aventurer\l"
	.string "avec « {STR_VAR_1} ».$"

DewfordTown_Hall_Text_OrganizeTrendParty:
	.string "Bref, comme je le disais, on devrait\n"
	.string "se retrouver et organiser une fête\l"
	.string "« {STR_VAR_1} »\l"
	.string "sur l'île.$"

DewfordTown_Hall_Text_BrilliantIndeed:
	.string "Oh, une idée géniale !\p"
	.string "Ça tranchera une fois pour toutes\n"
	.string "qui est le meilleur en\l"
	.string "« {STR_VAR_1} ».\l"
	.string "Brillant, en effet !\p"
	.string "À partir d'aujourd'hui, nos vies tourneront\n"
	.string "autour de « {STR_VAR_1} » !$"

DewfordTown_Hall_Text_TrendHasBecomePartOfLife:
	.string "J'y réfléchissais…\p"
	.string "Tu ne trouves pas que\n"
	.string "« {STR_VAR_1} » est\l"
	.string "passé d'une mode passagère à\l"
	.string "un élément de notre quotidien ?$"

DewfordTown_Hall_Text_TrendWeighsHeavilyOnMind:
	.string "Pardon ? Cette quantité,\n"
	.string "quoi ? Cependant, c'est\p"
	.string "vrai que « {STR_VAR_1}\n"
	.string "» pèse lourd sur\l"
	.string "ton esprit, que tu\l"
	.string "sois éveillé ou endormi.\p"
	.string "Absolument, tu es\n"
	.string "le PROFESSEUR «\l"
	.string "{STR_VAR_1} » !$"

DewfordTown_Hall_Text_IfWeTeamUpWellBeInvincible:
	.string "Si toi et moi formons une équipe,\n"
	.string "nous serons invincibles pour tout ce qui\l"
	.string "concerne « {STR_VAR_1} » !$"

DewfordTown_Hall_Text_WellBeTrendDuo:
	.string "Exactement, mon ami !\p"
	.string "Nous serons le duo\n"
	.string "« {STR_VAR_1} » !\p"
	.string "C'est une image mûre, non ?\n"
	.string "Hahahah !$"

DewfordTown_Hall_Text_GiveYouSludgeBomb:
	.string "Pour moi, BOMB-BEURK est au sommet\n"
	.string "de la popularité. C'est le numéro un.\p"
	.string "Hein ? Tu me dis que tu ne connais pas\n"
	.string "BOMB-BEURK ?\p"
	.string "C'est carrément pitoyable.\n"
	.string "Je vais t'en donner un.$"

DewfordTown_Hall_Text_LoveSludgeBombButTrendInToo:
	.string "J'adore BOMB-BEURK.\p"
	.string "Mais les POKéMON avec la capacité\n"
	.string "« {STR_VAR_1} »\l"
	.string "sont à la mode aussi.$"

