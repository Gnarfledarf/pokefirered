# 1 "data/maps/FourIsland_Mart/scripts.pory"

# 2 "data/maps/FourIsland_Mart/scripts.pory"
FourIsland_Mart_MapScripts::
# 3 "data/maps/FourIsland_Mart/scripts.pory"
	.byte 0
# 4 "data/maps/FourIsland_Mart/scripts.pory"

# 5 "data/maps/FourIsland_Mart/scripts.pory"
FourIsland_Mart_EventScript_Clerk::
# 6 "data/maps/FourIsland_Mart/scripts.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 7 "data/maps/FourIsland_Mart/scripts.pory"
	lock
# 8 "data/maps/FourIsland_Mart/scripts.pory"
	faceplayer
# 9 "data/maps/FourIsland_Mart/scripts.pory"
	message Text_MayIHelpYou
# 10 "data/maps/FourIsland_Mart/scripts.pory"
	waitmessage
# 11 "data/maps/FourIsland_Mart/scripts.pory"
	pokemart SHOP_ID_FOUR_ISLAND_MART
# 12 "data/maps/FourIsland_Mart/scripts.pory"
	msgbox Text_PleaseComeAgain
# 13 "data/maps/FourIsland_Mart/scripts.pory"
	release
# 14 "data/maps/FourIsland_Mart/scripts.pory"
	end
# 15 "data/maps/FourIsland_Mart/scripts.pory"

# 16 "data/maps/FourIsland_Mart/scripts.pory"
FourIsland_Mart_EventScript_Camper::
# 17 "data/maps/FourIsland_Mart/scripts.pory"
	msgbox FourIsland_Mart_Text_IcefallCaveIsFrigid, MSGBOX_NPC
# 18 "data/maps/FourIsland_Mart/scripts.pory"
	end
