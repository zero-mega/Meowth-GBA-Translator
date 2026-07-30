SaffronCity_FightingDojoVIP_MapScripts::
	.byte 0

SaffronCity_FightingDojoVIP_EventScript_Declined::
	closemessage
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Falkner::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Falkner_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_FALKNER_2, SaffronCity_FightingDojoVIP_Text_Falkner_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Bugsy::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Bugsy_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_BUGSY_2, SaffronCity_FightingDojoVIP_Text_Bugsy_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Whitney::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Whitney_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_WHITNEY_2, SaffronCity_FightingDojoVIP_Text_Whitney_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Morty::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Morty_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_MORTY_2, SaffronCity_FightingDojoVIP_Text_Morty_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Chuck::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Chuck_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_CHUCK_2, SaffronCity_FightingDojoVIP_Text_Chuck_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Jasmine::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Jasmine_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_JASMINE_2, SaffronCity_FightingDojoVIP_Text_Jasmine_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Pryce::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Pryce_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_PRYCE_2, SaffronCity_FightingDojoVIP_Text_Pryce_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Clair::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Clair_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_CLAIR_2, SaffronCity_FightingDojoVIP_Text_Clair_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Brock::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Brock_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_BROCK, SaffronCity_FightingDojoVIP_Text_Brock_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Misty::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Misty_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_MISTY, SaffronCity_FightingDojoVIP_Text_Misty_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Surge::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Surge_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_LTSURGE, SaffronCity_FightingDojoVIP_Text_Surge_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Erika::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Erika_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_ERIKA, SaffronCity_FightingDojoVIP_Text_Erika_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Janine::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Janine_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_JANINE, SaffronCity_FightingDojoVIP_Text_Janine_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Sabrina::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Sabrina_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_SABRINA, SaffronCity_FightingDojoVIP_Text_Sabrina_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Blaine::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Blaine_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_BLAINE, SaffronCity_FightingDojoVIP_Text_Blaine_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

SaffronCity_FightingDojoVIP_EventScript_Blue::
	lock
	faceplayer
	msgbox SaffronCity_FightingDojoVIP_Text_Blue_Rematch, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, SaffronCity_FightingDojoVIP_EventScript_Declined
	closemessage
	trainerbattle_no_intro TRAINER_BLUE, SaffronCity_FightingDojoVIP_Text_Blue_RematchDefeat
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	givebp 10
	msgbox BattleFrontier_Text_ObtainedXBattlePoints, MSGBOX_DEFAULT
	closemessage
	release
	end

@===============MONS===============================================================================================================

SaffronCity_FightingDojoVIP_EventScript_Scizor::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_SCIZOR, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Scizor, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Scizor:
	.string "CIZAYOX : Scii-zor !$"

SaffronCity_FightingDojoVIP_EventScript_Miltank::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MILTANK, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Miltank, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Miltank:
	.string "MILTANK : Meuuuuh !$"

SaffronCity_FightingDojoVIP_EventScript_Poliwhirl::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_POLIWHIRL, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Poliwhirl, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Poliwhirl:
	.string "TETARTOS : Tourne-tourne !$"

SaffronCity_FightingDojoVIP_EventScript_Dewgong::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_DEWGONG, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Dewgong, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Dewgong:
	.string "LAMANTINE : Goooooong !$"

SaffronCity_FightingDojoVIP_EventScript_Steelix::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_STEELIX, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Steelix, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Steelix:
	.string "STEELIX : GraaAAANk !$"

SaffronCity_FightingDojoVIP_EventScript_Kingdra::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KINGDRA, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Kingdra, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Kingdra:
	.string "HYPOROI : Draaa...$"

SaffronCity_FightingDojoVIP_EventScript_Onix::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ONIX, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Onix, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Onix:
	.string "ONIX : Oooonix !$"

SaffronCity_FightingDojoVIP_EventScript_Starmie::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_STARMIE, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Starmie, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Starmie:
	.string "STAROSS : Hyaaa !$"

SaffronCity_FightingDojoVIP_EventScript_Victreebel::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_VICTREEBEL, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Victreebel, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Victreebel:
	.string "EMPIFLOR : Vreeee !$"

SaffronCity_FightingDojoVIP_EventScript_Muk::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MUK, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Muk, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Muk:
	.string "GROTADMORV : Muuuk...$"

SaffronCity_FightingDojoVIP_EventScript_Kadabra::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_KADABRA, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Kadabra, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Kadabra:
	.string "KADABRA : Kadabra !$"

SaffronCity_FightingDojoVIP_EventScript_Magmar::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MAGMAR, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Magmar, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Magmar:
	.string "MAGMAR : Magmaaaar !$"

SaffronCity_FightingDojoVIP_EventScript_Raichu::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_RAICHU, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Raichu, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Raichu:
	.string "RAICHU : Raï-Raï !$"

SaffronCity_FightingDojoVIP_EventScript_Machamp::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MACHAMP, CRY_MODE_NORMAL
	msgbox SaffronCity_FightingDojoVIP_Text_Machamp, MSGBOX_DEFAULT
	waitmoncry
	applymovement2 VAR_LAST_TALKED, Common_Movement_FaceOriginalDirection
	waitmovement 0
	release
	end
SaffronCity_FightingDojoVIP_Text_Machamp:
	.string "MACKOGNEUR : Maa-champ !$"

SaffronCity_FightingDojo_EventScript_Chased::
	msgbox SaffronCity_FightingDojoVIP_Text_Chased, MSGBOX_NPC
	end

SaffronCity_FightingDojoVIP_Text_Chased:
	.string "Au secours !$"

SaffronCity_FightingDojoVIP_EvetScript_Statue::
	msgbox SaffronCity_FightingDojoVIP_Text_Statue, MSGBOX_SIGN
	end

SaffronCity_FightingDojoVIP_Text_Statue:
	.string "SALON VIP DU DOJO DE COMBAT$"

SaffronCity_FightingDojoVIP_Text_Falkner_Rematch:
	.string "Félicitations pour avoir battu\n"
	.string "les 4 DUOS SUPRÊMES !\p"
	.string "J'ai entraîné mes POKéMON\n"
	.string "de type VOL encore plus dur.\p"
	.string "Tu penses pouvoir affronter à nouveau\n"
	.string "la puissance des cieux ?$"

SaffronCity_FightingDojoVIP_Text_Falkner_RematchDefeat:
	.string "Waouh… Tu m'as encore battu.\p"
	.string "Je vais m'entraîner plus dur pour\n"
	.string "devenir le plus grand maître des oiseaux !$"

SaffronCity_FightingDojoVIP_Text_Bugsy_Rematch:
	.string "Waouh, tu es le CHAMPION de JOHTO\n"
	.string "maintenant !\p"
	.string "Tes compétences sont vraiment impressionnantes !\p"
	.string "J'ai été occupé par mes recherches.\p"
	.string "Je suis prêt à te montrer mes nouvelles\n"
	.string "découvertes.\p"
	.string "Tu veux avoir un rematch avec moi ?$"

SaffronCity_FightingDojoVIP_Text_Bugsy_RematchDefeat:
	.string "Waouh, tu dois être un DRESSEUR\n"
	.string "expert.\p"
	.string "Ma recherche n'est peut-être pas\n"
	.string "complète…$"

SaffronCity_FightingDojoVIP_Text_Whitney_Rematch:
	.string "Salut ! C'est toi !\p"
	.string "Wow, CHAMPION de JOHTO maintenant ?\p"
	.string "Tu es vraiment incroyable !\p"
	.string "Je veux voir à quel point tu es fort.\p"
	.string "Envie d'une revanche avec moi ?$"

SaffronCity_FightingDojoVIP_Text_Whitney_RematchDefeat:
	.string "Ouuaaaah !\p"
	.string "Ouuaaaah !\p"
	.string "…Snif, hic… …Méchant !$"

SaffronCity_FightingDojoVIP_Text_Morty_Rematch:
	.string "Ah, le CHAMPION\n"
	.string "de JOHTO !\p"
	.string "Content que\n"
	.string "tu sois venu.\l"
	.string "Tu as montré\p"
	.string "ta force\n"
	.string "et ta compétence,\p"
	.string "mais t'es-tu\n"
	.string "amélioré depuis ?\p"
	.string "Montre-moi !$"

SaffronCity_FightingDojoVIP_Text_Morty_RematchDefeat:
	.string "Je ne suis pas encore assez fort…\p"
	.string "Tu as vu bien plus de choses\n"
	.string "que moi.\p"
	.string "Je t'envie pour ça…$"

SaffronCity_FightingDojoVIP_Text_Chuck_Rematch:
	.string "WAHAHAH ! CHAMPION DE JOHTO ! Tu es\p"
	.string "revenu pour en avoir plus ! Je vois\p"
	.string "que tes compétences se sont améliorées ! Prêt\p"
	.string "à voir qui est le plus fort ?$"

SaffronCity_FightingDojoVIP_Text_Chuck_RematchDefeat:
	.string "Hein ? Quoi ? J'ai perdu ? Encore ?$"

SaffronCity_FightingDojoVIP_Text_Jasmine_Rematch:
	.string "…Félicitations, CHAMPION de\n"
	.string "JOHTO.\p"
	.string "Tu es devenu si fort…\p"
	.string "Je me demande si je me suis améliorée.\p"
	.string "Veux-tu vérifier ça ?\p"
	.string "Tu veux avoir une revanche avec moi ?$"

SaffronCity_FightingDojoVIP_Text_Jasmine_RematchDefeat:
	.string "…Tu es un meilleur Dresseur que\n"
	.string "moi,\p"
	.string "en force et en bonté.$"

SaffronCity_FightingDojoVIP_Text_Pryce_Rematch:
	.string "Ah, CHAMPION DE JOHTO !\p"
	.string "Tes compétences sont en effet\n"
	.string "remarquables. Je suis impressionné. Mais\p"
	.string "même maintenant, on a encore\p"
	.string "beaucoup à apprendre l'un de\n"
	.string "l'autre. Moi, FRÉDÉRIC--le dresseur d'hiver--\p"
	.string "J'ai encore quelques tours dans\p"
	.string "mon sac. Tu veux une\p"
	.string "revanche avec moi ?$"

SaffronCity_FightingDojoVIP_Text_Pryce_RematchDefeat:
	.string "Ah, encore une fois, je\n"
	.string "suis impressionné par tes prouesses.\p"
	.string "Avec ta volonté, je sais\n"
	.string "que tu surmonteras tous les\l"
	.string "obstacles de la vie.$"

SaffronCity_FightingDojoVIP_Text_Clair_Rematch:
	.string "Tu l'as fait, hein ? Tu\p"
	.string "es maintenant le CHAMPION DE JOHTO.\p"
	.string "Tu as prouvé ta force, mais\n"
	.string "peux-tu me battre à nouveau ?\p"
	.string "En tant que Maître Dragon,\n"
	.string "je ne me retiendrai pas.\p"
	.string "Pas cette fois. Tu veux\p"
	.string "une revanche avec moi ?$"

SaffronCity_FightingDojoVIP_Text_Clair_RematchDefeat:
	.string "J'ai perdu ?\p"
	.string "Encore ?\p"
	.string "Je n'y crois pas. Il doit\n"
	.string "être une erreur…$"

SaffronCity_FightingDojoVIP_Text_Brock_Rematch:
	.string "PIERRE : Salut, {PLAYER} !\p"
	.string "J'ai entendu que tu es maintenant le\n"
	.string "CHAMPION de KANTO.\p"
	.string "C'est incroyable !\p"
	.string "Tu dois être encore plus fort maintenant.\p"
	.string "Tu veux avoir une revanche avec moi ?$"

SaffronCity_FightingDojoVIP_Text_Brock_RematchDefeat:
	.string "PIERRE : Tes POKéMON ont encore une fois\n"
	.string "surmonté ma défense de roc…$"

SaffronCity_FightingDojoVIP_Text_Misty_Rematch:
	.string "ONDINE : Wow, tu es le CHAMPION\n"
	.string "de KANTO maintenant !\p"
	.string "C'est incroyable ! Tu es allé\n"
	.string "loin, {PLAYER}.\p"
	.string "Mais je ne recule pas.\p"
	.string "Tu veux avoir une revanche avec moi ?$"

SaffronCity_FightingDojoVIP_Text_Misty_RematchDefeat:
	.string "ONDINE : Tu es vraiment fort…$"

SaffronCity_FightingDojoVIP_Text_Surge_Rematch:
	.string "MAJOR BOB : Alors, tu es\n"
	.string "maintenant CHAMPION de KANTO ! Beau\p"
	.string "travail, gamin ! Mais ne\n"
	.string "crois pas que j'ai fini\p"
	.string "! On remet ça ?$"

SaffronCity_FightingDojoVIP_Text_Surge_RematchDefeat:
	.string "MAJOR BOB : Arrrgh ! Tu es toujours\n"
	.string "aussi fort !$"

SaffronCity_FightingDojoVIP_Text_Erika_Rematch:
	.string "ERIKA : Oh, bonjour. Quelle\p"
	.string "surprise, CHAMPION ! C'est si\p"
	.string "agréable de te revoir. Ton\p"
	.string "voyage a dû être si\n"
	.string "excitant. Même les champions aiment\p"
	.string "un défi. Tu veux une\p"
	.string "revanche avec moi ?$"

SaffronCity_FightingDojoVIP_Text_Erika_RematchDefeat:
	.string "ERIKA : Perdre laisse encore\n"
	.string "un goût amer… Mais savoir\p"
	.string "qu'il y a des DRESSEURS\n"
	.string "forts m'incite à m'améliorer…$"

SaffronCity_FightingDojoVIP_Text_Sabrina_Rematch:
	.string "SABRINA : Ah, le CHAMPION.\p"
	.string "J'ai senti ton retour.\p"
	.string "Ta puissance a énormément grandi.\p"
	.string "Même maintenant, je sens ton aura.\p"
	.string "Tu veux avoir un match retour avec moi ?$"

SaffronCity_FightingDojoVIP_Text_Sabrina_RematchDefeat:
	.string "MORGANE : Ton amour pour tes\n"
	.string "POKéMON a encore submergé mon\l"
	.string "pouvoir psychique…$"

SaffronCity_FightingDojoVIP_Text_Janine_Rematch:
	.string "Fufufufu…\p"
	.string "Waouh, tu l'as fait !\p"
	.string "Tu es le CHAMPION maintenant !\p"
	.string "Je suis si fier de toi ! Mais ne\n"
	.string "pense pas que je vais y aller mollo.\p"
	.string "Tu veux avoir un match retour avec moi ?$"

SaffronCity_FightingDojoVIP_Text_Janine_RematchDefeat:
	.string "JEANINE : Tu es toujours aussi\n"
	.string "coriace !\p"
	.string "Tu as clairement gagné…$"

SaffronCity_FightingDojoVIP_Text_Blaine_Rematch:
	.string "AUGUSTE : Whoa !\p"
	.string "Je vois que tu es devenu le CHAMPION\n"
	.string "DE KANTO !\p"
	.string "C'est brûlant !\p"
	.string "Tes talents sont de premier ordre.\p"
	.string "Je suis toujours partant pour un combat.\p"
	.string "Tu veux une revanche avec moi ?$"

SaffronCity_FightingDojoVIP_Text_Blaine_RematchDefeat:
	.string "AUGUSTE : Tes compétences sont vraiment\n"
	.string "ardentes !\p"
	.string "Tu as brûlé toutes mes\n"
	.string "défenses.$"

SaffronCity_FightingDojoVIP_Text_Blue_Rematch:
	.string "BLEU : Eh bien, eh bien. CHAMPION\p"
	.string "! On dirait que tu es allé\p"
	.string "loin. J'avais ce titre aussi, tu sais.\n"
	.string "Mais je ne me retiendrai pas. Voyons\p"
	.string "si tu peux le garder. Tu\p"
	.string "veux une revanche avec moi ?$"

SaffronCity_FightingDojoVIP_Text_Blue_RematchDefeat:
	.string "BLUE : Quoi ?\p"
	.string "Comment ai-je pu perdre encore ?$"

