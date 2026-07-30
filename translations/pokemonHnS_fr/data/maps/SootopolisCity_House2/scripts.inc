SootopolisCity_House2_MapScripts::
	.byte 0

SootopolisCity_House2_EventScript_ExpertF::
	lock
	faceplayer
	msgbox SootopolisCity_House2_Text_DidYouKnowAboutMtPyreOrbs, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, SootopolisCity_House2_EventScript_KnowAboutOrbs
	call_if_eq VAR_RESULT, NO, SootopolisCity_House2_EventScript_DontKnowAboutOrbs
	release
	end

SootopolisCity_House2_EventScript_KnowAboutOrbs::
	msgbox SootopolisCity_House2_Text_YesTwoOrbsSideBySide, MSGBOX_DEFAULT
	return

SootopolisCity_House2_EventScript_DontKnowAboutOrbs::
	msgbox SootopolisCity_House2_Text_OughtToVisitAndSee, MSGBOX_DEFAULT
	return

SootopolisCity_House2_Text_DidYouKnowAboutMtPyreOrbs:
	.string "MONT PYRÉ…\p"
	.string "Au sommet se trouvent deux orbes placés\n"
	.string "côte à côte. Tu le savais ?$"

SootopolisCity_House2_Text_YesTwoOrbsSideBySide:
	.string "Oui, deux orbes côte à côte…\p"
	.string "Les voir ensemble…\n"
	.string "C'est d'une certaine façon apaisant…$"

SootopolisCity_House2_Text_OughtToVisitAndSee:
	.string "C'est ça ?\n"
	.string "Tu devrais peut-être venir voir…$"

