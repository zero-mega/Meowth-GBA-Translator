VictoryRoad_B2F_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, VictoryRoad_B2F_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, VictoryRoad_B2F_OnTransition
	.byte 0

VictoryRoad_B2F_OnResume:
	callnative SetTimeBasedEncounters
	end

VictoryRoad_B2F_OnTransition:
	callnative SetTimeBasedEncounters
	goto_if_set FLAG_UNLOCK_BIRDS, VictoryRoad_B2F_SwitchToModern
	end

VictoryRoad_B2F_SwitchToModern::
	setmaplayoutindex LAYOUT_VICTORY_ROAD_B2F_MODERN
	end

VictoryRoad_B2F_EventScript_Vito::
	trainerbattle_single TRAINER_VITO, VictoryRoad_B2F_Text_VitoIntro, VictoryRoad_B2F_Text_VitoDefeat
	msgbox VictoryRoad_B2F_Text_VitoPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Owen::
	trainerbattle_single TRAINER_OWEN, VictoryRoad_B2F_Text_OwenIntro, VictoryRoad_B2F_Text_OwenDefeat
	msgbox VictoryRoad_B2F_Text_OwenPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Caroline::
	trainerbattle_single TRAINER_CAROLINE, VictoryRoad_B2F_Text_CarolineIntro, VictoryRoad_B2F_Text_CarolineDefeat
	msgbox VictoryRoad_B2F_Text_CarolinePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Julie::
	trainerbattle_single TRAINER_JULIE, VictoryRoad_B2F_Text_JulieIntro, VictoryRoad_B2F_Text_JulieDefeat
	msgbox VictoryRoad_B2F_Text_JuliePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Felix::
	trainerbattle_single TRAINER_NORMAN, VictoryRoad_B2F_Text_FelixIntro, VictoryRoad_B2F_Text_FelixDefeat
	msgbox VictoryRoad_B2F_Text_FelixPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Dianne::
	trainerbattle_single TRAINER_KENJI, VictoryRoad_B2F_Text_DianneIntro, VictoryRoad_B2F_Text_DianneDefeat
	msgbox VictoryRoad_B2F_Text_DiannePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_Text_VitoIntro:
	.string "J'ai tout entraîné en famille,\n"
	.string "chacun d'entre nous !\l"
	.string "Je ne perds contre personne !$"

VictoryRoad_B2F_Text_VitoDefeat:
	.string "Mieux que ma famille ?!\n"
	.string "C'est possible ?!$"

VictoryRoad_B2F_Text_VitoPostBattle:
	.string "J'étais meilleur que tout le monde\n"
	.string "dans ma famille. Je n'avais jamais\p"
	.string "perdu avant… J'ai perdu confiance… Je\n"
	.string "vais peut-être rentrer chez moi…$"

VictoryRoad_B2F_Text_OwenIntro:
	.string "J'avais entendu qu'il y avait un petit\n"
	.string "gamin costaud dans le coin. C'est toi ?$"

VictoryRoad_B2F_Text_OwenDefeat:
	.string "Le petit morpion est coriace !$"

VictoryRoad_B2F_Text_OwenPostBattle:
	.string "Les rumeurs disaient qu'un petit dur\n"
	.string "vient de POIVRESSE.$"

VictoryRoad_B2F_Text_CarolineIntro:
	.string "Tu dois commencer à être un peu fatigué.$"

VictoryRoad_B2F_Text_CarolineDefeat:
	.string "Aucun signe de fatigue !$"

VictoryRoad_B2F_Text_CarolinePostBattle:
	.string "La ROUTE VICTOIRE et la LIGUE POKéMON\n"
	.string "sont des défis longs et épuisants.\l"
	.string "Attention à la fatigue !$"

VictoryRoad_B2F_Text_JulieIntro:
	.string "Tu ne devrais pas te reposer sur tes lauriers\n"
	.string "juste parce que tu as beaucoup de BADGES D'ARÈNE.\p"
	.string "Il y aura toujours quelqu'un\n"
	.string "qui sera meilleur que toi !$"

VictoryRoad_B2F_Text_JulieDefeat:
	.string "Tu es meilleur que moi !$"

VictoryRoad_B2F_Text_JuliePostBattle:
	.string "Contemple tes BADGES collectés et\n"
	.string "souviens-toi des DRESSEURS que tu as affrontés.$"

VictoryRoad_B2F_Text_FelixIntro:
	.string "Je suis arrivé jusqu'ici, mais la tension\n"
	.string "me donne d'affreuses douleurs à l'estomac…$"

VictoryRoad_B2F_Text_FelixDefeat:
	.string "Ooh…\n"
	.string "Ça fait mal…$"

VictoryRoad_B2F_Text_FelixPostBattle:
	.string "Je ne peux pas m'empêcher d'être tendu en sachant\n"
	.string "que j'approche de la LIGUE POKéMON. Tout ce\p"
	.string "que je peux faire, c'est feindre le calme.$"

VictoryRoad_B2F_Text_DianneIntro:
	.string "L'élite parmi l'élite se rassemble\n"
	.string "dans cette grotte.\p"
	.string "Comment la trouves-tu ?$"

VictoryRoad_B2F_Text_DianneDefeat:
	.string "Pas le moindre signe de panique !$"

VictoryRoad_B2F_Text_DiannePostBattle:
	.string "Tu as du cran ! J'aime ça !\n"
	.string "Continue !$"

