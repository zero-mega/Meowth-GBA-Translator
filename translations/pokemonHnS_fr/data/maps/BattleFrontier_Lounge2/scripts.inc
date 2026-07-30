BattleFrontier_Lounge2_MapScripts::
	.byte 0

@ This NPC gives hints about a random facility or battle mode.
@ For battle modes he gives generic advice
@ For facilities, depending on how far the player has progressed he will say either
@    The name of the Frontier Brain there
@    The type and description of the 3 pokemon they use in their silver battle
@    The type and description of the 3 pokemon they use in their gold battle
BattleFrontier_Lounge2_EventScript_FrontierManiac::
	lock
	faceplayer
	goto_if_set FLAG_MET_BATTLE_FRONTIER_MANIAC, BattleFrontier_Lounge2_EventScript_AlreadyMetManiac
	setflag FLAG_MET_BATTLE_FRONTIER_MANIAC
	msgbox BattleFrontier_Lounge2_Text_FrontierManiacIntro, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice
	end

BattleFrontier_Lounge2_EventScript_AlreadyMetManiac::
	msgbox BattleFrontier_Lounge2_Text_SwingByForTheLatestWord, MSGBOX_DEFAULT
	goto BattleFrontier_Lounge2_EventScript_GiveAdvice
	end

BattleFrontier_Lounge2_EventScript_GiveAdvice::
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_SINGLES, BattleFrontier_Lounge2_EventScript_BufferSingle
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_DOUBLES, BattleFrontier_Lounge2_EventScript_BufferDouble
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_MULTIS, BattleFrontier_Lounge2_EventScript_BufferMulti
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_LINK, BattleFrontier_Lounge2_EventScript_BufferMultiLink
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_DOME, BattleFrontier_Lounge2_EventScript_BufferBattleDome
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_FACTORY, BattleFrontier_Lounge2_EventScript_BufferBattleFactory
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PALACE, BattleFrontier_Lounge2_EventScript_BufferBattlePalace
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_ARENA, BattleFrontier_Lounge2_EventScript_BufferBattleArena
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PIKE, BattleFrontier_Lounge2_EventScript_BufferBattlePike
	call_if_eq VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_PYRAMID, BattleFrontier_Lounge2_EventScript_BufferBattlePyramid
@ <= FRONTIER_MANIAC_TOWER_LINK is any Battle Tower mode
	call_if_le VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_TOWER_LINK, BattleFrontier_Lounge2_EventScript_BattleTowerNews
@ >= FRONTIER_MANIAC_DOME is any facility other than Battle Tower
	call_if_ge VAR_FRONTIER_MANIAC_FACILITY, FRONTIER_MANIAC_DOME, BattleFrontier_Lounge2_EventScript_FacilityNews
	special ShowFrontierManiacMessage
	waitmessage
	waitbuttonpress
	release
	end

BattleFrontier_Lounge2_EventScript_BattleTowerNews::
	msgbox BattleFrontier_Lounge2_Text_BattleTowerIsHottest, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_FacilityNews::
	msgbox BattleFrontier_Lounge2_Text_FacilityIsHottest, MSGBOX_DEFAULT
	return

BattleFrontier_Lounge2_EventScript_BufferSingle::
	bufferstdstring STR_VAR_1, STDSTRING_SINGLE
	return

BattleFrontier_Lounge2_EventScript_BufferDouble::
	bufferstdstring STR_VAR_1, STDSTRING_DOUBLE
	return

BattleFrontier_Lounge2_EventScript_BufferMulti::
	bufferstdstring STR_VAR_1, STDSTRING_MULTI
	return

BattleFrontier_Lounge2_EventScript_BufferMultiLink::
	bufferstdstring STR_VAR_1, STDSTRING_MULTI_LINK
	return

BattleFrontier_Lounge2_EventScript_BufferBattleDome::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_DOME
	return

BattleFrontier_Lounge2_EventScript_BufferBattleFactory::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_FACTORY
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePalace::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PALACE
	return

BattleFrontier_Lounge2_EventScript_BufferBattleArena::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_ARENA
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePike::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PIKE
	return

BattleFrontier_Lounge2_EventScript_BufferBattlePyramid::
	bufferstdstring STR_VAR_1, STDSTRING_BATTLE_PYRAMID
	return

BattleFrontier_Lounge2_EventScript_Maniac1::
	lock
	msgbox BattleFrontier_Lounge2_Text_NewsGatheringPower, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_Maniac2::
	lock
	msgbox BattleFrontier_Lounge2_Text_AmazingPowersOfObservation, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_Maniac3::
	lock
	msgbox BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion, MSGBOX_DEFAULT
	release
	end

BattleFrontier_Lounge2_EventScript_TriathleteF::
	msgbox BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe, MSGBOX_NPC
	end

BattleFrontier_Lounge2_Text_FrontierManiacIntro::
	.string "Salut ! Pour les infos sur le\n"
	.string "PARC DES COMBATS, je suis le no 1.\p"
	.string "Tu peux me considérer comme\n"
	.string "le MANIAQUE DU PARC.\p"
	.string "Juste pour vérifier, tu es\n"
	.string "DRESSEUR, c'est bien ça ?\p"
	.string "Je partagerai volontiers les\n"
	.string "dernières infos sur le PARC DES COMBATS.$"

BattleFrontier_Lounge2_Text_SwingByForTheLatestWord::
	.string "Salut ! Tu es venu me questionner\n"
	.string "sur les dernières rumeurs ? Bon, d'accord !$"

@ Unused
BattleFrontier_Lounge2_Text_MyInformationsBeenUsefulRight::
	.string "Alors ? Alors ? Alors ?\p"
	.string "Je suis sûr que mes informations t'ont\n"
	.string "été très utiles, non ?$"

BattleFrontier_Lounge2_Text_FacilityIsHottest::
	.string "Voyons voir…\p"
	.string "On dirait que {STR_VAR_1}\n"
	.string "est l'endroit le plus en vogue.$"

BattleFrontier_Lounge2_Text_BattleTowerIsHottest::
	.string "Voyons voir…\p"
	.string "On dirait que la TOUR DE COMBAT\n"
	.string "{STR_VAR_1} est la plus en vogue.$"

BattleFrontier_Lounge2_Text_SalonMaidenIsThere::
	.string "Tu ne le savais sûrement pas !\p"
	.string "Un de ces grands DRESSEURS que SCOTT\n"
	.string "appelle les AS DE LA ZONE DE COMBAT est là.\p"
	.string "C'est cette mystérieuse DRESSEUSE appelée\n"
	.string "la DEMOISELLE DU SALON qui dirige l'endroit.$"

BattleFrontier_Lounge2_Text_SalonMaidenSilverMons::
	.string "Tu as combattu la DEMOISELLE DU\p"
	.string "SALON ? Quand elle évalue\n"
	.string "son adversaire, elle utilise ces\p"
	.string "POKéMON : Un POKéMON PSI\n"
	.string "PSY, un POKéMON VOLCAN FEU,\l"
	.string "et un POKéMON DORMEUR NORMAL.$"

BattleFrontier_Lounge2_Text_SalonMaidenGoldMons::
	.string "Tu as combattu la DEMOISELLE DU\n"
	.string "SALON quand elle est sérieuse ?\p"
	.string "Quand elle se bat à fond,\n"
	.string "elle utiliserait ces POKéMON :\p"
	.string "Un POKéMON EON DRAGON &\n"
	.string "PSY, un POKéMON TONNERRE ÉLECTRIQUE,\l"
	.string "et un POKéMON DORMEUR NORMAL.$"

BattleFrontier_Lounge2_Text_DomeAceIsThere::
	.string "Tu ne le savais sûrement pas !\p"
	.string "Un de ces grands DRESSEURS que SCOTT\n"
	.string "appelle les AS DE LA ZONE DE COMBAT est là.\p"
	.string "C'est ce DRESSEUR flamboyant appelé\n"
	.string "l'AS DU DÔME qui dirige l'endroit.$"

BattleFrontier_Lounge2_Text_DomeAceSilverMons::
	.string "Tu as combattu le TACTICIEN DU DÔME\p"
	.string "? Quand il prend l'adversaire à la\n"
	.string "légère, il utilise ces trois POKéMON :\p"
	.string "Un POKéMON DRAGON DRAGON & VOL, un\n"
	.string "POKéMON POISSON BOUE EAU & SOL, et\l"
	.string "un POKéMON FLAMME FEU & VOL.$"

BattleFrontier_Lounge2_Text_DomeAceGoldMons::
	.string "Tu as combattu le TACTICIEN DU\n"
	.string "DÔME quand il est sérieux ?\p"
	.string "Quand il démontre sa stratégie, il\n"
	.string "utilise ces trois POKéMON : Un\p"
	.string "POKéMON EON DRAGON & VOL, un\n"
	.string "POKéMON POISSON BOUE EAU &\l"
	.string "SOL, et un POKéMON JAMBE\l"
	.string "DE FER ACIER & PSYCHIQUE.$"

BattleFrontier_Lounge2_Text_FactoryHeadIsThere::
	.string "Tu ne le savais sûrement pas !\p"
	.string "Un de ces grands DRESSEURS que SCOTT\n"
	.string "appelle les AS DE LA ZONE DE COMBAT est là.\p"
	.string "C'est ce DRESSEUR étrange appelé\n"
	.string "le CHEF D'USINE qui dirige l'endroit.$"

BattleFrontier_Lounge2_Text_FactoryHeadSilverMons::
	.string "As-tu déjà combattu le CHEF\n"
	.string "D'USINE ?\p"
	.string "Laisse-moi réfléchir… Quand il va au combat,\n"
	.string "il n'a que trois POKéMON de location.\p"
	.string "Il combat dans des conditions\n"
	.string "quasi identiques aux tiennes.$"

BattleFrontier_Lounge2_Text_FactoryHeadGoldMons::
	.string "As-tu combattu le CHEF D'USINE\n"
	.string "quand il est sérieux ?\p"
	.string "Quand il se bat sérieusement,\n"
	.string "il a quand même trois POKéMON de location.\p"
	.string "Il combat dans des conditions\n"
	.string "quasi identiques aux tiennes.$"

BattleFrontier_Lounge2_Text_PikeQueenIsThere::
	.string "Tu ne le savais sûrement pas !\p"
	.string "Un de ces grands DRESSEURS que SCOTT\n"
	.string "appelle les AS DE LA ZONE DE COMBAT est là.\p"
	.string "C'est cette effrayante DRESSEUSE appelée\n"
	.string "la REINE DU SERPENT qui dirige l'endroit.$"

BattleFrontier_Lounge2_Text_PikeQueenSilverMons::
	.string "Tu as combattu la REINE DU\n"
	.string "BARRAGE avant ? Quand elle est\p"
	.string "de bonne humeur, on dit qu'elle\n"
	.string "utilise ces trois POKéMON : Un\p"
	.string "POKéMON SERPENT CROC VENIN, un\n"
	.string "POKéMON MOISISSURE INSECTE & ROCHE,\l"
	.string "et un POKéMON TENDRE EAU.$"

BattleFrontier_Lounge2_Text_PikeQueenGoldMons::
	.string "Tu as combattu la REINE DU\n"
	.string "BARRAGE quand elle est sérieuse ?\p"
	.string "Quand elle est vraiment énervée,\n"
	.string "on dit qu'elle utilise ces trois\p"
	.string "POKéMON :\n"
	.string "Un POKéMON SERPENT CROC VENIN,\l"
	.string "un POKéMON SERPENT FER & SOL,\l"
	.string "et un POKéMON ATROCE EAU & VOL.$"

BattleFrontier_Lounge2_Text_ArenaTycoonIsThere::
	.string "Tu ne le savais sûrement pas !\p"
	.string "Un de ces grands DRESSEURS que SCOTT\n"
	.string "appelle les AS DE LA ZONE DE COMBAT est là.\p"
	.string "C'est ce mignon DRESSEUR appelé\n"
	.string "le MAÎTRE DE L'ARÈNE qui dirige l'endroit.$"

BattleFrontier_Lounge2_Text_ArenaTycoonSilverMons::
	.string "Tu as combattu la TYCOON DE\n"
	.string "L'ARÈNE avant ? Quand elle évalue\p"
	.string "la capacité de l'adversaire, elle utiliserait\n"
	.string "ces POKéMON : Un POKéMON CORNE\p"
	.string "UNIQUE INSECTE & COMBAT, un POKéMON\n"
	.string "CLAIR DE LUNE TÉNÈBRES, et un\l"
	.string "POKéMON MUE INSECTE & SPECTRE.$"

BattleFrontier_Lounge2_Text_ArenaTycoonGoldMons::
	.string "Tu as combattu la TYCOON DE\n"
	.string "L'ARÈNE quand elle est sérieuse ?\p"
	.string "Quand elle se bat pour de\n"
	.string "vrai, elle utiliserait ces POKéMON\p"
	.string ": Un POKéMON CLAIR DE\n"
	.string "LUNE TÉNÈBRES, un POKéMON OMBRE\l"
	.string "SPECTRE & POISON et un\l"
	.string "POKéMON CHAMPIGNON PLANTE & COMBAT.$"

BattleFrontier_Lounge2_Text_PalaceMavenIsThere::
	.string "Tu ne le savais sûrement pas !\p"
	.string "Un de ces grands DRESSEURS que SCOTT\n"
	.string "appelle les AS DE LA ZONE DE COMBAT est là.\p"
	.string "C'est ce sinistre DRESSEUR appelé\n"
	.string "le MAÎTRE DU PALAIS qui dirige l'endroit.$"

BattleFrontier_Lounge2_Text_PalaceMavenSilverMons::
	.string "Tu as combattu le MAÎTRE DU\n"
	.string "PALAIS avant ? Quand il teste\p"
	.string "l'esprit de l'adversaire, il utiliserait\n"
	.string "ces POKéMON : Un POKéMON\p"
	.string "CHAUVE-SOURIS POISON & VOL, un\n"
	.string "POKéMON PARESSEUX NORMAL, et un\l"
	.string "POKéMON TRANSPORT EAU & GLACE.$"

BattleFrontier_Lounge2_Text_PalaceMavenGoldMons::
	.string "Tu as combattu le MAÎTRE DU\n"
	.string "PALAIS quand il est sérieux ?\p"
	.string "Quand il met toute sa puissance\n"
	.string "dans le combat, il utiliserait ces\p"
	.string "POKéMON : Un POKéMON LÉGENDAIRE\n"
	.string "FEU, un POKéMON PARESSEUX NORMAL,\l"
	.string "et un POKéMON AURORE EAU.$"

BattleFrontier_Lounge2_Text_PyramidKingIsThere::
	.string "Tu ne le savais sûrement pas !\p"
	.string "Un de ces grands DRESSEURS que SCOTT\n"
	.string "appelle les AS DE LA ZONE DE COMBAT est là.\p"
	.string "C'est ce DRESSEUR brûlant appelé\n"
	.string "le ROI DE LA PYRAMIDE qui dirige l'endroit.$"

BattleFrontier_Lounge2_Text_PyramidKingSilverMons::
	.string "Tu as combattu le ROI DE\n"
	.string "LA PYRAMIDE avant ? Quand\p"
	.string "il évalue la puissance de\n"
	.string "l'adversaire, il utilise ces POKéMON\p"
	.string ": Un POKéMON PIC ROCHE\n"
	.string "ROCHE, un POKéMON ICEBERG GLACE,\l"
	.string "et un POKéMON FER ACIER.$"

BattleFrontier_Lounge2_Text_PyramidKingGoldMons::
	.string "Tu as combattu le ROI DE LA\n"
	.string "PYRAMIDE quand il est sérieux ?\p"
	.string "Quand il est plein d'énergie,\n"
	.string "il utilise apparemment ces\p"
	.string "POKéMON :\n"
	.string "Un POKéMON GEL OISEAU & GLACE,\l"
	.string "un POKéMON ÉLECTRIQUE OISEAU &\l"
	.string "ÉLECTRIQUE, et un POKéMON FLAMME OISEAU & FEU.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice1::
	.string "Bien sûr, il y a plusieurs endroits\n"
	.string "où tu peux entrer en COMBATS DUO.\p"
	.string "Mais les SALLES DE COMBAT DUO de\n"
	.string "la TOUR DE COMBAT sont, en gros,\p"
	.string "les bases ! C'est là que tu\n"
	.string "devrais apprendre comment se déroulent les COMBATS\l"
	.string "DUO ici au PARC DES COMBATS.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice2::
	.string "Fais attention aux combats ici.\p"
	.string "On dit qu'il y a des DRESSEURS qui ont\n"
	.string "développé des stratégies spéciales pour\l"
	.string "les COMBATS DOUBLES.$"

BattleFrontier_Lounge2_Text_DoubleBattleAdvice3::
	.string "Une fois que tu es à l'aise avec les\n"
	.string "COMBATS EN DOUBLE ici, tu devrais\l"
	.string "penser à défier d'autres endroits\l"
	.string "oférant des COMBATS EN DOUBLE.$"

BattleFrontier_Lounge2_Text_MultiBattleAdvice::
	.string "Toutes sortes de DRESSEURS se rassemblent\n"
	.string "dans le SALON DE COMBAT.\p"
	.string "Imagine : tu pourrais croiser tes\n"
	.string "amis ou tes fans !\l"
	.string "Regarde bien autour de toi !$"

BattleFrontier_Lounge2_Text_LinkMultiBattleAdvice::
	.string "Si tu es avec un ami, direction la\n"
	.string "SALLE COMBAT MULTI EN LINK.\p"
	.string "Si tu joues avec un ami fort,\n"
	.string "tu peux t'attendre à des adversaires coriaces !$"

BattleFrontier_Lounge2_Text_NewsGatheringPower::
	.string "Quel pouvoir de collecte d'infos incroyable !\n"
	.string "Mon mentor n'a pas son pareil !$"

BattleFrontier_Lounge2_Text_AmazingPowersOfObservation::
	.string "Quels pouvoirs d'observation incroyables !\n"
	.string "Mon mentor n'a pas son pareil !$"

BattleFrontier_Lounge2_Text_AmazingPowerOfPersuasion::
	.string "Quel pouvoir de persuasion incroyable !\n"
	.string "Mon mentor n'a pas son pareil !$"

BattleFrontier_Lounge2_Text_ThisPlaceIsScaringMe::
	.string "…Quel est cet endroit ?\n"
	.string "Ça me fait peur…$"

