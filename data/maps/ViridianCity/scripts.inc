# 1 "data/maps/ViridianCity/scripts.pory"

# 2 "data/maps/ViridianCity/scripts.pory"
ViridianCity_MapScripts::
# 3 "data/maps/ViridianCity/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, ViridianCity_OnLoad
# 4 "data/maps/ViridianCity/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianCity_OnTransition
# 5 "data/maps/ViridianCity/scripts.pory"
	.byte 0
# 6 "data/maps/ViridianCity/scripts.pory"

# 7 "data/maps/ViridianCity/scripts.pory"
ViridianCity_OnTransition::
# 8 "data/maps/ViridianCity/scripts.pory"
	setworldmapflag FLAG_WORLD_MAP_VIRIDIAN_CITY
# 9 "data/maps/ViridianCity/scripts.pory"
	call_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 0, ViridianCity_EventScript_SetOldManBlockingRoad
# 10 "data/maps/ViridianCity/scripts.pory"
	call_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 1, ViridianCity_EventScript_SetOldManStandingByRoad
# 11 "data/maps/ViridianCity/scripts.pory"
	call_if_ge VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 2, ViridianCity_EventScript_SetOldManNormal
# 12 "data/maps/ViridianCity/scripts.pory"
	call_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_GYM_DOOR, 0, ViridianCity_EventScript_TryUnlockGym
# 13 "data/maps/ViridianCity/scripts.pory"
	end
# 14 "data/maps/ViridianCity/scripts.pory"

# 15 "data/maps/ViridianCity/scripts.pory"
ViridianCity_OnLoad::
# 16 "data/maps/ViridianCity/scripts.pory"
	special SetRoofBirds
# 17 "data/maps/ViridianCity/scripts.pory"
	end
# 18 "data/maps/ViridianCity/scripts.pory"

# 19 "data/maps/ViridianCity/scripts.pory"
ViridianCity_EventScript_SetOldManNormal::
# 20 "data/maps/ViridianCity/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_OLD_MAN_1
# 21 "data/maps/ViridianCity/scripts.pory"
	return
# 22 "data/maps/ViridianCity/scripts.pory"

# 23 "data/maps/ViridianCity/scripts.pory"
ViridianCity_EventScript_SetOldManStandingByRoad::
# 24 "data/maps/ViridianCity/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_OLD_MAN_1
# 25 "data/maps/ViridianCity/scripts.pory"
	setobjectxyperm LOCALID_TUTORIAL_MAN, 21, 8
# 26 "data/maps/ViridianCity/scripts.pory"
	setobjectmovementtype LOCALID_TUTORIAL_MAN, MOVEMENT_TYPE_LOOK_AROUND
# 27 "data/maps/ViridianCity/scripts.pory"
	return
# 28 "data/maps/ViridianCity/scripts.pory"

# 29 "data/maps/ViridianCity/scripts.pory"
ViridianCity_EventScript_SetOldManBlockingRoad::
# 30 "data/maps/ViridianCity/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_OLD_MAN_LYING_DOWN
# 31 "data/maps/ViridianCity/scripts.pory"
	setobjectxyperm LOCALID_TUTORIAL_MAN, 21, 11
# 32 "data/maps/ViridianCity/scripts.pory"
	setobjectmovementtype LOCALID_TUTORIAL_MAN, MOVEMENT_TYPE_FACE_DOWN
# 33 "data/maps/ViridianCity/scripts.pory"
	return
# 34 "data/maps/ViridianCity/scripts.pory"

# 35 "data/maps/ViridianCity/scripts.pory"
ViridianCity_EventScript_TryUnlockGym::
# 36 "data/maps/ViridianCity/scripts.pory"
	goto_if_unset FLAG_BADGE02_GET, EventScript_Return
# 37 "data/maps/ViridianCity/scripts.pory"
	goto_if_unset FLAG_BADGE03_GET, EventScript_Return
# 38 "data/maps/ViridianCity/scripts.pory"
	goto_if_unset FLAG_BADGE04_GET, EventScript_Return
# 39 "data/maps/ViridianCity/scripts.pory"
	goto_if_unset FLAG_BADGE05_GET, EventScript_Return
# 40 "data/maps/ViridianCity/scripts.pory"
	goto_if_unset FLAG_BADGE06_GET, EventScript_Return
# 41 "data/maps/ViridianCity/scripts.pory"
	goto_if_unset FLAG_BADGE07_GET, EventScript_Return
# 42 "data/maps/ViridianCity/scripts.pory"
	setvar VAR_MAP_SCENE_VIRIDIAN_CITY_GYM_DOOR, 1
# 43 "data/maps/ViridianCity/scripts.pory"
	return
# 44 "data/maps/ViridianCity/scripts.pory"

# 45 "data/maps/ViridianCity/scripts.pory"
ViridianCity_EventScript_GymDoorLocked::
# 46 "data/maps/ViridianCity/scripts.pory"
	lockall
# 47 "data/maps/ViridianCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 48 "data/maps/ViridianCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 49 "data/maps/ViridianCity/scripts.pory"
	waitmovement 0
# 50 "data/maps/ViridianCity/scripts.pory"
	delay 20
# 51 "data/maps/ViridianCity/scripts.pory"
	msgbox ViridianCity_Text_GymDoorsAreLocked
# 52 "data/maps/ViridianCity/scripts.pory"
	closemessage
# 53 "data/maps/ViridianCity/scripts.pory"
	applymovement LOCALID_PLAYER, ViridianCity_Movement_JumpDownLedge
# 54 "data/maps/ViridianCity/scripts.pory"
	waitmovement 0
# 55 "data/maps/ViridianCity/scripts.pory"
	releaseall
# 56 "data/maps/ViridianCity/scripts.pory"
	end
# 57 "data/maps/ViridianCity/scripts.pory"

# 58 "data/maps/ViridianCity/scripts.pory"
ViridianCity_Movement_JumpDownLedge::
# 59 "data/maps/ViridianCity/scripts.pory"
	jump_2_down
# 60 "data/maps/ViridianCity/scripts.pory"
	step_end
# 61 "data/maps/ViridianCity/scripts.pory"

# 62 "data/maps/ViridianCity/scripts.pory"
ViridianCity_EventScript_CitySign::
# 63 "data/maps/ViridianCity/scripts.pory"
	msgbox ViridianCity_Text_CitySign, MSGBOX_SIGN
# 64 "data/maps/ViridianCity/scripts.pory"
	end
# 65 "data/maps/ViridianCity/scripts.pory"

# 66 "data/maps/ViridianCity/scripts.pory"
ViridianCity_EventScript_SchoolSign::
# 67 "data/maps/ViridianCity/scripts.pory"
	msgbox ViridianCity_Text_SchoolSign, MSGBOX_SIGN
# 68 "data/maps/ViridianCity/scripts.pory"
	end
# 69 "data/maps/ViridianCity/scripts.pory"

# 70 "data/maps/ViridianCity/scripts.pory"
ViridianCity_EventScript_TrainerTips1::
# 71 "data/maps/ViridianCity/scripts.pory"
	msgbox ViridianCity_Text_CatchMonsForEasierBattles, MSGBOX_SIGN
# 72 "data/maps/ViridianCity/scripts.pory"
	end
# 73 "data/maps/ViridianCity/scripts.pory"

# 74 "data/maps/ViridianCity/scripts.pory"
ViridianCity_EventScript_TrainerTips2::
# 75 "data/maps/ViridianCity/scripts.pory"
	msgbox ViridianCity_Text_MovesLimitedByPP, MSGBOX_SIGN
# 76 "data/maps/ViridianCity/scripts.pory"
	end
# 77 "data/maps/ViridianCity/scripts.pory"

# 78 "data/maps/ViridianCity/scripts.pory"
ViridianCity_EventScript_GymSign::
# 79 "data/maps/ViridianCity/scripts.pory"
	msgbox ViridianCity_Text_GymSign, MSGBOX_SIGN
# 80 "data/maps/ViridianCity/scripts.pory"
	end
# 81 "data/maps/ViridianCity/scripts.pory"

# 82 "data/maps/ViridianCity/scripts.pory"
ViridianCity_EventScript_GymDoor::
# 83 "data/maps/ViridianCity/scripts.pory"
	msgbox ViridianCity_Text_GymDoorsAreLocked, MSGBOX_SIGN
# 84 "data/maps/ViridianCity/scripts.pory"
	end
# 85 "data/maps/ViridianCity/scripts.pory"

# 86 "data/maps/ViridianCity/scripts.pory"
ViridianCity_EventScript_Boy::
# 87 "data/maps/ViridianCity/scripts.pory"
	msgbox ViridianCity_Text_CanCarryMonsAnywhere, MSGBOX_NPC
# 88 "data/maps/ViridianCity/scripts.pory"
	end
# 89 "data/maps/ViridianCity/scripts.pory"

# 90 "data/maps/ViridianCity/scripts.pory"
@ Other old man, not the tutorial old man
# 91 "data/maps/ViridianCity/scripts.pory"
ViridianCity_EventScript_OldMan::
# 92 "data/maps/ViridianCity/scripts.pory"
	lock
# 93 "data/maps/ViridianCity/scripts.pory"
	faceplayer
# 94 "data/maps/ViridianCity/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_GYM_DOOR, 1, ViridianCity_EventScript_OldManGymLeaderReturned
# 95 "data/maps/ViridianCity/scripts.pory"
	msgbox ViridianCity_Text_GymClosedWonderWhoLeaderIs
# 96 "data/maps/ViridianCity/scripts.pory"
	closemessage
# 97 "data/maps/ViridianCity/scripts.pory"
	applymovement LOCALID_VIRIDIAN_OLD_MAN, Common_Movement_FaceOriginalDirection
# 98 "data/maps/ViridianCity/scripts.pory"
	waitmovement 0
# 99 "data/maps/ViridianCity/scripts.pory"
	release
# 100 "data/maps/ViridianCity/scripts.pory"
	end
# 101 "data/maps/ViridianCity/scripts.pory"

# 102 "data/maps/ViridianCity/scripts.pory"
ViridianCity_EventScript_OldManGymLeaderReturned::
# 103 "data/maps/ViridianCity/scripts.pory"
	msgbox ViridianCity_Text_ViridiansGymLeaderReturned
# 104 "data/maps/ViridianCity/scripts.pory"
	release
# 105 "data/maps/ViridianCity/scripts.pory"
	end
# 106 "data/maps/ViridianCity/scripts.pory"

# 107 "data/maps/ViridianCity/scripts.pory"
ViridianCity_EventScript_TutorialOldMan::
# 108 "data/maps/ViridianCity/scripts.pory"
	lock
# 109 "data/maps/ViridianCity/scripts.pory"
	faceplayer
# 110 "data/maps/ViridianCity/scripts.pory"
	goto_if_set FLAG_BADGE01_GET, ViridianCity_EventScript_AskIfTeachyTVHelpful
# 111 "data/maps/ViridianCity/scripts.pory"
	goto_if_ge VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 2, ViridianCity_EventScript_TutorialCompleted
# 112 "data/maps/ViridianCity/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 1, ViridianCity_EventScript_TutorialStart
# 113 "data/maps/ViridianCity/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 0, ViridianCity_EventScript_TutorialNotReady
# 114 "data/maps/ViridianCity/scripts.pory"
	end
# 115 "data/maps/ViridianCity/scripts.pory"

# 116 "data/maps/ViridianCity/scripts.pory"
ViridianCity_EventScript_AskIfTeachyTVHelpful::
# 117 "data/maps/ViridianCity/scripts.pory"
	msgbox ViridianCity_Text_HowsTeachyTVHelping, MSGBOX_YESNO
# 118 "data/maps/ViridianCity/scripts.pory"
	goto_if_eq VAR_RESULT, NO, ViridianCity_EventScript_TeachyTVNotHelpful
# 119 "data/maps/ViridianCity/scripts.pory"
	msgbox ViridianCity_Text_MyGrandsonOnTheShow
# 120 "data/maps/ViridianCity/scripts.pory"
	release
# 121 "data/maps/ViridianCity/scripts.pory"
	end
# 122 "data/maps/ViridianCity/scripts.pory"

# 123 "data/maps/ViridianCity/scripts.pory"
ViridianCity_EventScript_TeachyTVNotHelpful::
# 124 "data/maps/ViridianCity/scripts.pory"
	msgbox ViridianCity_Text_TooBusyForTeachyTV
# 125 "data/maps/ViridianCity/scripts.pory"
	release
# 126 "data/maps/ViridianCity/scripts.pory"
	end
# 127 "data/maps/ViridianCity/scripts.pory"

# 128 "data/maps/ViridianCity/scripts.pory"
ViridianCity_EventScript_TutorialCompleted::
# 129 "data/maps/ViridianCity/scripts.pory"
	msgbox ViridianCity_Text_WeakenMonsFirstToCatch
# 130 "data/maps/ViridianCity/scripts.pory"
	release
# 131 "data/maps/ViridianCity/scripts.pory"
	end
# 132 "data/maps/ViridianCity/scripts.pory"

# 133 "data/maps/ViridianCity/scripts.pory"
ViridianCity_EventScript_TutorialStart::
# 134 "data/maps/ViridianCity/scripts.pory"
	call ViridianCity_EventScript_DoTutorialBattle
# 135 "data/maps/ViridianCity/scripts.pory"
	release
# 136 "data/maps/ViridianCity/scripts.pory"
	end
# 137 "data/maps/ViridianCity/scripts.pory"

# 138 "data/maps/ViridianCity/scripts.pory"
@ Unused
# 139 "data/maps/ViridianCity/scripts.pory"
ViridianCity_EventScript_WatchToLearnBasics::
# 140 "data/maps/ViridianCity/scripts.pory"
	msgbox ViridianCity_Text_WatchThatToLearnBasics
# 141 "data/maps/ViridianCity/scripts.pory"
	release
# 142 "data/maps/ViridianCity/scripts.pory"
	end
# 143 "data/maps/ViridianCity/scripts.pory"

# 144 "data/maps/ViridianCity/scripts.pory"
@ Unused. Starts battle after the post battle text, which is odd.
# 145 "data/maps/ViridianCity/scripts.pory"
ViridianCity_EventScript_TutorialUnused::
# 146 "data/maps/ViridianCity/scripts.pory"
	msgbox ViridianCity_Text_ThatWasEducationalTakeThis
# 147 "data/maps/ViridianCity/scripts.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 148 "data/maps/ViridianCity/scripts.pory"
	special QuestLog_CutRecording
# 149 "data/maps/ViridianCity/scripts.pory"
	special StartOldManTutorialBattle
# 150 "data/maps/ViridianCity/scripts.pory"
	waitstate
# 151 "data/maps/ViridianCity/scripts.pory"
	release
# 152 "data/maps/ViridianCity/scripts.pory"
	end
# 153 "data/maps/ViridianCity/scripts.pory"

# 154 "data/maps/ViridianCity/scripts.pory"
ViridianCity_EventScript_TutorialNotReady::
# 155 "data/maps/ViridianCity/scripts.pory"
	msgbox ViridianCity_Text_ThisIsPrivateProperty
# 156 "data/maps/ViridianCity/scripts.pory"
	closemessage
# 157 "data/maps/ViridianCity/scripts.pory"
	release
# 158 "data/maps/ViridianCity/scripts.pory"
	end
# 159 "data/maps/ViridianCity/scripts.pory"

# 160 "data/maps/ViridianCity/scripts.pory"
ViridianCity_EventScript_Youngster::
# 161 "data/maps/ViridianCity/scripts.pory"
	lock
# 162 "data/maps/ViridianCity/scripts.pory"
	faceplayer
# 163 "data/maps/ViridianCity/scripts.pory"
	msgbox ViridianCity_Text_WantToKnowAboutCaterpillarMons, MSGBOX_YESNO
# 164 "data/maps/ViridianCity/scripts.pory"
	goto_if_eq VAR_RESULT, YES, ViridianCity_EventScript_YoungsterExplainCaterpillars
# 165 "data/maps/ViridianCity/scripts.pory"
	goto_if_eq VAR_RESULT, NO, ViridianCity_EventScript_YoungsterDeclineExplanation
# 166 "data/maps/ViridianCity/scripts.pory"
	end
# 167 "data/maps/ViridianCity/scripts.pory"

# 168 "data/maps/ViridianCity/scripts.pory"
ViridianCity_EventScript_YoungsterExplainCaterpillars::
# 169 "data/maps/ViridianCity/scripts.pory"
	msgbox ViridianCity_Text_ExplainCaterpieWeedle
# 170 "data/maps/ViridianCity/scripts.pory"
	release
# 171 "data/maps/ViridianCity/scripts.pory"
	end
# 172 "data/maps/ViridianCity/scripts.pory"

# 173 "data/maps/ViridianCity/scripts.pory"
ViridianCity_EventScript_YoungsterDeclineExplanation::
# 174 "data/maps/ViridianCity/scripts.pory"
	msgbox ViridianCity_Text_OhOkayThen
# 175 "data/maps/ViridianCity/scripts.pory"
	release
# 176 "data/maps/ViridianCity/scripts.pory"
	end
# 177 "data/maps/ViridianCity/scripts.pory"

# 178 "data/maps/ViridianCity/scripts.pory"
ViridianCity_EventScript_Woman::
# 179 "data/maps/ViridianCity/scripts.pory"
	lock
# 180 "data/maps/ViridianCity/scripts.pory"
	faceplayer
# 181 "data/maps/ViridianCity/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 0, ViridianCity_EventScript_WomanRoadBlocked
# 182 "data/maps/ViridianCity/scripts.pory"
	msgbox ViridianCity_Text_GoShoppingInPewterOccasionally
# 183 "data/maps/ViridianCity/scripts.pory"
	release
# 184 "data/maps/ViridianCity/scripts.pory"
	end
# 185 "data/maps/ViridianCity/scripts.pory"

# 186 "data/maps/ViridianCity/scripts.pory"
ViridianCity_EventScript_WomanRoadBlocked::
# 187 "data/maps/ViridianCity/scripts.pory"
	msgbox ViridianCity_Text_GrandpaHasntHadCoffeeYet
# 188 "data/maps/ViridianCity/scripts.pory"
	closemessage
# 189 "data/maps/ViridianCity/scripts.pory"
	applymovement LOCALID_VIRIDIAN_WOMAN, Common_Movement_FaceOriginalDirection
# 190 "data/maps/ViridianCity/scripts.pory"
	waitmovement 0
# 191 "data/maps/ViridianCity/scripts.pory"
	release
# 192 "data/maps/ViridianCity/scripts.pory"
	end
# 193 "data/maps/ViridianCity/scripts.pory"

# 194 "data/maps/ViridianCity/scripts.pory"
ViridianCity_EventScript_DreamEaterTutor::
# 195 "data/maps/ViridianCity/scripts.pory"
	goto EventScript_DreamEaterTutor
# 196 "data/maps/ViridianCity/scripts.pory"
	end
# 197 "data/maps/ViridianCity/scripts.pory"

# 198 "data/maps/ViridianCity/scripts.pory"
ViridianCity_EventScript_RoadBlocked::
# 199 "data/maps/ViridianCity/scripts.pory"
	lockall
# 200 "data/maps/ViridianCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 201 "data/maps/ViridianCity/scripts.pory"
	msgbox ViridianCity_Text_ThisIsPrivateProperty
# 202 "data/maps/ViridianCity/scripts.pory"
	closemessage
# 203 "data/maps/ViridianCity/scripts.pory"
	applymovement LOCALID_PLAYER, ViridianCity_Movement_WalkDown
# 204 "data/maps/ViridianCity/scripts.pory"
	waitmovement 0
# 205 "data/maps/ViridianCity/scripts.pory"
	releaseall
# 206 "data/maps/ViridianCity/scripts.pory"
	end
# 207 "data/maps/ViridianCity/scripts.pory"

# 208 "data/maps/ViridianCity/scripts.pory"
ViridianCity_Movement_WalkDown::
# 209 "data/maps/ViridianCity/scripts.pory"
	walk_down
# 210 "data/maps/ViridianCity/scripts.pory"
	step_end
# 211 "data/maps/ViridianCity/scripts.pory"

# 212 "data/maps/ViridianCity/scripts.pory"
ViridianCity_EventScript_TutorialTriggerLeft::
# 213 "data/maps/ViridianCity/scripts.pory"
	lockall
# 214 "data/maps/ViridianCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 215 "data/maps/ViridianCity/scripts.pory"
	applymovement LOCALID_TUTORIAL_MAN, Common_Movement_WalkInPlaceFasterLeft
# 216 "data/maps/ViridianCity/scripts.pory"
	waitmovement 0
# 217 "data/maps/ViridianCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 218 "data/maps/ViridianCity/scripts.pory"
	waitmovement 0
# 219 "data/maps/ViridianCity/scripts.pory"
	call ViridianCity_EventScript_DoTutorialBattle
# 220 "data/maps/ViridianCity/scripts.pory"
	release
# 221 "data/maps/ViridianCity/scripts.pory"
	end
# 222 "data/maps/ViridianCity/scripts.pory"

# 223 "data/maps/ViridianCity/scripts.pory"
ViridianCity_EventScript_TutorialTriggerRight::
# 224 "data/maps/ViridianCity/scripts.pory"
	lockall
# 225 "data/maps/ViridianCity/scripts.pory"
	textcolor NPC_TEXT_COLOR_MALE
# 226 "data/maps/ViridianCity/scripts.pory"
	applymovement LOCALID_TUTORIAL_MAN, Common_Movement_WalkInPlaceFasterRight
# 227 "data/maps/ViridianCity/scripts.pory"
	waitmovement 0
# 228 "data/maps/ViridianCity/scripts.pory"
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceFasterLeft
# 229 "data/maps/ViridianCity/scripts.pory"
	waitmovement 0
# 230 "data/maps/ViridianCity/scripts.pory"
	call ViridianCity_EventScript_DoTutorialBattle
# 231 "data/maps/ViridianCity/scripts.pory"
	release
# 232 "data/maps/ViridianCity/scripts.pory"
	end
# 233 "data/maps/ViridianCity/scripts.pory"

# 234 "data/maps/ViridianCity/scripts.pory"
ViridianCity_EventScript_DoTutorialBattle::
# 235 "data/maps/ViridianCity/scripts.pory"
	msgbox ViridianCity_Text_ShowYouHowToCatchMons
# 236 "data/maps/ViridianCity/scripts.pory"
	closemessage
# 237 "data/maps/ViridianCity/scripts.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 238 "data/maps/ViridianCity/scripts.pory"
	special QuestLog_CutRecording
# 239 "data/maps/ViridianCity/scripts.pory"
	special StartOldManTutorialBattle
# 240 "data/maps/ViridianCity/scripts.pory"
	waitstate
# 241 "data/maps/ViridianCity/scripts.pory"
	lock
# 242 "data/maps/ViridianCity/scripts.pory"
	faceplayer
# 243 "data/maps/ViridianCity/scripts.pory"
	msgbox ViridianCity_Text_ThatWasEducationalTakeThis
# 244 "data/maps/ViridianCity/scripts.pory"
	setvar VAR_MAP_SCENE_VIRIDIAN_CITY_OLD_MAN, 2
# 245 "data/maps/ViridianCity/scripts.pory"
	giveitem ITEM_TEACHY_TV
# 246 "data/maps/ViridianCity/scripts.pory"
	msgbox ViridianCity_Text_WatchThatToLearnBasics
# 247 "data/maps/ViridianCity/scripts.pory"
	return
