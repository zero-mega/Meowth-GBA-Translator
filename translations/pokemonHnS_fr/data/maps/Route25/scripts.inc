.set LOCALID_ROUTE25_MISTY, 10
.set LOCALID_ROUTE25_MAN, 11
.set LOCALID_ROUTE25_SUICUNE, 16
.set LOCALID_ROUTE25_EUSINE, 15
.set LOCALID_CAPE_MISTY, 20

Route25_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route25_MapScript_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route25_MapScript_OnTransition::
	callnative SetTimeBasedEncounters
	goto_if_eq VAR_SUICUNE_ENCOUNTERS, 7, Route25_EventScript_SetSuicuneSceneMid
	end

Route25_EventScript_SetSuicuneSceneMid::
	setobjectxyperm LOCALID_ROUTE25_EUSINE, 65, 9
	end

Route25_EventScript_MistyRematch::
    lock
    faceplayer
    msgbox Route25_Text_Misty, MSGBOX_DEFAULT
    closemessage
    fadescreenswapbuffers FADE_TO_BLACK
    setflag FLAG_HIDE_CAPE_MISTY
    removeobject LOCALID_CAPE_MISTY
    fadescreenswapbuffers FADE_FROM_BLACK
    clearflag FLAG_HIDE_DOJO_MISTY
    release
    end

Route25_Text_Misty:
    .string "ONDINE : J'adore le coucher de soleil ici !\n"
    .string "Il me donne le courage d'avancer,\l"
    .string "tu sais ?\p"
    .string "D'accord !\p"
    .string "Si tu es prêt pour une vraie éclaboussure,\n"
    .string "rejoins-moi au DOJO DE COMBAT !$"

Route25_EventScript_Dudley::
	trainerbattle_single TRAINER_DUDLEY Route25_Text_SchoolboyDudleySeen, Route25_Text_SchoolboyDudleyBeaten
	msgbox Route25_Text_SchoolboyDudleyAfter, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Ellen::
	trainerbattle_single TRAINER_ELLEN Route25_Text_LassEllenSeen, Route25_Text_LassEllenBeaten
	msgbox Route25_Text_LassEllenAfter, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Joe::
	trainerbattle_single TRAINER_JOE Route25_Text_SchoolboyJoeSeen, Route25_Text_SchoolboyJoeBeaten
	msgbox Route25_Text_SchoolboyJoeAfter, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Laura::
	trainerbattle_single TRAINER_LAURA Route25_Text_LassLauraSeen, Route25_Text_LassLauraBeaten
	msgbox Route25_Text_LassLauraAfter, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Lloyd::
	trainerbattle_single TRAINER_LLOYD Route25_Text_CamperLloydSeen, Route25_Text_CamperLloydBeaten
	msgbox Route25_Text_CamperLloydAfter, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Shannon::
	trainerbattle_single TRAINER_SHANNON Route25_Text_LassShannonSeen, Route25_Text_LassShannonBeaten
	msgbox Route25_Text_LassShannonAfter, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Pat::
	trainerbattle_single TRAINER_PAT Route25_Text_SupernerdPatSeen, Route25_Text_SupernerdPatBeaten
	msgbox Route25_Text_SupernerdPatAfter, MSGBOX_AUTOCLOSE
	end

Route25_EventScript_Kevin::
	lock
	faceplayer
	goto_if_set FLAG_ROUTE25_GOT_NUGGET, Route25_EventScript_KevinAfter
	msgbox Route25_Text_CooltrainerKevinNugget, MSGBOX_DEFAULT
	giveitem ITEM_BIG_NUGGET
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_ROUTE25_GOT_NUGGET
	msgbox Route25_Text_CooltrainerKevinSeen, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_KEVIN, Route25_Text_CooltrainerKevinBeaten
	msgbox Route25_Text_CooltrainerKevinAfter, MSGBOX_DEFAULT
	closemessage
	release
	end
Route25_EventScript_KevinAfter::
	msgbox Route25_Text_CooltrainerKevinAfter, MSGBOX_NPC
	end

Route25_EventScript_BillsHouseSign::
	msgbox Route25_Text_BillsHouseSign, MSGBOX_SIGN
	end

Route25_Trigger_MistyRight::
	lock
	turnobject LOCALID_ROUTE25_MISTY, DIR_SOUTH
	delay 40
	turnobject LOCALID_ROUTE25_MAN, DIR_SOUTH
	playse SE_PIN
	applymovement2 LOCALID_ROUTE25_MAN, Common_Movement_ExclamationMark
	delay 60
	applymovement2 LOCALID_ROUTE25_MAN, Route25_Movement_ManLeaveRight
	waitmovement 0
	applymovement2 LOCALID_ROUTE25_MISTY, Route25_Movement_MistyWalkToPlayerRight
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	goto Route25_EventScript_Misty
Route25_Trigger_MistyLeft::
	lock
	turnobject LOCALID_ROUTE25_MISTY, DIR_SOUTH
	delay 40
	turnobject LOCALID_ROUTE25_MAN, DIR_SOUTH
	playse SE_PIN
	applymovement2 LOCALID_ROUTE25_MAN, Common_Movement_ExclamationMark
	delay 60
	applymovement2 LOCALID_ROUTE25_MAN, Route25_Movement_ManLeaveLeft
	waitmovement 0
	applymovement2 LOCALID_ROUTE25_MISTY, Route25_Movement_MistyWalkToPlayerLeft
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_EAST
	goto Route25_EventScript_Misty
Route25_EventScript_Misty::
	msgbox Route25_Text_MistyDate, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_ROUTE25_MISTY, Route25_Movement_MistyLeave
	waitmovement 0
	removeobject LOCALID_ROUTE25_MISTY
	removeobject LOCALID_ROUTE25_MAN
	setflag FLAG_HIDE_ROUTE25_MISTY
	clearflag FLAG_HIDE_CERULEAN_GYM_TRAINERS
	setflag FLAG_HIDE_CERULEAN_GYM_POKEMON
	setvar VAR_CERULEAN_CITY_STATE, 3
	release
	end

Route25_Trigger_SuicuneLeft::
	lock
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	delay 60
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	applymovement LOCALID_ROUTE25_SUICUNE, Route25_Movement_Suicune1
	playse SE_LEDGE
	waitse
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkRight1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Route25_Movement_WalkToSuicune
	waitmovement 0
	goto Route25_EventScript_SuicuneMerge
Route25_Trigger_SuicuneRight::
	lock
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	delay 60
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	applymovement LOCALID_ROUTE25_SUICUNE, Route25_Movement_Suicune1
	playse SE_LEDGE
	waitse
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Route25_Movement_WalkToSuicune
	waitmovement 0
	goto Route25_EventScript_SuicuneMerge
Route25_EventScript_SuicuneMerge::
	clearflag FLAG_HIDE_ROUTE25_EUSINE
	addobject LOCALID_ROUTE25_EUSINE
	applymovement LOCALID_ROUTE25_EUSINE, Route25_Movement_EusineEnter
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	msgbox Route25_Text_Eusine1, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE25_EUSINE, Route25_Movement_EusineSide
	waitmovement 0
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	msgbox Route25_Text_Eusine2, MSGBOX_DEFAULT
	closemessage
	setvar VAR_SUICUNE_ENCOUNTERS, 7
	release
	end
	
Route25_Text_Eusine1:
	.string "EUSINE : Pouf, pouf... Je\n"
	.string "ne suis… pas de\p"
	.string "taille. …Comme je l'avais\n"
	.string "prévu. .......................... … Vas-y.\l"
	.string "Depuis que je t'ai\p"
	.string "rencontré à la TOUR\n"
	.string "CENDRÉE de ROSYÈRES, j'ai\l"
	.string "en quelque sorte su\l"
	.string "que SUICUNE te choisirait.$"

Route25_Text_Eusine2:
	.string "Regarde bien !\p"
	.string "SUICUNE t'attend !\n"
	.string "Il attend un combat avec un DRESSEUR\l"
	.string "digne à qui il pourra se confier\l"
	.string "et se fier.$"

Route25_Text_Eusine3:
	.string "{PLAYER}…\n"
	.string "Vous deux êtes vraiment incroyables…\p"
	.string "Je n'ai jamais vu un combat aussi\n"
	.string "intense !\l"
	.string "Je n'ai aucun regret…\p"
	.string "Adieu, SUICUNE !\n"
	.string "Adieu… {PLAYER} !$"

Route25_EventScript_Eusine::
	msgbox Route25_Text_Eusine2, MSGBOX_NPC
	end

Route25_EventScript_Suicune::
	lock
	faceplayer
	playmoncry SPECIES_SUICUNE, CRY_MODE_NORMAL
	applymovement LOCALID_ROUTE25_SUICUNE, Route25_Movement_Suicune1
	playse SE_LEDGE
	waitse
	waitmovement 0
	playmoncry SPECIES_SUICUNE, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	seteventmon SPECIES_SUICUNE, 50
	special BattleSetup_StartLegendaryBattle
	waitstate
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route25_EventScript_SuicuneRan
	fadescreenswapbuffers FADE_TO_BLACK
	removeobject LOCALID_ROUTE25_SUICUNE
	setflag FLAG_HIDE_ROUTE25_SUICUNE
	fadescreenswapbuffers FADE_FROM_BLACK
	goto_if_ge VAR_SUICUNE_ENCOUNTERS, 8, Route25_EventScript_SuicunePostGame
	getplayerxy VAR_TEMP_0, VAR_TEMP_1
	call_if_eq VAR_TEMP_0, 66, Route25_AdjustPlayer
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	turnobject LOCALID_ROUTE25_EUSINE, DIR_NORTH
	msgbox Route25_Text_Eusine3, MSGBOX_DEFAULT
	closemessage
	applymovement2 LOCALID_ROUTE25_EUSINE, Route25_Movement_EusineLeave
	waitmovement 0
	removeobject LOCALID_ROUTE25_EUSINE
	setflag FLAG_HIDE_ROUTE25_EUSINE
	clearflag FLAG_HIDE_CELADON_EUSINE
	setvar VAR_SUICUNE_ENCOUNTERS, 8
	release
	end

Route25_EventScript_SuicuneRan::
	release
	end

Route25_AdjustPlayer::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft1
	waitmovement 0
	return

Route25_EventScript_SuicunePostGame::
	release
	end

Route25_Movement_EusineLeave:
	walk_down
	walk_down
	walk_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

Route25_Movement_EusineSide:
	walk_slow_left
	walk_slow_up
	step_end

Route25_Movement_EusineEnter:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_up
	walk_slow_up
	step_end

Route25_Movement_Suicune1:
	jump_in_place_down
	step_end

Route25_Movement_WalkToSuicune:
	walk_up
	walk_up
	step_end

Route25_Movement_MistyLeave:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route25_Movement_ManLeaveRight:
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end
Route25_Movement_ManLeaveLeft:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Route25_Movement_MistyWalkToPlayerRight:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	face_right
	step_end
Route25_Movement_MistyWalkToPlayerLeft:
	walk_down
	walk_down
	walk_down
	walk_down
	face_left
	step_end

Route25_Text_MistyDate:
	.string "ONDINE : Aww ! Pourquoi as-tu dû\n"
	.string "venir nous embêter maintenant ?\p"
	.string "Tu sais comment on appelle\n"
	.string "des gens comme toi ?\p"
	.string "Des nuisibles ! Tu m'as bien entendu,\n"
	.string "nuisible !\p"
	.string "…\p"
	.string "…Oh ? Ces BADGES que tu as…\n"
	.string "Ce sont des BADGES d'ARÈNE de JOHTO ?\p"
	.string "Si tu en as huit, tu dois être\n"
	.string "bon.\p"
	.string "OK, alors. Viens à l'ARÈNE d'AZURIA.\p"
	.string "Je serai heureuse de t'affronter.\p"
	.string "Je suis ONDINE, la CHAMPIONNE d'ARÈNE d'\n"
	.string "AZURIA.$"

Route25_Text_SchoolboyDudleySeen:
	.string "Bats les six Dresseurs pour\n"
	.string "gagner un fabuleux lot !\p"
	.string "Tu penses être à la hauteur ?$"

Route25_Text_SchoolboyDudleyBeaten:
	.string "Whoo ! Pas mal du tout.$"

Route25_Text_SchoolboyDudleyAfter:
	.string "J'ai fait de mon mieux.\n"
	.string "Je n'ai aucun regret.$"

Route25_Text_LassEllenSeen:
	.string "Je suis la deuxième.\n"
	.string "Ça devient sérieux !$"

Route25_Text_LassEllenBeaten:
	.string "Comment ai-je pu perdre ?$"

Route25_Text_LassEllenAfter:
	.string "J'ai fait de mon mieux.\n"
	.string "Je n'ai aucun regret.$"

Route25_Text_SchoolboyJoeSeen:
	.string "Voici le Nº 3 !\n"
	.string "Je ne serai pas facile.$"

Route25_Text_SchoolboyJoeBeaten:
	.string "Aïe ! Écrasé !$"

Route25_Text_SchoolboyJoeAfter:
	.string "J'ai fait de mon mieux.\n"
	.string "Je n'ai aucun regret.$"

Route25_Text_LassLauraSeen:
	.string "Je suis le no 4 !\n"
	.string "Tu commences à fatiguer ?$"

Route25_Text_LassLauraBeaten:
	.string "J'ai perdu aussi…$"

Route25_Text_LassLauraAfter:
	.string "J'ai fait de mon mieux.\n"
	.string "Je n'ai aucun regret.$"

Route25_Text_CamperLloydSeen:
	.string "OK ! Je suis le Nº 5.\n"
	.string "Je vais t'écraser !$"

Route25_Text_CamperLloydBeaten:
	.string "Ouah ! Trop fort.$"

Route25_Text_CamperLloydAfter:
	.string "J'ai fait de mon mieux.\n"
	.string "Je n'ai aucun regret.$"

Route25_Text_LassShannonSeen:
	.string "Je suis le dernier de la file, mais\n"
	.string "crois-moi, je suis costaud !$"

Route25_Text_LassShannonBeaten:
	.string "Tu plaisantes.$"

Route25_Text_LassShannonAfter:
	.string "J'ai fait de mon mieux.\n"
	.string "Je n'ai aucun regret.$"

Route25_Text_SupernerdPatSeen:
	.string "Mufufufu…\p"
	.string "Je n'ai rien à voir avec les\n"
	.string "DRESSEURS en pack de six.\p"
	.string "Je t'attendais ici pour te battre quand\n"
	.string "tu serais épuisé par tous les\l"
	.string "combats.$"

Route25_Text_SupernerdPatBeaten:
	.string "Tu n'es pas fatigué du tout ?$"

Route25_Text_SupernerdPatAfter:
	.string "Je suis désolé… Je ne tricherai\n"
	.string "plus…$"

Route25_Text_CooltrainerKevinNugget:
	.string "Tu as livré un combat de plus que\n"
	.string "prévu, mais tu as gagné\l"
	.string "quand même.\p"
	.string "Comme promis, tu gagnes un prix.$"

Route25_Text_CooltrainerKevinSeen:
	.string "Mais après t'avoir vu combattre,\n"
	.string "je veux voir comment je me débrouille.\p"
	.string "Qu'en dis-tu ? Laisse-moi\n"
	.string "t'affronter.$"

Route25_Text_CooltrainerKevinBeaten:
	.string "Je n'ai jamais eu un combat aussi\n"
	.string "bon !$"

Route25_Text_CooltrainerKevinAfter:
	.string "C'était un super combat !\p"
	.string "Toi et tes POKéMON êtes vraiment\n"
	.string "exceptionnels !$"

Route25_Text_BillsHouseSign:
	.string "MAISON SUR LA MER\n"
	.string "CHEZ BILL$"

