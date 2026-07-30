.set LOCALID_STAIR_GUARD, 2

RustboroCity_DevonCorp_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, RustboroCity_DevonCorp_1F_OnTransition
	.byte 0

RustboroCity_DevonCorp_1F_OnTransition:
	call_if_unset FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_BlockStairs
	end

RustboroCity_DevonCorp_1F_EventScript_BlockStairs::
	setobjectxyperm LOCALID_STAIR_GUARD, 14, 2
	setobjectmovementtype LOCALID_STAIR_GUARD, MOVEMENT_TYPE_FACE_DOWN
	return

RustboroCity_DevonCorp_1F_EventScript_Employee::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_GoodsRecovered
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_RobberWasntBright
	msgbox RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_RobberWasntBright::
	msgbox RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_GoodsRecovered::
	msgbox RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_StairGuard::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_AlwaysWelcome
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_GotRobbed
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_GotRobbed
	msgbox RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_AlwaysWelcome::
	msgbox RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_GotRobbed::
	msgbox RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_Greeter::
	lock
	faceplayer
	goto_if_set FLAG_RETURNED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_WelcomeToDevonCorp
	goto_if_set FLAG_RECOVERED_DEVON_GOODS, RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed
	goto_if_set FLAG_DEVON_GOODS_STOLEN, RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed
	msgbox RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_WelcomeToDevonCorp::
	msgbox RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_StaffGotRobbed::
	msgbox RustboroCity_DevonCorp_1F_Text_StaffGotRobbed, MSGBOX_DEFAULT
	release
	end

RustboroCity_DevonCorp_1F_EventScript_RocksMetalDisplay::
	msgbox RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_1F_EventScript_ProductsDisplay::
	msgbox RustboroCity_DevonCorp_1F_Text_ProductDisplay, MSGBOX_SIGN
	end

RustboroCity_DevonCorp_1F_Text_WelcomeToDevonCorp:
	.string "Bonjour et bienvenue à la DEVON\n"
	.string "SARL. Nous sommes fiers de\p"
	.string "produire des objets et des\n"
	.string "médicaments qui améliorent votre vie.$"

RustboroCity_DevonCorp_1F_Text_StaffGotRobbed:
	.string "Un de nos chercheurs s'est stupidement fait\n"
	.string "voler un colis important.$"

RustboroCity_DevonCorp_1F_Text_ThoseShoesAreOurProduct:
	.string "Hé, ces CHAUSSURES DE COURSE !\n"
	.string "C'est un de nos produits !\p"
	.string "Ça me rend heureux de voir\n"
	.string "quelqu'un utiliser ce qu'on a fabriqué.$"

RustboroCity_DevonCorp_1F_Text_RobberWasntVeryBright:
	.string "Ce colis volé…\p"
	.string "Bon, c'est important, mais ce n'est pas\n"
	.string "quelque chose que n'importe qui peut utiliser.\p"
	.string "À mon avis, ce voleur n'était\n"
	.string "pas très malin.$"

RustboroCity_DevonCorp_1F_Text_SoundsLikeStolenGoodsRecovered:
	.string "On dirait qu'ils ont récupéré\n"
	.string "les MARCHANDISES DEVON volées.$"

RustboroCity_DevonCorp_1F_Text_OnlyAuthorizedPeopleEnter:
	.string "Je suis désolé, seules les personnes autorisées\n"
	.string "peuvent entrer ici.$"

RustboroCity_DevonCorp_1F_Text_HowCouldWeGetRobbed:
	.string "C'est complètement stupide.\n"
	.string "Comment avons-nous pu nous faire voler ?$"

RustboroCity_DevonCorp_1F_Text_YoureAlwaysWelcomeHere:
	.string "Salut !\n"
	.string "Tu es toujours le bienvenu ici !$"

RustboroCity_DevonCorp_1F_Text_RocksMetalDisplay:
	.string "Des échantillons de\n"
	.string "roches et de métal sont\p"
	.string "exposés dans la vitrine.\n"
	.string "Il y a un panneau\p"
	.string "avec une inscription…\n"
	.string "“DEVON S.A. a commencé comme\p"
	.string "producteur de pierres de carrières.\n"
	.string "“L'entreprise fabrique aussi des\p"
	.string "BALLS en métal.\n"
	.string "“DEVON est aujourd'hui\p"
	.string "une entreprise\n"
	.string "technologique de premier plan.”$"

RustboroCity_DevonCorp_1F_Text_ProductDisplay:
	.string "Des prototypes et produits\n"
	.string "de test remplissent\p"
	.string "la vitrine en verre.\p"
	.string "Il y a un panneau\n"
	.string "avec une description…\l"
	.string "“En plus des BALLS industrielles,\p"
	.string "DEVON S.A. développe\n"
	.string "divers produits\l"
	.string "technologiques pour les dresseurs.”$"

