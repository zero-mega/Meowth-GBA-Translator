.set LOCALID_SSAQUA_B1F_SAILORLOOKING, 10

SSAqua_B1F_MapScripts::
	.byte 0

SSAqua_B1F_EventScript_Trigger::
	lock
	turnobject LOCALID_SSAQUA_B1F_SAILORLOOKING, DIR_EAST
	turnobject OBJ_EVENT_ID_PLAYER, DIR_WEST
	msgbox SSAqua_B1F_Text_FastShipOnDutySailor, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown1
	waitmovement 0 
	turnobject LOCALID_SSAQUA_B1F_SAILORLOOKING, DIR_SOUTH
	release
	end

SSAqua_B1F_EventScript_SailorLookingForBuddy::
	lock
	faceplayer
	goto_if_set FLAG_HIDE_SSAQUA_SAILOR, SSAqua_B1F_EventScript_SailorLookingFoundBuddy
	msgbox SSAqua_B1F_Text_FastShipOnDutySailor, MSGBOX_DEFAULT
	closemessage
	release
	end

SSAqua_B1F_EventScript_SailorLookingFoundBuddy::
	msgbox SSAqua_B1F_Text_FastShipOnDutySailorThanks, MSGBOX_DEFAULT
	goto_if_lt VAR_SSAQUA_STATE, 5, SSAqua_B1F_EventScript_SailorGirl
	closemessage
	release
	end
SSAqua_B1F_EventScript_SailorGirl::
	msgbox SSAqua_B1F_Text_FastShipOnDutySailorSawGirl, MSGBOX_DEFAULT
	closemessage
	release
	end

SSAqua_B1F_EventScript_SleepySailor::
	msgbox SSAqua_B1F_Text_FastShipOnDutySailorDirections, MSGBOX_NPC
	end

SSAqua_B1F_EventScript_Barfcan::
	msgbox SSAqua_B1F_Text_BarfCan, MSGBOX_SIGN
	end

SSAqua_B1F_Text_BarfCan:
    .string "Beurk !\n"
    .string "J'aurais pas dû regarder !$"

SSAqua_B1F_Text_FastShipOnDutySailor:
	.string "Hé, gamin. Tu pourrais\n"
	.string "chercher mon pote ?\p"
	.string "Il glande quelque part,\n"
	.string "ce fainéant !\p"
	.string "J'aimerais bien aller le chercher, mais je suis\n"
	.string "de service en ce moment.$"

SSAqua_B1F_Text_FastShipOnDutySailorRefused:
	.string "Oh, zut…\p"
	.string "Le CAPITAINE va être furieux…$"

SSAqua_B1F_Text_FastShipOnDutySailorThanks:
	.string "Merci, gamin ! Je lui ai passé un savon\n"
	.string "pour qu'il arrête de paresser !$"

SSAqua_B1F_Text_FastShipOnDutySailorSawGirl:
	.string "Une petite fille ?\p"
	.string "Je l'ai peut-être vue passer par ici.$"

SSAqua_B1F_Text_FastShipOnDutySailorDirections:
	.string "La salle à manger est juste devant.\p"
	.string "Les escaliers au bout mènent à\n"
	.string "la cabine du CAPITAINE.$"

SSAqua_B1F_EventScript_Jeff::
	trainerbattle_single TRAINER_JEFF SSAqua_B1F_Text_SailorJeffSeen, SSAqua_B1F_Text_SailorJeffBeaten
	msgbox SSAqua_B1F_Text_SailorJeffAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_SailorJeffSeen:
	.string "Rien ne vaut un combat pendant\n"
	.string "ma pause.$"

SSAqua_B1F_Text_SailorJeffBeaten:
	.string "Gagné ou perdu, ma pause est finie !$"

SSAqua_B1F_Text_SailorJeffAfter:
	.string "Je ne peux pas gagner si je ne\n"
	.string "me mets pas sérieusement.$"

SSAqua_B1F_EventScript_Debra::
	trainerbattle_single TRAINER_DEBRA SSAqua_B1F_Text_PicnickerDebraSeen, SSAqua_B1F_Text_PicnickerDebraBeaten
	msgbox SSAqua_B1F_Text_PicnickerDebraAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_PicnickerDebraSeen:
	.string "Je m'ennuie. On se bat ?$"

SSAqua_B1F_Text_PicnickerDebraBeaten:
	.string "Aïe ! Tu es trop fort !$"

SSAqua_B1F_Text_PicnickerDebraAfter:
	.string "SAFRANIA, CELADOPOLIS… J'ai entendu dire qu'il y a\n"
	.string "beaucoup de grandes villes à KANTO.$"

SSAqua_B1F_EventScript_Fritz::
	trainerbattle_single TRAINER_FRITZ SSAqua_B1F_Text_JugglerFritzSeen, SSAqua_B1F_Text_JugglerFritzBeaten
	msgbox SSAqua_B1F_Text_JugglerFritzAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_JugglerFritzSeen:
	.string "Urrf… J'ai le mal de mer !$"

SSAqua_B1F_Text_JugglerFritzBeaten:
	.string "Je ne peux plus bouger…$"

SSAqua_B1F_Text_JugglerFritzAfter:
	.string "Fini les bateaux pour moi.\n"
	.string "La prochaine fois,\p"
	.string "je prendrai le TRAIN MAGNÉTIQUE.$"

SSAqua_B1F_EventScript_Garrett::
	trainerbattle_single TRAINER_GARRETT SSAqua_B1F_Text_SailorGarrettSeen, SSAqua_B1F_Text_SailorGarrettBeaten
	msgbox SSAqua_B1F_Text_SailorGarrettAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_SailorGarrettSeen:
	.string "C'est ici que nous, marins, travaillons !$"

SSAqua_B1F_Text_SailorGarrettBeaten:
	.string "J'ai perdu sur mon propre terrain…$"

SSAqua_B1F_Text_SailorGarrettAfter:
	.string "Nous avons des passagers différents\n"
	.string "de CARMIN SUR MER à\p"
	.string "OLIVILLE.$"

SSAqua_B1F_EventScript_Jonah::
	trainerbattle_single TRAINER_JONAH SSAqua_B1F_Text_FisherJonahSeen, SSAqua_B1F_Text_FisherJonahBeaten
	msgbox SSAqua_B1F_Text_FisherJonahAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_FisherJonahSeen:
	.string "Même si on est en pleine mer,\n"
	.string "je ne peux pas pêcher !\p"
	.string "C'est ennuyeux ! Combattons !$"

SSAqua_B1F_Text_FisherJonahBeaten:
	.string "Je… Je ne m'ennuie plus…$"

SSAqua_B1F_Text_FisherJonahAfter:
	.string "Je prévois de pêcher sur le quai\n"
	.string "de CARMIN SUR MER.$"

SSAqua_B1F_EventScript_Wai::
	trainerbattle_single TRAINER_WAI SSAqua_B1F_Text_BlackbeltWaiSeen, SSAqua_B1F_Text_BlackbeltWaiBeaten
	msgbox SSAqua_B1F_Text_BlackbeltWaiAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_BlackbeltWaiSeen:
	.string "Je renforce mes jambes en\n"
	.string "me tenant\p"
	.string "contre le roulis du navire !$"

SSAqua_B1F_Text_BlackbeltWaiBeaten:
	.string "Écrasé et roulé dessus !$"

SSAqua_B1F_Text_BlackbeltWaiAfter:
	.string "Je n'ai pas trouvé le ROI DU KARATÉ\n"
	.string "en JOHTO.\p"
	.string "Il est censé s'entraîner dans\n"
	.string "une grotte quelque part.$"

SSAqua_B1F_EventScript_Kenneth::
	trainerbattle_single TRAINER_KENNETH SSAqua_B1F_Text_SailorKennethSeen, SSAqua_B1F_Text_SailorKennethBeaten
	msgbox SSAqua_B1F_Text_SailorKennethAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_SailorKennethSeen:
	.string "Je suis un marin !\p"
	.string "Mais j'entraîne des POKéMON pour\n"
	.string "devenir le CHAMPION !$"

SSAqua_B1F_Text_SailorKennethBeaten:
	.string "Mon manque d'entraînement est évident…$"

SSAqua_B1F_Text_SailorKennethAfter:
	.string "Huit BADGES ! Ça doit prouver\n"
	.string "que tu as battu\p"
	.string "des CHAMPIONS D'ARÈNE.\p"
	.string "Pas étonnant que tu sois si fort !$"

SSAqua_B1F_EventScript_Shirley::
	trainerbattle_single TRAINER_SHIRLEY SSAqua_B1F_Text_TeacherShirleySeen, SSAqua_B1F_Text_TeacherShirleyBeaten
	msgbox SSAqua_B1F_Text_TeacherShirleyAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_TeacherShirleySeen:
	.string "Ne touche pas à mes\n"
	.string "élèves !$"

SSAqua_B1F_Text_TeacherShirleyBeaten:
	.string "Aaack !$"

SSAqua_B1F_Text_TeacherShirleyAfter:
	.string "On est en sortie scolaire aux\n"
	.string "RUINES près de MAUVILLE.$"

SSAqua_B1F_EventScript_Nate::
	trainerbattle_single TRAINER_NATE SSAqua_B1F_Text_SchoolboyNateSeen, SSAqua_B1F_Text_SchoolboyNateBeaten
	msgbox SSAqua_B1F_Text_SchoolboyNateAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_SchoolboyNateSeen:
	.string "Tu connais les RUINES D'ALPHA ?$"

SSAqua_B1F_Text_SchoolboyNateBeaten:
	.string "Yaargh !$"

SSAqua_B1F_Text_SchoolboyNateAfter:
	.string "Les radios captent des signaux étranges\n"
	.string "dans les RUINES.$"

SSAqua_B1F_EventScript_Ricky::
	trainerbattle_single TRAINER_RICKY SSAqua_B1F_Text_SchoolboyRickySeen, SSAqua_B1F_Text_SchoolboyRickyBeaten
	msgbox SSAqua_B1F_Text_SchoolboyRickyAfter, MSGBOX_AUTOCLOSE
	end

SSAqua_B1F_Text_SchoolboyRickySeen:
	.string "Il y a d'étranges panneaux de pierre\n"
	.string "dans les RUINES D'ALPHA.$"

SSAqua_B1F_Text_SchoolboyRickyBeaten:
	.string "J'ai été battu !$"

SSAqua_B1F_Text_SchoolboyRickyAfter:
	.string "J'ai lu qu'il y avait quatre de\n"
	.string "ces panneaux en pierre.$"

