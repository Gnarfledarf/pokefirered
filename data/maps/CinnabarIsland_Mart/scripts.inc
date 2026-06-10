# 1 "data/maps/CinnabarIsland_Mart/scripts.pory"

# 2 "data/maps/CinnabarIsland_Mart/scripts.pory"
CinnabarIsland_Mart_MapScripts::
# 3 "data/maps/CinnabarIsland_Mart/scripts.pory"
	.byte 0
# 4 "data/maps/CinnabarIsland_Mart/scripts.pory"

# 5 "data/maps/CinnabarIsland_Mart/scripts.pory"
CinnabarIsland_Mart_EventScript_Woman::
# 6 "data/maps/CinnabarIsland_Mart/scripts.pory"
	msgbox CinnabarIsland_Mart_Text_DontTheyHaveXAttack, MSGBOX_NPC
# 7 "data/maps/CinnabarIsland_Mart/scripts.pory"
	end
# 8 "data/maps/CinnabarIsland_Mart/scripts.pory"

# 9 "data/maps/CinnabarIsland_Mart/scripts.pory"
CinnabarIsland_Mart_EventScript_Scientist::
# 10 "data/maps/CinnabarIsland_Mart/scripts.pory"
	msgbox CinnabarIsland_Mart_Text_ExtraItemsNeverHurt, MSGBOX_NPC
# 11 "data/maps/CinnabarIsland_Mart/scripts.pory"
	end
# 12 "data/maps/CinnabarIsland_Mart/scripts.pory"

# 13 "data/maps/CinnabarIsland_Mart/scripts.pory"
CinnabarIsland_Mart_EventScript_Clerk::
# 14 "data/maps/CinnabarIsland_Mart/scripts.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 15 "data/maps/CinnabarIsland_Mart/scripts.pory"
	lock
# 16 "data/maps/CinnabarIsland_Mart/scripts.pory"
	faceplayer
# 17 "data/maps/CinnabarIsland_Mart/scripts.pory"
	message Text_MayIHelpYou
# 18 "data/maps/CinnabarIsland_Mart/scripts.pory"
	waitmessage
# 19 "data/maps/CinnabarIsland_Mart/scripts.pory"
	pokemart SHOP_ID_CINNABAR_ISLAND_MART
# 20 "data/maps/CinnabarIsland_Mart/scripts.pory"
	msgbox Text_PleaseComeAgain
# 21 "data/maps/CinnabarIsland_Mart/scripts.pory"
	release
# 22 "data/maps/CinnabarIsland_Mart/scripts.pory"
	end
