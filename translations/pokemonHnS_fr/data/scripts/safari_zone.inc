SafariZone_EventScript_OutOfBallsMidBattle::
	setvar VAR_SAFARI_ZONE_STATE, 1
	special ExitSafariMode
	goto_if_set FLAG_IN_KANTO_SAFARI_ZONE, SafariZone_EventScript_ExitKanto
	setwarp MAP_SAFARI_ZONE_GATE_SAFARI_ZONE_ENTRANCE, 9, 3
	end

SafariZone_EventScript_Exit::
	setvar VAR_SAFARI_ZONE_STATE, 1
	special ExitSafariMode
	goto_if_set FLAG_IN_KANTO_SAFARI_ZONE, SafariZone_EventScript_ExitKanto
	warp MAP_SAFARI_ZONE_GATE_SAFARI_ZONE_ENTRANCE, 9, 3
	waitstate
	end

SafariZone_EventScript_ExitKanto::
	clearflag FLAG_IN_KANTO_SAFARI_ZONE
	warp MAP_FUCHSIA_CITY_SAFARI_ZONE_ENTRANCE, 5, 6
	waitstate
	end

SafariZone_EventScript_RetirePrompt::
	lockall
	msgbox SafariZone_Text_WouldYouLikeToExit, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SafariZone_EventScript_Retire
	releaseall
	end

SafariZone_EventScript_Retire::
	goto SafariZone_EventScript_Exit

SafariZone_EventScript_TimesUp::
	lockall
	playse SE_DING_DONG
	message SafariZone_Text_TimesUp
	waitmessage
	waitbuttonpress
	releaseall
	goto SafariZone_EventScript_Exit

SafariZone_EventScript_OutOfBalls::
	lockall
	playse SE_DING_DONG
	message SafariZone_Text_OutOfBalls
	waitmessage
	waitbuttonpress
	releaseall
	goto SafariZone_EventScript_Exit

EventScript_PokeBlockFeeder::
	lockall
	special GetPokeblockFeederInFront
	goto_if_ne VAR_RESULT, 0xFFFF, SafariZone_EventScript_PokeblockPresent
	msgbox SafariZone_Text_PlacePokeblockOnFeeder, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SafariZone_EventScript_ChoosePokeblock
	releaseall
	end

SafariZone_EventScript_ChoosePokeblock::
	fadescreen FADE_TO_BLACK
	special OpenPokeblockCaseOnFeeder
	waitstate
	goto_if_ne VAR_RESULT, 0xFFFF, SafariZone_EventScript_PokeblockPlaced
	releaseall
	end

SafariZone_EventScript_PokeblockPlaced::
	message SafariZone_Text_PokeblockWasPlaced
	waitmessage
	waitbuttonpress
	releaseall
	end

SafariZone_EventScript_PokeblockPresent::
	message SafariZone_Text_PokeblockStillHere
	waitmessage
	waitbuttonpress
	releaseall
	end

SafariZone_Text_WouldYouLikeToExit:
	.string "Veux-tu quitter la\n"
	.string "ZONE SAFARI maintenant ?$"

SafariZone_Text_TimesUp:
	.string "Ding-dong ! Le temps est écoulé !\n"
	.string "Ta partie SAFARI est terminée.$"

SafariZone_Text_OutOfBalls:
	.string "Tu n'as plus de SAFARI BALLS.\n"
	.string "Ton PARC SAFARI est terminé.$"

SafariZone_Text_PlacePokeblockOnFeeder:
	.string "Veux-tu placer un {POKEBLOCK}\n"
	.string "sur le DISTRIBUTEUR {POKEBLOCK} ?$"

SafariZone_Text_PokeblockStillHere:
	.string "Le {STR_VAR_1} que tu as laissé\n"
	.string "est toujours là.$"

SafariZone_Text_PokeblockWasPlaced:
	.string "Le {STR_VAR_1} a été placé\n"
	.string "sur le DISTRIBUTEUR {POKEBLOCK}.$"

Route121_SafariZoneGate_SafariZoneEntrance_Text_WelcomeToSafariZone:
	.string "Bienvenue à la\p"
	.string "ZONE SAFARI !\n"
	.string "Ici, tu pourras voir\p"
	.string "de nombreux types de\n"
	.string "POKéMON rarement\p"
	.string "vus à JOHTO.\n"
	.string "Et tu les verras dans\p"
	.string "leur habitat naturel !\n"
	.string "Profite de\p"
	.string "ton séjour !$"

Route121_SafariZoneGate_SafariZoneEntrance_Text_WelcomeFirstTime:
	.string "Bienvenue au PARC SAFARI !\n"
	.string "C'est ta première visite ?$"

Route121_SafariZoneGate_SafariZoneEntrance_Text_ComeInAndEnjoy:
	.string "Entre et profite de la ZONE SAFARI !$"

Route121_SafariZoneGate_SafariZoneEntrance_Text_FirstTimeInfo:
	.string "Quand tu entres dans le PARC SAFARI,\n"
	.string "tu commences avec 30 SAFARI BALLS\l"
	.string "pour attraper des POKéMON. La partie\p"
	.string "SAFARI est terminée quand tu n'as\n"
	.string "plus de SAFARI BALLS, ou quand\l"
	.string "tu as fait 500 pas. Entre\p"
	.string "et profite du PARC SAFARI !$"

Route121_SafariZoneGate_SafariZoneEntrance_Text_WouldYouLikeToPlay:
	.string "Bienvenue au PARC SAFARI !\p"
	.string "Tout ce que tu veux attraper pour seulement ¥500 !\n"
	.string "Veux-tu jouer une PARTIE SAFARI ?$"

Route121_SafariZoneGate_SafariZoneEntrance_Text_PlayAnotherTime:
	.string "OK.\n"
	.string "Reviens jouer une autre fois !$"

Route121_SafariZoneGate_SafariZoneEntrance_Text_NotEnoughMoney:
	.string "Tu n'as pas assez d'argent.\n"
	.string "Désolé.$"

Route121_SafariZoneGate_SafariZoneEntrance_Text_ThatWillBe500Please:
	.string "Ça fera 500¥, s'il te plaît.$"

Route121_SafariZoneGate_SafariZoneEntrance_Text_HereAreYourSafariBalls:
	.string "Voici tes SAFARI BALLS.$"

Route121_SafariZoneGate_SafariZoneEntrance_Text_Received30SafariBalls:
	.string "{PLAYER} a reçu 30 SAFARI BALLS.$"

Route121_SafariZoneGate_SafariZoneEntrance_Text_PleaseEnjoyYourself:
	.string "On te préviendra quand ta\n"
	.string "partie sera terminée. D'ici\p"
	.string "là, amuse-toi bien !\n"
	.string "Bonne excursion sauvage !$"

Route121_SafariZoneGate_SafariZoneEntrance_Text_PCIsFull:
	.string "Excuse-moi !\n"
	.string "Ton BOÎTE PC est pleine.$"

Route121_SafariZoneGate_SafariZoneEntrance_Text_YouNeedPokeblockCase:
	.string "Excusez-moi ! Il semble que vous\n"
	.string "n'ayez pas de BOÎTE À {POKEBLOCK}S.\p"
	.string "Votre partie SAFARI sera bien plus\n"
	.string "fructueuse si vous utilisez des {POKEBLOCK}S.\p"
	.string "Revenez avec une BOÎTE À {POKEBLOCK}S.\p"
	.string "Vous pouvez en obtenir une\n"
	.string "au PARC SAFARI de JOHTO.$"

SafariZone_South_Text_StillHaveTimeExit:
	.string "Il te reste du temps. Veux-tu\n"
	.string "quitter la ZONE SAFARI maintenant ?$"

SafariZone_South_Text_EnjoyTheRestOfYourAdventure:
	.string "Profitez du reste de votre\n"
	.string "aventure sauvage !$"

SafariZone_South_Text_ExitEarlyThankYouForPlaying:
	.string "OK.\p"
	.string "Je reprends tes SAFARI BALLS\n"
	.string "restantes.\p"
	.string "Merci d'avoir joué.\n"
	.string "À bientôt !$"

SafariZone_South_Text_GoodLuck:
	.string "Bonne chance !\p"
	.string "Si tu as besoin de quoi que ce soit, n'hésite pas\n"
	.string "à me le dire !$"

SafariZone_South_Text_Boy:
	.string "Tu savais ?\p"
	.string "Si tu mets un {POKEBLOCK} dans cette case,\n"
	.string "des POKéMON s'attroupent.$"

SafariZone_South_Text_Man:
	.string "Je veux continuer à aller plus loin, mais j'ai\n"
	.string "oublié d'apporter un VÉLO.\p"
	.string "Quelque chose me dit que des POKéMON rares\n"
	.string "vivent dans les zones éloignées.$"

SafariZone_Southwest_Text_Woman:
	.string "Parfois, quand je lance un {POKEBLOCK}\n"
	.string "sur un POKéMON, il l'ignore.\p"
	.string "Les POKéMON ont-ils des goûts\n"
	.string "et des dégoûts pour ce qu'ils mangent ?$"

SafariZone_Northwest_Text_Man:
	.string "Halète… Halète…\n"
	.string "J'ai réussi à venir jusqu'ici… mais…\p"
	.string "Je suis épuisé… Je n'ai pas l'énergie pour\n"
	.string "attraper des POKéMON…$"

SafariZone_North_Text_Fisherman:
	.string "Je suis en mission pour trouver des POKéMON\n"
	.string "EAU qu'on ne voit pas à HOENN.\p"
	.string "Tu sais où se trouve le lac ?$"

SafariZone_North_Text_Man:
	.string "Je vais attraper plein de POKéMON rares\n"
	.string "ici et les échanger avec mes amis !$"

SafariZone_South_Text_Youngster:
	.string "J'ai mis un {POKEBLOCK} sur le DISTRIBUTEUR DE {POKEBLOCK}.\n"
	.string "Mais il semble avoir disparu.\p"
	.string "Je suppose que des POKéMON l'ont mangé\n"
	.string "sans que je m'en aperçoive.$"

Route121_SafariZoneGate_SafariZoneEntrance_Text_TrainerTip:
	.string "ASTUCE DRESSEUR DU PARC SAFARI !\p"
	.string "Lance des {POKEBLOCK}S aux POKéMON sauvages pour les\n"
	.string "rendre moins enclins à fuir.$"

SafariZone_Southwest_Text_RestHouseSign:
	.string "« Reposez vos pieds fatigués. »\n"
	.string "MAISON DE REPOS$"

SafariZone_RestHouse_Text_Youngster:
	.string "Je n'ai pas de {POKEBLOCK}S, mais j'ai attrapé\n"
	.string "beaucoup de POKéMON.\p"
	.string "Tu peux améliorer tes chances de capture\n"
	.string "en t'approchant d'eux\l"
	.string "avant de lancer une SAFARI BALL.$"

SafariZone_RestHouse_Text_PsychicM:
	.string "Si tu utilises des {POKEBLOCK}S, les POKéMON sauvages ne\n"
	.string "s'enfuiront pas si vite.\p"
	.string "Ce n'est pas très utile de donner des {POKEBLOCK}S aux\n"
	.string "POKéMON qui ne fuient pas facilement.$"

SafariZone_RestHouse_Text_FatMan:
	.string "Si tu mets un {POKEBLOCK} sur la MANGEOIRE,\n"
	.string "les POKéMON sont attirés.\p"
	.string "Je pense que les POKéMON de même nature\n"
	.string "sont attirés par un certain {POKEBLOCK}.$"

SafariZone_South_Text_AreaOffLimits1:
	.string "Cette zone est encore en construction.\n"
	.string "Accès interdit, désolé !$"

SafariZone_Southeast_Text_ExpansionIsFinished:
	.string "Le projet d'expansion du PARC SAFARI\n"
	.string "est terminé maintenant.\p"
	.string "Nous espérons que tu apprécieras la nouvelle zone.$"

SafariZone_South_Text_AreaOffLimits2:
	.string "Cette zone est encore en construction.\n"
	.string "Accès interdit, désolé !$"

SafariZone_Southeast_Text_LittleGirl:
	.string "Waouh ! Youpi ! Je n'ai jamais vu\n"
	.string "ces POKéMON auparavant !$"

SafariZone_Southeast_Text_FatMan:
	.string "Les POKéMON de cette zone sont tous\n"
	.string "nouveaux pour moi.\p"
	.string "Et j'ai le droit d'attraper ces POKéMON\n"
	.string "rares ! Trop cool !$"

SafariZone_Southeast_Text_RichBoy:
	.string "Les POKéMON d'ici semblent venir\n"
	.string "d'un endroit autre que HOENN.$"

SafariZone_Northeast_Text_Boy:
	.string "Il ne me reste que quelques SAFARI BALLS.\p"
	.string "J'ai du mal à décider\n"
	.string "ce que je devrais attraper.$"

SafariZone_Northeast_Text_Woman:
	.string "J'ai entendu qu'on peut voir des PIKACHU ici.\n"
	.string "Où en trouver un ?$"

SafariZone_Northeast_Text_Girl:
	.string "Oh, mince ! Je n'arrive\n"
	.string "à rien attraper ! Je\p"
	.string "vais gaspiller le prix d'entrée\n"
	.string "si je n'attrape rien !$"
