.set LOCALID_LIGHTHOUSE_JASMINE, 12
.set LOCALID_LIGHTHOUSE_AMPHAROS, 13

OlivineCity_Lighthouse_MapScripts::
	.byte 0

OlivineLighthouse_EventScript_Item_Ether::
    finditem ITEM_ETHER
    end

OlivineLighthouse_EventScript_Item_RareCandy::
    finditem ITEM_RARE_CANDY
    end

OlivineLighthouse_EventScript_Item_TMBulkUp::
    finditem ITEM_TM_BULK_UP
    end

OlivineLighthouse_EventScript_Item_HyperPotion::
    finditem ITEM_HYPER_POTION
    end

OlivineLighthouse_EventScript_Item_Protein::
    finditem ITEM_PROTEIN
    end

OlivineLighthouse_EventScript_1FSailor::
	lock
	faceplayer
	msgbox OlivineLighthouse_Text_1FSailor, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineLighthouse_EventScript_1FPokefanF::
	lock
	faceplayer
	msgbox OlivineLighthouse_Text_1FPokefanF, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineLighthouse_Text_1FSailor:
	.string "Les gens s'entraînent dans ce PHARE.\p"
	.string "Ce n'est pas facile de grimper avec tous\n"
	.string "les Dresseurs qui attendent à l'intérieur.$"

OlivineLighthouse_Text_1FPokefanF:
	.string "Autrefois, des POKéMON éclairaient\n"
	.string "la mer autour d'OLIVILLE la nuit.\p"
	.string "Le PHARE a été construit en l'honneur\n"
	.string "de ces nobles POKéMON.$"

@2nd floor==============================================================================================================================

OlivineLighthouse_EventScript_Huey::
	trainerbattle_single TRAINER_HUEY, OlivineLighthouse_Text_SailorHueySeen, OlivineLighthouse_Text_SailorHueyBeaten
	msgbox OlivineLighthouse_Text_SailorHueyAfter, MSGBOX_AUTOCLOSE
	end

OlivineLighthouse_EventScript_GentlemanAlfred::
    trainerbattle_single TRAINER_ALFRED, OlivineLighthouse_Text_GentlemanAlfredSeen, OlivineLighthouse_Text_GentlemanAlfredBeaten
    msgbox OlivineLighthouse_Text_GentlemanAlfredAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_Text_SailorHueySeen:
	.string "Les hommes de la mer sont toujours\n"
	.string "prêts à se battre !$"

OlivineLighthouse_Text_SailorHueyBeaten:
	.string "Arf !\n"
	.string "Je perds !$"

OlivineLighthouse_Text_SailorHueyAfter:
	.string "Quelle puissance ! Ça te dirait\n"
	.string "de naviguer sur les mers avec moi ?$"

OlivineLighthouse_Text_GentlemanAlfredSeen:
	.string "Hm ? Ce n'est pas un endroit\n"
	.string "pour jouer.$"

OlivineLighthouse_Text_GentlemanAlfredBeaten:
	.string "Ah ! Je vois que tu es\n"
	.string "sérieux.$"

OlivineLighthouse_Text_GentlemanAlfredAfter:
	.string "En haut, il y a un POKéMON\n"
	.string "qui maintient le PHARE allumé. Mais j'ai\p"
	.string "entendu dire qu'il est malade et\n"
	.string "ne peut pas être soigné normalement.$"

@3rd floor==============================================================================================================================

OlivineLighthouse_EventScript_BirdKeeperTheo::
    trainerbattle_single TRAINER_THEO, OlivineLighthouse_Text_BirdKeeperTheoSeen, OlivineLighthouse_Text_BirdKeeperTheoBeaten
    msgbox OlivineLighthouse_Text_BirdKeeperTheoAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_EventScript_SailorTerrell::
    trainerbattle_single TRAINER_TERRELL, OlivineLighthouse_Text_SailorTerrellSeen, OlivineLighthouse_Text_SailorTerrellBeaten
    msgbox OlivineLighthouse_Text_SailorTerrellAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_EventScript_GentlemanPreston::
    trainerbattle_single TRAINER_PRESTON, OlivineLighthouse_Text_GentlemanPrestonSeen, OlivineLighthouse_Text_GentlemanPrestonBeaten
    msgbox OlivineLighthouse_Text_GentlemanPrestonAfter, MSGBOX_AUTOCLOSE
    end


OlivineLighthouse_Text_BirdKeeperTheoSeen:
	.string "Pourquoi es-tu ici ? Tu viens juste\n"
	.string "regarder ? Je te conseille de partir !$"

OlivineLighthouse_Text_BirdKeeperTheoBeaten:
	.string "Tu t'inquiètes vraiment pour\n"
	.string "le POKéMON malade…$"

OlivineLighthouse_Text_BirdKeeperTheoAfter:
	.string "Comment diable monte-t-on ?\p"
	.string "Je veux rendre visite au POKéMON malade,\n"
	.string "mais je n'arrive pas à monter…$"

OlivineLighthouse_Text_SailorTerrellSeen:
	.string "Les marins sont à la fois gentils et forts.\n"
	.string "Et toi ?$"

OlivineLighthouse_Text_SailorTerrellBeaten:
	.string "Tu es à la fois gentil et fort…$"

OlivineLighthouse_Text_SailorTerrellAfter:
	.string "Chaque fois que je reviens à\n"
	.string "OLIVILLE, je visite l'ARÈNE. Le type\p"
	.string "de POKéMON du CHAMPION D'ARÈNE a\n"
	.string "changé sans que je m'en aperçoive.$"

OlivineLighthouse_Text_GentlemanPrestonSeen:
	.string "Je voyage le monde pour entraîner mes\n"
	.string "POKéMON. Je veux te combattre.$"

OlivineLighthouse_Text_GentlemanPrestonBeaten:
	.string "…soupir… Je dois encore m'entraîner…$"

OlivineLighthouse_Text_GentlemanPrestonAfter:
	.string "JASMINE utilisait des POKéMON\n"
	.string "de type ROCHE comme ONIX.$"

@4th floor==============================================================================================================================

OlivineLighthouse_EventScript_SailorKent::
    trainerbattle_single TRAINER_KENT, OlivineLighthouse_Text_SailorKentSeen, OlivineLighthouse_Text_SailorKentBeaten
    msgbox OlivineLighthouse_Text_SailorKentAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_EventScript_LassConnie::
    trainerbattle_single TRAINER_CONNIE, OlivineLighthouse_Text_LassConnieSeen, OlivineLighthouse_Text_LassConnieBeaten
    msgbox OlivineLighthouse_Text_LassConnieAfter, MSGBOX_AUTOCLOSE
    end


OlivineLighthouse_Text_SailorKentSeen:
	.string "JASMINE doit être morte d'inquiétude pour\n"
	.string "les POKéMON ici.\p"
	.string "Elle ne sourit même plus ces jours-ci.$"

OlivineLighthouse_Text_SailorKentBeaten:
	.string "Je n'arrive pas à sourire non plus…$"

OlivineLighthouse_Text_SailorKentAfter:
	.string "En parlant de maladie, j'ai entendu dire\n"
	.string "qu'il y a une bonne PHARMACIE à OLIVILLE.$"

OlivineLighthouse_Text_LassConnieSeen:
	.string "JASMINE est la CHAMPIONNE D'ARÈNE de cette ville.\p"
	.string "Je compte bien la ramener avec moi.\p"
	.string "Personne ne devrait se mettre en travers de mon chemin !$"

OlivineLighthouse_Text_LassConnieBeaten:
	.string "Aaack ! Mon POKéMON !$"

OlivineLighthouse_Text_LassConnieAfter:
	.string "Exact. N'importe qui s'inquiéterait si\n"
	.string "son propre POKéMON était blessé.\p"
	.string "Je vais prier pour les POKéMON ici, pour\n"
	.string "que JASMINE puisse revenir à l'ARÈNE.$"

@5th floor==============================================================================================================================

OlivineLighthouse_EventScript_SailorErnest::
    trainerbattle_single TRAINER_ERNEST, OlivineLighthouse_Text_SailorErnestSeen, OlivineLighthouse_Text_SailorErnestBeaten
    msgbox OlivineLighthouse_Text_SailorErnestAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_EventScript_BirdKeeperDenis::
    trainerbattle_single TRAINER_DENIS, OlivineLighthouse_Text_BirdKeeperDenisSeen, OlivineLighthouse_Text_BirdKeeperDenisBeaten
    msgbox OlivineLighthouse_Text_BirdKeeperDenisAfter, MSGBOX_AUTOCLOSE
    end

OlivineLighthouse_Text_SailorErnestSeen:
	.string "Je voulais combattre JASMINE, mais elle\n"
	.string "n'est pas en forme maintenant.\p"
	.string "Alors, et toi ?$"

OlivineLighthouse_Text_SailorErnestBeaten:
	.string "Ouah, ouah. Tu es écrasant !$"

OlivineLighthouse_Text_SailorErnestAfter:
	.string "Un CHAMPION D'ARÈNE, ce n'est pas seulement\n"
	.string "être fort.\p"
	.string "Un CHAMPION doit aussi être\n"
	.string "compatissant.$"

OlivineLighthouse_Text_BirdKeeperDenisSeen:
	.string "On est assez haut ici. Mes POKéMON\n"
	.string "Oiseau sont en pleine forme.$"

OlivineLighthouse_Text_BirdKeeperDenisBeaten:
	.string "Oups… Ils se sont écrasés…$"

OlivineLighthouse_Text_BirdKeeperDenisAfter:
	.string "Mon POKéMON a appris VOL\n"
	.string "à IRISIA.\p"
	.string "Comme je suis un perdant, je vais VOLer\n"
	.string "au-dessus de la mer...$"

@6th floor==============================================================================================================================

OlivineLighthouse_EventScript_Jasmine::
	lock
	faceplayer
	goto_if_eq VAR_OLIVINE_CITY_STATE, 3, OlivineLighthouse_EventScript_JasmineGoGetPotion
	goto_if_eq VAR_OLIVINE_CITY_STATE, 4, OlivineLighthouse_EventScript_JasmineDeliverPotion
	msgbox OlivineLighthouse_Text_JasmineCianwoodPharmacy, MSGBOX_DEFAULT
	msgbox OlivineLighthouse_Text_JasmineGetMedicine, MSGBOX_DEFAULT
	closemessage
	setvar VAR_OLIVINE_CITY_STATE, 3
	release
	end
OlivineLighthouse_EventScript_JasmineGoGetPotion::
	msgbox OlivineLighthouse_Text_JasmineGetMedicine2, MSGBOX_DEFAULT
	release
	end


OlivineLighthouse_EventScript_Ampharos::
	lock
	faceplayer
	goto_if_lt VAR_OLIVINE_CITY_STATE, 5, OlivineLighthouse_EventScript_AmpharosSick
	fadescreen FADE_TO_WHITE
	playse SE_M_THUNDERBOLT2
	waitse
	fadescreen FADE_FROM_WHITE
	playmoncry SPECIES_AMPHAROS, CRY_MODE_NORMAL
	msgbox OlivineLighthouse_Text_AmphyPaluPalulu, MSGBOX_DEFAULT
	waitmoncry
	setflag FLAG_AMPHAROS_HEALED
	release
	end

OlivineLighthouse_EventScript_AmpharosSick::
	playmoncry SPECIES_AMPHAROS, CRY_MODE_NORMAL
	msgbox OlivineLighthouse_Text_AmphyPalPaloo, MSGBOX_DEFAULT
	waitmoncry
	msgbox OlivineLighthouse_Text_AmphyBreathingLabored, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineLighthouse_Text_JasmineCianwoodPharmacy:
	.string "JASMINE : …Ce POKéMON éclairait\n"
	.string "toujours la mer la nuit.\p"
	.string "…Mais il est soudainement tombé\n"
	.string "malade… Il a du mal à respirer…\p"
	.string "…Je comprends qu'il y a une\n"
	.string "merveilleuse PHARMACIE à\p"
	.string "PARMANIE…\n"
	.string "Mais c'est de l'autre côté de la mer… Et je ne peux pas laisser AMPHAROS sans surveillance…$"

OlivineLighthouse_Text_JasmineGetMedicine:
	.string "…Puis-je te demander d'aller chercher\n"
	.string "un médicament pour moi ? S'il te plaît ?$"

OlivineLighthouse_Text_JasmineGetMedicine2:
	.string "Il y a une merveilleuse PHARMACIE\n"
	.string "à ECRUMVILLE…\p"
	.string "Mais c'est de l'autre côté de la mer…\n"
	.string "Et je ne peux pas laisser AMPHINOS sans surveillance…\p"
	.string "…Puis-je te demander d'aller chercher des médicaments\n"
	.string "pour moi ? S'il te plaît ?$"

OlivineLighthouse_Text_JasmineCureAmphy:
	.string "JASMINE : …Ce médicament guérira-t-il\n"
	.string "PHARAMP ?$"


OlivineLighthouse_EventScript_JasmineDeliverPotion::
	msgbox OlivineLighthouse_Text_JasmineCureAmphy, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, OlivineLighthouse_EventScript_JasmineRefuse
	playse SE_USE_ITEM
	removeitem ITEM_SECRET_POTION
	msgbox OlivineLighthouse_Text_PlayerHandedSecretpotion, MSGBOX_DEFAULT
	waitse
	msgbox OlivineLighthouse_Text_JasmineDontBeOffended, MSGBOX_DEFAULT
	closemessage
	turnobject LOCALID_LIGHTHOUSE_JASMINE, DIR_NORTH
	delay 20
	turnobject LOCALID_LIGHTHOUSE_AMPHAROS, DIR_SOUTH
	playse MUS_HEAL
	waitse
	msgbox OlivineLighthouse_Text_JasmineAmphyHowFeeling, MSGBOX_DEFAULT
	fadescreen FADE_TO_WHITE
	playse SE_M_THUNDERBOLT2
	waitse
	fadescreen FADE_FROM_WHITE
	playmoncry SPECIES_AMPHAROS, CRY_MODE_NORMAL
	msgbox OlivineLighthouse_Text_AmphyPaluPalulu, MSGBOX_DEFAULT
	waitmoncry
	closemessage
	applymovement LOCALID_LIGHTHOUSE_AMPHAROS, OlivineLighthouse_Movement_Amphy
	waitmovement 0
	applymovement LOCALID_LIGHTHOUSE_JASMINE, OlivineLighthouse_Movement_Jasmine
	msgbox OlivineLighthouse_Text_JasmineThankYou, MSGBOX_DEFAULT
	closemessage

	fadescreen FADE_TO_BLACK
	playse SE_EXIT
	setflag FLAG_HIDE_LIGHTHOUSE_JASMINE
	removeobject LOCALID_LIGHTHOUSE_JASMINE
	waitse
	delay 50
	fadescreen FADE_FROM_BLACK
	setvar VAR_SAFARI_ZONE_GATE_STATE, 1
	setvar VAR_OLIVINE_CITY_STATE, 5
	setflag FLAG_AMPHAROS_HEALED
	clearflag FLAG_HIDE_OLIVINE_CITY_GYM_JASMINE
	release
	end

OlivineLighthouse_Movement_Jasmine:
	face_player
	step_end

OlivineLighthouse_Movement_Amphy:
	walk_up
	jump_in_place_down
	jump_in_place_left
	jump_in_place_right
	jump_in_place_up
	face_down
	step_end


OlivineLighthouse_EventScript_JasmineRefuse::
	msgbox OlivineLighthouse_Text_JasmineISee, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineLighthouse_Text_PlayerHandedSecretpotion:
	.string "{PLAYER} a donné la POTION SECRÈTE\n"
	.string "à JASMINE.$"

OlivineLighthouse_Text_JasmineDontBeOffended:
	.string "JASMINE : …Euh, ne sois pas\n"
	.string "offensé…\p"
	.string "…PHANPY ne prend rien de\n"
	.string "personne d'autre que moi…$"

OlivineLighthouse_Text_JasmineAmphyHowFeeling:
	.string "JASMINE : …\p"
	.string "PHARAMP, comment te sens-tu ?$"

OlivineLighthouse_Text_JasmineThankYou:
	.string "JASMINE : …Oh, quel soulagement…\p"
	.string "C'est tellement merveilleux…\p"
	.string "Merci beaucoup,\p"
	.string "beaucoup !\p"
	.string "Tu es vraiment gentil !\n"
	.string "Je suis si heureuse !$"

OlivineLighthouse_Text_JasmineISee:
	.string "JASMINE : …Je vois…\n"
	.string "…AMPHY, tiens bon !$"

OlivineLighthouse_Text_AmphyPalPaloo:
	.string "PHORY : …\n"
	.string "…Pa… paloo…$"

OlivineLighthouse_Text_AmphyBreathingLabored:
	.string "Sa respiration est terriblement\n"
	.string "affaiblie…$"

OlivineLighthouse_Text_AmphyPaluPalulu:
	.string "PHORY : Palu ! Palulu !$"


