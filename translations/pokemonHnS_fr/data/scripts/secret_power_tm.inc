Route111_Text_MakingRoomUseTMToMakeYourOwn:
	.string "Quoi ?\n"
	.string "Qu'est-ce que je fais ?\p"
	.string "Je réfléchis à faire ma propre salle\n"
	.string "ici avec une attaque POKéMON.\p"
	.string "Je sais ! Je vais te donner cette CT.\n"
	.string "Tu l'utiliseras pour faire ta propre salle ?$"

Route111_Text_ExplainSecretPower:
	.string "Trouve un grand arbre qui semble\n"
	.string "pouvoir laisser tomber des lianes.\p"
	.string "Utilise FORCE CACHÉE devant l'arbre.\n"
	.string "Des lianes devraient se détacher et tomber,\l"
	.string "pour que tu puisses grimper l'arbre.\p"
	.string "Tu trouveras beaucoup d'espace pour mettre\n"
	.string "tes objets préférés.\p"
	.string "Ce sera ta propre salle secrète…\n"
	.string "une BASE SECRÈTE !\p"
	.string "Tu devrais en faire une aussi.\p"
	.string "Autre chose, tu n'as pas toujours besoin\n"
	.string "de faire ta BASE SECRÈTE dans un arbre.\p"
	.string "Essaie d'utiliser FORCE CACHÉE sur les parois\n"
	.string "rocheuses qui ont de petites indentations.\p"
	.string "Je vais chercher d'autres endroits aussi.\n"
	.string "D'accord, salut !$"

Route111_Text_DontWantThis:
	.string "Oh, tu n'en veux pas ?\n"
	.string "Si tu changes d'avis, dis-le-moi, OK ?$"

Route111_Text_DontHaveAnyRoom:
	.string "Oh, tu n'as pas de place pour ça.\p"
	.string "Je vais le garder, alors reviens le chercher\n"
	.string "une autre fois, OK ?$"

Route111_EventScript_SecretPowerMan::
	lock
	faceplayer
	msgbox Route111_Text_MakingRoomUseTMToMakeYourOwn, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, Route111_EventScript_GiveSecretPower
	msgbox Route111_Text_DontWantThis, MSGBOX_DEFAULT
	release
	end

Route111_EventScript_GiveSecretPower::
	giveitem ITEM_TM_SECRET_POWER
	goto_if_eq VAR_RESULT, FALSE, Route111_EventScript_NoRoomForSecretPower
	msgbox Route111_Text_ExplainSecretPower, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_RECEIVED_SECRET_POWER
	clearflag FLAG_GARBAGEFLAG
	call_if_eq VAR_FACING, DIR_WEST, Route111_EventScript_SecretPowerManExit
	call_if_eq VAR_FACING, DIR_EAST, Route111_EventScript_SecretPowerManExit
	call_if_eq VAR_FACING, DIR_NORTH, Route111_EventScript_SecretPowerManExitNorth
	removeobject VAR_LAST_TALKED
	release
	end

Route111_EventScript_SecretPowerManExit::
	applymovement VAR_LAST_TALKED, Route111_Movement_SecretPowerManExit
	waitmovement 0
	return

Route111_EventScript_SecretPowerManExitNorth::
	applymovement VAR_LAST_TALKED, Route111_Movement_SecretPowerManExitNorth
	waitmovement 0
	return

Route111_EventScript_NoRoomForSecretPower::
	msgbox Route111_Text_DontHaveAnyRoom, MSGBOX_DEFAULT
	release
	end

Route111_Movement_SecretPowerManExit:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

Route111_Movement_SecretPowerManExitNorth:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	step_end
