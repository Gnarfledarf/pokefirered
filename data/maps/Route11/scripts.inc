# 1 "data/maps/Route11/scripts.pory"

# 2 "data/maps/Route11/scripts.pory"
Route11_MapScripts::
# 3 "data/maps/Route11/scripts.pory"
	map_script MAP_SCRIPT_ON_LOAD, Route11_OnLoad
# 4 "data/maps/Route11/scripts.pory"
	.byte 0
# 5 "data/maps/Route11/scripts.pory"

# 6 "data/maps/Route11/scripts.pory"
Route11_OnLoad::
# 7 "data/maps/Route11/scripts.pory"
	special SetRoofBirds
# 8 "data/maps/Route11/scripts.pory"
	end
# 9 "data/maps/Route11/scripts.pory"

# 10 "data/maps/Route11/scripts.pory"
Route11_EventScript_DiglettsCaveSign::
# 11 "data/maps/Route11/scripts.pory"
	msgbox Route11_Text_DiglettsCave, MSGBOX_SIGN
# 12 "data/maps/Route11/scripts.pory"
	end
