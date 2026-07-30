.set LOCALID_NURSE, 1

CeladonCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CeladonCity_PokemonCenter_OnTransition
	.byte 0

CeladonCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_CELADON_CITY
	end

CeladonCity_PokemonCenter_EventScript_CooltrainerF::
	msgbox CeladonCity_PokemonCenter1F_Text_CooltrainerF, MSGBOX_NPC
	end

CeladonCity_PokemonCenter_EventScript_Pharmacist::
	msgbox CeladonCity_PokemonCenter1F_Text_Pharmacist, MSGBOX_NPC
	end

CeladonCity_PokemonCenter_EventScript_Eusine::
	msgbox Celadon_Text_Eusine1, MSGBOX_NPC
	end

CeladonCity_PokemonCenter1F_Text_CooltrainerF:
	.string "ERIKA est une maîtresse des POKéMON\n"
	.string "Plante.\p"
	.string "Elle te fera payer si tu ne\n"
	.string "fais pas attention.$"

CeladonCity_PokemonCenter1F_Text_Pharmacist:
	.string "Le REPAIRE de la TEAM ROCKET est dans\n"
	.string "la cave de la SALLE DE JEUX.\p"
	.string "Oh, attends. C'était il y a\n"
	.string "trois ans.$"

Celadon_Text_Eusine1:
	.string "EUSINE : Salut !\p"
	.string "Je suis de retour dans ma ville natale.\p"
	.string "Ça fait un bon moment.$"

Celadon_Text_EusineLeaves:
	.string "{PLAYER}, tu as entendu\p"
	.string "? Il y a\n"
	.string "de nouvelles rumeurs sur\n"
	.string "un POKéMON aux couleurs\p"
	.string "de l'arc-en-ciel apparu à\n"
	.string "{STR_VAR_1}. Tu devrais\p"
	.string "aller voir !$"

Celadon_Text_NoBeasts:
	.string "Oh, au fait, {PLAYER}.\p"
	.string "As-tu attrapé les POKéMON\n"
	.string "légendaires RAIKOU et ENTEI\p"
	.string "? <……><……><……> D'accord… Si\p"
	.string "tu en attrapes même\p"
	.string "un, j'espère que tu\n"
	.string "m'en informeras. Je compte\p"
	.string "sur toi, {PLAYER} !$"
