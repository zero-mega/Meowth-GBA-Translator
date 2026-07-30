Route47_MapScripts::
	.byte 0


Route47_EventScript_Hiker::
	trainerbattle_single TRAINER_DEVIN, Route47_Text_HikerSeen, Route47_Text_HikerBeaten
	msgbox Route47_Text_HikerAfter, MSGBOX_AUTOCLOSE
	end

Route47_Text_HikerSeen::
	.string "Le désir des autres, c'est...\n"
	.string "ce que c'est. \p"
	.string "Mais les combats sont des combats,\n"
	.string "alors allons-y !$"

Route47_Text_HikerBeaten::
	.string "Wahaha !$"

Route47_Text_HikerAfter::
	.string "Après un combat, il faut toujours partir\n"
	.string "avec un dernier rire !$"

Route47_EventScript_Camper::
	trainerbattle_single TRAINER_GRANT, Route47_Text_CamperSeen, Route47_Text_CamperBeaten
	msgbox Route47_Text_CamperAfter, MSGBOX_AUTOCLOSE
	end

Route47_Text_CamperSeen::
	.string "Je n'aime pas les grandes foules, alors\n"
	.string "je campe ici avec mes\l"
	.string "POKéMON !$"

Route47_Text_CamperBeaten::
	.string "Je devrais aller plus profondément\n"
	.string "dans la montagne, je suppose…$"

Route47_Text_CamperAfter::
	.string "À plus !$"

Route47_EventScript_Thom::
	trainerbattle_double TRAINER_THOM_AND_KAE, Route47_Text_Couple1Seen, Route47_Text_Couple1Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route47_Text_Couple1After1, MSGBOX_AUTOCLOSE
	end

Route47_EventScript_Kae::
	trainerbattle_double TRAINER_THOM_AND_KAE, Route47_Text_Couple1Seen, Route47_Text_Couple1Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route47_Text_Couple1After2, MSGBOX_AUTOCLOSE
	end

Route47_Text_Couple1Seen::
	.string "THOM : Un plus un, ça fait deux.\n"
	.string "Mais ensemble, on est bien\l"
	.string "plus forts !\p"
	.string "KAE : Nous deux, on n'est pas\n"
	.string "un couple ennuyeux !$"

Route47_Text_Couple1Beaten::
	.string "THOM : Ce n'était pas ce que j'attendais.\l"
	.string "KAE : Tu es inhabituel toi aussi !$"

Route47_Text_Couple1After1::
	.string "THOM : Il semble que ta puissance\n"
	.string "soit impossible à prévoir !$"

Route47_Text_Couple1After2::
	.string "KAE : Je pensais que tu étais un DRESSEUR\n"
	.string "solitaire ordinaire. Comme j'avais tort !$"

Route47_EventScript_Duff::
	trainerbattle_double TRAINER_DUFF_AND_EDA, Route47_Text_Couple2Seen, Route47_Text_Couple2Beaten, Route104_Text_GinaNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route47_Text_Couple2After1, MSGBOX_AUTOCLOSE
	end

Route47_EventScript_Eda::
	trainerbattle_double TRAINER_DUFF_AND_EDA, Route47_Text_Couple2Seen, Route47_Text_Couple2Beaten, Route104_Text_GinaNotEnoughMons
	msgbox Route47_Text_Couple2After2, MSGBOX_AUTOCLOSE
	end

Route47_Text_Couple2Seen::
	.string "DUFF : Veiller sur ma copine\n"
	.string "fait battre mon cœur !\p"
	.string "EDA : Les sentiments de mon cœur pour mon\n"
	.string "petit ami sont aussi vastes et profonds\l"
	.string "que l'océan !$"

Route47_Text_Couple2Beaten::
	.string "DUFF : Je n'étais pas de taille…\l"
	.string "EDA : Tu es vraiment quelque chose...$"

Route47_Text_Couple2After1::
	.string "DUFF : Merci pour ce combat\n"
	.string "grandiose ! Au revoir !$"

Route47_Text_Couple2After2::
	.string "EDA : Tu devrais vraiment trouver\n"
	.string "un merveilleux partenaire, toi aussi !$"

Route47_EventScript_Sage::
	lock
	faceplayer
	msgbox EmbeddedTower_Text_OldManIntro, MSGBOX_DEFAULT
	closemessage
	release
	end

EmbeddedTower_Text_OldManIntro:
	.string "Eh bien, bonjour !\p"
	.string "On dit qu'autrefois, au-delà de ce trou,\n"
	.string "il y avait une immense\l"
	.string "tour atteignant le ciel.\p"
	.string "On dit que c'était une tour plutôt étrange\n"
	.string "avec la moitié enfoncée dans la falaise.\l"
	.string "Ce n'était pas seulement\p"
	.string "une haute tour atteignant\n"
	.string "le ciel, mais aussi s'enfonçant profondément\l"
	.string "sous terre !\p"
	.string "On raconte qu'elle atteignait même\n"
	.string "le fond de l'océan !\p"
	.string "En bref, les ruines reliaient autrefois\n"
	.string "le ciel, la terre et la mer…\l"
	.string "La majeure partie de la\p"
	.string "tour s'est effondrée,\n"
	.string "et il ne reste que\l"
	.string "l'entrée et son intérieur,\l"
	.string "où tu verras d'étranges motifs.$"

Route47_EventScript_Item_Pearl::
    finditem ITEM_PEARL
    end

Route47_EventScript_Item_Revive::
    finditem ITEM_REVIVE
    end

Route47_EventScript_Item_WhiteFlute::
    finditem ITEM_WHITE_FLUTE
    end

Route47_EventScript_Item_Stardust::
	finditem ITEM_STARDUST
	end

Route47_EventScript_Item_LuckyPunch::
	finditem ITEM_LUCKY_PUNCH
	end

Route47_EventScript_Chinchou::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_CHINCHOU, CRY_MODE_NORMAL
	msgbox Route47_Text_Chinchou, MSGBOX_DEFAULT
	waitmoncry
	release
	end

Route47_Text_Chinchou:
	.string "LOUPIO : Chou !$"
