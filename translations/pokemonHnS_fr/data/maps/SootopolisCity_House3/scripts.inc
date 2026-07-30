SootopolisCity_House3_MapScripts::
	.byte 0

SootopolisCity_House3_EventScript_Woman::
	lock
	faceplayer
	msgbox SootopolisCity_House3_Text_JuanHasManyFansDoYou, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, SootopolisCity_House3_EventScript_HaveFans
	msgbox SootopolisCity_House3_Text_LonesomeTryWorkingHarder, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House3_EventScript_HaveFans::
	msgbox SootopolisCity_House3_Text_YouMustBePrettyStrong, MSGBOX_DEFAULT
	release
	end

SootopolisCity_House3_EventScript_Girl::
	msgbox SootopolisCity_House3_Text_TrainerFanClubWasWild, MSGBOX_NPC
	end

SootopolisCity_House3_Text_JuanHasManyFansDoYou:
	.string "Tu es un DRESSEUR de POKéMON, n'est-ce pas ?\p"
	.string "JUAN d'ATALANOPOLIS a beaucoup de fans.\n"
	.string "Encore plus que son élève ALIX !\p"
	.string "Tu en as ?$"

SootopolisCity_House3_Text_YouMustBePrettyStrong:
	.string "Oh, alors tu dois être assez fort.$"

SootopolisCity_House3_Text_LonesomeTryWorkingHarder:
	.string "Oh, mince…\n"
	.string "C'est un peu triste.\p"
	.string "Essaie un peu plus fort d'avoir\n"
	.string "des fans.$"

SootopolisCity_House3_Text_TrainerFanClubWasWild:
	.string "Des fans dévoués viennent même\n"
	.string "d'ailleurs qu'à HOENN.\p"
	.string "C'était la folie quand je suis allé\n"
	.string "au FAN CLUB DES DRESSEURS à NÉNUCRIQUE.$"

