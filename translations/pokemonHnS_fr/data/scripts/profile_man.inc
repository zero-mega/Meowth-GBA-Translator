ProfileMan_EventScript_Man::
	lock
	faceplayer
	goto_if_set FLAG_SYS_CHAT_USED, ProfileMan_EventScript_GivenProfileBefore
	msgbox ProfileMan_Text_CollectTrainerProfiles, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeProfile
	end

ProfileMan_EventScript_AskToSeeProfile::
	msgbox ProfileMan_Text_MayISeeYourProfile, MSGBOX_DEFAULT
	multichoice 17, 6, MULTI_YESNOINFO_2, FALSE
	switch VAR_RESULT
	case 0, ProfileMan_EventScript_CreateProfile
	case 1, ProfileMan_EventScript_DeclineShowProfile
	case 2, ProfileMan_EventScript_Info
	case MULTI_B_PRESSED, ProfileMan_EventScript_DeclineShowProfile
	end

ProfileMan_EventScript_Info::
	msgbox ProfileMan_Text_EasyChatExplanation, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeProfile
	end

ProfileMan_EventScript_CreateProfile::
	msgbox ProfileMan_Text_LetsSeeItThen, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, EASY_CHAT_TYPE_PROFILE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, ProfileMan_EventScript_CancelShowProfile
	goto_if_eq VAR_RESULT, 1, ProfileMan_EventScript_ShowProfile
	end

ProfileMan_EventScript_CancelShowProfile::
	msgbox ProfileMan_Text_NotIntoItRightNow, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_ShowProfile::
	setvar VAR_0x8004, 0
	special ShowEasyChatProfile
	waitmessage
	delay 80
	msgbox ProfileMan_Text_FantasticProfile, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_DeclineShowProfile::
	msgbox ProfileMan_Text_ImagineYouWouldHaveWonderfulProfile, MSGBOX_DEFAULT
	release
	end

ProfileMan_EventScript_GivenProfileBefore::
	msgbox ProfileMan_Text_YouHaveWonderfulSmile, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeNewProfile
	end

ProfileMan_EventScript_AskToSeeNewProfile::
	msgbox ProfileMan_Text_MayISeeYourNewProfile, MSGBOX_DEFAULT
	multichoice 17, 6, MULTI_YESNOINFO_2, FALSE
	switch VAR_RESULT
	case 0, ProfileMan_EventScript_CreateNewProfile
	case 1, ProfileMan_EventScript_DeclineNewProfile
	case 2, ProfileMan_EventScript_InfoNewProfile
	case MULTI_B_PRESSED, ProfileMan_EventScript_DeclineNewProfile
	end

ProfileMan_EventScript_InfoNewProfile::
	msgbox ProfileMan_Text_EasyChatExplanation, MSGBOX_DEFAULT
	goto ProfileMan_EventScript_AskToSeeNewProfile
	end

ProfileMan_EventScript_CreateNewProfile::
	msgbox ProfileMan_Text_EvenBetterThanLastProfile, MSGBOX_DEFAULT
	closemessage
	setvar VAR_0x8004, EASY_CHAT_TYPE_PROFILE
	call Common_ShowEasyChatScreen
	lock
	faceplayer
	goto_if_eq VAR_RESULT, 0, ProfileMan_EventScript_CancelShowProfile
	goto_if_eq VAR_RESULT, 1, ProfileMan_EventScript_ShowProfile
	end

ProfileMan_EventScript_DeclineNewProfile::
	msgbox ProfileMan_Text_LikeProfileWayItIs, MSGBOX_DEFAULT
	release
	end

@ Unused
ProfileMan_EventScript_Ret::
	return

ProfileMan_Text_CollectTrainerProfiles:
	.string "Bonjour, DRESSEUR !\n"
	.string "Tu as un superbe sourire.\p"
	.string "J'ai un hobby : collectionner\n"
	.string "les profils des DRESSEURS POKéMON.$"

ProfileMan_Text_MayISeeYourProfile:
	.string "Alors, qu'en dis-tu ?\n"
	.string "Puis-je voir ton profil ?$"

ProfileMan_Text_EasyChatExplanation:
	.string "Tu crées ton propre profil en assemblant\n"
	.string "quatre mots ou expressions.\p"
	.string "Ici, je vais te montrer un exemple de\n"
	.string "profil utilisant quatre morceaux de texte.\p"
	.string "Tu peux remplacer ces quatre morceaux par\n"
	.string "d'autres morceaux de texte comme tu\l"
	.string "veux pour créer ton propre profil.\p"
	.string "Il y a beaucoup de morceaux de texte\n"
	.string "que tu peux utiliser.\p"
	.string "Ils sont organisés en groupes comme\n"
	.string "POKéMON, modes de vie et loisirs pour\l"
	.string "faciliter la recherche.\p"
	.string "Alors, d'abord, choisis le groupe de morceaux\n"
	.string "de texte pour afficher une liste de choix.\p"
	.string "Ensuite, choisis l'option que tu veux.\p"
	.string "Répète pour les choix de texte restants,\n"
	.string "et tu auras ton propre profil.$"

ProfileMan_Text_LetsSeeItThen:
	.string "Oui ! Merci !\n"
	.string "Alors, montre-le-moi.$"

ProfileMan_Text_ImagineYouWouldHaveWonderfulProfile:
	.string "Oh, vraiment ?\p"
	.string "J'imagine que quelqu'un comme toi aurait\n"
	.string "un profil magnifique…$"

ProfileMan_Text_NotIntoItRightNow:
	.string "Oh ? Ce n'est pas le moment ?\p"
	.string "Bon, n'importe quand me convient !$"

ProfileMan_Text_YouHaveWonderfulSmile:
	.string "Bonjour, DRESSEUR !\n"
	.string "Tu as un merveilleux sourire.$"

ProfileMan_Text_MayISeeYourNewProfile:
	.string "Puis-je voir ton nouveau profil ?$"

ProfileMan_Text_EvenBetterThanLastProfile:
	.string "Oui ! Merci !\p"
	.string "J'espère que ce sera encore mieux que le profil\n"
	.string "que tu m'as montré avant.$"

ProfileMan_Text_LikeProfileWayItIs:
	.string "Oh, tu aimes ton profil tel qu'il est.\p"
	.string "Je ne t'en blâme pas... c'est un\n"
	.string "superbe profil tel qu'il est.$"

ProfileMan_Text_FantasticProfile:
	.string "F-fantastique !\p"
	.string "Ton profil, il est merveilleux !\n"
	.string "Il dit vraiment qui tu es.\p"
	.string "Pourquoi, quiconque entend ce profil\n"
	.string "serait captivé par toi !\p"
	.string "Merci !$"

@ Unused
ProfileMan_Text_YouKnowSecretSaying:
	.string "Oh ?\n"
	.string "Tu connais la phrase secrète !\p"
	.string "Ça veut dire que tu es maintenant membre\n"
	.string "du CLUB ÉVÉNEMENT MYSTÈRE !$"
