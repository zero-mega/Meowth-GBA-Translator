Route111_OldLadysRestStop_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route111_OldLadysRestStop_OnTransition
	.byte 0

Route111_OldLadysRestStop_OnTransition:
	setflag FLAG_LANDMARK_OLD_LADY_REST_SHOP
	end

Route111_OldLadysRestStop_EventScript_OldLady::
	lock
	faceplayer
	msgbox Route111_OldLadysRestStop_Text_RestUpHere, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_OldLadysRestStop_EventScript_Rest
	goto_if_eq VAR_RESULT, NO, Route111_OldLadysRestStop_EventScript_DeclineRest
	end

Route111_OldLadysRestStop_EventScript_Rest::
	specialvar VAR_RESULT, IsPokecenterChallengeActivated
    goto_if_eq VAR_RESULT, TRUE, Route111_OldLadysRestStop_EventScript_Rest_PokecenterChallenge
	msgbox Route111_OldLadysRestStop_Text_TakeYourTimeRestUp, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	msgbox Route111_OldLadysRestStop_Text_StillTiredTakeAnotherRest, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_OldLadysRestStop_EventScript_Rest
	goto_if_eq VAR_RESULT, NO, Route111_OldLadysRestStop_EventScript_DeclineRest
	end

Route111_OldLadysRestStop_EventScript_Rest_PokecenterChallenge::
	msgbox Route111_OldLadysRestStop_Text_PokecenterChallenge, MSGBOX_DEFAULT
	closemessage
	end

Route111_OldLadysRestStop_EventScript_DeclineRest::
	msgbox Route111_OldLadysRestStop_Text_DontNeedToBeShy, MSGBOX_DEFAULT
	release
	end

Route111_OldLadysRestStop_Text_PokecenterChallenge:
	.string "Désolé, tu joues\n"
	.string "avec le DÉFI POKéCENTER !$"
	
Route111_OldLadysRestStop_Text_RestUpHere:
	.string "Oh là là, oh là là. Tes\n"
	.string "POKéMON ne sont pas épuisés ?\p"
	.string "Si tu veux, repose-toi ici. C'est\n"
	.string "une bonne idée ! Tu devrais.$"

Route111_OldLadysRestStop_Text_TakeYourTimeRestUp:
	.string "C'est ça.\n"
	.string "Prends ton temps et repose-toi !$"

Route111_OldLadysRestStop_Text_StillTiredTakeAnotherRest:
	.string "Oh là là, oh là là.\n"
	.string "Tes POKéMON sont encore fatigués ?\p"
	.string "Repose-toi encore ici.\n"
	.string "C'est une bonne idée. Tu devrais.$"

Route111_OldLadysRestStop_Text_DontNeedToBeShy:
	.string "C'est ça ?\n"
	.string "Pas besoin d'être timide.$"

