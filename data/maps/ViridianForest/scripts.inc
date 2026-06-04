# 1 "data/maps/ViridianForest/scripts.pory"

# 2 "data/maps/ViridianForest/scripts.pory"
ViridianForest_MapScripts::
# 3 "data/maps/ViridianForest/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, ViridianForest_OnTransition
# 4 "data/maps/ViridianForest/scripts.pory"
	.byte 0
# 5 "data/maps/ViridianForest/scripts.pory"

# 6 "data/maps/ViridianForest/scripts.pory"
ViridianForest_OnTransition::
# 7 "data/maps/ViridianForest/scripts.pory"
	setworldmapflag FLAG_WORLD_MAP_VIRIDIAN_FOREST
# 8 "data/maps/ViridianForest/scripts.pory"
	end
# 9 "data/maps/ViridianForest/scripts.pory"

# 10 "data/maps/ViridianForest/scripts.pory"
ViridianForest_EventScript_Youngster::
# 11 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_FriendsItchingToBattle, MSGBOX_NPC
# 12 "data/maps/ViridianForest/scripts.pory"
	end
# 13 "data/maps/ViridianForest/scripts.pory"

# 14 "data/maps/ViridianForest/scripts.pory"
ViridianForest_EventScript_Boy::
# 15 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_RanOutOfPokeBalls, MSGBOX_NPC
# 16 "data/maps/ViridianForest/scripts.pory"
	end
# 17 "data/maps/ViridianForest/scripts.pory"

# 18 "data/maps/ViridianForest/scripts.pory"
ViridianForest_EventScript_TrainerTips1::
# 19 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_AvoidGrassyAreasWhenWeak, MSGBOX_SIGN
# 20 "data/maps/ViridianForest/scripts.pory"
	end
# 21 "data/maps/ViridianForest/scripts.pory"

# 22 "data/maps/ViridianForest/scripts.pory"
ViridianForest_EventScript_TrainerTips2::
# 23 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_UseAntidoteForPoison, MSGBOX_SIGN
# 24 "data/maps/ViridianForest/scripts.pory"
	end
# 25 "data/maps/ViridianForest/scripts.pory"

# 26 "data/maps/ViridianForest/scripts.pory"
ViridianForest_EventScript_TrainerTips3::
# 27 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_ContactOakViaPCToRatePokedex, MSGBOX_SIGN
# 28 "data/maps/ViridianForest/scripts.pory"
	end
# 29 "data/maps/ViridianForest/scripts.pory"

# 30 "data/maps/ViridianForest/scripts.pory"
ViridianForest_EventScript_TrainerTips4::
# 31 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_CantCatchOwnedMons, MSGBOX_SIGN
# 32 "data/maps/ViridianForest/scripts.pory"
	end
# 33 "data/maps/ViridianForest/scripts.pory"

# 34 "data/maps/ViridianForest/scripts.pory"
ViridianForest_EventScript_TrainerTips5::
# 35 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_WeakenMonsBeforeCapture, MSGBOX_SIGN
# 36 "data/maps/ViridianForest/scripts.pory"
	end
# 37 "data/maps/ViridianForest/scripts.pory"

# 38 "data/maps/ViridianForest/scripts.pory"
ViridianForest_EventScript_ExitSign::
# 39 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_LeavingViridianForest, MSGBOX_SIGN
# 40 "data/maps/ViridianForest/scripts.pory"
	end
# 41 "data/maps/ViridianForest/scripts.pory"

# 42 "data/maps/ViridianForest/scripts.pory"
@todo: Replace Bug Catcher Colton with Bug Catcher Rick
# 43 "data/maps/ViridianForest/scripts.pory"
ViridianForest_EventScript_Rick::
# 44 "data/maps/ViridianForest/scripts.pory"
	trainerbattle_single TRAINER_BUG_CATCHER_RICK, ViridianForest_Text_RickIntro, ViridianForest_Text_RickDefeat
# 45 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_RickPostBattle, MSGBOX_AUTOCLOSE
# 46 "data/maps/ViridianForest/scripts.pory"
	end
# 47 "data/maps/ViridianForest/scripts.pory"

# 48 "data/maps/ViridianForest/scripts.pory"
ViridianForest_EventScript_Doug::
# 49 "data/maps/ViridianForest/scripts.pory"
	trainerbattle_single TRAINER_BUG_CATCHER_DOUG, ViridianForest_Text_DougIntro, ViridianForest_Text_DougDefeat
# 50 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_DougPostBattle, MSGBOX_AUTOCLOSE
# 51 "data/maps/ViridianForest/scripts.pory"
	end
# 52 "data/maps/ViridianForest/scripts.pory"

# 53 "data/maps/ViridianForest/scripts.pory"
ViridianForest_EventScript_Sammy::
# 54 "data/maps/ViridianForest/scripts.pory"
	trainerbattle_single TRAINER_BUG_CATCHER_SAMMY, ViridianForest_Text_SammyIntro, ViridianForest_Text_SammyDefeat
# 55 "data/maps/ViridianForest/scripts.pory"
	goto_if_set FLAG_GOT_NET_BALL_IN_VIRIDIAN_FOREST, ViridianForest_EventScript_Sammy_NetBallExplanation
# 56 "data/maps/ViridianForest/scripts.pory"
	goto_if_unset FLAG_GOT_NET_BALL_IN_VIRIDIAN_FOREST, ViridianForest_EventScript_Sammy_CheckIfFoundItem
# 57 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_SammyPostBattle, MSGBOX_AUTOCLOSE
# 58 "data/maps/ViridianForest/scripts.pory"
	end
# 59 "data/maps/ViridianForest/scripts.pory"

# 60 "data/maps/ViridianForest/scripts.pory"
ViridianForest_EventScript_Sammy_CheckIfFoundItem::
# 61 "data/maps/ViridianForest/scripts.pory"
	goto_if_set FLAG_HIDDEN_ITEM_VIRIDIAN_FOREST_POTION, ViridianForest_EventScript_Sammy_FoundItem
# 62 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_SammyPostBattle, MSGBOX_AUTOCLOSE
# 63 "data/maps/ViridianForest/scripts.pory"
	end
# 64 "data/maps/ViridianForest/scripts.pory"

# 65 "data/maps/ViridianForest/scripts.pory"
ViridianForest_EventScript_Sammy_FoundItem::
# 66 "data/maps/ViridianForest/scripts.pory"
	checkitem ITEM_POTION, 1
# 67 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_SammyPostBattle, MSGBOX_DEFAULT
# 68 "data/maps/ViridianForest/scripts.pory"
	goto_if_ge VAR_RESULT, TRUE, ViridianForest_EventScript_Sammy_ReturnLostItem
# 69 "data/maps/ViridianForest/scripts.pory"
	end
# 70 "data/maps/ViridianForest/scripts.pory"

# 71 "data/maps/ViridianForest/scripts.pory"
ViridianForest_EventScript_Sammy_ReturnLostItem::
# 72 "data/maps/ViridianForest/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 73 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_Sammy_FoundItem, MSGBOX_YESNO
# 74 "data/maps/ViridianForest/scripts.pory"
	goto_if_eq VAR_RESULT, YES, ViridianForest_EventScript_Sammy_ReturnedLostItem
# 75 "data/maps/ViridianForest/scripts.pory"
	closemessage
# 76 "data/maps/ViridianForest/scripts.pory"
	end
# 77 "data/maps/ViridianForest/scripts.pory"

# 78 "data/maps/ViridianForest/scripts.pory"
ViridianForest_EventScript_Sammy_ReturnedLostItem::
# 79 "data/maps/ViridianForest/scripts.pory"
	removeitem ITEM_POTION
# 80 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_Sammy_GaveItemBack
# 81 "data/maps/ViridianForest/scripts.pory"
	closemessage
# 82 "data/maps/ViridianForest/scripts.pory"
	call EventScript_RestorePrevTextColor
# 83 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_Sammy_ThankYouSoMuch, MSGBOX_DEFAULT
# 84 "data/maps/ViridianForest/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 85 "data/maps/ViridianForest/scripts.pory"
	checkitemspace ITEM_NET_BALL
# 86 "data/maps/ViridianForest/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, EventScript_BagIsFull
# 87 "data/maps/ViridianForest/scripts.pory"
	giveitem ITEM_NET_BALL, 1
# 88 "data/maps/ViridianForest/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, EventScript_NoRoomForItem
# 89 "data/maps/ViridianForest/scripts.pory"
	setflag FLAG_GOT_NET_BALL_IN_VIRIDIAN_FOREST
# 90 "data/maps/ViridianForest/scripts.pory"
	goto ViridianForest_EventScript_Sammy_NetBallExplanation
# 91 "data/maps/ViridianForest/scripts.pory"
	release
# 92 "data/maps/ViridianForest/scripts.pory"
	end
# 93 "data/maps/ViridianForest/scripts.pory"

# 94 "data/maps/ViridianForest/scripts.pory"
ViridianForest_EventScript_Sammy_NetBallExplanation::
# 95 "data/maps/ViridianForest/scripts.pory"
	textcolor NPC_TEXT_COLOR_DEFAULT
# 96 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_Sammy_NetBallExplanation, MSGBOX_AUTOCLOSE
# 97 "data/maps/ViridianForest/scripts.pory"
	end
# 98 "data/maps/ViridianForest/scripts.pory"

# 99 "data/maps/ViridianForest/scripts.pory"
ViridianForest_EventScript_Anthony::
# 100 "data/maps/ViridianForest/scripts.pory"
	trainerbattle_single TRAINER_BUG_CATCHER_ANTHONY, ViridianForest_Text_AnthonyIntro, ViridianForest_Text_AnthonyDefeat
# 101 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_AnthonyPostBattle, MSGBOX_AUTOCLOSE
# 102 "data/maps/ViridianForest/scripts.pory"
	end
# 103 "data/maps/ViridianForest/scripts.pory"

# 104 "data/maps/ViridianForest/scripts.pory"
ViridianForest_EventScript_Charlie::
# 105 "data/maps/ViridianForest/scripts.pory"
	trainerbattle_single TRAINER_BUG_CATCHER_CHARLIE, ViridianForest_Text_CharlieIntro, ViridianForest_Text_CharlieDefeat
# 106 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_CharliePostBattle, MSGBOX_AUTOCLOSE
# 107 "data/maps/ViridianForest/scripts.pory"
	end
# 108 "data/maps/ViridianForest/scripts.pory"

# 109 "data/maps/ViridianForest/scripts.pory"
ViridianForest_EventScript_Boy2::
# 110 "data/maps/ViridianForest/scripts.pory"
	faceplayer
# 111 "data/maps/ViridianForest/scripts.pory"
	goto_if_set FLAG_GOT_SILVER_POWDER_IN_VIRIDIAN_FOREST, ViridianForest_EventScript_Boy2_GotSilverPowder
# 112 "data/maps/ViridianForest/scripts.pory"
#ifdef FIRERED
# 113 "data/maps/ViridianForest/scripts.pory"
	check_if_species_caught SPECIES_BEEDRILL
# 114 "data/maps/ViridianForest/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, ViridianForest_EventScript_Boy2_CaughtBeedrill
# 115 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_IloveBeedrill
# 116 "data/maps/ViridianForest/scripts.pory"
#else
# 117 "data/maps/ViridianForest/scripts.pory"
#ifdef LEAFGREEN
# 118 "data/maps/ViridianForest/scripts.pory"
	check_if_species_caught SPECIES_BUTTERFREE
# 119 "data/maps/ViridianForest/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, ViridianForest_EventScript_Boy2_CaughtButterfree
# 120 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_IloveButterfree
# 121 "data/maps/ViridianForest/scripts.pory"
#endif
# 122 "data/maps/ViridianForest/scripts.pory"
#endif
# 123 "data/maps/ViridianForest/scripts.pory"
	release
# 124 "data/maps/ViridianForest/scripts.pory"
	end
# 125 "data/maps/ViridianForest/scripts.pory"

# 126 "data/maps/ViridianForest/scripts.pory"
ViridianForest_EventScript_Boy2_CaughtBeedrill::
# 127 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_ShowMeBeedrill, MSGBOX_NPC
# 128 "data/maps/ViridianForest/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 129 "data/maps/ViridianForest/scripts.pory"
	checkitemspace ITEM_SILVER_POWDER
# 130 "data/maps/ViridianForest/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, EventScript_BagIsFull
# 131 "data/maps/ViridianForest/scripts.pory"
	bufferitemname STR_VAR_2, ITEM_SILVER_POWDER
# 132 "data/maps/ViridianForest/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 133 "data/maps/ViridianForest/scripts.pory"
	message Text_ObtainedTheX
# 134 "data/maps/ViridianForest/scripts.pory"
	waitmessage
# 135 "data/maps/ViridianForest/scripts.pory"
	waitfanfare
# 136 "data/maps/ViridianForest/scripts.pory"
	additem ITEM_SILVER_POWDER
# 137 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_SilverPowderAway
# 138 "data/maps/ViridianForest/scripts.pory"
	call EventScript_RestorePrevTextColor
# 139 "data/maps/ViridianForest/scripts.pory"
	setflag FLAG_GOT_SILVER_POWDER_IN_VIRIDIAN_FOREST
# 140 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_SilverPowder, MSGBOX_NPC
# 141 "data/maps/ViridianForest/scripts.pory"
	release
# 142 "data/maps/ViridianForest/scripts.pory"
	end
# 143 "data/maps/ViridianForest/scripts.pory"

# 144 "data/maps/ViridianForest/scripts.pory"
ViridianForest_EventScript_Boy2_CaughtButterfree::
# 145 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_ShowMeButterfree, MSGBOX_NPC
# 146 "data/maps/ViridianForest/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 147 "data/maps/ViridianForest/scripts.pory"
	checkitemspace ITEM_SILVER_POWDER
# 148 "data/maps/ViridianForest/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, EventScript_BagIsFull
# 149 "data/maps/ViridianForest/scripts.pory"
	bufferitemname STR_VAR_2, ITEM_SILVER_POWDER
# 150 "data/maps/ViridianForest/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 151 "data/maps/ViridianForest/scripts.pory"
	message Text_ObtainedTheX
# 152 "data/maps/ViridianForest/scripts.pory"
	waitmessage
# 153 "data/maps/ViridianForest/scripts.pory"
	waitfanfare
# 154 "data/maps/ViridianForest/scripts.pory"
	additem ITEM_SILVER_POWDER
# 155 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_SilverPowderAway
# 156 "data/maps/ViridianForest/scripts.pory"
	call EventScript_RestorePrevTextColor
# 157 "data/maps/ViridianForest/scripts.pory"
	setflag FLAG_GOT_SILVER_POWDER_IN_VIRIDIAN_FOREST
# 158 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_SilverPowder, MSGBOX_NPC
# 159 "data/maps/ViridianForest/scripts.pory"
	release
# 160 "data/maps/ViridianForest/scripts.pory"
	end
# 161 "data/maps/ViridianForest/scripts.pory"

# 162 "data/maps/ViridianForest/scripts.pory"
ViridianForest_EventScript_Boy2_GotSilverPowder::
# 163 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_BugsEvolveEarly, MSGBOX_NPC
# 164 "data/maps/ViridianForest/scripts.pory"
	release
# 165 "data/maps/ViridianForest/scripts.pory"
	end
