.set LOCALID_NURSE, 1

VerdanturfTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, VerdanturfTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

VerdanturfTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_VERDANTURF_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

VerdanturfTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

VerdanturfTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox VerdanturfTown_PokemonCenter_1F_Text_FaithInYourPokemon, MSGBOX_NPC
	end

VerdanturfTown_PokemonCenter_1F_EventScript_ExpertM::
	msgbox VerdanturfTown_PokemonCenter_1F_Text_VisitForBattleTent, MSGBOX_NPC
	end

VerdanturfTown_PokemonCenter_1F_Text_FaithInYourPokemon:
	.string "Tu ne peux pas te considérer comme un vrai\n"
	.string "DRESSEUR si tu n'as pas confiance\l"
	.string "dans tes POKéMON.\p"
	.string "Seules les personnes qui croient\n"
	.string "en leurs POKéMON de combat peuvent aller\l"
	.string "jusqu'au bout.$"

VerdanturfTown_PokemonCenter_1F_Text_VisitForBattleTent:
	.string "La raison pour laquelle quelqu'un visiterait\n"
	.string "VERMILIA…\p"
	.string "C'est la TENTE DE COMBAT. Ça va sans\n"
	.string "dire.\p"
	.string "Ou bien il y a quelqu'un ici que tu\n"
	.string "es venu voir ?$"

