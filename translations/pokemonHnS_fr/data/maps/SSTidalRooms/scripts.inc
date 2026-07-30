SSTidalRooms_MapScripts::
	.byte 0

SSTidalRooms_EventScript_SnatchGiver::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_TM_SNATCH, SSTidalRooms_EventScript_ExplainSnatch
	msgbox SSTidalRooms_Text_NotSuspiciousTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_TM_SNATCH
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_SNATCH
	msgbox SSTidalRooms_Text_ExplainSnatch, MSGBOX_DEFAULT
	release
	end

SSTidalRooms_EventScript_ExplainSnatch::
	msgbox SSTidalRooms_Text_ExplainSnatch, MSGBOX_DEFAULT
	release
	end

SSTidalRooms_EventScript_Bed::
	specialvar VAR_RESULT, IsPokecenterChallengeActivated
	goto_if_eq VAR_RESULT, TRUE, SSTidalRooms_EventScript_Bed_PokecenterChallenge
	lockall
	msgbox SSTidalRooms_Text_TakeRestOnBed, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	call SSTidalRooms_EventScript_ProgessCruiseAfterBed
	releaseall
	end

SSTidalRooms_EventScript_Bed_PokecenterChallenge::
	msgbox SSTidalRooms_Text_TakeRestOnBed_PokecenterChallenge, MSGBOX_DEFAULT
	closemessage
	end

SSTidalRooms_EventScript_Colton::
	trainerbattle_single TRAINER_GRUNT_26, SSTidalRooms_Text_ColtonIntro, SSTidalRooms_Text_ColtonDefeat
	msgbox SSTidalRooms_Text_ColtonPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Micah::
	trainerbattle_single TRAINER_MICAH, SSTidalRooms_Text_MicahIntro, SSTidalRooms_Text_MicahDefeat
	msgbox SSTidalRooms_Text_MicahPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Thomas::
	trainerbattle_single TRAINER_THOMAS, SSTidalRooms_Text_ThomasIntro, SSTidalRooms_Text_ThomasDefeat
	msgbox SSTidalRooms_Text_ThomasPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Jed::
	trainerbattle_double TRAINER_LEA_AND_JED, SSTidalRooms_Text_JedIntro, SSTidalRooms_Text_JedDefeat, SSTidalRooms_Text_JedNotEnoughMons
	msgbox SSTidalRooms_Text_JedPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Lea::
	trainerbattle_double TRAINER_LEA_AND_JED, SSTidalRooms_Text_LeaIntro, SSTidalRooms_Text_LeaDefeat, SSTidalRooms_Text_LeaNotEnoughMons
	msgbox SSTidalRooms_Text_LeaPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Garret::
	trainerbattle_single TRAINER_GARRET, SSTidalRooms_Text_GarretIntro, SSTidalRooms_Text_GarretDefeat
	msgbox SSTidalRooms_Text_GarretPostBattle, MSGBOX_AUTOCLOSE
	end

SSTidalRooms_EventScript_Naomi::
	trainerbattle_single TRAINER_NAOMI, SSTidalRooms_Text_NaomiIntro, SSTidalRooms_Text_NaomiDefeat
	msgbox SSTidalRooms_Text_NaomiPostBattle, MSGBOX_AUTOCLOSE
	end
	
SSTidalRooms_Text_TakeRestOnBed_PokecenterChallenge:
	.string "Désolé, tu joues avec\n"
	.string "le DÉFI POKéCENTER !$"

SSTidalRooms_Text_TakeRestOnBed:
	.string "Il y a un lit…\n"
	.string "Reposons-nous.$"

SSTidalRooms_Text_ColtonIntro:
	.string "Je navigue souvent vers LILYCOVE.\p"
	.string "J'adore assister aux CONCOURS,\n"
	.string "tu vois.$"

SSTidalRooms_Text_ColtonDefeat:
	.string "C'était un match agréable !$"

SSTidalRooms_Text_ColtonPostBattle:
	.string "Je suis tellement excité en imaginant les\n"
	.string "POKéMON que je verrai au prochain\l"
	.string "CONCOURS. L'anticipation me fait frissonner !$"

SSTidalRooms_Text_MicahIntro:
	.string "Tes amis sont-ils forts ?$"

SSTidalRooms_Text_MicahDefeat:
	.string "Tes amis sont, en effet, forts.$"

SSTidalRooms_Text_MicahPostBattle:
	.string "Les amis n'ont pas besoin d'être humains.\n"
	.string "Pour moi, les POKéMON sont des amis précieux !$"

SSTidalRooms_Text_ThomasIntro:
	.string "Enfant…\n"
	.string "As-tu frappé à la porte ?$"

SSTidalRooms_Text_ThomasDefeat:
	.string "Une défaite doit être acceptée\n"
	.string "sans hâte ni panique.$"

SSTidalRooms_Text_ThomasPostBattle:
	.string "Ne jamais être perturbé en toute situation,\n"
	.string "c'est le code de conduite du GENTLEMAN.$"

SSTidalRooms_Text_JedIntro:
	.string "JED : Je me sens un peu gêné, mais…\n"
	.string "On va te montrer notre pouvoir amoureux !$"

SSTidalRooms_Text_JedDefeat:
	.string "JED : Soupir…$"

SSTidalRooms_Text_JedPostBattle:
	.string "JED : C'est la première fois que notre\n"
	.string "pouvoir d'amoureux n'a pas prévalu !\l"
	.string "Tu dois être un DRESSEUR génial !$"

SSTidalRooms_Text_JedNotEnoughMons:
	.string "JED : Tu n'as qu'un seul POKéMON ?\n"
	.string "Ce n'est pas un peu triste ?$"

SSTidalRooms_Text_LeaIntro:
	.string "LEA : Je me sens un peu bête, mais…\n"
	.string "On va te montrer notre pouvoir amoureux !$"

SSTidalRooms_Text_LeaDefeat:
	.string "LEA : Oh, mince !$"

SSTidalRooms_Text_LeaPostBattle:
	.string "LEA : Je n'arrive pas à y croire !\n"
	.string "Notre pouvoir d'amoureux a échoué…\l"
	.string "Tu dois être un DRESSEUR de ouf !$"

SSTidalRooms_Text_LeaNotEnoughMons:
	.string "LÉA : Je voulais combattre…\n"
	.string "Mais tu n'as même pas deux POKéMON…$"

SSTidalRooms_Text_GarretIntro:
	.string "Ah, tu arrives au bon moment.\p"
	.string "Je m'ennuie, tu vois.\n"
	.string "Tu peux m'amuser.$"

SSTidalRooms_Text_GarretDefeat:
	.string "…Ça suffira.$"

SSTidalRooms_Text_GarretPostBattle:
	.string "Peut-être que je demanderai à papa de m'acheter\n"
	.string "un yacht.\l"
	.string "Un yacht pour moi et mes POKéMON !$"

SSTidalRooms_Text_NaomiIntro:
	.string "Oh, tu es un DRESSEUR adorable.\n"
	.string "Tu veux prendre le thé ?\l"
	.string "Ou tu préfères combattre ?$"

SSTidalRooms_Text_NaomiDefeat:
	.string "Je vois.\n"
	.string "Tu es du genre actif.$"

SSTidalRooms_Text_NaomiPostBattle:
	.string "Une croisière mondiale sur un paquebot de luxe a\n"
	.string "son charme, je dois l'admettre…\p"
	.string "Mais j'avoue qu'il y a un côté attrayant\n"
	.string "à visiter HOENN en ferry.$"

SSTidalRooms_Text_NotSuspiciousTakeThis:
	.string "Euh… Salut ! Je… Je n'ai pas l'air suspect !\n"
	.string "Euh… Tu peux avoir ça ! Gratuitement !\p"
	.string "Ça… Honnêtement, je ne l'ai pas VOLÉ à\n"
	.string "quelqu'un ! Je ne ferais jamais une chose pareille !\l"
	.string "C'est propre ! Tu peux l'utiliser !$"

SSTidalRooms_Text_ExplainSnatch:
	.string "SIPHON absorbe les effets bénéfiques\n"
	.string "de certaines attaques avant qu'elles ne puissent\l"
	.string "être utilisées par un ennemi ou un allié.$"

