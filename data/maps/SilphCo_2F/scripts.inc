# 1 "data/maps/SilphCo_2F/scripts.pory"

# 2 "data/maps/SilphCo_2F/scripts.pory"
SilphCo_2F_MapScripts::
# 3 "data/maps/SilphCo_2F/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, SilphCo_2F_OnLoad
# 4 "data/maps/SilphCo_2F/scripts.pory"
	.byte 0
# 5 "data/maps/SilphCo_2F/scripts.pory"

# 6 "data/maps/SilphCo_2F/scripts.pory"
SilphCo_2F_OnLoad::
# 7 "data/maps/SilphCo_2F/scripts.pory"
	call_if_unset FLAG_SILPH_2F_DOOR_1, EventScript_Close2FDoor1
# 8 "data/maps/SilphCo_2F/scripts.pory"
	call_if_unset FLAG_SILPH_2F_DOOR_2, EventScript_Close2FDoor2
# 9 "data/maps/SilphCo_2F/scripts.pory"
	end
# 10 "data/maps/SilphCo_2F/scripts.pory"

# 11 "data/maps/SilphCo_2F/scripts.pory"
SilphCo_2F_EventScript_Woman::
# 12 "data/maps/SilphCo_2F/scripts.pory"
	goto_if_unset FLAG_GOT_TM73, SilphCo_2F_EventScript_Woman_Give_ThunderWave
# 13 "data/maps/SilphCo_2F/scripts.pory"
	msgbox SilphCo_2F_Text_Woman_GaveThunderWave, MSGBOX_NPC
# 14 "data/maps/SilphCo_2F/scripts.pory"
	end
# 15 "data/maps/SilphCo_2F/scripts.pory"

# 16 "data/maps/SilphCo_2F/scripts.pory"
SilphCo_2F_EventScript_Woman_Give_ThunderWave::
# 17 "data/maps/SilphCo_2F/scripts.pory"
	msgbox SilphCo_2F_Text_Woman_GiveThunderWave, MSGBOX_NPC
# 18 "data/maps/SilphCo_2F/scripts.pory"
	textcolor NPC_TEXT_COLOR_NEUTRAL
# 19 "data/maps/SilphCo_2F/scripts.pory"
	checkitemspace ITEM_TM73
# 20 "data/maps/SilphCo_2F/scripts.pory"
	goto_if_eq VAR_RESULT, FALSE, EventScript_BagIsFull
# 21 "data/maps/SilphCo_2F/scripts.pory"
	bufferitemname STR_VAR_2, ITEM_TM73
# 22 "data/maps/SilphCo_2F/scripts.pory"
	playfanfare MUS_LEVEL_UP
# 23 "data/maps/SilphCo_2F/scripts.pory"
	message Text_ObtainedTheX
# 24 "data/maps/SilphCo_2F/scripts.pory"
	waitmessage
# 25 "data/maps/SilphCo_2F/scripts.pory"
	waitfanfare
# 26 "data/maps/SilphCo_2F/scripts.pory"
	additem ITEM_TM73
# 27 "data/maps/SilphCo_2F/scripts.pory"
	msgbox SilphCo_2F_Text_TM73Away
# 28 "data/maps/SilphCo_2F/scripts.pory"
	call EventScript_RestorePrevTextColor
# 29 "data/maps/SilphCo_2F/scripts.pory"
	setflag FLAG_GOT_TM73
# 30 "data/maps/SilphCo_2F/scripts.pory"
	msgbox SilphCo_2F_Text_Woman_GaveThunderWave, MSGBOX_NPC
# 31 "data/maps/SilphCo_2F/scripts.pory"
	release
# 32 "data/maps/SilphCo_2F/scripts.pory"
	end
# 33 "data/maps/SilphCo_2F/scripts.pory"

# 34 "data/maps/SilphCo_2F/scripts.pory"
SilphCo_2F_EventScript_FloorSign::
# 35 "data/maps/SilphCo_2F/scripts.pory"
	msgbox SilphCo_2F_Text_FloorSign, MSGBOX_SIGN
# 36 "data/maps/SilphCo_2F/scripts.pory"
	end
# 37 "data/maps/SilphCo_2F/scripts.pory"

# 38 "data/maps/SilphCo_2F/scripts.pory"
SilphCo_2F_EventScript_Connor::
# 39 "data/maps/SilphCo_2F/scripts.pory"
	trainerbattle_single TRAINER_SCIENTIST_CONNOR, SilphCo_2F_Text_ConnorIntro, SilphCo_2F_Text_ConnorDefeat
# 40 "data/maps/SilphCo_2F/scripts.pory"
	msgbox SilphCo_2F_Text_ConnorPostBattle, MSGBOX_AUTOCLOSE
# 41 "data/maps/SilphCo_2F/scripts.pory"
	end
# 42 "data/maps/SilphCo_2F/scripts.pory"

# 43 "data/maps/SilphCo_2F/scripts.pory"
SilphCo_2F_EventScript_Jerry::
# 44 "data/maps/SilphCo_2F/scripts.pory"
	trainerbattle_single TRAINER_SCIENTIST_JERRY, SilphCo_2F_Text_JerryIntro, SilphCo_2F_Text_JerryDefeat
# 45 "data/maps/SilphCo_2F/scripts.pory"
	msgbox SilphCo_2F_Text_JerryPostBattle, MSGBOX_AUTOCLOSE
# 46 "data/maps/SilphCo_2F/scripts.pory"
	end
# 47 "data/maps/SilphCo_2F/scripts.pory"

# 48 "data/maps/SilphCo_2F/scripts.pory"
SilphCo_2F_EventScript_Grunt1::
# 49 "data/maps/SilphCo_2F/scripts.pory"
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_23, SilphCo_2F_Text_Grunt1Intro, SilphCo_2F_Text_Grunt1Defeat
# 50 "data/maps/SilphCo_2F/scripts.pory"
	msgbox SilphCo_2F_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
# 51 "data/maps/SilphCo_2F/scripts.pory"
	end
# 52 "data/maps/SilphCo_2F/scripts.pory"

# 53 "data/maps/SilphCo_2F/scripts.pory"
SilphCo_2F_EventScript_Grunt2::
# 54 "data/maps/SilphCo_2F/scripts.pory"
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_24, SilphCo_2F_Text_Grunt2Intro, SilphCo_2F_Text_Grunt2Defeat
# 55 "data/maps/SilphCo_2F/scripts.pory"
	msgbox SilphCo_2F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
# 56 "data/maps/SilphCo_2F/scripts.pory"
	end
