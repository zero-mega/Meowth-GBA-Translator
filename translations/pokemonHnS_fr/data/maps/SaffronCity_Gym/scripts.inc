SaffronCity_Gym_MapScripts::
	.byte 0

SaffronCity_Gym_EventScript_GymGuy::
	goto_if_set FLAG_DEFEATED_SAFFRON_GYM, SaffronCity_Gym_EventScript_GymGuy2
	msgbox SaffronCity_Gym_Text_GymGuideIntro, MSGBOX_NPC
	end

SaffronCity_Gym_EventScript_GymGuy2::
	msgbox SaffronCity_Gym_Text_GymGuideWin, MSGBOX_NPC
	end

SaffronCity_Gym_EventScript_Rebecca::
	trainerbattle_single TRAINER_REBECCA SaffronCity_Gym_Text_MediumRebeccaSeen, SaffronCity_Gym_Text_MediumRebeccaBeaten
	msgbox SaffronCity_Gym_Text_MediumRebeccaAfter, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Franklin::
	trainerbattle_single TRAINER_FRANKLIN SaffronCity_Gym_Text_PsychicFranklinSeen, SaffronCity_Gym_Text_PsychicFranklinBeaten
	msgbox SaffronCity_Gym_Text_PsychicFranklinAfter, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Doris::
	trainerbattle_single TRAINER_DORIS SaffronCity_Gym_Text_MediumDorisSeen, SaffronCity_Gym_Text_MediumDorisBeaten
	msgbox SaffronCity_Gym_Text_MediumDorisAfter, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Jared::
	trainerbattle_single TRAINER_JARED SaffronCity_Gym_Text_PsychicJaredSeen, SaffronCity_Gym_Text_PsychicJaredBeaten
	msgbox SaffronCity_Gym_Text_PsychicJaredAfter, MSGBOX_AUTOCLOSE
	end

SaffronCity_Gym_EventScript_Sabrina::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_SAFFRON_GYM, SaffronCity_Gym_EventScript_Sabrina_Defeated
	msgbox SaffronCity_Gym_Text_SabrinaIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_SABRINA, SaffronCity_Gym_Text_SabrinaWinLoss
	message SaffronCity_Gym_Text_ReceivedMarshBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox SaffronCity_Gym_Text_MarshBadgeInfo, MSGBOX_DEFAULT
	setflag FLAG_BADGE13_GET
	setflag FLAG_DEFEATED_SAFFRON_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 13
	call Common_EventScript_SetGymTrainers
	closemessage
	clearflag FLAG_HIDE_OLIVINE_SABRINA
	release
	end

SaffronCity_Gym_EventScript_Sabrina_Defeated::
	msgbox SaffronCity_Gym_Text_SabrinaPostBattle, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_Gym_Text_SabrinaIntro:
	.string "SABRINA :\p"
	.string "Je savais\n"
	.string "que tu viendrais…\p"
	.string "Il y a trois ans\p"
	.string "j'ai eu une vision\n"
	.string "de ton arrivée.\l"
	.string "Tu veux\l"
	.string "mon BADGE ?\p"
	.string "Montre-moi ta\n"
	.string "force psychique !$"

SaffronCity_Gym_Text_SabrinaWinLoss:
	.string "SABRINA : Ton pouvoir…\p"
	.string "Il dépasse de loin ce que j'avais prévu…\p"
	.string "Peut-être n'est-il pas possible de tout\n"
	.string "prévoir…\p"
	.string "Tu es incroyable.\n"
	.string "Reviens quand tu veux.$"

SaffronCity_Gym_Text_ReceivedMarshBadge:
	.string "{PLAYER} a reçu le BADGE MARAIS.$"

SaffronCity_Gym_Text_MarshBadgeInfo:
	.string "SABRINA : Le BADGE MARAIS\n"
	.string "réveille tes pouvoirs subconscients… Même\p"
	.string "si je n'ai pas su\n"
	.string "prévoir exactement ta puissance,\l"
	.string "une chose est certaine.\p"
	.string "Tu deviendras un CHAMPION\n"
	.string "célébré et adoré !$"

SaffronCity_Gym_Text_SabrinaPostBattle:
	.string "MORGANE : Ton amour pour tes\n"
	.string "POKéMON a submergé mon pouvoir\l"
	.string "psychique…\p"
	.string "Le pouvoir de l'amour, je pense, est\n"
	.string "aussi une sorte de pouvoir psychique…$"

SaffronCity_Gym_Text_SabrinaRematch:
	.string "SABRINA : Ah, le CHAMPION DE KANTO.\p"
	.string "J'ai senti ton retour.\p"
	.string "Ta puissance a énormément grandi.\p"
	.string "Même maintenant, je sens ton aura.\p"
	.string "Tu veux avoir un match retour avec moi ?$"

SaffronCity_Gym_Text_SabrinaRematchDefeat:
	.string "MORGANE : Ton amour pour tes\n"
	.string "POKéMON a encore submergé mon\l"
	.string "pouvoir psychique…$"

SaffronCity_Gym_Text_MediumRebeccaSeen:
	.string "La puissance de tous ceux que\n"
	.string "tu as battus me revient !$"

SaffronCity_Gym_Text_MediumRebeccaBeaten:
	.string "Fort… Beaucoup trop fort…$"

SaffronCity_Gym_Text_MediumRebeccaAfter:
	.string "Quelle est la source de ta puissance ?$"

SaffronCity_Gym_Text_PsychicFranklinSeen:
	.string "Le pouvoir psychique est le pouvoir\n"
	.string "de ton âme.$"

SaffronCity_Gym_Text_PsychicFranklinBeaten:
	.string "Ton âme a plus de puissance que\n"
	.string "la mienne !$"

SaffronCity_Gym_Text_PsychicFranklinAfter:
	.string "Tu as renforcé ton âme, pas\n"
	.string "seulement tes capacités.$"

SaffronCity_Gym_Text_MediumDorisSeen:
	.string "Fufufufu… Je le vois clairement.\p"
	.string "Je peux voir dans ton âme !$"

SaffronCity_Gym_Text_MediumDorisBeaten:
	.string "Je t'ai lu, et j'ai quand même perdu…$"

SaffronCity_Gym_Text_MediumDorisAfter:
	.string "Zut ! J'avais oublié que j'avais prédit\n"
	.string "que je perdrais contre toi.$"

SaffronCity_Gym_Text_PsychicJaredSeen:
	.string "Le DOJO DE COMBAT d'à côté était\n"
	.string "autrefois l'ARÈNE de cette ville.$"

SaffronCity_Gym_Text_PsychicJaredBeaten:
	.string "Pas de chance…$"

SaffronCity_Gym_Text_PsychicJaredAfter:
	.string "Le ROI DU KARATÉ, maître du DOJO\n"
	.string "COMBAT, vient d'être détruit\l"
	.string "par OLGA.$"

SaffronCity_Gym_Text_GymGuideIntro:
	.string "Hé, futur CHAMPION !\p"
	.string "Un dresseur aussi habile que toi\n"
	.string "n'a pas besoin qu'on lui explique comment\l"
	.string "affronter les POKéMON de type PSY,\l"
	.string "n'est-ce pas ?\p"
	.string "J'attends beaucoup de toi !\p"
	.string "Bonne chance !$"

SaffronCity_Gym_Text_GymGuideWin:
	.string "C'était un autre combat fantastique !$"

SaffronCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE13_GET, SaffronCity_Gym_EventScript_GymStatuePostVictory
	msgbox SaffronCity_Gym_Text_GymStatue
	releaseall
	end

SaffronCity_Gym_EventScript_GymStatuePostVictory::
	msgbox SaffronCity_Gym_Text_GymStatuePlayerWon
	releaseall
	end


SaffronCity_Gym_Text_GymStatue::
    .string "SAFRANIA ARENE POKéMON\n"
    .string "CHAMPIONNE : MORGANE\p"
    .string "DRESSEURS VAINQUEURS :\n"
    .string "BLUE, RED$"

SaffronCity_Gym_Text_GymStatuePlayerWon::
    .string "ARÈNE POKéMON DE SAFRANIA\n"
    .string "CHAMPION D'ARÈNE : MORGANE\p"
    .string "DRESSEURS VAINQUEURS :\n"
    .string "BLEU, ROUGE, {PLAYER}$"
