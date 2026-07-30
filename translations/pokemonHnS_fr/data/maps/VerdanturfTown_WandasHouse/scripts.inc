VerdanturfTown_WandasHouse_MapScripts::
	.byte 0

VerdanturfTown_WandasHouse_EventScript_Wally::
	lock
	faceplayer
	goto_if_set FLAG_WALLY_SPEECH, VerdanturfTown_WandasHouse_EventScript_WallyShortSpeech
	msgbox VerdanturfTown_WandasHouse_Text_StrongerSpeech, MSGBOX_DEFAULT
	setflag FLAG_WALLY_SPEECH
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallyShortSpeech::
	msgbox VerdanturfTown_WandasHouse_Text_StrongerSpeechShort, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncle::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, VerdanturfTown_WandasHouse_EventScript_WallysUncleEverGrande
	goto_if_set FLAG_DEFEATED_ECRUTEAK_CITY_GYM, VerdanturfTown_WandasHouse_EventScript_WallysUncleSlippedOff
	msgbox VerdanturfTown_WandasHouse_Text_WallysNextDoor, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncleSlippedOff::
	msgbox VerdanturfTown_WandasHouse_Text_WallySlippedOff, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysUncleEverGrande::
	msgbox VerdanturfTown_WandasHouse_Text_WallyGoneThatFar, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WandasBoyfriend::
	msgbox VerdanturfTown_WandasHouse_Text_CanSeeGirlfriendEveryDay, MSGBOX_NPC
	end

VerdanturfTown_WandasHouse_EventScript_Wanda::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_ECRUTEAK_CITY_GYM, VerdanturfTown_WandasHouse_EventScript_WandaDontWorry
	goto_if_set FLAG_DEFEATED_WALLY_MAUVILLE, VerdanturfTown_WandasHouse_EventScript_MeetWanda
	msgbox VerdanturfTown_WandasHouse_Text_DontWorryAboutWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_MeetWanda::
	msgbox VerdanturfTown_WandasHouse_Text_MeetWanda, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WandaDontWorry::
	msgbox VerdanturfTown_WandasHouse_Text_DontWorryAboutWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAunt::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_WALLY_VICTORY_ROAD, VerdanturfTown_WandasHouse_EventScript_WallysAuntEverGrande
	goto_if_set FLAG_DEFEATED_ECRUTEAK_CITY_GYM, VerdanturfTown_WandasHouse_EventScript_WallysAuntAnythingHappened
	goto_if_set FLAG_RUSTURF_TUNNEL_OPENED, VerdanturfTown_WandasHouse_EventScript_WallysAuntTunnelOpen
	msgbox VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendDriven, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntTunnelOpen::
	msgbox VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendWasDigging, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntAnythingHappened::
	msgbox VerdanturfTown_WandasHouse_Text_IfAnythingHappenedToWally, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_EventScript_WallysAuntEverGrande::
	msgbox VerdanturfTown_WandasHouse_Text_WallyWasInEverGrande, MSGBOX_DEFAULT
	release
	end

VerdanturfTown_WandasHouse_Text_StrongerSpeech:
	.string "WALLY : J'ai perdu contre toi,\n"
	.string "{PLAYER}, mais je ne me sens\p"
	.string "plus abattu.\n"
	.string "Parce que j'ai un\l"
	.string "nouveau but dans la vie.\l"
	.string "Ensemble avec mes\p"
	.string "POKéMON, je vais devenir\n"
	.string "plus fort !\p"
	.string "Un jour, je te battrai, {PLAYER} !\n"
	.string "Mais pour l'instant, merci pour tout !$"

VerdanturfTown_WandasHouse_Text_StrongerSpeechShort:
	.string "TIMMY : Regarde-moi, {PLAYER}.\n"
	.string "Je vais devenir plus fort que toi.\p"
	.string "Quand ce sera le cas, je te défierai\n"
	.string "à un autre combat.$"

VerdanturfTown_WandasHouse_Text_WallysNextDoor:
	.string "ONCLE : Oh ! {PLAYER}{KUN} !\n"
	.string "TIMMY est à côté.\p"
	.string "Mais, mon garçon, j'ai quelque chose\n"
	.string "à te dire.\p"
	.string "Cet environnement naturel fait\n"
	.string "des merveilles pour la santé de TIMMY.\p"
	.string "Peut-être que ce n'est pas que\n"
	.string "l'environnement. Ce sont peut-être les POKéMON qui redonnent\l"
	.string "espoir au garçon.$"

VerdanturfTown_WandasHouse_Text_WallySlippedOff:
	.string "WALLY est parti…\n"
	.string "Il s'est éclipsé tout seul…$"

VerdanturfTown_WandasHouse_Text_WallyGoneThatFar:
	.string "ONCLE : C'est vrai ?\n"
	.string "TIMMY est parti si loin\l"
	.string "tout seul…\p"
	.string "Eh bien, il faut le reconnaître - c'est\n"
	.string "le fils de mon petit frère.$"

VerdanturfTown_WandasHouse_Text_MeetWanda:
	.string "WANDA : Tu es ? Oh,\n"
	.string "d'accord, je comprends ! Tu es\p"
	.string "le {PLAYER} dont TIMMY me\n"
	.string "parlait. Je suis la cousine\p"
	.string "de TIMMY. Enchantée ! Je\n"
	.string "pense que TIMMY est devenu\p"
	.string "plus vif et en meilleure\n"
	.string "santé depuis qu'il est ici.$"

VerdanturfTown_WandasHouse_Text_DontWorryAboutWally:
	.string "WANDA : Ne t'inquiète pas pour\n"
	.string "PETER. Il ira bien. Je connais\p"
	.string "mon petit cousin, et il a\n"
	.string "des POKéMON avec lui aussi.$"

VerdanturfTown_WandasHouse_Text_CanSeeGirlfriendEveryDay:
	.string "Grâce à toi, je peux voir ma copine\n"
	.string "chaque jour.\l"
	.string "Heureux ? Tu paries !$"

VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendDriven:
	.string "Le petit ami de ma fille\n"
	.string "est une personne très motivée et\p"
	.string "passionnée. Il creuse un tunnel sans\n"
	.string "arrêt juste pour voir ma fille.\p"
	.string "Ma fille est un peu inquiète,\n"
	.string "alors elle va souvent au tunnel.$"

VerdanturfTown_WandasHouse_Text_DaughtersBoyfriendWasDigging:
	.string "C'est incroyable. Le petit ami de ma fille\n"
	.string "creusait le tunnel à la main !\p"
	.string "C'est tellement incroyable !$"

VerdanturfTown_WandasHouse_Text_IfAnythingHappenedToWally:
	.string "S'il arrivait quoi que ce soit à WALLY,\n"
	.string "je ne pourrais jamais regarder ses\l"
	.string "parents de CLÉMENTI-VILLE dans les yeux...$"

VerdanturfTown_WandasHouse_Text_WallyWasInEverGrande:
	.string "WALLY était à EVER GRANDE ?\p"
	.string "Ses parents à PETALBURG seraient\n"
	.string "ébahis d'entendre ça !$"

