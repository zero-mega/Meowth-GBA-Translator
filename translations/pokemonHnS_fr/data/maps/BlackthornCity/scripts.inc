.set LOCALID_BLACKTHORN_SAGE, 7
.set LOCALID_BLACKTHORN_BOY, 2

BlackthornCity_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, BlackthornCity_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, BlackthornCity_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, BlackthornCity_EventScript_CityEnter
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

BlackthornCity_OnLoad::
	goto_if_unset FLAG_BADGE05_GET, BlackThornCity_EventScript_MoveGymBoy
	goto_if_unset FLAG_BADGE06_GET, BlackThornCity_EventScript_MoveGymBoy
	goto_if_unset FLAG_BADGE07_GET, BlackThornCity_EventScript_MoveGymBoy
	end

BlackThornCity_EventScript_MoveGymBoy::
	setobjectxyperm LOCALID_BLACKTHORN_BOY, 24, 27
	end

BlackthornCity_OnFrame::
	map_script_2 VAR_BLACKTHORN_CITY_STATE, 4, BlackthornCity_EventScript_Call
	.2byte 0

BlackthornCity_EventScript_CityEnter:: 
	setflag FLAG_VISITED_BLACKTHORN_CITY
	callnative SetTimeBasedEncounters
	end

BlackthornCity_EventScript_Call::
	lock
	pokenavcall BlackthornCity_Text_ElmCall
	waitmessage
	delay 30
	setvar VAR_BLACKTHORN_CITY_STATE, 5
	setvar VAR_NEWBARKTOWN_LABSTATE, 7
	release
	end

BlackthornCity_Text_BaobaCall:
	.string "GARDIEN BAOBA : {PLAYER} !\p"
	.string "C'est le GARDIEN BAOBA.\p"
	.string "J'appelle pour te dire que\n"
	.string "le PARC SAFARI s'est agrandi !\p"
	.string "Viens nous rendre visite !$"

BlackthornCity_Text_ElmCall:
	.string "PROF.ORME : Allô, {PLAYER} ?\p"
	.string "J'ai quelque chose pour toi.\n"
	.string "Tu pourrais passer au LABO ?\p"
	.string "À plus tard !$"

BlackThornCity_EventScript_Sage::
	lock
	faceplayer
	goto_if_eq VAR_BLACKTHORN_CITY_STATE, 1, BlackThornCity_EventScript_SageRefuse
	msgbox BlackthornGrampsGrantsEntryText, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackThornCity_EventScript_SageRefuse::
	msgbox BlackthornGrampsRefusesEntryText, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackThornCity_Trigger_Sage::
	lock
	turnobject LOCALID_BLACKTHORN_SAGE, DIR_EAST
	msgbox BlackthornGrampsRefusesEntryText, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER Common_Movement_WalkDown1
	waitmovement 0
	turnobject LOCALID_BLACKTHORN_SAGE, DIR_SOUTH
	release
	end

BlackthornCity_EventScript_GymBoy::
	lock
	faceplayer
	goto_if_unset FLAG_BADGE05_GET, BlackThornCity_EventScript_GymBoyNotReady
	goto_if_unset FLAG_BADGE06_GET, BlackThornCity_EventScript_GymBoyNotReady
	goto_if_unset FLAG_BADGE07_GET, BlackThornCity_EventScript_GymBoyNotReady
	goto_if_eq VAR_BLACKTHORN_CITY_STATE, 1, BlackThornCity_EventScript_GymBoyBefore
	msgbox BlackthornCity_Text_ClairIsBeaten, MSGBOX_DEFAULT
	closemessage
	release
	end	

BlackThornCity_EventScript_GymBoyNotReady::
	msgbox BlackthornCity_Text_ClairNotReady, MSGBOX_DEFAULT
	closemessage
	release
	end

BlackThornCity_EventScript_GymBoyBefore::
	msgbox BlackthornCity_Text_ClairIsIn, MSGBOX_DEFAULT
	closemessage
	release
	end	

BlackthornCity_EventScript_BlackBelt::
	msgbox BlackBeltText_VoicesInMyHead, MSGBOX_NPC
	end

BlackthornCity_EventScript_CoolTrainerF::
	msgbox BlackthornCooltrainerF1Text, MSGBOX_NPC
	end

BlackthornCity_EventScript_Youngster::
	msgbox BlackthornYoungsterText, MSGBOX_NPC
	end

BlackthornCity_EventScript_CoolTrainerF2::
	msgbox BlackthornCooltrainerF2Text, MSGBOX_NPC
	end

BlackthornCity_EventScript_CitySign::
	msgbox BlackthornCitySignText, MSGBOX_SIGN
	end

BlackthornCity_EventScript_GymSign::
	msgbox BlackthornGymSignText, MSGBOX_SIGN
	end

BlackthornCity_EventScript_MoveHouseSign::
	msgbox BlackthornCity_Text_MoveDeletersHouseSign, MSGBOX_SIGN
	end

BlackthornCity_EventScript_DragonsDenSign::
	msgbox BlackthornCity_Text_DragonDenSign, MSGBOX_SIGN
	end

BlackthornCity_EventScript_Santos::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SPELL_TAG, BlackthornCity_EventScript_SantosCompleted
	msgbox BlackthornCity_MeetSantosText, MSGBOX_DEFAULT
	closemessage
	multichoice 20, 0, MULTI_DAYS_OF_WEEK, FALSE
	switch VAR_RESULT
	case 0, BlackthornCity_EventScript_SantosNope
	case 1, BlackthornCity_EventScript_SantosNope
	case 2, BlackthornCity_EventScript_SantosNope
	case 3, BlackthornCity_EventScript_SantosNope
	case 4, BlackthornCity_EventScript_SantosNope
	case 5, BlackthornCity_EventScript_SantosNope
	case 6, BlackthornCity_EventScript_SantosYes
	case 7 BlackthornCity_EventScript_SantosCancel
	case MULTI_B_PRESSED, BlackthornCity_EventScript_SantosCancel
	closemessage
	release
	end
BlackthornCity_EventScript_SantosYes::
	msgbox BlackthornCity_SantosGivesGiftText, MSGBOX_DEFAULT
	giveitem ITEM_SPELL_TAG
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_GOT_SPELL_TAG
	msgbox BlackthornCity_SantosGaveGiftText, MSGBOX_DEFAULT
	closemessage
	release
	end
BlackthornCity_EventScript_SantosNope::
	msgbox BlackthornCity_SantosNopeText, MSGBOX_DEFAULT
	closemessage
	release
	end
BlackthornCity_EventScript_SantosCancel::
	closemessage
	release
	end
BlackthornCity_EventScript_SantosCompleted::
	msgbox BlackthornCity_SantosSaturdayText, MSGBOX_DEFAULT
	closemessage
	release
	end


BlackthornCity_Text_ClairNotReady:
	.string "SANDRA, notre CHAMPIONNE D'ARÈNE, suit\n"
	.string "tes progrès. Cependant, elle n'affronte\p"
	.string "que les DRESSEURS qui\n"
	.string "ont déjà 7 BADGES.$"

BlackthornCity_Text_ClairIsIn:
	.string "SANDRA, notre CHAMPIONNE D'ARÈNE,\n"
	.string "t'attend. Cependant, il serait\p"
	.string "impossible pour un DRESSEUR\n"
	.string "ordinaire de gagner.$"

BlackthornCity_Text_ClairIsBeaten:
	.string "Tu as battu SANDRA ?\p"
	.string "C'est incroyable !\p"
	.string "Je n'ai jamais entendu parler d'elle perdant\n"
	.string "contre quelqu'un d'autre que PETER.$"

BlackthornGrampsRefusesEntryText:
	.string "Non. Seuls les Dresseurs choisis peuvent\n"
	.string "s'entraîner ici.\p"
	.string "Veuillez partir.$"

BlackthornGrampsGrantsEntryText:
	.string "Si IRIS l'autorise, son grand-\n"
	.string "père, notre MAÎTRE, le fera aussi.\p"
	.string "Tu peux entrer.$"

BlackBeltText_VoicesInMyHead:
	.string "Arooo ! Des voix dans ma tête !\p"
	.string "Hein ? J'écoute ma radio !$"

BlackthornCooltrainerF1Text:
	.string "Tu vas faire te rappeler des capacités\n"
	.string "à ton POKéMON ?$"

BlackthornYoungsterText:
	.string "Les maîtres Dragon viennent tous\n"
	.string "de la ville d'ÉBÈNELLE.$"

BlackthornCity_MeetSantosText:
	.string "SANTOS : …\p"
	.string "Je suis SANTOS de la famille des jours.\p"
	.string "Devine lequel.$"

BlackthornCity_SantosGivesGiftText:
	.string "Tu peux prendre ça…$"

BlackthornCity_SantosGaveGiftText:
	.string "SANTOS : …\p"
	.string "RUNE SORT…\p"
	.string "Les capacités SPECTRE deviennent plus fortes…\p"
	.string "Ça va te faire peur…$"

BlackthornCity_SantosSaturdayText:
	.string "SANTOS : …\p"
	.string "À un autre samedi…\p"
	.string "Je n'aurai plus de cadeaux…$"

BlackthornCity_SantosNopeText:
	.string "SANTOS : Non.$"

BlackthornCooltrainerF2Text:
	.string "Waouh, tu es passé par le SENTIER GLACE ?\p"
	.string "Tu dois être un DRESSEUR de feu !$"

BlackthornCitySignText:
	.string "EBENELLE\p"
	.string "Un Refuge Montagnard Tranquille$"

BlackthornGymSignText:
	.string "ARÈNE POKéMON D'EBENELLE\n"
	.string "CHAMPIONNE : IRIS\p"
	.string "L'Utilisatrice Bénie des POKéMON Dragon$"

BlackthornCity_Text_MoveDeletersHouseSign:
	.string "MAISON DE L'EFFACEUR DE CAPACITÉS$"

BlackthornCity_Text_DragonDenSign:
	.string "REPAIRE DRAGON DEVANT$"

