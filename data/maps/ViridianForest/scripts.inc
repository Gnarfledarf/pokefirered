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
ViridianForest_EventScript_Rick::
# 43 "data/maps/ViridianForest/scripts.pory"
	trainerbattle_single TRAINER_BUG_CATCHER_RICK, ViridianForest_Text_RickIntro, ViridianForest_Text_RickDefeat
# 44 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_RickPostBattle, MSGBOX_AUTOCLOSE
# 45 "data/maps/ViridianForest/scripts.pory"
	end
# 46 "data/maps/ViridianForest/scripts.pory"

# 47 "data/maps/ViridianForest/scripts.pory"
ViridianForest_EventScript_Doug::
# 48 "data/maps/ViridianForest/scripts.pory"
	trainerbattle_single TRAINER_BUG_CATCHER_DOUG, ViridianForest_Text_DougIntro, ViridianForest_Text_DougDefeat
# 49 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_DougPostBattle, MSGBOX_AUTOCLOSE
# 50 "data/maps/ViridianForest/scripts.pory"
	end
# 51 "data/maps/ViridianForest/scripts.pory"

# 52 "data/maps/ViridianForest/scripts.pory"
ViridianForest_EventScript_Sammy::
# 53 "data/maps/ViridianForest/scripts.pory"
	trainerbattle_single TRAINER_BUG_CATCHER_SAMMY, ViridianForest_Text_SammyIntro, ViridianForest_Text_SammyDefeat
# 54 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_SammyPostBattle, MSGBOX_AUTOCLOSE
# 55 "data/maps/ViridianForest/scripts.pory"
	end
# 56 "data/maps/ViridianForest/scripts.pory"

# 57 "data/maps/ViridianForest/scripts.pory"
ViridianForest_EventScript_Anthony::
# 58 "data/maps/ViridianForest/scripts.pory"
	trainerbattle_single TRAINER_BUG_CATCHER_ANTHONY, ViridianForest_Text_AnthonyIntro, ViridianForest_Text_AnthonyDefeat
# 59 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_AnthonyPostBattle, MSGBOX_AUTOCLOSE
# 60 "data/maps/ViridianForest/scripts.pory"
	end
# 61 "data/maps/ViridianForest/scripts.pory"

# 62 "data/maps/ViridianForest/scripts.pory"
ViridianForest_EventScript_Charlie::
# 63 "data/maps/ViridianForest/scripts.pory"
	trainerbattle_single TRAINER_BUG_CATCHER_CHARLIE, ViridianForest_Text_CharlieIntro, ViridianForest_Text_CharlieDefeat
# 64 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_CharliePostBattle, MSGBOX_AUTOCLOSE
# 65 "data/maps/ViridianForest/scripts.pory"
	end
# 66 "data/maps/ViridianForest/scripts.pory"

# 67 "data/maps/ViridianForest/scripts.pory"
ViridianForest_EventScript_Boy2::
# 68 "data/maps/ViridianForest/scripts.pory"
	faceplayer
# 69 "data/maps/ViridianForest/scripts.pory"
	goto_if_set FLAG_GOT_SILVER_POWDER_IN_VIRIDIAN_FOREST, ViridianForest_EventScript_Boy2_GotSilverPowder
# 70 "data/maps/ViridianForest/scripts.pory"
#ifdef FIRERED
# 71 "data/maps/ViridianForest/scripts.pory"
	check_if_species_caught SPECIES_BEEDRILL
# 72 "data/maps/ViridianForest/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, ViridianForest_EventScript_Boy2_CaughtBeedrill
# 73 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_IloveBeedrill
# 74 "data/maps/ViridianForest/scripts.pory"
#else
# 75 "data/maps/ViridianForest/scripts.pory"
#ifdef LEAFGREEN
# 76 "data/maps/ViridianForest/scripts.pory"
	check_if_species_caught SPECIES_BUTTERFREE
# 77 "data/maps/ViridianForest/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, ViridianForest_EventScript_Boy2_CaughtButterfree
# 78 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_IloveButterfree
# 79 "data/maps/ViridianForest/scripts.pory"
#endif
# 80 "data/maps/ViridianForest/scripts.pory"
#endif
# 81 "data/maps/ViridianForest/scripts.pory"
	release
# 82 "data/maps/ViridianForest/scripts.pory"
	end
# 83 "data/maps/ViridianForest/scripts.pory"

# 84 "data/maps/ViridianForest/scripts.pory"
ViridianForest_EventScript_Boy2_CaughtBeedrill::
# 85 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_ShowMeBeedrill, MSGBOX_NPC
# 86 "data/maps/ViridianForest/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 87 "data/maps/ViridianForest/scripts.pory"
	checkitemspace ITEM_SILVER_POWDER
# 88 "data/maps/ViridianForest/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, EventScript_BagIsFull
# 89 "data/maps/ViridianForest/scripts.pory"
	bufferitemname STR_VAR_2, ITEM_SILVER_POWDER
# 90 "data/maps/ViridianForest/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 91 "data/maps/ViridianForest/scripts.pory"
	message Text_ObtainedTheX
# 92 "data/maps/ViridianForest/scripts.pory"
	waitmessage
# 93 "data/maps/ViridianForest/scripts.pory"
	waitfanfare
# 94 "data/maps/ViridianForest/scripts.pory"
	additem ITEM_SILVER_POWDER
# 95 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_SilverPowderAway
# 96 "data/maps/ViridianForest/scripts.pory"
	call EventScript_RestorePrevTextColor
# 97 "data/maps/ViridianForest/scripts.pory"
	setflag FLAG_GOT_SILVER_POWDER_IN_VIRIDIAN_FOREST
# 98 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_SilverPowder, MSGBOX_NPC
# 99 "data/maps/ViridianForest/scripts.pory"
	release
# 100 "data/maps/ViridianForest/scripts.pory"
	end
# 101 "data/maps/ViridianForest/scripts.pory"

# 102 "data/maps/ViridianForest/scripts.pory"
ViridianForest_EventScript_Boy2_CaughtButterfree::
# 103 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_ShowMeButterfree, MSGBOX_NPC
# 104 "data/maps/ViridianForest/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 105 "data/maps/ViridianForest/scripts.pory"
	checkitemspace ITEM_SILVER_POWDER
# 106 "data/maps/ViridianForest/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, EventScript_BagIsFull
# 107 "data/maps/ViridianForest/scripts.pory"
	bufferitemname STR_VAR_2, ITEM_SILVER_POWDER
# 108 "data/maps/ViridianForest/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 109 "data/maps/ViridianForest/scripts.pory"
	message Text_ObtainedTheX
# 110 "data/maps/ViridianForest/scripts.pory"
	waitmessage
# 111 "data/maps/ViridianForest/scripts.pory"
	waitfanfare
# 112 "data/maps/ViridianForest/scripts.pory"
	additem ITEM_SILVER_POWDER
# 113 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_SilverPowderAway
# 114 "data/maps/ViridianForest/scripts.pory"
	call EventScript_RestorePrevTextColor
# 115 "data/maps/ViridianForest/scripts.pory"
	setflag FLAG_GOT_SILVER_POWDER_IN_VIRIDIAN_FOREST
# 116 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_SilverPowder, MSGBOX_NPC
# 117 "data/maps/ViridianForest/scripts.pory"
	release
# 118 "data/maps/ViridianForest/scripts.pory"
	end
# 119 "data/maps/ViridianForest/scripts.pory"

# 120 "data/maps/ViridianForest/scripts.pory"
ViridianForest_EventScript_Boy2_GotSilverPowder::
# 121 "data/maps/ViridianForest/scripts.pory"
	msgbox ViridianForest_Text_BugsEvolveEarly, MSGBOX_NPC
# 122 "data/maps/ViridianForest/scripts.pory"
	release
# 123 "data/maps/ViridianForest/scripts.pory"
	end
