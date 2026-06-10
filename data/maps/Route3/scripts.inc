# 1 "data/maps/Route3/scripts.pory"

# 2 "data/maps/Route3/scripts.pory"
Route3_MapScripts::
# 3 "data/maps/Route3/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Route3_OnLoad
# 4 "data/maps/Route3/scripts.pory"
	.byte 0
# 5 "data/maps/Route3/scripts.pory"

# 6 "data/maps/Route3/scripts.pory"
Route3_OnLoad::
# 7 "data/maps/Route3/scripts.pory"
#ifdef FIRERED
# 8 "data/maps/Route3/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES(EKANS)
# 9 "data/maps/Route3/scripts.pory"
#else
# 10 "data/maps/Route3/scripts.pory"
#ifdef LEAFGREEN
# 11 "data/maps/Route3/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES(SANDSHREW)
# 12 "data/maps/Route3/scripts.pory"
#endif
# 13 "data/maps/Route3/scripts.pory"
#endif
# 14 "data/maps/Route3/scripts.pory"
	special SetRoofBirds
# 15 "data/maps/Route3/scripts.pory"
	end
# 16 "data/maps/Route3/scripts.pory"

# 17 "data/maps/Route3/scripts.pory"
Route3_EventScript_Youngster::
# 18 "data/maps/Route3/scripts.pory"
	msgbox Route3_Text_TunnelFromCeruleanTiring, MSGBOX_NPC
# 19 "data/maps/Route3/scripts.pory"
	end
# 20 "data/maps/Route3/scripts.pory"

# 21 "data/maps/Route3/scripts.pory"
Route3_EventScript_RouteSign::
# 22 "data/maps/Route3/scripts.pory"
	msgbox Route3_Text_RouteSign, MSGBOX_SIGN
# 23 "data/maps/Route3/scripts.pory"
	end
