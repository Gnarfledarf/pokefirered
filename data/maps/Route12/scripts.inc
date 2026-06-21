# 1 "data/maps/Route12/scripts.pory"

# 2 "data/maps/Route12/scripts.pory"
Route12_MapScripts::
# 3 "data/maps/Route12/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Route12_OnLoad
# 4 "data/maps/Route12/scripts.pory"
	map_script MAP_SCRIPT_ON_RESUME, Route12_OnResume
# 5 "data/maps/Route12/scripts.pory"
	.byte 0
# 6 "data/maps/Route12/scripts.pory"

# 7 "data/maps/Route12/scripts.pory"
Route12_OnResume::
# 8 "data/maps/Route12/scripts.pory"
	call_if_set FLAG_SYS_SPECIAL_WILD_BATTLE, Route12_EventScript_TryRemoveSnorlax
# 9 "data/maps/Route12/scripts.pory"
	end
# 10 "data/maps/Route12/scripts.pory"

# 11 "data/maps/Route12/scripts.pory"
Route12_OnLoad::
# 12 "data/maps/Route12/scripts.pory"
#ifdef FIRERED
# 13 "data/maps/Route12/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES(HORSEA)
# 14 "data/maps/Route12/scripts.pory"
#else
# 15 "data/maps/Route12/scripts.pory"
#ifdef LEAFGREEN
# 16 "data/maps/Route12/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES(KRABBY)
# 17 "data/maps/Route12/scripts.pory"
#endif
# 18 "data/maps/Route12/scripts.pory"
#endif
# 19 "data/maps/Route12/scripts.pory"
	special SetRoofBirds
# 20 "data/maps/Route12/scripts.pory"
	end
# 21 "data/maps/Route12/scripts.pory"

# 22 "data/maps/Route12/scripts.pory"
Route12_EventScript_TryRemoveSnorlax::
# 23 "data/maps/Route12/scripts.pory"
	removeobject VAR_LAST_TALKED
# 24 "data/maps/Route12/scripts.pory"
	return
# 25 "data/maps/Route12/scripts.pory"

# 26 "data/maps/Route12/scripts.pory"
Route12_EventScript_Snorlax::
# 27 "data/maps/Route12/scripts.pory"
	lock
# 28 "data/maps/Route12/scripts.pory"
	faceplayer
# 29 "data/maps/Route12/scripts.pory"
	goto_if_unset FLAG_GOT_POKE_FLUTE, Route12_EventScript_SnorlaxNoPokeFlute
# 30 "data/maps/Route12/scripts.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 31 "data/maps/Route12/scripts.pory"
	special QuestLog_CutRecording
# 32 "data/maps/Route12/scripts.pory"
	msgbox Text_WantToUsePokeFlute, MSGBOX_YESNO
# 33 "data/maps/Route12/scripts.pory"
	goto_if_eq VAR_RESULT, NO, Route12_EventScript_DontUsePokeFlute
# 34 "data/maps/Route12/scripts.pory"
	call EventScript_AwakenSnorlax
# 35 "data/maps/Route12/scripts.pory"
	setwildbattle SPECIES_SNORLAX, 30
# 36 "data/maps/Route12/scripts.pory"
	waitse
# 37 "data/maps/Route12/scripts.pory"
	playmoncry SPECIES_SNORLAX, CRY_MODE_ENCOUNTER
# 38 "data/maps/Route12/scripts.pory"
	delay 40
# 39 "data/maps/Route12/scripts.pory"
	waitmoncry
# 40 "data/maps/Route12/scripts.pory"
	setflag FLAG_HIDE_ROUTE_12_SNORLAX
# 41 "data/maps/Route12/scripts.pory"
	setflag FLAG_SYS_SPECIAL_WILD_BATTLE
# 42 "data/maps/Route12/scripts.pory"
	setflag FLAG_WOKE_UP_ROUTE_12_SNORLAX
# 43 "data/maps/Route12/scripts.pory"
	dowildbattle
# 44 "data/maps/Route12/scripts.pory"
	clearflag FLAG_SYS_SPECIAL_WILD_BATTLE
# 45 "data/maps/Route12/scripts.pory"
	specialvar VAR_RESULT, GetBattleOutcome
# 46 "data/maps/Route12/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, Route12_EventScript_FoughtSnorlax
# 47 "data/maps/Route12/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, Route12_EventScript_FoughtSnorlax
# 48 "data/maps/Route12/scripts.pory"
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, Route12_EventScript_FoughtSnorlax
# 49 "data/maps/Route12/scripts.pory"
	release
# 50 "data/maps/Route12/scripts.pory"
	end
# 51 "data/maps/Route12/scripts.pory"

# 52 "data/maps/Route12/scripts.pory"
Route12_EventScript_DontUsePokeFlute::
# 53 "data/maps/Route12/scripts.pory"
	release
# 54 "data/maps/Route12/scripts.pory"
	end
# 55 "data/maps/Route12/scripts.pory"

# 56 "data/maps/Route12/scripts.pory"
Route12_EventScript_FoughtSnorlax::
# 57 "data/maps/Route12/scripts.pory"
	msgbox Text_SnorlaxReturnedToMountains
# 58 "data/maps/Route12/scripts.pory"
	release
# 59 "data/maps/Route12/scripts.pory"
	end
# 60 "data/maps/Route12/scripts.pory"

# 61 "data/maps/Route12/scripts.pory"
Route12_EventScript_SnorlaxNoPokeFlute::
# 62 "data/maps/Route12/scripts.pory"
	msgbox Route12_Text_MonSprawledOutInSlumber
# 63 "data/maps/Route12/scripts.pory"
	release
# 64 "data/maps/Route12/scripts.pory"
	end
# 65 "data/maps/Route12/scripts.pory"

# 66 "data/maps/Route12/scripts.pory"
Route12_EventScript_RouteSign::
# 67 "data/maps/Route12/scripts.pory"
	msgbox Route12_Text_RouteSign, MSGBOX_SIGN
# 68 "data/maps/Route12/scripts.pory"
	end
# 69 "data/maps/Route12/scripts.pory"

# 70 "data/maps/Route12/scripts.pory"
Route12_EventScript_FishingSign::
# 71 "data/maps/Route12/scripts.pory"
	msgbox Route12_Text_SportfishingArea, MSGBOX_SIGN
# 72 "data/maps/Route12/scripts.pory"
	end
