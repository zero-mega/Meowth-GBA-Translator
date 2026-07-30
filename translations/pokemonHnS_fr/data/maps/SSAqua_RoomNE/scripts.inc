SSAqua_RoomNE_MapScripts::
	.byte 0

SSAqua_RoomNE_EventScript_Noland::
	trainerbattle_single TRAINER_NOLAND SSAqua_RoomNE_Text_HikerNolandSeen, SSAqua_RoomNE_Text_HikerNolandBeaten
	msgbox SSAqua_RoomNE_Text_HikerNolandAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomNE_EventScript_Ethan::
	trainerbattle_single TRAINER_ETHAN SSAqua_RoomNE_Text_PokemaniacEthanSeen, SSAqua_RoomNE_Text_PokemaniacEthanBeaten
	msgbox SSAqua_RoomNE_Text_PokemaniacEthanAfterBattle, MSGBOX_AUTOCLOSE
	end

SSAqua_RoomNE_Text_HikerNolandSeen:
    .string "Tu es seul ?\n"
    .string "Alors combattons !$"

SSAqua_RoomNE_Text_HikerNolandBeaten:
    .string "C'est trop à encaisser !$"

SSAqua_RoomNE_Text_HikerNolandAfterBattle:
    .string "Je me demande s'il y a des montagnes\n"
    .string "qui valent la peine d'être escaladées à KANTO ?$"

SSAqua_RoomNE_Text_PokemaniacEthanSeen:
    .string "Tu connais LILY ?\n"
    .string "C'est une super DJ à KANTO.$"

SSAqua_RoomNE_Text_PokemaniacEthanBeaten:
    .string "Gyaaaah !$"

SSAqua_RoomNE_Text_PokemaniacEthanAfterBattle:
    .string "LILY est sympa, mais\n"
    .string "MARY est la meilleure !\n"
    .string "Je veux écouter\n"
    .string "les émissions radio de\n"
    .string "JOHTO !$"
