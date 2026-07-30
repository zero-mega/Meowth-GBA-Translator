ChangeDeoxysFormNormal::
	setvar 0x8000, SPECIES_DEOXYS_ATTACK
	setvar 0x8001, SPECIES_DEOXYS_DEFENSE
	setvar 0x8002, 0
	setvar 0x8005, SPECIES_DEOXYS_SPEED
	msgbox ChangeDeoxysForm_Text_NormalForm, MSGBOX_DEFAULT
	closemessage
	special CheckPkm
	goto_if_eq VAR_RESULT, TRUE, ChangeDeoxysForm
	goto_if_eq VAR_RESULT, FALSE, ChangeDeoxysForm_End_Nothing_Happened
	end

ChangeDeoxysFormDefense::
	setvar 0x8000, SPECIES_DEOXYS_ATTACK
	setvar 0x8001, 0
	setvar 0x8002, SPECIES_DEOXYS
	setvar 0x8005, SPECIES_DEOXYS_SPEED
	msgbox ChangeDeoxysForm_Text_DefenseForm, MSGBOX_DEFAULT
	closemessage
	special CheckPkm
	goto_if_eq VAR_RESULT, TRUE, ChangeDeoxysForm
	goto_if_eq VAR_RESULT, FALSE, ChangeDeoxysForm_End_Nothing_Happened
	end

ChangeDeoxysFormAttack::
	setvar 0x8000, 0
	setvar 0x8001, SPECIES_DEOXYS_DEFENSE
	setvar 0x8002, SPECIES_DEOXYS
	setvar 0x8005, SPECIES_DEOXYS_SPEED
	msgbox ChangeDeoxysForm_Text_AttackForm, MSGBOX_DEFAULT
	closemessage
	special CheckPkm
	goto_if_eq VAR_RESULT, TRUE, ChangeDeoxysForm
	goto_if_eq VAR_RESULT, FALSE, ChangeDeoxysForm_End_Nothing_Happened
	end

ChangeDeoxysFormSpeed::
	setvar 0x8000, SPECIES_DEOXYS_ATTACK
	setvar 0x8001, SPECIES_DEOXYS_DEFENSE
	setvar 0x8002, SPECIES_DEOXYS
	setvar 0x8005, 0
	msgbox ChangeDeoxysForm_Text_SpeedForm, MSGBOX_DEFAULT
	closemessage
	special CheckPkm
	goto_if_eq VAR_RESULT, TRUE, ChangeDeoxysForm
	goto_if_eq VAR_RESULT, FALSE, ChangeDeoxysForm_End_Nothing_Happened
	end

ChangeDeoxysForm::
	lockall
	applymovement OBJ_EVENT_ID_PLAYER, ChangeDeoxysForm_Movement
	waitmovement 0
	delay 60
	msgbox ChangeDeoxysForm_Text_Beginning, MSGBOX_DEFAULT
	goto ChangeDeoxysForm_Start
ChangeDeoxysForm_End:
	msgbox ChangeDeoxysForm_Text_End, MSGBOX_DEFAULT
	callnative UpdateFollowingPokemon
	releaseall
	end

ChangeDeoxysForm_Start::
	msgbox ChangeDeoxysForm_Text_Select, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq ChangeDeoxysForm_End
	compare VAR_RESULT, YES
	goto_if_eq ChangeDeoxysForm_Start_Select_Pokemon

ChangeDeoxysForm_Start_Select_Pokemon::
	special ChoosePartyMon
	waitstate
	compare VAR_0x8004, 255
	goto_if_eq ChangeDeoxysForm_End
	special TryChangeDeoxysForm
	compare VAR_RESULT, TRUE
	goto_if_eq ChangeDeoxysForm_Success
	compare VAR_RESULT, FALSE
	goto_if_eq ChangeDeoxysForm_End_Wrong_Pokemon
	goto ChangeDeoxysForm_End

ChangeDeoxysForm_Success:
	playmoncry SPECIES_DEOXYS, 0
	msgbox ChangeDeoxysForm_Text_Success, MSGBOX_DEFAULT
	waitmoncry
	waitbuttonpress
	goto ChangeDeoxysForm_End

ChangeDeoxysForm_End_Wrong_Pokemon::
	msgbox ChangeDeoxysForm_Text_End_Wrong_Pokemon, MSGBOX_DEFAULT
	releaseall
	end

ChangeDeoxysForm_End_Nothing_Happened::
	delay 20
	msgbox ChangeDeoxysForm_Text_End, MSGBOX_DEFAULT
	waitmessage
	releaseall
	end

ChangeDeoxysForm_Text_NormalForm:
	.string "On dirait un météorite NORMAL.\n"
	.string "Il a une surface rugueuse et sèche.$"

ChangeDeoxysForm_Text_DefenseForm:
	.string "On dirait un météorite SOLIDE.\n"
	.string "Semble incassable, comme un diamant.$"

ChangeDeoxysForm_Text_AttackForm:
	.string "On dirait un MÉTÉORITE puissant.\n"
	.string "Il est brûlant au toucher.$"

ChangeDeoxysForm_Text_SpeedForm:
	.string "Ça ressemble à un météorite LÉGER.\n"
	.string "Je peux le soulever très facilement !$"

ChangeDeoxysForm_Text_Beginning:
	.string "Un de mes POKéMON a réagi !$"

ChangeDeoxysForm_Text_End:
	.string "Je devrais y aller.$"

ChangeDeoxysForm_Text_End_Wrong_Pokemon:
	.string "Mon POKéMON a adoré toucher\n"
	.string "la météorite plus que je ne le pensais !\p"
	.string "Mais rien ne s'est passé...\n"
	.string "Je devrais y aller.$"

ChangeDeoxysForm_Text_Select:
	.string "Est-ce que je devrais laisser un de mes POKéMON\n"
	.string "toucher cette météorite ?$"

ChangeDeoxysForm_Text_Success:
	.string "Quelque chose est arrivé à DEOXYS !$"

ChangeDeoxysForm_Movement:
	emote_question_mark
	step_end
