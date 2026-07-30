.set LOCALID_WALDAS_DAD, 6

RustboroCity_Flat1_2F_MapScripts::
	.byte 0

RustboroCity_Flat1_2F_EventScript_WaldasDad::
	lock
	faceplayer
	specialvar VAR_RESULT, TryBufferWaldaPhrase
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_Flat1_2F_EventScript_WaldasDadFirstPhrase
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Flat1_2F_EventScript_WaldasDadNewPhrase

RustboroCity_Flat1_2F_EventScript_GivePhrase::
	special DoWaldaNamingScreen
	waitstate
	goto_if_eq VAR_0x8004, 1, RustboroCity_Flat1_2F_EventScript_CancelGivePhrase
	goto_if_eq VAR_0x8004, 2, RustboroCity_Flat1_2F_EventScript_CancelGiveFirstPhrase
	specialvar VAR_RESULT, TryGetWallpaperWithWaldaPhrase
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Flat1_2F_EventScript_WaldaLikesPhrase
	goto_if_eq VAR_RESULT, FALSE, RustboroCity_Flat1_2F_EventScript_WaldaDoesntLikePhrase
	end

RustboroCity_Flat1_2F_EventScript_WaldasDadFirstPhrase::
	msgbox RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase
	msgbox RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion, MSGBOX_DEFAULT
	goto RustboroCity_Flat1_2F_EventScript_GivePhrase

RustboroCity_Flat1_2F_EventScript_WaldasDadNewPhrase::
	msgbox RustboroCity_Flat1_2F_Text_BeenSayingXDoYouKnowBetterPhrase, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase
	msgbox RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion, MSGBOX_DEFAULT
	goto RustboroCity_Flat1_2F_EventScript_GivePhrase

RustboroCity_Flat1_2F_EventScript_DeclineGivePhrase::
	msgbox RustboroCity_Flat1_2F_Text_OhIsThatRight, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_CancelGivePhrase::
	msgbox RustboroCity_Flat1_2F_Text_OhYouDontKnowAny, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_CancelGiveFirstPhrase::
	msgbox RustboroCity_Flat1_2F_Text_ThinkOfMyOwnPhrase, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldaLikesPhrase::
	msgbox RustboroCity_Flat1_2F_Text_LetsGiveItATry2, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_OhShesLaughing, MSGBOX_DEFAULT
	applymovement LOCALID_WALDAS_DAD, Common_Movement_FacePlayer
	waitmovement 0
	msgbox RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldaDoesntLikePhrase::
	msgbox RustboroCity_Flat1_2F_Text_LetsGiveItATry, MSGBOX_DEFAULT
	call RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda
	msgbox RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat1_2F_EventScript_WaldasDadFaceWalda::
	turnobject LOCALID_WALDAS_DAD, DIR_EAST
	return

RustboroCity_Flat1_2F_EventScript_WaldasMom::
	msgbox RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard, MSGBOX_NPC
	end

RustboroCity_Flat1_2F_EventScript_PokeDoll::
	msgbox RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll, MSGBOX_SIGN
	end

RustboroCity_Flat1_2F_Text_ComingUpWithMealsIsHard:
	.string "Oh, c'est si dur chaque jour…\p"
	.string "Qu'est-ce qui est dur ?\n"
	.string "Tu dois demander ?\p"
	.string "C'est essayer de trouver quoi\n"
	.string "préparer à manger chaque jour.\p"
	.string "Ce n'est vraiment pas facile d'inventer\n"
	.string "des repas chaque jour.$"

RustboroCity_Flat1_2F_Text_HelloDoYouKnowFunnyPhrase:
	.string "Oh, bonjour !\n"
	.string "Bienvenue dans la famille POIVRE.\p"
	.string "J'ai une question pour toi.\n"
	.string "As-tu déjà fait du baby-sitting ?\p"
	.string "Tu vois, je suis un nouveau père, alors élever\n"
	.string "un enfant est tout nouveau pour moi.\p"
	.string "Et j'ai un problème. Ma fille\n"
	.string "WALDA ne rit pas assez.\p"
	.string "Je pense qu'elle rirait pour moi si je lui disais\n"
	.string "quelque chose de drôle.\p"
	.string "Connais-tu un mot ou une phrase drôle\n"
	.string "que tu pourrais me dire ?$"

RustboroCity_Flat1_2F_Text_BeenSayingXDoYouKnowBetterPhrase:
	.string "Je dis « {STR_VAR_1} » pour\n"
	.string "l'amuser ces derniers temps. Tu connais\p"
	.string "un meilleur mot ou une\n"
	.string "phrase qui pourrait marcher ?$"

RustboroCity_Flat1_2F_Text_WonderfulLetsHearSuggestion:
	.string "Oh, c'est merveilleux.\n"
	.string "Alors, voyons voir ta suggestion.$"

RustboroCity_Flat1_2F_Text_OhIsThatRight:
	.string "Oh, c'est vrai ?\p"
	.string "Eh bien, si tu as une bonne\n"
	.string "suggestion, je suis tout ouïe.$"

RustboroCity_Flat1_2F_Text_LetsGiveItATry2:
	.string "Ah, je vois.\n"
	.string "Eh bien, essayons, d'accord ?$"

RustboroCity_Flat1_2F_Text_OhShesLaughing:
	.string "{STR_VAR_1}.\n"
	.string "{STR_VAR_1}.\p"
	.string "Oh, oui ! Elle rit !\n"
	.string "Oh, je suis aussi ravie qu'elle !$"

RustboroCity_Flat1_2F_Text_LetsGiveItATry:
	.string "Ah, je vois.\n"
	.string "Eh bien, essayons, d'accord ?$"

RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll:
	.string "{STR_VAR_1}.\n"
	.string "{STR_VAR_1}.\p"
	.string "Hmm… Elle ne sourit pas du tout.\n"
	.string "Peut-être que WALDA est une enfant sérieuse…$"

RustboroCity_Flat1_2F_Text_ThinkOfMyOwnPhrase:
	.string "Oh, tu ne connais donc aucun bon mot.\n"
	.string "Je ferais mieux de réfléchir par moi-même.\p"
	.string "Hmm…\n"
	.string "Que dirais-tu de « {STR_VAR_1} » ?\l"
	.string "Voyons si ça marchera.$"

RustboroCity_Flat1_2F_Text_ShesNotSmilingAtAll2:
	.string "{STR_VAR_1}.\n"
	.string "{STR_VAR_1}.\p"
	.string "Hmm… Elle ne sourit pas du tout.\n"
	.string "Peut-être que WALDA est une enfant sérieuse…$"

RustboroCity_Flat1_2F_Text_OhYouDontKnowAny:
	.string "Oh, tu ne connais donc pas de bons mots.\n"
	.string "Je vais essayer de l'amuser avec\l"
	.string "la phrase que j'ai utilisée avant.\p"
	.string "Bref, si tu as une bonne suggestion,\n"
	.string "n'hésite pas à me la dire, d'accord ?$"

RustboroCity_Flat1_2F_Text_ThankYouIllGiveYouWallpaper:
	.string "Merci !\p"
	.string "Grâce à toi, ma chérie WALDA\n"
	.string "a ri pour moi !\p"
	.string "En fait, je n'ai peut-être pas l'air spécial,\n"
	.string "mais je suis l'un des meilleurs chercheurs\l"
	.string "de DEVON S.A.\p"
	.string "Alors, que dirais-tu que je fasse quelque chose\n"
	.string "en retour pour toi ?\p"
	.string "Je sais, j'ajouterai de nouveaux motifs\n"
	.string "de papier peint pour les BOÎTES dans le\l"
	.string "Système de Stockage PC POKéMON.\p"
	.string "Dans le menu des motifs de papier peint,\n"
	.string "sélectionne « AMIS ».\p"
	.string "Ça te donnera accès aux nouveaux\n"
	.string "motifs de papier peint.$"

RustboroCity_Flat1_2F_Text_ItsAPokemonPlushDoll:
	.string "C'est une PELUCHE de POKéMON !$"

