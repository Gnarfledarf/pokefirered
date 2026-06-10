# 1 "data/maps/ThreeIsland_Mart/scripts.pory"

# 2 "data/maps/ThreeIsland_Mart/scripts.pory"
ThreeIsland_Mart_MapScripts::
# 3 "data/maps/ThreeIsland_Mart/scripts.pory"
	.byte 0
# 4 "data/maps/ThreeIsland_Mart/scripts.pory"

# 5 "data/maps/ThreeIsland_Mart/scripts.pory"
ThreeIsland_Mart_EventScript_Clerk::
# 6 "data/maps/ThreeIsland_Mart/scripts.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 7 "data/maps/ThreeIsland_Mart/scripts.pory"
	lock
# 8 "data/maps/ThreeIsland_Mart/scripts.pory"
	faceplayer
# 9 "data/maps/ThreeIsland_Mart/scripts.pory"
	message Text_MayIHelpYou
# 10 "data/maps/ThreeIsland_Mart/scripts.pory"
	waitmessage
# 11 "data/maps/ThreeIsland_Mart/scripts.pory"
	pokemart SHOP_ID_THREE_ISLAND_MART
# 12 "data/maps/ThreeIsland_Mart/scripts.pory"
	msgbox Text_PleaseComeAgain
# 13 "data/maps/ThreeIsland_Mart/scripts.pory"
	release
# 14 "data/maps/ThreeIsland_Mart/scripts.pory"
	end
# 15 "data/maps/ThreeIsland_Mart/scripts.pory"

# 16 "data/maps/ThreeIsland_Mart/scripts.pory"
ThreeIsland_Mart_EventScript_Picnicker::
# 17 "data/maps/ThreeIsland_Mart/scripts.pory"
	msgbox ThreeIsland_Mart_Text_TrueThatCeldadonDeptStoreBigger, MSGBOX_NPC
# 18 "data/maps/ThreeIsland_Mart/scripts.pory"
	end
# 19 "data/maps/ThreeIsland_Mart/scripts.pory"

# 20 "data/maps/ThreeIsland_Mart/scripts.pory"
ThreeIsland_Mart_EventScript_BugCatcher::
# 21 "data/maps/ThreeIsland_Mart/scripts.pory"
	msgbox ThreeIsland_Mart_Text_PeopleHealWithBerriesFromForest, MSGBOX_NPC
# 22 "data/maps/ThreeIsland_Mart/scripts.pory"
	end
# 23 "data/maps/ThreeIsland_Mart/scripts.pory"

# 24 "data/maps/ThreeIsland_Mart/scripts.pory"
ThreeIsland_Mart_EventScript_Youngster::
# 25 "data/maps/ThreeIsland_Mart/scripts.pory"
	msgbox ThreeIsland_Mart_Text_BikersWereAboutToTrashMart, MSGBOX_NPC
# 26 "data/maps/ThreeIsland_Mart/scripts.pory"
	end
