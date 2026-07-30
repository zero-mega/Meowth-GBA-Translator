BattleFrontier_Lounge9_MapScripts::
	.byte 0

BattleFrontier_Lounge9_Heal::
	specialvar VAR_RESULT, IsPokecenterChallengeActivated
	goto_if_eq VAR_RESULT, TRUE, SSTidalRooms_EventScript_Bed_PokecenterChallenge
	msgbox BattleFrontier_Lounge9_Heal_TEXT, MSGBOX_NPC
	waitmessage
	fadescreen 0x1
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	fadescreen 0x0
	msgbox BattleFrontier_Lounge9_Heal_TEXT2, MSGBOX_NPC
	waitmessage
	release
	end

BattleFrontier_Lounge9_Heal_TEXT:
	.string "Salut ! Bienvenue au DOJO D'ENTRAÎNEMENT !\n"
	.string "Je vais soigner tes POKéMON.$"

BattleFrontier_Lounge9_Heal_TEXT2:
	.string "Nous espérons te revoir bientôt !$"

BattleFrontier_Lounge9_EV_No:
	msgbox BattleFrontier_Lounge9_EV_No_TEXT, MSGBOX_DEFAULT
	waitmessage
	release
	end

@EV Gym

BattleFrontier_Lounge9_EV_HP::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge9_EV_HP_TEXT, MSGBOX_YESNO
	waitmessage
	compare VAR_RESULT, YES
	goto_if_eq BattleFrontier_Lounge9_EV_HP_Yes
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_Lounge9_EV_No
	end

BattleFrontier_Lounge9_EV_HP_Yes::
	msgbox BattleFrontier_Lounge9_EV_HP_TEXT2, MSGBOX_DEFAULT
	waitmessage
	setflag FLAG_SYS_NO_CATCHING
	setflag FLAG_NO_SHINY
	setwildbattle SPECIES_WAILORD, 1, ITEM_NONE
	dowildbattle
	clearflag FLAG_SYS_NO_CATCHING
	clearflag FLAG_NO_SHINY
	release
	end
	
BattleFrontier_Lounge9_EV_ATK::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge9_EV_ATK_TEXT, MSGBOX_YESNO
	waitmessage
	compare VAR_RESULT, YES
	goto_if_eq BattleFrontier_Lounge9_EV_ATK_Yes
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_Lounge9_EV_No
	end

BattleFrontier_Lounge9_EV_ATK_Yes::
	msgbox BattleFrontier_Lounge9_EV_ATK_TEXT2, MSGBOX_DEFAULT
	waitmessage
	setflag FLAG_SYS_NO_CATCHING
	setflag FLAG_NO_SHINY
	setwildbattle SPECIES_GALLADE, 1, ITEM_NONE
	dowildbattle
	clearflag FLAG_SYS_NO_CATCHING
	clearflag FLAG_NO_SHINY
	release
	end

BattleFrontier_Lounge9_EV_SATK::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge9_EV_SATK_TEXT, MSGBOX_YESNO
	waitmessage
	compare VAR_RESULT, YES
	goto_if_eq BattleFrontier_Lounge9_EV_SATK_Yes
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_Lounge9_EV_No
	end

BattleFrontier_Lounge9_EV_SATK_Yes::
	msgbox BattleFrontier_Lounge9_EV_SATK_TEXT2, MSGBOX_DEFAULT
	waitmessage
	setflag FLAG_SYS_NO_CATCHING
	setflag FLAG_NO_SHINY
	setwildbattle SPECIES_GARDEVOIR, 1, ITEM_NONE
	dowildbattle
	clearflag FLAG_SYS_NO_CATCHING
	clearflag FLAG_NO_SHINY
	release
	end

BattleFrontier_Lounge9_EV_DEF::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge9_EV_DEF_TEXT, MSGBOX_YESNO
	waitmessage
	compare VAR_RESULT, YES
	goto_if_eq BattleFrontier_Lounge9_EV_DEF_Yes
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_Lounge9_EV_No
	end

BattleFrontier_Lounge9_EV_DEF_Yes::
	msgbox BattleFrontier_Lounge9_EV_DEF_TEXT2, MSGBOX_DEFAULT
	waitmessage
	setflag FLAG_SYS_NO_CATCHING
	setflag FLAG_NO_SHINY
	setwildbattle SPECIES_AGGRON, 1, ITEM_NONE
	dowildbattle
	clearflag FLAG_SYS_NO_CATCHING
	clearflag FLAG_NO_SHINY
	release
	end

BattleFrontier_Lounge9_EV_SDEF::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge9_EV_SDEF_TEXT, MSGBOX_YESNO
	waitmessage
	compare VAR_RESULT, YES
	goto_if_eq BattleFrontier_Lounge9_EV_SDEF_Yes
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_Lounge9_EV_No
	end

BattleFrontier_Lounge9_EV_SDEF_Yes::
	msgbox BattleFrontier_Lounge9_EV_SDEF_TEXT2, MSGBOX_DEFAULT
	waitmessage
	setflag FLAG_SYS_NO_CATCHING
	setflag FLAG_NO_SHINY
	setwildbattle SPECIES_LUDICOLO, 1, ITEM_NONE
	dowildbattle
	clearflag FLAG_SYS_NO_CATCHING
	clearflag FLAG_NO_SHINY
	release
	end

BattleFrontier_Lounge9_EV_SPD::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge9_EV_SPD_TEXT, MSGBOX_YESNO
	waitmessage
	compare VAR_RESULT, YES
	goto_if_eq BattleFrontier_Lounge9_EV_SPD_Yes
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_Lounge9_EV_No
	end

BattleFrontier_Lounge9_EV_SPD_Yes::
	msgbox BattleFrontier_Lounge9_EV_SPD_TEXT2, MSGBOX_DEFAULT
	waitmessage
	setflag FLAG_SYS_NO_CATCHING
	setflag FLAG_NO_SHINY
	setwildbattle SPECIES_SCEPTILE, 1, ITEM_NONE
	dowildbattle
	clearflag FLAG_SYS_NO_CATCHING
	clearflag FLAG_NO_SHINY
	release
	end

BattleFrontier_Lounge9_EV_HP_TEXT:
	.string "Salut l'ami ! Je peux entraîner tes\n"
	.string "POKéMON en POINTS DE VIE.\p"
	.string "Tu es prêt ?$"

BattleFrontier_Lounge9_EV_HP_TEXT2:
	.string "En avant WAILORD !$"

BattleFrontier_Lounge9_EV_ATK_TEXT:
	.string "OSHA ! Je peux entraîner ton POKéMON\n"
	.string "en ATTAQUE.\p"
	.string "Tu es prêt ?$"

BattleFrontier_Lounge9_EV_ATK_TEXT2:
	.string "En avant GALLAME !$"

BattleFrontier_Lounge9_EV_SATK_TEXT:
	.string "Bonjour ! Je peux entraîner tes POKéMON\n"
	.string "en ATTAQUE SPÉCIALE.\p"
	.string "Tu es prêt ?$"

BattleFrontier_Lounge9_EV_SATK_TEXT2:
	.string "En avant GARDEVOIR !$"
	
BattleFrontier_Lounge9_EV_DEF_TEXT:
	.string "Salut, gamin ! Je peux entraîner tes\n"
	.string "POKéMON en DÉFENSE.\p"
	.string "Tu es prêt ?$"

BattleFrontier_Lounge9_EV_DEF_TEXT2:
	.string "En avant, GALEKING !$"

BattleFrontier_Lounge9_EV_SDEF_TEXT:
	.string "Bonjour mon dresseur ! Je peux entraîner tes\n"
	.string "POKéMON en DEF. SPÉ.\p"
	.string "Es-tu prêt ?$"

BattleFrontier_Lounge9_EV_SDEF_TEXT2:
	.string "En avant LUDICOLO !$"

BattleFrontier_Lounge9_EV_SPD_TEXT:
	.string "Hmph… Je peux entraîner ton\n"
	.string "POKéMON en VITESSE.\p"
	.string "Tu es prêt ?$"

BattleFrontier_Lounge9_EV_SPD_TEXT2:
	.string "En avant JUNGKO !$"

BattleFrontier_Lounge9_EV_No_TEXT:
	.string "Non ? OK.$"

@Columns text

BattleFrontier_Lounge9_EV_Column::
	msgbox BattleFrontier_Lounge9_EV_Column_Text, MSGBOX_SIGN
	end

BattleFrontier_Lounge9_EV_Column_Text:
    .string "Bienvenue au DOJO D'ENTRAÎNEMENT !\p"
    .string "Ici, tu trouveras divers types\n"
    .string "d'entraînement pour améliorer les STATS des POKéMON.\p"
    .string "RÉINITIALISATION EV :\n"
    .string "EV-MAN peut remettre les EV d'un POKéMON à\l"
    .string "zéro. Il est dans la colonne de droite.\p"
    .string "ENTRAÎNEMENT EV :\n"
    .string "Six dresseurs se concentrent sur chaque STAT, de\l"
    .string "gauche à droite : DEF - ATK - PV - VIT -\l"
    .string "ATQ.SPÉ - DÉF.SPÉ.\p"
    .string "ASTUCE : un BRACELET MACHO multiplie les EV\n"
    .string "gagnés par 5 !\p"
    .string "Après être devenu CHAMPION de HOENN,\n"
    .string "tu débloques les options suivantes :\p"
    .string "ENTRAÎNEMENT IV & FORCE CACHÉE :\n"
    .string "IV-MAN entraîne les POKéMON pour maximiser les IV.\l"
    .string "Il peut aussi ajuster les IV pour changer le\l"
    .string "type de FORCE CACHÉE.\p"
    .string "ENTRAÎNEMENT EXPÉRIENCE :\n"
    .string "L'INFIRMIÈRE EXPÉRIENCE en bas à\l"
    .string "gauche propose un entraînement pour ton équipe.\p"
    .string "ÉCHANGEUR DE TALENT :\n"
    .string "L'EXPERT TALENT en haut à gauche peut\l"
    .string "échanger entre les talents qu'un POKéMON\l"
    .string "peut avoir naturellement.$"

@EV RESET

BattleFrontier_Lounge9_EV_SetZero::
	lockall
	faceplayer
	goto_if_unset FLAG_EV_MAN_FIRSTIME, BattleFrontier_Lounge9_EV_SetZeroIntro
	msgbox BattleFrontier_Lounge9_EV_SetZeroTextNoIntro, MSGBOX_YESNO
	waitmessage
	compare VAR_RESULT, YES
	goto_if_eq BattleFrontier_Lounge9_EV_SetZeroMoney
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_Lounge9_EV_SetZeroNo
	end

BattleFrontier_Lounge9_EV_SetZeroIntro::
	setflag FLAG_EV_MAN_FIRSTIME
	msgbox BattleFrontier_Lounge9_EV_SetZeroText, MSGBOX_NPC
	waitmessage
	end

BattleFrontier_Lounge9_EV_SetZeroMoney::
	msgbox BattleFrontier_Lounge9_EV_SetZeroMoneyText, MSGBOX_YESNO
	waitmessage
	compare VAR_RESULT, YES
	goto_if_eq BattleFrontier_Lounge9_EV_SetZeroCheckMoney
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_Lounge9_EV_SetZeroNo
	end

BattleFrontier_Lounge9_EV_SetZeroCheckMoney::
	checkmoney 20000, 0
	compare VAR_RESULT, TRUE
	goto_if_eq BattleFrontier_Lounge9_EV_SetZeroYes
	compare VAR_RESULT, FALSE
	goto_if_eq BattleFrontier_Lounge9_EV_SetZeroNoMoney
	end

BattleFrontier_Lounge9_EV_SetZeroYes::
	msgbox BattleFrontier_Lounge9_EV_SetZeroText2, MSGBOX_DEFAULT
	waitmessage
	closemessage
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, PARTY_SIZE
	goto_if_ge BattleFrontier_Lounge9_EV_SetZeroNo
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_EGG
	goto_if_eq BattleFrontier_Lounge9_EV_SetZeroEgg
	goto BattleFrontier_Lounge9_EV_SetZeroSure
	end

BattleFrontier_Lounge9_EV_SetZeroNo::
	msgbox BattleFrontier_Lounge9_EV_SetZeroTextNo, MSGBOX_DEFAULT
	waitmessage
	releaseall
	end

BattleFrontier_Lounge9_EV_SetZeroNoMoney::
	msgbox BattleFrontier_Lounge9_EV_SetZeroTextNoMoney, MSGBOX_DEFAULT
	waitmessage
	releaseall
	end

BattleFrontier_Lounge9_EV_SetZeroEgg::
	msgbox BattleFrontier_Lounge9_EV_SetZeroTextEgg, MSGBOX_DEFAULT
	waitmessage
	releaseall
	end

BattleFrontier_Lounge9_EV_SetZeroSure::
	faceplayer
	msgbox BattleFrontier_Lounge9_EV_SetZeroTextSure, MSGBOX_YESNO
	waitmessage
	compare VAR_RESULT, YES
	goto_if_eq BattleFrontier_Lounge9_EV_SetZeroProceed
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_Lounge9_EV_SetZeroNo
	end

BattleFrontier_Lounge9_EV_SetZeroProceed::
	faceplayer
	fadescreen 0x1
	delay 30
	removemoney 20000, 0
	fadescreen 0x0
	setvar VAR_0x8000, 0
	setvar VAR_0x8001, 0
	setvar VAR_0x8002, 0
	setvar VAR_0x8003, 0
	setvar VAR_0x8005, 0
	setvar VAR_0x8006, 0
	special SetHpEvs
	special SetAtkEvs
	special SetDefEvs
	special SetSpdEvs
	special SetSpAtkEvs
	special SetSpDefEvs
	msgbox BattleFrontier_Lounge9_EV_SetZeroText3, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BattleFrontier_Lounge9_EV_SetZeroText:
    .string "Salutations, dresseur. Je m'appelle\n"
    .string "EVAN, mais on m'appelle souvent\n"
    .string "EV-MAN.\p"
    .string "Je suis le propriétaire de cet\n"
    .string "établissement, où j'effectue\n"
    .string "l'entraînement avec mon frère, IVAN.\p"
    .string "Si tu souhaites remettre à zéro\n"
    .string "les EV d'un POKéMON, parle-moi.$"

BattleFrontier_Lounge9_EV_SetZeroTextNoIntro:
    .string "EV-MAN : Bon retour.\n"
    .string "Veux-tu que je remette à zéro tous tes\l"
    .string "POINTS D'EFFORT de POKéMON ?$"

BattleFrontier_Lounge9_EV_SetZeroText2:
	.string "Quels EV de POKéMON dois-je\n"
	.string "remettre à zéro ?$"

BattleFrontier_Lounge9_EV_SetZeroText3:
    .string "Ouf ! C'était dur, mais j'ai réussi !\n"
    .string "Tous ses PE ont été remis à zéro !$"

BattleFrontier_Lounge9_EV_SetZeroTextEgg:
	.string "Désolé, ça ne marchera pas.$"

BattleFrontier_Lounge9_EV_SetZeroTextNo:
	.string "Reviens si tu en as besoin !$"

BattleFrontier_Lounge9_EV_SetZeroMoneyText:
    .string "Ce processus est assez difficile.\n"
    .string "Il coûtera 20 000¥.\l"
    .string "Veux-tu continuer ?$"

BattleFrontier_Lounge9_EV_SetZeroTextNoMoney:
    .string "Tu n'as pas assez d'argent.\p"
    .string "Reviens quand tu en auras.$"

BattleFrontier_Lounge9_EV_SetZeroTextSure:
    .string "Es-tu sûr de vouloir remettre à zéro\n"
    .string "les PE de ce POKéMON ?\p"
    .string "Ce processus est irréversible.$"

@IV setter to 31 (all of them) &&&& HIDDEN POWER Type selector

BattleFrontier_Lounge9_IV_Man::
	checkflag FLAG_IV_SETTER
	lockall
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, BattleFrontier_Lounge9_IV_ManNoChampion
	call_if_unset FLAG_IV_SETTER, BattleFrontier_Lounge9_IV_First_Time
	msgbox BattleFrontier_Lounge9_IV_Text1, MSGBOX_YESNO
	waitmessage
	compare VAR_RESULT, YES
	goto_if_eq BattleFrontier_Lounge9_IV_CheckMoney
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_Lounge9_IV_No
	end

BattleFrontier_Lounge9_IV_ManNoChampion::
	msgbox BattleFrontier_Lounge9_IV_TextNoChampion, MSGBOX_NPC
	releaseall
	end

BattleFrontier_Lounge9_IV_First_Time::
	msgbox BattleFrontier_Lounge9_IV_TextFirstTime, MSGBOX_NPC
	setflag FLAG_IV_SETTER
	releaseall
	end

BattleFrontier_Lounge9_IV_No::
	msgbox BattleFrontier_Lounge9_IV_Text_No, MSGBOX_DEFAULT
	waitmessage
	releaseall
	end

BattleFrontier_Lounge9_IV_NoLevel::
	msgbox BattleFrontier_Lounge9_IV_Text_NoLevel, MSGBOX_DEFAULT
	waitmessage
	releaseall
	end

BattleFrontier_Lounge9_IV_CheckMoney::
	checkmoney 100000, 0
	compare VAR_RESULT, TRUE
	goto_if_eq BattleFrontier_Lounge9_IV_ChoosePkm
	compare VAR_RESULT, FALSE
	goto_if_eq BattleFrontier_Lounge9_EV_SetZeroNoMoney
	end

BattleFrontier_Lounge9_IV_ChoosePkm::
	faceplayer
	closemessage
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, PARTY_SIZE
	goto_if_ge BattleFrontier_Lounge9_IV_No
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	compare VAR_RESULT, SPECIES_EGG
	goto_if_eq BattleFrontier_Lounge9_EV_SetZeroEgg
	goto BattleFrontier_Lounge9_IV_CheckIfLvlMax
	end

BattleFrontier_Lounge9_IV_CheckIfLvlMax::
	faceplayer
	waitmessage
	checkpartymonlevel 100
	compare VAR_RESULT, TRUE
	goto_if_eq BattleFrontier_Lounge9_IV_Continue_Question_CustomOrMax
	compare VAR_RESULT, FALSE
	goto_if_eq BattleFrontier_Lounge9_IV_NoLevel
	releaseall
	end

BattleFrontier_Lounge9_IV_Continue_Question_CustomOrMax::
	faceplayer
	msgbox BattleFrontier_Lounge9_IV_Text_CustomizeIVs, MSGBOX_DEFAULT
	waitmessage
	dynmultichoice 20, 8, FALSE, 2, 0, DYN_MULTICHOICE_CB_NONE, EventScript_IVSetter_Text_CustomizeIVs, EventScript_IVSetter_Text_SetMax
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge9_IV_CustomizeIVs_SelectType
	case 1, BattleFrontier_Lounge9_IV_SetMax
	case MULTI_B_PRESSED, BattleFrontier_Lounge9_IV_No
	closemessage
	release
	end

EventScript_IVSetter_Text_CustomizeIVs:
	.string "PERSONNALISER$"

EventScript_IVSetter_Text_SetMax:
	.string "AU MAX$"

BattleFrontier_Lounge9_IV_SetMax::
	faceplayer
	fadescreen 0x1
	delay 100
	removemoney 100000, 0
	fadescreen 0x0
	faceplayer
	setvar VAR_0x8007, 31
	setvar VAR_0x8008, 31
	setvar VAR_0x8009, 31
	setvar VAR_0x800A, 31
	setvar VAR_0x800B, 31
	setvar VAR_UNUSED_0x8014, 31
	special SetHpIvs
	special SetAtkIvs
	special SetDefIvs
	special SetSpdIvs
	special SetSpAtkIvs
	special SetSpDefIvs
	msgbox BattleFrontier_Lounge9_IV_Finish, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BattleFrontier_Lounge9_IV_CustomizeIVs_SelectType:
	msgbox BattleFrontier_Lounge9_IV_Text_CustomizeIVs_SetType, MSGBOX_DEFAULT
	dynmultichoice 0, 0, FALSE, 6, 0, DYN_MULTICHOICE_CB_NONE, EventScript_IVSetter_Type_Fighting, EventScript_IVSetter_Type_Flying, EventScript_IVSetter_Type_Poison, EventScript_IVSetter_Type_Ground, EventScript_IVSetter_Type_Rock, EventScript_IVSetter_Type_Bug, EventScript_IVSetter_Type_Ghost, EventScript_IVSetter_Type_Steel, EventScript_IVSetter_Type_Fairy, EventScript_IVSetter_Type_Fire, EventScript_IVSetter_Type_Water, EventScript_IVSetter_Type_Grass, EventScript_IVSetter_Type_Electric, EventScript_IVSetter_Type_Psychic, EventScript_IVSetter_Type_Ice, EventScript_IVSetter_Type_Dragon, EventScript_IVSetter_Type_Dark 
	switch VAR_RESULT
	case 0, BattleFrontier_Lounge9_MultichoiceIVs_SetType_Fighting
	case 1, BattleFrontier_Lounge9_MultichoiceIVs_SetType_Flying
	case 2, BattleFrontier_Lounge9_MultichoiceIVs_SetType_Poison
	case 3, BattleFrontier_Lounge9_MultichoiceIVs_SetType_Ground
	case 4, BattleFrontier_Lounge9_MultichoiceIVs_SetType_Rock
	case 5, BattleFrontier_Lounge9_MultichoiceIVs_SetType_Bug
	case 6, BattleFrontier_Lounge9_MultichoiceIVs_SetType_Ghost
	case 7, BattleFrontier_Lounge9_MultichoiceIVs_SetType_Steel
	case 8, BattleFrontier_Lounge9_MultichoiceIVs_SetType_Fairy
	case 9, BattleFrontier_Lounge9_MultichoiceIVs_SetType_Fire
	case 10, BattleFrontier_Lounge9_MultichoiceIVs_SetType_Water
	case 11, BattleFrontier_Lounge9_MultichoiceIVs_SetType_Grass
	case 12, BattleFrontier_Lounge9_MultichoiceIVs_SetType_Electric
	case 13, BattleFrontier_Lounge9_MultichoiceIVs_SetType_Psychic
	case 14, BattleFrontier_Lounge9_MultichoiceIVs_SetType_Ice
	case 15, BattleFrontier_Lounge9_MultichoiceIVs_SetType_Dragon
	case 16, BattleFrontier_Lounge9_MultichoiceIVs_SetType_Dark
	closemessage
	release
	end

BattleFrontier_Lounge9_MultichoiceIVs_SetType_Fighting::
	faceplayer
	fadescreen 0x1
	delay 100
	removemoney 100000, 0
	fadescreen 0x0
	faceplayer
	setvar VAR_0x8007, 31 @HP
	setvar VAR_0x8008, 31 @ATK
	setvar VAR_0x8009, 30 @DEF
	setvar VAR_0x800B, 30 @SP. ATK
	setvar VAR_UNUSED_0x8014, 30 @SP. DEF
	setvar VAR_0x800A, 30 @SPD
	special SetHpIvs
	special SetAtkIvs
	special SetDefIvs
	special SetSpAtkIvs
	special SetSpDefIvs
	special SetSpdIvs
	msgbox BattleFrontier_Lounge9_IV_Finish, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BattleFrontier_Lounge9_MultichoiceIVs_SetType_Flying::
	faceplayer
	fadescreen 0x1
	delay 100
	removemoney 100000, 0
	fadescreen 0x0
	faceplayer
	setvar VAR_0x8007, 31 @HP
	setvar VAR_0x8008, 31 @ATK
	setvar VAR_0x8009, 31 @DEF
	setvar VAR_0x800B, 30 @SP. ATK
	setvar VAR_UNUSED_0x8014, 30 @SP. DEF
	setvar VAR_0x800A, 30 @SPD
	special SetHpIvs
	special SetAtkIvs
	special SetDefIvs
	special SetSpAtkIvs
	special SetSpDefIvs
	special SetSpdIvs
	msgbox BattleFrontier_Lounge9_IV_Finish, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BattleFrontier_Lounge9_MultichoiceIVs_SetType_Poison::
	faceplayer
	fadescreen 0x1
	delay 100
	removemoney 100000, 0
	fadescreen 0x0
	faceplayer
	setvar VAR_0x8007, 31 @HP
	setvar VAR_0x8008, 31 @ATK
	setvar VAR_0x8009, 30 @DEF
	setvar VAR_0x800B, 30 @SP. ATK
	setvar VAR_UNUSED_0x8014, 30 @SP. DEF
	setvar VAR_0x800A, 31 @SPD
	special SetHpIvs
	special SetAtkIvs
	special SetDefIvs
	special SetSpAtkIvs
	special SetSpDefIvs
	special SetSpdIvs
	msgbox BattleFrontier_Lounge9_IV_Finish, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BattleFrontier_Lounge9_MultichoiceIVs_SetType_Ground::
	faceplayer
	fadescreen 0x1
	delay 100
	removemoney 100000, 0
	fadescreen 0x0
	faceplayer
	setvar VAR_0x8007, 31 @HP
	setvar VAR_0x8008, 31 @ATK
	setvar VAR_0x8009, 31 @DEF
	setvar VAR_0x800B, 30 @SP. ATK
	setvar VAR_UNUSED_0x8014, 30 @SP. DEF
	setvar VAR_0x800A, 31 @SPD
	special SetHpIvs
	special SetAtkIvs
	special SetDefIvs
	special SetSpAtkIvs
	special SetSpDefIvs
	special SetSpdIvs
	msgbox BattleFrontier_Lounge9_IV_Finish, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BattleFrontier_Lounge9_MultichoiceIVs_SetType_Rock::
	faceplayer
	fadescreen 0x1
	delay 100
	removemoney 100000, 0
	fadescreen 0x0
	faceplayer
	setvar VAR_0x8007, 31 @HP
	setvar VAR_0x8008, 31 @ATK
	setvar VAR_0x8009, 30 @DEF
	setvar VAR_0x800B, 31 @SP. ATK
	setvar VAR_UNUSED_0x8014, 30 @SP. DEF
	setvar VAR_0x800A, 30 @SPD
	special SetHpIvs
	special SetAtkIvs
	special SetDefIvs
	special SetSpAtkIvs
	special SetSpDefIvs
	special SetSpdIvs
	msgbox BattleFrontier_Lounge9_IV_Finish, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BattleFrontier_Lounge9_MultichoiceIVs_SetType_Bug::
	faceplayer
	fadescreen 0x1
	delay 100
	removemoney 100000, 0
	fadescreen 0x0
	faceplayer
	setvar VAR_0x8007, 31 @HP
	setvar VAR_0x8008, 31 @ATK
	setvar VAR_0x8009, 31 @DEF
	setvar VAR_0x800B, 31 @SP. ATK
	setvar VAR_UNUSED_0x8014, 30 @SP. DEF
	setvar VAR_0x800A, 30 @SPD
	special SetHpIvs
	special SetAtkIvs
	special SetDefIvs
	special SetSpAtkIvs
	special SetSpDefIvs
	special SetSpdIvs
	msgbox BattleFrontier_Lounge9_IV_Finish, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BattleFrontier_Lounge9_MultichoiceIVs_SetType_Ghost::
	faceplayer
	fadescreen 0x1
	delay 100
	removemoney 100000, 0
	fadescreen 0x0
	faceplayer
	setvar VAR_0x8007, 31 @HP
	setvar VAR_0x8008, 31 @ATK
	setvar VAR_0x8009, 30 @DEF
	setvar VAR_0x800B, 31 @SP. ATK
	setvar VAR_UNUSED_0x8014, 30 @SP. DEF
	setvar VAR_0x800A, 31 @SPD
	special SetHpIvs
	special SetAtkIvs
	special SetDefIvs
	special SetSpAtkIvs
	special SetSpDefIvs
	special SetSpdIvs
	msgbox BattleFrontier_Lounge9_IV_Finish, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BattleFrontier_Lounge9_MultichoiceIVs_SetType_Steel::
	faceplayer
	fadescreen 0x1
	delay 100
	removemoney 100000, 0
	fadescreen 0x0
	faceplayer
	setvar VAR_0x8007, 31 @HP
	setvar VAR_0x8008, 31 @ATK
	setvar VAR_0x8009, 31 @DEF
	setvar VAR_0x800B, 31 @SP. ATK
	setvar VAR_UNUSED_0x8014, 30 @SP. DEF
	setvar VAR_0x800A, 31 @SPD
	special SetHpIvs
	special SetAtkIvs
	special SetDefIvs
	special SetSpAtkIvs
	special SetSpDefIvs
	special SetSpdIvs
	msgbox BattleFrontier_Lounge9_IV_Finish, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BattleFrontier_Lounge9_MultichoiceIVs_SetType_Fairy::
	faceplayer
	fadescreen 0x1
	delay 100
	removemoney 100000, 0
	fadescreen 0x0
	faceplayer
	setvar VAR_0x8007, 30 @HP
	setvar VAR_0x8008, 31 @ATK
	setvar VAR_0x8009, 30 @DEF
	setvar VAR_0x800B, 30 @SP. ATK
	setvar VAR_UNUSED_0x8014, 31 @SP. DEF
	setvar VAR_0x800A, 30 @SPD
	special SetHpIvs
	special SetAtkIvs
	special SetDefIvs
	special SetSpAtkIvs
	special SetSpDefIvs
	special SetSpdIvs
	msgbox BattleFrontier_Lounge9_IV_Finish, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BattleFrontier_Lounge9_MultichoiceIVs_SetType_Fire::
	faceplayer
	fadescreen 0x1
	delay 100
	removemoney 100000, 0
	fadescreen 0x0
	faceplayer
	setvar VAR_0x8007, 31 @HP
	setvar VAR_0x8008, 30 @ATK
	setvar VAR_0x8009, 31 @DEF
	setvar VAR_0x800B, 30 @SP. ATK
	setvar VAR_UNUSED_0x8014, 31 @SP. DEF
	setvar VAR_0x800A, 30 @SPD
	special SetHpIvs
	special SetAtkIvs
	special SetDefIvs
	special SetSpAtkIvs
	special SetSpDefIvs
	special SetSpdIvs
	msgbox BattleFrontier_Lounge9_IV_Finish, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BattleFrontier_Lounge9_MultichoiceIVs_SetType_Water::
	faceplayer
	fadescreen 0x1
	delay 100
	removemoney 100000, 0
	fadescreen 0x0
	faceplayer
	setvar VAR_0x8007, 31 @HP
	setvar VAR_0x8008, 31 @ATK
	setvar VAR_0x8009, 30 @DEF
	setvar VAR_0x800B, 30 @SP. ATK
	setvar VAR_UNUSED_0x8014, 31 @SP. DEF
	setvar VAR_0x800A, 31 @SPD
	special SetHpIvs
	special SetAtkIvs
	special SetDefIvs
	special SetSpAtkIvs
	special SetSpDefIvs
	special SetSpdIvs
	msgbox BattleFrontier_Lounge9_IV_Finish, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BattleFrontier_Lounge9_MultichoiceIVs_SetType_Grass::
	faceplayer
	fadescreen 0x1
	delay 100
	removemoney 100000, 0
	fadescreen 0x0
	faceplayer
	setvar VAR_0x8007, 31 @HP
	setvar VAR_0x8008, 31 @ATK
	setvar VAR_0x8009, 31 @DEF
	setvar VAR_0x800B, 30 @SP. ATK
	setvar VAR_UNUSED_0x8014, 31 @SP. DEF
	setvar VAR_0x800A, 31 @SPD
	special SetHpIvs
	special SetAtkIvs
	special SetDefIvs
	special SetSpAtkIvs
	special SetSpDefIvs
	special SetSpdIvs
	msgbox BattleFrontier_Lounge9_IV_Finish, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BattleFrontier_Lounge9_MultichoiceIVs_SetType_Electric::
	faceplayer
	fadescreen 0x1
	delay 100
	removemoney 100000, 0
	fadescreen 0x0
	faceplayer
	setvar VAR_0x8007, 30 @HP
	setvar VAR_0x8008, 30 @ATK
	setvar VAR_0x8009, 30 @DEF
	setvar VAR_0x800B, 31 @SP. ATK
	setvar VAR_UNUSED_0x8014, 31 @SP. DEF
	setvar VAR_0x800A, 30 @SPD
	special SetHpIvs
	special SetAtkIvs
	special SetDefIvs
	special SetSpAtkIvs
	special SetSpDefIvs
	special SetSpdIvs
	msgbox BattleFrontier_Lounge9_IV_Finish, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BattleFrontier_Lounge9_MultichoiceIVs_SetType_Psychic::
	faceplayer
	fadescreen 0x1
	delay 100
	removemoney 100000, 0
	fadescreen 0x0
	faceplayer
	setvar VAR_0x8007, 30 @HP
	setvar VAR_0x8008, 30 @ATK
	setvar VAR_0x8009, 31 @DEF
	setvar VAR_0x800B, 31 @SP. ATK
	setvar VAR_UNUSED_0x8014, 31 @SP. DEF
	setvar VAR_0x800A, 30 @SPD
	special SetHpIvs
	special SetAtkIvs
	special SetDefIvs
	special SetSpAtkIvs
	special SetSpDefIvs
	special SetSpdIvs
	msgbox BattleFrontier_Lounge9_IV_Finish, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BattleFrontier_Lounge9_MultichoiceIVs_SetType_Ice::
	faceplayer
	fadescreen 0x1
	delay 100
	removemoney 100000, 0
	fadescreen 0x0
	faceplayer
	setvar VAR_0x8007, 30 @HP
	setvar VAR_0x8008, 30 @ATK
	setvar VAR_0x8009, 30 @DEF
	setvar VAR_0x800B, 31 @SP. ATK
	setvar VAR_UNUSED_0x8014, 31 @SP. DEF
	setvar VAR_0x800A, 31 @SPD
	special SetHpIvs
	special SetAtkIvs
	special SetDefIvs
	special SetSpAtkIvs
	special SetSpDefIvs
	special SetSpdIvs
	msgbox BattleFrontier_Lounge9_IV_Finish, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BattleFrontier_Lounge9_MultichoiceIVs_SetType_Dragon::
	faceplayer
	fadescreen 0x1
	delay 100
	removemoney 100000, 0
	fadescreen 0x0
	faceplayer
	setvar VAR_0x8007, 30 @HP
	setvar VAR_0x8008, 30 @ATK
	setvar VAR_0x8009, 31 @DEF
	setvar VAR_0x800B, 31 @SP. ATK
	setvar VAR_UNUSED_0x8014, 31 @SP. DEF
	setvar VAR_0x800A, 31 @SPD
	special SetHpIvs
	special SetAtkIvs
	special SetDefIvs
	special SetSpAtkIvs
	special SetSpDefIvs
	special SetSpdIvs
	msgbox BattleFrontier_Lounge9_IV_Finish, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BattleFrontier_Lounge9_MultichoiceIVs_SetType_Dark::
	faceplayer
	fadescreen 0x1
	delay 100
	removemoney 100000, 0
	fadescreen 0x0
	faceplayer
	setvar VAR_0x8007, 31 @HP
	setvar VAR_0x8008, 31 @ATK
	setvar VAR_0x8009, 31 @DEF
	setvar VAR_0x800B, 31 @SP. ATK
	setvar VAR_UNUSED_0x8014, 31 @SP. DEF
	setvar VAR_0x800A, 31 @SPD
	special SetHpIvs
	special SetAtkIvs
	special SetDefIvs
	special SetSpAtkIvs
	special SetSpDefIvs
	special SetSpdIvs
	msgbox BattleFrontier_Lounge9_IV_Finish, MSGBOX_DEFAULT
	closemessage
	releaseall
	end

BattleFrontier_Lounge9_IV_TextNoChampion:
	.string "Hmm ? Quoi ?\p"
	.string "Oh, tu es un dresseur. Mais pas un que\n"
	.string "je qualifierais de fort…\p"
	.string "Bats la LIGUE POKéMON et\n"
	.string "reviens me voir.\p"
	.string "Je te montrerai l'entraînement\n"
	.string "le plus intense de la région !$"

BattleFrontier_Lounge9_IV_Text_CustomizeIVs:
	.string "Voulez-vous définir les IV à une valeur\n"
	.string "précise pour obtenir différents types de\l"
	.string "FORCE CACHÉE ? Ou dois-je mettre\p"
	.string "tous les IV à 31 ?$"

BattleFrontier_Lounge9_IV_Text_CustomizeIVs_SetType:
	.string "Quel type de FORCE CACHEE\n"
	.string "cherches-tu ?$"

EventScript_IVSetter_Type_Fighting:
	.string "TYPE COMBAT$"

EventScript_IVSetter_Type_Flying:
	.string "TYPE VOL$"

EventScript_IVSetter_Type_Poison:
	.string "TYPE POISON$"

EventScript_IVSetter_Type_Ground:
	.string "TYPE SOL$"

EventScript_IVSetter_Type_Rock:
	.string "TYPE ROCHE$"

EventScript_IVSetter_Type_Bug:
	.string "TYPE INSECTE$"

EventScript_IVSetter_Type_Ghost:
	.string "TYPE SPECTRE$"

EventScript_IVSetter_Type_Steel:
	.string "TYPE ACIER$"

EventScript_IVSetter_Type_Fairy:
	.string "TYPE FÉE$"

EventScript_IVSetter_Type_Fire:
	.string "TYPE FEU$"

EventScript_IVSetter_Type_Water:
	.string "TYPE EAU$"

EventScript_IVSetter_Type_Grass:
	.string "TYPE PLANTE$"

EventScript_IVSetter_Type_Electric:
	.string "TYPE ÉLECTRIK$"

EventScript_IVSetter_Type_Psychic:
	.string "TYPE PSY$"

EventScript_IVSetter_Type_Ice:
	.string "TYPE GLACE$"

EventScript_IVSetter_Type_Dragon:
	.string "TYPE DRAGON$"

EventScript_IVSetter_Type_Dark:
	.string "TYPE TÉNÈBRES$"

BattleFrontier_Lounge9_IV_Text_SetMaxQuestion:
	.string "Ensuite, je mettrai tous les IV au maximum,\n"
	.string "soit 31. Dois-je continuer ?$"

BattleFrontier_Lounge9_IV_TextFirstTime:
    .string "Hé ! C'est toi ! Super de\n"
    .string "te voir par ici !\p"
    .string "Attends… Tu ne me connais pas ?\p"
    .string ". . .\p"
    .string ". . .\p"
    .string "Oh, c'est vrai ! Je t'ai vu à la télé il n'y a pas\n"
    .string "longtemps !\p"
    .string "Je suis IVAN, mais tu peux m'appeler\n"
    .string "IV-MAN !\p"
    .string "Oui, je suis le frère d'EV-MAN.\n"
    .string "Pas étonnant.\p"
    .string "Et toi…\p"
    .string "Tu es {PLAYER}, celui qui a\n"
    .string "récemment remporté la LIGUE POKéMON !\p"
    .string "Ton dernier combat était incroyable.\n"
    .string "J'ai tellement appris en te regardant\n"
    .string "que j'ai rejoint ton FAN CLUB !\p"
    .string "Après ça, j'ai décidé de devenir\n"
    .string "plus fort moi aussi, alors j'ai créé la\n"
    .string "routine d'entraînement ultime.\p"
    .string "Pour les POKéMON, bien sûr !\n"
    .string "Si tu veux, on peut s'entraîner ensemble pour\n"
    .string "maximiser le potentiel de tes POKéMON.\p"
    .string "Mais… pour endurer cet entraînement, un\n"
    .string "POKéMON doit être totalement préparé.\p"
    .string "Seuls ceux qui ont atteint le\n"
    .string "NIVEAU MAXIMUM peuvent le supporter.\p"
    .string "Tu veux essayer ?\p"
    .string "C'est un processus long et difficile,\n"
    .string "alors j'ai besoin de 100 000¥ pour le mettre en place.\p"
    .string "Dis-moi quand tu seras prêt !$"

BattleFrontier_Lounge9_IV_Text1:
	.string "M. MUSCLE : Salut ! Tu es là pour l'entraînement\n"
	.string "ultime de tout HOENN ?\p"
	.string "Ça coûte 100.000¥, mais ça vaut le coup !\n"
	.string "On commence ?$"

BattleFrontier_Lounge9_IV_Text_No:
	.string "Oh… Bon, à une autre fois.$"

BattleFrontier_Lounge9_IV_Text_NoLevel:
	.string "Je ne crois pas que ton POKéMON ait atteint\n"
	.string "son NIVEAU maximum…$"

BattleFrontier_Lounge9_IV_Finish:
	.string "Ouf... Je suis épuisé...\n"
	.string "Et tes POKéMON ?\p"
	.string "Tu devrais te reposer un peu avant de partir.\p"
	.string "À bientôt !$"

@Chansey training

BattleFrontier_Lounge9_Nurse::
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, BattleFrontier_Lounge9_NurseChampion
	msgbox BattleFrontier_Lounge9_NurseRepeat2, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, BattleFrontier_Lounge9_Chansey1End
	case YES, BattleFrontier_Lounge9_NurseBattle
	case MULTI_B_PRESSED, BattleFrontier_Lounge9_Chansey1End

BattleFrontier_Lounge9_NurseBattle::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_JOEY, 0, BattleFrontier_Lounge9_NurseIntro, BattleFrontier_Lounge9_NurseDefeat, BattleFrontier_Lounge9_ChanseyBattleAgain
	end

BattleFrontier_Lounge9_Chansey1End::
	closemessage
	end

BattleFrontier_Lounge9_ChanseyBattleAgain::
	faceplayer
	msgbox BattleFrontier_Lounge9_NurseRepeat, MSGBOX_AUTOCLOSE
	clearflag 0x85B
	end

BattleFrontier_Lounge9_NurseChampion:
	faceplayer
	msgbox BattleFrontier_Lounge9_NurseChampionText, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge9_NurseChampionText:
	.string "Je suis l'INFIRMIÈRE EXPÉRIENCE !\n"
	.string "Malheureusement, je ne peux pas te combattre\l"
	.string "à moins que tu ne deviennes CHAMPION.$"

BattleFrontier_Lounge9_NurseIntro:
	.string "Allez, LEUPHORIE !$"

BattleFrontier_Lounge9_NurseDefeat:
	.string "Oh non… LEUPHORIE, utilise E-COQUE !$"

BattleFrontier_Lounge9_NurseRepeat:
	.string "Si tu veux, on peut se battre à nouveau !$"

BattleFrontier_Lounge9_NurseRepeat2:
	.string "Prêt pour un combat ?$"

@Ability swapper

BattleFrontier_Lounge9_Ability_Man::
	lockall
	faceplayer
	goto_if_unset FLAG_SYS_GAME_CLEAR, BattleFrontier_Lounge9_Ability_ManNoChampion
	msgbox BattleFrontier_Lounge9_Ability_Text1, MSGBOX_YESNO
	waitmessage
	compare VAR_RESULT, YES
	goto_if_eq BattleFrontier_Lounge9_Ability_CheckMoney
	compare VAR_RESULT, NO
	goto_if_eq BattleFrontier_Lounge9_Ability_No
	end

BattleFrontier_Lounge9_Ability_ManNoChampion::
	msgbox BattleFrontier_Lounge9_Ability_Text_NoChampion, MSGBOX_DEFAULT
	waitmessage
	releaseall
	end

BattleFrontier_Lounge9_Ability_No:
	msgbox BattleFrontier_Lounge9_Ability_Text_No, MSGBOX_DEFAULT
	waitmessage
	releaseall
	end

BattleFrontier_Lounge9_Ability_CheckMoney:
	checkmoney 25000, 0
	compare VAR_RESULT, TRUE
	goto_if_eq BattleFrontier_Lounge9_Ability_Continue
	compare VAR_RESULT, FALSE
	goto_if_eq BattleFrontier_Lounge9_EV_SetZeroNoMoney
	end

BattleFrontier_Lounge9_Ability_Continue:
	closemessage
	special ChoosePartyMon
	waitstate
	special SwitchMonAbility
	compare VAR_RESULT, TRUE
	goto_if_eq BattleFrontier_Lounge9_Ability_Finish
	compare VAR_RESULT, FALSE
	goto_if_eq BattleFrontier_Lounge9_Ability_Cant
	end

BattleFrontier_Lounge9_Ability_Cant:
	msgbox BattleFrontier_Lounge9_Ability_Text_Cant, MSGBOX_DEFAULT
	waitmessage
	releaseall
	end

BattleFrontier_Lounge9_Ability_Finish:
	fadescreen 0x1
	delay 100
	fadescreen 0x0
	faceplayer
	waitse
	playse SE_EXP_MAX
	msgbox BattleFrontier_Lounge9_Ability_Finish_Text, MSGBOX_DEFAULT
	removemoney 25000, 0
	closemessage
	releaseall
	end

BattleFrontier_Lounge9_Ability_Finish_Text:
	.string "Voilà ! De rien !$"

BattleFrontier_Lounge9_Ability_Text1:
	.string "Bienvenue ! Je suis l'EXPERT DES TALENTS !\p"
	.string "Je peux échanger les talents des POKéMON\n"
	.string "en un clin d'oeil, pour seulement 25.000¥ !\p"
	.string "Veux-tu que j'échange le talent\n"
	.string "d'un POKéMON ?$"

BattleFrontier_Lounge9_Ability_Text_No:
	.string "Bien sûr. Je serai là si tu as besoin de moi.$"

BattleFrontier_Lounge9_Ability_Text_Cant:
	.string "Je ne peux pas faire ça. Ce POKéMON\n"
	.string "n'a pas de deuxième TALENT !$"

BattleFrontier_Lounge9_Ability_Text_NoChampion:
	.string "Bienvenue ! Je suis l'EXPERT DES TALENTS !\p"
	.string "Je peux échanger les talents des POKéMON\n"
	.string "en un clin d'oeil.\p"
	.string "Malheureusement, j'ai mal au dos et\n"
	.string "je ne peux pas travailler aujourd'hui.\p"
	.string "Reviens plus tard !$"

