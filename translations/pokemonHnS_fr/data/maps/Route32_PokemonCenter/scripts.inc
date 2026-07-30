.set LOCALID_NURSE, 1

Route32_PokemonCenter_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route32_PokemonCenter_OnTransition	
	.byte 0

Route32_PokemonCenter_OnTransition::
	setrespawn HEAL_LOCATION_ROUTE_32
	end

Route32_PokemonCenter_EventScript_Lass::
	lock
	faceplayer
	msgbox Route32_Pokecenter_Text_CooltrainerF, MSGBOX_DEFAULT
	closemessage
	release
	end

Route32_PokemonCenter_EventScript_FishingGuru::
	lock
	faceplayer
	checkitem ITEM_OLD_ROD
	goto_if_eq VAR_RESULT, TRUE, Route32_PokemonCenter_EventScript_FishingGuru3
	msgbox Route32_Pokecenter_Text_FishingGuruQuestion, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, TRUE, Route32_PokemonCenter_EventScript_FishingGuru2
	msgbox Route32_Pokecenter_Text_FishingGuruNo, MSGBOX_DEFAULT
	closemessage
	release
	end
Route32_PokemonCenter_EventScript_FishingGuru2::
	msgbox Route32_Pokecenter_Text_FishingGuruYes, MSGBOX_DEFAULT
	giveitem ITEM_OLD_ROD
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox Route32_Pokecenter_Text_FishingGuruGiveRod, MSGBOX_DEFAULT
	closemessage
	release
	end
Route32_PokemonCenter_EventScript_FishingGuru3::
	msgbox Route32_Pokecenter_Text_FishingGuruAfter, MSGBOX_DEFAULT
	release
	end



Route32_Pokecenter_Text_FishingGuruQuestion:
	.string "C'est un super spot de pêche.\p"
	.string "Tu as vu des gens pêcher ?\n"
	.string "Et toi ?\p"
	.string "Tu veux une de mes CANNES ?$"

Route32_Pokecenter_Text_FishingGuruYes:
	.string "Hé, c'est bon à entendre.\p"
	.string "Maintenant tu es un pêcheur aussi !$"

Route32_Pokecenter_Text_FishingGuruGiveRod:
	.string "La pêche, c'est génial !\p"
	.string "S'il y a de l'eau, que ce soit la mer ou\n"
	.string "un ruisseau, essaie ta CANNE !$"

Route32_Pokecenter_Text_FishingGuruNo:
	.string "Oh. C'est plutôt décevant…$"

Route32_Pokecenter_Text_FishingGuruAfter:
	.string "Hé, gamin. Ça mord, par ici ?$"

Route32_Pokecenter_Text_CooltrainerF:
	.string "Qu'est-ce que je devrais faire tenir à mon POKéMON ?\p"
	.string "Peut-être un objet qui augmente\n"
	.string "la puissance d'ATTAQUE…$"

