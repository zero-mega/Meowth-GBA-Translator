MtPyre_6F_MapScripts::
	.byte 0

MtPyre_6F_EventScript_Valerie::
	trainerbattle_single TRAINER_VALERIE_1, MtPyre_6F_Text_ValerieIntro, MtPyre_6F_Text_ValerieDefeat, MtPyre_6F_EventScript_RegisterValerie
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtPyre_6F_EventScript_RematchValerie
	msgbox MtPyre_6F_Text_ValeriePostBattle, MSGBOX_DEFAULT
	release
	end

MtPyre_6F_EventScript_RegisterValerie::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtPyre_6F_Text_ValerieRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_VALERIE_1
	release
	end

MtPyre_6F_EventScript_RematchValerie::
	trainerbattle_rematch TRAINER_VALERIE_1, MtPyre_6F_Text_ValerieRematchIntro, MtPyre_6F_Text_ValerieRematchDefeat
	msgbox MtPyre_6F_Text_ValeriePostRematch, MSGBOX_AUTOCLOSE
	end

MtPyre_6F_EventScript_Cedric::
	trainerbattle_single TRAINER_GRUNT_8, MtPyre_6F_Text_CedricIntro, MtPyre_6F_Text_CedricDefeat
	msgbox MtPyre_6F_Text_CedricPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_6F_Text_ValerieIntro:
	.string "Quand je suis ici…\n"
	.string "Une étrange force m'envahit…$"

MtPyre_6F_Text_ValerieDefeat:
	.string "La puissance s'éteint…$"

MtPyre_6F_Text_ValeriePostBattle:
	.string "Peut-être que le pouvoir vient des esprits\n"
	.string "des POKéMON endormis agités ici…$"

MtPyre_6F_Text_ValerieRegister:
	.string "Fufufu… J'ai perdu le match,\n"
	.string "mais… J'ai cette petite\p"
	.string "capacité… Sans jamais toucher\n"
	.string "ton POKéNAV… Hiyah !$"

MtPyre_6F_Text_ValerieRematchIntro:
	.string "Derrière toi…\n"
	.string "Qu'est-ce que c'est…$"

MtPyre_6F_Text_ValerieRematchDefeat:
	.string "Quelque chose s'est estompé…$"

MtPyre_6F_Text_ValeriePostRematch:
	.string "Les POKéMON au repos ici…\n"
	.string "Parfois, ils jouent…$"

MtPyre_6F_Text_CedricIntro:
	.string "Tu as perdu le nord ?\n"
	.string "N'aie crainte, je suis là !$"

MtPyre_6F_Text_CedricDefeat:
	.string "Tu n'étais pas perdu ?$"

MtPyre_6F_Text_CedricPostBattle:
	.string "J'avais le sentiment qu'un DRESSEUR perdu serait\n"
	.string "paniqué et facile à battre. C'est\p"
	.string "sale et je ne réessaierai pas…$"

