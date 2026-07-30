.set LOCALID_CAFE_JASMINE, 4

OlivineCity_Cafe_MapScripts::
	.byte 0

OlivineCity_Cafe_EventScript_Jasmine::
	lock
	faceplayer
	msgbox OlivineCity_Cafe_Text_Jasmine, MSGBOX_DEFAULT
	closemessage
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_CAFE_JASMINE
	removeobject LOCALID_CAFE_JASMINE
	fadescreenswapbuffers FADE_FROM_BLACK
	clearflag FLAG_HIDE_DOJO_JASMINE
	release
	end

OlivineCity_Cafe_Text_Jasmine:
	.string "Oh… Bonjour, {PLAYER}. Ces plats\p"
	.string "devant moi ne sont pas\n"
	.string "tous à moi… Euh… En\p"
	.string "fait, la personne assise\p"
	.string "ici avant moi a\n"
	.string "beaucoup mangé… Si tu\p"
	.string "veux te battre à\n"
	.string "nouveau, viens me voir\l"
	.string "au DOJO sur SAFRANIA.$"

OlivineCity_EventScript_SailorA::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_HM_STRENGTH, OlivineCity_EventScript_SailorA2
	msgbox OlivineCity_Text_CafeSailorStrength, MSGBOX_DEFAULT
	giveitem ITEM_HM_STRENGTH
	setflag FLAG_RECEIVED_HM_STRENGTH
OlivineCity_EventScript_SailorA2::
	msgbox OlivineCity_Text_CafeSailorGotStrength, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_Cook::
	lock
	faceplayer
	msgbox OlivineCity_Text_CafeFishingGuru, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_EventScript_SailorB::
	lock
	faceplayer
	msgbox OlivineCity_Text_CafeSailor, MSGBOX_DEFAULT
	closemessage
	release
	end

OlivineCity_Text_CafeSailorStrength:
	.string "Hah ! Tes POKéMON ont l'air bien\n"
	.string "légers !\p"
	.string "Ils n'ont pas la force de\n"
	.string "déplacer des rochers.\p"
	.string "Tiens, utilise ça et apprends-leur\n"
	.string "FORCE !$"

OlivineCity_Text_CafeSailorGotStrength:
	.string "En mer, la seule chose sur laquelle\n"
	.string "tu peux compter, c'est toi-même ! Je\p"
	.string "suis si fier de mon corps musclé\n"
	.string "! Tu devrais t'entraîner comme moi !$"

OlivineCity_Text_CafeFishingGuru:
	.string "Le menu du CAFÉ D'OLIVILLE regorge\n"
	.string "de plats copieux pour les MARINS\l"
	.string "costauds comme moi !$"

OlivineCity_Text_CafeSailor:
	.string "Chaque fois que j'arrive dans cette ville,\n"
	.string "je vais toujours au CAFÉ D'OLIVILLE.\p"
	.string "Tout au menu me donne de la force.\n"
	.string "Je ne peux pas m'arrêter de manger !$"

