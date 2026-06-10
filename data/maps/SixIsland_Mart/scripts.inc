# 1 "data/maps/SixIsland_Mart/scripts.pory"

# 2 "data/maps/SixIsland_Mart/scripts.pory"
SixIsland_Mart_MapScripts::
# 3 "data/maps/SixIsland_Mart/scripts.pory"
	.byte 0
# 4 "data/maps/SixIsland_Mart/scripts.pory"

# 5 "data/maps/SixIsland_Mart/scripts.pory"
SixIsland_Mart_EventScript_Clerk::
# 6 "data/maps/SixIsland_Mart/scripts.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 7 "data/maps/SixIsland_Mart/scripts.pory"
	lock
# 8 "data/maps/SixIsland_Mart/scripts.pory"
	faceplayer
# 9 "data/maps/SixIsland_Mart/scripts.pory"
	message Text_MayIHelpYou
# 10 "data/maps/SixIsland_Mart/scripts.pory"
	waitmessage
# 11 "data/maps/SixIsland_Mart/scripts.pory"
	pokemart SHOP_ID_SIX_ISLAND_MART
# 12 "data/maps/SixIsland_Mart/scripts.pory"
	msgbox Text_PleaseComeAgain
# 13 "data/maps/SixIsland_Mart/scripts.pory"
	release
# 14 "data/maps/SixIsland_Mart/scripts.pory"
	end
# 15 "data/maps/SixIsland_Mart/scripts.pory"

# 16 "data/maps/SixIsland_Mart/scripts.pory"
SixIsland_Mart_EventScript_Picnicker::
# 17 "data/maps/SixIsland_Mart/scripts.pory"
	msgbox SixIsland_Mart_Text_ShouldBuyMailAndWriteLetter, MSGBOX_NPC
# 18 "data/maps/SixIsland_Mart/scripts.pory"
	end
