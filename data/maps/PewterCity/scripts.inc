# 1 "data/maps/PewterCity/scripts.pory"

# 2 "data/maps/PewterCity/scripts.pory"
PewterCity_MapScripts::
# 3 "data/maps/PewterCity/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, PewterCity_OnLoad
# 4 "data/maps/PewterCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, PewterCity_OnTransition
# 5 "data/maps/PewterCity/scripts.pory"
	.byte 0
# 6 "data/maps/PewterCity/scripts.pory"

# 7 "data/maps/PewterCity/scripts.pory"
PewterCity_OnLoad::
# 8 "data/maps/PewterCity/scripts.pory"
	special SetRoofBirds
# 9 "data/maps/PewterCity/scripts.pory"
	end
# 10 "data/maps/PewterCity/scripts.pory"

# 11 "data/maps/PewterCity/scripts.pory"
PewterCity_OnTransition::
# 12 "data/maps/PewterCity/scripts.pory"
	setworldmapflag FLAG_WORLD_MAP_PEWTER_CITY
# 13 "data/maps/PewterCity/scripts.pory"
	setvar VAR_MAP_SCENE_PEWTER_CITY_MUSEUM_1F, 0
# 14 "data/maps/PewterCity/scripts.pory"
	end
# 15 "data/maps/PewterCity/scripts.pory"

# 16 "data/maps/PewterCity/scripts.pory"
@ Impossible to speak to this NPC from a facing dir != DIR_EAST normally, so they arent checked
# 17 "data/maps/PewterCity/scripts.pory"
@ Additionally, no movement script exists for facing DIR_SOUTH, which would necessitate walking out of bounds
# 18 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_GymGuide::
# 19 "data/maps/PewterCity/scripts.pory"
	lock
# 20 "data/maps/PewterCity/scripts.pory"
	faceplayer
# 21 "data/maps/PewterCity/scripts.pory"
	msgbox PewterCity_Text_BrocksLookingForChallengersFollowMe
# 22 "data/maps/PewterCity/scripts.pory"
	closemessage
# 23 "data/maps/PewterCity/scripts.pory"
	playbgm MUS_FOLLOW_ME, 0
# 24 "data/maps/PewterCity/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, PewterCity_EventScript_WalkToGymEast
# 25 "data/maps/PewterCity/scripts.pory"
	msgbox PewterCity_Text_GoTakeOnBrock
# 26 "data/maps/PewterCity/scripts.pory"
	closemessage
# 27 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GymGuideExit
# 28 "data/maps/PewterCity/scripts.pory"
	waitmovement 0
# 29 "data/maps/PewterCity/scripts.pory"
	fadedefaultbgm
# 30 "data/maps/PewterCity/scripts.pory"
	removeobject LOCALID_PEWTER_GYM_GUIDE
# 31 "data/maps/PewterCity/scripts.pory"
	clearflag FLAG_HIDE_PEWTER_CITY_GYM_GUIDE
# 32 "data/maps/PewterCity/scripts.pory"
	release
# 33 "data/maps/PewterCity/scripts.pory"
	end
# 34 "data/maps/PewterCity/scripts.pory"

# 35 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_WalkToGymEast::
# 36 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWaitForGuideEast
# 37 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideMoveToLeadEast
# 38 "data/maps/PewterCity/scripts.pory"
	waitmovement 0
# 39 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWalkToGymEast
# 40 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideWalkToGymEast
# 41 "data/maps/PewterCity/scripts.pory"
	waitmovement 0
# 42 "data/maps/PewterCity/scripts.pory"
	return
# 43 "data/maps/PewterCity/scripts.pory"

# 44 "data/maps/PewterCity/scripts.pory"
@ Unused
# 45 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_WalkToGymWest::
# 46 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWaitForGuideWest
# 47 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideMoveToLeadWest
# 48 "data/maps/PewterCity/scripts.pory"
	waitmovement 0
# 49 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWalkToGymWest
# 50 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideWalkToGymWest
# 51 "data/maps/PewterCity/scripts.pory"
	waitmovement 0
# 52 "data/maps/PewterCity/scripts.pory"
	return
# 53 "data/maps/PewterCity/scripts.pory"

# 54 "data/maps/PewterCity/scripts.pory"
@ Unused
# 55 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_WalkToGymNorth::
# 56 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWaitForGuideNorth
# 57 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideMoveToLeadNorth
# 58 "data/maps/PewterCity/scripts.pory"
	waitmovement 0
# 59 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWalkToGymNorth
# 60 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideWalkToGymNorth
# 61 "data/maps/PewterCity/scripts.pory"
	waitmovement 0
# 62 "data/maps/PewterCity/scripts.pory"
	return
# 63 "data/maps/PewterCity/scripts.pory"

# 64 "data/maps/PewterCity/scripts.pory"
.macro walk_to_gym
# 65 "data/maps/PewterCity/scripts.pory"
	walk_left
# 66 "data/maps/PewterCity/scripts.pory"
	walk_left
# 67 "data/maps/PewterCity/scripts.pory"
	walk_left
# 68 "data/maps/PewterCity/scripts.pory"
	walk_up
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
	walk_left
# 81 "data/maps/PewterCity/scripts.pory"
	walk_left
# 82 "data/maps/PewterCity/scripts.pory"
	walk_left
# 83 "data/maps/PewterCity/scripts.pory"
	walk_left
# 84 "data/maps/PewterCity/scripts.pory"
	walk_left
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
	walk_up
# 91 "data/maps/PewterCity/scripts.pory"
	walk_up
# 92 "data/maps/PewterCity/scripts.pory"
	walk_up
# 93 "data/maps/PewterCity/scripts.pory"
	walk_up
# 94 "data/maps/PewterCity/scripts.pory"
	walk_up
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
	walk_left
# 107 "data/maps/PewterCity/scripts.pory"
	walk_left
# 108 "data/maps/PewterCity/scripts.pory"
	walk_left
# 109 "data/maps/PewterCity/scripts.pory"
	walk_left
# 110 "data/maps/PewterCity/scripts.pory"
	walk_left
# 111 "data/maps/PewterCity/scripts.pory"
	walk_down
# 112 "data/maps/PewterCity/scripts.pory"
	walk_down
# 113 "data/maps/PewterCity/scripts.pory"
	walk_down
# 114 "data/maps/PewterCity/scripts.pory"
	walk_down
# 115 "data/maps/PewterCity/scripts.pory"
	walk_down
# 116 "data/maps/PewterCity/scripts.pory"
	walk_down
# 117 "data/maps/PewterCity/scripts.pory"
	walk_down
# 118 "data/maps/PewterCity/scripts.pory"
	walk_down
# 119 "data/maps/PewterCity/scripts.pory"
	walk_right
# 120 "data/maps/PewterCity/scripts.pory"
	walk_right
# 121 "data/maps/PewterCity/scripts.pory"
	walk_right
# 122 "data/maps/PewterCity/scripts.pory"
	walk_right
# 123 "data/maps/PewterCity/scripts.pory"
	walk_right
# 124 "data/maps/PewterCity/scripts.pory"
	walk_right
# 125 "data/maps/PewterCity/scripts.pory"
	walk_right
# 126 "data/maps/PewterCity/scripts.pory"
	walk_right
# 127 "data/maps/PewterCity/scripts.pory"
.endm
# 128 "data/maps/PewterCity/scripts.pory"

# 129 "data/maps/PewterCity/scripts.pory"
.macro walk_to_gym_alt
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
	walk_left
# 140 "data/maps/PewterCity/scripts.pory"
	walk_left
# 141 "data/maps/PewterCity/scripts.pory"
	walk_left
# 142 "data/maps/PewterCity/scripts.pory"
	walk_left
# 143 "data/maps/PewterCity/scripts.pory"
	walk_left
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
	walk_up
# 150 "data/maps/PewterCity/scripts.pory"
	walk_up
# 151 "data/maps/PewterCity/scripts.pory"
	walk_up
# 152 "data/maps/PewterCity/scripts.pory"
	walk_up
# 153 "data/maps/PewterCity/scripts.pory"
	walk_up
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
	walk_left
# 165 "data/maps/PewterCity/scripts.pory"
	walk_left
# 166 "data/maps/PewterCity/scripts.pory"
	walk_left
# 167 "data/maps/PewterCity/scripts.pory"
	walk_left
# 168 "data/maps/PewterCity/scripts.pory"
	walk_left
# 169 "data/maps/PewterCity/scripts.pory"
	walk_down
# 170 "data/maps/PewterCity/scripts.pory"
	walk_down
# 171 "data/maps/PewterCity/scripts.pory"
	walk_down
# 172 "data/maps/PewterCity/scripts.pory"
	walk_down
# 173 "data/maps/PewterCity/scripts.pory"
	walk_down
# 174 "data/maps/PewterCity/scripts.pory"
	walk_down
# 175 "data/maps/PewterCity/scripts.pory"
	walk_down
# 176 "data/maps/PewterCity/scripts.pory"
	walk_down
# 177 "data/maps/PewterCity/scripts.pory"
	walk_right
# 178 "data/maps/PewterCity/scripts.pory"
	walk_right
# 179 "data/maps/PewterCity/scripts.pory"
	walk_right
# 180 "data/maps/PewterCity/scripts.pory"
	walk_right
# 181 "data/maps/PewterCity/scripts.pory"
	walk_right
# 182 "data/maps/PewterCity/scripts.pory"
	walk_right
# 183 "data/maps/PewterCity/scripts.pory"
	walk_right
# 184 "data/maps/PewterCity/scripts.pory"
.endm
# 185 "data/maps/PewterCity/scripts.pory"

# 186 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_PlayerWaitForGuideEast::
# 187 "data/maps/PewterCity/scripts.pory"
	delay_16
# 188 "data/maps/PewterCity/scripts.pory"
	delay_16
# 189 "data/maps/PewterCity/scripts.pory"
	delay_4
# 190 "data/maps/PewterCity/scripts.pory"
	walk_in_place_faster_down
# 191 "data/maps/PewterCity/scripts.pory"
	step_end
# 192 "data/maps/PewterCity/scripts.pory"

# 193 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_PlayerWalkToGymEast::
# 194 "data/maps/PewterCity/scripts.pory"
	walk_down
# 195 "data/maps/PewterCity/scripts.pory"
	walk_to_gym
# 196 "data/maps/PewterCity/scripts.pory"
	step_end
# 197 "data/maps/PewterCity/scripts.pory"

# 198 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_PlayerWaitForGuideWest::
# 199 "data/maps/PewterCity/scripts.pory"
	delay_16
# 200 "data/maps/PewterCity/scripts.pory"
	step_end
# 201 "data/maps/PewterCity/scripts.pory"

# 202 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_PlayerWalkToGymWest::
# 203 "data/maps/PewterCity/scripts.pory"
	walk_left
# 204 "data/maps/PewterCity/scripts.pory"
	walk_left
# 205 "data/maps/PewterCity/scripts.pory"
	walk_left
# 206 "data/maps/PewterCity/scripts.pory"
	walk_left
# 207 "data/maps/PewterCity/scripts.pory"
	walk_left
# 208 "data/maps/PewterCity/scripts.pory"
	walk_to_gym_alt
# 209 "data/maps/PewterCity/scripts.pory"
	step_end
# 210 "data/maps/PewterCity/scripts.pory"

# 211 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_PlayerWaitForGuideNorth::
# 212 "data/maps/PewterCity/scripts.pory"
	delay_16
# 213 "data/maps/PewterCity/scripts.pory"
	step_end
# 214 "data/maps/PewterCity/scripts.pory"

# 215 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_PlayerWalkToGymNorth::
# 216 "data/maps/PewterCity/scripts.pory"
	walk_up
# 217 "data/maps/PewterCity/scripts.pory"
	walk_left
# 218 "data/maps/PewterCity/scripts.pory"
	walk_left
# 219 "data/maps/PewterCity/scripts.pory"
	walk_left
# 220 "data/maps/PewterCity/scripts.pory"
	walk_left
# 221 "data/maps/PewterCity/scripts.pory"
	walk_to_gym_alt
# 222 "data/maps/PewterCity/scripts.pory"
	step_end
# 223 "data/maps/PewterCity/scripts.pory"

# 224 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_GuideMoveToLeadEast::
# 225 "data/maps/PewterCity/scripts.pory"
	walk_down
# 226 "data/maps/PewterCity/scripts.pory"
	walk_left
# 227 "data/maps/PewterCity/scripts.pory"
	walk_in_place_faster_up
# 228 "data/maps/PewterCity/scripts.pory"
	walk_in_place_up
# 229 "data/maps/PewterCity/scripts.pory"
	step_end
# 230 "data/maps/PewterCity/scripts.pory"

# 231 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_GuideWalkToGymEast::
# 232 "data/maps/PewterCity/scripts.pory"
	walk_to_gym
# 233 "data/maps/PewterCity/scripts.pory"
	walk_right
# 234 "data/maps/PewterCity/scripts.pory"
	walk_in_place_faster_left
# 235 "data/maps/PewterCity/scripts.pory"
	step_end
# 236 "data/maps/PewterCity/scripts.pory"

# 237 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_GuideMoveToLeadWest::
# 238 "data/maps/PewterCity/scripts.pory"
	walk_in_place_right
# 239 "data/maps/PewterCity/scripts.pory"
	step_end
# 240 "data/maps/PewterCity/scripts.pory"

# 241 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_GuideWalkToGymWest::
# 242 "data/maps/PewterCity/scripts.pory"
	walk_left
# 243 "data/maps/PewterCity/scripts.pory"
	walk_left
# 244 "data/maps/PewterCity/scripts.pory"
	walk_left
# 245 "data/maps/PewterCity/scripts.pory"
	walk_left
# 246 "data/maps/PewterCity/scripts.pory"
	walk_to_gym_alt
# 247 "data/maps/PewterCity/scripts.pory"
	walk_right
# 248 "data/maps/PewterCity/scripts.pory"
	walk_in_place_faster_left
# 249 "data/maps/PewterCity/scripts.pory"
	step_end
# 250 "data/maps/PewterCity/scripts.pory"

# 251 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_GuideMoveToLeadNorth::
# 252 "data/maps/PewterCity/scripts.pory"
	walk_in_place_down
# 253 "data/maps/PewterCity/scripts.pory"
	step_end
# 254 "data/maps/PewterCity/scripts.pory"

# 255 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_GuideWalkToGymNorth::
# 256 "data/maps/PewterCity/scripts.pory"
	walk_left
# 257 "data/maps/PewterCity/scripts.pory"
	walk_left
# 258 "data/maps/PewterCity/scripts.pory"
	walk_left
# 259 "data/maps/PewterCity/scripts.pory"
	walk_left
# 260 "data/maps/PewterCity/scripts.pory"
	walk_to_gym_alt
# 261 "data/maps/PewterCity/scripts.pory"
	walk_right
# 262 "data/maps/PewterCity/scripts.pory"
	walk_in_place_faster_left
# 263 "data/maps/PewterCity/scripts.pory"
	step_end
# 264 "data/maps/PewterCity/scripts.pory"

# 265 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_GymGuideExit::
# 266 "data/maps/PewterCity/scripts.pory"
	walk_down
# 267 "data/maps/PewterCity/scripts.pory"
	walk_left
# 268 "data/maps/PewterCity/scripts.pory"
	walk_left
# 269 "data/maps/PewterCity/scripts.pory"
	walk_left
# 270 "data/maps/PewterCity/scripts.pory"
	walk_left
# 271 "data/maps/PewterCity/scripts.pory"
	walk_left
# 272 "data/maps/PewterCity/scripts.pory"
	walk_left
# 273 "data/maps/PewterCity/scripts.pory"
	walk_left
# 274 "data/maps/PewterCity/scripts.pory"
	walk_left
# 275 "data/maps/PewterCity/scripts.pory"
	walk_left
# 276 "data/maps/PewterCity/scripts.pory"
	step_end
# 277 "data/maps/PewterCity/scripts.pory"

# 278 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_GymGuideTriggerTop::
# 279 "data/maps/PewterCity/scripts.pory"
	lockall
# 280 "data/maps/PewterCity/scripts.pory"
	setvar VAR_TEMP_1, 0
# 281 "data/maps/PewterCity/scripts.pory"
	goto PewterCity_EventScript_GymGuideTrigger
# 282 "data/maps/PewterCity/scripts.pory"
	end
# 283 "data/maps/PewterCity/scripts.pory"

# 284 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_GymGuideTriggerMid::
# 285 "data/maps/PewterCity/scripts.pory"
	lockall
# 286 "data/maps/PewterCity/scripts.pory"
	setvar VAR_TEMP_1, 1
# 287 "data/maps/PewterCity/scripts.pory"
	goto PewterCity_EventScript_GymGuideTrigger
# 288 "data/maps/PewterCity/scripts.pory"
	end
# 289 "data/maps/PewterCity/scripts.pory"

# 290 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_GymGuideTriggerBottom::
# 291 "data/maps/PewterCity/scripts.pory"
	lockall
# 292 "data/maps/PewterCity/scripts.pory"
	setvar VAR_TEMP_1, 2
# 293 "data/maps/PewterCity/scripts.pory"
	goto PewterCity_EventScript_GymGuideTrigger
# 294 "data/maps/PewterCity/scripts.pory"
	end
# 295 "data/maps/PewterCity/scripts.pory"

# 296 "data/maps/PewterCity/scripts.pory"
@ This trigger is inaccessible and its corresponding movement script isnt linked
# 297 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_GymGuideTriggerRight::
# 298 "data/maps/PewterCity/scripts.pory"
	lockall
# 299 "data/maps/PewterCity/scripts.pory"
	setvar VAR_TEMP_1, 3
# 300 "data/maps/PewterCity/scripts.pory"
	goto PewterCity_EventScript_GymGuideTrigger
# 301 "data/maps/PewterCity/scripts.pory"
	end
# 302 "data/maps/PewterCity/scripts.pory"

# 303 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_GymGuideTrigger::
# 304 "data/maps/PewterCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 305 "data/maps/PewterCity/scripts.pory"
	msgbox PewterCity_Text_BrocksLookingForChallengersFollowMe
# 306 "data/maps/PewterCity/scripts.pory"
	closemessage
# 307 "data/maps/PewterCity/scripts.pory"
	playbgm MUS_FOLLOW_ME, 0
# 308 "data/maps/PewterCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 0, PewterCity_EventScript_WalkToGymTop
# 309 "data/maps/PewterCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, PewterCity_EventScript_WalkToGymMid
# 310 "data/maps/PewterCity/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, PewterCity_EventScript_WalkToGymBottom
# 311 "data/maps/PewterCity/scripts.pory"
	msgbox PewterCity_Text_GoTakeOnBrock
# 312 "data/maps/PewterCity/scripts.pory"
	closemessage
# 313 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GymGuideExit
# 314 "data/maps/PewterCity/scripts.pory"
	waitmovement 0
# 315 "data/maps/PewterCity/scripts.pory"
	fadedefaultbgm
# 316 "data/maps/PewterCity/scripts.pory"
	removeobject LOCALID_PEWTER_GYM_GUIDE
# 317 "data/maps/PewterCity/scripts.pory"
	clearflag FLAG_HIDE_PEWTER_CITY_GYM_GUIDE
# 318 "data/maps/PewterCity/scripts.pory"
	releaseall
# 319 "data/maps/PewterCity/scripts.pory"
	end
# 320 "data/maps/PewterCity/scripts.pory"

# 321 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_WalkToGymTop::
# 322 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideMoveToLeadTop
# 323 "data/maps/PewterCity/scripts.pory"
	waitmovement 0
# 324 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWalkToGymTop
# 325 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideWalkToGymTop
# 326 "data/maps/PewterCity/scripts.pory"
	waitmovement 0
# 327 "data/maps/PewterCity/scripts.pory"
	return
# 328 "data/maps/PewterCity/scripts.pory"

# 329 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_WalkToGymMid::
# 330 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideMoveToLeadMid
# 331 "data/maps/PewterCity/scripts.pory"
	waitmovement 0
# 332 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWalkToGymMid
# 333 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideWalkToGymMid
# 334 "data/maps/PewterCity/scripts.pory"
	waitmovement 0
# 335 "data/maps/PewterCity/scripts.pory"
	return
# 336 "data/maps/PewterCity/scripts.pory"

# 337 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_WalkToGymBottom::
# 338 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideMoveToLeadBottom
# 339 "data/maps/PewterCity/scripts.pory"
	waitmovement 0
# 340 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWalkToGymBottom
# 341 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideWalkToGymBottom
# 342 "data/maps/PewterCity/scripts.pory"
	waitmovement 0
# 343 "data/maps/PewterCity/scripts.pory"
	return
# 344 "data/maps/PewterCity/scripts.pory"

# 345 "data/maps/PewterCity/scripts.pory"
@ Unused
# 346 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_WalkToGymRight::
# 347 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideApproachPlayerRight
# 348 "data/maps/PewterCity/scripts.pory"
	waitmovement 0
# 349 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWalkToGymRight
# 350 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PEWTER_GYM_GUIDE, PewterCity_Movement_GuideWalkToGymRight
# 351 "data/maps/PewterCity/scripts.pory"
	waitmovement 0
# 352 "data/maps/PewterCity/scripts.pory"
	return
# 353 "data/maps/PewterCity/scripts.pory"

# 354 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_PlayerWalkToGymTop::
# 355 "data/maps/PewterCity/scripts.pory"
	walk_left
# 356 "data/maps/PewterCity/scripts.pory"
	walk_to_gym
# 357 "data/maps/PewterCity/scripts.pory"
	step_end
# 358 "data/maps/PewterCity/scripts.pory"

# 359 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_PlayerWalkToGymMid::
# 360 "data/maps/PewterCity/scripts.pory"
	walk_up
# 361 "data/maps/PewterCity/scripts.pory"
	walk_left
# 362 "data/maps/PewterCity/scripts.pory"
	walk_to_gym
# 363 "data/maps/PewterCity/scripts.pory"
	step_end
# 364 "data/maps/PewterCity/scripts.pory"

# 365 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_PlayerWalkToGymBottom::
# 366 "data/maps/PewterCity/scripts.pory"
	walk_up
# 367 "data/maps/PewterCity/scripts.pory"
	walk_up
# 368 "data/maps/PewterCity/scripts.pory"
	walk_left
# 369 "data/maps/PewterCity/scripts.pory"
	walk_to_gym
# 370 "data/maps/PewterCity/scripts.pory"
	step_end
# 371 "data/maps/PewterCity/scripts.pory"

# 372 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_PlayerWalkToGymRight::
# 373 "data/maps/PewterCity/scripts.pory"
	walk_left
# 374 "data/maps/PewterCity/scripts.pory"
	walk_left
# 375 "data/maps/PewterCity/scripts.pory"
	walk_left
# 376 "data/maps/PewterCity/scripts.pory"
	walk_left
# 377 "data/maps/PewterCity/scripts.pory"
	walk_up
# 378 "data/maps/PewterCity/scripts.pory"
	walk_left
# 379 "data/maps/PewterCity/scripts.pory"
	walk_left
# 380 "data/maps/PewterCity/scripts.pory"
	walk_left
# 381 "data/maps/PewterCity/scripts.pory"
	walk_up
# 382 "data/maps/PewterCity/scripts.pory"
	walk_up
# 383 "data/maps/PewterCity/scripts.pory"
	walk_to_gym_alt
# 384 "data/maps/PewterCity/scripts.pory"
	step_end
# 385 "data/maps/PewterCity/scripts.pory"

# 386 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_GuideMoveToLeadTop::
# 387 "data/maps/PewterCity/scripts.pory"
	walk_left
# 388 "data/maps/PewterCity/scripts.pory"
	walk_down
# 389 "data/maps/PewterCity/scripts.pory"
	walk_in_place_faster_right
# 390 "data/maps/PewterCity/scripts.pory"
	walk_in_place_right
# 391 "data/maps/PewterCity/scripts.pory"
	step_end
# 392 "data/maps/PewterCity/scripts.pory"

# 393 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_GuideMoveToLeadMid::
# 394 "data/maps/PewterCity/scripts.pory"
	walk_down
# 395 "data/maps/PewterCity/scripts.pory"
	walk_in_place_down
# 396 "data/maps/PewterCity/scripts.pory"
	step_end
# 397 "data/maps/PewterCity/scripts.pory"

# 398 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_GuideMoveToLeadBottom::
# 399 "data/maps/PewterCity/scripts.pory"
	walk_down
# 400 "data/maps/PewterCity/scripts.pory"
	walk_down
# 401 "data/maps/PewterCity/scripts.pory"
	walk_in_place_down
# 402 "data/maps/PewterCity/scripts.pory"
	step_end
# 403 "data/maps/PewterCity/scripts.pory"

# 404 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_GuideApproachPlayerRight::
# 405 "data/maps/PewterCity/scripts.pory"
	walk_down
# 406 "data/maps/PewterCity/scripts.pory"
	walk_down
# 407 "data/maps/PewterCity/scripts.pory"
	walk_right
# 408 "data/maps/PewterCity/scripts.pory"
	walk_down
# 409 "data/maps/PewterCity/scripts.pory"
	walk_right
# 410 "data/maps/PewterCity/scripts.pory"
	walk_in_place_right
# 411 "data/maps/PewterCity/scripts.pory"
	step_end
# 412 "data/maps/PewterCity/scripts.pory"

# 413 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_GuideWalkToGymTop::
# 414 "data/maps/PewterCity/scripts.pory"
	walk_to_gym
# 415 "data/maps/PewterCity/scripts.pory"
	walk_right
# 416 "data/maps/PewterCity/scripts.pory"
	walk_in_place_faster_left
# 417 "data/maps/PewterCity/scripts.pory"
	step_end
# 418 "data/maps/PewterCity/scripts.pory"

# 419 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_GuideWalkToGymMid::
# 420 "data/maps/PewterCity/scripts.pory"
	walk_left
# 421 "data/maps/PewterCity/scripts.pory"
	walk_to_gym
# 422 "data/maps/PewterCity/scripts.pory"
	walk_right
# 423 "data/maps/PewterCity/scripts.pory"
	walk_in_place_faster_left
# 424 "data/maps/PewterCity/scripts.pory"
	step_end
# 425 "data/maps/PewterCity/scripts.pory"

# 426 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_GuideWalkToGymBottom::
# 427 "data/maps/PewterCity/scripts.pory"
	walk_up
# 428 "data/maps/PewterCity/scripts.pory"
	walk_left
# 429 "data/maps/PewterCity/scripts.pory"
	walk_to_gym
# 430 "data/maps/PewterCity/scripts.pory"
	walk_right
# 431 "data/maps/PewterCity/scripts.pory"
	walk_in_place_faster_left
# 432 "data/maps/PewterCity/scripts.pory"
	step_end
# 433 "data/maps/PewterCity/scripts.pory"

# 434 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_GuideWalkToGymRight::
# 435 "data/maps/PewterCity/scripts.pory"
	walk_left
# 436 "data/maps/PewterCity/scripts.pory"
	walk_left
# 437 "data/maps/PewterCity/scripts.pory"
	walk_left
# 438 "data/maps/PewterCity/scripts.pory"
	walk_up
# 439 "data/maps/PewterCity/scripts.pory"
	walk_left
# 440 "data/maps/PewterCity/scripts.pory"
	walk_left
# 441 "data/maps/PewterCity/scripts.pory"
	walk_left
# 442 "data/maps/PewterCity/scripts.pory"
	walk_up
# 443 "data/maps/PewterCity/scripts.pory"
	walk_up
# 444 "data/maps/PewterCity/scripts.pory"
	walk_to_gym_alt
# 445 "data/maps/PewterCity/scripts.pory"
	walk_right
# 446 "data/maps/PewterCity/scripts.pory"
	walk_in_place_faster_left
# 447 "data/maps/PewterCity/scripts.pory"
	step_end
# 448 "data/maps/PewterCity/scripts.pory"

# 449 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_Lass::
# 450 "data/maps/PewterCity/scripts.pory"
	msgbox PewterCity_Text_ClefairyCameFromMoon, MSGBOX_NPC
# 451 "data/maps/PewterCity/scripts.pory"
	end
# 452 "data/maps/PewterCity/scripts.pory"

# 453 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_MuseumGuide::
# 454 "data/maps/PewterCity/scripts.pory"
	lock
# 455 "data/maps/PewterCity/scripts.pory"
	faceplayer
# 456 "data/maps/PewterCity/scripts.pory"
	msgbox PewterCity_Text_DidYouCheckOutMuseum, MSGBOX_YESNO
# 457 "data/maps/PewterCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PewterCity_EventScript_CheckedOutMuseum
# 458 "data/maps/PewterCity/scripts.pory"
	msgbox PewterCity_Text_ReallyYouHaveToGo
# 459 "data/maps/PewterCity/scripts.pory"
	closemessage
# 460 "data/maps/PewterCity/scripts.pory"
	delay 10
# 461 "data/maps/PewterCity/scripts.pory"
	playbgm MUS_FOLLOW_ME, 0
# 462 "data/maps/PewterCity/scripts.pory"
	call_if_eq VAR_FACING, DIR_NORTH, PewterCity_EventScript_LeadToMuseumNorth
# 463 "data/maps/PewterCity/scripts.pory"
	call_if_eq VAR_FACING, DIR_SOUTH, PewterCity_EventScript_LeadToMuseumSouth
# 464 "data/maps/PewterCity/scripts.pory"
	call_if_eq VAR_FACING, DIR_WEST, PewterCity_EventScript_LeadToMuseumWest
# 465 "data/maps/PewterCity/scripts.pory"
	call_if_eq VAR_FACING, DIR_EAST, PewterCity_EventScript_LeadToMuseumEast
# 466 "data/maps/PewterCity/scripts.pory"
	msgbox PewterCity_Text_ThisIsTheMuseum
# 467 "data/maps/PewterCity/scripts.pory"
	closemessage
# 468 "data/maps/PewterCity/scripts.pory"
	delay 10
# 469 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PEWTER_MUSEUM_GUIDE, PewterCity_Movement_MuseumGuideExit
# 470 "data/maps/PewterCity/scripts.pory"
	waitmovement 0
# 471 "data/maps/PewterCity/scripts.pory"
	fadedefaultbgm
# 472 "data/maps/PewterCity/scripts.pory"
	removeobject LOCALID_PEWTER_MUSEUM_GUIDE
# 473 "data/maps/PewterCity/scripts.pory"
	clearflag FLAG_HIDE_PEWTER_MUSEUM_GUIDE
# 474 "data/maps/PewterCity/scripts.pory"
	release
# 475 "data/maps/PewterCity/scripts.pory"
	end
# 476 "data/maps/PewterCity/scripts.pory"

# 477 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_LeadToMuseumNorth::
# 478 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PEWTER_MUSEUM_GUIDE, PewterCity_Movement_GuideWalkToMuseumNorth
# 479 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWalkToMuseumNorth
# 480 "data/maps/PewterCity/scripts.pory"
	waitmovement 0
# 481 "data/maps/PewterCity/scripts.pory"
	return
# 482 "data/maps/PewterCity/scripts.pory"

# 483 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_LeadToMuseumSouth::
# 484 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PEWTER_MUSEUM_GUIDE, PewterCity_Movement_GuideWalkToMuseumSouth
# 485 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWalkToMuseumSouth
# 486 "data/maps/PewterCity/scripts.pory"
	waitmovement 0
# 487 "data/maps/PewterCity/scripts.pory"
	return
# 488 "data/maps/PewterCity/scripts.pory"

# 489 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_LeadToMuseumWest::
# 490 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PEWTER_MUSEUM_GUIDE, PewterCity_Movement_GuideWalkToMuseumWest
# 491 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWalkToMuseumWest
# 492 "data/maps/PewterCity/scripts.pory"
	waitmovement 0
# 493 "data/maps/PewterCity/scripts.pory"
	return
# 494 "data/maps/PewterCity/scripts.pory"

# 495 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_LeadToMuseumEast::
# 496 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PEWTER_MUSEUM_GUIDE, PewterCity_Movement_GuideWalkToMuseumEast
# 497 "data/maps/PewterCity/scripts.pory"
	applymovement LOCALID_PLAYER, PewterCity_Movement_PlayerWalkToMuseumEast
# 498 "data/maps/PewterCity/scripts.pory"
	waitmovement 0
# 499 "data/maps/PewterCity/scripts.pory"
	return
# 500 "data/maps/PewterCity/scripts.pory"

# 501 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_CheckedOutMuseum::
# 502 "data/maps/PewterCity/scripts.pory"
	msgbox PewterCity_Text_WerentThoseFossilsAmazing
# 503 "data/maps/PewterCity/scripts.pory"
	release
# 504 "data/maps/PewterCity/scripts.pory"
	end
# 505 "data/maps/PewterCity/scripts.pory"

# 506 "data/maps/PewterCity/scripts.pory"
.macro walk_to_museum
# 507 "data/maps/PewterCity/scripts.pory"
	walk_down
# 508 "data/maps/PewterCity/scripts.pory"
	walk_down
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
	walk_left
# 516 "data/maps/PewterCity/scripts.pory"
	walk_left
# 517 "data/maps/PewterCity/scripts.pory"
	walk_left
# 518 "data/maps/PewterCity/scripts.pory"
	walk_left
# 519 "data/maps/PewterCity/scripts.pory"
	walk_left
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
	walk_up
# 526 "data/maps/PewterCity/scripts.pory"
	walk_up
# 527 "data/maps/PewterCity/scripts.pory"
	walk_up
# 528 "data/maps/PewterCity/scripts.pory"
	walk_up
# 529 "data/maps/PewterCity/scripts.pory"
	walk_up
# 530 "data/maps/PewterCity/scripts.pory"
	walk_left
# 531 "data/maps/PewterCity/scripts.pory"
	walk_left
# 532 "data/maps/PewterCity/scripts.pory"
	walk_left
# 533 "data/maps/PewterCity/scripts.pory"
	walk_left
# 534 "data/maps/PewterCity/scripts.pory"
	walk_left
# 535 "data/maps/PewterCity/scripts.pory"
	walk_left
# 536 "data/maps/PewterCity/scripts.pory"
.endm
# 537 "data/maps/PewterCity/scripts.pory"

# 538 "data/maps/PewterCity/scripts.pory"
.macro walk_to_museum_south
# 539 "data/maps/PewterCity/scripts.pory"
	walk_right
# 540 "data/maps/PewterCity/scripts.pory"
	walk_down
# 541 "data/maps/PewterCity/scripts.pory"
	walk_down
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
	walk_left
# 549 "data/maps/PewterCity/scripts.pory"
	walk_left
# 550 "data/maps/PewterCity/scripts.pory"
	walk_left
# 551 "data/maps/PewterCity/scripts.pory"
	walk_left
# 552 "data/maps/PewterCity/scripts.pory"
	walk_left
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
	walk_up
# 559 "data/maps/PewterCity/scripts.pory"
	walk_up
# 560 "data/maps/PewterCity/scripts.pory"
	walk_up
# 561 "data/maps/PewterCity/scripts.pory"
	walk_up
# 562 "data/maps/PewterCity/scripts.pory"
	walk_up
# 563 "data/maps/PewterCity/scripts.pory"
	walk_left
# 564 "data/maps/PewterCity/scripts.pory"
	walk_left
# 565 "data/maps/PewterCity/scripts.pory"
	walk_left
# 566 "data/maps/PewterCity/scripts.pory"
	walk_left
# 567 "data/maps/PewterCity/scripts.pory"
	walk_left
# 568 "data/maps/PewterCity/scripts.pory"
	walk_left
# 569 "data/maps/PewterCity/scripts.pory"
.endm
# 570 "data/maps/PewterCity/scripts.pory"

# 571 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_PlayerWalkToMuseumNorth::
# 572 "data/maps/PewterCity/scripts.pory"
	walk_up
# 573 "data/maps/PewterCity/scripts.pory"
	walk_to_museum
# 574 "data/maps/PewterCity/scripts.pory"
	delay_8
# 575 "data/maps/PewterCity/scripts.pory"
	walk_in_place_faster_up
# 576 "data/maps/PewterCity/scripts.pory"
	step_end
# 577 "data/maps/PewterCity/scripts.pory"

# 578 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_GuideWalkToMuseumNorth::
# 579 "data/maps/PewterCity/scripts.pory"
	walk_to_museum
# 580 "data/maps/PewterCity/scripts.pory"
	walk_left
# 581 "data/maps/PewterCity/scripts.pory"
	walk_in_place_faster_up
# 582 "data/maps/PewterCity/scripts.pory"
	step_end
# 583 "data/maps/PewterCity/scripts.pory"

# 584 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_PlayerWalkToMuseumSouth::
# 585 "data/maps/PewterCity/scripts.pory"
	walk_down
# 586 "data/maps/PewterCity/scripts.pory"
	walk_to_museum_south
# 587 "data/maps/PewterCity/scripts.pory"
	delay_8
# 588 "data/maps/PewterCity/scripts.pory"
	walk_in_place_faster_up
# 589 "data/maps/PewterCity/scripts.pory"
	step_end
# 590 "data/maps/PewterCity/scripts.pory"

# 591 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_GuideWalkToMuseumSouth::
# 592 "data/maps/PewterCity/scripts.pory"
	walk_to_museum_south
# 593 "data/maps/PewterCity/scripts.pory"
	walk_left
# 594 "data/maps/PewterCity/scripts.pory"
	walk_in_place_faster_up
# 595 "data/maps/PewterCity/scripts.pory"
	step_end
# 596 "data/maps/PewterCity/scripts.pory"

# 597 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_PlayerWalkToMuseumWest::
# 598 "data/maps/PewterCity/scripts.pory"
	walk_up
# 599 "data/maps/PewterCity/scripts.pory"
	walk_down
# 600 "data/maps/PewterCity/scripts.pory"
	walk_to_museum
# 601 "data/maps/PewterCity/scripts.pory"
	walk_in_place_faster_up
# 602 "data/maps/PewterCity/scripts.pory"
	step_end
# 603 "data/maps/PewterCity/scripts.pory"

# 604 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_GuideWalkToMuseumWest::
# 605 "data/maps/PewterCity/scripts.pory"
	walk_right
# 606 "data/maps/PewterCity/scripts.pory"
	walk_to_museum
# 607 "data/maps/PewterCity/scripts.pory"
	walk_left
# 608 "data/maps/PewterCity/scripts.pory"
	walk_in_place_faster_up
# 609 "data/maps/PewterCity/scripts.pory"
	step_end
# 610 "data/maps/PewterCity/scripts.pory"

# 611 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_PlayerWalkToMuseumEast::
# 612 "data/maps/PewterCity/scripts.pory"
	walk_right
# 613 "data/maps/PewterCity/scripts.pory"
	walk_to_museum
# 614 "data/maps/PewterCity/scripts.pory"
	delay_8
# 615 "data/maps/PewterCity/scripts.pory"
	walk_in_place_faster_up
# 616 "data/maps/PewterCity/scripts.pory"
	step_end
# 617 "data/maps/PewterCity/scripts.pory"

# 618 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_GuideWalkToMuseumEast::
# 619 "data/maps/PewterCity/scripts.pory"
	walk_to_museum
# 620 "data/maps/PewterCity/scripts.pory"
	walk_left
# 621 "data/maps/PewterCity/scripts.pory"
	walk_in_place_faster_up
# 622 "data/maps/PewterCity/scripts.pory"
	step_end
# 623 "data/maps/PewterCity/scripts.pory"

# 624 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_MuseumGuideExit::
# 625 "data/maps/PewterCity/scripts.pory"
	walk_down
# 626 "data/maps/PewterCity/scripts.pory"
	walk_right
# 627 "data/maps/PewterCity/scripts.pory"
	walk_right
# 628 "data/maps/PewterCity/scripts.pory"
	walk_right
# 629 "data/maps/PewterCity/scripts.pory"
	walk_right
# 630 "data/maps/PewterCity/scripts.pory"
	walk_right
# 631 "data/maps/PewterCity/scripts.pory"
	walk_right
# 632 "data/maps/PewterCity/scripts.pory"
	walk_right
# 633 "data/maps/PewterCity/scripts.pory"
	walk_down
# 634 "data/maps/PewterCity/scripts.pory"
	walk_down
# 635 "data/maps/PewterCity/scripts.pory"
	walk_down
# 636 "data/maps/PewterCity/scripts.pory"
	walk_right
# 637 "data/maps/PewterCity/scripts.pory"
	walk_right
# 638 "data/maps/PewterCity/scripts.pory"
	walk_right
# 639 "data/maps/PewterCity/scripts.pory"
	step_end
# 640 "data/maps/PewterCity/scripts.pory"

# 641 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_FatMan::
# 642 "data/maps/PewterCity/scripts.pory"
	lock
# 643 "data/maps/PewterCity/scripts.pory"
	faceplayer
# 644 "data/maps/PewterCity/scripts.pory"
	famechecker FAMECHECKER_BROCK, 2
# 645 "data/maps/PewterCity/scripts.pory"
	msgbox PewterCity_Text_BrockOnlySeriousTrainerHere
# 646 "data/maps/PewterCity/scripts.pory"
	release
# 647 "data/maps/PewterCity/scripts.pory"
	end
# 648 "data/maps/PewterCity/scripts.pory"

# 649 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_BugCatcher::
# 650 "data/maps/PewterCity/scripts.pory"
	lock
# 651 "data/maps/PewterCity/scripts.pory"
	faceplayer
# 652 "data/maps/PewterCity/scripts.pory"
	msgbox PewterCity_Text_DoYouKnowWhatImDoing, MSGBOX_YESNO
# 653 "data/maps/PewterCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, PewterCity_EventScript_KnowWhatTheyreDoing
# 654 "data/maps/PewterCity/scripts.pory"
	msgbox PewterCity_Text_SprayingRepelToKeepWildMonsOut
# 655 "data/maps/PewterCity/scripts.pory"
	release
# 656 "data/maps/PewterCity/scripts.pory"
	end
# 657 "data/maps/PewterCity/scripts.pory"

# 658 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_KnowWhatTheyreDoing::
# 659 "data/maps/PewterCity/scripts.pory"
	msgbox PewterCity_Text_ThatsRightItsHardWork
# 660 "data/maps/PewterCity/scripts.pory"
	release
# 661 "data/maps/PewterCity/scripts.pory"
	end
# 662 "data/maps/PewterCity/scripts.pory"

# 663 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_TrainerTips::
# 664 "data/maps/PewterCity/scripts.pory"
	msgbox PewterCity_Text_TrainerTipsEarningEXP, MSGBOX_SIGN
# 665 "data/maps/PewterCity/scripts.pory"
	end
# 666 "data/maps/PewterCity/scripts.pory"

# 667 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_PoliceNotice::
# 668 "data/maps/PewterCity/scripts.pory"
	msgbox PewterCity_Text_CallPoliceIfInfoOnThieves, MSGBOX_SIGN
# 669 "data/maps/PewterCity/scripts.pory"
	end
# 670 "data/maps/PewterCity/scripts.pory"

# 671 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_MuseumSign::
# 672 "data/maps/PewterCity/scripts.pory"
	msgbox PewterCity_Text_MuseumOfScience, MSGBOX_SIGN
# 673 "data/maps/PewterCity/scripts.pory"
	end
# 674 "data/maps/PewterCity/scripts.pory"

# 675 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_GymSign::
# 676 "data/maps/PewterCity/scripts.pory"
	lockall
# 677 "data/maps/PewterCity/scripts.pory"
	famechecker FAMECHECKER_BROCK, 0
# 678 "data/maps/PewterCity/scripts.pory"
	msgbox PewterCity_Text_GymSign
# 679 "data/maps/PewterCity/scripts.pory"
	releaseall
# 680 "data/maps/PewterCity/scripts.pory"
	end
# 681 "data/maps/PewterCity/scripts.pory"

# 682 "data/maps/PewterCity/scripts.pory"
PewterCity_EventScript_CitySign::
# 683 "data/maps/PewterCity/scripts.pory"
	msgbox PewterCity_Text_CitySign, MSGBOX_SIGN
# 684 "data/maps/PewterCity/scripts.pory"
	end
# 685 "data/maps/PewterCity/scripts.pory"

# 686 "data/maps/PewterCity/scripts.pory"
@PewterCity_EventScript_RunningShoesAide::
# 687 "data/maps/PewterCity/scripts.pory"
@	lock
# 688 "data/maps/PewterCity/scripts.pory"
@	faceplayer
# 689 "data/maps/PewterCity/scripts.pory"
@	setvar VAR_TEMP_1, 0
# 690 "data/maps/PewterCity/scripts.pory"
@	call PewterCity_EventScript_AideGiveRunningShoes
# 691 "data/maps/PewterCity/scripts.pory"
@	release
# 692 "data/maps/PewterCity/scripts.pory"
@	end
# 693 "data/maps/PewterCity/scripts.pory"
@
# 694 "data/maps/PewterCity/scripts.pory"
@PewterCity_EventScript_RunningShoesAideTriggerTop::
# 695 "data/maps/PewterCity/scripts.pory"
@	lockall
# 696 "data/maps/PewterCity/scripts.pory"
@	setvar VAR_TEMP_1, 1
# 697 "data/maps/PewterCity/scripts.pory"
@	call PewterCity_EventScript_AideGiveRunningShoes
# 698 "data/maps/PewterCity/scripts.pory"
@	releaseall
# 699 "data/maps/PewterCity/scripts.pory"
@	end
# 700 "data/maps/PewterCity/scripts.pory"
@
# 701 "data/maps/PewterCity/scripts.pory"
@PewterCity_EventScript_RunningShoesAideTriggerMid::
# 702 "data/maps/PewterCity/scripts.pory"
@	lockall
# 703 "data/maps/PewterCity/scripts.pory"
@	setvar VAR_TEMP_1, 2
# 704 "data/maps/PewterCity/scripts.pory"
@	call PewterCity_EventScript_AideGiveRunningShoes
# 705 "data/maps/PewterCity/scripts.pory"
@	releaseall
# 706 "data/maps/PewterCity/scripts.pory"
@	end
# 707 "data/maps/PewterCity/scripts.pory"
@
# 708 "data/maps/PewterCity/scripts.pory"
@PewterCity_EventScript_RunningShoesAideTriggerBottom::
# 709 "data/maps/PewterCity/scripts.pory"
@	lockall
# 710 "data/maps/PewterCity/scripts.pory"
@	setvar VAR_TEMP_1, 3
# 711 "data/maps/PewterCity/scripts.pory"
@	call PewterCity_EventScript_AideGiveRunningShoes
# 712 "data/maps/PewterCity/scripts.pory"
@	releaseall
# 713 "data/maps/PewterCity/scripts.pory"
@	end
# 714 "data/maps/PewterCity/scripts.pory"
@
# 715 "data/maps/PewterCity/scripts.pory"
@PewterCity_EventScript_AideGiveRunningShoes::
# 716 "data/maps/PewterCity/scripts.pory"
@	return
# 717 "data/maps/PewterCity/scripts.pory"
@
# 718 "data/maps/PewterCity/scripts.pory"
@PewterCity_EventScript_AideNoticePlayer::
# 719 "data/maps/PewterCity/scripts.pory"
@	applymovement LOCALID_PEWTER_AIDE, Common_Movement_WalkInPlaceFasterDown
# 720 "data/maps/PewterCity/scripts.pory"
@	waitmovement 0
# 721 "data/maps/PewterCity/scripts.pory"
@	return
# 722 "data/maps/PewterCity/scripts.pory"

# 723 "data/maps/PewterCity/scripts.pory"
@ Aide already at player
# 724 "data/maps/PewterCity/scripts.pory"
@PewterCity_EventScript_AideApproachPlayer0::
# 725 "data/maps/PewterCity/scripts.pory"
@	closemessage
# 726 "data/maps/PewterCity/scripts.pory"
@	delay 20
# 727 "data/maps/PewterCity/scripts.pory"
@	return
# 728 "data/maps/PewterCity/scripts.pory"

# 729 "data/maps/PewterCity/scripts.pory"
@PewterCity_EventScript_AideApproachPlayer1::
# 730 "data/maps/PewterCity/scripts.pory"
@	closemessage
# 731 "data/maps/PewterCity/scripts.pory"
@	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 732 "data/maps/PewterCity/scripts.pory"
@	waitmovement 0
# 733 "data/maps/PewterCity/scripts.pory"
@	return
# 734 "data/maps/PewterCity/scripts.pory"
@
# 735 "data/maps/PewterCity/scripts.pory"
@PewterCity_EventScript_AideApproachPlayer2::
# 736 "data/maps/PewterCity/scripts.pory"
@	closemessage
# 737 "data/maps/PewterCity/scripts.pory"
@	applymovement LOCALID_PEWTER_AIDE, PewterCity_Movement_AideApproachPlayerMid
# 738 "data/maps/PewterCity/scripts.pory"
@	waitmovement 0
# 739 "data/maps/PewterCity/scripts.pory"
@	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 740 "data/maps/PewterCity/scripts.pory"
@	waitmovement 0
# 741 "data/maps/PewterCity/scripts.pory"
@	return
# 742 "data/maps/PewterCity/scripts.pory"
@
# 743 "data/maps/PewterCity/scripts.pory"
@PewterCity_EventScript_AideApproachPlayer3::
# 744 "data/maps/PewterCity/scripts.pory"
@	closemessage
# 745 "data/maps/PewterCity/scripts.pory"
@	applymovement LOCALID_PEWTER_AIDE, PewterCity_Movement_AideApproachPlayerBottom
# 746 "data/maps/PewterCity/scripts.pory"
@	waitmovement 0
# 747 "data/maps/PewterCity/scripts.pory"
@	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 748 "data/maps/PewterCity/scripts.pory"
@	waitmovement 0
# 749 "data/maps/PewterCity/scripts.pory"
@	return
# 750 "data/maps/PewterCity/scripts.pory"
@
# 751 "data/maps/PewterCity/scripts.pory"
@PewterCity_EventScript_AideExit0::
# 752 "data/maps/PewterCity/scripts.pory"
@	applymovement LOCALID_PEWTER_AIDE, PewterCity_Movement_AideExit0
# 753 "data/maps/PewterCity/scripts.pory"
@	waitmovement 0
# 754 "data/maps/PewterCity/scripts.pory"
@	return
# 755 "data/maps/PewterCity/scripts.pory"
@
# 756 "data/maps/PewterCity/scripts.pory"
@PewterCity_EventScript_AideExit1::
# 757 "data/maps/PewterCity/scripts.pory"
@	applymovement LOCALID_PEWTER_AIDE, PewterCity_Movement_AideExit1
# 758 "data/maps/PewterCity/scripts.pory"
@	waitmovement 0
# 759 "data/maps/PewterCity/scripts.pory"
@	return
# 760 "data/maps/PewterCity/scripts.pory"
@
# 761 "data/maps/PewterCity/scripts.pory"
@PewterCity_EventScript_AideExit2::
# 762 "data/maps/PewterCity/scripts.pory"
@	applymovement LOCALID_PEWTER_AIDE, PewterCity_Movement_AideExit2
# 763 "data/maps/PewterCity/scripts.pory"
@	waitmovement 0
# 764 "data/maps/PewterCity/scripts.pory"
@	return
# 765 "data/maps/PewterCity/scripts.pory"
@
# 766 "data/maps/PewterCity/scripts.pory"
@PewterCity_EventScript_AideExit3::
# 767 "data/maps/PewterCity/scripts.pory"
@	applymovement LOCALID_PEWTER_AIDE, PewterCity_Movement_AideExit3
# 768 "data/maps/PewterCity/scripts.pory"
@	waitmovement 0
# 769 "data/maps/PewterCity/scripts.pory"
@	return
# 770 "data/maps/PewterCity/scripts.pory"
@
# 771 "data/maps/PewterCity/scripts.pory"
@PewterCity_Movement_AideApproachPlayerMid::
# 772 "data/maps/PewterCity/scripts.pory"
@	delay_4
# 773 "data/maps/PewterCity/scripts.pory"
@	walk_down
# 774 "data/maps/PewterCity/scripts.pory"
@	step_end
# 775 "data/maps/PewterCity/scripts.pory"
@
# 776 "data/maps/PewterCity/scripts.pory"
@PewterCity_Movement_AideApproachPlayerBottom::
# 777 "data/maps/PewterCity/scripts.pory"
@	delay_4
# 778 "data/maps/PewterCity/scripts.pory"
@	walk_down
# 779 "data/maps/PewterCity/scripts.pory"
@	walk_down
# 780 "data/maps/PewterCity/scripts.pory"
@	step_end
# 781 "data/maps/PewterCity/scripts.pory"
@
# 782 "data/maps/PewterCity/scripts.pory"
@PewterCity_Movement_AideExit0::
# 783 "data/maps/PewterCity/scripts.pory"
@	walk_down
# 784 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 785 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 786 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 787 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 788 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 789 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 790 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 791 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 792 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 793 "data/maps/PewterCity/scripts.pory"
@	step_end
# 794 "data/maps/PewterCity/scripts.pory"
@
# 795 "data/maps/PewterCity/scripts.pory"
@PewterCity_Movement_AideExit1::
# 796 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 797 "data/maps/PewterCity/scripts.pory"
@	walk_down
# 798 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 799 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 800 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 801 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 802 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 803 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 804 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 805 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 806 "data/maps/PewterCity/scripts.pory"
@	step_end
# 807 "data/maps/PewterCity/scripts.pory"
@
# 808 "data/maps/PewterCity/scripts.pory"
@PewterCity_Movement_AideExit2::
# 809 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 810 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 811 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 812 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 813 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 814 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 815 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 816 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 817 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 818 "data/maps/PewterCity/scripts.pory"
@	step_end
# 819 "data/maps/PewterCity/scripts.pory"
@
# 820 "data/maps/PewterCity/scripts.pory"
@PewterCity_Movement_AideExit3::
# 821 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 822 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 823 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 824 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 825 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 826 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 827 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 828 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 829 "data/maps/PewterCity/scripts.pory"
@	walk_left
# 830 "data/maps/PewterCity/scripts.pory"
@	step_end
# 831 "data/maps/PewterCity/scripts.pory"

# 832 "data/maps/PewterCity/scripts.pory"
@ Unused
# 833 "data/maps/PewterCity/scripts.pory"
PewterCity_Movement_WalkInPlaceLeft::
# 834 "data/maps/PewterCity/scripts.pory"
	walk_in_place_left
# 835 "data/maps/PewterCity/scripts.pory"
	step_end
