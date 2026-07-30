GoldenrodCity_BikeShop_MapScripts::
	.byte 0

GoldenrodCity_BikeShop_EventScript_Clerk::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_BIKE, GoldenrodCity_BikeShop_EventScript_Clerk_BikeReceived
	msgbox GoldenrodCity_BikeShop_Text_ClerkIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_BikeShop_EventScript_Clerk_BikeAgreed
	msgbox GoldenrodCity_BikeShop_Text_Refused, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BikeShop_EventScript_Clerk_BikeAgreed::
	msgbox GoldenrodCity_BikeShop_Text_ClerkAgreed, MSGBOX_DEFAULT
	giveitem ITEM_MACH_BIKE
	setflag FLAG_RECEIVED_BIKE
	closemessage
	release
	end

GoldenrodCity_BikeShop_EventScript_Clerk_BikeReceived::
	msgbox GoldenrodCity_BikeShop_Text_Mainshop, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BikeShop_EventScript_Clerk2::
	lock
	faceplayer
	msgbox GoldenrodCity_BikeShop_Text_Clerk2, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BikeShop_EventScript_Bike::
	lock
	msgbox GoldenrodCity_BikeShop_Text_Bicycle, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_BikeShop_Text_Clerk2:
	.string "Faire du VÉLO est aussi simple que\n"
	.string "d'appuyer sur un bouton si tu l'\l"
	.string "ENREGISTRES depuis le SAC.\p"
	.string "Si tu as besoin d'aller plus vite,\n"
	.string "tu dois d'abord t'arrêter !\p"
	.string "Ça peut sembler être un conseil\n"
	.string "étrange, mais tu ne peux changer\l"
	.string "les vitesses du VÉLO qu'à l'arrêt.\p"
	.string "Appuie sur ton bouton R à l'arrêt\n"
	.string "et la prochaine fois que tu pédaleras,\l"
	.string "tu atteindras des vitesses plus grandes !$"

GoldenrodCity_BikeShop_Text_ClerkIntro:
    .string "…soupir… Je suis venu ici, mais je\n"
    .string "n'arrive pas à vendre mes VÉLOS. Pourquoi\p"
    .string "? Tu pourrais faire du vélo et\n"
    .string "faire de la pub pour moi ?$"

GoldenrodCity_BikeShop_Text_ClerkAgreed:
    .string "Vraiment ? Génial !\p"
    .string "Donne-moi ton nom et ton numéro de téléphone,\n"
    .string "et je te prête un BICYCLETTE.$"

GoldenrodCity_BikeShop_Text_BorrowedBicycle:
    .string "{PLAYER} a emprunté un VÉLO.$"

GoldenrodCity_BikeShop_Text_Mainshop:
	.string "Les affaires ont\n"
	.string "été difficiles\l"
	.string "depuis notre\p"
	.string "déménagement de KANTO.\n"
	.string "Nous apprécions ton aide !\p"
	.string "Peux-tu acheter\n"
	.string "quelque chose ?\p"
	.string "Merci !$"

GoldenrodCity_BikeShop_Text_Refused:
    .string "…soupir… Oh, la gentillesse\n"
    .string "des gens…$"

GoldenrodCity_BikeShop_Text_JustReleasedCompact:
    .string "Sortie récente !\p"
    .string "BICYCLETTES compactes de premier choix !$"

GoldenrodCity_BikeShop_Text_Bicycle:
    .string "C'est une BICYCLETTE toute neuve !$"
