CianwoodHouse1_MapScripts::
	.byte 0

CianwoodHouse1_EventScript_Hermit::
	lock
	faceplayer
	msgbox CianwoodCity_Text_OldManIntro MSGBOX_DEFAULT
	goto_if_eq VAR_LUGIA_OR_HOOH, 2, CianwoodHouse1_EventScript_HermitHooh
	checkitem ITEM_TIDAL_BELL
	goto_if_eq VAR_RESULT, TRUE, CianwoodHouse1_EventScript_HermitTidalBell
	msgbox CianwoodCity_Text_WhirlIslandsStory, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse1_EventScript_HermitTidalBell::
	msgbox CianwoodCity_Text_TidalBellReaction, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse1_EventScript_HermitHooh::
	checkitem ITEM_CLEAR_BELL
	goto_if_eq VAR_RESULT, TRUE, CianwoodHouse1_EventScript_HermitClearBell
	msgbox CianwoodCity_Text_BellTowerStory, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodHouse1_EventScript_HermitClearBell::
	msgbox CianwoodCity_Text_ClearBellReaction, MSGBOX_DEFAULT
	closemessage
	release
	end

CianwoodCity_Text_OldManIntro:
	.string "Je ne me\n"
	.string "souviens pas\p"
	.string "de la dernière fois\n"
	.string "où quelqu'un est venu\l"
	.string "me rendre visite.\l"
	.string "Quand j'étais\p"
	.string "jeune, j'étais un\n"
	.string "DRESSEUR\p"
	.string "POKéMON aussi.\n"
	.string "Ces souvenirs me\l"
	.string "réchauffent le coeur.$"

CianwoodCity_Text_BellTowerStory:
	.string "As-tu entendu parler de la TOUR CENDRÉE\n"
	.string "à ROSYÈRES ?\p"
	.string "Il y a ce qu'on appelle des Cloches Claire\n"
	.string "au sommet de la tour.\p"
	.string "Elles ne font pas un seul bruit\n"
	.string "dans les vents forts.\p"
	.string "Il n'y a qu'une façon de les\n"
	.string "faire sonner.\p"
	.string "C'est d'obtenir une autre CLOCHE CLAIRE\n"
	.string "comme celles au sommet de la\l"
	.string "tour.\p"
	.string "Je suis parti à sa recherche quand j'étais jeune.\n"
	.string "Mais je n'en ai jamais eu une…$"

CianwoodCity_Text_WhirlIslandsStory:
	.string "As-tu entendu parler des ÎLES TOURBILLON ?\p"
	.string "Il y a ce qu'on appelle\n"
	.string "les Cloches des Marées\p"
	.string "au bassin de la cascade.\n"
	.string "Elles ne font pas un seul bruit\p"
	.string "dans les vents forts.\n"
	.string "Il n'y a qu'une façon de les faire sonner.\p"
	.string "C'est d'obtenir une autre Cloche des Marées\n"
	.string "comme celles au bassin.\l"
	.string "Je suis parti à sa recherche\p"
	.string "quand j'étais jeune.\n"
	.string "Mais je n'en ai jamais eu une…$"

CianwoodCity_Text_ClearBellReaction:
	.string "Oh ! Tu as réussi\n"
	.string "à obtenir une Cloche\p"
	.string "Claire ? Le vieux\n"
	.string "rêve que je faisais...\p"
	.string "Je vois... Tu l'as\n"
	.string "fait... ... ...Je l'entends\l"
	.string "! Le carillon des\p"
	.string "cloches sur le vent\n"
	.string "venant de la direction\l"
	.string "de la TOUR CENDRÉE...$"

CianwoodCity_Text_TidalBellReaction:
	.string "Oh ! Tu as réussi\n"
	.string "à obtenir une Cloche des\p"
	.string "Marées ? Le vieux\n"
	.string "rêve que je faisais...\p"
	.string "Je vois... Tu l'as\n"
	.string "fait... ... ...Je l'entends\l"
	.string "! Le carillon des\p"
	.string "cloches sur la brise\n"
	.string "marine venant de la\l"
	.string "direction des ÎLES TOURBILLON...$"
