AzaleaTown_House1_MapScripts::
	.byte 0

AzaleaTown_House1_EventScript_Boss::
	lock
	faceplayer
	goto_if_eq VAR_AZALEA_TOWN_STATE, 5, AzaleaTown_House1_EventScript_Boss3
	goto_if_eq VAR_AZALEA_TOWN_STATE, 6, AzaleaTown_House1_EventScript_Boss3
	goto_if_eq VAR_AZALEA_TOWN_STATE, 7, AzaleaTown_House1_EventScript_Boss4
	goto_if_set FLAG_HIDE_AZALEA_TOWN_ROCKETS, AzaleaTown_House1_EventScript_Boss2
	msgbox CharcoalKiln_Text_Boss1, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Boss2::
	msgbox CharcoalKiln_Text_Boss2, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Boss3::
	msgbox CharcoalKiln_Text_Boss3, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Boss4::
	msgbox CharcoalKiln_Text_Boss4, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Apprentice::
	lock
	faceplayer
	goto_if_ge VAR_AZALEA_TOWN_STATE, 7, AzaleaTown_House1_EventScript_Apprentice3
	goto_if_set FLAG_HIDE_AZALEA_TOWN_ROCKETS, AzaleaTown_House1_EventScript_Apprentice2
	msgbox CharcoalKiln_Text_Apprentice1, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Apprentice2::
	msgbox CharcoalKiln_Text_Apprentice2, MSGBOX_DEFAULT
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Apprentice3::
	goto_if_set FLAG_GOT_CHARCOAL, AzaleaTown_House1_EventScript_Apprentice4
	msgbox CharcoalKiln_Text_Apprentice3, MSGBOX_DEFAULT
	giveitem ITEM_CHARCOAL 
	setflag FLAG_GOT_CHARCOAL
	closemessage
	release
	end

AzaleaTown_House1_EventScript_Apprentice4::
	msgbox CharcoalKiln_Text_Apprentice4, MSGBOX_DEFAULT
	closemessage
	release
	end


AzaleaTown_House1_EventScript_Farfetchd::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_FARFETCHD, CRY_MODE_NORMAL
	msgbox CharcoalKiln_Text_Farfetchd, MSGBOX_DEFAULT
	waitmoncry
	release
	end
	


CharcoalKiln_Text_Boss1:
	.string "Tous les RAMOLOSS ont disparu\n"
	.string "de la ville.\p"
	.string "Le protecteur de la forêt est peut-être\n"
	.string "en colère contre nous…\p"
	.string "Ce pourrait être un mauvais présage. Nous\n"
	.string "devrions rester à l'intérieur.$"

CharcoalKiln_Text_Boss2:
	.string "Les RAMOLOSS sont revenus…$"

CharcoalKiln_Text_Boss3:
	.string "Les RAMOLOSS sont revenus… Mais mon\p"
	.string "APPRENTI n'est pas revenu du\n"
	.string "BOIS AUX CHÊNES. Où est\p"
	.string "ce fainéant, au juste ?$"

CharcoalKiln_Text_Boss4:
	.string "Tu as chassé la TEAM ROCKET et\n"
	.string "tu es allé seul dans la FORÊT D'ILEX ?\p"
	.string "Ça demande du cran ! J'aime ça.\n"
	.string "Viens t'entraîner avec nous.$"

CharcoalKiln_Text_Apprentice1:
	.string "Où sont passés tous les RAMOLOSS ?\p"
	.string "Sont-ils en train de jouer quelque part ?$"

CharcoalKiln_Text_Apprentice2:
	.string "Le RAMOLOSS est revenu !$"

CharcoalKiln_Text_Apprentice3:
	.string "Je suis désolé, j'ai oublié de\p"
	.string "te remercier. C'est du CHARBON que\p"
	.string "j'ai fabriqué. Les POKéMON FEU\n"
	.string "seraient heureux de le tenir.$"

CharcoalKiln_Text_Apprentice4:
	.string "Le RAMOLOSS est revenu, et tu as même\n"
	.string "trouvé CANARTICHAO.\p"
	.string "Tu es le plus cool, mec !$"

CharcoalKiln_Text_Farfetchd:
	.string "CANARTICHO : Kwaa !$"
