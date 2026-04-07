# 1 "data/maps/FuchsiaCity_House2/scripts.pory"

# 2 "data/maps/FuchsiaCity_House2/scripts.pory"
FuchsiaCity_House2_MapScripts::
# 3 "data/maps/FuchsiaCity_House2/scripts.pory"
	.byte 0
# 4 "data/maps/FuchsiaCity_House2/scripts.pory"

# 5 "data/maps/FuchsiaCity_House2/scripts.pory"
FuchsiaCity_House2_EventScript_FishingGurusBrother::
# 6 "data/maps/FuchsiaCity_House2/scripts.pory"
	lock
# 7 "data/maps/FuchsiaCity_House2/scripts.pory"
	faceplayer
# 8 "data/maps/FuchsiaCity_House2/scripts.pory"
	goto_if_set FLAG_GOT_SUPER_ROD, FuchsiaCity_House2_EventScript_AlreadyGotSuperRod
# 9 "data/maps/FuchsiaCity_House2/scripts.pory"
	msgbox FuchsiaCity_House2_Text_DoYouLikeToFish, MSGBOX_YESNO
# 10 "data/maps/FuchsiaCity_House2/scripts.pory"
	goto_if_eq VAR_RESULT, YES, FuchsiaCity_House2_EventScript_GiveSuperRod
# 11 "data/maps/FuchsiaCity_House2/scripts.pory"
	msgbox FuchsiaCity_House2_Text_OhThatsDisappointing
# 12 "data/maps/FuchsiaCity_House2/scripts.pory"
	release
# 13 "data/maps/FuchsiaCity_House2/scripts.pory"
	end
# 14 "data/maps/FuchsiaCity_House2/scripts.pory"

# 15 "data/maps/FuchsiaCity_House2/scripts.pory"
FuchsiaCity_House2_EventScript_AlreadyGotSuperRod::
# 16 "data/maps/FuchsiaCity_House2/scripts.pory"
	msgbox FuchsiaCity_House2_Text_HowAreTheFishBiting
# 17 "data/maps/FuchsiaCity_House2/scripts.pory"
	release
# 18 "data/maps/FuchsiaCity_House2/scripts.pory"
	end
# 19 "data/maps/FuchsiaCity_House2/scripts.pory"

# 20 "data/maps/FuchsiaCity_House2/scripts.pory"
FuchsiaCity_House2_EventScript_GiveSuperRod::
# 21 "data/maps/FuchsiaCity_House2/scripts.pory"
	msgbox FuchsiaCity_House2_Text_LikeYourStyleTakeThis
# 22 "data/maps/FuchsiaCity_House2/scripts.pory"
	checkitemspace ITEM_SUPER_ROD
# 23 "data/maps/FuchsiaCity_House2/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, FuchsiaCity_House2_EventScript_NoRoomForSuperRod
# 24 "data/maps/FuchsiaCity_House2/scripts.pory"
	giveitem_msg FuchsiaCity_House2_Text_ReceivedSuperRod, ITEM_SUPER_ROD
# 25 "data/maps/FuchsiaCity_House2/scripts.pory"
	msgbox FuchsiaCity_House2_Text_SuperRodCanCatchBetterMons
# 26 "data/maps/FuchsiaCity_House2/scripts.pory"
	setflag FLAG_GOT_SUPER_ROD
# 27 "data/maps/FuchsiaCity_House2/scripts.pory"
	release
# 28 "data/maps/FuchsiaCity_House2/scripts.pory"
	end
# 29 "data/maps/FuchsiaCity_House2/scripts.pory"

# 30 "data/maps/FuchsiaCity_House2/scripts.pory"
FuchsiaCity_House2_EventScript_NoRoomForSuperRod::
# 31 "data/maps/FuchsiaCity_House2/scripts.pory"
	msgbox FuchsiaCity_House2_Text_YouHaveNoRoomForGift
# 32 "data/maps/FuchsiaCity_House2/scripts.pory"
	release
# 33 "data/maps/FuchsiaCity_House2/scripts.pory"
	end
