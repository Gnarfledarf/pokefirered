# 1 "data/maps/TwoIsland/scripts.pory"

# 2 "data/maps/TwoIsland/scripts.pory"
TwoIsland_MapScripts::
# 3 "data/maps/TwoIsland/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, TwoIsland_OnTransition
# 4 "data/maps/TwoIsland/scripts.pory"
	.byte 0
# 5 "data/maps/TwoIsland/scripts.pory"

# 6 "data/maps/TwoIsland/scripts.pory"
TwoIsland_OnTransition::
# 7 "data/maps/TwoIsland/scripts.pory"
	setworldmapflag FLAG_WORLD_MAP_TWO_ISLAND
# 8 "data/maps/TwoIsland/scripts.pory"
	setflag FLAG_VISITED_TWO_ISLAND
# 9 "data/maps/TwoIsland/scripts.pory"
	call TwoIsland_EventScript_SetShopState
# 10 "data/maps/TwoIsland/scripts.pory"
	end
# 11 "data/maps/TwoIsland/scripts.pory"

# 12 "data/maps/TwoIsland/scripts.pory"
TwoIsland_EventScript_SetShopState::
# 13 "data/maps/TwoIsland/scripts.pory"
	goto_if_set FLAG_SYS_CAN_LINK_WITH_RS, TwoIsland_EventScript_SetShopStateAfterHoennLink
# 14 "data/maps/TwoIsland/scripts.pory"
	goto_if_set FLAG_SYS_GAME_CLEAR, TwoIsland_EventScript_SetShopStateAfterChampion
# 15 "data/maps/TwoIsland/scripts.pory"
	goto_if_set FLAG_RESCUED_LOSTELLE, TwoIsland_EventScript_SetShopStateAfterLostelleRescue
# 16 "data/maps/TwoIsland/scripts.pory"
	goto TwoIsland_EventScript_SetShopStateDefault
# 17 "data/maps/TwoIsland/scripts.pory"
	end
# 18 "data/maps/TwoIsland/scripts.pory"

# 19 "data/maps/TwoIsland/scripts.pory"
TwoIsland_EventScript_SetShopStateAfterHoennLink::
# 20 "data/maps/TwoIsland/scripts.pory"
	goto_if_unset FLAG_TWO_ISLAND_SHOP_INTRODUCED, TwoIsland_EventScript_SetShopInitial
# 21 "data/maps/TwoIsland/scripts.pory"
	goto_if_unset FLAG_TWO_ISLAND_SHOP_EXPANDED_1, TwoIsland_EventScript_SetShopExpanded1
# 22 "data/maps/TwoIsland/scripts.pory"
	goto_if_unset FLAG_TWO_ISLAND_SHOP_EXPANDED_2, TwoIsland_EventScript_SetShopExpanded2
# 23 "data/maps/TwoIsland/scripts.pory"
	goto TwoIsland_EventScript_SetShopExpanded3
# 24 "data/maps/TwoIsland/scripts.pory"
	end
# 25 "data/maps/TwoIsland/scripts.pory"

# 26 "data/maps/TwoIsland/scripts.pory"
TwoIsland_EventScript_SetShopStateAfterChampion::
# 27 "data/maps/TwoIsland/scripts.pory"
	goto_if_unset FLAG_TWO_ISLAND_SHOP_INTRODUCED, TwoIsland_EventScript_SetShopInitial
# 28 "data/maps/TwoIsland/scripts.pory"
	goto_if_unset FLAG_RESCUED_LOSTELLE, TwoIsland_EventScript_SetShopInitial
# 29 "data/maps/TwoIsland/scripts.pory"
	goto_if_unset FLAG_TWO_ISLAND_SHOP_EXPANDED_1, TwoIsland_EventScript_SetShopExpanded1
# 30 "data/maps/TwoIsland/scripts.pory"
	goto TwoIsland_EventScript_SetShopExpanded2
# 31 "data/maps/TwoIsland/scripts.pory"
	end
# 32 "data/maps/TwoIsland/scripts.pory"

# 33 "data/maps/TwoIsland/scripts.pory"
TwoIsland_EventScript_SetShopStateAfterLostelleRescue::
# 34 "data/maps/TwoIsland/scripts.pory"
	goto_if_unset FLAG_TWO_ISLAND_SHOP_INTRODUCED, TwoIsland_EventScript_SetShopInitial
# 35 "data/maps/TwoIsland/scripts.pory"
	goto TwoIsland_EventScript_SetShopExpanded1
# 36 "data/maps/TwoIsland/scripts.pory"
	end
# 37 "data/maps/TwoIsland/scripts.pory"

# 38 "data/maps/TwoIsland/scripts.pory"
TwoIsland_EventScript_SetShopStateDefault::
# 39 "data/maps/TwoIsland/scripts.pory"
	goto TwoIsland_EventScript_SetShopInitial
# 40 "data/maps/TwoIsland/scripts.pory"
	end
# 41 "data/maps/TwoIsland/scripts.pory"

# 42 "data/maps/TwoIsland/scripts.pory"
TwoIsland_EventScript_SetShopInitial::
# 43 "data/maps/TwoIsland/scripts.pory"
	setvar VAR_MAP_SCENE_TWO_ISLAND, 1
# 44 "data/maps/TwoIsland/scripts.pory"
	return
# 45 "data/maps/TwoIsland/scripts.pory"

# 46 "data/maps/TwoIsland/scripts.pory"
TwoIsland_EventScript_SetShopExpanded1::
# 47 "data/maps/TwoIsland/scripts.pory"
	setvar VAR_MAP_SCENE_TWO_ISLAND, 2
# 48 "data/maps/TwoIsland/scripts.pory"
	clearflag FLAG_HIDE_TWO_ISLAND_WOMAN
# 49 "data/maps/TwoIsland/scripts.pory"
	return
# 50 "data/maps/TwoIsland/scripts.pory"

# 51 "data/maps/TwoIsland/scripts.pory"
TwoIsland_EventScript_SetShopExpanded2::
# 52 "data/maps/TwoIsland/scripts.pory"
	setvar VAR_MAP_SCENE_TWO_ISLAND, 3
# 53 "data/maps/TwoIsland/scripts.pory"
	clearflag FLAG_HIDE_TWO_ISLAND_BEAUTY
# 54 "data/maps/TwoIsland/scripts.pory"
	return
# 55 "data/maps/TwoIsland/scripts.pory"

# 56 "data/maps/TwoIsland/scripts.pory"
TwoIsland_EventScript_SetShopExpanded3::
# 57 "data/maps/TwoIsland/scripts.pory"
	setvar VAR_MAP_SCENE_TWO_ISLAND, 4
# 58 "data/maps/TwoIsland/scripts.pory"
	clearflag FLAG_HIDE_TWO_ISLAND_POKE_MANIAC
# 59 "data/maps/TwoIsland/scripts.pory"
	return
# 60 "data/maps/TwoIsland/scripts.pory"

# 61 "data/maps/TwoIsland/scripts.pory"
TwoIsland_EventScript_Clerk::
# 62 "data/maps/TwoIsland/scripts.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 63 "data/maps/TwoIsland/scripts.pory"
	lock
# 64 "data/maps/TwoIsland/scripts.pory"
	faceplayer
# 65 "data/maps/TwoIsland/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_TWO_ISLAND, 4, TwoIsland_EventScript_ClerkShopExpanded3
# 66 "data/maps/TwoIsland/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_TWO_ISLAND, 3, TwoIsland_EventScript_ClerkShopExpanded2
# 67 "data/maps/TwoIsland/scripts.pory"
	goto_if_eq VAR_MAP_SCENE_TWO_ISLAND, 2, TwoIsland_EventScript_ClerkShopExpanded1
# 68 "data/maps/TwoIsland/scripts.pory"
	goto TwoIsland_EventScript_ClerkShopInitial
# 69 "data/maps/TwoIsland/scripts.pory"
	end
# 70 "data/maps/TwoIsland/scripts.pory"

# 71 "data/maps/TwoIsland/scripts.pory"
TwoIsland_EventScript_ClerkShopExpanded3::
# 72 "data/maps/TwoIsland/scripts.pory"
	goto_if_set FLAG_TWO_ISLAND_SHOP_EXPANDED_3, TwoIsland_EventScript_ClerkShopSkipIntro
# 73 "data/maps/TwoIsland/scripts.pory"
	setflag FLAG_TWO_ISLAND_SHOP_EXPANDED_3
# 74 "data/maps/TwoIsland/scripts.pory"
	message TwoIsland_Text_BringingItemsFromDistantLands
# 75 "data/maps/TwoIsland/scripts.pory"
	waitmessage
# 76 "data/maps/TwoIsland/scripts.pory"
	goto TwoIsland_EventScript_ShowShop
# 77 "data/maps/TwoIsland/scripts.pory"
	end
# 78 "data/maps/TwoIsland/scripts.pory"

# 79 "data/maps/TwoIsland/scripts.pory"
TwoIsland_EventScript_ClerkShopExpanded2::
# 80 "data/maps/TwoIsland/scripts.pory"
	goto_if_set FLAG_TWO_ISLAND_SHOP_EXPANDED_2, TwoIsland_EventScript_ClerkShopSkipIntro
# 81 "data/maps/TwoIsland/scripts.pory"
	setflag FLAG_TWO_ISLAND_SHOP_EXPANDED_2
# 82 "data/maps/TwoIsland/scripts.pory"
	message TwoIsland_Text_HopeYouGiveItYourBest
# 83 "data/maps/TwoIsland/scripts.pory"
	waitmessage
# 84 "data/maps/TwoIsland/scripts.pory"
	goto TwoIsland_EventScript_ShowShop
# 85 "data/maps/TwoIsland/scripts.pory"
	end
# 86 "data/maps/TwoIsland/scripts.pory"

# 87 "data/maps/TwoIsland/scripts.pory"
TwoIsland_EventScript_ClerkShopExpanded1::
# 88 "data/maps/TwoIsland/scripts.pory"
	goto_if_set FLAG_TWO_ISLAND_SHOP_EXPANDED_1, TwoIsland_EventScript_ClerkShopSkipIntro
# 89 "data/maps/TwoIsland/scripts.pory"
	setflag FLAG_TWO_ISLAND_SHOP_EXPANDED_1
# 90 "data/maps/TwoIsland/scripts.pory"
	message TwoIsland_Text_AddedMerchandiseForLostelle
# 91 "data/maps/TwoIsland/scripts.pory"
	waitmessage
# 92 "data/maps/TwoIsland/scripts.pory"
	goto TwoIsland_EventScript_ShowShop
# 93 "data/maps/TwoIsland/scripts.pory"
	end
# 94 "data/maps/TwoIsland/scripts.pory"

# 95 "data/maps/TwoIsland/scripts.pory"
TwoIsland_EventScript_ClerkShopInitial::
# 96 "data/maps/TwoIsland/scripts.pory"
	goto_if_set FLAG_TWO_ISLAND_SHOP_INTRODUCED, TwoIsland_EventScript_ClerkShopSkipIntro
# 97 "data/maps/TwoIsland/scripts.pory"
	setflag FLAG_TWO_ISLAND_SHOP_INTRODUCED
# 98 "data/maps/TwoIsland/scripts.pory"
	message TwoIsland_Text_WelcomeToShopMerchandiseLimited
# 99 "data/maps/TwoIsland/scripts.pory"
	waitmessage
# 100 "data/maps/TwoIsland/scripts.pory"
	goto TwoIsland_EventScript_ShowShop
# 101 "data/maps/TwoIsland/scripts.pory"
	end
# 102 "data/maps/TwoIsland/scripts.pory"

# 103 "data/maps/TwoIsland/scripts.pory"
TwoIsland_EventScript_ClerkShopSkipIntro::
# 104 "data/maps/TwoIsland/scripts.pory"
	message Text_MayIHelpYou
# 105 "data/maps/TwoIsland/scripts.pory"
	waitmessage
# 106 "data/maps/TwoIsland/scripts.pory"
TwoIsland_EventScript_ShowShop::
# 107 "data/maps/TwoIsland/scripts.pory"
	pokemart SHOP_ID_TWO_ISLAND_SHOP
# 108 "data/maps/TwoIsland/scripts.pory"
	msgbox Text_PleaseComeAgain
# 109 "data/maps/TwoIsland/scripts.pory"
	release
# 110 "data/maps/TwoIsland/scripts.pory"
	end
# 111 "data/maps/TwoIsland/scripts.pory"

# 112 "data/maps/TwoIsland/scripts.pory"
TwoIsland_EventScript_Sailor::
# 113 "data/maps/TwoIsland/scripts.pory"
	msgbox TwoIsland_Text_FellowMovedFromCeladonCity, MSGBOX_NPC
# 114 "data/maps/TwoIsland/scripts.pory"
	end
# 115 "data/maps/TwoIsland/scripts.pory"

# 116 "data/maps/TwoIsland/scripts.pory"
TwoIsland_EventScript_Woman::
# 117 "data/maps/TwoIsland/scripts.pory"
	msgbox TwoIsland_Text_ShopkeepersBrotherWorksGameCorner, MSGBOX_NPC
# 118 "data/maps/TwoIsland/scripts.pory"
	end
# 119 "data/maps/TwoIsland/scripts.pory"

# 120 "data/maps/TwoIsland/scripts.pory"
TwoIsland_EventScript_Beauty::
# 121 "data/maps/TwoIsland/scripts.pory"
	lock
# 122 "data/maps/TwoIsland/scripts.pory"
	faceplayer
# 123 "data/maps/TwoIsland/scripts.pory"
	famechecker FAMECHECKER_BRUNO, 4
# 124 "data/maps/TwoIsland/scripts.pory"
	msgbox TwoIsland_Text_BrunoCameToIslandWhileBack
# 125 "data/maps/TwoIsland/scripts.pory"
	release
# 126 "data/maps/TwoIsland/scripts.pory"
	end
# 127 "data/maps/TwoIsland/scripts.pory"

# 128 "data/maps/TwoIsland/scripts.pory"
TwoIsland_EventScript_PokeManiac::
# 129 "data/maps/TwoIsland/scripts.pory"
	msgbox TwoIsland_Text_BuyRareItemsHere, MSGBOX_NPC
# 130 "data/maps/TwoIsland/scripts.pory"
	end
# 131 "data/maps/TwoIsland/scripts.pory"

# 132 "data/maps/TwoIsland/scripts.pory"
TwoIsland_EventScript_Boy::
# 133 "data/maps/TwoIsland/scripts.pory"
	msgbox TwoIsland_Text_OldWomanLivesOutOnCape, MSGBOX_NPC
# 134 "data/maps/TwoIsland/scripts.pory"
	end
# 135 "data/maps/TwoIsland/scripts.pory"

# 136 "data/maps/TwoIsland/scripts.pory"
TwoIsland_EventScript_LittleBoy::
# 137 "data/maps/TwoIsland/scripts.pory"
	msgbox TwoIsland_Text_HaveYouTriedJumpingGame, MSGBOX_NPC
# 138 "data/maps/TwoIsland/scripts.pory"
	end
# 139 "data/maps/TwoIsland/scripts.pory"

# 140 "data/maps/TwoIsland/scripts.pory"
TwoIsland_EventScript_IslandSign::
# 141 "data/maps/TwoIsland/scripts.pory"
	msgbox TwoIsland_Text_IslandSign, MSGBOX_SIGN
# 142 "data/maps/TwoIsland/scripts.pory"
	end
# 143 "data/maps/TwoIsland/scripts.pory"

# 144 "data/maps/TwoIsland/scripts.pory"
TwoIsland_EventScript_JoyfulGameCornerSign::
# 145 "data/maps/TwoIsland/scripts.pory"
	msgbox TwoIsland_Text_JoyfulGameCornerSign, MSGBOX_SIGN
# 146 "data/maps/TwoIsland/scripts.pory"
	end
# 147 "data/maps/TwoIsland/scripts.pory"

# 148 "data/maps/TwoIsland/scripts.pory"
TwoIsland_EventScript_FastCurrentSign::
# 149 "data/maps/TwoIsland/scripts.pory"
	msgbox TwoIsland_Text_DangerFastCurrent, MSGBOX_SIGN
# 150 "data/maps/TwoIsland/scripts.pory"
	end
