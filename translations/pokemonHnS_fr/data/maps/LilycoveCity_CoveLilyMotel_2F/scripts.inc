LilycoveCity_CoveLilyMotel_2F_MapScripts::
	.byte 0

LilycoveCity_CoveLilyMotel_2F_EventScript_GameDesigner::
	lock
	faceplayer
	call_if_unset FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex
	call_if_set FLAG_TEMP_2, LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
	specialvar VAR_RESULT, HasAllHoennMons
	goto_if_eq VAR_RESULT, TRUE, LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowMeCompletedDex::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex, MSGBOX_DEFAULT
	return

LilycoveCity_CoveLilyMotel_2F_EventScript_AllHoennMonsFanfare::
	setflag FLAG_TEMP_2
	playfanfare MUS_OBTAIN_ITEM
	waitfanfare
	goto LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_ShowDiploma::
	message LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	special Special_ShowDiploma
	waitstate
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Programmer::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GraphicArtist::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_FatMan::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Woman::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_GameBoyKid::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy, MSGBOX_NPC
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_Scott::
	lock
	faceplayer
	goto_if_set FLAG_MET_SCOTT_IN_LILYCOVE, LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles, MSGBOX_DEFAULT
	addvar VAR_SCOTT_STATE, 1
	setflag FLAG_MET_SCOTT_IN_LILYCOVE
	release
	end

LilycoveCity_CoveLilyMotel_2F_EventScript_MetScott::
	msgbox LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy, MSGBOX_DEFAULT
	release
	end

LilycoveCity_CoveLilyMotel_2F_Text_ShowMeCompletedDex:
	.string "Je suis le GAME DESIGNER.\p"
	.string "Oh, c'est vrai ?\n"
	.string "Tu travailles sur un POKéDEX ?\p"
	.string "C'est dur d'essayer de le compléter,\n"
	.string "mais n'abandonne pas.\p"
	.string "Si tu le complètes, viens\n"
	.string "me le montrer.$"

LilycoveCity_CoveLilyMotel_2F_Text_FilledPokedexGiveYouThis:
	.string "Waouh ! C'est génial ! Oui,\n"
	.string "c'est totalement génial ! Ce POKéDEX\p"
	.string "est complètement rempli ! Tu dois\n"
	.string "vraiment aimer les POKéMON !\p"
	.string "Je suis impressionné ! Laisse-moi\p"
	.string "te donner quelque chose en\n"
	.string "reconnaissance de ton exploit !$"

LilycoveCity_CoveLilyMotel_2F_Text_ImTheProgrammer:
	.string "Moi ? Tu me parles ?\n"
	.string "Je suis le PROGRAMMEUR.\p"
	.string "Je me demande à quoi ressemblent les\n"
	.string "MACHINES À SOUS ici.$"

LilycoveCity_CoveLilyMotel_2F_Text_ImTheGraphicArtist:
	.string "Je suis le GRAPHISTE ! Les POKéMON\n"
	.string "de HOENN ne sont-ils pas intéressants ?$"

LilycoveCity_CoveLilyMotel_2F_Text_GirlsAreCute:
	.string "Les filles NAGEUSES, elles sont mignonnes, hein ?\n"
	.string "Combattre une NAGEUSE mignonne…\p"
	.string "Ouah, c'est génial !\p"
	.string "Et les JUMELLES ! Elles ne sont pas mignonnes ?\n"
	.string "Un combat 2 contre 2 avec des JUMELLES…\p"
	.string "Ouah, c'est trop amusant !$"

LilycoveCity_CoveLilyMotel_2F_Text_SeaBreezeTicklesHeart:
	.string "La brise marine me chatouille le cœur.\n"
	.string "On se sent bien ici !$"

LilycoveCity_CoveLilyMotel_2F_Text_NeverLeaveWithoutGameBoy:
	.string "On ne sait jamais quand et\n"
	.string "où les gens te défieront. C'est\p"
	.string "pourquoi je ne quitte jamais la\n"
	.string "maison sans ma GAME BOY ADVANCE.$"

LilycoveCity_CoveLilyMotel_2F_Text_SnoozingPreferBattles:
	.string "Pour un dur à cuire comme moi,\n"
	.string "les POKéMON robustes sont les meilleurs.\p"
	.string "L'attaque est la meilleure défense !\n"
	.string "Une attaque implacable est l'ultime !\p"
	.string "Mais ce n'est pas de ça\n"
	.string "que je voulais parler.\p"
	.string "De temps en temps, une jolie demoiselle\n"
	.string "passe par ici.\p"
	.string "Elle dit qu'elle peut lire dans les pensées\n"
	.string "des POKéMON.\p"
	.string "Je ne sais pas pour ça,\p"
	.string "mais elle est vraiment mignonne.\n"
	.string "Hein ?\l"
	.string "Pourquoi tu me regardes comme ça ?$"

LilycoveCity_CoveLilyMotel_2F_Text_ContestsDoTakeStrategy:
	.string "SCOTT : Je pense qu'il faut de la stratégie\n"
	.string "pour gagner un CONCOURS.\p"
	.string "Élaborer des stratégies de CONCOURS est une façon\n"
	.string "de devenir un meilleur DRESSEUR, je dirais.$"

