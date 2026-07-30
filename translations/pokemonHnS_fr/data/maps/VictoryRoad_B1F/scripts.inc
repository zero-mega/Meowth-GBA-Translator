VictoryRoad_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, SetTimeEncounters
	map_script MAP_SCRIPT_ON_TRANSITION, SetTimeEncounters
	.byte 0

VictoryRoad_B1F_EventScript_Samuel::
	trainerbattle_single TRAINER_SAMUEL, VictoryRoad_B1F_Text_SamuelIntro, VictoryRoad_B1F_Text_SamuelDefeat
	msgbox VictoryRoad_B1F_Text_SamuelPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Shannon::
	trainerbattle_single TRAINER_SHANNON, VictoryRoad_B1F_Text_ShannonIntro, VictoryRoad_B1F_Text_ShannonDefeat
	msgbox VictoryRoad_B1F_Text_ShannonPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Michelle::
	trainerbattle_single TRAINER_MICHELLE, VictoryRoad_B1F_Text_MichelleIntro, VictoryRoad_B1F_Text_MichelleDefeat
	msgbox VictoryRoad_B1F_Text_MichellePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Mitchell::
	trainerbattle_single TRAINER_MITCHELL, VictoryRoad_B1F_Text_MitchellIntro, VictoryRoad_B1F_Text_MitchellDefeat
	msgbox VictoryRoad_B1F_Text_MitchellPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_EventScript_Halle::
	trainerbattle_single TRAINER_PRYCE_1, VictoryRoad_B1F_Text_HalleIntro, VictoryRoad_B1F_Text_HalleDefeat
	msgbox VictoryRoad_B1F_Text_HallePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B1F_Text_SamuelIntro:
	.string "L'idée de me rapprocher de la\n"
	.string "LIGUE POKéMON…\p"
	.string "Ça me donne le trac…$"

VictoryRoad_B1F_Text_SamuelDefeat:
	.string "Je n'ai rien pu faire…$"

VictoryRoad_B1F_Text_SamuelPostBattle:
	.string "La LIGUE POKéMON est redevenue lointaine…\n"
	.string "Quelle déception…$"

VictoryRoad_B1F_Text_ShannonIntro:
	.string "Pour gagner la LIGUE POKéMON, tu as besoin\n"
	.string "de la confiance de tes\l"
	.string "POKéMON.$"

VictoryRoad_B1F_Text_ShannonDefeat:
	.string "Votre relation est basée sur\n"
	.string "une confiance solide.$"

VictoryRoad_B1F_Text_ShannonPostBattle:
	.string "En restant ensemble tout le temps, la confiance\n"
	.string "grandit entre les POKéMON et les DRESSEURS.$"

VictoryRoad_B1F_Text_MichelleIntro:
	.string "Ce n'est pas le but. C'est juste un endroit\n"
	.string "sur le chemin de la LIGUE POKéMON.$"

VictoryRoad_B1F_Text_MichelleDefeat:
	.string "C'est ça !$"

VictoryRoad_B1F_Text_MichellePostBattle:
	.string "Tu t'en sortiras bien, c'est sûr !\n"
	.string "Tes POKéMON sont impatients !$"

VictoryRoad_B1F_Text_MitchellIntro:
	.string "Mes POKéMON sont cosmiquement\n"
	.string "impressionnants !$"

VictoryRoad_B1F_Text_MitchellDefeat:
	.string "Je n'ai jamais rencontré quelqu'un comme toi auparavant.$"

VictoryRoad_B1F_Text_MitchellPostBattle:
	.string "Même hors combat, je sens une puissance\n"
	.string "incroyable émaner de toi\l"
	.string "et de tes POKéMON.$"

VictoryRoad_B1F_Text_HalleIntro:
	.string "OK, pas besoin de t'énerver !\n"
	.string "Détends-toi, prenons ça cool !$"

VictoryRoad_B1F_Text_HalleDefeat:
	.string "Ouah !\n"
	.string "Formidable !$"

VictoryRoad_B1F_Text_HallePostBattle:
	.string "Bien sûr, c'est la ROUTE VICTOIRE.\p"
	.string "Mais ce n'est pas si différent du\n"
	.string "chemin que tu as parcouru jusqu'ici.\p"
	.string "Essaie de profiter du reste\n"
	.string "du voyage !$"

