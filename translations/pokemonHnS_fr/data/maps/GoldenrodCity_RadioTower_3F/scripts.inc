GoldenrodCity_RadioTower_3F_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, GoldenrodCity_RadioTower_3F_OnLoad
	.byte 0

GoldenrodCity_RadioTower_3F_OnLoad::
	call_if_set FLAG_HIDE_RADIOTOWER_GATE, GoldenrodCity_RadioTower_3F_HideGate
	end
	
GoldenrodCity_RadioTower_3F_HideGate::
	setmetatile 25, 8, 0x335, FALSE
	setmetatile 25, 9, 0x335, FALSE

	setmetatile 26, 8, 0X334, FALSE
	setmetatile 26, 9, 0X334, FALSE

	setmetatile 27, 8, 0X334, FALSE
	setmetatile 27, 9, 0X334, FALSE

	setmetatile 28, 8, 0X334, FALSE
	setmetatile 28, 9, 0X334, FALSE

	setmetatile 29, 8, 0X334, FALSE
	setmetatile 29, 9, 0X334, FALSE

	setmetatile 30, 8, 0X334, FALSE
	setmetatile 30, 9, 0X334, FALSE

	setmetatile 31, 8, 0X334, FALSE
	setmetatile 31, 9, 0X334, FALSE
	return


GoldenrodRaidoTower3_EventScript_Grunt6::
	trainerbattle_single TRAINER_GRUNT_6 GoldenrodCity_RadioTower_3F_Text_GruntM7Seen, GoldenrodCity_RadioTower_3F_Text_GruntM7Beaten
	msgbox GoldenrodCity_RadioTower_3F_Text_GruntM7After, MSGBOX_AUTOCLOSE
	end

GoldenrodRaidoTower3_EventScript_Grunt7::
	trainerbattle_single TRAINER_GRUNT_7 GoldenrodCity_RadioTower_3F_Text_GruntM8Seen, GoldenrodCity_RadioTower_3F_Text_GruntM8Beaten
	msgbox GoldenrodCity_RadioTower_3F_Text_GruntM8After, MSGBOX_AUTOCLOSE
	end

GoldenrodRaidoTower3_EventScript_Grunt8::
	trainerbattle_single TRAINER_GRUNT_8 GoldenrodCity_RadioTower_3F_Text_GruntM9Seen, GoldenrodCity_RadioTower_3F_Text_GruntM9Beaten
	msgbox GoldenrodCity_RadioTower_3F_Text_GruntM9After, MSGBOX_AUTOCLOSE
	end

GoldenrodRaidoTower3_EventScript_Scientist::
	trainerbattle_single TRAINER_MARC GoldenrodCity_RadioTower_3F_Text_ScientistMarcSeen, GoldenrodCity_RadioTower_3F_Text_ScientistMarcBeaten
	msgbox GoldenrodCity_RadioTower_3F_Text_ScientistMarcAfter, MSGBOX_AUTOCLOSE
	end


GoldenrodCity_RadioTower_3F_EventScript_Cooltrainer::
	lock
	faceplayer
	goto_if_set FLAG_GOT_SKILL_SWAP, GoldenrodCity_RadioTower_3F_EventScript_Cooltrainer3
	goto_if_ge VAR_GOLDENROD_CITY_STATE, 10, GoldenrodCity_RadioTower_3F_EventScript_Cooltrainer2

	msgbox GoldenrodCity_RadioTower_3F_Text_CooltrainerFPleaseSave, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Cooltrainer2::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_3F_Text_CooltrainerFHeroGift, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_TM_SKILL_SWAP
	setflag FLAG_GOT_SKILL_SWAP
	msgbox GoldenrodCity_RadioTower_3F_Text_CooltrainerFSunnyDay, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Cooltrainer3::
	msgbox GoldenrodCity_RadioTower_3F_Text_CooltrainerFMarvelous, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Nerd::
	lock
	faceplayer
	msgbox GoldenrodCity_RadioTower_3F_Text_SuperNerd, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Gate::
	lock
	msgbox GoldenrodCity_RadioTower_3F_Text_CardKeySlot, MSGBOX_SIGN
	goto_if_set FLAG_HIDE_RADIOTOWER_GATE, GoldenrodCity_RadioTower_3F_EventScript_GateOpened
	checkitem ITEM_CARD_KEY
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_RadioTower_3F_EventScript_OpenGate
	closemessage
	release
	end


GoldenrodCity_RadioTower_3F_EventScript_GateOpened::
	msgbox GoldenrodCity_RadioTower_3F_Text_Open, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_OpenGate::
	msgbox GoldenrodCity_RadioTower_3F_Text_InsertedCardKey, MSGBOX_SIGN
	call GoldenrodCity_RadioTower_3F_HideGate
	playse SE_CLICK
	special DrawWholeMapView
	msgbox GoldenrodCity_RadioTower_3F_Text_Open, MSGBOX_SIGN
	setflag FLAG_HIDE_RADIOTOWER_GATE
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Sign1::
	lock
	msgbox GoldenrodCity_RadioTower_3F_Text_PersonnelSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_EventScript_Sign2::
	lock
	msgbox GoldenrodCity_RadioTower_3F_Text_PokemonMusicSign, MSGBOX_SIGN
	closemessage
	release
	end

GoldenrodCity_RadioTower_3F_Text_CardKeySlot:
	.string "C'est l'emplacement de la CARTE MAGNÉTIQUE.$"

GoldenrodCity_RadioTower_3F_Text_InsertedCardKey:
	.string "{PLAYER} a inséré la CARTE MAGNÉTIQUE.$"
 
GoldenrodCity_RadioTower_3F_Text_Open:
	.string "La porte est ouverte.$"

GoldenrodCity_RadioTower_3F_Text_PersonnelSign:
	.string "3E PERSONNEL$"

GoldenrodCity_RadioTower_3F_Text_PokemonMusicSign:
	.string "MUSIQUE POKéMON avec DJ BEN$"

GoldenrodCity_RadioTower_3F_Text_SuperNerd:
	.string "Nous avons enregistré les cris\n"
	.string "de tous les POKéMON\l"
	.string "qui ont été découverts.\p"
	.string "Nous en avons environ 400 sortes.$"

GoldenrodCity_RadioTower_3F_Text_GymGuideRockets:
	.string "Pour les DRESSEURS, les POKéMON\n"
	.string "sont leurs partenaires bien-aimés. C'est\p"
	.string "terrible comment la TEAM ROCKET\n"
	.string "essaie de contrôler les POKéMON.$"

GoldenrodCity_RadioTower_3F_Text_GymGuide:
	.string "On diffuse 24 heures sur 24 pour proposer\n"
	.string "des programmes divertissants.\p"
	.string "Je vais faire de mon mieux pour courir\n"
	.string "nuit et jour aussi !$"

GoldenrodCity_RadioTower_3F_Text_CooltrainerFPleaseSave:
	.string "Le boss de la TEAM\n"
	.string "ROCKET s'est enfermé. Mais le\p"
	.string "DIRECTEUR peut l'ouvrir. Il est\p"
	.string "au cinquième étage. Sauve-le,\p"
	.string "s'il te plaît !$"

GoldenrodCity_RadioTower_3F_Text_CooltrainerFDirectorSafe:
	.string "Le DIRECTEUR est-il en sécurité ?$"

GoldenrodCity_RadioTower_3F_Text_CooltrainerFHeroGift:
	.string "Merci ! Tu es mon héros !\p"
	.string "Voici un gage de ma reconnaissance.$"

GoldenrodCity_RadioTower_3F_Text_CooltrainerFSunnyDay:
	.string "C'est ÉCHANGE DE TALENT. Ça échange le talent\n"
	.string "d'un POKéMON avec celui d'un autre.$"

GoldenrodCity_RadioTower_3F_Text_CooltrainerFMarvelous:
	.string "Tu étais tout simplement merveilleuse !$"

GoldenrodCity_RadioTower_3F_Text_GruntM7Seen:
	.string "J'ai reçu des ordres stricts.\p"
	.string "Je dois écraser quiconque défie\n"
	.string "la TEAM ROCKET !$"

GoldenrodCity_RadioTower_3F_Text_GruntM7Beaten:
	.string "Quoi ?!$"

GoldenrodCity_RadioTower_3F_Text_GruntM7After:
	.string "J'ai échoué dans ma mission…\p"
	.string "ARCHER va être furieux...$"

GoldenrodCity_RadioTower_3F_Text_GruntM8Seen:
	.string "C'est génial de donner des ordres\n"
	.string "à des POKéMON pour commettre des crimes.$"

GoldenrodCity_RadioTower_3F_Text_GruntM8Beaten:
	.string "Tu plaisantes !$"

GoldenrodCity_RadioTower_3F_Text_GruntM8After:
	.string "Je me sens nul d'avoir perdu !\p"
	.string "Zut ! Je déteste les POKéMON inutiles !$"

GoldenrodCity_RadioTower_3F_Text_GruntM9Seen:
	.string "Pourquoi le volet s'est-il ouvert ? Est-ce\n"
	.string "que tu y es pour quelque chose ?$"

GoldenrodCity_RadioTower_3F_Text_GruntM9Beaten:
	.string "C'est fini pour moi !$"

GoldenrodCity_RadioTower_3F_Text_GruntM9After:
	.string "Quoi ?! Tu as réussi à passer nos hommes\n"
	.string "dans le SOUS-SOL ?\p"
	.string "Comment as-tu fait ?$"

GoldenrodCity_RadioTower_3F_Text_ScientistMarcSeen:
	.string "Un enfant inconnu qui erre ici ?\p"
	.string "Qui es-tu ?$"

GoldenrodCity_RadioTower_3F_Text_ScientistMarcBeaten:
	.string "Tch ! Je t'ai pris trop à la légère !$"

GoldenrodCity_RadioTower_3F_Text_ScientistMarcAfter:
	.string "Bwahahaha…\p"
	.string "Je peux émettre un signal aussi puissant\n"
	.string "que nécessaire d'ici.$"

