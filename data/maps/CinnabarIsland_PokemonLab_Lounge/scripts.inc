# 1 "data/maps/CinnabarIsland_PokemonLab_Lounge/scripts.pory"

# 2 "data/maps/CinnabarIsland_PokemonLab_Lounge/scripts.pory"
CinnabarIsland_PokemonLab_Lounge_MapScripts::
# 3 "data/maps/CinnabarIsland_PokemonLab_Lounge/scripts.pory"
	.byte 0
# 4 "data/maps/CinnabarIsland_PokemonLab_Lounge/scripts.pory"

# 5 "data/maps/CinnabarIsland_PokemonLab_Lounge/scripts.pory"
CinnabarIsland_PokemonLab_Lounge_EventScript_Scientist::
# 6 "data/maps/CinnabarIsland_PokemonLab_Lounge/scripts.pory"
	msgbox CinnabarIsland_PokemonLab_Lounge_Text_FoundFossilInMtMoon, MSGBOX_NPC
# 7 "data/maps/CinnabarIsland_PokemonLab_Lounge/scripts.pory"
	end
# 8 "data/maps/CinnabarIsland_PokemonLab_Lounge/scripts.pory"

# 9 "data/maps/CinnabarIsland_PokemonLab_Lounge/scripts.pory"
CinnabarIsland_PokemonLab_Lounge_EventScript_Clifton::
# 10 "data/maps/CinnabarIsland_PokemonLab_Lounge/scripts.pory"
	lock
# 11 "data/maps/CinnabarIsland_PokemonLab_Lounge/scripts.pory"
	faceplayer
# 12 "data/maps/CinnabarIsland_PokemonLab_Lounge/scripts.pory"
	ingame_trade INGAME_TRADE_ELECTRODE, Trade_Text_DoYouHaveMonWouldYouTradeForMon, CinnabarIsland_PokemonLab_Lounge_EventScript_CliftonDeclineTrade, CinnabarIsland_PokemonLab_Lounge_EventScript_CliftonNotRequestedMon, Trade_Text_Thanks, FLAG_DID_ESPHERE_TRADE, CinnabarIsland_PokemonLab_Lounge_EventScript_CliftonAlreadyTraded
# 13 "data/maps/CinnabarIsland_PokemonLab_Lounge/scripts.pory"
	release
# 14 "data/maps/CinnabarIsland_PokemonLab_Lounge/scripts.pory"
	end
# 15 "data/maps/CinnabarIsland_PokemonLab_Lounge/scripts.pory"

# 16 "data/maps/CinnabarIsland_PokemonLab_Lounge/scripts.pory"
CinnabarIsland_PokemonLab_Lounge_EventScript_CliftonDeclineTrade::
# 17 "data/maps/CinnabarIsland_PokemonLab_Lounge/scripts.pory"
	msgbox Trade_Text_WellIfYouDontWantTo
# 18 "data/maps/CinnabarIsland_PokemonLab_Lounge/scripts.pory"
	release
# 19 "data/maps/CinnabarIsland_PokemonLab_Lounge/scripts.pory"
	end
# 20 "data/maps/CinnabarIsland_PokemonLab_Lounge/scripts.pory"

# 21 "data/maps/CinnabarIsland_PokemonLab_Lounge/scripts.pory"
CinnabarIsland_PokemonLab_Lounge_EventScript_CliftonNotRequestedMon::
# 22 "data/maps/CinnabarIsland_PokemonLab_Lounge/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8009
# 23 "data/maps/CinnabarIsland_PokemonLab_Lounge/scripts.pory"
	msgbox Trade_Text_ThisIsntMon
# 24 "data/maps/CinnabarIsland_PokemonLab_Lounge/scripts.pory"
	release
# 25 "data/maps/CinnabarIsland_PokemonLab_Lounge/scripts.pory"
	end
# 26 "data/maps/CinnabarIsland_PokemonLab_Lounge/scripts.pory"

# 27 "data/maps/CinnabarIsland_PokemonLab_Lounge/scripts.pory"
CinnabarIsland_PokemonLab_Lounge_EventScript_CliftonAlreadyTraded::
# 28 "data/maps/CinnabarIsland_PokemonLab_Lounge/scripts.pory"
	msgbox Trade_Text_HasTradedMonGrownStronger
# 29 "data/maps/CinnabarIsland_PokemonLab_Lounge/scripts.pory"
	release
# 30 "data/maps/CinnabarIsland_PokemonLab_Lounge/scripts.pory"
	end
# 31 "data/maps/CinnabarIsland_PokemonLab_Lounge/scripts.pory"

# 32 "data/maps/CinnabarIsland_PokemonLab_Lounge/scripts.pory"
CinnabarIsland_PokemonLab_Lounge_EventScript_Norma::
# 33 "data/maps/CinnabarIsland_PokemonLab_Lounge/scripts.pory"
	lock
# 34 "data/maps/CinnabarIsland_PokemonLab_Lounge/scripts.pory"
	faceplayer
# 35 "data/maps/CinnabarIsland_PokemonLab_Lounge/scripts.pory"
	ingame_trade INGAME_TRADE_TANGELA, Trade_Text_DoYouHaveMonWantToTradeForMon, CinnabarIsland_PokemonLab_Lounge_EventScript_NormaDeclineTrade, CinnabarIsland_PokemonLab_Lounge_EventScript_NormaNotRequestedMon, Trade_Text_ThanksYoureAPal, FLAG_DID_TANGENY_TRADE, CinnabarIsland_PokemonLab_Lounge_EventScript_NormaAlreadyTraded
# 36 "data/maps/CinnabarIsland_PokemonLab_Lounge/scripts.pory"
	release
# 37 "data/maps/CinnabarIsland_PokemonLab_Lounge/scripts.pory"
	end
# 38 "data/maps/CinnabarIsland_PokemonLab_Lounge/scripts.pory"

# 39 "data/maps/CinnabarIsland_PokemonLab_Lounge/scripts.pory"
CinnabarIsland_PokemonLab_Lounge_EventScript_NormaDeclineTrade::
# 40 "data/maps/CinnabarIsland_PokemonLab_Lounge/scripts.pory"
	msgbox Trade_Text_ThatsTooBad
# 41 "data/maps/CinnabarIsland_PokemonLab_Lounge/scripts.pory"
	release
# 42 "data/maps/CinnabarIsland_PokemonLab_Lounge/scripts.pory"
	end
# 43 "data/maps/CinnabarIsland_PokemonLab_Lounge/scripts.pory"

# 44 "data/maps/CinnabarIsland_PokemonLab_Lounge/scripts.pory"
CinnabarIsland_PokemonLab_Lounge_EventScript_NormaNotRequestedMon::
# 45 "data/maps/CinnabarIsland_PokemonLab_Lounge/scripts.pory"
	bufferspeciesname STR_VAR_1, VAR_0x8009
# 46 "data/maps/CinnabarIsland_PokemonLab_Lounge/scripts.pory"
	msgbox Trade_Text_ThisIsNoMon
# 47 "data/maps/CinnabarIsland_PokemonLab_Lounge/scripts.pory"
	release
# 48 "data/maps/CinnabarIsland_PokemonLab_Lounge/scripts.pory"
	end
# 49 "data/maps/CinnabarIsland_PokemonLab_Lounge/scripts.pory"

# 50 "data/maps/CinnabarIsland_PokemonLab_Lounge/scripts.pory"
CinnabarIsland_PokemonLab_Lounge_EventScript_NormaAlreadyTraded::
# 51 "data/maps/CinnabarIsland_PokemonLab_Lounge/scripts.pory"
	msgbox Trade_Text_HowIsMyOldMon
# 52 "data/maps/CinnabarIsland_PokemonLab_Lounge/scripts.pory"
	release
# 53 "data/maps/CinnabarIsland_PokemonLab_Lounge/scripts.pory"
	end
