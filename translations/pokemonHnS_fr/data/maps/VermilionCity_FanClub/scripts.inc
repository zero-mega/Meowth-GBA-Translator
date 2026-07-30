.set LOCALID_FAN_CLUB_CLEFAIRY_DOLL, 5

VermilionCity_FanClub_MapScripts::
	.byte 0

VermilionCity_FanClub_EventScript_Chairman::
	lock
	faceplayer
	goto_if_eq VAR_FAN_CLUB_GUY, 1, VermilionCity_FanClub_EventScript_ChairmanAfter
	msgbox PokemonFanClub_Text_Chairman_Intro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, FALSE, VermilionCity_FanClub_EventScript_ChairmanRefused
	msgbox PokemonFanClub_Text_Chairman_Rapidash, MSGBOX_DEFAULT
	msgbox PokemonFanClub_Text_Chairman_Gift, MSGBOX_DEFAULT
	giveitem ITEM_RARE_CANDY
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_FAN_CLUB_GUY, 1
	msgbox PokemonFanClub_Text_Chairman_Candy, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_ChairmanRefused::
	msgbox PokemonFanClub_Text_Chairman_Disappointed, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_ChairmanAfter::
	msgbox PokemonFanClub_Text_Chairman_MoreTales, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_Woman1::
	msgbox PokemonFanClub_Text_Receptionist, MSGBOX_NPC
	end

VermilionCity_FanClub_EventScript_Woman2::
	msgbox PokemonFanClub_Text_Teacher, MSGBOX_NPC
	end

VermilionCity_FanClub_EventScript_ClefairyGuy::
	lock
	faceplayer
	msgbox PokemonFanClub_Text_ClefairyGuy_Adorable, MSGBOX_DEFAULT
	goto_if_eq VAR_FAN_CLUB_CLEFAIRY, 1, VermilionCity_FanClub_EventScript_ClefairyGiveDoll
	goto_if_ge VAR_FAN_CLUB_CLEFAIRY, 2, VermilionCity_FanClub_EventScript_ClefairyAfter
	msgbox PokemonFanClub_Text_ClefairyGuy_MakingDo, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_ClefairyGiveDoll::
	msgbox PokemonFanClub_Text_ClefairyGuy_ReturnDoll, MSGBOX_DEFAULT
	fadescreenswapbuffers FADE_TO_BLACK
	setflag FLAG_HIDE_FAN_CLUB_CLEFAIRY_DOLL
	removeobject LOCALID_FAN_CLUB_CLEFAIRY_DOLL
	fadescreenswapbuffers FADE_FROM_BLACK
	giveitem ITEM_LOST_ITEM
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_FAN_CLUB_CLEFAIRY, 2
	msgbox PokemonFanClub_Text_ClefairyGuy_GoingToGetOne, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_ClefairyAfter::
	msgbox PokemonFanClub_Text_ClefairyGuy_GoingToGetOne, MSGBOX_DEFAULT
	closemessage
	release
	end

VermilionCity_FanClub_EventScript_Bayleef::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_BAYLEEF, CRY_MODE_NORMAL
	msgbox PokemonFanClub_Text_Bayleef, MSGBOX_DEFAULT
	waitmoncry
	release
	end


PokemonFanClub_Text_Chairman_Intro:
	.string "Je suis le PRÉSIDENT du FAN CLUB\n"
	.string "POKéMON.\p"
	.string "J'ai élevé plus de 150 POKéMON.\p"
	.string "Je suis très exigeant quand il s'agit de\n"
	.string "POKéMON.\p"
	.string "Tu es venu juste pour entendre parler de\n"
	.string "mes POKéMON ?$"

PokemonFanClub_Text_Chairman_Rapidash:
	.string "Bien ! Alors\p"
	.string "écoute !\p"
	.string "Alors… mon\n"
	.string "GALOPA préféré…\l"
	.string "Il est… mignon…\l"
	.string "adorable…\l"
	.string "intelligent…\l"
	.string "insupport\l"
	.string "ablement…\p"
	.string "plus… incroyable…\n"
	.string "oh… tu penses\l"
	.string "que je\l"
	.string "devrais lui\p"
	.string "donner un\n"
	.string "surnom ?$"

PokemonFanClub_Text_Chairman_Gift:
	.string "Merci de m'avoir écouté.\n"
	.string "Je veux que tu aies ça !$"

PokemonFanClub_Text_Chairman_Candy:
	.string "C'est une SUPER BONBON qui\n"
	.string "rend les POKéMON plus forts.\p"
	.string "Je préfère renforcer mes\n"
	.string "POKéMON en combattant, alors\l"
	.string "tu peux le garder.$"

PokemonFanClub_Text_Chairman_MoreTales:
	.string "Bonjour, {PLAYER} !\p"
	.string "Tu es revenu me parler de mes\n"
	.string "POKéMON ?\p"
	.string "Non ? Oh... J'avais encore des histoires\n"
	.string "à raconter...$"

PokemonFanClub_Text_Chairman_Disappointed:
	.string "Quelle déception…\p"
	.string "Reviens si tu veux écouter.$"

PokemonFanClub_Text_Receptionist:
	.string "Notre PRÉSIDENT est très bavard\n"
	.string "quand il s'agit de POKéMON…$"

@=Clefairy=Guy=========================================================================================================
PokemonFanClub_Text_ClefairyGuy_Adorable:
	.string "J'adore la façon dont MÉLO fait onduler\n"
	.string "son doigt quand il essaie d'utiliser\l"
	.string "MÉTRONOME.\p"
	.string "C'est trop adorable !$"

PokemonFanClub_Text_ClefairyGuy_MakingDo:
	.string "J'adore MÉLOFÉE, mais je n'arrive\n"
	.string "jamais à en attraper une.\p"
	.string "Alors je me contente d'une\n"
	.string "POKé POUPÉE que j'ai trouvée.$"

PokemonFanClub_Text_ClefairyGuy_ReturnDoll:
	.string "Ah, je comprends. La fille qui a perdu\n"
	.string "cette POKé POUPÉE est triste…\p"
	.string "OK. Pourrais-tu rapporter cette POKé POUPÉE\n"
	.string "à cette pauvre petite fille ?\p"
	.string "Un jour, je me ferai un vrai MÉLOFÉE\n"
	.string "tout seul. Pas de souci !$"

PokemonFanClub_Text_ClefairyGuy_GoingToGetOne:
	.string "Tu verras. Je vais me faire un vrai\n"
	.string "MÉLOFÉE comme ami.$"

@============================================================================================================================

PokemonFanClub_Text_Teacher:
	.string "Regarde mon adorable MACRONIUM !\p"
	.string "La feuille sur sa tête est si mignonne !$"

PokemonFanClub_Text_ClefairyDoll:
	.string "C'est un MÉLOFÉE ! Hein ?\p"
	.string "Oh, oui. C'est une POKé POUPÉE\n"
	.string "MÉLOFÉE.$"

PokemonFanClub_Text_Bayleef:
	.string "MACRONIUM : Li liif !$"

PokemonFanClub_Text_Listen:
	.string "Écoutons poliment les autres\n"
	.string "dresseurs.$"

PokemonFanClub_Text_Bragging:
	.string "Si quelqu'un se vante, vante-toi\n"
	.string "en retour !$"
