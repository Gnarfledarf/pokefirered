# 1 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 2 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
.equ HELIX_FOSSIL, 1
# 3 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
.equ DOME_FOSSIL,  2
# 4 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
.equ OLD_AMBER,    3
# 5 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 6 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_MapScripts::
# 7 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	.byte 0
# 8 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 9 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_Garett::
# 10 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	lock
# 11 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	faceplayer
# 12 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	ingame_trade INGAME_TRADE_SEEL, Trade_Text_LookingForMonWannaTradeForMon, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DeclineTrade, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_NotRequestedMon, Trade_Text_HeyThanks, FLAG_DID_SEELOR_TRADE, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_AlreadyTraded
# 13 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	release
# 14 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	end
# 15 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 16 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DeclineTrade::
# 17 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	msgbox Trade_Text_AwwOhWell
# 18 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	release
# 19 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	end
# 20 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 21 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_NotRequestedMon::
# 22 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8009
# 23 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	msgbox Trade_Text_WhatThatsNoMon
# 24 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	release
# 25 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	end
# 26 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 27 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_AlreadyTraded::
# 28 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	msgbox Trade_Text_IsntMyOldMonGreat
# 29 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	release
# 30 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	end
# 31 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 32 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilScientist::
# 33 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	lock
# 34 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	faceplayer
# 35 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	setvar VAR_RESULT, FALSE
# 36 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	call_if_set FLAG_REVIVED_AMBER, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_CheckRevivedMtMoonFossil
# 37 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_RevivedAllFossils
# 38 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 2, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_GiveRevivedMon
# 39 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 1, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilStillReviving
# 40 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	call CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_CheckAddHelixFossilToList
# 41 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ChooseFossilHelix
# 42 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	call CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_CheckAddDomeFossilToList
# 43 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ChooseFossilDome
# 44 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	call CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_CheckAddOldAmberToList
# 45 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ChooseFossilAmber
# 46 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_HaveYouAFossilForMe
# 47 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DontShowFossil
# 48 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	end
# 49 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 50 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_CheckAddHelixFossilToList::
# 51 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_unset FLAG_GOT_HELIX_FOSSIL, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_SetResultFalse
# 52 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_set FLAG_REVIVED_HELIX, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_SetResultFalse
# 53 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	setvar VAR_RESULT, TRUE
# 54 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	return
# 55 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 56 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_CheckAddDomeFossilToList::
# 57 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_unset FLAG_GOT_DOME_FOSSIL, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_SetResultFalse
# 58 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_set FLAG_REVIVED_DOME, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_SetResultFalse
# 59 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	setvar VAR_RESULT, TRUE
# 60 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	return
# 61 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 62 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_CheckAddOldAmberToList::
# 63 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_unset FLAG_GOT_OLD_AMBER, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_SetResultFalse
# 64 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_set FLAG_REVIVED_AMBER, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_SetResultFalse
# 65 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	setvar VAR_RESULT, TRUE
# 66 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	return
# 67 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 68 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_SetResultFalse::
# 69 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	setvar VAR_RESULT, FALSE
# 70 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	return
# 71 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 72 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DontShowFossil::
# 73 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_NoIsTooBad
# 74 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	release
# 75 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	end
# 76 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 77 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ChooseFossilHelix::
# 78 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	message CinnabarIsland_PokemonLab_ExperimentRoom_Text_HaveYouAFossilForMe
# 79 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	waitmessage
# 80 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	call CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_CheckAddOldAmberToList
# 81 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ChooseFossilHelixAmber
# 82 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	multichoice 0, 0, MULTI_HELIX, FALSE
# 83 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	switch VAR_RESULT
# 84 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	case 0, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ShowHelixFossil
# 85 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	case 1, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DontShowFossil
# 86 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	case 127, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DontShowFossil
# 87 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	end
# 88 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 89 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ChooseFossilDome::
# 90 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	message CinnabarIsland_PokemonLab_ExperimentRoom_Text_HaveYouAFossilForMe
# 91 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	waitmessage
# 92 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	call CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_CheckAddOldAmberToList
# 93 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ChooseFossilDomeAmber
# 94 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	multichoice 0, 0, MULTI_DOME, FALSE
# 95 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	switch VAR_RESULT
# 96 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	case 0, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ShowDomeFossil
# 97 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	case 1, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DontShowFossil
# 98 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	case 127, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DontShowFossil
# 99 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	end
# 100 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 101 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ChooseFossilAmber::
# 102 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	message CinnabarIsland_PokemonLab_ExperimentRoom_Text_HaveYouAFossilForMe
# 103 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	waitmessage
# 104 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	multichoice 0, 0, MULTI_AMBER, FALSE
# 105 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	switch VAR_RESULT
# 106 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	case 0, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ShowOldAmber
# 107 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	case 1, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DontShowFossil
# 108 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	case 127, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DontShowFossil
# 109 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	end
# 110 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 111 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ChooseFossilHelixAmber::
# 112 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	multichoice 0, 0, MULTI_HELIX_AMBER, FALSE
# 113 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	switch VAR_RESULT
# 114 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	case 0, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ShowHelixFossil
# 115 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	case 1, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ShowOldAmber
# 116 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	case 2, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DontShowFossil
# 117 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	case 127, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DontShowFossil
# 118 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	end
# 119 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 120 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ChooseFossilDomeAmber::
# 121 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	multichoice 0, 0, MULTI_DOME_AMBER, FALSE
# 122 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	switch VAR_RESULT
# 123 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	case 0, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ShowDomeFossil
# 124 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	case 1, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ShowOldAmber
# 125 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	case 2, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DontShowFossil
# 126 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	case 127, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DontShowFossil
# 127 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	end
# 128 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 129 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ShowHelixFossil::
# 130 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_OMANYTE
# 131 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	bufferitemname STR_VAR_2, ITEM_HELIX_FOSSIL
# 132 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_ThatFossilIsOfMonMakeItLiveAgain, MSGBOX_YESNO
# 133 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_eq VAR_RESULT, NO, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DeclineReviveFossil
# 134 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_HandedFossilToWeirdDoctor
# 135 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 136 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	removeitem ITEM_HELIX_FOSSIL
# 137 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_TakesTimeGoForWalk
# 138 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 1
# 139 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL, HELIX_FOSSIL
# 140 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	release
# 141 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	end
# 142 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 143 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ShowDomeFossil::
# 144 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_KABUTO
# 145 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	bufferitemname STR_VAR_2, ITEM_DOME_FOSSIL
# 146 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_ThatFossilIsOfMonMakeItLiveAgain, MSGBOX_YESNO
# 147 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_eq VAR_RESULT, NO, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DeclineReviveFossil
# 148 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_HandedFossilToWeirdDoctor
# 149 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 150 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	removeitem ITEM_DOME_FOSSIL
# 151 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_TakesTimeGoForWalk
# 152 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 1
# 153 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL, DOME_FOSSIL
# 154 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	release
# 155 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	end
# 156 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 157 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_ShowOldAmber::
# 158 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_AERODACTYL
# 159 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	bufferitemname STR_VAR_2, ITEM_OLD_AMBER
# 160 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_ThatFossilIsOfMonMakeItLiveAgain, MSGBOX_YESNO
# 161 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_eq VAR_RESULT, NO, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DeclineReviveFossil
# 162 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_HandedFossilToWeirdDoctor
# 163 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 164 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	removeitem ITEM_OLD_AMBER
# 165 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_TakesTimeGoForWalk
# 166 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 1
# 167 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL, OLD_AMBER
# 168 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	release
# 169 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	end
# 170 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 171 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_DeclineReviveFossil::
# 172 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_YouComeAgain
# 173 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	release
# 174 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	end
# 175 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 176 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_FossilStillReviving::
# 177 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_TakesTimeGoForWalk
# 178 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	release
# 179 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	end
# 180 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 181 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_GiveRevivedMon::
# 182 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL, HELIX_FOSSIL, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_GiveOmanyte
# 183 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL, DOME_FOSSIL, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_GiveKabuto
# 184 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_WHICH_FOSSIL, OLD_AMBER, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_GiveAerodactyl
# 185 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	end
# 186 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 187 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_GiveOmanyte::
# 188 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_OMANYTE
# 189 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_OMANYTE
# 190 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_FossilMonBackToLife
# 191 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	givemon SPECIES_OMANYTE, 5
# 192 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 2, EventScript_NoMoreRoomForPokemon
# 193 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	setflag FLAG_REVIVED_HELIX
# 194 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 0, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_NicknameMonParty
# 195 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 1, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_NicknameMonPC
# 196 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	end
# 197 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 198 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_GiveKabuto::
# 199 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_KABUTO
# 200 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_KABUTO
# 201 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_FossilMonBackToLife
# 202 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	givemon SPECIES_KABUTO, 5
# 203 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 2, EventScript_NoMoreRoomForPokemon
# 204 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	setflag FLAG_REVIVED_DOME
# 205 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 0, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_NicknameMonParty
# 206 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 1, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_NicknameMonPC
# 207 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	end
# 208 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 209 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_GiveAerodactyl::
# 210 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	setvar VAR_TEMP_1, SPECIES_AERODACTYL
# 211 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	bufferspeciesname STR_VAR_1, SPECIES_AERODACTYL
# 212 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_FossilMonBackToLife
# 213 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	givemon SPECIES_AERODACTYL, 5
# 214 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 2, EventScript_NoMoreRoomForPokemon
# 215 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	setflag FLAG_REVIVED_AMBER
# 216 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 0, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_NicknameMonParty
# 217 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_eq VAR_RESULT, 1, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_NicknameMonPC
# 218 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	end
# 219 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 220 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_NicknameMonParty::
# 221 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 222 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 223 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	message CinnabarIsland_PokemonLab_ExperimentRoom_Text_ReceivedMonFromDoctor
# 224 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	waitmessage
# 225 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	waitfanfare
# 226 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 0
# 227 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 228 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_eq VAR_RESULT, NO, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_EndGiveMon
# 229 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	call EventScript_GetGiftMonPartySlot
# 230 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	call EventScript_ChangePokemonNickname
# 231 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_EndGiveMon
# 232 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	end
# 233 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 234 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_NicknameMonPC::
# 235 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 236 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 237 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	message CinnabarIsland_PokemonLab_ExperimentRoom_Text_ReceivedMonFromDoctor
# 238 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	waitmessage
# 239 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	waitfanfare
# 240 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	setvar VAR_MAP_SCENE_CINNABAR_ISLAND_POKEMON_LAB_EXPERIMENT_ROOM_REVIVE_STATE, 0
# 241 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	msgbox Text_GiveNicknameToThisMon, MSGBOX_YESNO
# 242 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_eq VAR_RESULT, NO, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_MonSentToPC
# 243 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	call EventScript_NameReceivedBoxMon
# 244 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_MonSentToPC
# 245 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	end
# 246 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 247 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_MonSentToPC::
# 248 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	call EventScript_TransferredToPC
# 249 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_EndGiveMon
# 250 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	end
# 251 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 252 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_EndGiveMon::
# 253 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	release
# 254 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	end
# 255 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 256 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_RevivedAllFossils::
# 257 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	msgbox CinnabarIsland_PokemonLab_ExperimentRoom_Text_YouComeAgain
# 258 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	release
# 259 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	end
# 260 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 261 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_CheckRevivedMtMoonFossil::
# 262 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_set FLAG_GOT_HELIX_FOSSIL, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_CheckRevivedHelix
# 263 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_set FLAG_GOT_DOME_FOSSIL, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_CheckRevivedDome
# 264 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_SetResultFalse
# 265 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	end
# 266 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 267 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_CheckRevivedHelix::
# 268 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_unset FLAG_REVIVED_HELIX, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_SetResultFalse
# 269 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	setvar VAR_RESULT, TRUE
# 270 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	return
# 271 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"

# 272 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_CheckRevivedDome::
# 273 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	goto_if_unset FLAG_REVIVED_DOME, CinnabarIsland_PokemonLab_ExperimentRoom_EventScript_SetResultFalse
# 274 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	setvar VAR_RESULT, TRUE
# 275 "data/maps/CinnabarIsland_PokemonLab_ExperimentRoom/scripts.pory"
	return
