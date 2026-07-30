MysteryGiftScript_VisitingTrainer::
	setvaddress MysteryGiftScript_VisitingTrainer
	special ValidateEReaderTrainer
	vgoto_if_eq VAR_RESULT, 0, MysteryGiftScript_VisitingTrainerArrived
	lock
	faceplayer
	vmessage sText_MysteryGiftVisitingTrainerInstructions
	waitmessage
	waitbuttonpress
	release
	end

MysteryGiftScript_VisitingTrainerArrived:
	lock
	faceplayer
	vmessage sText_MysteryGiftVisitingTrainerArrived
	waitmessage
	waitbuttonpress
	release
	end

sText_MysteryGiftVisitingTrainerInstructions:
	.string "Merci d'utiliser le Système\n"
	.string "CADEAU MYSTÈRE.\p"
	.string "En tenant cette CARTE MERVEILLE, tu peux\n"
	.string "participer à une enquête dans une\l"
	.string "POKéMON-MART.\p"
	.string "Utilise ces enquêtes pour inviter\n"
	.string "des DRESSEURS à ATALANOPOLIS.\p"
	.string "…Laisse-moi te donner un mot de passe\n"
	.string "secret pour une enquête :\p"
	.string "“DONNE-MOI\n"
	.string "UN SUPER DRESSEUR”\p"
	.string "Écris ça dans une enquête et envoie-le\n"
	.string "au SYSTÈME DE\l"
	.string "COMMUNICATION SANS FIL.$"

sText_MysteryGiftVisitingTrainerArrived:
	.string "Merci d'utiliser\n"
	.string "le Système\p"
	.string "CADEAU MYSTÈRE.\n"
	.string "Un DRESSEUR\p"
	.string "est arrivé à\n"
	.string "ATALANOPOLIS\p"
	.string "cherchant\n"
	.string "un adversaire.\p"
	.string "Va le\n"
	.string "rencontrer !$"
