# 1 "data/maps/PewterCity/scripts.pory"

# 2 "data/maps/PewterCity/scripts.pory"
PewterCity_MapScripts::
# 3 "data/maps/PewterCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, PewterCity_OnTransition
# 4 "data/maps/PewterCity/scripts.pory"
	.byte 0
# 5 "data/maps/PewterCity/scripts.pory"

# 6 "data/maps/PewterCity/scripts.pory"
PewterCity_OnTransition::
# 7 "data/maps/PewterCity/scripts.pory"
	setworldmapflag FLAG_WORLD_MAP_PEWTER_CITY
# 8 "data/maps/PewterCity/scripts.pory"
	setvar VAR_MAP_SCENE_PEWTER_CITY_MUSEUM_1F, 0
# 9 "data/maps/PewterCity/scripts.pory"
	end
# 10 "data/maps/PewterCity/scripts.pory"

# 11 "data/maps/PewterCity/scripts.pory"
@ Impossible to speak to this NPC from a facing dir != DIR_EAST normally, so they arent checked
# 12 "data/maps/PewterCity/scripts.pory"
@ Additionally, no movement script exists for facing DIR_SOUTH, which would necessitate walking out of bounds
# 13 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_GymGuide::
# 14 "data/maps/PewterCity/scripts.pory"
	lock
# 15 "data/maps/PewterCity/scripts.pory"
	faceplayer
# 16 "data/maps/PewterCity/scripts.pory"
	msgbox PewterCity_Text_BrocksLookingForChallengersFollowMe
# 17 "data/maps/PewterCity/scripts.pory"
	closemessage
# 18 "data/maps/PewterCity/scripts.pory"
	playbgm MUS_FOLLOW_ME, 0
# 19 "data/maps/PewterCity/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, PewterCity_EventScript_WalkToGymEast
# 20 "data/maps/PewterCity/scripts.pory"
	msgbox PewterCity_Text_GoTakeOnBrock
# 21 "data/maps/PewterCity/scripts.pory"
	closemessage
# 22 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GymGuideExit
# 23 "data/maps/PewterCity/scripts.pory"
	waitmovement 0
# 24 "data/maps/PewterCity/scripts.pory"
	fadedefaultbgm
# 25 "data/maps/PewterCity/scripts.pory"
	removeobject LOCALID_PEWTER_GYM_GUIDE
# 26 "data/maps/PewterCity/scripts.pory"
	clearflag FLAG_HIDE_PEWTER_CITY_GYM_GUIDE
# 27 "data/maps/PewterCity/scripts.pory"
	release
# 28 "data/maps/PewterCity/scripts.pory"
	end
# 29 "data/maps/PewterCity/scripts.pory"

# 30 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_WalkToGymEast::
# 31 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWaitForGuideEast
# 32 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideMoveToLeadEast
# 33 "data/maps/PewterCity/scripts.pory"
	waitmovement 0
# 34 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWalkToGymEast
# 35 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideWalkToGymEast
# 36 "data/maps/PewterCity/scripts.pory"
	waitmovement 0
# 37 "data/maps/PewterCity/scripts.pory"
	return
# 38 "data/maps/PewterCity/scripts.pory"

# 39 "data/maps/PewterCity/scripts.pory"
@ Unused
# 40 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_WalkToGymWest::
# 41 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWaitForGuideWest
# 42 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideMoveToLeadWest
# 43 "data/maps/PewterCity/scripts.pory"
	waitmovement 0
# 44 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWalkToGymWest
# 45 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideWalkToGymWest
# 46 "data/maps/PewterCity/scripts.pory"
	waitmovement 0
# 47 "data/maps/PewterCity/scripts.pory"
	return
# 48 "data/maps/PewterCity/scripts.pory"

# 49 "data/maps/PewterCity/scripts.pory"
@ Unused
# 50 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_WalkToGymNorth::
# 51 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWaitForGuideNorth
# 52 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideMoveToLeadNorth
# 53 "data/maps/PewterCity/scripts.pory"
	waitmovement 0
# 54 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWalkToGymNorth
# 55 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideWalkToGymNorth
# 56 "data/maps/PewterCity/scripts.pory"
	waitmovement 0
# 57 "data/maps/PewterCity/scripts.pory"
	return
# 58 "data/maps/PewterCity/scripts.pory"

# 59 "data/maps/PewterCity/scripts.pory"
.macro walk_to_gym
# 60 "data/maps/PewterCity/scripts.pory"
	walk_left
# 61 "data/maps/PewterCity/scripts.pory"
	walk_left
# 62 "data/maps/PewterCity/scripts.pory"
	walk_left
# 63 "data/maps/PewterCity/scripts.pory"
	walk_up
# 64 "data/maps/PewterCity/scripts.pory"
	walk_left
# 65 "data/maps/PewterCity/scripts.pory"
	walk_left
# 66 "data/maps/PewterCity/scripts.pory"
	walk_left
# 67 "data/maps/PewterCity/scripts.pory"
	walk_left
# 68 "data/maps/PewterCity/scripts.pory"
	walk_left
# 69 "data/maps/PewterCity/scripts.pory"
	walk_left
# 70 "data/maps/PewterCity/scripts.pory"
	walk_left
# 71 "data/maps/PewterCity/scripts.pory"
	walk_left
# 72 "data/maps/PewterCity/scripts.pory"
	walk_left
# 73 "data/maps/PewterCity/scripts.pory"
	walk_left
# 74 "data/maps/PewterCity/scripts.pory"
	walk_left
# 75 "data/maps/PewterCity/scripts.pory"
	walk_left
# 76 "data/maps/PewterCity/scripts.pory"
	walk_left
# 77 "data/maps/PewterCity/scripts.pory"
	walk_left
# 78 "data/maps/PewterCity/scripts.pory"
	walk_left
# 79 "data/maps/PewterCity/scripts.pory"
	walk_left
# 80 "data/maps/PewterCity/scripts.pory"
	walk_up
# 81 "data/maps/PewterCity/scripts.pory"
	walk_up
# 82 "data/maps/PewterCity/scripts.pory"
	walk_up
# 83 "data/maps/PewterCity/scripts.pory"
	walk_up
# 84 "data/maps/PewterCity/scripts.pory"
	walk_up
# 85 "data/maps/PewterCity/scripts.pory"
	walk_up
# 86 "data/maps/PewterCity/scripts.pory"
	walk_up
# 87 "data/maps/PewterCity/scripts.pory"
	walk_up
# 88 "data/maps/PewterCity/scripts.pory"
	walk_up
# 89 "data/maps/PewterCity/scripts.pory"
	walk_up
# 90 "data/maps/PewterCity/scripts.pory"
	walk_left
# 91 "data/maps/PewterCity/scripts.pory"
	walk_left
# 92 "data/maps/PewterCity/scripts.pory"
	walk_left
# 93 "data/maps/PewterCity/scripts.pory"
	walk_left
# 94 "data/maps/PewterCity/scripts.pory"
	walk_left
# 95 "data/maps/PewterCity/scripts.pory"
	walk_left
# 96 "data/maps/PewterCity/scripts.pory"
	walk_left
# 97 "data/maps/PewterCity/scripts.pory"
	walk_left
# 98 "data/maps/PewterCity/scripts.pory"
	walk_left
# 99 "data/maps/PewterCity/scripts.pory"
	walk_left
# 100 "data/maps/PewterCity/scripts.pory"
	walk_left
# 101 "data/maps/PewterCity/scripts.pory"
	walk_left
# 102 "data/maps/PewterCity/scripts.pory"
	walk_left
# 103 "data/maps/PewterCity/scripts.pory"
	walk_left
# 104 "data/maps/PewterCity/scripts.pory"
	walk_left
# 105 "data/maps/PewterCity/scripts.pory"
	walk_left
# 106 "data/maps/PewterCity/scripts.pory"
	walk_down
# 107 "data/maps/PewterCity/scripts.pory"
	walk_down
# 108 "data/maps/PewterCity/scripts.pory"
	walk_down
# 109 "data/maps/PewterCity/scripts.pory"
	walk_down
# 110 "data/maps/PewterCity/scripts.pory"
	walk_down
# 111 "data/maps/PewterCity/scripts.pory"
	walk_down
# 112 "data/maps/PewterCity/scripts.pory"
	walk_down
# 113 "data/maps/PewterCity/scripts.pory"
	walk_down
# 114 "data/maps/PewterCity/scripts.pory"
	walk_right
# 115 "data/maps/PewterCity/scripts.pory"
	walk_right
# 116 "data/maps/PewterCity/scripts.pory"
	walk_right
# 117 "data/maps/PewterCity/scripts.pory"
	walk_right
# 118 "data/maps/PewterCity/scripts.pory"
	walk_right
# 119 "data/maps/PewterCity/scripts.pory"
	walk_right
# 120 "data/maps/PewterCity/scripts.pory"
	walk_right
# 121 "data/maps/PewterCity/scripts.pory"
	walk_right
# 122 "data/maps/PewterCity/scripts.pory"
.endm
# 123 "data/maps/PewterCity/scripts.pory"

# 124 "data/maps/PewterCity/scripts.pory"
.macro walk_to_gym_alt
# 125 "data/maps/PewterCity/scripts.pory"
	walk_left
# 126 "data/maps/PewterCity/scripts.pory"
	walk_left
# 127 "data/maps/PewterCity/scripts.pory"
	walk_left
# 128 "data/maps/PewterCity/scripts.pory"
	walk_left
# 129 "data/maps/PewterCity/scripts.pory"
	walk_left
# 130 "data/maps/PewterCity/scripts.pory"
	walk_left
# 131 "data/maps/PewterCity/scripts.pory"
	walk_left
# 132 "data/maps/PewterCity/scripts.pory"
	walk_left
# 133 "data/maps/PewterCity/scripts.pory"
	walk_left
# 134 "data/maps/PewterCity/scripts.pory"
	walk_left
# 135 "data/maps/PewterCity/scripts.pory"
	walk_left
# 136 "data/maps/PewterCity/scripts.pory"
	walk_left
# 137 "data/maps/PewterCity/scripts.pory"
	walk_left
# 138 "data/maps/PewterCity/scripts.pory"
	walk_left
# 139 "data/maps/PewterCity/scripts.pory"
	walk_up
# 140 "data/maps/PewterCity/scripts.pory"
	walk_up
# 141 "data/maps/PewterCity/scripts.pory"
	walk_up
# 142 "data/maps/PewterCity/scripts.pory"
	walk_up
# 143 "data/maps/PewterCity/scripts.pory"
	walk_up
# 144 "data/maps/PewterCity/scripts.pory"
	walk_up
# 145 "data/maps/PewterCity/scripts.pory"
	walk_up
# 146 "data/maps/PewterCity/scripts.pory"
	walk_up
# 147 "data/maps/PewterCity/scripts.pory"
	walk_up
# 148 "data/maps/PewterCity/scripts.pory"
	walk_up
# 149 "data/maps/PewterCity/scripts.pory"
	walk_left
# 150 "data/maps/PewterCity/scripts.pory"
	walk_left
# 151 "data/maps/PewterCity/scripts.pory"
	walk_left
# 152 "data/maps/PewterCity/scripts.pory"
	walk_left
# 153 "data/maps/PewterCity/scripts.pory"
	walk_left
# 154 "data/maps/PewterCity/scripts.pory"
	walk_left
# 155 "data/maps/PewterCity/scripts.pory"
	walk_left
# 156 "data/maps/PewterCity/scripts.pory"
	walk_left
# 157 "data/maps/PewterCity/scripts.pory"
	walk_left
# 158 "data/maps/PewterCity/scripts.pory"
	walk_left
# 159 "data/maps/PewterCity/scripts.pory"
	walk_left
# 160 "data/maps/PewterCity/scripts.pory"
	walk_left
# 161 "data/maps/PewterCity/scripts.pory"
	walk_left
# 162 "data/maps/PewterCity/scripts.pory"
	walk_left
# 163 "data/maps/PewterCity/scripts.pory"
	walk_left
# 164 "data/maps/PewterCity/scripts.pory"
	walk_down
# 165 "data/maps/PewterCity/scripts.pory"
	walk_down
# 166 "data/maps/PewterCity/scripts.pory"
	walk_down
# 167 "data/maps/PewterCity/scripts.pory"
	walk_down
# 168 "data/maps/PewterCity/scripts.pory"
	walk_down
# 169 "data/maps/PewterCity/scripts.pory"
	walk_down
# 170 "data/maps/PewterCity/scripts.pory"
	walk_down
# 171 "data/maps/PewterCity/scripts.pory"
	walk_down
# 172 "data/maps/PewterCity/scripts.pory"
	walk_right
# 173 "data/maps/PewterCity/scripts.pory"
	walk_right
# 174 "data/maps/PewterCity/scripts.pory"
	walk_right
# 175 "data/maps/PewterCity/scripts.pory"
	walk_right
# 176 "data/maps/PewterCity/scripts.pory"
	walk_right
# 177 "data/maps/PewterCity/scripts.pory"
	walk_right
# 178 "data/maps/PewterCity/scripts.pory"
	walk_right
# 179 "data/maps/PewterCity/scripts.pory"
.endm
# 180 "data/maps/PewterCity/scripts.pory"

# 181 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_PlayerWaitForGuideEast::
# 182 "data/maps/PewterCity/scripts.pory"
	delay_16
# 183 "data/maps/PewterCity/scripts.pory"
	delay_16
# 184 "data/maps/PewterCity/scripts.pory"
	delay_4
# 185 "data/maps/PewterCity/scripts.pory"
	walk_in_place_faster_down
# 186 "data/maps/PewterCity/scripts.pory"
	step_end
# 187 "data/maps/PewterCity/scripts.pory"

# 188 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_PlayerWalkToGymEast::
# 189 "data/maps/PewterCity/scripts.pory"
	walk_down
# 190 "data/maps/PewterCity/scripts.pory"
	walk_to_gym
# 191 "data/maps/PewterCity/scripts.pory"
	step_end
# 192 "data/maps/PewterCity/scripts.pory"

# 193 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_PlayerWaitForGuideWest::
# 194 "data/maps/PewterCity/scripts.pory"
	delay_16
# 195 "data/maps/PewterCity/scripts.pory"
	step_end
# 196 "data/maps/PewterCity/scripts.pory"

# 197 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_PlayerWalkToGymWest::
# 198 "data/maps/PewterCity/scripts.pory"
	walk_left
# 199 "data/maps/PewterCity/scripts.pory"
	walk_left
# 200 "data/maps/PewterCity/scripts.pory"
	walk_left
# 201 "data/maps/PewterCity/scripts.pory"
	walk_left
# 202 "data/maps/PewterCity/scripts.pory"
	walk_left
# 203 "data/maps/PewterCity/scripts.pory"
	walk_to_gym_alt
# 204 "data/maps/PewterCity/scripts.pory"
	step_end
# 205 "data/maps/PewterCity/scripts.pory"

# 206 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_PlayerWaitForGuideNorth::
# 207 "data/maps/PewterCity/scripts.pory"
	delay_16
# 208 "data/maps/PewterCity/scripts.pory"
	step_end
# 209 "data/maps/PewterCity/scripts.pory"

# 210 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_PlayerWalkToGymNorth::
# 211 "data/maps/PewterCity/scripts.pory"
	walk_up
# 212 "data/maps/PewterCity/scripts.pory"
	walk_left
# 213 "data/maps/PewterCity/scripts.pory"
	walk_left
# 214 "data/maps/PewterCity/scripts.pory"
	walk_left
# 215 "data/maps/PewterCity/scripts.pory"
	walk_left
# 216 "data/maps/PewterCity/scripts.pory"
	walk_to_gym_alt
# 217 "data/maps/PewterCity/scripts.pory"
	step_end
# 218 "data/maps/PewterCity/scripts.pory"

# 219 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_GuideMoveToLeadEast::
# 220 "data/maps/PewterCity/scripts.pory"
	walk_down
# 221 "data/maps/PewterCity/scripts.pory"
	walk_left
# 222 "data/maps/PewterCity/scripts.pory"
	walk_in_place_faster_up
# 223 "data/maps/PewterCity/scripts.pory"
	walk_in_place_up
# 224 "data/maps/PewterCity/scripts.pory"
	step_end
# 225 "data/maps/PewterCity/scripts.pory"

# 226 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_GuideWalkToGymEast::
# 227 "data/maps/PewterCity/scripts.pory"
	walk_to_gym
# 228 "data/maps/PewterCity/scripts.pory"
	walk_right
# 229 "data/maps/PewterCity/scripts.pory"
	walk_in_place_faster_left
# 230 "data/maps/PewterCity/scripts.pory"
	step_end
# 231 "data/maps/PewterCity/scripts.pory"

# 232 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_GuideMoveToLeadWest::
# 233 "data/maps/PewterCity/scripts.pory"
	walk_in_place_right
# 234 "data/maps/PewterCity/scripts.pory"
	step_end
# 235 "data/maps/PewterCity/scripts.pory"

# 236 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_GuideWalkToGymWest::
# 237 "data/maps/PewterCity/scripts.pory"
	walk_left
# 238 "data/maps/PewterCity/scripts.pory"
	walk_left
# 239 "data/maps/PewterCity/scripts.pory"
	walk_left
# 240 "data/maps/PewterCity/scripts.pory"
	walk_left
# 241 "data/maps/PewterCity/scripts.pory"
	walk_to_gym_alt
# 242 "data/maps/PewterCity/scripts.pory"
	walk_right
# 243 "data/maps/PewterCity/scripts.pory"
	walk_in_place_faster_left
# 244 "data/maps/PewterCity/scripts.pory"
	step_end
# 245 "data/maps/PewterCity/scripts.pory"

# 246 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_GuideMoveToLeadNorth::
# 247 "data/maps/PewterCity/scripts.pory"
	walk_in_place_down
# 248 "data/maps/PewterCity/scripts.pory"
	step_end
# 249 "data/maps/PewterCity/scripts.pory"

# 250 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_GuideWalkToGymNorth::
# 251 "data/maps/PewterCity/scripts.pory"
	walk_left
# 252 "data/maps/PewterCity/scripts.pory"
	walk_left
# 253 "data/maps/PewterCity/scripts.pory"
	walk_left
# 254 "data/maps/PewterCity/scripts.pory"
	walk_left
# 255 "data/maps/PewterCity/scripts.pory"
	walk_to_gym_alt
# 256 "data/maps/PewterCity/scripts.pory"
	walk_right
# 257 "data/maps/PewterCity/scripts.pory"
	walk_in_place_faster_left
# 258 "data/maps/PewterCity/scripts.pory"
	step_end
# 259 "data/maps/PewterCity/scripts.pory"

# 260 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_GymGuideExit::
# 261 "data/maps/PewterCity/scripts.pory"
	walk_down
# 262 "data/maps/PewterCity/scripts.pory"
	walk_left
# 263 "data/maps/PewterCity/scripts.pory"
	walk_left
# 264 "data/maps/PewterCity/scripts.pory"
	walk_left
# 265 "data/maps/PewterCity/scripts.pory"
	walk_left
# 266 "data/maps/PewterCity/scripts.pory"
	walk_left
# 267 "data/maps/PewterCity/scripts.pory"
	walk_left
# 268 "data/maps/PewterCity/scripts.pory"
	walk_left
# 269 "data/maps/PewterCity/scripts.pory"
	walk_left
# 270 "data/maps/PewterCity/scripts.pory"
	walk_left
# 271 "data/maps/PewterCity/scripts.pory"
	step_end
# 272 "data/maps/PewterCity/scripts.pory"

# 273 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_GymGuideTriggerTop::
# 274 "data/maps/PewterCity/scripts.pory"
	lockall
# 275 "data/maps/PewterCity/scripts.pory"
	setvar VAR_TEMP_1, 0
# 276 "data/maps/PewterCity/scripts.pory"
	goto PewterCity_EventScript_GymGuideTrigger
# 277 "data/maps/PewterCity/scripts.pory"
	end
# 278 "data/maps/PewterCity/scripts.pory"

# 279 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_GymGuideTriggerMid::
# 280 "data/maps/PewterCity/scripts.pory"
	lockall
# 281 "data/maps/PewterCity/scripts.pory"
	setvar VAR_TEMP_1, 1
# 282 "data/maps/PewterCity/scripts.pory"
	goto PewterCity_EventScript_GymGuideTrigger
# 283 "data/maps/PewterCity/scripts.pory"
	end
# 284 "data/maps/PewterCity/scripts.pory"

# 285 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_GymGuideTriggerBottom::
# 286 "data/maps/PewterCity/scripts.pory"
	lockall
# 287 "data/maps/PewterCity/scripts.pory"
	setvar VAR_TEMP_1, 2
# 288 "data/maps/PewterCity/scripts.pory"
	goto PewterCity_EventScript_GymGuideTrigger
# 289 "data/maps/PewterCity/scripts.pory"
	end
# 290 "data/maps/PewterCity/scripts.pory"

# 291 "data/maps/PewterCity/scripts.pory"
@ This trigger is inaccessible and its corresponding movement script isnt linked
# 292 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_GymGuideTriggerRight::
# 293 "data/maps/PewterCity/scripts.pory"
	lockall
# 294 "data/maps/PewterCity/scripts.pory"
	setvar VAR_TEMP_1, 3
# 295 "data/maps/PewterCity/scripts.pory"
	goto PewterCity_EventScript_GymGuideTrigger
# 296 "data/maps/PewterCity/scripts.pory"
	end
# 297 "data/maps/PewterCity/scripts.pory"

# 298 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_GymGuideTrigger::
# 299 "data/maps/PewterCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 300 "data/maps/PewterCity/scripts.pory"
	msgbox PewterCity_Text_BrocksLookingForChallengersFollowMe
# 301 "data/maps/PewterCity/scripts.pory"
	closemessage
# 302 "data/maps/PewterCity/scripts.pory"
	playbgm MUS_FOLLOW_ME, 0
# 303 "data/maps/PewterCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 0, PewterCity_EventScript_WalkToGymTop
# 304 "data/maps/PewterCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, PewterCity_EventScript_WalkToGymMid
# 305 "data/maps/PewterCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, PewterCity_EventScript_WalkToGymBottom
# 306 "data/maps/PewterCity/scripts.pory"
	msgbox PewterCity_Text_GoTakeOnBrock
# 307 "data/maps/PewterCity/scripts.pory"
	closemessage
# 308 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GymGuideExit
# 309 "data/maps/PewterCity/scripts.pory"
	waitmovement 0
# 310 "data/maps/PewterCity/scripts.pory"
	fadedefaultbgm
# 311 "data/maps/PewterCity/scripts.pory"
	removeobject LOCALID_PEWTER_GYM_GUIDE
# 312 "data/maps/PewterCity/scripts.pory"
	clearflag FLAG_HIDE_PEWTER_CITY_GYM_GUIDE
# 313 "data/maps/PewterCity/scripts.pory"
	releaseall
# 314 "data/maps/PewterCity/scripts.pory"
	end
# 315 "data/maps/PewterCity/scripts.pory"

# 316 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_WalkToGymTop::
# 317 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideMoveToLeadTop
# 318 "data/maps/PewterCity/scripts.pory"
	waitmovement 0
# 319 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWalkToGymTop
# 320 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideWalkToGymTop
# 321 "data/maps/PewterCity/scripts.pory"
	waitmovement 0
# 322 "data/maps/PewterCity/scripts.pory"
	return
# 323 "data/maps/PewterCity/scripts.pory"

# 324 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_WalkToGymMid::
# 325 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideMoveToLeadMid
# 326 "data/maps/PewterCity/scripts.pory"
	waitmovement 0
# 327 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWalkToGymMid
# 328 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideWalkToGymMid
# 329 "data/maps/PewterCity/scripts.pory"
	waitmovement 0
# 330 "data/maps/PewterCity/scripts.pory"
	return
# 331 "data/maps/PewterCity/scripts.pory"

# 332 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_WalkToGymBottom::
# 333 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideMoveToLeadBottom
# 334 "data/maps/PewterCity/scripts.pory"
	waitmovement 0
# 335 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWalkToGymBottom
# 336 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideWalkToGymBottom
# 337 "data/maps/PewterCity/scripts.pory"
	waitmovement 0
# 338 "data/maps/PewterCity/scripts.pory"
	return
# 339 "data/maps/PewterCity/scripts.pory"

# 340 "data/maps/PewterCity/scripts.pory"
@ Unused
# 341 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_WalkToGymRight::
# 342 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideApproachPlayerRight
# 343 "data/maps/PewterCity/scripts.pory"
	waitmovement 0
# 344 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWalkToGymRight
# 345 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideWalkToGymRight
# 346 "data/maps/PewterCity/scripts.pory"
	waitmovement 0
# 347 "data/maps/PewterCity/scripts.pory"
	return
# 348 "data/maps/PewterCity/scripts.pory"

# 349 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_PlayerWalkToGymTop::
# 350 "data/maps/PewterCity/scripts.pory"
	walk_left
# 351 "data/maps/PewterCity/scripts.pory"
	walk_to_gym
# 352 "data/maps/PewterCity/scripts.pory"
	step_end
# 353 "data/maps/PewterCity/scripts.pory"

# 354 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_PlayerWalkToGymMid::
# 355 "data/maps/PewterCity/scripts.pory"
	walk_up
# 356 "data/maps/PewterCity/scripts.pory"
	walk_left
# 357 "data/maps/PewterCity/scripts.pory"
	walk_to_gym
# 358 "data/maps/PewterCity/scripts.pory"
	step_end
# 359 "data/maps/PewterCity/scripts.pory"

# 360 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_PlayerWalkToGymBottom::
# 361 "data/maps/PewterCity/scripts.pory"
	walk_up
# 362 "data/maps/PewterCity/scripts.pory"
	walk_up
# 363 "data/maps/PewterCity/scripts.pory"
	walk_left
# 364 "data/maps/PewterCity/scripts.pory"
	walk_to_gym
# 365 "data/maps/PewterCity/scripts.pory"
	step_end
# 366 "data/maps/PewterCity/scripts.pory"

# 367 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_PlayerWalkToGymRight::
# 368 "data/maps/PewterCity/scripts.pory"
	walk_left
# 369 "data/maps/PewterCity/scripts.pory"
	walk_left
# 370 "data/maps/PewterCity/scripts.pory"
	walk_left
# 371 "data/maps/PewterCity/scripts.pory"
	walk_left
# 372 "data/maps/PewterCity/scripts.pory"
	walk_up
# 373 "data/maps/PewterCity/scripts.pory"
	walk_left
# 374 "data/maps/PewterCity/scripts.pory"
	walk_left
# 375 "data/maps/PewterCity/scripts.pory"
	walk_left
# 376 "data/maps/PewterCity/scripts.pory"
	walk_up
# 377 "data/maps/PewterCity/scripts.pory"
	walk_up
# 378 "data/maps/PewterCity/scripts.pory"
	walk_to_gym_alt
# 379 "data/maps/PewterCity/scripts.pory"
	step_end
# 380 "data/maps/PewterCity/scripts.pory"

# 381 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_GuideMoveToLeadTop::
# 382 "data/maps/PewterCity/scripts.pory"
	walk_left
# 383 "data/maps/PewterCity/scripts.pory"
	walk_down
# 384 "data/maps/PewterCity/scripts.pory"
	walk_in_place_faster_right
# 385 "data/maps/PewterCity/scripts.pory"
	walk_in_place_right
# 386 "data/maps/PewterCity/scripts.pory"
	step_end
# 387 "data/maps/PewterCity/scripts.pory"

# 388 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_GuideMoveToLeadMid::
# 389 "data/maps/PewterCity/scripts.pory"
	walk_down
# 390 "data/maps/PewterCity/scripts.pory"
	walk_in_place_down
# 391 "data/maps/PewterCity/scripts.pory"
	step_end
# 392 "data/maps/PewterCity/scripts.pory"

# 393 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_GuideMoveToLeadBottom::
# 394 "data/maps/PewterCity/scripts.pory"
	walk_down
# 395 "data/maps/PewterCity/scripts.pory"
	walk_down
# 396 "data/maps/PewterCity/scripts.pory"
	walk_in_place_down
# 397 "data/maps/PewterCity/scripts.pory"
	step_end
# 398 "data/maps/PewterCity/scripts.pory"

# 399 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_GuideApproachPlayerRight::
# 400 "data/maps/PewterCity/scripts.pory"
	walk_down
# 401 "data/maps/PewterCity/scripts.pory"
	walk_down
# 402 "data/maps/PewterCity/scripts.pory"
	walk_right
# 403 "data/maps/PewterCity/scripts.pory"
	walk_down
# 404 "data/maps/PewterCity/scripts.pory"
	walk_right
# 405 "data/maps/PewterCity/scripts.pory"
	walk_in_place_right
# 406 "data/maps/PewterCity/scripts.pory"
	step_end
# 407 "data/maps/PewterCity/scripts.pory"

# 408 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_GuideWalkToGymTop::
# 409 "data/maps/PewterCity/scripts.pory"
	walk_to_gym
# 410 "data/maps/PewterCity/scripts.pory"
	walk_right
# 411 "data/maps/PewterCity/scripts.pory"
	walk_in_place_faster_left
# 412 "data/maps/PewterCity/scripts.pory"
	step_end
# 413 "data/maps/PewterCity/scripts.pory"

# 414 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_GuideWalkToGymMid::
# 415 "data/maps/PewterCity/scripts.pory"
	walk_left
# 416 "data/maps/PewterCity/scripts.pory"
	walk_to_gym
# 417 "data/maps/PewterCity/scripts.pory"
	walk_right
# 418 "data/maps/PewterCity/scripts.pory"
	walk_in_place_faster_left
# 419 "data/maps/PewterCity/scripts.pory"
	step_end
# 420 "data/maps/PewterCity/scripts.pory"

# 421 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_GuideWalkToGymBottom::
# 422 "data/maps/PewterCity/scripts.pory"
	walk_up
# 423 "data/maps/PewterCity/scripts.pory"
	walk_left
# 424 "data/maps/PewterCity/scripts.pory"
	walk_to_gym
# 425 "data/maps/PewterCity/scripts.pory"
	walk_right
# 426 "data/maps/PewterCity/scripts.pory"
	walk_in_place_faster_left
# 427 "data/maps/PewterCity/scripts.pory"
	step_end
# 428 "data/maps/PewterCity/scripts.pory"

# 429 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_GuideWalkToGymRight::
# 430 "data/maps/PewterCity/scripts.pory"
	walk_left
# 431 "data/maps/PewterCity/scripts.pory"
	walk_left
# 432 "data/maps/PewterCity/scripts.pory"
	walk_left
# 433 "data/maps/PewterCity/scripts.pory"
	walk_up
# 434 "data/maps/PewterCity/scripts.pory"
	walk_left
# 435 "data/maps/PewterCity/scripts.pory"
	walk_left
# 436 "data/maps/PewterCity/scripts.pory"
	walk_left
# 437 "data/maps/PewterCity/scripts.pory"
	walk_up
# 438 "data/maps/PewterCity/scripts.pory"
	walk_up
# 439 "data/maps/PewterCity/scripts.pory"
	walk_to_gym_alt
# 440 "data/maps/PewterCity/scripts.pory"
	walk_right
# 441 "data/maps/PewterCity/scripts.pory"
	walk_in_place_faster_left
# 442 "data/maps/PewterCity/scripts.pory"
	step_end
# 443 "data/maps/PewterCity/scripts.pory"

# 444 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_Lass::
# 445 "data/maps/PewterCity/scripts.pory"
	msgbox PewterCity_Text_ClefairyCameFromMoon, MSGBOX_NPC
# 446 "data/maps/PewterCity/scripts.pory"
	end
# 447 "data/maps/PewterCity/scripts.pory"

# 448 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_MuseumGuide::
# 449 "data/maps/PewterCity/scripts.pory"
	lock
# 450 "data/maps/PewterCity/scripts.pory"
	faceplayer
# 451 "data/maps/PewterCity/scripts.pory"
	msgbox PewterCity_Text_DidYouCheckOutMuseum, MSGBOX_YESNO
# 452 "data/maps/PewterCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PewterCity_EventScript_CheckedOutMuseum
# 453 "data/maps/PewterCity/scripts.pory"
	msgbox PewterCity_Text_ReallyYouHaveToGo
# 454 "data/maps/PewterCity/scripts.pory"
	closemessage
# 455 "data/maps/PewterCity/scripts.pory"
	delay 10
# 456 "data/maps/PewterCity/scripts.pory"
	playbgm MUS_FOLLOW_ME, 0
# 457 "data/maps/PewterCity/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, PewterCity_EventScript_LeadToMuseumNorth
# 458 "data/maps/PewterCity/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, PewterCity_EventScript_LeadToMuseumSouth
# 459 "data/maps/PewterCity/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, PewterCity_EventScript_LeadToMuseumWest
# 460 "data/maps/PewterCity/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, PewterCity_EventScript_LeadToMuseumEast
# 461 "data/maps/PewterCity/scripts.pory"
	msgbox PewterCity_Text_ThisIsTheMuseum
# 462 "data/maps/PewterCity/scripts.pory"
	closemessage
# 463 "data/maps/PewterCity/scripts.pory"
	delay 10
# 464 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PEWTER_MUSEUM_GUIDE, PewterCity_Movement_MuseumGuideExit
# 465 "data/maps/PewterCity/scripts.pory"
	waitmovement 0
# 466 "data/maps/PewterCity/scripts.pory"
	fadedefaultbgm
# 467 "data/maps/PewterCity/scripts.pory"
	removeobject LOCALID_PEWTER_MUSEUM_GUIDE
# 468 "data/maps/PewterCity/scripts.pory"
	clearflag FLAG_HIDE_PEWTER_MUSEUM_GUIDE
# 469 "data/maps/PewterCity/scripts.pory"
	release
# 470 "data/maps/PewterCity/scripts.pory"
	end
# 471 "data/maps/PewterCity/scripts.pory"

# 472 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_LeadToMuseumNorth::
# 473 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PEWTER_MUSEUM_GUIDE, PewterCity_Movement_GuideWalkToMuseumNorth
# 474 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWalkToMuseumNorth
# 475 "data/maps/PewterCity/scripts.pory"
	waitmovement 0
# 476 "data/maps/PewterCity/scripts.pory"
	return
# 477 "data/maps/PewterCity/scripts.pory"

# 478 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_LeadToMuseumSouth::
# 479 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PEWTER_MUSEUM_GUIDE, PewterCity_Movement_GuideWalkToMuseumSouth
# 480 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWalkToMuseumSouth
# 481 "data/maps/PewterCity/scripts.pory"
	waitmovement 0
# 482 "data/maps/PewterCity/scripts.pory"
	return
# 483 "data/maps/PewterCity/scripts.pory"

# 484 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_LeadToMuseumWest::
# 485 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PEWTER_MUSEUM_GUIDE, PewterCity_Movement_GuideWalkToMuseumWest
# 486 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWalkToMuseumWest
# 487 "data/maps/PewterCity/scripts.pory"
	waitmovement 0
# 488 "data/maps/PewterCity/scripts.pory"
	return
# 489 "data/maps/PewterCity/scripts.pory"

# 490 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_LeadToMuseumEast::
# 491 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PEWTER_MUSEUM_GUIDE, PewterCity_Movement_GuideWalkToMuseumEast
# 492 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWalkToMuseumEast
# 493 "data/maps/PewterCity/scripts.pory"
	waitmovement 0
# 494 "data/maps/PewterCity/scripts.pory"
	return
# 495 "data/maps/PewterCity/scripts.pory"

# 496 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_CheckedOutMuseum::
# 497 "data/maps/PewterCity/scripts.pory"
	msgbox PewterCity_Text_WerentThoseFossilsAmazing
# 498 "data/maps/PewterCity/scripts.pory"
	release
# 499 "data/maps/PewterCity/scripts.pory"
	end
# 500 "data/maps/PewterCity/scripts.pory"

# 501 "data/maps/PewterCity/scripts.pory"
.macro walk_to_museum
# 502 "data/maps/PewterCity/scripts.pory"
	walk_down
# 503 "data/maps/PewterCity/scripts.pory"
	walk_down
# 504 "data/maps/PewterCity/scripts.pory"
	walk_left
# 505 "data/maps/PewterCity/scripts.pory"
	walk_left
# 506 "data/maps/PewterCity/scripts.pory"
	walk_left
# 507 "data/maps/PewterCity/scripts.pory"
	walk_left
# 508 "data/maps/PewterCity/scripts.pory"
	walk_left
# 509 "data/maps/PewterCity/scripts.pory"
	walk_left
# 510 "data/maps/PewterCity/scripts.pory"
	walk_left
# 511 "data/maps/PewterCity/scripts.pory"
	walk_left
# 512 "data/maps/PewterCity/scripts.pory"
	walk_left
# 513 "data/maps/PewterCity/scripts.pory"
	walk_left
# 514 "data/maps/PewterCity/scripts.pory"
	walk_left
# 515 "data/maps/PewterCity/scripts.pory"
	walk_up
# 516 "data/maps/PewterCity/scripts.pory"
	walk_up
# 517 "data/maps/PewterCity/scripts.pory"
	walk_up
# 518 "data/maps/PewterCity/scripts.pory"
	walk_up
# 519 "data/maps/PewterCity/scripts.pory"
	walk_up
# 520 "data/maps/PewterCity/scripts.pory"
	walk_up
# 521 "data/maps/PewterCity/scripts.pory"
	walk_up
# 522 "data/maps/PewterCity/scripts.pory"
	walk_up
# 523 "data/maps/PewterCity/scripts.pory"
	walk_up
# 524 "data/maps/PewterCity/scripts.pory"
	walk_up
# 525 "data/maps/PewterCity/scripts.pory"
	walk_left
# 526 "data/maps/PewterCity/scripts.pory"
	walk_left
# 527 "data/maps/PewterCity/scripts.pory"
	walk_left
# 528 "data/maps/PewterCity/scripts.pory"
	walk_left
# 529 "data/maps/PewterCity/scripts.pory"
	walk_left
# 530 "data/maps/PewterCity/scripts.pory"
	walk_left
# 531 "data/maps/PewterCity/scripts.pory"
.endm
# 532 "data/maps/PewterCity/scripts.pory"

# 533 "data/maps/PewterCity/scripts.pory"
.macro walk_to_museum_south
# 534 "data/maps/PewterCity/scripts.pory"
	walk_right
# 535 "data/maps/PewterCity/scripts.pory"
	walk_down
# 536 "data/maps/PewterCity/scripts.pory"
	walk_down
# 537 "data/maps/PewterCity/scripts.pory"
	walk_left
# 538 "data/maps/PewterCity/scripts.pory"
	walk_left
# 539 "data/maps/PewterCity/scripts.pory"
	walk_left
# 540 "data/maps/PewterCity/scripts.pory"
	walk_left
# 541 "data/maps/PewterCity/scripts.pory"
	walk_left
# 542 "data/maps/PewterCity/scripts.pory"
	walk_left
# 543 "data/maps/PewterCity/scripts.pory"
	walk_left
# 544 "data/maps/PewterCity/scripts.pory"
	walk_left
# 545 "data/maps/PewterCity/scripts.pory"
	walk_left
# 546 "data/maps/PewterCity/scripts.pory"
	walk_left
# 547 "data/maps/PewterCity/scripts.pory"
	walk_left
# 548 "data/maps/PewterCity/scripts.pory"
	walk_up
# 549 "data/maps/PewterCity/scripts.pory"
	walk_up
# 550 "data/maps/PewterCity/scripts.pory"
	walk_up
# 551 "data/maps/PewterCity/scripts.pory"
	walk_up
# 552 "data/maps/PewterCity/scripts.pory"
	walk_up
# 553 "data/maps/PewterCity/scripts.pory"
	walk_up
# 554 "data/maps/PewterCity/scripts.pory"
	walk_up
# 555 "data/maps/PewterCity/scripts.pory"
	walk_up
# 556 "data/maps/PewterCity/scripts.pory"
	walk_up
# 557 "data/maps/PewterCity/scripts.pory"
	walk_up
# 558 "data/maps/PewterCity/scripts.pory"
	walk_left
# 559 "data/maps/PewterCity/scripts.pory"
	walk_left
# 560 "data/maps/PewterCity/scripts.pory"
	walk_left
# 561 "data/maps/PewterCity/scripts.pory"
	walk_left
# 562 "data/maps/PewterCity/scripts.pory"
	walk_left
# 563 "data/maps/PewterCity/scripts.pory"
	walk_left
# 564 "data/maps/PewterCity/scripts.pory"
.endm
# 565 "data/maps/PewterCity/scripts.pory"

# 566 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_PlayerWalkToMuseumNorth::
# 567 "data/maps/PewterCity/scripts.pory"
	walk_up
# 568 "data/maps/PewterCity/scripts.pory"
	walk_to_museum
# 569 "data/maps/PewterCity/scripts.pory"
	delay_8
# 570 "data/maps/PewterCity/scripts.pory"
	walk_in_place_faster_up
# 571 "data/maps/PewterCity/scripts.pory"
	step_end
# 572 "data/maps/PewterCity/scripts.pory"

# 573 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_GuideWalkToMuseumNorth::
# 574 "data/maps/PewterCity/scripts.pory"
	walk_to_museum
# 575 "data/maps/PewterCity/scripts.pory"
	walk_left
# 576 "data/maps/PewterCity/scripts.pory"
	walk_in_place_faster_up
# 577 "data/maps/PewterCity/scripts.pory"
	step_end
# 578 "data/maps/PewterCity/scripts.pory"

# 579 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_PlayerWalkToMuseumSouth::
# 580 "data/maps/PewterCity/scripts.pory"
	walk_down
# 581 "data/maps/PewterCity/scripts.pory"
	walk_to_museum_south
# 582 "data/maps/PewterCity/scripts.pory"
	delay_8
# 583 "data/maps/PewterCity/scripts.pory"
	walk_in_place_faster_up
# 584 "data/maps/PewterCity/scripts.pory"
	step_end
# 585 "data/maps/PewterCity/scripts.pory"

# 586 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_GuideWalkToMuseumSouth::
# 587 "data/maps/PewterCity/scripts.pory"
	walk_to_museum_south
# 588 "data/maps/PewterCity/scripts.pory"
	walk_left
# 589 "data/maps/PewterCity/scripts.pory"
	walk_in_place_faster_up
# 590 "data/maps/PewterCity/scripts.pory"
	step_end
# 591 "data/maps/PewterCity/scripts.pory"

# 592 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_PlayerWalkToMuseumWest::
# 593 "data/maps/PewterCity/scripts.pory"
	walk_up
# 594 "data/maps/PewterCity/scripts.pory"
	walk_down
# 595 "data/maps/PewterCity/scripts.pory"
	walk_to_museum
# 596 "data/maps/PewterCity/scripts.pory"
	walk_in_place_faster_up
# 597 "data/maps/PewterCity/scripts.pory"
	step_end
# 598 "data/maps/PewterCity/scripts.pory"

# 599 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_GuideWalkToMuseumWest::
# 600 "data/maps/PewterCity/scripts.pory"
	walk_right
# 601 "data/maps/PewterCity/scripts.pory"
	walk_to_museum
# 602 "data/maps/PewterCity/scripts.pory"
	walk_left
# 603 "data/maps/PewterCity/scripts.pory"
	walk_in_place_faster_up
# 604 "data/maps/PewterCity/scripts.pory"
	step_end
# 605 "data/maps/PewterCity/scripts.pory"

# 606 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_PlayerWalkToMuseumEast::
# 607 "data/maps/PewterCity/scripts.pory"
	walk_right
# 608 "data/maps/PewterCity/scripts.pory"
	walk_to_museum
# 609 "data/maps/PewterCity/scripts.pory"
	delay_8
# 610 "data/maps/PewterCity/scripts.pory"
	walk_in_place_faster_up
# 611 "data/maps/PewterCity/scripts.pory"
	step_end
# 612 "data/maps/PewterCity/scripts.pory"

# 613 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_GuideWalkToMuseumEast::
# 614 "data/maps/PewterCity/scripts.pory"
	walk_to_museum
# 615 "data/maps/PewterCity/scripts.pory"
	walk_left
# 616 "data/maps/PewterCity/scripts.pory"
	walk_in_place_faster_up
# 617 "data/maps/PewterCity/scripts.pory"
	step_end
# 618 "data/maps/PewterCity/scripts.pory"

# 619 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_MuseumGuideExit::
# 620 "data/maps/PewterCity/scripts.pory"
	walk_down
# 621 "data/maps/PewterCity/scripts.pory"
	walk_right
# 622 "data/maps/PewterCity/scripts.pory"
	walk_right
# 623 "data/maps/PewterCity/scripts.pory"
	walk_right
# 624 "data/maps/PewterCity/scripts.pory"
	walk_right
# 625 "data/maps/PewterCity/scripts.pory"
	walk_right
# 626 "data/maps/PewterCity/scripts.pory"
	walk_right
# 627 "data/maps/PewterCity/scripts.pory"
	walk_right
# 628 "data/maps/PewterCity/scripts.pory"
	walk_down
# 629 "data/maps/PewterCity/scripts.pory"
	walk_down
# 630 "data/maps/PewterCity/scripts.pory"
	walk_down
# 631 "data/maps/PewterCity/scripts.pory"
	walk_right
# 632 "data/maps/PewterCity/scripts.pory"
	walk_right
# 633 "data/maps/PewterCity/scripts.pory"
	walk_right
# 634 "data/maps/PewterCity/scripts.pory"
	step_end
# 635 "data/maps/PewterCity/scripts.pory"

# 636 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_FatMan::
# 637 "data/maps/PewterCity/scripts.pory"
	lock
# 638 "data/maps/PewterCity/scripts.pory"
	faceplayer
# 639 "data/maps/PewterCity/scripts.pory"
	famechecker FAMECHECKER_BROCK, 2
# 640 "data/maps/PewterCity/scripts.pory"
	msgbox PewterCity_Text_BrockOnlySeriousTrainerHere
# 641 "data/maps/PewterCity/scripts.pory"
	release
# 642 "data/maps/PewterCity/scripts.pory"
	end
# 643 "data/maps/PewterCity/scripts.pory"

# 644 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_BugCatcher::
# 645 "data/maps/PewterCity/scripts.pory"
	lock
# 646 "data/maps/PewterCity/scripts.pory"
	faceplayer
# 647 "data/maps/PewterCity/scripts.pory"
	msgbox PewterCity_Text_DoYouKnowWhatImDoing, MSGBOX_YESNO
# 648 "data/maps/PewterCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PewterCity_EventScript_KnowWhatTheyreDoing
# 649 "data/maps/PewterCity/scripts.pory"
	msgbox PewterCity_Text_SprayingRepelToKeepWildMonsOut
# 650 "data/maps/PewterCity/scripts.pory"
	release
# 651 "data/maps/PewterCity/scripts.pory"
	end
# 652 "data/maps/PewterCity/scripts.pory"

# 653 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_KnowWhatTheyreDoing::
# 654 "data/maps/PewterCity/scripts.pory"
	msgbox PewterCity_Text_ThatsRightItsHardWork
# 655 "data/maps/PewterCity/scripts.pory"
	release
# 656 "data/maps/PewterCity/scripts.pory"
	end
# 657 "data/maps/PewterCity/scripts.pory"

# 658 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_TrainerTips::
# 659 "data/maps/PewterCity/scripts.pory"
	msgbox PewterCity_Text_TrainerTipsEarningEXP, MSGBOX_SIGN
# 660 "data/maps/PewterCity/scripts.pory"
	end
# 661 "data/maps/PewterCity/scripts.pory"

# 662 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_PoliceNotice::
# 663 "data/maps/PewterCity/scripts.pory"
	msgbox PewterCity_Text_CallPoliceIfInfoOnThieves, MSGBOX_SIGN
# 664 "data/maps/PewterCity/scripts.pory"
	end
# 665 "data/maps/PewterCity/scripts.pory"

# 666 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_MuseumSign::
# 667 "data/maps/PewterCity/scripts.pory"
	msgbox PewterCity_Text_MuseumOfScience, MSGBOX_SIGN
# 668 "data/maps/PewterCity/scripts.pory"
	end
# 669 "data/maps/PewterCity/scripts.pory"

# 670 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_GymSign::
# 671 "data/maps/PewterCity/scripts.pory"
	lockall
# 672 "data/maps/PewterCity/scripts.pory"
	famechecker FAMECHECKER_BROCK, 0
# 673 "data/maps/PewterCity/scripts.pory"
	msgbox PewterCity_Text_GymSign
# 674 "data/maps/PewterCity/scripts.pory"
	releaseall
# 675 "data/maps/PewterCity/scripts.pory"
	end
# 676 "data/maps/PewterCity/scripts.pory"

# 677 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_CitySign::
# 678 "data/maps/PewterCity/scripts.pory"
	msgbox PewterCity_Text_CitySign, MSGBOX_SIGN
# 679 "data/maps/PewterCity/scripts.pory"
	end
# 680 "data/maps/PewterCity/scripts.pory"

# 681 "data/maps/PewterCity/scripts.pory"
@PewterCity_EventScript_RunningShoesAide::
# 682 "data/maps/PewterCity/scripts.pory"
@	lock
# 683 "data/maps/PewterCity/scripts.pory"
@	faceplayer
# 684 "data/maps/PewterCity/scripts.pory"
@	setvar VAR_TEMP_1, 0
# 685 "data/maps/PewterCity/scripts.pory"
@	call PewterCity_EventScript_AideGiveRunningShoes
# 686 "data/maps/PewterCity/scripts.pory"
@	release
# 687 "data/maps/PewterCity/scripts.pory"
@	end
# 688 "data/maps/PewterCity/scripts.pory"
@
# 689 "data/maps/PewterCity/scripts.pory"
@PewterCity_EventScript_RunningShoesAideTriggerTop::
# 690 "data/maps/PewterCity/scripts.pory"
@	lockall
# 691 "data/maps/PewterCity/scripts.pory"
@	setvar VAR_TEMP_1, 1
# 692 "data/maps/PewterCity/scripts.pory"
@	call PewterCity_EventScript_AideGiveRunningShoes
# 693 "data/maps/PewterCity/scripts.pory"
@	releaseall
# 694 "data/maps/PewterCity/scripts.pory"
@	end
# 695 "data/maps/PewterCity/scripts.pory"
@
# 696 "data/maps/PewterCity/scripts.pory"
@PewterCity_EventScript_RunningShoesAideTriggerMid::
# 697 "data/maps/PewterCity/scripts.pory"
@	lockall
# 698 "data/maps/PewterCity/scripts.pory"
@	setvar VAR_TEMP_1, 2
# 699 "data/maps/PewterCity/scripts.pory"
@	call PewterCity_EventScript_AideGiveRunningShoes
# 700 "data/maps/PewterCity/scripts.pory"
@	releaseall
# 701 "data/maps/PewterCity/scripts.pory"
@	end
# 702 "data/maps/PewterCity/scripts.pory"
@
# 703 "data/maps/PewterCity/scripts.pory"
@PewterCity_EventScript_RunningShoesAideTriggerBottom::
# 704 "data/maps/PewterCity/scripts.pory"
@	lockall
# 705 "data/maps/PewterCity/scripts.pory"
@	setvar VAR_TEMP_1, 3
# 706 "data/maps/PewterCity/scripts.pory"
@	call PewterCity_EventScript_AideGiveRunningShoes
# 707 "data/maps/PewterCity/scripts.pory"
@	releaseall
# 708 "data/maps/PewterCity/scripts.pory"
@	end
# 709 "data/maps/PewterCity/scripts.pory"
@
# 710 "data/maps/PewterCity/scripts.pory"
@PewterCity_EventScript_AideGiveRunningShoes::
# 711 "data/maps/PewterCity/scripts.pory"
@	return
# 712 "data/maps/PewterCity/scripts.pory"
@
# 713 "data/maps/PewterCity/scripts.pory"
@PewterCity_EventScript_AideNoticePlayer::
# 714 "data/maps/PewterCity/scripts.pory"
@	applymovement LOCALID_PEWTER_AIDE, Common_Movement_WalkInPlaceFasterDown
# 715 "data/maps/PewterCity/scripts.pory"
@	waitmovement 0
# 716 "data/maps/PewterCity/scripts.pory"
@	return
# 717 "data/maps/PewterCity/scripts.pory"

# 718 "data/maps/PewterCity/scripts.pory"
@ Aide already at player
# 719 "data/maps/PewterCity/scripts.pory"
@PewterCity_EventScript_AideApproachPlayer0::
# 720 "data/maps/PewterCity/scripts.pory"
@	closemessage
# 721 "data/maps/PewterCity/scripts.pory"
@	delay 20
# 722 "data/maps/PewterCity/scripts.pory"
@	return
# 723 "data/maps/PewterCity/scripts.pory"

# 724 "data/maps/PewterCity/scripts.pory"
@PewterCity_EventScript_AideApproachPlayer1::
# 725 "data/maps/PewterCity/scripts.pory"
@	closemessage
# 726 "data/maps/PewterCity/scripts.pory"
@	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 727 "data/maps/PewterCity/scripts.pory"
@	waitmovement 0
# 728 "data/maps/PewterCity/scripts.pory"
@	return
# 729 "data/maps/PewterCity/scripts.pory"
@
# 730 "data/maps/PewterCity/scripts.pory"
@PewterCity_EventScript_AideApproachPlayer2::
# 731 "data/maps/PewterCity/scripts.pory"
@	closemessage
# 732 "data/maps/PewterCity/scripts.pory"
@	applymovement LOCALID_PEWTER_AIDE, PewterCity_Movement_AideApproachPlayerMid
# 733 "data/maps/PewterCity/scripts.pory"
@	waitmovement 0
# 734 "data/maps/PewterCity/scripts.pory"
@	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 735 "data/maps/PewterCity/scripts.pory"
@	waitmovement 0
# 736 "data/maps/PewterCity/scripts.pory"
@	return
# 737 "data/maps/PewterCity/scripts.pory"
@
# 738 "data/maps/PewterCity/scripts.pory"
@PewterCity_EventScript_AideApproachPlayer3::
# 739 "data/maps/PewterCity/scripts.pory"
@	closemessage
# 740 "data/maps/PewterCity/scripts.pory"
@	applymovement LOCALID_PEWTER_AIDE, PewterCity_Movement_AideApproachPlayerBottom
# 741 "data/maps/PewterCity/scripts.pory"
@	waitmovement 0
# 742 "data/maps/PewterCity/scripts.pory"
@	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 743 "data/maps/PewterCity/scripts.pory"
@	waitmovement 0
# 744 "data/maps/PewterCity/scripts.pory"
@	return
# 745 "data/maps/PewterCity/scripts.pory"
@
# 746 "data/maps/PewterCity/scripts.pory"
@PewterCity_EventScript_AideExit0::
# 747 "data/maps/PewterCity/scripts.pory"
@	applymovement LOCALID_PEWTER_AIDE, PewterCity_Movement_AideExit0
# 748 "data/maps/PewterCity/scripts.pory"
@	waitmovement 0
# 749 "data/maps/PewterCity/scripts.pory"
@	return
# 750 "data/maps/PewterCity/scripts.pory"
@
# 751 "data/maps/PewterCity/scripts.pory"
@PewterCity_EventScript_AideExit1::
# 752 "data/maps/PewterCity/scripts.pory"
@	applymovement LOCALID_PEWTER_AIDE, PewterCity_Movement_AideExit1
# 753 "data/maps/PewterCity/scripts.pory"
@	waitmovement 0
# 754 "data/maps/PewterCity/scripts.pory"
@	return
# 755 "data/maps/PewterCity/scripts.pory"
@
# 756 "data/maps/PewterCity/scripts.pory"
@PewterCity_EventScript_AideExit2::
# 757 "data/maps/PewterCity/scripts.pory"
@	applymovement LOCALID_PEWTER_AIDE, PewterCity_Movement_AideExit2
# 758 "data/maps/PewterCity/scripts.pory"
@	waitmovement 0
# 759 "data/maps/PewterCity/scripts.pory"
@	return
# 760 "data/maps/PewterCity/scripts.pory"
@
# 761 "data/maps/PewterCity/scripts.pory"
@PewterCity_EventScript_AideExit3::
# 762 "data/maps/PewterCity/scripts.pory"
@	applymovement LOCALID_PEWTER_AIDE, PewterCity_Movement_AideExit3
# 763 "data/maps/PewterCity/scripts.pory"
@	waitmovement 0
# 764 "data/maps/PewterCity/scripts.pory"
@	return
# 765 "data/maps/PewterCity/scripts.pory"
@
# 766 "data/maps/PewterCity/scripts.pory"
@PewterCity_Movement_AideApproachPlayerMid::
# 767 "data/maps/PewterCity/scripts.pory"
@	delay_4
# 768 "data/maps/PewterCity/scripts.pory"
@	walk_down
# 769 "data/maps/PewterCity/scripts.pory"
@	step_end
# 770 "data/maps/PewterCity/scripts.pory"
@
# 771 "data/maps/PewterCity/scripts.pory"
@PewterCity_Movement_AideApproachPlayerBottom::
# 772 "data/maps/PewterCity/scripts.pory"
@	delay_4
# 773 "data/maps/PewterCity/scripts.pory"
@	walk_down
# 774 "data/maps/PewterCity/scripts.pory"
@	walk_down
# 775 "data/maps/PewterCity/scripts.pory"
@	step_end
# 776 "data/maps/PewterCity/scripts.pory"
@
# 777 "data/maps/PewterCity/scripts.pory"
@PewterCity_Movement_AideExit0::
# 778 "data/maps/PewterCity/scripts.pory"
@	walk_down
# 779 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 780 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 781 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 782 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 783 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 784 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 785 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 786 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 787 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 788 "data/maps/PewterCity/scripts.pory"
@	step_end
# 789 "data/maps/PewterCity/scripts.pory"
@
# 790 "data/maps/PewterCity/scripts.pory"
@PewterCity_Movement_AideExit1::
# 791 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 792 "data/maps/PewterCity/scripts.pory"
@	walk_down
# 793 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 794 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 795 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 796 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 797 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 798 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 799 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 800 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 801 "data/maps/PewterCity/scripts.pory"
@	step_end
# 802 "data/maps/PewterCity/scripts.pory"
@
# 803 "data/maps/PewterCity/scripts.pory"
@PewterCity_Movement_AideExit2::
# 804 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 805 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 806 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 807 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 808 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 809 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 810 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 811 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 812 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 813 "data/maps/PewterCity/scripts.pory"
@	step_end
# 814 "data/maps/PewterCity/scripts.pory"
@
# 815 "data/maps/PewterCity/scripts.pory"
@PewterCity_Movement_AideExit3::
# 816 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 817 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 818 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 819 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 820 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 821 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 822 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 823 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 824 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 825 "data/maps/PewterCity/scripts.pory"
@	step_end
# 826 "data/maps/PewterCity/scripts.pory"

# 827 "data/maps/PewterCity/scripts.pory"
@ Unused
# 828 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_WalkInPlaceLeft::
# 829 "data/maps/PewterCity/scripts.pory"
	walk_in_place_left
# 830 "data/maps/PewterCity/scripts.pory"
	step_end
