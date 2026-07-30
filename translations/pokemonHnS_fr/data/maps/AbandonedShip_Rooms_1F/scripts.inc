AbandonedShip_Rooms_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SetTimeEncounters
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

AbandonedShip_Rooms_1F_EventScript_Gentleman::
	msgbox AbandonedShip_Rooms_1F_Text_TakingALookAround, MSGBOX_NPC
	end

AbandonedShip_Rooms_1F_EventScript_Demetrius::
	trainerbattle_single TRAINER_JULIA, AbandonedShip_Rooms_1F_Text_DemetriusIntro, AbandonedShip_Rooms_1F_Text_DemetriusDefeat
	msgbox AbandonedShip_Rooms_1F_Text_DemetriusPostBattle, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms_1F_EventScript_Thalia::
	trainerbattle_single TRAINER_THALIA_1, AbandonedShip_Rooms_1F_Text_ThaliaIntro, AbandonedShip_Rooms_1F_Text_ThaliaDefeat, AbandonedShip_Rooms_1F_EventScript_RegisterThalia
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, AbandonedShip_Rooms_1F_EventScript_ThaliaRematch
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaPostBattle, MSGBOX_DEFAULT
	release
	end

AbandonedShip_Rooms_1F_EventScript_RegisterThalia::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_THALIA_1
	release
	end

AbandonedShip_Rooms_1F_EventScript_ThaliaRematch::
	trainerbattle_rematch TRAINER_THALIA_1, AbandonedShip_Rooms_1F_Text_ThaliaRematchIntro, AbandonedShip_Rooms_1F_Text_ThaliaRematchDefeat
	msgbox AbandonedShip_Rooms_1F_Text_ThaliaPostRematch, MSGBOX_AUTOCLOSE
	end

AbandonedShip_Rooms_1F_Text_TakingALookAround:
	.string "Les navires de ce type sont rares,\n"
	.string "alors je fais le tour.\p"
	.string "Hmhm...\n"
	.string "Il semble y avoir d'autres cabines...$"

AbandonedShip_Rooms_1F_Text_ThaliaIntro:
	.string "Qu'est-ce qui te pousse à venir ici ?\n"
	.string "Tu dois être curieux !$"

AbandonedShip_Rooms_1F_Text_ThaliaDefeat:
	.string "Pas seulement curieux, mais aussi fort…$"

AbandonedShip_Rooms_1F_Text_ThaliaPostBattle:
	.string "L'homme d'à côté…\p"
	.string "Il dit qu'il fait du tourisme,\n"
	.string "mais je n'en suis pas sûre.$"

AbandonedShip_Rooms_1F_Text_ThaliaRegister:
	.string "Tu es un DRESSEUR si fort !\n"
	.string "Laisse-moi t'enregistrer en souvenir !$"

AbandonedShip_Rooms_1F_Text_ThaliaRematchIntro:
	.string "Qu'est-ce qui te pousse à revenir ?\n"
	.string "Tu dois vraiment être curieux !$"

AbandonedShip_Rooms_1F_Text_ThaliaRematchDefeat:
	.string "Tu n'es pas un peu trop fort ?$"

AbandonedShip_Rooms_1F_Text_ThaliaPostRematch:
	.string "Je suis sûr que cet homme prépare quelque chose !\n"
	.string "Il agit de façon si suspecte !$"

AbandonedShip_Rooms_1F_Text_DemetriusIntro:
	.string "Waaah !\n"
	.string "On m'a trouvé ! …Hein ?$"

AbandonedShip_Rooms_1F_Text_DemetriusDefeat:
	.string "Oh, tu n'es pas maman.$"

AbandonedShip_Rooms_1F_Text_DemetriusPostBattle:
	.string "J'ai des ennuis avec maman, alors je me suis enfui.\n"
	.string "Garde secret où je suis !$"

