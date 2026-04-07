# 1 "data/maps/Route18_EastEntrance_2F/scripts.pory"

# 2 "data/maps/Route18_EastEntrance_2F/scripts.pory"
Route18_EastEntrance_2F_MapScripts::
# 3 "data/maps/Route18_EastEntrance_2F/scripts.pory"
	.byte 0
# 4 "data/maps/Route18_EastEntrance_2F/scripts.pory"

# 5 "data/maps/Route18_EastEntrance_2F/scripts.pory"
Route18_EastEntrance_2F_EventScript_LeftBinoculars::
# 6 "data/maps/Route18_EastEntrance_2F/scripts.pory"
	msgbox Route18_EastEntrance_2F_Text_PalletTownInWest, MSGBOX_SIGN
# 7 "data/maps/Route18_EastEntrance_2F/scripts.pory"
	end
# 8 "data/maps/Route18_EastEntrance_2F/scripts.pory"

# 9 "data/maps/Route18_EastEntrance_2F/scripts.pory"
Route18_EastEntrance_2F_EventScript_RightBinoculars::
# 10 "data/maps/Route18_EastEntrance_2F/scripts.pory"
	msgbox Route18_EastEntrance_2F_Text_PeopleSwimming, MSGBOX_SIGN
# 11 "data/maps/Route18_EastEntrance_2F/scripts.pory"
	end
# 12 "data/maps/Route18_EastEntrance_2F/scripts.pory"

# 13 "data/maps/Route18_EastEntrance_2F/scripts.pory"
Route18_EastEntrance_2F_EventScript_Haden::
# 14 "data/maps/Route18_EastEntrance_2F/scripts.pory"
	lock
# 15 "data/maps/Route18_EastEntrance_2F/scripts.pory"
	faceplayer
# 16 "data/maps/Route18_EastEntrance_2F/scripts.pory"
	ingame_trade INGAME_TRADE_LICKITUNG, Trade_Text_LookingForMonWannaTradeForMon, Route18_EastEntrance_2F_EventScript_DeclineTrade, Route18_EastEntrance_2F_EventScript_NotRequestedMon, Trade_Text_HeyThanks, FLAG_DID_MARC_TRADE, Route18_EastEntrance_2F_EventScript_AlreadyTraded
# 17 "data/maps/Route18_EastEntrance_2F/scripts.pory"
	release
# 18 "data/maps/Route18_EastEntrance_2F/scripts.pory"
	end
# 19 "data/maps/Route18_EastEntrance_2F/scripts.pory"

# 20 "data/maps/Route18_EastEntrance_2F/scripts.pory"
Route18_EastEntrance_2F_EventScript_DeclineTrade::
# 21 "data/maps/Route18_EastEntrance_2F/scripts.pory"
	msgbox Trade_Text_AwwOhWell
# 22 "data/maps/Route18_EastEntrance_2F/scripts.pory"
	release
# 23 "data/maps/Route18_EastEntrance_2F/scripts.pory"
	end
# 24 "data/maps/Route18_EastEntrance_2F/scripts.pory"

# 25 "data/maps/Route18_EastEntrance_2F/scripts.pory"
Route18_EastEntrance_2F_EventScript_NotRequestedMon::
# 26 "data/maps/Route18_EastEntrance_2F/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8009
# 27 "data/maps/Route18_EastEntrance_2F/scripts.pory"
	msgbox Trade_Text_WhatThatsNoMon
# 28 "data/maps/Route18_EastEntrance_2F/scripts.pory"
	release
# 29 "data/maps/Route18_EastEntrance_2F/scripts.pory"
	end
# 30 "data/maps/Route18_EastEntrance_2F/scripts.pory"

# 31 "data/maps/Route18_EastEntrance_2F/scripts.pory"
Route18_EastEntrance_2F_EventScript_AlreadyTraded::
# 32 "data/maps/Route18_EastEntrance_2F/scripts.pory"
	msgbox Trade_Text_IsntMyOldMonGreat
# 33 "data/maps/Route18_EastEntrance_2F/scripts.pory"
	release
# 34 "data/maps/Route18_EastEntrance_2F/scripts.pory"
	end
