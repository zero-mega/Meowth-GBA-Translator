.set LOCALID_COLE, 2
.set LOCALID_GERALD, 3
.set LOCALID_AXLE, 4
.set LOCALID_DANIELLE, 5

LavaridgeTown_Gym_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LavaridgeTown_Gym_1F_OnTransition
	.byte 0

LavaridgeTown_Gym_1F_OnTransition:
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
	call LavaridgeTown_Gym_1F_EventScript_CheckBuryTrainers
	end

@ Unclear where/if these temp vars are getting checked
LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars::
	setvar VAR_TEMP_B, 0
	setvar VAR_TEMP_C, 0
	setvar VAR_TEMP_D, 0
	setvar VAR_TEMP_E, 0
	setvar VAR_TEMP_F, 0
	goto_if_defeated TRAINER_COLE, LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar
	setvar VAR_TEMP_B, 1
LavaridgeTown_Gym_1F_EventScript_SetGeraldTempVar::
	goto_if_defeated TRAINER_RUSSELL, LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar
	setvar VAR_TEMP_C, 1
LavaridgeTown_Gym_1F_EventScript_SetAxleTempVar::
	goto_if_defeated TRAINER_COREY, LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar
	setvar VAR_TEMP_D, 1
LavaridgeTown_Gym_1F_EventScript_SetDanielleTempVar::
	goto_if_defeated TRAINER_JIM, LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars
	setvar VAR_TEMP_E, 1
LavaridgeTown_Gym_1F_EventScript_EndSetTrainerTempVars::
	return

LavaridgeTown_Gym_1F_EventScript_CheckBuryTrainers::
	goto_if_defeated TRAINER_COLE, LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald
	setobjectmovementtype LOCALID_COLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryGerald::
	goto_if_defeated TRAINER_RUSSELL, LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle
	setobjectmovementtype LOCALID_GERALD, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryAxle::
	goto_if_defeated TRAINER_COREY, LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle
	setobjectmovementtype LOCALID_AXLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_CheckBuryDanielle::
	goto_if_defeated TRAINER_JIM, LavaridgeTown_Gym_1F_EventScript_EndCheckBuryTrainers
	setobjectmovementtype LOCALID_DANIELLE, MOVEMENT_TYPE_BURIED
LavaridgeTown_Gym_1F_EventScript_EndCheckBuryTrainers::
	return

LavaridgeTown_Gym_1F_EventScript_Flannery::
	trainerbattle_single TRAINER_PING, LavaridgeTown_Gym_1F_Text_FlanneryIntro, LavaridgeTown_Gym_1F_Text_FlanneryDefeat, LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, LavaridgeTown_Gym_1F_EventScript_FlanneryRematch
	goto_if_unset FLAG_RECEIVED_TM_OVERHEAT, LavaridgeTown_Gym_1F_EventScript_GiveOverheat2
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostBattle, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_FlanneryDefeated::
	message LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_WHITEOUT_TO_LAVARIDGE
	setflag FLAG_DEFEATED_ECRUTEAK_CITY_GYM
	setflag FLAG_BADGE04_GET
	addvar VAR_GARBAGEVAR, 1
	call_if_eq VAR_GARBAGEVAR, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 4
	call Common_EventScript_SetGymTrainers
	setflag FLAG_HIDE_VERDANTURF_TOWN_WANDAS_HOUSE_WALLY
	setvar VAR_GARBAGEVAR, 1
	call LavaridgeTown_Gym_1F_EventScript_GiveOverheat
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox LavaridgeTown_Gym_1F_Text_RegisteredFlannery, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_FLANNERY_MATCH_CALL
	release
	end

LavaridgeTown_Gym_1F_EventScript_GiveOverheat2::
	giveitem ITEM_TM_OVERHEAT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_OVERHEAT
	release
	end

LavaridgeTown_Gym_1F_EventScript_GiveOverheat::
	giveitem ITEM_TM_OVERHEAT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox LavaridgeTown_Gym_1F_Text_ExplainOverheat, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_OVERHEAT
	return

LavaridgeTown_Gym_1F_EventScript_FlanneryRematch::
	trainerbattle_rematch_double TRAINER_PING, LavaridgeTown_Gym_1F_Text_FlanneryPreRematch, LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat, LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons
	msgbox LavaridgeTown_Gym_1F_Text_FlanneryPostRematch, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Cole::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_COLE, LOCALID_COLE, LavaridgeTown_Gym_1F_Text_ColeIntro, LavaridgeTown_Gym_1F_Text_ColeDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_ColePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_EventScript_CheckTrainerScript::
	call LavaridgeTown_Gym_1F_EventScript_SetTrainerTempVars
	release
	special ShouldTryGetTrainerScript
	goto_if_eq VAR_RESULT, 1, EventScript_GotoTrainerScript
	end

LavaridgeTown_Gym_1F_EventScript_Axle::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_COREY, LOCALID_AXLE, LavaridgeTown_Gym_1F_Text_AxleIntro, LavaridgeTown_Gym_1F_Text_AxleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_AxlePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Keegan::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_KEEGAN, LOCALID_KEEGAN, LavaridgeTown_Gym_B1F_Text_KeeganIntro, LavaridgeTown_Gym_B1F_Text_KeeganDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_KeeganPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Danielle::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_JIM, LOCALID_DANIELLE, LavaridgeTown_Gym_1F_Text_DanielleIntro, LavaridgeTown_Gym_1F_Text_DanielleDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_DaniellePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_Gerald::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_RUSSELL, LOCALID_GERALD, LavaridgeTown_Gym_1F_Text_GeraldIntro, LavaridgeTown_Gym_1F_Text_GeraldDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_1F_Text_GeraldPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Jace::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_KOGA_2, LOCALID_JACE, LavaridgeTown_Gym_B1F_Text_JaceIntro, LavaridgeTown_Gym_B1F_Text_JaceDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_JacePostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Jeff::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_JEFF, LOCALID_JEFF, LavaridgeTown_Gym_B1F_Text_JeffIntro, LavaridgeTown_Gym_B1F_Text_JeffDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_JeffPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_B1F_EventScript_Eli::
	trainerbattle TRAINER_BATTLE_CONTINUE_SCRIPT, TRAINER_ELI, LOCALID_ELI, LavaridgeTown_Gym_B1F_Text_EliIntro, LavaridgeTown_Gym_B1F_Text_EliDefeat, LavaridgeTown_Gym_EventScript_CheckTrainerScript
	msgbox LavaridgeTown_Gym_B1F_Text_EliPostBattle, MSGBOX_AUTOCLOSE
	end

LavaridgeTown_Gym_1F_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ECRUTEAK_CITY_GYM, LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory
	msgbox LavaridgeTown_Gym_1F_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_GymGuidePostVictory::
	msgbox LavaridgeTown_Gym_1F_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

LavaridgeTown_Gym_1F_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
	end

LavaridgeTown_Gym_1F_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE04_GET, LavaridgeTown_Gym_1F_EventScript_GymStatueCertified
	goto LavaridgeTown_Gym_1F_EventScript_GymStatue
	end

LavaridgeTown_Gym_1F_EventScript_GymStatueCertified::
	msgbox LavaridgeTown_Gym_1F_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_EventScript_GymStatue::
	msgbox LavaridgeTown_Gym_1F_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

LavaridgeTown_Gym_1F_Text_GymGuideAdvice:
	.string "Hé, comment ça\n"
	.string "va, futur CHAMPION\p"
	.string "{PLAYER} ?\n"
	.string "AUGUSTE, la CHAMPIONNE\p"
	.string "d'ARÈNE de LAVARIA,\n"
	.string "utilise des POKéMON de type FEU.\p"
	.string "Utilise des capacités\n"
	.string "EAU ou SOL !\l"
	.string "Bonne chance !$"

LavaridgeTown_Gym_1F_Text_GymGuidePostVictory:
	.string "Ouille ! C'était un combat brûlant !$"

LavaridgeTown_Gym_1F_Text_ColeIntro:
	.string "Aïe aïe aïe aïe !\n"
	.string "Ouh là, c'est chaud !$"

LavaridgeTown_Gym_1F_Text_ColeDefeat:
	.string "Je suis aveuglé par la sueur dans mes yeux…$"

LavaridgeTown_Gym_1F_Text_ColePostBattle:
	.string "Être enterré dans le sable chaud favorise\n"
	.string "la circulation.\p"
	.string "C'est efficace pour soulager les douleurs\n"
	.string "articulaires.$"

LavaridgeTown_Gym_1F_Text_AxleIntro:
	.string "J'essaie de me détendre.\n"
	.string "Ne viens pas m'ajouter du stress !$"

LavaridgeTown_Gym_1F_Text_AxleDefeat:
	.string "J'espère que ADRIANA va te carboniser !$"

LavaridgeTown_Gym_1F_Text_AxlePostBattle:
	.string "Haaah… Ouf…\p"
	.string "Si tu restes trop longtemps enfoui dans\n"
	.string "le sable chaud, ça t'épuise…$"

LavaridgeTown_Gym_B1F_Text_KeeganIntro:
	.string "Tu dois commencer à être fatigué.\n"
	.string "Tu aimerais te reposer dans le sable chaud,\l"
	.string "n'est-ce pas ?\p"
	.string "Mais tu devrais savoir que maintenir\n"
	.string "sa volonté est une capacité importante\l"
	.string "pour tous les DRESSEURS.$"

LavaridgeTown_Gym_B1F_Text_KeeganDefeat:
	.string "Joue avec le feu, et tu te brûleras…$"

LavaridgeTown_Gym_B1F_Text_KeeganPostBattle:
	.string "Ta compétence est réelle… Mais\n"
	.string "notre CHAMPIONNE ALIZÉE est forte.\p"
	.string "Si tu ne fais pas\n"
	.string "attention, tu seras sérieusement brûlé.$"

LavaridgeTown_Gym_1F_Text_GeraldIntro:
	.string "Tes POKéMON peuvent-ils supporter\n"
	.string "une chaleur de 200 °C ?$"

LavaridgeTown_Gym_1F_Text_GeraldDefeat:
	.string "Ça n'a pas assez brûlé fort…$"

LavaridgeTown_Gym_1F_Text_GeraldPostBattle:
	.string "La température du magma est\n"
	.string "de 392 degrés.\p"
	.string "Tes POKéMON m'ont battu, ils devraient\n"
	.string "facilement survivre dans le magma.$"

LavaridgeTown_Gym_1F_Text_DanielleIntro:
	.string "Euh…\n"
	.string "OK, je vais me battre avec toi.$"

LavaridgeTown_Gym_1F_Text_DanielleDefeat:
	.string "Oh, mais tu es trop fort.$"

LavaridgeTown_Gym_1F_Text_DaniellePostBattle:
	.string "Je vais devenir une DRESSEUSE jolie et forte\n"
	.string "comme FLORA.$"

LavaridgeTown_Gym_B1F_Text_JaceIntro:
	.string "Allez, debout !\n"
	.string "Partons avant que mes sentiments refroidissent !$"

LavaridgeTown_Gym_B1F_Text_JaceDefeat:
	.string "Il fait si chaud, et pourtant mon cœur\n"
	.string "est glacé…$"

LavaridgeTown_Gym_B1F_Text_JacePostBattle:
	.string "À en juger par ton esprit combatif,\n"
	.string "tu as peut-être une chance contre\l"
	.string "notre CHAMPION.$"

LavaridgeTown_Gym_B1F_Text_JeffIntro:
	.string "Tu vois comment les flammes brûlent sauvagement ?\n"
	.string "Elles s'embrasent en prévision de ma victoire !$"

LavaridgeTown_Gym_B1F_Text_JeffDefeat:
	.string "Quelque chose n'a pas marché.$"

LavaridgeTown_Gym_B1F_Text_JeffPostBattle:
	.string "Et alors ? Et alors ?\n"
	.string "Je peux marcher sur des braises à pieds nus !\p"
	.string "...N'y pense même pas d'essayer !$"

LavaridgeTown_Gym_B1F_Text_EliIntro:
	.string "Autant j'aime les montagnes,\n"
	.string "j'aime surtout les volcans.$"

LavaridgeTown_Gym_B1F_Text_EliDefeat:
	.string "Bon, il me semble que j'ai perdu sans\n"
	.string "jamais avoir eu le contrôle.$"

LavaridgeTown_Gym_B1F_Text_EliPostBattle:
	.string "Je reste ici parce que je suis devenu fan\n"
	.string "de la puissance de FLORA.\p"
	.string "Héhéhéhé.$"

LavaridgeTown_Gym_1F_Text_FlanneryIntro:
	.string "Bienvenue… Non, attends.\p"
	.string "Petit DRESSEUR, comme c'est bon de voir\n"
	.string "que tu es arrivé ici !\p"
	.string "On m'a confié le…\n"
	.string "Non, attends.\p"
	.string "Je suis AUGUSTE, et je suis la CHAMPIONNE\n"
	.string "d'ARÈNE ici !\p"
	.string "Euh…\n"
	.string "Ne me sous-estime pas, même si\l"
	.string "je suis CHAMPIONNE depuis peu de temps !\p"
	.string "Avec les compétences héritées de mon grand-\n"
	.string "père, je vais, euh… démontrer les\l"
	.string "capacités brûlantes qu'on a perfectionnées sur cette terre !$"

LavaridgeTown_Gym_1F_Text_FlanneryDefeat:
	.string "Oh…\n"
	.string "Je suppose que\p"
	.string "j'essayais trop fort…\n"
	.string "Je… Je suis devenue\p"
	.string "CHAMPIONNE d'ARÈNE\n"
	.string "récemment.\p"
	.string "J'ai essayé trop fort\n"
	.string "d'être parfaite…\p"
	.string "{PLAYER}{KUN}, merci\n"
	.string "pour tes conseils.$"

LavaridgeTown_Gym_1F_Text_ReceivedHeatBadge:
	.string "{PLAYER} a reçu le BADGE CHALEUR\n"
	.string "de FLORA.$"

LavaridgeTown_Gym_1F_Text_ExplainHeatBadgeTakeThis:
	.string "Si tu as un BADGE\n"
	.string "CHALEUR, tous\l"
	.string "les POKéMON\l"
	.string "jusqu'au niv. 50, même\p"
	.string "ceux des échanges,\n"
	.string "obéiront.\p"
	.string "Continue à collectionner\n"
	.string "des BADGES !$"

LavaridgeTown_Gym_1F_Text_ExplainOverheat:
	.string "La CT50 contient Surchauffe. Cette capacité\p"
	.string "inflige de graves dégâts à l'adversaire.\n"
	.string "Mais elle baisse aussi fortement\p"
	.string "l'ATQ. SPÉ. du POKéMON qui\n"
	.string "l'utilise. Elle ne convient peut-être\l"
	.string "pas pour les combats prolongés.$"

LavaridgeTown_Gym_1F_Text_RegisteredFlannery:
	.string "CHAMPIONNE D'ARÈNE FLORA\n"
	.string "enregistrée dans le POKéNAV.$"

LavaridgeTown_Gym_1F_Text_FlanneryPostBattle:
	.string "Ta puissance me rappelle quelqu'un...\p"
	.string "Oh ! Je sais ! Tu combats comme PIERRE,\n"
	.string "le CHAMPION D'ARÈNE de CLÉMENTI-VILLE.$"

LavaridgeTown_Gym_1F_Text_GymStatue:
	.string "ARÈNE POKéMON DE LAVARIDGE$"

LavaridgeTown_Gym_1F_Text_GymStatueCertified:
	.string "ARÈNE POKéMON DE LAVARIDGE\p"
	.string "DRESSEURS CERTIFIÉS DE FLORA :\n"
	.string "{PLAYER}$"

LavaridgeTown_Gym_1F_Text_FlanneryPreRematch:
	.string "FLANNERY : Perdre un combat ne va pas\n"
	.string "me dégonfler.\p"
	.string "J'adore les POKéMON.\n"
	.string "J'adore combattre.\l"
	.string "Et… j'adore cette ARÈNE !\p"
	.string "Échangeons des attaques brûlantes\n"
	.string "lors d'un autre combat !$"

LavaridgeTown_Gym_1F_Text_FlanneryRematchDefeat:
	.string "Ouf !\n"
	.string "Au bord de l'éruption !$"

LavaridgeTown_Gym_1F_Text_FlanneryPostRematch:
	.string "FLANNERY : J'ai perdu le combat,\n"
	.string "mais je suis totalement satisfaite.\p"
	.string "Il est rare que je profite d'un combat\n"
	.string "aussi intense.\p"
	.string "Refaisons-en un comme celui-là\n"
	.string "un de ces jours !$"

LavaridgeTown_Gym_1F_Text_FlanneryRematchNeedTwoMons:
	.string "AUGUSTE :\n"
	.string "Perdre un\p"
	.string "combat ne va pas\n"
	.string "me dégonfler.\l"
	.string "J'aime les POKéMON.\p"
	.string "J'aime combattre.\n"
	.string "Et… J'aime\p"
	.string "cette ARÈNE !\n"
	.string "{PLAYER},\p"
	.string "montre-moi\n"
	.string "ta passion !$"
