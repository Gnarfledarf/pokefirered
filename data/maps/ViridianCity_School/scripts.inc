# 1 "data/maps/ViridianCity_School/scripts.pory"

# 2 "data/maps/ViridianCity_School/scripts.pory"
ViridianCity_School_MapScripts::
# 3 "data/maps/ViridianCity_School/scripts.pory"
	.byte 0
# 4 "data/maps/ViridianCity_School/scripts.pory"

# 5 "data/maps/ViridianCity_School/scripts.pory"
ViridianCity_School_EventScript_Lass::
# 6 "data/maps/ViridianCity_School/scripts.pory"
	lock
# 7 "data/maps/ViridianCity_School/scripts.pory"
	faceplayer
# 8 "data/maps/ViridianCity_School/scripts.pory"
	msgbox ViridianCity_School_Text_TryingToMemorizeNotes
# 9 "data/maps/ViridianCity_School/scripts.pory"
	closemessage
# 10 "data/maps/ViridianCity_School/scripts.pory"
	applymovement LOCALID_SCHOOL_LASS, Common_Movement_WalkInPlaceFasterUp
# 11 "data/maps/ViridianCity_School/scripts.pory"
	waitmovement 0
# 12 "data/maps/ViridianCity_School/scripts.pory"
	release
# 13 "data/maps/ViridianCity_School/scripts.pory"
	end
# 14 "data/maps/ViridianCity_School/scripts.pory"

# 15 "data/maps/ViridianCity_School/scripts.pory"
ViridianCity_School_EventScript_Woman::
# 16 "data/maps/ViridianCity_School/scripts.pory"
	lock
# 17 "data/maps/ViridianCity_School/scripts.pory"
	faceplayer
# 18 "data/maps/ViridianCity_School/scripts.pory"
	goto_if_set FLAG_GOT_QUICK_CLAW_IN_TRAINER_SCHOOL, ViridianCity_School_EventScript_Woman_ReadBlackboardCarefully
# 19 "data/maps/ViridianCity_School/scripts.pory"
    compare VAR_BADGE_COUNT, 1
# 20 "data/maps/ViridianCity_School/scripts.pory"
    goto_if_ge ViridianCity_School_EventScript_Woman_GotGymBadge
# 21 "data/maps/ViridianCity_School/scripts.pory"
	msgbox ViridianCity_School_Text_GetOneGymBadge
# 22 "data/maps/ViridianCity_School/scripts.pory"
	closemessage
# 23 "data/maps/ViridianCity_School/scripts.pory"
	applymovement LOCALID_SCHOOL_WOMAN, Common_Movement_FaceOriginalDirection
# 24 "data/maps/ViridianCity_School/scripts.pory"
	waitmovement 0
# 25 "data/maps/ViridianCity_School/scripts.pory"
	release
# 26 "data/maps/ViridianCity_School/scripts.pory"
	end
# 27 "data/maps/ViridianCity_School/scripts.pory"

# 28 "data/maps/ViridianCity_School/scripts.pory"
ViridianCity_School_EventScript_Woman_GotGymBadge::
# 29 "data/maps/ViridianCity_School/scripts.pory"
	msgbox ViridianCity_School_Text_GotOneGymBadge, MSGBOX_NPC
# 30 "data/maps/ViridianCity_School/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 31 "data/maps/ViridianCity_School/scripts.pory"
	checkitemspace ITEM_QUICK_CLAW
# 32 "data/maps/ViridianCity_School/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, EventScript_BagIsFull
# 33 "data/maps/ViridianCity_School/scripts.pory"
	bufferitemname STR_VAR_2, ITEM_QUICK_CLAW
# 34 "data/maps/ViridianCity_School/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 35 "data/maps/ViridianCity_School/scripts.pory"
	message Text_ObtainedTheX
# 36 "data/maps/ViridianCity_School/scripts.pory"
	waitmessage
# 37 "data/maps/ViridianCity_School/scripts.pory"
	waitfanfare
# 38 "data/maps/ViridianCity_School/scripts.pory"
	additem ITEM_QUICK_CLAW
# 39 "data/maps/ViridianCity_School/scripts.pory"
	msgbox ViridianCity_School_Text_QuickClawAway
# 40 "data/maps/ViridianCity_School/scripts.pory"
	call EventScript_RestorePrevTextColor
# 41 "data/maps/ViridianCity_School/scripts.pory"
	setflag FLAG_GOT_QUICK_CLAW_IN_TRAINER_SCHOOL
# 42 "data/maps/ViridianCity_School/scripts.pory"
	msgbox ViridianCity_School_Text_QuickClaw, MSGBOX_NPC
# 43 "data/maps/ViridianCity_School/scripts.pory"
	release
# 44 "data/maps/ViridianCity_School/scripts.pory"
	end
# 45 "data/maps/ViridianCity_School/scripts.pory"

# 46 "data/maps/ViridianCity_School/scripts.pory"
ViridianCity_School_EventScript_Woman_ReadBlackboardCarefully::
# 47 "data/maps/ViridianCity_School/scripts.pory"
	msgbox ViridianCity_School_Text_ReadBlackboardCarefully
# 48 "data/maps/ViridianCity_School/scripts.pory"
	closemessage
# 49 "data/maps/ViridianCity_School/scripts.pory"
	applymovement LOCALID_SCHOOL_WOMAN, Common_Movement_FaceOriginalDirection
# 50 "data/maps/ViridianCity_School/scripts.pory"
	waitmovement 0
# 51 "data/maps/ViridianCity_School/scripts.pory"
	release
# 52 "data/maps/ViridianCity_School/scripts.pory"
	end
# 53 "data/maps/ViridianCity_School/scripts.pory"

# 54 "data/maps/ViridianCity_School/scripts.pory"
ViridianCity_School_EventScript_Notebook::
# 55 "data/maps/ViridianCity_School/scripts.pory"
	lockall
# 56 "data/maps/ViridianCity_School/scripts.pory"
	msgbox ViridianCity_School_Text_NotebookFirstPage
# 57 "data/maps/ViridianCity_School/scripts.pory"
	msgbox ViridianCity_School_Text_TurnThePage, MSGBOX_YESNO
# 58 "data/maps/ViridianCity_School/scripts.pory"
	goto_if_eq VAR_RESULT, NO, ViridianCity_School_EventScript_StopReadingNotebook
# 59 "data/maps/ViridianCity_School/scripts.pory"
	msgbox ViridianCity_School_Text_NotebookSecondPage
# 60 "data/maps/ViridianCity_School/scripts.pory"
	msgbox ViridianCity_School_Text_TurnThePage, MSGBOX_YESNO
# 61 "data/maps/ViridianCity_School/scripts.pory"
	goto_if_eq VAR_RESULT, NO, ViridianCity_School_EventScript_StopReadingNotebook
# 62 "data/maps/ViridianCity_School/scripts.pory"
	msgbox ViridianCity_School_Text_NotebookThirdPage
# 63 "data/maps/ViridianCity_School/scripts.pory"
	msgbox ViridianCity_School_Text_TurnThePage, MSGBOX_YESNO
# 64 "data/maps/ViridianCity_School/scripts.pory"
	goto_if_eq VAR_RESULT, NO, ViridianCity_School_EventScript_StopReadingNotebook
# 65 "data/maps/ViridianCity_School/scripts.pory"
	msgbox ViridianCity_School_Text_NotebookFourthPage
# 66 "data/maps/ViridianCity_School/scripts.pory"
	applymovement LOCALID_SCHOOL_LASS, Common_Movement_WalkInPlaceFasterUp
# 67 "data/maps/ViridianCity_School/scripts.pory"
	waitmovement 0
# 68 "data/maps/ViridianCity_School/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 69 "data/maps/ViridianCity_School/scripts.pory"
	msgbox ViridianCity_School_Text_HeyDontLookAtMyNotes
# 70 "data/maps/ViridianCity_School/scripts.pory"
	releaseall
# 71 "data/maps/ViridianCity_School/scripts.pory"
	end
# 72 "data/maps/ViridianCity_School/scripts.pory"

# 73 "data/maps/ViridianCity_School/scripts.pory"
ViridianCity_School_EventScript_StopReadingNotebook::
# 74 "data/maps/ViridianCity_School/scripts.pory"
	releaseall
# 75 "data/maps/ViridianCity_School/scripts.pory"
	end
# 76 "data/maps/ViridianCity_School/scripts.pory"

# 77 "data/maps/ViridianCity_School/scripts.pory"
ViridianCity_School_EventScript_Blackboard::
# 78 "data/maps/ViridianCity_School/scripts.pory"
	lockall
# 79 "data/maps/ViridianCity_School/scripts.pory"
	msgbox ViridianCity_School_Text_BlackboardListsStatusProblems
# 80 "data/maps/ViridianCity_School/scripts.pory"
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
# 81 "data/maps/ViridianCity_School/scripts.pory"
	end
# 82 "data/maps/ViridianCity_School/scripts.pory"

# 83 "data/maps/ViridianCity_School/scripts.pory"
ViridianCity_School_EventScript_ChooseBlackboardTopic::
# 84 "data/maps/ViridianCity_School/scripts.pory"
	message ViridianCity_School_Text_ReadWhichTopic
# 85 "data/maps/ViridianCity_School/scripts.pory"
	waitmessage
# 86 "data/maps/ViridianCity_School/scripts.pory"
	multichoicegrid 7, 1, MULTI_TRAINER_SCHOOL_WHITEBOARD, 3, FALSE
# 87 "data/maps/ViridianCity_School/scripts.pory"
	switch VAR_RESULT
# 88 "data/maps/ViridianCity_School/scripts.pory"
	case 0, ViridianCity_School_EventScript_ReadSleep
# 89 "data/maps/ViridianCity_School/scripts.pory"
	case 1, ViridianCity_School_EventScript_ReadPoison
# 90 "data/maps/ViridianCity_School/scripts.pory"
	case 2, ViridianCity_School_EventScript_ReadParalysis
# 91 "data/maps/ViridianCity_School/scripts.pory"
	case 3, ViridianCity_School_EventScript_ReadBurn
# 92 "data/maps/ViridianCity_School/scripts.pory"
	case 4, ViridianCity_School_EventScript_ReadFreeze
# 93 "data/maps/ViridianCity_School/scripts.pory"
	case 5, ViridianCity_School_EventScript_ExitBlackboard
# 94 "data/maps/ViridianCity_School/scripts.pory"
	case 127, ViridianCity_School_EventScript_ExitBlackboard
# 95 "data/maps/ViridianCity_School/scripts.pory"
	end
# 96 "data/maps/ViridianCity_School/scripts.pory"

# 97 "data/maps/ViridianCity_School/scripts.pory"
ViridianCity_School_EventScript_ReadSleep::
# 98 "data/maps/ViridianCity_School/scripts.pory"
	msgbox ViridianCity_School_Text_ExplainSleep
# 99 "data/maps/ViridianCity_School/scripts.pory"
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
# 100 "data/maps/ViridianCity_School/scripts.pory"
	end
# 101 "data/maps/ViridianCity_School/scripts.pory"

# 102 "data/maps/ViridianCity_School/scripts.pory"
ViridianCity_School_EventScript_ReadBurn::
# 103 "data/maps/ViridianCity_School/scripts.pory"
	msgbox ViridianCity_School_Text_ExplainBurn
# 104 "data/maps/ViridianCity_School/scripts.pory"
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
# 105 "data/maps/ViridianCity_School/scripts.pory"
	end
# 106 "data/maps/ViridianCity_School/scripts.pory"

# 107 "data/maps/ViridianCity_School/scripts.pory"
ViridianCity_School_EventScript_ReadPoison::
# 108 "data/maps/ViridianCity_School/scripts.pory"
	msgbox ViridianCity_School_Text_ExplainPoison
# 109 "data/maps/ViridianCity_School/scripts.pory"
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
# 110 "data/maps/ViridianCity_School/scripts.pory"
	end
# 111 "data/maps/ViridianCity_School/scripts.pory"

# 112 "data/maps/ViridianCity_School/scripts.pory"
ViridianCity_School_EventScript_ReadFreeze::
# 113 "data/maps/ViridianCity_School/scripts.pory"
	msgbox ViridianCity_School_Text_ExplainFreeze
# 114 "data/maps/ViridianCity_School/scripts.pory"
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
# 115 "data/maps/ViridianCity_School/scripts.pory"
	end
# 116 "data/maps/ViridianCity_School/scripts.pory"

# 117 "data/maps/ViridianCity_School/scripts.pory"
ViridianCity_School_EventScript_ReadParalysis::
# 118 "data/maps/ViridianCity_School/scripts.pory"
	msgbox ViridianCity_School_Text_ExplainParalysis
# 119 "data/maps/ViridianCity_School/scripts.pory"
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
# 120 "data/maps/ViridianCity_School/scripts.pory"
	end
# 121 "data/maps/ViridianCity_School/scripts.pory"

# 122 "data/maps/ViridianCity_School/scripts.pory"
ViridianCity_School_EventScript_ExitBlackboard::
# 123 "data/maps/ViridianCity_School/scripts.pory"
	releaseall
# 124 "data/maps/ViridianCity_School/scripts.pory"
	end
