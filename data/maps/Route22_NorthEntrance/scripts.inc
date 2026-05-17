# 1 "data/maps/Route22_NorthEntrance/scripts.pory"

# 2 "data/maps/Route22_NorthEntrance/scripts.pory"
Route22_NorthEntrance_MapScripts::
# 3 "data/maps/Route22_NorthEntrance/scripts.pory"
	.byte 0
# 4 "data/maps/Route22_NorthEntrance/scripts.pory"

# 5 "data/maps/Route22_NorthEntrance/scripts.pory"
Route22_NorthEntrance_EventScript_BoulderBadgeGuard::
# 6 "data/maps/Route22_NorthEntrance/scripts.pory"
	lock
# 7 "data/maps/Route22_NorthEntrance/scripts.pory"
	faceplayer
# 8 "data/maps/Route22_NorthEntrance/scripts.pory"
	setvar VAR_TEMP_1, 1
# 9 "data/maps/Route22_NorthEntrance/scripts.pory"
	bufferstdstring STR_VAR_1, STDSTRING_BOULDER_BADGE
# 10 "data/maps/Route22_NorthEntrance/scripts.pory"
	goto Route22_NorthEntrance_EventScript_BadgeGuard
# 11 "data/maps/Route22_NorthEntrance/scripts.pory"
	end
# 12 "data/maps/Route22_NorthEntrance/scripts.pory"

# 13 "data/maps/Route22_NorthEntrance/scripts.pory"
Route22_NorthEntrance_EventScript_BoulderBadgeGuardTrigger::
# 14 "data/maps/Route22_NorthEntrance/scripts.pory"
	lockall
# 15 "data/maps/Route22_NorthEntrance/scripts.pory"
	setvar VAR_TEMP_1, 1
# 16 "data/maps/Route22_NorthEntrance/scripts.pory"
	setvar VAR_0x8009, 1
# 17 "data/maps/Route22_NorthEntrance/scripts.pory"
	bufferstdstring STR_VAR_1, STDSTRING_BOULDER_BADGE
# 18 "data/maps/Route22_NorthEntrance/scripts.pory"
	goto Route23_EventScript_BadgeGuardTrigger
# 19 "data/maps/Route22_NorthEntrance/scripts.pory"
	end
# 20 "data/maps/Route22_NorthEntrance/scripts.pory"

# 21 "data/maps/Route22_NorthEntrance/scripts.pory"
Route22_NorthEntrance_EventScript_Woman::
# 22 "data/maps/Route22_NorthEntrance/scripts.pory"
	lock
# 23 "data/maps/Route22_NorthEntrance/scripts.pory"
	faceplayer
# 24 "data/maps/Route22_NorthEntrance/scripts.pory"
	goto_if_set FLAG_GOT_TM121, Route22_NorthEntrance_EventScript_ExplainTM121
# 25 "data/maps/Route22_NorthEntrance/scripts.pory"
	msgbox Route22_NorthEntrance_Text_CanIConfide, MSGBOX_YESNO
# 26 "data/maps/Route22_NorthEntrance/scripts.pory"
	goto_if_eq VAR_RESULT, YES, Route22_NorthEntrance_EventScript_Confide
# 27 "data/maps/Route22_NorthEntrance/scripts.pory"
	goto_if_eq VAR_RESULT, NO, Route22_NorthEntrance_EventScript_DeclineConfide
# 28 "data/maps/Route22_NorthEntrance/scripts.pory"
	end
# 29 "data/maps/Route22_NorthEntrance/scripts.pory"

# 30 "data/maps/Route22_NorthEntrance/scripts.pory"
Route22_NorthEntrance_EventScript_NoRoomForTM121::
# 31 "data/maps/Route22_NorthEntrance/scripts.pory"
	msgbox Route22_NorthEntrance_Text_DontHaveRoomForThis
# 32 "data/maps/Route22_NorthEntrance/scripts.pory"
	release
# 33 "data/maps/Route22_NorthEntrance/scripts.pory"
	end
# 34 "data/maps/Route22_NorthEntrance/scripts.pory"

# 35 "data/maps/Route22_NorthEntrance/scripts.pory"
Route22_NorthEntrance_EventScript_ExplainTM121::
# 36 "data/maps/Route22_NorthEntrance/scripts.pory"
	msgbox Route22_NorthEntrance_Text_ExplainTM121
# 37 "data/maps/Route22_NorthEntrance/scripts.pory"
	release
# 38 "data/maps/Route22_NorthEntrance/scripts.pory"
	end
# 39 "data/maps/Route22_NorthEntrance/scripts.pory"

# 40 "data/maps/Route22_NorthEntrance/scripts.pory"
Route22_NorthEntrance_EventScript_Confide::
# 41 "data/maps/Route22_NorthEntrance/scripts.pory"
	msgbox Route22_NorthEntrance_Text_Confide
# 42 "data/maps/Route22_NorthEntrance/scripts.pory"
	checkitemspace ITEM_TM121
# 43 "data/maps/Route22_NorthEntrance/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, Route22_NorthEntrance_EventScript_NoRoomForTM121
# 44 "data/maps/Route22_NorthEntrance/scripts.pory"
	giveitem_msg Route22_NorthEntrance_Text_ReceivedTM121FromGirl, ITEM_TM121
# 45 "data/maps/Route22_NorthEntrance/scripts.pory"
	msgbox Route22_NorthEntrance_Text_ExplainTM121
# 46 "data/maps/Route22_NorthEntrance/scripts.pory"
	setflag FLAG_GOT_TM121
# 47 "data/maps/Route22_NorthEntrance/scripts.pory"
	release
# 48 "data/maps/Route22_NorthEntrance/scripts.pory"
	end
# 49 "data/maps/Route22_NorthEntrance/scripts.pory"

# 50 "data/maps/Route22_NorthEntrance/scripts.pory"
Route22_NorthEntrance_EventScript_DeclineConfide::
# 51 "data/maps/Route22_NorthEntrance/scripts.pory"
	msgbox Route22_NorthEntrance_Text_OfCourseNot
# 52 "data/maps/Route22_NorthEntrance/scripts.pory"
	release
# 53 "data/maps/Route22_NorthEntrance/scripts.pory"
	end
