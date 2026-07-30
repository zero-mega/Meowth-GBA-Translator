MauvilleCity_PokemonCenter_1F_EventScript_MauvilleOldMan::
	special Script_GetCurrentMauvilleMan
	switch VAR_RESULT
	case MAUVILLE_MAN_BARD, MauvilleCity_PokemonCenter_1F_EventScript_Bard
	case MAUVILLE_MAN_HIPSTER, MauvilleCity_PokemonCenter_1F_EventScript_Hipster
	case MAUVILLE_MAN_TRADER, MauvilleCity_PokemonCenter_1F_EventScript_Trader
	case MAUVILLE_MAN_STORYTELLER, MauvilleCity_PokemonCenter_1F_EventScript_Storyteller
	case MAUVILLE_MAN_GIDDY, MauvilleCity_PokemonCenter_1F_EventScript_Giddy
	end

@ Bard
MauvilleCity_PokemonCenter_1F_EventScript_Bard::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToHearMySong, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_PlaySong
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineSong
	end

MauvilleCity_PokemonCenter_1F_EventScript_PlaySong::
	setvar VAR_0x8004, 0
	special PlayBardSong
	delay 60
	special HasBardSongBeenChanged
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_AskToWriteLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_WishICouldPlaySongForOthers, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineSong::
	msgbox MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues1, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_AskToWriteLyrics::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToWriteSomeLyrics, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics
	end

MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics::
	setvar VAR_0x8004, EASY_CHAT_TYPE_BARD_SONG
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_LetMeSingItForYou, MSGBOX_DEFAULT
	setvar VAR_0x8004, 1
	special PlayBardSong
	delay 60
	msgbox MauvilleCity_PokemonCenter_1F_Text_ThatHowYouWantedSongToGo, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_WriteLyrics
	special SaveBardSongLyrics
	msgbox MauvilleCity_PokemonCenter_1F_Text_IllSingThisSongForAWhile, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineWritingLyrics::
	msgbox MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues2, MSGBOX_DEFAULT
	release
	end

@ Hipster
MauvilleCity_PokemonCenter_1F_EventScript_Hipster::
	lock
	faceplayer
	setflag FLAG_UNLOCKED_TRENDY_SAYINGS
	msgbox MauvilleCity_PokemonCenter_1F_Text_TeachWhatsHipAndHappening, MSGBOX_DEFAULT
	special HasHipsterTaughtWord
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_TryTeachWord
	msgbox MauvilleCity_PokemonCenter_1F_Text_IAlreadyTaughtYou, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTeachWord::
	special HipsterTryTeachWord
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_TeachWord
	msgbox MauvilleCity_PokemonCenter_1F_Text_IveGotNothingNewToTeach, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TeachWord::
	msgbox MauvilleCity_PokemonCenter_1F_Text_HaveYouHeardOfWord, MSGBOX_DEFAULT
	special SetHipsterTaughtWord
	release
	end

@ Trader
MauvilleCity_PokemonCenter_1F_Text_WantToTradeDecor:
	.string "Salut, je suis l'ÉCHANGEUR.\n"
	.string "Tu veux échanger des décorations avec moi ?$"

MauvilleCity_PokemonCenter_1F_Text_TraderFeelingTheBlues:
	.string "Oh…\n"
	.string "Tu m'as laissé le blues…$"

MauvilleCity_PokemonCenter_1F_Text_WeveAlreadyTraded:
	.string "Mais on a déjà échangé des décorations,\n"
	.string "toi et moi.$"

MauvilleCity_PokemonCenter_1F_Text_PickADecorItem:
	.string "Si tu vois un objet décoratif qui\n"
	.string "t'intéresse parmi les miens, dis-le.$"

MauvilleCity_PokemonCenter_1F_Text_YouDontWantAnything:
	.string "Tu ne veux rien ?\n"
	.string "Je me sens indésirable…$"

MauvilleCity_PokemonCenter_1F_Text_OnceBelongedToPlayerDoYouWantIt:
	.string "Cet objet décoratif appartenait autrefois\n"
	.string "à {STR_VAR_1}.\p"
	.string "Tu le veux ?$"

MauvilleCity_PokemonCenter_1F_Text_YouDontHaveAnyDecor:
	.string "Euh… Attends une seconde. Tu n'as pas\n"
	.string "un seul objet de décoration !$"

MauvilleCity_PokemonCenter_1F_Text_PickTheDecorToTrade:
	.string "OK, choisis la décoration que tu\n"
	.string "vas m'échanger.$"

MauvilleCity_PokemonCenter_1F_Text_YouDontWantToTrade:
	.string "Tu ne veux pas échanger avec moi ?\n"
	.string "Je me sens indésirable…$"

MauvilleCity_PokemonCenter_1F_Text_YouveNoRoomForThis:
	.string "Tu as tous les {STR_VAR_2}S qui peuvent\n"
	.string "être stockés. Tu n'as plus de place pour ça.$"

MauvilleCity_PokemonCenter_1F_Text_SoWellTradeTheseDecor:
	.string "D'accord, on échange mon {STR_VAR_3}\n"
	.string "contre ton {STR_VAR_2} ?$"

MauvilleCity_PokemonCenter_1F_Text_ThatDecorIsInUse:
	.string "Cette décoration est utilisée.\n"
	.string "Tu ne peux pas l'échanger.$"

MauvilleCity_PokemonCenter_1F_Text_SendDecorToYourPC:
	.string "Alors on échange !\n"
	.string "J'enverrai ma décoration sur ton PC.$"

MauvilleCity_PokemonCenter_1F_Text_CantTradeThatOne:
	.string "Oups ! Désolé ! C'est une décoration\n"
	.string "très rare.\l"
	.string "Je ne peux pas l'échanger !\p"
	.string "Ça t'intéresse, autre chose ?$"

MauvilleCity_PokemonCenter_1F_EventScript_Trader::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_WantToTradeDecor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineTrade
	special GetTraderTradedFlag
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_AlreadyTraded
	message MauvilleCity_PokemonCenter_1F_Text_PickADecorItem
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineTrade::
	msgbox MauvilleCity_PokemonCenter_1F_Text_TraderFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_AlreadyTraded::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WeveAlreadyTraded, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive::
	special TraderMenuGetDecoration
	waitstate
	goto_if_eq VAR_0x8004, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelPickDecor
	goto_if_eq VAR_0x8004, 0xFFFF, MauvilleCity_PokemonCenter_1F_EventScript_InvalidDecor
	msgbox MauvilleCity_PokemonCenter_1F_Text_OnceBelongedToPlayerDoYouWantIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_PickDifferentDecor
	special DoesPlayerHaveNoDecorations
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_DontHaveAnyDecor
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	end

MauvilleCity_PokemonCenter_1F_EventScript_CancelPickDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontWantAnything, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_InvalidDecor::
	message MauvilleCity_PokemonCenter_1F_Text_CantTradeThatOne
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDifferentDecor::
	message MauvilleCity_PokemonCenter_1F_Text_PickADecorItem
	waitmessage
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToReceive
	end

MauvilleCity_PokemonCenter_1F_EventScript_DontHaveAnyDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontHaveAnyDecor, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive::
	msgbox MauvilleCity_PokemonCenter_1F_Text_PickTheDecorToTrade, MSGBOX_DEFAULT
	special TraderShowDecorationMenu
	waitstate
	goto_if_eq VAR_0x8006, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelGiveDecor
	goto_if_eq VAR_0x8006, 0xFFFF, MauvilleCity_PokemonCenter_1F_EventScript_DecorInUse
	special IsDecorationCategoryFull
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_NoRoomForDecor
	msgbox MauvilleCity_PokemonCenter_1F_Text_SoWellTradeTheseDecor, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	special TraderDoDecorationTrade
	msgbox MauvilleCity_PokemonCenter_1F_Text_SendDecorToYourPC, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_CancelGiveDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDontWantToTrade, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DecorInUse::
	msgbox MauvilleCity_PokemonCenter_1F_Text_ThatDecorIsInUse, MSGBOX_DEFAULT
	goto MauvilleCity_PokemonCenter_1F_EventScript_PickDecorToGive
	end

MauvilleCity_PokemonCenter_1F_EventScript_NoRoomForDecor::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouveNoRoomForThis, MSGBOX_DEFAULT
	release
	end

@ Storyteller
MauvilleCity_PokemonCenter_1F_Text_WillYouHearMyTale:
	.string "Je suis le CONTEUR.\n"
	.string "Je vais te raconter des histoires de DRESSEURS\l"
	.string "légendaires.\p"
	.string "Veux-tu entendre mon récit ?$"

MauvilleCity_PokemonCenter_1F_Text_StorytellerFeelingTheBlues:
	.string "Oh…\n"
	.string "Tu m'as laissé le blues…$"

MauvilleCity_PokemonCenter_1F_Text_WhichTaleToTell:
	.string "Je connais ces légendes.\n"
	.string "Quelle histoire veux-tu que je te raconte ?$"

MauvilleCity_PokemonCenter_1F_Text_IKnowNoTales:
	.string "Mais je ne connais aucun DRESSEUR\n"
	.string "légendaire. D'où, je ne connais aucune histoire.\p"
	.string "Où trouve-t-on un DRESSEUR digne\n"
	.string "d'une légende ?$"

MauvilleCity_PokemonCenter_1F_Text_YouDidStatXTimes:
	.string "Quoi ?! Toi… Toi…\n"
	.string "{STR_VAR_2} {STR_VAR_1} fois\p"
	.string "?! C'est vraiment\n"
	.string "magnifique ! C'est\p"
	.string "la naissance d'une\n"
	.string "nouvelle légende !$"

MauvilleCity_PokemonCenter_1F_Text_CouldThereBeOtherLegends:
	.string "Ça me fait penser : y aurait-il d'autres\n"
	.string "DRESSEURS aux légendes plus impressionnantes\l"
	.string "en attente d'être découverts ?$"

MauvilleCity_PokemonCenter_1F_Text_HaveYouAnyLegendaryTales:
	.string "Tu es un DRESSEUR ?\p"
	.string "Alors dis-moi, as-tu des histoires\n"
	.string "même vaguement légendaires ?$"

@ Unused
MauvilleCity_PokemonCenter_1F_Text_HearAnotherLegendaryTale:
	.string "Au fait… Veux-tu entendre\n"
	.string "une autre légende ?$"

MauvilleCity_PokemonCenter_1F_Text_NotWorthyOfLegend:
	.string "Hmm…\n"
	.string "Je ne suis pas satisfait…\p"
	.string "J'aimerais que tu m'apportes des nouvelles dignes\n"
	.string "d'être appelées une légende.$"

MauvilleCity_PokemonCenter_1F_Text_IWishMorePeopleWereInterested:
	.string "J'aimerais que plus de gens s'intéressent\n"
	.string "à mes épopées légendaires de DRESSEURS\l"
	.string "légendaires.$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameTitle::
	.string "Le DRESSEUR Économe$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameAction::
	.string "A sauvegardé$"

MauvilleCity_PokemonCenter_1F_Text_SavedGameStory::
	.string "Voici l'histoire d'un DRESSEUR\n"
	.string "nommé {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a sauvegardé le jeu\n"
	.string "{STR_VAR_1} fois !\p"
	.string "On ne trouvera jamais de DRESSEUR\n"
	.string "plus prudent que {STR_VAR_3} !$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedTitle::
	.string "Le DRESSEUR meneur de tendance$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedAction::
	.string "A lancé des modes$"

MauvilleCity_PokemonCenter_1F_Text_TrendsStartedStory::
	.string "Voici l'histoire d'un DRESSEUR\n"
	.string "nommé {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a lancé de nouvelles tendances\n"
	.string "{STR_VAR_1} fois !\p"
	.string "{STR_VAR_3} lance des tendances pour\n"
	.string "toute la région de HOENN !$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedTitle::
	.string "Le DRESSEUR planteur de BAIES$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedAction::
	.string "A planté des BAIES$"

MauvilleCity_PokemonCenter_1F_Text_BerriesPlantedStory::
	.string "Voici l'histoire d'un DRESSEUR\n"
	.string "nommé {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a planté des BAIES\n"
	.string "{STR_VAR_1} fois !\p"
	.string "{STR_VAR_3} est un légendaire\n"
	.string "amateur de BAIES !$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesTitle::
	.string "Le DRESSEUR fan de VÉLO$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesAction::
	.string "A échangé des VÉLOS$"

MauvilleCity_PokemonCenter_1F_Text_BikeTradesStory::
	.string "Voici l'histoire d'un DRESSEUR\n"
	.string "nommé {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a échangé des VÉLOS\n"
	.string "{STR_VAR_1} fois !\p"
	.string "{STR_VAR_3} doit adorer les VÉLOS\n"
	.string "profondément et passionnément !$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsTitle::
	.string "Le DRESSEUR interviewé$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsAction::
	.string "A été interviewé$"

MauvilleCity_PokemonCenter_1F_Text_InterviewsStory::
	.string "C'est l'histoire d'un DRESSEUR\n"
	.string "nommé {STR_VAR_3}.\p"
	.string "Ce DRESSEUR s'est fait interviewer\n"
	.string "{STR_VAR_1} fois !\p"
	.string "{STR_VAR_3} doit être un DRESSEUR qui\n"
	.string "attire beaucoup l'attention !$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesTitle::
	.string "Le DRESSEUR combatif$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesAction::
	.string "a combattu$"

MauvilleCity_PokemonCenter_1F_Text_TrainerBattlesStory::
	.string "C'est l'histoire d'un DRESSEUR\n"
	.string "nommé {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a combattu {STR_VAR_1} fois !\p"
	.string "{STR_VAR_3} doit être un DRESSEUR qui\n"
	.string "ne refuse jamais un combat !$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtTitle::
	.string "Le DRESSEUR qui capture des POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtAction::
	.string "A attrapé des POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_PokemonCaughtStory::
	.string "Voici l'histoire d'un DRESSEUR\n"
	.string "nommé {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a attrapé\n"
	.string "{STR_VAR_1} POKéMON !\p"
	.string "{STR_VAR_3} est un légendaire\n"
	.string "chasseur de POKéMON sauvages !$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtTitle::
	.string "Le DRESSEUR Pêcheur$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtAction::
	.string "Attrapé des POKéMON avec une CANNE$"

MauvilleCity_PokemonCenter_1F_Text_FishingPokemonCaughtStory::
	.string "Voici l'histoire d'un DRESSEUR\n"
	.string "nommé {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a attrapé\n"
	.string "{STR_VAR_1} POKéMON en pêchant !\p"
	.string "{STR_VAR_3} est un expert\n"
	.string "légendaire de la pêche !$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedTitle::
	.string "Le DRESSEUR couveur d'ŒUFS$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedAction::
	.string "A fait éclore des ŒUFS$"

MauvilleCity_PokemonCenter_1F_Text_EggsHatchedStory::
	.string "Voici l'histoire d'un DRESSEUR\n"
	.string "nommé {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a fait éclore {STR_VAR_1} POKéMON\n"
	.string "à partir d'ŒUFS !\p"
	.string "{STR_VAR_3} est un légendaire\n"
	.string "couveur d'ŒUFS !$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedTitle::
	.string "Le DRESSEUR Évoluteur$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedAction::
	.string "A fait évoluer des POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_PokemonEvolvedStory::
	.string "Voici l'histoire d'un DRESSEUR\n"
	.string "nommé {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a fait évoluer\n"
	.string "{STR_VAR_1} POKéMON !\p"
	.string "{STR_VAR_3} est le plus grand\n"
	.string "faiseur d'évolutions de POKéMON !$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterTitle::
	.string "Le DRESSEUR Amoureux du CENTRE POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterAction::
	.string "A utilisé des CENTRES POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_UsedPokemonCenterStory::
	.string "C'est l'histoire d'un DRESSEUR\n"
	.string "nommé {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a soigné des POKéMON\n"
	.string "{STR_VAR_1} fois aux CENTRES POKéMON !\p"
	.string "Personne n'aime plus les CENTRES POKéMON\n"
	.string "que {STR_VAR_3} !$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeTitle::
	.string "Le DRESSEUR Casanier$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeAction::
	.string "A reposé ses POKéMON à la maison$"

MauvilleCity_PokemonCenter_1F_Text_RestedAtHomeStory::
	.string "C'est l'histoire d'un DRESSEUR\n"
	.string "nommé {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a soigné des POKéMON\n"
	.string "{STR_VAR_1} fois à la maison !\p"
	.string "On ne pourrait pas trouver plus casanier\n"
	.string "que {STR_VAR_3} !$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesTitle::
	.string "Le DRESSEUR fan du PARC SAFARI$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesAction::
	.string "Entré dans le PARC SAFARI$"

MauvilleCity_PokemonCenter_1F_Text_SafariGamesStory::
	.string "C'est l'histoire d'un DRESSEUR\n"
	.string "nommé {STR_VAR_3}.\p"
	.string "Ce DRESSEUR est allé au PARC SAFARI\n"
	.string "{STR_VAR_1} fois !\p"
	.string "{STR_VAR_3} est un DRESSEUR dont le côté\n"
	.string "sauvage ressort au PARC SAFARI !$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutTitle::
	.string "Le DRESSEUR COUPE$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutAction::
	.string "a utilisé COUPE$"

MauvilleCity_PokemonCenter_1F_Text_UsedCutStory::
	.string "Voici l'histoire d'un DRESSEUR\n"
	.string "nommé {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a utilisé COUPE\n"
	.string "{STR_VAR_1} fois !\p"
	.string "{STR_VAR_3} est un DRESSEUR qui\n"
	.string "adore vraiment COUPE !$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashTitle::
	.string "Le DRESSEUR casseur de rochers$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashAction::
	.string "A brisé des rochers$"

MauvilleCity_PokemonCenter_1F_Text_UsedRockSmashStory::
	.string "C'est l'histoire d'un DRESSEUR\n"
	.string "nommé {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a utilisé FORCE\n"
	.string "{STR_VAR_1} fois !\p"
	.string "{STR_VAR_3} doit être un DRESSEUR qui\n"
	.string "ne laisse aucune pierre intacte !$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesTitle::
	.string "Le DRESSEUR fan de déplacements$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesAction::
	.string "A déplacé la BASE SECRETE$"

MauvilleCity_PokemonCenter_1F_Text_MovedBasesStory::
	.string "C'est l'histoire d'un DRESSEUR\n"
	.string "nommé {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a déménagé sa BASE SECRÈTE\n"
	.string "{STR_VAR_1} fois !\p"
	.string "{STR_VAR_3} est un DRESSEUR qui adore\n"
	.string "changer de maison souvent !$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashTitle::
	.string "Le DRESSEUR fan de TREMPETTE$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashAction::
	.string "A utilisé ÉCLABOUSSURE$"

MauvilleCity_PokemonCenter_1F_Text_UsedSplashStory::
	.string "Voici l'histoire d'un DRESSEUR\n"
	.string "nommé {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a utilisé TREMPETTE\n"
	.string "{STR_VAR_1} fois !\p"
	.string "{STR_VAR_3} est un DRESSEUR qui doit adorer\n"
	.string "barboter !$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleTitle::
	.string "Le DRESSEUR Tenace$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleAction::
	.string "A dû utiliser LUTTE$"

MauvilleCity_PokemonCenter_1F_Text_UsedStruggleStory::
	.string "C'est l'histoire d'un DRESSEUR\n"
	.string "nommé {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a dû utiliser LUTTE\n"
	.string "{STR_VAR_1} fois !\p"
	.string "{STR_VAR_3} est un DRESSEUR tenace\n"
	.string "qui n'abandonne jamais face à l'adversité !$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsTitle::
	.string "Le roi des SLOTS$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsAction::
	.string "A gagné le gros lot aux MACHINES À SOUS$"

MauvilleCity_PokemonCenter_1F_Text_SlotJackpotsStory::
	.string "C'est l'histoire d'un DRESSEUR\n"
	.string "nommé {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a gagné le gros lot aux\n"
	.string "MACHINES À SOUS {STR_VAR_1} fois.\p"
	.string "{STR_VAR_3} est un DRESSEUR chanceux\n"
	.string "aux MACHINES À SOUS !$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsTitle::
	.string "Le Champion de la ROULETTE$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsAction::
	.string "A enchaîné des victoires à la ROULETTE de$"

MauvilleCity_PokemonCenter_1F_Text_RouletteWinsStory::
	.string "C'est l'histoire d'un DRESSEUR\n"
	.string "nommé {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a gagné à la ROULETTE\n"
	.string "{STR_VAR_1} fois d'affilée.\p"
	.string "{STR_VAR_3} a eu de la chance quand la bille\n"
	.string "a rebondi à la ROULETTE !$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesTitle::
	.string "Le Challenger de la TOUR DE COMBAT$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesAction::
	.string "A relevé le défi de la TOUR DE COMBAT$"

MauvilleCity_PokemonCenter_1F_Text_BattleTowerChallengesStory::
	.string "Voici l'histoire d'un DRESSEUR appelé {STR_VAR_3}.\n"
	.string "Ce DRESSEUR a relevé le défi\p"
	.string "de la TOUR DE COMBAT {STR_VAR_1}\n"
	.string "fois ! {STR_VAR_3} est un DRESSEUR\p"
	.string "qui aspire à l'excellence à\n"
	.string "la TOUR DE COMBAT !$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksTitle::
	.string "Le DRESSEUR fan de mélanges$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksAction::
	.string "A fabriqué des {POKEBLOCK}S$"

MauvilleCity_PokemonCenter_1F_Text_MadePokeblocksStory::
	.string "C'est l'histoire d'un DRESSEUR\n"
	.string "nommé {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a fait des {POKEBLOCK}S\n"
	.string "{STR_VAR_1} fois !\p"
	.string "Personne n'utilise mieux le MIXEUR\n"
	.string "À BAIES que {STR_VAR_3} !$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsTitle::
	.string "Le DRESSEUR fan de CONCOURS$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsAction::
	.string "A participé à des CONCOURS$"

MauvilleCity_PokemonCenter_1F_Text_EnteredContestsStory::
	.string "Voici l'histoire d'un DRESSEUR\n"
	.string "nommé {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a participé à des CONCOURS\n"
	.string "{STR_VAR_1} fois !\p"
	.string "{STR_VAR_3} doit adorer montrer ses\n"
	.string "POKéMON aux autres !$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsTitle::
	.string "Le Maître des CONCOURS$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsAction::
	.string "A gagné des CONCOURS$"

MauvilleCity_PokemonCenter_1F_Text_WonContestsStory::
	.string "Voici l'histoire d'un DRESSEUR\n"
	.string "nommé {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a gagné des CONCOURS\n"
	.string "{STR_VAR_1} fois !\p"
	.string "{STR_VAR_3} doit être un incroyable\n"
	.string "maître des CONCOURS !$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedTitle::
	.string "Le Fervent du Shopping$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedAction::
	.string "a acheté$"

MauvilleCity_PokemonCenter_1F_Text_TimesShoppedStory::
	.string "C'est l'histoire d'un DRESSEUR\n"
	.string "nommé {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a acheté des objets en magasin\n"
	.string "{STR_VAR_1} fois !\p"
	.string "{STR_VAR_3} doit être un DRESSEUR\n"
	.string "qui aime faire du shopping !$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderTitle::
	.string "Le DRESSEUR chercheur d'objets$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderAction::
	.string "A utilisé un CHERCH'OBJET$"

MauvilleCity_PokemonCenter_1F_Text_UsedItemFinderStory::
	.string "C'est l'histoire d'un DRESSEUR\n"
	.string "nommé {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a utilisé un CHERCH'OBJET\n"
	.string "{STR_VAR_1} fois !\p"
	.string "{STR_VAR_3} doit adorer fouiller le sol\n"
	.string "à la recherche d'objets cachés !$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedTitle::
	.string "Le DRESSEUR trempé de pluie$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedAction::
	.string "A été mouillé$"

MauvilleCity_PokemonCenter_1F_Text_TimesRainedStory::
	.string "Voici l'histoire d'un DRESSEUR\n"
	.string "nommé {STR_VAR_3}.\p"
	.string "Ce DRESSEUR s'est fait tremper par la pluie\n"
	.string "{STR_VAR_1} fois !\p"
	.string "Le charisme de {STR_VAR_3} doit même\n"
	.string "attirer la pluie !$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexTitle::
	.string "Le lecteur assidu du POKéDEX$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexAction::
	.string "A consulté un POKéDEX$"

MauvilleCity_PokemonCenter_1F_Text_CheckedPokedexStory::
	.string "Voici l'histoire d'un DRESSEUR\n"
	.string "nommé {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a consulté le POKéDEX\n"
	.string "{STR_VAR_1} fois !\p"
	.string "{STR_VAR_3} doit adorer examiner\n"
	.string "les POKéMON dans un POKéDEX !$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsTitle::
	.string "Le Collectionneur de RUBANS$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsAction::
	.string "A reçu des RUBANS$"

MauvilleCity_PokemonCenter_1F_Text_ReceivedRibbonsStory::
	.string "Voici l'histoire d'un DRESSEUR\n"
	.string "nommé {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a reçu des RUBANS\n"
	.string "{STR_VAR_1} fois !\p"
	.string "{STR_VAR_3} doit être un DRESSEUR qui\n"
	.string "adore collectionner les RUBANS !$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedTitle::
	.string "Le DRESSEUR sauteur de ressorts$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedAction::
	.string "A sauté des sauts de falaise$"

MauvilleCity_PokemonCenter_1F_Text_LedgesJumpedStory::
	.string "C'est l'histoire d'un DRESSEUR\n"
	.string "nommé {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a sauté des rebords\n"
	.string "{STR_VAR_1} fois !\p"
	.string "S'il y a un rebord à sauter,\n"
	.string "{STR_VAR_3} ne peut pas s'en empêcher !$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedTitle::
	.string "Le téléspectateur légendaire$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedAction::
	.string "A regardé la TV$"

MauvilleCity_PokemonCenter_1F_Text_TVWatchedStory::
	.string "Voici l'histoire d'un DRESSEUR\n"
	.string "nommé {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a regardé la télé\n"
	.string "{STR_VAR_1} fois !\p"
	.string "{STR_VAR_3} doit adorer regarder la télé !$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockTitle::
	.string "Le DRESSEUR soucieux du temps$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockAction::
	.string "A consulté l'heure$"

MauvilleCity_PokemonCenter_1F_Text_CheckedClockStory::
	.string "C'est l'histoire d'un DRESSEUR\n"
	.string "nommé {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a vérifié l'heure\n"
	.string "{STR_VAR_1} fois !\p"
	.string "{STR_VAR_3} doit être un DRESSEUR ponctuel\n"
	.string "qui est conscient du temps.$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryTitle::
	.string "Le sorcier de la LOTERIE POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryAction::
	.string "A gagné à la LOTERIE POKéMON$"

MauvilleCity_PokemonCenter_1F_Text_WonLotteryStory::
	.string "C'est l'histoire d'un DRESSEUR\n"
	.string "nommé {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a gagné à la LOTERIE POKéMON\n"
	.string "{STR_VAR_1} fois !\p"
	.string "{STR_VAR_3} doit avoir beaucoup d'amis\n"
	.string "avec qui échanger des POKéMON !$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareTitle::
	.string "Le DRESSEUR qui utilise la PENSION$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareAction::
	.string "A laissé un POKéMON à la PENSION$"

MauvilleCity_PokemonCenter_1F_Text_UsedDaycareStory::
	.string "C'est l'histoire d'un DRESSEUR\n"
	.string "nommé {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a laissé des POKéMON à la\n"
	.string "PENSION {STR_VAR_1} fois !\p"
	.string "{STR_VAR_3} doit être quelqu'un qui\n"
	.string "lève ses POKéMON avec énergie !$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarTitle::
	.string "Le DRESSEUR amateur de TÉLÉCABINE$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarAction::
	.string "A pris le TÉLÉPHÉRIQUE$"

MauvilleCity_PokemonCenter_1F_Text_RodeCableCarStory::
	.string "C'est l'histoire d'un DRESSEUR\n"
	.string "nommé {STR_VAR_3}.\p"
	.string "Ce DRESSEUR a pris le TÉLÉPHÉRIQUE\n"
	.string "{STR_VAR_1} fois !\p"
	.string "{STR_VAR_3} doit être un DRESSEUR occupé\n"
	.string "qui monte et descend tout le temps !$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsTitle::
	.string "Le DRESSEUR amateur de sources chaudes$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsAction::
	.string "S'est baigné dans des sources chaudes$"

MauvilleCity_PokemonCenter_1F_Text_HotSpringsStory::
	.string "Voici l'histoire d'un DRESSEUR\n"
	.string "nommé {STR_VAR_3}.\p"
	.string "Ce DRESSEUR s'est baigné dans des sources\n"
	.string "chaudes {STR_VAR_1} fois !\p"
	.string "{STR_VAR_3} doit être un DRESSEUR\n"
	.string "à la peau douce comme un bébé !$"


MauvilleCity_PokemonCenter_1F_EventScript_Storyteller::
	lock
	faceplayer
	setvar VAR_0x8008, 0
	setvar VAR_0x8009, 0
	setvar VAR_0x800A, 0
	setvar VAR_0x800B, 0
	msgbox MauvilleCity_PokemonCenter_1F_Text_WillYouHearMyTale, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	specialvar VAR_RESULT, StorytellerGetFreeStorySlot
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_KnowNoTales
	message MauvilleCity_PokemonCenter_1F_Text_WhichTaleToTell
	waitmessage
	special StorytellerStoryListMenu
	waitstate
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_CancelStorySelection
	setvar VAR_0x8008, 1
	special Script_StorytellerDisplayStory
	waitmessage
	waitbuttonpress
	specialvar VAR_RESULT, StorytellerUpdateStat
	goto_if_eq VAR_RESULT, 0, MauvilleCity_PokemonCenter_1F_EventScript_AreThereOtherTales
	goto MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale

MauvilleCity_PokemonCenter_1F_EventScript_CancelStorySelection::
	goto MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	end

MauvilleCity_PokemonCenter_1F_EventScript_AreThereOtherTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_CouldThereBeOtherLegends, MSGBOX_DEFAULT
	specialvar VAR_RESULT, HasStorytellerAlreadyRecorded
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_StorytellerEnd
	goto MauvilleCity_PokemonCenter_1F_EventScript_DoYouHaveAnyTales

MauvilleCity_PokemonCenter_1F_EventScript_KnowNoTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_IKnowNoTales, MSGBOX_DEFAULT
MauvilleCity_PokemonCenter_1F_EventScript_DoYouHaveAnyTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_HaveYouAnyLegendaryTales, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller
	specialvar VAR_RESULT, Script_StorytellerInitializeRandomStat
	goto_if_eq VAR_RESULT, 1, MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale
	msgbox MauvilleCity_PokemonCenter_1F_Text_NotWorthyOfLegend, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_TellPlayersTale::
	msgbox MauvilleCity_PokemonCenter_1F_Text_YouDidStatXTimes, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineStoryteller::
	msgbox MauvilleCity_PokemonCenter_1F_Text_StorytellerFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

@ Unused
MauvilleCity_PokemonCenter_1F_EventScript_WaitingForRecordMix::
	msgbox MauvilleCity_PokemonCenter_1F_Text_IWishMorePeopleWereInterested, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_StorytellerEnd::
	release
	end

@ Giddy
MauvilleCity_PokemonCenter_1F_Text_HearMyStory:
	.string "Je suis GIDDY !\n"
	.string "J'ai une histoire scintillante pour toi !\p"
	.string "Tu veux entendre mon histoire ?$"

MauvilleCity_PokemonCenter_1F_Text_GiddyFeelingTheBlues:
	.string "Oh…\n"
	.string "Tu m'as laissé le blues…$"

MauvilleCity_PokemonCenter_1F_Text_AlsoIWasThinking:
	.string "Aussi, je pensais…$"

MauvilleCity_PokemonCenter_1F_Text_WeShouldChatAgain:
	.string "Je crois que c'est tout…\p"
	.string "On devrait reparler !\n"
	.string "À plus !$"

MauvilleCity_PokemonCenter_1F_EventScript_Giddy::
	lock
	faceplayer
	msgbox MauvilleCity_PokemonCenter_1F_Text_HearMyStory, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_TryTellTale
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_DeclineGiddy
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTellTale::
	special GiddyShouldTellAnotherTale
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales
	end

MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale::
	special GiddyShouldTellAnotherTale
	goto_if_eq VAR_RESULT, TRUE, MauvilleCity_PokemonCenter_1F_EventScript_GiddyStartNewTale
	goto_if_eq VAR_RESULT, FALSE, MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales
	end

MauvilleCity_PokemonCenter_1F_EventScript_GiddyStartNewTale::
	msgbox MauvilleCity_PokemonCenter_1F_Text_AlsoIWasThinking, MSGBOX_DEFAULT
	goto MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale
	end

@ Giddy will continue to tell stories regardless of whether yes or no is selected below.
@ Each story there is a 10% chance it will be his last. Otherwise he will stop at 10 stories.
MauvilleCity_PokemonCenter_1F_EventScript_GiddyTellTale::
	special GenerateGiddyLine
	special ShowFieldMessageStringVar4
	waitmessage
	yesnobox 20, 8
	goto_if_eq VAR_RESULT, YES, MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale
	goto_if_eq VAR_RESULT, NO, MauvilleCity_PokemonCenter_1F_EventScript_TryTellNewTale
	end

MauvilleCity_PokemonCenter_1F_EventScript_DeclineGiddy::
	msgbox MauvilleCity_PokemonCenter_1F_Text_GiddyFeelingTheBlues, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_ToldEnoughTales::
	msgbox MauvilleCity_PokemonCenter_1F_Text_WeShouldChatAgain, MSGBOX_DEFAULT
	release
	end

MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToHearMySong:
	.string "Bonjour, je suis le BARDE.\n"
	.string "Veux-tu écouter ma chanson ?$"

MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues1:
	.string "Oh…\n"
	.string "Tu m'as laissé le blues…$"

MauvilleCity_PokemonCenter_1F_Text_WishICouldPlaySongForOthers:
	.string "Oh, quelle chanson émouvante…\n"
	.string "J'aimerais la jouer pour les autres…$"

MauvilleCity_PokemonCenter_1F_Text_WouldYouLikeToWriteSomeLyrics:
	.string "Alors ?\n"
	.string "Qu'est-ce que tu penses de ma chanson ?\p"
	.string "Mais je ne suis pas très content des\n"
	.string "paroles.\p"
	.string "Tu voudrais m'écrire de\n"
	.string "nouvelles paroles ?$"

MauvilleCity_PokemonCenter_1F_Text_BardFeelingTheBlues2:
	.string "Oh…\n"
	.string "Tu m'as laissé le blues…$"

MauvilleCity_PokemonCenter_1F_Text_LetMeSingItForYou:
	.string "Merci beaucoup !\n"
	.string "Laisse-moi te le chanter.$"

MauvilleCity_PokemonCenter_1F_Text_ThatHowYouWantedSongToGo:
	.string "C'était comme tu voulais que\n"
	.string "ta chanson se passe ?$"

MauvilleCity_PokemonCenter_1F_Text_IllSingThisSongForAWhile:
	.string "D'accord ! C'est réglé.\n"
	.string "Je vais chanter cette chanson un moment.$"

MauvilleCity_PokemonCenter_1F_Text_TeachWhatsHipAndHappening:
	.string "Hé, yo ! On m'appelle le HIPSTER.\n"
	.string "Je vais t'apprendre ce qui est branché et tendance.$"

MauvilleCity_PokemonCenter_1F_Text_IAlreadyTaughtYou:
	.string "Mais bon, je t'ai déjà appris ce qui est\n"
	.string "branché.\p"
	.string "J'aimerais répandre la bonne parole\n"
	.string "à d'autres gens.$"

MauvilleCity_PokemonCenter_1F_Text_IveGotNothingNewToTeach:
	.string "Mais bon, tu connais déjà beaucoup de choses\n"
	.string "branchées.\p"
	.string "Je n'ai rien de nouveau à t'apprendre !$"

MauvilleCity_PokemonCenter_1F_Text_HaveYouHeardOfWord:
	.string "Hé, tu connais le mot\n"
	.string "« {STR_VAR_1} » ?\p"
	.string "Ça veut dire quoi ? Eh bien…\n"
	.string "Demande à ton papa ou à ta maman, d'accord ?$"
