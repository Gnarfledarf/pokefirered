# 1 "data/maps/PalletTown/scripts.pory"

# 2 "data/maps/PalletTown/scripts.pory"
.equ SIGN_LADY_READY, VAR_TEMP_2
# 3 "data/maps/PalletTown/scripts.pory"

# 4 "data/maps/PalletTown/scripts.pory"
PalletTown_MapScripts::
# 5 "data/maps/PalletTown/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, PalletTown_OnLoad
# 6 "data/maps/PalletTown/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, PalletTown_OnTransition
# 7 "data/maps/PalletTown/scripts.pory"
	map_script MAP_SCRIPT_ON_FRAME_TABLE, PalletTown_OnFrame
# 8 "data/maps/PalletTown/scripts.pory"
	.byte 0
# 9 "data/maps/PalletTown/scripts.pory"

# 10 "data/maps/PalletTown/scripts.pory"
PalletTown_OnLoad::
# 11 "data/maps/PalletTown/scripts.pory"
	special SetRoofBirds
# 12 "data/maps/PalletTown/scripts.pory"
	end
# 13 "data/maps/PalletTown/scripts.pory"

# 14 "data/maps/PalletTown/scripts.pory"
PalletTown_OnTransition::
# 15 "data/maps/PalletTown/scripts.pory"
	setworldmapflag FLAG_WORLD_MAP_PALLET_TOWN
# 16 "data/maps/PalletTown/scripts.pory"
	call_if_set FLAG_PALLET_LADY_NOT_BLOCKING_SIGN, PalletTown_EventScript_TryReadySignLady
# 17 "data/maps/PalletTown/scripts.pory"
	call_if_eq VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 0, PalletTown_EventScript_SetSignLadyPos
# 18 "data/maps/PalletTown/scripts.pory"
	call_if_eq VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1, PalletTown_EventScript_SetSignLadyDone
# 19 "data/maps/PalletTown/scripts.pory"
	end
# 20 "data/maps/PalletTown/scripts.pory"

# 21 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_TryReadySignLady::
# 22 "data/maps/PalletTown/scripts.pory"
	goto_if_unset FLAG_OPENED_START_MENU, EventScript_Return
# 23 "data/maps/PalletTown/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1, EventScript_Return
# 24 "data/maps/PalletTown/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1
# 25 "data/maps/PalletTown/scripts.pory"
	return
# 26 "data/maps/PalletTown/scripts.pory"

# 27 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_SetSignLadyDone::
# 28 "data/maps/PalletTown/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 2
# 29 "data/maps/PalletTown/scripts.pory"
	return
# 30 "data/maps/PalletTown/scripts.pory"

# 31 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_SetSignLadyPos::
# 32 "data/maps/PalletTown/scripts.pory"
	goto_if_set FLAG_PALLET_LADY_NOT_BLOCKING_SIGN, PalletTown_EventScript_MoveSignLadyToRouteEntrance
# 33 "data/maps/PalletTown/scripts.pory"
	setobjectxyperm LOCALID_PALLET_SIGN_LADY, 5, 15
# 34 "data/maps/PalletTown/scripts.pory"
	setobjectmovementtype LOCALID_PALLET_SIGN_LADY, MOVEMENT_TYPE_FACE_UP
# 35 "data/maps/PalletTown/scripts.pory"
	return
# 36 "data/maps/PalletTown/scripts.pory"

# 37 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_MoveSignLadyToRouteEntrance::
# 38 "data/maps/PalletTown/scripts.pory"
	setobjectxyperm LOCALID_PALLET_SIGN_LADY, 12, 2
# 39 "data/maps/PalletTown/scripts.pory"
	setobjectmovementtype LOCALID_PALLET_SIGN_LADY, MOVEMENT_TYPE_FACE_DOWN
# 40 "data/maps/PalletTown/scripts.pory"
	setvar SIGN_LADY_READY, TRUE
# 41 "data/maps/PalletTown/scripts.pory"
	return
# 42 "data/maps/PalletTown/scripts.pory"

# 43 "data/maps/PalletTown/scripts.pory"
PalletTown_OnFrame::
# 44 "data/maps/PalletTown/scripts.pory"
	map_script_2 VAR_MAP_SCENE_PALLET_TOWN_OAK, 2, PalletTown_EventScript_OakRatingScene
# 45 "data/maps/PalletTown/scripts.pory"
	.2byte 0
# 46 "data/maps/PalletTown/scripts.pory"

# 47 "data/maps/PalletTown/scripts.pory"
@ Oak approaches player after exiting their house post Elite Four to check if they should receieve the National Dex
# 48 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_OakRatingScene::
# 49 "data/maps/PalletTown/scripts.pory"
	lockall
# 50 "data/maps/PalletTown/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 51 "data/maps/PalletTown/scripts.pory"
	setobjectxyperm LOCALID_PALLET_PROF_OAK, 14, 14
# 52 "data/maps/PalletTown/scripts.pory"
	setobjectmovementtype LOCALID_PALLET_PROF_OAK, MOVEMENT_TYPE_FACE_LEFT
# 53 "data/maps/PalletTown/scripts.pory"
	addobject LOCALID_PALLET_PROF_OAK
# 54 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PALLET_PROF_OAK, PalletTown_Movement_OakWalkToPlayersDoor
# 55 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 56 "data/maps/PalletTown/scripts.pory"
	goto_if_unset FLAG_WORLD_MAP_ONE_ISLAND, PalletTown_EventScript_NotBeenToOneIslandYet
# 57 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_OakLetMeSeePokedex
# 58 "data/maps/PalletTown/scripts.pory"
	setvar VAR_0x8004, 0
# 59 "data/maps/PalletTown/scripts.pory"
	specialvar VAR_RESULT, GetPokedexCount
# 60 "data/maps/PalletTown/scripts.pory"
	copyvar VAR_0x8008, VAR_0x8005
# 61 "data/maps/PalletTown/scripts.pory"
	copyvar VAR_0x8009, VAR_0x8006
# 62 "data/maps/PalletTown/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_0x8008
# 63 "data/maps/PalletTown/scripts.pory"
	buffernumberstring STR_VAR_2, VAR_0x8009
# 64 "data/maps/PalletTown/scripts.pory"
	goto_if_lt VAR_0x8009, 60, PalletTown_EventScript_NotEnoughMonsForNationalDex
# 65 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_CaughtXImpressiveFollowMe
# 66 "data/maps/PalletTown/scripts.pory"
	closemessage
# 67 "data/maps/PalletTown/scripts.pory"
	playbgm MUS_FOLLOW_ME, 0
# 68 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PLAYER, PalletTown_Movement_PlayerWalkToLabFromHouse
# 69 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PALLET_PROF_OAK, PalletTown_Movement_OakWalkToLabFromHouse
# 70 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 71 "data/maps/PalletTown/scripts.pory"
	opendoor 16, 13
# 72 "data/maps/PalletTown/scripts.pory"
	waitdooranim
# 73 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PALLET_PROF_OAK, PalletTown_Movement_OakEnterLab
# 74 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PLAYER, PalletTown_Movement_PlayerEnterLab
# 75 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 76 "data/maps/PalletTown/scripts.pory"
	closedoor 16, 13
# 77 "data/maps/PalletTown/scripts.pory"
	waitdooranim
# 78 "data/maps/PalletTown/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 7
# 79 "data/maps/PalletTown/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_OAK, 3
# 80 "data/maps/PalletTown/scripts.pory"
	setflag FLAG_HIDE_OAK_IN_PALLET_TOWN
# 81 "data/maps/PalletTown/scripts.pory"
	warp MAP_PALLET_TOWN_PROFESSOR_OAKS_LAB, 6, 12
# 82 "data/maps/PalletTown/scripts.pory"
	waitstate
# 83 "data/maps/PalletTown/scripts.pory"
	releaseall
# 84 "data/maps/PalletTown/scripts.pory"
	end
# 85 "data/maps/PalletTown/scripts.pory"

# 86 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_EndOakRatingScene::
# 87 "data/maps/PalletTown/scripts.pory"
	closemessage
# 88 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PALLET_PROF_OAK, PalletTown_Movement_OakExit
# 89 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 90 "data/maps/PalletTown/scripts.pory"
	removeobject LOCALID_PALLET_PROF_OAK
# 91 "data/maps/PalletTown/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_OAK, 3
# 92 "data/maps/PalletTown/scripts.pory"
	releaseall
# 93 "data/maps/PalletTown/scripts.pory"
	end
# 94 "data/maps/PalletTown/scripts.pory"

# 95 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_NotEnoughMonsForNationalDex::
# 96 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_CaughtXPuttingInHonestEffort
# 97 "data/maps/PalletTown/scripts.pory"
	goto PalletTown_EventScript_EndOakRatingScene
# 98 "data/maps/PalletTown/scripts.pory"
	end
# 99 "data/maps/PalletTown/scripts.pory"

# 100 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_NotBeenToOneIslandYet::
# 101 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_OakYouEnjoyingTraveling
# 102 "data/maps/PalletTown/scripts.pory"
	goto PalletTown_EventScript_EndOakRatingScene
# 103 "data/maps/PalletTown/scripts.pory"
	end
# 104 "data/maps/PalletTown/scripts.pory"

# 105 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_OakWalkToPlayersDoor::
# 106 "data/maps/PalletTown/scripts.pory"
	walk_left
# 107 "data/maps/PalletTown/scripts.pory"
	walk_left
# 108 "data/maps/PalletTown/scripts.pory"
	walk_left
# 109 "data/maps/PalletTown/scripts.pory"
	walk_up
# 110 "data/maps/PalletTown/scripts.pory"
	walk_up
# 111 "data/maps/PalletTown/scripts.pory"
	walk_up
# 112 "data/maps/PalletTown/scripts.pory"
	walk_up
# 113 "data/maps/PalletTown/scripts.pory"
	walk_up
# 114 "data/maps/PalletTown/scripts.pory"
	walk_left
# 115 "data/maps/PalletTown/scripts.pory"
	walk_left
# 116 "data/maps/PalletTown/scripts.pory"
	walk_left
# 117 "data/maps/PalletTown/scripts.pory"
	walk_left
# 118 "data/maps/PalletTown/scripts.pory"
	walk_left
# 119 "data/maps/PalletTown/scripts.pory"
	walk_in_place_faster_up
# 120 "data/maps/PalletTown/scripts.pory"
	step_end
# 121 "data/maps/PalletTown/scripts.pory"

# 122 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_OakExit::
# 123 "data/maps/PalletTown/scripts.pory"
	walk_right
# 124 "data/maps/PalletTown/scripts.pory"
	walk_right
# 125 "data/maps/PalletTown/scripts.pory"
	walk_right
# 126 "data/maps/PalletTown/scripts.pory"
	walk_right
# 127 "data/maps/PalletTown/scripts.pory"
	walk_right
# 128 "data/maps/PalletTown/scripts.pory"
	walk_down
# 129 "data/maps/PalletTown/scripts.pory"
	walk_down
# 130 "data/maps/PalletTown/scripts.pory"
	walk_down
# 131 "data/maps/PalletTown/scripts.pory"
	walk_down
# 132 "data/maps/PalletTown/scripts.pory"
	walk_down
# 133 "data/maps/PalletTown/scripts.pory"
	walk_right
# 134 "data/maps/PalletTown/scripts.pory"
	walk_right
# 135 "data/maps/PalletTown/scripts.pory"
	walk_right
# 136 "data/maps/PalletTown/scripts.pory"
	step_end
# 137 "data/maps/PalletTown/scripts.pory"

# 138 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_OakWalkToLabFromHouse::
# 139 "data/maps/PalletTown/scripts.pory"
	walk_right
# 140 "data/maps/PalletTown/scripts.pory"
	walk_right
# 141 "data/maps/PalletTown/scripts.pory"
	walk_right
# 142 "data/maps/PalletTown/scripts.pory"
	walk_right
# 143 "data/maps/PalletTown/scripts.pory"
	walk_right
# 144 "data/maps/PalletTown/scripts.pory"
	walk_down
# 145 "data/maps/PalletTown/scripts.pory"
	walk_down
# 146 "data/maps/PalletTown/scripts.pory"
	walk_down
# 147 "data/maps/PalletTown/scripts.pory"
	walk_down
# 148 "data/maps/PalletTown/scripts.pory"
	walk_down
# 149 "data/maps/PalletTown/scripts.pory"
	walk_right
# 150 "data/maps/PalletTown/scripts.pory"
	walk_right
# 151 "data/maps/PalletTown/scripts.pory"
	walk_right
# 152 "data/maps/PalletTown/scripts.pory"
	walk_right
# 153 "data/maps/PalletTown/scripts.pory"
	walk_right
# 154 "data/maps/PalletTown/scripts.pory"
	walk_in_place_faster_up
# 155 "data/maps/PalletTown/scripts.pory"
	step_end
# 156 "data/maps/PalletTown/scripts.pory"

# 157 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_PlayerWalkToLabFromHouse::
# 158 "data/maps/PalletTown/scripts.pory"
	walk_down
# 159 "data/maps/PalletTown/scripts.pory"
	walk_right
# 160 "data/maps/PalletTown/scripts.pory"
	walk_right
# 161 "data/maps/PalletTown/scripts.pory"
	walk_right
# 162 "data/maps/PalletTown/scripts.pory"
	walk_right
# 163 "data/maps/PalletTown/scripts.pory"
	walk_right
# 164 "data/maps/PalletTown/scripts.pory"
	walk_down
# 165 "data/maps/PalletTown/scripts.pory"
	walk_down
# 166 "data/maps/PalletTown/scripts.pory"
	walk_down
# 167 "data/maps/PalletTown/scripts.pory"
	walk_down
# 168 "data/maps/PalletTown/scripts.pory"
	walk_down
# 169 "data/maps/PalletTown/scripts.pory"
	walk_right
# 170 "data/maps/PalletTown/scripts.pory"
	walk_right
# 171 "data/maps/PalletTown/scripts.pory"
	walk_right
# 172 "data/maps/PalletTown/scripts.pory"
	walk_right
# 173 "data/maps/PalletTown/scripts.pory"
	step_end
# 174 "data/maps/PalletTown/scripts.pory"

# 175 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_OakTriggerLeft::
# 176 "data/maps/PalletTown/scripts.pory"
	lockall
# 177 "data/maps/PalletTown/scripts.pory"
	setvar VAR_TEMP_1, 0
# 178 "data/maps/PalletTown/scripts.pory"
	goto PalletTown_EventScript_OakTrigger
# 179 "data/maps/PalletTown/scripts.pory"
	end
# 180 "data/maps/PalletTown/scripts.pory"

# 181 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_OakTriggerRight::
# 182 "data/maps/PalletTown/scripts.pory"
	lockall
# 183 "data/maps/PalletTown/scripts.pory"
	setvar VAR_TEMP_1, 1
# 184 "data/maps/PalletTown/scripts.pory"
	goto PalletTown_EventScript_OakTrigger
# 185 "data/maps/PalletTown/scripts.pory"
	end
# 186 "data/maps/PalletTown/scripts.pory"

# 187 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_OakTrigger::
# 188 "data/maps/PalletTown/scripts.pory"
	famechecker FAMECHECKER_OAK, FCPICKSTATE_COLORED, UpdatePickStateFromSpecialVar8005
# 189 "data/maps/PalletTown/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 190 "data/maps/PalletTown/scripts.pory"
	delay 30
# 191 "data/maps/PalletTown/scripts.pory"
	playbgm MUS_OAK, 0
# 192 "data/maps/PalletTown/scripts.pory"
	message PalletTown_Text_OakDontGoOut
# 193 "data/maps/PalletTown/scripts.pory"
	waitmessage
# 194 "data/maps/PalletTown/scripts.pory"
	delay 85
# 195 "data/maps/PalletTown/scripts.pory"
	closemessage
# 196 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterDown
# 197 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 198 "data/maps/PalletTown/scripts.pory"
	playse SE_PIN
# 199 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_ExclamationMark
# 200 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 201 "data/maps/PalletTown/scripts.pory"
	delay 30
# 202 "data/maps/PalletTown/scripts.pory"
	addobject LOCALID_PALLET_PROF_OAK
# 203 "data/maps/PalletTown/scripts.pory"
	call_if_eq VAR_TEMP_1, 0, PalletTown_EventScript_OakEnterLeft
# 204 "data/maps/PalletTown/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, PalletTown_EventScript_OakEnterRight
# 205 "data/maps/PalletTown/scripts.pory"
	delay 30
# 206 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_OakGrassUnsafeNeedMon
# 207 "data/maps/PalletTown/scripts.pory"
	closemessage
# 208 "data/maps/PalletTown/scripts.pory"
	delay 30
# 209 "data/maps/PalletTown/scripts.pory"
	call_if_eq VAR_TEMP_1, 0, PalletTown_EventScript_OakLeadPlayerToLabLeft
# 210 "data/maps/PalletTown/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, PalletTown_EventScript_OakLeadPlayerToLabRight
# 211 "data/maps/PalletTown/scripts.pory"
	opendoor 16, 13
# 212 "data/maps/PalletTown/scripts.pory"
	waitdooranim
# 213 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PALLET_PROF_OAK, PalletTown_Movement_OakEnterLab
# 214 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PLAYER, PalletTown_Movement_PlayerEnterLab
# 215 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 216 "data/maps/PalletTown/scripts.pory"
	closedoor 16, 13
# 217 "data/maps/PalletTown/scripts.pory"
	waitdooranim
# 218 "data/maps/PalletTown/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_PROFESSOR_OAKS_LAB, 1
# 219 "data/maps/PalletTown/scripts.pory"
	clearflag FLAG_HIDE_OAK_IN_HIS_LAB
# 220 "data/maps/PalletTown/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_OAK, 1
# 221 "data/maps/PalletTown/scripts.pory"
	setflag FLAG_HIDE_OAK_IN_PALLET_TOWN
# 222 "data/maps/PalletTown/scripts.pory"
	setflag FLAG_DONT_TRANSITION_MUSIC
# 223 "data/maps/PalletTown/scripts.pory"
	warp MAP_PALLET_TOWN_PROFESSOR_OAKS_LAB, 6, 12
# 224 "data/maps/PalletTown/scripts.pory"
	waitstate
# 225 "data/maps/PalletTown/scripts.pory"
	releaseall
# 226 "data/maps/PalletTown/scripts.pory"
	end
# 227 "data/maps/PalletTown/scripts.pory"

# 228 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_OakEnterLeft::
# 229 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PALLET_PROF_OAK, PalletTown_Movement_OakEnterLeft
# 230 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 231 "data/maps/PalletTown/scripts.pory"
	return
# 232 "data/maps/PalletTown/scripts.pory"

# 233 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_OakEnterRight::
# 234 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PALLET_PROF_OAK, PalletTown_Movement_OakEnterRight
# 235 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 236 "data/maps/PalletTown/scripts.pory"
	return
# 237 "data/maps/PalletTown/scripts.pory"

# 238 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_OakLeadPlayerToLabLeft::
# 239 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PALLET_PROF_OAK, PalletTown_Movement_OakWalkToLabLeft
# 240 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PLAYER, PalletTown_Movement_PlayerWalkToLabLeft
# 241 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 242 "data/maps/PalletTown/scripts.pory"
	return
# 243 "data/maps/PalletTown/scripts.pory"

# 244 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_OakLeadPlayerToLabRight::
# 245 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PALLET_PROF_OAK, PalletTown_Movement_OakWalkToLabRight
# 246 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PLAYER, PalletTown_Movement_PlayerWalkToLabRight
# 247 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 248 "data/maps/PalletTown/scripts.pory"
	return
# 249 "data/maps/PalletTown/scripts.pory"

# 250 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_OakEnterLeft::
# 251 "data/maps/PalletTown/scripts.pory"
	walk_up
# 252 "data/maps/PalletTown/scripts.pory"
	walk_up
# 253 "data/maps/PalletTown/scripts.pory"
	walk_right
# 254 "data/maps/PalletTown/scripts.pory"
	walk_up
# 255 "data/maps/PalletTown/scripts.pory"
	walk_up
# 256 "data/maps/PalletTown/scripts.pory"
	walk_right
# 257 "data/maps/PalletTown/scripts.pory"
	walk_up
# 258 "data/maps/PalletTown/scripts.pory"
	walk_up
# 259 "data/maps/PalletTown/scripts.pory"
	step_end
# 260 "data/maps/PalletTown/scripts.pory"

# 261 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_OakEnterRight::
# 262 "data/maps/PalletTown/scripts.pory"
	walk_right
# 263 "data/maps/PalletTown/scripts.pory"
	walk_up
# 264 "data/maps/PalletTown/scripts.pory"
	walk_up
# 265 "data/maps/PalletTown/scripts.pory"
	walk_right
# 266 "data/maps/PalletTown/scripts.pory"
	walk_up
# 267 "data/maps/PalletTown/scripts.pory"
	walk_up
# 268 "data/maps/PalletTown/scripts.pory"
	walk_right
# 269 "data/maps/PalletTown/scripts.pory"
	walk_up
# 270 "data/maps/PalletTown/scripts.pory"
	walk_up
# 271 "data/maps/PalletTown/scripts.pory"
	step_end
# 272 "data/maps/PalletTown/scripts.pory"

# 273 "data/maps/PalletTown/scripts.pory"
	.macro walk_to_lab
# 274 "data/maps/PalletTown/scripts.pory"
	walk_left
# 275 "data/maps/PalletTown/scripts.pory"
	walk_down
# 276 "data/maps/PalletTown/scripts.pory"
	walk_down
# 277 "data/maps/PalletTown/scripts.pory"
	walk_down
# 278 "data/maps/PalletTown/scripts.pory"
	walk_down
# 279 "data/maps/PalletTown/scripts.pory"
	walk_down
# 280 "data/maps/PalletTown/scripts.pory"
	walk_down
# 281 "data/maps/PalletTown/scripts.pory"
	walk_down
# 282 "data/maps/PalletTown/scripts.pory"
	walk_down
# 283 "data/maps/PalletTown/scripts.pory"
	walk_down
# 284 "data/maps/PalletTown/scripts.pory"
	walk_down
# 285 "data/maps/PalletTown/scripts.pory"
	walk_down
# 286 "data/maps/PalletTown/scripts.pory"
	walk_right
# 287 "data/maps/PalletTown/scripts.pory"
	walk_right
# 288 "data/maps/PalletTown/scripts.pory"
	walk_right
# 289 "data/maps/PalletTown/scripts.pory"
	walk_right
# 290 "data/maps/PalletTown/scripts.pory"
	.endm
# 291 "data/maps/PalletTown/scripts.pory"

# 292 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_OakWalkToLabLeft::
# 293 "data/maps/PalletTown/scripts.pory"
	walk_down
# 294 "data/maps/PalletTown/scripts.pory"
	walk_to_lab
# 295 "data/maps/PalletTown/scripts.pory"
	walk_right
# 296 "data/maps/PalletTown/scripts.pory"
	walk_in_place_faster_up
# 297 "data/maps/PalletTown/scripts.pory"
	step_end
# 298 "data/maps/PalletTown/scripts.pory"

# 299 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_OakWalkToLabRight::
# 300 "data/maps/PalletTown/scripts.pory"
	walk_down
# 301 "data/maps/PalletTown/scripts.pory"
	walk_left
# 302 "data/maps/PalletTown/scripts.pory"
	walk_to_lab
# 303 "data/maps/PalletTown/scripts.pory"
	walk_right
# 304 "data/maps/PalletTown/scripts.pory"
	walk_in_place_faster_up
# 305 "data/maps/PalletTown/scripts.pory"
	step_end
# 306 "data/maps/PalletTown/scripts.pory"

# 307 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_OakEnterLab::
# 308 "data/maps/PalletTown/scripts.pory"
	walk_up
# 309 "data/maps/PalletTown/scripts.pory"
	set_invisible
# 310 "data/maps/PalletTown/scripts.pory"
	step_end
# 311 "data/maps/PalletTown/scripts.pory"

# 312 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_PlayerWalkToLabLeft::
# 313 "data/maps/PalletTown/scripts.pory"
	walk_down
# 314 "data/maps/PalletTown/scripts.pory"
	walk_down
# 315 "data/maps/PalletTown/scripts.pory"
	walk_to_lab
# 316 "data/maps/PalletTown/scripts.pory"
	step_end
# 317 "data/maps/PalletTown/scripts.pory"

# 318 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_PlayerWalkToLabRight::
# 319 "data/maps/PalletTown/scripts.pory"
	walk_down
# 320 "data/maps/PalletTown/scripts.pory"
	walk_down
# 321 "data/maps/PalletTown/scripts.pory"
	walk_left
# 322 "data/maps/PalletTown/scripts.pory"
	walk_to_lab
# 323 "data/maps/PalletTown/scripts.pory"
	step_end
# 324 "data/maps/PalletTown/scripts.pory"

# 325 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_PlayerEnterLab::
# 326 "data/maps/PalletTown/scripts.pory"
	walk_right
# 327 "data/maps/PalletTown/scripts.pory"
	walk_up
# 328 "data/maps/PalletTown/scripts.pory"
	set_invisible
# 329 "data/maps/PalletTown/scripts.pory"
	step_end
# 330 "data/maps/PalletTown/scripts.pory"

# 331 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_SignLady::
# 332 "data/maps/PalletTown/scripts.pory"
	lock
# 333 "data/maps/PalletTown/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 2, PalletTown_EventScript_SignLadyDone
# 334 "data/maps/PalletTown/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1, PalletTown_EventScript_SignLadyJustShowedSign
# 335 "data/maps/PalletTown/scripts.pory"
	goto_if_eq SIGN_LADY_READY, TRUE, PalletTown_EventScript_SignLadyStartShowSign
# 336 "data/maps/PalletTown/scripts.pory"
	goto_if_set FLAG_TEMP_2, PalletTown_EventScript_SignLadyGoReadSign
# 337 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_HmmIsThatRight
# 338 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PALLET_SIGN_LADY, Common_Movement_FacePlayer
# 339 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 340 "data/maps/PalletTown/scripts.pory"
	playse SE_PIN
# 341 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PALLET_SIGN_LADY, Common_Movement_ExclamationMark
# 342 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 343 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PALLET_SIGN_LADY, Common_Movement_Delay48
# 344 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 345 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_OhLookLook
# 346 "data/maps/PalletTown/scripts.pory"
	closemessage
# 347 "data/maps/PalletTown/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, PalletTown_EventScript_SignLadyMoveOutOfWayRight
# 348 "data/maps/PalletTown/scripts.pory"
	call_if_ne VAR_FACING, DIR_EAST, PalletTown_EventScript_SignLadyMoveOutOfWayLeft
# 349 "data/maps/PalletTown/scripts.pory"
	copyobjectxytoperm LOCALID_PALLET_SIGN_LADY
# 350 "data/maps/PalletTown/scripts.pory"
	setflag FLAG_TEMP_2
# 351 "data/maps/PalletTown/scripts.pory"
	release
# 352 "data/maps/PalletTown/scripts.pory"
	end
# 353 "data/maps/PalletTown/scripts.pory"

# 354 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_SignLadyMoveOutOfWayRight::
# 355 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PALLET_SIGN_LADY, PalletTown_Movement_SignLadyMoveOutOfWayRight
# 356 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 357 "data/maps/PalletTown/scripts.pory"
	return
# 358 "data/maps/PalletTown/scripts.pory"

# 359 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_SignLadyMoveOutOfWayLeft::
# 360 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PALLET_SIGN_LADY, PalletTown_Movement_SignLadyMoveOutOfWayLeft
# 361 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 362 "data/maps/PalletTown/scripts.pory"
	return
# 363 "data/maps/PalletTown/scripts.pory"

# 364 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_SignLadyDone::
# 365 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PALLET_SIGN_LADY, Common_Movement_FacePlayer
# 366 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 367 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_RaisingMonsToo
# 368 "data/maps/PalletTown/scripts.pory"
	release
# 369 "data/maps/PalletTown/scripts.pory"
	end
# 370 "data/maps/PalletTown/scripts.pory"

# 371 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_SignLadyGoReadSign::
# 372 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PALLET_SIGN_LADY, Common_Movement_FacePlayer
# 373 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 374 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_ReadItReadIt
# 375 "data/maps/PalletTown/scripts.pory"
	release
# 376 "data/maps/PalletTown/scripts.pory"
	end
# 377 "data/maps/PalletTown/scripts.pory"

# 378 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_SignLadyJustShowedSign::
# 379 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PALLET_SIGN_LADY, Common_Movement_FacePlayer
# 380 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 381 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_SignsAreUsefulArentThey
# 382 "data/maps/PalletTown/scripts.pory"
	release
# 383 "data/maps/PalletTown/scripts.pory"
	end
# 384 "data/maps/PalletTown/scripts.pory"

# 385 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_SignLadyMoveOutOfWayRight::
# 386 "data/maps/PalletTown/scripts.pory"
	walk_right
# 387 "data/maps/PalletTown/scripts.pory"
	walk_in_place_faster_left
# 388 "data/maps/PalletTown/scripts.pory"
	step_end
# 389 "data/maps/PalletTown/scripts.pory"

# 390 "data/maps/PalletTown/scripts.pory"
PalletTown_Movement_SignLadyMoveOutOfWayLeft::
# 391 "data/maps/PalletTown/scripts.pory"
	walk_left
# 392 "data/maps/PalletTown/scripts.pory"
	walk_in_place_faster_right
# 393 "data/maps/PalletTown/scripts.pory"
	step_end
# 394 "data/maps/PalletTown/scripts.pory"

# 395 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_FatMan::
# 396 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_CanStoreItemsAndMonsInPC, MSGBOX_NPC
# 397 "data/maps/PalletTown/scripts.pory"
	end
# 398 "data/maps/PalletTown/scripts.pory"

# 399 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_OaksLabSign::
# 400 "data/maps/PalletTown/scripts.pory"
	lockall
# 401 "data/maps/PalletTown/scripts.pory"
	famechecker FAMECHECKER_OAK, 0
# 402 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_OakPokemonResearchLab
# 403 "data/maps/PalletTown/scripts.pory"
	releaseall
# 404 "data/maps/PalletTown/scripts.pory"
	end
# 405 "data/maps/PalletTown/scripts.pory"

# 406 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_PlayersHouseSign::
# 407 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_PlayersHouse, MSGBOX_SIGN
# 408 "data/maps/PalletTown/scripts.pory"
	end
# 409 "data/maps/PalletTown/scripts.pory"

# 410 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_RivalsHouseSign::
# 411 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_RivalsHouse, MSGBOX_SIGN
# 412 "data/maps/PalletTown/scripts.pory"
	end
# 413 "data/maps/PalletTown/scripts.pory"

# 414 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_TownSign::
# 415 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_TownSign, MSGBOX_SIGN
# 416 "data/maps/PalletTown/scripts.pory"
	end
# 417 "data/maps/PalletTown/scripts.pory"

# 418 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_TrainerTips::
# 419 "data/maps/PalletTown/scripts.pory"
	lockall
# 420 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_PressStartToOpenMenu
# 421 "data/maps/PalletTown/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1
# 422 "data/maps/PalletTown/scripts.pory"
	releaseall
# 423 "data/maps/PalletTown/scripts.pory"
	end
# 424 "data/maps/PalletTown/scripts.pory"

# 425 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_SignLadyTrigger::
# 426 "data/maps/PalletTown/scripts.pory"
	lockall
# 427 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PALLET_SIGN_LADY, Common_Movement_WalkInPlaceFasterRight
# 428 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 429 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 430 "data/maps/PalletTown/scripts.pory"
	call PalletTown_EventScript_SignLadyShowSign
# 431 "data/maps/PalletTown/scripts.pory"
	releaseall
# 432 "data/maps/PalletTown/scripts.pory"
	end
# 433 "data/maps/PalletTown/scripts.pory"

# 434 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_SignLadyShowSign::
# 435 "data/maps/PalletTown/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 436 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_LookCopiedTrainerTipsSign
# 437 "data/maps/PalletTown/scripts.pory"
	closemessage
# 438 "data/maps/PalletTown/scripts.pory"
	delay 20
# 439 "data/maps/PalletTown/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 440 "data/maps/PalletTown/scripts.pory"
	setflag FLAG_OPENED_START_MENU
# 441 "data/maps/PalletTown/scripts.pory"
	setvar VAR_MAP_SCENE_PALLET_TOWN_SIGN_LADY, 1
# 442 "data/maps/PalletTown/scripts.pory"
	setvar SIGN_LADY_READY, FALSE
# 443 "data/maps/PalletTown/scripts.pory"
	special SetWalkingIntoSignVars
# 444 "data/maps/PalletTown/scripts.pory"
	special DisableMsgBoxWalkaway
# 445 "data/maps/PalletTown/scripts.pory"
	signmsg
# 446 "data/maps/PalletTown/scripts.pory"
	msgbox PalletTown_Text_PressStartToOpenMenuCopy
# 447 "data/maps/PalletTown/scripts.pory"
	normalmsg
# 448 "data/maps/PalletTown/scripts.pory"
	return
# 449 "data/maps/PalletTown/scripts.pory"

# 450 "data/maps/PalletTown/scripts.pory"
PalletTown_EventScript_SignLadyStartShowSign::
# 451 "data/maps/PalletTown/scripts.pory"
	applymovement LOCALID_PALLET_SIGN_LADY, Common_Movement_FacePlayer
# 452 "data/maps/PalletTown/scripts.pory"
	waitmovement 0
# 453 "data/maps/PalletTown/scripts.pory"
	call PalletTown_EventScript_SignLadyShowSign
# 454 "data/maps/PalletTown/scripts.pory"
	release
# 455 "data/maps/PalletTown/scripts.pory"
	end
