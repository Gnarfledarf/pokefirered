# 1 "data/maps/Route6/scripts.pory"

# 2 "data/maps/Route6/scripts.pory"
Route6_MapScripts::
# 3 "data/maps/Route6/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Route6_OnLoad
# 4 "data/maps/Route6/scripts.pory"
	.byte 0
# 5 "data/maps/Route6/scripts.pory"

# 6 "data/maps/Route6/scripts.pory"
Route6_OnLoad::
# 7 "data/maps/Route6/scripts.pory"
#ifdef FIRERED
# 8 "data/maps/Route6/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES(ODDISH)
# 9 "data/maps/Route6/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES(ODDISH)
# 10 "data/maps/Route6/scripts.pory"
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_SPECIES(ODDISH)
# 11 "data/maps/Route6/scripts.pory"
	setvar VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_SPECIES(BEEDRILL)
# 12 "data/maps/Route6/scripts.pory"
#else
# 13 "data/maps/Route6/scripts.pory"
#ifdef LEAFGREEN
# 14 "data/maps/Route6/scripts.pory"
	setvar VAR_OBJ_GFX_ID_0, OBJ_EVENT_GFX_SPECIES(BELLSPROUT)
# 15 "data/maps/Route6/scripts.pory"
	setvar VAR_OBJ_GFX_ID_1, OBJ_EVENT_GFX_SPECIES(BELLSPROUT)
# 16 "data/maps/Route6/scripts.pory"
	setvar VAR_OBJ_GFX_ID_2, OBJ_EVENT_GFX_SPECIES(BELLSPROUT)
# 17 "data/maps/Route6/scripts.pory"
	setvar VAR_OBJ_GFX_ID_3, OBJ_EVENT_GFX_SPECIES(BUTTERFREE)
# 18 "data/maps/Route6/scripts.pory"
#endif
# 19 "data/maps/Route6/scripts.pory"
#endif
# 20 "data/maps/Route6/scripts.pory"
	special SetRoofBirds
# 21 "data/maps/Route6/scripts.pory"
	end
# 22 "data/maps/Route6/scripts.pory"

# 23 "data/maps/Route6/scripts.pory"
Route6_EventScript_UndergroundPathSign::
# 24 "data/maps/Route6/scripts.pory"
	msgbox Route6_Text_UndergroundPathSign, MSGBOX_SIGN
# 25 "data/maps/Route6/scripts.pory"
	end
