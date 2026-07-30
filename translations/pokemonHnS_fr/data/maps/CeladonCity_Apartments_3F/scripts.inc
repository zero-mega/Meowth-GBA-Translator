CeladonCity_Apartments_3F_MapScripts::
	.byte 0

CeladonCity_Apartments_3F_EventScript_Sign::
	msgbox CeladonMansion3F_Text_DevRoomSign, MSGBOX_SIGN
	end

CeladonCity_Apartments_3F_EventScript_Programmer::
	msgbox GameFreak_Text_Programmer, MSGBOX_NPC
	end

CeladonCity_Apartments_3F_EventScript_GraphicArtist::
	msgbox GameFreak_Text_GraphicArtist, MSGBOX_NPC
	end

CeladonCity_Apartments_3F_EventScript_Program::
	msgbox CeladonMansion3F_Text_GameProgram, MSGBOX_SIGN
	end

CeladonCity_Apartments_3F_EventScript_Picture::
	msgbox CeladonMansion3F_Text_Drawing, MSGBOX_SIGN
	end

CeladonCity_Apartments_3F_EventScript_CharacterDesigner::
	msgbox GameFreak_Text_CharacterDesigner, MSGBOX_NPC
	end

GameFreak_Text_GameDesigner:
	.string "C'est vrai ?\p"
	.string "Je suis le CONCEPTEUR DE JEU !\p"
	.string "Remplir ton POKéDEX, c'est dur,\n"
	.string "mais n'abandonne pas !$"

GameFreak_Text_GameDesignerCompletedPokedex:
	.string "Waouh ! Excellent ! Tu as complété\n"
	.string "ton POKéDEX !\p"
	.string "Félicitations !$"

GameFreak_Text_GraphicArtist:
	.string "Je suis le GRAPHISTE.\p"
	.string "Je t'ai dessiné !$"

GameFreak_Text_GraphicArtistPrintDiploma:
	.string "Je suis le GRAPHISTE.\p"
	.string "Oh, tu as complété ton POKéDEX ?\p"
	.string "Tu veux que j'imprime ton\n"
	.string "DIPLÔME ?$"

GameFreak_Text_GraphicArtistRefused:
	.string "Dis-moi si tu veux que j'imprime\n"
	.string "ton DIPLÔME.$"

GameFreak_Text_GraphicArtistError:
	.string "Quelque chose ne va pas. Je dois\n"
	.string "annuler l'impression.$"

GameFreak_Text_Programmer:
	.string "Qui, moi ? Je suis le PROGRAMMEUR.\p"
	.string "Joue aux machines à sous !$"

GameFreak_Text_CharacterDesigner:
	.string "Les JUMELLES ne sont-elles pas adorables ?\p"
	.string "JASMINE est jolie aussi.\p"
	.string "Oh, je les adore !$"

CeladonMansion3F_Text_DevRoomSign:
	.string "SALLE DE DÉVELOPPEMENT GAME FREAK$"

CeladonMansion3F_Text_Drawing:
	.string "C'est un dessin détaillé d'une\n"
	.string "jolie fille.$"

CeladonMansion3F_Text_GameProgram:
	.string "C'est le programme du jeu. Le modifier\n"
	.string "pourrait introduire un bug dans le\n"
	.string "jeu !$"

CeladonMansion3F_Text_ReferenceMaterial:
	.string "C'est rempli de documents\n"
	.string "de référence. Il y a même une\n"
	.string "POKé POUPÉE.$"
