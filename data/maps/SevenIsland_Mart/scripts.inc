# 1 "data/maps/SevenIsland_Mart/scripts.pory"

# 2 "data/maps/SevenIsland_Mart/scripts.pory"
SevenIsland_Mart_MapScripts::
# 3 "data/maps/SevenIsland_Mart/scripts.pory"
	.byte 0
# 4 "data/maps/SevenIsland_Mart/scripts.pory"

# 5 "data/maps/SevenIsland_Mart/scripts.pory"
SevenIsland_Mart_EventScript_Clerk::
# 6 "data/maps/SevenIsland_Mart/scripts.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 7 "data/maps/SevenIsland_Mart/scripts.pory"
	lock
# 8 "data/maps/SevenIsland_Mart/scripts.pory"
	faceplayer
# 9 "data/maps/SevenIsland_Mart/scripts.pory"
	message Text_MayIHelpYou
# 10 "data/maps/SevenIsland_Mart/scripts.pory"
	waitmessage
# 11 "data/maps/SevenIsland_Mart/scripts.pory"
	pokemart SHOP_ID_SEVEN_ISLAND_MART
# 12 "data/maps/SevenIsland_Mart/scripts.pory"
	msgbox Text_PleaseComeAgain
# 13 "data/maps/SevenIsland_Mart/scripts.pory"
	release
# 14 "data/maps/SevenIsland_Mart/scripts.pory"
	end
# 15 "data/maps/SevenIsland_Mart/scripts.pory"

# 16 "data/maps/SevenIsland_Mart/scripts.pory"
SevenIsland_Mart_EventScript_Lass::
# 17 "data/maps/SevenIsland_Mart/scripts.pory"
	msgbox SevenIsland_Mart_Text_MonHavePersonalitiesOfTheirOwn, MSGBOX_NPC
# 18 "data/maps/SevenIsland_Mart/scripts.pory"
	end
# 19 "data/maps/SevenIsland_Mart/scripts.pory"

# 20 "data/maps/SevenIsland_Mart/scripts.pory"
SevenIsland_Mart_EventScript_Hiker::
# 21 "data/maps/SevenIsland_Mart/scripts.pory"
	msgbox SevenIsland_Mart_Text_PreparationsCompleteForRuins, MSGBOX_NPC
# 22 "data/maps/SevenIsland_Mart/scripts.pory"
	end
# 23 "data/maps/SevenIsland_Mart/scripts.pory"

# 24 "data/maps/SevenIsland_Mart/scripts.pory"
SevenIsland_Mart_EventScript_Fisher::
# 25 "data/maps/SevenIsland_Mart/scripts.pory"
	msgbox SevenIsland_Mart_Text_NeedToFishOnSevenIsland, MSGBOX_NPC
# 26 "data/maps/SevenIsland_Mart/scripts.pory"
	end
