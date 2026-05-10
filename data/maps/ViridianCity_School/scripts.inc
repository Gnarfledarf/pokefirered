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
ViridianCity_School_EventScript_Woman_Old::
# 16 "data/maps/ViridianCity_School/scripts.pory"
	lock
# 17 "data/maps/ViridianCity_School/scripts.pory"
	faceplayer
# 18 "data/maps/ViridianCity_School/scripts.pory"
	msgbox ViridianCity_School_Text_ReadBlackboardCarefully
# 19 "data/maps/ViridianCity_School/scripts.pory"
	closemessage
# 20 "data/maps/ViridianCity_School/scripts.pory"
	applymovement LOCALID_SCHOOL_WOMAN, Common_Movement_FaceOriginalDirection
# 21 "data/maps/ViridianCity_School/scripts.pory"
	waitmovement 0
# 22 "data/maps/ViridianCity_School/scripts.pory"
	release
# 23 "data/maps/ViridianCity_School/scripts.pory"
	end
# 24 "data/maps/ViridianCity_School/scripts.pory"

# 25 "data/maps/ViridianCity_School/scripts.pory"
ViridianCity_School_EventScript_Woman::
# 26 "data/maps/ViridianCity_School/scripts.pory"
	lock
# 27 "data/maps/ViridianCity_School/scripts.pory"
	faceplayer
# 28 "data/maps/ViridianCity_School/scripts.pory"
	goto_if_set FLAG_GOT_QUICK_CLAW_IN_TRAINER_SCHOOL, ViridianCity_School_EventScript_Woman_ReadBlackboardCarefully
# 29 "data/maps/ViridianCity_School/scripts.pory"
    compare VAR_BADGE_COUNT, 1
# 30 "data/maps/ViridianCity_School/scripts.pory"
    goto_if_ge ViridianCity_School_EventScript_Woman_GotGymBadge
# 31 "data/maps/ViridianCity_School/scripts.pory"
	msgbox ViridianCity_School_Text_GetOneGymBadge
# 32 "data/maps/ViridianCity_School/scripts.pory"
	closemessage
# 33 "data/maps/ViridianCity_School/scripts.pory"
	applymovement LOCALID_SCHOOL_WOMAN, Common_Movement_FaceOriginalDirection
# 34 "data/maps/ViridianCity_School/scripts.pory"
	waitmovement 0
# 35 "data/maps/ViridianCity_School/scripts.pory"
	release
# 36 "data/maps/ViridianCity_School/scripts.pory"
	end
# 37 "data/maps/ViridianCity_School/scripts.pory"

# 38 "data/maps/ViridianCity_School/scripts.pory"
ViridianCity_School_EventScript_Woman_GotGymBadge::
# 39 "data/maps/ViridianCity_School/scripts.pory"
	msgbox ViridianCity_School_Text_GotOneGymBadge, MSGBOX_NPC
# 40 "data/maps/ViridianCity_School/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 41 "data/maps/ViridianCity_School/scripts.pory"
	checkitemspace ITEM_QUICK_CLAW
# 42 "data/maps/ViridianCity_School/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, EventScript_BagIsFull
# 43 "data/maps/ViridianCity_School/scripts.pory"
	bufferitemname STR_VAR_2, ITEM_QUICK_CLAW
# 44 "data/maps/ViridianCity_School/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 45 "data/maps/ViridianCity_School/scripts.pory"
	message Text_ObtainedTheX
# 46 "data/maps/ViridianCity_School/scripts.pory"
	waitmessage
# 47 "data/maps/ViridianCity_School/scripts.pory"
	waitfanfare
# 48 "data/maps/ViridianCity_School/scripts.pory"
	additem ITEM_QUICK_CLAW
# 49 "data/maps/ViridianCity_School/scripts.pory"
	msgbox ViridianCity_School_Text_QuickClawAway
# 50 "data/maps/ViridianCity_School/scripts.pory"
	call EventScript_RestorePrevTextColor
# 51 "data/maps/ViridianCity_School/scripts.pory"
	setflag FLAG_GOT_QUICK_CLAW_IN_TRAINER_SCHOOL
# 52 "data/maps/ViridianCity_School/scripts.pory"
	msgbox ViridianCity_School_Text_QuickClaw, MSGBOX_NPC
# 53 "data/maps/ViridianCity_School/scripts.pory"
	release
# 54 "data/maps/ViridianCity_School/scripts.pory"
	end
# 55 "data/maps/ViridianCity_School/scripts.pory"

# 56 "data/maps/ViridianCity_School/scripts.pory"
ViridianCity_School_EventScript_Woman_ReadBlackboardCarefully::
# 57 "data/maps/ViridianCity_School/scripts.pory"
	msgbox ViridianCity_School_Text_ReadBlackboardCarefully
# 58 "data/maps/ViridianCity_School/scripts.pory"
	closemessage
# 59 "data/maps/ViridianCity_School/scripts.pory"
	applymovement LOCALID_SCHOOL_WOMAN, Common_Movement_FaceOriginalDirection
# 60 "data/maps/ViridianCity_School/scripts.pory"
	waitmovement 0
# 61 "data/maps/ViridianCity_School/scripts.pory"
	release
# 62 "data/maps/ViridianCity_School/scripts.pory"
	end
# 63 "data/maps/ViridianCity_School/scripts.pory"

# 64 "data/maps/ViridianCity_School/scripts.pory"
ViridianCity_School_EventScript_Notebook::
# 65 "data/maps/ViridianCity_School/scripts.pory"
	lockall
# 66 "data/maps/ViridianCity_School/scripts.pory"
	msgbox ViridianCity_School_Text_NotebookFirstPage
# 67 "data/maps/ViridianCity_School/scripts.pory"
	msgbox ViridianCity_School_Text_TurnThePage, MSGBOX_YESNO
# 68 "data/maps/ViridianCity_School/scripts.pory"
	goto_if_eq VAR_RESULT, NO, ViridianCity_School_EventScript_StopReadingNotebook
# 69 "data/maps/ViridianCity_School/scripts.pory"
	msgbox ViridianCity_School_Text_NotebookSecondPage
# 70 "data/maps/ViridianCity_School/scripts.pory"
	msgbox ViridianCity_School_Text_TurnThePage, MSGBOX_YESNO
# 71 "data/maps/ViridianCity_School/scripts.pory"
	goto_if_eq VAR_RESULT, NO, ViridianCity_School_EventScript_StopReadingNotebook
# 72 "data/maps/ViridianCity_School/scripts.pory"
	msgbox ViridianCity_School_Text_NotebookThirdPage
# 73 "data/maps/ViridianCity_School/scripts.pory"
	msgbox ViridianCity_School_Text_TurnThePage, MSGBOX_YESNO
# 74 "data/maps/ViridianCity_School/scripts.pory"
	goto_if_eq VAR_RESULT, NO, ViridianCity_School_EventScript_StopReadingNotebook
# 75 "data/maps/ViridianCity_School/scripts.pory"
	msgbox ViridianCity_School_Text_NotebookFourthPage
# 76 "data/maps/ViridianCity_School/scripts.pory"
	applymovement LOCALID_SCHOOL_LASS, Common_Movement_WalkInPlaceFasterUp
# 77 "data/maps/ViridianCity_School/scripts.pory"
	waitmovement 0
# 78 "data/maps/ViridianCity_School/scripts.pory"
	textcolor NPC_TEXT_COLOR_FEMALE
# 79 "data/maps/ViridianCity_School/scripts.pory"
	msgbox ViridianCity_School_Text_HeyDontLookAtMyNotes
# 80 "data/maps/ViridianCity_School/scripts.pory"
	releaseall
# 81 "data/maps/ViridianCity_School/scripts.pory"
	end
# 82 "data/maps/ViridianCity_School/scripts.pory"

# 83 "data/maps/ViridianCity_School/scripts.pory"
ViridianCity_School_EventScript_StopReadingNotebook::
# 84 "data/maps/ViridianCity_School/scripts.pory"
	releaseall
# 85 "data/maps/ViridianCity_School/scripts.pory"
	end
# 86 "data/maps/ViridianCity_School/scripts.pory"

# 87 "data/maps/ViridianCity_School/scripts.pory"
ViridianCity_School_EventScript_Blackboard::
# 88 "data/maps/ViridianCity_School/scripts.pory"
	lockall
# 89 "data/maps/ViridianCity_School/scripts.pory"
	msgbox ViridianCity_School_Text_BlackboardListsStatusProblems
# 90 "data/maps/ViridianCity_School/scripts.pory"
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
# 91 "data/maps/ViridianCity_School/scripts.pory"
	end
# 92 "data/maps/ViridianCity_School/scripts.pory"

# 93 "data/maps/ViridianCity_School/scripts.pory"
ViridianCity_School_EventScript_ChooseBlackboardTopic::
# 94 "data/maps/ViridianCity_School/scripts.pory"
	message ViridianCity_School_Text_ReadWhichTopic
# 95 "data/maps/ViridianCity_School/scripts.pory"
	waitmessage
# 96 "data/maps/ViridianCity_School/scripts.pory"
	multichoicegrid 7, 1, MULTI_TRAINER_SCHOOL_WHITEBOARD, 3, FALSE
# 97 "data/maps/ViridianCity_School/scripts.pory"
	switch VAR_RESULT
# 98 "data/maps/ViridianCity_School/scripts.pory"
	case 0, ViridianCity_School_EventScript_ReadSleep
# 99 "data/maps/ViridianCity_School/scripts.pory"
	case 1, ViridianCity_School_EventScript_ReadPoison
# 100 "data/maps/ViridianCity_School/scripts.pory"
	case 2, ViridianCity_School_EventScript_ReadParalysis
# 101 "data/maps/ViridianCity_School/scripts.pory"
	case 3, ViridianCity_School_EventScript_ReadBurn
# 102 "data/maps/ViridianCity_School/scripts.pory"
	case 4, ViridianCity_School_EventScript_ReadFreeze
# 103 "data/maps/ViridianCity_School/scripts.pory"
	case 5, ViridianCity_School_EventScript_ExitBlackboard
# 104 "data/maps/ViridianCity_School/scripts.pory"
	case 127, ViridianCity_School_EventScript_ExitBlackboard
# 105 "data/maps/ViridianCity_School/scripts.pory"
	end
# 106 "data/maps/ViridianCity_School/scripts.pory"

# 107 "data/maps/ViridianCity_School/scripts.pory"
ViridianCity_School_EventScript_ReadSleep::
# 108 "data/maps/ViridianCity_School/scripts.pory"
	msgbox ViridianCity_School_Text_ExplainSleep
# 109 "data/maps/ViridianCity_School/scripts.pory"
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
# 110 "data/maps/ViridianCity_School/scripts.pory"
	end
# 111 "data/maps/ViridianCity_School/scripts.pory"

# 112 "data/maps/ViridianCity_School/scripts.pory"
ViridianCity_School_EventScript_ReadBurn::
# 113 "data/maps/ViridianCity_School/scripts.pory"
	msgbox ViridianCity_School_Text_ExplainBurn
# 114 "data/maps/ViridianCity_School/scripts.pory"
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
# 115 "data/maps/ViridianCity_School/scripts.pory"
	end
# 116 "data/maps/ViridianCity_School/scripts.pory"

# 117 "data/maps/ViridianCity_School/scripts.pory"
ViridianCity_School_EventScript_ReadPoison::
# 118 "data/maps/ViridianCity_School/scripts.pory"
	msgbox ViridianCity_School_Text_ExplainPoison
# 119 "data/maps/ViridianCity_School/scripts.pory"
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
# 120 "data/maps/ViridianCity_School/scripts.pory"
	end
# 121 "data/maps/ViridianCity_School/scripts.pory"

# 122 "data/maps/ViridianCity_School/scripts.pory"
ViridianCity_School_EventScript_ReadFreeze::
# 123 "data/maps/ViridianCity_School/scripts.pory"
	msgbox ViridianCity_School_Text_ExplainFreeze
# 124 "data/maps/ViridianCity_School/scripts.pory"
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
# 125 "data/maps/ViridianCity_School/scripts.pory"
	end
# 126 "data/maps/ViridianCity_School/scripts.pory"

# 127 "data/maps/ViridianCity_School/scripts.pory"
ViridianCity_School_EventScript_ReadParalysis::
# 128 "data/maps/ViridianCity_School/scripts.pory"
	msgbox ViridianCity_School_Text_ExplainParalysis
# 129 "data/maps/ViridianCity_School/scripts.pory"
	goto ViridianCity_School_EventScript_ChooseBlackboardTopic
# 130 "data/maps/ViridianCity_School/scripts.pory"
	end
# 131 "data/maps/ViridianCity_School/scripts.pory"

# 132 "data/maps/ViridianCity_School/scripts.pory"
ViridianCity_School_EventScript_ExitBlackboard::
# 133 "data/maps/ViridianCity_School/scripts.pory"
	releaseall
# 134 "data/maps/ViridianCity_School/scripts.pory"
	end
