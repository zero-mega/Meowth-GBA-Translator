TinTower_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TinTower_OnTransition
	.byte 0

TinTower_OnTransition::
	setescapewarp MAP_BELLCHIME_TRAIL, 35, 42
	end

TinTower_1F_EventScript_SageA::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_STATE, 11, TinTower_1F_EventScript_SageA_Hooh
	msgbox TinTower_1F_Sage4_Text2, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower_1F_EventScript_SageA_Hooh::
	msgbox TinTower_1F_Sage4_Text1, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower_1F_EventScript_SageB::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_STATE, 11, TinTower_1F_EventScript_SageB_Hooh
	msgbox TinTower_1F_Sage2_Text, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower_1F_EventScript_SageB_Hooh::
	msgbox TinTower_1F_Sage1_Text, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower_1F_EventScript_SageC::
	lock
	faceplayer
	goto_if_eq VAR_ECRUTEAK_CITY_STATE, 11, TinTower_1F_EventScript_SageC_Hooh
	msgbox TinTower_1F_Sage6_Text2, MSGBOX_DEFAULT
	closemessage
	release
	end

TinTower_1F_EventScript_SageC_Hooh::
	msgbox TinTower_1F_Sage3_Text, MSGBOX_DEFAULT
	closemessage
	release
	end


TinTower_1F_Sage1_Text:
	.string "Selon la légende…\n"
	.string "Quand les âmes des POKéMON et des humains\p"
	.string "communient, du ciel descend un\n"
	.string "POKéMON aux couleurs de l'arc-en-ciel…\p"
	.string "Cela signifierait-il que les POKéMON\n"
	.string "légendaires nous mettent à l'épreuve ?$"

TinTower_1F_Sage2_Text:
	.string "Quand la\n"
	.string "TOUR DE\l"
	.string "CUIVRE a brûlé,\p"
	.string "trois POKéMON\p"
	.string "sans nom\n"
	.string "auraient\p"
	.string "péri. C'était\n"
	.string "tragique.\p"
	.string "Mais leur\n"
	.string "esprit\p"
	.string "vit encore…$"

TinTower_1F_Sage3_Text:
	.string "On dit que les deux TOURS ont été\n"
	.string "construites pour favoriser l'amitié et\p"
	.string "l'espoir entre les POKéMON et les humains.\n"
	.string "C'était il y a 700 ans, mais l'idéal\p"
	.string "reste important aujourd'hui.$"

TinTower_1F_Sage4_Text1:
	.string "HO-OH semble être descendu\n"
	.string "sur cette TOUR CENDRÉE !$"

TinTower_1F_Sage4_Text2:
	.string "On dit que les POKéMON légendaires\n"
	.string "incarnent trois pouvoirs…\p"
	.string "La foudre qui a frappé la TOUR.\n"
	.string "Le feu qui a brûlé la TOUR.\p"
	.string "Et la pluie qui a éteint le feu…$"

TinTower_1F_Sage6_Text2:
	.string "Parmi les POKéMON légendaires,\n"
	.string "SUICUNE serait le plus\p"
	.string "proche de HO-OH. J'ai\n"
	.string "entendu dire qu'il\p"
	.string "pourrait apparaître à\n"
	.string "la TOUR CENDRÉE.$"

TinTower_1F_EusineHoOh_Text:
	.string "Je le savais. Je savais que\p"
	.string "tu verrais le POKéMON aux couleurs\n"
	.string "de l'arc-en-ciel, <PLAYER>. C'est arrivé comme\p"
	.string "je l'avais imaginé. Mes recherches ne\n"
	.string "sont pas mauvaises, je dirais. Je\p"
	.string "vais continuer à étudier les POKéMON\n"
	.string "pour devenir un POKéMANIAC célèbre !$"

TinTower_1F_EusineSuicune_Text:
	.string "EUSINE : Génial ! Trop génial, même !\n"
	.string "Je n'ai jamais vu un combat aussi grand.\p"
	.string "C'était vraiment inspirant à voir.\n"
	.string "SUICUNE était dur, mais tu étais encore\p"
	.string "plus incroyable, <PLAYER>.\n"
	.string "J'ai entendu dire que le pouvoir mystique de SUICUNE\p"
	.string "invoque un POKéMON aux couleurs de l'arc-en-ciel.\n"
	.string "Peut-être, juste peut-être, ce\p"
	.string "qui s'est passé aujourd'hui\n"
	.string "fera apparaître ce POKéMON.\p"
	.string "Je vais étudier les légendes davantage.\n"
	.string "Merci de m'avoir montré ce combat fantastique.\p"
	.string "À plus, <PLAYER> !$"
