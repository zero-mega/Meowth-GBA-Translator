.set LOCALID_OWNER, 1

LilycoveCity_CoveLilyMotel_1F_MapScripts::
	.byte 0

LilycoveCity_CoveLilyMotel_1F_EventScript_MotelOwner::
	lockall
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_CoveLilyMotel_1F_EventScript_GameClear
	goto_if_set FLAG_BADGE07_GET, LilycoveCity_CoveLilyMotel_1F_EventScript_AquaHideoutBusted
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_GuestsDoubledByMascot, MSGBOX_DEFAULT
	applymovement LOCALID_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_NoGuestsWithTeamAqua, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_AquaHideoutBusted::
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_MonFoundLostItem, MSGBOX_DEFAULT
	applymovement LOCALID_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_HeardAquaHideoutBusted, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_GameClear::
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_HouseSittingMonCaughtBurglar, MSGBOX_DEFAULT
	applymovement LOCALID_OWNER, Common_Movement_FacePlayer
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_BetterGetWorkingOnGuestsDinner, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OWNER, Common_Movement_FaceOriginalDirection
	waitmovement 0
	releaseall
	end

LilycoveCity_CoveLilyMotel_1F_EventScript_BlockingTV::
	lockall
	playse SE_PIN
	applymovement LOCALID_OWNER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_OWNER, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	msgbox LilycoveCity_CoveLilyMotel_1F_Text_CantSeeTheTV, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, LilycoveCity_CoveLilyMotel_1F_Movement_PlayerPushFromTV
	applymovement LOCALID_OWNER, LilycoveCity_CoveLilyMotel_1F_Movement_OwnerPushPlayer
	waitmovement 0
	applymovement LOCALID_OWNER, LilycoveCity_CoveLilyMotel_1F_Movement_OwnerReturn
	waitmovement 0
	release
	end

LilycoveCity_CoveLilyMotel_1F_Movement_PlayerPushFromTV:
	face_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

LilycoveCity_CoveLilyMotel_1F_Movement_OwnerPushPlayer:
	walk_up
	step_end

LilycoveCity_CoveLilyMotel_1F_Movement_OwnerReturn:
	face_down
	walk_down
	face_up
	step_end

LilycoveCity_CoveLilyMotel_1F_Text_GuestsDoubledByMascot:
	.string "Hm, alors ils ont doublé les clients\n"
	.string "en utilisant les POKéMON comme attractions ?\p"
	.string "Hm, eh bien, peut-être que je devrais\n"
	.string "faire d'un POKéMON mignon la mascotte de\p"
	.string "notre auberge. Je me demande si ça\n"
	.string "attirera plus de clients chez nous ?$"

LilycoveCity_CoveLilyMotel_1F_Text_NoGuestsWithTeamAqua:
	.string "Oh, pardon, pardon !\n"
	.string "J'étais trop absorbé par la télé !\p"
	.string "Depuis que la TEAM AQUA est arrivée en ville,\n"
	.string "les touristes sont restés loin.$"

LilycoveCity_CoveLilyMotel_1F_Text_CantSeeTheTV:
	.string "Hé, devant !\n"
	.string "Je ne vois pas la télé !$"

LilycoveCity_CoveLilyMotel_1F_Text_MonFoundLostItem:
	.string "Incroyable ! Un POKéMON a retrouvé\n"
	.string "l'objet perdu de quelqu'un ?\p"
	.string "C'est quelque chose. Si on avait des POKéMON\n"
	.string "intelligents comme ça…\p"
	.string "On pourrait récupérer tout ce que nos\n"
	.string "clients ont égaré…$"

LilycoveCity_CoveLilyMotel_1F_Text_HeardAquaHideoutBusted:
	.string "Oh, pardon, pardon ! J'étais\n"
	.string "trop absorbé par la TV\p"
	.string "! J'ai entendu que quelqu'un\n"
	.string "a démantelé la PLANQUE TEAM\p"
	.string "AQUA. Grâce à ça, on\n"
	.string "vient de réserver un groupe\p"
	.string "important. C'était une entreprise appelée…\n"
	.string "Euh… GAME quelque chose…$"

LilycoveCity_CoveLilyMotel_1F_Text_HouseSittingMonCaughtBurglar:
	.string "Incroyable ! Un POKéMON gardant la maison\n"
	.string "a attrapé un cambrioleur ?\p"
	.string "C'est quelque chose. Si on avait un POKéMON\n"
	.string "robuste comme garde…\p"
	.string "On pourrait offrir plus de sécurité\n"
	.string "à nos clients.$"

LilycoveCity_CoveLilyMotel_1F_Text_BetterGetWorkingOnGuestsDinner:
	.string "Oh, pardon, pardon ! J'étais trop\n"
	.string "absorbé par la TV. Oh, oui.\p"
	.string "Un grand groupe d'invités est arrivé\n"
	.string "il y a un moment. Ils\p"
	.string "se sont enregistrés sous GAME FREAK,\n"
	.string "alors je suppose qu'ils font des\p"
	.string "jeux. Oh-oh, je ferais mieux\n"
	.string "de préparer leur dîner !$"

