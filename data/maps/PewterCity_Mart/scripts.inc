# 1 "data/maps/PewterCity_Mart/scripts.pory"

# 2 "data/maps/PewterCity_Mart/scripts.pory"
PewterCity_Mart_MapScripts::
# 3 "data/maps/PewterCity_Mart/scripts.pory"
	.byte 0
# 4 "data/maps/PewterCity_Mart/scripts.pory"

# 5 "data/maps/PewterCity_Mart/scripts.pory"
PewterCity_Mart_EventScript_Youngster::
# 6 "data/maps/PewterCity_Mart/scripts.pory"
	msgbox PewterCity_Mart_Text_BoughtWeirdFishFromShadyGuy, MSGBOX_NPC
# 7 "data/maps/PewterCity_Mart/scripts.pory"
	end
# 8 "data/maps/PewterCity_Mart/scripts.pory"

# 9 "data/maps/PewterCity_Mart/scripts.pory"
PewterCity_Mart_EventScript_Boy::
# 10 "data/maps/PewterCity_Mart/scripts.pory"
	msgbox PewterCity_Mart_Text_GoodThingsIfRaiseMonsDiligently, MSGBOX_NPC
# 11 "data/maps/PewterCity_Mart/scripts.pory"
	end
# 12 "data/maps/PewterCity_Mart/scripts.pory"

# 13 "data/maps/PewterCity_Mart/scripts.pory"
PewterCity_Mart_EventScript_Clerk::
# 14 "data/maps/PewterCity_Mart/scripts.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 15 "data/maps/PewterCity_Mart/scripts.pory"
	lock
# 16 "data/maps/PewterCity_Mart/scripts.pory"
	faceplayer
# 17 "data/maps/PewterCity_Mart/scripts.pory"
	message Text_MayIHelpYou
# 18 "data/maps/PewterCity_Mart/scripts.pory"
	waitmessage
# 19 "data/maps/PewterCity_Mart/scripts.pory"
	pokemart SHOP_ID_PEWTER_CITY_MART
# 20 "data/maps/PewterCity_Mart/scripts.pory"
	msgbox Text_PleaseComeAgain
# 21 "data/maps/PewterCity_Mart/scripts.pory"
	release
# 22 "data/maps/PewterCity_Mart/scripts.pory"
	end
