GoldenrodCity_UndergroundEntrance_MapScripts::
	.byte 0


GoldenrodUnderground_EventScript_SuperNerd::
	lock
	faceplayer
	msgbox GoldenrodUnderground1_Text_SuperNerd, MSGBOX_DEFAULT
	closemessage
	lock
	release
	end

GoldenrodUnderground_EventScript_Teacher::
	lock
	faceplayer
	msgbox GoldenrodUnderground1_Text_Teacher, MSGBOX_DEFAULT
	closemessage
	lock
	release
	end

GoldenrodUnderground1_Text_SuperNerd:
	.string "On m'a défié en duel\n"
	.string "en bas.\p"
	.string "C'est dur là-bas. Tu ferais\n"
	.string "mieux d'être prudent.$"


GoldenrodUnderground1_Text_Teacher:
	.string "Il y a des boutiques en bas…\n"
	.string "Mais il y a aussi des Dresseurs.\p"
	.string "J'ai peur d'y descendre.$"
