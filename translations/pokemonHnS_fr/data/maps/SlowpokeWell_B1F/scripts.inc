.set LOCALID_WELL_KURT, 19

SlowpokeWell_B1F_MapScripts::
	.byte 0

SlowpokeWell_B1F_EventScript_Item_Super_Potion_1::
	finditem ITEM_SUPER_POTION
	end

SlowpokeWell_B1F_EventScript_Item_Super_Potion_2::
	finditem ITEM_SUPER_POTION
	end

SlowpokeWell_B1F_EventScript_Item_Great_Ball::
	finditem ITEM_GREAT_BALL
	end

SlowpokeWell_B1F_EventScript_Item_Full_Heal::
	finditem ITEM_FULL_HEAL
	end

SlowpokeWell_B1F_EventScript_Kurt::
	lock
	msgbox SlowpokeWell_B1F_Text_KurtIntro, MSGBOX_DEFAULT
	closemessage
	end

SlowpokeWell_B1F_EventScript_Grunt21::
	trainerbattle_single TRAINER_GRUNT_21, SlowpokeWell_B1F_Text_GruntM29Seen, SlowpokeWell_B1F_Text_GruntM29Beaten
	msgbox SlowpokeWell_B1F_Text_GruntM29After, MSGBOX_AUTOCLOSE
	end

SlowpokeWell_B1F_EventScript_Grunt22F::
	trainerbattle_single TRAINER_GRUNT_22, SlowpokeWell_B1F_Text_GruntF1Seen, SlowpokeWell_B1F_Text_GruntF1Beaten
	msgbox SlowpokeWell_B1F_Text_GruntF1After, MSGBOX_AUTOCLOSE
	end

SlowpokeWell_B1F_EventScript_Eto::
	trainerbattle_single TRAINER_ETO, SlowpokeWell_B1F_Text_GruntM2Seen, SlowpokeWell_B1F_Text_GruntM2Beaten
	msgbox SlowpokeWell_B1F_Text_GruntM2After, MSGBOX_AUTOCLOSE
	end

SlowpokeWell_B1F_EventScript_Proton::
	lock
	faceplayer
	msgbox SlowpokeWell_B1F_Text_ProtonSeen, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_PROTON_1, SlowpokeWell_B1F_Text_ProtonBeaten
	msgbox SlowpokeWell_B1F_Text_ProtonAfter, MSGBOX_AUTOCLOSE
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_AZALEA_TOWN_ROCKETS
	clearflag FLAG_HIDE_KURT_1
	addobject LOCALID_WELL_KURT
	removeobject 11
	removeobject 12
	removeobject 13
	delay 120
	fadescreen FADE_FROM_BLACK
	special DrawWholeMapView
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	applymovement LOCALID_WELL_KURT, SlowpokeWell_B1F_Movement_Kurt
	waitmovement 0
	msgbox SlowpokeWell_B1F_Text_KurtAfter, MSGBOX_DEFAULT
	closemessage
	fadescreen FADE_TO_BLACK
	setflag FLAG_HIDE_SLOWPOKE_WELL_KURT
	setflag FLAG_HIDE_KURT_1
	clearflag FLAG_HIDE_KURT_2
	clearflag FLAG_HIDE_AZALEA_TOWN_SLOWPOKE
	setvar VAR_AZALEA_TOWN_STATE, 3
	warp MAP_AZALEA_TOWN_KURTS_HOUSE, 15, 4
	release
	end

SlowpokeWell_B1F_Movement_Kurt:
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	step_end

SlowpokeWell_B1F_Text_KurtIntro:
	.string "KURT : Hé, {PLAYER} !\p"
	.string "Le garde en haut\n"
	.string "s'est enfui quand\p"
	.string "je lui ai crié dessus.\n"
	.string "Mais ensuite je\p"
	.string "suis tombé dans\n"
	.string "le PUITS.\p"
	.string "Les QUEUES-RAMOLOSS\n"
	.string "sont\p"
	.string "en sécurité maintenant.\p"
	.string "Merci pour ton\n"
	.string "aide, {PLAYER} !$"

SlowpokeWell_B1F_Text_KurtAfter:
	.string "KURT : Bien joué, {PLAYER} !\p"
	.string "La TEAM ROCKET a déguerpi.\p"
	.string "Mon dos va mieux aussi.\n"
	.string "Sortons d'ici.$"

SlowpokeWell_B1F_Text_GruntM29Seen:
	.string "Mince ! Je faisais la garde en\n"
	.string "haut quand un vieux type m'a crié\l"
	.string "dessus.\p"
	.string "Il m'a tellement effrayé que\n"
	.string "je suis tombé ici.\p"
	.string "Je vais évacuer ma colère en\n"
	.string "me défoulant sur toi !$"

SlowpokeWell_B1F_Text_GruntM29Beaten:
	.string "Arrgh ! Ce n'est PAS mon jour !$"

SlowpokeWell_B1F_Text_GruntM29After:
	.string "Bien sûr, on a coupé les\n"
	.string "queues de RAMOLOSS et on les vend\l"
	.string "comme ça.\p"
	.string "Tout ce qu'on fait est pour le profit.\p"
	.string "C'est ça ! On est la TEAM ROCKET,\n"
	.string "et on fera n'importe quoi pour l'argent !$"

SlowpokeWell_B1F_Text_ProtonSeen:
	.string "Qu'est-ce que tu veux ?\p"
	.string "Si tu interromps notre travail,\n"
	.string "n'attends aucune pitié !$"

SlowpokeWell_B1F_Text_ProtonBeaten:
	.string "Tu t'en es bien sorti aujourd'hui,\n"
	.string "mais attends la prochaine fois !$"

SlowpokeWell_B1F_Text_ProtonAfter:
	.string "Ouais, la TEAM ROCKET a été\n"
	.string "démantelée il y a trois ans.\p"
	.string "Le boss s'est caché.\p"
	.string "Mais nous avons continué nos\n"
	.string "activités en secret !\p"
	.string "Un petit obstacle comme toi ne\n"
	.string "sera pas un problème pour notre mission.\p"
	.string "Je te conseille d'avoir très peur\n"
	.string "de ce qui va arriver !$"

SlowpokeWell_B1F_Text_GruntM2Seen:
	.string "Hyuck-hyuck-hyuck ! Tu arrêtes de prendre\n"
	.string "des QUEUES DE RAMOLOSS ? Tu\p"
	.string "es fou ! Si on\n"
	.string "t'obéissait, la réputation de la\l"
	.string "TEAM ROCKET serait ruinée !$"

SlowpokeWell_B1F_Text_GruntM2Beaten:
	.string "Hyuck…\n"
	.string "Trop fort…$"

SlowpokeWell_B1F_Text_GruntM2After:
	.string "On a besoin d'argent,\n"
	.string "mais vendre des QUEUES RAMOLOSS ?\p"
	.string "C'est dur d'être un SBIRE ROCKET !$"

SlowpokeWell_B1F_Text_GruntF1Seen:
	.string "Tu en as assez des QUEUES ?\p"
	.string "Ouais, essaie juste de nous battre\n"
	.string "tous !$"

SlowpokeWell_B1F_Text_GruntF1Beaten:
	.string "Sale morveux !$"

SlowpokeWell_B1F_Text_GruntF1After:
	.string "Les QUEUES-RAMOLOSS repoussent vite !\p"
	.string "Qu'y a-t-il de mal à les vendre ?$"

SlowpokeWell_B1F_Text_SlowpokeWithMail:
	.string "Un RAMOLOSS à qui on a coupé la QUEUE…\p"
	.string "Hein ? Il a du COURRIER.\n"
	.string "Le lire ?$"

SlowpokeWell_B1F_Text_SlowpokeMail:
	.string "{PLAYER} lit le COURRIER.\p"
	.string "Sois sage et veille sur la\n"
	.string "maison avec Papi et RAMOLOSS.\p"
	.string "Bisous, Papa$"

SlowpokeWell_B1F_Text_TaillessSlowpoke:
	.string "Un RAMOLOSS avec sa QUEUE coupée…$"
