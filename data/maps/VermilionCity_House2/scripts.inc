# 1 "data/maps/VermilionCity_House2/scripts.pory"

# 2 "data/maps/VermilionCity_House2/scripts.pory"
VermilionCity_House2_MapScripts::
# 3 "data/maps/VermilionCity_House2/scripts.pory"
	.byte 0
# 4 "data/maps/VermilionCity_House2/scripts.pory"

# 5 "data/maps/VermilionCity_House2/scripts.pory"
VermilionCity_House2_EventScript_Elyssa::
# 6 "data/maps/VermilionCity_House2/scripts.pory"
	lock
# 7 "data/maps/VermilionCity_House2/scripts.pory"
	faceplayer
# 8 "data/maps/VermilionCity_House2/scripts.pory"
	ingame_trade INGAME_TRADE_FARFETCHD, VermilionCity_House2_Text_DoYouHaveMonWantToTradeForMyMon, VermilionCity_House2_EventScript_DeclineTrade, VermilionCity_House2_EventScript_NotRequestedMon, VermilionCity_House2_Text_ThankYou, FLAG_DID_CH_DING_TRADE, VermilionCity_House2_EventScript_AlreadyTraded
# 9 "data/maps/VermilionCity_House2/scripts.pory"
	release
# 10 "data/maps/VermilionCity_House2/scripts.pory"
	end
# 11 "data/maps/VermilionCity_House2/scripts.pory"

# 12 "data/maps/VermilionCity_House2/scripts.pory"
VermilionCity_House2_EventScript_DeclineTrade::
# 13 "data/maps/VermilionCity_House2/scripts.pory"
	msgbox VermilionCity_House2_Text_ThatsTooBad
# 14 "data/maps/VermilionCity_House2/scripts.pory"
	release
# 15 "data/maps/VermilionCity_House2/scripts.pory"
	end
# 16 "data/maps/VermilionCity_House2/scripts.pory"

# 17 "data/maps/VermilionCity_House2/scripts.pory"
VermilionCity_House2_EventScript_NotRequestedMon::
# 18 "data/maps/VermilionCity_House2/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8009
# 19 "data/maps/VermilionCity_House2/scripts.pory"
	msgbox VermilionCity_House2_Text_ThisIsNoMon
# 20 "data/maps/VermilionCity_House2/scripts.pory"
	release
# 21 "data/maps/VermilionCity_House2/scripts.pory"
	end
# 22 "data/maps/VermilionCity_House2/scripts.pory"

# 23 "data/maps/VermilionCity_House2/scripts.pory"
VermilionCity_House2_EventScript_AlreadyTraded::
# 24 "data/maps/VermilionCity_House2/scripts.pory"
	msgbox VermilionCity_House2_Text_HowIsMyOldMon
# 25 "data/maps/VermilionCity_House2/scripts.pory"
	release
# 26 "data/maps/VermilionCity_House2/scripts.pory"
	end
