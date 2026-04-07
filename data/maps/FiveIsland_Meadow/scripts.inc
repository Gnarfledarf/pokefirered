# 1 "data/maps/FiveIsland_Meadow/scripts.pory"

# 2 "data/maps/FiveIsland_Meadow/scripts.pory"
FiveIsland_Meadow_MapScripts::
# 3 "data/maps/FiveIsland_Meadow/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, FiveIsland_Meadow_OnLoad
# 4 "data/maps/FiveIsland_Meadow/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, FiveIsland_Meadow_OnResume
# 5 "data/maps/FiveIsland_Meadow/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, FiveIsland_Meadow_OnTransition
# 6 "data/maps/FiveIsland_Meadow/scripts.pory"
	.byte 0
# 7 "data/maps/FiveIsland_Meadow/scripts.pory"

# 8 "data/maps/FiveIsland_Meadow/scripts.pory"
FiveIsland_Meadow_OnLoad::
# 9 "data/maps/FiveIsland_Meadow/scripts.pory"
	call_if_set FLAG_UNLOCKED_ROCKET_WAREHOUSE, FiveIsland_Meadow_EventScript_SetWarehouseDoorUnlocked
# 10 "data/maps/FiveIsland_Meadow/scripts.pory"
	end
# 11 "data/maps/FiveIsland_Meadow/scripts.pory"

# 12 "data/maps/FiveIsland_Meadow/scripts.pory"
FiveIsland_Meadow_OnResume:
# 13 "data/maps/FiveIsland_Meadow/scripts.pory"
	call_if_set FLAG_SYS_SPECIAL_WILD_BATTLE, FiveIsland_Meadow_EventScript_TryRemoveSudowoodo
# 14 "data/maps/FiveIsland_Meadow/scripts.pory"
	end
# 15 "data/maps/FiveIsland_Meadow/scripts.pory"

# 16 "data/maps/FiveIsland_Meadow/scripts.pory"
FiveIsland_Meadow_EventScript_TryRemoveSudowoodo::
# 17 "data/maps/FiveIsland_Meadow/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 18 "data/maps/FiveIsland_Meadow/scripts.pory"
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, EventScript_Return
# 19 "data/maps/FiveIsland_Meadow/scripts.pory"
	removeobject VAR_LAST_TALKED
# 20 "data/maps/FiveIsland_Meadow/scripts.pory"
	return
# 21 "data/maps/FiveIsland_Meadow/scripts.pory"

# 22 "data/maps/FiveIsland_Meadow/scripts.pory"
FiveIsland_Meadow_OnTransition:
# 23 "data/maps/FiveIsland_Meadow/scripts.pory"
	call_if_unset FLAG_DEFEATED_FIVE_ISLAND_MEADOW_SUDOWOODO, FiveIsland_Meadow_EventScript_ShowSudowoodo
# 24 "data/maps/FiveIsland_Meadow/scripts.pory"
	end
# 25 "data/maps/FiveIsland_Meadow/scripts.pory"

# 26 "data/maps/FiveIsland_Meadow/scripts.pory"
FiveIsland_Meadow_EventScript_ShowSudowoodo::
# 27 "data/maps/FiveIsland_Meadow/scripts.pory"
	clearflag FLAG_HIDE_FIVE_ISLAND_MEADOW_SUDOWOODO
# 28 "data/maps/FiveIsland_Meadow/scripts.pory"
	return
# 29 "data/maps/FiveIsland_Meadow/scripts.pory"

# 30 "data/maps/FiveIsland_Meadow/scripts.pory"
FiveIsland_Meadow_EventScript_Sudowoodo::
# 31 "data/maps/FiveIsland_Meadow/scripts.pory"
	lock
# 32 "data/maps/FiveIsland_Meadow/scripts.pory"
	faceplayer
# 33 "data/maps/FiveIsland_Meadow/scripts.pory"
	waitse
# 34 "data/maps/FiveIsland_Meadow/scripts.pory"
	playse SE_SUDOWOODO_SHAKE
# 35 "data/maps/FiveIsland_Meadow/scripts.pory"
	applymovement LOCALID_FIVE_ISLAND_MEADOW_SUDOWOODO, FiveIsland_Meadow_Movement_SudowoodoShake
# 36 "data/maps/FiveIsland_Meadow/scripts.pory"
	waitmovement 0
# 37 "data/maps/FiveIsland_Meadow/scripts.pory"
	release
# 38 "data/maps/FiveIsland_Meadow/scripts.pory"
	end
# 39 "data/maps/FiveIsland_Meadow/scripts.pory"

# 40 "data/maps/FiveIsland_Meadow/scripts.pory"
FiveIsland_Meadow_EventScript_HeadbuttSudowoodo::
# 41 "data/maps/FiveIsland_Meadow/scripts.pory"
	lockall
# 42 "data/maps/FiveIsland_Meadow/scripts.pory"
	checkpartymove MOVE_HEADBUTT
# 43 "data/maps/FiveIsland_Meadow/scripts.pory"
	compare VAR_RESULT, PARTY_SIZE
# 44 "data/maps/FiveIsland_Meadow/scripts.pory"
	goto_if_eq FiveIsland_Meadow_EventScript_Sudowoodo
# 45 "data/maps/FiveIsland_Meadow/scripts.pory"
	setfieldeffectargument 0, VAR_RESULT
# 46 "data/maps/FiveIsland_Meadow/scripts.pory"
	bufferpartymonnick 0, VAR_RESULT
# 47 "data/maps/FiveIsland_Meadow/scripts.pory"
	buffermovename 1, MOVE_HEADBUTT
# 48 "data/maps/FiveIsland_Meadow/scripts.pory"
	msgbox Text_WantToHeadbutt_Sudowoodo, MSGBOX_YESNO
# 49 "data/maps/FiveIsland_Meadow/scripts.pory"
	compare VAR_RESULT, NO
# 50 "data/maps/FiveIsland_Meadow/scripts.pory"
	goto_if_eq EventScript_CancelHeadbutt
# 51 "data/maps/FiveIsland_Meadow/scripts.pory"
	msgbox Text_MonUsedHeadbutt, MSGBOX_DEFAULT
# 52 "data/maps/FiveIsland_Meadow/scripts.pory"
	closemessage
# 53 "data/maps/FiveIsland_Meadow/scripts.pory"
	dofieldeffect FLDEFF_USE_HEADBUTT
# 54 "data/maps/FiveIsland_Meadow/scripts.pory"
	waitstate
# 55 "data/maps/FiveIsland_Meadow/scripts.pory"
	goto FiveIsland_Meadow_EventScript_HeadbuttTree_Sudowoodo
# 56 "data/maps/FiveIsland_Meadow/scripts.pory"
	end
# 57 "data/maps/FiveIsland_Meadow/scripts.pory"

# 58 "data/maps/FiveIsland_Meadow/scripts.pory"
FiveIsland_Meadow_EventScript_HeadbuttTree_Sudowoodo::
# 59 "data/maps/FiveIsland_Meadow/scripts.pory"
	lockall
# 60 "data/maps/FiveIsland_Meadow/scripts.pory"
	dofieldeffect FLDEFF_USE_HEADBUTT
# 61 "data/maps/FiveIsland_Meadow/scripts.pory"
	waitstate
# 62 "data/maps/FiveIsland_Meadow/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 63 "data/maps/FiveIsland_Meadow/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 64 "data/maps/FiveIsland_Meadow/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 65 "data/maps/FiveIsland_Meadow/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 66 "data/maps/FiveIsland_Meadow/scripts.pory"
	special ShakeScreen
# 67 "data/maps/FiveIsland_Meadow/scripts.pory"
	waitstate
# 68 "data/maps/FiveIsland_Meadow/scripts.pory"
	waitse
# 69 "data/maps/FiveIsland_Meadow/scripts.pory"
	playse SE_SUDOWOODO_SHAKE
# 70 "data/maps/FiveIsland_Meadow/scripts.pory"
	applymovement LOCALID_FIVE_ISLAND_MEADOW_SUDOWOODO, FiveIsland_Meadow_Movement_SudowoodoShake
# 71 "data/maps/FiveIsland_Meadow/scripts.pory"
	playse SE_SUDOWOODO_SHAKE
# 72 "data/maps/FiveIsland_Meadow/scripts.pory"
	applymovement LOCALID_FIVE_ISLAND_MEADOW_SUDOWOODO, FiveIsland_Meadow_Movement_SudowoodoShake
# 73 "data/maps/FiveIsland_Meadow/scripts.pory"
	waitmovement 0
# 74 "data/maps/FiveIsland_Meadow/scripts.pory"
	msgbox gText_Sudowoodo_Furious, MSGBOX_DEFAULT
# 75 "data/maps/FiveIsland_Meadow/scripts.pory"
	closemessage
# 76 "data/maps/FiveIsland_Meadow/scripts.pory"
	waitse
# 77 "data/maps/FiveIsland_Meadow/scripts.pory"
	playmoncry SPECIES_SUDOWOODO, CRY_MODE_ENCOUNTER
# 78 "data/maps/FiveIsland_Meadow/scripts.pory"
	delay 40
# 79 "data/maps/FiveIsland_Meadow/scripts.pory"
	waitmoncry
# 80 "data/maps/FiveIsland_Meadow/scripts.pory"
	setvar VAR_LAST_TALKED, LOCALID_FIVE_ISLAND_MEADOW_SUDOWOODO
# 81 "data/maps/FiveIsland_Meadow/scripts.pory"
	setwildbattle SPECIES_SUDOWOODO, 40
# 82 "data/maps/FiveIsland_Meadow/scripts.pory"
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
# 83 "data/maps/FiveIsland_Meadow/scripts.pory"
	dowildbattle
# 84 "data/maps/FiveIsland_Meadow/scripts.pory"
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
# 85 "data/maps/FiveIsland_Meadow/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 86 "data/maps/FiveIsland_Meadow/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, FiveIsland_Meadow_EventScript_DefeatedSudowoodo
# 87 "data/maps/FiveIsland_Meadow/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, FiveIsland_Meadow_EventScript_DefeatedSudowoodo
# 88 "data/maps/FiveIsland_Meadow/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, FiveIsland_Meadow_EventScript_DefeatedSudowoodo
# 89 "data/maps/FiveIsland_Meadow/scripts.pory"
	setflag FLAG_DEFEATED_FIVE_ISLAND_MEADOW_SUDOWOODO
# 90 "data/maps/FiveIsland_Meadow/scripts.pory"
	release
# 91 "data/maps/FiveIsland_Meadow/scripts.pory"
	end
# 92 "data/maps/FiveIsland_Meadow/scripts.pory"

# 93 "data/maps/FiveIsland_Meadow/scripts.pory"
FiveIsland_Meadow_EventScript_DefeatedSudowoodo::
# 94 "data/maps/FiveIsland_Meadow/scripts.pory"
	setflag FLAG_DEFEATED_FIVE_ISLAND_MEADOW_SUDOWOODO
# 95 "data/maps/FiveIsland_Meadow/scripts.pory"
	goto EventScript_RemoveStaticMon
# 96 "data/maps/FiveIsland_Meadow/scripts.pory"
	end
# 97 "data/maps/FiveIsland_Meadow/scripts.pory"

# 98 "data/maps/FiveIsland_Meadow/scripts.pory"
FiveIsland_Meadow_Movement_SudowoodoShake:
# 99 "data/maps/FiveIsland_Meadow/scripts.pory"
	face_right
# 100 "data/maps/FiveIsland_Meadow/scripts.pory"
	delay_8
# 101 "data/maps/FiveIsland_Meadow/scripts.pory"
	face_down
# 102 "data/maps/FiveIsland_Meadow/scripts.pory"
	delay_8
# 103 "data/maps/FiveIsland_Meadow/scripts.pory"
	face_left
# 104 "data/maps/FiveIsland_Meadow/scripts.pory"
	delay_8
# 105 "data/maps/FiveIsland_Meadow/scripts.pory"
	face_down
# 106 "data/maps/FiveIsland_Meadow/scripts.pory"
	delay_8
# 107 "data/maps/FiveIsland_Meadow/scripts.pory"
	face_right
# 108 "data/maps/FiveIsland_Meadow/scripts.pory"
	delay_8
# 109 "data/maps/FiveIsland_Meadow/scripts.pory"
	face_down
# 110 "data/maps/FiveIsland_Meadow/scripts.pory"
	delay_8
# 111 "data/maps/FiveIsland_Meadow/scripts.pory"
	face_left
# 112 "data/maps/FiveIsland_Meadow/scripts.pory"
	delay_8
# 113 "data/maps/FiveIsland_Meadow/scripts.pory"
	face_down
# 114 "data/maps/FiveIsland_Meadow/scripts.pory"
	step_end
# 115 "data/maps/FiveIsland_Meadow/scripts.pory"

# 116 "data/maps/FiveIsland_Meadow/scripts.pory"
FiveIsland_Meadow_EventScript_WarehouseDoor::
# 117 "data/maps/FiveIsland_Meadow/scripts.pory"
	lockall
# 118 "data/maps/FiveIsland_Meadow/scripts.pory"
	goto_if_set FLAG_UNLOCKED_ROCKET_WAREHOUSE, FiveIsland_Meadow_EventScript_WarehouseDoorAlreadyOpen
# 119 "data/maps/FiveIsland_Meadow/scripts.pory"
	goto_if_set FLAG_LEARNED_YES_NAH_CHANSEY, FiveIsland_Meadow_EventScript_OpenWarehouseDoor
# 120 "data/maps/FiveIsland_Meadow/scripts.pory"
	msgbox FiveIsland_Meadow_Text_EnteredPasswordAnotherNeeded
# 121 "data/maps/FiveIsland_Meadow/scripts.pory"
	releaseall
# 122 "data/maps/FiveIsland_Meadow/scripts.pory"
	end
# 123 "data/maps/FiveIsland_Meadow/scripts.pory"

# 124 "data/maps/FiveIsland_Meadow/scripts.pory"
FiveIsland_Meadow_EventScript_OpenWarehouseDoor::
# 125 "data/maps/FiveIsland_Meadow/scripts.pory"
	setflag FLAG_UNLOCKED_ROCKET_WAREHOUSE
# 126 "data/maps/FiveIsland_Meadow/scripts.pory"
	message FiveIsland_Meadow_Text_EnteredPasswordDoorOpened
# 127 "data/maps/FiveIsland_Meadow/scripts.pory"
	waitmessage
# 128 "data/maps/FiveIsland_Meadow/scripts.pory"
	delay 60
# 129 "data/maps/FiveIsland_Meadow/scripts.pory"
	call FiveIsland_Meadow_EventScript_SetWarehouseDoorUnlocked
# 130 "data/maps/FiveIsland_Meadow/scripts.pory"
	special DrawWholeMapView
# 131 "data/maps/FiveIsland_Meadow/scripts.pory"
	playse SE_PIN
# 132 "data/maps/FiveIsland_Meadow/scripts.pory"
	waitse
# 133 "data/maps/FiveIsland_Meadow/scripts.pory"
	releaseall
# 134 "data/maps/FiveIsland_Meadow/scripts.pory"
	end
# 135 "data/maps/FiveIsland_Meadow/scripts.pory"

# 136 "data/maps/FiveIsland_Meadow/scripts.pory"
FiveIsland_Meadow_EventScript_WarehouseDoorAlreadyOpen::
# 137 "data/maps/FiveIsland_Meadow/scripts.pory"
	msgbox FiveIsland_Meadow_Text_WarehouseDoorAlreadyOpen
# 138 "data/maps/FiveIsland_Meadow/scripts.pory"
	releaseall
# 139 "data/maps/FiveIsland_Meadow/scripts.pory"
	end
# 140 "data/maps/FiveIsland_Meadow/scripts.pory"

# 141 "data/maps/FiveIsland_Meadow/scripts.pory"
FiveIsland_Meadow_EventScript_SetWarehouseDoorUnlocked::
# 142 "data/maps/FiveIsland_Meadow/scripts.pory"
	setmetatile 12, 21, METATILE_SeviiIslands45_RocketWarehouseDoor_Unlocked, 1
# 143 "data/maps/FiveIsland_Meadow/scripts.pory"
	return
# 144 "data/maps/FiveIsland_Meadow/scripts.pory"

# 145 "data/maps/FiveIsland_Meadow/scripts.pory"
FiveIsland_Meadow_EventScript_Rocket1::
# 146 "data/maps/FiveIsland_Meadow/scripts.pory"
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_49, FiveIsland_Meadow_Text_Rocket1Intro, FiveIsland_Meadow_Text_Rocket1Defeat
# 147 "data/maps/FiveIsland_Meadow/scripts.pory"
	msgbox FiveIsland_Meadow_Text_Rocket1PostBattle, MSGBOX_AUTOCLOSE
# 148 "data/maps/FiveIsland_Meadow/scripts.pory"
	end
# 149 "data/maps/FiveIsland_Meadow/scripts.pory"

# 150 "data/maps/FiveIsland_Meadow/scripts.pory"
FiveIsland_Meadow_EventScript_Rocket2::
# 151 "data/maps/FiveIsland_Meadow/scripts.pory"
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_50, FiveIsland_Meadow_Text_Rocket2Intro, FiveIsland_Meadow_Text_Rocket2Defeat
# 152 "data/maps/FiveIsland_Meadow/scripts.pory"
	msgbox FiveIsland_Meadow_Text_Rocket2PostBattle, MSGBOX_AUTOCLOSE
# 153 "data/maps/FiveIsland_Meadow/scripts.pory"
	end
# 154 "data/maps/FiveIsland_Meadow/scripts.pory"

# 155 "data/maps/FiveIsland_Meadow/scripts.pory"
FiveIsland_Meadow_EventScript_Rocket3::
# 156 "data/maps/FiveIsland_Meadow/scripts.pory"
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_51, FiveIsland_Meadow_Text_Rocket3Intro, FiveIsland_Meadow_Text_Rocket3Defeat
# 157 "data/maps/FiveIsland_Meadow/scripts.pory"
	msgbox FiveIsland_Meadow_Text_Rocket3PostBattle, MSGBOX_AUTOCLOSE
# 158 "data/maps/FiveIsland_Meadow/scripts.pory"
	end
# 159 "data/maps/FiveIsland_Meadow/scripts.pory"

# 160 "data/maps/FiveIsland_Meadow/scripts.pory"
gText_Sudowoodo_Furious::
# 161 "data/maps/FiveIsland_Meadow/scripts.pory"
	.string "The weird tree has become furious!\p"
# 162 "data/maps/FiveIsland_Meadow/scripts.pory"
	.string "The weird tree attacked!$"
