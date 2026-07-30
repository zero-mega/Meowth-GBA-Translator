BattleFrontier_Lounge5_MapScripts::
	.byte 0

BattleFrontier_Lounge5_EventScript_NatureGirl::
	lock
	faceplayer
	msgbox BattleFrontier_Lounge5_Text_NatureGirlGreeting, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown
	special ChoosePartyMon
	waitstate
	lock
	faceplayer
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, BattleFrontier_Lounge5_EventScript_NatureGirlEgg
	special ShowNatureGirlMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirlEgg::
	msgbox BattleFrontier_Lounge5_Text_NatureGirlEgg, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_NatureGirlNoneShown::
	msgbox BattleFrontier_Lounge5_Text_NatureGirlNoneShown, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge5_EventScript_Gentleman::
	msgbox BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_BlackBelt::
	msgbox BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound, MSGBOX_NPC
	end

BattleFrontier_Lounge5_EventScript_LittleBoy::
	msgbox BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot, MSGBOX_NPC
	end

BattleFrontier_Lounge5_Text_NatureGirlGreeting::
	.string "Ehehe !\n"
	.string "Je peux dire à quoi pensent les POKéMON !\p"
	.string "S'il te plaît !\n"
	.string "Puis-je voir tes POKéMON ?$"

BattleFrontier_Lounge5_Text_NatureGirlNoneShown::
	.string "Bouh !\n"
	.string "Radin !$"

BattleFrontier_Lounge5_Text_NatureGirlHardy::
	.string "Hmhm…\p"
	.string "Celui-ci dit qu'il aime combattre !\n"
	.string "Il combattra même s'il a beaucoup\l"
	.string "de bobos !$"

BattleFrontier_Lounge5_Text_NatureGirlLonely::
	.string "Hmhm…\p"
	.string "Celui-ci dit qu'il aime être sournois !\n"
	.string "Mais s'il a assez de bobos,\l"
	.string "il riposte !$"

BattleFrontier_Lounge5_Text_NatureGirlBrave::
	.string "Hmhm...\p"
	.string "Celui-ci dit qu'il aime se battre !\n"
	.string "Mais s'il a trop de bobos,\l"
	.string "il s'inquiète pour lui-même !$"

BattleFrontier_Lounge5_Text_NatureGirlAdamant::
	.string "Hmhm…\p"
	.string "Celui-ci dit qu'il aime combattre !\n"
	.string "Il combattra même s'il a beaucoup\l"
	.string "de bobos !$"

BattleFrontier_Lounge5_Text_NatureGirlNaughty::
	.string "Hmhm…\p"
	.string "Celui-ci dit qu'il se débrouille tout seul !\n"
	.string "Mais s'il a assez de bobos,\l"
	.string "il riposte !$"

BattleFrontier_Lounge5_Text_NatureGirlBold::
	.string "Hmhm...\p"
	.string "Celui-ci dit qu'il aime être sournois !\n"
	.string "Mais s'il a trop de bobos,\l"
	.string "il s'inquiète pour lui-même !$"

BattleFrontier_Lounge5_Text_NatureGirlDocileNaiveQuietQuirky::
	.string "Hmhm…\p"
	.string "Celui-ci dit qu'il aime combattre !\n"
	.string "Il combattra même s'il a beaucoup\l"
	.string "de bobos !$"

BattleFrontier_Lounge5_Text_NatureGirlRelaxed::
	.string "Hmhm…\p"
	.string "Celui-ci dit qu'il aime être sournois !\n"
	.string "Mais s'il a assez de bobos,\l"
	.string "il riposte !$"

BattleFrontier_Lounge5_Text_NatureGirlImpish::
	.string "Hmhm...\p"
	.string "Celui-ci dit qu'il aime se battre !\n"
	.string "Mais s'il a trop de bobos,\l"
	.string "il s'inquiète pour lui-même !$"

BattleFrontier_Lounge5_Text_NatureGirlLax::
	.string "Hmhm...\p"
	.string "Celui-ci dit qu'il aime être sournois !\n"
	.string "Il dit qu'il aime être sournois même\l"
	.string "s'il a beaucoup de bobos !$"

BattleFrontier_Lounge5_Text_NatureGirlTimid::
	.string "Hmhm…\p"
	.string "Celui-ci dit qu'il aime combattre !\n"
	.string "Mais s'il a assez de bobos,\l"
	.string "il devient sournois !$"

BattleFrontier_Lounge5_Text_NatureGirlHasty::
	.string "Hmhm…\p"
	.string "Celui-ci dit qu'il aime combattre !\n"
	.string "Il combattra même s'il a beaucoup\l"
	.string "de bobos !$"

BattleFrontier_Lounge5_Text_NatureGirlSerious::
	.string "Hmhm...\p"
	.string "Celui-ci dit qu'il aime être sournois !\n"
	.string "Il dit qu'il aime être sournois même\l"
	.string "s'il a beaucoup de bobos !$"

BattleFrontier_Lounge5_Text_NatureGirlJolly::
	.string "Hmhm...\p"
	.string "Celui-ci dit qu'il aime être sournois !\n"
	.string "Mais s'il a trop de bobos,\l"
	.string "il s'inquiète pour lui-même !$"

BattleFrontier_Lounge5_Text_NatureGirlModest::
	.string "Hmhm… Celui-ci dit qu'il se débrouille\p"
	.string "tout seul ! Il dit qu'il\n"
	.string "s'inquiète pour lui-même qu'il ait beaucoup\l"
	.string "de bobos ou pas !$"

BattleFrontier_Lounge5_Text_NatureGirlMild::
	.string "Hmhm...\p"
	.string "Celui-ci dit qu'il sait se débrouiller seul !\n"
	.string "Mais s'il a trop de bobos,\l"
	.string "il devient sournois !$"

BattleFrontier_Lounge5_Text_NatureGirlBashful::
	.string "Hmhm… Celui-ci dit qu'il se débrouille\p"
	.string "tout seul ! Il dit qu'il\n"
	.string "s'inquiète pour lui-même même s'il\l"
	.string "a beaucoup de bobos !$"

BattleFrontier_Lounge5_Text_NatureGirlRash::
	.string "Hmhm...\p"
	.string "Celui-ci dit qu'il aime être sournois !\n"
	.string "Il dit qu'il aime être sournois même\l"
	.string "s'il a beaucoup de bobos !$"

BattleFrontier_Lounge5_Text_NatureGirlCalm::
	.string "Hmhm… Celui-ci dit qu'il se débrouille\p"
	.string "tout seul ! Il dit qu'il\n"
	.string "s'inquiète pour lui-même même s'il\l"
	.string "a beaucoup de bobos !$"

BattleFrontier_Lounge5_Text_NatureGirlGentle::
	.string "Hmhm…\p"
	.string "Celui-ci dit qu'il se débrouille tout seul !\n"
	.string "Mais s'il a assez de bobos,\l"
	.string "il riposte !$"

BattleFrontier_Lounge5_Text_NatureGirlSassy::
	.string "Hmhm…\p"
	.string "Celui-ci dit qu'il aime combattre !\n"
	.string "Mais s'il a assez de bobos,\l"
	.string "il devient sournois !$"

BattleFrontier_Lounge5_Text_NatureGirlCareful::
	.string "Hmhm...\p"
	.string "Celui-ci dit qu'il sait se débrouiller seul !\n"
	.string "Mais s'il a trop de bobos,\l"
	.string "il devient sournois !$"

BattleFrontier_Lounge5_Text_NatureGirlEgg::
	.string "C'est bête ! Un OEUF dort !\n"
	.string "Je ne peux pas lui parler !$"

BattleFrontier_Lounge5_Text_LadyClaimsSheUnderstandsPokemon::
	.string "Comme c'est charmant !\n"
	.string "Cette petite dame prétend pouvoir\l"
	.string "comprendre les POKéMON !$"

BattleFrontier_Lounge5_Text_GirlSayingSomethingProfound::
	.string "J'ai le sentiment que la petite fille\n"
	.string "dit quelque chose de profond.$"

BattleFrontier_Lounge5_Text_GirlPlaysAtRedHouseALot::
	.string "Je sais quelque chose !\p"
	.string "Cette petite fille joue souvent\n"
	.string "à la maison rouge !$"

