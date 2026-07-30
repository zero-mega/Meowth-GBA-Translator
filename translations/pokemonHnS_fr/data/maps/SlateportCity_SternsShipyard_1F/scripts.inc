.set LOCALID_DOCK, 1

SlateportCity_SternsShipyard_1F_MapScripts::
	.byte 0

SlateportCity_SternsShipyard_1F_EventScript_Dock::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, SlateportCity_SternsShipyard_1F_EventScript_FerryReady
	goto_if_set FLAG_BADGE07_GET, SlateportCity_SternsShipyard_1F_EventScript_BrineyJoined
	goto_if_set FLAG_DELIVERED_DEVON_GOODS, SlateportCity_SternsShipyard_1F_EventScript_NeedVeteran
	goto_if_set FLAG_DOCK_REJECTED_DEVON_GOODS, SlateportCity_SternsShipyard_1F_EventScript_GoFindStern
	msgbox SlateportCity_SternsShipyard_1F_Text_CantMakeHeadsOrTails, MSGBOX_DEFAULT
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_MeetDockDeliverToStern, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DOCK, Common_Movement_FaceOriginalDirection
	waitmovement 0
	setflag FLAG_DOCK_REJECTED_DEVON_GOODS
	setflag FLAG_GARBAGEFLAG
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_FerryReady::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_FerryIsReady, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_BrineyJoined::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_BrineyJoinedUs, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_GoFindStern::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_CouldYouFindStern, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_DOCK, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_NeedVeteran::
	applymovement LOCALID_DOCK, Common_Movement_FacePlayer
	waitmovement 0
	msgbox SlateportCity_SternsShipyard_1F_Text_CouldUseAdviceFromVeteran, MSGBOX_DEFAULT
	releaseall
	end

SlateportCity_SternsShipyard_1F_EventScript_Scientist1::
	msgbox SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_EventScript_Scientist2::
	msgbox SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_EventScript_Briney::
	msgbox SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock, MSGBOX_NPC
	end

SlateportCity_SternsShipyard_1F_Text_CantMakeHeadsOrTails:
	.string "Euh… Si ça va ici, et que ça\n"
	.string "va là-bas…\p"
	.string "Alors, où va ce truc ?\n"
	.string "Et ce bidule, alors ?\p"
	.string "Aaargh ! Je n'y comprends\n"
	.string "plus rien !$"

SlateportCity_SternsShipyard_1F_Text_MeetDockDeliverToStern:
	.string "Hm ?\n"
	.string "Salut, je\p"
	.string "suis DOCK.\n"
	.string "Le CAPT.\p"
	.string "POIVRE\n"
	.string "m'a commandé de\p"
	.string "concevoir\n"
	.string "un ferry.\p"
	.string "Oh ! Ça là-bas…\n"
	.string "Ce sont des\p"
	.string "produits\n"
	.string "DEVON S.A. ?$"

SlateportCity_SternsShipyard_1F_Text_CouldYouFindStern:
	.string "CHANTIER : Où le CAPT.\n"
	.string "LOUGE est-il passé ? Tu\p"
	.string "pourrais aller le trouver et\n"
	.string "lui livrer ce colis ?$"

SlateportCity_SternsShipyard_1F_Text_CouldUseAdviceFromVeteran:
	.string "CHANTIER : La construction navale est un art.\p"
	.string "Beaucoup de choses ne peuvent pas être\n"
	.string "comprises par le calcul seul.\p"
	.string "J'aurais vraiment besoin des conseils d'un vétéran\n"
	.string "qui connaît les mers…$"

SlateportCity_SternsShipyard_1F_Text_BrineyJoinedUs:
	.string "CHANTIER : Salut ! M. CORAIL s'est joint\n"
	.string "à nous pour nous aider.\p"
	.string "Grâce à ce vieux loup de mer, le\n"
	.string "ferry prend forme petit à petit.$"

SlateportCity_SternsShipyard_1F_Text_FerryIsReady:
	.string "DOCK : Le ferry est enfin\p"
	.string "prêt ! Le nouveau S.S.\n"
	.string "MARÉE est vraiment une merveille\p"
	.string "de technologie ! Mais, j'ai\n"
	.string "le sentiment qu'on peut faire\p"
	.string "encore mieux. Tu sais, la\n"
	.string "technologie n'a jamais de fin.$"

SlateportCity_SternsShipyard_1F_Text_DecidedToHelpDock:
	.string "M. BRINEY : Ah, {PLAYER}{KUN} !\n"
	.string "Ça fait trop longtemps !\p"
	.string "Aye, depuis que je t'ai\n"
	.string "rencontré, ce vieux loup de mer\p"
	.string "se sent fringant !\n"
	.string "Alors j'ai décidé\p"
	.string "d'aider DOCK à fabriquer\n"
	.string "un ferry.\p"
	.string "Aye, après tout, un ferry pourrait\n"
	.string "traverser les mers\p"
	.string "avec des POKéMON !\n"
	.string "Ça serait génial, non ?\l"
	.string "Aye, j'ai hâte !$"

SlateportCity_SternsShipyard_1F_Text_SeaIsLikeLivingThing:
	.string "Les saisons, la météo, la position\n"
	.string "de la lune dans le ciel…\p"
	.string "Tout cela et d'autres conditions font\n"
	.string "que la mer change d'expression.\p"
	.string "C'est vrai !\n"
	.string "La mer est comme un être vivant !$"

SlateportCity_SternsShipyard_1F_Text_GetSeasickEasily:
	.string "Le mal de mer me prend facilement.\n"
	.string "Alors je préfère aider ici.$"

