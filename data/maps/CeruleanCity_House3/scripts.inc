# 1 "data/maps/CeruleanCity_House3/scripts.pory"

# 2 "data/maps/CeruleanCity_House3/scripts.pory"
CeruleanCity_House3_MapScripts::
# 3 "data/maps/CeruleanCity_House3/scripts.pory"
	.byte 0
# 4 "data/maps/CeruleanCity_House3/scripts.pory"

# 5 "data/maps/CeruleanCity_House3/scripts.pory"
CeruleanCity_House3_EventScript_OldWoman::
# 6 "data/maps/CeruleanCity_House3/scripts.pory"
	msgbox CeruleanCity_House3_Text_PleaseTradeWithMyHusband, MSGBOX_NPC
# 7 "data/maps/CeruleanCity_House3/scripts.pory"
	end
# 8 "data/maps/CeruleanCity_House3/scripts.pory"

# 9 "data/maps/CeruleanCity_House3/scripts.pory"
CeruleanCity_House3_EventScript_Dontae::
# 10 "data/maps/CeruleanCity_House3/scripts.pory"
	lock
# 11 "data/maps/CeruleanCity_House3/scripts.pory"
	faceplayer
# 12 "data/maps/CeruleanCity_House3/scripts.pory"
	ingame_trade INGAME_TRADE_JYNX, Trade_Text_DoYouHaveMonWouldYouTradeForMon, CeruleanCity_House3_EventScript_DeclineTrade, CeruleanCity_House3_EventScript_NotRequestedMon, Trade_Text_Thanks, FLAG_DID_ZYNX_TRADE, CeruleanCity_House3_EventScript_AlreadyTraded
# 13 "data/maps/CeruleanCity_House3/scripts.pory"
	release
# 14 "data/maps/CeruleanCity_House3/scripts.pory"
	end
# 15 "data/maps/CeruleanCity_House3/scripts.pory"

# 16 "data/maps/CeruleanCity_House3/scripts.pory"
CeruleanCity_House3_EventScript_DeclineTrade::
# 17 "data/maps/CeruleanCity_House3/scripts.pory"
	msgbox Trade_Text_WellIfYouDontWantTo
# 18 "data/maps/CeruleanCity_House3/scripts.pory"
	release
# 19 "data/maps/CeruleanCity_House3/scripts.pory"
	end
# 20 "data/maps/CeruleanCity_House3/scripts.pory"

# 21 "data/maps/CeruleanCity_House3/scripts.pory"
CeruleanCity_House3_EventScript_NotRequestedMon::
# 22 "data/maps/CeruleanCity_House3/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8009
# 23 "data/maps/CeruleanCity_House3/scripts.pory"
	msgbox Trade_Text_ThisIsntMon
# 24 "data/maps/CeruleanCity_House3/scripts.pory"
	release
# 25 "data/maps/CeruleanCity_House3/scripts.pory"
	end
# 26 "data/maps/CeruleanCity_House3/scripts.pory"

# 27 "data/maps/CeruleanCity_House3/scripts.pory"
CeruleanCity_House3_EventScript_AlreadyTraded::
# 28 "data/maps/CeruleanCity_House3/scripts.pory"
	msgbox Trade_Text_HasTradedMonGrownStronger
# 29 "data/maps/CeruleanCity_House3/scripts.pory"
	release
# 30 "data/maps/CeruleanCity_House3/scripts.pory"
	end
