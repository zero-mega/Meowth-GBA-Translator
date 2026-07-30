MysteryGiftScript_AlteringCave::
	setvaddress MysteryGiftScript_AlteringCave
	addvar VAR_ALTERING_CAVE_WILD_SET, 1
	vgoto_if_ne VAR_ALTERING_CAVE_WILD_SET, (NUM_ALTERING_CAVE_TABLES + 1), MysteryGiftScript_AlteringCave_
	setvar VAR_ALTERING_CAVE_WILD_SET, 0
MysteryGiftScript_AlteringCave_:
	lock
	faceplayer
	vmessage sText_MysteryGiftAlteringCave
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftAlteringCave:
	.string "Merci d'utiliser le système\n"
	.string "CADEAU MYSTÈRE.\p"
	.string "Il semble y avoir une rumeur sur\n"
	.string "des POKéMON rares aperçus.\p"
	.string "Les signalements viendraient de\n"
	.string "la GROTTE ALTÉRÉE sur la ROUTE 103.\p"
	.string "Peut-être vaudrait-il la peine\n"
	.string "d'enquêter sur cette rumeur.$"
