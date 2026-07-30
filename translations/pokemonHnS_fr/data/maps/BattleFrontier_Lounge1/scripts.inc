BattleFrontier_Lounge1_MapScripts::
	.byte 0

@ NPC that rates pokemon based on their IVs
BattleFrontier_Lounge1_EventScript_Breeder::
	lock
	faceplayer
	call_if_unset FLAG_MET_BATTLE_FRONTIER_BREEDER, BattleFrontier_Lounge1_EventScript_BreederIntro
	call_if_set FLAG_MET_BATTLE_FRONTIER_BREEDER, BattleFrontier_Lounge1_EventScript_AlreadyMetBreeder
	setflag FLAG_MET_BATTLE_FRONTIER_BREEDER
	goto BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder
	end

BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder::
	special ChoosePartyMon
	waitstate
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge1_EventScript_ShowMonToBreeder
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge1_EventScript_CancelMonSelect
	end

BattleFrontier_Lounge1_EventScript_BreederIntro::
	msgbox BattleFrontier_Lounge1_Text_PokemonBreederIntro, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge1_EventScript_AlreadyMetBreeder::
	msgbox BattleFrontier_Lounge1_Text_LetsLookAtYourPokemon, MSGBOX_DEFAULT
	return

@ BufferVarsForIVRater buffers the following values
@ VAR_0x8005: Sum of the mons IVs
@ VAR_0x8006: Stat id of highest IV stat
@ VAR_0x8007: IV of the highest IV stat
BattleFrontier_Lounge1_EventScript_ShowMonToBreeder::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, BattleFrontier_Lounge1_EventScript_ShowEggToBreeder
	special BufferVarsForIVRater
	goto_if_le VAR_0x8005, 90, BattleFrontier_Lounge1_EventScript_AverageTotalIVs       @ Average of 15
	goto_if_le VAR_0x8005, 120, BattleFrontier_Lounge1_EventScript_AboveAverageTotalIVs @ Average of 20
	goto_if_le VAR_0x8005, 150, BattleFrontier_Lounge1_EventScript_HighTotalIVs         @ Average of 25
	goto_if_ge VAR_0x8005, 151, BattleFrontier_Lounge1_EventScript_VeryHighTotalIVs     @ Average of > 25
	end

BattleFrontier_Lounge1_EventScript_ShowEggToBreeder::
	msgbox BattleFrontier_Lounge1_Text_EvenICantTell, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_ChooseMonToShowBreeder
	end

@ Comment on the highest IV stat
BattleFrontier_Lounge1_EventScript_HighestIVStat::
	goto_if_eq VAR_0x8006, STAT_HP, BattleFrontier_Lounge1_EventScript_HighestIVHP
	goto_if_eq VAR_0x8006, STAT_ATK, BattleFrontier_Lounge1_EventScript_HighestIVAtk
	goto_if_eq VAR_0x8006, STAT_DEF, BattleFrontier_Lounge1_EventScript_HighestIVDef
	goto_if_eq VAR_0x8006, STAT_SPEED, BattleFrontier_Lounge1_EventScript_HighestIVSpeed
	goto_if_eq VAR_0x8006, STAT_SPATK, BattleFrontier_Lounge1_EventScript_HighestIVSpAtk
	goto_if_eq VAR_0x8006, STAT_SPDEF, BattleFrontier_Lounge1_EventScript_HighestIVSpDef
	end

@ Comment on the highest IV value
BattleFrontier_Lounge1_EventScript_HighestIVValue::
	goto_if_le VAR_0x8007, 15, BattleFrontier_Lounge1_EventScript_HighestIVLow
	goto_if_le VAR_0x8007, 25, BattleFrontier_Lounge1_EventScript_HighestIVMid
	goto_if_le VAR_0x8007, 30, BattleFrontier_Lounge1_EventScript_HighestIVHigh
	goto_if_ge VAR_0x8007, 31, BattleFrontier_Lounge1_EventScript_HighestIVMax
	end

BattleFrontier_Lounge1_EventScript_EndBreederComments::
	release
	end

BattleFrontier_Lounge1_EventScript_AverageTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_AverageAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_AboveAverageTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_BetterThanAverageAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_HighTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_ImpressiveAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_VeryHighTotalIVs::
	msgbox BattleFrontier_Lounge1_Text_OutstandingAbility, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVStat
	end

BattleFrontier_Lounge1_EventScript_HighestIVHP::
	msgbox BattleFrontier_Lounge1_Text_BestAspectHP, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVAtk::
	msgbox BattleFrontier_Lounge1_Text_BestAspectAtk, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVDef::
	msgbox BattleFrontier_Lounge1_Text_BestAspectDef, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVSpeed::
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpeed, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVSpAtk::
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpAtk, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVSpDef::
	msgbox BattleFrontier_Lounge1_Text_BestAspectSpDef, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_HighestIVValue
	end

BattleFrontier_Lounge1_EventScript_HighestIVLow::
	msgbox BattleFrontier_Lounge1_Text_StatRelativelyGood, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_HighestIVMid::
	msgbox BattleFrontier_Lounge1_Text_StatImpressive, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_HighestIVHigh::
	msgbox BattleFrontier_Lounge1_Text_StatOutstanding, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_HighestIVMax::
	msgbox BattleFrontier_Lounge1_Text_StatFlawless, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge1_EventScript_EndBreederComments
	end

BattleFrontier_Lounge1_EventScript_CancelMonSelect::
	msgbox BattleFrontier_Lounge1_Text_NoTimeForMyAdvice, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge1_EventScript_Boy1::
	msgbox BattleFrontier_Lounge1_Text_SaidMyMonIsOutstanding, MSGBOX_NPC
	end

BattleFrontier_Lounge1_EventScript_Boy2::
	msgbox BattleFrontier_Lounge1_Text_DidntDoAnythingSpecialRaisingIt, MSGBOX_NPC
	end

BattleFrontier_Lounge1_Text_PokemonBreederIntro:
	.string "Pendant 70 ans j'ai\n"
	.string "élevé des POKéMON !\l"
	.string "Je suis l'homme\p"
	.string "qu'on vénère comme\n"
	.string "le légendaire meilleur\l"
	.string "ÉLEVEUR POKéMON !\p"
	.string "Si tu deviens un\n"
	.string "grand dresseur,\l"
	.string "reviens me voir !\p"
	.string "Je t'apprendrai les\n"
	.string "secrets de l'élevage !$"

BattleFrontier_Lounge1_Text_AverageAbility:
	.string "…Hmm…\p"
	.string "Celui-ci, dans l'ensemble, je le décrirais\n"
	.string "comme ayant des capacités moyennes.$"

BattleFrontier_Lounge1_Text_BetterThanAverageAbility:
	.string "…Hmm…\p"
	.string "Celui-ci, dans l'ensemble, je le décrirais comme\n"
	.string "ayant des capacités supérieures à la moyenne.$"

BattleFrontier_Lounge1_Text_ImpressiveAbility:
	.string "…Hmm…\p"
	.string "Celui-ci, dans l'ensemble, je dirais qu'il est\n"
	.string "plutôt impressionnant en capacité !$"

BattleFrontier_Lounge1_Text_OutstandingAbility:
	.string "…Hmm…\p"
	.string "Celui-ci, dans l'ensemble, je dirais qu'il est\n"
	.string "merveilleusement exceptionnel en capacité !$"

BattleFrontier_Lounge1_Text_BestAspectHP:
	.string "Au fait, le meilleur aspect,\n"
	.string "je dirais, ce sont ses PV…$"

BattleFrontier_Lounge1_Text_BestAspectAtk:
	.string "À propos, le meilleur aspect,\n"
	.string "je dirais, c'est son ATTAQUE…$"

BattleFrontier_Lounge1_Text_BestAspectDef:
	.string "À propos, le meilleur aspect,\n"
	.string "je dirais, c'est sa DÉFENSE…$"

BattleFrontier_Lounge1_Text_BestAspectSpAtk:
	.string "Au passage, le meilleur aspect,\n"
	.string "je dirais, c'est son ATTAQUE SPÉCIALE…$"

BattleFrontier_Lounge1_Text_BestAspectSpDef:
	.string "Au passage, le meilleur aspect,\n"
	.string "je dirais, c'est sa DÉFENSE SPÉCIALE…$"

BattleFrontier_Lounge1_Text_BestAspectSpeed:
	.string "À propos, le meilleur aspect,\n"
	.string "je dirais, c'est sa VITESSE…$"

BattleFrontier_Lounge1_Text_StatRelativelyGood:
	.string "Cette stat est relativement bonne.\n"
	.string "…Hm… C'est comme ça que je l'appelle.$"

BattleFrontier_Lounge1_Text_StatImpressive:
	.string "Cette stat est plutôt impressionnante.\n"
	.string "…Hm… C'est comme ça que je l'appelle.$"

BattleFrontier_Lounge1_Text_StatOutstanding:
	.string "Cette stat est exceptionnelle !\n"
	.string "…Hm… C'est comme ça que je l'appelle.$"

BattleFrontier_Lounge1_Text_StatFlawless:
	.string "C'est parfait ! Une chose de perfection !\n"
	.string "…Hm… C'est comme ça que je l'appelle.$"

BattleFrontier_Lounge1_Text_NoTimeForMyAdvice:
	.string "Quoi ? Tu n'as pas le\n"
	.string "temps pour mes conseils ? Tu\p"
	.string "devrais toujours être avide d'apprendre des\n"
	.string "expériences de tes aînés !$"

@ Unused
BattleFrontier_Lounge1_Text_HaveBusinessNeedsTending:
	.string "Oui, qu'est-ce qu'il y a maintenant ?\p"
	.string "J'ai des affaires à régler !\n"
	.string "Garde ça pour la prochaine fois !$"

BattleFrontier_Lounge1_Text_LetsLookAtYourPokemon:
	.string "Ah, jeune homme ! Les capacités de tes\n"
	.string "POKéMON t'intriguent ?\p"
	.string "Allez, allez !\n"
	.string "Regardons tes POKéMON !$"

BattleFrontier_Lounge1_Text_EvenICantTell:
	.string "Expert je suis, mais même moi je ne peux rien dire\n"
	.string "sur un POKéMON pas encore éclos !\p"
	.string "Montre-moi un POKéMON !\n"
	.string "Un POKéMON, c'est ce que je dois voir !$"

BattleFrontier_Lounge1_Text_SaidMyMonIsOutstanding:
	.string "Il a dit que mon POKéMON est exceptionnel !\n"
	.string "Je suis content de l'avoir bien élevé !$"

BattleFrontier_Lounge1_Text_DidntDoAnythingSpecialRaisingIt:
	.string "Il a dit que mon POKéMON est exceptionnel !\n"
	.string "Mais je n'ai rien fait de spécial pour\l"
	.string "l'élever…$"

