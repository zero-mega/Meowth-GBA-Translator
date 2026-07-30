MtPyre_2F_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, CaveHole_CheckFallDownHole
	map_script MAP_SCRIPT_ON_TRANSITION, CaveHole_FixCrackedGround
	map_script MAP_SCRIPT_ON_RESUME, MtPyre_2F_SetHoleWarp
	.byte 0

MtPyre_2F_SetHoleWarp:
	setstepcallback STEP_CB_CRACKED_FLOOR
	setholewarp MAP_MT_PYRE_1F
	end

MtPyre_2F_EventScript_Woman::
	msgbox MtPyre_2F_Text_MemoriesOfSkitty, MSGBOX_NPC
	end

MtPyre_2F_EventScript_PokefanM::
	msgbox MtPyre_2F_Text_TumbledFromFloorAbove, MSGBOX_NPC
	end

MtPyre_2F_EventScript_Mark::
	trainerbattle_single TRAINER_MARK, MtPyre_2F_Text_MarkIntro, MtPyre_2F_Text_MarkDefeat
	msgbox MtPyre_2F_Text_MarkPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Luke::
	trainerbattle_double TRAINER_DEZ_AND_LUKE, MtPyre_2F_Text_LukeIntro, MtPyre_2F_Text_LukeDefeat, MtPyre_2F_Text_LukeNotEnoughMons
	msgbox MtPyre_2F_Text_LukePostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Dez::
	trainerbattle_double TRAINER_DEZ_AND_LUKE, MtPyre_2F_Text_DezIntro, MtPyre_2F_Text_DezDefeat, MtPyre_2F_Text_DezNotEnoughMons
	msgbox MtPyre_2F_Text_DezPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Leah::
	trainerbattle_single TRAINER_LEAH, MtPyre_2F_Text_LeahIntro, MtPyre_2F_Text_LeahDefeat
	msgbox MtPyre_2F_Text_LeahPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_EventScript_Zander::
	trainerbattle_single TRAINER_ZANDER, MtPyre_2F_Text_ZanderIntro, MtPyre_2F_Text_ZanderDefeat
	msgbox MtPyre_2F_Text_ZanderPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_2F_Text_MemoriesOfSkitty:
	.string "Les souvenirs de mon adorable SKITTY…\n"
	.string "Mes yeux débordent rien qu'en y pensant.$"

MtPyre_2F_Text_TumbledFromFloorAbove:
	.string "Ouch, aïe… Il y a des trous\n"
	.string "dans le sol ici et là. Je\p"
	.string "n'ai pas fait attention et je\n"
	.string "suis tombé de l'étage du dessus.$"

MtPyre_2F_Text_MarkIntro:
	.string "Hé ! Tu cherches des POKéMON ?\n"
	.string "Tu es passé après moi ! C'est impoli !$"

MtPyre_2F_Text_MarkDefeat:
	.string "Ayieeeeh !\n"
	.string "Pardon, pardonne-moi, s'il te plaît !$"

MtPyre_2F_Text_MarkPostBattle:
	.string "Les gens ne viennent pas souvent ici,\n"
	.string "alors je pensais qu'il y aurait des POKéMON rares.$"

MtPyre_2F_Text_LukeIntro:
	.string "LUKE : On est là pour un pari.\p"
	.string "Héhé, si je lui montre à quel point je suis cool,\n"
	.string "elle va craquer pour moi. J'en suis sûr !\p"
	.string "Je sais ! Je vais te battre et lui montrer\n"
	.string "à quel point je suis cool !$"

MtPyre_2F_Text_LukeDefeat:
	.string "LUKE : Oups !$"

MtPyre_2F_Text_LukePostBattle:
	.string "LUKE : Eh bien, on a perdu, mais c'est OK !\n"
	.string "Je suis juste à tes côtés.\l"
	.string "On va s'en sortir avec ce défi !$"

MtPyre_2F_Text_LukeNotEnoughMons:
	.string "LUKE : Si tu veux m'affronter,\n"
	.string "amène plus de POKéMON.\p"
	.string "Sinon, je ne pourrai pas montrer\n"
	.string "à ma copine à quel point je suis cool !$"

MtPyre_2F_Text_DezIntro:
	.string "DEZ : Je suis venue ici sur un pari avec mon\n"
	.string "petit ami.\p"
	.string "C'est vraiment effrayant, mais je suis avec mon\n"
	.string "petit ami. Ça va.\p"
	.string "Je sais ! Je vais demander à mon petit ami de faire\n"
	.string "le malin en te battant !$"

MtPyre_2F_Text_DezDefeat:
	.string "DEZ : Waaaah ! J'ai peur !$"

MtPyre_2F_Text_DezPostBattle:
	.string "DEZ : On est amoureux, alors on\n"
	.string "s'en fiche si on perd !$"

MtPyre_2F_Text_DezNotEnoughMons:
	.string "DEZ : Si tu veux nous défier, tu\n"
	.string "devrais amener au moins deux POKéMON.\p"
	.string "Mon petit ami est fort.\n"
	.string "Un seul POKéMON ne suffira pas du tout.$"

MtPyre_2F_Text_LeahIntro:
	.string "Tu es une personne inconnue…\n"
	.string "Pars avant qu'il ne t'arrive quelque chose !$"

MtPyre_2F_Text_LeahDefeat:
	.string "Hmm…\n"
	.string "Tu es solide.$"

MtPyre_2F_Text_LeahPostBattle:
	.string "Notre famille est DRESSEUR ici\n"
	.string "depuis l'époque de mon\p"
	.string "arrière-grand-mère… C'est mon devoir\n"
	.string "de protéger cette montagne…$"

MtPyre_2F_Text_ZanderIntro:
	.string "Kiyaaaaah !\n"
	.string "J'ai trop peur !$"

MtPyre_2F_Text_ZanderDefeat:
	.string "Noooooon !\n"
	.string "J'ai perdu la tête !$"

MtPyre_2F_Text_ZanderPostBattle:
	.string "Je sursaute à chaque fois que je vois\n"
	.string "quelque chose bouger…\p"
	.string "Je n'aurais pas dû venir m'entraîner ici…$"

