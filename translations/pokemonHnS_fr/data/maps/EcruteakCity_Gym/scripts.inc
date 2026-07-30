EcruteakCity_Gym_MapScripts::
	.byte 0

EcruteakCity_Gym_EventScript_GymGuy::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ECRUTEAK_CITY_GYM, EcruteakCity_Gym_EventScript_GymGuy2
	msgbox EcruteakCity_GymGuideText, MSGBOX_DEFAULT
	closemessage
	release
	end
	
EcruteakCity_Gym_EventScript_GymGuy2::
	msgbox EcruteakCity_GymGuideWinText, MSGBOX_DEFAULT
	release
	end	

EcruteakCity_Gym_EventScript_Jeffrey::
	trainerbattle_single TRAINER_JEFFREY SageJeffreySeenText, SageJeffreyBeatenText
	msgbox SageJeffreyAfterBattleText, MSGBOX_AUTOCLOSE
	end
EcruteakCity_Gym_EventScript_Ping::
	trainerbattle_single TRAINER_PING SagePingSeenText, SagePingBeatenText
	msgbox SagePingAfterBattleText, MSGBOX_AUTOCLOSE
	end

EcruteakCity_Gym_EventScript_Martha::
	trainerbattle_single TRAINER_MARTHA MediumMarthaSeenText, MediumMarthaBeatenText
	msgbox MediumMarthaAfterBattleText, MSGBOX_AUTOCLOSE
	end

EcruteakCity_Gym_EventScript_Grace::
	trainerbattle_single TRAINER_GRACE MediumGraceSeenText, MediumGraceBeatenText
	msgbox MediumGraceAfterBattleText, MSGBOX_AUTOCLOSE
	end

EcruteakCity_Gym_EventScript_Morty::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ECRUTEAK_CITY_GYM, EcruteakCity_Gym_EventScript_Morty_Defeated
	msgbox MortyIntroText, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MORTY_1, MortyWinLossText
	message Text_ReceivedFogBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox MortyText_FogBadgeSpeech, MSGBOX_DEFAULT
	setflag FLAG_BADGE04_GET
	setflag FLAG_DEFEATED_ECRUTEAK_CITY_GYM
	addvar VAR_NUM_BADGES, 1
	setvar VAR_0x8008, 4
	call Common_EventScript_SetGymTrainers
	giveitem ITEM_TM_SHADOW_BALL
	msgbox MortyText_ShadowBallSpeech, MSGBOX_DEFAULT
	setvar VAR_ECRUTEAK_CITY_STATE, 4
	closemessage
	release
	end

EcruteakCity_Gym_EventScript_Morty_Defeated::
	msgbox MortyFightDoneText, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Gym_EventScript_Statue::
	lock
	goto_if_set FLAG_DEFEATED_ECRUTEAK_CITY_GYM, EcruteakCity_Gym_EventScript_Statue2
	msgbox EcruteakCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Gym_EventScript_Statue2::
	msgbox EcruteakCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	closemessage
	release
	end

EcruteakCity_Gym_Text_GymStatue:
	.string "ROSALIA ARENE POKéMON$"

EcruteakCity_Gym_Text_GymStatueCertified:
	.string "ROSALIA ARENE POKéMON\p"
	.string "DRESSEURS CERTIFIÉS DE MORTIMER :\n"
	.string "{PLAYER}$"

MortyIntroText:
	.string "Bon de vous voir.\p"
	.string "Ici à ROSALIA, les POKéMON ont\n"
	.string "toujours été vénérés.\p"
	.string "On dit qu'un POKéMON aux couleurs\n"
	.string "de l'arc-en-ciel descendra\l"
	.string "pour apparaître devant un vrai Dresseur.\p"
	.string "J'ai cru à cette légende, alors je me suis\n"
	.string "entraîné ici en secret.\p"
	.string "En conséquence, je peux maintenant voir ce\n"
	.string "que les autres ne peuvent pas.\p"
	.string "Encore un peu…\p"
	.string "Avec un peu plus, je pourrais voir\n"
	.string "un avenir où je rencontre le\l"
	.string "POKéMON aux couleurs de l'arc-en-ciel.\p"
	.string "Tu vas m'aider à atteindre\n"
	.string "ce niveau !$"

MortyWinLossText:
	.string "Je ne suis pas encore assez fort…\p"
	.string "D'accord. Ce BADGE est à toi.$"

Text_ReceivedFogBadge:
	.string "{PLAYER} a reçu le BADGE BRUME.$"

MortyText_FogBadgeSpeech:
	.string "Avec le BADGE BRUME, les POKéMON\n"
	.string "jusqu'au Niveau 50 t'obéiront.\p"
	.string "De plus, tout POKéMON qui connaît\n"
	.string "SURF pourra l'utiliser\l"
	.string "à tout moment.\p"
	.string "Je veux que tu prennes ceci aussi.$"

MortyText_ShadowBallSpeech:
	.string "C'est BALL'OMBRE.\n"
	.string "Il inflige des dégâts et peut\l"
	.string "baisser la DEF. SPÉ.\p"
	.string "Utilise-le si ça te convient.$"

MortyFightDoneText:
	.string "Je vois… Ton voyage\p"
	.string "t'a mené dans des\n"
	.string "contrées lointaines. Tu as\p"
	.string "vu plus de\n"
	.string "choses que moi.\p"
	.string "Je t'en envie…$"

MortyRematchText:
	.string "Ah, le CHAMPION\n"
	.string "de JOHTO !\p"
	.string "Content que\n"
	.string "tu sois venu.\l"
	.string "Tu as montré\p"
	.string "force\n"
	.string "et compétence,\p"
	.string "mais as-tu\n"
	.string "grandi depuis ?\p"
	.string "Montre-moi !$"

Morty_RematchDefeatText:
	.string "Je ne suis pas encore assez bon…\p"
	.string "Tu as vu plus de choses que moi\n"
	.string "de toute ma vie.\p"
	.string "Je t'envie pour ça…$"

SageJeffreySeenText:
	.string "J'ai passé le printemps avec mes\n"
	.string "POKéMON.\p"
	.string "Puis l'été, l'automne et l'hiver...\p"
	.string "Puis le printemps est revenu.\n"
	.string "Nous sommes ensemble depuis longtemps.$"

SageJeffreyBeatenText:
	.string "Victoires et défaites--j'ai connu\n"
	.string "les deux.$"

SageJeffreyAfterBattleText:
	.string "D'où viennent les POKéMON ?$"

SagePingSeenText:
	.string "Peux-tu infliger des dégâts\n"
	.string "à nos POKéMON ?$"

SagePingBeatenText:
	.string "Ah ! Bien joué !$"

SagePingAfterBattleText:
	.string "Nous utilisons des POKéMON de type SPECTRE.\p"
	.string "Aucune attaque de type NORMAL\n"
	.string "ne peut leur faire de mal !$"

MediumMarthaSeenText:
	.string "Je vais gagner !$"

MediumMarthaBeatenText:
	.string "Je... je... j'ai perdu !$"

MediumMarthaAfterBattleText:
	.string "Celui qui veut gagner le plus\n"
	.string "est celui qui gagnera !$"

MediumGraceSeenText:
	.string "Perdu dans nos couloirs sombres ?\n"
	.string "Bats-moi si tu veux un indice !$"

MediumGraceBeatenText:
	.string "Qu-quoi ?$"

MediumGraceAfterBattleText:
	.string "Très bien. Je vais te dire le secret\n"
	.string "des ombres.\p"
	.string "Le chemin est juste devant\n"
	.string "tes yeux !$"

EcruteakCity_GymGuideText:
	.string "Hé CHAMPION !\n"
	.string "Tu es presque\p"
	.string "à mi-chemin !\n"
	.string "Les DRESSEURS\p"
	.string "ici utilisent\n"
	.string "des POKéMON\l"
	.string "SPECTRE et\p"
	.string "TÉNÈBRES. Sois\n"
	.string "prudent !$"

EcruteakCity_GymGuideWinText:
	.string "Ouf, {PLAYER}. Tu as été génial !\p"
	.string "Je me recroquevillais dans un coin\n"
	.string "de pure terreur !$"

EcruteakCity_GymClosedText:
	.string "MORTY, le CHAMPION d'ARÈNE, est\n"
	.string "absent.\p"
	.string "Désolé, mais tu dois\n"
	.string "partir.\p"
	.string "Hohohoho.$"
