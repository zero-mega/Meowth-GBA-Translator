.set LOCALID_STEVEN, 1

MeteorFalls_StevensCave_MapScripts::
	.byte 0

MeteorFalls_StevensCave_EventScript_Steven::
	lock
	goto_if_set FLAG_STEVEN_REMATCH, MeteorFalls_StevensCave_EventScript_StevenRematch
	goto_if_set FLAG_DEFEATED_RED, MeteorFalls_StevensCave_EventScript_Defeated
	waitse
	playse SE_PIN
	applymovement LOCALID_STEVEN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_STEVEN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_STEVEN, MeteorFalls_StevensCave_Text_StevenDefeat
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_RED
	setflag FLAG_SIDNEY_REMATCH
	setflag FLAG_PHOEBE_REMATCH
	setflag FLAG_GLACIA_REMATCH
	setflag FLAG_DRAKE_REMATCH
	setflag FLAG_WALLACE_REMATCH
	release
	end

MeteorFalls_StevensCave_EventScript_StevenRematch::
	waitse
	playse SE_PIN
	applymovement LOCALID_STEVEN, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_STEVEN, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst2, MSGBOX_DEFAULT
	setflag FLAG_SYS_SET_BATTLE_BGM
	setvar VAR_TEMP_F, MUS_HG_VS_CHAMPION
	trainerbattle_no_intro TRAINER_STEVEN2, MeteorFalls_StevensCave_Text_StevenDefeat2
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue2, MSGBOX_DEFAULT
	clearflag FLAG_STEVEN_REMATCH
	goto_if_unset FLAG_ARCEUS_EGG_GIVE MeteorFalls_StevensCave_EventScript_StevenArceusEvent
	release
	end

MeteorFalls_StevensCave_EventScript_Defeated::
	applymovement LOCALID_STEVEN, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MeteorFalls_StevensCave_Text_MyPredictionCameTrue, MSGBOX_DEFAULT
	release
	end

MeteorFalls_StevensCave_EventScript_StevenArceusEvent::
	msgbox MeteorFalls_StevensCave_Text_ArceusEvent1, MSGBOX_DEFAULT
	setflag FLAG_ARCEUS_EGG_GIVE
	playfanfare MUS_OBTAIN_ITEM
	message LavaridgeTown_Text_ReceivedTheEgg
	waitfanfare
	giveegg SPECIES_ARCEUS
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, MeteorFalls_StevensCave_EventScript_StevenArceusEventToParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, MeteorFalls_StevensCave_EventScript_StevenArceusEventToPC
	release
	end

MeteorFalls_StevensCave_EventScript_StevenArceusEventToParty::
	call Common_EventScript_GetGiftMonPartySlot
	msgbox MeteorFalls_StevensCave_Text_ArceusEvent2, MSGBOX_DEFAULT
	release
	end

MeteorFalls_StevensCave_EventScript_StevenArceusEventToPC::
	call Common_EventScript_TransferredToPC
	msgbox MeteorFalls_StevensCave_Text_ArceusEvent2, MSGBOX_DEFAULT
	release
	end

MeteorFalls_StevensCave_Text_ArceusEvent1:
	.string "Et… J'aimerais te donner quelque chose que\n"
	.string "j'ai trouvé en creusant par ici.\l"
	.string "C'est un oeuf étrange. Je le\p"
	.string "porte depuis de nombreuses semaines mais\n"
	.string "il n'éclot pas. Tu es un\p"
	.string "meilleur dresseur que moi, alors peut-être\n"
	.string "que tu pourras le faire éclore.$"

MeteorFalls_StevensCave_Text_ArceusEvent2:
	.string "Je me demande quel POKéMON pond\n"
	.string "ses oeufs entre les rochers et\p"
	.string "s'en va… Peut-être un POKéMON\p"
	.string "ancien ? Fufufu… qui sait…$"

MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst:
	.string "PROF.ORME : {PLAYER} ! Te voilà !\n"
	.string "J'avais besoin de te demander une faveur.\p"
	.string "Je mène de nouvelles recherches\n"
	.string "sur les POKéMON en ce moment. Je me\p"
	.string "demandais si tu pouvais m'aider,\p"
	.string "{KUN}.\n"
	.string "Tu vois…\p"
	.string "J'écris un article que je veux\n"
	.string "présenter à une conférence.\p"
	.string "Mais il y a des choses que je\n"
	.string "ne comprends pas encore. Alors ! J'aimerais que tu élèves un POKéMON que j'ai récemment attrapé.{PLAYER}{KUN}$"

MeteorFalls_StevensCave_Text_ShouldKnowHowGoodIAmExpectWorst2:
	.string "PIERRE : Oh, salut, {PLAYER}{KUN}.\p"
	.string "Tu es de retour. ALIZA m'a dit que\n"
	.string "tu l'as battu et tout le CONSEIL\l"
	.string "DES 4 à nouveau. C'est incroyable !\p"
	.string "Je suis devenu plus fort aussi.\n"
	.string "Tu peux me donner un vrai défi\p"
	.string "encore ? D'accord, {PLAYER}{KUN}, c'est parti !$"

MeteorFalls_StevensCave_Text_StevenDefeat:
	.string "Toi…\n"
	.string "Je ne savais pas que tu deviendrais si fort…$"

MeteorFalls_StevensCave_Text_StevenDefeat2:
	.string "Toi…\n"
	.string "Personne ne peut te surpasser maintenant.$"

MeteorFalls_StevensCave_Text_MyPredictionCameTrue:
	.string "PIERRE : En y repensant, depuis que nos\n"
	.string "chemins se sont croisés pour la première fois\l"
	.string "dans la GROTTE GRANITE à ALGATIA, j'avais ce sentiment.\p"
	.string "Je pensais que tu finirais par devenir\n"
	.string "le CHAMPION.\p"
	.string "Mes prédictions se réalisent généralement.\p"
	.string "Et où iras-tu à partir d'ici ?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Fufufu, que dirais-tu de ceci ?\p"
	.string "Tu devrais commencer par défier à nouveau\n"
	.string "le CONSEIL DES 4. J'ai entendu qu'ils sont\l"
	.string "beaucoup plus forts. Qu'en penses-tu ?$"

MeteorFalls_StevensCave_Text_MyPredictionCameTrue2:
	.string "STEVEN: Come to think of it, ever since\n"
	.string "our paths first crossed in GRANITE\l"
	.string "CAVE in DEWFORD, I had this feeling.\p"
	.string "I thought that you would eventually\n"
	.string "become stronger than me.\p"
	.string "My predictions usually come true.\p"
	.string "And where will you go from here?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Fufufu, even I couldn't tell you that.$"
