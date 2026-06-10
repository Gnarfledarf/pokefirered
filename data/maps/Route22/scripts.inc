# 1 "data/maps/Route22/scripts.pory"

# 2 "data/maps/Route22/scripts.pory"
Route22_MapScripts::
# 3 "data/maps/Route22/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Route22_OnLoad
# 4 "data/maps/Route22/scripts.pory"
	.byte 0
# 5 "data/maps/Route22/scripts.pory"

# 6 "data/maps/Route22/scripts.pory"
Route22_OnLoad::
# 7 "data/maps/Route22/scripts.pory"
	special SetRoofBirds
# 8 "data/maps/Route22/scripts.pory"
	end
# 9 "data/maps/Route22/scripts.pory"

# 10 "data/maps/Route22/scripts.pory"
Route22_EventScript_EarlyRivalTriggerTop::
# 11 "data/maps/Route22/scripts.pory"
	lockall
# 12 "data/maps/Route22/scripts.pory"
	setvar VAR_TEMP_1, 0
# 13 "data/maps/Route22/scripts.pory"
	goto Route22_EventScript_EarlyRival
# 14 "data/maps/Route22/scripts.pory"
	end
# 15 "data/maps/Route22/scripts.pory"

# 16 "data/maps/Route22/scripts.pory"
Route22_EventScript_EarlyRivalTriggerMid::
# 17 "data/maps/Route22/scripts.pory"
	lockall
# 18 "data/maps/Route22/scripts.pory"
	setvar VAR_TEMP_1, 1
# 19 "data/maps/Route22/scripts.pory"
	setobjectxyperm LOCALID_ROUTE22_RIVAL, 25, 5
# 20 "data/maps/Route22/scripts.pory"
	goto Route22_EventScript_EarlyRival
# 21 "data/maps/Route22/scripts.pory"
	end
# 22 "data/maps/Route22/scripts.pory"

# 23 "data/maps/Route22/scripts.pory"
Route22_EventScript_EarlyRivalTriggerBottom::
# 24 "data/maps/Route22/scripts.pory"
	lockall
# 25 "data/maps/Route22/scripts.pory"
	setvar VAR_TEMP_1, 2
# 26 "data/maps/Route22/scripts.pory"
	setobjectxyperm LOCALID_ROUTE22_RIVAL, 25, 5
# 27 "data/maps/Route22/scripts.pory"
	goto Route22_EventScript_EarlyRival
# 28 "data/maps/Route22/scripts.pory"
	end
# 29 "data/maps/Route22/scripts.pory"

# 30 "data/maps/Route22/scripts.pory"
Route22_EventScript_EarlyRival::
# 31 "data/maps/Route22/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 32 "data/maps/Route22/scripts.pory"
	playbgm MUS_ENCOUNTER_RIVAL, 0
# 33 "data/maps/Route22/scripts.pory"
	addobject LOCALID_ROUTE22_RIVAL
# 34 "data/maps/Route22/scripts.pory"
	call_if_eq VAR_TEMP_1, 0, Route22_EventScript_EarlyRivalApproach
# 35 "data/maps/Route22/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, Route22_EventScript_EarlyRivalApproach
# 36 "data/maps/Route22/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, Route22_EventScript_EarlyRivalApproachBottom
# 37 "data/maps/Route22/scripts.pory"
	delay 6
# 38 "data/maps/Route22/scripts.pory"
	msgbox Route22_Text_EarlyRivalIntro
# 39 "data/maps/Route22/scripts.pory"
	call_if_eq VAR_STARTER_MON, 2, Route22_EventScript_EarlyRivalSquirtle
# 40 "data/maps/Route22/scripts.pory"
	call_if_eq VAR_STARTER_MON, 1, Route22_EventScript_EarlyRivalBulbasaur
# 41 "data/maps/Route22/scripts.pory"
	call_if_eq VAR_STARTER_MON, 0, Route22_EventScript_EarlyRivalCharmander
# 42 "data/maps/Route22/scripts.pory"
	msgbox Route22_Text_EarlyRivalPostBattle
# 43 "data/maps/Route22/scripts.pory"
	closemessage
# 44 "data/maps/Route22/scripts.pory"
	delay 10
# 45 "data/maps/Route22/scripts.pory"
	playbgm MUS_RIVAL_EXIT, 0
# 46 "data/maps/Route22/scripts.pory"
	call_if_eq VAR_TEMP_1, 0, Route22_EventScript_EarlyRivalExit
# 47 "data/maps/Route22/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, Route22_EventScript_EarlyRivalExit
# 48 "data/maps/Route22/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, Route22_EventScript_EarlyRivalExitBottom
# 49 "data/maps/Route22/scripts.pory"
	fadedefaultbgm
# 50 "data/maps/Route22/scripts.pory"
	removeobject LOCALID_ROUTE22_RIVAL
# 51 "data/maps/Route22/scripts.pory"
	setvar VAR_MAP_SCENE_ROUTE22, 2
# 52 "data/maps/Route22/scripts.pory"
	releaseall
# 53 "data/maps/Route22/scripts.pory"
	end
# 54 "data/maps/Route22/scripts.pory"

# 55 "data/maps/Route22/scripts.pory"
Route22_EventScript_EarlyRivalApproach::
# 56 "data/maps/Route22/scripts.pory"
	applymovement LOCALID_ROUTE22_RIVAL, Route22_Movement_RivalApproach
# 57 "data/maps/Route22/scripts.pory"
	waitmovement 0
# 58 "data/maps/Route22/scripts.pory"
	return
# 59 "data/maps/Route22/scripts.pory"

# 60 "data/maps/Route22/scripts.pory"
Route22_EventScript_EarlyRivalApproachBottom::
# 61 "data/maps/Route22/scripts.pory"
	applymovement LOCALID_ROUTE22_RIVAL, Route22_Movement_RivalApproachBottom
# 62 "data/maps/Route22/scripts.pory"
	applymovement LOCALID_PLAYER, Route22_Movement_PlayerFaceRival
# 63 "data/maps/Route22/scripts.pory"
	waitmovement 0
# 64 "data/maps/Route22/scripts.pory"
	return
# 65 "data/maps/Route22/scripts.pory"

# 66 "data/maps/Route22/scripts.pory"
Route22_EventScript_EarlyRivalSquirtle::
# 67 "data/maps/Route22/scripts.pory"
	trainerbattle_earlyrival TRAINER_RIVAL_ROUTE22_EARLY_SQUIRTLE, 0, Route22_Text_EarlyRivalDefeat, Text_RivalVictory
# 68 "data/maps/Route22/scripts.pory"
	return
# 69 "data/maps/Route22/scripts.pory"

# 70 "data/maps/Route22/scripts.pory"
Route22_EventScript_EarlyRivalBulbasaur::
# 71 "data/maps/Route22/scripts.pory"
	trainerbattle_earlyrival TRAINER_RIVAL_ROUTE22_EARLY_BULBASAUR, 0, Route22_Text_EarlyRivalDefeat, Text_RivalVictory
# 72 "data/maps/Route22/scripts.pory"
	return
# 73 "data/maps/Route22/scripts.pory"

# 74 "data/maps/Route22/scripts.pory"
Route22_EventScript_EarlyRivalCharmander::
# 75 "data/maps/Route22/scripts.pory"
	trainerbattle_earlyrival TRAINER_RIVAL_ROUTE22_EARLY_CHARMANDER, 0, Route22_Text_EarlyRivalDefeat, Text_RivalVictory
# 76 "data/maps/Route22/scripts.pory"
	return
# 77 "data/maps/Route22/scripts.pory"

# 78 "data/maps/Route22/scripts.pory"
Route22_EventScript_EarlyRivalExit::
# 79 "data/maps/Route22/scripts.pory"
	applymovement LOCALID_ROUTE22_RIVAL, Route22_Movement_EarlyRivalExit
# 80 "data/maps/Route22/scripts.pory"
	waitmovement 0
# 81 "data/maps/Route22/scripts.pory"
	return
# 82 "data/maps/Route22/scripts.pory"

# 83 "data/maps/Route22/scripts.pory"
Route22_EventScript_EarlyRivalExitBottom::
# 84 "data/maps/Route22/scripts.pory"
	applymovement LOCALID_ROUTE22_RIVAL, Route22_Movement_EarlyRivalExitBottom
# 85 "data/maps/Route22/scripts.pory"
	waitmovement 0
# 86 "data/maps/Route22/scripts.pory"
	return
# 87 "data/maps/Route22/scripts.pory"

# 88 "data/maps/Route22/scripts.pory"
Route22_Movement_UnusedRivalExit:: @ 8
# 89 "data/maps/Route22/scripts.pory"
	walk_right
# 90 "data/maps/Route22/scripts.pory"
	walk_right
# 91 "data/maps/Route22/scripts.pory"
	walk_right
# 92 "data/maps/Route22/scripts.pory"
	walk_right
# 93 "data/maps/Route22/scripts.pory"
	walk_right
# 94 "data/maps/Route22/scripts.pory"
	walk_right
# 95 "data/maps/Route22/scripts.pory"
	walk_right
# 96 "data/maps/Route22/scripts.pory"
	step_end
# 97 "data/maps/Route22/scripts.pory"

# 98 "data/maps/Route22/scripts.pory"
Route22_Movement_EarlyRivalExit::
# 99 "data/maps/Route22/scripts.pory"
	walk_down
# 100 "data/maps/Route22/scripts.pory"
	walk_right
# 101 "data/maps/Route22/scripts.pory"
	walk_right
# 102 "data/maps/Route22/scripts.pory"
	walk_right
# 103 "data/maps/Route22/scripts.pory"
	walk_right
# 104 "data/maps/Route22/scripts.pory"
	walk_right
# 105 "data/maps/Route22/scripts.pory"
	walk_down
# 106 "data/maps/Route22/scripts.pory"
	walk_down
# 107 "data/maps/Route22/scripts.pory"
	walk_down
# 108 "data/maps/Route22/scripts.pory"
	walk_down
# 109 "data/maps/Route22/scripts.pory"
	walk_down
# 110 "data/maps/Route22/scripts.pory"
	walk_down
# 111 "data/maps/Route22/scripts.pory"
	step_end
# 112 "data/maps/Route22/scripts.pory"

# 113 "data/maps/Route22/scripts.pory"
Route22_Movement_EarlyRivalExitBottom::
# 114 "data/maps/Route22/scripts.pory"
	walk_right
# 115 "data/maps/Route22/scripts.pory"
	walk_right
# 116 "data/maps/Route22/scripts.pory"
	walk_right
# 117 "data/maps/Route22/scripts.pory"
	walk_right
# 118 "data/maps/Route22/scripts.pory"
	walk_down
# 119 "data/maps/Route22/scripts.pory"
	walk_down
# 120 "data/maps/Route22/scripts.pory"
	walk_down
# 121 "data/maps/Route22/scripts.pory"
	walk_down
# 122 "data/maps/Route22/scripts.pory"
	walk_down
# 123 "data/maps/Route22/scripts.pory"
	walk_down
# 124 "data/maps/Route22/scripts.pory"
	walk_down
# 125 "data/maps/Route22/scripts.pory"
	step_end
# 126 "data/maps/Route22/scripts.pory"

# 127 "data/maps/Route22/scripts.pory"
Route22_Movement_RivalApproach::
# 128 "data/maps/Route22/scripts.pory"
	walk_right
# 129 "data/maps/Route22/scripts.pory"
	walk_right
# 130 "data/maps/Route22/scripts.pory"
	walk_right
# 131 "data/maps/Route22/scripts.pory"
	walk_right
# 132 "data/maps/Route22/scripts.pory"
	walk_right
# 133 "data/maps/Route22/scripts.pory"
	walk_right
# 134 "data/maps/Route22/scripts.pory"
	walk_right
# 135 "data/maps/Route22/scripts.pory"
	step_end
# 136 "data/maps/Route22/scripts.pory"

# 137 "data/maps/Route22/scripts.pory"
Route22_Movement_RivalApproachBottom::
# 138 "data/maps/Route22/scripts.pory"
	walk_right
# 139 "data/maps/Route22/scripts.pory"
	walk_right
# 140 "data/maps/Route22/scripts.pory"
	walk_right
# 141 "data/maps/Route22/scripts.pory"
	walk_right
# 142 "data/maps/Route22/scripts.pory"
	walk_right
# 143 "data/maps/Route22/scripts.pory"
	walk_right
# 144 "data/maps/Route22/scripts.pory"
	walk_right
# 145 "data/maps/Route22/scripts.pory"
	walk_right
# 146 "data/maps/Route22/scripts.pory"
	walk_in_place_faster_down
# 147 "data/maps/Route22/scripts.pory"
	step_end
# 148 "data/maps/Route22/scripts.pory"

# 149 "data/maps/Route22/scripts.pory"
Route22_Movement_PlayerFaceRival::
# 150 "data/maps/Route22/scripts.pory"
	delay_16
# 151 "data/maps/Route22/scripts.pory"
	delay_16
# 152 "data/maps/Route22/scripts.pory"
	delay_16
# 153 "data/maps/Route22/scripts.pory"
	delay_16
# 154 "data/maps/Route22/scripts.pory"
	delay_16
# 155 "data/maps/Route22/scripts.pory"
	delay_16
# 156 "data/maps/Route22/scripts.pory"
	delay_16
# 157 "data/maps/Route22/scripts.pory"
	delay_8
# 158 "data/maps/Route22/scripts.pory"
	walk_in_place_faster_up
# 159 "data/maps/Route22/scripts.pory"
	step_end
# 160 "data/maps/Route22/scripts.pory"

# 161 "data/maps/Route22/scripts.pory"
Route22_EventScript_LateRivalTriggerTop::
# 162 "data/maps/Route22/scripts.pory"
	lockall
# 163 "data/maps/Route22/scripts.pory"
	setvar VAR_TEMP_1, 0
# 164 "data/maps/Route22/scripts.pory"
	goto Route22_EventScript_LateRival
# 165 "data/maps/Route22/scripts.pory"
	end
# 166 "data/maps/Route22/scripts.pory"

# 167 "data/maps/Route22/scripts.pory"
Route22_EventScript_LateRivalTriggerMid::
# 168 "data/maps/Route22/scripts.pory"
	lockall
# 169 "data/maps/Route22/scripts.pory"
	setvar VAR_TEMP_1, 1
# 170 "data/maps/Route22/scripts.pory"
	setobjectxyperm LOCALID_ROUTE22_RIVAL, 25, 5
# 171 "data/maps/Route22/scripts.pory"
	goto Route22_EventScript_LateRival
# 172 "data/maps/Route22/scripts.pory"
	end
# 173 "data/maps/Route22/scripts.pory"

# 174 "data/maps/Route22/scripts.pory"
Route22_EventScript_LateRivalTriggerBottom::
# 175 "data/maps/Route22/scripts.pory"
	lockall
# 176 "data/maps/Route22/scripts.pory"
	setvar VAR_TEMP_1, 2
# 177 "data/maps/Route22/scripts.pory"
	setobjectxyperm LOCALID_ROUTE22_RIVAL, 25, 5
# 178 "data/maps/Route22/scripts.pory"
	goto Route22_EventScript_LateRival
# 179 "data/maps/Route22/scripts.pory"
	end
# 180 "data/maps/Route22/scripts.pory"

# 181 "data/maps/Route22/scripts.pory"
Route22_EventScript_LateRival::
# 182 "data/maps/Route22/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 183 "data/maps/Route22/scripts.pory"
	playbgm MUS_ENCOUNTER_RIVAL, 0
# 184 "data/maps/Route22/scripts.pory"
	addobject LOCALID_ROUTE22_RIVAL
# 185 "data/maps/Route22/scripts.pory"
	call_if_eq VAR_TEMP_1, 0, Route22_EventScript_LateRivalApproach
# 186 "data/maps/Route22/scripts.pory"
	call_if_eq VAR_TEMP_1, 1, Route22_EventScript_LateRivalApproach
# 187 "data/maps/Route22/scripts.pory"
	call_if_eq VAR_TEMP_1, 2, Route22_EventScript_LateRivalApproachBottom
# 188 "data/maps/Route22/scripts.pory"
	msgbox Route22_Text_LateRivalIntro
# 189 "data/maps/Route22/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_ROUTE22_RIVAL
# 190 "data/maps/Route22/scripts.pory"
	call_if_eq VAR_STARTER_MON, 2, Route22_EventScript_LateRivalSquirtle
# 191 "data/maps/Route22/scripts.pory"
	call_if_eq VAR_STARTER_MON, 1, Route22_EventScript_LateRivalBulbasaur
# 192 "data/maps/Route22/scripts.pory"
	call_if_eq VAR_STARTER_MON, 0, Route22_EventScript_LateRivalCharmander
# 193 "data/maps/Route22/scripts.pory"
	msgbox Route22_Text_LateRivalPostBattle
# 194 "data/maps/Route22/scripts.pory"
	closemessage
# 195 "data/maps/Route22/scripts.pory"
	delay 10
# 196 "data/maps/Route22/scripts.pory"
	playbgm MUS_RIVAL_EXIT, 0
# 197 "data/maps/Route22/scripts.pory"
	applymovement LOCALID_ROUTE22_RIVAL, Route22_Movement_LateRivalExit
# 198 "data/maps/Route22/scripts.pory"
	waitmovement 0
# 199 "data/maps/Route22/scripts.pory"
	fadedefaultbgm
# 200 "data/maps/Route22/scripts.pory"
	removeobject LOCALID_ROUTE22_RIVAL
# 201 "data/maps/Route22/scripts.pory"
	setvar VAR_MAP_SCENE_ROUTE22, 4
# 202 "data/maps/Route22/scripts.pory"
	releaseall
# 203 "data/maps/Route22/scripts.pory"
	end
# 204 "data/maps/Route22/scripts.pory"

# 205 "data/maps/Route22/scripts.pory"
Route22_EventScript_LateRivalApproach::
# 206 "data/maps/Route22/scripts.pory"
	applymovement LOCALID_ROUTE22_RIVAL, Route22_Movement_RivalApproach
# 207 "data/maps/Route22/scripts.pory"
	waitmovement 0
# 208 "data/maps/Route22/scripts.pory"
	return
# 209 "data/maps/Route22/scripts.pory"

# 210 "data/maps/Route22/scripts.pory"
Route22_EventScript_LateRivalApproachBottom::
# 211 "data/maps/Route22/scripts.pory"
	applymovement LOCALID_ROUTE22_RIVAL, Route22_Movement_RivalApproachBottom
# 212 "data/maps/Route22/scripts.pory"
	applymovement LOCALID_PLAYER, Route22_Movement_PlayerFaceRival
# 213 "data/maps/Route22/scripts.pory"
	waitmovement 0
# 214 "data/maps/Route22/scripts.pory"
	return
# 215 "data/maps/Route22/scripts.pory"

# 216 "data/maps/Route22/scripts.pory"
Route22_EventScript_LateRivalSquirtle::
# 217 "data/maps/Route22/scripts.pory"
	trainerbattle_no_intro TRAINER_RIVAL_ROUTE22_LATE_SQUIRTLE, Route22_Text_LateRivalDefeat
# 218 "data/maps/Route22/scripts.pory"
	return
# 219 "data/maps/Route22/scripts.pory"

# 220 "data/maps/Route22/scripts.pory"
Route22_EventScript_LateRivalBulbasaur::
# 221 "data/maps/Route22/scripts.pory"
	trainerbattle_no_intro TRAINER_RIVAL_ROUTE22_LATE_BULBASAUR, Route22_Text_LateRivalDefeat
# 222 "data/maps/Route22/scripts.pory"
	return
# 223 "data/maps/Route22/scripts.pory"

# 224 "data/maps/Route22/scripts.pory"
Route22_EventScript_LateRivalCharmander::
# 225 "data/maps/Route22/scripts.pory"
	trainerbattle_no_intro TRAINER_RIVAL_ROUTE22_LATE_CHARMANDER, Route22_Text_LateRivalDefeat
# 226 "data/maps/Route22/scripts.pory"
	return
# 227 "data/maps/Route22/scripts.pory"

# 228 "data/maps/Route22/scripts.pory"
Route22_Movement_LateRivalExit::
# 229 "data/maps/Route22/scripts.pory"
	walk_left
# 230 "data/maps/Route22/scripts.pory"
	walk_left
# 231 "data/maps/Route22/scripts.pory"
	walk_left
# 232 "data/maps/Route22/scripts.pory"
	walk_left
# 233 "data/maps/Route22/scripts.pory"
	walk_left
# 234 "data/maps/Route22/scripts.pory"
	walk_left
# 235 "data/maps/Route22/scripts.pory"
	walk_left
# 236 "data/maps/Route22/scripts.pory"
	step_end
# 237 "data/maps/Route22/scripts.pory"

# 238 "data/maps/Route22/scripts.pory"
Route22_EventScript_LeagueGateSign::
# 239 "data/maps/Route22/scripts.pory"
	msgbox Route22_Text_LeagueGateSign, MSGBOX_SIGN
# 240 "data/maps/Route22/scripts.pory"
	end
