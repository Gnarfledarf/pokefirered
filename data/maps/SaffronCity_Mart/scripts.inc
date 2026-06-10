# 1 "data/maps/SaffronCity_Mart/scripts.pory"

# 2 "data/maps/SaffronCity_Mart/scripts.pory"
SaffronCity_Mart_MapScripts::
# 3 "data/maps/SaffronCity_Mart/scripts.pory"
	.byte 0
# 4 "data/maps/SaffronCity_Mart/scripts.pory"

# 5 "data/maps/SaffronCity_Mart/scripts.pory"
SaffronCity_Mart_EventScript_Lass::
# 6 "data/maps/SaffronCity_Mart/scripts.pory"
	msgbox SaffronCity_Mart_Text_ReviveIsCostly, MSGBOX_NPC
# 7 "data/maps/SaffronCity_Mart/scripts.pory"
	end
# 8 "data/maps/SaffronCity_Mart/scripts.pory"

# 9 "data/maps/SaffronCity_Mart/scripts.pory"
SaffronCity_Mart_EventScript_Youngster::
# 10 "data/maps/SaffronCity_Mart/scripts.pory"
	msgbox SaffronCity_Mart_Text_MaxRepelMoreEffectiveThanSuper, MSGBOX_NPC
# 11 "data/maps/SaffronCity_Mart/scripts.pory"
	end
# 12 "data/maps/SaffronCity_Mart/scripts.pory"

# 13 "data/maps/SaffronCity_Mart/scripts.pory"
SaffronCity_Mart_EventScript_Clerk::
# 14 "data/maps/SaffronCity_Mart/scripts.pory"
	goto_if_questlog EventScript_ReleaseEnd
# 15 "data/maps/SaffronCity_Mart/scripts.pory"
	lock
# 16 "data/maps/SaffronCity_Mart/scripts.pory"
	faceplayer
# 17 "data/maps/SaffronCity_Mart/scripts.pory"
	message Text_MayIHelpYou
# 18 "data/maps/SaffronCity_Mart/scripts.pory"
	waitmessage
# 19 "data/maps/SaffronCity_Mart/scripts.pory"
	pokemart SHOP_ID_SAFFRON_CITY_MART
# 20 "data/maps/SaffronCity_Mart/scripts.pory"
	msgbox Text_PleaseComeAgain
# 21 "data/maps/SaffronCity_Mart/scripts.pory"
	release
# 22 "data/maps/SaffronCity_Mart/scripts.pory"
	end
