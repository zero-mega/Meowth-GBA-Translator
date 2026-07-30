PewterCity_Museum_2F_MapScripts::
	.byte 0


PewterCity_Museum_2F_EventScript_Nerd::
	msgbox PewterCity_Museum_2F_Text_Nerd, MSGBOX_NPC
	end

PewterCity_Museum_2F_EventScript_Daughter::
	lock
	msgbox PewterCity_Museum_2F_Text_AskedDaddyToCatchPikachu, MSGBOX_DEFAULT
	release
	end

PewterCity_Museum_2F_EventScript_Dad::
	lock
	msgbox PewterCity_Museum_2F_Text_PikachuSoonIPromise, MSGBOX_DEFAULT
	release
	end

PewterCity_Museum_2F_EventScript_Meteor::
	msgbox PewterCity_Museum_2F_Text_MeteoriteThatFellOnMtMoon, MSGBOX_SIGN
	end

PewterCity_Museum_2F_Text_Nerd:
	.string "On dit que des météorites ont frappé\n"
	.string "l'ÎLE NAISSANCE.\p"
	.string "On aimerait les exposer ici\n"
	.string "dans notre musée, mais...\p"
	.string "Ces météorites émettraient\n"
	.string "une étrange énergie et ne peuvent pas\l"
	.string "être emportées...$"

PewterCity_Museum_2F_Text_AskedDaddyToCatchPikachu::
    .string "Je veux un PIKACHU !\n"
    .string "Il est si mignon !\p"
    .string "J'ai demandé à papa de m'en attraper un !$"

PewterCity_Museum_2F_Text_PikachuSoonIPromise::
    .string "Oui, un PIKACHU bientôt, promis !$"

PewterCity_Museum_2F_Text_SpaceShuttle::
    .string "Navette spatiale$"

PewterCity_Museum_2F_Text_MeteoriteThatFellOnMtMoon::
    .string "Une météorite tombée sur le MONT LUNE.\n"
    .string "On pense que c'est une PIERRE LUNE.$"
