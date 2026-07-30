GoldenrodCity_RadioTower_2F_MapScripts::
	.byte 0

GoldenrodRaidoTower2_EventScript_Grunt3::
	trainerbattle_single TRAINER_GRUNT_3 GoldenrodCity_RadioTower_2F_Text_GruntM4Seen, GoldenrodCity_RadioTower_2F_Text_GruntM4Beaten
	msgbox GoldenrodCity_RadioTower_2F_Text_GruntM4After, MSGBOX_AUTOCLOSE
	end
GoldenrodRaidoTower2_EventScript_Grunt4::
	trainerbattle_single TRAINER_GRUNT_4 GoldenrodCity_RadioTower_2F_Text_GruntM5Seen, GoldenrodCity_RadioTower_2F_Text_GruntM5Beaten
	msgbox GoldenrodCity_RadioTower_2F_Text_GruntM5After, MSGBOX_AUTOCLOSE
	end
GoldenrodRaidoTower2_EventScript_Grunt5::
	trainerbattle_single TRAINER_GRUNT_5 GoldenrodCity_RadioTower_2F_Text_GruntM6Seen, GoldenrodCity_RadioTower_2F_Text_GruntM6Beaten
	msgbox GoldenrodCity_RadioTower_2F_Text_GruntM6After, MSGBOX_AUTOCLOSE
	end
GoldenrodRaidoTower2_EventScript_GruntF2::
	trainerbattle_single TRAINER_GRUNT_26 GoldenrodCity_RadioTower_2F_Text_GruntF2Seen, GoldenrodCity_RadioTower_2F_Text_GruntF2Beaten
	msgbox GoldenrodCity_RadioTower_2F_Text_GruntF2After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_RadioTower_2F_EventScript_Sign1::
	lock
	msgbox GoldenrodCity_RadioTower_2F_Text_SalesSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Sign2::
	lock
	msgbox GoldenrodCity_RadioTower_2F_Text_OakTalkSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Boy::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_2F_Text_SuperNerd, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Policeman::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_2F_Text_Policeman, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Buena::
	lock
	faceplayer
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 6, GoldenrodCity_RadioTower_2F_EventScript_Buena2
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 7, GoldenrodCity_RadioTower_2F_EventScript_Buena2
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 8, GoldenrodCity_RadioTower_2F_EventScript_Buena2
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 9, GoldenrodCity_RadioTower_2F_EventScript_Buena2
	msgbox GoldenrodCity_RadioTower_2F_Text_BuenaShowPromo, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Buena2::
	msgbox RadioTower2FBuenaPasswordIsHelpText, MSGBOX_DEFAULT
	closemessage
	release
	end


GoldenrodCity_RadioTower_2F_EventScript_Teacher::
	lock
	faceplayer
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 6, GoldenrodCity_RadioTower_2F_EventScript_Teacher2
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 7, GoldenrodCity_RadioTower_2F_EventScript_Teacher2 
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 8, GoldenrodCity_RadioTower_2F_EventScript_Teacher2 
	goto_if_eq VAR_GOLDENROD_CITY_STATE, 9, GoldenrodCity_RadioTower_2F_EventScript_Teacher2 
	msgbox GoldenrodCity_RadioTower_2F_Text_Teacher, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Teacher2::
	msgbox GoldenrodCity_RadioTower_2F_Text_TeacherRockets, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_2F_EventScript_Jigglypuff::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_JIGGLYPUFF, CRY_MODE_NORMAL
	msgbox GoldenrodCity_RadioTower_2F_Text_Jigglypuff, MSGBOX_DEFAULT
	waitmoncry
	release
	end

RadioTower2FBuenaPasswordIsHelpText:
	.string "BUENA : Hein ? Le mot de passe d'aujourd'hui ?\n"
	.string "AIDE, bien sûr !$"

GoldenrodCity_RadioTower_2F_Text_SuperNerd:
	.string "Tu peux écouter la radio\n"
	.string "partout. Allume-la !$"

GoldenrodCity_RadioTower_2F_Text_Policeman:
	.string "Accès interdit au-delà de\n"
	.string "ce point.$"

GoldenrodCity_RadioTower_2F_Text_Teacher:
	.string "Les berceuses à la radio peuvent\n"
	.string "endormir les POKéMON.$"

GoldenrodCity_RadioTower_2F_Text_TeacherRockets:
	.string "Pourquoi voudraient-ils s'emparer\n"
	.string "de la TOUR RADIO ?$"

GoldenrodCity_RadioTower_2F_Text_Jigglypuff:
	.string "RONDOUDOU : Jiggly…$"

GoldenrodCity_RadioTower_2F_Text_BlackBelt1:
	.string "Désolé. Personnel autorisé\n"
	.string "uniquement au-delà de ce point.\p"
	.string "Avant, ce n'était pas comme ça.\p"
	.string "Il y a quelque chose qui cloche\n"
	.string "avec le DIRECTEUR…$"

GoldenrodCity_RadioTower_2F_Text_BlackBelt2:
	.string "N'hésite pas à regarder partout.\p"
	.string "Le DIRECTEUR est redevenu sympa,\n"
	.string "comme avant.$"

GoldenrodCity_RadioTower_2F_Text_GruntM4Seen:
	.string "Il y a trois ans, la TEAM ROCKET a été\n"
	.string "forcée de se dissoudre.\p"
	.string "Mais on fait un retour ici !$"

GoldenrodCity_RadioTower_2F_Text_GruntM4Beaten:
	.string "Gwah ! Pas de façons !$"

GoldenrodCity_RadioTower_2F_Text_GruntM4After:
	.string "On ne te laissera pas gâcher\n"
	.string "nos plans de retour !$"

GoldenrodCity_RadioTower_2F_Text_GruntM5Seen:
	.string "Nous sommes la TEAM ROCKET, les exploiteurs\n"
	.string "de POKéMON !\p"
	.string "On adore être méchants ! Tu as peur ?$"

GoldenrodCity_RadioTower_2F_Text_GruntM5Beaten:
	.string "Tu te prends pour un héros ?$"

GoldenrodCity_RadioTower_2F_Text_GruntM5After:
	.string "On n'est pas toujours méchants.\n"
	.string "On fait juste ce qu'on veut.$"

GoldenrodCity_RadioTower_2F_Text_GruntM6Seen:
	.string "Hé, hé ! Ne nous gêne pas !$"

GoldenrodCity_RadioTower_2F_Text_GruntM6Beaten:
	.string "Arggh. J'abandonne.$"

GoldenrodCity_RadioTower_2F_Text_GruntM6After:
	.string "Nos CADRES essaient de s'emparer\n"
	.string "de cet endroit.\p"
	.string "Ils ont un grand plan. Je me demande\n"
	.string "ce que c'est ?$"

GoldenrodCity_RadioTower_2F_Text_GruntF2Seen:
	.string "Hahaha !\p"
	.string "Comme c'est ennuyeux. C'était beaucoup trop facile\n"
	.string "de s'emparer de cet endroit !\p"
	.string "Allez, amuse-moi un peu !$"

GoldenrodCity_RadioTower_2F_Text_GruntF2Beaten:
	.string "Q-qui es-tu ?$"

GoldenrodCity_RadioTower_2F_Text_GruntF2After:
	.string "Tu m'as battu, et je ne l'oublierai\n"
	.string "pas !$"

GoldenrodCity_RadioTower_2F_Text_BuenaShowPromo:
	.string "BUENA : Écoute mon ÉMISSION\n"
	.string "MOT DE PASSE !$"

GoldenrodCity_RadioTower_2F_Text_SalesSign:
	.string "2E VENTES$"

GoldenrodCity_RadioTower_2F_Text_OakTalkSign:
	.string "POKéMON A TOUT PRIX DU PROF.CHEN\p"
	.string "L'émission la plus populaire !$"

GoldenrodCity_RadioTower_2F_Text_PokemonRadioSign:
	.string "Radio POKéMON partout, à tout moment$"
