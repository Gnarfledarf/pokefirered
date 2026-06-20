# 1 "data/maps/VermilionCity/scripts.pory"

# 2 "data/maps/VermilionCity/scripts.pory"
VermilionCity_MapScripts::
# 3 "data/maps/VermilionCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_OnTransition
# 4 "data/maps/VermilionCity/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VermilionCity_OnFrame
# 5 "data/maps/VermilionCity/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, VermilionCity_OnLoad
# 6 "data/maps/VermilionCity/scripts.pory"
	.byte 0
# 7 "data/maps/VermilionCity/scripts.pory"

# 8 "data/maps/VermilionCity/scripts.pory"
VermilionCity_OnFrame::
# 9 "data/maps/VermilionCity/scripts.pory"
	map_script_2 VAR_MAP_SCENE_VERMILION_CITY, 2, VermilionCity_EventScript_ExitSSAnne
# 10 "data/maps/VermilionCity/scripts.pory"
	.2byte 0
# 11 "data/maps/VermilionCity/scripts.pory"

# 12 "data/maps/VermilionCity/scripts.pory"
VermilionCity_OnLoad::
# 13 "data/maps/VermilionCity/scripts.pory"
	special SetRoofBirds
# 14 "data/maps/VermilionCity/scripts.pory"
	end
# 15 "data/maps/VermilionCity/scripts.pory"

# 16 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ExitSSAnne::
# 17 "data/maps/VermilionCity/scripts.pory"
	lockall
# 18 "data/maps/VermilionCity/scripts.pory"
	applymovement LOCALID_PLAYER, VermilionCity_Movement_ExitSSAnne
# 19 "data/maps/VermilionCity/scripts.pory"
	waitmovement 0
# 20 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_MAP_SCENE_VERMILION_CITY, 3
# 21 "data/maps/VermilionCity/scripts.pory"
	releaseall
# 22 "data/maps/VermilionCity/scripts.pory"
	end
# 23 "data/maps/VermilionCity/scripts.pory"

# 24 "data/maps/VermilionCity/scripts.pory"
VermilionCity_Movement_ExitSSAnne::
# 25 "data/maps/VermilionCity/scripts.pory"
	walk_up
# 26 "data/maps/VermilionCity/scripts.pory"
	walk_up
# 27 "data/maps/VermilionCity/scripts.pory"
	step_end
# 28 "data/maps/VermilionCity/scripts.pory"

# 29 "data/maps/VermilionCity/scripts.pory"
VermilionCity_OnTransition::
# 30 "data/maps/VermilionCity/scripts.pory"
	setworldmapflag FLAG_WORLD_MAP_VERMILION_CITY
# 31 "data/maps/VermilionCity/scripts.pory"
	call_if_set FLAG_TALKED_TO_OAKS_AIDE_IN_VERMILION, VermilionCity_EventScript_HideOaksAide
# 32 "data/maps/VermilionCity/scripts.pory"
	end
# 33 "data/maps/VermilionCity/scripts.pory"

# 34 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_HideOaksAide::
# 35 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_HIDE_VERMILION_CITY_OAKS_AIDE
# 36 "data/maps/VermilionCity/scripts.pory"
	return
# 37 "data/maps/VermilionCity/scripts.pory"

# 38 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_Woman::
# 39 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_GrimerMultipliesInSludge, MSGBOX_NPC
# 40 "data/maps/VermilionCity/scripts.pory"
	end
# 41 "data/maps/VermilionCity/scripts.pory"

# 42 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_OldMan1::
# 43 "data/maps/VermilionCity/scripts.pory"
	lock
# 44 "data/maps/VermilionCity/scripts.pory"
	faceplayer
# 45 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_VERMILION_CITY, 3, VermilionCity_EventScript_OldMan1SSAnneLeft
# 46 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_DidYouSeeSSAnneInHarbor
# 47 "data/maps/VermilionCity/scripts.pory"
	release
# 48 "data/maps/VermilionCity/scripts.pory"
	end
# 49 "data/maps/VermilionCity/scripts.pory"

# 50 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_OldMan1SSAnneLeft::
# 51 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_SSAnneHasDepartedForYear
# 52 "data/maps/VermilionCity/scripts.pory"
	release
# 53 "data/maps/VermilionCity/scripts.pory"
	end
# 54 "data/maps/VermilionCity/scripts.pory"

# 55 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_FerrySailor::
# 56 "data/maps/VermilionCity/scripts.pory"
	lock
# 57 "data/maps/VermilionCity/scripts.pory"
	faceplayer
# 58 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_VERMILION_CITY, 3, VermilionCity_EventScript_CheckSeagallopPresent
# 59 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_WelcomeToTheSSAnne
# 60 "data/maps/VermilionCity/scripts.pory"
	release
# 61 "data/maps/VermilionCity/scripts.pory"
	end
# 62 "data/maps/VermilionCity/scripts.pory"

# 63 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckHasMysticTicket::
# 64 "data/maps/VermilionCity/scripts.pory"
	goto_if_unset FLAG_ENABLE_SHIP_NAVEL_ROCK, EventScript_SetResultFalse
# 65 "data/maps/VermilionCity/scripts.pory"
	checkitem ITEM_MYSTIC_TICKET
# 66 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, EventScript_SetResultFalse
# 67 "data/maps/VermilionCity/scripts.pory"
	goto EventScript_SetResultTrue
# 68 "data/maps/VermilionCity/scripts.pory"
	end
# 69 "data/maps/VermilionCity/scripts.pory"

# 70 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckHasAuroraTicket::
# 71 "data/maps/VermilionCity/scripts.pory"
	goto_if_unset FLAG_ENABLE_SHIP_BIRTH_ISLAND, EventScript_SetResultFalse
# 72 "data/maps/VermilionCity/scripts.pory"
	checkitem ITEM_AURORA_TICKET
# 73 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, EventScript_SetResultFalse
# 74 "data/maps/VermilionCity/scripts.pory"
	goto EventScript_SetResultTrue
# 75 "data/maps/VermilionCity/scripts.pory"
	end
# 76 "data/maps/VermilionCity/scripts.pory"

# 77 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckSeagallopPresent::
# 78 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 79 "data/maps/VermilionCity/scripts.pory"
	goto_if_set FLAG_BATTLE_FRONTIER_UNLOCKED, VermilionCity_EventScript_ChooseFrontierUnlocked
# 80 "data/maps/VermilionCity/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 5, VermilionCity_EventScript_ChooseSeagallopDestRainbowPass
# 81 "data/maps/VermilionCity/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 1, VermilionCity_EventScript_ChooseSeagallopDestTriPass
# 82 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_TheShipSetSail
# 83 "data/maps/VermilionCity/scripts.pory"
	release
# 84 "data/maps/VermilionCity/scripts.pory"
	end
# 85 "data/maps/VermilionCity/scripts.pory"

# 86 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ChooseFrontierUnlocked::
# 87 "data/maps/VermilionCity/scripts.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 88 "data/maps/VermilionCity/scripts.pory"
	special QuestLog_CutRecording
# 89 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_BoardSeagallopFerry
# 90 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 91 "data/maps/VermilionCity/scripts.pory"
	dynmultipush Seagallop_SeviiIslands, 0
# 92 "data/maps/VermilionCity/scripts.pory"
	dynmultipush Seagallop_BattleFrontier, 1
# 93 "data/maps/VermilionCity/scripts.pory"
	call VermilionCity_EventScript_CheckHasMysticTicket
# 94 "data/maps/VermilionCity/scripts.pory"
	call_if_eq VAR_RESULT, TRUE, VermilionCity_AddMysticTicket
# 95 "data/maps/VermilionCity/scripts.pory"
	call VermilionCity_EventScript_CheckHasAuroraTicket
# 96 "data/maps/VermilionCity/scripts.pory"
	call_if_eq VAR_RESULT, TRUE, VermilionCity_AddAuroraTicket
# 97 "data/maps/VermilionCity/scripts.pory"
	dynmultipush Seagallop_Cancel, 4
# 98 "data/maps/VermilionCity/scripts.pory"
	dynmultistack 0, 0, FALSE, 5, FALSE, 0, NULL
# 99 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 100 "data/maps/VermilionCity/scripts.pory"
	case 0, EventScript_SeviiDestinationsPage1
# 101 "data/maps/VermilionCity/scripts.pory"
	case 1, EventScript_SailToBattleFrontier
# 102 "data/maps/VermilionCity/scripts.pory"
	case 2, EventScript_SailToNavelRock
# 103 "data/maps/VermilionCity/scripts.pory"
	case 3, EventScript_SailToBirthIsland
# 104 "data/maps/VermilionCity/scripts.pory"
	case 4, EventScript_CancelSail
# 105 "data/maps/VermilionCity/scripts.pory"
	case MULTI_B_PRESSED, EventScript_CancelSail
# 106 "data/maps/VermilionCity/scripts.pory"
	end
# 107 "data/maps/VermilionCity/scripts.pory"

# 108 "data/maps/VermilionCity/scripts.pory"
VermilionCity_AddMysticTicket::
# 109 "data/maps/VermilionCity/scripts.pory"
	dynmultipush Seagallop_NavelRock, 2
# 110 "data/maps/VermilionCity/scripts.pory"
	return
# 111 "data/maps/VermilionCity/scripts.pory"

# 112 "data/maps/VermilionCity/scripts.pory"
VermilionCity_AddAuroraTicket::
# 113 "data/maps/VermilionCity/scripts.pory"
	dynmultipush Seagallop_BirthIsland, 3
# 114 "data/maps/VermilionCity/scripts.pory"
	return
# 115 "data/maps/VermilionCity/scripts.pory"

# 116 "data/maps/VermilionCity/scripts.pory"
Seagallop_SeviiIslands::
# 117 "data/maps/VermilionCity/scripts.pory"
	.string "Sevii Islands$"
# 118 "data/maps/VermilionCity/scripts.pory"

# 119 "data/maps/VermilionCity/scripts.pory"
Seagallop_NavelRock::
# 120 "data/maps/VermilionCity/scripts.pory"
	.string "Navel Rock$"
# 121 "data/maps/VermilionCity/scripts.pory"

# 122 "data/maps/VermilionCity/scripts.pory"
Seagallop_BirthIsland::
# 123 "data/maps/VermilionCity/scripts.pory"
	.string "Birth Island$"
# 124 "data/maps/VermilionCity/scripts.pory"

# 125 "data/maps/VermilionCity/scripts.pory"
Seagallop_BattleFrontier::
# 126 "data/maps/VermilionCity/scripts.pory"
	.string "Battle Frontier$"
# 127 "data/maps/VermilionCity/scripts.pory"

# 128 "data/maps/VermilionCity/scripts.pory"
Seagallop_Cancel::
# 129 "data/maps/VermilionCity/scripts.pory"
	.string "Cancel$"
# 130 "data/maps/VermilionCity/scripts.pory"

# 131 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ChooseSeagallopDestRainbowPass::
# 132 "data/maps/VermilionCity/scripts.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 133 "data/maps/VermilionCity/scripts.pory"
	special QuestLog_CutRecording
# 134 "data/maps/VermilionCity/scripts.pory"
	call VermilionCity_EventScript_CheckHasMysticTicket
# 135 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, VermilionCity_EventScript_HasMysticTicket
# 136 "data/maps/VermilionCity/scripts.pory"
	call VermilionCity_EventScript_CheckHasAuroraTicket
# 137 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, VermilionCity_EventScript_HasAuroraTicket
# 138 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 139 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_BoardSeagallopRainbowPass
# 140 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 141 "data/maps/VermilionCity/scripts.pory"
	goto EventScript_SeviiDestinationsPage1
# 142 "data/maps/VermilionCity/scripts.pory"
	end
# 143 "data/maps/VermilionCity/scripts.pory"

# 144 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_HasMysticTicket::
# 145 "data/maps/VermilionCity/scripts.pory"
	call VermilionCity_EventScript_CheckHasAuroraTicket
# 146 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, VermilionCity_EventScript_HasMysticAndAuroraTickets
# 147 "data/maps/VermilionCity/scripts.pory"
	call_if_unset FLAG_SHOWN_MYSTIC_TICKET, VermilionCity_EventScript_ShowMysticTicket
# 148 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_BoardSeagallopFerry
# 149 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 150 "data/maps/VermilionCity/scripts.pory"
	multichoice 17, 6, MULTI_SEVII_NAVEL, FALSE
# 151 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 152 "data/maps/VermilionCity/scripts.pory"
	case 0, EventScript_SeviiDestinationsPage1
# 153 "data/maps/VermilionCity/scripts.pory"
	case 1, EventScript_SailToNavelRock
# 154 "data/maps/VermilionCity/scripts.pory"
	case 2, EventScript_CancelSail
# 155 "data/maps/VermilionCity/scripts.pory"
	case MULTI_B_PRESSED, EventScript_CancelSail
# 156 "data/maps/VermilionCity/scripts.pory"
	end
# 157 "data/maps/VermilionCity/scripts.pory"

# 158 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ShowMysticTicket::
# 159 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_SHOWN_MYSTIC_TICKET
# 160 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_OhMysticTicketTakeYouToNavelRock
# 161 "data/maps/VermilionCity/scripts.pory"
	return
# 162 "data/maps/VermilionCity/scripts.pory"

# 163 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_HasAuroraTicket::
# 164 "data/maps/VermilionCity/scripts.pory"
	call_if_unset FLAG_SHOWN_AURORA_TICKET, VermilionCity_EventScript_ShowAuroraTicket
# 165 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_BoardSeagallopFerry
# 166 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 167 "data/maps/VermilionCity/scripts.pory"
	multichoice 13, 6, MULTI_SEVII_BIRTH, FALSE
# 168 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 169 "data/maps/VermilionCity/scripts.pory"
	case 0, EventScript_SeviiDestinationsPage1
# 170 "data/maps/VermilionCity/scripts.pory"
	case 1, EventScript_SailToBirthIsland
# 171 "data/maps/VermilionCity/scripts.pory"
	case 2, EventScript_CancelSail
# 172 "data/maps/VermilionCity/scripts.pory"
	case MULTI_B_PRESSED, EventScript_CancelSail
# 173 "data/maps/VermilionCity/scripts.pory"
	end
# 174 "data/maps/VermilionCity/scripts.pory"

# 175 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ShowAuroraTicket::
# 176 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_SHOWN_AURORA_TICKET
# 177 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_OhAuroraTicketTakeYouToBirthIsland
# 178 "data/maps/VermilionCity/scripts.pory"
	return
# 179 "data/maps/VermilionCity/scripts.pory"

# 180 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_HasMysticAndAuroraTickets::
# 181 "data/maps/VermilionCity/scripts.pory"
	call_if_unset FLAG_SHOWN_MYSTIC_TICKET, VermilionCity_EventScript_ShowMysticTicket
# 182 "data/maps/VermilionCity/scripts.pory"
	call_if_unset FLAG_SHOWN_AURORA_TICKET, VermilionCity_EventScript_ShowAuroraTicket
# 183 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_BoardSeagallopFerry
# 184 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 185 "data/maps/VermilionCity/scripts.pory"
	multichoice 13, 5, MULTI_SEVII_NAVEL_BIRTH, FALSE
# 186 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 187 "data/maps/VermilionCity/scripts.pory"
	case 0, EventScript_SeviiDestinationsPage1
# 188 "data/maps/VermilionCity/scripts.pory"
	case 1, EventScript_SailToNavelRock
# 189 "data/maps/VermilionCity/scripts.pory"
	case 2, EventScript_SailToBirthIsland
# 190 "data/maps/VermilionCity/scripts.pory"
	case 3, EventScript_CancelSail
# 191 "data/maps/VermilionCity/scripts.pory"
	case MULTI_B_PRESSED, EventScript_CancelSail
# 192 "data/maps/VermilionCity/scripts.pory"
	end
# 193 "data/maps/VermilionCity/scripts.pory"

# 194 "data/maps/VermilionCity/scripts.pory"
EventScript_SailToNavelRock::
# 195 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_Seagallop10Departing
# 196 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 197 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8006, SEAGALLOP_NAVEL_ROCK
# 198 "data/maps/VermilionCity/scripts.pory"
	goto EventScript_SetSail
# 199 "data/maps/VermilionCity/scripts.pory"
	end
# 200 "data/maps/VermilionCity/scripts.pory"

# 201 "data/maps/VermilionCity/scripts.pory"
EventScript_SailToBirthIsland::
# 202 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_Seagallop12Departing
# 203 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 204 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8006, SEAGALLOP_BIRTH_ISLAND
# 205 "data/maps/VermilionCity/scripts.pory"
	goto EventScript_SetSail
# 206 "data/maps/VermilionCity/scripts.pory"
	end
# 207 "data/maps/VermilionCity/scripts.pory"

# 208 "data/maps/VermilionCity/scripts.pory"
EventScript_SailToBattleFrontier::
# 209 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_Seagallop12Departing
# 210 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 211 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8006, SEAGALLOP_BATTLE_FRONTIER
# 212 "data/maps/VermilionCity/scripts.pory"
	goto EventScript_SetSail
# 213 "data/maps/VermilionCity/scripts.pory"
	end
# 214 "data/maps/VermilionCity/scripts.pory"

# 215 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ChooseSeagallopDestTriPass::
# 216 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_BoardSeagallopTriPass
# 217 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 218 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 219 "data/maps/VermilionCity/scripts.pory"
	multichoice 19, 5, MULTI_SEAGALLOP_123, FALSE
# 220 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 221 "data/maps/VermilionCity/scripts.pory"
	case 0, EventScript_SailToOneIsland2
# 222 "data/maps/VermilionCity/scripts.pory"
	case 1, EventScript_SailToTwoIsland2
# 223 "data/maps/VermilionCity/scripts.pory"
	case 2, EventScript_SailToThreeIsland2
# 224 "data/maps/VermilionCity/scripts.pory"
	case 3, EventScript_CancelSail
# 225 "data/maps/VermilionCity/scripts.pory"
	case MULTI_B_PRESSED, EventScript_CancelSail
# 226 "data/maps/VermilionCity/scripts.pory"
	end
# 227 "data/maps/VermilionCity/scripts.pory"

# 228 "data/maps/VermilionCity/scripts.pory"
@ Unreachable
# 229 "data/maps/VermilionCity/scripts.pory"
Vermilion_EventScript_Unused::
# 230 "data/maps/VermilionCity/scripts.pory"
	release
# 231 "data/maps/VermilionCity/scripts.pory"
	end
# 232 "data/maps/VermilionCity/scripts.pory"

# 233 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckTicketLeft::
# 234 "data/maps/VermilionCity/scripts.pory"
	lockall
# 235 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_CheckTicket
# 236 "data/maps/VermilionCity/scripts.pory"
	end
# 237 "data/maps/VermilionCity/scripts.pory"

# 238 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckTicketRight::
# 239 "data/maps/VermilionCity/scripts.pory"
	lockall
# 240 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_CheckTicket
# 241 "data/maps/VermilionCity/scripts.pory"
	end
# 242 "data/maps/VermilionCity/scripts.pory"

# 243 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ExitedTicketCheck::
# 244 "data/maps/VermilionCity/scripts.pory"
	lockall
# 245 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_VERMILION_CITY_TICKET_CHECK_TRIGGER, 0
# 246 "data/maps/VermilionCity/scripts.pory"
	releaseall
# 247 "data/maps/VermilionCity/scripts.pory"
	end
# 248 "data/maps/VermilionCity/scripts.pory"

# 249 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckTicket::
# 250 "data/maps/VermilionCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 251 "data/maps/VermilionCity/scripts.pory"
	applymovement LOCALID_VERMILION_FERRY_SAILOR, Common_Movement_WalkInPlaceFasterLeft
# 252 "data/maps/VermilionCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 253 "data/maps/VermilionCity/scripts.pory"
	waitmovement 0
# 254 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_VERMILION_CITY, 3, VermilionCity_EventScript_CheckSeagallopPresentTrigger
# 255 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_DoYouHaveATicket
# 256 "data/maps/VermilionCity/scripts.pory"
	goto_if_unset FLAG_GOT_SS_TICKET, VermilionCity_EventScript_DontHaveSSTicket
# 257 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_FlashedSSTicket
# 258 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_VERMILION_CITY_TICKET_CHECK_TRIGGER, 1
# 259 "data/maps/VermilionCity/scripts.pory"
	releaseall
# 260 "data/maps/VermilionCity/scripts.pory"
	end
# 261 "data/maps/VermilionCity/scripts.pory"

# 262 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_DontHaveSSTicket::
# 263 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_DontHaveNeededSSTicket
# 264 "data/maps/VermilionCity/scripts.pory"
	closemessage
# 265 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_WalkUpPier
# 266 "data/maps/VermilionCity/scripts.pory"
	end
# 267 "data/maps/VermilionCity/scripts.pory"

# 268 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckSeagallopPresentTrigger::
# 269 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 270 "data/maps/VermilionCity/scripts.pory"
	goto_if_set FLAG_BATTLE_FRONTIER_UNLOCKED, VermilionCity_EventScript_ChooseFrontierUnlocked
# 271 "data/maps/VermilionCity/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 5, VermilionCity_EventScript_ChooseSeagallopDestRainbowPass
# 272 "data/maps/VermilionCity/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 1, VermilionCity_EventScript_ChooseSeagallopDestTriPass
# 273 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_TheShipSetSail
# 274 "data/maps/VermilionCity/scripts.pory"
	closemessage
# 275 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_WalkUpPier
# 276 "data/maps/VermilionCity/scripts.pory"
	end
# 277 "data/maps/VermilionCity/scripts.pory"

# 278 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_Sailor::
# 279 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_SSAnneVisitsOnceAYear, MSGBOX_NPC
# 280 "data/maps/VermilionCity/scripts.pory"
	end
# 281 "data/maps/VermilionCity/scripts.pory"

# 282 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_OaksAide::
# 283 "data/maps/VermilionCity/scripts.pory"
	lock
# 284 "data/maps/VermilionCity/scripts.pory"
	faceplayer
# 285 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_TALKED_TO_OAKS_AIDE_IN_VERMILION
# 286 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_Route2AideHasPackageForYou
# 287 "data/maps/VermilionCity/scripts.pory"
	release
# 288 "data/maps/VermilionCity/scripts.pory"
	end
# 289 "data/maps/VermilionCity/scripts.pory"

# 290 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_OldMan2::
# 291 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_BuildingOnThisLand, MSGBOX_NPC
# 292 "data/maps/VermilionCity/scripts.pory"
	end
# 293 "data/maps/VermilionCity/scripts.pory"

# 294 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_Machop::
# 295 "data/maps/VermilionCity/scripts.pory"
	lock
# 296 "data/maps/VermilionCity/scripts.pory"
	faceplayer
# 297 "data/maps/VermilionCity/scripts.pory"
	waitse
# 298 "data/maps/VermilionCity/scripts.pory"
	playmoncry SPECIES_MACHOP, CRY_MODE_NORMAL
# 299 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_Machop
# 300 "data/maps/VermilionCity/scripts.pory"
	waitmoncry
# 301 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_MachopStompingLandFlat
# 302 "data/maps/VermilionCity/scripts.pory"
	release
# 303 "data/maps/VermilionCity/scripts.pory"
	end
# 304 "data/maps/VermilionCity/scripts.pory"

# 305 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CitySign::
# 306 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_CitySign, MSGBOX_SIGN
# 307 "data/maps/VermilionCity/scripts.pory"
	end
# 308 "data/maps/VermilionCity/scripts.pory"

# 309 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_SnorlaxNotice::
# 310 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_SnorlaxBlockingRoute12, MSGBOX_SIGN
# 311 "data/maps/VermilionCity/scripts.pory"
	end
# 312 "data/maps/VermilionCity/scripts.pory"

# 313 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_PokemonFanClubSign::
# 314 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_PokemonFanClubSign, MSGBOX_SIGN
# 315 "data/maps/VermilionCity/scripts.pory"
	end
# 316 "data/maps/VermilionCity/scripts.pory"

# 317 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_GymSign::
# 318 "data/maps/VermilionCity/scripts.pory"
	lockall
# 319 "data/maps/VermilionCity/scripts.pory"
	famechecker FAMECHECKER_LTSURGE, 0
# 320 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_GymSign
# 321 "data/maps/VermilionCity/scripts.pory"
	releaseall
# 322 "data/maps/VermilionCity/scripts.pory"
	end
# 323 "data/maps/VermilionCity/scripts.pory"

# 324 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_HarborSign::
# 325 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_VermilionHarbor, MSGBOX_SIGN
# 326 "data/maps/VermilionCity/scripts.pory"
	end
