.set LOCALID_ROUTE27_FATMAN, 1

Route27_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route27_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route27_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route27_EventScript_BaobaCall::
	pokenavcall BlackthornCity_Text_BaobaCall
	waitmessage
	delay 30
	setflag FLAG_SAFARI_ZONE_WEST_EXPANSION
    setvar VAR_ROUTE27_BAOBA_CALL, 1
	end

Route27_EventScript_FirstSteps::
    lock
    playse SE_PIN
    setflag FLAG_VISITED_KANTO
    applymovement2 LOCALID_ROUTE27_FATMAN, Common_Movement_ExclamationMark
    turnobject LOCALID_ROUTE27_FATMAN, DIR_WEST
    delay 30
    getplayerxy VAR_TEMP_0, VAR_TEMP_1
    call_if_eq VAR_TEMP_1, 24, Route27_EventScript_FirstStepsWalkTop
    call_if_eq VAR_TEMP_1, 25, Route27_EventScript_FirstStepsWalkBot

    msgbox Route27_Text_FisherHey, MSGBOX_DEFAULT
    msgbox Route27_Text_FisherMessage, MSGBOX_DEFAULT
    closemessage
    turnobject LOCALID_ROUTE27_FATMAN, DIR_SOUTH

    @integrated flagheap
    setflag FLAG_HIDE_VICTORY_ROAD_SILVER
    setflag FLAG_HIDE_INDIGO_PLATEAU_SILVER
    setflag FLAG_HIDE_INDIGO_PLATEAU_MARY_OAK
    
    clearflag FLAG_GOT_TM_SANDSTORM
    clearflag FLAG_INDIGOJUNCTION_HIDE_SILVER_GUARD
    clearflag FLAG_INDIGOJUNCTION_HIDE_KANTO_GUARD

    setvar VAR_ROUTE27_STATE, 1
    release
    end

Route27_EventScript_FirstStepsWalkTop::
    applymovement2 LOCALID_ROUTE27_FATMAN, Route27_Movement_WalkTop
    waitmovement 0
    return
Route27_EventScript_FirstStepsWalkBot::
    applymovement2 LOCALID_ROUTE27_FATMAN, Route27_Movement_WalkBot
    waitmovement 0
    return

Route27_Movement_WalkTop:
    face_left
    walk_left
    step_end

Route27_Movement_WalkBot:
    walk_down
    walk_left
    step_end

Route27_EventScript_Item_Moonstone::
    finditem ITEM_MOON_STONE
    end

Route27_EventScript_Item_RareCandy::
    finditem ITEM_RARE_CANDY
    end

Route27_EventScript_Item_SolarBeam::
    finditem ITEM_TM_SOLAR_BEAM
    end

Route27_EventScript_Item_Revive::
    finditem ITEM_REVIVE
    end

Route27_EventScript_Fatman::
    msgbox Route27_Text_FisherMessage, MSGBOX_NPC
    end

Route27_EventScript_Blake::
	trainerbattle_single TRAINER_BLAKE Route27_Text_CooltrainermBlakeSeen, Route27_Text_CooltrainermBlakeBeaten
	msgbox Route27_Text_CooltrainermBlakeAfter, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_Brian::
	trainerbattle_single TRAINER_BRIAN Route27_Text_CooltrainermBrianSeen, Route27_Text_CooltrainermBrianBeaten
	msgbox Route27_Text_CooltrainermBrianAfter, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_Reena::
	trainerbattle_single TRAINER_REENA Route27_Text_CooltrainerfReenaSeen, Route27_Text_CooltrainerfReenaBeaten
	msgbox Route27_Text_CooltrainerfReenaAfter, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_Megan::
	trainerbattle_single TRAINER_MEGAN Route27_Text_CooltrainerfMeganSeen, Route27_Text_CooltrainerfMeganBeaten
	msgbox Route27_Text_CooltrainerfMeganAfter, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_Gilbert::
	trainerbattle_single TRAINER_GILBERT Route27_Text_PsychicGilbertSeen, Route27_Text_PsychicGilbertBeaten
	msgbox Route27_Text_PsychicGilbertAfter, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_Jose::
	trainerbattle_single TRAINER_JOSE Route27_Text_BirdKeeperJoseSeen, Route27_Text_BirdKeeperJoseBeaten
	msgbox Route27_Text_BirdKeeperJoseAfter, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_Scott::
	trainerbattle_single TRAINER_SCOTT Route27_Text_FisherScottSeen, Route27_Text_FisherScottBeaten
	msgbox Route27_Text_FisherScottAfter, MSGBOX_AUTOCLOSE
	end

Route27_EventScript_TohjoFallsSign::
    msgbox TohjoFalls_Text_Sign, MSGBOX_SIGN
    end

Route27_Text_FisherHey:
    .string "Hé !$"

Route27_Text_FisherMessage:
    .string "Tu sais ce que tu viens de faire ?\p"
    .string "Tu as fait ton premier pas vers\n"
    .string "KANTO.\p"
    .string "Regarde ta CARTE du POKéMATOS.$"

Route27_Text_CooltrainermBlakeSeen:
    .string "Tu as l'air assez fort.\n"
    .string "Laisse-moi te combattre !$"

Route27_Text_CooltrainermBlakeBeaten:
    .string "Aïe !$"

Route27_Text_CooltrainermBlakeAfter:
    .string "Si tu réussis ce périple difficile,\n"
    .string "la vérité sera révélée !\p"
    .string "Hé, désolé, je voulais juste\n"
    .string "dire quelque chose de cool.$"

Route27_Text_CooltrainermBrianSeen:
    .string "Hm ? Tu es fort, n'est-ce pas ?$"

Route27_Text_CooltrainermBrianBeaten:
    .string "Comme je le pensais !$"

Route27_Text_CooltrainermBrianAfter:
    .string "Un bon Dresseur peut reconnaître\n"
    .string "les autres bons Dresseurs.$"

Route27_Text_CooltrainerfReenaSeen:
    .string "Tu ne devrais pas sous-estimer les\n"
    .string "POKéMON sauvages de ces parages.$"

Route27_Text_CooltrainerfReenaBeaten:
    .string "Oh ! Tu es bien trop fort !$"

Route27_Text_CooltrainerfReenaAfter:
    .string "Tu n'es qu'un gamin, mais tu ne dois\n"
    .string "pas être sous-estimé non plus.$"

Route27_Text_CooltrainerfMeganSeen:
    .string "C'est rare de voir quelqu'un venir ici.\p"
    .string "Tu t'entraînes seul ?$"

Route27_Text_CooltrainerfMeganBeaten:
    .string "Oh ! Tu es vraiment fort !$"

Route27_Text_CooltrainerfMeganAfter:
    .string "J'étudie les POKéMON avant et après\n"
    .string "l'évolution.\p"
    .string "L'évolution rend vraiment les\n"
    .string "POKéMON plus forts.\p"
    .string "Mais les formes évoluées apprennent aussi\n"
    .string "les attaques plus tard.$"

Route27_Text_PsychicGilbertSeen:
    .string "Ne dis rien ! Laisse-moi\p"
    .string "deviner ce que tu penses.\p"
    .string "Mmmmmmm… J'ai trouvé ! Tu\p"
    .string "relèves le défi de\n"
    .string "la LIGUE POKéMON !$"

Route27_Text_PsychicGilbertBeaten:
    .string "Tu es trop fort !$"

Route27_Text_PsychicGilbertAfter:
    .string "Avec tes compétences, tu te débrouilleras bien à\n"
    .string "la LIGUE.\p"
    .string "C'est ce que dit ma prémonition.$"

Route27_Text_BirdKeeperJoseSeen:
    .string "Cui ! Cui ! Tetweet !$"

Route27_Text_BirdKeeperJoseBeaten:
    .string "Piu !$"

Route27_Text_BirdKeeperJoseAfter:
    .string "Les ORNITHOLOGUES comme moi imitent les sifflements\n"
    .string "d'oiseaux pour commander les POKéMON.$"

TohjoFalls_Text_Sign:
    .string "CHUTES TOHJO\p"
    .string "LE LIEN ENTRE KANTO ET JOHTO$"

Route27_Text_FisherScottSeen:
    .string "Je me sens super bien aujourd'hui !\p"
    .string "J'ai l'impression que je pourrais même\n"
    .string "battre le CHAMPION de la LIGUE !$"

Route27_Text_FisherScottBeaten:
    .string "Non ! Pas dans ce combat !$"

Route27_Text_FisherScottAfter:
    .string "Comme à la pêche, tout est fini\n"
    .string "aux POKéMON si tu abandonnes.$"
