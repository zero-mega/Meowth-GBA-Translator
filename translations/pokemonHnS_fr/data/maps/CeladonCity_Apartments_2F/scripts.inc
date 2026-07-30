CeladonCity_Apartments_2F_MapScripts::
	.byte 0

CeladonCity_Apartments_2F_EventScript_Computer::
	lock
	playse SE_PC_ON
	msgbox CeladonMansion2F_Text_Computer
	playse SE_PC_OFF
	waitse
	release
	end

CeladonCity_Apartments_2F_EventScript_Sign::
	msgbox CeladonMansion2F_Text_DevOfficeSign, MSGBOX_SIGN
	end

CeladonMansion2F_Text_Computer:
	.string "{PLAYER} a\p"
	.string "allumé le PC.\p"
	.string "…\n"
	.string "Quelqu'un était\p"
	.string "en train de\p"
	.string "composer un e-mail.\n"
	.string "« …J'espère que\p"
	.string "tu continueras\n"
	.string "les recherches sur les\p"
	.string "Systèmes de Stockage.\p"
	.string "De BILL »$"

CeladonMansion2F_Text_DevOfficeSign:
	.string "BUREAU DE DÉVELOPPEMENT HEART & SOUL$"

CeladonMansion2F_EventScript_LilDill::
	msgbox CeladonMansion2F_Text_LilDill, MSGBOX_NPC
	end

CeladonMansion2F_EventScript_InfiniteBacon::
	msgbox CeladonMansion2F_Text_InfiniteBacon, MSGBOX_NPC
	end

CeladonMansion2F_EventScript_TixoRebel::
	msgbox CeladonMansion2F_Text_TixoRebel, MSGBOX_NPC
	end

CeladonMansion2F_EventScript_Phant::
	msgbox CeladonMansion2F_Text_Phant, MSGBOX_NPC
	end

CeladonMansion2F_EventScript_Exclsior::
	msgbox CeladonMansion2F_Text_Exclsior, MSGBOX_NPC
	end

CeladonMansion2F_EventScript_DaniRainbow::
    msgbox CeladonMansion2F_Text_DaniRaibow, MSGBOX_NPC
    end

CeladonMansion2F_Text_LilDill:
	.string "Salut à tous,\p"
	.string "Patch 15--\p"
	.string "Pardon, je\p"
	.string "veux dire…\n"
	.string "Salut, je suis le\p"
	.string "DIRECTEUR DU JEU !\n"
	.string "J'ai construit les\p"
	.string "cartes, les tuiles…\n"
	.string "Amusez-vous bien !$"

CeladonMansion2F_Text_InfiniteBacon:
	.string "Nous travaillons à reconstruire ce jeu\n"
	.string "dans pokeemerald expansion !$"

CeladonMansion2F_Text_TixoRebel:
	.string "Tu as entendu parler de L'ŒUFIFICATION ?\n"
	.string "C'était un bug de la version de test\l"
	.string "qui transformait aléatoirement des POKéMON en\l"
	.string "ŒUFS !\p"
	.string "J'ai développé le correctif !$"

CeladonMansion2F_Text_Phant:
	.string "J'adore les DEMAKES !\p"
	.string "Tu as joué à SWORD AND SHIELD\n"
	.string "ULTIMATE PLUS - ENGLISH ?\l"
	.string "Je l'ai traduit !\p"
	.string "Pour mon prochain DEMAKE, je pense\n"
	.string "que je vais faire ALOLA !$"

CeladonMansion2F_Text_Exclsior:
	.string "J'ai implémenté les sprites de SURF\n"
	.string "uniques pour chaque POKéMON !\p"
	.string "Comme le projet est OPEN SOURCE,\n"
	.string "tu peux ajouter tes propres fonctionnalités aussi !$"

CeladonMansion2F_Text_DaniRaibow:
	.string "Salut ! Je suis assez\p"
	.string "doué pour trouver des problèmes,\n"
	.string "et pour en corriger de\p"
	.string "petits. Tu veux entendre une\p"
	.string "blague ? LANCE a essayé\n"
	.string "d'apprendre DRACOSOUFFLE à DRACOLOSSE. Mais\p"
	.string "DRACOLOSSE allait trop vite avec\n"
	.string "ULTRARAPID ; il n'a pas\l"
	.string "pu le rattraper !$"
