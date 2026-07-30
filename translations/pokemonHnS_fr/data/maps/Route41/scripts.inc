Route41_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route41_MapScript_OnTransition
	.byte 0

Route41_MapScript_OnTransition::
	goto_if_eq VAR_COMPLETED_LUGIA, 4, Route41_MapScript_DoNothing
	goto_if_ge VAR_OLIVINE_CITY_STATE, 5, OlivineCity_MapScript_ClearWeather
	end

Route41_MapScript_DoNothing::
	end

Route41_EventScript_Charlie::
	trainerbattle_single TRAINER_CHARLIE, Route41_Text_SwimmermCharlieSeen, Route41_Text_SwimmermCharlieBeaten
	msgbox Route41_Text_SwimmermCharlieAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermCharlieSeen:
	.string "L'eau est chaude ici.\n"
	.string "Je suis détendu et souple.\p"
	.string "Bien sûr, je t'affronte !$"

Route41_Text_SwimmermCharlieBeaten:
	.string "Aïe ! J'ai la peau des doigts plissée !$"

Route41_Text_SwimmermCharlieAfter:
	.string "Ce n'est pas relaxant de flotter\n"
	.string "comme ça ?$"

Route41_EventScript_George::
	trainerbattle_single TRAINER_GEORGE, Route41_Text_SwimmermGeorgeSeen, Route41_Text_SwimmermGeorgeBeaten
	msgbox Route41_Text_SwimmermGeorgeAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermGeorgeSeen:
	.string "Je suis un peu fatigué.\n"
	.string "Si je gagne, prête-moi ton POKéMON.$"

Route41_Text_SwimmermGeorgeBeaten:
	.string "Huff, huff…$"

Route41_Text_SwimmermGeorgeAfter:
	.string "C'est si loin jusqu'à IRISIA.\p"
	.string "Mais le retour vers OLIVILLE\n"
	.string "n'est pas facile non plus.\p"
	.string "Que dois-je faire ?$"

Route41_EventScript_Berke::
	trainerbattle_single TRAINER_BERKE, Route41_Text_SwimmermBerkeSeen, Route41_Text_SwimmermBerkeBeaten
	msgbox Route41_Text_SwimmermBerkeAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermBerkeSeen:
	.string "Vois ces îles bloquées par\n"
	.string "des tourbillons ?\p"
	.string "Il doit y avoir un secret !$"

Route41_Text_SwimmermBerkeBeaten:
	.string "Quel est le secret de\n"
	.string "ta force ?$"

Route41_Text_SwimmermBerkeAfter:
	.string "C'était une nuit sombre et orageuse…\p"
	.string "J'ai vu un POKéMON géant voler\n"
	.string "depuis les îles.\p"
	.string "Il dispersait des plumes\n"
	.string "de ses ailes argentées.$"

Route41_EventScript_Kirk::
	trainerbattle_single TRAINER_KIRK, Route41_Text_SwimmermKirkSeen, Route41_Text_SwimmermKirkBeaten
	msgbox Route41_Text_SwimmermKirkAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermKirkSeen:
	.string "Les vagues sont sauvages ici.\p"
	.string "Elles te fatiguent pendant\n"
	.string "que tu nages.$"

Route41_Text_SwimmermKirkBeaten:
	.string "Je suis crevé !$"

Route41_Text_SwimmermKirkAfter:
	.string "Les courants m'empêchent\n"
	.string "d'atteindre cette île.$"

Route41_EventScript_Mathew::
	trainerbattle_single TRAINER_MATHEW, Route41_Text_SwimmermMathewSeen, Route41_Text_SwimmermMathewBeaten
	msgbox Route41_Text_SwimmermMathewAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmermMathewSeen:
	.string "Tu cherches les secrets\n"
	.string "des ÎLES TOURBILLON ?$"

Route41_Text_SwimmermMathewBeaten:
	.string "Ooh, tu as une grande endurance !$"

Route41_Text_SwimmermMathewAfter:
	.string "Un secret sur les ÎLES TOURBILLON…\p"
	.string "C'est noir comme dans un four à l'intérieur !$"

Route41_EventScript_Kaylee::
	trainerbattle_single TRAINER_KAYLEE, Route41_Text_SwimmerfKayleeSeen, Route41_Text_SwimmerfKayleeBeaten
	msgbox Route41_Text_SwimmerfKayleeAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfKayleeSeen:
	.string "Je suis en route vers les ÎLES TOURBIÈRES.\p"
	.string "Je pars explorer avec des amis.$"

Route41_Text_SwimmerfKayleeBeaten:
	.string "C'est comme ça qu'on fait ?$"

Route41_Text_SwimmerfKayleeAfter:
	.string "On dit qu'il y a un grand POKéMON\n"
	.string "au fond des TOURBI'ÎLES.\p"
	.string "Je me demande ce que c'est ?$"

Route41_EventScript_Susie::
	trainerbattle_single TRAINER_SUSIE, Route41_Text_SwimmerfSusieSeen, Route41_Text_SwimmerfSusieBeaten
	msgbox Route41_Text_SwimmerfSusieAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfSusieSeen:
	.string "Tu as l'air si élégant\n"
	.string "en chevauchant ton POKéMON.$"

Route41_Text_SwimmerfSusieBeaten:
	.string "Je suis écrasé…$"

Route41_Text_SwimmerfSusieAfter:
	.string "Il n'y avait pas une chanson à succès\n"
	.string "sur un garçon chevauchant un LOKHLASS ?$"

Route41_EventScript_Denise::
	trainerbattle_single TRAINER_DENISE, Route41_Text_SwimmerfDeniseSeen, Route41_Text_SwimmerfDeniseBeaten
	msgbox Route41_Text_SwimmerfDeniseAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfDeniseSeen:
	.string "Le temps est si beau,\n"
	.string "je suis dans le brouillard !$"

Route41_Text_SwimmerfDeniseBeaten:
	.string "Ohhh !$"

Route41_Text_SwimmerfDeniseAfter:
	.string "Un coup de soleil, c'est le pire pour la peau.\p"
	.string "Mais je n'utilise pas de crème solaire.\p"
	.string "Je ne veux pas polluer l'eau.$"

Route41_EventScript_Kara::
	trainerbattle_single TRAINER_KARA, Route41_Text_SwimmerfKaraSeen, Route41_Text_SwimmerfKaraBeaten
	msgbox Route41_Text_SwimmerfKaraAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfKaraSeen:
	.string "Si tu as besoin de te reposer,\n"
	.string "reste à flot.\p"
	.string "Tu reprendras ton souffle\n"
	.string "et tu pourras continuer fort.$"

Route41_Text_SwimmerfKaraBeaten:
	.string "Oh ! Tu as plus d'énergie que moi.$"

Route41_Text_SwimmerfKaraAfter:
	.string "J'ai entendu des rugissements au fond\n"
	.string "des ÎLES.$"

Route41_EventScript_Wendy::
	trainerbattle_single TRAINER_WENDY, Route41_Text_SwimmerfWendySeen, Route41_Text_SwimmerfWendyBeaten
	msgbox Route41_Text_SwimmerfWendyAfter, MSGBOX_AUTOCLOSE
	end

Route41_Text_SwimmerfWendySeen:
	.string "La nuit, les STARPIE se rassemblent\n"
	.string "près de la surface de l'eau.$"

Route41_Text_SwimmerfWendyBeaten:
	.string "Oh, non…$"

Route41_Text_SwimmerfWendyAfter:
	.string "Les groupes de STARI s'illuminent\n"
	.string "en même temps.\p"
	.string "C'est si beau que c'est effrayant.$"

Route41_EventScript_Tentacruel1::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TENTACRUEL, CRY_MODE_NORMAL
	goto_if_ge VAR_TEMP_0, 2, Route41_EventScript_TentacruelAttack1
	msgbox Route41_Text_Tentacruel, MSGBOX_DEFAULT
	waitmoncry
	addvar VAR_TEMP_0, 1
	release
	end
Route41_EventScript_TentacruelAttack1::
	msgbox Route41_Text_TentacruelAttack, MSGBOX_DEFAULT
	waitmessage
	setflag FLAG_SYS_NO_CATCHING
	setflag FLAG_NO_SHINY
	setwildbattle SPECIES_TENTACRUEL, 100, ITEM_NONE
	dowildbattle
	closemessage
	clearflag FLAG_SYS_NO_CATCHING
	clearflag FLAG_NO_SHINY
	playse SE_USE_ITEM
	msgbox Route41_Text_TentacruelHeal, MSGBOX_DEFAULT
	setvar VAR_TEMP_0, 0
	closemessage
	release
	end

Route41_EventScript_Tentacruel2::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TENTACRUEL, CRY_MODE_NORMAL
	goto_if_ge VAR_TEMP_1, 2, Route41_EventScript_TentacruelAttack2
	msgbox Route41_Text_Tentacruel, MSGBOX_DEFAULT
	waitmoncry
	addvar VAR_TEMP_1, 1
	release
	end
Route41_EventScript_TentacruelAttack2::
	msgbox Route41_Text_TentacruelAttack, MSGBOX_DEFAULT
	waitmessage
	setwildbattle SPECIES_TENTACRUEL, 100, ITEM_NONE
	dowildbattle
	closemessage
	playse SE_USE_ITEM
	msgbox Route41_Text_TentacruelHeal, MSGBOX_DEFAULT
	setvar VAR_TEMP_1, 0
	closemessage
	release
	end

Route41_EventScript_Tentacruel3::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TENTACRUEL, CRY_MODE_NORMAL
	goto_if_ge VAR_TEMP_2, 2, Route41_EventScript_TentacruelAttack3
	msgbox Route41_Text_Tentacruel, MSGBOX_DEFAULT
	waitmoncry
	addvar VAR_TEMP_2, 1
	release
	end
Route41_EventScript_TentacruelAttack3::
	msgbox Route41_Text_TentacruelAttack, MSGBOX_DEFAULT
	waitmessage
	setwildbattle SPECIES_TENTACRUEL, 100, ITEM_NONE
	dowildbattle
	closemessage
	playse SE_USE_ITEM
	msgbox Route41_Text_TentacruelHeal, MSGBOX_DEFAULT
	setvar VAR_TEMP_2, 0
	closemessage
	release
	end

Route41_EventScript_Tentacruel4::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_TENTACRUEL, CRY_MODE_NORMAL
	goto_if_ge VAR_TEMP_3, 2, Route41_EventScript_TentacruelAttack4
	msgbox Route41_Text_Tentacruel, MSGBOX_DEFAULT
	waitmoncry
	addvar VAR_TEMP_3, 1
	release
	end
Route41_EventScript_TentacruelAttack4::
	msgbox Route41_Text_TentacruelAttack, MSGBOX_DEFAULT
	waitmessage
	setwildbattle SPECIES_TENTACRUEL, 100, ITEM_NONE
	dowildbattle
	closemessage
	playse SE_USE_ITEM
	msgbox Route41_Text_TentacruelHeal, MSGBOX_DEFAULT
	setvar VAR_TEMP_3, 0
	closemessage
	release
	end

Route41_Text_Tentacruel:
	.string "KRAKENOS : Cruooo...$"

Route41_Text_TentacruelAttack:
	.string "KRAKENOS : CRUOOOOOO !$"

Route41_Text_TentacruelHeal:
	.string "Le TENTACRUEL a utilisé SOIN !\n"
	.string "Il est complètement soigné !$"
