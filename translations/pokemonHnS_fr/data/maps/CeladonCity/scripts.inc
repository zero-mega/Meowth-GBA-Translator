.set LOCALID_CELADON_ERIKA, 15

CeladonCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_EventScript_CityEnter
	.byte 0

CeladonCity_EventScript_CityEnter::
	setflag FLAG_VISITED_CELADON_CITY
	end

CeladonCity_EventScript_Erika::
    lock
    faceplayer
    msgbox CeladonCity_Text_Erika, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_FOUNTAIN_ERIKA
    removeobject LOCALID_CELADON_ERIKA
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_ERIKA
    release
    end

CeladonCity_Text_Erika:
    .string "Oh, {PLAYER}. La fontaine n'est-elle pas\n"
    .string "magnifique aujourd'hui ? Si tu\p"
    .string "veux un autre combat, je\n"
    .string "serai au DOJO DE COMBAT.$"

CeladonCity_EventScript_Fatman::
	msgbox CeladonCity_Text_Fisher, MSGBOX_NPC
	end
CeladonCity_EventScript_Poliwrath::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_POLIWRATH, CRY_MODE_NORMAL
	msgbox CeladonCity_Text_Poliwrath, MSGBOX_DEFAULT
	waitmoncry
	release
	end

CeladonCity_EventScript_Teacher1::
	msgbox CeladonCity_Text_Teacher1, MSGBOX_NPC
	end

CeladonCity_EventScript_GrimerGramps::
	msgbox CeladonCity_Text_Gramps1, MSGBOX_NPC
	end

CeladonCity_EventScript_CreepGramps::
	msgbox CeladonCity_Text_Gramps2, MSGBOX_NPC
	end

CeladonCity_EventScript_Youngster::
	msgbox CeladonCity_Text_Youngster1, MSGBOX_NPC
	end

CeladonCity_EventScript_Youngster2::
	msgbox CeladonCity_Text_Youngster2, MSGBOX_NPC
	end

CeladonCity_EventScript_Teacher2::
	msgbox CeladonCity_Text_Teacher2, MSGBOX_NPC
	end

CeladonCity_EventScript_Lass::
	msgbox CeladonCity_Text_Lass, MSGBOX_NPC
	end

CeladonCity_Text_Fisher:
	.string "Ce TETARTOS est mon partenaire.\p"
	.string "Je me demande s'il évoluera un jour\n"
	.string "en POKéMON grenouille.$"

CeladonCity_Text_Poliwrath:
	.string "TARPAUD : Croak !$"

CeladonCity_Text_Teacher1:
	.string "J'ai encore perdu aux machines à sous...\p"
	.string "Nous les filles, on joue aussi aux machines.\p"
	.string "Tu devrais essayer aussi.$"

CeladonCity_Text_Gramps1:
	.string "Des TADMORV sont apparus récemment.\p"
	.string "Tu vois l'étang devant la maison ?\n"
	.string "Des TADMORV y vivent maintenant.\p"
	.string "D'où viennent-ils ? C'est un\n"
	.string "problème grave…$"

CeladonCity_Text_Gramps2:
	.string "Nihihi ! Cette ARÈNE est géniale !\n"
	.string "Seules les filles sont admises ici !$"

CeladonCity_Text_Youngster1:
	.string "Tu veux connaître un secret ?\p"
	.string "Le MANOIR DE SAFRANIA a une\n"
	.string "porte dérobée.$"

CeladonCity_Text_Youngster2:
	.string "Ils organisent un concours de repas\n"
	.string "au restaurant.\p"
	.string "Rien qu'à les regarder, j'ai l'impression\n"
	.string "d'être rassasié...$"

CeladonCity_Text_Teacher2:
	.string "Le GRAND MAGASIN de CELADON a le plus grand\n"
	.string "choix de marchandises.\p"
	.string "Si tu ne trouves pas ce que tu cherches\n"
	.string "ici, tu ne le trouveras nulle part.\p"
	.string "Oh là là… J'ai l'air d'un vendeur.$"

CeladonCity_Text_Lass:
	.string "En regardant le sol pendant que\n"
	.string "je marchais, j'ai eu le vertige.$"

CeladonCity_EventScript_CitySign::
	msgbox CeladonCity_Text_Sign, MSGBOX_SIGN
	end

CeladonCity_EventScript_GymSign::
	msgbox CeladonGym_Text_Sign, MSGBOX_SIGN
	end

CeladonCity_EventScript_StoreSign::
	msgbox CeladonCity_Text_DeptStoreSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_MansionSign::
	msgbox CeladonCity_Text_MansionSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_GameCornerSign::
	msgbox CeladonCity_Text_GameCornerSign, MSGBOX_SIGN
	end

CeladonCity_EventScript_TrainerTips::
	msgbox CeladonCity_Text_TrainerTips, MSGBOX_SIGN
	end

CeladonCity_Text_Sign:
	.string "CÉLADOPOLE\p"
	.string "La Ville aux Rêves Arc-en-Ciel$"

CeladonGym_Text_Sign:
	.string "SAFRANIA ARENE POKéMON\n"
	.string "CHAMPIONNE : ERIKA\p"
	.string "La Princesse Amoureuse de la Nature$"

CeladonCity_Text_DeptStoreSign:
	.string "Trouvez ce dont vous avez besoin au\n"
	.string "GRAND MAGASIN de CÉLADOPOLE !$"

CeladonCity_Text_MansionSign:
	.string "MANOIR DE SAFRANIA$"

CeladonCity_Text_GameCornerSign:
	.string "Le terrain de jeu pour tous--\n"
	.string "CASINO de CELADOPOLE$"

CeladonCity_Text_TrainerTips:
	.string "CONSEILS DRESSEUR\p"
	.string "DÉF SPÉ. protège les POKéMON\n"
	.string "contre les attaques SPÉCIALES comme\n"
	.string "le feu et l'eau.\p"
	.string "Va acheter tes objets au GRAND MAGASIN\n"
	.string "de CELADOPOLIS !$"
