# 1 "data/maps/VermilionCity/scripts.pory"

# 2 "data/maps/VermilionCity/scripts.pory"
VermilionCity_MapScripts::
# 3 "data/maps/VermilionCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, VermilionCity_OnTransition
# 4 "data/maps/VermilionCity/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, VermilionCity_OnFrame
# 5 "data/maps/VermilionCity/scripts.pory"
	.byte 0
# 6 "data/maps/VermilionCity/scripts.pory"

# 7 "data/maps/VermilionCity/scripts.pory"
VermilionCity_OnFrame::
# 8 "data/maps/VermilionCity/scripts.pory"
	map_script_2 VAR_MAP_SCENE_VERMILION_CITY, 2, VermilionCity_EventScript_ExitSSAnne
# 9 "data/maps/VermilionCity/scripts.pory"
	.2byte 0
# 10 "data/maps/VermilionCity/scripts.pory"

# 11 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ExitSSAnne::
# 12 "data/maps/VermilionCity/scripts.pory"
	lockall
# 13 "data/maps/VermilionCity/scripts.pory"
	applymovement LOCALID_PLAYER, VermilionCity_Movement_ExitSSAnne
# 14 "data/maps/VermilionCity/scripts.pory"
	waitmovement 0
# 15 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_MAP_SCENE_VERMILION_CITY, 3
# 16 "data/maps/VermilionCity/scripts.pory"
	releaseall
# 17 "data/maps/VermilionCity/scripts.pory"
	end
# 18 "data/maps/VermilionCity/scripts.pory"

# 19 "data/maps/VermilionCity/scripts.pory"
VermilionCity_Movement_ExitSSAnne::
# 20 "data/maps/VermilionCity/scripts.pory"
	walk_up
# 21 "data/maps/VermilionCity/scripts.pory"
	walk_up
# 22 "data/maps/VermilionCity/scripts.pory"
	step_end
# 23 "data/maps/VermilionCity/scripts.pory"

# 24 "data/maps/VermilionCity/scripts.pory"
VermilionCity_OnTransition::
# 25 "data/maps/VermilionCity/scripts.pory"
	setworldmapflag FLAG_WORLD_MAP_VERMILION_CITY
# 26 "data/maps/VermilionCity/scripts.pory"
	call_if_set FLAG_TALKED_TO_OAKS_AIDE_IN_VERMILION, VermilionCity_EventScript_HideOaksAide
# 27 "data/maps/VermilionCity/scripts.pory"
	end
# 28 "data/maps/VermilionCity/scripts.pory"

# 29 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_HideOaksAide::
# 30 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_HIDE_VERMILION_CITY_OAKS_AIDE
# 31 "data/maps/VermilionCity/scripts.pory"
	return
# 32 "data/maps/VermilionCity/scripts.pory"

# 33 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_Woman::
# 34 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_GrimerMultipliesInSludge, MSGBOX_NPC
# 35 "data/maps/VermilionCity/scripts.pory"
	end
# 36 "data/maps/VermilionCity/scripts.pory"

# 37 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_OldMan1::
# 38 "data/maps/VermilionCity/scripts.pory"
	lock
# 39 "data/maps/VermilionCity/scripts.pory"
	faceplayer
# 40 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_VERMILION_CITY, 3, VermilionCity_EventScript_OldMan1SSAnneLeft
# 41 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_DidYouSeeSSAnneInHarbor
# 42 "data/maps/VermilionCity/scripts.pory"
	release
# 43 "data/maps/VermilionCity/scripts.pory"
	end
# 44 "data/maps/VermilionCity/scripts.pory"

# 45 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_OldMan1SSAnneLeft::
# 46 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_SSAnneHasDepartedForYear
# 47 "data/maps/VermilionCity/scripts.pory"
	release
# 48 "data/maps/VermilionCity/scripts.pory"
	end
# 49 "data/maps/VermilionCity/scripts.pory"

# 50 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_FerrySailor::
# 51 "data/maps/VermilionCity/scripts.pory"
	lock
# 52 "data/maps/VermilionCity/scripts.pory"
	faceplayer
# 53 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_VERMILION_CITY, 3, VermilionCity_EventScript_CheckSeagallopPresent
# 54 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_WelcomeToTheSSAnne
# 55 "data/maps/VermilionCity/scripts.pory"
	release
# 56 "data/maps/VermilionCity/scripts.pory"
	end
# 57 "data/maps/VermilionCity/scripts.pory"

# 58 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckHasMysticTicket::
# 59 "data/maps/VermilionCity/scripts.pory"
	goto_if_unset FLAG_ENABLE_SHIP_NAVEL_ROCK, EventScript_SetResultFalse
# 60 "data/maps/VermilionCity/scripts.pory"
	checkitem ITEM_MYSTIC_TICKET
# 61 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, EventScript_SetResultFalse
# 62 "data/maps/VermilionCity/scripts.pory"
	goto EventScript_SetResultTrue
# 63 "data/maps/VermilionCity/scripts.pory"
	end
# 64 "data/maps/VermilionCity/scripts.pory"

# 65 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckHasAuroraTicket::
# 66 "data/maps/VermilionCity/scripts.pory"
	goto_if_unset FLAG_ENABLE_SHIP_BIRTH_ISLAND, EventScript_SetResultFalse
# 67 "data/maps/VermilionCity/scripts.pory"
	checkitem ITEM_AURORA_TICKET
# 68 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, EventScript_SetResultFalse
# 69 "data/maps/VermilionCity/scripts.pory"
	goto EventScript_SetResultTrue
# 70 "data/maps/VermilionCity/scripts.pory"
	end
# 71 "data/maps/VermilionCity/scripts.pory"

# 72 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckSeagallopPresent::
# 73 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 74 "data/maps/VermilionCity/scripts.pory"
	goto_if_set FLAG_BATTLE_FRONTIER_UNLOCKED, VermilionCity_EventScript_ChooseFrontierUnlocked
# 75 "data/maps/VermilionCity/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 5, VermilionCity_EventScript_ChooseSeagallopDestRainbowPass
# 76 "data/maps/VermilionCity/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 1, VermilionCity_EventScript_ChooseSeagallopDestTriPass
# 77 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_TheShipSetSail
# 78 "data/maps/VermilionCity/scripts.pory"
	release
# 79 "data/maps/VermilionCity/scripts.pory"
	end
# 80 "data/maps/VermilionCity/scripts.pory"

# 81 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ChooseFrontierUnlocked::
# 82 "data/maps/VermilionCity/scripts.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 83 "data/maps/VermilionCity/scripts.pory"
	special QuestLog_CutRecording
# 84 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_BoardSeagallopFerry
# 85 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 86 "data/maps/VermilionCity/scripts.pory"
	dynmultipush Seagallop_SeviiIslands, 0
# 87 "data/maps/VermilionCity/scripts.pory"
	dynmultipush Seagallop_BattleFrontier, 1
# 88 "data/maps/VermilionCity/scripts.pory"
	call VermilionCity_EventScript_CheckHasMysticTicket
# 89 "data/maps/VermilionCity/scripts.pory"
	call_if_eq VAR_RESULT, TRUE, VermilionCity_AddMysticTicket
# 90 "data/maps/VermilionCity/scripts.pory"
	call VermilionCity_EventScript_CheckHasAuroraTicket
# 91 "data/maps/VermilionCity/scripts.pory"
	call_if_eq VAR_RESULT, TRUE, VermilionCity_AddAuroraTicket
# 92 "data/maps/VermilionCity/scripts.pory"
	dynmultipush Seagallop_Cancel, 4
# 93 "data/maps/VermilionCity/scripts.pory"
	dynmultistack 0, 0, FALSE, 5, FALSE, 0, NULL
# 94 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 95 "data/maps/VermilionCity/scripts.pory"
	case 0, EventScript_SeviiDestinationsPage1
# 96 "data/maps/VermilionCity/scripts.pory"
	case 1, EventScript_SailToBattleFrontier
# 97 "data/maps/VermilionCity/scripts.pory"
	case 2, EventScript_SailToNavelRock
# 98 "data/maps/VermilionCity/scripts.pory"
	case 3, EventScript_SailToBirthIsland
# 99 "data/maps/VermilionCity/scripts.pory"
	case 4, EventScript_CancelSail
# 100 "data/maps/VermilionCity/scripts.pory"
	case MULTI_B_PRESSED, EventScript_CancelSail
# 101 "data/maps/VermilionCity/scripts.pory"
	end
# 102 "data/maps/VermilionCity/scripts.pory"

# 103 "data/maps/VermilionCity/scripts.pory"
VermilionCity_AddMysticTicket::
# 104 "data/maps/VermilionCity/scripts.pory"
	dynmultipush Seagallop_NavelRock, 2
# 105 "data/maps/VermilionCity/scripts.pory"
	return
# 106 "data/maps/VermilionCity/scripts.pory"

# 107 "data/maps/VermilionCity/scripts.pory"
VermilionCity_AddAuroraTicket::
# 108 "data/maps/VermilionCity/scripts.pory"
	dynmultipush Seagallop_BirthIsland, 3
# 109 "data/maps/VermilionCity/scripts.pory"
	return
# 110 "data/maps/VermilionCity/scripts.pory"

# 111 "data/maps/VermilionCity/scripts.pory"
Seagallop_SeviiIslands::
# 112 "data/maps/VermilionCity/scripts.pory"
	.string "SEVII ISLANDS$"
# 113 "data/maps/VermilionCity/scripts.pory"

# 114 "data/maps/VermilionCity/scripts.pory"
Seagallop_NavelRock::
# 115 "data/maps/VermilionCity/scripts.pory"
	.string "NAVEL ROCK$"
# 116 "data/maps/VermilionCity/scripts.pory"

# 117 "data/maps/VermilionCity/scripts.pory"
Seagallop_BirthIsland::
# 118 "data/maps/VermilionCity/scripts.pory"
	.string "BIRTH ISLAND$"
# 119 "data/maps/VermilionCity/scripts.pory"

# 120 "data/maps/VermilionCity/scripts.pory"
Seagallop_BattleFrontier::
# 121 "data/maps/VermilionCity/scripts.pory"
	.string "BATTLE FRONTIER$"
# 122 "data/maps/VermilionCity/scripts.pory"

# 123 "data/maps/VermilionCity/scripts.pory"
Seagallop_Cancel::
# 124 "data/maps/VermilionCity/scripts.pory"
	.string "CANCEL$"
# 125 "data/maps/VermilionCity/scripts.pory"

# 126 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ChooseSeagallopDestRainbowPass::
# 127 "data/maps/VermilionCity/scripts.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 128 "data/maps/VermilionCity/scripts.pory"
	special QuestLog_CutRecording
# 129 "data/maps/VermilionCity/scripts.pory"
	call VermilionCity_EventScript_CheckHasMysticTicket
# 130 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, VermilionCity_EventScript_HasMysticTicket
# 131 "data/maps/VermilionCity/scripts.pory"
	call VermilionCity_EventScript_CheckHasAuroraTicket
# 132 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, VermilionCity_EventScript_HasAuroraTicket
# 133 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 134 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_BoardSeagallopRainbowPass
# 135 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 136 "data/maps/VermilionCity/scripts.pory"
	goto EventScript_SeviiDestinationsPage1
# 137 "data/maps/VermilionCity/scripts.pory"
	end
# 138 "data/maps/VermilionCity/scripts.pory"

# 139 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_HasMysticTicket::
# 140 "data/maps/VermilionCity/scripts.pory"
	call VermilionCity_EventScript_CheckHasAuroraTicket
# 141 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, VermilionCity_EventScript_HasMysticAndAuroraTickets
# 142 "data/maps/VermilionCity/scripts.pory"
	call_if_unset FLAG_SHOWN_MYSTIC_TICKET, VermilionCity_EventScript_ShowMysticTicket
# 143 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_BoardSeagallopFerry
# 144 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 145 "data/maps/VermilionCity/scripts.pory"
	multichoice 17, 6, MULTI_SEVII_NAVEL, FALSE
# 146 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 147 "data/maps/VermilionCity/scripts.pory"
	case 0, EventScript_SeviiDestinationsPage1
# 148 "data/maps/VermilionCity/scripts.pory"
	case 1, EventScript_SailToNavelRock
# 149 "data/maps/VermilionCity/scripts.pory"
	case 2, EventScript_CancelSail
# 150 "data/maps/VermilionCity/scripts.pory"
	case MULTI_B_PRESSED, EventScript_CancelSail
# 151 "data/maps/VermilionCity/scripts.pory"
	end
# 152 "data/maps/VermilionCity/scripts.pory"

# 153 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ShowMysticTicket::
# 154 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_SHOWN_MYSTIC_TICKET
# 155 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_OhMysticTicketTakeYouToNavelRock
# 156 "data/maps/VermilionCity/scripts.pory"
	return
# 157 "data/maps/VermilionCity/scripts.pory"

# 158 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_HasAuroraTicket::
# 159 "data/maps/VermilionCity/scripts.pory"
	call_if_unset FLAG_SHOWN_AURORA_TICKET, VermilionCity_EventScript_ShowAuroraTicket
# 160 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_BoardSeagallopFerry
# 161 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 162 "data/maps/VermilionCity/scripts.pory"
	multichoice 13, 6, MULTI_SEVII_BIRTH, FALSE
# 163 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 164 "data/maps/VermilionCity/scripts.pory"
	case 0, EventScript_SeviiDestinationsPage1
# 165 "data/maps/VermilionCity/scripts.pory"
	case 1, EventScript_SailToBirthIsland
# 166 "data/maps/VermilionCity/scripts.pory"
	case 2, EventScript_CancelSail
# 167 "data/maps/VermilionCity/scripts.pory"
	case MULTI_B_PRESSED, EventScript_CancelSail
# 168 "data/maps/VermilionCity/scripts.pory"
	end
# 169 "data/maps/VermilionCity/scripts.pory"

# 170 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ShowAuroraTicket::
# 171 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_SHOWN_AURORA_TICKET
# 172 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_OhAuroraTicketTakeYouToBirthIsland
# 173 "data/maps/VermilionCity/scripts.pory"
	return
# 174 "data/maps/VermilionCity/scripts.pory"

# 175 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_HasMysticAndAuroraTickets::
# 176 "data/maps/VermilionCity/scripts.pory"
	call_if_unset FLAG_SHOWN_MYSTIC_TICKET, VermilionCity_EventScript_ShowMysticTicket
# 177 "data/maps/VermilionCity/scripts.pory"
	call_if_unset FLAG_SHOWN_AURORA_TICKET, VermilionCity_EventScript_ShowAuroraTicket
# 178 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_BoardSeagallopFerry
# 179 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 180 "data/maps/VermilionCity/scripts.pory"
	multichoice 13, 5, MULTI_SEVII_NAVEL_BIRTH, FALSE
# 181 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 182 "data/maps/VermilionCity/scripts.pory"
	case 0, EventScript_SeviiDestinationsPage1
# 183 "data/maps/VermilionCity/scripts.pory"
	case 1, EventScript_SailToNavelRock
# 184 "data/maps/VermilionCity/scripts.pory"
	case 2, EventScript_SailToBirthIsland
# 185 "data/maps/VermilionCity/scripts.pory"
	case 3, EventScript_CancelSail
# 186 "data/maps/VermilionCity/scripts.pory"
	case MULTI_B_PRESSED, EventScript_CancelSail
# 187 "data/maps/VermilionCity/scripts.pory"
	end
# 188 "data/maps/VermilionCity/scripts.pory"

# 189 "data/maps/VermilionCity/scripts.pory"
EventScript_SailToNavelRock::
# 190 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_Seagallop10Departing
# 191 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 192 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8006, SEAGALLOP_NAVEL_ROCK
# 193 "data/maps/VermilionCity/scripts.pory"
	goto EventScript_SetSail
# 194 "data/maps/VermilionCity/scripts.pory"
	end
# 195 "data/maps/VermilionCity/scripts.pory"

# 196 "data/maps/VermilionCity/scripts.pory"
EventScript_SailToBirthIsland::
# 197 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_Seagallop12Departing
# 198 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 199 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8006, SEAGALLOP_BIRTH_ISLAND
# 200 "data/maps/VermilionCity/scripts.pory"
	goto EventScript_SetSail
# 201 "data/maps/VermilionCity/scripts.pory"
	end
# 202 "data/maps/VermilionCity/scripts.pory"

# 203 "data/maps/VermilionCity/scripts.pory"
EventScript_SailToBattleFrontier::
# 204 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_Seagallop12Departing
# 205 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 206 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8006, SEAGALLOP_BATTLE_FRONTIER
# 207 "data/maps/VermilionCity/scripts.pory"
	goto EventScript_SetSail
# 208 "data/maps/VermilionCity/scripts.pory"
	end
# 209 "data/maps/VermilionCity/scripts.pory"

# 210 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ChooseSeagallopDestTriPass::
# 211 "data/maps/VermilionCity/scripts.pory"
	message VermilionCity_Text_BoardSeagallopTriPass
# 212 "data/maps/VermilionCity/scripts.pory"
	waitmessage
# 213 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 214 "data/maps/VermilionCity/scripts.pory"
	multichoice 19, 5, MULTI_SEAGALLOP_123, FALSE
# 215 "data/maps/VermilionCity/scripts.pory"
	switch VAR_RESULT
# 216 "data/maps/VermilionCity/scripts.pory"
	case 0, EventScript_SailToOneIsland2
# 217 "data/maps/VermilionCity/scripts.pory"
	case 1, EventScript_SailToTwoIsland2
# 218 "data/maps/VermilionCity/scripts.pory"
	case 2, EventScript_SailToThreeIsland2
# 219 "data/maps/VermilionCity/scripts.pory"
	case 3, EventScript_CancelSail
# 220 "data/maps/VermilionCity/scripts.pory"
	case MULTI_B_PRESSED, EventScript_CancelSail
# 221 "data/maps/VermilionCity/scripts.pory"
	end
# 222 "data/maps/VermilionCity/scripts.pory"

# 223 "data/maps/VermilionCity/scripts.pory"
@ Unreachable
# 224 "data/maps/VermilionCity/scripts.pory"
Vermilion_EventScript_Unused::
# 225 "data/maps/VermilionCity/scripts.pory"
	release
# 226 "data/maps/VermilionCity/scripts.pory"
	end
# 227 "data/maps/VermilionCity/scripts.pory"

# 228 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckTicketLeft::
# 229 "data/maps/VermilionCity/scripts.pory"
	lockall
# 230 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_CheckTicket
# 231 "data/maps/VermilionCity/scripts.pory"
	end
# 232 "data/maps/VermilionCity/scripts.pory"

# 233 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckTicketRight::
# 234 "data/maps/VermilionCity/scripts.pory"
	lockall
# 235 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_CheckTicket
# 236 "data/maps/VermilionCity/scripts.pory"
	end
# 237 "data/maps/VermilionCity/scripts.pory"

# 238 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_ExitedTicketCheck::
# 239 "data/maps/VermilionCity/scripts.pory"
	lockall
# 240 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_VERMILION_CITY_TICKET_CHECK_TRIGGER, 0
# 241 "data/maps/VermilionCity/scripts.pory"
	releaseall
# 242 "data/maps/VermilionCity/scripts.pory"
	end
# 243 "data/maps/VermilionCity/scripts.pory"

# 244 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckTicket::
# 245 "data/maps/VermilionCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 246 "data/maps/VermilionCity/scripts.pory"
	applymovement LOCALID_VERMILION_FERRY_SAILOR, Common_Movement_WalkInPlaceFasterLeft
# 247 "data/maps/VermilionCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 248 "data/maps/VermilionCity/scripts.pory"
	waitmovement 0
# 249 "data/maps/VermilionCity/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_VERMILION_CITY, 3, VermilionCity_EventScript_CheckSeagallopPresentTrigger
# 250 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_DoYouHaveATicket
# 251 "data/maps/VermilionCity/scripts.pory"
	goto_if_unset FLAG_GOT_SS_TICKET, VermilionCity_EventScript_DontHaveSSTicket
# 252 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_FlashedSSTicket
# 253 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_VERMILION_CITY_TICKET_CHECK_TRIGGER, 1
# 254 "data/maps/VermilionCity/scripts.pory"
	releaseall
# 255 "data/maps/VermilionCity/scripts.pory"
	end
# 256 "data/maps/VermilionCity/scripts.pory"

# 257 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_DontHaveSSTicket::
# 258 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_DontHaveNeededSSTicket
# 259 "data/maps/VermilionCity/scripts.pory"
	closemessage
# 260 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_WalkUpPier
# 261 "data/maps/VermilionCity/scripts.pory"
	end
# 262 "data/maps/VermilionCity/scripts.pory"

# 263 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CheckSeagallopPresentTrigger::
# 264 "data/maps/VermilionCity/scripts.pory"
	setvar VAR_0x8004, SEAGALLOP_VERMILION_CITY
# 265 "data/maps/VermilionCity/scripts.pory"
	goto_if_set FLAG_BATTLE_FRONTIER_UNLOCKED, VermilionCity_EventScript_ChooseFrontierUnlocked
# 266 "data/maps/VermilionCity/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 5, VermilionCity_EventScript_ChooseSeagallopDestRainbowPass
# 267 "data/maps/VermilionCity/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_ONE_ISLAND_POKEMON_CENTER_1F, 1, VermilionCity_EventScript_ChooseSeagallopDestTriPass
# 268 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_TheShipSetSail
# 269 "data/maps/VermilionCity/scripts.pory"
	closemessage
# 270 "data/maps/VermilionCity/scripts.pory"
	goto VermilionCity_EventScript_WalkUpPier
# 271 "data/maps/VermilionCity/scripts.pory"
	end
# 272 "data/maps/VermilionCity/scripts.pory"

# 273 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_Sailor::
# 274 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_SSAnneVisitsOnceAYear, MSGBOX_NPC
# 275 "data/maps/VermilionCity/scripts.pory"
	end
# 276 "data/maps/VermilionCity/scripts.pory"

# 277 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_OaksAide::
# 278 "data/maps/VermilionCity/scripts.pory"
	lock
# 279 "data/maps/VermilionCity/scripts.pory"
	faceplayer
# 280 "data/maps/VermilionCity/scripts.pory"
	setflag FLAG_TALKED_TO_OAKS_AIDE_IN_VERMILION
# 281 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_Route2AideHasPackageForYou
# 282 "data/maps/VermilionCity/scripts.pory"
	release
# 283 "data/maps/VermilionCity/scripts.pory"
	end
# 284 "data/maps/VermilionCity/scripts.pory"

# 285 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_OldMan2::
# 286 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_BuildingOnThisLand, MSGBOX_NPC
# 287 "data/maps/VermilionCity/scripts.pory"
	end
# 288 "data/maps/VermilionCity/scripts.pory"

# 289 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_Machop::
# 290 "data/maps/VermilionCity/scripts.pory"
	lock
# 291 "data/maps/VermilionCity/scripts.pory"
	faceplayer
# 292 "data/maps/VermilionCity/scripts.pory"
	waitse
# 293 "data/maps/VermilionCity/scripts.pory"
	playmoncry SPECIES_MACHOP, CRY_MODE_NORMAL
# 294 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_Machop
# 295 "data/maps/VermilionCity/scripts.pory"
	waitmoncry
# 296 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_MachopStompingLandFlat
# 297 "data/maps/VermilionCity/scripts.pory"
	release
# 298 "data/maps/VermilionCity/scripts.pory"
	end
# 299 "data/maps/VermilionCity/scripts.pory"

# 300 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_CitySign::
# 301 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_CitySign, MSGBOX_SIGN
# 302 "data/maps/VermilionCity/scripts.pory"
	end
# 303 "data/maps/VermilionCity/scripts.pory"

# 304 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_SnorlaxNotice::
# 305 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_SnorlaxBlockingRoute12, MSGBOX_SIGN
# 306 "data/maps/VermilionCity/scripts.pory"
	end
# 307 "data/maps/VermilionCity/scripts.pory"

# 308 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_PokemonFanClubSign::
# 309 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_PokemonFanClubSign, MSGBOX_SIGN
# 310 "data/maps/VermilionCity/scripts.pory"
	end
# 311 "data/maps/VermilionCity/scripts.pory"

# 312 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_GymSign::
# 313 "data/maps/VermilionCity/scripts.pory"
	lockall
# 314 "data/maps/VermilionCity/scripts.pory"
	famechecker FAMECHECKER_LTSURGE, 0
# 315 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_GymSign
# 316 "data/maps/VermilionCity/scripts.pory"
	releaseall
# 317 "data/maps/VermilionCity/scripts.pory"
	end
# 318 "data/maps/VermilionCity/scripts.pory"

# 319 "data/maps/VermilionCity/scripts.pory"
VermilionCity_EventScript_HarborSign::
# 320 "data/maps/VermilionCity/scripts.pory"
	msgbox VermilionCity_Text_VermilionHarbor, MSGBOX_SIGN
# 321 "data/maps/VermilionCity/scripts.pory"
	end
