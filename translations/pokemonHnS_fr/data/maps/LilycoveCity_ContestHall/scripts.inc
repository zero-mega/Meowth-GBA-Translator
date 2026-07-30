@ VAR_LAST_TALKED would have made all these direct references unnecessary
.set LOCALID_SMART_MC, 4
.set LOCALID_SMART_JUDGE, 5
.set LOCALID_SMART_CONTESTANT_1, 6
.set LOCALID_SMART_CONTESTANT_2, 7
.set LOCALID_SMART_CONTESTANT_3, 8
.set LOCALID_SMART_CONTESTANT_4, 9
.set LOCALID_SMART_AUDIENCE_4, 11
.set LOCALID_SMART_AUDIENCE_2, 12
.set LOCALID_BEAUTY_MC, 13
.set LOCALID_BEAUTY_JUDGE, 14
.set LOCALID_BEAUTY_CONTESTANT_1, 15
.set LOCALID_BEAUTY_CONTESTANT_2, 16
.set LOCALID_BEAUTY_CONTESTANT_3, 17
.set LOCALID_BEAUTY_CONTESTANT_4, 18
.set LOCALID_BEAUTY_AUDIENCE_1, 19
.set LOCALID_BEAUTY_AUDIENCE_3, 20
.set LOCALID_BEAUTY_AUDIENCE_2, 21
.set LOCALID_SMART_AUDIENCE_3, 22
.set LOCALID_CUTE_MC, 23
.set LOCALID_CUTE_JUDGE, 24
.set LOCALID_CUTE_CONTESTANT_1, 25
.set LOCALID_CUTE_CONTESTANT_2, 26
.set LOCALID_CUTE_CONTESTANT_3, 27
.set LOCALID_CUTE_CONTESTANT_4, 28
.set LOCALID_CUTE_AUDIENCE_1, 29
.set LOCALID_CUTE_AUDIENCE_3, 30
.set LOCALID_CUTE_AUDIENCE_2, 31

LilycoveCity_ContestHall_MapScripts::
	.byte 0

LilycoveCity_ContestHall_EventScript_Boy1::
	msgbox LilycoveCity_ContestHall_Text_TodayWonSmartnessContest, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Boy2::
	msgbox LilycoveCity_ContestHall_Text_EnteredBunchOfContests, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Girl::
	msgbox LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_Sailor::
	msgbox LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous, MSGBOX_NPC
	end

LilycoveCity_ContestHall_EventScript_SmartContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EnteredWrongContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_RaisedMonToBeSmart, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience1::
	msgbox LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_SmartContestAudience4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_StillLoveSmartnessContests, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_SMART_AUDIENCE_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_OverdidGrooming, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BEAUTY_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestMC::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_InTheMiddleOfContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_MC, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestJudge::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_JUDGE, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant1::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_MyAzurillWasDistracted, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_NeverWonBattleButContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_PetalDanceIsMarvel, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestant4::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_CONTESTANT_4, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience1::
	lockall
	applymovement LOCALID_CUTE_AUDIENCE_1, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_ContestHall_Text_MyChildIsInContest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_1, Common_Movement_FaceOriginalDirection
	waitmovement 0
	delay 25
	msgbox LilycoveCity_ContestHall_Text_ComeOnDear, MSGBOX_DEFAULT
	releaseall
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience2::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_2, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_CuteContestAudience3::
	lock
	faceplayer
	msgbox LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CUTE_AUDIENCE_3, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

LilycoveCity_ContestHall_EventScript_BeautyStageSign::
	msgbox LilycoveCity_ContestHall_Text_BeautyContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_CuteStageSign::
	msgbox LilycoveCity_ContestHall_Text_CuteContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_EventScript_SmartStageSign::
	msgbox LilycoveCity_ContestHall_Text_SmartContestStage, MSGBOX_SIGN
	end

LilycoveCity_ContestHall_Text_TodayWonSmartnessContest:
	.string "Ce POKéMON a gagné le CONCOURS DE BEAUTÉ\n"
	.string "ici avant.\p"
	.string "Eh bien, devine quoi ? Aujourd'hui, je l'ai fait\n"
	.string "gagner un CONCOURS D'INTELLIGENCE !\p"
	.string "Mes talents me font peur à moi-même…$"

LilycoveCity_ContestHall_Text_EnteredBunchOfContests:
	.string "J'ai participé à plein de\n"
	.string "CONCOURS, alors je comprends comment\p"
	.string "ça marche. Si tu es\n"
	.string "dans un CONCOURS SÉDUCTION, la\p"
	.string "séduction compte, mais pas seulement\n"
	.string "au premier tour !$"

LilycoveCity_ContestHall_Text_ManWhoWonEarlierHadPokeblocks:
	.string "Le jeune homme qui a gagné tout à l'heure avait\n"
	.string "plein de {POKEBLOCK}S différents.\p"
	.string "Peut-on gagner si on en a autant\n"
	.string "de ces trucs ?$"

LilycoveCity_ContestHall_Text_IsntThisPlaceHumongous:
	.string "Waouh, cet endroit est énorme !\p"
	.string "La tension dans l'air... Ce n'est pas\n"
	.string "comme une salle de CONCOURS de province.$"

LilycoveCity_ContestHall_Text_GiveItBestSmartAppeal:
	.string "MC : OK, POKéMON malins et leurs\n"
	.string "DRESSEURS, êtes-vous prêts ?!\p"
	.string "Donnez le meilleur de vous-mêmes !\n"
	.string "À vos démonstrations !$"

LilycoveCity_ContestHall_Text_AreYouEnjoyingThisContest:
	.string "JUGE : Vous appréciez ce CONCOURS ?\p"
	.string "Revenez avec trois amis, et\n"
	.string "vous pourrez tous participer à un CONCOURS !$"

LilycoveCity_ContestHall_Text_EnteredWrongContest:
	.string "Ayayayay…\n"
	.string "Je me suis inscrit au mauvais CONCOURS.\p"
	.string "J'ai inscrit ce POKéMON costaud au\n"
	.string "CONCOURS D'INTELLIGENCE…\p"
	.string "Allez, impressionne-les avec un\n"
	.string "CASSAGE bien malin.$"

LilycoveCity_ContestHall_Text_RaisedMonToBeSmart:
	.string "J'ai passé de nombreuses années, et toute ma\n"
	.string "sagesie, à élever ce POKéMON\l"
	.string "pour qu'il soit intelligent.\p"
	.string "Il ne sera pas facilement battu par les\n"
	.string "POKéMON d'un jeune louveteau.\p"
	.string "Ma chère épouse, tu vois ça ?$"

LilycoveCity_ContestHall_Text_IfMonPullsSmartMoveNext:
	.string "C'est ça !\p"
	.string "Si mon POKéMON fait un joli coup ensuite,\n"
	.string "l'excitation du public atteindra son paroxysme !$"

LilycoveCity_ContestHall_Text_DontAppreciateCuteLeechLife:
	.string "Oh, mon Dieu, non !\p"
	.string "Le VAMPIRISME de mon adorable Nosferapti\n"
	.string "est si mignon que je l'ai utilisé encore et encore !\p"
	.string "Mais ces gens méchants n'apprécient\n"
	.string "pas du tout !$"

LilycoveCity_ContestHall_Text_YoureBeautifulGrandpa:
	.string "Kiyaaah ! Tu es magnifique, Papy !$"

LilycoveCity_ContestHall_Text_AllSeemToUseDifferentMoves:
	.string "Même quand les DRESSEURS inscrivent le même\n"
	.string "type de POKéMON, ils semblent tous utiliser\l"
	.string "des attaques différentes pour les actions.\p"
	.string "C'est comme les gens qui ont\n"
	.string "des styles différents pour combattre.$"

LilycoveCity_ContestHall_Text_PokemonSmarterThanTrainers:
	.string "Je pense que les POKéMON ont l'air plus intelligents\n"
	.string "que leurs DRESSEURS. De loin.$"

LilycoveCity_ContestHall_Text_StillLoveSmartnessContests:
	.string "Au final, j'aime toujours\n"
	.string "les CONCOURS SAGACITÉ. Cette\p"
	.string "couleur verte intellectuelle… C'est\n"
	.string "si… Si… Cool.$"

LilycoveCity_ContestHall_Text_AreYouEnteringBeautyContest:
	.string "MC : Tu participes au CONCOURS\n"
	.string "de BEAUTÉ aussi ? Bonne chance !$"

LilycoveCity_ContestHall_Text_EveryPokemonPristineBeauty:
	.string "JUGE : Ah, chaque POKéMON ici est\n"
	.string "un modèle de beauté immaculée !\p"
	.string "Ah, j'ai presque oublié de les noter !$"

LilycoveCity_ContestHall_Text_EyesWillBeGluedToMyBeauty:
	.string "Un POKéMON aussi beau...\n"
	.string "Il n'y en a pas un autre comme lui.\p"
	.string "Tous les regards seront rivés\n"
	.string "sur ma beauté.$"

LilycoveCity_ContestHall_Text_OverdidGrooming:
	.string "Waaaah !\p"
	.string "J'ai brossé et toileté mon POKéMON\n"
	.string "soigneusement pour ce CONCOURS…\p"
	.string "Mais j'en ai trop fait…\n"
	.string "Le pelage de mon POKéMON est devenu tout hirsute…\p"
	.string "Que dois-je faire ?$"

LilycoveCity_ContestHall_Text_JudgeWontSeeAuroraBeam:
	.string "Ce RAYON AURORA est si éblouissant\n"
	.string "que le JUGE ne pourra pas\p"
	.string "le voir. Euh, attends… Ça\n"
	.string "n'aurait alors aucun sens !$"

LilycoveCity_ContestHall_Text_PokemonLooksLikeYoungerMe:
	.string "Ce joli POKéMON me ressemble\n"
	.string "quand j'étais plus jeune.\p"
	.string "Au moment où je l'ai dit, mon mari\n"
	.string "a recraché le café qu'il buvait.\p"
	.string "J'ai dit quelque chose de drôle ?$"

LilycoveCity_ContestHall_Text_WinBeautyContestMakesMeHappy:
	.string "Tu sais, si je gagne un CONCOURS\n"
	.string "DE BEAUTÉ, ça me rend\l"
	.string "heureuse. Plus que d'habitude, en tout cas.$"

LilycoveCity_ContestHall_Text_GanderAtAllThosePrettyPokemon:
	.string "Wahahahah !\p"
	.string "Regarde tous ces jolis\n"
	.string "POKéMON !\l"
	.string "J'adore ce genre de spectacle !$"

LilycoveCity_ContestHall_Text_CantWinOnBeautyAlone:
	.string "On ne peut pas toujours gagner\n"
	.string "sur la beauté seule. Il faut\p"
	.string "toiletter ton POKéMON pour qu'il\n"
	.string "soit brillant comme le mien.$"

LilycoveCity_ContestHall_Text_InTheMiddleOfContest:
	.string "MC : Oh-oh ! Bonjour !\n"
	.string "Nous sommes en plein CONCOURS\p"
	.string "! Inscris-toi à notre comptoir\n"
	.string "d'inscription et reviens, OK ?$"

LilycoveCity_ContestHall_Text_SuchCharmingCuteAppeals:
	.string "JUGE : Oh, quelles démonstrations charmantes\n"
	.string "et mignonnes !\p"
	.string "Oh, mon Dieu ! Quelle démonstration\n"
	.string "adorable de SURF D'EAU !$"

LilycoveCity_ContestHall_Text_MyAzurillWasDistracted:
	.string "Oh, non… Mon adorable AZURILL a été\n"
	.string "distrait par un autre POKéMON.$"

LilycoveCity_ContestHall_Text_NeverWonBattleButContest:
	.string "Mes POKéMON n'ont jamais gagné un combat,\n"
	.string "mais mets-les dans un CONCOURS et attention !$"

LilycoveCity_ContestHall_Text_PetalDanceIsMarvel:
	.string "La DANSE-FLEURS de mon POKéMON est un modèle\n"
	.string "d'élégance.\p"
	.string "Je ne laisserai personne perturber\n"
	.string "sa performance.$"

LilycoveCity_ContestHall_Text_MyMonAppealSoMuchCuter:
	.string "Les POKéMON de tout le monde sont très mignons.\p"
	.string "Cependant, si mon POKéMON faisait\n"
	.string "une démonstration mignonne…\p"
	.string "Je suis sûr qu'il serait bien plus\n"
	.string "mignon que les autres.$"

LilycoveCity_ContestHall_Text_MyChildIsInContest:
	.string "Mon enfant participe à ce CONCOURS.$"

LilycoveCity_ContestHall_Text_ComeOnDear:
	.string "Allez, chéri. Fonce !\n"
	.string "Ton POKéMON est le meilleur !$"

LilycoveCity_ContestHall_Text_ThatGirlThereIsCutest:
	.string "Je pense que cette fille là-bas\n"
	.string "est la plus mignonne du lot.\p"
	.string "Quoi ? Ils jugent les\n"
	.string "POKéMON sur leur apparence ?$"

LilycoveCity_ContestHall_Text_WantCuteMonOfMyOwn:
	.string "Ohh, voir tous ces POKéMON mignons\n"
	.string "me donne envie d'en avoir !\p"
	.string "Je vais aller en attraper !$"

LilycoveCity_ContestHall_Text_BeautyContestStage:
	.string "SCÈNE DE CONCOURS BEAUTÉ\n"
	.string "SOYEZ SÉDUITS PAR DE BEAUX POKéMON !$"

LilycoveCity_ContestHall_Text_CuteContestStage:
	.string "SCÈNE DU CONCOURS DE GRÂCE\n"
	.string "LAISSÉZ-VOUS CHARMEZ PAR DES POKéMON MIGNONS !$"

LilycoveCity_ContestHall_Text_SmartContestStage:
	.string "SCÈNE DE CONCOURS INTELLIGENCE\n"
	.string "SOYEZ IMPRESSIONNÉS PAR LES POKéMON INTELLIGENTS !$"

