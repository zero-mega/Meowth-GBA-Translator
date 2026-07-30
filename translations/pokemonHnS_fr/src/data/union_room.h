ALIGNED(4) static const u8 sText_EmptyString[] = _("");
ALIGNED(4) static const u8 sText_Colon[] = _(":");
ALIGNED(4) static const u8 sText_ID[] = _("{ID}");
ALIGNED(4) static const u8 sText_PleaseStartOver[] = _("Recommence depuis le début.");
ALIGNED(4) static const u8 sText_WirelessSearchCanceled[] = _("La recherche du SYSTÈME DE\nCOMMUNICATION SANS FIL a été annulée.");
ALIGNED(4) static const u8 sText_AwaitingCommunucation2[] = _("En attente de communication\nd'un autre joueur."); // Unused
ALIGNED(4) static const u8 sText_AwaitingCommunication[] = _("{STR_VAR_1} ! En attente de\ncommunication d'un autre joueur.");
ALIGNED(4) static const u8 sText_AwaitingLinkPressStart[] = _("{STR_VAR_1} ! En attente de lien !\nAppuie sur START quand tout le monde est prêt.");
ALIGNED(4) static const u8 sJPText_SingleBattle[] = _("シングルバトルを かいさいする");
ALIGNED(4) static const u8 sJPText_DoubleBattle[] = _("ダブルバトルを かいさいする");
ALIGNED(4) static const u8 sJPText_MultiBattle[] = _("マルチバトルを かいさいする");
ALIGNED(4) static const u8 sJPText_TradePokemon[] = _("ポケモンこうかんを かいさいする");
ALIGNED(4) static const u8 sJPText_Chat[] = _("チャットを かいさいする");
ALIGNED(4) static const u8 sJPText_DistWonderCard[] = _("ふしぎなカードをくばる");
ALIGNED(4) static const u8 sJPText_DistWonderNews[] = _("ふしぎなニュースをくばる");
ALIGNED(4) static const u8 sJPText_DistMysteryEvent[] = _("ふしぎなできごとを かいさいする"); // Unused
ALIGNED(4) static const u8 sJPText_HoldPokemonJump[] = _("なわとびを かいさいする");
ALIGNED(4) static const u8 sJPText_HoldBerryCrush[] = _("きのみマッシャーを かいさいする");
ALIGNED(4) static const u8 sJPText_HoldBerryPicking[] = _("きのみどりを かいさいする");
ALIGNED(4) static const u8 sJPText_HoldSpinTrade[] = _("ぐるぐるこうかんを かいさいする");
ALIGNED(4) static const u8 sJPText_HoldSpinShop[] = _("ぐるぐるショップを かいさいする");

// Unused
static const u8 *const sJPLinkGroupActionTexts[] = {
    sJPText_SingleBattle,
    sJPText_DoubleBattle,
    sJPText_MultiBattle,
    sJPText_TradePokemon,
    sJPText_Chat,
    sJPText_DistWonderCard,
    sJPText_DistWonderNews,
    sJPText_DistWonderCard,
    sJPText_HoldPokemonJump,
    sJPText_HoldBerryCrush,
    sJPText_HoldBerryPicking,
    sJPText_HoldBerryPicking,
    sJPText_HoldSpinTrade,
    sJPText_HoldSpinShop
};

static const u8 sText_1PlayerNeeded[] = _("1 joueur\nnécessaire.");
static const u8 sText_2PlayersNeeded[] = _("2 joueurs\nnécessaires.");
static const u8 sText_3PlayersNeeded[] = _("3 joueurs\nnécessaires.");
static const u8 sText_4PlayersNeeded[] = _("4 joueurs\nnécessaires.");
static const u8 sText_2PlayerMode[] = _("MODE\n2 JOUEURS");
static const u8 sText_3PlayerMode[] = _("MODE\n3 JOUEURS");
static const u8 sText_4PlayerMode[] = _("MODE\n4 JOUEURS");
static const u8 sText_5PlayerMode[] = _("MODE\n5 JOUEURS");

static const u8 *const sPlayersNeededOrModeTexts[][5] = {
    // 2 players required
    {
        sText_1PlayerNeeded,
        sText_2PlayerMode
    },
    // 4 players required
    {
        sText_3PlayersNeeded,
        sText_2PlayersNeeded,
        sText_1PlayerNeeded,
        sText_4PlayerMode
    },
    // 2-5 players required
    {
        sText_1PlayerNeeded,
        sText_2PlayerMode,
        sText_3PlayerMode,
        sText_4PlayerMode,
        sText_5PlayerMode
    },
    // 3-5 players required
    {
        sText_2PlayersNeeded,
        sText_1PlayerNeeded,
        sText_3PlayerMode,
        sText_4PlayerMode,
        sText_5PlayerMode
    },
    // 2-4 players required
    {
        sText_1PlayerNeeded,
        sText_2PlayerMode,
        sText_3PlayerMode,
        sText_4PlayerMode
    }
};

ALIGNED(4) static const u8 sText_BButtonCancel[] = _("{B_BUTTON}ANNULER");
ALIGNED(4) static const u8 sJPText_SearchingForParticipants[] = _("ため\nさんかしゃ ぼしゅうちゅう です！"); // Unused, may have been cut off
ALIGNED(4) static const u8 sText_PlayerContactedYouForXAccept[] = _("{STR_VAR_2} t'a contacté pour\n{STR_VAR_1}. Accepter ?");
ALIGNED(4) static const u8 sText_PlayerContactedYouShareX[] = _("{STR_VAR_2} t'a contacté.\nVeux-tu partager {STR_VAR_1} ?");
ALIGNED(4) static const u8 sText_PlayerContactedYouAddToMembers[] = _("{STR_VAR_2} t'a contacté.\nAjouter aux membres ?");
ALIGNED(4) static const u8 sText_AreTheseMembersOK[] = _("{STR_VAR_1} !\nCes membres conviennent-ils ?");
ALIGNED(4) static const u8 sText_CancelModeWithTheseMembers[] = _("Annuler le MODE {STR_VAR_1}\navec ces membres ?");
ALIGNED(4) static const u8 sText_AnOKWasSentToPlayer[] = _("Un « OK » a été envoyé\nà {STR_VAR_1}.");
ALIGNED(4) static const u8 sText_OtherTrainerUnavailableNow[] = _("L'autre DRESSEUR ne semble pas\ndisponible pour l'instant…\p");
ALIGNED(4) static const u8 sText_CantTransmitTrainerTooFar[] = _("Tu ne peux pas communiquer avec un DRESSEUR\ntrop éloigné.\p");
ALIGNED(4) static const u8 sText_TrainersNotReadyYet[] = _("L'autre DRESSEUR n'est pas\nencore prêt.\p");

static const u8 *const sCantTransmitToTrainerTexts[] = {
    [UR_TRADE_PLAYER_NOT_READY - 1]  = sText_CantTransmitTrainerTooFar,
    [UR_TRADE_PARTNER_NOT_READY - 1] = sText_TrainersNotReadyYet
};

ALIGNED(4) static const u8 sText_ModeWithTheseMembersWillBeCanceled[] = _("Le mode {STR_VAR_1} avec\nces membres sera annulé.{PAUSE 60}");
ALIGNED(4) static const u8 sText_MemberNoLongerAvailable[] = _("Un membre ne peut plus\nrester disponible.\p");

static const u8 *const sPlayerUnavailableTexts[] = {
    sText_OtherTrainerUnavailableNow,
    sText_MemberNoLongerAvailable
};

ALIGNED(4) static const u8 sText_TrainerAppearsUnavailable[] = _("L'autre DRESSEUR semble\nindisponible…\p");
ALIGNED(4) static const u8 sText_PlayerSentBackOK[] = _("{STR_VAR_1} a répondu « OK » !");
ALIGNED(4) static const u8 sText_PlayerOKdRegistration[] = _("{STR_VAR_1} a accepté ton inscription\nen tant que membre.");
ALIGNED(4) static const u8 sText_PlayerRepliedNo[] = _("{STR_VAR_1} a répondu « Non… »\p");
ALIGNED(4) static const u8 sText_AwaitingOtherMembers[] = _("{STR_VAR_1} !\nEn attente des autres membres !");
ALIGNED(4) static const u8 sText_QuitBeingMember[] = _("Quitter le groupe ?");
ALIGNED(4) static const u8 sText_StoppedBeingMember[] = _("Tu n'es plus membre.\p");

static const u8 *const sPlayerDisconnectedTexts[] = {
    [RFU_STATUS_OK]                  = NULL,
    [RFU_STATUS_FATAL_ERROR]         = sText_MemberNoLongerAvailable,
    [RFU_STATUS_CONNECTION_ERROR]    = sText_TrainerAppearsUnavailable,
    [RFU_STATUS_CHILD_SEND_COMPLETE] = NULL,
    [RFU_STATUS_NEW_CHILD_DETECTED]  = NULL,
    [RFU_STATUS_JOIN_GROUP_OK]       = NULL,
    [RFU_STATUS_JOIN_GROUP_NO]       = sText_PlayerRepliedNo,
    [RFU_STATUS_WAIT_ACK_JOIN_GROUP] = NULL,
    [RFU_STATUS_LEAVE_GROUP_NOTICE]  = NULL,
    [RFU_STATUS_LEAVE_GROUP]         = sText_StoppedBeingMember
};

ALIGNED(4) static const u8 sText_WirelessLinkEstablished[] = _("La liaison du SYSTÈME DE\nCOMMUNICATION SANS FIL est établie.");
ALIGNED(4) static const u8 sText_WirelessLinkDropped[] = _("La liaison du SYSTÈME de\nCOMMUNICATION SANS FIL a été coupée…");
ALIGNED(4) static const u8 sText_LinkWithFriendDropped[] = _("La connexion avec ton ami a été\ninterrompue…");
ALIGNED(4) static const u8 sText_PlayerRepliedNo2[] = _("{STR_VAR_1} a répondu : « Non… »");

static const u8 *const sLinkDroppedTexts[] = {
    [RFU_STATUS_OK]                  = NULL,
    [RFU_STATUS_FATAL_ERROR]         = sText_LinkWithFriendDropped,
    [RFU_STATUS_CONNECTION_ERROR]    = sText_LinkWithFriendDropped,
    [RFU_STATUS_CHILD_SEND_COMPLETE] = NULL,
    [RFU_STATUS_NEW_CHILD_DETECTED]  = NULL,
    [RFU_STATUS_JOIN_GROUP_OK]       = NULL,
    [RFU_STATUS_JOIN_GROUP_NO]       = sText_PlayerRepliedNo2,
    [RFU_STATUS_WAIT_ACK_JOIN_GROUP] = NULL,
    [RFU_STATUS_LEAVE_GROUP_NOTICE]  = NULL,
    [RFU_STATUS_LEAVE_GROUP]         = NULL
};

ALIGNED(4) static const u8 sText_DoYouWantXMode[] = _("Veux-tu le MODE\n{STR_VAR_2} ?");
ALIGNED(4) static const u8 sText_DoYouWantXMode2[] = _("Veux-tu le MODE\n{STR_VAR_2} ?");

// Unused
static const u8 *const sDoYouWantModeTexts[] = {
    sText_DoYouWantXMode,
    sText_DoYouWantXMode2
};

ALIGNED(4) static const u8 sText_CommunicatingPleaseWait[] = _("Communication…\nVeuillez patienter."); // Unused
ALIGNED(4) static const u8 sText_AwaitingPlayersResponseAboutTrade[] = _("En attente de la réponse de {STR_VAR_1}\nconcernant l'échange…");
ALIGNED(4) static const u8 sText_Communicating[] = _("Communicating{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\n"
                                                     "{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.");
ALIGNED(4) static const u8 sText_CommunicatingWithPlayer[] = _("Communicating with {STR_VAR_1}{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\n"
                                                               "{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.");
ALIGNED(4) static const u8 sText_PleaseWaitAWhile[] = _("Please wait a while{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.\n"
                                                        "{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.{PAUSE 15}.");

static const u8 *const sCommunicatingWaitTexts[] = {
    sText_Communicating,
    sText_CommunicatingWithPlayer,
    sText_PleaseWaitAWhile
};

ALIGNED(4) static const u8 sText_HiDoSomethingMale[] = _("Salut ! Y a-t-il quelque chose\nque tu voulais faire ?");
ALIGNED(4) static const u8 sText_HiDoSomethingFemale[] = _("Bonjour !\nTu veux faire quelque chose ?");
ALIGNED(4) static const u8 sText_HiDoSomethingAgainMale[] = _("{STR_VAR_1} : Salut, on se revoit !\nQu'est-ce que tu veux faire cette fois ?");
ALIGNED(4) static const u8 sText_HiDoSomethingAgainFemale[] = _("{STR_VAR_1} : Oh ! {PLAYER}, salut !\nTu veux faire quelque chose ?");

static const u8 *const sHiDoSomethingTexts[][GENDER_COUNT] = {
    {
        sText_HiDoSomethingMale,
        sText_HiDoSomethingFemale
    }, {
        sText_HiDoSomethingAgainMale,
        sText_HiDoSomethingAgainFemale
    }
};

ALIGNED(4) static const u8 sText_DoSomethingMale[] = _("Tu veux faire quelque chose ?");
ALIGNED(4) static const u8 sText_DoSomethingFemale[] = _("Veux-tu faire quelque chose ?");
ALIGNED(4) static const u8 sText_DoSomethingAgainMale[] = _("{STR_VAR_1} : Que veux-tu\nfaire maintenant ?");
ALIGNED(4) static const u8 sText_DoSomethingAgainFemale[] = _("{STR_VAR_1} : Tu veux faire autre chose ?"); // Unused

// Unused
static const u8 *const sDoSomethingTexts[][GENDER_COUNT] = {
    {
        sText_DoSomethingMale,
        sText_DoSomethingFemale
    }, {
        sText_DoSomethingAgainMale,
        sText_DoSomethingAgainMale // was probably supposed to be sText_DoSomethingAgainFemale
    }
};

ALIGNED(4) static const u8 sText_SomebodyHasContactedYou[] = _("Quelqu'un t'a contacté.{PAUSE 60}");
ALIGNED(4) static const u8 sText_PlayerHasContactedYou[] = _("{STR_VAR_1} t'a contacté.{PAUSE 60}");

static const u8 *const sPlayerContactedYouTexts[] = {
    sText_SomebodyHasContactedYou,
    sText_PlayerHasContactedYou
};

ALIGNED(4) static const u8 sText_AwaitingResponseFromTrainer[] = _("En attente d'une réponse\ndu DRESSEUR…");
ALIGNED(4) static const u8 sText_AwaitingResponseFromPlayer[] = _("En attente d'une réponse de\n{STR_VAR_1}…");

static const u8 *const sAwaitingResponseTexts[] = {
    sText_AwaitingResponseFromTrainer,
    sText_AwaitingResponseFromPlayer
};

ALIGNED(4) static const u8 sText_ShowTrainerCard[] = _("L'autre DRESSEUR t'a montré\nsa CARTE DE DRESSEUR.\pTu veux montrer ta\nCARTE DE DRESSEUR ?");
ALIGNED(4) static const u8 sText_BattleChallenge[] = _("L'autre DRESSEUR te défie\nen combat.\pAcceptes-tu le défi\nde combat ?");
ALIGNED(4) static const u8 sText_ChatInvitation[] = _("L'autre DRESSEUR t'invite\nà discuter.\pAcceptes-tu l'invitation\nà discuter ?");
ALIGNED(4) static const u8 sText_OfferToTradeMon[] = _("Une offre d'échange de ton\n{DYNAMIC 1} N. {DYNAMIC 0} enregistré\pen contrepartie d'un\n{DYNAMIC 3} N. {DYNAMIC 2}.\pAcceptes-tu cette offre\nd'échange ?");
ALIGNED(4) static const u8 sText_OfferToTradeEgg[] = _("Il y a une offre d'échange pour ton\nŒUF enregistré.\lAcceptes-tu cette offre d'échange ?");
ALIGNED(4) static const u8 sText_ChatDropped[] = _("Le chat a été interrompu.\p");
ALIGNED(4) static const u8 sText_OfferDeclined1[] = _("Tu as refusé l'offre.\p");
ALIGNED(4) static const u8 sText_OfferDeclined2[] = _("Tu as refusé l'offre.\p");
ALIGNED(4) static const u8 sText_ChatEnded[] = _("La discussion est terminée.\p");

// Unused
static const u8 *const sInvitationTexts[] = {
    sText_ShowTrainerCard,
    sText_BattleChallenge,
    sText_ChatInvitation,
    sText_OfferToTradeMon
};

ALIGNED(4) static const u8 sText_JoinChatMale[] = _("Oh, hé ! On est en train de discuter.\nTu veux nous rejoindre ?");
ALIGNED(4) static const u8 sText_PlayerJoinChatMale[] = _("{STR_VAR_1} : Hé, {PLAYER} !\nOn discute en ce moment.\lTu veux nous rejoindre ?");
ALIGNED(4) static const u8 sText_JoinChatFemale[] = _("Oh, salut ! On discute.\nTu veux nous rejoindre ?");
ALIGNED(4) static const u8 sText_PlayerJoinChatFemale[] = _("{STR_VAR_1} : Oh, salut, {PLAYER} !\nOn discute en ce moment.\lTu veux nous rejoindre ?");

static const u8 *const sJoinChatTexts[][GENDER_COUNT] = {
    {
        sText_JoinChatMale,
        sText_JoinChatFemale
    }, {
        sText_PlayerJoinChatMale,
        sText_PlayerJoinChatFemale
    }
};

ALIGNED(4) static const u8 sText_TrainerAppearsBusy[] = _("……\nLe DRESSEUR semble occupé…\p");
ALIGNED(4) static const u8 sText_WaitForBattleMale[] = _("Un combat, hein ?\nD'accord, donne-moi un peu de temps.");
ALIGNED(4) static const u8 sText_WaitForChatMale[] = _("Tu veux discuter, hein ?\nD'accord, attends un peu.");
ALIGNED(4) static const u8 sText_ShowTrainerCardMale[] = _("Bien sûr ! En guise de « Salutations »,\nvoici ma CARTE de DRESSEUR.");
ALIGNED(4) static const u8 sText_WaitForBattleFemale[] = _("Un combat ? Bien sûr, mais j'ai besoin\nde temps pour me préparer.");
ALIGNED(4) static const u8 sText_WaitForChatFemale[] = _("Tu voulais discuter ?\nD'accord, mais patiente un moment.");
ALIGNED(4) static const u8 sText_ShowTrainerCardFemale[] = _("Pour me présenter, je vais te montrer\nma CARTE DRESSEUR.");

static const u8 *const sText_WaitOrShowCardTexts[GENDER_COUNT][4] = {
    {
        sText_WaitForBattleMale,
        sText_WaitForChatMale,
        NULL,
        sText_ShowTrainerCardMale
    }, {
        sText_WaitForBattleFemale,
        sText_WaitForChatFemale,
        NULL,
        sText_ShowTrainerCardFemale
    }
};

ALIGNED(4) static const u8 sText_WaitForChatMale2[] = _("Tu veux discuter, hein ?\nD'accord, attends un peu."); // Unused
ALIGNED(4) static const u8 sText_DoneWaitingBattleMale[] = _("Merci d'avoir attendu !\nCommençons notre combat !{PAUSE 60}");
ALIGNED(4) static const u8 sText_DoneWaitingChatMale[] = _("D'accord !\nDiscutons !{PAUSE 60}");
ALIGNED(4) static const u8 sText_DoneWaitingBattleFemale[] = _("Désolé de t'avoir fait attendre !\nC'est parti !{PAUSE 60}");
ALIGNED(4) static const u8 sText_DoneWaitingChatFemale[] = _("Désolé de t'avoir fait attendre !\nDiscutons.{PAUSE 60}");
ALIGNED(4) static const u8 sText_TradeWillBeStarted[] = _("L'échange va commencer.{PAUSE 60}");
ALIGNED(4) static const u8 sText_BattleWillBeStarted[] = _("Le combat va commencer.{PAUSE 60}");
ALIGNED(4) static const u8 sText_EnteringChat[] = _("Connexion au chat…{PAUSE 60}");

static const u8 *const sStartActivityTexts[][GENDER_COUNT][3] = {
    {
        {
            sText_BattleWillBeStarted,
            sText_EnteringChat,
            sText_TradeWillBeStarted
        }, {
            sText_BattleWillBeStarted,
            sText_EnteringChat,
            sText_TradeWillBeStarted
        }
    }, {
        {
            sText_DoneWaitingBattleMale,
            sText_DoneWaitingChatMale,
            sText_TradeWillBeStarted
        }, {
            sText_DoneWaitingBattleFemale,
            sText_DoneWaitingChatFemale,
            sText_TradeWillBeStarted
        }
    }
};

ALIGNED(4) static const u8 sText_BattleDeclinedMale[] = _("Désolé ! Mes POKéMON ne se sentent pas\ntrès bien pour l'instant.\lBattons-nous une autre fois.\p");
ALIGNED(4) static const u8 sText_BattleDeclinedFemale[] = _("Je suis vraiment désolé, mais mes POKéMON\nne se sentent pas bien…\pCombattons une autre fois.\p");

static const u8 *const sBattleDeclinedTexts[GENDER_COUNT] = {
    sText_BattleDeclinedMale,
    sText_BattleDeclinedFemale
};

ALIGNED(4) static const u8 sText_ShowTrainerCardDeclinedMale[] = _("Hein ? Ma CARTE DRESSEUR…\nOù est-elle passée ?\lDésolé ! Je te la montrerai une autre fois !\p");
ALIGNED(4) static const u8 sText_ShowTrainerCardDeclinedFemale[] = _("Oh ? Où ai-je mis ma\nCARTE DRESSEUR ?…\lDésolé ! Je te la montrerai plus tard !\p");

static const u8 *const sShowTrainerCardDeclinedTexts[GENDER_COUNT] = {
    sText_ShowTrainerCardDeclinedMale,
    sText_ShowTrainerCardDeclinedFemale
};

ALIGNED(4) static const u8 sText_IfYouWantToDoSomethingMale[] = _("Si tu veux faire quelque chose avec\nmoi, fais-moi signe !\p");
ALIGNED(4) static const u8 sText_IfYouWantToDoSomethingFemale[] = _("Si tu veux faire quelque chose avec\nmoi, ne sois pas timide.\p");

static const u8 *const sIfYouWantToDoSomethingTexts[GENDER_COUNT] = {
    sText_IfYouWantToDoSomethingMale,
    sText_IfYouWantToDoSomethingFemale
};

ALIGNED(4) static const u8 sText_TrainerBattleBusy[] = _("Oups ! Désolé, mais j'ai\nautre chose à faire.\lUne autre fois, d'accord ?\p");
ALIGNED(4) static const u8 sText_NeedTwoMonsOfLevel30OrLower1[] = _("Si tu veux combattre, il te faut\ndeux POKéMON de moins de\lniveau 30.\p");
ALIGNED(4) static const u8 sText_NeedTwoMonsOfLevel30OrLower2[] = _("Pour un combat, il te faut deux\nPOKéMON de niveau inférieur à 30.\p");

ALIGNED(4) static const u8 sText_DeclineChatMale[] = _("D'accord.\nViens me voir quand tu veux, OK ?\p");
ALIGNED(4) static const u8 stext_DeclineChatFemale[] = _("Oh…\nReviens quand tu veux.\p");

// Response from partner when player declines chat
static const u8 *const sDeclineChatTexts[GENDER_COUNT] = {
    sText_DeclineChatMale,
    stext_DeclineChatFemale
};

ALIGNED(4) static const u8 sText_ChatDeclinedMale[] = _("Oh, désolé !\nJe ne peux pas maintenant.\lOn discutera une autre fois.\p");
ALIGNED(4) static const u8 sText_ChatDeclinedFemale[] = _("Oh, je suis désolé.\nJ'ai trop à faire en ce moment.\lOn discutera une autre fois.\p");

// Response from partner when they decline chat
static const u8 *const sChatDeclinedTexts[GENDER_COUNT] = {
    sText_ChatDeclinedMale,
    sText_ChatDeclinedFemale
};

ALIGNED(4) static const u8 sText_YoureToughMale[] = _("Whoa !\nJe vois que tu es assez coriace !\p");
ALIGNED(4) static const u8 sText_UsedGoodMoveMale[] = _("Tu as utilisé cette capacité ?\nBonne stratégie !\p");
ALIGNED(4) static const u8 sText_BattleSurpriseMale[] = _("Bravo !\nÇa m'a ouvert les yeux !\p");
ALIGNED(4) static const u8 sText_SwitchedMonsMale[] = _("Oh ! Comment as-tu pu utiliser ce\nPOKéMON dans cette situation ?\p");
ALIGNED(4) static const u8 sText_YoureToughFemale[] = _("Ce POKéMON…\nIl a été très bien élevé !\p");
ALIGNED(4) static const u8 sText_UsedGoodMoveFemale[] = _("C'est ça !\nC'est la bonne capacité maintenant !\p");
ALIGNED(4) static const u8 sText_BattleSurpriseFemale[] = _("C'est génial !\nTu peux te battre comme ça ?\p");
ALIGNED(4) static const u8 sText_SwitchedMonsFemale[] = _("Tu as un timing parfait pour\nchanger de POKéMON !\p");

static const u8 *const sBattleReactionTexts[GENDER_COUNT][4] = {
    {
        sText_YoureToughMale,
        sText_UsedGoodMoveMale,
        sText_BattleSurpriseMale,
        sText_SwitchedMonsMale
    },
    {
        sText_YoureToughFemale,
        sText_UsedGoodMoveFemale,
        sText_BattleSurpriseFemale,
        sText_SwitchedMonsFemale
    }
};

ALIGNED(4) static const u8 sText_LearnedSomethingMale[] = _("Oh, je vois !\nC'est instructif !\p");
ALIGNED(4) static const u8 sText_ThatsFunnyMale[] = _("Ne dis plus rien de drôle !\nJ'ai mal aux côtes d'avoir ri !\p");
ALIGNED(4) static const u8 sText_RandomChatMale1[] = _("Oh ?\nQuelque chose comme ça s'est passé.\p");
ALIGNED(4) static const u8 sText_RandomChatMale2[] = _("Hmhm… Quoi ?\nC'est donc ça que tu dis ?\p");
ALIGNED(4) static const u8 sText_LearnedSomethingFemale[] = _("Vraiment ?\nJe ne savais pas.\p");
ALIGNED(4) static const u8 sText_ThatsFunnyFemale[] = _("Ahaha !\nQu'est-ce que c'est que ça ?\p");
ALIGNED(4) static const u8 sText_RandomChatFemale1[] = _("Oui, c'est exactement ça !\nC'est ce que je voulais dire.\p");
ALIGNED(4) static const u8 sText_RandomChatFemale2[] = _("En d'autres termes…\nOui ! C'est ça !\p");

static const u8 *const sChatReactionTexts[GENDER_COUNT][4] = {
    {
        sText_LearnedSomethingMale,
        sText_ThatsFunnyMale,
        sText_RandomChatMale1,
        sText_RandomChatMale2
    },
    {
        sText_LearnedSomethingFemale,
        sText_ThatsFunnyFemale,
        sText_RandomChatFemale1,
        sText_RandomChatFemale2
    }
};

ALIGNED(4) static const u8 sText_ShowedTrainerCardMale1[] = _("Je te montre ma CARTE de DRESSEUR\npour te saluer.\p");
ALIGNED(4) static const u8 sText_ShowedTrainerCardMale2[] = _("J'espère apprendre à mieux te connaître !\p");
ALIGNED(4) static const u8 sText_ShowedTrainerCardFemale1[] = _("On se montre nos CARTES DRESSEUR\npour faire connaissance.\p");
ALIGNED(4) static const u8 sText_ShowedTrainerCardFemale2[] = _("Ravi de te rencontrer.\nNe sois pas un étranger !\p");

static const u8 *const sTrainerCardReactionTexts[GENDER_COUNT][2] = {
    {
        sText_ShowedTrainerCardMale1,
        sText_ShowedTrainerCardMale2
    },
    {
        sText_ShowedTrainerCardFemale1,
        sText_ShowedTrainerCardFemale2
    }
};

ALIGNED(4) static const u8 sText_MaleTraded1[] = _("Yeahah !\nJe voulais vraiment ce POKéMON !\p");
ALIGNED(4) static const u8 sText_MaleTraded2[] = _("Enfin, un échange m'a permis d'avoir ce\nPOKéMON que je voulais depuis longtemps.\p");
ALIGNED(4) static const u8 sText_FemaleTraded1[] = _("J'échange des POKéMON en ce moment.\p");
ALIGNED(4) static const u8 sText_FemaleTraded2[] = _("J'ai enfin obtenu le POKéMON que\nje voulais en échange !\p");

static const u8 *const sTradeReactionTexts[GENDER_COUNT][4] = {
    {
        sText_MaleTraded1,
        sText_MaleTraded2
    },
    {
        sText_FemaleTraded1,
        sText_FemaleTraded2
    }
};

ALIGNED(4) static const u8 sText_XCheckedTradingBoard[] = _("{STR_VAR_1} a consulté le\nTABLEAU D'ÉCHANGE.\p");
ALIGNED(4) static const u8 sText_RegisterMonAtTradingBoard[] = _("Bienvenue au TABLEAU D'ÉCHANGE.\pTu peux enregistrer ton POKéMON\net le proposer à l'échange.\pVeux-tu enregistrer l'un de\ntes POKéMON ?");
ALIGNED(4) static const u8 sText_TradingBoardInfo[] = _("This TRADING BOARD is used for\n"
                                                        "offering a POKéMON for a trade.\p"
                                                        "All you need to do is register a\n"
                                                        "POKéMON for a trade.\p"
                                                        "Another TRAINER may offer a party\n"
                                                        "POKéMON in return for the trade.\p"
                                                        "We hope you will register POKéMON\n"
                                                        "and trade them with many, many\l"
                                                        "other TRAINERS.\p"
                                                        "Would you like to register one of\nyour POKéMON?");
ALIGNED(4) static const u8 sText_ThankYouForRegistering[] = _("Nous avons enregistré ton POKéMON\npour l'échange sur le TABLEAU D'ÉCHANGE.\pMerci d'utiliser ce service !\p"); // unused
ALIGNED(4) static const u8 sText_NobodyHasRegistered[] = _("Personne n'a enregistré de POKéMON\npour échange sur le TABLEAU D'ÉCHANGE.\p\n"); // unused
ALIGNED(4) static const u8 sText_ChooseRequestedMonType[] = _("Choisis le type de POKéMON\nque tu souhaites dans l'échange.\n");
ALIGNED(4) static const u8 sText_WhichMonWillYouOffer[] = _("Quel POKéMON de ton équipe\nveux-tu proposer à l'échange ?\p");
ALIGNED(4) static const u8 sText_RegistrationCanceled[] = _("L'enregistrement a été annulé.\p");
ALIGNED(4) static const u8 sText_RegistraionCompleted[] = _("L'enregistrement est terminé.\p");
ALIGNED(4) static const u8 sText_TradeCanceled[] = _("L'échange a été annulé.\p");
ALIGNED(4) static const u8 sText_CancelRegistrationOfMon[] = _("Annuler l'enregistrement de ton\n{STR_VAR_1} N. {STR_VAR_2} ?");
ALIGNED(4) static const u8 sText_CancelRegistrationOfEgg[] = _("Annuler l'enregistrement\nde ton ŒUF ?");
ALIGNED(4) static const u8 sText_RegistrationCanceled2[] = _("L'enregistrement a été annulé.\p");
ALIGNED(4) static const u8 sText_TradeTrainersWillBeListed[] = _("Les DRESSEURS souhaitant échanger\nseront listés."); // unused
ALIGNED(4) static const u8 sText_ChooseTrainerToTradeWith2[] = _("Choisis le DRESSEUR avec qui tu\nveux échanger des POKéMON."); // unused
ALIGNED(4) static const u8 sText_AskTrainerToMakeTrade[] = _("Veux-tu demander à {STR_VAR_1}\nde faire un échange ?");
ALIGNED(4) static const u8 sText_AwaitingResponseFromTrainer2[] = _("En attente d'une réponse\ndu DRESSEUR…"); // unused
ALIGNED(4) static const u8 sText_NotRegisteredAMonForTrade[] = _("Tu n'as pas inscrit de POKéMON\npour l'échange.\p"); // unused
ALIGNED(4) static const u8 sText_DontHaveTypeTrainerWants[] = _("Tu n'as pas de POKéMON de type {STR_VAR_2}\nque {STR_VAR_1} veut.\p");
ALIGNED(4) static const u8 sText_DontHaveEggTrainerWants[] = _("Tu n'as pas d'ŒUF que\n{STR_VAR_1} veut.\p");
ALIGNED(4) static const u8 sText_PlayerCantTradeForYourMon[] = _("{STR_VAR_1} ne peut pas échanger\nton POKéMON pour l'instant.\p");
ALIGNED(4) static const u8 sText_CantTradeForPartnersMon[] = _("Tu ne peux pas échanger le POKéMON\nde {STR_VAR_1} pour l'instant.\p");

// Unused
static const u8 *const sCantTradeMonTexts[] = {
    sText_PlayerCantTradeForYourMon,
    sText_CantTradeForPartnersMon
};

ALIGNED(4) static const u8 sText_TradeOfferRejected[] = _("Ton offre d'échange a été refusée.\p");
ALIGNED(4) static const u8 sText_EggTrade[] = _("ÉCHANGE D'ŒUFS");
ALIGNED(4) static const u8 sText_ChooseJoinCancel[] = _("{DPAD_UPDOWN}CHOISIR  {A_BUTTON}REJOINDRE  {B_BUTTON}ANNULER");
ALIGNED(4) static const u8 sText_ChooseTrainer[] = _("Choisis un DRESSEUR, s'il te plaît.");
ALIGNED(4) static const u8 sText_ChooseTrainerSingleBattle[] = _("Choisis un DRESSEUR pour\nun COMBAT SIMPLE.");
ALIGNED(4) static const u8 sText_ChooseTrainerDoubleBattle[] = _("Choisis un DRESSEUR pour\nun COMBAT DOUBLE.");
ALIGNED(4) static const u8 sText_ChooseLeaderMultiBattle[] = _("Choisis le MENEUR pour\nun COMBAT MULTI.");
ALIGNED(4) static const u8 sText_ChooseTrainerToTradeWith[] = _("Choisis le DRESSEUR avec\nqui échanger.");
ALIGNED(4) static const u8 sText_ChooseTrainerToShareWonderCards[] = _("Choisis le DRESSEUR qui partage\ndes CARTES MERVEILLE.");
ALIGNED(4) static const u8 sText_ChooseTrainerToShareWonderNews[] = _("Choisis le DRESSEUR qui partage\ndes ACTUALITÉS MERVEILLE.");
ALIGNED(4) static const u8 sText_ChooseLeaderPokemonJump[] = _("Saute avec des mini POKéMON !\nChoisis le CHEF D'ÉQUIPE.");
ALIGNED(4) static const u8 sText_ChooseLeaderBerryCrush[] = _("BROYEUR DE BAIES !\nChoisis le LEADER, s'il te plaît.");
ALIGNED(4) static const u8 sText_ChooseLeaderBerryPicking[] = _("RAMASSAGE DE BAIES DODRIO !\nChoisis le CHEF D'ÉQUIPE.");
ALIGNED(4) static const u8 sText_ChooseLeaderBerryBlender[] = _("MIXEUR A BAIES !\nChoisis le LEADER, s'il te plaît.");
ALIGNED(4) static const u8 sText_ChooseLeaderRecordCorner[] = _("COIN ENREGISTREMENT !\nChoisis le LEADER, s'il te plaît.");
ALIGNED(4) static const u8 sText_ChooseLeaderCoolContest[] = _("CONCOURS COOL !\nChoisis le MENEUR.");
ALIGNED(4) static const u8 sText_ChooseLeaderBeautyContest[] = _("CONCOURS DE BEAUTÉ !\nChoisis le LEADER, s'il te plaît.");
ALIGNED(4) static const u8 sText_ChooseLeaderCuteContest[] = _("CONCOURS MIMINE !\nChoisis le MENEUR.");
ALIGNED(4) static const u8 sText_ChooseLeaderSmartContest[] = _("CONCOURS INTELLIGENCE !\nChoisis le MENEUR.");
ALIGNED(4) static const u8 sText_ChooseLeaderToughContest[] = _("CONCOURS ROBUSTESSE !\nChoisis le MENEUR.");
ALIGNED(4) static const u8 sText_ChooseLeaderBattleTowerLv50[] = _("TOUR DE COMBAT NIVEAU NORMAL !\nChoisissez le LEADER.");
ALIGNED(4) static const u8 sText_ChooseLeaderBattleTowerOpenLv[] = _("TOUR DE COMBAT NIVEAU DIFFICILE !\nChoisissez le LEADER.");

static const u8 *const sChooseTrainerTexts[NUM_LINK_GROUP_TYPES] =
{
    [LINK_GROUP_SINGLE_BATTLE]     = sText_ChooseTrainerSingleBattle,
    [LINK_GROUP_DOUBLE_BATTLE]     = sText_ChooseTrainerDoubleBattle,
    [LINK_GROUP_MULTI_BATTLE]      = sText_ChooseLeaderMultiBattle,
    [LINK_GROUP_TRADE]             = sText_ChooseTrainerToTradeWith,
    [LINK_GROUP_POKEMON_JUMP]      = sText_ChooseLeaderPokemonJump,
    [LINK_GROUP_BERRY_CRUSH]       = sText_ChooseLeaderBerryCrush,
    [LINK_GROUP_BERRY_PICKING]     = sText_ChooseLeaderBerryPicking,
    [LINK_GROUP_WONDER_CARD]       = sText_ChooseTrainerToShareWonderCards,
    [LINK_GROUP_WONDER_NEWS]       = sText_ChooseTrainerToShareWonderNews,
    [LINK_GROUP_UNION_ROOM_RESUME] = NULL,
    [LINK_GROUP_UNION_ROOM_INIT]   = NULL,
    [LINK_GROUP_UNK_11]            = NULL,
    [LINK_GROUP_RECORD_CORNER]     = sText_ChooseLeaderRecordCorner,
    [LINK_GROUP_BERRY_BLENDER]     = sText_ChooseLeaderBerryBlender,
    [LINK_GROUP_UNK_14]            = NULL,
    [LINK_GROUP_COOL_CONTEST]      = sText_ChooseLeaderCoolContest,
    [LINK_GROUP_BEAUTY_CONTEST]    = sText_ChooseLeaderBeautyContest,
    [LINK_GROUP_CUTE_CONTEST]      = sText_ChooseLeaderCuteContest,
    [LINK_GROUP_SMART_CONTEST]     = sText_ChooseLeaderSmartContest,
    [LINK_GROUP_TOUGH_CONTEST]     = sText_ChooseLeaderToughContest,
    [LINK_GROUP_BATTLE_TOWER]      = sText_ChooseLeaderBattleTowerLv50,
    [LINK_GROUP_BATTLE_TOWER_OPEN] = sText_ChooseLeaderBattleTowerOpenLv
};

ALIGNED(4) static const u8 sText_SearchingForWirelessSystemWait[] = _("Recherche d'un SYSTÈME de\nCOMMUNICATION SANS FIL. Patientez...");
ALIGNED(4) static const u8 sText_MustHaveTwoMonsForDoubleBattle[] = _("Pour un COMBAT DOUBLE, tu dois avoir\nau moins deux POKéMON.\p"); // Unused
ALIGNED(4) static const u8 sText_AwaitingPlayersResponse[] = _("En attente de la réponse de {STR_VAR_1}…");
ALIGNED(4) static const u8 sText_PlayerHasBeenAskedToRegisterYouPleaseWait[] = _("{STR_VAR_1} a été chargé d'enregistrer ton\nmembre. Veuillez patienter.");
ALIGNED(4) static const u8 sText_AwaitingResponseFromWirelessSystem[] = _("En attente d'une réponse du\nSYSTÈME DE COMMUNICATION SANS FIL.");
ALIGNED(4) static const u8 sText_PleaseWaitForOtherTrainersToGather[] = _("Veuillez attendre que les autres DRESSEURS\nse rassemblent et se préparent."); // Unused
ALIGNED(4) static const u8 sText_NoCardsSharedRightNow[] = _("Aucune CARTE ne semble être\npartagée pour le moment.");
ALIGNED(4) static const u8 sText_NoNewsSharedRightNow[] = _("Aucune ACTUALITÉ ne semble être\npartagée pour le moment.");

static const u8 *const sNoWonderSharedTexts[] = {
    sText_NoCardsSharedRightNow,
    sText_NoNewsSharedRightNow
};

ALIGNED(4) static const u8 sText_Battle[] = _("COMBAT");
ALIGNED(4) static const u8 sText_Chat2[] = _("BAVARDE");
ALIGNED(4) static const u8 sText_Greetings[] = _("POLITESSES");
ALIGNED(4) static const u8 sText_Exit[] = _("QUITTER");
ALIGNED(4) static const u8 sText_Exit2[] = _("QUITTER");
ALIGNED(4) static const u8 sText_Info[] = _("INFOS");
ALIGNED(4) static const u8 sText_NameWantedOfferLv[] = _("NOM{CLEAR_TO 60}RECHERCHÉ{CLEAR_TO 110}OFFRE{CLEAR_TO 198}NIV.");
ALIGNED(4) static const u8 sText_SingleBattle[] = _("COMBAT SOLO");
ALIGNED(4) static const u8 sText_DoubleBattle[] = _("COMBAT DUO");
ALIGNED(4) static const u8 sText_MultiBattle[] = _("COMBAT MULTI");
ALIGNED(4) static const u8 sText_PokemonTrades[] = _("ÉCHANGES POKéMON");
ALIGNED(4) static const u8 sText_Chat[] = _("BAVARDE");
ALIGNED(4) static const u8 sText_Cards[] = _("CARTES");
ALIGNED(4) static const u8 sText_WonderCards[] = _("CARTES MIRACLE");
ALIGNED(4) static const u8 sText_WonderNews[] = _("ACTUALITÉ MERVEILLE");
ALIGNED(4) static const u8 sText_PokemonJump[] = _("POKéMON JUMP");
ALIGNED(4) static const u8 sText_BerryCrush[] = _("ÉCRASE-BAIES");
ALIGNED(4) static const u8 sText_BerryPicking[] = _("CUEILLETTE DE BAIES");
ALIGNED(4) static const u8 sText_Search[] = _("CHERCHER");
ALIGNED(4) static const u8 sText_BerryBlender[] = _("MIXEUR DE BAIES");
ALIGNED(4) static const u8 sText_RecordCorner[] = _("COIN RECORD");
ALIGNED(4) static const u8 sText_CoolContest[] = _("CONCOURS COOL");
ALIGNED(4) static const u8 sText_BeautyContest[] = _("CONCOURS DE BEAUTÉ");
ALIGNED(4) static const u8 sText_CuteContest[] = _("CONCOURS MIMINE");
ALIGNED(4) static const u8 sText_SmartContest[] = _("CONCOURS INTELLIGENCE");
ALIGNED(4) static const u8 sText_ToughContest[] = _("CONCOURS ROBUSTESSE");
ALIGNED(4) static const u8 sText_BattleTowerLv50[] = _("TOUR DE COMBAT NIVEAU NORMAL");
ALIGNED(4) static const u8 sText_BattleTowerOpenLv[] = _("TOUR DE COMBAT NIVEAU DIFFICILE");
ALIGNED(4) static const u8 sText_ItsNormalCard[] = _("C'est une CARTE NORMALE.");
ALIGNED(4) static const u8 sText_ItsBronzeCard[] = _("C'est une CARTE BRONZE !");
ALIGNED(4) static const u8 sText_ItsCopperCard[] = _("C'est une CARTE CUIVRE !");
ALIGNED(4) static const u8 sText_ItsSilverCard[] = _("C'est une CARTE ARGENT !");
ALIGNED(4) static const u8 sText_ItsGoldCard[] = _("C'est une CARTE OR !");

static const u8 *const sCardColorTexts[] = {
    sText_ItsNormalCard,
    sText_ItsBronzeCard,
    sText_ItsCopperCard,
    sText_ItsSilverCard,
    sText_ItsGoldCard
};

ALIGNED(4) static const u8 sText_TrainerCardInfoPage1[] = _("C'est la CARTE DRESSEUR\nde {DYNAMIC 0} {DYNAMIC\l1}… {DYNAMIC 2}\pPOKéDEX : {DYNAMIC\n3} TEMPS :\p{DYNAMIC 4}:{DYNAMIC 5}");
ALIGNED(4) static const u8 sText_TrainerCardInfoPage2[] = _("COMBATS : VICTOIRES : {DYNAMIC 0}  DÉFAITES : {DYNAMIC 2}\nÉCHANGES : {DYNAMIC 3}\p« {DYNAMIC 4} {DYNAMIC 5}\n{DYNAMIC 6} {DYNAMIC 7} »\p");
ALIGNED(4) static const u8 sText_GladToMeetYouMale[] = _("{DYNAMIC 1} : Ravi de t'avoir rencontré !{PAUSE 60}");
ALIGNED(4) static const u8 sText_GladToMeetYouFemale[] = _("{DYNAMIC 1} : Enchanté de te rencontrer !{PAUSE 60}");

static const u8 *const sGladToMeetYouTexts[GENDER_COUNT] = {
    sText_GladToMeetYouMale,
    sText_GladToMeetYouFemale
};

ALIGNED(4) static const u8 sText_FinishedCheckingPlayersTrainerCard[] = _("Vérification de la CARTE de DRESSEUR\nde {DYNAMIC 1} terminée.{PAUSE 60}");

static const u8 *const sLinkGroupActivityNameTexts[] = {
    [ACTIVITY_NONE]              = sText_EmptyString,
    [ACTIVITY_BATTLE_SINGLE]     = sText_SingleBattle,
    [ACTIVITY_BATTLE_DOUBLE]     = sText_DoubleBattle,
    [ACTIVITY_BATTLE_MULTI]      = sText_MultiBattle,
    [ACTIVITY_TRADE]             = sText_PokemonTrades,
    [ACTIVITY_CHAT]              = sText_Chat,
    [ACTIVITY_WONDER_CARD_DUP]   = sText_WonderCards,
    [ACTIVITY_WONDER_NEWS_DUP]   = sText_WonderNews,
    [ACTIVITY_CARD]              = sText_Cards,
    [ACTIVITY_POKEMON_JUMP]      = sText_PokemonJump,
    [ACTIVITY_BERRY_CRUSH]       = sText_BerryCrush,
    [ACTIVITY_BERRY_PICK]        = sText_BerryPicking,
    [ACTIVITY_SEARCH]            = sText_Search,
    [ACTIVITY_SPIN_TRADE]        = sText_EmptyString,
    [ACTIVITY_BATTLE_TOWER_OPEN] = sText_BattleTowerOpenLv,
    [ACTIVITY_RECORD_CORNER]     = sText_RecordCorner,
    [ACTIVITY_BERRY_BLENDER]     = sText_BerryBlender,
    [ACTIVITY_ACCEPT]            = sText_EmptyString,
    [ACTIVITY_DECLINE]           = sText_EmptyString,
    [ACTIVITY_NPCTALK]           = sText_EmptyString,
    [ACTIVITY_PLYRTALK]          = sText_EmptyString,
    [ACTIVITY_WONDER_CARD]       = sText_WonderCards,
    [ACTIVITY_WONDER_NEWS]       = sText_WonderNews,
    [ACTIVITY_CONTEST_COOL]      = sText_CoolContest,
    [ACTIVITY_CONTEST_BEAUTY]    = sText_BeautyContest,
    [ACTIVITY_CONTEST_CUTE]      = sText_CuteContest,
    [ACTIVITY_CONTEST_SMART]     = sText_SmartContest,
    [ACTIVITY_CONTEST_TOUGH]     = sText_ToughContest,
    [ACTIVITY_BATTLE_TOWER]      = sText_BattleTowerLv50
};

static const struct WindowTemplate sWindowTemplate_BButtonCancel = {
    .bg = 0,
    .tilemapLeft = 0,
    .tilemapTop = 0,
    .width = 30,
    .height = 2,
    .paletteNum = 15,
    .baseBlock = 0x0008
};

// Minimum and maximum number of players for a link group
// A minimum of 0 means the min and max are equal
#define LINK_GROUP_CAPACITY(min, max)(((min) << 12) | ((max) << 8))
#define GROUP_MAX(capacity)(capacity & 0x0F)
#define GROUP_MIN(capacity)(capacity >> 4)
#define GROUP_MIN2(capacity)(capacity & 0xF0) // Unnecessary to have both, but needed to match

static const u32 sLinkGroupToActivityAndCapacity[NUM_LINK_GROUP_TYPES] = {
    [LINK_GROUP_SINGLE_BATTLE]     = ACTIVITY_BATTLE_SINGLE     | LINK_GROUP_CAPACITY(0, 2),
    [LINK_GROUP_DOUBLE_BATTLE]     = ACTIVITY_BATTLE_DOUBLE     | LINK_GROUP_CAPACITY(0, 2),
    [LINK_GROUP_MULTI_BATTLE]      = ACTIVITY_BATTLE_MULTI      | LINK_GROUP_CAPACITY(0, 4),
    [LINK_GROUP_TRADE]             = ACTIVITY_TRADE             | LINK_GROUP_CAPACITY(0, 2),
    [LINK_GROUP_POKEMON_JUMP]      = ACTIVITY_POKEMON_JUMP      | LINK_GROUP_CAPACITY(2, 5),
    [LINK_GROUP_BERRY_CRUSH]       = ACTIVITY_BERRY_CRUSH       | LINK_GROUP_CAPACITY(2, 5),
    [LINK_GROUP_BERRY_PICKING]     = ACTIVITY_BERRY_PICK        | LINK_GROUP_CAPACITY(3, 5),
    [LINK_GROUP_WONDER_CARD]       = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_WONDER_NEWS]       = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_UNION_ROOM_RESUME] = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_UNION_ROOM_INIT]   = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_UNK_11]            = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_RECORD_CORNER]     = ACTIVITY_RECORD_CORNER     | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_BERRY_BLENDER]     = ACTIVITY_BERRY_BLENDER     | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_UNK_14]            = ACTIVITY_NONE              | LINK_GROUP_CAPACITY(0, 0),
    [LINK_GROUP_COOL_CONTEST]      = ACTIVITY_CONTEST_COOL      | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_BEAUTY_CONTEST]    = ACTIVITY_CONTEST_BEAUTY    | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_CUTE_CONTEST]      = ACTIVITY_CONTEST_CUTE      | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_SMART_CONTEST]     = ACTIVITY_CONTEST_SMART     | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_TOUGH_CONTEST]     = ACTIVITY_CONTEST_TOUGH     | LINK_GROUP_CAPACITY(2, 4),
    [LINK_GROUP_BATTLE_TOWER]      = ACTIVITY_BATTLE_TOWER      | LINK_GROUP_CAPACITY(0, 2),
    [LINK_GROUP_BATTLE_TOWER_OPEN] = ACTIVITY_BATTLE_TOWER_OPEN | LINK_GROUP_CAPACITY(0, 2)
};

static const struct WindowTemplate sWindowTemplate_PlayerList = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 3,
    .width = 13,
    .height = 8,
    .paletteNum = 15,
    .baseBlock = 0x0044
};

static const struct WindowTemplate sWindowTemplate_5PlayerList = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 3,
    .width = 13,
    .height = 10,
    .paletteNum = 15,
    .baseBlock = 0x0044
};

static const struct WindowTemplate sWindowTemplate_NumPlayerMode = {
    .bg = 0,
    .tilemapLeft = 16,
    .tilemapTop = 3,
    .width = 7,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 0x00c6
};

static const struct ListMenuItem sPossibleGroupMembersListMenuItems[] = {
    { sText_EmptyString, 0 },
    { sText_EmptyString, 1 },
    { sText_EmptyString, 2 },
    { sText_EmptyString, 3 },
    { sText_EmptyString, 4 }
};

static const struct ListMenuTemplate sListMenuTemplate_PossibleGroupMembers = {
    .items = sPossibleGroupMembersListMenuItems,
    .moveCursorFunc = NULL,
    .itemPrintFunc = ItemPrintFunc_PossibleGroupMembers,
    .totalItems = ARRAY_COUNT(sPossibleGroupMembersListMenuItems),
    .maxShowed = 5,
    .windowId = 0,
    .header_X = 0,
    .item_X = 0,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_INVISIBLE
};

static const struct WindowTemplate sWindowTemplate_GroupList = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 3,
    .width = 17,
    .height = 10,
    .paletteNum = 15,
    .baseBlock = 0x0044
};

static const struct WindowTemplate sWindowTemplate_PlayerNameAndId = {
    .bg = 0,
    .tilemapLeft = 20,
    .tilemapTop = 3,
    .width = 7,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 0x00ee
};

static const struct ListMenuItem sUnionRoomGroupsMenuItems[] = {
    { sText_EmptyString,  0 },
    { sText_EmptyString,  1 },
    { sText_EmptyString,  2 },
    { sText_EmptyString,  3 },
    { sText_EmptyString,  4 },
    { sText_EmptyString,  5 },
    { sText_EmptyString,  6 },
    { sText_EmptyString,  7 },
    { sText_EmptyString,  8 },
    { sText_EmptyString,  9 },
    { sText_EmptyString, 10 },
    { sText_EmptyString, 11 },
    { sText_EmptyString, 12 },
    { sText_EmptyString, 13 },
    { sText_EmptyString, 14 },
    { sText_EmptyString, 15 }
};

static const struct ListMenuTemplate sListMenuTemplate_UnionRoomGroups = {
    .items = sUnionRoomGroupsMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = ListMenuItemPrintFunc_UnionRoomGroups,
    .totalItems = ARRAY_COUNT(sUnionRoomGroupsMenuItems),
    .maxShowed = 5,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_MULTIPLE_SCROLL_DPAD,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW
};

static const struct WindowTemplate sWindowTemplate_InviteToActivity = {
    .bg = 0,
    .tilemapLeft = 20,
    .tilemapTop = 5,
    .width = 16,
    .height = 8,
    .paletteNum = 15,
    .baseBlock = 0x0001
};

static const struct ListMenuItem sInviteToActivityMenuItems[] = {
    { sText_Greetings, ACTIVITY_CARD | LINK_GROUP_CAPACITY(0, 2)},
    { sText_Battle,    ACTIVITY_BATTLE_SINGLE | IN_UNION_ROOM | LINK_GROUP_CAPACITY(0, 2)},
    { sText_Chat2,     ACTIVITY_CHAT | IN_UNION_ROOM | LINK_GROUP_CAPACITY(0, 2)},
    { sText_Exit,      ACTIVITY_NONE | IN_UNION_ROOM }
};

static const struct ListMenuTemplate sListMenuTemplate_InviteToActivity = {
    .items = sInviteToActivityMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = ARRAY_COUNT(sInviteToActivityMenuItems),
    .maxShowed = 4,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW
};

static const struct WindowTemplate sWindowTemplate_RegisterForTrade = {
    .bg = 0,
    .tilemapLeft = 18,
    .tilemapTop = 7,
    .width = 16,
    .height = 6,
    .paletteNum = 15,
    .baseBlock = 0x0001
};

static const struct ListMenuItem sRegisterForTradeListMenuItems[] = {
    { gText_Register, 1 },
    { sText_Info, 2 },
    { sText_Exit, 3 }
};

static const struct ListMenuTemplate sListMenuTemplate_RegisterForTrade = {
    .items = sRegisterForTradeListMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = ARRAY_COUNT(sRegisterForTradeListMenuItems),
    .maxShowed = 3,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW
};

static const struct WindowTemplate sWindowTemplate_TradingBoardRequestType = {
    .bg = 0,
    .tilemapLeft = 20,
    .tilemapTop = 1,
    .width = 16,
    .height = 12,
    .paletteNum = 15,
    .baseBlock = 0x0001
};

static const struct ListMenuItem sTradingBoardTypes[NUMBER_OF_MON_TYPES] = {
    { gTypeNames[TYPE_NORMAL],   TYPE_NORMAL         },
    { gTypeNames[TYPE_FIRE],     TYPE_FIRE           },
    { gTypeNames[TYPE_WATER],    TYPE_WATER          },
    { gTypeNames[TYPE_ELECTRIC], TYPE_ELECTRIC       },
    { gTypeNames[TYPE_GRASS],    TYPE_GRASS          },
    { gTypeNames[TYPE_ICE],      TYPE_ICE            },
    { gTypeNames[TYPE_GROUND],   TYPE_GROUND         },
    { gTypeNames[TYPE_ROCK],     TYPE_ROCK           },
    { gTypeNames[TYPE_FLYING],   TYPE_FLYING         },
    { gTypeNames[TYPE_PSYCHIC],  TYPE_PSYCHIC        },
    { gTypeNames[TYPE_FIGHTING], TYPE_FIGHTING       },
    { gTypeNames[TYPE_POISON],   TYPE_POISON         },
    { gTypeNames[TYPE_BUG],      TYPE_BUG            },
    { gTypeNames[TYPE_GHOST],    TYPE_GHOST          },
    { gTypeNames[TYPE_DRAGON],   TYPE_DRAGON         },
    { gTypeNames[TYPE_STEEL],    TYPE_STEEL          },
    { gTypeNames[TYPE_DARK],     TYPE_DARK           },
    { gTypeNames[TYPE_FAIRY],    TYPE_FAIRY          },
    { sText_Exit,                NUMBER_OF_MON_TYPES }
};

static const struct ListMenuTemplate sMenuTemplate_TradingBoardRequestType = {
    .items = sTradingBoardTypes,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = NULL,
    .totalItems = ARRAY_COUNT(sTradingBoardTypes),
    .maxShowed = 6,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW
};

static const struct WindowTemplate sWindowTemplate_TradingBoardHeader = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = 28,
    .height = 2,
    .paletteNum = 13,
    .baseBlock = 0x0001
};

static const struct WindowTemplate sWindowTemplate_TradingBoardMain = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 5,
    .width = 28,
    .height = 12,
    .paletteNum = 13,
    .baseBlock = 0x0039
};

static const struct ListMenuItem sTradeBoardListMenuItems[] = {
    { sText_EmptyString, LIST_HEADER },
    { sText_EmptyString,  0 },
    { sText_EmptyString,  1 },
    { sText_EmptyString,  2 },
    { sText_EmptyString,  3 },
    { sText_EmptyString,  4 },
    { sText_EmptyString,  5 },
    { sText_EmptyString,  6 },
    { sText_EmptyString,  7 },
    { sText_Exit2,  8 }
};

static const struct ListMenuTemplate sTradeBoardListMenuTemplate = {
    .items = sTradeBoardListMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = TradeBoardListMenuItemPrintFunc,
    .totalItems = ARRAY_COUNT(sTradeBoardListMenuItems),
    .maxShowed = 6,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 14,
    .fillValue = 15,
    .cursorShadowPal = 13,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_NO_MULTIPLE_SCROLL,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW
};

// Unused
static const struct WindowTemplate sWindowTemplate_Unused = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 5,
    .width = 28,
    .height = 12,
    .paletteNum = 13,
    .baseBlock = 0x0039
};

static const struct ListMenuItem sEmptyListMenuItems[] = {
    { sText_EmptyString,  0 },
    { sText_EmptyString,  1 },
    { sText_EmptyString,  2 },
    { sText_EmptyString,  3 },
    { sText_EmptyString,  4 },
    { sText_EmptyString,  5 },
    { sText_EmptyString,  6 },
    { sText_EmptyString,  7 },
    { sText_EmptyString,  8 },
    { sText_EmptyString,  9 },
    { sText_EmptyString, 10 },
    { sText_EmptyString, 11 },
    { sText_EmptyString, 12 },
    { sText_EmptyString, 13 },
    { sText_EmptyString, 14 },
    { sText_EmptyString, 15 }
};

// Unused
static const struct ListMenuTemplate sEmptyListMenuTemplate = {
    .items = sEmptyListMenuItems,
    .moveCursorFunc = ListMenuDefaultCursorMoveFunc,
    .itemPrintFunc = ItemPrintFunc_EmptyList,
    .totalItems = ARRAY_COUNT(sEmptyListMenuItems),
    .maxShowed = 4,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = 0,
    .itemVerticalPadding = 0,
    .scrollMultiple = LIST_MULTIPLE_SCROLL_DPAD,
    .fontId = FONT_NORMAL,
    .cursorKind = CURSOR_BLACK_ARROW
};

static const struct RfuPlayerData sUnionRoomPlayer_DummyRfu = {0};

ALIGNED(4) static const u8 sAcceptedActivityIds_SingleBattle[]    = {ACTIVITY_BATTLE_SINGLE, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_DoubleBattle[]    = {ACTIVITY_BATTLE_DOUBLE, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_MultiBattle[]     = {ACTIVITY_BATTLE_MULTI, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_Trade[]           = {ACTIVITY_TRADE, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_PokemonJump[]     = {ACTIVITY_POKEMON_JUMP, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BerryCrush[]      = {ACTIVITY_BERRY_CRUSH, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BerryPicking[]    = {ACTIVITY_BERRY_PICK, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_WonderCard[]      = {ACTIVITY_WONDER_CARD, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_WonderNews[]      = {ACTIVITY_WONDER_NEWS, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_Resume[]          = {
    IN_UNION_ROOM | ACTIVITY_NONE,
    IN_UNION_ROOM | ACTIVITY_BATTLE_SINGLE,
    IN_UNION_ROOM | ACTIVITY_TRADE,
    IN_UNION_ROOM | ACTIVITY_CHAT,
    IN_UNION_ROOM | ACTIVITY_CARD,
    IN_UNION_ROOM | ACTIVITY_ACCEPT,
    IN_UNION_ROOM | ACTIVITY_DECLINE,
    IN_UNION_ROOM | ACTIVITY_NPCTALK,
    IN_UNION_ROOM | ACTIVITY_PLYRTALK,
    0xff
};
ALIGNED(4) static const u8 sAcceptedActivityIds_Init[]            = {ACTIVITY_SEARCH, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_Unk11[]           = {
    ACTIVITY_BATTLE_SINGLE,
    ACTIVITY_BATTLE_DOUBLE,
    ACTIVITY_BATTLE_MULTI,
    ACTIVITY_TRADE,
    ACTIVITY_POKEMON_JUMP,
    ACTIVITY_BERRY_CRUSH,
    ACTIVITY_BERRY_PICK,
    ACTIVITY_WONDER_CARD,
    ACTIVITY_WONDER_NEWS,
    ACTIVITY_SPIN_TRADE,
    0xff
};
ALIGNED(4) static const u8 sAcceptedActivityIds_RecordCorner[]    = {ACTIVITY_RECORD_CORNER, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BerryBlender[]    = {ACTIVITY_BERRY_BLENDER, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_CoolContest[]     = {ACTIVITY_CONTEST_COOL, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BeautyContest[]   = {ACTIVITY_CONTEST_BEAUTY, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_CuteContest[]     = {ACTIVITY_CONTEST_CUTE, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_SmartContest[]    = {ACTIVITY_CONTEST_SMART, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_ToughContest[]    = {ACTIVITY_CONTEST_TOUGH, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BattleTower[]     = {ACTIVITY_BATTLE_TOWER, 0xff};
ALIGNED(4) static const u8 sAcceptedActivityIds_BattleTowerOpen[] = {ACTIVITY_BATTLE_TOWER_OPEN, 0xff};

static const u8 *const sAcceptedActivityIds[NUM_LINK_GROUP_TYPES] = {
    [LINK_GROUP_SINGLE_BATTLE]     = sAcceptedActivityIds_SingleBattle,
    [LINK_GROUP_DOUBLE_BATTLE]     = sAcceptedActivityIds_DoubleBattle,
    [LINK_GROUP_MULTI_BATTLE]      = sAcceptedActivityIds_MultiBattle,
    [LINK_GROUP_TRADE]             = sAcceptedActivityIds_Trade,
    [LINK_GROUP_POKEMON_JUMP]      = sAcceptedActivityIds_PokemonJump,
    [LINK_GROUP_BERRY_CRUSH]       = sAcceptedActivityIds_BerryCrush,
    [LINK_GROUP_BERRY_PICKING]     = sAcceptedActivityIds_BerryPicking,
    [LINK_GROUP_WONDER_CARD]       = sAcceptedActivityIds_WonderCard,
    [LINK_GROUP_WONDER_NEWS]       = sAcceptedActivityIds_WonderNews,
    [LINK_GROUP_UNION_ROOM_RESUME] = sAcceptedActivityIds_Resume,
    [LINK_GROUP_UNION_ROOM_INIT]   = sAcceptedActivityIds_Init,
    [LINK_GROUP_UNK_11]            = sAcceptedActivityIds_Unk11,
    [LINK_GROUP_RECORD_CORNER]     = sAcceptedActivityIds_RecordCorner,
    [LINK_GROUP_BERRY_BLENDER]     = sAcceptedActivityIds_BerryBlender,
    [LINK_GROUP_UNK_14]            = NULL,
    [LINK_GROUP_COOL_CONTEST]      = sAcceptedActivityIds_CoolContest,
    [LINK_GROUP_BEAUTY_CONTEST]    = sAcceptedActivityIds_BeautyContest,
    [LINK_GROUP_CUTE_CONTEST]      = sAcceptedActivityIds_CuteContest,
    [LINK_GROUP_SMART_CONTEST]     = sAcceptedActivityIds_SmartContest,
    [LINK_GROUP_TOUGH_CONTEST]     = sAcceptedActivityIds_ToughContest,
    [LINK_GROUP_BATTLE_TOWER]      = sAcceptedActivityIds_BattleTower,
    [LINK_GROUP_BATTLE_TOWER_OPEN] = sAcceptedActivityIds_BattleTowerOpen
};

static const u8 sLinkGroupToURoomActivity[NUM_LINK_GROUP_TYPES + 2] =
{
    [LINK_GROUP_SINGLE_BATTLE]     = ACTIVITY_BATTLE_SINGLE,
    [LINK_GROUP_DOUBLE_BATTLE]     = ACTIVITY_BATTLE_DOUBLE,
    [LINK_GROUP_MULTI_BATTLE]      = ACTIVITY_BATTLE_MULTI,
    [LINK_GROUP_TRADE]             = ACTIVITY_TRADE,
    [LINK_GROUP_POKEMON_JUMP]      = ACTIVITY_POKEMON_JUMP,
    [LINK_GROUP_BERRY_CRUSH]       = ACTIVITY_BERRY_CRUSH,
    [LINK_GROUP_BERRY_PICKING]     = ACTIVITY_BERRY_PICK,
    [LINK_GROUP_WONDER_CARD]       = ACTIVITY_WONDER_CARD,
    [LINK_GROUP_WONDER_NEWS]       = ACTIVITY_WONDER_NEWS,
    [LINK_GROUP_UNION_ROOM_RESUME] = ACTIVITY_NONE,
    [LINK_GROUP_UNION_ROOM_INIT]   = ACTIVITY_NONE,
    [LINK_GROUP_UNK_11]            = ACTIVITY_NONE,
    [LINK_GROUP_RECORD_CORNER]     = ACTIVITY_RECORD_CORNER,
    [LINK_GROUP_BERRY_BLENDER]     = ACTIVITY_BERRY_BLENDER,
    [LINK_GROUP_UNK_14]            = ACTIVITY_NONE,
    [LINK_GROUP_COOL_CONTEST]      = ACTIVITY_CONTEST_COOL,
    [LINK_GROUP_BEAUTY_CONTEST]    = ACTIVITY_CONTEST_BEAUTY,
    [LINK_GROUP_CUTE_CONTEST]      = ACTIVITY_CONTEST_CUTE,
    [LINK_GROUP_SMART_CONTEST]     = ACTIVITY_CONTEST_SMART,
    [LINK_GROUP_TOUGH_CONTEST]     = ACTIVITY_CONTEST_TOUGH,
    [LINK_GROUP_BATTLE_TOWER]      = ACTIVITY_BATTLE_TOWER,
    [LINK_GROUP_BATTLE_TOWER_OPEN] = ACTIVITY_BATTLE_TOWER_OPEN
};
