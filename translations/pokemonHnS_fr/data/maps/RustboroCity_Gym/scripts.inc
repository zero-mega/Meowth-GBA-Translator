RustboroCity_Gym_MapScripts::
	.byte 0

RustboroCity_Gym_EventScript_Roxanne::
	trainerbattle_single TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxanneIntro, RustboroCity_Gym_Text_RoxanneDefeat, RustboroCity_Gym_EventScript_RoxanneDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, RustboroCity_Gym_EventScript_RoxanneRematch
	goto_if_unset FLAG_RECEIVED_TM_ROCK_TOMB, RustboroCity_Gym_EventScript_GiveRockTomb
	msgbox RustboroCity_Gym_Text_RoxannePostBattle, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_RoxanneDefeated::
	message RustboroCity_Gym_Text_ReceivedStoneBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox RustboroCity_Gym_Text_StoneBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_VIOLET_GYM
	setflag FLAG_BADGE01_GET
	setvar VAR_GARBAGEVAR, 1
	addvar VAR_GARBAGEVAR, 1
	setvar VAR_0x8008, 1
	call Common_EventScript_SetGymTrainers
	call_if_eq VAR_GARBAGEVAR, 6, Common_EventScript_ReadyPetalburgGymForBattle
	goto RustboroCity_Gym_EventScript_GiveRockTomb
	end

RustboroCity_Gym_EventScript_GiveRockTomb::
	giveitem ITEM_TM_ROCK_TOMB
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_ROCK_TOMB
	goto_if_set FLAG_FINITE_TMS, RustboroCity_Gym_EventScript_GiveRockTombFinite
	msgbox RustboroCity_Gym_Text_ExplainRockTombInfinite, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_GiveRockTombFinite::
	msgbox RustboroCity_Gym_Text_ExplainRockTomb MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_RoxanneRematch::
	trainerbattle_rematch_double TRAINER_ROXANNE_1, RustboroCity_Gym_Text_RoxannePreRematch, RustboroCity_Gym_Text_RoxanneRematchDefeat, RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons
	msgbox RustboroCity_Gym_Text_RoxannePostRematch, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Josh::
	trainerbattle_single TRAINER_JOSH, RustboroCity_Gym_Text_JoshIntro, RustboroCity_Gym_Text_JoshDefeat
	msgbox RustboroCity_Gym_Text_JoshPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Tommy::
	trainerbattle_single TRAINER_TOMMY, RustboroCity_Gym_Text_TommyIntro, RustboroCity_Gym_Text_TommyDefeat
	msgbox RustboroCity_Gym_Text_TommyPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_Marc::
	trainerbattle_single TRAINER_MARC, RustboroCity_Gym_Text_MarcIntro, RustboroCity_Gym_Text_MarcDefeat
	msgbox RustboroCity_Gym_Text_MarcPostBattle, MSGBOX_AUTOCLOSE
	end

RustboroCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_VIOLET_GYM, RustboroCity_Gym_EventScript_GymGuidePostVictory
	msgbox RustboroCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_GymGuidePostVictory::
	msgbox RustboroCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

RustboroCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, RustboroCity_Gym_EventScript_GymStatueCertified
	goto RustboroCity_Gym_EventScript_GymStatue
	end

RustboroCity_Gym_EventScript_GymStatueCertified::
	msgbox RustboroCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_GymStatue::
	msgbox RustboroCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

RustboroCity_Gym_EventScript_RegisterRoxanne::
	lockall
	pokenavcall RustboroCity_Gym_Text_RoxanneRegisterCall
	waitmessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox RustboroCity_Gym_Text_RegisteredRoxanne, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_ROXANNE_MATCH_CALL
	clearflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	releaseall
	end

RustboroCity_Gym_Text_GymGuideAdvice:
	.string "Yo, comment ça va ?\p"
	.string "Écoute, mon pote !\n"
	.string "Tu voudrais devenir CHAMPION ?\p"
	.string "Je ne suis pas DRESSEUR, moi, mais je peux\n"
	.string "sûrement te donner des conseils gagnants.\p"
	.string "C'est réglé, alors ! On vise le\n"
	.string "CHAMPIONNAT POKéMON ensemble !\p"
	.string "C'est ton travail de DRESSEUR de collecter\n"
	.string "les BADGES d'ARÈNE, non ?\p"
	.string "Mais les CHAMPIONS d'ARÈNE ne sont pas\p"
	.string "des minces !\n"
	.string "Et c'est là que j'interviens !\p"
	.string "Je suis là pour donner des conseils d'expert !\n"
	.string "ROXANNE, la CHAMPIONNE d'ARÈNE, utilise\p"
	.string "des POKéMON de type ROCHE.\n"
	.string "Le type ROCHE est très résistant, mais\l"
	.string "il ne supporte pas les capacités de type EAU\p"
	.string "et PLANTE.\n"
	.string "Viens me voir après, si tu bats\p"
	.string "la CHAMPIONNE d'ARÈNE. Allez, vas-y !$"

RustboroCity_Gym_Text_GymGuidePostVictory:
	.string "Waouh ! Quelle\n"
	.string "victoire\p"
	.string "à couper le souffle !\n"
	.string "Mes encouragements\p"
	.string "ont dû fonctionner !\n"
	.string "Génial !\p"
	.string "Vérifie ta\p"
	.string "CARTE DRESSEUR.\n"
	.string "Tu as gagné des\p"
	.string "Points de Combat !$"

RustboroCity_Gym_Text_JoshIntro:
	.string "Ne nous prenez pas à la légère, nous les\n"
	.string "DRESSEURS D'ARÈNE ! Je vais te montrer !$"

RustboroCity_Gym_Text_JoshDefeat:
	.string "Tu étais bien trop fort pour moi…$"

RustboroCity_Gym_Text_JoshPostBattle:
	.string "Tu n'as encore rien vu de la puissance\n"
	.string "terrifiante du type ROCHE !$"

RustboroCity_Gym_Text_TommyIntro:
	.string "Si tu ne peux pas me battre, tu n'auras\n"
	.string "aucune chance contre ROXANNE !$"

RustboroCity_Gym_Text_TommyDefeat:
	.string "Ouah ! Tu as du potentiel !$"

RustboroCity_Gym_Text_TommyPostBattle:
	.string "ROXANNE est plus forte que moi de\n"
	.string "plusieurs fois.\p"
	.string "Tu ferais mieux d'être sur tes gardes !$"

RustboroCity_Gym_Text_MarcIntro:
	.string "On est en pleine ville,\n"
	.string "et alors ?\p"
	.string "Mes POKéMON ROC ont besoin de place pour\n"
	.string "déchaîner leur rage !$"

RustboroCity_Gym_Text_MarcDefeat:
	.string "Oh, mon dieu !\n"
	.string "Notre challenger est un sacré client coriace !$"

RustboroCity_Gym_Text_MarcPostBattle:
	.string "Je dois rendre hommage à notre CHAMPION.\p"
	.string "Il lui a fallu du cran et du bon sens\n"
	.string "pour choisir le type ROCHE à son jeune âge.$"

RustboroCity_Gym_Text_RoxanneIntro:
	.string "Bonjour, je suis ROXANNE, la CHAMPIONNE\n"
	.string "de l'ARÈNE POKéMON de MÉROUVILLE. Je\p"
	.string "suis devenue CHAMPIONNE d'ARÈNE pour appliquer\n"
	.string "ce que j'ai appris à l'ÉCOLE\l"
	.string "DES DRESSEURS au combat. Pourrais-tu\p"
	.string "me montrer comment tu combats,\n"
	.string "et avec quels POKéMON ?$"

RustboroCity_Gym_Text_RoxanneDefeat:
	.string "Alors… J'ai perdu… Il\n"
	.string "semble que j'ai encore\p"
	.string "beaucoup à apprendre… Je\n"
	.string "comprends. Les règles de\p"
	.string "la LIGUE POKéMON stipulent\p"
	.string "que les DRESSEURS reçoivent\n"
	.string "ceci s'ils battent un\l"
	.string "CHAMPION d'ARÈNE. Accepte le\p"
	.string "BADGE ROCHE officiel de\n"
	.string "la LIGUE POKéMON.$"

RustboroCity_Gym_Text_ReceivedStoneBadge:
	.string "{PLAYER} a reçu le BADGE ROCHE\n"
	.string "de ROXANNE.$"

RustboroCity_Gym_Text_StoneBadgeInfoTakeThis:
	.string "Le BADGE ROCHE augmente la puissance\n"
	.string "d'ATTAQUE de tes POKéMON.\p"
	.string "Il leur permet aussi d'utiliser la CS COUPE\n"
	.string "en dehors des combats.\p"
	.string "Prends ceci aussi, s'il te plaît.$"

RustboroCity_Gym_Text_ExplainRockTomb:
	.string "Cette MACHINE\n"
	.string "TECHNIQUE, CT39,\p"
	.string "contient TOMBEROCHE.\n"
	.string "Elle inflige des dégâts\p"
	.string "en faisant tomber\n"
	.string "des rochers sur l'ennemi.\n"
	.string "N'oublie pas de l'enseigner !$"

RustboroCity_Gym_Text_ExplainRockTombInfinite:
	.string "Cette MACHINE TECHNIQUE, CT39,\n"
	.string "contient TOMBEROCHE.\p"
	.string "Elle inflige des dégâts\n"
	.string "en faisant tomber\p"
	.string "des rochers sur l'ennemi.\n"
	.string "C'est une capacité\n"
	.string "ROCHE utile !$"

RustboroCity_Gym_Text_RoxannePostBattle:
	.string "Puisque tu es si fort, tu devrais\n"
	.string "défier d'autres CHAMPIONS D'ARÈNE.\p"
	.string "En affrontant plein de DRESSEURS,\n"
	.string "tu apprendras beaucoup de choses.$"

RustboroCity_Gym_Text_GymStatue:
	.string "MÉROUVILLE ARENE POKéMON$"

RustboroCity_Gym_Text_GymStatueCertified:
	.string "MÉROUVILLE ARENE POKéMON\p"
	.string "DRESSEURS CERTIFIÉS DE ROXANNE :\n"
	.string "{PLAYER}$"

RustboroCity_Gym_Text_RoxanneRegisterCall:
	.string "… … … … … …\n"
	.string "… … … … … Bip !\p"
	.string "ROXANNE : Oh, bonjour, {PLAYER} ?\n"
	.string "C'est ROXANNE de CIVETTE VILLE.\p"
	.string "J'ai entendu de BRAWLY que tu\n"
	.string "avances dans les rangs des\l"
	.string "DRESSEURS à une vitesse incroyable.\p"
	.string "Eh bien, je préfère ne pas penser\n"
	.string "que je ne peux pas te battre.\p"
	.string "Je promets de remodeler mon ARÈNE\n"
	.string "pour que tu puisses nous défier à nouveau.\p"
	.string "J'espère que tu attendras cet\n"
	.string "événement autant que moi !\p"
	.string "… … … … … …\n"
	.string "… … … … … Clique !$"

RustboroCity_Gym_Text_RegisteredRoxanne:
	.string "CHAMPIONNE D'ARÈNE ROXANNE\n"
	.string "enregistrée dans le POKéNAV.$"

RustboroCity_Gym_Text_RoxannePreRematch:
	.string "ROXANNE : Je suis si contente de\n"
	.string "te revoir. Je suis ROXANNE, la\p"
	.string "CHAMPIONNE d'ARÈNE ici. Je suis sûre\n"
	.string "qu'on a tous vécu beaucoup de\p"
	.string "combats depuis. J'aimerais voir à quel\n"
	.string "point on s'est améliorés. Combattons !$"

RustboroCity_Gym_Text_RoxanneRematchDefeat:
	.string "Grr…\n"
	.string "Encore une défaite…$"

RustboroCity_Gym_Text_RoxannePostRematch:
	.string "ROXANNE : J'ai encore beaucoup à apprendre\n"
	.string "en matière de combat de POKéMON.\p"
	.string "Cette prise de conscience me fait d'autant plus\n"
	.string "aimer les combats !$"

RustboroCity_Gym_Text_RoxanneRematchNeedTwoMons:
	.string "ROXANNE : Je suis si\n"
	.string "contente de\p"
	.string "te revoir.\n"
	.string "Je suis ROXANNE, la\p"
	.string "CHAMPIONNE\n"
	.string "d'ARÈNE ici.\p"
	.string "Je suis sûre qu'on\n"
	.string "a tous les deux\p"
	.string "gagné en expérience.\n"
	.string "Combattons !$"
