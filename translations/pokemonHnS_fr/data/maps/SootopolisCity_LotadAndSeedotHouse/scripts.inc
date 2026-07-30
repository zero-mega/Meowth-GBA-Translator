SootopolisCity_LotadAndSeedotHouse_MapScripts::
	.byte 0

SootopolisCity_LotadAndSeedotHouse_EventScript_SeedotBrother::
	special GetSeedotSizeRecordInfo
	lock
	faceplayer
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigSeedot, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	copyvar VAR_RESULT, VAR_0x8004
	goto_if_eq VAR_RESULT, PARTY_NOTHING_CHOSEN, SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowSeedot
	special CompareSeedotSize
	bufferunitsystemtext UNIT_TEXT_LENGTH_SMALL_PLURAL, 1
	goto_if_eq VAR_RESULT, 1, SootopolisCity_LotadAndSeedotHouse_EventScript_NotSeedot
	goto_if_eq VAR_RESULT, 2, SootopolisCity_LotadAndSeedotHouse_EventScript_SmallSeedot
	goto_if_eq VAR_RESULT, 3, SootopolisCity_LotadAndSeedotHouse_EventScript_BigSeedot
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigSeedot, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NotSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotSeedot, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_SmallSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerSeedot, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_BigSeedot::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_GoshMightBeBiggerThanLotad, MSGBOX_DEFAULT
	giveitem ITEM_ELIXIR
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir1
	closemessage
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir1::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull1, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_LotadBrother::
	special GetLotadSizeRecordInfo
	lock
	faceplayer
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigLotad, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	copyvar VAR_RESULT, VAR_0x8004
	goto_if_eq VAR_RESULT, PARTY_NOTHING_CHOSEN, SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowLotad
	special CompareLotadSize
	bufferunitsystemtext UNIT_TEXT_LENGTH_SMALL_PLURAL, 1
	goto_if_eq VAR_RESULT, 1, SootopolisCity_LotadAndSeedotHouse_EventScript_NotLotad
	goto_if_eq VAR_RESULT, 2, SootopolisCity_LotadAndSeedotHouse_EventScript_SmallLotad
	goto_if_eq VAR_RESULT, 3, SootopolisCity_LotadAndSeedotHouse_EventScript_BigLotad
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_CancelShowLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigLotad, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NotLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotLotad, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_SmallLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerLotad, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_BigLotad::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_WowMightBeBiggerThanSeedot, MSGBOX_DEFAULT
	giveitem ITEM_ELIXIR
	goto_if_eq VAR_RESULT, FALSE, SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir2
	closemessage
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_NoRoomForElixir2::
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull2, MSGBOX_DEFAULT
	release
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_SeedotSizeRecord::
	special GetSeedotSizeRecordInfo
	lockall
	bufferunitsystemtext UNIT_TEXT_LENGTH_SMALL_SINGLE, 1
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BiggestSeedotInHistory, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_LotadAndSeedotHouse_EventScript_LotadSizeRecord::
	special GetLotadSizeRecordInfo
	lockall
	bufferunitsystemtext UNIT_TEXT_LENGTH_SMALL_SINGLE, 1
	msgbox SootopolisCity_LotadAndSeedotHouse_Text_BiggestLotadInHistory, MSGBOX_DEFAULT
	releaseall
	end

SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigSeedot:
	.string "Tu connais le\n"
	.string "POKéMON\p"
	.string "GRAINIPIOT ?\n"
	.string "On le voit\p"
	.string "rarement\n"
	.string "à ATALANOPOLIS.\p"
	.string "Bref, j'adore les\n"
	.string "gros GRAINIPIOT.\p"
	.string "Ils sont si\n"
	.string "mignons !$"

SootopolisCity_LotadAndSeedotHouse_Text_GoshMightBeBiggerThanLotad:
	.string "{STR_VAR_2} {STR_VAR_1} !\n"
	.string "Oh là là, c'en est un gros !\p"
	.string "Il pourrait même battre le gros NÉNUPIOT\n"
	.string "que mon petit frère a vu !\p"
	.string "Merci de me l'avoir montré.\n"
	.string "Voici ma façon de te remercier !$"

@ Unused
SootopolisCity_LotadAndSeedotHouse_Text_ReceivedPotion1:
	.string "{PLAYER} a reçu une POTION.$"

SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull1:
	.string "Hein ?\n"
	.string "Ton SAC est bourré.$"

SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerSeedot:
	.string "{STR_VAR_2} {STR_VAR_1}, c'est ça ?\p"
	.string "Hmm… J'ai vu un GRAINIOT\n"
	.string "plus grand que celui-ci.$"

SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotSeedot:
	.string "Oh, c'est vraiment quelque chose…\n"
	.string "Mais ce n'est pas un GRAINIPIOT !$"

SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigSeedot:
	.string "Tu n'as pas un grand GRAINIPIOT ?\n"
	.string "C'est dommage…\p"
	.string "Si tu attrapes un grand GRAINIPIOT,\n"
	.string "viens me le montrer.$"

SootopolisCity_LotadAndSeedotHouse_Text_BiggestSeedotInHistory:
	.string "Le plus grand GRAINIPIOT de l'histoire\n"
	.string "! Le géant {STR_VAR_2}-{STR_VAR_3} de {STR_VAR_1}\p"
	.string "! Un GRAINIPIOT plus grand qu'un\n"
	.string "NÉNUPIOT ne pouvait rêver mieux !$"

SootopolisCity_LotadAndSeedotHouse_Text_PleaseShowMeBigLotad:
	.string "Tu connais le\n"
	.string "POKéMON NENUPIOT ?\p"
	.string "On le voit rarement\p"
	.string "à ATALANOPOLIS.\n"
	.string "J'adore, je\p"
	.string "veux dire\n"
	.string "j'adore les\p"
	.string "gros NENUPIOT !\n"
	.string "Mon préféré !$"

SootopolisCity_LotadAndSeedotHouse_Text_WowMightBeBiggerThanSeedot:
	.string "{STR_VAR_2} {STR_VAR_1} !\n"
	.string "Wow, c'est gros !\p"
	.string "Ça pourrait être encore plus gros que\n"
	.string "le gros GRAINIPIOT que mon grand frère a vu.\p"
	.string "Merci de me l'avoir montré !\n"
	.string "Voici ma façon de te remercier !$"

@ Unused
SootopolisCity_LotadAndSeedotHouse_Text_ReceivedPotion2:
	.string "{PLAYER} a reçu une POTION.$"

SootopolisCity_LotadAndSeedotHouse_Text_BagCrammedFull2:
	.string "Hein ?\n"
	.string "Ton SAC est bourré.$"

SootopolisCity_LotadAndSeedotHouse_Text_SeenBiggerLotad:
	.string "{STR_VAR_2} {STR_VAR_1} ?\p"
	.string "Hmm… J'ai déjà vu un NENUPIOT\n"
	.string "plus gros que celui-ci.$"

SootopolisCity_LotadAndSeedotHouse_Text_ThatsNotLotad:
	.string "Eh bien, c'est quelque chose !\n"
	.string "Mais ce n'est pas un NÉNUPIOT !$"

SootopolisCity_LotadAndSeedotHouse_Text_DontHaveBigLotad:
	.string "Tu n'as pas un grand NÉNUFOR ?\n"
	.string "Quelle déception…\p"
	.string "Si tu attrapes un grand NÉNUFOR,\n"
	.string "viens me le montrer !$"

SootopolisCity_LotadAndSeedotHouse_Text_BiggestLotadInHistory:
	.string "Le plus grand NÉNUPIOT de l'histoire !\n"
	.string "Le colosse {STR_VAR_2}-{STR_VAR_3} de {STR_VAR_1} !\p"
	.string "Un NÉNUPIOT plus grand qu'un GRAINIPIOT\n"
	.string "ne pouvait rêver mieux !$"
