RustboroCity_PokemonSchool_MapScripts::
	.byte 0

RustboroCity_PokemonSchool_EventScript_Blackboard::
	lockall
	msgbox RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic::
	message RustboroCity_PokemonSchool_Text_ReadWhichTopic
	waitmessage
	multichoicegrid 8, 1, MULTI_STATUS_INFO, 3, FALSE
	switch VAR_RESULT
	case 0, RustboroCity_PokemonSchool_EventScript_Poison
	case 1, RustboroCity_PokemonSchool_EventScript_Paralysis
	case 2, RustboroCity_PokemonSchool_EventScript_Sleep
	case 3, RustboroCity_PokemonSchool_EventScript_Burn
	case 4, RustboroCity_PokemonSchool_EventScript_Freeze
	case 5, RustboroCity_PokemonSchool_EventScript_ExitTopicSelect
	case MULTI_B_PRESSED, RustboroCity_PokemonSchool_EventScript_ExitTopicSelect
	end

RustboroCity_PokemonSchool_EventScript_Poison::
	msgbox RustboroCity_PokemonSchool_Text_ExplainPoison, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Paralysis::
	msgbox RustboroCity_PokemonSchool_Text_ExplainParalysis, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Sleep::
	msgbox RustboroCity_PokemonSchool_Text_ExplainSleep, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Burn::
	msgbox RustboroCity_PokemonSchool_Text_ExplainBurn, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_Freeze::
	msgbox RustboroCity_PokemonSchool_Text_ExplainFreeze, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_ChooseBlackboardTopic
	end

RustboroCity_PokemonSchool_EventScript_ExitTopicSelect::
	releaseall
	end

RustboroCity_PokemonSchool_EventScript_GameboyKid1::
	msgbox RustboroCity_PokemonSchool_Text_TradingRightNow, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_GameboyKid2::
	msgbox RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_RichBoy::
	msgbox RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_Lass::
	msgbox RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_SchoolKidM::
	msgbox RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry, MSGBOX_NPC
	end

RustboroCity_PokemonSchool_EventScript_StudentNotebook::
	msgbox RustboroCity_PokemonSchool_Text_StudentsNotes, MSGBOX_SIGN
	end

RustboroCity_PokemonSchool_EventScript_Teacher::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_QUICK_CLAW, RustboroCity_PokemonSchool_EventScript_GaveQuickClaw
	call_if_eq VAR_FACING, DIR_EAST, RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast
	call_if_eq VAR_FACING, DIR_WEST, RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest
	msgbox RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw, MSGBOX_DEFAULT
	giveitem ITEM_QUICK_CLAW
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	setflag FLAG_RECEIVED_QUICK_CLAW
	release
	end

RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsEast::
	applymovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast
	waitmovement 0
	return

RustboroCity_PokemonSchool_EventScript_TeacherCheckOnStudentsWest::
	applymovement VAR_LAST_TALKED, RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest
	waitmovement 0
	return

RustboroCity_PokemonSchool_EventScript_GaveQuickClaw::
	msgbox RustboroCity_PokemonSchool_Text_ExplainQuickClaw, MSGBOX_DEFAULT
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	release
	end

RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsWest:
	walk_left
	walk_down
	walk_down
	walk_right
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_left
	walk_left
	walk_up
	walk_up
	walk_right
	step_end

RustboroCity_PokemonSchool_Movement_TeacherCheckOnStudentsEast:
	walk_right
	walk_right
	walk_down
	walk_down
	walk_left
	walk_left
	walk_in_place_faster_down
	delay_16
	delay_16
	delay_16
	walk_down
	walk_in_place_faster_left
	delay_16
	delay_16
	walk_right
	delay_16
	delay_16
	delay_8
	walk_up
	walk_right
	walk_up
	walk_up
	walk_left
	walk_left
	step_end

RustboroCity_PokemonSchool_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE, RustboroCity_PokemonSchool_EventScript_ScottWatchStudents
	goto_if_set FLAG_MET_SCOTT_RUSTBORO, RustboroCity_PokemonSchool_EventScript_ScottSpokeAlready
	goto_if_set FLAG_BADGE01_GET, RustboroCity_PokemonSchool_EventScript_ScottGreetHasBadge
	msgbox RustboroCity_PokemonSchool_Text_ScottMetAlreadyCut, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_RUSTBORO
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottSpokeAlready::
	goto_if_set FLAG_BADGE01_GET, RustboroCity_PokemonSchool_EventScript_ScottNoticeBadge
	msgbox RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottGreetHasBadge::
	msgbox RustboroCity_PokemonSchool_Text_ScottMetAlreadyStoneBadge, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge
	end

RustboroCity_PokemonSchool_EventScript_ScottNoticeBadge::
	msgbox RustboroCity_PokemonSchool_Text_ScottStoneBadge, MSGBOX_DEFAULT
	goto RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge
	end

RustboroCity_PokemonSchool_EventScript_MetScottAfterBadge::
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_AFTER_OBTAINING_STONE_BADGE
	release
	end

RustboroCity_PokemonSchool_EventScript_ScottWatchStudents::
	msgbox RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown, MSGBOX_DEFAULT
	release
	end

RustboroCity_PokemonSchool_Text_BlackboardListsStatusChanges:
	.string "Le tableau liste les changements de statut\n"
	.string "qui peuvent affecter les POKéMON en combat.$"

RustboroCity_PokemonSchool_Text_ReadWhichTopic:
	.string "Quel sujet veux-tu lire ?$"

RustboroCity_PokemonSchool_Text_ExplainPoison:
	.string "Si un POKéMON est empoisonné,\n"
	.string "il perdra progressivement des PV.\p"
	.string "Les effets du poison\n"
	.string "persistent après un combat.\p"
	.string "Les PV d'un POKéMON\n"
	.string "empoisonné baissent en voyageant.\p"
	.string "Soigne-le avec un ANTIDOTE.$"

RustboroCity_PokemonSchool_Text_ExplainParalysis:
	.string "Si un POKéMON est paralysé,\n"
	.string "sa VITESSE diminue.\p"
	.string "Il peut aussi ne pas pouvoir bouger pendant\n"
	.string "le combat.\p"
	.string "La paralysie persiste après le combat.\n"
	.string "Soigne-la avec un ANTI-PARA.$"

RustboroCity_PokemonSchool_Text_ExplainSleep:
	.string "Si un POKéMON s'endort, il ne\n"
	.string "pourra pas attaquer. Un POKéMON peut\p"
	.string "se réveiller tout seul, mais\n"
	.string "si un combat se termine\l"
	.string "pendant qu'il dort, il restera\p"
	.string "endormi. Réveille-le avec un RÉVEIL.$"

RustboroCity_PokemonSchool_Text_ExplainBurn:
	.string "Une brûlure réduit la puissance d'ATTAQUE et\n"
	.string "diminue progressivement les PV de la victime.\p"
	.string "Une brûlure persiste après le combat.\n"
	.string "Soigne une brûlure avec un ANTI-BRÛLE.$"

RustboroCity_PokemonSchool_Text_ExplainFreeze:
	.string "Un POKéMON gelé devient totalement\n"
	.string "hors d'état de nuire.\p"
	.string "Il reste gelé après le combat.\n"
	.string "Soigne-le avec un ANTIGEL.$"

RustboroCity_PokemonSchool_Text_StudentsWhoDontStudyGetQuickClaw:
	.string "Les élèves qui n'étudient pas goûtent\n"
	.string "un peu de ma VIVE GRIFFE.\p"
	.string "Que tu sois un bon élève ou non\n"
	.string "se verra dans la façon dont tu utilises\l"
	.string "cet objet.$"

RustboroCity_PokemonSchool_Text_ExplainQuickClaw:
	.string "Un POKéMON tenant la VIVE GRIFFE\n"
	.string "accélère parfois et attaque avant son\l"
	.string "adversaire. Il y a beaucoup\p"
	.string "d'autres objets faits pour être\n"
	.string "tenus par des POKéMON. Rien\p"
	.string "que ça te donnera de\n"
	.string "nombreux sujets à étudier !$"

RustboroCity_PokemonSchool_Text_TradingRightNow:
	.string "J'échange des POKéMON avec mon ami\n"
	.string "en ce moment.$"

RustboroCity_PokemonSchool_Text_AlwaysWantedSeedot:
	.string "J'ai toujours voulu un GRAINIPIOT,\n"
	.string "et j'en ai enfin un !$"

RustboroCity_PokemonSchool_Text_PokemontCantUseManMadeItems:
	.string "Les POKéMON peuvent tenir des objets,\n"
	.string "mais ils ne savent pas quoi faire des objets\l"
	.string "fabriqués par l'homme comme les POTIONS et ANTIDOTES.$"

RustboroCity_PokemonSchool_Text_ConfusedPokemonAttacksItself:
	.string "Tu sais que certaines attaques POKéMON\n"
	.string "peuvent rendre un POKéMON confus ?\p"
	.string "Un POKéMON confus peut parfois\n"
	.string "s'attaquer lui-même sans le vouloir.\p"
	.string "Mais une fois le combat terminé, il\n"
	.string "redeviendra normal.$"

RustboroCity_PokemonSchool_Text_PokemonHealItselfWithBerry:
	.string "Un POKéMON tenant une BAIE se soigne\n"
	.string "lui-même…\p"
	.string "Il existe beaucoup de types d'objets\n"
	.string "que les POKéMON peuvent tenir…\p"
	.string "C'est vraiment dur de prendre\n"
	.string "des notes…$"

RustboroCity_PokemonSchool_Text_StudentsNotes:
	.string "C'est le cahier\p"
	.string "de cet élève…\n"
	.string "Les POKéMON se\p"
	.string "attrapent avec des\n"
	.string "POKé BALLS.\p"
	.string "Jusqu'à\n"
	.string "six POKéMON\l"
	.string "peuvent\p"
	.string "accompagner\n"
	.string "un DRESSEUR.\l"
	.string "C'est les bases !$"

RustboroCity_PokemonSchool_Text_ScottMetAlreadyCut:
	.string "Allô ? On ne s'est pas déjà rencontrés ?\n"
	.string "Je crois à BOURG-EN-HERBE.\p"
	.string "Laisse-moi me présenter.\n"
	.string "Je m'appelle SCOTT.\p"
	.string "Je voyage partout à la recherche\n"
	.string "de DRESSEURS exceptionnels.\p"
	.string "Plus précisément, je cherche\n"
	.string "des experts en combat POKéMON.\p"
	.string "Alors, qu'est-ce qui t'amène à cette ÉCOLE ?\n"
	.string "Tu es DRESSEUR aussi ?\p"
	.string "La première chose à faire est de faire\n"
	.string "apprendre la capacité COUPE à un POKéMON.\p"
	.string "Si je me souviens bien, quelqu'un dans\n"
	.string "cette ville a COUPE.$"

RustboroCity_PokemonSchool_Text_StudentTalentLevelUnknown:
	.string "SCOTT : Hmm…\p"
	.string "Le niveau de talent des élèves ici\n"
	.string "est inconnu. Le potentiel est là.$"

RustboroCity_PokemonSchool_Text_ScottStoneBadge:
	.string "SCOTT : Oh, qu'est-ce que c'est ?\p"
	.string "C'est un BADGE ROCHE, n'est-ce pas ?\n"
	.string "C'est assez impressionnant, je dirais. Mais,\p"
	.string "tu sais, j'aurais adoré te voir\n"
	.string "en combat. C'est difficile de savoir\p"
	.string "quel genre de DRESSEUR tu es\n"
	.string "juste avec un BADGE de LIGUE.$"

RustboroCity_PokemonSchool_Text_ScottMetAlreadyStoneBadge:
	.string "Allô ? On ne s'est pas déjà rencontrés ?\n"
	.string "Je crois à BOURG-EN-HERBE.\p"
	.string "Laisse-moi me présenter.\n"
	.string "Je m'appelle SCOTT.\p"
	.string "Je voyage partout à la recherche\n"
	.string "de DRESSEURS exceptionnels.\p"
	.string "Plus précisément, je cherche\n"
	.string "des experts en combat POKéMON.\p"
	.string "Oh, qu'est-ce que c'est ?\n"
	.string "C'est un BADGE ROCHE, n'est-ce pas ?\p"
	.string "C'est assez impressionnant, je dirais, pour\n"
	.string "un DRESSEUR débutant comme toi.\p"
	.string "Mais tu sais, j'aurais adoré te voir\n"
	.string "en combat.\p"
	.string "C'est difficile de savoir quel genre de\n"
	.string "DRESSEUR tu es juste avec un BADGE de LIGUE.$"

