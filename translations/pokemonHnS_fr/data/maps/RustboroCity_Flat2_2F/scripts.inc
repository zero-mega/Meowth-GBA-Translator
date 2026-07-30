RustboroCity_Flat2_2F_MapScripts::
	.byte 0

RustboroCity_Flat2_2F_EventScript_OldMan::
	msgbox RustboroCity_Flat2_2F_Text_DevonWasTinyInOldDays, MSGBOX_NPC
	end

RustboroCity_Flat2_2F_EventScript_NinjaBoy::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_PREMIER_BALL_RUSTBORO, RustboroCity_Flat2_2F_EventScript_GavePremierBall
	msgbox RustboroCity_Flat2_2F_Text_MyDaddyMadeThisYouCanHaveIt, MSGBOX_DEFAULT
	giveitem ITEM_PREMIER_BALL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_PREMIER_BALL_RUSTBORO
	release
	end

RustboroCity_Flat2_2F_EventScript_GavePremierBall::
	msgbox RustboroCity_Flat2_2F_Text_GoingToWorkAtDevonToo, MSGBOX_DEFAULT
	release
	end

RustboroCity_Flat2_2F_Text_DevonWasTinyInOldDays:
	.string "Il y a bien longtemps, DEVON n'était qu'une\n"
	.string "toute petite entreprise.$"

RustboroCity_Flat2_2F_Text_MyDaddyMadeThisYouCanHaveIt:
	.string "Mon papa travaille à la SOCIÉTÉ.\p"
	.string "Mon papa a fait ça !\n"
	.string "Mais je ne peux pas l'utiliser, alors prends-le.$"

RustboroCity_Flat2_2F_Text_GoingToWorkAtDevonToo:
	.string "Mon papa travaille à la SOCIÉTÉ.\p"
	.string "Quand je serai grand, je travaillerai pour\n"
	.string "DEVON aussi.$"

