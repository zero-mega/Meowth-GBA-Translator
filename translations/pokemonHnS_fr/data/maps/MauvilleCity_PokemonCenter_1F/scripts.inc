.set LOCALID_NURSE, 1

MauvilleCity_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, MauvilleCity_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

MauvilleCity_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_MAUVILLE_CITY
	call Common_EventScript_UpdateBrineyLocation
	goto MauvilleCity_PokemonCenter_1F_EventScript_SetMauvilleOldManGfx
	end

MauvilleCity_PokemonCenter_1F_EventScript_SetMauvilleOldManGfx::
	special SetMauvilleOldManObjEventGfx
	end

MauvilleCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

MauvilleCity_PokemonCenter_1F_EventScript_Woman1::
	msgbox MauvilleCity_PokemonCenter_1F_Text_ManOverThereSaysWeirdThings, MSGBOX_NPC
	end

MauvilleCity_PokemonCenter_1F_EventScript_Woman2::
	msgbox MauvilleCity_PokemonCenter_1F_Text_MyDataUpdatedFromRecordCorner, MSGBOX_NPC
	end

MauvilleCity_PokemonCenter_1F_EventScript_Youngster::
	msgbox MauvilleCity_PokemonCenter_1F_Text_RecordCornerSoundsFun, MSGBOX_NPC
	end

MauvilleCity_PokemonCenter_1F_Text_ManOverThereSaysWeirdThings:
	.string "Ce type là-bas dit des trucs\n"
	.string "bizarres !\p"
	.string "Il est drôle d'une drôle de façon.\n"
	.string "Je ne l'oublierai pas de sitôt !$"

MauvilleCity_PokemonCenter_1F_Text_MyDataUpdatedFromRecordCorner:
	.string "Quand j'ai accédé au COIN RECORD,\n"
	.string "les données des tendances à ENTOILLE\l"
	.string "ont été mises à jour.\p"
	.string "Cette info est maintenant identique\n"
	.string "à celle de mon ami !$"

MauvilleCity_PokemonCenter_1F_Text_RecordCornerSoundsFun:
	.string "Un COIN RECORD a ouvert à l'étage du\n"
	.string "CENTRE POKéMON.\p"
	.string "Je ne sais pas de quoi il s'agit, mais ça\n"
	.string "a l'air amusant. Je vais aller voir !$"

