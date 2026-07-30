Route3_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route3_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	.byte 0

Route3_OnTransition: 
	callnative SetTimeBasedEncounters
	end

Route3_EventScript_Otis::
	trainerbattle_single TRAINER_OTIS, Route3_Text_FirebreatherOtis_Seen, Route3_Text_FirebreatherOtis_Beaten
	msgbox Route3_Text_FirebreatherOtis_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Warren::
	trainerbattle_single TRAINER_WARREN, Route3_Text_YoungsterWarren_Seen, Route3_Text_YoungsterWarren_Beaten
	msgbox Route3_Text_YoungsterWarren_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Jimmy::
	trainerbattle_single TRAINER_JIMMY, Route3_Text_YoungsterJimmy_Seen, Route3_Text_YoungsterJimmy_Beaten
	msgbox Route3_Text_YoungsterJimmy_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Burt::
	trainerbattle_single TRAINER_BURT, Route3_Text_FirebreatherBurt_Seen, Route3_Text_FirebreatherBurt_Beaten
	msgbox Route3_Text_FirebreatherBurt_AfterBattle, MSGBOX_AUTOCLOSE
	end

Route3_EventScript_Sign::
	msgbox Route3_Text_MtMoonSquareSign, MSGBOX_SIGN
	end

Route3_Text_FirebreatherOtis_Seen:
	.string "Ah ! Le temps est aussi beau que jamais.$"

Route3_Text_FirebreatherOtis_Beaten:
	.string "Il fait beau, mais je suis trempé…$"

Route3_Text_FirebreatherOtis_AfterBattle:
	.string "Quand il pleut, c'est dur d'allumer\n"
	.string "le feu…$"

Route3_Text_YoungsterWarren_Seen:
	.string "Hmmm… Je ne sais pas quoi faire…$"

Route3_Text_YoungsterWarren_Beaten:
	.string "Je savais que je perdrais…$"

Route3_Text_YoungsterWarren_AfterBattle:
	.string "Tu avais l'air fort.\p"
	.string "J'avais peur de t'affronter…$"

Route3_Text_YoungsterJimmy_Seen:
	.string "Je cours comme le vent !$"

Route3_Text_YoungsterJimmy_Beaten:
	.string "Emporté !$"

Route3_Text_YoungsterJimmy_AfterBattle:
	.string "Je porte un short toute l'année.\p"
	.string "C'est ma politique vestimentaire.$"

Route3_Text_FirebreatherBurt_Seen:
	.string "Approchez, venez voir !$"

Route3_Text_FirebreatherBurt_Beaten:
	.string "Aïe ! C'est chaud !$"

Route3_Text_FirebreatherBurt_AfterBattle:
	.string "Le plus grand cracheur de feu de KANTO,\n"
	.string "c'est moi.\p"
	.string "Mais pas le meilleur DRESSEUR…$"

Route3_Text_MtMoonSquareSign:
	.string "PLACE MT.LUNA\p"
	.string "Monte simplement les escaliers.$"

