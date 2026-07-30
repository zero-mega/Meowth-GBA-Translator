UnionCave_B1F_MapScripts::
	.byte 0

UnionCave_B1F_EventScript_HikerPhillip::
	trainerbattle_single TRAINER_PHILLIP, UnionCave_B1F_Text_HikerPhillipSeen, UnionCave_B1F_Text_HikerPhillipBeaten
	msgbox UnionCave_B1F_Text_HikerPhillipAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B1F_EventScript_HikerLeonard::
	trainerbattle_single TRAINER_LEONARD, UnionCave_B1F_Text_HikerLeonardSeen, UnionCave_B1F_Text_HikerLeonardBeaten
	msgbox UnionCave_B1F_Text_HikerLeonardAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B1F_EventScript_PokemaniacAndrew::
	trainerbattle_single TRAINER_ANDREW, UnionCave_B1F_Text_PokemaniacAndrewSeen, UnionCave_B1F_Text_PokemaniacAndrewBeaten
	msgbox UnionCave_B1F_Text_PokemaniacAndrewAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B1F_EventScript_PokemaniacCalvin::
	trainerbattle_single TRAINER_CALVIN, UnionCave_B1F_Text_PokemaniacCalvinSeen, UnionCave_B1F_Text_PokemaniacCalvinBeaten
	msgbox UnionCave_B1F_Text_PokemaniacCalvinAfter, MSGBOX_AUTOCLOSE
	end

UnionCave_B1F_EventScript_Item_SecretPower::
	finditem ITEM_TM_SECRET_POWER
	end

UnionCave_B1F_EventScript_Item_Xdefend::
	finditem ITEM_X_DEFEND
	end

UnionCave_B1F_Text_HikerPhillipSeen:
	.string "Ça fait longtemps que je n'ai pas vu\n"
	.string "une autre personne.\p"
	.string "Ne sois pas timide. Combattons !$"

UnionCave_B1F_Text_HikerPhillipBeaten:
	.string "Argh…$"

UnionCave_B1F_Text_HikerPhillipAfter:
	.string "Je suis perdu depuis longtemps…\p"
	.string "Ça ne me dérange pas ici, mais j'ai\n"
	.string "tellement faim !$"

UnionCave_B1F_Text_HikerLeonardSeen:
	.string "Tiens donc ! Un visiteur !$"

UnionCave_B1F_Text_HikerLeonardBeaten:
	.string "Wahahah ! Tu es fougueux !$"

UnionCave_B1F_Text_HikerLeonardAfter:
	.string "Je vis ici en bas.\p"
	.string "Tu peux le faire aussi, si tu veux.\p"
	.string "Il y a plein de place, tu vois.$"

UnionCave_B1F_Text_PokemaniacAndrewSeen:
	.string "Qui est là ?\p"
	.string "Laisse-moi et mes POKéMON tranquilles !$"

UnionCave_B1F_Text_PokemaniacAndrewBeaten:
	.string "Va… Va-t'en !$"

UnionCave_B1F_Text_PokemaniacAndrewAfter:
	.string "Je n'ai que mes POKéMON. Je suis en-\n"
	.string "délire de joie.$"

UnionCave_B1F_Text_PokemaniacCalvinSeen:
	.string "Je suis venu jusqu'ici pour mener\n"
	.string "mes recherches sur les POKéMON.\p"
	.string "Laisse-moi te montrer mes découvertes\n"
	.string "en combat !$"

UnionCave_B1F_Text_PokemaniacCalvinBeaten:
	.string "Tu m'as fait la démonstration !$"

UnionCave_B1F_Text_PokemaniacCalvinAfter:
	.string "Je devrais compiler et annoncer les résultats\n"
	.string "de mes recherches.\p"
	.string "Je pourrais même devenir célèbre comme\n"
	.string "le PROF.ORME.$"
