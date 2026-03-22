FiveIsland_Meadow_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, FiveIsland_Meadow_OnLoad
	map_script MAP_SCRIPT_ON_RESUME, FiveIsland_Meadow_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, FiveIsland_Meadow_OnTransition
	.byte 0

FiveIsland_Meadow_OnLoad::
	call_if_set FLAG_UNLOCKED_ROCKET_WAREHOUSE, FiveIsland_Meadow_EventScript_SetWarehouseDoorUnlocked
	end

FiveIsland_Meadow_OnResume:
	call_if_set FLAG_SYS_SPECIAL_WILD_BATTLE, FiveIsland_Meadow_EventScript_TryRemoveSudowoodo
	end

FiveIsland_Meadow_EventScript_TryRemoveSudowoodo::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, EventScript_Return
	removeobject VAR_LAST_TALKED
	return

FiveIsland_Meadow_OnTransition:
	call_if_unset FLAG_DEFEATED_FIVE_ISLAND_MEADOW_SUDOWOODO, FiveIsland_Meadow_EventScript_ShowSudowoodo
	end

FiveIsland_Meadow_EventScript_ShowSudowoodo::
	clearflag FLAG_HIDE_FIVE_ISLAND_MEADOW_SUDOWOODO
	return

FiveIsland_Meadow_EventScript_Sudowoodo::
	lock
	faceplayer
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_FIVE_ISLAND_MEADOW_SUDOWOODO, FiveIsland_Meadow_Movement_SudowoodoShake
	waitmovement 0
	release
	end

FiveIsland_Meadow_EventScript_HeadbuttSudowoodo::
	lockall
	checkpartymove MOVE_HEADBUTT
	compare VAR_RESULT, PARTY_SIZE
	goto_if_eq FiveIsland_Meadow_EventScript_Sudowoodo
	setfieldeffectargument 0, VAR_RESULT
	bufferpartymonnick 0, VAR_RESULT
	buffermovename 1, MOVE_HEADBUTT
	msgbox Text_WantToHeadbutt_Sudowoodo, MSGBOX_YESNO
	compare VAR_RESULT, NO
	goto_if_eq EventScript_CancelHeadbutt
	msgbox Text_MonUsedHeadbutt, MSGBOX_DEFAULT
	closemessage
	dofieldeffect FLDEFF_USE_HEADBUTT
	waitstate
	goto FiveIsland_Meadow_EventScript_HeadbuttTree_Sudowoodo
	end

FiveIsland_Meadow_EventScript_HeadbuttTree_Sudowoodo::
	lockall
	dofieldeffect FLDEFF_USE_HEADBUTT
	waitstate
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeScreen
	waitstate
	waitse
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_FIVE_ISLAND_MEADOW_SUDOWOODO, FiveIsland_Meadow_Movement_SudowoodoShake
	playse SE_SUDOWOODO_SHAKE
	applymovement LOCALID_FIVE_ISLAND_MEADOW_SUDOWOODO, FiveIsland_Meadow_Movement_SudowoodoShake
	waitmovement 0
	msgbox gText_Sudowoodo_Furious, MSGBOX_DEFAULT
	closemessage
	waitse
	playmoncry SPECIES_SUDOWOODO, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_FIVE_ISLAND_MEADOW_SUDOWOODO
	setwildbattle SPECIES_SUDOWOODO, 40
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
	dowildbattle
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, FiveIsland_Meadow_EventScript_DefeatedSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, FiveIsland_Meadow_EventScript_DefeatedSudowoodo
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, FiveIsland_Meadow_EventScript_DefeatedSudowoodo
	setflag FLAG_DEFEATED_FIVE_ISLAND_MEADOW_SUDOWOODO
	release
	end

FiveIsland_Meadow_EventScript_DefeatedSudowoodo::
	setflag FLAG_DEFEATED_FIVE_ISLAND_MEADOW_SUDOWOODO
	goto EventScript_RemoveStaticMon
	end

FiveIsland_Meadow_Movement_SudowoodoShake:
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	delay_8
	face_right
	delay_8
	face_down
	delay_8
	face_left
	delay_8
	face_down
	step_end

FiveIsland_Meadow_EventScript_WarehouseDoor::
	lockall
	goto_if_set FLAG_UNLOCKED_ROCKET_WAREHOUSE, FiveIsland_Meadow_EventScript_WarehouseDoorAlreadyOpen
	goto_if_set FLAG_LEARNED_YES_NAH_CHANSEY, FiveIsland_Meadow_EventScript_OpenWarehouseDoor
	msgbox FiveIsland_Meadow_Text_EnteredPasswordAnotherNeeded
	releaseall
	end

FiveIsland_Meadow_EventScript_OpenWarehouseDoor::
	setflag FLAG_UNLOCKED_ROCKET_WAREHOUSE
	message FiveIsland_Meadow_Text_EnteredPasswordDoorOpened
	waitmessage
	delay 60
	call FiveIsland_Meadow_EventScript_SetWarehouseDoorUnlocked
	special DrawWholeMapView
	playse SE_PIN
	waitse
	releaseall
	end

FiveIsland_Meadow_EventScript_WarehouseDoorAlreadyOpen::
	msgbox FiveIsland_Meadow_Text_WarehouseDoorAlreadyOpen
	releaseall
	end

FiveIsland_Meadow_EventScript_SetWarehouseDoorUnlocked::
	setmetatile 12, 21, METATILE_SeviiIslands45_RocketWarehouseDoor_Unlocked, 1
	return

FiveIsland_Meadow_EventScript_Rocket1::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_49, FiveIsland_Meadow_Text_Rocket1Intro, FiveIsland_Meadow_Text_Rocket1Defeat
	msgbox FiveIsland_Meadow_Text_Rocket1PostBattle, MSGBOX_AUTOCLOSE
	end

FiveIsland_Meadow_EventScript_Rocket2::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_50, FiveIsland_Meadow_Text_Rocket2Intro, FiveIsland_Meadow_Text_Rocket2Defeat
	msgbox FiveIsland_Meadow_Text_Rocket2PostBattle, MSGBOX_AUTOCLOSE
	end

FiveIsland_Meadow_EventScript_Rocket3::
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_51, FiveIsland_Meadow_Text_Rocket3Intro, FiveIsland_Meadow_Text_Rocket3Defeat
	msgbox FiveIsland_Meadow_Text_Rocket3PostBattle, MSGBOX_AUTOCLOSE
	end

gText_Sudowoodo_Furious::
	.string "The weird tree has become furious!\p"
	.string "The weird tree attacked!$"
