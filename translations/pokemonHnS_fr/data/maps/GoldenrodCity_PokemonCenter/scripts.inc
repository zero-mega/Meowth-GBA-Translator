.set LOCALID_NURSE, 1

GoldenrodCity_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, GoldenrodCity_PokemonCenter_OnTransition
	.byte 0

GoldenrodCity_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_GOLDENROD_CITY
	end

GoldenrodCity_PokemonCenter_EventScript_GbaKid1::
	lock
	faceplayer
	msgbox GoldenrodCity_PokemonCenter_GameboyKidText1, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_PokemonCenter_EventScript_GbaKid2::
	lock
	faceplayer
	msgbox GoldenrodCity_PokemonCenter_GameboyKidText2, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_PokemonCenter_EventScript_Granny::
	lock
	faceplayer
	msgbox GoldenrodCity_PokemonCenter_GrannyText, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_PokemonCenter_EventScript_Lass::
	lock
	faceplayer
	msgbox GoldenrodCity_PokemonCenter_LassText, MSGBOX_DEFAULT
	closemessage
	release
	end

GoldenrodCity_PokemonCenter_GrannyText:
    .string "J'adore vivre dans la grande ville !\n"
    .string "Je suis venue ici quand j'étais une jeune\l"
    .string "Dresseuse, comme toi !$"

GoldenrodCity_PokemonCenter_GameboyKidText1:
    .string "C'est un CENTRE POKéMON spécial.\n"
    .string "Le toit est en or !$"

GoldenrodCity_PokemonCenter_GameboyKidText2:
    .string "J'ai dit à mon frère que le toit est\n"
    .string "fait d'or véritable. Il croit\l"
    .string "n'importe quoi !$"

GoldenrodCity_PokemonCenter_LassText:
    .string "Un POKéMON de niveau supérieur ne\n"
    .string "gagne pas toujours.\p"
    .string "Après tout, il peut avoir un\n"
    .string "désavantage de type.\p"
    .string "Je ne pense pas qu'il existe un seul\n"
    .string "POKéMON qui soit le plus fort.$"

GoldenrodPokeCenter_LinkReceptionistPleaseAcceptGSBallText:
    .string "{PLAYER}, n'est-ce pas ? Félicitations\p"
    .string "! En offre spéciale, une\p"
    .string "GS BALL a été envoyée\n"
    .string "rien que pour toi !\p"
    .string "Accepte-la, s'il te plaît !$"

GoldenrodPokeCenter_LinkReceptionistPleaseDoComeAgainText:
    .string "Revenez nous voir !$"

GoldenrodCity_PokemonCenter_PokefanFDoYouHaveEonMailText:
    .string "Oh là là, ton sac a l'air si lourd !\p"
    .string "Oh ! Tu aurais par hasard\n"
    .string "quelque chose appelé MAIL EON ?\p"
    .string "Ma fille en cherche un.\p"
    .string "Tu peux m'en donner un, non ?$"

GoldenrodCity_PokemonCenter_AskGiveAwayAnEonMailText:
    .string "Donner un COURRIER EON ?$"

GoldenrodCity_PokemonCenter_PokefanFThisIsForYouText:
    .string "Oh, c'est génial ! Merci,\n"
    .string "chéri !\p"
    .string "Tiens, c'est pour toi en retour !$"

GoldenrodCity_PokemonCenter_PokefanFDaughterWillBeDelightedText:
    .string "Ma fille sera ravie !$"

GoldenrodCity_PokemonCenter_PokefanFTooBadText:
    .string "Oh ? Tu n'en as pas ? Dommage.$"

GoldenrodCity_PokemonCenter_PokefanFAnotherTimeThenText:
    .string "Oh… Bon, une autre fois, alors.$"

GoldenrodCity_PokemonCenter_PlayerGaveAwayTheEonMailText:
    .string "{PLAYER} a donné le MAIL EON.$"
