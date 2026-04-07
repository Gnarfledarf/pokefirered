# 1 "data/maps/UndergroundPath_NorthEntrance/scripts.pory"

# 2 "data/maps/UndergroundPath_NorthEntrance/scripts.pory"
UndergroundPath_NorthEntrance_MapScripts::
# 3 "data/maps/UndergroundPath_NorthEntrance/scripts.pory"
	.byte 0
# 4 "data/maps/UndergroundPath_NorthEntrance/scripts.pory"

# 5 "data/maps/UndergroundPath_NorthEntrance/scripts.pory"
UndergroundPath_NorthEntrance_EventScript_Saige::
# 6 "data/maps/UndergroundPath_NorthEntrance/scripts.pory"
	lock
# 7 "data/maps/UndergroundPath_NorthEntrance/scripts.pory"
	faceplayer
# 8 "data/maps/UndergroundPath_NorthEntrance/scripts.pory"
	ingame_trade INGAME_TRADE_NIDORAN, Trade_Text_DoYouHaveMonWantToTradeForMon, UndergroundPath_NorthEntrance_EventScript_DeclineTrade, UndergroundPath_NorthEntrance_EventScript_NotRequestedMon, Trade_Text_ThanksYoureAPal, FLAG_DID_MS_NIDO_TRADE, UndergroundPath_NorthEntrance_EventScript_AlreadyTraded
# 9 "data/maps/UndergroundPath_NorthEntrance/scripts.pory"
	release
# 10 "data/maps/UndergroundPath_NorthEntrance/scripts.pory"
	end
# 11 "data/maps/UndergroundPath_NorthEntrance/scripts.pory"

# 12 "data/maps/UndergroundPath_NorthEntrance/scripts.pory"
UndergroundPath_NorthEntrance_EventScript_DeclineTrade::
# 13 "data/maps/UndergroundPath_NorthEntrance/scripts.pory"
	msgbox Trade_Text_ThatsTooBad
# 14 "data/maps/UndergroundPath_NorthEntrance/scripts.pory"
	release
# 15 "data/maps/UndergroundPath_NorthEntrance/scripts.pory"
	end
# 16 "data/maps/UndergroundPath_NorthEntrance/scripts.pory"

# 17 "data/maps/UndergroundPath_NorthEntrance/scripts.pory"
UndergroundPath_NorthEntrance_EventScript_NotRequestedMon::
# 18 "data/maps/UndergroundPath_NorthEntrance/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8009
# 19 "data/maps/UndergroundPath_NorthEntrance/scripts.pory"
	msgbox Trade_Text_ThisIsNoMon
# 20 "data/maps/UndergroundPath_NorthEntrance/scripts.pory"
	release
# 21 "data/maps/UndergroundPath_NorthEntrance/scripts.pory"
	end
# 22 "data/maps/UndergroundPath_NorthEntrance/scripts.pory"

# 23 "data/maps/UndergroundPath_NorthEntrance/scripts.pory"
UndergroundPath_NorthEntrance_EventScript_AlreadyTraded::
# 24 "data/maps/UndergroundPath_NorthEntrance/scripts.pory"
	msgbox Trade_Text_HowIsMyOldMon
# 25 "data/maps/UndergroundPath_NorthEntrance/scripts.pory"
	release
# 26 "data/maps/UndergroundPath_NorthEntrance/scripts.pory"
	end
