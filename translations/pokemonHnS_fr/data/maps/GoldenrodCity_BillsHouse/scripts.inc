GoldenrodCity_BillsHouse_MapScripts::
	.byte 0

GoldenrodCity_BillsHouse_EventScript_Sister::
	lock
	faceplayer
	msgbox BillHouse_Text_SisterStorageSystem, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BillsHouse_EventScript_Mom::
	lock
	faceplayer
	goto_if_set FLAG_SYS_PC_BILL, GoldenrodCity_BillsHouse_EventScript_Mom2
	msgbox BillHouse_Text_MomBeforeEcruteak, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BillsHouse_EventScript_Mom2::
	msgbox BillHouse_Text_MomAfterEcruteak, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BillsHouse_EventScript_Bill::
	lock
	faceplayer
	goto_if_unset FLAG_GOT_EEVEE, GoldenrodCity_BillsHouse_EventScript_Bill_Eevee
	msgbox BillHouse_Text_PopWontWork, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BillsHouse_EventScript_Bill_Eevee::
	msgbox BillHouse_Text_TakeThisEevee, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, GoldenrodCity_BillsHouse_EventScript_Bill_Refused
	msgbox BillHouse_Text_CountingOnYou, MSGBOX_DEFAULT

	@HnS named gift pokemon setup
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_EEVEE
	bufferspeciesname STR_VAR_1, SPECIES_EEVEE
	givenamedmon 3
	call Common_EventScript_GiftMonNamed

    

	setflag FLAG_GOT_EEVEE
	msgbox BillHouse_Text_EeveeMayEvolve, MSGBOX_DEFAULT
	closemessage
	release
	end


GoldenrodCity_BillsHouse_EventScript_Bill_Refused::
	msgbox BillHouse_Text_NoEevee, MSGBOX_DEFAULT
	closemessage
	release
	end

BillHouse_Text_TakeThisEevee:
    .string "BILL : Salut, {PLAYER} ! Fais-nous\n"
    .string "une faveur et prends cet EVOLI.\p"
    .string "Il a été confié à nos soins\n"
    .string "pendant que je travaillais sur\p"
    .string "mon système.\n"
    .string "Quelqu'un doit s'en occuper,\p"
    .string "mais je n'aime pas sortir.\n"
    .string "Je peux compter sur toi pour jouer avec, {PLAYER} ?$"

BillHouse_Text_CountingOnYou:
    .string "BILL : Je savais que tu y\p"
    .string "arriverais ! Bravo ! Tu es le\p"
    .string "vrai truc ! OK, je compte\p"
    .string "sur toi. Prends-en bien soin !$"

BillHouse_Text_ReceivedEevee:
    .string "{PLAYER} a reçu EVOLI !$"

BillHouse_Text_EeveeMayEvolve:
    .string "BILL : Le PROF.ORME prétend qu'EVOLI peut\n"
    .string "évoluer de nouvelles façons inconnues.$"

BillHouse_Text_PartyFull:
    .string "Whoa, attends. Tu ne peux plus porter\n"
    .string "de POKéMON.$"

BillHouse_Text_NoEevee:
    .string "Oh… Que faire maintenant ?$"

BillHouse_Text_PopWontWork:
    .string "BILL : Mon père ne veut pas travailler.\n"
    .string "Il ne fait que paresser toute la journée.\p"
    .string "Il devient vraiment pénible...$"

BillHouse_Text_MomBeforeEcruteak:
    .string "Oh, tu collectionnes les POKéMON ? Mon fils\n"
    .string "BILL est un expert.\p"
    .string "Il vient d'être appelé au CENTRE\n"
    .string "POKéMON d'ECRUTEAK.\p"
    .string "Mon mari est parti au CASINO\n"
    .string "sans qu'on l'appelle…$"

BillHouse_Text_MomAfterEcruteak:
    .string "Mon mari était autrefois connu comme un\n"
    .string "POKéMANIAC.\p"
    .string "PIERRE a dû tenir de son\n"
    .string "père.$"

BillHouse_Text_SisterUsefulNumber:
    .string "Tu es un DRESSEUR ?\p"
    .string "J'ai un numéro de téléphone utile\n"
    .string "pour toi.$"

BillHouse_Text_RecordedBillsNumber:
    .string "{PLAYER} a enregistré le numéro de BILL.$"

BillHouse_Text_SisterRefusedNumber:
    .string "Mon frère a créé le système de stockage\n"
    .string "PC POKéMON.\p"
    .string "J'allais te donner le numéro\n"
    .string "de BILL…$"

BillHouse_Text_SisterPhoneFull:
    .string "Tu ne peux plus enregistrer de numéros.$"

BillHouse_Text_SisterStorageSystem:
    .string "Mon grand frère LÉO a créé le système\n"
    .string "de stockage POKéMON du PC.$"
