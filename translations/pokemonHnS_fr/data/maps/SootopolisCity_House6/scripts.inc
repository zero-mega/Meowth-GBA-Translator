SootopolisCity_House6_MapScripts::
	.byte 0

SootopolisCity_House6_EventScript_Woman::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_WAILMER_DOLL, SootopolisCity_House6_EventScript_ReceivedWailmerDoll
	msgbox SootopolisCity_House6_Text_FirstGuestInWhileTakeDoll, MSGBOX_YESNO
	call_if_eq VAR_RESULT, NO, SootopolisCity_House6_EventScript_DeclineWailmerDoll
	msgbox SootopolisCity_House6_Text_TakeGoodCareOfIt, MSGBOX_DEFAULT
	givedecoration DECOR_WAILMER_DOLL
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_House6_EventScript_NoRoomForWailmerDoll
	setflag FLAG_RECEIVED_WAILMER_DOLL
	release
	end

SootopolisCity_House6_EventScript_DeclineWailmerDoll::
	msgbox SootopolisCity_House6_Text_DontWantThisDoll, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House6_EventScript_ReceivedWailmerDoll::
	msgbox SootopolisCity_House6_Text_LovePlushDolls, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House6_EventScript_NoRoomForWailmerDoll::
	bufferdecorationname STR_VAR_2, DECOR_WAILMER_DOLL
	msgbox gText_NoRoomLeftForAnother, MSGBOX_DEFAULT
	msgbox SootopolisCity_House6_Text_IllHoldItForYou, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House6_Text_FirstGuestInWhileTakeDoll:
	.string "Bonjour ! Vous êtes notre premier\n"
	.string "visiteur depuis longtemps. Vous avez illuminé\p"
	.string "ma journée, alors je vous\n"
	.string "offre une grande PELUCHE WAILMER.$"

SootopolisCity_House6_Text_TakeGoodCareOfIt:
	.string "Prends-en bien soin !$"

SootopolisCity_House6_Text_IllHoldItForYou:
	.string "Oh, tu le veux, mais pas maintenant ?\n"
	.string "OK, je te le garde.$"

SootopolisCity_House6_Text_DontWantThisDoll:
	.string "Tu es sûr ?\n"
	.string "Tu ne veux pas cette POUPÉE ?$"

SootopolisCity_House6_Text_LovePlushDolls:
	.string "J'adore les POUPEES en peluche !$"

