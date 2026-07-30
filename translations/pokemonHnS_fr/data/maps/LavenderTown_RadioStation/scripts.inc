LavenderTown_RadioStation_MapScripts::
	.byte 0

LavenderTown_RadioStation_EventScript_Officer::
	msgbox LavenderTown_RadioStation_Text_Officer, MSGBOX_NPC
	end

LavenderTown_RadioStation_EventScript_Receptionist::
	msgbox LavenderTown_RadioStation_Text_Receptionist, MSGBOX_NPC
	end

LavenderTown_RadioStation_EventScript_SuperNerd::
	msgbox LavenderTown_RadioStation_Text_SuperNerd1, MSGBOX_NPC
	end

LavenderTown_RadioStation_EventScript_Director::
	lock
	faceplayer
	goto_if_set FLAG_KANTO_RADIO_GOT, LavenderTown_RadioStation_EventScript_DirectorGotRadio
	goto_if_set FLAG_RETURNED_MACHINE_PART, LavenderTown_RadioStation_EventScript_DirectorReturnedMachinePart
	msgbox LavenderTown_RadioStation_Text_Gentleman, MSGBOX_NPC
	end
LavenderTown_RadioStation_EventScript_DirectorReturnedMachinePart::
	msgbox LavenderTown_RadioStation_Text_Gentleman_ReturnedMachinePart, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	msgbox LavendertownRadioStation_Text_Upgraded_Radio, MSGBOX_DEFAULT
	waitfanfare
	msgbox LavenderTown_RadioStation_Text_Gentleman_GotExpnCard, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_KANTO_RADIO_GOT
	release
	end
LavenderTown_RadioStation_EventScript_DirectorGotRadio::	
	msgbox LavenderTown_RadioStation_Text_Gentleman_GotExpnCard, MSGBOX_NPC
	end

LavenderTown_RadioStation_EventScript_Host::
	goto_if_set FLAG_KANTO_RADIO_GOT, LavenderTown_RadioStation_EventScript_Host2
	msgbox LavenderTown_RadioStation_Text_SuperNerd2, MSGBOX_NPC
	end
LavenderTown_RadioStation_EventScript_Host2::
	msgbox LavenderTown_RadioStation_Text_SuperNerd2_GotExpnCard, MSGBOX_NPC
	end

LavenderTown_RadioStation_EventScript_Directory::
	msgbox LavenderTown_RadioStation_Text_Directory, MSGBOX_SIGN
	end
LavenderTown_RadioStation_EventScript_Sign::
	msgbox LavenderTown_RadioStation_Text_PokeFluteSign, MSGBOX_SIGN
	end
LavenderTown_RadioStation_EventScript_Library::
	msgbox LavenderTown_RadioStation_Text_ReferenceLibrary, MSGBOX_SIGN
	end

LavenderTown_RadioStation_Text_Receptionist:
	.string "Bienvenue ! N'hésite pas à regarder\n"
	.string "partout à cet étage.$"

LavenderTown_RadioStation_Text_Officer:
	.string "Désolé, mais vous ne pouvez visiter\n"
	.string "que le rez-de-chaussée.\p"
	.string "Depuis que la TOUR RADIO de JOHTO\n"
	.string "a été prise par un gang criminel,\l"
	.string "nous avons dû renforcer notre\l"
	.string "sécurité.$"

LavenderTown_RadioStation_Text_SuperNerd1:
	.string "Beaucoup de gens travaillent dur ici\n"
	.string "à la TOUR RADIO.\p"
	.string "Ils doivent faire de leur mieux\n"
	.string "pour proposer de bons programmes.$"

LavenderTown_RadioStation_Text_Gentleman:
	.string "Oh, non, non, non !\p"
	.string "On est hors antenne depuis que\n"
	.string "la CENTRALE s'est arrêtée.\p"
	.string "Tous mes efforts pour créer cette\n"
	.string "station seraient perdus si je ne peux pas\l"
	.string "diffuser.\p"
	.string "Je suis ruiné !$"

LavenderTown_RadioStation_Text_Gentleman_ReturnedMachinePart:
	.string "Ah ! Alors tu es {PLAYER}, celui qui\n"
	.string "a résolu le problème de la CENTRALE ?\p"
	.string "Grâce à toi, je n'ai jamais perdu mon\n"
	.string "travail.\p"
	.string "Je te le dis, tu m'as vraiment\n"
	.string "sauvé la mise !\p"
	.string "Prends ça en remerciement.$"

LavendertownRadioStation_Text_Upgraded_Radio:
	.string "{PLAYER} obtient la\n"
	.string "AMÉLIORATION RADIO !$"

LavenderTown_RadioStation_Text_Gentleman_GotExpnCard:
	.string "Avec ça, tu peux écouter les émissions\n"
	.string "radio ici à KANTO.\p"
	.string "Gahahahaha !$"

LavenderTown_RadioStation_Text_SuperNerd2:
	.string "Salut ! Je suis le super\p"
	.string "DIRECTEUR MUSICAL ! Hein ? Ta\p"
	.string "RADIO ne capte pas mes émissions\n"
	.string "musicales. Quel dommage ! Si\p"
	.string "tu obtiens une CARTE EXPN,\n"
	.string "tu pourras écouter. Tu ferais\l"
	.string "mieux d'en avoir une !$"

LavenderTown_RadioStation_Text_SuperNerd2_GotExpnCard:
	.string "Hé, toi !\p"
	.string "Je suis le super DIRECTEUR MUSICAL !\p"
	.string "Je suis responsable des magnifiques\n"
	.string "mélodies diffusées à la radio.\p"
	.string "Ne sois pas ringard. Récupère ta musique\n"
	.string "à la radio !$"

LavenderTown_RadioStation_Text_Directory:
	.string "1ER ACCUEIL 2E VENTES\p"
	.string "3E PERSONNEL 4E PRODUCTION\p"
	.string "5E BUREAU DU DIRECTEUR$"

LavenderTown_RadioStation_Text_PokeFluteSign:
	.string "Réveille les POKéMON avec les doux\n"
	.string "sons de la POKé FLÛTE sur\l"
	.string "le CANAL 20$"

LavenderTown_RadioStation_Text_ReferenceLibrary:
	.string "Ouah ! Un rack complet de CD et vidéos\n"
	.string "POKéMON.\p"
	.string "Ça doit être la bibliothèque\n"
	.string "de référence.$"

