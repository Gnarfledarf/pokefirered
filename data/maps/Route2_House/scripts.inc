# 1 "data/maps/Route2_House/scripts.pory"

# 2 "data/maps/Route2_House/scripts.pory"
Route2_House_MapScripts::
# 3 "data/maps/Route2_House/scripts.pory"
	.byte 0
# 4 "data/maps/Route2_House/scripts.pory"

# 5 "data/maps/Route2_House/scripts.pory"
Route2_House_EventScript_Scientist::
# 6 "data/maps/Route2_House/scripts.pory"
	msgbox Route2_House_Text_FaintedMonsCanUseFieldMoves, MSGBOX_NPC
# 7 "data/maps/Route2_House/scripts.pory"
	end
# 8 "data/maps/Route2_House/scripts.pory"

# 9 "data/maps/Route2_House/scripts.pory"
Route2_House_EventScript_Reyley::
# 10 "data/maps/Route2_House/scripts.pory"
	lock
# 11 "data/maps/Route2_House/scripts.pory"
	faceplayer
# 12 "data/maps/Route2_House/scripts.pory"
	ingame_trade INGAME_TRADE_MR_MIME, Trade_Text_LookingForMonWannaTradeForMon, Route2_House_EventScript_DeclineTrade, Route2_House_EventScript_NotRequestedMon, Trade_Text_HeyThanks, FLAG_DID_MIMIEN_TRADE, Route2_House_EventScript_AlreadyTraded
# 13 "data/maps/Route2_House/scripts.pory"
	release
# 14 "data/maps/Route2_House/scripts.pory"
	end
# 15 "data/maps/Route2_House/scripts.pory"

# 16 "data/maps/Route2_House/scripts.pory"
Route2_House_EventScript_DeclineTrade::
# 17 "data/maps/Route2_House/scripts.pory"
	msgbox Trade_Text_AwwOhWell
# 18 "data/maps/Route2_House/scripts.pory"
	release
# 19 "data/maps/Route2_House/scripts.pory"
	end
# 20 "data/maps/Route2_House/scripts.pory"

# 21 "data/maps/Route2_House/scripts.pory"
Route2_House_EventScript_NotRequestedMon::
# 22 "data/maps/Route2_House/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8009
# 23 "data/maps/Route2_House/scripts.pory"
	msgbox Trade_Text_WhatThatsNoMon
# 24 "data/maps/Route2_House/scripts.pory"
	release
# 25 "data/maps/Route2_House/scripts.pory"
	end
# 26 "data/maps/Route2_House/scripts.pory"

# 27 "data/maps/Route2_House/scripts.pory"
Route2_House_EventScript_AlreadyTraded::
# 28 "data/maps/Route2_House/scripts.pory"
	msgbox Trade_Text_IsntMyOldMonGreat
# 29 "data/maps/Route2_House/scripts.pory"
	release
# 30 "data/maps/Route2_House/scripts.pory"
	end
