.set LOCALID_SPROUT_TOWER_SILVER, 5

SproutTower_3F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SproutTower_3F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

SproutTower_3F_OnTransition: 
	callnative SetTimeBasedEncounters
	end


SproutTower_3F_EventScript_SageJin::
	trainerbattle_single TRAINER_JIN SproutTower_Text_SageJin_Seen, SproutTower_Text_SageJin_Beaten
	msgbox SproutTower_Text_SageJin_AfterBattle, MSGBOX_AUTOCLOSE
	end


SproutTower_3F_EventScript_SageNeal::
	trainerbattle_single TRAINER_NEAL SproutTower_Text_SageNeal_Seen, SproutTower_Text_SageNeal_Beaten
	msgbox SproutTower_Text_SageNeal_AfterBattle, MSGBOX_AUTOCLOSE
	end

SproutTower_3F_EventScript_SageTroy::
	trainerbattle_single TRAINER_TROY SproutTower_Text_SageTroy_Seen, SproutTower_Text_SageTroy_Beaten
	msgbox SproutTower_Text_SageTroy_AfterBattle, MSGBOX_AUTOCLOSE
	end

SproutTower_3F_EventScript_Painting::
	lock
	msgbox SproutTower_Text_3F_Painting, MSGBOX_AUTOCLOSE
	release
	end

SproutTower_3F_EventScript_Potion::
	finditem ITEM_POTION
	end

SproutTower_3F_EventScript_EscapeRope::
	finditem ITEM_ESCAPE_ROPE
	end

SproutTower_3F_EventScript_TriggerSceneLeft::
	lock
	playbgm MUS_HG_ENCOUNTER_RIVAL, TRUE
	applymovement LOCALID_SPROUT_TOWER_SILVER, SproutTower_3F_Movement_Silver1
	waitmovement 0
	msgbox SproutTower_Text_ElderLecturesRival, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_SPROUT_TOWER_SILVER, Common_Movement_ExclamationMark	
	delay 60
	applymovement LOCALID_SPROUT_TOWER_SILVER, SproutTower_3F_Movement_SilverLeft
	waitmovement 0
	msgbox SproutTower_Text_RivalOnlyCaresStrong, MSGBOX_DEFAULT
	delay 30
	msgbox SproutTower_Text_RivalUsedEscapeRope, MSGBOX_DEFAULT
	applymovement LOCALID_SPROUT_TOWER_SILVER SproutTower_3F_Movement_EscapeRope
	waitmovement 0
	closemessage
	fadescreen FADE_TO_BLACK
	playse SE_EXIT
	setflag FLAG_HIDE_SPROUT_TOWER_SILVER
	removeobject LOCALID_SPROUT_TOWER_SILVER
	delay 55
	fadescreen FADE_FROM_BLACK
	special DrawWholeMapView
	fadedefaultbgm
	setvar VAR_SPROUT_TOWER, 1
	release
	end

SproutTower_3F_EventScript_TriggerSceneRight::
	lock
	playbgm MUS_HG_ENCOUNTER_RIVAL, TRUE
	applymovement LOCALID_SPROUT_TOWER_SILVER, SproutTower_3F_Movement_Silver1
	waitmovement 0
	msgbox SproutTower_Text_ElderLecturesRival, MSGBOX_DEFAULT
	closemessage
	playse SE_PIN
	applymovement LOCALID_SPROUT_TOWER_SILVER, Common_Movement_ExclamationMark	
	delay 60
	applymovement LOCALID_SPROUT_TOWER_SILVER, SproutTower_3F_Movement_SilverRight
	waitmovement 0
	waitmovement 0
	msgbox SproutTower_Text_RivalOnlyCaresStrong, MSGBOX_DEFAULT
	msgbox SproutTower_Text_RivalUsedEscapeRope, MSGBOX_DEFAULT
	applymovement LOCALID_SPROUT_TOWER_SILVER SproutTower_3F_Movement_EscapeRope
	waitmovement 0
	closemessage
	fadescreen FADE_TO_BLACK
	playse SE_EXIT
	setflag FLAG_HIDE_SPROUT_TOWER_SILVER
	removeobject LOCALID_SPROUT_TOWER_SILVER
	delay 55
	fadescreen FADE_FROM_BLACK
	special DrawWholeMapView
	fadedefaultbgm
	setvar VAR_SPROUT_TOWER, 1
	release
	end

SproutTower_3F_EventScript_SageLi::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_FLASH, SproutTower_3F_EventScript_SageLi_Beaten
	msgbox SproutTower_Text_SageLi_Seen, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_LI, SproutTower_Text_SageLi_Beaten
	msgbox SproutTower_Text_SageLi_TakeFlash, MSGBOX_DEFAULT
	giveitem ITEM_HM_FLASH
	setflag FLAG_RECEIVED_HM_FLASH
	msgbox SproutTower_Text_SageLi_FlashExplain, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_3F_EventScript_SageLi_Beaten::
	msgbox SproutTower_Text_SageLi_AfterBattle, MSGBOX_DEFAULT
	closemessage
	release
	end

SproutTower_3F_Movement_Silver1:
	walk_fast_up
	walk_fast_up
	step_end

SproutTower_3F_Movement_SilverLeft:
	face_down
	delay_16
	walk_right
	walk_right
	walk_down
	walk_down
	step_end

SproutTower_3F_Movement_SilverRight:
	face_down
	delay_16
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	step_end

SproutTower_3F_Movement_EscapeRope:
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	face_right
	face_up
	face_left
	face_down
	step_end

SproutTower_Text_ElderLecturesRival:
	.string "DOYEN : Tu es en effet\n"
	.string "habile comme dresseur. Comme promis, voici\p"
	.string "ta CS. Mais laisse-moi te\p"
	.string "dire : tu devrais traiter\n"
	.string "tes POKéMON mieux. Ta façon\p"
	.string "de combattre est bien trop\n"
	.string "brutale. Les POKéMON ne sont\p"
	.string "pas des outils de guerre…$"

SproutTower_Text_RivalOnlyCaresStrong:
	.string "…\n"
	.string "…Humph !\p"
	.string "Il prétend être le DOYEN mais\n"
	.string "il est faible.\p"
	.string "C'est logique.\p"
	.string "Je ne perdrais jamais contre des\n"
	.string "imbéciles qui parlent d'être gentils\p"
	.string "avec les POKéMON.\n"
	.string "Je ne m'intéresse qu'aux POKéMON\p"
	.string "forts qui peuvent gagner.\n"
	.string "Les POKéMON faibles, je m'en fiche complètement.$"

SproutTower_Text_RivalUsedEscapeRope:
	.string "{RIVAL} a utilisé une CORDE SORTIE !$"

SproutTower_Text_SageLi_Seen:
	.string "Si gentil de ta part\p"
	.string "de venir ici ! La\n"
	.string "TOUR CHETIFLOR est un lieu\p"
	.string "d'entraînement. Les gens et les\n"
	.string "POKéMON testent leurs liens pour\l"
	.string "construire un avenir radieux ensemble.\p"
	.string "Je suis l'épreuve finale. Laisse-moi\p"
	.string "vérifier les liens entre tes\n"
	.string "POKéMON et toi !$"

SproutTower_Text_SageLi_Beaten:
	.string "Ah, excellent !$"

SproutTower_Text_SageLi_TakeFlash:
	.string "Toi et tes POKéMON n'aurez aucun problème\n"
	.string "à utiliser cette capacité.\p"
	.string "Prends cette CS FLASH.$"

SproutTower_Text_SageLi_FlashExplain:
	.string "FLASH éclaire même les endroits les\n"
	.string "plus sombres. Mais pour l'utiliser hors\p"
	.string "combat, il te faut le\n"
	.string "BADGE de l'ARÈNE de MAUVILLE.$"

SproutTower_Text_SageLi_AfterBattle:
	.string "J'espère que tu apprendras et grandiras\n"
	.string "grâce à ton voyage.$"

SproutTower_Text_SageJin_Seen:
	.string "Je m'entraîne pour trouver l'illumination\n"
	.string "grâce aux POKéMON !$"

SproutTower_Text_SageJin_Beaten:
	.string "Mon entraînement est incomplet…$"

SproutTower_Text_SageJin_AfterBattle:
	.string "Plus les POKéMON deviennent\n"
	.string "forts, plus le DRESSEUR\p"
	.string "aussi. Non, attends. Plus\n"
	.string "le DRESSEUR devient fort,\l"
	.string "plus les POKéMON aussi.$"

SproutTower_Text_SageTroy_Seen:
	.string "Laisse-moi voir à quel point tu fais\n"
	.string "confiance à tes POKéMON.$"

SproutTower_Text_SageTroy_Beaten:
	.string "Oui, ta confiance est sincère !$"

SproutTower_Text_SageTroy_AfterBattle:
	.string "Ce n'est pas loin du DOYEN.$"

SproutTower_Text_SageNeal_Seen:
	.string "La CS du SAGE éclaire\n"
	.string "même l'obscurité totale.$"

SproutTower_Text_SageNeal_Beaten:
	.string "C'est ma tête qui est brillante !$"

SproutTower_Text_SageNeal_AfterBattle:
	.string "Que la lumière éclaire\n"
	.string "ton voyage.$"

SproutTower_Text_3F_Painting:
	.string "C'est un tableau puissant d'un\n"
	.string "CHENIPAN.$"
