# 1 "data/maps/TwoIsland_House/scripts.pory"

# 2 "data/maps/TwoIsland_House/scripts.pory"
.equ CHECKED_MUSHROOMS,  FLAG_TEMP_1
# 3 "data/maps/TwoIsland_House/scripts.pory"
.equ HAS_BIG_MUSHROOM,   FLAG_TEMP_2
# 4 "data/maps/TwoIsland_House/scripts.pory"
.equ HAS_TINY_MUSHROOMS, FLAG_TEMP_3
# 5 "data/maps/TwoIsland_House/scripts.pory"
.equ HAS_BOTH_MUSHROOMS, FLAG_TEMP_4
# 6 "data/maps/TwoIsland_House/scripts.pory"

# 7 "data/maps/TwoIsland_House/scripts.pory"
TwoIsland_House_MapScripts::
# 8 "data/maps/TwoIsland_House/scripts.pory"
	.byte 0
# 9 "data/maps/TwoIsland_House/scripts.pory"

# 10 "data/maps/TwoIsland_House/scripts.pory"
TwoIsland_House_EventScript_MoveManiac::
# 11 "data/maps/TwoIsland_House/scripts.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 12 "data/maps/TwoIsland_House/scripts.pory"
	special QuestLog_CutRecording
# 13 "data/maps/TwoIsland_House/scripts.pory"
	lock
# 14 "data/maps/TwoIsland_House/scripts.pory"
	faceplayer
# 15 "data/maps/TwoIsland_House/scripts.pory"
	clearflag HAS_BIG_MUSHROOM
# 16 "data/maps/TwoIsland_House/scripts.pory"
	clearflag HAS_TINY_MUSHROOMS
# 17 "data/maps/TwoIsland_House/scripts.pory"
	clearflag HAS_BOTH_MUSHROOMS
# 18 "data/maps/TwoIsland_House/scripts.pory"
	goto_if_set CHECKED_MUSHROOMS, TwoIsland_House_EventScript_CheckPlayerHasMushrooms
# 19 "data/maps/TwoIsland_House/scripts.pory"
	msgbox TwoIsland_House_Text_TeachMonMoveForMushroom
# 20 "data/maps/TwoIsland_House/scripts.pory"
	setflag CHECKED_MUSHROOMS
# 21 "data/maps/TwoIsland_House/scripts.pory"
	goto TwoIsland_House_EventScript_CheckPlayerHasMushrooms
# 22 "data/maps/TwoIsland_House/scripts.pory"
	end
# 23 "data/maps/TwoIsland_House/scripts.pory"

# 24 "data/maps/TwoIsland_House/scripts.pory"
TwoIsland_House_EventScript_CheckPlayerHasMushrooms::
# 25 "data/maps/TwoIsland_House/scripts.pory"
	checkitem ITEM_BIG_MUSHROOM
# 26 "data/maps/TwoIsland_House/scripts.pory"
	call_if_eq VAR_RESULT, TRUE, TwoIsland_House_EventScript_SetHasBigMushroom
# 27 "data/maps/TwoIsland_House/scripts.pory"
	checkitem ITEM_TINY_MUSHROOM, 2
# 28 "data/maps/TwoIsland_House/scripts.pory"
	call_if_eq VAR_RESULT, TRUE, TwoIsland_House_EventScript_SetHasTinyMushrooms
# 29 "data/maps/TwoIsland_House/scripts.pory"
	goto_if_set HAS_BIG_MUSHROOM, TwoIsland_House_EventScript_CheckAlsoHasTinyMushrooms
# 30 "data/maps/TwoIsland_House/scripts.pory"
	goto_if_set HAS_TINY_MUSHROOMS, TwoIsland_House_EventScript_CheckAlsoHasBigMushroom
# 31 "data/maps/TwoIsland_House/scripts.pory"
	goto TwoIsland_House_EventScript_EndTutorMove
# 32 "data/maps/TwoIsland_House/scripts.pory"
	end
# 33 "data/maps/TwoIsland_House/scripts.pory"

# 34 "data/maps/TwoIsland_House/scripts.pory"
TwoIsland_House_EventScript_CheckAlsoHasTinyMushrooms::
# 35 "data/maps/TwoIsland_House/scripts.pory"
	call_if_set HAS_TINY_MUSHROOMS, TwoIsland_House_EventScript_SetHasBothMushrooms
# 36 "data/maps/TwoIsland_House/scripts.pory"
	goto TwoIsland_House_EventScript_AskTutorMon
# 37 "data/maps/TwoIsland_House/scripts.pory"
	end
# 38 "data/maps/TwoIsland_House/scripts.pory"

# 39 "data/maps/TwoIsland_House/scripts.pory"
TwoIsland_House_EventScript_CheckAlsoHasBigMushroom::
# 40 "data/maps/TwoIsland_House/scripts.pory"
	call_if_set HAS_BIG_MUSHROOM, TwoIsland_House_EventScript_SetHasBothMushrooms
# 41 "data/maps/TwoIsland_House/scripts.pory"
	goto TwoIsland_House_EventScript_AskTutorMon
# 42 "data/maps/TwoIsland_House/scripts.pory"
	end
# 43 "data/maps/TwoIsland_House/scripts.pory"

# 44 "data/maps/TwoIsland_House/scripts.pory"
TwoIsland_House_EventScript_AskTutorMon::
# 45 "data/maps/TwoIsland_House/scripts.pory"
	msgbox TwoIsland_House_Text_WantMeToTeachMove, MSGBOX_YESNO
# 46 "data/maps/TwoIsland_House/scripts.pory"
	goto_if_eq VAR_RESULT, NO, TwoIsland_House_EventScript_EndTutorMove
# 47 "data/maps/TwoIsland_House/scripts.pory"
	goto TwoIsland_House_EventScript_ChooseMonToTutor
# 48 "data/maps/TwoIsland_House/scripts.pory"
	end
# 49 "data/maps/TwoIsland_House/scripts.pory"

# 50 "data/maps/TwoIsland_House/scripts.pory"
TwoIsland_House_EventScript_ChooseMonToTutor::
# 51 "data/maps/TwoIsland_House/scripts.pory"
	msgbox TwoIsland_House_Text_TutorWhichMon
# 52 "data/maps/TwoIsland_House/scripts.pory"
	special ChooseMonForMoveRelearner
# 53 "data/maps/TwoIsland_House/scripts.pory"
	waitstate
# 54 "data/maps/TwoIsland_House/scripts.pory"
	goto_if_ge VAR_0x8004, PARTY_SIZE, TwoIsland_House_EventScript_EndTutorMove
# 55 "data/maps/TwoIsland_House/scripts.pory"
	special IsSelectedMonEgg
# 56 "data/maps/TwoIsland_House/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, TwoIsland_House_EventScript_CantTutorEgg
# 57 "data/maps/TwoIsland_House/scripts.pory"
	special HasMovesToRelearn
# 58 "data/maps/TwoIsland_House/scripts.pory"
	goto_if_eq VAR_RESULT, 0, TwoIsland_House_EventScript_NoMoveToTutorMon
# 59 "data/maps/TwoIsland_House/scripts.pory"
	goto TwoIsland_House_EventScript_ChooseMoveToTeach
# 60 "data/maps/TwoIsland_House/scripts.pory"
	end
# 61 "data/maps/TwoIsland_House/scripts.pory"

# 62 "data/maps/TwoIsland_House/scripts.pory"
TwoIsland_House_EventScript_ChooseMoveToTeach::
# 63 "data/maps/TwoIsland_House/scripts.pory"
	msgbox TwoIsland_House_Text_TeachWhichMove
# 64 "data/maps/TwoIsland_House/scripts.pory"
	special TeachMoveRelearnerMove
# 65 "data/maps/TwoIsland_House/scripts.pory"
	waitstate
# 66 "data/maps/TwoIsland_House/scripts.pory"
	goto_if_eq VAR_0x8004, 0, TwoIsland_House_EventScript_ChooseMonToTutor
# 67 "data/maps/TwoIsland_House/scripts.pory"
	goto_if_set HAS_BOTH_MUSHROOMS, TwoIsland_House_EventScript_ChooseMushroom
# 68 "data/maps/TwoIsland_House/scripts.pory"
	goto_if_set HAS_BIG_MUSHROOM, TwoIsland_House_EventScript_GiveBigMushroom
# 69 "data/maps/TwoIsland_House/scripts.pory"
	goto_if_set HAS_TINY_MUSHROOMS, TwoIsland_House_EventScript_GiveTinyMushrooms
# 70 "data/maps/TwoIsland_House/scripts.pory"
	end
# 71 "data/maps/TwoIsland_House/scripts.pory"

# 72 "data/maps/TwoIsland_House/scripts.pory"
TwoIsland_House_EventScript_GiveBigMushroom::
# 73 "data/maps/TwoIsland_House/scripts.pory"
	removeitem ITEM_BIG_MUSHROOM
# 74 "data/maps/TwoIsland_House/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 75 "data/maps/TwoIsland_House/scripts.pory"
	msgbox TwoIsland_House_Text_HandedOverOneBigMushroom
# 76 "data/maps/TwoIsland_House/scripts.pory"
	call EventScript_RestorePrevTextColor
# 77 "data/maps/TwoIsland_House/scripts.pory"
	goto TwoIsland_House_EventScript_EndTutorMove
# 78 "data/maps/TwoIsland_House/scripts.pory"
	end
# 79 "data/maps/TwoIsland_House/scripts.pory"

# 80 "data/maps/TwoIsland_House/scripts.pory"
TwoIsland_House_EventScript_GiveTinyMushrooms::
# 81 "data/maps/TwoIsland_House/scripts.pory"
	removeitem ITEM_TINY_MUSHROOM, 2
# 82 "data/maps/TwoIsland_House/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 83 "data/maps/TwoIsland_House/scripts.pory"
	msgbox TwoIsland_House_Text_HandedOverTwoTinyMushrooms
# 84 "data/maps/TwoIsland_House/scripts.pory"
	call EventScript_RestorePrevTextColor
# 85 "data/maps/TwoIsland_House/scripts.pory"
	goto TwoIsland_House_EventScript_EndTutorMove
# 86 "data/maps/TwoIsland_House/scripts.pory"
	end
# 87 "data/maps/TwoIsland_House/scripts.pory"

# 88 "data/maps/TwoIsland_House/scripts.pory"
TwoIsland_House_EventScript_ChooseMushroom::
# 89 "data/maps/TwoIsland_House/scripts.pory"
	message TwoIsland_House_Text_IllNeedMushroomOrTwo
# 90 "data/maps/TwoIsland_House/scripts.pory"
	waitmessage
# 91 "data/maps/TwoIsland_House/scripts.pory"
	multichoice 0, 0, MULTI_MUSHROOMS, TRUE
# 92 "data/maps/TwoIsland_House/scripts.pory"
	switch VAR_RESULT
# 93 "data/maps/TwoIsland_House/scripts.pory"
	case 0, TwoIsland_House_EventScript_GiveTinyMushrooms
# 94 "data/maps/TwoIsland_House/scripts.pory"
	case 1, TwoIsland_House_EventScript_GiveBigMushroom
# 95 "data/maps/TwoIsland_House/scripts.pory"
	end
# 96 "data/maps/TwoIsland_House/scripts.pory"

# 97 "data/maps/TwoIsland_House/scripts.pory"
TwoIsland_House_EventScript_NoMoveToTutorMon::
# 98 "data/maps/TwoIsland_House/scripts.pory"
	msgbox TwoIsland_House_Text_NoMoveICanTeachThatMon
# 99 "data/maps/TwoIsland_House/scripts.pory"
	goto TwoIsland_House_EventScript_ChooseMonToTutor
# 100 "data/maps/TwoIsland_House/scripts.pory"
	end
# 101 "data/maps/TwoIsland_House/scripts.pory"

# 102 "data/maps/TwoIsland_House/scripts.pory"
TwoIsland_House_EventScript_CantTutorEgg::
# 103 "data/maps/TwoIsland_House/scripts.pory"
	msgbox TwoIsland_House_Text_CantTeachAnEgg
# 104 "data/maps/TwoIsland_House/scripts.pory"
	goto TwoIsland_House_EventScript_ChooseMonToTutor
# 105 "data/maps/TwoIsland_House/scripts.pory"
	end
# 106 "data/maps/TwoIsland_House/scripts.pory"

# 107 "data/maps/TwoIsland_House/scripts.pory"
TwoIsland_House_EventScript_EndTutorMove::
# 108 "data/maps/TwoIsland_House/scripts.pory"
	msgbox TwoIsland_House_Text_NeedMushroomOrTwoToLearnMove
# 109 "data/maps/TwoIsland_House/scripts.pory"
	release
# 110 "data/maps/TwoIsland_House/scripts.pory"
	end
# 111 "data/maps/TwoIsland_House/scripts.pory"

# 112 "data/maps/TwoIsland_House/scripts.pory"
TwoIsland_House_EventScript_SetHasBigMushroom::
# 113 "data/maps/TwoIsland_House/scripts.pory"
	setflag HAS_BIG_MUSHROOM
# 114 "data/maps/TwoIsland_House/scripts.pory"
	return
# 115 "data/maps/TwoIsland_House/scripts.pory"

# 116 "data/maps/TwoIsland_House/scripts.pory"
TwoIsland_House_EventScript_SetHasTinyMushrooms::
# 117 "data/maps/TwoIsland_House/scripts.pory"
	setflag HAS_TINY_MUSHROOMS
# 118 "data/maps/TwoIsland_House/scripts.pory"
	return
# 119 "data/maps/TwoIsland_House/scripts.pory"

# 120 "data/maps/TwoIsland_House/scripts.pory"
TwoIsland_House_EventScript_SetHasBothMushrooms::
# 121 "data/maps/TwoIsland_House/scripts.pory"
	setflag HAS_BOTH_MUSHROOMS
# 122 "data/maps/TwoIsland_House/scripts.pory"
	return
