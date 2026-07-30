GoldenrodCity_UndergroundStorage_MapScripts::
	.byte 0

GoldenrodCity_UndergroundStorage_EventScript_Director::
    lock
    faceplayer
    checkitem ITEM_CARD_KEY
    goto_if_eq VAR_RESULT, TRUE, GoldenrodCity_UndergroundStorage_EventScript_Director2
    msgbox RadioTowerBasement_Text_DirectorIntro, MSGBOX_DEFAULT
    closemessage
    giveitem ITEM_CARD_KEY
    msgbox RadioTowerBasement_Text_DirectorCardKey, MSGBOX_DEFAULT
    closemessage
    release
    end

GoldenrodCity_UndergroundStorage_EventScript_Director2::
    msgbox RadioTowerBasement_Text_DirectorAfter, MSGBOX_DEFAULT
    closemessage
    release
    end

GoldenrodCity_UndergroundStorage_EventScript_Grunt19::
    trainerbattle_single TRAINER_GRUNT_19, RadioTowerBasement_Text_GruntM24Seen, RadioTowerBasement_Text_GruntM24Beaten
	msgbox RadioTowerBasement_Text_GruntM24After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_UndergroundStorage_EventScript_Grunt12::
    trainerbattle_single TRAINER_GRUNT_12, RadioTowerBasement_Text_GruntM14Seen, RadioTowerBasement_Text_GruntM14Beaten
	msgbox RadioTowerBasement_Text_GruntM14After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_UndergroundStorage_EventScript_Eto::
    trainerbattle_single TRAINER_ETO_3, RadioTowerBasement_Text_GruntM15Seen, RadioTowerBasement_Text_GruntM15Beaten
	msgbox RadioTowerBasement_Text_GruntM15After, MSGBOX_AUTOCLOSE
	end

GoldenrodCity_UndergroundStorage_EventScript_Item_TM_CALM_MIND::
    finditem ITEM_TM_CALM_MIND
    end

GoldenrodCity_UndergroundStorage_EventScript_Item_UltraBall::
    finditem ITEM_ULTRA_BALL
    end

GoldenrodCity_UndergroundStorage_EventScript_Item_MaxEther::
    finditem ITEM_MAX_ETHER
    end

RadioTowerBasement_Text_GruntM24Seen:
    .string "Comment es-tu arrivé si loin ?\p"
    .string "Je suppose que c'est inévitable. Je vais\n"
    .string "te débarrasser.$"

RadioTowerBasement_Text_GruntM24Beaten:
    .string "On m'a éliminé…$"

RadioTowerBasement_Text_GruntM24After:
    .string "La TEAM ROCKET continuera, en attendant\n"
    .string "le retour de GIOVANNI.\p"
    .string "On fera tout ce qu'il faut.$"

RadioTowerBasement_Text_GruntM14Seen:
    .string "Tu n'iras pas plus loin !\p"
    .string "Je n'ai pas de pitié pour mes ennemis,\n"
    .string "même les gamins !$"

RadioTowerBasement_Text_GruntM14Beaten:
    .string "Bon sang !$"

RadioTowerBasement_Text_GruntM14After:
    .string "J'ai perdu…\p"
    .string "Pardonne-moi, GIOVANNI !$"

RadioTowerBasement_Text_GruntM15Seen:
    .string "Hyuck-hyuck-hyuck ! Regarde qui c'est !\p"
    .string "Prêt ? Je suis vraiment dur maintenant !$"

RadioTowerBasement_Text_GruntM15Beaten:
    .string "Hi hi hi ! Tu es si bon !\p"
    .string "Cette affaire TEAM ROCKET n'est qu'un\n"
    .string "travail, mais je vais quand même me battre\p"
    .string "contre toi !\p"
    .string "Prépare-toi !$"

RadioTowerBasement_Text_GruntM15After:
    .string "Hi hi hi ! C'était génial !\n"
    .string "Je me souviendrai de toi !$"

RadioTowerBasement_Text_DirectorIntro:
    .string "DIRECTEUR : Qui ? Quoi ? Tu es venu\n"
    .string "me sauver ?\p"
    .string "Merci !\p"
    .string "La TOUR RADIO !\p"
    .string "Que se passe-t-il là-bas ?\p"
    .string "Prise par la TEAM ROCKET ?\p"
    .string "Tiens. Prends cette CARTE MAGNÉTIQUE.$"

RadioTowerBasement_Text_DirectorCardKey:
    .string "DIRECTEUR : Utilise ça pour ouvrir\n"
    .string "les volets au 3e étage.$"

RadioTowerBasement_Text_DirectorAfter:
    .string "Je t'en supplie,\p"
    .string "aide-moi.\n"
    .string "On ne sait pas ce\p"
    .string "qu'ils feront s'ils\n"
    .string "contrôlent l'émetteur.\p"
    .string "La TEAM ROCKET doit\p"
    .string "être arrêtée !\p"
    .string "{PLAYER}, aide-nous !$"
