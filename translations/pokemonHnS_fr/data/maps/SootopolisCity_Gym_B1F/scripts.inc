SootopolisCity_Gym_B1F_MapScripts::
	.byte 0

SootopolisCity_Gym_B1F_EventScript_Andrea::
	trainerbattle_single TRAINER_BRIAN, SootopolisCity_Gym_B1F_Text_AndreaIntro, SootopolisCity_Gym_B1F_Text_AndreaDefeat
	msgbox SootopolisCity_Gym_B1F_Text_AndreaPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Crissy::
	trainerbattle_single TRAINER_HARRY, SootopolisCity_Gym_B1F_Text_CrissyIntro, SootopolisCity_Gym_B1F_Text_CrissyDefeat
	msgbox SootopolisCity_Gym_B1F_Text_CrissyPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Brianna::
	trainerbattle_single TRAINER_ELLEN, SootopolisCity_Gym_B1F_Text_BriannaIntro, SootopolisCity_Gym_B1F_Text_BriannaDefeat
	msgbox SootopolisCity_Gym_B1F_Text_BriannaPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Connie::
	trainerbattle_single TRAINER_CONNIE, SootopolisCity_Gym_B1F_Text_ConnieIntro, SootopolisCity_Gym_B1F_Text_ConnieDefeat
	msgbox SootopolisCity_Gym_B1F_Text_ConniePostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Bridget::
	trainerbattle_single TRAINER_BRIDGET, SootopolisCity_Gym_B1F_Text_BridgetIntro, SootopolisCity_Gym_B1F_Text_BridgetDefeat
	msgbox SootopolisCity_Gym_B1F_Text_BridgetPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Olivia::
	trainerbattle_single TRAINER_OLIVIA, SootopolisCity_Gym_B1F_Text_OliviaIntro, SootopolisCity_Gym_B1F_Text_OliviaDefeat
	msgbox SootopolisCity_Gym_B1F_Text_OliviaPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Tiffany::
	trainerbattle_single TRAINER_TIFFANY, SootopolisCity_Gym_B1F_Text_TiffanyIntro, SootopolisCity_Gym_B1F_Text_TiffanyDefeat
	msgbox SootopolisCity_Gym_B1F_Text_TiffanyPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Bethany::
	trainerbattle_single TRAINER_BETHANY, SootopolisCity_Gym_B1F_Text_BethanyIntro, SootopolisCity_Gym_B1F_Text_BethanyDefeat
	msgbox SootopolisCity_Gym_B1F_Text_BethanyPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Annika::
	trainerbattle_single TRAINER_CARRIE, SootopolisCity_Gym_B1F_Text_AnnikaIntro, SootopolisCity_Gym_B1F_Text_AnnikaDefeat
	msgbox SootopolisCity_Gym_B1F_Text_AnnikaPostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_EventScript_Daphne::
	trainerbattle_single TRAINER_JIMMY, SootopolisCity_Gym_B1F_Text_DaphneIntro, SootopolisCity_Gym_B1F_Text_DaphneDefeat
	msgbox SootopolisCity_Gym_B1F_Text_DaphnePostBattle, MSGBOX_AUTOCLOSE
	end

SootopolisCity_Gym_B1F_Text_AndreaIntro:
	.string "Je vais te montrer les techniques sublimes\n"
	.string "que j'ai apprises de notre CHAMPION JUAN !$"

SootopolisCity_Gym_B1F_Text_AndreaDefeat:
	.string "Pardonne-moi, JUAN…$"

SootopolisCity_Gym_B1F_Text_AndreaPostBattle:
	.string "Regarde ce qui se passe si tu fais craquer\n"
	.string "toutes les dalles du sol.$"

SootopolisCity_Gym_B1F_Text_CrissyIntro:
	.string "Tu es venu jusqu'ici, mais tu ne verras pas\n"
	.string "JUAN.\p"
	.string "Pas si tu perds contre moi, en tout cas !$"

SootopolisCity_Gym_B1F_Text_CrissyDefeat:
	.string "Tu es fort !\n"
	.string "J'ai été dupé par ton air mignon !$"

SootopolisCity_Gym_B1F_Text_CrissyPostBattle:
	.string "Tu es peut-être assez bon pour éviter\n"
	.string "d'être éliminé en un coup par JUAN.$"

SootopolisCity_Gym_B1F_Text_DaphneIntro:
	.string "Voir JUAN diriger\n"
	.string "un combat...\p"
	.string "Sa beauté m'a poussé à\n"
	.string "devenir DRESSEUR.$"

SootopolisCity_Gym_B1F_Text_DaphneDefeat:
	.string "Tu as combattu avec plus de beauté\n"
	.string "que je n'en ai pu montrer…$"

SootopolisCity_Gym_B1F_Text_DaphnePostBattle:
	.string "La grâce que tu apportes au combat est\n"
	.string "fabuleuse.\p"
	.string "Oh… J'ai tellement de chance d'avoir trouvé\n"
	.string "les POKéMON.$"

SootopolisCity_Gym_B1F_Text_ConnieIntro:
	.string "Je vais te montrer à quel point\n"
	.string "les combats peuvent être durs.$"

SootopolisCity_Gym_B1F_Text_ConnieDefeat:
	.string "Oh.\n"
	.string "Tu es fort.$"

SootopolisCity_Gym_B1F_Text_ConniePostBattle:
	.string "Je vais te dire un truc sympa.\p"
	.string "Pour atteindre JUAN, tu dois marcher\n"
	.string "sur chaque case du sol une fois.$"

SootopolisCity_Gym_B1F_Text_BridgetIntro:
	.string "L'ARÈNE POKéMON de plus haut niveau\n"
	.string "de la région HOENN…\p"
	.string "C'est l'ARÈNE DE SOOTOPOLIS.$"

SootopolisCity_Gym_B1F_Text_BridgetDefeat:
	.string "Quel niveau élevé tu as !$"

SootopolisCity_Gym_B1F_Text_BridgetPostBattle:
	.string "Plutôt que d'être satisfait d'être\n"
	.string "dans une ARÈNE forte, je pense que s'entraîner dans\l"
	.string "d'autres endroits te rendra plus fort.\l"
	.string "Mais surtout, ça a l'air plus amusant.$"

SootopolisCity_Gym_B1F_Text_OliviaIntro:
	.string "J'entraîne mes POKéMON avec\n"
	.string "JUAN.\p"
	.string "Ne me prends pas pour une minette.$"

SootopolisCity_Gym_B1F_Text_OliviaDefeat:
	.string "J'ai été battu…$"

SootopolisCity_Gym_B1F_Text_OliviaPostBattle:
	.string "Je pense que tu as du potentiel.\n"
	.string "Pourquoi ne resterais-tu pas t'entraîner avec nous ?$"

SootopolisCity_Gym_B1F_Text_TiffanyIntro:
	.string "Une glisse gracieuse sur la glace sans\n"
	.string "franchir aucune ligne…\p"
	.string "Un DRESSEUR offrant cette performance\n"
	.string "serait d'une élégance magnifique !$"

SootopolisCity_Gym_B1F_Text_TiffanyDefeat:
	.string "Eh bien, pardon ?!$"

SootopolisCity_Gym_B1F_Text_TiffanyPostBattle:
	.string "C'est évident, mais la force d'un\n"
	.string "DRESSEUR n'a rien à voir\l"
	.string "avec l'âge qu'il a.$"

SootopolisCity_Gym_B1F_Text_BethanyIntro:
	.string "Quand je suis avec mes POKéMON, le temps\n"
	.string "passe avant qu'on puisse dire « Oups ! »$"

SootopolisCity_Gym_B1F_Text_BethanyDefeat:
	.string "Oups !$"

SootopolisCity_Gym_B1F_Text_BethanyPostBattle:
	.string "J'aimerais pouvoir oublier les causes perdues\n"
	.string "avant de pouvoir dire « Oups ! »$"

SootopolisCity_Gym_B1F_Text_AnnikaIntro:
	.string "Je peux me battre avec des POKéMON\n"
	.string "très rares si tu veux.$"

SootopolisCity_Gym_B1F_Text_AnnikaDefeat:
	.string "Oh, voyons ! As-tu bien regardé\n"
	.string "mes POKéMON ?$"

SootopolisCity_Gym_B1F_Text_AnnikaPostBattle:
	.string "Je suis venue dans cette ARÈNE parce\n"
	.string "que JUAN a complimenté mon adorable POKéMON.\p"
	.string "Oh, si seulement j'avais rencontré JUAN\n"
	.string "quand j'étais plus jeune…$"

SootopolisCity_Gym_B1F_Text_BriannaIntro:
	.string "Hihi…\n"
	.string "Ton air sombre est si charmant.$"

SootopolisCity_Gym_B1F_Text_BriannaDefeat:
	.string "Oh, mon Dieu.\n"
	.string "J'ai été beaucoup trop indulgent.$"

SootopolisCity_Gym_B1F_Text_BriannaPostBattle:
	.string "Tu n'as pas pu poser un doigt sur JUAN,\n"
	.string "j'en suis sûre. Hi hi…$"

